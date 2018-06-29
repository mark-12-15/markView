#include "BCSettingSubTitlesDlg.h"
#include "ui_BCSettingSubTitlesDlg.h"
#include <QColorDialog>
#include "../Common/BCCommon.h"
#include "../Model/BCMChannel.h"
#include "../Model/BCMSubTitlesScene.h"
#include "../Common//BCLocalServer.h"

BCSettingSubTitlesDlg::BCSettingSubTitlesDlg(BCMChannel *pChannel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingSubTitlesDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    // 标题和图标
    setWindowTitle(tr("设置字幕"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    m_pChannel = pChannel;

    // ??? 初始化
    BCMSubTitlesSceneData *pSubTitles = m_pChannel->GetSubTitles();
    ui->m_pTextLineEdit->setText( pSubTitles->m_qsText );
    ui->m_pPosXLineEdit->setText( QString::number(pSubTitles->m_pos.x()) );
    ui->m_pPosYLineEdit->setText( QString::number(pSubTitles->m_pos.y()) );
    ui->m_pVisibleCombBox->setCurrentIndex( pSubTitles->m_nVisible );

    ui->m_pColorBtn->setPalette(QPalette(pSubTitles->m_color));
}

BCSettingSubTitlesDlg::~BCSettingSubTitlesDlg()
{
    delete ui;
}

void BCSettingSubTitlesDlg::on_m_pColorBtn_clicked()
{
    BCMSubTitlesSceneData *pSubTitles = m_pChannel->GetSubTitles();
    QColorDialog dlg(pSubTitles->m_color, BCCommon::Application());
    if (1 != dlg.exec())
        return;

    QColor color = dlg.currentColor();
    pSubTitles->m_color = color;

    ui->m_pColorBtn->setPalette(QPalette(pSubTitles->m_color));
}

void BCSettingSubTitlesDlg::on_m_pCancelBtn_clicked()
{
    this->close();
}
#include "../Common/BCCommunication.h"
void BCSettingSubTitlesDlg::on_m_pOkBtn_clicked()
{
    if (NULL != m_pChannel) {
        BCMSubTitlesSceneData *pSubTitles = m_pChannel->GetSubTitles();
        pSubTitles->m_qsText = ui->m_pTextLineEdit->text();
        pSubTitles->m_pos = QPoint(ui->m_pPosXLineEdit->text().toInt(),
                                   ui->m_pPosYLineEdit->text().toInt());
        pSubTitles->m_nVisible = ui->m_pVisibleCombBox->currentIndex();

        if ( BCCommon::g_bConnectWithServer ) {
            BCCommunication *pServer = BCCommunication::Application();
            pServer->SetSubTitles(pSubTitles->m_nVisible, m_pChannel->GetChannelID(), m_pChannel->GetChannelID(), pSubTitles->m_color.red(), pSubTitles->m_color.green(), pSubTitles->m_color.blue(),
                                  pSubTitles->m_pos.x(), pSubTitles->m_pos.y(), pSubTitles->m_qsText);
        } else {
            BCLocalServer *pServer = BCLocalServer::Application();
            if (1 == pSubTitles->m_nVisible) {
                for (int i = 0; i < 5; i++) {
                    pServer->SetSubTitlesColor(m_pChannel->GetChannelType(), m_pChannel->GetChannelID(), m_pChannel->GetChannelID(), pSubTitles->m_color.red(), pSubTitles->m_color.green(), pSubTitles->m_color.blue(), m_pChannel->GetBoardCardID(), m_pChannel->GetBoardCardPos());
                    QThread::msleep(50);
                }

                for (int i = 0; i < 5; i++) {
                    pServer->SetSubTitlesPos(m_pChannel->GetChannelType(), m_pChannel->GetChannelID(), m_pChannel->GetChannelID(), pSubTitles->m_pos.x(), pSubTitles->m_pos.y(), m_pChannel->GetBoardCardID(), m_pChannel->GetBoardCardPos());
                    QThread::msleep(50);
                }
                for (int i = 0; i < 5; i++) {
                    pServer->SetSubTitlesText(m_pChannel->GetChannelType(), m_pChannel->GetChannelID(), m_pChannel->GetChannelID(), pSubTitles->m_qsText, m_pChannel->GetBoardCardID(), m_pChannel->GetBoardCardPos());
                    QThread::msleep(50);
                }
            }
            for (int i = 0; i < 5; i++) {
                pServer->SetSubTitlesVisible(m_pChannel->GetChannelType(), m_pChannel->GetChannelID(), m_pChannel->GetChannelID(), pSubTitles->m_nVisible, m_pChannel->GetBoardCardID(), m_pChannel->GetBoardCardPos());
                QThread::msleep(50);
            }
        }
    }

    this->close();
}

void BCSettingSubTitlesDlg::on_m_pApplyBtn_clicked()
{
    if (NULL != m_pChannel) {
        BCMSubTitlesSceneData *pSubTitles = m_pChannel->GetSubTitles();
        pSubTitles->m_qsText = ui->m_pTextLineEdit->text();
        pSubTitles->m_pos = QPoint(ui->m_pPosXLineEdit->text().toInt(),
                                   ui->m_pPosYLineEdit->text().toInt());
        pSubTitles->m_nVisible = ui->m_pVisibleCombBox->currentIndex();

        if ( BCCommon::g_bConnectWithServer ) {
            BCCommunication *pServer = BCCommunication::Application();
            pServer->SetSubTitles(pSubTitles->m_nVisible, m_pChannel->GetChannelID(), m_pChannel->GetChannelID(), pSubTitles->m_color.red(), pSubTitles->m_color.green(), pSubTitles->m_color.blue(),
                                  pSubTitles->m_pos.x(), pSubTitles->m_pos.y(), pSubTitles->m_qsText);
        } else {
            BCLocalServer *pServer = BCLocalServer::Application();
            if (1 == pSubTitles->m_nVisible) {
                for (int i = 0; i < 5; i++) {
                    pServer->SetSubTitlesColor(m_pChannel->GetChannelType(), m_pChannel->GetChannelID(), m_pChannel->GetChannelID(), pSubTitles->m_color.red(), pSubTitles->m_color.green(), pSubTitles->m_color.blue(), m_pChannel->GetBoardCardID(), m_pChannel->GetBoardCardPos());
                    QThread::msleep(50);
                }

                for (int i = 0; i < 5; i++) {
                    pServer->SetSubTitlesPos(m_pChannel->GetChannelType(), m_pChannel->GetChannelID(), m_pChannel->GetChannelID(), pSubTitles->m_pos.x(), pSubTitles->m_pos.y(), m_pChannel->GetBoardCardID(), m_pChannel->GetBoardCardPos());
                    QThread::msleep(50);
                }
                for (int i = 0; i < 5; i++) {
                    pServer->SetSubTitlesText(m_pChannel->GetChannelType(), m_pChannel->GetChannelID(), m_pChannel->GetChannelID(), pSubTitles->m_qsText, m_pChannel->GetBoardCardID(), m_pChannel->GetBoardCardPos());
                    QThread::msleep(50);
                }
            }
            for (int i = 0; i < 5; i++) {
                pServer->SetSubTitlesVisible(m_pChannel->GetChannelType(), m_pChannel->GetChannelID(), m_pChannel->GetChannelID(), pSubTitles->m_nVisible, m_pChannel->GetBoardCardID(), m_pChannel->GetBoardCardPos());
                QThread::msleep(50);
            }
        }
    }
}
