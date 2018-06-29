#include "BCSettingCommunicationDlg.h"
#include "ui_BCSettingCommunicationDlg.h"
#include <QSettings>
#include <qt_windows.h>
#include <QMessageBox>
#include <QNetworkInterface>
#include <QSerialPortInfo>
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"
#include "BCSettingWaitingDlg.h"

#define NOJOINTMATRIX       // 不要矩阵级联

BCSettingCommunicationUdp::BCSettingCommunicationUdp(BCSettingCommunicationDlg *pDlg)
    :QObject(NULL)
{
    m_pDlg = pDlg;
    BCCommon::g_nPreviewTick = (1234 == BCCommon::g_nPreviewTick) ? GetTickCount() : BCCommon::g_nPreviewTick;

    // 搜索设备的UDP
    m_pUdpSocket = new QUdpSocket(this);
    m_pUdpSocket->bind(1500, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    //m_pUdpSocket->bind(1500, QUdpSocket::ShareAddress);
    connect(m_pUdpSocket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));

    // 搜索预监回显的UDP
    m_pPreviewUdpSocket = new QUdpSocket(this);
    connect(m_pPreviewUdpSocket, SIGNAL(readyRead()), this, SLOT(onRecvPreviewUdpData()));

    // ----------------------------------------------------------------------------------------------
    // get ip
    BCLocalServer *pServer = BCLocalServer::Application();

    QString qsCurrentIP;
    QList<QNetworkInterface> network = QNetworkInterface::allInterfaces();
    foreach (QNetworkInterface net, network) {
        // 双网卡判断不出来时使用
        QString netName = net.humanReadableName();
        if ( !BCCommon::g_qsConnectName.isEmpty() ) {
            if (!netName.contains(BCCommon::g_qsConnectName))
                continue;
        }
        // 不要回环(127.0.0.1)，要已经分配资源并且在用的网卡
        if (!(net.flags() & QNetworkInterface::IsLoopBack) && (net.flags() & QNetworkInterface::IsUp) && (net.flags() & QNetworkInterface::IsRunning)) {
            QList<QNetworkAddressEntry> allIP = net.addressEntries();
            foreach(QNetworkAddressEntry ip, allIP) {
                if (ip.ip().protocol() == QAbstractSocket::IPv4Protocol) {
                    qsCurrentIP = ip.ip().toString();

                   // qDebug() << qsCurrentIP << net.flags();
                    pServer->AddLog( QString("Search IP: %1").arg(qsCurrentIP) );
                }
            }
        }
    }

    if (qsCurrentIP.isEmpty())
        qsCurrentIP = QHostAddress(QHostAddress::LocalHost).toString();

    //qDebug() << qsCurrentIP << "~~~~";

    QStringList lstIP = qsCurrentIP.split(".");
    for (int i = 0; i < lstIP.count(); i++) {
        m_lstIP.append( lstIP.at(i).toUInt() );
    }
    // ----------------------------------------------------------------------------------------------

    m_pTimer = new QTimer();
    m_pTimer->setInterval( 100 );
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(onSearchDevice()));             // 搜索通讯设备
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(onSearchPreviewDevice()));      // 搜索预监设备
    m_pTimer->start();
}

BCSettingCommunicationUdp::~BCSettingCommunicationUdp()
{
    m_pTimer->stop();
    m_pTimer->deleteLater();

    m_pUdpSocket->deleteLater();
    m_pPreviewUdpSocket->deleteLater();
}

