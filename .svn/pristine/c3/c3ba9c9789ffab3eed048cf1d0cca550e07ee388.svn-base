#include "BCSettingOtherDeviceControlDlg.h"
#include "ui_BCSettingOtherDeviceControlDlg.h"
#include <QTcpSocket>
#include <QHostAddress>
#include <QMouseEvent>
#include "../Common/BCLocalServer.h"


// 屏幕开
//cmd.append(QChar(0xFF));
//cmd.append(QChar(0x55));
//cmd.append(QChar(0x02));
//cmd.append(QChar(0xD5));
//cmd.append(QChar(0x11));
//cmd.append(QChar(0x53));
//cmd.append(QChar(0x10));
//cmd.append(QChar(0x01));
//cmd.append(QChar(0xAA));
//cmd.append(QChar(0xFA));
// 屏幕关
//cmd.append(QChar(0xFF));
//cmd.append(QChar(0x55));
//cmd.append(QChar(0x02));
//cmd.append(QChar(0xD5));
//cmd.append(QChar(0x11));
//cmd.append(QChar(0x53));
//cmd.append(QChar(0x10));
//cmd.append(QChar(0x00));
//cmd.append(QChar(0xAA));
//cmd.append(QChar(0xFA));

QString qsUnClickBtnStyle =
QString("QPushButton {"
    "background-color: rgb(229, 235, 235);"
    "border-width: 2px;"
    "border-color: rgb(229, 235, 235);"
    "border-style: solid;"
    "border-radius: 0;"
    "padding: 3px;"
    "min-width: 9ex;"
    "min-height: 2.5ex;}"
"QPushButton:hover {"
    "background-color: rgb(232, 72, 61);"
    "border-color: rgb(232, 72, 61);"
    "color: rgb(255, 255, 255);}"
"QPushButton:pressed {"
    "padding-left: 5px;"
    "padding-top: 5px;"
    "background-color: rgb(232, 72, 61);}");

QString qsClickBtnStyle =
QString("QPushButton {"
    "background-color: rgb(232, 72, 61);"
    "border-width: 2px;"
    "border-color: rgb(232, 72, 61);"
    "border-style: solid;"
    "border-radius: 0;"
    "padding: 3px;"
    "min-width: 9ex;"
    "min-height: 2.5ex;}"
    "color: rgb(255, 255, 255);"
"QPushButton:hover {"
    "background-color: rgb(232, 72, 61);"
    "border-color: rgb(232, 72, 61);"
    "color: rgb(255, 255, 255);}"
"QPushButton:pressed {"
    "padding-left: 5px;"
    "padding-top: 5px;"
    "background-color: rgb(232, 72, 61);}");

BCVedioBtn::BCVedioBtn(QWidget *parent)
    :QPushButton(parent)
{
    m_pTcpSocket = NULL;
    this->setStyleSheet( QString("border-image: url(:/image/otherdevice/vediosource.png);") );
}

