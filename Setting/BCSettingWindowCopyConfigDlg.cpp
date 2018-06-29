#include "BCSettingWindowCopyConfigDlg.h"
#include "ui_BCSettingWindowCopyConfigDlg.h"
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"
#include "../Model/BCMChannel.h"
#include <QMessageBox>

BCSettingWindowCopyConfigDlg::BCSettingWindowCopyConfigDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingWindowCopyConfigDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("设置通道复制数量"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    // 设置可复制数量，最多支持240个复制窗口，高清占4个通道
    m_nPCCount = 0;
    m_nVideoCount = 0;
    m_nMaxCopyCount = 240;
    ui->progressBar->setValue( 0 );
    MainWindow *pMainWindow = BCCommon::Application();
    QList<BCMChannel *> lstChannel = pMainWindow->GetInputChannels();
    for (int i = 0; i < lstChannel.count(); i++) {
        BCMChannel *pChannel = lstChannel.at( i );
        int chType = pChannel->GetChannelType();

        if (0 == chType) {    // PC
            m_nMaxCopyCount -= 2;
            m_nPCCount++;
        }
        if (3 == chType) {    // Video
            m_nMaxCopyCount -= 2;
            m_nVideoCount++;
        }
        if (2 == chType)    // HDVI
            m_nMaxCopyCount -= 8;
    }

    // 如果没有可复制通道或者设备是2000设备则不支持复制
    if ((BCCommon::g_nDeviceType != 0) || (m_nMaxCopyCount <= 0)) {
        ui->m_pStatusLabel->setText( tr("注意：当前设备不支持复制通道!!!") );
    } else {
        ui->m_pStatusLabel->setText( tr("注意：复制通道的总和为%1，请合理分配").arg(m_nMaxCopyCount) );
    }
}

BCSettingWindowCopyConfigDlg::~BCSettingWindowCopyConfigDlg()
{
    delete ui;
}

void BCSettingWindowCopyConfigDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingWindowCopyConfigDlg::on_m_pOKBtn_clicked()
{
    if ((BCCommon::g_nDeviceType != 0) || (m_nMaxCopyCount <= 0)) {
        // 不支持时不发送指令
    } else {
        int nPCCount = ui->m_pPCCopyCountLineEdit->text().toInt();
        int nVideoCount = ui->m_pVideoCopyCountLineEdit->text().toInt();

        // 如果数量有问题则提示对话框
        if ((nPCCount*m_nPCCount + nVideoCount*m_nVideoCount) > m_nMaxCopyCount) {
            QMessageBox::warning(this,
                                 tr("警告"),
                                 tr("复制数量已经超出合理范围，请重新填写!"),
                                 QMessageBox::Ok);

            return;
        }

        int nSplitTime = 200;
        BCLocalServer *pServer = BCLocalServer::Application();
        MainWindow *pMainWindow = BCCommon::Application();
        QList<BCMChannel *> lstChannel = pMainWindow->GetInputChannels();

        // 1.清空复制数量
        for (int i = 0; i < lstChannel.count(); i++) {
            BCMChannel *pChannel = lstChannel.at( i );
            int chType = pChannel->GetChannelType();
            int chid = pChannel->GetChannelID();

            if (0 == chType) {    // PC
                pServer->DelWinCopy(0, chid);
            }
            if (3 == chType) {    // Video
                pServer->DelWinCopy(1, chid);
            }

            ui->progressBar->setValue( (45/lstChannel.count())*(i+1) );
            QThread::msleep( nSplitTime );
        }

        ui->progressBar->setValue( 45 );

        // 2.设置复制数量
        for (int i = 0; i < lstChannel.count(); i++) {
            BCMChannel *pChannel = lstChannel.at( i );
            int chType = pChannel->GetChannelType();
            int chid = pChannel->GetChannelID();

            if (0 == chType) {    // PC
                pServer->SetWinCopy(0, chid, nPCCount);
            }
            if (3 == chType) {    // Video
                pServer->SetWinCopy(1, chid, nVideoCount);
            }

            ui->progressBar->setValue( 45+(45/lstChannel.count())*(i+1) );
            QThread::msleep( nSplitTime );
        }

        ui->progressBar->setValue( 90 );

        // 3.将数量写入xml文件
        BCCommon::g_nSignalWindowCopyCount = nPCCount;
        BCCommon::g_nSignalWindowCopyCountOfVideo = nVideoCount;

        QFile file( QString("../xml/BCGenaralConfig.xml") );
        if ( file.open(QIODevice::ReadOnly)) {
            // 将文件内容读到QDomDocument中
            QDomDocument doc;
            bool bLoadFile = doc.setContent(&file);
            file.close();

            if ( bLoadFile ) {
                // 二级链表
                QDomElement docElem = doc.documentElement();
                docElem.setAttribute("SignalWindowCopyCount", BCCommon::g_nSignalWindowCopyCount);
                docElem.setAttribute("SignalWindowCopyCountOfVideo", BCCommon::g_nSignalWindowCopyCountOfVideo);

                // 写入文件
                if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) ) {
                    //
                } else {
                    QTextStream out(&file);
                    doc.save(out,4);
                    file.close();
                }
            }
        }

        ui->progressBar->setValue( 100 );
    }

    this->accept();
}

void BCSettingWindowCopyConfigDlg::on_m_pOpenWindowCopyBtn_clicked()
{
    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->SetWinCopyEnable( true );
}

void BCSettingWindowCopyConfigDlg::on_m_pCloseWindowCopyBtn_clicked()
{
    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->SetWinCopyEnable( false );
}