unsigned int make_boardcast_cmd_str(int index,unsigned char ssmsg[], BSDevice *pDevice)
{
    const BYTE usr_set_cmd[85]=
    {
    0xff,0x52,0x06,0x00,0x71,0x77,0x7c,0x42,0x2f,0x61,0x64,0x6d,0x69,0x6e,0x00,0x61,0x64,0x6d,0x69,0x6e,0x00,
    0x00,0x10,0x0e,0x00,0x08,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x8c,0x4e,0x2a,0x20,0x31,0x39,0x32,0x2e,0x31,
    0x36,0x38,0x2e,0x30,0x2e,0x32,0x30,0x31,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xc9,0x00,0xa8,0xc0,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xeb
    };

    const BYTE usr_set_basic_cmd[89]=
    {
    0xff,0x56,0x05,0x00,0x71,0x77,0x7c,0x42,0x2f,0x61,0x64,0x6d,0x69,0x6e,0x00,0x61,
    0x64,0x6d,0x69,0x6e,0x00,0x95,0x63,0x03,0x00,0x00,0x00,0x50,0x00,0x00,0x07,0x00,
    0xa8,0xc0,0xc9,0x00,0xa8,0xc0,0x00,0xff,0xff,0xff,0x55,0x6c,0x6c,0x2d,0x66,0x32,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x61,0x64,0x6d,0x69,0x6e,0x00,
    0x61,0x64,0x6d,0x69,0x6e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03
    };

    const BYTE usr_reboot_cmd[22]=
    {
    0xff,0x13,0x02,0x00,0x71,0x77,0x7c,0x42,0x2f,0x61,0x64,0x6d,0x69,0x6e,0x00,0x61,0x64,0x6d,0x69,0x6e,0x00,0xfc
    };

    unsigned short	i;
    unsigned char	B0;

    if(index==0)
    {
            for(i=0;i<85;i++)
            {
                ssmsg[i] = usr_set_cmd[i];
            }

            for (int i = 0; i < 6; i++) {
                ssmsg[i+3] = pDevice->mac[i];
            }

            ssmsg[21] = 0x00;
            ssmsg[22] = 0x10;
            ssmsg[23] = 0x0e;
            ssmsg[24] = 0x00;

            ssmsg[33] = ((BYTE *)&pDevice->port)[0];//0x0e;
            ssmsg[34] = ((BYTE *)&pDevice->port)[1];//0x00;

            ssmsg[35] = ((BYTE *)&pDevice->port)[0];//0x0e;
            ssmsg[36] = ((BYTE *)&pDevice->port)[1];//0x00;

            int ip1 = 0xff & pDevice->ip[0];
            int ip2 = 0xff & pDevice->ip[1];
            int ip3 = 0xff & pDevice->ip[2];
            int ip4 = 0xff & pDevice->ip[3];
            sprintf((char *)&ssmsg[37],"%d.%d.%d.%d", ip1, ip2, ip3, ip4);
            //sprintf((char *)&ssmsg[37],"%s",tmp_ip_addr_str);
            B0 = 0;
            for(i=1;i<84;i++)
            {
                B0 = B0 + ssmsg[i];
            }
            ssmsg[84] = B0;
            return	85;
    }

    if(index==1)
    {
            for(i=0;i<89;i++)
            {
                ssmsg[i] = usr_set_basic_cmd[i];
            }

            for (int i = 0; i < 6; i++) {
                ssmsg[i+3] = pDevice->mac[i];
            }

            ssmsg[24] = 0x80;

            ssmsg[33] = ((BYTE *)&pDevice->ip)[0];
            ssmsg[32] = ((BYTE *)&pDevice->ip)[1];
            ssmsg[31] = ((BYTE *)&pDevice->ip)[2];
            ssmsg[30] = ((BYTE *)&pDevice->ip)[3];

            ssmsg[37] = ((BYTE *)&pDevice->gateway)[0];
            ssmsg[36] = ((BYTE *)&pDevice->gateway)[1];
            ssmsg[35] = ((BYTE *)&pDevice->gateway)[2];
            ssmsg[34] = ((BYTE *)&pDevice->gateway)[3];

            ssmsg[41] = ((BYTE *)&pDevice->mask)[0];
            ssmsg[40] = ((BYTE *)&pDevice->mask)[1];
            ssmsg[39] = ((BYTE *)&pDevice->mask)[2];
            ssmsg[38] = ((BYTE *)&pDevice->mask)[3];

            ssmsg[42] = pDevice->name[0];//'B';
            ssmsg[43] = pDevice->name[1];//'R';
            ssmsg[44] = pDevice->name[2];//'L';
            ssmsg[45] = pDevice->name[3];//'C';
            ssmsg[46] = pDevice->name[4];//'N';
            ssmsg[47] = pDevice->name[5];//'T';

            B0 = 0;
            for(i=1;i<88;i++)
            {
                B0 = B0 + ssmsg[i];
            }
            ssmsg[88] = B0;
            return	89;
    }

    if(index==2)
    {
            for(i=0;i<22;i++)
            {
                ssmsg[i] = usr_reboot_cmd[i];
            }

            ssmsg[3] = pDevice->mac[0];
            ssmsg[4] = pDevice->mac[1];
            ssmsg[5] = pDevice->mac[2];
            ssmsg[6] = pDevice->mac[3];
            ssmsg[7] = pDevice->mac[4];
            ssmsg[8] = pDevice->mac[5];

            B0 = 0;
            for(i=1;i<21;i++)
            {
                B0 = B0 + ssmsg[i];
            }
            ssmsg[21] = B0;
            return	22;
    }

    return	0;
}

void BCSettingCommunicationUdp::ModifyDeviceConfig(BSDevice *pDevice, int type)
{
    if (NULL == pDevice)
        return;

    unsigned char ssmsg[256];
    int cmdLen = make_boardcast_cmd_str(type, ssmsg, pDevice);
    m_pUdpSocket->writeDatagram((char*)ssmsg, cmdLen, QHostAddress::Broadcast, 1500);
}

void BCSettingCommunicationUdp::onSearchPreviewDevice()
{
    // 只有VP4000才搜索设备IP
    if (m_pDlg->GetDeviceType() != 2)
        return;

    if (4 != m_lstIP.count() )
        return;

    unsigned char ssmsg[16];

    ssmsg[0] = 0xec;
    ssmsg[1] = 0x98;
    ssmsg[2] = 0x16;
    ssmsg[3] = 0x10;
    if (1 == BCCommon::g_nPreviewDirectDevice) {    // 搜索设备
        ssmsg[4] = 0x01;
    } else {                                        // 搜索Vedio Server
        ssmsg[4] = 0x02;
    }

    ssmsg[5] = m_lstIP.at(0);
    ssmsg[6] = m_lstIP.at(1);
    ssmsg[7] = m_lstIP.at(2);
    ssmsg[8] = m_lstIP.at(3);
    ssmsg[9] = BCCommon::g_nPreviewTick & 0x00ff;//g_local_ip_address[3];
    ssmsg[10] = ((BCCommon::g_nPreviewTick>>8)&0x00ff);

    ssmsg[11] = 0;  // 顺序4个应该是tcp socket的状态值，暂时看有3种：0 0x1234 0x5678，但似乎都没生效
    ssmsg[12] = 0;
    ssmsg[13] = 0;
    ssmsg[14] = 0;
    ssmsg[15] = 0;

    // 固定广播端口
    if (1 == BCCommon::g_nPreviewDirectDevice) {
        m_pPreviewUdpSocket->writeDatagram((char*)ssmsg, 8, QHostAddress::Broadcast, 6061);   // 搜索设备
    } else {
        m_pPreviewUdpSocket->writeDatagram((char*)ssmsg, 16, QHostAddress::Broadcast, 6063); // 搜索Vedio Server
    }
}

