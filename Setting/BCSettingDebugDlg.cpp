#include "BCSettingDebugDlg.h"
#include "ui_BCSettingDebugDlg.h"
#include "../Common/BCLocalServer.h"
#include "../Common/BCCommon.h"

BCSettingDebugDlg::BCSettingDebugDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingDebugDlg)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("调试工具"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );
}

BCSettingDebugDlg::~BCSettingDebugDlg()
{
    delete ui;
}

void BCSettingDebugDlg::AddCmd(const QString &cmd)
{
    ui->m_pRecvTextEdit->append( cmd );
}

void BCSettingDebugDlg::on_m_pClearBtn_clicked()
{
    ui->m_pRecvTextEdit->clear();
}

void BCSettingDebugDlg::on_m_pSendBtn_clicked()
{
    QString text = ui->m_pSendTextEdit->toPlainText();

    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->SendCmd(text.append("\r\n"), false);
}
