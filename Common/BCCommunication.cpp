#include "BCCommunication.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include "BCLoginDlg.h"
#include "MainWindow.h"
#include "../Model/BCMRoom.h"
#include "../Model/BCMChannel.h"
#include "../Model/BCMGroupScene.h"
#include "../Model/BCMWindowScene.h"
#include "../Model/BCMGroupDisplay.h"
#include "../View/BCControlTreeWidget.h"
#include "../View/BCSignalTreeWidget.h"
#include "../View/BCLocationDlg.h"
#include "../View/BCSceneTreeWidget.h"
#include "../View/BCFaceWidget.h"
#include "../View/BCToolBar.h"
#include "../View/BCRibbonMainToolBarAction.h"
#include "../View/BCRoomWidget.h"
#include "../View/BCSignalWindowDisplayWidget.h"
#include "BCLocalServer.h"
#include "BCCommon.h"

// 需要定义命令结束标识，否则当命令发送过快的时候接收方会自动合并多个命令，造成解析错误
#define CMDOVERFLAG QString("$$$$")

BCCommunication::BCCommunication()
{
    m_ip = QString::null;
    m_port = 0;
    m_nHeartBeatCount = 0;

    m_pLoginDlg             = NULL;
    m_timeOfPreview = QTime::currentTime().addMSecs( -10*1000 );

    m_pSocket = new QTcpSocket( this );
    connect(m_pSocket, SIGNAL(readyRead()), this, SLOT(onRevData()));
    connect(m_pSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onDisplayError(QAbstractSocket::SocketError)));

    m_pOneSecondTimer = new QTimer();
    m_pOneSecondTimer->setInterval( 1000 );
    connect(m_pOneSecondTimer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    m_pOneSecondTimer->start();
}

BCCommunication::~BCCommunication()
{
    m_pOneSecondTimer->stop();
    m_pOneSecondTimer->deleteLater();

    m_pSocket->close();
    m_pSocket->deleteLater();
}

void BCCommunication::onTimeout()
{
    return;
    if (m_ip.isEmpty() || !BCCommon::g_bConnectWithServer)
        return;

    // 如果小于10秒钟没必要执行
    int nOffsetTime = m_timeOfPreview.msecsTo( QTime::currentTime() );
    if (nOffsetTime < 2*1000)
        return;

    MainWindow *pMainWindow = BCCommon::Application();
    QAbstractSocket::SocketState socketState = m_pSocket->state();
    if ((socketState != QAbstractSocket::ConnectingState) && (socketState != QAbstractSocket::ConnectedState)) {
        BCCommon::g_bConnectStatusOK = false;
        QHostAddress hostAddress;
        hostAddress.setAddress( m_ip );
        m_pSocket->connectToHost(hostAddress, m_port);
        m_pSocket->waitForConnected( 50 );
    } else {
        BCCommon::g_bConnectStatusOK = true;

        if (NULL != pMainWindow->GetCurrentUser()) {
            // 保持连接
            m_nHeartBeatCount++;
            this->SendCmd( EncodeStandardJson("Heartbeat", pMainWindow->GetCurrentUser()->loginName) );
            if (m_nHeartBeatCount > 6) {
                if ( m_pSocket->state() == QAbstractSocket::ConnectedState ) {
                    m_pSocket->disconnectFromHost();
                    m_pSocket->waitForDisconnected( 50 );
                }
            }
        }

    }

    // 刷新连接状态
    pMainWindow->RefreshStatusBar();
}

// 全局唯一值
BCCommunication *BCCommunication::Application()
{
    if (NULL == m_pCommunication) {
        m_pCommunication = new BCCommunication();
    }

    return m_pCommunication;
}

void BCCommunication::Destroy()
{
    if (NULL != m_pCommunication) {
        delete m_pCommunication;
        m_pCommunication = NULL;
    }
}

BCCommunication *BCCommunication::m_pCommunication = NULL;

// 接收服务器返回值
void BCCommunication::onRevData()
{
    QString json = m_pSocket->readAll();

    // 如果不包含结束符则属于非法指令，直接返回不处理
    if ( !json.contains( CMDOVERFLAG ) ) {
       m_nCacheTimes++;
       m_qsCacheJson += json;

       qDebug() << "recv times " << m_nCacheTimes;

       if (m_nCacheTimes >= 50) {
           // 清空缓存JSON
           m_nCacheTimes = 0;
           m_qsCacheJson = QString::null;
           return;
       }

       return;
    } else if (m_nCacheTimes != 0) {
        json = m_qsCacheJson + json;
    }

    qDebug() << "recv server msg : " << json;

    // 经过分割后的指令
    QStringList lstCmds = json.split( CMDOVERFLAG );
    for (int i = 0; i < lstCmds.count(); i++) {
       // 处理单个指令函数
       RevSingleData( lstCmds.at(i) );
    }

    // 清空缓存JSON
    m_nCacheTimes = 0;
    m_qsCacheJson = QString::null;
}

