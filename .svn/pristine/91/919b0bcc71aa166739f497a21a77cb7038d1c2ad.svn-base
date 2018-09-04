#include "BCMRoom.h"
#include "BCMGroupScene.h"
#include "BCMWindowScene.h"
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"
#include "BCMGroupDisplay.h"
#include <QTcpSocket>

//#define SCENEIDBEGINFROM0       // 场景从0开始

BCMRoom::BCMRoom(int id)
{
    m_id = id;
    m_type = 0;

    // 屏幕开关
    m_bSwitchOn = false;
    m_pSwitchSocket = NULL;
    m_nIsUseVirResotluion = 0;
    m_nVirSize = QSize(3840, 2160);
    isConnectByNet = 1;             // 是否网络通信
    switchip = "192.168.1.85";
    switchport = 9000;
    qsCurrentCom = "COM1";           // 串口号
    nCurrentBaudRate = 9600;           // 波特率
    nCurrentDataBit = 8;            // 数据位
    nCurrentStopBit = 1;            // 停止位
    qsCurrentCheckBit = "None";      // 校验位
    qsCurrentStreamCtrl = "None";    // 控制流
    switchtype = 1; // 0:16 1:text

    // 默认场景
    m_pDefaultScene = new BCMWindowScene( this );
    m_pDefaultScene->SetWindowSceneID( 128 );

    // 默认场景组
    m_lstGroupScene.append( new BCMGroupScene( this ) );

    m_pSignalWidgetMgr = NULL;

    // 初始化信号窗定时器
    m_pWindowSceneTimer = new QTimer( this );
    m_bLoopWindowScene = false;
    m_nLoopWindowSceneIndex = 0;
    m_nWindowSceneTimeIndex = 0;

    // 关联定时器信号槽
    m_pWindowSceneTimer->setInterval( 1000 );
    QObject::connect(m_pWindowSceneTimer, SIGNAL(timeout()), this, SLOT(onLoopWindowScene()));
}

BCMRoom::~BCMRoom()
{
    if (NULL != m_pSwitchSocket) {
        m_pSwitchSocket->deleteLater();
    }

    m_serial.close();

    // 清空屏组链表
    while ( !m_lstGroupDisplay.isEmpty() )
        delete m_lstGroupDisplay.takeFirst();

    // 清空场景组链表
    while ( !m_lstGroupScene.isEmpty() )
        delete m_lstGroupScene.takeFirst();

    // 删除默认场景
    if (NULL != m_pDefaultScene) {
        delete m_pDefaultScene;
        m_pDefaultScene = NULL;
    }
}

void BCMRoom::SetRoomName(const QString &qs, bool bSendCmd)
{
    m_name = qs;

    if ( !bSendCmd )
        return;

    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->UpdateRoomName(m_id, m_name);
}

void BCMRoom::SetLoopWindowScene(bool b)
{
    m_bLoopWindowScene = b;

    m_bLoopWindowScene ? m_pWindowSceneTimer->start() : m_pWindowSceneTimer->stop();
}

