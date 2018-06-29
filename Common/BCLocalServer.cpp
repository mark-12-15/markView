#include "BCLocalServer.h"
#include "BCLocalDatabase.h"
#include <QLibrary>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QNetworkInterface>
#include <QNetworkAddressEntry>
#include "../Common/BCCommon.h"
#include "../Model/BCMRoom.h"
#include "../Model/BCMChannel.h"
#include "../Model/BCMGroupDisplay.h"

BCLocalServer::BCLocalServer()
{
    m_pUdpSocket = NULL;
    m_pUdpSocketVP2000 = NULL;
    m_pTcpSocket = NULL;
    m_pOneSecondTimer = NULL;

    m_bDeviceWorking    = true;
    m_bSynchronization  = false;

    m_bIsLoadDataOK = false;
    m_nIsDemoMode = 2;
    m_nHeartTimes = 0;

    m_timeOfPreview = QTime::currentTime().addMSecs( -10*1000 );

    // 初始化系统参数
    InitCommunicationPara();

    // 必须放在最后初始化，因为需要调用dll接口
    m_pDB = new BCLocalDatabase( this );

    // 1秒定时器，网络连接并且使用DLL时创建,做两件事：
    // 1.如果规模没加载成功则一直判断，直到加载成功为止
    // 2.控制同步，取默认场景
    m_pOneSecondTimer = new QTimer();
    m_pOneSecondTimer->setInterval( 1000 );
    connect(m_pOneSecondTimer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

BCLocalServer::~BCLocalServer()
{
    delete m_pDB;
    m_pDB = NULL;

    // 关闭串口
    m_serial.close();

    // 关闭定时器
    if (NULL != m_pOneSecondTimer) {
        m_pOneSecondTimer->stop();
        m_pOneSecondTimer->deleteLater();
    }

    if (NULL != m_pUdpSocket) {
        m_pUdpSocket->disconnectFromHost();
        m_pUdpSocket->deleteLater();
    }

    if (NULL != m_pUdpSocketVP2000) {
        m_pUdpSocketVP2000->disconnectFromHost();
        m_pUdpSocketVP2000->deleteLater();
    }

    if (NULL != m_pTcpSocket) {
        m_pTcpSocket->disconnectFromHost();
        m_pTcpSocket->deleteLater();
    }
}

BCLocalServer *BCLocalServer::m_pLocalServer = NULL;

BCLocalServer *BCLocalServer::Application()
{
    if (NULL == m_pLocalServer) {
        m_pLocalServer = new BCLocalServer();
    }

    return m_pLocalServer;
}

void BCLocalServer::Destroy()
{
    if (NULL == m_pLocalServer)
        return;

    delete m_pLocalServer;
    m_pLocalServer = NULL;
}

void BCLocalServer::InitCommunicationPara()
{
    // 判断文件是否可读
    QFile file( QString("../xml/BCConnectConfig.xml") );
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

    m_nConfigType = docElem.attribute("ConfigType").toInt();
    m_bIsNetConnect = docElem.attribute("NetConnect").toInt();
    m_qsConnectIPWithoutDLL = docElem.attribute("ConnectIPWithoutDLL");
    m_qsConnectPortWithoutDLL = docElem.attribute("ConnectPortWithoutDLL");
    m_qsCurrentCom = docElem.attribute("CurrentCom");
    m_nCurrentBaudRate = docElem.attribute("CurrentBaudRate").toInt();
    m_nCurrentDataBit = docElem.attribute("CurrentDataBit").toInt();
    m_nCurrentStopBit = docElem.attribute("CurrentStopBit").toInt();
    m_qsCurrentCheckBit = docElem.attribute("CurrentCheckBit") ;
    m_qsCurrentStreamCtrl = docElem.attribute("CurrentStreamCtrl");
}

void BCLocalServer::SetCommunicationPara()
{
    QFile file( QString("../xml/BCConnectConfig.xml") );
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
    docElem.setAttribute("NetConnect", m_bIsNetConnect ? 1 : 0);
    docElem.setAttribute("CurrentCom", m_qsCurrentCom);
    docElem.setAttribute("CurrentBaudRate", m_nCurrentBaudRate);
    docElem.setAttribute("CurrentDataBit", m_nCurrentDataBit);
    docElem.setAttribute("CurrentStopBit", m_nCurrentStopBit);
    docElem.setAttribute("CurrentCheckBit", m_qsCurrentCheckBit);
    docElem.setAttribute("CurrentStreamCtrl", m_qsCurrentStreamCtrl);

    docElem.setAttribute("ConnectIPWithoutDLL", m_qsConnectIPWithoutDLL);
    docElem.setAttribute("ConnectPortWithoutDLL", m_qsConnectPortWithoutDLL);

    // 写入文件
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}

void BCLocalServer::ConnectSerialPort()
{
    if ( m_serial.isOpen() ) {
        BCCommon::g_bConnectStatusOK = true;
        return;
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
    BCCommon::g_bConnectStatusOK = m_serial.open(QIODevice::ReadWrite);
}

void BCLocalServer::SingleSync()
{
//    MainWindow *pApplication = BCCommon::Application();
//    BCMRoom *pRoom = pApplication->GetCurrentMRoom();
//    QListIterator<BCMGroupDisplay *> it ( pRoom->GetGroupDisplay() );
//    while ( it.hasNext() ) {
//        BCMGroupDisplay *pGroupDisplay = it.next();
//        int gid = pGroupDisplay->GetGroupDisplayID();

//        BSWindowSceneData *pSignalWindowData = GetDefaultScene( gid );
//        while (NULL != pSignalWindowData) {
//            QStringList lstIP;
//            for (int i = 0; i < 16; i++) {
//                lstIP.append( QString(pSignalWindowData->cIPVeioIP[i]) );
//            }
//            ServerWinsize(gid,
//                          pSignalWindowData->cid,
//                          pSignalWindowData->ctype,
//                          pSignalWindowData->winid,
//                          pSignalWindowData->left,
//                          pSignalWindowData->top,
//                          pSignalWindowData->width+pSignalWindowData->left,
//                          pSignalWindowData->height+pSignalWindowData->top,
//                          pSignalWindowData->nIPVSegmentation,
//                          lstIP);

//            pSignalWindowData = pSignalWindowData->pNext;
//        }
//    }
}

void BCLocalServer::InitDataBaseData()
{
    // 初始化标志位
    m_bIsLoadDataOK = false;
    if (NULL != m_pUdpSocket) {
        m_pUdpSocket->close();
    }
    if (NULL != m_pUdpSocketVP2000) {
        m_pUdpSocketVP2000->close();
    }
    if (NULL != m_pTcpSocket) {
        m_pTcpSocket->close();
    }
    m_serial.close();

    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode) {
        m_bIsLoadDataOK = true;
        return;
    }

    // 如果是服务器则加载数据
    if ( BCCommon::g_bConnectWithServer ) {
        MainWindow *pApplication = BCCommon::Application();
        pApplication->LoadDataFromServer();

        return;
    } else {
        m_pDB->InitDataBaseData();  // 重新加载DLL数据
    }
}

void BCLocalServer::SetLoadDataOK()
{
    m_bIsLoadDataOK = true;

    if (0 == m_nIsDemoMode)
        return;

    if ( BCCommon::g_bConnectWithServer ) {
        m_pOneSecondTimer->start();
        return;
    }

    if ( m_bIsNetConnect ) {
        // 搜索设备的UDP
        if ((1 == BCCommon::g_nDeviceType) || (2 == BCCommon::g_nDeviceType)) {
            if (NULL == m_pUdpSocket) {
                m_pUdpSocket = new QUdpSocket(this);
                m_pUdpSocket->bind(1500, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
                connect(m_pUdpSocket, SIGNAL(readyRead()), this, SLOT(onRecvUdpData()));
            }
        } else {
            if (NULL == m_pUdpSocketVP2000) {
                m_pUdpSocketVP2000 = new QUdpSocket(this);
                m_pUdpSocketVP2000->connectToHost(QHostAddress(m_qsConnectIPWithoutDLL), 9800);
                connect(m_pUdpSocketVP2000, SIGNAL(readyRead()), this, SLOT(onRecvUdpData2000()));
            }
        }

        if (NULL == m_pTcpSocket) {
            m_pTcpSocket = new QTcpSocket();
            m_pTcpSocket->setSocketOption(QAbstractSocket::KeepAliveOption, 1);
            connect(m_pTcpSocket, SIGNAL(readyRead()), this, SLOT(onRecvTcpData()));
        }

        // 每次到这里都重新进行连接
        m_pTcpSocket->connectToHost(QHostAddress(m_qsConnectIPWithoutDLL), m_qsConnectPortWithoutDLL.toInt());
        m_pTcpSocket->waitForConnected( 500 );

        if (m_pTcpSocket->ConnectedState == QAbstractSocket::ConnectedState) {
            BCCommon::g_bConnectStatusOK = true;
        } else {
            BCCommon::g_bConnectStatusOK = false;
        }
    } else {
        // 设置的时候直接连接串口
        ConnectSerialPort();

        this->AddLog( QString("[LOADDATA OK. SERIALPORT CONNECTED.]" ) );
    }

    m_pOneSecondTimer->start();
}

void BCLocalServer::SetDemoLoadDataOK()
{
    m_nIsDemoMode = 1;
    m_bIsLoadDataOK = true;

    if ( m_bIsNetConnect ) {
        if (NULL == m_pTcpSocket) {
            m_pTcpSocket = new QTcpSocket();
            m_pTcpSocket->setSocketOption(QAbstractSocket::KeepAliveOption, 0);
            connect(m_pTcpSocket, SIGNAL(readyRead()), this, SLOT(onRecvTcpData()));
        }

        // 每次到这里都重新进行连接
        m_pTcpSocket->connectToHost(QHostAddress(m_qsConnectIPWithoutDLL), m_qsConnectPortWithoutDLL.toInt());
        m_pTcpSocket->waitForConnected( 500 );

        if (m_pTcpSocket->ConnectedState == QAbstractSocket::ConnectedState) {
            BCCommon::g_bConnectStatusOK = true;
        } else {
            BCCommon::g_bConnectStatusOK = false;
        }

        //qDebug() << m_qsConnectIPWithoutDLL << m_qsConnectPortWithoutDLL << BCCommon::g_bConnectStatusOK;
    } else {
        // 设置的时候直接连接串口
        ConnectSerialPort();

        this->AddLog( QString("[LOADDATA OK. SERIALPORT CONNECTED.]" ) );
    }

    m_pOneSecondTimer->start();
}

void BCLocalServer::DisConnect()
{
    if (0 == m_nIsDemoMode)
        return;

    m_pOneSecondTimer->stop();

    if (NULL != m_pTcpSocket) {
        m_pTcpSocket->disconnectFromHost();
        m_pTcpSocket->waitForDisconnected( 500 );
    }

    m_serial.close();

    BCCommon::g_bConnectStatusOK = false;

    // 刷新连接状态
    MainWindow *pMainWindow = BCCommon::Application();
    pMainWindow->RefreshStatusBar();
}

void BCLocalServer::ReConnect()
{
    if (0 == m_nIsDemoMode)
        return;

    if ( m_bIsNetConnect ) {
        m_pTcpSocket->connectToHost(QHostAddress(m_qsConnectIPWithoutDLL), m_qsConnectPortWithoutDLL.toInt());
        m_pTcpSocket->waitForConnected( 500 );

        if (m_pTcpSocket->state() == QAbstractSocket::ConnectedState) {
            BCCommon::g_bConnectStatusOK = true;
        }
    } else {
        ConnectSerialPort();
    }

    // 刷新连接状态
    MainWindow *pMainWindow = BCCommon::Application();
    pMainWindow->RefreshStatusBar();

    m_pOneSecondTimer->start();
}

void BCLocalServer::onRecvSerialData()
{
    m_nHeartTimes = 0;
    BCCommon::g_bConnectStatusOK = true;
}

void BCLocalServer::onRecvTcpData()
{
    // 只对2000起作用
//    if ((1 == BCCommon::g_nDeviceType) || (2 == BCCommon::g_nDeviceType))
//        return;

    m_nHeartTimes = 0;
    //qDebug() << "recv ip " << m_nHeartTimes << "~~~~~~~~~~~~~";

    if ( !BCCommon::g_bConnectStatusOK ) {
        m_pTcpSocket->connectToHost(QHostAddress(m_qsConnectIPWithoutDLL), m_qsConnectPortWithoutDLL.toInt());
        m_pTcpSocket->waitForConnected( 500 );

        if (m_pTcpSocket->state() == QAbstractSocket::ConnectedState) {
            BCCommon::g_bConnectStatusOK = true;
        }
    }
}

// 接收UDP信息
void BCLocalServer::onRecvUdpData()
{
    while(m_pUdpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(m_pUdpSocket->pendingDatagramSize());

        unsigned char tmpbuf[4096];
        int bread = m_pUdpSocket->readDatagram((char *)tmpbuf, 256);

        // 如果是关闭通信之后可能会还会进入到UDP广播中，因为之前的缓存数据没有过来，这里需要根据定时器的状态进行判断
        if ( !m_pOneSecondTimer->isActive() )
            continue;

        //qDebug() << tmpbuf[0] << tmpbuf[1] << tmpbuf[2] << bread;
        if ((tmpbuf[0]==0xff)&&(tmpbuf[1]==0x24)&&(tmpbuf[2]==0x01)&&(bread==0x24)) {
            // 9~14为设备的Mac地址，根据这个可以获得设备的信息
            QString qsMac = QString("%1-%2-%3-%4-%5-%6").arg(QString::number(tmpbuf[9], 16)).arg(QString::number(tmpbuf[10], 16)).arg(QString::number(tmpbuf[11], 16))
                    .arg(QString::number(tmpbuf[12], 16)).arg(QString::number(tmpbuf[13], 16)).arg(QString::number(tmpbuf[14], 16));

            // 只判断当前设备
            if (m_qsConnectMacWithoutDLL == qsMac) {
                m_nHeartTimes = 0;
                //qDebug() << "vp4000 udp recv " << m_nHeartTimes;

                if ( !BCCommon::g_bConnectStatusOK ) {
                    m_pTcpSocket->connectToHost(QHostAddress(m_qsConnectIPWithoutDLL), m_qsConnectPortWithoutDLL.toInt());
                    m_pTcpSocket->waitForConnected( 500 );

                    if (m_pTcpSocket->state() == QAbstractSocket::ConnectedState) {
                        BCCommon::g_bConnectStatusOK = true;
                    }
                }
            }
        }
    }
}

// 接收UDP信息
void BCLocalServer::onRecvUdpData2000()
{
    while(m_pUdpSocketVP2000->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(m_pUdpSocketVP2000->pendingDatagramSize());

        unsigned char tmpbuf[4096];
        m_pUdpSocketVP2000->readDatagram((char *)tmpbuf, 256);

        // 只对2000起作用
        if ((1 == BCCommon::g_nDeviceType) || (2 == BCCommon::g_nDeviceType))
            return;

        m_nHeartTimes = 0;

        if ( !BCCommon::g_bConnectStatusOK ) {
            m_pTcpSocket->connectToHost(QHostAddress(m_qsConnectIPWithoutDLL), m_qsConnectPortWithoutDLL.toInt());
            m_pTcpSocket->waitForConnected( 500 );

            if (m_pTcpSocket->state() == QAbstractSocket::ConnectedState) {
                BCCommon::g_bConnectStatusOK = true;
            }
        }
    }
}

void BCLocalServer::onTimeout()
{
    // 如果小于10秒钟没必要执行
    int nOffsetTime = m_timeOfPreview.msecsTo( QTime::currentTime() );
    if (nOffsetTime < 2*1000)
        return;

    m_nHeartTimes++;

    if ((1 == BCCommon::g_nDeviceType) || (2 == BCCommon::g_nDeviceType)) {
//        if ( m_bIsNetConnect ) {
//            if (NULL != m_pUdpSocket) {
//                unsigned char ssmsg_user_k2[4];
//                ssmsg_user_k2[0] = 0xff;
//                ssmsg_user_k2[1] = 0x01;
//                ssmsg_user_k2[2] = 0x01;
//                ssmsg_user_k2[3] = 0x02;

//                m_pUdpSocket->writeDatagram((char*)ssmsg_user_k2, 4, QHostAddress::Broadcast, 1500);//将data中的数据发送
//                //qDebug() << "vp4000 send udp " << m_nHeartTimes;
//            }
//        } else {
//            SendCmd("ip\r\n", false);   // 发送id作为串口心跳包
//        }

        SendCmd("ip\r\n", false);   // 发送id作为串口心跳包

        //qDebug() << "send ip " << m_nHeartTimes;

        if (m_nHeartTimes > 5) {
            BCCommon::g_bConnectStatusOK = false;

            // 如果断开则主动关闭
            if ( m_bIsNetConnect ) {
                if ( m_pTcpSocket->state() == QAbstractSocket::ConnectedState ) {
                    m_pTcpSocket->disconnectFromHost();
                    m_pTcpSocket->waitForDisconnected(50);
                }
            } else {
                m_serial.close();
            }

            if ( m_bIsNetConnect ) {
                m_pTcpSocket->connectToHost(QHostAddress(m_qsConnectIPWithoutDLL), m_qsConnectPortWithoutDLL.toInt());
                m_pTcpSocket->waitForConnected( 500 );
            } else {
                ConnectSerialPort();
            }
        }
    }

    if (0 == BCCommon::g_nDeviceType) {
//        if ( m_bIsNetConnect ) {
//            if (NULL != m_pUdpSocketVP2000) {
//                m_pUdpSocketVP2000->write("id\r\n");
//                m_pUdpSocketVP2000->waitForBytesWritten(50);
//            }
//        } else {
//            SendCmd("id\r\n", false);   // 发送id作为串口心跳包
//        }

        SendCmd("id\r\n", false);   // 发送id作为串口心跳包

        if (m_nHeartTimes > 10) {
            BCCommon::g_bConnectStatusOK = false;

            // 如果断开则主动关闭
            if ( m_bIsNetConnect ) {
                if ( m_pTcpSocket->state() == QAbstractSocket::ConnectedState ) {
                    m_pTcpSocket->disconnectFromHost();
                    m_pTcpSocket->waitForDisconnected(50);
                }
            } else {
                m_serial.close();
            }

            if ( m_bIsNetConnect ) {
                m_pTcpSocket->connectToHost(QHostAddress(m_qsConnectIPWithoutDLL), m_qsConnectPortWithoutDLL.toInt());
                m_pTcpSocket->waitForConnected( 500 );
            } else {
                ConnectSerialPort();
            }
        }
    }

    // 刷新连接状态
    MainWindow *pMainWindow = BCCommon::Application();
    pMainWindow->RefreshStatusBar();
}

void BCLocalServer::SetSynchronization(bool b)
{

}

QPoint BCLocalServer::Authenticate(const QString &usr, const QString &pwd)
{
    return m_pDB->Authenticate(usr, pwd);
}

// 添加场景组
void BCLocalServer::AddGroupScene(int id, int nRoomID,int nIsNormalLoop,  int nIsLoop, int nLoopInterval, const QString &qsName)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    MainWindow *pMainWindow = BCCommon::Application();
    BCSUser *pCurrentUser = pMainWindow->GetCurrentUser();
    if (NULL == pCurrentUser)
        return;

    m_pDB->AddGroupScene(pCurrentUser->id, m_qsConnectIPWithoutDLL, id, nRoomID, nIsNormalLoop, nIsLoop, nLoopInterval, qsName);
}

// 添加场景
void BCLocalServer::AddScene(int id, int nRoomID, int nGroupSceneID, int nIsCycle, const QString &qsName, int nLoopInterval)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    MainWindow *pMainWindow = BCCommon::Application();
    BCSUser *pCurrentUser = pMainWindow->GetCurrentUser();
    if (NULL == pCurrentUser)
        return;

    m_pDB->AddScene(pCurrentUser->id, m_qsConnectIPWithoutDLL, id, nRoomID, nGroupSceneID, nIsCycle, qsName, nLoopInterval);
}

// 添加场景数据
void BCLocalServer::AddSceneData(int nRoomID, int nGroupSceneID, int nSceneID, int nGroupDisplayID, int nChannelID, int nChannelType, int nCopyIndex, int nLeft, int nTop, int nWidth, int nHeight,
                                 int nIPVSegmentationCount, QStringList lstIPVIP, const QString &title, int winid)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    MainWindow *pMainWindow = BCCommon::Application();
    BCSUser *pCurrentUser = pMainWindow->GetCurrentUser();
    if (NULL == pCurrentUser)
        return;

    m_pDB->AddSceneData(m_qsConnectIPWithoutDLL, nRoomID, nGroupSceneID, nSceneID, nGroupDisplayID, nChannelID, nChannelType, nCopyIndex, nLeft, nTop, nWidth, nHeight, nIPVSegmentationCount, lstIPVIP, title, winid);
}