void BCCommunication::RevSingleData(const QString &json)
{
    if ( json.isEmpty() )
        return;

    // 解析json的cmdKey
    QString cmdKey = DecodeJsonKey( json );

    // 解析登录返回信息
    if ("LoginResult" == cmdKey) {
        QString qsLoginRes = GetJsonValueByKey(json, "LoginResult");
        QStringList lstPara = qsLoginRes.split(" ");
        if (2 == lstPara.count()) {
            int userid = lstPara.at(0).toInt();
            int level = lstPara.at(1).toInt();

            if (NULL != m_pLoginDlg)
                m_pLoginDlg->SetServerRes(userid, level);
        }
    }
    // 解析心跳回数
    if ("HeartbeatResult" == cmdKey) {
        m_nHeartBeatCount = 0;
    }

    // 解析退出登录信息
    if ("Logoff" == cmdKey) {
        MainWindow *pApplication = BCCommon::Application();
        pApplication->onTrayIconQuit();
    }

    // 解析房间配置返回值
    if ("GetRoomsResult" == cmdKey) {
        MainWindow *pApplication = BCCommon::Application();
        pApplication->DealRoomDataFromServer( json );
    }

    // 解析输入通道返回值
    if ("GetInputChannelsResult" == cmdKey) {
        MainWindow *pApplication = BCCommon::Application();
        pApplication->DealInputChannelDataFromServer( json );
    }

    // 解析主工具条返回值
    if ("GetMarkViewMainToolBarResult" == cmdKey) {
        MainWindow *pApplication = BCCommon::Application();
        pApplication->DealMainToolBarDataFromServer( json );
    }

    // 移动窗口请求控制
    if ("requestControlBySignalWindowResult" == cmdKey) {
        int nRes = GetStandardJsonResult( json );
        if (1 == nRes) {
            QString qsRes = GetJsonValueByKey(json, "requestControlBySignalWindowResult");
            QStringList lstPara = qsRes.split(" ");
            if (4 == lstPara.count()) {
                int groupid = lstPara.at(0).toInt();
                int chid    = lstPara.at(1).toInt();
                int chtype  = lstPara.at(2).toInt();
                int winid   = lstPara.at(3).toInt();

                ServerMoveSignalWindow(groupid, chid, chtype, winid);
            }
        }
    }

    // 打开轮训请求控制
    if ("requestControlByGroupSceneResult" == cmdKey) {
        int nRes = GetStandardJsonResult( json );
        if (1 == nRes) {
            QString qsRes = GetJsonValueByKey(json, "requestControlByGroupSceneResult");
            QStringList lstPara = qsRes.split(" ");
            if (2 == lstPara.count()) {
                int roomid = lstPara.at(0).toInt();
                int groupsceneid = lstPara.at(1).toInt();

                ServerLoopGroupScene(roomid, groupsceneid);
            }
        }
    }

    // 打开预布局
    if ("requestControlByFloorPlanningResult" == cmdKey) {
        int nRes = GetStandardJsonResult( json );
        if (1 == nRes) {
            QString qsRes = GetJsonValueByKey(json, "requestControlByFloorPlanningResult");
            QStringList lstPara = qsRes.split(" ");
            if (2 == lstPara.count()) {
                int roomid = lstPara.at(0).toInt();
                int groupsceneid = lstPara.at(1).toInt();

                ServerFloorPlanning(roomid, groupsceneid);
            }
        }
    }

    // 解析请求开窗返回值
    if ("winsizeResult" == cmdKey) {
        int nRes = GetStandardJsonResult( json );
        if (1 == nRes) {
            QString qsRes = GetJsonValueByKey(json, "winsizeResult");
            QStringList lstPara = qsRes.split(" ");
            if (9 == lstPara.count()) {
                int groupid = lstPara.at(0).toInt();
                int chid    = lstPara.at(1).toInt();
                int winid   = lstPara.at(2).toInt();
                int l       = lstPara.at(3).toInt();
                int t       = lstPara.at(4).toInt();
                int r       = lstPara.at(5).toInt();
                int b       = lstPara.at(6).toInt();
                int type    = lstPara.at(7).toInt();

                ServerWinsize(groupid, chid, type, winid, l, t, r, b);
            }
        }
    }

    // 同步开窗，移动
    if ("winsize" == cmdKey) {
        QString qsRes = GetJsonValueByKey(json, "winsize");
        QStringList lstPara = qsRes.split(" ");
        if (9 == lstPara.count()) {
            int groupid = lstPara.at(0).toInt();
            int chid    = lstPara.at(1).toInt();
            int winid   = lstPara.at(2).toInt();
            int l       = lstPara.at(3).toInt();
            int t       = lstPara.at(4).toInt();
            int r       = lstPara.at(5).toInt();
            int b       = lstPara.at(6).toInt();
            int chtype  = lstPara.at(7).toInt();

            // 同步开窗
            ServerWinsize(groupid, chid, chtype, winid, l, t, r, b);
        }
    }

    // 同步关窗
    if ("winswitchResult" == cmdKey) {
        int nRes = GetStandardJsonResult( json );
        if (1 == nRes) {
            QString qsRes = GetJsonValueByKey(json, "winswitchResult");
            QStringList lstPara = qsRes.split(" ");
            if (5 == lstPara.count()) {
                int groupid = lstPara.at(0).toInt();
                int winid   = lstPara.at(1).toInt();
                int chid    = lstPara.at(2).toInt();
                int chtype  = lstPara.at(3).toInt();

                // 同步开窗
                ServerWinswitch(groupid, chid, chtype, winid);
            }
        }
    }

    // 关窗回复
    if ("winswitch" == cmdKey) {
        QString qsRes = GetJsonValueByKey(json, "winswitch");
        QStringList lstPara = qsRes.split(" ");
        if (5 == lstPara.count()) {
            int groupid = lstPara.at(0).toInt();
            int winid   = lstPara.at(1).toInt();
            int chid    = lstPara.at(2).toInt();
            int chtype  = lstPara.at(3).toInt();

            // 同步开窗
            ServerWinswitch(groupid, chid, chtype, winid);
        }
    }

    // 清屏回复
    if ("resetResult" == cmdKey) {
        int nRes = GetStandardJsonResult( json );
        if (1 == nRes) {
            QString qsRes = GetJsonValueByKey(json, "resetResult");

            ServerReset( qsRes );
        }
    }

    // 同步清屏
    if ("reset" == cmdKey) {
        QString qsRes = GetJsonValueByKey(json, "reset");

        ServerReset( qsRes );
    }

    // 添加场景返回值
    if ("addSceneResult" == cmdKey) {
        int nRes = GetStandardJsonResult( json );
        if (1 == nRes) {
            int roomid = -1;
            int groupsceneid = -1;
            sWindowScene swindowscene = DecodeSceneJson(json, roomid, groupsceneid);
            if (-1 != swindowscene.id) {
                ServerAddScene(roomid, groupsceneid, swindowscene);
                RefreshSceneWidget();
            }
        }
    }

    // 同步添加场景
    if ("addScene" == cmdKey) {
        int roomid = -1;
        int groupsceneid = -1;
        sWindowScene swindowscene = DecodeSceneJson(json, roomid, groupsceneid);
        if (-1 != swindowscene.id) {
            ServerAddScene(roomid, groupsceneid, swindowscene);
            RefreshSceneWidget();
        }
    }

    // 删除场景返回值
    if ("deleteSceneResult" == cmdKey) {
        int nRes = GetStandardJsonResult( json );
        if (1 == nRes) {
            QString qsRes = GetJsonValueByKey(json, "deleteSceneResult");
            QStringList lstParas = qsRes.split(" ");
            if (3 == lstParas.count()) {
                int id = lstParas.at(0).toInt();
                int nRoomID = lstParas.at(1).toInt();
                int nGroupSceneID = lstParas.at(2).toInt();

                ServerDeleteScene(nRoomID, nGroupSceneID, id);
                RefreshSceneWidget();
            }
        }
    }

    // 同步删除场景
    if ("deleteScene" == cmdKey) {
        QString qsRes = GetJsonValueByKey(json, "deleteScene");
        QStringList lstParas = qsRes.split(" ");
        if (3 == lstParas.count()) {
            int id = lstParas.at(0).toInt();
            int nRoomID = lstParas.at(1).toInt();
            int nGroupSceneID = lstParas.at(2).toInt();

            ServerDeleteScene(nRoomID, nGroupSceneID, id);
            RefreshSceneWidget();
        }
    }

    // 刷新场景返回值
    if ("updateSceneResult" == cmdKey) {
        int nRes = GetStandardJsonResult( json );
        if (1 == nRes) {
            QString qsRes = GetJsonValueByKey(json, "updateSceneResult");
            QStringList lstParas = qsRes.split(" ");
            if (5 == lstParas.count()) {
                int id = lstParas.at(0).toInt();
                int nRoomID = lstParas.at(1).toInt();
                int nGroupSceneID = lstParas.at(2).toInt();
                int nCycle = lstParas.at(3).toInt();
                QString name = lstParas.at(4);

                ServerUpdateScene(nRoomID, nGroupSceneID, id, nCycle, name);
                RefreshSceneWidget();
            }
        }
    }

    // 同步刷新场景
    if ("updateScene" == cmdKey) {
        QString qsRes = GetJsonValueByKey(json, "updateScene");
        QStringList lstParas = qsRes.split(" ");
        if (5 == lstParas.count()) {
            int id = lstParas.at(0).toInt();
            int nRoomID = lstParas.at(1).toInt();
            int nGroupSceneID = lstParas.at(2).toInt();
            int nCycle = lstParas.at(3).toInt();
            QString name = lstParas.at(4);

            ServerUpdateScene(nRoomID, nGroupSceneID, id, nCycle, name);
            RefreshSceneWidget();
        }
    }

    // 刷新场景数据返回值
    if ("updateSceneDataResult" == cmdKey) {
        int nRes = GetStandardJsonResult( json );
        if (1 == nRes) {
            int roomid = -1;
            int groupsceneid = -1;
            sWindowScene swindowscene = DecodeSceneJson(json, roomid, groupsceneid);
            if (-1 != swindowscene.id) {
                ServerUpdateScene(roomid, groupsceneid, swindowscene);
                RefreshSceneWidget();
            }
        }
    }

    // 同步刷新场景数据
    if ("updateSceneData" == cmdKey) {
        int roomid = -1;
        int groupsceneid = -1;
        sWindowScene swindowscene = DecodeSceneJson(json, roomid, groupsceneid);
        if (-1 != swindowscene.id) {
            ServerUpdateScene(roomid, groupsceneid, swindowscene);
            RefreshSceneWidget();
        }
    }

    // 调用场景返回
    if ("gloadResult" == cmdKey) {
        QString qsRes = GetJsonValueByKey(json, "gloadResult");
        QStringList lstParas = qsRes.split(" ");
        if (2 == lstParas.count()) {
            ServerLoadWindowScene(lstParas.at(0).toInt(), lstParas.at(1).toInt());
        }
    }

    // 同步调用场景
    if ("gload" == cmdKey) {
        QString qsRes = GetJsonValueByKey(json, "gload");
        QStringList lstParas = qsRes.split(" ");
        if (2 == lstParas.count()) {
            ServerLoadWindowScene(lstParas.at(0).toInt(), lstParas.at(1).toInt());
        }
    }

    // 同步修改输入通道名称
    if ("UpdateInputChannel" == cmdKey) {
        QString qsRes = GetJsonValueByKey(json, "UpdateInputChannel");
        QStringList lstParas = qsRes.split(" ");
        if (4 == lstParas.count()) {
            int userid = lstParas.at(0).toInt();
            int chid = lstParas.at(1).toInt();
            int chtype = lstParas.at(2).toInt();
            QString text = lstParas.at(3);

            ServerUpdateInputChannel(chid, chtype, text);
        }
    }

    // 同步修改场景顺序
    if ("UpdateSceneSort" == cmdKey) {
        QString qsPara = GetJsonValueByKey(json, "UpdateSceneSort");
        if ( qsPara.contains(" ") ) {
            QStringList lstParas = qsPara.split(" ");
            if (lstParas.count() != 4)
                return;

            int roomid = lstParas.at(1).toInt();
            int groupsceneid = lstParas.at(2).toInt();
            int scenecount = lstParas.at(3).toInt();

            QString qsSceneSortMap = GetJsonValueByKey(json, "UpdateSceneSort", "cmdSort");
            if ( qsSceneSortMap.contains(" ") ) {
                QStringList lstSceneSort = qsSceneSortMap.split(" ");
                if (lstSceneSort.count() != scenecount*2)
                    return;

                QMap<int, int> map;
                for (int i = 0; i < scenecount; i++) {
                    int sceneid = lstSceneSort.at(2*i+0).toInt();
                    int sort = lstSceneSort.at(2*i+1).toInt();

                    map.insert(sceneid, sort);
                }

                ServerUpdateSceneSort(roomid, groupsceneid, map);
            }
        }
    }
}

