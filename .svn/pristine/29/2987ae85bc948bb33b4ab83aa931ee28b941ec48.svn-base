#include "BCSettingOutsideInterfaceDlg.h"
#include "ui_BCSettingOutsideInterfaceDlg.h"
#include <QSerialPortInfo>
#include "../Common/BCOutsideInterfaceServer.h"
#include "../Common/BCCommon.h"

BCSettingOutsideInterfaceDlg::BCSettingOutsideInterfaceDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingOutsideInterfaceDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("外部接口"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    // 初始化COM连接参数
    QList<QSerialPortInfo> lstSerialPort = QSerialPortInfo::availablePorts();
    for (int i = 0; i < lstSerialPort.count(); i++) {
        QSerialPortInfo info = lstSerialPort.at( i );
        ui->m_pComComBox1->addItem( info.portName() );
    }

    BCOutsideInterfaceServer *pServer = BCOutsideInterfaceServer::Application();
    ui->m_pComComBox1->setCurrentText( pServer->m_qsCurrentCom );
    ui->m_pBaudRateComBox1->setCurrentText( QString::number(pServer->m_nCurrentBaudRate) );
    ui->m_pDataBitComBox1->setCurrentText( QString::number(pServer->m_nCurrentDataBit) );
    ui->m_pStopBitComBox1->setCurrentText( QString::number(pServer->m_nCurrentStopBit) );
    ui->m_pCheckBitComBox1->setCurrentText( pServer->m_qsCurrentCheckBit );
    ui->m_pStreamCtrlComBox1->setCurrentText( pServer->m_qsCurrentStreamCtrl );
}

BCSettingOutsideInterfaceDlg::~BCSettingOutsideInterfaceDlg()
{
    delete ui;
}

void BCSettingOutsideInterfaceDlg::on_m_pConnectBtn1_clicked()
{
    BCOutsideInterfaceServer *pServer = BCOutsideInterfaceServer::Application();
    pServer->m_qsCurrentCom = ui->m_pComComBox1->currentText();
    pServer->m_nCurrentBaudRate = ui->m_pBaudRateComBox1->currentText().toInt();
    pServer->m_nCurrentDataBit = ui->m_pDataBitComBox1->currentText().toInt();
    pServer->m_nCurrentStopBit = ui->m_pStopBitComBox1->currentText().toInt();
    pServer->m_qsCurrentCheckBit = ui->m_pCheckBitComBox1->currentText();
    pServer->m_qsCurrentStreamCtrl = ui->m_pStreamCtrlComBox1->currentText();

    pServer->Connect();
    ui->m_pStatusLabel1->setText(pServer->IsConnected() ? tr("连接成功") : tr("连接失败，请检查连接信息."));
}

