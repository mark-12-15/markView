#include "BCSettingPasswordStyle.h"
#include "ui_BCSettingPasswordStyle.h"
#include <QPushButton>
#include <QMessageBox>
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"
#include "../Common/BCCommunication.h"

BCSettingPasswordStyle::BCSettingPasswordStyle(QWidget *parent,bool /*hiden*/) :
    QDialog(parent),
    ui(new Ui::BCSettingPasswordStyle)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("修改密码"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );
}

BCSettingPasswordStyle::~BCSettingPasswordStyle()
{
    delete ui;
}

void BCSettingPasswordStyle::on_m_pOKBtn_clicked()
{
    QString qsOldPassword = ui->m_pOldLineEdit->text();
    QString qsNewPassword = ui->m_pNewLineEdit->text();
    QString qsReNewPassword = ui->m_pReNewLineEdit->text();

    MainWindow *pMainWindow = BCCommon::Application();
    BCSUser *pUser = pMainWindow->GetCurrentUser();
    if (qsOldPassword != pUser->password ) {
        QMessageBox::warning(this,
                             tr("警告"),
                             tr("原密码不对，请重新输入!"),
                             QMessageBox::Ok);
        return;
    }

    if ( qsNewPassword.contains(" ") ) {
        QMessageBox::warning(this,
                             tr("警告"),
                             tr("新密码中不可以包含空格，请重新输入!"),
                             QMessageBox::Ok);
        return;
    }

    if (qsNewPassword != qsReNewPassword) {
        QMessageBox::warning(this,
                             tr("警告"),
                             tr("两次新密码不同，请重新输入!"),
                             QMessageBox::Ok);
        return;
    }

    // 赋值新密码
    pUser->password = qsNewPassword;

    // 修改数据库
    if ( BCCommon::g_bConnectWithServer ) {
        BCCommunication *pServer = BCCommunication::Application();
        pServer->ModifyUser(pUser->id, pUser->loginName, pUser->password);
    } else {
        BCLocalServer *pServer = BCLocalServer::Application();
        pServer->ModifyUser(pUser->id, pUser->loginName, pUser->password, -1);
    }

    QMessageBox::information(this,
                         tr("提示"),
                         tr("修改密码成功!"),
                         QMessageBox::Ok);

    this->accept();
}

void BCSettingPasswordStyle::on_m_pCancelBtn_clicked()
{
    this->reject();
}