QString BCCommunication::DecodeJsonKey(const QString &json) {
    QJsonParseError json_error;
    QJsonDocument parse_doucment = QJsonDocument::fromJson(json.toLocal8Bit(), &json_error);
    if(json_error.error != QJsonParseError::NoError) {
        qDebug() << json_error.errorString();
        return QString::null;
    }

    if( !parse_doucment.isObject() )
        return QString::null;

    QJsonObject obj = parse_doucment.object();
    if( !obj.contains("cmdKey") )
        return QString::null;

    QJsonValue cmdValue = obj.take("cmdKey");
    if( !cmdValue.isString() )
        return QString::null;

    return cmdValue.toString();
}

void BCCommunication::onDisplayError(QAbstractSocket::SocketError)
{
   qDebug()<< m_pSocket->errorString();
   m_pSocket->close();
}

// **************************************************************************************************************
// 请求服务器接口
void BCCommunication::RequestLogin(BCLoginDlg *pLoginDlg, const QString &usr, const QString &pwd)
{
    m_pLoginDlg = pLoginDlg;
    SendCmd( EncodeStandardJson("Login", QString("%1 %2").arg(usr).arg(pwd)) );
}

void BCCommunication::RequestConfig(const QString &key, int userid)
{
    SendCmd( EncodeStandardJson(key, QString::number(userid)) );
}

