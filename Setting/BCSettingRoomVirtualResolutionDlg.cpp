#include "BCSettingRoomVirtualResolutionDlg.h"
#include "ui_BCSettingRoomVirtualResolutionDlg.h"
#include "../Model/BCMRoom.h"
#include "../Model/BCMGroupDisplay.h"
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"
#include <QMessageBox>

BCSettingRoomVirtualResolutionDlg::BCSettingRoomVirtualResolutionDlg(BCMRoom *pRoom, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingRoomVirtualResolutionDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("虚拟分辨率"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    m_pRoom = pRoom;

    // init
    ui->m_pUseVirtualResolutionCheckBox->setChecked((1 == m_pRoom->IsUseVirSize()) ? true : false);
    ui->m_pWidthLineEdit->setText( QString::number(m_pRoom->GetWallSize().width()) );
    ui->m_pHeightLineEdit->setText( QString::number(m_pRoom->GetWallSize().height()) );

    BCMGroupDisplay *pGroupDisplay = m_pRoom->GetGroupDisplay( m_pRoom->GetRoomID() );
    if (NULL != pGroupDisplay) {
        ui->m_pUseVirtualArrayCheckBox->setChecked(pGroupDisplay->IsUseVirArraySize() ? true : false);
        ui->m_pArrayXLineEdit->setText( QString::number(pGroupDisplay->GetVirArraySize().width()) );
        ui->m_pArrayYLineEdit->setText( QString::number(pGroupDisplay->GetVirArraySize().height()) );
    }

}

BCSettingRoomVirtualResolutionDlg::~BCSettingRoomVirtualResolutionDlg()
{
    delete ui;
}

void BCSettingRoomVirtualResolutionDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingRoomVirtualResolutionDlg::on_m_pApplyBtn_clicked()
{
    int width = ui->m_pWidthLineEdit->text().toInt();
    int height = ui->m_pHeightLineEdit->text().toInt();
    int useVir = ui->m_pUseVirtualResolutionCheckBox->isChecked() ? 1 : 0;
    if (useVir == 1) {
        if ((width < 1) || (height < 1)) {
            QMessageBox::warning(this,
                                 tr("警告"),
                                 tr("数值不合理，请检查!"),
                                 QMessageBox::Ok);
        }
    }

    BCMGroupDisplay *pGroupDisplay = m_pRoom->GetGroupDisplay( m_pRoom->GetRoomID() );
    if (NULL != pGroupDisplay) {
        int arrX = ui->m_pArrayXLineEdit->text().toInt();
        int arrY = ui->m_pArrayYLineEdit->text().toInt();
        int useVirArr = ui->m_pUseVirtualArrayCheckBox->isChecked() ? 1 : 0;
        if (useVirArr == 1) {
            if ((arrX < 1) || (arrY < 1)) {
                QMessageBox::warning(this,
                                     tr("警告"),
                                     tr("数值不合理，请检查!"),
                                     QMessageBox::Ok);
            }
        }

        m_pRoom->SetIsUseVirSize( useVir );
        m_pRoom->SetWallVirSize(width, height);
        pGroupDisplay->SetUseVirArraySize( useVirArr );
        pGroupDisplay->SetVirArraySize(arrX, arrY);
        BCLocalServer *pServer = BCLocalServer::Application();
        pServer->UpdateRoomVirSize(m_pRoom->GetRoomID(), useVir, width, height, useVirArr, arrX, arrY);
        this->accept();

        // 重新加载界面
        MainWindow *pMainWindow = BCCommon::Application();
        pMainWindow->RefreshMainWindow();
    }
}