void BCSettingCommunicationUdp::onRecvPreviewUdpData()
{
    while(m_pPreviewUdpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(m_pPreviewUdpSocket->pendingDatagramSize());

        unsigned char tmpbuf[4096];
        int bread = m_pPreviewUdpSocket->readDatagram((char *)tmpbuf, 256);

        // 搜索设备是1024，预监回显服务器是256
        int nMaxBreadCount = (1 == BCCommon::g_nPreviewDirectDevice) ? 1024 : 256;
        if((bread>0)&&(bread<nMaxBreadCount))
        {
            unsigned char flagBuf[6];
            if (1 == BCCommon::g_nPreviewDirectDevice) {    // 搜索设备
                flagBuf[0] = 0xec;
                flagBuf[1] = 0x98;
                flagBuf[2] = 0x61;
                flagBuf[3] = 0x20;
                flagBuf[4] = 0x01;
                flagBuf[5] = 0x10;
            } else {                                        // 搜索Vedio Server
                flagBuf[0] = 0xec;
                flagBuf[1] = 0x98;
                flagBuf[2] = 0x61;
                flagBuf[3] = 0x30;
                flagBuf[4] = 0x06;
                flagBuf[5] = 0x10;
            }
            if((tmpbuf[0]==flagBuf[0])&&(tmpbuf[1]==flagBuf[1])&&(tmpbuf[2]==flagBuf[2])&&(tmpbuf[3]==flagBuf[3])&&(tmpbuf[4]==flagBuf[4])&&(bread==flagBuf[5]))
            {
                int C0 = tmpbuf[9];
                C0<<= 8;
                C0 += tmpbuf[10];

                qDebug() << QString("%1.%2.%3.%4").arg(tmpbuf[5]).arg(tmpbuf[6]).arg(tmpbuf[7]).arg(tmpbuf[8]) << C0;
                //m_pMgr->StartPlayerThread(QString("%1.%2.%3.%4").arg(tmpbuf[5]).arg(tmpbuf[6]).arg(tmpbuf[7]).arg(tmpbuf[8]), C0);

                // 发送信号添加到combbox中
                emit sigPreviewIP(QString("%1.%2.%3.%4").arg(tmpbuf[5]).arg(tmpbuf[6]).arg(tmpbuf[7]).arg(tmpbuf[8]), C0);
            }
        }
    }
}

// 使用UDP广播发送信息，MessageType是指头文件中的枚举数据类型
//sendMessage即把本机的主机名，用户名+（消息内容后ip地址）广播出去
void BCSettingCommunicationUdp::onSearchDevice()
{
    unsigned char ssmsg_user_k2[4];
    ssmsg_user_k2[0] = 0xff;
    ssmsg_user_k2[1] = 0x01;
    ssmsg_user_k2[2] = 0x01;
    ssmsg_user_k2[3] = 0x02;

    m_pUdpSocket->writeDatagram((char*)ssmsg_user_k2, 4, QHostAddress::Broadcast, 1500);//将data中的数据发送
}

void BCSettingCommunicationUdp::GetDeviceConfig(int m1, int m2, int m3, int m4, int m5, int m6)
{
    unsigned char	ssmsg_user_k2[22]={0xff,0x13,0x03,0x00,0x71,0x77,0x7c,0x42,0x2f,0x61,0x64,0x6d,0x69,0x6e,0x00,0x61,0x64,0x6d,0x69,0x6e,0x00,0xfd};
    ssmsg_user_k2[3] = (unsigned char)m1;
    ssmsg_user_k2[4] = (unsigned char)m2;
    ssmsg_user_k2[5] = (unsigned char)m3;
    ssmsg_user_k2[6] = (unsigned char)m4;
    ssmsg_user_k2[7] = (unsigned char)m5;
    ssmsg_user_k2[8] = (unsigned char)m6;
    unsigned char B0 = 0;
    for (int i=1;i<21;i++) {
        B0 = B0 + ssmsg_user_k2[i];
    }
    ssmsg_user_k2[21] = B0;

    m_pUdpSocket->writeDatagram((char *)ssmsg_user_k2, 22, QHostAddress::Broadcast, 1500);//将data中的数据发送
}

