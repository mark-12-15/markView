#include "BCSettingMontageDlg.h"
#include "ui_BCSettingMontageDlg.h"
#include "../Common/BCLocalServer.h"
#include "../Common/BCCommon.h"

BCSettingMontageDlg::BCSettingMontageDlg(QWidget *parent)
    :QDialog(parent),
    ui(new Ui::BCSettingMontageDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("拼接设置"));
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));

    Init();
}

BCSettingMontageDlg::~BCSettingMontageDlg()
{
    delete ui;
}

void BCSettingMontageDlg::Init()
{
    // 预设的屏幕分辨率
    m_lstResolution << "640*480"
                    << "720*483"
                    << "720*576"
                    << "800*600"
                    << "960*2160"
                    << "1024*768"
                    << "1152*864"
                    << "1280*720"
                    << "1280*800"
                    << "1280*960"
                    << "1280*1024"
                    << "1360*768"
                    << "1366*768"
                    << "1400*1050"
                    << "1440*900"
                    << "1600*900"
                    << "1600*1200"
                    << "1920*1080"
                    << "1920*1200"
                    << "2048*1536"
                    << "2560*1600";

    // 初始化分辨率的slider
    ui->m_pResolutionSlider->setTickPosition(QSlider::TicksBelow);
    ui->m_pResolutionSlider->setRange(0, m_lstResolution.count()-1);
    ui->m_pResolutionSlider->setTickInterval(1);
    ui->m_pResolutionSlider->setSingleStep(1);
    connect(ui->m_pResolutionSlider, SIGNAL(valueChanged(int)), this, SLOT(onResolutionValueChanged(int)));

    // 本地数据库取拼接数据，没取到则返回
    BCLocalServer *pServer = BCLocalServer::Application();
//    BSMontage *pMontage = pServer->GetMontage();
//    if (NULL == pMontage)
//        return;

//    QString qsResolution = QString("%1*%2")
//            .arg(pMontage->resolutionX)
//            .arg(pMontage->resolutionY);

//    // 如果存了记录的分辨率则设置当前值
//    if ( m_lstResolution.contains( qsResolution ) ) {
//        ui->m_pResolutionSlider->setValue( m_lstResolution.indexOf(qsResolution) );
//    }

//    ui->m_pDisplayArrayXSpinBox->setValue( pMontage->displayArrayX );
//    ui->m_pDisplayArrayYSpinBox->setValue( pMontage->displayArrayY );

//    ui->m_pSubDisplayArrayXSpinBox->setValue(  pMontage->subDisplayArrayX );
//    ui->m_pSubDisplayArrayYSpinBox->setValue(  pMontage->subDisplayArrayY );

//    ui->m_pUsedForMontageCheckBox->setChecked( (1==pMontage->isUsedForMontage) ? true : false );
//    ui->m_pUsedForMontageCountSpinBox->setValue( pMontage->usedForMontageCount );

//    ui->m_pRefreshRateComboBox->setCurrentText( QString::number(pMontage->refreshRate) );

//    ui->m_pSideWidthXSpinBox->setValue( pMontage->sideWidthX );
//    ui->m_pSideWidthYSpinBox->setValue( pMontage->sideWidthY );

//    ui->m_pInputTypeComboBox->setCurrentText( QString(pMontage->inputType) );
//    ui->m_pInputStartPosSpinBox->setValue( pMontage->inputStartPos );
//    ui->m_pInputCountSpinBox->setValue( pMontage->inputCount );
}

void BCSettingMontageDlg::onResolutionValueChanged(int value)
{
    if ((value < 0) || (value > m_lstResolution.count()-1))
        return;

    ui->m_pResolutionLabel->setText( m_lstResolution.at(value) );
}

void BCSettingMontageDlg::on_m_pOkBtn_clicked()
{
//    BCLocalServer *pServer = BCLocalServer::Application();
//    pServer->SetMontage(NULL);
    this->close();
}

void BCSettingMontageDlg::on_m_pCancelBtn_clicked()
{
    this->close();
}

void BCSettingMontageDlg::on_m_pLoadLastStatusBtn_clicked()
{
//    BCLocalServer *pServer = BCLocalServer::Application();
//    pServer->LoadMontageLastStatus();
}

void BCSettingMontageDlg::on_m_pTestConfigBtn_clicked()
{
//    BCLocalServer *pServer = BCLocalServer::Application();
//    pServer->TestMontageConfig();
}

void BCSettingMontageDlg::on_m_pInputSetBtn_clicked()
{
//    BCLocalServer *pServer = BCLocalServer::Application();
//    pServer->SetMontageInputConfig();
}