void BCVedioBtn::mousePressEvent(QMouseEvent *e)
{
    QPoint pt = e->pos();
    qDebug() << e->pos();

    // 上
    QString cmd;
    if ((pt.y() > 15) && (pt.y() < 15+50)
            && (pt.x() > 25) && (pt.x() < 145)) {
        this->setStyleSheet( QString("border-image: url(:/image/otherdevice/vediotop.png);") );
        cmd.append(QChar(0xFF));
        cmd.append(QChar(0x55));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0x23));
        cmd.append(QChar(0x54));
        cmd.append(QChar(0x39));
        cmd.append(QChar(0x30));
        cmd.append(QChar(0x0D));
        cmd.append(QChar(0xFA));
    }

    // 下
    if ((pt.y() > 210-15-50) && (pt.y() < 210-15)
            && (pt.x() > 25) && (pt.x() < 145)) {
        this->setStyleSheet( QString("border-image: url(:/image/otherdevice/vediodown.png);") );
        cmd.append(QChar(0xFF));
        cmd.append(QChar(0x55));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0x23));
        cmd.append(QChar(0x54));
        cmd.append(QChar(0x32));
        cmd.append(QChar(0x30));
        cmd.append(QChar(0x0D));
        cmd.append(QChar(0xFA));
    }

    // 左
    if ((pt.x() > 15) && (pt.x() < 15+50)
            && (pt.y() > 65) && (pt.y() < 65+80)) {
        this->setStyleSheet( QString("border-image: url(:/image/otherdevice/vedioleft.png);") );

        // 摄像头 左
        cmd.append(QChar(0xFF));
        cmd.append(QChar(0x55));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0x23));
        cmd.append(QChar(0x50));
        cmd.append(QChar(0x39));
        cmd.append(QChar(0x30));
        cmd.append(QChar(0x0D));
        cmd.append(QChar(0xFA));
    }

    // 右
    if ((pt.x() > 210-15-50) && (pt.x() < 210-15)
            && (pt.y() > 65) && (pt.y() < 65+80)) {
        this->setStyleSheet( QString("border-image: url(:/image/otherdevice/vedioright.png);") );
        cmd.append(QChar(0xFF));
        cmd.append(QChar(0x55));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0x23));
        cmd.append(QChar(0x50));
        cmd.append(QChar(0x32));
        cmd.append(QChar(0x30));
        cmd.append(QChar(0x0D));
        cmd.append(QChar(0xFA));
    }

    m_pTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCVedioBtn::mouseReleaseEvent(QMouseEvent *)
{
    this->setStyleSheet( QString("border-image: url(:/image/otherdevice/vediosource.png);") );

    // 摄像头 左右停
    QString cmd;
    cmd.append(QChar(0xFF));
    cmd.append(QChar(0x55));
    cmd.append(QChar(0x04));
    cmd.append(QChar(0x23));
    cmd.append(QChar(0x50));
    cmd.append(QChar(0x35));
    cmd.append(QChar(0x30));
    cmd.append(QChar(0x0D));
    cmd.append(QChar(0xFA));

    m_pTcpSocket->write(cmd.toLatin1(), cmd.length());

    // 摄像头 上下停
    cmd = QString::null;
    cmd.append(QChar(0xFF));
    cmd.append(QChar(0x55));
    cmd.append(QChar(0x04));
    cmd.append(QChar(0x23));
    cmd.append(QChar(0x54));
    cmd.append(QChar(0x35));
    cmd.append(QChar(0x30));
    cmd.append(QChar(0x0D));
    cmd.append(QChar(0xFA));

    m_pTcpSocket->write(cmd.toLatin1(), cmd.length());
}

// ---------------------------------------------------------------------

BCSettingOtherDeviceControlDlg::BCSettingOtherDeviceControlDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingOtherDeviceControlDlg)
{
    ui->setupUi(this);

    m_nType = -1;
    m_bPower = true;
    m_pTcpSocket = new QTcpSocket();
    connect(m_pTcpSocket, SIGNAL(disconnected()), this, SLOT(onReconnect()));

    BCLocalServer *pServer = BCLocalServer::Application();
    if (0 != pServer->m_nIsDemoMode) {
        m_pTcpSocket->connectToHost(QHostAddress("192.168.1.7"), 8000);
        m_pTcpSocket->waitForConnected( 50 );
    }

    ui->m_pVedioBtn->SetTcpSocket( m_pTcpSocket );

    on_m_pRoom1Btn_clicked();
    on_m_pMainVedioBtn_clicked();
}

BCSettingOtherDeviceControlDlg::~BCSettingOtherDeviceControlDlg()
{
    delete ui;
}

void BCSettingOtherDeviceControlDlg::onReconnect()
{
    m_pTcpSocket->connectToHost(QHostAddress("192.168.1.7"), 8000);
    m_pTcpSocket->waitForConnected( 50 );
}