// 接收UDP信息
void BCSettingCommunicationUdp::processPendingDatagrams()
{
    while(m_pUdpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(m_pUdpSocket->pendingDatagramSize());

        unsigned char tmpbuf[4096];
        int bread = m_pUdpSocket->readDatagram((char *)tmpbuf, 256);

        //qDebug() << tmpbuf[0] << tmpbuf[1] << tmpbuf[2] << bread;
        if ((tmpbuf[0]==0xff)&&(tmpbuf[1]==0x24)&&(tmpbuf[2]==0x01)&&(bread==0x24)) {
            // 9~14为设备的Mac地址，根据这个可以获得设备的信息
            QString qsMac = QString("%1-%2-%3-%4-%5-%6").arg(QString::number(tmpbuf[9], 16)).arg(QString::number(tmpbuf[10], 16)).arg(QString::number(tmpbuf[11], 16))
                    .arg(QString::number(tmpbuf[12], 16)).arg(QString::number(tmpbuf[13], 16)).arg(QString::number(tmpbuf[14], 16));

            //qDebug() << qsMac;
            if ( !m_lstMac.contains(qsMac) )
                GetDeviceConfig((int)tmpbuf[9], (int)tmpbuf[10], (int)tmpbuf[11], (int)tmpbuf[12], (int)tmpbuf[13], (int)tmpbuf[14]);
        } else if((bread==0x82)&&(tmpbuf[0]==0x95)&&(tmpbuf[1]==0x63)&&(tmpbuf[2]==0x03)&&((tmpbuf[3]==0x80)||(tmpbuf[3]==0x00))) {
            QString qsMac = QString("%1-%2-%3-%4-%5-%6").arg(QString::number(tmpbuf[53], 16)).arg(QString::number(tmpbuf[54], 16)).arg(QString::number(tmpbuf[55], 16))
                    .arg(QString::number(tmpbuf[56], 16)).arg(QString::number(tmpbuf[57], 16)).arg(QString::number(tmpbuf[58], 16));

            if ( m_lstMac.contains(qsMac) )
                return;

            // 网关、子网掩码和端口直接copy头儿的代码
            QString qsGateway = QString("%1.%2.%3.%4").arg((int)tmpbuf[0x10]).arg((int)(tmpbuf[0x0f])).arg((int)(tmpbuf[0x0e])).arg((int)(tmpbuf[0x0d]));
            QString qsMask = QString("%1.%2.%3.%4").arg((int)tmpbuf[0x14]).arg((int)(tmpbuf[0x13])).arg((int)(tmpbuf[0x12])).arg((int)(tmpbuf[0x11]));
            unsigned int C0 = tmpbuf[0x50];
            unsigned int C1 =tmpbuf[0x4f];
            C0<<=8;
            C0+=C1;

            int port = C0;

            // ??? ip取9~12位，mac取53~58位，user取21~26位，可能存在BUG
            QString qsIP = QString("%1.%2.%3.%4").arg((int)tmpbuf[12]).arg((int)(tmpbuf[11])).arg((int)(tmpbuf[10])).arg((int)(tmpbuf[9]));
            QString qsUser = QString("%1%2%3%4%5%6").arg(QString(tmpbuf[21])).arg(QString(tmpbuf[22])).arg(QString(tmpbuf[23]))
                    .arg(QString(tmpbuf[24])).arg(QString(tmpbuf[25])).arg(QString(tmpbuf[26]));

            qDebug() << qsIP << "~~~";
            m_lstMac.append( qsMac );
            sigDevice(qsUser, qsIP, port, qsMask, qsGateway, qsMac);
        } else if ((bread==0x04)&&(tmpbuf[0]==0xff)&&(tmpbuf[1]==0x01)&&(tmpbuf[2]==0x06)&&(tmpbuf[3]==0x4b)) {
            BCLocalServer *pServer = BCLocalServer::Application();
            pServer->AddLog( "set device config, step1 ok" );
        } else if ((bread==0x04)&&(tmpbuf[0]==0xff)&&(tmpbuf[1]==0x01)&&(tmpbuf[2]==0x05)&&(tmpbuf[3]==0x4b)) {
            BCLocalServer *pServer = BCLocalServer::Application();
            pServer->AddLog( "set device config, step2 ok" );
        } else if ((bread==0x04)&&(tmpbuf[0]==0xff)&&(tmpbuf[1]==0x01)&&(tmpbuf[2]==0x02)&&(tmpbuf[3]==0x4b)) {
            BCLocalServer *pServer = BCLocalServer::Application();
            pServer->AddLog( "set device config, step3 ok" );
        }
    }
}

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------

BCSettingCommunicationDlg::BCSettingCommunicationDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingCommunicationDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("设备信息"));
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));

#ifdef NOJOINTMATRIX
    ui->m_pJointCheckBox->setVisible( false );
#endif

    // 如果当前级别要是操作员或者用户时不显示修改IP界面
    MainWindow *pMainWindow = BCCommon::Application();
    if (pMainWindow->GetCurrentUser()->level > 1) {
        ui->m_pMoreSetBtn->setVisible( false );
    }

    // 修改网络信息时不显示mac地址
    ui->label_6->setVisible( false );
    ui->m_pSelectedMacLineEdit->setVisible( false );

    init();
}

BCSettingCommunicationDlg::~BCSettingCommunicationDlg()
{
    delete ui;

    if (NULL != m_pSearchDeviceUdp) {
        delete m_pSearchDeviceUdp;
        m_pSearchDeviceUdp = NULL;
    }
}

int BCSettingCommunicationDlg::GetDeviceType()
{
    return ui->m_pDeviceType->currentIndex();
}

