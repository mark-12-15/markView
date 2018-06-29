#include "BCSettingModifyEDIDDialog.h"
#include "ui_BCSettingModifyEDIDDialog.h"
#include <float.h>
#include "../Model/BCMChannel.h"
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"

BCSettingModifyEDIDDialog::BCSettingModifyEDIDDialog(BCMChannel *pChannel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingModifyEDIDDialog)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    // 标题和图标
    setWindowTitle(tr("编辑EDID"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    m_pChannel = pChannel;
}

BCSettingModifyEDIDDialog::~BCSettingModifyEDIDDialog()
{
    delete ui;
}

void BCSettingModifyEDIDDialog::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingModifyEDIDDialog::on_m_pOKBtn_clicked()
{
    int resolutionX = ui->m_pXLineEdit->text().toInt();
    int resolutionY = ui->m_pYLineEdit->text().toInt();
    int hz = ui->m_pHzLineEdit->text().toInt();

    //int id = m_pChannel->GetChannelID() - nBeginID;
    int nBoardID = m_pChannel->GetBoardCardID(); //id / 2;                  // 板卡号，从0开始
    int nChID = m_pChannel->GetBoardCardPos(); //0 == (id % 2)) ? 0 : 2;    // 通道号，0/2

    // 发送指令
    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->SetHDBaseEDID(nBoardID, nChID, resolutionX, resolutionY, hz);

    this->accept();
}
