#include "BCSettingModifyVP2000IPDlg.h"
#include "ui_BCSettingModifyVP2000IPDlg.h"
#include <QMessageBox>
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"

BCSettingModifyVP2000IPDlg::BCSettingModifyVP2000IPDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingModifyVP2000IPDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    // 标题和图标
    setWindowTitle(tr("修改设备IP"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    ui->m_pIPLineEdit->setText( BCLocalServer::Application()->m_qsConnectIPWithoutDLL );
}

BCSettingModifyVP2000IPDlg::~BCSettingModifyVP2000IPDlg()
{
    delete ui;
}

void BCSettingModifyVP2000IPDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingModifyVP2000IPDlg::on_m_pOKBtn_clicked()
{
    // 检查字符串格式
    QString ip = ui->m_pIPLineEdit->text();
    QRegExp rx("^(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[1-9])\.(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[1-9]|0)\.(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[1-9]|0)\.(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[0-9])$");
    if( !rx.exactMatch(ip) ) {
        QMessageBox::information(this, tr("提示"), tr("IP地址格式错误."));
        return;
    }

    // 发送指令修改设备IP
    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->SetDevice2000IP( ip );

    // 修改DB文件内的配置信息
    pServer->UpdateRoomIP( ip );

    // 如果是网络控制需要断开连接，设置新地址，重新连接
    if ( pServer->m_bIsNetConnect ) {
        pServer->m_qsConnectIPWithoutDLL = ip;
        pServer->DisConnect();
        pServer->ReConnect();
    }

    this->accept();
}