// 删除场景组
void BCLocalServer::RemoveGroupScene(int nRoomID, int nGroupID)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    m_pDB->RemoveGroupScene(m_qsConnectIPWithoutDLL, nRoomID, nGroupID);
}

// 删除场景
void BCLocalServer::RemoveScene(int nRoomID, int nGroupID, int nSceneID)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    m_pDB->RemoveScene(m_qsConnectIPWithoutDLL, nRoomID, nGroupID, nSceneID);
}

// 删除场景数据
void BCLocalServer::RemoveSceneData(int nRoomID, int nGroupID, int nSceneID)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    m_pDB->RemoveSceneData(m_qsConnectIPWithoutDLL, nRoomID, nGroupID, nSceneID);
}

// 更新场景组
void BCLocalServer::UpdateGroupScene(int id, int nRoomID, int nIsNormalLoop, int nIsLoop, int nLoopInterval, const QString &qsName)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    MainWindow *pMainWindow = BCCommon::Application();
    BCSUser *pCurrentUser = pMainWindow->GetCurrentUser();
    if (NULL == pCurrentUser)
        return;

    m_pDB->UpdateGroupScene(pCurrentUser->id, m_qsConnectIPWithoutDLL, id, nRoomID, nIsNormalLoop, nIsLoop, nLoopInterval, qsName);
}

// 更新场景
void BCLocalServer::UpdateScene(int id, int nRoomID, int nGroupSceneID, int nIsCycle, const QString &qsName, int nLoopInterval)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    MainWindow *pMainWindow = BCCommon::Application();
    BCSUser *pCurrentUser = pMainWindow->GetCurrentUser();
    if (NULL == pCurrentUser)
        return;

    m_pDB->UpdateScene(pCurrentUser->id, m_qsConnectIPWithoutDLL, id, nRoomID, nGroupSceneID, nIsCycle, qsName, nLoopInterval);
}