void BCCommunication::RequestWinSwitch(int gid, int winid, int chid, int type, int copyIndex)
{
    SendCmd( EncodeStandardJson("winswitch", QString("%1 %2 %3 %4 %5").arg(gid).arg(winid).arg(chid).arg(type).arg(copyIndex)) );
}

void BCCommunication::RequestAddWindowScene(sWindowScene swindowscene, int roomid, int groupsceneid)
{
    SendCmd( EncodeSceneJson(QString("addScene"), swindowscene, roomid, groupsceneid) );
}

void BCCommunication::RequestDeleteWindowScene(int id, int roomid, int groupsceneid)
{
    SendCmd( EncodeStandardJson("deleteScene", QString("%1 %2 %3").arg(id).arg(roomid).arg(groupsceneid)) );
}

void BCCommunication::RequestUpdateWindowScene(int id, int roomid, int groupsceneid, int cycle, const QString &name)
{
    SendCmd( EncodeStandardJson("updateScene", QString("%1 %2 %3 %4 %5").arg(id).arg(roomid).arg(groupsceneid).arg(cycle).arg(name)) );
}

void BCCommunication::RequestUpdateWindowScene(sWindowScene swindowscene, int roomid, int groupsceneid)
{
    SendCmd( EncodeSceneJson(QString("updateSceneData"), swindowscene, roomid, groupsceneid) );
}

void BCCommunication::RequestLoadWindowScene(int nGroupDisplayID, int id)
{
    SendCmd( EncodeStandardJson("gload", QString("%1 %2").arg(nGroupDisplayID).arg(id)) );
}

void BCCommunication::SetIPVedioCurrentIP(int cid, int /*winid*/, int /*segmentation*/, int currentSegmentaion, const QString &ip, int boardcardid, int boardcardpos)
{
    SendCmd( EncodeStandardJson("SetIPVedioCurrentIP", QString("%1 %2 %3 %4 %5").arg(cid).arg(currentSegmentaion).arg(ip).arg(boardcardid).arg(boardcardpos)) );
}

void BCCommunication::SetIPVedioSegmentation(int cid, int segmentation, int boardcardid, int boardcardpos)
{
    SendCmd( EncodeStandardJson("SetIPVedioSegmentation", QString("%1 %2 %3 %4").arg(cid).arg(segmentation).arg(boardcardid).arg(boardcardpos)) );
}

void BCCommunication::SetSubTitles(int visible, int beginChid, int endChid, int r, int g, int b, int posx, int posy, const QString &text)
{
    SendCmd( EncodeStandardJson("SetSubtitles", QString("%1 %2 %3 %4 %5 %6 %7 %8 %9")
                                .arg(visible).arg(beginChid).arg(endChid).arg(r).arg(g).arg(b).arg(posx).arg(posy).arg(text)) );
}

void BCCommunication::SetCutArea(int chid, int left, int right, int top, int bottom)
{
    SendCmd( EncodeStandardJson("CutChannelArea", QString("%1 %2 %3 %4 %5").arg(chid).arg(left).arg(right).arg(top).arg(bottom)) );
}

void BCCommunication::UpdateInputChannel(int userid, int chid, int chtype, const QString &text)
{
    SendCmd( EncodeStandardJson("UpdateInputChannel", QString("%1 %2 %3 %4").arg(userid).arg(chid).arg(chtype).arg(text)) );
}

void BCCommunication::UpdateSceneSort(int roomid, int groupid, QMap<int, int> map)
{
    MainWindow *pMainWindow = BCCommon::Application();
    BCSUser *pCurrentUser = pMainWindow->GetCurrentUser();
    if (NULL == pCurrentUser)
        return;

    SendCmd( EncodeSceneSortJson(pCurrentUser->id, roomid, groupid, map) );
}

void BCCommunication::ModifyUser(int id, const QString &usr, const QString &psw)
{
    SendCmd( EncodeStandardJson("ModifyUser", QString("%1 %2 %3").arg(id).arg(usr).arg(psw)) );
}

void BCCommunication::RequestControlBySignalWindow(int groupid, int chid, int chtype, int winid)
{
    SendCmd( EncodeStandardJson("requestControlBySignalWindow", QString("%1 %2 %3 %4").arg(groupid).arg(chid).arg(chtype).arg(winid)) );
}

void BCCommunication::RequestControlByGroupScene(int roomid, int groupsceneid)
{
    SendCmd( EncodeStandardJson("requestControlByGroupScene", QString("%1 %2").arg(roomid).arg(groupsceneid)) );
}

