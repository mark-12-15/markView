#include "BCSettingSingleDisplaySwitchConfigDlg.h"
#include "ui_BCSettingSingleDisplaySwitchConfigDlg.h"
#include "../Common/BCCommon.h"
#include "../Model/BCMDisplay.h"

BCSettingSingleDisplaySwitchConfigDlg::BCSettingSingleDisplaySwitchConfigDlg(BCMDisplay *pMDisplay, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingSingleDisplaySwitchConfigDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    m_pMDisplay = pMDisplay;
    ui->m_pSwitchOnLineEdit->setText( m_pMDisplay->GetSwitchOnCmd() );
    ui->m_pSwitchOffLineEdit->setText( m_pMDisplay->GetSwitchOffCmd() );

    this->setWindowTitle(tr("单屏开关配置"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );
}

BCSettingSingleDisplaySwitchConfigDlg::~BCSettingSingleDisplaySwitchConfigDlg()
{
    delete ui;
}

void BCSettingSingleDisplaySwitchConfigDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingSingleDisplaySwitchConfigDlg::on_m_pOKBtn_clicked()
{
    m_pMDisplay->SetSwitchOnCmd(ui->m_pSwitchOnLineEdit->text(), true);
    m_pMDisplay->SetSwitchOffCmd(ui->m_pSwitchOffLineEdit->text(), true);

    this->accept();
}
