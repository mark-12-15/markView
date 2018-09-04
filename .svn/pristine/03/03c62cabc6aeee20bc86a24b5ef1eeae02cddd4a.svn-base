#include "BCMMatrix.h"
#include <QTcpSocket>
#include "../Common/BCCommon.h"

//#define SWITCHGOURPCMD      // 切换指令按照分组模式

BCMMatrix::BCMMatrix()
{
    m_pTcpSocket = NULL;
}

void BCMMatrix::SetMatrixRoomName(const QString &text)
{
    name = text;

    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->UpdateMatrixRoomName(id, name);
}

void BCMMatrix::ConnectDevice()
{
    if ( !isConnectByNet ) {
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
    } else {
        // 新建socket
        if (NULL == m_pTcpSocket) {
            m_pTcpSocket = new QTcpSocket();
            m_pTcpSocket->setSocketOption(QAbstractSocket::KeepAliveOption, 0);
        }

        QAbstractSocket::SocketState socketState = m_pTcpSocket->state();
        if ((socketState != QAbstractSocket::ConnectingState) && (socketState != QAbstractSocket::ConnectedState)) {
            m_pTcpSocket->connectToHost(QHostAddress(ip), port);
            m_pTcpSocket->waitForConnected( 50 );
        }
    }
}

void BCMMatrix::Load(int id)
{
    QString cmd;
#ifdef SWITCHGOURPCMD
    cmd.append(QChar(0xF0));
    cmd.append(QChar(0x0F));
    cmd.append(QChar(0x04));
    cmd.append(QChar(0x05));
    cmd.append(QChar(id));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0xFF));
    cmd.append(QChar(0xFF));
#else
    QString qsBaseCmd = loadFlag;
    if (0 == cmdType) { // 16
        qsBaseCmd = qsBaseCmd.arg(id,4,16,QLatin1Char('0'));
        QStringList lstCmd = qsBaseCmd.split(" ");
        for (int i = 0; i < lstCmd.count(); i++) {
            QString singleCmd = lstCmd.at( i );
            cmd.append(QChar(singleCmd.toInt(NULL, 16)));
        }
    } else {    // ascii
        qsBaseCmd = qsBaseCmd.replace("%1", QString::number(id));
        //qsBaseCmd = loadFlag.arg(id);
        cmd = QString("%1\r\n").arg(qsBaseCmd);
    }
#endif
    SendCmd( cmd );
}

void BCMMatrix::Save(int id)
{
    QString cmd;
#ifdef SWITCHGOURPCMD
     cmd.append(QChar(0xF0));
     cmd.append(QChar(0x0F));
     cmd.append(QChar(0x04));
     cmd.append(QChar(0x04));
     cmd.append(QChar(id));
     cmd.append(QChar(0x00));
     cmd.append(QChar(0x00));
     cmd.append(QChar(0x00));
     cmd.append(QChar(0x00));
     cmd.append(QChar(0x00));
     cmd.append(QChar(0x00));
     cmd.append(QChar(0x00));
     cmd.append(QChar(0xFF));
     cmd.append(QChar(0xFF));
#else
    QString qsBaseCmd = saveFlag;
    if (0 == cmdType) { // 16
        qsBaseCmd = qsBaseCmd.arg(id,4,16,QLatin1Char('0'));
        QStringList lstCmd = qsBaseCmd.split(" ");
        for (int i = 0; i < lstCmd.count(); i++) {
            QString singleCmd = lstCmd.at( i );
            cmd.append(QChar(singleCmd.toInt(NULL, 16)));
        }
    } else {    // ascii
        qsBaseCmd = qsBaseCmd.replace("%1", QString::number(id));
        //qsBaseCmd = saveFlag.arg(id);
        cmd = QString("%1\r\n").arg(qsBaseCmd);
    }
#endif
    SendCmd( cmd );
}

