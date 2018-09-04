#include "BCSettingAddIPVedioTreeWidgetItemDlg.h"
#include "ui_BCSettingAddIPVedioTreeWidgetItemDlg.h"
#include "../Common/BCCommon.h"

BCSettingAddIPVedioTreeWidgetItemDlg::BCSettingAddIPVedioTreeWidgetItemDlg(int type, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingAddIPVedioTreeWidgetItemDlg)
{
    ui->setupUi(this);

    this->setWindowTitle(tr("添加IPVideo对话框"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    if (0 == type) {
        ui->m_pPosCombBox->addItem(tr("根节点"));
    } else {
        ui->m_pPosCombBox->addItem(tr("同级节点"));
        ui->m_pPosCombBox->addItem(tr("子节点"));
    }
}

BCSettingAddIPVedioTreeWidgetItemDlg::BCSettingAddIPVedioTreeWidgetItemDlg(const QString &name, const QString &url, const QString &decoder, const QString &resolution, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingAddIPVedioTreeWidgetItemDlg)
{
    ui->setupUi(this);

    this->setWindowTitle(tr("修改IPVideo对话框"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    // 隐藏位置属性
    ui->m_pPosLabel->hide();
    ui->m_pPosCombBox->hide();

    ui->m_pNameLineEdit->setText( name );
    ui->m_pUrlLineEdit->setText( url );
    ui->m_pDecoderComboBox->setCurrentIndex(decoder.contains("H264") ? 0 : 1);
    QStringList lstResolution = resolution.split("*");
    int resolutionX = 0;
    int resolutionY = 0;
    if (2 == lstResolution.count()) {
        resolutionX = lstResolution.at(0).toInt();
        resolutionY = lstResolution.at(1).toInt();
    }
    ui->m_pResolutionXLineEdit->setText( QString::number(resolutionX) );
    ui->m_pResolutionYLineEdit->setText( QString::number(resolutionY) );
}

BCSettingAddIPVedioTreeWidgetItemDlg::~BCSettingAddIPVedioTreeWidgetItemDlg()
{
    delete ui;
}

void BCSettingAddIPVedioTreeWidgetItemDlg::on_m_pOKBtn_clicked()
{
    m_nPos = ui->m_pPosCombBox->currentIndex();
    m_qsName = ui->m_pNameLineEdit->text();
    m_qsURL = ui->m_pUrlLineEdit->text();
    m_qsDecoder = ui->m_pDecoderComboBox->currentText();
    m_qsResolution = QString("%1*%2").arg(ui->m_pResolutionXLineEdit->text())
            .arg(ui->m_pResolutionYLineEdit->text());

    this->accept();
}

void BCSettingAddIPVedioTreeWidgetItemDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}
