#include "BCSettingMatrixCutInputChannelDlg.h"
#include "ui_BCSettingMatrixCutInputChannelDlg.h"
#include "../Common/BCCommon.h"
#include "../Model/BCMMatrix.h"

BCSettingMatrixCutInputChannelDlg::BCSettingMatrixCutInputChannelDlg(BCMMatrix *pMatrix, int id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingMatrixCutInputChannelDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    // 标题和图标
    setWindowTitle(tr("裁剪信号"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    m_pMatrix = pMatrix;
    m_id = id;

    for (int i = 0; i < m_pMatrix->lstInputNode.count(); i++) {
        sMatrixNode node = m_pMatrix->lstInputNode.at( i );
        if (m_id != node.id)
            continue;

        ui->m_pLeftLineEdit->setText( QString::number(node.cutl) );
        ui->m_pRightLineEdit->setText( QString::number(node.cutr) );
        ui->m_pTopLineEdit->setText( QString::number(node.cutt) );
        ui->m_pBottomLineEdit->setText( QString::number(node.cutb) );
    }
}

BCSettingMatrixCutInputChannelDlg::~BCSettingMatrixCutInputChannelDlg()
{
    delete ui;
}

void BCSettingMatrixCutInputChannelDlg::SendCmd()
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

    this->m_pMatrix->SetCut(m_id, left, right, top, bottom);
}

void BCSettingMatrixCutInputChannelDlg::on_m_pApplyBtn_clicked()
{
    SendCmd();
}

void BCSettingMatrixCutInputChannelDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingMatrixCutInputChannelDlg::on_m_pOkBtn_clicked()
{
    SendCmd();
    this->accept();
}