// 添加自定义通道组
void BCLocalServer::AddGroupInputChannel(int id, const QString &qsName)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    MainWindow *pMainWindow = BCCommon::Application();
    BCSUser *pCurrentUser = pMainWindow->GetCurrentUser();
    if (NULL == pCurrentUser)
        return;

    m_pDB->AddGroupInputChannel(pCurrentUser->id, m_qsConnectIPWithoutDLL, id, qsName);
}

// 添加自定义通道中间表
void BCLocalServer::AddGroupInputChannelMid(int id, int type, int groupid, const QString &qsName)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    MainWindow *pMainWindow = BCCommon::Application();
    BCSUser *pCurrentUser = pMainWindow->GetCurrentUser();
    if (NULL == pCurrentUser)
        return;

    m_pDB->AddGroupInputChannelMid(pCurrentUser->id, m_qsConnectIPWithoutDLL, id, type, groupid, qsName);
}

// 删除自定义通道组
void BCLocalServer::RemoveGroupInputChannel(int id)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    MainWindow *pMainWindow = BCCommon::Application();
    BCSUser *pCurrentUser = pMainWindow->GetCurrentUser();
    if (NULL == pCurrentUser)
        return;

    m_pDB->RemoveGroupInputChannel(pCurrentUser->id, m_qsConnectIPWithoutDLL, id);
}

// 更新自定义通道组
void BCLocalServer::UpdateGroupInputChannel(int id, const QString &qsName)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    MainWindow *pMainWindow = BCCommon::Application();
    BCSUser *pCurrentUser = pMainWindow->GetCurrentUser();
    if (NULL == pCurrentUser)
        return;

    m_pDB->UpdateGroupInputChannel(pCurrentUser->id, m_qsConnectIPWithoutDLL, id, qsName);
}

// 更新自定义通道中间表
void BCLocalServer::UpdateGroupInputChannelMid(int id, int type, int groupid, const QString &qsName)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    MainWindow *pMainWindow = BCCommon::Application();
    BCSUser *pCurrentUser = pMainWindow->GetCurrentUser();
    if (NULL == pCurrentUser)
        return;

    m_pDB->UpdateGroupInputChannelMid(pCurrentUser->id, m_qsConnectIPWithoutDLL, id, type, groupid, qsName);
}

void BCLocalServer::UpdateInputChannel(int userid, const QString &deviceip, int id, int type, const QString &qsName)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    m_pDB->UpdateInputChannel(userid, deviceip, id, type, qsName);
}

void BCLocalServer::UpdateRoomName(int id, const QString &qsName)
{
    MainWindow *pMainWindow = BCCommon::Application();
    BCSUser *pCurrentUser = pMainWindow->GetCurrentUser();
    if (NULL == pCurrentUser)
        return;

    m_pDB->UpdateRoomName(pCurrentUser->id, m_qsConnectIPWithoutDLL, id, qsName);
}

void BCLocalServer::UpdateRoomFormat(int roomid, int roomtype, int arrX, int arrY, int resoluX, int resoluY)
{
    m_pDB->UpdateRoomFormat(m_qsConnectIPWithoutDLL, roomid, roomtype, arrX, arrY, resoluX, resoluY);
}

void BCLocalServer::UpdateRoomSwitchConfig(int roomid,
                                           int isNet, const QString &ip, int port, const QString &com, int baudrate, int databit, int stopbit, const QString &checkBit, const QString &streamctrl,
                                           int type, const QString &cmdon, const QString &cmdoff)
{
    m_pDB->UpdateRoomSwitchConfig(m_qsConnectIPWithoutDLL, roomid, isNet, ip, port, com, baudrate, databit, stopbit, checkBit, streamctrl, type, cmdon, cmdoff);
}

void BCLocalServer::UpdateRoomSwitchStatus(int roomid, int n)
{
    m_pDB->UpdateRoomSwitchStatus(m_qsConnectIPWithoutDLL, roomid, n);
}

void BCLocalServer::UpdateRoomConfig(QList<sRoomConfig> lst)
{
    m_pDB->UpdateRoomConfig(m_qsConnectIPWithoutDLL, lst);
}

void BCLocalServer::UpdateRoomVirSize(int id, int useVir, int width, int height, int useVirSeg, int virArrX, int virArrY)
{
    m_pDB->UpdateRoomVirSize(m_qsConnectIPWithoutDLL, id, useVir, width, height, useVirSeg, virArrX, virArrY);
}

void BCLocalServer::UpdateRoomLEDSize(int id, QList<int> lst)
{
    m_pDB->UpdateRoomLEDSize(m_qsConnectIPWithoutDLL, id, lst);
}

void BCLocalServer::UpdateRoomIP(const QString &newIP)
{
    m_pDB->UpdateRoomIP(m_qsConnectIPWithoutDLL, newIP);
}

void BCLocalServer::UpdateInputChannelRemoteIP(int type, int id, const QString &ip)
{
    m_pDB->UpdateInputChannelRemoteIP(m_qsConnectIPWithoutDLL, type, id, ip);
}

void BCLocalServer::UpdateInputChannelSubTitlePower(int type, int id, int power)
{
    m_pDB->UpdateInputChannelSubTitlePower(m_qsConnectIPWithoutDLL, type, id, power);
}

void BCLocalServer::UpdateDisplayBaseInfo(int roomid, int id, const QString &name, int status, const QString &onCmd, const QString &offCmd)
{
    m_pDB->UpdateDisplayBaseInfo(m_qsConnectIPWithoutDLL, roomid, id, name, status, onCmd, offCmd);
}

void BCLocalServer::UpdateSceneSort(int roomid, int groupid, QMap<int, int> map)
{
    MainWindow *pMainWindow = BCCommon::Application();
    BCSUser *pCurrentUser = pMainWindow->GetCurrentUser();
    if (NULL == pCurrentUser)
        return;

    m_pDB->UpdateSceneSort(pCurrentUser->id, m_qsConnectIPWithoutDLL, roomid, groupid, map);
}

QStringList BCLocalServer::GetUsers()
{
    return m_pDB->GetUsers();
}

void BCLocalServer::AddUser(int id, const QString &usr, const QString &psw, int level)
{
    m_pDB->AddUser(id, usr, psw, level);
}

void BCLocalServer::ModifyUser(int id, const QString &usr, const QString &psw, int level)
{
    m_pDB->ModifyUser(id, usr, psw, level);
}

void BCLocalServer::RemoveUser(int id)
{
    m_pDB->RemoveUser( id );
}

QList<sTaskPlanning> BCLocalServer::GetTaskPlanning(int creatorID)
{
    return m_pDB->GetTaskPlanning( creatorID );
}

void BCLocalServer::SetTaskPlanning(QList<sTaskPlanning> lst)
{
    m_pDB->SetTaskPlanning( lst );
}

int BCLocalServer::AddTaskPlanning(sTaskPlanning stask)
{
    return m_pDB->AddTaskPlanning( stask );
}

// 删除任务计划
void BCLocalServer::RemoveTaskPlanning(int id)
{
    m_pDB->RemoveTaskPlanning( id );
}

// 修改任务计划
void BCLocalServer::ModifyTaskPlanning(sTaskPlanning stask)
{
    m_pDB->ModifyTaskPlanning( stask );
}

// 清空任务计划
void BCLocalServer::ClearTaskPlanning()
{
    m_pDB->ClearTaskPlanning();
}

QList<sTab> BCLocalServer::GetUserMainToolBar(int userid)
{
    return m_pDB->GetUserMainToolBar( userid );
}

void BCLocalServer::SetUserMainToolBar(int userid, QList<sTab> lstTab)
{
    m_pDB->SetUserMainToolBar(userid, lstTab);
}

QList<sRoom> BCLocalServer::GetGroupDisplays(int userid, const QString &deviceip)
{
    int roomCount = 1;
    int c = 4;
    int r = 2;
    if (2 != m_nIsDemoMode) {
        QList<sRoom> lstRoom;

        for (int roomIndex = 0; roomIndex < roomCount; roomIndex++) {
            sGroupDisplay sgroupdisplay;
            sgroupdisplay.id = 0;
            sgroupdisplay.left = 0;
            sgroupdisplay.top = 0;
            sgroupdisplay.resolutionX = 1920;
            sgroupdisplay.resolutionY = 1080;
            sgroupdisplay.width = c*1920;
            sgroupdisplay.height = r*1080;
            sgroupdisplay.arrayX = c;
            sgroupdisplay.arrayY = r;
            sgroupdisplay.segmentationX = 2;
            sgroupdisplay.segmentationY = 2;

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    sDisplay sdisplay;
                    sdisplay.id = i*c + j;
                    sdisplay.name = QString("%1").arg(i*c + j, 3, 10, QChar('0'));
                    sdisplay.left = j*1920;
                    sdisplay.top = i*1080;
                    sdisplay.resolutionX = 1920;
                    sdisplay.resolutionY = 1080;
                    sdisplay.segmentation = 4;

                    sgroupdisplay.lstDisplay.append( sdisplay );
                }
            }

            sRoom sroom;
            sroom.id = roomIndex;
            sroom.name = tr("显示拼墙");
            sroom.width = c*1920;
            sroom.height = r*1080;
            sroom.lstGroupDisplay.append( sgroupdisplay );
            sroom.isNetConnect = 1;
            sroom.switchip = "192.168.1.85";
            sroom.switchport = 9000;
            sroom.switchCom = "COM1";
            sroom.switchBaudRate = 9600;
            sroom.switchDataBit = 8;
            sroom.switchStopBit = 1;
            sroom.switchCheckBit = "None";
            sroom.switchStreamCtrl = "None";
            sroom.switchtype = 1;
            sroom.switchoncmd = "";
            sroom.switchoffcmd = "";

            lstRoom.append( sroom );
        }

        return lstRoom;
    }

    return m_pDB->GetGroupDisplays(userid, deviceip);
}

QList<sInputChannel> BCLocalServer::GetInputChannels(int userid, const QString &deviceip)
{
    // 如果是演示模式直接返回
    if (2 != m_nIsDemoMode) {
        QList<sInputChannel> lstData;
        for (int i = 0; i < 8; i++) {
            sInputChannel sinputchannel;
            sinputchannel.id = i;
            sinputchannel.basename = tr("PC%1-").arg(i+1);
            sinputchannel.name = tr("电脑%1").arg(i+1);
            sinputchannel.type = 0;
            sinputchannel.signalsource = 0;
            sinputchannel.cutleft = 0;
            sinputchannel.cutright = 0;
            sinputchannel.cuttop = 0;
            sinputchannel.cutbottom = 0;

            lstData.append( sinputchannel );
        }
        for (int i = 0; i < 4; i++) {
            sInputChannel sinputchannel;
            sinputchannel.id = i+8;
            sinputchannel.basename = tr("IPVideo%1-").arg(i+1);
            sinputchannel.name = tr("IPVideo%1").arg(i+1);
            sinputchannel.type = 1;
            sinputchannel.signalsource = 9;
            sinputchannel.cutleft = 0;
            sinputchannel.cutright = 0;
            sinputchannel.cuttop = 0;
            sinputchannel.cutbottom = 0;

            lstData.append( sinputchannel );
        }
        for (int i = 0; i < 4; i++) {
            sInputChannel sinputchannel;
            sinputchannel.id = i+12;
            sinputchannel.basename = tr("Video%1-").arg(i+1);
            sinputchannel.name = tr("Video%1").arg(i+1);
            sinputchannel.type = 3;
            sinputchannel.signalsource = 8;
            sinputchannel.cutleft = 0;
            sinputchannel.cutright = 0;
            sinputchannel.cuttop = 0;
            sinputchannel.cutbottom = 0;

            lstData.append( sinputchannel );
        }
        for (int i = 0; i < 4; i++) {
            sInputChannel sinputchannel;
            sinputchannel.id = i+16;
            sinputchannel.basename = tr("HD%1-").arg(i+1);
            sinputchannel.name = tr("高清%1").arg(i+1);
            sinputchannel.type = 2;
            sinputchannel.signalsource = 3;
            sinputchannel.cutleft = 0;
            sinputchannel.cutright = 0;
            sinputchannel.cuttop = 0;
            sinputchannel.cutbottom = 0;

            lstData.append( sinputchannel );
        }

        return lstData;
    }

    return m_pDB->GetInputChannels(userid, deviceip);
}