void BCMRoom::onLoopWindowScene()
{
    QMutexLocker locker(&m_mutex);

    // 如果都没有添加到循环则直接退出
    QList<BCMWindowScene *> lstLoopWindowScene;
    for (int i = 0; i < m_lstGroupScene.count(); i++) {
        BCMGroupScene *pGroupScene = m_lstGroupScene.at( i );
        QList<BCMWindowScene *> lstWindowScene = pGroupScene->GetWindowScenes();
        for (int j = 0; j < lstWindowScene.count(); j++) {
            BCMWindowScene *pWindowScene = lstWindowScene.at( j );
            if ( !pWindowScene->IsCycled() )
                continue;

            lstLoopWindowScene.append( pWindowScene );
        }
    }

    if ( lstLoopWindowScene.isEmpty() )
        return;

    // 如果索引值大于索引范围则将索引移至第一个
    if (m_nLoopWindowSceneIndex >= lstLoopWindowScene.count())
        m_nLoopWindowSceneIndex = 0;

    // 找到对应场景并显示
    BCMWindowScene *pWindowScene = lstLoopWindowScene.at( m_nLoopWindowSceneIndex );
    bool bCycled = pWindowScene->IsCycled();

    // 非常规模式先判断场景内轮巡时间是否完成，完成后轮巡下个场景
    bool bShowScene = false;
    m_nWindowSceneTimeIndex++;
    if (m_nWindowSceneTimeIndex >= pWindowScene->GetWindowSceneLoopInterval()) {
        bShowScene = true;
        m_nWindowSceneTimeIndex = 0;

        m_nLoopWindowSceneIndex++;
        if (m_nLoopWindowSceneIndex >= lstLoopWindowScene.count())
            m_nLoopWindowSceneIndex = 0;
    } else if (1 == m_nWindowSceneTimeIndex) {
        bShowScene = true;
    }

    if ( bCycled ) {
        if ( bShowScene ) { // 只有第一次执行
            pWindowScene->Show();
        }
    } else
        onLoopWindowScene();
}

void BCMRoom::AddGroupDisplay(BCMGroupDisplay *pGroupDisplay)
{
    m_lstGroupDisplay.append( pGroupDisplay );
}

BCMGroupDisplay *BCMRoom::GetGroupDisplay(int id)
{
    QListIterator<BCMGroupDisplay *> it( m_lstGroupDisplay );
    while (it.hasNext()) {
        BCMGroupDisplay *pGroupDisplay = it.next();

        if (pGroupDisplay->GetGroupDisplayID() != id)
            continue;

        return pGroupDisplay;
    }

    return NULL;
}

BCMGroupScene *BCMRoom::GetGroupScene(int id)
{
    QListIterator<BCMGroupScene *> it( m_lstGroupScene );
    while (it.hasNext()) {
        BCMGroupScene *pGroupScene = it.next();
        if (NULL == pGroupScene)
            continue;

        if (pGroupScene->GetGroupSceneID() == id)
            return pGroupScene;
    }

    return NULL;
}

void BCMRoom::RemoveGroupDisplay(BCMGroupDisplay *pGroupDisplay)
{
    if (NULL == pGroupDisplay)
        return;

    m_lstGroupDisplay.removeOne( pGroupDisplay );

    delete pGroupDisplay;
    pGroupDisplay = NULL;
}

void BCMRoom::ClearGroupDisplay()
{
    while ( !m_lstGroupDisplay.isEmpty() )
        delete m_lstGroupDisplay.takeFirst();
}

void BCMRoom::AddGroupScene(BCMGroupScene *pGroupScene)
{
    // 如果存在则直接返回
    if ( m_lstGroupScene.contains( pGroupScene ) )
        return;

    m_lstGroupScene.append( pGroupScene );

    // 本地数据库
    if ( !BCCommon::g_bConnectWithServer ) {
        BCLocalServer *pServer = BCLocalServer::Application();

        pServer->AddGroupScene(pGroupScene->GetGroupSceneID(),
                               m_id,
                               0,
                               0,
                               1,
                               pGroupScene->GetGroupSceneName());
    }
}

void BCMRoom::RemoveLastGroupScene()
{
    if ( m_lstGroupScene.isEmpty() )
        return;

    BCMGroupScene *pGroupScene = m_lstGroupScene.last();
    m_lstGroupScene.removeOne( pGroupScene );

    // 本地数据库
    if ( !BCCommon::g_bConnectWithServer ) {
        BCLocalServer *pServer = BCLocalServer::Application();
        pServer->RemoveGroupScene(m_id, pGroupScene->GetGroupSceneID());
    }

    delete pGroupScene;
    pGroupScene = NULL;
}

void BCMRoom::RemoveGroupScene(BCMGroupScene *pGroupScene)
{
    if (NULL == pGroupScene)
        return;

    m_lstGroupScene.removeOne( pGroupScene );

    // 本地数据库
    if ( !BCCommon::g_bConnectWithServer ) {
        BCLocalServer *pServer = BCLocalServer::Application();
        pServer->RemoveGroupScene(m_id, pGroupScene->GetGroupSceneID());
    }

    delete pGroupScene;
    pGroupScene = NULL;
}