void BCSettingCommunicationDlg::init()
{
    m_pSearchDeviceUdp = NULL;

    // -------------------------------------------------------------------------------------------------- 无论是否通讯都要进行初始化的 begin
    // 不显示高级设置
    ui->m_pMoreSetGroupBox->setVisible( false );

    // 设置设备链表表头
    QStringList lstHeaders;
    lstHeaders << tr("名称") << tr("IP") << tr("端口") << tr("子网掩码") << tr("网关地址") << tr("MAC地址");
    ui->m_pDeviceTableWidget->setColumnCount( 6 );
    ui->m_pDeviceTableWidget->setHorizontalHeaderLabels( lstHeaders );
    ui->m_pDeviceTableWidget->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位

    connect(ui->m_pDeviceTableWidget, SIGNAL(currentCellChanged(int,int,int,int)), this, SLOT(onCurrentRowChanged(int,int,int,int)));
    // -------------------------------------------------------------------------------------------------- end

    // -------------------------------------------------------------------------------------------------- 本地服务器获取数据，没有数据时直接返回
    // 获得设备通讯参数
    BCLocalServer *pServer = BCLocalServer::Application();

    // 初始化Net连接参数
    bool bConnectWithNet = pServer->m_bIsNetConnect;
    ui->m_pUseNetConnectRadioBtn->setChecked( bConnectWithNet );
    ui->m_pUseComConnectRadioBtn->setChecked( !bConnectWithNet );

    // 如果是NET连接，设置COM连接参数不可用
    if ( bConnectWithNet ) {
        on_m_pUseNetConnectRadioBtn_clicked();
    } else {
        on_m_pUseComConnectRadioBtn_clicked();
    }

    // 初始化COM连接参数
    QList<QSerialPortInfo> lstSerialPort = QSerialPortInfo::availablePorts();
    for (int i = 0; i < lstSerialPort.count(); i++) {
        QSerialPortInfo info = lstSerialPort.at( i );
        ui->m_pComComBox->addItem( info.portName() );
    }

    // 其他参数
    ui->m_pComComBox->setCurrentText( pServer->m_qsCurrentCom );
    ui->m_pBaudRateComBox->setCurrentText(QString::number(pServer->m_nCurrentBaudRate));
    ui->m_pDataBitComBox->setCurrentText(QString::number(pServer->m_nCurrentDataBit));
    ui->m_pStopBitComBox->setCurrentText(QString::number(pServer->m_nCurrentStopBit));
    ui->m_pCheckBitComBox->setCurrentText( pServer->m_qsCurrentCheckBit );
    ui->m_pStreamCtrlComBox->setCurrentText( pServer->m_qsCurrentStreamCtrl );

    // 先给网络连接赋值，如果搜索到设备则进行替换
    ui->m_pNetIPLineEdit->setText( pServer->m_qsConnectIPWithoutDLL );
    ui->m_pNetPortLineEdit->setText( pServer->m_qsConnectPortWithoutDLL );

    // 初始化当前选择设备
    //if (0 != BCCommon::g_nDeviceType) {
        on_m_pSearchDeviceBtn_clicked();
    //}

    // 初始化设备类型
    ui->m_pDeviceType->setItemText(0, BCCommon::g_qsDeviceType2000);
    ui->m_pDeviceType->setItemText(1, BCCommon::g_qsDeviceType2000A);
    ui->m_pDeviceType->setItemText(2, BCCommon::g_qsDeviceType4000);
    ui->m_pDeviceType->setItemText(3, BCCommon::g_qsDeviceTypeMatrix);
    ui->m_pDeviceType->setCurrentIndex( BCCommon::g_nDeviceType );                          // 根据xml内容修改设备类型
    ui->m_pJointCheckBox->setChecked((0 == BCCommon::g_nIsContainsMatrix) ? true : false);  // 初始化是否联控
    ui->m_pJointCheckBox->setEnabled((3 != BCCommon::g_nDeviceType) ? true : false);           // 矩阵界面时不需要联控
    on_m_pDeviceType_currentIndexChanged( BCCommon::g_nDeviceType );    // 强制执行，否则当index没有改变时不会进入
}

void BCSettingCommunicationDlg::on_m_pUseNetConnectRadioBtn_clicked()
{
    ui->m_pComComBox->setEnabled(false);
    ui->m_pBaudRateComBox->setEnabled(false);
    ui->m_pDataBitComBox->setEnabled(false);
    ui->m_pStopBitComBox->setEnabled(false);
    ui->m_pCheckBitComBox->setEnabled(false);
    ui->m_pStreamCtrlComBox->setEnabled(false);

    ui->m_pNetIPLineEdit->setEnabled(true);
    ui->m_pNetPortLineEdit->setEnabled(true);

    ui->groupBox_2->setEnabled(true);
}

void BCSettingCommunicationDlg::on_m_pUseComConnectRadioBtn_clicked()
{
    ui->m_pComComBox->setEnabled(true);
    ui->m_pBaudRateComBox->setEnabled(true);
    ui->m_pDataBitComBox->setEnabled(true);
    ui->m_pStopBitComBox->setEnabled(true);
    ui->m_pCheckBitComBox->setEnabled(true);
    ui->m_pStreamCtrlComBox->setEnabled(true);

    ui->m_pNetIPLineEdit->setEnabled(false);
    ui->m_pNetPortLineEdit->setEnabled(false);

    ui->groupBox_2->setEnabled(false);
}

void BCSettingCommunicationDlg::on_m_pMoreSetBtn_clicked()
{
    ui->m_pMoreSetBtn->setText( ui->m_pMoreSetGroupBox->isVisible() ? tr("网络设置 >>") : tr("网络设置 <<"));
    ui->m_pMoreSetGroupBox->setVisible( !ui->m_pMoreSetGroupBox->isVisible() );
}

void BCSettingCommunicationDlg::on_m_pSearchDeviceBtn_clicked()
{
    // 搜索设备应该分为网口和串口两种
    BCLocalServer *pServer = BCLocalServer::Application();

    // 直接清除表头，需要重新设置
    ui->m_pDeviceTableWidget->clear();
    ui->m_pDeviceTableWidget->setRowCount( 0 );
    QStringList lstHeaders;
    lstHeaders << tr("名称") << tr("IP") << tr("端口") << tr("子网掩码") << tr("网关地址") << tr("MAC地址");
    ui->m_pDeviceTableWidget->setHorizontalHeaderLabels( lstHeaders );

    if (NULL == m_pSearchDeviceUdp) {
        m_pSearchDeviceUdp = new BCSettingCommunicationUdp( this );
        connect(m_pSearchDeviceUdp, SIGNAL(sigDevice(QString,QString,int,QString,QString,QString)), this, SLOT(onAddDevice(QString,QString,int,QString,QString,QString)));
        connect(m_pSearchDeviceUdp, SIGNAL(sigPreviewIP(QString, int)), this, SLOT(onAddPrevewDevice(QString, int)));
    }
    m_pSearchDeviceUdp->m_lstMac.clear();
}

void BCSettingCommunicationDlg::onAddPrevewDevice(const QString &ip, int port)
{
    if (0 == ui->m_pDeviceType->currentIndex())
        return;

    // 如果不包含预监IP则添加到下拉链表中
    if (-1 == ui->m_pPreviewComboBox->findText( ip )) {
        ui->m_pPreviewComboBox->addItem( ip );
    }

    // 加到map中记录
    if ( !mapPreviewIPPort.contains(ip) ) {
        mapPreviewIPPort.insert(ip, port);
    }
}