QList<sGroupScene> BCLocalServer::GetGroupScene(int userid, const QString &deviceip, int roomid)
{
    return m_pDB->GetGroupScene(userid, deviceip, roomid);
}

QList<sWindowScene> BCLocalServer::GetWindowScene(int userid, const QString &deviceip, int roomid, int groupid, int sceneid)
{
    return m_pDB->GetWindowScene(userid, deviceip, roomid, groupid, sceneid);
}

QList<sCustomInputChannel> BCLocalServer::GetCustomGroupInputChannels(int userid, const QString &deviceip)
{
    return m_pDB->GetCustomGroupInputChannels(userid, deviceip);
}

QList<sMatrix> BCLocalServer::GetMatrixConfig()
{
    QList<sMatrix> lstRes;

    QFile file( QString("../xml/BCMatrixConfig.xml") );
    if(!file.open(QIODevice::ReadOnly)){
        return lstRes;
    }

    // 将文件内容读到QDomDocument中
    QDomDocument doc;
    bool bLoadFile = doc.setContent(&file);
    file.close();

    if ( !bLoadFile )
        return lstRes;

    // 二级链表
    QDomElement docElem = doc.documentElement();

    // 循环添加矩阵
    for (int i = 0; i < docElem.childNodes().count(); i++) {
        QDomNode nodeRoom = docElem.childNodes().at(i);
        if ( !nodeRoom.isElement() )
            continue;

        sMatrix smatrix;
        QDomElement eleRoom = nodeRoom.toElement();
        smatrix.id = eleRoom.attribute(QString("ID")).toInt();
        smatrix.name = eleRoom.attribute(QString("Name"));
        smatrix.isConnectByNet = eleRoom.attribute(QString("IsConnectByNet")).toInt();
        smatrix.ip = eleRoom.attribute(QString("IP"));
        smatrix.port = eleRoom.attribute(QString("Port")).toInt();
        smatrix.qsCurrentCom = eleRoom.attribute(QString("CurrentCom"));
        smatrix.nCurrentBaudRate = eleRoom.attribute(QString("CurrentBaudRate")).toInt();
        smatrix.nCurrentDataBit = eleRoom.attribute(QString("CurrentDataBit")).toInt();
        smatrix.nCurrentStopBit = eleRoom.attribute(QString("CurrentStopBit")).toInt();
        smatrix.qsCurrentCheckBit = eleRoom.attribute(QString("CurrentCheckBit"));
        smatrix.qsCurrentStreamCtrl = eleRoom.attribute(QString("CurrentStreamCtrl"));
        smatrix.switchFlag = eleRoom.attribute(QString("switchFlag"));
        smatrix.saveFlag = eleRoom.attribute(QString("saveFlag"));
        smatrix.loadFlag = eleRoom.attribute(QString("loadFlag"));
        smatrix.isOn = eleRoom.attribute(QString("isOn")).toInt();
        smatrix.qsOnCmd = eleRoom.attribute(QString("OnCmd"));
        smatrix.qsOffCmd = eleRoom.attribute(QString("OffCmd"));
        smatrix.jointSceneRoomID = eleRoom.attribute(QString("JointSceneRoomID")).toInt();
        smatrix.jointWithVP4000 = eleRoom.attribute(QString("jointWithVP4000")).toInt();
        smatrix.cmdType = eleRoom.attribute(QString("cmdType")).toInt();

        // 循环添加矩阵入口、出口和场景信息
        for (int j = 0; j < eleRoom.childNodes().count(); j++) {
            QDomNode node = eleRoom.childNodes().at(j);
            if ( !node.isElement() )
                continue;

            QDomElement ele = node.toElement();
            QString qsNodeName = node.nodeName();
            if (qsNodeName == "Input") {
                for (int k = 0; k < ele.childNodes().count(); k++) {
                    QDomNode nodeInput = ele.childNodes().at(k);
                    if ( !nodeInput.isElement() )
                        continue;

                    sMatrixNode inputNode;
                    QDomElement eleInput = nodeInput.toElement();
                    inputNode.id = eleInput.attribute(QString("ID")).toInt();
                    inputNode.name = eleInput.attribute(QString("Name"));
                    inputNode.cutl = eleInput.attribute(QString("cutl")).toInt();
                    inputNode.cutr = eleInput.attribute(QString("cutr")).toInt();
                    inputNode.cutt = eleInput.attribute(QString("cutt")).toInt();
                    inputNode.cutb = eleInput.attribute(QString("cutb")).toInt();

                    smatrix.lstInputNode.append( inputNode );
                }
            }
            if (qsNodeName == "Output") {
                for (int k = 0; k < ele.childNodes().count(); k++) {
                    QDomNode nodeOutput = ele.childNodes().at(k);
                    if ( !nodeOutput.isElement() )
                        continue;

                    sMatrixNode outputNode;
                    QDomElement eleOutput = nodeOutput.toElement();
                    outputNode.id = eleOutput.attribute(QString("ID")).toInt();
                    outputNode.name = eleOutput.attribute(QString("Name"));
                    outputNode.nSwitch = eleOutput.attribute(QString("IsSwitch")).toInt();
                    outputNode.nSwitchID = eleOutput.attribute(QString("SwitchID")).toInt();
                    outputNode.isOn = eleOutput.attribute(QString("isOn")).toInt();
                    outputNode.qsOnCmd = eleOutput.attribute(QString("OnCmd"));
                    outputNode.qsOffCmd = eleOutput.attribute(QString("OffCmd"));
                    outputNode.jointWithVP4000ChannelID = eleOutput.attribute(QString("jointWithVP4000ChannelID")).toInt();
                    outputNode.jointWithVP2000ChannelType = eleOutput.attribute(QString("jointWithVP2000ChannelType")).toInt();

                    smatrix.lstOutputNode.append( outputNode );
                }
            }
            if (qsNodeName == "SceneList") {
                for (int k = 0; k < ele.childNodes().count(); k++) {
                    QDomNode nodeScene = ele.childNodes().at(k);
                    if ( !nodeScene.isElement() )
                        continue;

                    sMatrixScene sceneNode;
                    QDomElement eleScene = nodeScene.toElement();
                    sceneNode.id = eleScene.attribute(QString("ID")).toInt();
                    sceneNode.name = eleScene.attribute(QString("Name"));

                    for (int m = 0; m < eleScene.childNodes().count(); m++) {
                        QDomNode nodeSwitch = eleScene.childNodes().at(m);
                        if ( !nodeSwitch.isElement() )
                            continue;

                        QDomElement eleSwitch = nodeSwitch.toElement();
                        int inputID = eleSwitch.attribute(QString("InputID")).toInt();
                        int outputID = eleSwitch.attribute(QString("OutputID")).toInt();
                        sceneNode.lstSwitchInfo.append( QPoint(inputID, outputID) );
                    }

                    smatrix.lstScene.append( sceneNode );
                }
            }
        }

        lstRes.append( smatrix );
    }

    return lstRes;

    // 直接从数据库中取配置信息
    //return m_pDB->GetMatrixConfig();
}

void BCLocalServer::SetMatrixConfig(const QList<sMatrix> lstMatrix)
{
    QDomDocument doc;
    QDomElement eleRoot = doc.createElement(QString("BR"));

    // 循环添加矩阵房间
    for (int i = 0; i < lstMatrix.count(); i++) {
        sMatrix smatrix = lstMatrix.at( i );

        // 房间基本属性
        QDomElement eleRoomNode = doc.createElement(QString("Room"));
        eleRoomNode.setAttribute(QString("ID"), smatrix.id);
        eleRoomNode.setAttribute(QString("Name"), smatrix.name);
        eleRoomNode.setAttribute(QString("IsConnectByNet"), smatrix.isConnectByNet);
        eleRoomNode.setAttribute(QString("IP"), smatrix.ip);
        eleRoomNode.setAttribute(QString("Port"), smatrix.port);
        eleRoomNode.setAttribute(QString("CurrentCom"), smatrix.qsCurrentCom);
        eleRoomNode.setAttribute(QString("CurrentBaudRate"), smatrix.nCurrentBaudRate);
        eleRoomNode.setAttribute(QString("CurrentDataBit"), smatrix.nCurrentDataBit);
        eleRoomNode.setAttribute(QString("CurrentStopBit"), smatrix.nCurrentStopBit);
        eleRoomNode.setAttribute(QString("CurrentCheckBit"), smatrix.qsCurrentCheckBit);
        eleRoomNode.setAttribute(QString("CurrentStreamCtrl"), smatrix.qsCurrentStreamCtrl);
        eleRoomNode.setAttribute(QString("IsOn"), smatrix.isOn);
        eleRoomNode.setAttribute(QString("OnCmd"), smatrix.qsOnCmd);
        eleRoomNode.setAttribute(QString("OffCmd"), smatrix.qsOffCmd);
        eleRoomNode.setAttribute(QString("JointSceneRoomID"), smatrix.jointSceneRoomID);
        eleRoomNode.setAttribute(QString("cmdType"), smatrix.cmdType);
        eleRoomNode.setAttribute(QString("switchFlag"), smatrix.switchFlag);
        eleRoomNode.setAttribute(QString("saveFlag"), smatrix.saveFlag);
        eleRoomNode.setAttribute(QString("loadFlag"), smatrix.loadFlag);
        eleRoomNode.setAttribute(QString("jointWithVP4000"), smatrix.jointWithVP4000);

        // 输入通道
        QDomElement eleInput = doc.createElement(QString("Input"));
        for (int j = 0; j < smatrix.lstInputNode.count(); j++) {
            sMatrixNode inputNode = smatrix.lstInputNode.at( j );
            QDomElement eleInputNode = doc.createElement(QString("Node"));
            eleInputNode.setAttribute(QString("ID"), inputNode.id);
            eleInputNode.setAttribute(QString("Name"), inputNode.name);
            eleInputNode.setAttribute(QString("cutl"), inputNode.cutl);
            eleInputNode.setAttribute(QString("cutr"), inputNode.cutr);
            eleInputNode.setAttribute(QString("cutt"), inputNode.cutt);
            eleInputNode.setAttribute(QString("cutb"), inputNode.cutb);

            eleInput.appendChild( eleInputNode );
        }
        eleRoomNode.appendChild( eleInput );

        // 输出通道
        QDomElement eleOutput = doc.createElement(QString("Output"));
        for (int j = 0; j < smatrix.lstOutputNode.count(); j++) {
            sMatrixNode outputNode = smatrix.lstOutputNode.at( j );
            QDomElement eleOutputNode = doc.createElement(QString("Node"));
            eleOutputNode.setAttribute(QString("ID"), outputNode.id);
            eleOutputNode.setAttribute(QString("Name"), outputNode.name);
            eleOutputNode.setAttribute(QString("IsSwitch"), outputNode.nSwitch);
            eleOutputNode.setAttribute(QString("SwitchID"), outputNode.nSwitchID);
            eleOutputNode.setAttribute(QString("IsOn"), outputNode.isOn);
            eleOutputNode.setAttribute(QString("OnCmd"), outputNode.qsOnCmd);
            eleOutputNode.setAttribute(QString("OffCmd"), outputNode.qsOffCmd);
            eleOutputNode.setAttribute(QString("jointWithVP4000ChannelID"), outputNode.jointWithVP4000ChannelID);
            eleOutputNode.setAttribute(QString("jointWithVP2000ChannelType"), outputNode.jointWithVP2000ChannelType);

            eleOutput.appendChild( eleOutputNode );
        }
        eleRoomNode.appendChild( eleOutput );

        // 场景
        QDomElement eleSceneListNode = doc.createElement(QString("SceneList"));
        for (int j = 0; j < smatrix.lstScene.count(); j++) {
            sMatrixScene sceneNode = smatrix.lstScene.at( j );
            QDomElement eleSceneNode = doc.createElement(QString("Scene"));
            eleSceneNode.setAttribute(QString("ID"), sceneNode.id);
            eleSceneNode.setAttribute(QString("Name"), sceneNode.name);

            // 场景切换信息
            for (int k = 0; k < sceneNode.lstSwitchInfo.count(); k++) {
                QPoint switchPt = sceneNode.lstSwitchInfo.at( k );
                QDomElement eleSwitchNode = doc.createElement(QString("Node"));
                eleSwitchNode.setAttribute(QString("InputID"), switchPt.x());
                eleSwitchNode.setAttribute(QString("OutputID"), switchPt.y());

                eleSceneNode.appendChild( eleSwitchNode );
            }

            eleSceneListNode.appendChild( eleSceneNode );
        }
        eleRoomNode.appendChild( eleSceneListNode );

        eleRoot.appendChild( eleRoomNode );
    }

    // 添加根节点
    doc.appendChild( eleRoot );

    // 写入文件
    QFile file( QString("../xml/BCMatrixConfig.xml") );
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();

    // 直接从数据库中取配置信息
    //m_pDB->SetMatrixConfig( lstMatrix );
}

