#include "BCOtherDeviceControlDlg.h"
#include "ui_BCOtherDeviceControlDlg.h"
#include <QTcpSocket>
#include <QHostAddress>
#include "../Common/BCCommon.h"
BCOtherDeviceControlDlg::BCOtherDeviceControlDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCOtherDeviceControlDlg)
{
    ui->setupUi(this);

    this->setWindowTitle(tr("外设控制"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    m_pDisplayTcpSocket = new QTcpSocket();
    m_pLightingTcpSocket = new QTcpSocket();
    m_pAudioTcpSocket = new QTcpSocket();
    m_pVedioTcpSocket = new QTcpSocket();

    m_pDisplayTcpSocket->connectToHost(QHostAddress("192.168.1.10"), 8000);
    m_pLightingTcpSocket->connectToHost(QHostAddress("192.168.1.8"), 8000);
    m_pAudioTcpSocket->connectToHost(QHostAddress("192.168.1.7"), 8000);
    m_pVedioTcpSocket->connectToHost(QHostAddress("192.168.1.9"), 8000);

    // set icon
    // vedio
    SetToolButtonIcon(ui->m_pVedioLeftBtn, QString("vedioleft48.png"));
    SetToolButtonIcon(ui->m_pVedioRightBtn, QString("vedioright48.png"));
    SetToolButtonIcon(ui->m_pVedioTopBtn, QString("vediotop48.png"));
    SetToolButtonIcon(ui->m_pVedioBottomBtn, QString("vediobottom48.png"));
    SetToolButtonIcon(ui->m_pVedioLeftTopBtn, QString("vediolefttop48.png"));
    SetToolButtonIcon(ui->m_pVedioLeftBottomBtn, QString("vedioleftbottom48.png"));
    SetToolButtonIcon(ui->m_pVedioRightTopBtn, QString("vediorighttop48.png"));
    SetToolButtonIcon(ui->m_pVedioRightBottomBtn, QString("vediorightbottom48.png"));
    SetToolButtonIcon(ui->m_pVedioZoomOnBtn, QString("vediozoomon48.png"));
    SetToolButtonIcon(ui->m_pVedioZoomOffBtn, QString("vediozoomoff48.png"));
    SetToolButtonIcon(ui->m_pVedioFocusOnBtn, QString("vediofocuson48.png"));
    SetToolButtonIcon(ui->m_pVedioFocusOffBtn, QString("vediofocusoff48.png"));
    SetToolButtonIcon(ui->m_pVedioStopBtn, QString("vediostop48.png"));

    // light
    SetToolButtonIcon(ui->m_pLightingOnBtn, QString("lightingon48.png"));
    SetToolButtonIcon(ui->m_pLightingOffBtn, QString("lightingoff48.png"));

    // audio
    SetToolButtonIcon(ui->m_pAudioPlusBtn, QString("audioplus48.png"));
    SetToolButtonIcon(ui->m_pAudioReduceBtn, QString("audioreduce48.png"));
    SetToolButtonIcon(ui->m_pAudioSilenceBtn, QString("audiosilence48.png"));

    // display
    SetToolButtonIcon(ui->m_pDisplayOnBtn, QString("displayon48.png"));
    SetToolButtonIcon(ui->m_pDisplayOffBtn, QString("displayoff48.png"));
}

BCOtherDeviceControlDlg::~BCOtherDeviceControlDlg()
{
    delete ui;
}

void BCOtherDeviceControlDlg::SetToolButtonIcon(QToolButton *pBtn, QString qsIconPath, int w, int h)
{
    pBtn->setIcon(QIcon(QPixmap(BCCommon::g_qOtherDevicePath+qsIconPath).scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    pBtn->setIconSize(QSize(w, h));
}

void BCOtherDeviceControlDlg::on_m_pDisplayOnBtn_clicked()
{
    QString cmd;
    cmd.append(QChar(0xD5));
    cmd.append(QChar(0x11));
    cmd.append(QChar(0x33));
    cmd.append(QChar(0x10));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0xAA));

    m_pDisplayTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCOtherDeviceControlDlg::on_m_pDisplayOffBtn_clicked()
{
    QString cmd;
    cmd.append(QChar(0xD5));
    cmd.append(QChar(0x11));
    cmd.append(QChar(0x33));
    cmd.append(QChar(0x10));
    cmd.append(QChar(0x00));
    cmd.append(QChar(0xAA));

    m_pDisplayTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCOtherDeviceControlDlg::on_m_pLightingOnBtn_clicked()
{
    QString cmd = QString("#000001\r\n");

    m_pLightingTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCOtherDeviceControlDlg::on_m_pLightingOffBtn_clicked()
{
    QString cmd = QString("#000000\r\n");

    m_pLightingTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCOtherDeviceControlDlg::on_m_pAudioPlusBtn_clicked()
{
    QString cmd = QString("#40 MACRO 3\r\n");

    m_pAudioTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCOtherDeviceControlDlg::on_m_pAudioReduceBtn_clicked()
{
    QString cmd = QString("#40 MACRO 4\r\n");

    m_pAudioTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCOtherDeviceControlDlg::on_m_pAudioSilenceBtn_clicked()
{
    QString cmd = QString("#40 MACRO 8\r\n");

    m_pAudioTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCOtherDeviceControlDlg::on_m_pVedioZoomOnBtn_clicked()
{
    QString cmd;
    cmd.append(QChar(0x81));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x04));
    cmd.append(QChar(0x07));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0xFF));

    m_pVedioTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCOtherDeviceControlDlg::on_m_pVedioZoomOffBtn_clicked()
{
    QString cmd;
    cmd.append(QChar(0x81));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x04));
    cmd.append(QChar(0x07));
    cmd.append(QChar(0x03));
    cmd.append(QChar(0xFF));

    m_pVedioTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCOtherDeviceControlDlg::on_m_pVedioFocusOnBtn_clicked()
{
    QString cmd;
    cmd.append(QChar(0x81));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x04));
    cmd.append(QChar(0x08));
    cmd.append(QChar(0x03));
    cmd.append(QChar(0xFF));

    m_pVedioTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCOtherDeviceControlDlg::on_m_pVedioFocusOffBtn_clicked()
{
    QString cmd;
    cmd.append(QChar(0x81));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x04));
    cmd.append(QChar(0x08));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0xFF));

    m_pVedioTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCOtherDeviceControlDlg::on_m_pVedioTopBtn_clicked()
{
    QString cmd;
    cmd.append(QChar(0x81));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x06));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x03));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x03));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0xFF));

    m_pVedioTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCOtherDeviceControlDlg::on_m_pVedioRightBtn_clicked()
{
    QString cmd;
    cmd.append(QChar(0x81));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x06));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x03));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x03));
    cmd.append(QChar(0xFF));

    m_pVedioTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCOtherDeviceControlDlg::on_m_pVedioBottomBtn_clicked()
{
    QString cmd;
    cmd.append(QChar(0x81));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x06));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x03));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x03));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0xFF));

    m_pVedioTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCOtherDeviceControlDlg::on_m_pVedioLeftTopBtn_clicked()
{
    QString cmd;
    cmd.append(QChar(0x81));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x06));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x03));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0xFF));

    m_pVedioTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCOtherDeviceControlDlg::on_m_pVedioRightTopBtn_clicked()
{
    QString cmd;
    cmd.append(QChar(0x81));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x06));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x03));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0xFF));

    m_pVedioTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCOtherDeviceControlDlg::on_m_pVedioLeftBottomBtn_clicked()
{
    QString cmd;
    cmd.append(QChar(0x81));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x06));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x03));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0xFF));

    m_pVedioTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCOtherDeviceControlDlg::on_m_pVedioRightBottomBtn_clicked()
{
    QString cmd;
    cmd.append(QChar(0x81));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x06));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x07));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0xFF));

    m_pVedioTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCOtherDeviceControlDlg::on_m_pVedioStopBtn_clicked()
{
    QString cmd;
    cmd.append(QChar(0x81));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x06));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x03));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x03));
    cmd.append(QChar(0x03));
    cmd.append(QChar(0xFF));

    m_pVedioTcpSocket->write(cmd.toLatin1(), cmd.length());
}

void BCOtherDeviceControlDlg::on_m_pVedioLeftBtn_clicked()
{
    QString cmd;
    cmd.append(QChar(0x81));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x06));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x03));
    cmd.append(QChar(0x02));
    cmd.append(QChar(0x01));
    cmd.append(QChar(0x03));
    cmd.append(QChar(0xFF));

    qDebug() << cmd;
    qDebug() << cmd.toLatin1();

    m_pVedioTcpSocket->write(cmd.toLatin1(), cmd.length());
}
