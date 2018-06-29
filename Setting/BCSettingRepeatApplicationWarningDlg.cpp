#include "BCSettingRepeatApplicationWarningDlg.h"
#include "ui_BCSettingRepeatApplicationWarningDlg.h"
#include "../Common/BCCommon.h"

BCSettingRepeatApplicationWarningDlg::BCSettingRepeatApplicationWarningDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingRepeatApplicationWarningDlg)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("提示"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    ui->m_pIconLabel->setPixmap( QPixmap(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsIconPathOfTrayIcon) );
}

BCSettingRepeatApplicationWarningDlg::~BCSettingRepeatApplicationWarningDlg()
{
    delete ui;
}

void BCSettingRepeatApplicationWarningDlg::on_m_pOKBtn_clicked()
{
    this->accept();
}