void BCMRoom::RemoveGroupScene(const QString &id)
{
    // 根据ID找到场景组
    BCMGroupScene *pGroupScene = NULL;
    QListIterator<BCMGroupScene *> it( m_lstGroupScene );
    while ( it.hasNext() ) {
        pGroupScene = it.next();
        if (QString::number(pGroupScene->GetGroupSceneID()) != id)
            continue;

        break;
    }

    if (NULL == pGroupScene)
        return;

    m_lstGroupScene.removeOne( pGroupScene );

    // 本地数据库
    if ( !BCCommon::g_bConnectWithServer ) {
        BCLocalServer *pServer = BCLocalServer::Application();
        pServer->RemoveGroupScene(m_id, pGroupScene->GetGroupSceneID());
    }

    delete pGroupScene;
    pGroupScene = NULL;
}

void BCMRoom::ClearGroupScene()
{
    // 本地数据库
    if ( !BCCommon::g_bConnectWithServer ) {
        BCLocalServer *pServer = BCLocalServer::Application();
        QListIterator<BCMGroupScene *> it( m_lstGroupScene );
        while ( it.hasNext() ) {
            BCMGroupScene *pGroupScene = it.next();

            pServer->RemoveGroupScene(m_id, pGroupScene->GetGroupSceneID());
        }
    }

    while ( !m_lstGroupScene.isEmpty() )
        delete m_lstGroupScene.takeFirst();
}