void BCSettingOtherDeviceControlDlg::on_m_pMainVedioBtn_clicked()
{
    m_nType = -1;
    ui->m_pDisplayWidget->setVisible( false );
    ui->m_pAudioWidget1->setVisible( false );
    ui->m_pAudioWidget2->setVisible( false );
    ui->m_pAudioWidget3->setVisible( false );
    ui->m_pAudioWidget4->setVisible( false );
    ui->m_pVedioWidget->setVisible( true );
    ui->m_pPowerWidget->setVisible( false );
    ui->m_pLightWidget->setVisible( false );
    ui->m_pContainWidget->setVisible( false );
    ui->m_pTVWidget->setVisible( false );
}

void BCSettingOtherDeviceControlDlg::on_m_pDisplayMainBtn_clicked()
{
    m_nType = 1;
    ui->m_pDisplayWidget->setVisible( true );
    ui->m_pAudioWidget1->setVisible( false );
    ui->m_pAudioWidget2->setVisible( false );
    ui->m_pAudioWidget3->setVisible( false );
    ui->m_pAudioWidget4->setVisible( false );
    ui->m_pVedioWidget->setVisible( false );
    ui->m_pPowerWidget->setVisible( true );
    ui->m_pLightWidget->setVisible( false );
    ui->m_pContainWidget->setVisible( false );
    ui->m_pTVWidget->setVisible( false );

    m_bPower = !m_bPower;
    on_m_pPowerBtn_clicked();
}

void BCSettingOtherDeviceControlDlg::on_m_pMainAudioBtn_clicked()
{
    m_nType = -1;
    ui->m_pDisplayWidget->setVisible( false );
    ui->m_pAudioWidget1->setVisible( true );
    ui->m_pAudioWidget2->setVisible( true );
    ui->m_pAudioWidget3->setVisible( true );
    ui->m_pAudioWidget4->setVisible( true );
    ui->m_pVedioWidget->setVisible( false );
    ui->m_pPowerWidget->setVisible( false );
    ui->m_pLightWidget->setVisible( false );
    ui->m_pContainWidget->setVisible( false );
    ui->m_pTVWidget->setVisible( false );
}

void BCSettingOtherDeviceControlDlg::on_m_pMainLightBtn_clicked()
{
    m_nType = -1;
    ui->m_pDisplayWidget->setVisible( false );
    ui->m_pAudioWidget1->setVisible( false );
    ui->m_pAudioWidget2->setVisible( false );
    ui->m_pAudioWidget3->setVisible( false );
    ui->m_pAudioWidget4->setVisible( false );
    ui->m_pVedioWidget->setVisible( false );
    ui->m_pPowerWidget->setVisible( false );
    ui->m_pLightWidget->setVisible( true );
    ui->m_pContainWidget->setVisible( false );
    ui->m_pTVWidget->setVisible( false );
}

void BCSettingOtherDeviceControlDlg::on_m_pMainTVBtn_clicked()
{
    m_nType = -1;
    ui->m_pDisplayWidget->setVisible( false );
    ui->m_pAudioWidget1->setVisible( false );
    ui->m_pAudioWidget2->setVisible( false );
    ui->m_pAudioWidget3->setVisible( false );
    ui->m_pAudioWidget4->setVisible( false );
    ui->m_pVedioWidget->setVisible( false );
    ui->m_pPowerWidget->setVisible( false );
    ui->m_pLightWidget->setVisible( false );
    ui->m_pContainWidget->setVisible( false );
    ui->m_pTVWidget->setVisible( true );
}

void BCSettingOtherDeviceControlDlg::on_m_pMainCurtainBtn_clicked()
{
    m_nType = -1;
    ui->m_pDisplayWidget->setVisible( false );
    ui->m_pAudioWidget1->setVisible( false );
    ui->m_pAudioWidget2->setVisible( false );
    ui->m_pAudioWidget3->setVisible( false );
    ui->m_pAudioWidget4->setVisible( false );
    ui->m_pVedioWidget->setVisible( false );
    ui->m_pPowerWidget->setVisible( false );
    ui->m_pLightWidget->setVisible( false );
    ui->m_pContainWidget->setVisible( true );
    ui->m_pTVWidget->setVisible( false );
}

