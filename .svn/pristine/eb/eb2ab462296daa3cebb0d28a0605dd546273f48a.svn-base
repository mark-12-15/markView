#include "BCSettingDisplaySwitchRoomWidget.h"
#include "ui_BCSettingDisplaySwitchRoomWidget.h"
#include "../Model/BCMRoom.h"
#include "BCSettingDisplaySwitchConfigDlg.h"
#include <QSerialPortInfo>

BCSettingDisplaySwitchRoomWidget::BCSettingDisplaySwitchRoomWidget(BCMRoom *pRoom, BCSettingDisplaySwitchConfigDlg *parent) :
    QWidget(parent),
    ui(new Ui::BCSettingDisplaySwitchRoomWidget)
{
    ui->setupUi(this);

    m_pRoom = pRoom;
    m_parent = parent;

    // 初始化Net连接参数
    ui->m_pUseNetConnectRadioBtn->setChecked( m_pRoom->GetSwitchIsNetConnect() );
    ui->m_pUseComConnectRadioBtn->setChecked( !m_pRoom->GetSwitchIsNetConnect() );

    // 初始化COM连接参数
    QList<QSerialPortInfo> lstSerialPort = QSerialPortInfo::availablePorts();
    for (int i = 0; i < lstSerialPort.count(); i++) {
        QSerialPortInfo info = lstSerialPort.at( i );
        ui->m_pComComBox->addItem( info.portName() );
    }

    // 其他参数
    ui->m_pComComBox->setCurrentText( m_pRoom->GetSwitchCom() );
    ui->m_pBaudRateComBox->setCurrentText(QString::number(m_pRoom->GetSwitchBaudRate()));
    ui->m_pDataBitComBox->setCurrentText(QString::number(m_pRoom->GetSwitchDataBit()));
    ui->m_pStopBitComBox->setCurrentText(QString::number(m_pRoom->GetSwitchStopBit()));
    ui->m_pCheckBitComBox->setCurrentText( m_pRoom->GetSwitchCheckBit() );
    ui->m_pStreamCtrlComBox->setCurrentText( m_pRoom->GetSwitchStreamCtrl() );

    // 设置基础数据
    ui->m_pRoomLabel->setText( QString("%1(%2)").arg(m_pRoom->GetRoomName()).arg(m_pRoom->GetRoomID()) );
    ui->m_pNetIPLineEdit->setText( m_pRoom->GetSwitchIP() );
    ui->m_pNetPortLineEdit->setText( QString::number(m_pRoom->GetSwitchPort()) );
    ui->m_pCommandTypeCombox->setCurrentIndex( m_pRoom->GetSwitchType() );
    ui->m_pOpenCmdLineEdit->setText( m_pRoom->GetSwitchOnCmd() );
    ui->m_pCloseCmdLineEdit->setText( m_pRoom->GetSwitchOffCmd() );
}

BCSettingDisplaySwitchRoomWidget::~BCSettingDisplaySwitchRoomWidget()
{
    delete ui;
}

void BCSettingDisplaySwitchRoomWidget::RefreshDisplayMaker(QList<sDisplayMaker> lstMaker)
{
    disconnect(ui->m_pDisplayMakerComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_m_pDisplayMakerComboBox_currentIndexChanged(int)));

    // 1.重新构造combbox
    ui->m_pDisplayMakerComboBox->clear();
    m_lstMaker = lstMaker;

    int index = -1;
    for (int i = 0; i < m_lstMaker.count(); i++) {
        sDisplayMaker dmaker = m_lstMaker.at( i );
        ui->m_pDisplayMakerComboBox->addItem( dmaker.maker );

        // 如果指令完全吻合记录索引
        if ((ui->m_pCommandTypeCombox->currentIndex() == dmaker.cmdType)
                && (ui->m_pOpenCmdLineEdit->text() == dmaker.onCmd)
                && (ui->m_pCloseCmdLineEdit->text() == dmaker.offCmd)) {
            index == i;
        }
    }
    ui->m_pDisplayMakerComboBox->addItem( tr("自定义") );

    // 2.看当前指令是否和某厂家一致，如果一致则设置当前厂家
    ui->m_pDisplayMakerComboBox->setCurrentIndex((-1 != index) ? index : (ui->m_pDisplayMakerComboBox->count()-1));

    connect(ui->m_pDisplayMakerComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_m_pDisplayMakerComboBox_currentIndexChanged(int)));
}

void BCSettingDisplaySwitchRoomWidget::SaveConfig()
{
    m_pRoom->SetSwitchConfig( ui->m_pUseNetConnectRadioBtn->isChecked() ? 1 : 0,
                              ui->m_pNetIPLineEdit->text(),
                              ui->m_pNetPortLineEdit->text().toInt(),
                              ui->m_pComComBox->currentText(),
                              ui->m_pBaudRateComBox->currentText().toInt(),
                              ui->m_pDataBitComBox->currentText().toInt(),
                              ui->m_pStopBitComBox->currentText().toInt(),
                              ui->m_pCheckBitComBox->currentText(),
                              ui->m_pStreamCtrlComBox->currentText(),
                              ui->m_pCommandTypeCombox->currentIndex(),
                              ui->m_pOpenCmdLineEdit->text(),
                              ui->m_pCloseCmdLineEdit->text(),
                              true );
}

void BCSettingDisplaySwitchRoomWidget::on_m_pDisplayMakerComboBox_currentIndexChanged(int index)
{
    if (index < m_lstMaker.count()) {
        sDisplayMaker dmaker = m_lstMaker.at( index );
        ui->m_pCommandTypeCombox->setCurrentIndex( dmaker.cmdType );
        ui->m_pOpenCmdLineEdit->setText( dmaker.onCmd );
        ui->m_pCloseCmdLineEdit->setText( dmaker.offCmd );
    }
}
