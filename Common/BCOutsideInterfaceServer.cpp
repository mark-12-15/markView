#include "BCOutsideInterfaceServer.h"
#include "BCCommon.h"
#include "../Model/BCMRoom.h"
#include "../Model/BCMGroupDisplay.h"
#include "BCCommunication.h"
#include "../View/BCRoomWidget.h"
#include "../View/BCSignalWindowDisplayWidget.h"
#include "../Model/BCMGroupScene.h"
#include "../Model/BCMWindowScene.h"
#include "BCLocalServer.h"

BCOutsideInterfaceServer::BCOutsideInterfaceServer()
    :QObject(NULL)
{
    // 判断文件是否可读
    QFile file( QString("../xml/BCOutsideInterfaceChannelMapConfig.xml") );
    if(!file.open(QIODevice::ReadOnly)){
        return;
    }

    // 将文件内容读到QDomDocument中
    QDomDocument doc;
    bool bLoadFile = doc.setContent(&file);
    file.close();

    if ( bLoadFile ) {
        // 二级链表
        QDomElement docElem = doc.documentElement();
        m_qsCurrentCom = docElem.attribute("CurrentCom");
        m_nCurrentBaudRate = docElem.attribute("CurrentBaudRate").toInt();
        m_nCurrentDataBit = docElem.attribute("CurrentDataBit").toInt();
        m_nCurrentStopBit = docElem.attribute("CurrentStopBit").toInt();
        m_qsCurrentCheckBit = docElem.attribute("CurrentCheckBit") ;
        m_qsCurrentStreamCtrl = docElem.attribute("CurrentStreamCtrl");

        for (int i = 0; i < docElem.childNodes().count(); i++) {
            QDomNode node = docElem.childNodes().at(i);
            if ( !node.isElement() )
                continue;

            QDomElement ele = node.toElement();
            int x = ele.attribute("srcID").toInt();
            int y = ele.attribute("targetID").toInt();

            m_lstChannelMap.append( QPoint(x, y) );
        }
    }
}

BCOutsideInterfaceServer::~BCOutsideInterfaceServer()
{
    m_serial.close();

    QFile file( QString("../xml/BCOutsideInterfaceChannelMapConfig.xml") );
    if(!file.open(QIODevice::ReadOnly)){
        return;
    }

    // 将文件内容读到QDomDocument中
    QDomDocument doc;
    bool bLoadFile = doc.setContent(&file);
    file.close();

    if ( !bLoadFile )
        return;

    // 二级链表
    QDomElement docElem = doc.documentElement();
    docElem.setAttribute("CurrentCom", m_qsCurrentCom);
    docElem.setAttribute("CurrentBaudRate", m_nCurrentBaudRate);
    docElem.setAttribute("CurrentDataBit", m_nCurrentDataBit);
    docElem.setAttribute("CurrentStopBit", m_nCurrentStopBit);
    docElem.setAttribute("CurrentCheckBit", m_qsCurrentCheckBit);
    docElem.setAttribute("CurrentStreamCtrl", m_qsCurrentStreamCtrl);

    // 写入文件
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}

// 全局唯一值
BCOutsideInterfaceServer *BCOutsideInterfaceServer::Application()
{
    if (NULL == m_pApplication) {
        m_pApplication = new BCOutsideInterfaceServer();
    }

    return m_pApplication;
}

void BCOutsideInterfaceServer::Destroy()
{
    if (NULL != m_pApplication) {
        delete m_pApplication;
        m_pApplication = NULL;
    }
}

BCOutsideInterfaceServer *BCOutsideInterfaceServer::m_pApplication = NULL;

