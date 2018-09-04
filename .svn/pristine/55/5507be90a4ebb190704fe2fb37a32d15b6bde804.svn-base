#include "BCLocalSerialPort.h"
#include "BCLocalServer.h"
#include <WinSock2.h>
#include <QTimer>
#include "BCCommon.h"

BCLocalSerialPort::BCLocalSerialPort(QObject *parent)
    :QSerialPort(parent)
{
    m_nType = -1;
    m_nRequestcount = 0;

    connect(this, SIGNAL(readyRead()), this, SLOT(onRecvMessage()));
    Init();

    m_pTimer = new QTimer( this );
    m_pTimer->setInterval( 500 );
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
}

BCLocalSerialPort::~BCLocalSerialPort()
{
    this->close();
}

void BCLocalSerialPort::Init()
{
    BCLocalServer *pServer = BCLocalServer::Application();

    this->setPortName( pServer->m_qsCurrentCom );	//设置COM口

    this->setBaudRate((QSerialPort::BaudRate)pServer->m_nCurrentBaudRate,QSerialPort::AllDirections); //设置波特率和读写方向
    this->setDataBits((QSerialPort::DataBits)pServer->m_nCurrentDataBit);		//数据位为8位
    this->setStopBits((QSerialPort::StopBits)pServer->m_nCurrentStopBit);     //一位停止位

    QSerialPort::Parity eParity = QSerialPort::NoParity;
    if (pServer->m_qsCurrentCheckBit == "Odd")
        eParity = QSerialPort::OddParity;
    else if (pServer->m_qsCurrentCheckBit == "Even")
        eParity = QSerialPort::EvenParity;
    else if (pServer->m_qsCurrentCheckBit == "Mark")
        eParity = QSerialPort::MarkParity;
    else if (pServer->m_qsCurrentCheckBit == "Space")
        eParity = QSerialPort::SpaceParity;

    this->setParity( eParity );	//无校验位

    QSerialPort::FlowControl eFlowControl = QSerialPort::NoFlowControl;
    if (pServer->m_qsCurrentStreamCtrl == "Hardware")
        eFlowControl = QSerialPort::HardwareControl;
    else if (pServer->m_qsCurrentStreamCtrl == "Software")
        eFlowControl = QSerialPort::SoftwareControl;

    this->setFlowControl( eFlowControl );//无流控制
    this->close();                       //先关串口，再打开，可以保证串口不被其它函数占用。
    this->open(QIODevice::ReadWrite);	//以可读写的方式打开串口
}

void BCLocalSerialPort::RequestConfig(int type)
{
    m_nType = type;
    m_byteRecv.clear();

    int internal = 50;
    if (1 == m_nType) { // 4000
        internal = 500;
        QString cmd = "readstat\r\n";
        this->write(cmd.toLatin1(), cmd.length());
    } else if (11 == m_nType) {
        this->write(QString("getip\r\n").toLatin1());
    } else if (10 == m_nType) {
        this->write(QString("getformat\r\n").toLatin1());
    }

    m_pTimer->setInterval( internal );
    m_pTimer->start();
    m_nTimerTimes = 0;
}

void BCLocalSerialPort::onRecvMessage()
{
    QByteArray byteRecv = this->readAll();
    m_byteRecv.append( byteRecv );
}

