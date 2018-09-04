#include "BCSettingModifyNameDlg.h"
#include "ui_BCSettingModifyNameDlg.h"
#include "../Common/BCCommon.h"

BCSettingModifyNameDlg::BCSettingModifyNameDlg(const QString &str, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingModifyNameDlg)
{
    ui->setupUi(this);
    //this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("修改名称"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    ui->m_pNameLineEdit->setText( str );
}

BCSettingModifyNameDlg::~BCSettingModifyNameDlg()
{
    delete ui;
}

QString BCSettingModifyNameDlg::GetString()
{
    return m_str;
}

void BCSettingModifyNameDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingModifyNameDlg::on_m_pOKBtn_clicked()
{
    m_str = ui->m_pNameLineEdit->text();
    this->accept();
}