void BCOutsideInterfaceServer::Connect()
{
    if ( m_serial.isOpen() ) {
        m_serial.close();
    }

    connect(&m_serial, SIGNAL(readyRead()), this, SLOT(onRecvSerialData()));
    m_serial.setPortName( m_qsCurrentCom );	//设置COM口

    m_serial.setBaudRate((QSerialPort::BaudRate)m_nCurrentBaudRate,QSerialPort::AllDirections); //设置波特率和读写方向
    m_serial.setDataBits((QSerialPort::DataBits)m_nCurrentDataBit);		//数据位为8位
    m_serial.setStopBits((QSerialPort::StopBits)m_nCurrentStopBit);     //一位停止位

    QSerialPort::Parity eParity = QSerialPort::NoParity;
    if (m_qsCurrentCheckBit == "Odd")
        eParity = QSerialPort::OddParity;
    else if (m_qsCurrentCheckBit == "Even")
        eParity = QSerialPort::EvenParity;
    else if (m_qsCurrentCheckBit == "Mark")
        eParity = QSerialPort::MarkParity;
    else if (m_qsCurrentCheckBit == "Space")
        eParity = QSerialPort::SpaceParity;

    m_serial.setParity( eParity );	//无校验位

    QSerialPort::FlowControl eFlowControl = QSerialPort::NoFlowControl;
    if (m_qsCurrentStreamCtrl == "Hardware")
        eFlowControl = QSerialPort::HardwareControl;
    else if (m_qsCurrentStreamCtrl == "Software")
        eFlowControl = QSerialPort::SoftwareControl;

    m_serial.setFlowControl( eFlowControl );//无流控制
    m_serial.close();                       //先关串口，再打开，可以保证串口不被其它函数占用。
    m_serial.open(QIODevice::ReadWrite);
}

bool BCOutsideInterfaceServer::IsConnected()
{
    return m_serial.isOpen();
}