void BCLocalServer::SetMatrixName(int roomid, int output, int id, const QString &name)
{
    QFile file( QString("../xml/BCMatrixConfig.xml") );
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

    // 循环矩阵房间
    for (int i = 0; i < docElem.childNodes().count(); i++) {
        QDomNode nodeRoom = docElem.childNodes().at(i);
        if ( !nodeRoom.isElement() )
            continue;

        QDomElement eleRoom = nodeRoom.toElement();
        int nRoomID = eleRoom.attribute("ID").toInt();
        if (nRoomID != roomid)
            continue;

        // 循环节点
        for (int j = 0; j < eleRoom.childNodes().count(); j++) {
            QDomNode nodeIO = eleRoom.childNodes().at(j);
            if ( !nodeIO.isElement() )
                continue;

            QDomElement eleIO = nodeIO.toElement();
            QString qsNodeIOName = (0 == output) ? "Input" : "Output";
            if (qsNodeIOName != eleIO.nodeName())
                continue;

            for (int k = 0; k < eleIO.childNodes().count(); k++) {
                QDomNode node = eleIO.childNodes().at(k);
                if ( !node.isElement() )
                    continue;

                QDomElement ele = node.toElement();
                int nNodeID = ele.attribute("ID").toInt();
                if (nNodeID != id)
                    continue;

                ele.setAttribute("Name", name);
            }
        }
    }

    // 写入文件
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}

void BCLocalServer::AddMatrixScene(int roomid, int id, const QString &name, QList<QPoint> lst)
{
    QFile file( QString("../xml/BCMatrixConfig.xml") );
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

    // 循环矩阵房间
    for (int i = 0; i < docElem.childNodes().count(); i++) {
        QDomNode nodeRoom = docElem.childNodes().at(i);
        if ( !nodeRoom.isElement() )
            continue;

        QDomElement eleRoom = nodeRoom.toElement();
        int nRoomID = eleRoom.attribute("ID").toInt();
        if (nRoomID != roomid)
            continue;

        // 循环节点
        for (int j = 0; j < eleRoom.childNodes().count(); j++) {
            QDomNode nodeSceneList = eleRoom.childNodes().at(j);
            if ( !nodeSceneList.isElement() )
                continue;

            QDomElement eleSceneList = nodeSceneList.toElement();
            if ("SceneList" != eleSceneList.nodeName())
                continue;

            // 查找是否有场景节点，有则删除
            for (int k = 0; k < eleSceneList.childNodes().count(); k++) {
                QDomNode nodeScene = eleSceneList.childNodes().at(k);
                if ( !nodeScene.isElement() )
                    continue;

                QDomElement eleScene = nodeScene.toElement();
                int nSceneID = eleScene.attribute("ID").toInt();
                if (nSceneID != id)
                    continue;

                eleSceneList.removeChild( nodeScene );
            }

            // 新建场景并添加
            QDomElement eleSceneNode = doc.createElement(QString("Scene"));
            eleSceneNode.setAttribute(QString("ID"), id);
            eleSceneNode.setAttribute(QString("Name"), name);
            for (int k = 0; k < lst.count(); k++) {
                QPoint pt = lst.at(k);
                QDomElement eleSceneDataNode = doc.createElement(QString("Node"));
                eleSceneDataNode.setAttribute(QString("InputID"), pt.x());
                eleSceneDataNode.setAttribute(QString("OutputID"), pt.y());

                eleSceneNode.appendChild( eleSceneDataNode );
            }

            eleSceneList.appendChild( eleSceneNode );
        }
    }

    // 写入文件
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}

void BCLocalServer::UpdateMatrixScene(int roomid, int id, QList<QPoint> lst)
{
    QFile file( QString("../xml/BCMatrixConfig.xml") );
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

    // 循环矩阵房间
    for (int i = 0; i < docElem.childNodes().count(); i++) {
        QDomNode nodeRoom = docElem.childNodes().at(i);
        if ( !nodeRoom.isElement() )
            continue;

        QDomElement eleRoom = nodeRoom.toElement();
        int nRoomID = eleRoom.attribute("ID").toInt();
        if (nRoomID != roomid)
            continue;

        // 循环节点
        for (int j = 0; j < eleRoom.childNodes().count(); j++) {
            QDomNode nodeSceneList = eleRoom.childNodes().at(j);
            if ( !nodeSceneList.isElement() )
                continue;

            QDomElement eleSceneList = nodeSceneList.toElement();
            if ("SceneList" != eleSceneList.nodeName())
                continue;

            // 查找是否有场景节点，有则删除
            for (int k = 0; k < eleSceneList.childNodes().count(); k++) {
                QDomNode nodeScene = eleSceneList.childNodes().at(k);
                if ( !nodeScene.isElement() )
                    continue;

                QDomElement eleScene = nodeScene.toElement();
                int nSceneID = eleScene.attribute("ID").toInt();
                if (nSceneID != id)
                    continue;

                // 清空场景数据
                QDomElement eleNullScene = doc.createElement(QString("Scene"));
                eleNullScene.setAttribute("ID", id);
                eleNullScene.setAttribute("Name", eleScene.attribute("Name"));

                // 更新场景数据
                for (int l = 0; l < lst.count(); l++) {
                    QPoint pt = lst.at(l);
                    QDomElement eleSceneDataNode = doc.createElement(QString("Node"));
                    eleSceneDataNode.setAttribute(QString("InputID"), pt.x());
                    eleSceneDataNode.setAttribute(QString("OutputID"), pt.y());

                    eleNullScene.appendChild( eleSceneDataNode );
                }

                eleSceneList.replaceChild(eleNullScene, eleScene);
            }
        }
    }

    // 写入文件
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}

void BCLocalServer::UpdateMatrixScene(int roomid, int id, const QString &name)
{
    QFile file( QString("../xml/BCMatrixConfig.xml") );
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

    // 循环矩阵房间
    for (int i = 0; i < docElem.childNodes().count(); i++) {
        QDomNode nodeRoom = docElem.childNodes().at(i);
        if ( !nodeRoom.isElement() )
            continue;

        QDomElement eleRoom = nodeRoom.toElement();
        int nRoomID = eleRoom.attribute("ID").toInt();
        if (nRoomID != roomid)
            continue;

        // 循环节点
        for (int j = 0; j < eleRoom.childNodes().count(); j++) {
            QDomNode nodeSceneList = eleRoom.childNodes().at(j);
            if ( !nodeSceneList.isElement() )
                continue;

            QDomElement eleSceneList = nodeSceneList.toElement();
            if ("SceneList" != eleSceneList.nodeName())
                continue;

            // 查找是否有场景节点，有则删除
            for (int k = 0; k < eleSceneList.childNodes().count(); k++) {
                QDomNode nodeScene = eleSceneList.childNodes().at(k);
                if ( !nodeScene.isElement() )
                    continue;

                QDomElement eleScene = nodeScene.toElement();
                int nSceneID = eleScene.attribute("ID").toInt();
                if (nSceneID != id)
                    continue;

                eleScene.setAttribute("Name", name);
            }
        }
    }

    // 写入文件
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}

void BCLocalServer::UpdateMatrixRoomName(int roomid, const QString &name)
{
    QFile file( QString("../xml/BCMatrixConfig.xml") );
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

    // 循环矩阵房间
    for (int i = 0; i < docElem.childNodes().count(); i++) {
        QDomNode nodeRoom = docElem.childNodes().at(i);
        if ( !nodeRoom.isElement() )
            continue;

        QDomElement eleRoom = nodeRoom.toElement();
        int nRoomID = eleRoom.attribute("ID").toInt();
        if (nRoomID != roomid)
            continue;

        eleRoom.setAttribute("Name", name);
    }

    // 写入文件
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}

void BCLocalServer::UpdateMatrixRoomSwitch(int roomid, int isOn)
{
    QFile file( QString("../xml/BCMatrixConfig.xml") );
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

    // 循环矩阵房间
    for (int i = 0; i < docElem.childNodes().count(); i++) {
        QDomNode nodeRoom = docElem.childNodes().at(i);
        if ( !nodeRoom.isElement() )
            continue;

        QDomElement eleRoom = nodeRoom.toElement();
        int nRoomID = eleRoom.attribute("ID").toInt();
        if (nRoomID != roomid)
            continue;

        eleRoom.setAttribute("IsOn", isOn);
    }

    // 写入文件
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}

void BCLocalServer::UpdateMatrixOutputSwitch(int roomid, int id, int isOn)
{
    QFile file( QString("../xml/BCMatrixConfig.xml") );
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

    // 循环矩阵房间
    for (int i = 0; i < docElem.childNodes().count(); i++) {
        QDomNode nodeRoom = docElem.childNodes().at(i);
        if ( !nodeRoom.isElement() )
            continue;

        // 查找房间
        QDomElement eleRoom = nodeRoom.toElement();
        int nCurrentID = eleRoom.attribute("ID").toInt();
        if (nCurrentID != roomid)
            continue;

        // 查找输出节点
        for (int j = 0; j < eleRoom.childNodes().count(); j++) {
            QDomNode nodeOutput = eleRoom.childNodes().at(j);
            if ( !nodeOutput.isElement() )
                continue;

            if (nodeOutput.nodeName() != "Output")
                continue;

            QDomElement eleOutput = nodeOutput.toElement();
            for (int k = 0; k < eleOutput.childNodes().count(); k++) {
                QDomNode node = eleOutput.childNodes().at(k);
                if ( !node.isElement() )
                    continue;

                QDomElement ele = node.toElement();
                int nCurrentID = ele.attribute("ID").toInt();
                if (nCurrentID != id)
                    continue;

                ele.setAttribute("IsOn", isOn);
                break;
            }
        }
    }

    // 写入文件
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}

