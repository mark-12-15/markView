#include "BCSettingChannelRemoteIPDlg.h"
#include "ui_BCSettingChannelRemoteIPDlg.h"
#include "../Common/BCCommon.h"
#include "../Model/BCMChannel.h"

BCSettingChannelRemoteIPDlg::BCSettingChannelRemoteIPDlg(BCMChannel *pChannel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingChannelRemoteIPDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("配置控制IP"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    m_pChannel = pChannel;

    ui->lineEdit->setText( m_pChannel->GetRemoteIP() );
}

BCSettingChannelRemoteIPDlg::~BCSettingChannelRemoteIPDlg()
{
    delete ui;
}

void BCSettingChannelRemoteIPDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingChannelRemoteIPDlg::on_m_pOKBtn_clicked()
{
    m_pChannel->SetRemoteIP( ui->lineEdit->text() );
    this->accept();
}