void BCSettingCommunicationDlg::on_m_pDeviceType_currentIndexChanged(int index)
{
    // 设备类型改变，2000时需要清空链表，并停止UDP，其他情况需要打开UDP
    if (0 == index) {   // vp2000
        m_pSearchDeviceUdp->m_pTimer->stop();
        ui->m_pPreviewComboBox->setEnabled( false );
        ui->m_pPreviewComboBox->clear();

        ui->m_pDeviceTableWidget->clear();
        ui->m_pDeviceTableWidget->setRowCount( 0 );
        QStringList lstHeaders;
        lstHeaders << tr("名称") << tr("IP") << tr("端口") << tr("子网掩码") << tr("网关地址") << tr("MAC地址");
        ui->m_pDeviceTableWidget->setHorizontalHeaderLabels( lstHeaders );

        ui->m_pJointCheckBox->setEnabled( true );
    } else if (1 == index) { // vp2000a
        // 2000 不支持回显，不支持复制
        ui->m_pPreviewComboBox->setEnabled( false );
        ui->m_pPreviewComboBox->clear();

        m_pSearchDeviceUdp->m_pTimer->start();

        on_m_pSearchDeviceBtn_clicked();

        ui->m_pJointCheckBox->setEnabled( true );
    } else if (2 == index) {    // vp4000
        ui->m_pPreviewComboBox->setEnabled( true );
        m_pSearchDeviceUdp->m_pTimer->start();

        on_m_pSearchDeviceBtn_clicked();

        ui->m_pJointCheckBox->setEnabled( true );
    } else if (3 == index) {   // matrix
        m_pSearchDeviceUdp->m_pTimer->stop();
        ui->m_pPreviewComboBox->setEnabled( false );
        ui->m_pPreviewComboBox->clear();

        ui->m_pDeviceTableWidget->clear();
        ui->m_pDeviceTableWidget->setRowCount( 0 );
        QStringList lstHeaders;
        lstHeaders << tr("名称") << tr("IP") << tr("端口") << tr("子网掩码") << tr("网关地址") << tr("MAC地址");
        ui->m_pDeviceTableWidget->setHorizontalHeaderLabels( lstHeaders );

        ui->m_pJointCheckBox->setEnabled( false );
    }
}

void BCSettingCommunicationDlg::onAddDevice(const QString &name, const QString &ip, int port, const QString &mask, const QString &gateway, const QString &mac)
{
    if (0 == ui->m_pDeviceType->currentIndex())
        return;

    int nRowCount = ui->m_pDeviceTableWidget->rowCount();

    ui->m_pDeviceTableWidget->setRowCount( nRowCount+1 );

    QTableWidgetItem *pItem = new QTableWidgetItem( name );
    pItem->setFlags( pItem->flags() & (~Qt::ItemIsEditable));   // 不可编辑
    ui->m_pDeviceTableWidget->setItem(nRowCount, 0, pItem);

    pItem = new QTableWidgetItem( ip );
    pItem->setFlags( pItem->flags() & (~Qt::ItemIsEditable));   // 不可编辑
    ui->m_pDeviceTableWidget->setItem(nRowCount, 1, pItem);

    pItem = new QTableWidgetItem(QString::number( port ));
    pItem->setFlags( pItem->flags() & (~Qt::ItemIsEditable));   // 不可编辑
    ui->m_pDeviceTableWidget->setItem(nRowCount, 2, pItem);

    pItem = new QTableWidgetItem( mask );
    pItem->setFlags( pItem->flags() & (~Qt::ItemIsEditable));   // 不可编辑
    ui->m_pDeviceTableWidget->setItem(nRowCount, 3, pItem);

    pItem = new QTableWidgetItem( gateway );
    pItem->setFlags( pItem->flags() & (~Qt::ItemIsEditable));   // 不可编辑
    ui->m_pDeviceTableWidget->setItem(nRowCount, 4, pItem);

    pItem = new QTableWidgetItem( mac );
    pItem->setFlags( pItem->flags() & (~Qt::ItemIsEditable));   // 不可编辑
    ui->m_pDeviceTableWidget->setItem(nRowCount, 5, pItem);

    // 插入到ip mac对应关系表里
    if ( !mapIPMac.contains(ip) )
        mapIPMac.insert(ip, mac);
}

void BCSettingCommunicationDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingCommunicationDlg::on_m_pOkBtn_clicked()
{
    if ( ui->m_pUseNetConnectRadioBtn->isChecked() ) {
        if (ui->m_pNetIPLineEdit->text().isEmpty()) {
            QMessageBox::warning(this,
                                 tr("警告"),
                                 tr("网络连接时IP不可为空!"),
                                 QMessageBox::Ok);
            return;
        }
    }

    // 设备类型改变，2000时需要清空链表，并停止UDP，其他情况需要打开UDP
    BCCommon::g_nDeviceType = ui->m_pDeviceType->currentIndex();
    if (0 == BCCommon::g_nDeviceType) {   // vp2000
        // 2000 不支持回显，不支持复制
        BCCommon::g_bEchoModel = false;
        BCCommon::g_nIsContainsMatrix = ui->m_pJointCheckBox->isChecked() ? 0 : -1;
    } else if (1 == BCCommon::g_nDeviceType) { // vp2000a
        // 2000 不支持回显，不支持复制
        BCCommon::g_bEchoModel = false;
        BCCommon::g_nIsContainsMatrix = ui->m_pJointCheckBox->isChecked() ? 0 : -1;
    } else if (2 == BCCommon::g_nDeviceType) {    // vp4000
        // 2000A, 4000 支持回显，支持复制
        BCCommon::g_bEchoModel = true;
        BCCommon::g_nIsContainsMatrix = ui->m_pJointCheckBox->isChecked() ? 0 : -1;
    } else if (3 == BCCommon::g_nDeviceType) { // matrix
        // matrix 不支持回显，不支持复制
        BCCommon::g_bEchoModel = false;
        BCCommon::g_nIsContainsMatrix = 1;
    }

    // 将设备类型写入文件
    QFile file( QString("../xml/BCGenaralConfig.xml") );
    if (file.open(QIODevice::ReadOnly)) {
        // 将文件内容读到QDomDocument中
        QDomDocument doc;
        bool bLoadFile = doc.setContent(&file);
        file.close();

        if ( bLoadFile ) {
            // 二级链表
            QDomElement docElem = doc.documentElement();
            docElem.setAttribute("DeviceType", BCCommon::g_nDeviceType);
            //docElem.setAttribute("IsContainsMatrix", BCCommon::g_nIsContainsMatrix);
            docElem.setAttribute("EchoModel", BCCommon::g_bEchoModel ? 1 : 0);

            // 写入文件
            if ( file.open(QIODevice::WriteOnly | QIODevice::Truncate) ) {
                QTextStream out(&file);
                doc.save(out,4);
                file.close();
            }
        }
    }

    // 记录参数
    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->m_bIsNetConnect = ui->m_pUseNetConnectRadioBtn->isChecked();
    pServer->m_qsCurrentCom = ui->m_pComComBox->currentText();
    pServer->m_nCurrentBaudRate = ui->m_pBaudRateComBox->currentText().toInt();
    pServer->m_nCurrentDataBit = ui->m_pDataBitComBox->currentText().toInt();
    pServer->m_nCurrentStopBit = ui->m_pStopBitComBox->currentText().toInt();
    pServer->m_qsCurrentCheckBit = ui->m_pCheckBitComBox->currentText();
    pServer->m_qsCurrentStreamCtrl = ui->m_pStreamCtrlComBox->currentText();
    pServer->m_qsConnectIPWithoutDLL = ui->m_pNetIPLineEdit->text();
    pServer->m_qsConnectMacWithoutDLL = mapIPMac.value( ui->m_pNetIPLineEdit->text() );
    pServer->m_qsConnectPortWithoutDLL = ui->m_pNetPortLineEdit->text();
    pServer->m_nIsDemoMode = 2;
    pServer->SetCommunicationPara();
    pServer->DisConnect();

    // 记录当前回显IP
    BCCommon::g_qsPreviewIP = ui->m_pPreviewComboBox->currentText();
    BCCommon::g_bEchoModel = !BCCommon::g_qsPreviewIP.isEmpty();
    BCCommon::g_nPreviewPort = mapPreviewIPPort.value(BCCommon::g_qsPreviewIP, 8206);

    this->accept();

    // 重新加载
    if (BCCommon::g_nIsContainsMatrix == 1) {
        MainWindow *pApplication = BCCommon::Application();
        pApplication->RefreshMainWindow();
    } else {
        BCSettingWaitingDlg *waitingDlg = new BCSettingWaitingDlg();
        waitingDlg->show();
    }
}

void BCSettingCommunicationDlg::on_m_pDemoModeBtn_clicked()
{
    // 记录参数
    BCCommon::g_nDeviceType = ui->m_pDeviceType->currentIndex();
    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->m_nIsDemoMode = 0;

    // 记录当前回显IP
    BCCommon::g_qsPreviewIP = "";
    BCCommon::g_bEchoModel = false;

    this->accept();

    BCSettingWaitingDlg *waitingDlg = new BCSettingWaitingDlg();
    waitingDlg->show();
}

void BCSettingCommunicationDlg::onCurrentRowChanged(int cr, int, int pr, int)
{
    // 当前行变化时继续操作
    if (cr == pr)
        return;

    // 当前行如果不合法则返回
    if ((cr < 0) || (cr >= ui->m_pDeviceTableWidget->rowCount())) {
        ui->m_pSelectedNameLineEdit->setText( QString::null );
        ui->m_pSelectedIPLineEdit->setText( QString::null );
        ui->m_pSelectedPortLineEdit->setText( QString::null );
        ui->m_pSelectedMaskLineEdit->setText( QString::null );
        ui->m_pSelectedGatewayLineEdit->setText( QString::null );
        ui->m_pSelectedMacLineEdit->setText( QString::null );

        ui->m_pNetIPLineEdit->setText( QString::null );
        ui->m_pNetPortLineEdit->setText( QString::null );
        return;
    }

    QString qsName = ui->m_pDeviceTableWidget->item(cr, 0)->text();
    QString qsIP = ui->m_pDeviceTableWidget->item(cr, 1)->text();
    QString qsPort = ui->m_pDeviceTableWidget->item(cr, 2)->text();
    QString qsMask = ui->m_pDeviceTableWidget->item(cr, 3)->text();
    QString qsGateway = ui->m_pDeviceTableWidget->item(cr, 4)->text();
    QString qsMac = ui->m_pDeviceTableWidget->item(cr, 5)->text();

    ui->m_pSelectedNameLineEdit->setText( qsName );
    ui->m_pSelectedIPLineEdit->setText( qsIP );
    ui->m_pSelectedPortLineEdit->setText( qsPort );
    ui->m_pSelectedMaskLineEdit->setText( qsMask );
    ui->m_pSelectedGatewayLineEdit->setText( qsGateway );
    ui->m_pSelectedMacLineEdit->setText( qsMac );

    ui->m_pNetIPLineEdit->setText( qsIP );
    ui->m_pNetPortLineEdit->setText( qsPort );
}