void BCOutsideInterfaceServer::onRecvSerialData()
{
    // 添加调试信息使用
    MainWindow *pMainWindow = BCCommon::Application();

    QByteArray byteArr = m_serial.readAll();
    if ( !byteArr.isEmpty() ) {
        QString cmd( byteArr );
        QStringList lstCmd = cmd.split("\r\n"); // ??? 结束符需要确认
        for (int i = 0; i < lstCmd.count(); i++) {
            QString qsSingleCmd = lstCmd.at( i );

            // 判断参数个数
            QStringList lstPara = qsSingleCmd.split(" ");
            if ((7 != lstPara.count()) && (3 != lstPara.count())) {
                pMainWindow->AddDebugCmd( QString("OUTCMD: %1[ERR: PARA COUNT NOT MATCHING]").arg(qsSingleCmd) );
                continue;
            }

            // 判断关键字
            QString qsKey = lstPara.at( 0 );
            qsKey = qsKey.toUpper();
            if ((qsKey != "SWWINSIZE") && (qsKey != "LOAD") && (qsKey != "SAVE")) {
                pMainWindow->AddDebugCmd( QString("OUTCMD: %1[ERR: CMD KEY NOT MATCHING]").arg(qsSingleCmd) );
                continue;
            }

            if (7 == lstPara.count()) {
                // 判断输入通道是否存在
                int chid = lstPara.at( 1 ).toInt();

                // 查找是否有映射ID
                for (int j = 0; j < m_lstChannelMap.count(); j++) {
                    QPoint pt = m_lstChannelMap.at( j );
                    if (pt.x() != chid)
                        continue;

                    chid = pt.y();
                    break;
                }

                BCMChannel *pChannel = pMainWindow->GetInputChannel(chid, -1); // 目前只支持4000
                if (NULL == pChannel) {
                    pMainWindow->AddDebugCmd( QString("OUTCMD: %1[ERR: CHANNEL ID(%2) NOT FIND]").arg(qsSingleCmd).arg(chid) );
                    continue;
                }

                int gid = lstPara.at( 2 ).toInt();
                BCMRoom *pRoom = pMainWindow->GetMRoom( gid );
                if (NULL == pRoom) {
                    pMainWindow->AddDebugCmd( QString("OUTCMD: %1[ERR: GROUP ID NOT FIND]").arg(qsSingleCmd) );
                    continue;
                }

                int l = lstPara.at( 3 ).toInt();
                int t = lstPara.at( 4 ).toInt();
                int r = lstPara.at( 5 ).toInt();
                int b = lstPara.at( 6 ).toInt();

                BCMGroupDisplay *pMGroupDisplay = pRoom->GetGroupDisplay( pRoom->GetRoomID() );
                if (NULL == pMGroupDisplay) {
                    pMainWindow->AddDebugCmd( QString("OUTCMD: %1[ERR: GROUP NOT FIND]").arg(qsSingleCmd) );
                    continue;
                }

                QSizeF wallSize = pRoom->GetWallSize();
                QSize size = pMGroupDisplay->GetArraySize();
                int singleDisplayWidth = wallSize.width() / size.width();
                int singleDisplayHeight = wallSize.height() / size.height();
                if ((l > 0) && (t > 0) && (r > l) && (b > t) && (r <= size.width()+1) && (b <= size.height()+1)) {
                    BCGroupDisplayWidget *pGroupDisplay = pMGroupDisplay->GetDisplayWidgetManager();
                    if (NULL != pGroupDisplay) {
                        BCRoomMainWidget *pSignalManager = pRoom->GetSignalWidgetManager();
                        if (NULL != pSignalManager) {
                            int nl = (l-1) * singleDisplayWidth;
                            int nt = (t-1) * singleDisplayHeight;
                            int nw = (r-l) * singleDisplayWidth;
                            int nh = (b-t) * singleDisplayHeight;

                            // 这里判断是否存在当前位置的窗口，如果存在则替换数据源
                            bool bOpenWindow = true;
                            BCSignalWindowDisplayWidget *pSignalWindow = NULL;
                            QList<BCSignalWindowDisplayWidget *> lstSignalWindows = pSignalManager->GetSignalWindows();
                            for (int j = 0; j < lstSignalWindows.count(); j++) {
                                pSignalWindow = lstSignalWindows.at( j );
                                if (QRect(nl, nt, nw, nh) == pSignalWindow->GetFactRect()) {
                                    bOpenWindow = false;
                                    break;
                                }
                            }

                            if ( bOpenWindow )
                                pSignalManager->AddSignalWindow(nl, nt, nw, nh, pGroupDisplay, pChannel);
                            else {
                                pSignalWindow->SetInputChannel( pChannel );
                            }
                        }
                    }
                } else {
                    pMainWindow->AddDebugCmd( QString("OUTCMD: %1[ERR: PARA INVALID]").arg(qsSingleCmd) );
                }
            } else if (3 == lstPara.count()) {      // load save
                int gid = lstPara.at( 1 ).toInt();
                int sceneid = lstPara.at( 2 ).toInt();
                BCMRoom *pRoom = pMainWindow->GetMRoom( gid );
                if (NULL == pRoom) {
                    pMainWindow->AddDebugCmd( QString("OUTCMD: %1[ERR: GROUP ID NOT FIND]").arg(qsSingleCmd) );
                    continue;
                }

                BCMWindowScene *pWindowScene = NULL;
                QList<BCMGroupScene *> lstGroupScene = pRoom->GetGroupScenes();
                for (int i = 0; i < lstGroupScene.count(); i++) {
                    BCMGroupScene *pGroupScene = lstGroupScene.at( i );
                    pWindowScene = pGroupScene->GetWindowScene( sceneid );

                    if (NULL != pWindowScene)
                        break;
                }

                if (NULL == pWindowScene) {
                    pMainWindow->AddDebugCmd( QString("OUTCMD: %1[ERR: SCENE ID NOT FIND]").arg(qsSingleCmd) );

                    // 如果没有则直接发送指令
                    BCLocalServer *pServer = BCLocalServer::Application();
                    if ("LOAD" == qsKey)
                        pServer->load(gid, sceneid);
                    else
                        pServer->save(gid, sceneid);

                    continue;
                } else {
                    if ("LOAD" == qsKey)
                        pWindowScene->Show();
                    else
                        pWindowScene->Update();
                }
            }
        }
    }
}