void BCCommunication::RequestControlByFloorPlanning(int roomid, int groupsceneid)
{
    SendCmd( EncodeStandardJson("requestControlByFloorPlanning", QString("%1 %2").arg(roomid).arg(groupsceneid)) );
}

void BCCommunication::RequestOver(int roomid)
{
    qDebug() << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~````";
    SendCmd( EncodeStandardJson("over", QString::number(roomid)) );
}

// **************************************************************************************************************
QString BCCommunication::EncodeSceneJson(const QString &k, sWindowScene swindowscene, int roomid, int groupsceneid)
{
    QJsonObject json;
    json.insert("cmdKey", k);

    QJsonObject jsonScene;
    jsonScene.insert("roomid", roomid);
    jsonScene.insert("groupsceneid", groupsceneid);

    jsonScene.insert("id", swindowscene.id);
    jsonScene.insert("iscycle", swindowscene.cycle);
    jsonScene.insert("name", swindowscene.name);

    // 6.添加场景数据
    QJsonArray arrSceneData;
    for (int l = 0; l < swindowscene.lstData.count(); l++) {
        sWindowSceneData swindowscenedata = swindowscene.lstData.at( l );

        // 构造屏组对象
        QJsonObject jsonSceneData;
        jsonSceneData.insert("roomid", roomid);
        jsonSceneData.insert("groupsceneid", groupsceneid);
        jsonSceneData.insert("sceneid", swindowscene.id);
        jsonSceneData.insert("groupdisplayid", swindowscenedata.groupdisplayid);
        jsonSceneData.insert("channelid", swindowscenedata.chid);
        jsonSceneData.insert("channeltype", swindowscenedata.chtype);
        jsonSceneData.insert("copyindex", swindowscenedata.copyIndex);
        jsonSceneData.insert("left", swindowscenedata.left);
        jsonSceneData.insert("top", swindowscenedata.top);
        jsonSceneData.insert("width", swindowscenedata.width);
        jsonSceneData.insert("height", swindowscenedata.height);
        jsonSceneData.insert("ipvsegmentation", swindowscenedata.ipvSegmentation);
        jsonSceneData.insert("ipvip1", swindowscenedata.lstIP.at(0));
        jsonSceneData.insert("ipvip2", swindowscenedata.lstIP.at(1));
        jsonSceneData.insert("ipvip3", swindowscenedata.lstIP.at(2));
        jsonSceneData.insert("ipvip4", swindowscenedata.lstIP.at(3));
        jsonSceneData.insert("ipvip5", swindowscenedata.lstIP.at(4));
        jsonSceneData.insert("ipvip6", swindowscenedata.lstIP.at(5));
        jsonSceneData.insert("ipvip7", swindowscenedata.lstIP.at(6));
        jsonSceneData.insert("ipvip8", swindowscenedata.lstIP.at(7));
        jsonSceneData.insert("ipvip9", swindowscenedata.lstIP.at(8));
        jsonSceneData.insert("ipvip10", swindowscenedata.lstIP.at(9));
        jsonSceneData.insert("ipvip11", swindowscenedata.lstIP.at(10));
        jsonSceneData.insert("ipvip12", swindowscenedata.lstIP.at(11));
        jsonSceneData.insert("ipvip13", swindowscenedata.lstIP.at(12));
        jsonSceneData.insert("ipvip14", swindowscenedata.lstIP.at(13));
        jsonSceneData.insert("ipvip15", swindowscenedata.lstIP.at(14));
        jsonSceneData.insert("ipvip16", swindowscenedata.lstIP.at(15));
        jsonSceneData.insert("winid", swindowscenedata.winid);

        arrSceneData.append( jsonSceneData );
    }

    // 在房间属性sceneDatas下添加场景
    jsonScene.insert("sceneDatas", arrSceneData);

    json.insert("cmdValue", jsonScene);

    QJsonDocument document;
    document.setObject(json);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);

    QString cmdValue = QString::fromLocal8Bit( byte_array ) + CMDOVERFLAG;
    return cmdValue;
}

// **************************************************************************************************************

QString BCCommunication::EncodeStandardJson(const QString &k, const QString &v)
{
    QJsonObject json;
    json.insert("cmdKey", k);
    json.insert("cmdValue", v);

    QJsonDocument document;
    document.setObject(json);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);

    QString cmdValue = QString::fromLocal8Bit( byte_array ) + CMDOVERFLAG;
    return cmdValue;
}

QString BCCommunication::GetJsonValueByKey(const QString &json, const QString &key, QString valueKey)
{
    QJsonParseError json_error;
    QJsonDocument parse_doucment = QJsonDocument::fromJson(json.toLocal8Bit(), &json_error);
    if(json_error.error != QJsonParseError::NoError)
        return QString::null;

    if( !parse_doucment.isObject() )
        return QString::null;

    QJsonObject obj = parse_doucment.object();
    if( !obj.contains("cmdKey") )
        return QString::null;

    QJsonValue cmdValue = obj.take("cmdKey");
    if( !cmdValue.isString() )
        return QString::null;

    if (key != cmdValue.toString())
        return QString::null;

    cmdValue = obj.take( valueKey );
    if( !cmdValue.isString() )
        return QString::null;

    return cmdValue.toString();
}

int BCCommunication::GetStandardJsonResult(const QString &json)
{
    QJsonParseError json_error;
    QJsonDocument parse_doucment = QJsonDocument::fromJson(json.toLocal8Bit(), &json_error);
    if(json_error.error != QJsonParseError::NoError)
        return 0;

    if( !parse_doucment.isObject() )
        return 0;

    QJsonObject obj = parse_doucment.object();
    if( !obj.contains("cmdResult") )
        return 0;

    QJsonValue cmdValue = obj.take("cmdResult");
    if( !cmdValue.isString() )
        return 0;

    return cmdValue.toString().toInt();
}