void BCLocalServer::UpdateMatrixInputCut(int roomid, int id, int l, int r, int t, int b)
{
    QFile file( QString("../xml/BCMatrixConfig.xml") );
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

    // 循环矩阵房间
    for (int i = 0; i < docElem.childNodes().count(); i++) {
        QDomNode nodeRoom = docElem.childNodes().at(i);
        if ( !nodeRoom.isElement() )
            continue;

        // 查找房间
        QDomElement eleRoom = nodeRoom.toElement();
        int nCurrentID = eleRoom.attribute("ID").toInt();
        if (nCurrentID != roomid)
            continue;

        // 查找输出节点
        for (int j = 0; j < eleRoom.childNodes().count(); j++) {
            QDomNode nodeOutput = eleRoom.childNodes().at(j);
            if ( !nodeOutput.isElement() )
                continue;

            if (nodeOutput.nodeName() != "Input")
                continue;

            QDomElement eleOutput = nodeOutput.toElement();
            for (int k = 0; k < eleOutput.childNodes().count(); k++) {
                QDomNode node = eleOutput.childNodes().at(k);
                if ( !node.isElement() )
                    continue;

                QDomElement ele = node.toElement();
                int nCurrentID = ele.attribute("ID").toInt();
                if (nCurrentID != id)
                    continue;

                ele.setAttribute("cutl", l);
                ele.setAttribute("cutr", r);
                ele.setAttribute("cutt", t);
                ele.setAttribute("cutb", b);
                break;
            }
        }
    }

    // 写入文件
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}

void BCLocalServer::UpdateMatrixJointChannel(int id, QList<QPoint> lst)
{
    QFile file( QString("../xml/BCMatrixConfig.xml") );
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

    // 循环矩阵房间
    for (int i = 0; i < docElem.childNodes().count(); i++) {
        QDomNode nodeRoom = docElem.childNodes().at(i);
        if ( !nodeRoom.isElement() )
            continue;

        // 查找房间
        QDomElement eleRoom = nodeRoom.toElement();
        int roomid = eleRoom.attribute("ID").toInt();
        if (roomid != id)
            continue;

        // 查找输出节点
        for (int j = 0; j < eleRoom.childNodes().count(); j++) {
            QDomNode nodeOutput = eleRoom.childNodes().at(j);
            if ( !nodeOutput.isElement() )
                continue;

            if (nodeOutput.nodeName() != "Output")
                continue;

            QDomElement eleOutput = nodeOutput.toElement();
            for (int k = 0; k < eleOutput.childNodes().count(); k++) {
                QDomNode node = eleOutput.childNodes().at(k);
                if ( !node.isElement() )
                    continue;

                QDomElement ele = node.toElement();
                int nCurrentID = ele.attribute("ID").toInt();
                for (int m = 0; m < lst.count(); m++) {
                    QPoint pt = lst.at( m );
                    if (pt.x() != nCurrentID)
                        continue;

                    ele.setAttribute("jointWithVP4000ChannelID", pt.y());
                    break;
                }
            }
        }
    }

    // 写入文件
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}

void BCLocalServer::RemoveMatrixScene(int roomid, int id)
{
    QFile file( QString("../xml/BCMatrixConfig.xml") );
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

    // 循环矩阵房间
    for (int i = 0; i < docElem.childNodes().count(); i++) {
        QDomNode nodeRoom = docElem.childNodes().at(i);
        if ( !nodeRoom.isElement() )
            continue;

        QDomElement eleRoom = nodeRoom.toElement();
        int nRoomID = eleRoom.attribute("ID").toInt();
        if (nRoomID != roomid)
            continue;

        // 循环节点
        for (int j = 0; j < eleRoom.childNodes().count(); j++) {
            QDomNode nodeSceneList = eleRoom.childNodes().at(j);
            if ( !nodeSceneList.isElement() )
                continue;

            QDomElement eleSceneList = nodeSceneList.toElement();
            if ("SceneList" != eleSceneList.nodeName())
                continue;

            // 查找是否有场景节点，有则删除
            for (int k = 0; k < eleSceneList.childNodes().count(); k++) {
                QDomNode nodeScene = eleSceneList.childNodes().at(k);
                if ( !nodeScene.isElement() )
                    continue;

                QDomElement eleScene = nodeScene.toElement();
                int nSceneID = eleScene.attribute("ID").toInt();
                if (nSceneID != id)
                    continue;

                eleSceneList.removeChild( nodeScene );
            }
        }
    }

    // 写入文件
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}

void BCLocalServer::ClearMatrixScene(int roomid)
{
    QFile file( QString("../xml/BCMatrixConfig.xml") );
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

    // 循环矩阵房间
    for (int i = 0; i < docElem.childNodes().count(); i++) {
        QDomNode nodeRoom = docElem.childNodes().at(i);
        if ( !nodeRoom.isElement() )
            continue;

        QDomElement eleRoom = nodeRoom.toElement();
        int nRoomID = eleRoom.attribute("ID").toInt();
        if (nRoomID != roomid)
            continue;

        // 循环节点
        for (int j = 0; j < eleRoom.childNodes().count(); j++) {
            QDomNode nodeSceneList = eleRoom.childNodes().at(j);
            if ( !nodeSceneList.isElement() )
                continue;

            QDomElement eleSceneList = nodeSceneList.toElement();
            if ("SceneList" != eleSceneList.nodeName())
                continue;

            QDomElement eleNullSceneList = doc.createElement(QString("SceneList"));
            eleRoom.replaceChild(eleNullSceneList, eleSceneList);
        }
    }

    // 写入文件
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}

void BCLocalServer::SetMatrixSwitch(int id, int inputid, int outputid)
{
    QFile file( QString("../xml/BCMatrixConfig.xml") );
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

    // 循环矩阵房间
    for (int i = 0; i < docElem.childNodes().count(); i++) {
        QDomNode nodeRoom = docElem.childNodes().at(i);
        if ( !nodeRoom.isElement() )
            continue;

        // 查找房间
        QDomElement eleRoom = nodeRoom.toElement();
        int nCurrentID = eleRoom.attribute("ID").toInt();
        if (nCurrentID != id)
            continue;

        // 查找输出节点
        for (int j = 0; j < eleRoom.childNodes().count(); j++) {
            QDomNode nodeOutput = eleRoom.childNodes().at(j);
            if ( !nodeOutput.isElement() )
                continue;

            if (nodeOutput.nodeName() != "Output")
                continue;

            QDomElement eleOutput = nodeOutput.toElement();
            for (int k = 0; k < eleOutput.childNodes().count(); k++) {
                QDomNode node = eleOutput.childNodes().at(k);
                if ( !node.isElement() )
                    continue;

                QDomElement ele = node.toElement();
                int nCurrentID = ele.attribute("ID").toInt();
                if (nCurrentID != outputid)
                    continue;

                ele.setAttribute("IsSwitch", (-1 == inputid) ? 0 : 1);
                ele.setAttribute("SwitchID", inputid);
                break;
            }
        }
    }

    // 写入文件
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();

    //m_pDB->SetMatrixSwitch(ip, port, inputid, outputid);
}

void BCLocalServer::reset(const QString &qsGroupDisplayIDs)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    if ( qsGroupDisplayIDs.contains(" ") ) {
        QStringList lstIDs = qsGroupDisplayIDs.split(" ");
        for (int i = 0; i < lstIDs.count(); i++) {
            QString qsID = lstIDs.at( i );
            if ( !qsID.isEmpty() ) {
                QString cmd;
                if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) { // VP2000A, VP4000
                    cmd = QString("greset %1\r\n").arg(qsID.toInt());
                } else if (BCCommon::g_nDeviceType == 0) {  // VP2000
                    cmd = QString("reset\r\n");
                }

                SendCmd( cmd );
            }
        }
    } else {
        QString cmd;
        if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) { // VP2000A, VP4000
            cmd = QString("greset %1\r\n").arg(qsGroupDisplayIDs);
        } else if (BCCommon::g_nDeviceType == 0) {  // VP2000
            cmd = QString("reset\r\n");
        }

        SendCmd( cmd );
    }
}

void BCLocalServer::winsize(int gid, int chid, int winid, int l, int t, int r, int b, int type, int copyIndex)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    // 添加偏移量
    MainWindow *pMainWindow = BCCommon::Application();
    QSize size = pMainWindow->GetWinsizeOffset( gid );
    l += size.width();
    r += size.width();
    t += size.height();
    b += size.height();

    QString cmd;
    if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) { // VP2000A, VP4000
        cmd = QString("gwinsize %1 %2 %3 %4 %5 %6 %7\r\n")
            .arg(gid)
            .arg(winid)
            .arg(chid)
            .arg(l)
            .arg(t)
            .arg(r)
            .arg(b);
    } else if (BCCommon::g_nDeviceType == 0) {  // VP2000
        if (-1 == copyIndex) {  // 没有子窗口则正常开窗
            QString qsHeader;
            if (0 == type)
                qsHeader = "Dwinsize";
            else if (3 == type)
                qsHeader = "Vwinsize";
            else if (2 == type)
                qsHeader = "Bwinsize";

            cmd = QString("%1 %2 %3 %4 %5 %6\r\n")
                    .arg( qsHeader )
                    .arg( chid )
                    .arg(l)
                    .arg(t)
                    .arg(r)
                    .arg(b);
        } else { // 有子窗口则复制开窗
            type = (3 == type) ? 1 : type;  // VP2000的类型3是video
            cmd = QString("Cwinsize %1 %2 %3 %4 %5 %6 %7\r\n")
                    .arg( type )
                    .arg( chid )
                    .arg( copyIndex )
                    .arg(l)
                    .arg(t)
                    .arg(r)
                    .arg(b);
        }
    }

    SendCmd( cmd );
}

void BCLocalServer::winswitch(int gid, int winid, int chid, int type, int copyIndex)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    QString cmd;
    if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) { // VP2000A, VP4000
        cmd = QString("gwinswitch %1 %2\r\n")
                .arg(gid)
                .arg(winid);
    } else if (BCCommon::g_nDeviceType == 0) { // VP2000
        if (-1 == copyIndex) {  // 没有子窗口则正常开窗
            QString qsHeader;
            if (0 == type)
                qsHeader = "Dwinswitch";
            else if (3 == type)
                qsHeader = "Vwinswitch";
            else if (2 == type)
                qsHeader = "Bwinswitch";

            cmd = QString("%1 %2\r\n")
                    .arg( qsHeader )
                    .arg( chid );
        } else {
            type = (3 == type) ? 1 : type;
            cmd = QString("wincopyswitch %1 %2 %3\r\n")
                    .arg( type )
                    .arg( chid )
                    .arg( copyIndex );
        }
    }

    SendCmd( cmd );
}

void BCLocalServer::save(int groupID, int sceneID)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    QString cmd;
    if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) { // VP2000A, VP4000
        cmd = QString("gsave %1 %2\r\n")
                .arg(groupID)
                .arg(sceneID);
    } else if (BCCommon::g_nDeviceType == 0) {  // VP2000
        cmd = QString("save %1\r\n").arg(sceneID);
    }

    SendCmd( cmd );
}

