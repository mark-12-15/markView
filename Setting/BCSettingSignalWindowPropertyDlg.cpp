#include "BCSettingSignalWindowPropertyDlg.h"
#include "ui_BCSettingSignalWindowPropertyDlg.h"
#include "../Common/BCCommon.h"
#include "../View/BCSignalWindowDisplayWidget.h"
#include "../Model/BCMChannel.h"

BCSettingSignalWindowPropertyDlg::BCSettingSignalWindowPropertyDlg(BCSignalWindowDisplayWidget *pWidget, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingSignalWindowPropertyDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    m_pWidget = pWidget;

    // 标题和图标
    setWindowTitle(tr("信号窗属性"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    Init();
}

BCSettingSignalWindowPropertyDlg::~BCSettingSignalWindowPropertyDlg()
{
    delete ui;
}

void BCSettingSignalWindowPropertyDlg::Init()
{
    // Widget模式
    if (NULL != m_pWidget) {
        BCMChannel *pChannel = m_pWidget->GetInputChannel();
        QString qsTitle = pChannel->GetChannelName();
        ui->m_pTitleLineEdit->setText( qsTitle );

        QRect rect = m_pWidget->GetFactRect();

        ui->m_pPoxXLineEdit->setText( QString::number(rect.left()) );
        ui->m_pPoxYLineEdit->setText( QString::number(rect.top()) );
        ui->m_pWidthLineEdit->setText( QString::number(rect.width()) );
        ui->m_pHeightLineEdit->setText( QString::number(rect.height()) );
    }
}

void BCSettingSignalWindowPropertyDlg::on_m_pCancelBtn_clicked()
{
    this->close();
}

void BCSettingSignalWindowPropertyDlg::on_m_pOkBtn_clicked()
{
    QString qsTitle = ui->m_pTitleLineEdit->text();
    int x = ui->m_pPoxXLineEdit->text().toInt();
    int y = ui->m_pPoxYLineEdit->text().toInt();
    int w = ui->m_pWidthLineEdit->text().toInt();
    int h = ui->m_pHeightLineEdit->text().toInt();

    if (NULL != m_pWidget) {
        m_pWidget->SetSignalWindowTitle(qsTitle);

        m_pWidget->SetSignalWindowResize(x, y, w, h);
    }

    this->close();
}
