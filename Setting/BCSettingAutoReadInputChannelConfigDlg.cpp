#include "BCSettingAutoReadInputChannelConfigDlg.h"
#include "ui_BCSettingAutoReadInputChannelConfigDlg.h"
#include "../Common/BCCommon.h"

BCSettingAutoReadInputChannelConfigDlg::BCSettingAutoReadInputChannelConfigDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingAutoReadInputChannelConfigDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    // 标题和图标
    setWindowTitle(tr("自定义输入通道配置"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    ui->m_pIsUseCheckBox->setChecked( (0 == BCCommon::g_nIsUseInputChannelConfig) ? true : false );
    ui->m_pPCCountLineEdit->setText( QString::number(BCCommon::g_npcCount) );
    ui->m_pPCBeginIDLineEdit->setText( QString::number(BCCommon::g_npcBeginID) );
    ui->m_pIPVedioCountLineEdit->setText( QString::number(BCCommon::g_nipvCount) );
    ui->m_pIPVedioBeginIDLineEdit->setText( QString::number(BCCommon::g_nipvBeginID) );
    ui->m_pVedioCountLineEdit->setText( QString::number(BCCommon::g_nvedioCount) );
    ui->m_pVedioBeginIDLineEdit->setText( QString::number(BCCommon::g_nvedioBeginID) );
    ui->m_pHDCountLineEdit->setText( QString::number(BCCommon::g_nhdCount) );
    ui->m_pHDBeginIDLineEdit->setText( QString::number(BCCommon::g_nhdBeginID) );

    on_m_pIsUseCheckBox_released();
}

BCSettingAutoReadInputChannelConfigDlg::~BCSettingAutoReadInputChannelConfigDlg()
{
    delete ui;
}

void BCSettingAutoReadInputChannelConfigDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingAutoReadInputChannelConfigDlg::on_m_pOKBtn_clicked()
{
    BCCommon::g_nIsUseInputChannelConfig = ui->m_pIsUseCheckBox->isChecked() ? 0 : 1;
    BCCommon::g_npcCount = ui->m_pPCCountLineEdit->text().toInt();
    BCCommon::g_npcBeginID = ui->m_pPCBeginIDLineEdit->text().toInt();
    BCCommon::g_nipvCount = ui->m_pIPVedioCountLineEdit->text().toInt();
    BCCommon::g_nipvBeginID = ui->m_pIPVedioBeginIDLineEdit->text().toInt();
    BCCommon::g_nvedioCount = ui->m_pVedioCountLineEdit->text().toInt();
    BCCommon::g_nvedioBeginID = ui->m_pVedioBeginIDLineEdit->text().toInt();
    BCCommon::g_nhdCount = ui->m_pHDCountLineEdit->text().toInt();
    BCCommon::g_nhdBeginID = ui->m_pHDBeginIDLineEdit->text().toInt();

    QFile file( QString("../xml/BCInputChannelConfig.xml") );
    if (file.open(QIODevice::ReadOnly)) {
        // 将文件内容读到QDomDocument中
        QDomDocument doc;
        bool bLoadFile = doc.setContent(&file);
        file.close();

        if ( bLoadFile ) {
            // 二级链表
            QDomElement docElem = doc.documentElement();
            docElem.setAttribute("isuse", BCCommon::g_nIsUseInputChannelConfig ? 1 : 0);
            docElem.setAttribute("pcCount", BCCommon::g_npcCount);
            docElem.setAttribute("pcBeginID", BCCommon::g_npcBeginID);
            docElem.setAttribute("ipvCount", BCCommon::g_nipvCount);
            docElem.setAttribute("ipvBeginID", BCCommon::g_nipvBeginID);
            docElem.setAttribute("vedioCount", BCCommon::g_nvedioCount);
            docElem.setAttribute("vedioBeginID", BCCommon::g_nvedioBeginID);
            docElem.setAttribute("hdCount", BCCommon::g_nhdCount);
            docElem.setAttribute("hdBeginID", BCCommon::g_nhdBeginID);

            // 写入文件
            if( file.open(QIODevice::WriteOnly | QIODevice::Truncate) ) {
                QTextStream out(&file);
                doc.save(out,4);
                file.close();
            }
        }
    }

    this->accept();
}

void BCSettingAutoReadInputChannelConfigDlg::on_m_pIsUseCheckBox_released()
{
    bool b = ui->m_pIsUseCheckBox->isChecked();

    ui->m_pPCCountLineEdit->setEnabled( !b );
    ui->m_pPCBeginIDLineEdit->setEnabled( !b );
    ui->m_pIPVedioCountLineEdit->setEnabled( !b );
    ui->m_pIPVedioBeginIDLineEdit->setEnabled( !b );
    ui->m_pVedioCountLineEdit->setEnabled( !b );
    ui->m_pVedioBeginIDLineEdit->setEnabled( !b );
    ui->m_pHDCountLineEdit->setEnabled( !b );
    ui->m_pHDBeginIDLineEdit->setEnabled( !b );
}