void BCSettingOtherDeviceControlDlg::on_m_pPowerBtn_clicked()
{
    m_bPower = !m_bPower;
    ui->m_pPowerBtn->setStyleSheet(QString("border-image: url(:/image/otherdevice/%1.png);").arg(m_bPower ? "poweron" : "poweroff"));
}

void BCSettingOtherDeviceControlDlg::on_m_pDisplayHDMIBtn_clicked()
{
    // 模式 HDMI
    QString cmd;
    cmd.append(QChar(0xFF));
    cmd.append(QChar(0x55));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0xD5));
    cmd.append(QChar(0x11));
    cmd.append(QChar(0x11));
    cmd.append(QChar(0x20));
    cmd.append(QChar(0x04));
    cmd.append(QChar(0xAA));
    cmd.append(QChar(0xFA));

    m_pTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCSettingOtherDeviceControlDlg::on_m_pDisplayDVIBtn_clicked()
{
    // 模式 DVI
    QString cmd;
    cmd.append(QChar(0xFF));
    cmd.append(QChar(0x55));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0xD5));
    cmd.append(QChar(0x11));
    cmd.append(QChar(0x11));
    cmd.append(QChar(0x20));
    cmd.append(QChar(0x05));
    cmd.append(QChar(0xAA));
    cmd.append(QChar(0xFA));

    m_pTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCSettingOtherDeviceControlDlg::on_m_pDisplayVideo1Btn_clicked()
{
    // 模式 VEDIO1
    QString cmd;
    cmd.append(QChar(0xFF));
    cmd.append(QChar(0x55));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0xD5));
    cmd.append(QChar(0x11));
    cmd.append(QChar(0x11));
    cmd.append(QChar(0x20));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0xAA));
    cmd.append(QChar(0xFA));

    m_pTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCSettingOtherDeviceControlDlg::on_m_pdisplayVIDEO2Btn_clicked()
{
    // 模式 VEDIO2
    QString cmd;
    cmd.append(QChar(0xFF));
    cmd.append(QChar(0x55));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0xD5));
    cmd.append(QChar(0x11));
    cmd.append(QChar(0x11));
    cmd.append(QChar(0x20));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0xAA));
    cmd.append(QChar(0xFA));

    m_pTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCSettingOtherDeviceControlDlg::on_m_pDisplayVGABtn_clicked()
{
    // 模式 VGA
    QString cmd;
    cmd.append(QChar(0xFF));
    cmd.append(QChar(0x55));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0xD5));
    cmd.append(QChar(0x11));
    cmd.append(QChar(0x11));
    cmd.append(QChar(0x20));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0xAA));
    cmd.append(QChar(0xFA));

    m_pTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCSettingOtherDeviceControlDlg::on_m_pRoom1Btn_clicked()
{
    ui->m_pRoom1Btn->setStyleSheet( qsClickBtnStyle );
    ui->m_pRoom2Btn->setStyleSheet( qsUnClickBtnStyle );
    ui->m_pRoom3Btn->setStyleSheet( qsUnClickBtnStyle );
    ui->m_pRoom4Btn->setStyleSheet( qsUnClickBtnStyle );
}

void BCSettingOtherDeviceControlDlg::on_m_pRoom2Btn_clicked()
{
    ui->m_pRoom1Btn->setStyleSheet( qsUnClickBtnStyle );
    ui->m_pRoom2Btn->setStyleSheet( qsClickBtnStyle );
    ui->m_pRoom3Btn->setStyleSheet( qsUnClickBtnStyle );
    ui->m_pRoom4Btn->setStyleSheet( qsUnClickBtnStyle );
}