QString BCCommunication::EncodeSceneSortJson(int userid, int roomid, int groupid, QMap<int, int> map)
{
    QJsonObject json;
    json.insert("cmdKey", "UpdateSceneSort");
    json.insert("cmdValue", QString("%1 %2 %3 %4").arg(userid).arg(roomid).arg(groupid).arg(map.keys().count()));

    // 排序场景和顺序
    QString qsSceneSort = QString::null;
    for (int i = 0; i < map.keys().count(); i++) {
        int key = map.keys().at(i);
        int value = map.value(key);
        qsSceneSort.append( QString("%1 %2 ").arg(key).arg(value) );
    }

    // 去掉最后的空格
    if ( !qsSceneSort.isEmpty() ) {
        qsSceneSort = qsSceneSort.left( qsSceneSort.length()-1 );
    }

    json.insert("cmdSort", qsSceneSort);

    QJsonDocument document;
    document.setObject(json);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);

    QString cmdValue = QString::fromLocal8Bit( byte_array ) + CMDOVERFLAG;
    return cmdValue;
}

void BCCommunication::Winsize(int groupid, int chid, int winid, int l, int t, int r, int b, int type, int copyIndex)
{
    SendCmd( EncodeStandardJson("winsize", QString("%1 %2 %3 %4 %5 %6 %7 %8 %9")
                                .arg(groupid)
                                .arg(chid)
                                .arg(winid)
                                .arg(l)
                                .arg(t)
                                .arg(r)
                                .arg(b)
                                .arg(type)
                                .arg(copyIndex)) );
}

void BCCommunication::Reset(const QString &ids)
{
    SendCmd( EncodeStandardJson("reset", ids) );
}

void BCCommunication::ServerWinsize(int groupid, int chid, int chtype, int winid, int l, int t, int r, int b)
{
    // 需要取3个类对象，之后才能开窗
    MainWindow *pApplication = BCCommon::Application();
    BCMRoom *pRoom = pApplication->GetMRoomByGroupDisplayID( groupid );
    if (NULL == pRoom)
        return;

    BCMGroupDisplay *pMGroupDisplay = pRoom->GetGroupDisplay( groupid );
    if (NULL == pMGroupDisplay)
        return;

    BCMChannel *pChannel = pApplication->GetInputChannel(chid, chtype);
    if (NULL == pChannel)
        return;

    // 1.屏组的UI类
    BCGroupDisplayWidget *pGroupDisplay = pMGroupDisplay->GetDisplayWidgetManager();
    if (NULL == pGroupDisplay)
        return;

    // 3.窗口管理类
    BCRoomMainWidget *pSignalManager = pRoom->GetSignalWidgetManager();

    pSignalManager->ServerWinsize(pGroupDisplay, pChannel, winid, l, t, r-l, b-t);
}

void BCCommunication::ServerWinswitch(int groupid, int /*channelid*/, int /*chtype*/, int windowid)
{
    // 需要取3个类对象，之后才能开窗
    MainWindow *pApplication = BCCommon::Application();
    BCMRoom *pRoom = pApplication->GetMRoomByGroupDisplayID( groupid );
    if (NULL == pRoom)
        return;

    BCRoomMainWidget *pSignalManager = pRoom->GetSignalWidgetManager();
    if (NULL == pSignalManager)
        return;

    BCSignalWindowDisplayWidget *pItem = pSignalManager->GetSignalWindowByWindowID( windowid );
    if (NULL == pItem)
        return;

    pSignalManager->ServerWinSwitchResult(true, pItem);
}

void BCCommunication::ServerMoveSignalWindow(int groupid, int /*channelid*/, int /*chtype*/, int windowid)
{
    // 需要取3个类对象，之后才能开窗
    MainWindow *pApplication = BCCommon::Application();
    BCMRoom *pRoom = pApplication->GetMRoomByGroupDisplayID( groupid );
    if (NULL == pRoom)
        return;

    BCRoomMainWidget *pSignalManager = pRoom->GetSignalWidgetManager();
    if (NULL == pSignalManager)
        return;

    BCSignalWindowDisplayWidget *pItem = pSignalManager->GetSignalWindowByWindowID( windowid );
    if (NULL == pItem)
        return;

    pItem->ServerRequestControlResult();
}

void BCCommunication::ServerReset(const QString &ids)
{
    MainWindow *pApplication = BCCommon::Application();

    // ??? 这里其实是按照一个房间一个屏组的方式进行清屏的，如果后续改成一个房间多个屏组，则Manager内函数要改动
    QStringList lstID = ids.split(" ");
    for (int i = 0; i < lstID.count(); i++) {
        QString qsID = lstID.at(i);
        if ( qsID.isEmpty() )
            continue;

        BCMRoom *pRoom = pApplication->GetMRoomByGroupDisplayID( qsID.toInt() );
        if (NULL == pRoom)
            return;

        BCRoomMainWidget *pSignalManager = pRoom->GetSignalWidgetManager();
        if (NULL == pSignalManager)
            return;

        pSignalManager->ServerResetResult( true );
    }
}

void BCCommunication::ServerAddScene(int nRoomID, int nGroupSceneID, sWindowScene swindowscene)
{
    MainWindow *pApplication = BCCommon::Application();
    BCMRoom *pRoom = pApplication->GetMRoom( nRoomID );
    if (NULL == pRoom)
        return;

    // 首先找当前房间内是否有指定ID的场景组
    BCMGroupScene *pGroupScene = pRoom->GetGroupScene( nGroupSceneID );
    if (NULL == pGroupScene)
        return;

    BCMWindowScene *pWindowScene = pGroupScene->GetWindowScene( swindowscene.id );
    if (NULL == pWindowScene)
        pWindowScene = new BCMWindowScene( pGroupScene );
    else
        pWindowScene->Clear( false );

    // 根据服务器返回值设置属性
    pWindowScene->SetWindowSceneID( swindowscene.id );
    pWindowScene->SetIsCycled( (1 == swindowscene.cycle) ? true : false );
    pWindowScene->SetWindowSceneName( swindowscene.name );
    for (int i = 0; i < swindowscene.lstData.count(); i++) {
        sWindowSceneData swindowscenedata = swindowscene.lstData.at( i );

        // 解析属性
        BCWindowSceneData *pSceneData = new BCWindowSceneData;
        pSceneData->m_nScreenGroupID = swindowscenedata.groupdisplayid;
        pSceneData->m_nChannelID = swindowscenedata.chid;
        pSceneData->m_nChannelType = swindowscenedata.chtype;
        pSceneData->m_nCopyIndex = swindowscenedata.copyIndex;
        pSceneData->m_rect = QRectF(swindowscenedata.left,
                                    swindowscenedata.top,
                                    swindowscenedata.width,
                                    swindowscenedata.height);
        pSceneData->m_nIPVSegmentation = swindowscenedata.ipvSegmentation;
        pSceneData->m_nWindowID = swindowscenedata.winid;
        pSceneData->m_lstIP = swindowscenedata.lstIP;

        pWindowScene->AddWindowSceneData( pSceneData );
    }

    // 添加到场景组
    pGroupScene->AddWindowScene( pWindowScene );
}

