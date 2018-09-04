#include "BCSettingIPVedioIPDlg.h"
#include "ui_BCSettingIPVedioIPDlg.h"
#include "../Model/BCMChannel.h"
#include "../Common/BCLocalServer.h"
#include "../Common/BCCommon.h"

BCSettingIPVedioIPDlg::BCSettingIPVedioIPDlg(BCMChannel *pChannel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingIPVedioIPDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("IPVideo IP设置"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    m_pChannel = pChannel;
}

BCSettingIPVedioIPDlg::~BCSettingIPVedioIPDlg()
{
    delete ui;
}

void BCSettingIPVedioIPDlg::on_m_pOKBtn_clicked()
{
    if (NULL != m_pChannel) {
        QString ip = ui->m_pIPLineEdit->text();
        QString mask = ui->m_pMaskLineEdit->text();
        QString gateway = ui->m_pGatewayLineEdit->text();
        QString mac = ui->m_pMacLineEdit->text();

        BCLocalServer *pServer = BCLocalServer::Application();
        pServer->SetIPVedioConfig(m_pChannel->GetChannelID(), ip, mask, gateway, mac, m_pChannel->GetBoardCardID(), m_pChannel->GetBoardCardPos());
    }

    this->accept();
}

void BCSettingIPVedioIPDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}
