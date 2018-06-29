#include "BCSettingDeviceCustomResolutionDlg.h"
#include "ui_BCSettingDeviceCustomResolutionDlg.h"
#include "../Common/BCCommon.h"

BCSettingDeviceCustomResolutionDlg::BCSettingDeviceCustomResolutionDlg(int liveW, int liveH, int preW, int preH, int syncW, int syncH, int totalW, int totalH, int polarityW, int polarityH, int hertz, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingDeviceCustomResolutionDlg)
{
    ui->setupUi(this);

    this->setWindowTitle(tr("规模设置"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    ui->m_pLiveWSpinBox->setValue( liveW );
    ui->m_pLiveHSpinBox->setValue( liveH );
    ui->m_pPreWSpinBox->setValue( preW );
    ui->m_pPreHSpinBox->setValue( preH );
    ui->m_pSyncWSpinBox->setValue( syncW );
    ui->m_pSyncHSpinBox->setValue( syncH );
    ui->m_pTotalWSpinBox->setValue( totalW );
    ui->m_pTotalHSpinBox->setValue( totalH );
    ui->m_pPolarityWCombBox->setCurrentIndex( (1 == polarityW) ? 0 : 1 );
    ui->m_pPolarityHCombBox->setCurrentIndex( (1 == polarityH) ? 0 : 1 );
    ui->m_pHertzSpinBox->setValue( hertz );
}

BCSettingDeviceCustomResolutionDlg::~BCSettingDeviceCustomResolutionDlg()
{
    delete ui;
}

void BCSettingDeviceCustomResolutionDlg::on_m_pOKBtn_clicked()
{
    // 记录变量
    m_liveW = ui->m_pLiveWSpinBox->value();
    m_liveH = ui->m_pLiveHSpinBox->value();
    m_preW = ui->m_pPreWSpinBox->value();
    m_preH = ui->m_pPreHSpinBox->value();
    m_syncW = ui->m_pSyncWSpinBox->value();
    m_syncH = ui->m_pSyncHSpinBox->value();
    m_totalW = ui->m_pTotalWSpinBox->value();
    m_totalH = ui->m_pTotalHSpinBox->value();
    m_polarityW = (0 == ui->m_pPolarityWCombBox->currentIndex()) ? 1 : 0;
    m_polarityH = (0 == ui->m_pPolarityHCombBox->currentIndex()) ? 1 : 0;
    m_hertz = ui->m_pHertzSpinBox->value();

    this->accept();
}

void BCSettingDeviceCustomResolutionDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}