void BCLocalSerialPort::onTimeOut()
{
    m_nTimerTimes++;

    if (1 == m_nType) { // 4000
        // 判断起始符和结束符
        if (m_byteRecv.length() == 12020) { // 4U
            if ((QChar(m_byteRecv.at(0)) == QChar(0xA6))
                    && (QChar(m_byteRecv.at(1)) == QChar(0xEC))
                    && (QChar(m_byteRecv.at(2)) == QChar(0xAA))
                    && (QChar(m_byteRecv.at(3)) == QChar(0x16))
                    && (QChar(m_byteRecv.at(4)) == QChar(0x55))
                    && (QChar(m_byteRecv.at(5)) == QChar(0xAA))
                    && (QChar(m_byteRecv.at(6)) == QChar(0x77))
                    && (QChar(m_byteRecv.at(7)) == QChar(0x66))) {
                // success
                m_nRequestcount = 0;
                m_nTimerTimes = 0;

                m_pTimer->stop();

                BCLocalServer *pServer = BCLocalServer::Application();
                QStringList lstChannelData, lstGroupDisplayData, lstDefaultScene;
                QList<sSerialSignalWindow> lstSignalWindow;   // 信号窗链表

                int k = 0;                  // 数组的起始值
                int n = 16;
                unsigned char cHighLow[2];  // 计算高低位的临时数组，串口数据需要两位进行组合，而且高低位是反向的

                // group count
                cHighLow[0] = m_byteRecv.at(21);
                cHighLow[1] = m_byteRecv.at(20);
                int nGroupCount= cHighLow[0]<<8|cHighLow[1];

                // group display data
                QMap<int, QList<int>> mapGroupDisplayBaseInfo;
                for (int i = 0; i < nGroupCount; i++) {
                    cHighLow[0] = m_byteRecv.at((n+i*16+0)*2+1);
                    cHighLow[1] = m_byteRecv.at((n+i*16+0)*2);
                    int groupid = cHighLow[0]<<8|cHighLow[1]; // groupid
                    cHighLow[0] = m_byteRecv.at((n+i*16+3)*2+1);
                    cHighLow[1] = m_byteRecv.at((n+i*16+3)*2);
                    int formatx = cHighLow[0]<<8|cHighLow[1]; // formatx
                    cHighLow[0] = m_byteRecv.at((n+i*16+4)*2+1);
                    cHighLow[1] = m_byteRecv.at((n+i*16+4)*2);
                    int formaty = cHighLow[0]<<8|cHighLow[1]; // formaty
                    cHighLow[0] = m_byteRecv.at((n+i*16+5)*2+1);
                    cHighLow[1] = m_byteRecv.at((n+i*16+5)*2);
                    unsigned int xsize = cHighLow[0]<<8|cHighLow[1]; // xsize
                    cHighLow[0] = m_byteRecv.at((n+i*16+6)*2+1);
                    cHighLow[1] = m_byteRecv.at((n+i*16+6)*2);
                    int ysize = cHighLow[0]<<8|cHighLow[1]; // ysize
                    cHighLow[0] = m_byteRecv.at((n+i*16+7)*2+1);
                    cHighLow[1] = m_byteRecv.at((n+i*16+7)*2);
                    int posx = cHighLow[0]<<8|cHighLow[1]; // posx
                    cHighLow[0] = m_byteRecv.at((n+i*16+8)*2+1);
                    cHighLow[1] = m_byteRecv.at((n+i*16+8)*2);
                    int posy = cHighLow[0]<<8|cHighLow[1]; // posy

                    qDebug() << "group display: " << groupid << formatx << formaty << xsize << ysize << posx << posy;
                    if ((formatx == 0) || (formaty == 0) || (xsize == 0) || (ysize == 0)) {
                        continue;
                    }

                    // 放基本信息，供下面默认窗口时使用
                    QList<int> lstGroupDisplayBaseInfo;
                    lstGroupDisplayBaseInfo << posx << posy;
                    mapGroupDisplayBaseInfo.insert(groupid, lstGroupDisplayBaseInfo);

                    lstGroupDisplayData.append( QString::number( groupid ) );
                    lstGroupDisplayData.append( QString::number( formatx ) );
                    lstGroupDisplayData.append( QString::number( formaty ) );
                    lstGroupDisplayData.append( QString::number( xsize ) );
                    lstGroupDisplayData.append( QString::number( ysize ) );
                    lstGroupDisplayData.append( QString::number( posx ) );
                    lstGroupDisplayData.append( QString::number( posy ) );
                    pServer->AddLog( QString("Group Display: %1, %2, %3, %4, %5, %6, %7").arg(groupid).arg(formatx).arg(formaty).arg(xsize).arg(ysize).arg(posx).arg(posy) );
                }

                if ( lstGroupDisplayData.isEmpty() ) {
                    emit sigDemoMode();
                    return;
                }

                k = n+nGroupCount*16+0;
                n = k+1;

                // channel count
                cHighLow[0] = m_byteRecv.at(17);
                cHighLow[1] = m_byteRecv.at(16);
                int nChannelCount= cHighLow[0]<<8|cHighLow[1];   // 全部通道，可用不可用在一起

                // temp memory for default scene
                QList<int> lstSort;     // 存放叠层链表
                for (int i = 0; i < nChannelCount; i++) {
                    cHighLow[0] = m_byteRecv.at((n+i+0)*2+1);
                    cHighLow[1] = m_byteRecv.at((n+i+0)*2);
                    int sort = cHighLow[0]<<8|cHighLow[1];           // sort
                    lstSort.append( sort );
                }

                k = n+nChannelCount;
                n = k+1;

                // temp memory for default scene
                int nSignalWindow = n;

                k = n+nChannelCount*6;
                n = k+0;

                // channel valid count
                cHighLow[0] = m_byteRecv.at(23);
                cHighLow[1] = m_byteRecv.at(22);
                int nChannelValidCount= cHighLow[0]<<8|cHighLow[1];

                // channel data
                if (0 == BCCommon::g_nIsUseInputChannelConfig) {
                    int tempBoardpos = 0;   // ??? 变量临时使用，硬件修改后删除
                    int tempVideoBoardid = -1;
                    int tempVideoBoardpos = 0;
                    for (int i = 0; i < nChannelValidCount; i++) {
                        cHighLow[0] = m_byteRecv.at((n+i*4+0)*2+1);
                        cHighLow[1] = m_byteRecv.at((n+i*4+0)*2);
                        int xpixels = cHighLow[0]<<8|cHighLow[1];           // xpixels
                        cHighLow[0] = m_byteRecv.at((n+i*4+1)*2+1);
                        cHighLow[1] = m_byteRecv.at((n+i*4+1)*2);
                        int ypixels = cHighLow[0]<<8|cHighLow[1];           // ypixels
                        cHighLow[0] = m_byteRecv.at((n+i*4+2)*2+1);
                        cHighLow[1] = m_byteRecv.at((n+i*4+2)*2);
                        int chid = cHighLow[0]<<8|cHighLow[1];              // chid
                        cHighLow[0] = m_byteRecv.at((n+i*4+3)*2+1);
                        cHighLow[1] = m_byteRecv.at((n+i*4+3)*2);
                        unsigned short type = cHighLow[0]<<8|cHighLow[1];   // type
                        unsigned short boardid = type & 0xFF;               // 板卡ID
                        unsigned short chtype = type>>12;                   // 0普清 3高清 9IPV 8Vedio
                        unsigned short boardpos = type<<4;
                        boardpos = boardpos>>12;                            // 板卡位置，如：0 1 2 3

                        // ??? 14U设备高清板卡位置不正确，如两块板卡回来的位置是4 6 0 2，应为0 1 0 1
                        if (3 == chtype) {
                            boardpos = tempBoardpos % 2;
                            tempBoardpos++;
                        }

                        // ??? video返回板卡位置数据有误，这里手动判断
                        if (8 == chtype) {
                            if (tempVideoBoardid == boardid) {
                                tempVideoBoardpos++;
                            }

                            // 记录上个板卡位置
                            if (tempVideoBoardid != boardid) {
                                tempVideoBoardid = boardid;
                                tempVideoBoardpos = 0;
                            }

                            // 纠正板卡位置信息
                            boardpos = tempVideoBoardpos;
                        }

                        lstChannelData.append( QString::number( chid ) );
                        lstChannelData.append( QString::number( chtype ) );
                        lstChannelData.append( QString::number( boardid ) );
                        lstChannelData.append( QString::number( boardpos ) );
                        lstChannelData.append( QString::number( xpixels ) );
                        lstChannelData.append( QString::number( ypixels ) );
                        pServer->AddLog( QString("Channel: %1, %2, %3, %4, %5, %6").arg(chid).arg(chtype).arg(boardid).arg(boardpos).arg(xpixels).arg(ypixels) );
                        qDebug() << "channel: " << chid << chtype  << boardid << boardpos << xpixels << ypixels;
                    }
                } else {
                    for (int i = 0; i < BCCommon::g_npcCount; i++) {
                        lstChannelData.append( QString::number( i+BCCommon::g_npcBeginID ) );
                        lstChannelData.append( QString::number( 0 ) );
                        lstChannelData.append( QString::number( 0 ) );  // 板卡ID和板卡位置，这里信息不对，需要界面提供，但界面此处功能是否需要扩展需要商议
                        lstChannelData.append( QString::number( 0 ) );
                        lstChannelData.append( QString::number( 1920 ) );
                        lstChannelData.append( QString::number( 1080 ) );
                    }
                    for (int i = 0; i < BCCommon::g_nipvCount; i++) {
                        lstChannelData.append( QString::number( i+BCCommon::g_nipvBeginID ) );
                        lstChannelData.append( QString::number( 9 ) );
                        lstChannelData.append( QString::number( 0 ) );  // 板卡ID和板卡位置，这里信息不对，需要界面提供，但界面此处功能是否需要扩展需要商议
                        lstChannelData.append( QString::number( 0 ) );
                        lstChannelData.append( QString::number( 1920 ) );
                        lstChannelData.append( QString::number( 1080 ) );
                    }
                    for (int i = 0; i < BCCommon::g_nvedioCount; i++) {
                        lstChannelData.append( QString::number( i+BCCommon::g_nvedioBeginID ) );
                        lstChannelData.append( QString::number( 8 ) );
                        lstChannelData.append( QString::number( 0 ) );  // 板卡ID和板卡位置，这里信息不对，需要界面提供，但界面此处功能是否需要扩展需要商议
                        lstChannelData.append( QString::number( 0 ) );
                        lstChannelData.append( QString::number( 800 ) );
                        lstChannelData.append( QString::number( 540 ) );
                    }
                    for (int i = 0; i < BCCommon::g_nhdCount; i++) {
                        lstChannelData.append( QString::number( (i*2)+BCCommon::g_nhdBeginID ) );
                        lstChannelData.append( QString::number( 3 ) );
                        lstChannelData.append( QString::number( 0 ) );  // 板卡ID和板卡位置，这里信息不对，需要界面提供，但界面此处功能是否需要扩展需要商议
                        lstChannelData.append( QString::number( 0 ) );
                        lstChannelData.append( QString::number( 3840 ) );
                        lstChannelData.append( QString::number( 2160 ) );
                    }
                }

                k = n+4*nChannelValidCount;
                n = k+0;

                // ??? 暂时不知道数组是做什么用的
                for (int i = 0; i < 32; i++) {
                    cHighLow[0] = m_byteRecv.at((n+i*1+0)*2+1);
                    cHighLow[1] = m_byteRecv.at((n+i*1+0)*2);
                    //int x = cHighLow[0]<<8|cHighLow[1];
                }

                k = n+32;
                n = k+0;

                // ??? 暂时不知道数组是做什么用的
                int j = 0;
                cHighLow[0] = m_byteRecv.at((n+j+0)*2+1);
                cHighLow[1] = m_byteRecv.at((n+j+0)*2);
                //int nInitBackBoardType = cHighLow[0]<<8|cHighLow[1];
                j++;
                cHighLow[0] = m_byteRecv.at((n+j+0)*2+1);
                cHighLow[1] = m_byteRecv.at((n+j+0)*2);
                int nMaxBoardLimit = cHighLow[0]<<8|cHighLow[1];
                for (int i = 0; i < nMaxBoardLimit; i++) {
                    cHighLow[0] = m_byteRecv.at((n+j+0)*2+1);
                    cHighLow[1] = m_byteRecv.at((n+j+0)*2);
                    //int nMainBoardType = cHighLow[0]<<8|cHighLow[1];
                    j++;
                    cHighLow[0] = m_byteRecv.at((n+j+0)*2+1);
                    cHighLow[1] = m_byteRecv.at((n+j+0)*2);
                    //int nAuxMainBoardType = cHighLow[0]<<8|cHighLow[1];
                    j++;

                }

                // ??? 暂时不知道数组是做什么用的
                j++;
                cHighLow[0] = m_byteRecv.at((n+j+0)*2+1);
                cHighLow[1] = m_byteRecv.at((n+j+0)*2);
                //int nK = cHighLow[0]<<8|cHighLow[1] - 0xea00;

                // 取当前段的j
                cHighLow[0] = m_byteRecv.at(25);
                cHighLow[1] = m_byteRecv.at(24);
                j = cHighLow[0]<<8|cHighLow[1];

                k = n+j;
                n = k+0;

                // temp memory for default scene
                int nGroupIndex = n;

                n += nChannelCount;

                // temp memory for default scene
                int nGroupData = n;

                // default scene
                for (int i = 0; i < nChannelCount; i++) {
                    cHighLow[0] = m_byteRecv.at((nSignalWindow+i*6+1)*2+1);
                    cHighLow[1] = m_byteRecv.at((nSignalWindow+i*6+1)*2);
                    int enable = cHighLow[0]<<8|cHighLow[1];                    // enable, 1/65535
                    if (1 != enable)
                        continue;

                    cHighLow[0] = m_byteRecv.at((nSignalWindow+i*6+0)*2+1);
                    cHighLow[1] = m_byteRecv.at((nSignalWindow+i*6+0)*2);
                    int chid = cHighLow[0]<<8|cHighLow[1];                      // chid
                    cHighLow[0] = m_byteRecv.at((nSignalWindow+i*6+2)*2+1);
                    cHighLow[1] = m_byteRecv.at((nSignalWindow+i*6+2)*2);
                    int x0 = cHighLow[0]<<8|cHighLow[1];                        // left
                    cHighLow[0] = m_byteRecv.at((nSignalWindow+i*6+3)*2+1);
                    cHighLow[1] = m_byteRecv.at((nSignalWindow+i*6+3)*2);
                    int y0 = cHighLow[0]<<8|cHighLow[1];                        // top
                    cHighLow[0] = m_byteRecv.at((nSignalWindow+i*6+4)*2+1);
                    cHighLow[1] = m_byteRecv.at((nSignalWindow+i*6+4)*2);
                    int x1 = cHighLow[0]<<8|cHighLow[1];                        // right
                    cHighLow[0] = m_byteRecv.at((nSignalWindow+i*6+5)*2+1);
                    cHighLow[1] = m_byteRecv.at((nSignalWindow+i*6+5)*2);
                    int y1 = cHighLow[0]<<8|cHighLow[1];                        // bottom

                    cHighLow[0] = m_byteRecv.at((nGroupIndex+i+0)*2+1);
                    cHighLow[1] = m_byteRecv.at((nGroupIndex+i+0)*2);
                    unsigned short nMapGroupIndex = cHighLow[0]<<8|cHighLow[1]; // groupid
                    nMapGroupIndex -= 0xc000;
                    cHighLow[0] = m_byteRecv.at((nGroupData+i+0)*2+1);
                    cHighLow[1] = m_byteRecv.at((nGroupData+i+0)*2);
                    int nMapGroupData = cHighLow[0]<<8|cHighLow[1];             // wid

                    // 添加偏移量
                    MainWindow *pMainWindow = BCCommon::Application();
                    QSize size = pMainWindow->GetWinsizeOffset( nMapGroupIndex );
                    x0 -= size.width();
                    x1 -= size.width();
                    y0 -= size.height();
                    y1 -= size.height();

                    // 添加到链表，方便后面进行排序
                    sSerialSignalWindow ssigWindow;
                    ssigWindow.gid = nMapGroupIndex;
                    ssigWindow.chid = chid;
                    ssigWindow.winid = nMapGroupData;

                    // 判断是否有设置偏移量
                    if ( BCCommon::g_bDefaultWindowOffset ) {
                        QList<int> lstGroupDisplayBaseInfo = mapGroupDisplayBaseInfo.value(ssigWindow.gid);
                        if (lstGroupDisplayBaseInfo.count() == 2) {
                            x0 -= lstGroupDisplayBaseInfo.first();
                            x1 -= lstGroupDisplayBaseInfo.first();
                            y0 -= lstGroupDisplayBaseInfo.last();
                            y1 -= lstGroupDisplayBaseInfo.last();
                        }
                    }

                    ssigWindow.rect = QRect(x0, y0, x1-x0, y1-y0);
                    ssigWindow.sort = lstSort.indexOf( i );
                    lstSignalWindow.append( ssigWindow );

                    pServer->AddLog( QString("Default Signal Window : %1, %2, %3, %4, %5, %6").arg(ssigWindow.gid).arg(ssigWindow.chid).arg(ssigWindow.rect.left()).arg(ssigWindow.rect.top()).arg(ssigWindow.rect.width()).arg(ssigWindow.rect.height()) );
                }

                // 排序；规则是屏组ID和叠放顺序倒序
                sortSignalWindow( &lstSignalWindow );

                // 添加到链表中
                for (int i = 0; i < lstSignalWindow.count(); i++) {
                    sSerialSignalWindow ssigWindow = lstSignalWindow.at( i );

                    lstDefaultScene.append( QString::number( ssigWindow.gid ) );
                    lstDefaultScene.append( QString::number( ssigWindow.winid ) );
                    lstDefaultScene.append( QString::number( ssigWindow.chid ) );
                    lstDefaultScene.append( QString::number( ssigWindow.rect.left() ) );
                    lstDefaultScene.append( QString::number( ssigWindow.rect.top() ) );
                    lstDefaultScene.append( QString::number( ssigWindow.rect.width() ) );
                    lstDefaultScene.append( QString::number( ssigWindow.rect.height() ) );
                    //pServer->AddLog( QString("Default Signal Window : %1, %2, %3, %4, %5, %6").arg(ssigWindow.gid).arg(ssigWindow.chid).arg(ssigWindow.rect.left()).arg(ssigWindow.rect.top()).arg(ssigWindow.rect.width()).arg(ssigWindow.rect.height()) );
                    qDebug() << "default signal window: " << ssigWindow.gid << ssigWindow.chid << ssigWindow.winid << ssigWindow.rect << ssigWindow.sort;
                }

                // 发送信号
                emit sigVP4000Config(lstChannelData, lstGroupDisplayData, lstDefaultScene);
                return;
            }
        }
    } else if (11 == m_nType) { // 2000 ip
        QString qsDeviceConfig( m_byteRecv );

        // 当head不对时重新获取
        if ( qsDeviceConfig.contains("IP:") ) {

            // 当参数小于8个时重新获取
            qsDeviceConfig = qsDeviceConfig.right(qsDeviceConfig.length() - qsDeviceConfig.indexOf("IP:"));
            qsDeviceConfig.replace("IP:", "");
            QStringList lstPara = qsDeviceConfig.split(" ");
            if (lstPara.count() >= 2) {
                // success
                m_nRequestcount = 0;
                m_nTimerTimes = 0;

                m_pTimer->stop();

                // 取参数
                QString qsIP = lstPara.at(0);

                qDebug() << "2000 ip ~~~~~~~~~~~~~~~~~~~~~~~~";
                emit sigVP2000IP(0, qsIP);
                return;
            }
        }
    } else if (10 == m_nType) { // 2000 format
        QString qsDeviceConfig( m_byteRecv );

        // 当head不对时重新获取
        if (qsDeviceConfig.left(6) == QString("FORMAT")) {

            // 当参数小于8个时重新获取
            qsDeviceConfig.replace("FORMAT:", "");
            QStringList lstPara = qsDeviceConfig.split("\t");
            if (lstPara.count() >= 8) {
                // success
                m_nRequestcount = 0;
                m_nTimerTimes = 0;

                m_pTimer->stop();

                // 取参数
                int arrayX = lstPara.at(0).toInt();
                int arrayY = lstPara.at(1).toInt();
                int resolutionX = lstPara.at(2).toInt();
                int resolutionY = lstPara.at(3).toInt();
                int pcCount = lstPara.at(4).toInt();
                int vedioCount = lstPara.at(5).toInt();
                int hdCount = lstPara.at(6).toInt();

                qDebug() << "2000 config ~~~~~~~~~~~~~~~~~~~~~~";
                emit sigVP2000Config(0, arrayX, arrayY, resolutionX, resolutionY, pcCount, vedioCount, hdCount);
                return;
            }
        }
    }

    int times = (1 == m_nType) ? 3 : 20;    // 4000 请求3次，2000请求20次
    if (m_nTimerTimes > times) {
        qDebug() << "time out ..times over 1500, request count: " << m_nRequestcount;
        m_pTimer->stop();

        if (m_nRequestcount < times) {
            m_nRequestcount++;

            RequestConfig( m_nType );
        } else {
            // get info err
            m_nRequestcount = 0;
            m_nTimerTimes = 0;

            emit sigDemoMode();
        }
    }
}

void BCLocalSerialPort::sortSignalWindow(QList<sSerialSignalWindow> *pList)
{
    qSort(pList->begin(), pList->end(), compareSignalWindow);
}

bool BCLocalSerialPort::compareSignalWindow(const sSerialSignalWindow &win1, const sSerialSignalWindow &win2)
{
    if (win1.gid == win2.gid) {
        if (win1.sort > win2.sort) {
            return true;
        } else {
            return false;
        }
    } else if (win1.gid > win2.gid) {
        return false;
    } else {
        return true;
    }
}
