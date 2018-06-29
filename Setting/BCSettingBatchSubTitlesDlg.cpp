#include "BCSettingBatchSubTitlesDlg.h"
#include "ui_BCSettingBatchSubTitlesDlg.h"
#include <QColorDialog>
#include <QMessageBox>
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"
#include "../Common/BCCommunication.h"
#include "../Model/BCMChannel.h"
#include "../Model/BCMSubTitlesScene.h"

BCSettingBatchSubTitlesDlg::BCSettingBatchSubTitlesDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingBatchSubTitlesDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    // 标题和图标
    setWindowTitle(tr("批量设置字幕"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    // 初始化
    MainWindow *pApplication = BCCommon::Application();
    ui->m_pBeginChannelIDLineEdit->setText( QString::number(0) );
    ui->m_pEndChannelIDLineEdit->setText( QString::number(pApplication->GetInputChannels().count()-1) );
    ui->m_pSubTitlesTextLineEdit->setText( QString("Welcome") );
    ui->m_pSubTitlesPosXLineEdit->setText( QString::number(0) );
    ui->m_pSubTitlesPosYLineEdit->setText( QString::number(0) );
    ui->m_pSubTitlesColorBtn->setPalette(QPalette(QColor(0, 0, 255)));
    ui->m_pSubTitlesVisibleCombox->setCurrentIndex( 0 );
}

BCSettingBatchSubTitlesDlg::~BCSettingBatchSubTitlesDlg()
{
    delete ui;
}

void BCSettingBatchSubTitlesDlg::on_m_pSubTitlesColorBtn_clicked()
{
    QColor oldColor = ui->m_pSubTitlesColorBtn->palette().color(QPalette::Window);
    QColorDialog dlg(oldColor, BCCommon::Application());
    if (1 != dlg.exec())
        return;

    QColor newColor = dlg.currentColor();
    ui->m_pSubTitlesColorBtn->setPalette(QPalette(newColor));
}

void BCSettingBatchSubTitlesDlg::on_m_pSubTitlesTextApplyBtn_clicked()
{
    SetSubTitles( 0 );
}

void BCSettingBatchSubTitlesDlg::on_m_pSubTitlesPosApplyBtn_clicked()
{
    SetSubTitles( 1 );
}

void BCSettingBatchSubTitlesDlg::on_m_pSubTitlesColorApplyBtn_clicked()
{
    SetSubTitles( 2 );
}

void BCSettingBatchSubTitlesDlg::on_m_pSubTitlesVisibleApplyBtn_clicked()
{
    SetSubTitles( 3 );
}

void BCSettingBatchSubTitlesDlg::SetSubTitles(int type)
{
    int nBeginChid = ui->m_pBeginChannelIDLineEdit->text().toInt();
    int nEndChid = ui->m_pEndChannelIDLineEdit->text().toInt();
    if (nBeginChid > nEndChid) {
        QMessageBox msgBox( this );
        msgBox.setWindowTitle("警告");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("起始通道应小于终止通道!");
        msgBox.exec();

        return;
    }

    MainWindow *pApplication = BCCommon::Application();
    QList<BCMChannel *> lstChannels = pApplication->GetInputChannels();
    int nChannelCount = lstChannels.count();
    if ((nBeginChid < -1) || (nBeginChid >= nChannelCount)
            || (nEndChid < -1) || (nEndChid >= nChannelCount)) {
        QMessageBox msgBox( this );
        msgBox.setWindowTitle("警告");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText(QString("通道范围不合法,应在(0-%1)范围内.").arg(nChannelCount-1));
        msgBox.exec();

        return;
    }

    QString qsText = ui->m_pSubTitlesTextLineEdit->text();
    int nPosX = ui->m_pSubTitlesPosXLineEdit->text().toInt();
    int nPosY = ui->m_pSubTitlesPosYLineEdit->text().toInt();
    QColor color = ui->m_pSubTitlesColorBtn->palette().color(QPalette::Window);
    int r = color.red();
    int g = color.green();
    int b = color.blue();
    int visible = ui->m_pSubTitlesVisibleCombox->currentIndex();

    int boardcardid = -1;
    int boardcardpos = -1;
    if (nBeginChid == nEndChid) {
        for (int i = 0; i < lstChannels.count(); i++) {
            BCMChannel *pChannel = lstChannels.at( i );
            if (pChannel->GetChannelID() != nBeginChid)
                continue;

            boardcardid = pChannel->GetBoardCardID();
            boardcardpos = pChannel->GetBoardCardPos();
            break;
        }
    }

    if ( BCCommon::g_bConnectWithServer ) {
        BCCommunication *pServer = BCCommunication::Application();
        pServer->SetSubTitles(visible, nBeginChid, nEndChid, r, g, b, nPosX, nPosY, qsText);
    } else {
        BCLocalServer *pServer = BCLocalServer::Application();
        if (0 == type) {
            char *pSubTitlesText = BCCommon::getTextStr(qsText);
            pServer->SetSubTitlesText(0, nBeginChid, nEndChid, qsText, boardcardid, boardcardpos);
            free( pSubTitlesText );

            // 批量设置通道字幕
            for (int i = 0; i < nChannelCount; i++) {
                BCMChannel *pChannel = lstChannels.at(i);
                BCMSubTitlesSceneData *pSubTitles = pChannel->GetSubTitles();
                pSubTitles->m_qsText = qsText;
            }
        }
        if (1 == type) {
            pServer->SetSubTitlesPos(0, nBeginChid, nEndChid, nPosX, nPosY, boardcardid, boardcardpos);

            // 批量设置通道字幕
            for (int i = 0; i < nChannelCount; i++) {
                BCMChannel *pChannel = lstChannels.at(i);
                BCMSubTitlesSceneData *pSubTitles = pChannel->GetSubTitles();
                pSubTitles->m_pos = QPoint(nPosX, nPosY);
            }
        }
        if (2 == type) {
            pServer->SetSubTitlesColor(0, nBeginChid, nEndChid, color.red(), color.green(), color.blue(), boardcardid, boardcardpos);

            // 批量设置通道字幕
            for (int i = 0; i < nChannelCount; i++) {
                BCMChannel *pChannel = lstChannels.at(i);
                BCMSubTitlesSceneData *pSubTitles = pChannel->GetSubTitles();
                pSubTitles->m_color = color;
            }
        }
        if (3 == type) {
            pServer->SetSubTitlesVisible(0, nBeginChid, nEndChid, visible, boardcardid, boardcardpos);

            // 批量设置通道字幕
            for (int i = 0; i < nChannelCount; i++) {
                BCMChannel *pChannel = lstChannels.at(i);
                BCMSubTitlesSceneData *pSubTitles = pChannel->GetSubTitles();
                pSubTitles->m_nVisible = visible;
            }
        }
    }
}
