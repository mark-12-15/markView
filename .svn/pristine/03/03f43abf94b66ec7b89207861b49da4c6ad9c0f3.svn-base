#include "BCSettingCutInputChannelDlg.h"
#include "ui_BCSettingCutInputChannelDlg.h"
#include "../Model/BCMChannel.h"
#include "../Common/BCCommon.h"

BCSettingCutInputChannelDlg::BCSettingCutInputChannelDlg(BCMChannel *pChannel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingCutInputChannelDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    // 标题和图标
    setWindowTitle(tr("裁剪信号"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    m_pChannel = pChannel;

    QRect rect = m_pChannel->GetCutArea();

//    disconnect(ui->m_pLeftLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_m_pLeftLineEdit_textChanged(QString)));
//    disconnect(ui->m_pRightLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_m_pRightLineEdit_textChanged(QString)));
//    disconnect(ui->m_pTopLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_m_pTopLineEdit_textChanged(QString)));
//    disconnect(ui->m_pBottomLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_m_pBottomLineEdit_textChanged(QString)));

    ui->m_pLeftLineEdit->setText( QString::number(rect.left()) );
    ui->m_pRightLineEdit->setText( QString::number(rect.width()) );
    ui->m_pTopLineEdit->setText( QString::number(rect.top()) );
    ui->m_pBottomLineEdit->setText( QString::number(rect.height()) );

//    connect(ui->m_pLeftLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_m_pLeftLineEdit_textChanged(QString)));
//    connect(ui->m_pRightLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_m_pRightLineEdit_textChanged(QString)));
//    connect(ui->m_pTopLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_m_pTopLineEdit_textChanged(QString)));
//    connect(ui->m_pBottomLineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_m_pBottomLineEdit_textChanged(QString)));
}

BCSettingCutInputChannelDlg::~BCSettingCutInputChannelDlg()
{
    delete ui;
}

void BCSettingCutInputChannelDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingCutInputChannelDlg::on_m_pOkBtn_clicked()
{
    SendCmd();
    this->accept();
}

void BCSettingCutInputChannelDlg::SendCmd()
{
    int left = ui->m_pLeftLineEdit->text().toInt();
    int right = ui->m_pRightLineEdit->text().toInt();
    int top = ui->m_pTopLineEdit->text().toInt();
    int bottom = ui->m_pBottomLineEdit->text().toInt();

    // 范围是x 0~960 y 0~540
    left = (left < 0) ? 0 : ((left > 960) ? 960 : left);
    right = (right < 0) ? 0 : ((right > 960) ? 960 : right);
    top = (top < 0) ? 0 : ((top > 540) ? 540 : top);
    bottom = (bottom < 0) ? 0 : ((bottom > 540) ? 540 : bottom);

    // 修改数据库
    if (NULL != m_pChannel) {
        m_pChannel->SetCutArea(left, right, top, bottom, true);
    }
}

//void BCSettingCutInputChannelDlg::on_m_pTopLineEdit_textChanged(const QString &/*arg1*/)
//{
//    SendCmd();
//}

//void BCSettingCutInputChannelDlg::on_m_pBottomLineEdit_textChanged(const QString &/*arg1*/)
//{
//    SendCmd();
//}

//void BCSettingCutInputChannelDlg::on_m_pLeftLineEdit_textChanged(const QString &/*arg1*/)
//{
//    SendCmd();
//}

//void BCSettingCutInputChannelDlg::on_m_pRightLineEdit_textChanged(const QString &/*arg1*/)
//{
//    SendCmd();
//}

void BCSettingCutInputChannelDlg::on_m_pApplyBtn_clicked()
{
    SendCmd();
}