int BCMRoom::GetWindowSceneID()
{
    // 如果没有场景组则返回0
    if ( m_lstGroupScene.isEmpty() )
#ifdef SCENEIDBEGINFROM0
        return 0;
#else
        return 1;
#endif

    // 循环现有开窗获得WindowID
    QList<int> lstWindowSceneIDs;
    QListIterator<BCMGroupScene *> it( m_lstGroupScene );
    while ( it.hasNext() ) {
        BCMGroupScene *pGroupScene = it.next();
        if (NULL == pGroupScene)
            continue;

        // 循环场景
        QList<BCMWindowScene *> lstWindowScenes = pGroupScene->GetWindowScenes();
        QListIterator<BCMWindowScene *> itScene( lstWindowScenes );
        while ( itScene.hasNext() ) {
            BCMWindowScene *pWindowScene = itScene.next();
            if (NULL == pWindowScene)
                continue;

            // 将ID添加到临时链表
            int id = pWindowScene->GetWindowSceneID();
            lstWindowSceneIDs.append( id );
        }
    }

    // 从0开始循环，如果中间有空缺直接返回，无空缺返回最后一个
#ifdef SCENEIDBEGINFROM0
    for (int i = 0; i < lstWindowSceneIDs.count()+1; i++) {
#else
    for (int i = 1; i < lstWindowSceneIDs.count()+2; i++) {
#endif
        if (lstWindowSceneIDs.contains(i))
            continue;

        return i;
    }

#ifdef SCENEIDBEGINFROM0
    return 0;
#else
    return 1;
#endif
}

bool BCMRoom::IsExistWindowScene(int id)
{
    QListIterator<BCMGroupScene *> itGroups( m_lstGroupScene );
    while ( itGroups.hasNext() ) {
        BCMGroupScene *pGroupScene = itGroups.next();

        QList<BCMWindowScene *> lstWindowScene = pGroupScene->GetWindowScenes();
        QListIterator<BCMWindowScene *> it( lstWindowScene );
        while ( it.hasNext() ) {
            BCMWindowScene *pWindowScene = it.next();
            if (NULL == pWindowScene)
                continue;

            if (pWindowScene->GetWindowSceneID() == id)
                return true;
        }
    }

    return false;
}

void BCMRoom::SetSwitchConfig(int isNet, const QString &ip, int port, const QString &com, int baudrate, int databit, int stopbit, const QString &checkBit, const QString &streamctrl,
                              int type, const QString &cmdon, const QString &cmdoff, bool bSendCmd)
{
    isConnectByNet = isNet;
    switchip = ip;
    switchport = port;
    qsCurrentCom = com;
    nCurrentBaudRate = baudrate;
    nCurrentDataBit = databit;
    nCurrentStopBit = stopbit;
    qsCurrentCheckBit = checkBit;
    qsCurrentStreamCtrl = streamctrl;
    switchtype = type;
    switchoncmd = cmdon;
    switchoffcmd = cmdoff;

    if ( !bSendCmd )
        return;

    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->UpdateRoomSwitchConfig(m_id, isNet, ip, port, com, baudrate, databit, stopbit, checkBit, streamctrl, type, cmdon, cmdoff);
}

void BCMRoom::SetSwitchOn(bool b, bool bSendCmd)
{
    // 赋值是否打开屏幕
    m_bSwitchOn = b;

    if ( !bSendCmd )
        return;

    if ((switchtype != 0) && (switchtype != 1))
        return;

    if ( !isConnectByNet ) {
        if ( !m_serial.isOpen() ) {
            m_serial.setPortName( qsCurrentCom );	//设置COM口

            m_serial.setBaudRate((QSerialPort::BaudRate)nCurrentBaudRate,QSerialPort::AllDirections); //设置波特率和读写方向
            m_serial.setDataBits((QSerialPort::DataBits)nCurrentDataBit);		//数据位为8位
            m_serial.setStopBits((QSerialPort::StopBits)nCurrentStopBit);     //一位停止位

            QSerialPort::Parity eParity = QSerialPort::NoParity;
            if (qsCurrentCheckBit == "Odd")
                eParity = QSerialPort::OddParity;
            else if (qsCurrentCheckBit == "Even")
                eParity = QSerialPort::EvenParity;
            else if (qsCurrentCheckBit == "Mark")
                eParity = QSerialPort::MarkParity;
            else if (qsCurrentCheckBit == "Space")
                eParity = QSerialPort::SpaceParity;

            m_serial.setParity( eParity );	//无校验位

            QSerialPort::FlowControl eFlowControl = QSerialPort::NoFlowControl;
            if (qsCurrentStreamCtrl == "Hardware")
                eFlowControl = QSerialPort::HardwareControl;
            else if (qsCurrentStreamCtrl == "Software")
                eFlowControl = QSerialPort::SoftwareControl;

            m_serial.setFlowControl( eFlowControl );//无流控制
            m_serial.close();                       //先关串口，再打开，可以保证串口不被其它函数占用。
            m_serial.open(QIODevice::ReadWrite);	//以可读写的方式打开串口
        }
    } else {
        // 新建socket
        if (NULL == m_pSwitchSocket) {
            m_pSwitchSocket = new QTcpSocket();
        }

        // 先断开连接
        m_pSwitchSocket->disconnectFromHost();
        m_pSwitchSocket->waitForDisconnected( 50 );

        // 重新连接
        QAbstractSocket::SocketState socketState = m_pSwitchSocket->state();
        if ((socketState != QAbstractSocket::ConnectingState) && (socketState != QAbstractSocket::ConnectedState)) {
            m_pSwitchSocket->connectToHost(QHostAddress(switchip), switchport);
            m_pSwitchSocket->waitForConnected( 50 );
        }
    }

    if (switchtype == 0) {  // 16进制
        QString qsCmd = m_bSwitchOn ? switchoncmd : switchoffcmd;

        // 多个文本使用/分割
        QStringList lstCmdSrc = qsCmd.split("/");
        for (int k = 0; k < lstCmdSrc.count(); k++) {
            QString singleCmdSrc = lstCmdSrc.at( k );
            if ( singleCmdSrc.isEmpty() )
                continue;

            QString cmd;
            QStringList lstCmd = singleCmdSrc.split(" ");
            for (int i = 0; i < lstCmd.count(); i++) {
                QString singleCmd = lstCmd.at( i );
                cmd.append(QChar(singleCmd.toInt(NULL, 16)));
            }

            // 直接发送
            if ( isConnectByNet ) {
                m_pSwitchSocket->write(cmd.toLatin1(), cmd.length());
                m_pSwitchSocket->flush();
            } else {
                m_serial.write( cmd.toLatin1() );
                m_serial.waitForBytesWritten( 50 );
            }

            QThread::msleep( 200 );
        }
    } else if (switchtype == 1) {   // 文本
        QString cmd = m_bSwitchOn ? switchoncmd : switchoffcmd;

        // 多个文本使用/分割
        QStringList lstCmd = cmd.split("/");
        for (int i = 0; i < lstCmd.count(); i++) {
            QString singleCmd = lstCmd.at( i );
            if ( singleCmd.isEmpty() )
                continue;

            // 添加换行符
            singleCmd.append("\r\n");

            // 直接发送
            if ( isConnectByNet ) {
                m_pSwitchSocket->write(singleCmd.toLatin1(), singleCmd.length());
                m_pSwitchSocket->flush();
            } else {
                m_serial.write( singleCmd.toLatin1() );
                m_serial.waitForBytesWritten( 50 );
            }

            QThread::msleep( 200 );
        }
    }

    // 更新数据库
    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->UpdateRoomSwitchStatus(m_id, m_bSwitchOn ? 1 : 0);
}

void BCMRoom::SendCmd(const QString &cmd)
{
    if ( !isConnectByNet ) {
        if ( !m_serial.isOpen() ) {
            m_serial.setPortName( qsCurrentCom );	//设置COM口

            m_serial.setBaudRate((QSerialPort::BaudRate)nCurrentBaudRate,QSerialPort::AllDirections); //设置波特率和读写方向
            m_serial.setDataBits((QSerialPort::DataBits)nCurrentDataBit);		//数据位为8位
            m_serial.setStopBits((QSerialPort::StopBits)nCurrentStopBit);     //一位停止位

            QSerialPort::Parity eParity = QSerialPort::NoParity;
            if (qsCurrentCheckBit == "Odd")
                eParity = QSerialPort::OddParity;
            else if (qsCurrentCheckBit == "Even")
                eParity = QSerialPort::EvenParity;
            else if (qsCurrentCheckBit == "Mark")
                eParity = QSerialPort::MarkParity;
            else if (qsCurrentCheckBit == "Space")
                eParity = QSerialPort::SpaceParity;

            m_serial.setParity( eParity );	//无校验位

            QSerialPort::FlowControl eFlowControl = QSerialPort::NoFlowControl;
            if (qsCurrentStreamCtrl == "Hardware")
                eFlowControl = QSerialPort::HardwareControl;
            else if (qsCurrentStreamCtrl == "Software")
                eFlowControl = QSerialPort::SoftwareControl;

            m_serial.setFlowControl( eFlowControl );//无流控制
            m_serial.close();                       //先关串口，再打开，可以保证串口不被其它函数占用。
            m_serial.open(QIODevice::ReadWrite);	//以可读写的方式打开串口
        }
    } else {
        // 新建socket
        if (NULL == m_pSwitchSocket) {
            m_pSwitchSocket = new QTcpSocket();
        }

        // 先断开连接
        m_pSwitchSocket->disconnectFromHost();
        m_pSwitchSocket->waitForDisconnected( 50 );

        // 重新连接
        QAbstractSocket::SocketState socketState = m_pSwitchSocket->state();
        if ((socketState != QAbstractSocket::ConnectingState) && (socketState != QAbstractSocket::ConnectedState)) {
            m_pSwitchSocket->connectToHost(QHostAddress(switchip), switchport);
            m_pSwitchSocket->waitForConnected( 50 );
        }
    }

    // 直接发送
    if ( isConnectByNet ) {
        m_pSwitchSocket->write(cmd.toLatin1(), cmd.length());
        m_pSwitchSocket->flush();
    } else {
        m_serial.write( cmd.toLatin1() );
        m_serial.waitForBytesWritten( 50 );
    }
}