void BCLocalServer::load(int groupID, int sceneID)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    QString cmd;
    if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) { // VP2000A, VP4000
        cmd = QString("gload %1 %2\r\n")
                .arg(groupID)
                .arg(sceneID);
    } else if (BCCommon::g_nDeviceType == 0) {  // VP2000
        cmd = QString("load %1\r\n").arg(sceneID);
    }

    SendCmd( cmd );
}

void BCLocalServer::winup(int gid, int winid)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    QString cmd;
    if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) { // VP2000A, VP4000
        cmd = QString("winup %1 %2\r\n")
                .arg(gid)
                .arg(winid);
    } else if (BCCommon::g_nDeviceType == 0) {  // VP2000
        //cmd = QString("load %1\r\n").arg(sceneID);
    }

    SendCmd( cmd );
}

void BCLocalServer::windown(int gid, int winid)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    QString cmd;
    if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) { // VP2000A, VP4000
        cmd = QString("windown %1 %2\r\n")
                .arg(gid)
                .arg(winid);
    } else if (BCCommon::g_nDeviceType == 0) {  // VP2000
        //cmd = QString("load %1\r\n").arg(sceneID);
    }

    SendCmd( cmd );
}

void BCLocalServer::SetIPVedioCurrentIP(int cid, int /*winid*/, int /*segmentation*/, int currentSegmentaion, QString ip, int boardcardid, int boardcardpos, int decoder, int resolutionX, int resolutionY)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    int index = currentSegmentaion+(boardcardpos%2)*4;
    index += (boardcardpos%2)*36;   // 相邻两个口子用的是两套IP地址，第二套从36起始
    QString cmd0 = QString("ipvcmd %1 %2 0 %3 %4 %5 %6 %7\r\n")
    //QString cmd0 = QString("ipvcmd %1 %2 0 %3 96 1920 1080 %4\r\n")
    //QString cmd0 = QString("ipvcmd %1 %2 0 %3 %4\r\n")
            .arg( boardcardid )
            .arg( (boardcardpos < 2) ? 0 : 1 )
            .arg( index )
            .arg( decoder )
            .arg( resolutionX )
            .arg( resolutionY )
            .arg(ip);

    QString cmd2 = QString("ipvcmd %1 %2 2 %3 %4 %5\r\n")
            .arg(boardcardid)
            .arg((boardcardpos < 2) ? 0 : 1)
            .arg(boardcardpos%2)
            .arg(currentSegmentaion)
            .arg( index );

    SendCmd( cmd0 );

    // 发送指令间隔
    Sleep(200);

    SendCmd( cmd2 );
}

void BCLocalServer::SetIPVedioSegmentation(int cid, int segmentation, int boardcardid, int boardcardpos)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    // 窗口默认分屏是-1，直接取绝对值
    segmentation = qAbs( segmentation );

//    int cmdSegment = segmentation;
//    switch ( segmentation ) {
//    case 1:
//        cmdSegment = 1;
//        break;
//    case 2:
//        cmdSegment = 4;
//        break;
//    case 3:
//        cmdSegment = 9;
//        break;
//    case 4:
//        cmdSegment = 16;
//        break;
//    case 5:
//        cmdSegment = 25;
//        break;
//    default:
//        cmdSegment = 36;
//        break;
//    }

    QString cmd = QString("ipvcmd %1 %2 3 %3 %4\r\n")
            .arg(boardcardid)
            .arg((boardcardpos < 2) ? 0 : 1)
            .arg(boardcardpos%2)
            .arg(segmentation);
    SendCmd( cmd );
}

void BCLocalServer::SetIPVedioConfig(int cid, QString ip, QString mask, QString gateway, QString mac, int boardcardid, int boardcardpos)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    QString cmdIP = QString("ipvcmd %1 %2 6 %3 %4 %5\r\n")
            .arg(boardcardid)
            .arg((boardcardpos < 2) ? 0 : 1)
            .arg(ip)
            .arg(mask)
            .arg(gateway);

    QString cmdMac = QString("ipvcmd %1 %2 8 %3\r\n")
                    .arg(boardcardid)
                    .arg((boardcardpos < 2) ? 0 : 1)
                    .arg(mac);

    // 发送两遍，可能会丢指令
    for (int i = 0; i < 2; i++) {
        SendCmd( cmdIP );

        QThread::msleep( 50 );
        SendCmd( cmdMac );

        QThread::msleep( 50 );
    }
}

void BCLocalServer::SetCutArea(int userid, const QString &deviceip, int chid, int type, int boardcardid, int boardcardpos, int left, bool bExecL, int right, bool bExecR, int top, bool bExecT, int bottom, bool bExecB)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    int loopTimes = 1;      // 循环次数
    int splitTime = 1000;     // 指令间隔时间
    if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) { // VP2000A, VP4000
        for (int i = 0; i < loopTimes; i++) {
            QString cmd = QString("vt6cutleft %1 %2 %3\r\n")
                    .arg(boardcardid)
                    .arg(boardcardpos)
                    .arg(left);
            if ( bExecL ) {
                SendCmd( cmd );
                QThread::msleep(splitTime);
            }

            cmd = QString("vt6cutright %1 %2 %3\r\n")
                    .arg(boardcardid)
                    .arg(boardcardpos)
                    .arg(right);
            if ( bExecR ) {
                SendCmd( cmd );
                QThread::msleep(splitTime);
            }

            cmd = QString("vt6cutup %1 %2 %3\r\n")
                    .arg(boardcardid)
                    .arg(boardcardpos)
                    .arg(top);
            if ( bExecT ) {
                SendCmd( cmd );
                QThread::msleep(splitTime);
            }

            cmd = QString("vt6cutdown %1 %2 %3\r\n")
                    .arg(boardcardid)
                    .arg(boardcardpos)
                    .arg(bottom);
            if ( bExecB ) {
                SendCmd( cmd );
            }
            QThread::msleep(splitTime);
        }
    } else if (BCCommon::g_nDeviceType == 0) {  // VP2000
        type = (3 == type) ? 1 : type;  // 2000 时video类型是1，4000中是3

        for (int i = 0; i < loopTimes; i++) {
            QString cmd = QString("vt6cutleft %1 %2 %3\r\n")
                    .arg(type)
                    .arg(chid)
                    .arg(left);
            if ( bExecL ) {
                SendCmd( cmd );
                QThread::msleep(splitTime);
            }

            cmd = QString("vt6cutright %1 %2 %3\r\n")
                    .arg(type)
                    .arg(chid)
                    .arg(right);
            if ( bExecR ) {
                SendCmd( cmd );
                QThread::msleep(splitTime);
            }

            cmd = QString("vt6cutup %1 %2 %3\r\n")
                    .arg(type)
                    .arg(chid)
                    .arg(top);
            if ( bExecT ) {
                SendCmd( cmd );
                QThread::msleep(splitTime);
            }

            cmd = QString("vt6cutdown %1 %2 %3\r\n")
                    .arg(type)
                    .arg(chid)
                    .arg(bottom);
            if ( bExecB ) {
                SendCmd( cmd );
            }
            QThread::msleep(splitTime);
        }
    }

    m_pDB->SetCutArea(userid, deviceip, chid, type, left, right, top, bottom);
}

void BCLocalServer::DelWinCopy(int type, int chid)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    QString cmd = QString("delwincopy %1 %2\r\n")
            .arg(type)
            .arg(chid);

    SendCmd( cmd );
}

void BCLocalServer::SetWinCopy(int type, int chid, int count)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    QString cmd = QString("wincopy %1 %2 %3\r\n")
            .arg(type)
            .arg(chid)
            .arg(count);

    SendCmd( cmd );
}

void BCLocalServer::SetWinCopyEnable(bool b)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    QString cmd = QString("wincopyen %1\r\n")
            .arg(b ? 1 : 0);

    SendCmd( cmd );
}

void BCLocalServer::SetPreviewSwitch(bool bOpen)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    QString cmd = QString("setprewena %1\r\n")
            .arg(bOpen ? 1 : 0);

    SendCmd( cmd );
}

void BCLocalServer::SetPreviewActiveG(int gid)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    QString cmd = QString("activeg %1\r\n")
            .arg(gid);

    SendCmd( cmd );
}

void BCLocalServer::SetDevice2000IP(const QString &ip)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    QStringList lstIP = ip.split(".");
    if (4 != lstIP.count())
        return;

    QString cmd = QString("setip %1 %2 %3 %4\r\n")
            .arg(lstIP.at(0).toInt())
            .arg(lstIP.at(1).toInt())
            .arg(lstIP.at(2).toInt())
            .arg(lstIP.at(3).toInt());

    SendCmd( cmd );
}

void BCLocalServer::SetDevice2000RemoveShadow(int arrX, int arrY, int resX, int resY, int shaX, int shaY)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    QString cmd = QString("setspformatxy %1 %2 %3 %4 %5 %6\r\n")
            .arg(arrX).arg(arrY)
            .arg(resX).arg(resY)
            .arg(shaX).arg(shaY);

    SendCmd( cmd );
}

int BCLocalServer::SetInputChannelType(int chtype, int chid, int type, int boardcardid, int boardcardpos)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return 0;

    QString cmd;
    if (BCCommon::g_nDeviceType == 0) { // vp2000
        type = (3 == type) ? 1 : type;  // 2000 时video类型是1，4000中是3
        cmd = QString("vt6inputmode %1 %2 %3\r\n").arg(chtype).arg(chid).arg(type);
    } else if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) { // vp4000
        cmd = QString("vt6inputmode %1 %2 %3\r\n")
                .arg(boardcardid)
                .arg(boardcardpos)
                .arg(type);
    }

    SendCmd( cmd );

    return 1;
}

int BCLocalServer::SetSubTitlesVisible(int type, int beginChid, int endChid, int visible, int boardcardid, int boardcardpos)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return 0;

    QString cmd;
    if (BCCommon::g_nDeviceType == 0) { // vp2000
        type = (4 == type) ? 1 : type;
        cmd = QString("%1 %2 %3\r\n")
                   .arg((1 == visible) ? QString("openosd") : QString("closeosd"))
                   .arg(type)
                   .arg(endChid);
    } else if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) { // vp4000
        if (beginChid == endChid) {
            cmd = QString("%1 %2 %3\r\n")
                       .arg((1 == visible) ? QString("openosd") : QString("closeosd"))
                       .arg(boardcardid)
                       .arg(boardcardpos);
        } else {
            cmd = QString("%1 %2 %3\r\n")
                       .arg((1 == visible) ? QString("openosda") : QString("closeosda"))
                       .arg(beginChid)
                       .arg(endChid);
        }
    }

    SendCmd( cmd );

    return 1;
}

int BCLocalServer::SetSubTitlesPos(int type, int beginChid, int endChid, int x, int y, int boardcardid, int boardcardpos)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return 0;

    QString cmd;
    if (BCCommon::g_nDeviceType == 0) { // vp2000
        type = (4 == type) ? 1 : type;
        cmd = QString("%1 %2 %3 %4 %5\r\n")
                   .arg(QString("osdpos"))
                   .arg(type)
                   .arg(endChid)
                .arg(x).arg(y);
    } else if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) { // vp4000
        if (beginChid == endChid) {
            cmd = QString("osdpos %1 %2 %3 %4\r\n")
                    .arg(boardcardid)
                    .arg(boardcardpos)
                    .arg(x)
                    .arg(y);
        } else {
            cmd = QString("osdposa %1 %2 %3 %4\r\n")
                    .arg(beginChid)
                    .arg(endChid)
                    .arg(x)
                    .arg(y);
        }
    }

    SendCmd( cmd );

    return 1;
}