void BCCommunication::ServerDeleteScene(int nRoomID, int nGroupSceneID, int sceneid)
{
    MainWindow *pApplication = BCCommon::Application();

    BCMRoom *pRoom = pApplication->GetMRoom( nRoomID );
    if (NULL == pRoom)
        return;

    // 首先找当前房间内是否有指定ID的场景组
    BCMGroupScene *pGroupScene = pRoom->GetGroupScene( nGroupSceneID );
    if (NULL == pGroupScene)
        return;

    // 清除场景并删除
    pGroupScene->RemoveWindowScene( sceneid );
}

void BCCommunication::ServerUpdateScene(int nRoomID, int nGroupSceneID, int sceneid, int cycle, const QString &name)
{
    MainWindow *pApplication = BCCommon::Application();
    BCMRoom *pRoom = pApplication->GetMRoom( nRoomID );
    if (NULL == pRoom)
        return;

    // 首先找当前房间内是否有指定ID的场景组
    BCMGroupScene *pGroupScene = pRoom->GetGroupScene( nGroupSceneID );
    if (NULL == pGroupScene)
        return;

    BCMWindowScene *pWindowScene = pGroupScene->GetWindowScene( sceneid );
    if (NULL == pWindowScene)
        return;

    pWindowScene->SetIsCycled((1 == cycle) ? true : false, false);
    pWindowScene->SetWindowSceneName(name, false);
}

void BCCommunication::ServerUpdateScene(int nRoomID, int nGroupSceneID, sWindowScene swindowscene)
{
    MainWindow *pApplication = BCCommon::Application();
    BCMRoom *pRoom = pApplication->GetMRoom( nRoomID );
    if (NULL == pRoom)
        return;

    // 首先找当前房间内是否有指定ID的场景组
    BCMGroupScene *pGroupScene = pRoom->GetGroupScene( nGroupSceneID );
    if (NULL == pGroupScene)
        return;

    BCMWindowScene *pWindowScene = pGroupScene->GetWindowScene( swindowscene.id );
    if (NULL == pWindowScene)
        return;

    pWindowScene->SetIsCycled((1 == swindowscene.cycle) ? true : false, false);
    pWindowScene->SetWindowSceneName(swindowscene.name, false);

    pWindowScene->Clear( false );

    for (int i = 0; i < swindowscene.lstData.count(); i++) {
        sWindowSceneData swindowscenedata = swindowscene.lstData.at( i );

        BCWindowSceneData *pSceneData = new BCWindowSceneData;
        pSceneData->m_nScreenGroupID = swindowscenedata.groupdisplayid;
        pSceneData->m_nChannelID = swindowscenedata.chid;
        pSceneData->m_nChannelType = swindowscenedata.chtype;
        pSceneData->m_nCopyIndex = swindowscenedata.copyIndex;
        pSceneData->m_rect = QRectF(swindowscenedata.left,
                                    swindowscenedata.top,
                                    swindowscenedata.width,
                                    swindowscenedata.height);
        pSceneData->m_nIPVSegmentation = swindowscenedata.ipvSegmentation;
        pSceneData->m_nWindowID = swindowscenedata.winid;
        pSceneData->m_lstIP = swindowscenedata.lstIP;

        pWindowScene->AddWindowSceneData( pSceneData );
    }
}

void BCCommunication::ServerLoadWindowScene(int nGroupDisplayID, int sceneid)
{
    MainWindow *pApplication = BCCommon::Application();
    BCMRoom *pRoom = pApplication->GetMRoom( nGroupDisplayID );
    if (NULL == pRoom)
        return;

    // 首先找当前房间内是否有指定ID的场景组
    BCMGroupScene *pGroupScene = pRoom->GetGroupScene( 0 );
    if (NULL == pGroupScene)
        return;

    BCMWindowScene *pWindowScene = pGroupScene->GetWindowScene( sceneid );
    if (NULL != pWindowScene)
        pWindowScene->Show( false );
}

void BCCommunication::ServerLoopGroupScene(int nRoomID, int nGroupSceneID)
{
    MainWindow *pApplication = BCCommon::Application();
    BCMRoom *pRoom = pApplication->GetMRoom( nRoomID );
    if (NULL == pRoom)
        return;

    pRoom->SetLoopWindowScene( true );

//    // 首先找当前房间内是否有指定ID的场景组
//    BCMGroupScene *pGroupScene = pRoom->GetGroupScene( nGroupSceneID );
//    if (NULL == pGroupScene)
//        return;

//    // 打开场景组轮训
//    pGroupScene->SetLoopWindowScene(true, false);

    // 修改主工具条上按钮的状态
    BCRibbonMainToolBar *pMainToolBar = pApplication->GetRibbonMainToolBar();
    if (NULL == pMainToolBar)
        return;

    // 找到几个按钮，因为需要设置是否可用
    BCRibbonMainToolBarAction *pLoopSceneBtn = pMainToolBar->GetButtonAction( BCRibbonMainToolBar::WINDOWSCENELOOP );
    pLoopSceneBtn->RefreshSceneLoop( pRoom );
}