void BCSettingOtherDeviceControlDlg::on_m_pRoom3Btn_clicked()
{
    ui->m_pRoom1Btn->setStyleSheet( qsUnClickBtnStyle );
    ui->m_pRoom2Btn->setStyleSheet( qsUnClickBtnStyle );
    ui->m_pRoom3Btn->setStyleSheet( qsClickBtnStyle );
    ui->m_pRoom4Btn->setStyleSheet( qsUnClickBtnStyle );
}

void BCSettingOtherDeviceControlDlg::on_m_pRoom4Btn_clicked()
{
    ui->m_pRoom1Btn->setStyleSheet( qsUnClickBtnStyle );
    ui->m_pRoom2Btn->setStyleSheet( qsUnClickBtnStyle );
    ui->m_pRoom3Btn->setStyleSheet( qsUnClickBtnStyle );
    ui->m_pRoom4Btn->setStyleSheet( qsClickBtnStyle );
}

void BCSettingOtherDeviceControlDlg::on_m_pVedioOff1_clicked()
{
    // 输入1静音FF 55 03 A5AC0C00020100000000000F FA
    QString cmd;
    cmd.append(QChar(0xFF));
    cmd.append(QChar(0x55));
    cmd.append(QChar(0x03));

    cmd.append(QChar(0xA5));
    cmd.append(QChar(0xAC));
    cmd.append(QChar(0x0C));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x0F));

    cmd.append(QChar(0xFA));

    m_pTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCSettingOtherDeviceControlDlg::on_m_pVedioOff2_clicked()
{
    // 输入2静音 FF 55 03 A5AC0C000201000000010111 FA
    QString cmd;
    cmd.append(QChar(0xFF));
    cmd.append(QChar(0x55));
    cmd.append(QChar(0x03));

    cmd.append(QChar(0xA5));
    cmd.append(QChar(0xAC));
    cmd.append(QChar(0x0C));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x11));

    cmd.append(QChar(0xFA));

    m_pTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCSettingOtherDeviceControlDlg::on_m_pVedioOff3_clicked()
{
    // 输入3静音 FF 55 03 A5AC0C000201000000020213 FA
    QString cmd;
    cmd.append(QChar(0xFF));
    cmd.append(QChar(0x55));
    cmd.append(QChar(0x03));

    cmd.append(QChar(0xA5));
    cmd.append(QChar(0xAC));
    cmd.append(QChar(0x0C));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x13));

    cmd.append(QChar(0xFA));

    m_pTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCSettingOtherDeviceControlDlg::on_m_pVedioOff4_clicked()
{
    // 输入4静音 FF 55 03 A5AC0C000201000000030315
    QString cmd;
    cmd.append(QChar(0xFF));
    cmd.append(QChar(0x55));
    cmd.append(QChar(0x03));

    cmd.append(QChar(0xA5));
    cmd.append(QChar(0xAC));
    cmd.append(QChar(0x0C));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x03));
    cmd.append(QChar(0x03));
    cmd.append(QChar(0x15));

    cmd.append(QChar(0xFA));

    m_pTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCSettingOtherDeviceControlDlg::on_m_pVedioOn1_clicked()
{
    // 输入1解除静音 FF 55 03 A5AC0C00020000000000000E FA
    QString cmd;
    cmd.append(QChar(0xFF));
    cmd.append(QChar(0x55));
    cmd.append(QChar(0x03));

    cmd.append(QChar(0xA5));
    cmd.append(QChar(0xAC));
    cmd.append(QChar(0x0C));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x0E));

    cmd.append(QChar(0xFA));

    m_pTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCSettingOtherDeviceControlDlg::on_m_pVedioOn2_clicked()
{
    // 输入2解除静音 FF 55 03 A5AC0C000200000000010110 FA
    QString cmd;
    cmd.append(QChar(0xFF));
    cmd.append(QChar(0x55));
    cmd.append(QChar(0x03));

    cmd.append(QChar(0xA5));
    cmd.append(QChar(0xAC));
    cmd.append(QChar(0x0C));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x10));

    cmd.append(QChar(0xFA));

    m_pTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCSettingOtherDeviceControlDlg::on_m_pVedioOn3_clicked()
{
    // 输入3解除静音 FF 55 03 A5AC0C000200000000020212 FA
    QString cmd;
    cmd.append(QChar(0xFF));
    cmd.append(QChar(0x55));
    cmd.append(QChar(0x03));

    cmd.append(QChar(0xA5));
    cmd.append(QChar(0xAC));
    cmd.append(QChar(0x0C));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x12));

    cmd.append(QChar(0xFA));

    m_pTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCSettingOtherDeviceControlDlg::on_m_pVedioOn4_clicked()
{
    // 输入4解除静音 FF 55 03 A5AC0C000200000000030314 FA
    QString cmd;
    cmd.append(QChar(0xFF));
    cmd.append(QChar(0x55));
    cmd.append(QChar(0x03));

    cmd.append(QChar(0xA5));
    cmd.append(QChar(0xAC));
    cmd.append(QChar(0x0C));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0x03));
    cmd.append(QChar(0x03));
    cmd.append(QChar(0x14));

    cmd.append(QChar(0xFA));

    m_pTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCSettingOtherDeviceControlDlg::on_m_pAudioSlider1_valueChanged(int value)
{
    QString cmd;
    cmd.append(QChar(0xFF));
    cmd.append(QChar(0x55));
    cmd.append(QChar(0x03));

    if (value < 25) {
        // 输入1低音 FF 55 03 A5AC0C0004F1F000000000F1 FA
        cmd.append(QChar(0xA5));
        cmd.append(QChar(0xAC));
        cmd.append(QChar(0x0C));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0xF1));
        cmd.append(QChar(0xF0));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0xF1));
    } else if (value < 50) {
        // 输入1中音 FF 55 03 A5AC0C000400000000000010 FA
        cmd.append(QChar(0xA5));
        cmd.append(QChar(0xAC));
        cmd.append(QChar(0x0C));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x10));
    } else if (value < 75) {
        // 输入1中高 FF 55 03 A5AC0C00040258000000006A FA
        cmd.append(QChar(0xA5));
        cmd.append(QChar(0xAC));
        cmd.append(QChar(0x0C));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0x02));
        cmd.append(QChar(0x58));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x6A));
    } else {
        // 输入1高音 FF 55 03 A5AC0C000404B000000000C4 FA
        cmd.append(QChar(0xA5));
        cmd.append(QChar(0xAC));
        cmd.append(QChar(0x0C));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0xB0));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0xC4));
    }

    cmd.append(QChar(0xFA));

    m_pTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCSettingOtherDeviceControlDlg::on_m_pAudioSlider2_valueChanged(int value)
{
    QString cmd;
    cmd.append(QChar(0xFF));
    cmd.append(QChar(0x55));
    cmd.append(QChar(0x03));

    if (value < 25) {
        // 输入2低音
        cmd.append(QChar(0xA5));
        cmd.append(QChar(0xAC));
        cmd.append(QChar(0x0C));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0xF1));
        cmd.append(QChar(0xF0));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x01));
        cmd.append(QChar(0x01));
        cmd.append(QChar(0xF3));
    } else if (value < 50) {
        // 输入2中音
        cmd.append(QChar(0xA5));
        cmd.append(QChar(0xAC));
        cmd.append(QChar(0x0C));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x01));
        cmd.append(QChar(0x01));
        cmd.append(QChar(0x12));
    } else if (value < 75) {
        // 输入2中高
        cmd.append(QChar(0xA5));
        cmd.append(QChar(0xAC));
        cmd.append(QChar(0x0C));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0x02));
        cmd.append(QChar(0x58));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x01));
        cmd.append(QChar(0x01));
        cmd.append(QChar(0x6C));
    } else {
        // 输入2高音
        cmd.append(QChar(0xA5));
        cmd.append(QChar(0xAC));
        cmd.append(QChar(0x0C));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0xB0));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x01));
        cmd.append(QChar(0x01));
        cmd.append(QChar(0xC6));
    }

    cmd.append(QChar(0xFA));

    m_pTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCSettingOtherDeviceControlDlg::on_m_pAudioSlider3_valueChanged(int value)
{
    QString cmd;
    cmd.append(QChar(0xFF));
    cmd.append(QChar(0x55));
    cmd.append(QChar(0x03));

    if (value < 25) {
        // 输入3低音 FF 55 03 A5AC0C0004F1F000000202F5 FA
        cmd.append(QChar(0xA5));
        cmd.append(QChar(0xAC));
        cmd.append(QChar(0x0C));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0xF1));
        cmd.append(QChar(0xF0));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x02));
        cmd.append(QChar(0x02));
        cmd.append(QChar(0xF5));
    } else if (value < 50) {
        // 输入3中音 FF 55 03 A5AC0C000400000000020214 FA
        cmd.append(QChar(0xA5));
        cmd.append(QChar(0xAC));
        cmd.append(QChar(0x0C));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x02));
        cmd.append(QChar(0x02));
        cmd.append(QChar(0x14));
    } else if (value < 75) {
        // 输入3中高 FF 55 03 A5AC0C00040258000002026E FA
        cmd.append(QChar(0xA5));
        cmd.append(QChar(0xAC));
        cmd.append(QChar(0x0C));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0x02));
        cmd.append(QChar(0x58));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x02));
        cmd.append(QChar(0x02));
        cmd.append(QChar(0x6E));
    } else {
        // 输入3高音 FF 55 03 A5AC0C000404B000000202C8 FA
        cmd.append(QChar(0xA5));
        cmd.append(QChar(0xAC));
        cmd.append(QChar(0x0C));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0xB0));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x02));
        cmd.append(QChar(0x02));
        cmd.append(QChar(0xC8));
    }

    cmd.append(QChar(0xFA));

    m_pTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCSettingOtherDeviceControlDlg::on_m_pAudioSlider4_valueChanged(int value)
{
    QString cmd;
    cmd.append(QChar(0xFF));
    cmd.append(QChar(0x55));
    cmd.append(QChar(0x03));

    if (value < 25) {
        // 输入4低音 FF 55 03 A5AC0C0004F3800000030389 FA
        cmd.append(QChar(0xA5));
        cmd.append(QChar(0xAC));
        cmd.append(QChar(0x0C));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0xF3));
        cmd.append(QChar(0x80));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x03));
        cmd.append(QChar(0x03));
        cmd.append(QChar(0x89));
    } else if (value < 50) {
        // 输入4中音 FF 55 03 A5AC0C000400000000030316 FA
        cmd.append(QChar(0xA5));
        cmd.append(QChar(0xAC));
        cmd.append(QChar(0x0C));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x03));
        cmd.append(QChar(0x03));
        cmd.append(QChar(0x16));
    } else if (value < 75) {
        // 输入4中高 FF 55 03 A5AC0C000402580000030370 FA
        cmd.append(QChar(0xA5));
        cmd.append(QChar(0xAC));
        cmd.append(QChar(0x0C));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0x02));
        cmd.append(QChar(0x58));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x03));
        cmd.append(QChar(0x03));
        cmd.append(QChar(0x70));
    } else {
        // 输入4高音 FF 55 03 A5AC0C000404B000000303CA FA
        cmd.append(QChar(0xA5));
        cmd.append(QChar(0xAC));
        cmd.append(QChar(0x0C));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0x04));
        cmd.append(QChar(0xB0));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x00));
        cmd.append(QChar(0x03));
        cmd.append(QChar(0x03));
        cmd.append(QChar(0xCA));
    }

    cmd.append(QChar(0xFA));

    m_pTcpSocket->write(cmd.toLatin1(), cmd.length());
}