int BCLocalServer::SetSubTitlesColor(int type, int beginChid, int endChid, int r, int g, int b, int boardcardid, int boardcardpos)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return 0;

    QString cmd;
    if (BCCommon::g_nDeviceType == 0) { // vp2000
        type = (4 == type) ? 1 : type;
        cmd = QString("%1 %2 %3 %4 %5 %6\r\n")
                   .arg(QString("osdcolor"))
                   .arg(type)
                   .arg(endChid)
                .arg(r).arg(g).arg(b);
    } else if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) { // vp4000
        if (beginChid == endChid) {
            cmd = QString("osdcolor %1 %2 %3 %4 %5\r\n")
                    .arg(boardcardid)
                    .arg(boardcardpos)
                    .arg(r)
                    .arg(g)
                    .arg(b);
        } else {
            cmd = QString("osdcolora %1 %2 %3 %4 %5\r\n")
                    .arg(beginChid)
                    .arg(endChid)
                    .arg(r)
                    .arg(g)
                    .arg(b);
        }
    }

    SendCmd( cmd );

    return 1;
}

int BCLocalServer::SetSubTitlesText(int type, int beginChid, int endChid, QString text, int boardcardid, int boardcardpos)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return 0;

    // 这里需要把text编码从UTF-8转换成ANSI，否则汉字无法正常显示
    char strB_out[255];
    Convert(text.toStdString().c_str(),strB_out,CP_UTF8,CP_ACP);

    char push_cmd_str[255];
    if (BCCommon::g_nDeviceType == 0) { // vp2000
        type = (4 == type) ? 1 : type;
        sprintf(push_cmd_str,"osd %d %d %s\r", type, endChid, strB_out);
    } else if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) { // vp4000
        if (beginChid == endChid) {
            sprintf(push_cmd_str,"osd %d %d %s\r", boardcardid, boardcardpos, strB_out);
        } else {
            sprintf(push_cmd_str,"osda %d %d %s\r", beginChid, endChid, strB_out);
        }
    }

    if ( m_bIsNetConnect ) {
        m_pTcpSocket->write(push_cmd_str);
        m_pTcpSocket->flush();
    } else {
        // 串口
        if ( !m_serial.isOpen() )
            ConnectSerialPort();

        m_serial.write( push_cmd_str );
        m_serial.waitForBytesWritten( 50 );
        m_serial.flush();
    }

    // 添加到调试窗口
    MainWindow *pMainWindow = BCCommon::Application();
    pMainWindow->AddDebugCmd( QString(push_cmd_str) );

    return 1;
}

void BCLocalServer::Convert(const char* strIn,char* strOut, int sourceCodepage, int targetCodepage)
{
    int len=strlen(strIn);
    int unicodeLen=MultiByteToWideChar(sourceCodepage,0,strIn,-1,NULL,0);
    wchar_t* pUnicode;
    pUnicode=new wchar_t[unicodeLen+1];
    memset(pUnicode,0,(unicodeLen+1)*sizeof(wchar_t));
    MultiByteToWideChar(sourceCodepage,0,strIn,-1,(LPWSTR)pUnicode,unicodeLen);
    BYTE * pTargetData = NULL;
    int targetLen=WideCharToMultiByte(targetCodepage,0,(LPWSTR)pUnicode,-1,(char *)pTargetData,0,NULL,NULL);
    pTargetData=new BYTE[targetLen+1];
    memset(pTargetData,0,targetLen+1);
    WideCharToMultiByte(targetCodepage,0,(LPWSTR)pUnicode,-1,(char *)pTargetData,targetLen,NULL,NULL);
    strcpy(strOut,(char*)pTargetData);
    delete pUnicode;
    delete pTargetData;
}

void BCLocalServer::SetHDBaseEDID(int bid, int cid, int x, int y, int hz)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    QString cmd = QString("newsetdualddca %1 %2 %3 %4 %5\r\n")
            .arg(bid)
            .arg(cid)
            .arg(x)
            .arg(y)
            .arg(hz);

    SendCmd( cmd );
}

void BCLocalServer::SetRstGroup()
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    SendCmd( QString("rstgroup\r\n") );
}
QString BCLocalServer::GetRstGroup()
{
    return QString("rstgroup\r\n");
}
void BCLocalServer::SetGroup(int gid, int schid, int echid)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    QString cmd = QString("setgroup %1 %2 %3\r\n").arg(gid).arg(schid).arg(echid);

    SendCmd( cmd );
}
QString BCLocalServer::GetGroup(int gid, int schid, int echid)
{
    QString cmd = QString("setgroup %1 %2 %3\r\n").arg(gid).arg(schid).arg(echid);

    return cmd;
}

void BCLocalServer::RemoveGroup(int gid)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    QString cmd = QString("setgroup %1 255\r\n").arg(gid);

    SendCmd( cmd );
}

void BCLocalServer::SetCustomResolution(int liveW, int liveH, int preW, int preH, int syncW, int syncH, int totalW, int totalH, int /*polarityW*/, int /*polarityH*/, int hertz)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    QString cmd = QString("newddcmodetype 8 %1 %2 %3 %4 %5 %6 %7 %8 %9 %10\r\n")
            .arg(preW).arg(totalW-liveW-preW-syncW).arg(syncW).arg(liveW)
            .arg(preH).arg(totalH-liveH-preH-syncH).arg(syncH).arg(liveH)
            .arg(0).arg(hertz);

    SendCmd( cmd );
}
QString BCLocalServer::GetCustomResolution(int liveW, int liveH, int preW, int preH, int syncW, int syncH, int totalW, int totalH, int /*polarityW*/, int /*polarityH*/, int hertz)
{
    QString cmd = QString("newddcmodetype 8 %1 %2 %3 %4 %5 %6 %7 %8 %9 %10\r\n")
            .arg(preW).arg(totalW-liveW-preW-syncW).arg(syncW).arg(liveW)
            .arg(preH).arg(totalH-liveH-preH-syncH).arg(syncH).arg(liveH)
            .arg(0).arg(hertz);

    return cmd;
}
void BCLocalServer::SetResolution(int schid, int echid, int resolution)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    QString cmd;
    if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) { // VP2000A, VP4000
        cmd = QString("resolution %1 %2 %3\r\n").arg(schid).arg(echid).arg(resolution);
    } else {
        switch ( resolution ) { // VP2000分辨率和VP4000有差异
        case 0: // 1920*1080
            resolution = 3;
            break;
        case 1: // 1400*1050
            resolution = 2;
            break;
        case 2: // 1366*768
            resolution = 1;
            break;
        default:// 1024*768
            resolution = 0;
            break;
        }
        cmd = QString("resolution %1\r\n").arg(resolution);
    }

    SendCmd( cmd );
}
QString BCLocalServer::GetResolution(int schid, int echid, int resolution)
{
    QString cmd;
    if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) { // VP2000A, VP4000
        cmd = QString("resolution %1 %2 %3\r\n").arg(schid).arg(echid).arg(resolution);
    } else {
        switch ( resolution ) { // VP2000分辨率和VP4000有差异
        case 0: // 1920*1080
            resolution = 3;
            break;
        case 1: // 1400*1050
            resolution = 2;
            break;
        case 2: // 1366*768
            resolution = 1;
            break;
        default:// 1024*768
            resolution = 0;
            break;
        }
        cmd = QString("resolution %1\r\n").arg(resolution);
    }

    return cmd;
}
void BCLocalServer::SetGFormartxy(int gid, int x, int y, int resolutionX, int resolutionY)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    QString cmd;
    if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) { // VP2000A, VP4000
        cmd = QString("setgformatxy %1 %2 %3 %4 %5\r\n").arg(gid).arg(x).arg(y).arg(resolutionX).arg(resolutionY);
    } else if (BCCommon::g_nDeviceType == 0) {   // VP2000
        cmd = QString("setformatxy %1 %2 %3 %4\r\n").arg(x).arg(y).arg(resolutionX).arg(resolutionY);
    }

    SendCmd( cmd );
}
QString BCLocalServer::GetGFormartxy(int gid, int x, int y, int resolutionX, int resolutionY)
{
    QString cmd;
    if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) { // VP2000A, VP4000
        cmd = QString("setgformatxy %1 %2 %3 %4 %5\r\n").arg(gid).arg(x).arg(y).arg(resolutionX).arg(resolutionY);
    } else if (BCCommon::g_nDeviceType == 0) {   // VP2000
        cmd = QString("setformatxy %1 %2 %3 %4\r\n").arg(x).arg(y).arg(resolutionX).arg(resolutionY);
    }

    return cmd;
}
void BCLocalServer::SetFormatxy(int arrX, int arrY, int resoluX, int resoluY)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    QString cmd = QString("setformatxy %1 %2 %3 %4\r\n").arg(arrX).arg(arrY).arg(resoluX).arg(resoluY);

    SendCmd( cmd );
}
QString BCLocalServer::GetFormatxy(int arrX, int arrY, int resoluX, int resoluY)
{
    QString cmd = QString("setformatxy %1 %2 %3 %4\r\n").arg(arrX).arg(arrY).arg(resoluX).arg(resoluY);

    return cmd;
}

void BCLocalServer::Setxy(int groupid, int chid, int l, int t, int r, int b)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    QString cmd;
    if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) { // VP2000A, VP4000
        cmd = QString("setgxy %1 %2 %3 %4 %5 %6\r\n").arg(groupid).arg(chid).arg(l).arg(t).arg(r).arg(b);
    } else if (BCCommon::g_nDeviceType == 0) {   // VP2000
        int nChID = (chid/4)*4 + chid; // 遇到4的倍数跳4个口
        cmd = QString("setxy %1 %2 %3 %4 %5\r\n").arg(nChID).arg(l).arg(t).arg(r).arg(b);
    }

    SendCmd( cmd );
}

void BCLocalServer::SendCmd(const QString &cmd, bool bAddDebug)
{
    // 如果是演示模式直接返回
    if (0 == m_nIsDemoMode)
        return;

    // 更新执行时间
    m_timeOfPreview = QTime::currentTime();

    if ( m_bIsNetConnect ) {
        SendTcpData( cmd );
    } else {
        // 串口
        SendSerialPortData( cmd );
    }

    // 添加到调试窗口
    if ( bAddDebug ) {
        MainWindow *pMainWindow = BCCommon::Application();
        pMainWindow->AddDebugCmd( cmd );
    }
}

void BCLocalServer::SendTcpData(const QString &cmd, int cmdLen)
{
    // 判断是否包含汉字
    qDebug() << "TCP: " << cmd;
    this->AddLog( "TCP: "+cmd );
    if (NULL != m_pTcpSocket) {
        cmdLen = (-1 == cmdLen) ? cmd.length() : cmdLen;
        m_pTcpSocket->write(cmd.toLatin1(), cmdLen);
        m_pTcpSocket->flush();
    }
}

void BCLocalServer::SendSerialPortData(const QString &cmd)
{
    //qDebug() << "SERIAL: " << cmd;
    this->AddLog( "SERIAL: "+cmd );
    if ( !m_serial.isOpen() )
        return;

    m_serial.write(cmd.toLatin1(), cmd.length());
    m_serial.waitForBytesWritten( 50 );
    m_serial.flush();
}

void BCLocalServer::AddLog(QString text)
{
    QFile file( "log.txt" );
    QTextStream stream( &file);
    if ( file.open(QFile::ReadWrite |QIODevice::Append) ) {
        stream << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << ": " << text << "\r\n";
        file.close();
    }
}