void BCMMatrix::SetSwitch(int inID, int outID)
{
    QString cmd;
#ifdef SWITCHGOURPCMD
    cmd.append(QChar(0xF0));
    cmd.append(QChar(0x0F));
    cmd.append(QChar(0x03));
    cmd.append(QChar(0x09));
    cmd.append(QChar(0x01));
    int gindex = outID / 8;     // 组内索引
    cmd.append(QChar(0x80));
    for (int i = 1; i < 9; i++) {
        if (i == outID) {
            cmd.append(inID);
        } else {
            cmd.append(QChar(0x00));
        }
    }
#else
    QString qsBaseCmd = switchFlag;
    if (0 == cmdType) { // 16
        qsBaseCmd = qsBaseCmd.arg(inID,4,16,QLatin1Char('0')).arg(outID,4,16,QLatin1Char('0'));
        QStringList lstCmd = qsBaseCmd.split(" ");
        for (int i = 0; i < lstCmd.count(); i++) {
            QString singleCmd = lstCmd.at( i );
            cmd.append(QChar(singleCmd.toInt(NULL, 16)));
        }
    } else {    // ascii
        qsBaseCmd = qsBaseCmd.replace("%1", QString::number(inID));
        qsBaseCmd = qsBaseCmd.replace("%2", QString::number(outID));
        //qsBaseCmd = switchFlag.arg(inID).arg(outID);
        cmd = QString("%1\r\n").arg(qsBaseCmd);
    }
#endif

    // 发送指令
    SendCmd( cmd );

    // 修改内存
    for (int i = 0; i < lstOutputNode.count(); i++) {
        sMatrixNode node = lstOutputNode.at( i );
        if (outID != node.id)
            continue;

        node.nSwitch = 1;
        node.nSwitchID = inID;

        lstOutputNode.replace(i, node);
        break;
    }

    // 保存到文件
    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->SetMatrixSwitch(id, inID, outID);
}

void BCMMatrix::SetMatrixName(int output, int nodeid, const QString &name)
{
    // 替换节点
    QList<sMatrixNode> lstNode = (0 == output) ? lstInputNode : lstOutputNode;
    for (int i = 0; i < lstNode.count(); i++) {
        sMatrixNode node = lstNode.at( i );
        if (nodeid != node.id)
            continue;

        node.name = name;
        lstNode.replace(i, node);
        break;
    }

    if (0 == output) {
        lstInputNode = lstNode;
    } else {
        lstOutputNode = lstNode;
    }

    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->SetMatrixName(id, output, nodeid, name);
}

void BCMMatrix::SetCut(int nodeid, int l, int r, int t, int b)
{
    // 修改内存
    for (int i = 0; i < lstInputNode.count(); i++) {
        sMatrixNode node = lstInputNode.at( i );
        if (nodeid != node.id)
            continue;

        node.cutl = l;
        node.cutr = r;
        node.cutt = t;
        node.cutb = b;
        lstInputNode.replace(i, node);
        break;
    }

    // 发送指令
    SendCmd( QString("Vt6CutLeft 0 %1 %2\r\n").arg(nodeid).arg(l) );
    QThread::msleep( 100 );
    SendCmd( QString("Vt6CutRight 0 %1 %2\r\n").arg(nodeid).arg(r) );
    QThread::msleep( 100 );
    SendCmd( QString("Vt6CutUp 0 %1 %2\r\n").arg(nodeid).arg(t) );
    QThread::msleep( 100 );
    SendCmd( QString("VT6CUTDOWN 0 %1 %2\r\n").arg(nodeid).arg(b) );
    QThread::msleep( 100 );

    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->UpdateMatrixInputCut(id, nodeid, l, r, t, b);
}

void BCMMatrix::SendCmd(const QString &cmd)
{
    if ( isConnectByNet ) {
        ConnectDevice();

        if (NULL != m_pTcpSocket) {
            int cmdLen = cmd.length();
            m_pTcpSocket->write(cmd.toLatin1(), cmdLen);
            m_pTcpSocket->flush();
        }
    } else {
        // 连接串口
        if ( !m_serial.isOpen() )
            ConnectDevice();

        m_serial.write( cmd.toLatin1() );
        m_serial.waitForBytesWritten( 50 );
        m_serial.flush();

        // 发完指令关闭串口，这里防止环出串口
        m_serial.close();
    }

    // 添加到调试窗口
    MainWindow *pMainWindow = BCCommon::Application();
    pMainWindow->AddDebugCmd( cmd );
}
