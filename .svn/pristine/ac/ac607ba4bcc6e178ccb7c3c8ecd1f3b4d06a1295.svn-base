#include "BCSettingOutSideCommandDlg.h"
#include "ui_BCSettingOutSideCommandDlg.h"
#include <QFileDialog>
#include <QMessageBox>
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"

BCSettingOutSideCommandDlg::BCSettingOutSideCommandDlg(int type, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingOutSideCommandDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    QString qsWindowTitle = tr("系统升级");
    this->setWindowTitle( qsWindowTitle );
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));

    // 如果是普通的增值服务对话框则隐藏掉上面的获取编码Widget
    if (0 == type) {
        int nCodeWidgetHeight = ui->m_pCodeWidget->height();
        ui->m_pCodeWidget->setVisible( false );
        this->resize(this->width(), this->height()-nCodeWidgetHeight-24);
    }
}

BCSettingOutSideCommandDlg::~BCSettingOutSideCommandDlg()
{
    delete ui;
}

void BCSettingOutSideCommandDlg::on_m_pGetCodeBtn_clicked()
{
    // 创建tcp连接，发送指令，等待回码
}

void BCSettingOutSideCommandDlg::on_m_pSelectConfigFileBtn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                       NULL,
                                                       tr("config File (*.config)"));
    ui->m_pConfigFileLineEdit->setText( fileName );
}

void BCSettingOutSideCommandDlg::on_m_pSelectMd5FileBtn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                       NULL,
                                                       tr("md5 File (*.md5)"));
    ui->m_pMd5FileLineEdit->setText( fileName );
}

void BCSettingOutSideCommandDlg::on_m_pExecBtn_clicked()
{
    QString qsConfigFileName = ui->m_pConfigFileLineEdit->text();
    QString qsMd5FileName = ui->m_pMd5FileLineEdit->text();

    if ( qsConfigFileName.isEmpty() ) {
        QMessageBox::warning(this,
                             tr("警告"),
                             tr("请选择配置文件!"),
                             QMessageBox::Ok);
        ui->m_pConfigFileLineEdit->setFocus();
        return;
    }
    if ( qsMd5FileName.isEmpty() ) {
        QMessageBox::warning(this,
                             tr("警告"),
                             tr("请选择校验文件!"),
                             QMessageBox::Ok);
        ui->m_pMd5FileLineEdit->setFocus();
        return;
    }

    QFile file1(qsConfigFileName);
    if (!file1.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this,
                             tr("警告"),
                             tr("配置文件格式损坏，请检查!"),
                             QMessageBox::Ok);
        ui->m_pConfigFileLineEdit->setFocus();
        return;
    }

    QFile file2(qsMd5FileName);
    if (!file2.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this,
                             tr("警告"),
                             tr("校验文件格式损坏，请检查!"),
                             QMessageBox::Ok);
        ui->m_pMd5FileLineEdit->setFocus();
        return;
    }

    // 对应的编码字典
    QString qsEncodeKey = QString("0123456789abcdefghigklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    QString qsDecodeKey = QString("56VWXYZ78ghigABCDEFGHIJKLklmnopqrstu01234vwxyzMNOPQRS9abcdefTU");

    QByteArray configArr = file1.readAll();
    QByteArray md5Arr = file2.readAll();

    // 对于字符串的解码
    QString qsBase64 = QString( configArr );
    for (int i = 0; i < qsBase64.length(); i++) {
        QChar c = qsBase64.at(i);

        int index = qsDecodeKey.indexOf(c);
        if (-1 != index) {
            qsBase64 = qsBase64.replace(i, 1, qsEncodeKey.at(index));
        }
    }

    // 解析base64成字符串
    QString qsSrcCmd = QString(QByteArray::fromBase64(qsBase64.toLocal8Bit()));
    QByteArray srcMd5Arr = QCryptographicHash::hash(qsSrcCmd.toLocal8Bit(), QCryptographicHash::Md5);
    if (md5Arr != srcMd5Arr) {
        QMessageBox::warning(this,
                             tr("警告"),
                             tr("校验失败，请联系厂家!"),
                             QMessageBox::Ok);
        return;
    }

    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->SendCmd( QString("%1\r\n").arg(qsSrcCmd) );

    ui->m_pStatus->setText("执行成功！");
}