void BCSettingCommunicationDlg::on_m_pModifyDeviceConfigBtn_clicked()
{
    BCLocalServer *pServer = BCLocalServer::Application();

    // 取修改的数据
    QString qsName = ui->m_pSelectedNameLineEdit->text();
    QString qsIP = ui->m_pSelectedIPLineEdit->text();
    QString qsPort = ui->m_pSelectedPortLineEdit->text();
    QString qsMask = ui->m_pSelectedMaskLineEdit->text();
    QString qsGateway = ui->m_pSelectedGatewayLineEdit->text();
    QString qsMac = ui->m_pSelectedMacLineEdit->text();

    // 检查格式
    if (qsName.length() > 6) {
        QMessageBox::warning(this,
                             tr("警告"),
                             tr("名字长度应小于6位，请检查!"),
                             QMessageBox::Ok);
        return;
    }

    QStringList lstSplitIP = qsIP.split(".");
    if (4 != lstSplitIP.count()) {
        QMessageBox::warning(this,
                             tr("警告"),
                             tr("IP格式不正确，请检查!"),
                             QMessageBox::Ok);
        return;
    }

    QStringList lstSplitMask = qsMask.split(".");
    if (4 != lstSplitMask.count()) {
        QMessageBox::warning(this,
                             tr("警告"),
                             tr("子网掩码格式不正确，请检查!"),
                             QMessageBox::Ok);
        return;
    }

    QStringList lstSplitGateway = qsGateway.split(".");
    if (4 != lstSplitGateway.count()) {
        QMessageBox::warning(this,
                             tr("警告"),
                             tr("网关格式不正确，请检查!"),
                             QMessageBox::Ok);
        return;
    }

    QStringList lstSplitMac = qsMac.split("-");
    if (6 != lstSplitMac.count()) {
        QMessageBox::warning(this,
                             tr("警告"),
                             tr("Mac地址格式不正确，请检查!"),
                             QMessageBox::Ok);
        return;
    }

    // 修改表格
    int cr = ui->m_pDeviceTableWidget->currentRow();
    if (cr < ui->m_pDeviceTableWidget->rowCount()) {
        ui->m_pDeviceTableWidget->item(cr, 0)->setText( qsName );
        ui->m_pDeviceTableWidget->item(cr, 1)->setText( qsIP );
        ui->m_pDeviceTableWidget->item(cr, 2)->setText( qsPort );
        ui->m_pDeviceTableWidget->item(cr, 3)->setText( qsMask );
        ui->m_pDeviceTableWidget->item(cr, 4)->setText( qsGateway );
        ui->m_pDeviceTableWidget->item(cr, 5)->setText( qsMac );

        ui->m_pNetIPLineEdit->setText( qsIP );
        ui->m_pNetPortLineEdit->setText( qsPort );
    }

    // 给DLL传数据
    BSDevice *pDevice = new BSDevice;
    pDevice->selectFlag = 1;
    pDevice->pNext = NULL;

    for (int i = 0; i < 6; i++) {
        if (i < qsName.length())
            pDevice->name[i] = qsName.toLatin1().data()[i];
    }

    for (int i = 0; i < 4; i++) {
        pDevice->ip[i] = (char)lstSplitIP.at(i).toInt();
        pDevice->mask[i] = (char)lstSplitMask.at(i).toInt();
        pDevice->gateway[i] = (char)lstSplitGateway.at(i).toInt();
    }
    for (int i = 0; i < 6; i++) {
        pDevice->mac[i] = lstSplitMac.at(i).toInt(NULL, 16);
    }

    pDevice->port = qsPort.toInt();

    // 修改配置
    if ( pServer->m_bIsNetConnect ) {
        m_pSearchDeviceUdp->ModifyDeviceConfig(pDevice, 0);
        QThread::msleep(100);
        m_pSearchDeviceUdp->ModifyDeviceConfig(pDevice, 1);
        QThread::msleep(100);
        m_pSearchDeviceUdp->ModifyDeviceConfig(pDevice, 2);
    } else {
        // ??? 串口通讯
    }

    // 清空内存
    delete pDevice;
    pDevice = NULL;
}

QString BCSettingCommunicationDlg::getcomm(int index, QString keyorvalue)
{
    QString commresult;

    HKEY hKey;
    //LPCWSTR subkey;
    wchar_t keyname[256]; //键名数组
    char keyvalue[256];  //键值数组
    DWORD keysize,type,valuesize;
    int indexnum;

    if (::RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("HARDWARE\\DEVICEMAP\\SERIALCOMM"), 0, KEY_READ, &hKey) != 0) {
        QString error="Cannot open regedit!";//无法打开注册表时返回error
        return error;
    }//if(::RegOpenKeyEx(HKEY_LOCAL_MACHINE,subkey,0,KEY_READ,&hKey)!=0)

    QString keymessage;//键名
    QString message;
    QString valuemessage;//键值

    indexnum = index;//要读取键值的索引号
    keysize = sizeof(keyname);
    valuesize = sizeof(keyvalue);

    if (RegEnumValue(hKey, indexnum, keyname, &keysize, 0, &type, (BYTE*)keyvalue, &valuesize) == 0) { //列举键名和值
        for (int i=0; i<(int)keysize; i++) {
            message = keyname[i];
            keymessage.append(message);
        }

        for (int j=0; j<(int)valuesize; j++) {
             if (keyvalue[j] != 0x00) {
                 valuemessage.append(keyvalue[j]);
             }
        }

        if (keyorvalue == "key") {
             commresult = keymessage;
        }

        if (keyorvalue == "value") {
             commresult=valuemessage;
        }
    } else {
         commresult = "nokey";
    }

    RegCloseKey(hKey);//关闭注册表

    return commresult;
}