void BCCommunication::ServerFloorPlanning(int nRoomID, int nGroupSceneID)
{
    MainWindow *pApplication = BCCommon::Application();
    pApplication->ServerFloorPlanningSwitchOn(nRoomID, nGroupSceneID);
}

void BCCommunication::ServerUpdateInputChannel(int chid, int chtype, const QString &text)
{
    MainWindow *pApplication = BCCommon::Application();

    // 修改通道名字
    BCMChannel *pChannel = pApplication->GetInputChannel(chid, chtype);
    if (NULL == pChannel)
        return;

    pChannel->SetChannelName( text );

    // 刷新数据
    BCToolBar *pToolBar = pApplication->GetToolBar( MainWindow::SIGNALSOURCETOOLBAR );
    if (NULL == pToolBar)
        return;

    BCFaceWidget *pSignalSourceWidget = dynamic_cast<BCFaceWidget *>( pToolBar->widget() );
    if (NULL != pSignalSourceWidget)
        pSignalSourceWidget->Refresh( 0 );
}

void BCCommunication::ServerUpdateSceneSort(int roomid, int groupsceneid, QMap<int, int> map)
{
    MainWindow *pApplication = BCCommon::Application();

    BCMRoom *pRoom = pApplication->GetMRoom( roomid );
    if (NULL == pRoom)
        return;

    BCMGroupScene *pGroupScene = pRoom->GetGroupScene( groupsceneid );
    if (NULL == pGroupScene)
        return;

    // 更新场景排序
    pGroupScene->UpdateWindowSceneSort( map );

    // 更新界面
    BCToolBar *pToolBar = pApplication->GetToolBar( MainWindow::SIGNALSOURCETOOLBAR );
    if (NULL == pToolBar)
        return;

    BCFaceWidget *pSignalSourceWidget = dynamic_cast<BCFaceWidget *>( pToolBar->widget() );
    if (NULL != pSignalSourceWidget)
        pSignalSourceWidget->Refresh( 0 );
}

void BCCommunication::RefreshSceneWidget()
{
    MainWindow *pApplication = BCCommon::Application();

    // 刷新数据
    BCToolBar *pToolBar = pApplication->GetToolBar( MainWindow::SIGNALSOURCETOOLBAR );
    if (NULL == pToolBar)
        return;

    BCFaceWidget *pSignalSourceWidget = dynamic_cast<BCFaceWidget *>( pToolBar->widget() );
    if (NULL != pSignalSourceWidget)
        pSignalSourceWidget->Refresh( 0 );
}

sWindowScene BCCommunication::DecodeSceneJson(const QString &json, int &roomid, int &groupsceneid)
{
    sWindowScene swindowscene;
    swindowscene.id = -1;
    swindowscene.cycle = -1;

    QJsonParseError json_error;
    QJsonDocument parse_doucment = QJsonDocument::fromJson(json.toLocal8Bit(), &json_error);
    if(json_error.error != QJsonParseError::NoError)
        return swindowscene;

    if( !parse_doucment.isObject() )
        return swindowscene;

    QJsonObject obj = parse_doucment.object();
    if( !obj.contains("cmdValue") )
        return swindowscene;

    // 这里的cmdValue是数组
    QJsonValue cmdValue = obj.take("cmdValue");
    if( !cmdValue.isObject() )
        return swindowscene;

    QJsonObject objScene = cmdValue.toObject();

    roomid = objScene.value("roomid").toInt();
    groupsceneid = objScene.value("groupsceneid").toInt();

    swindowscene.id = objScene.value("id").toInt();
    swindowscene.cycle = objScene.value("iscycle").toInt();
    swindowscene.name = objScene.value("name").toString();

    // 循环场景数据
    QJsonArray arrSceneDatas = objScene.value("sceneDatas").toArray();
    for (int l = 0; l < arrSceneDatas.count(); l++) {
        QJsonObject jsonSceneData = arrSceneDatas.at(l).toObject();
        if ( jsonSceneData.isEmpty() )
            continue;

        sWindowSceneData swindowscenedata;

        swindowscenedata.groupdisplayid = jsonSceneData.value("groupdisplayid").toInt();
        swindowscenedata.chid = jsonSceneData.value("channelid").toInt();
        swindowscenedata.chtype = jsonSceneData.value("channeltype").toInt();
        swindowscenedata.copyIndex = jsonSceneData.value("copyindex").toInt();
        swindowscenedata.left = jsonSceneData.value("left").toDouble();
        swindowscenedata.top = jsonSceneData.value("top").toDouble();
        swindowscenedata.width = jsonSceneData.value("width").toDouble();
        swindowscenedata.height = jsonSceneData.value("height").toDouble();
        swindowscenedata.ipvSegmentation = jsonSceneData.value("ipvsegmentation").toInt();
        swindowscenedata.winid = jsonSceneData.value("winid").toInt();
        for (int m = 0; m < 36; m++) {
            swindowscenedata.lstIP << jsonSceneData.value(QString("ipvip%1").arg(m+1)).toString();
        }

        // 添加到场景
        swindowscene.lstData.append( swindowscenedata );
    }

    return swindowscene;
}

void BCCommunication::SetIPAndPort(const QString &ip, int port)
{
    m_ip = ip;
    m_port = port;

    m_pSocket->disconnectFromHost();
    QHostAddress hostAddress;
    hostAddress.setAddress( m_ip );
    m_pSocket->connectToHost(hostAddress, m_port);

    m_pSocket->waitForConnected( 50 );
}

int BCCommunication::SendCmd(const QString &cmd)
{
    int nRes = -1;
    if (NULL == m_pSocket)
        return nRes;

    if ( cmd.isEmpty() )
        return nRes;

//    if (QAbstractSocket::UnconnectedState == m_pSocket->state()) {
//        m_pSocket->connectToHost(m_ip, m_port);
//    }

    // 更新执行时间
    m_timeOfPreview = QTime::currentTime();

    qDebug() << "will send: " << cmd << m_pSocket->state();
    nRes = m_pSocket->write( cmd.toLocal8Bit() );
    m_pSocket->flush();

    return nRes;
}
