#include "BCLocationDlg.h"
#include "ui_BCLocationDlg.h"
#include "../Common/BCCommon.h"
#include "../Common/BCCommunication.h"
#include "../Model/BCMGroupDisplay.h"
#include "../Model/BCMChannel.h"
#include "BCRoomWidget.h"
#include "BCSingleDisplayWidget.h"
#include "BCSignalWindowDisplayWidget.h"
#include "BCGroupDisplayWidget.h"

BCLocationLabel::BCLocationLabel(int r, int c, const QString &text, QWidget *parent)
    :QLabel(parent)
{
    setAutoFillBackground(true);
    m_nRow = r;
    m_nCol = c;

    setText( text );
    setAlignment(Qt::AlignLeft | Qt::AlignTop);
    setFrameShape (QFrame::Box);

    m_bHightLight = true;
    SetHightLight( !m_bHightLight );
}

void BCLocationLabel::SetHightLight(bool bHightLight)
{
   if (bHightLight == m_bHightLight)
       return;

   setPalette(QPalette(bHightLight ? QColor(BCCommon::g_nVirtualRectFillColorR,
                                            BCCommon::g_nVirtualRectFillColorG,
                                            BCCommon::g_nVirtualRectFillColorB,
                                            255)
                                   : QColor(BCCommon::g_nSingleDisplayFillColorR,
                                            BCCommon::g_nSingleDisplayFillColorG,
                                            BCCommon::g_nSingleDisplayFillColorB,
                                            BCCommon::g_nSingleDisplayFillColorA)));
   m_bHightLight = bHightLight;
}
// ---------------------------------------------------------------------------------------------------------------------------------

BCLocationDlg::BCLocationDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCLocationDlg)
{
    ui->setupUi(this);

    this->setWindowTitle( QObject::tr("快速开窗") );
    this->setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    m_pGroupDisplayWidget = NULL;
    m_pSignalWindowWidget = NULL;
    ui->m_pLocationGroupWidget->SetLocationDlg( this );
    ui->m_pLocationWidget->SetLocationDlg( this );

    Refresh();

    // VP2000时支持16分割，其他仅支持4分割
    if (BCCommon::g_bConnectWithServer ||(BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) {
    //if ( 1 ) {
        ui->m_pRadioBtn6->hide();
        ui->m_pRadioBtn8->hide();
        ui->m_pRadioBtn9->hide();
        ui->m_pRadioBtn12->hide();
        ui->m_pRadioBtn16->hide();
    }
}

BCLocationDlg::~BCLocationDlg()
{
    delete ui;
}

void BCLocationDlg::Refresh()
{
    MainWindow *pApplication = BCCommon::Application();
    BCRoomWidget *pWallView = pApplication->GetCurrentRoomWidget();
    if (NULL == pWallView)
        return;

    // 当前信号窗管理类
    BCRoomMainWidget *pSignalMgr = pWallView->GetRoomMainWidget();
    if (NULL == pSignalMgr)
        return;

    // 当前屏组
    BCGroupDisplayWidget *pSceneGroup = pSignalMgr->GetCurrentGroupDisplay();
    if (NULL == pSceneGroup)
        return;

    // 更新信号窗
    bool bModifySignalWindowOrGroupdisplay = false;
    //BCMChannel *pChannel = pApplication->GetCurrentInputChannel();

    BCSignalWindowDisplayWidget *pSignalWindow = pSignalMgr->GetCurrentSignalWindow();
    if (m_pSignalWindowWidget != pSignalWindow) {
        m_pSignalWindowWidget = pSignalWindow;

        bModifySignalWindowOrGroupdisplay = true;
    }

    // 更新屏组
    if (pSceneGroup != m_pGroupDisplayWidget) {
        m_pGroupDisplayWidget = pSceneGroup;

        // 分割变为初始化状态
        switch ( pSignalMgr->GetSegmentation() ) {
        case 1:
            ui->m_pRadioBtn1->setChecked( true );
            on_m_pRadioBtn1_clicked();
            break;
        case 4:
            ui->m_pRadioBtn4->setChecked( true );
            on_m_pRadioBtn4_clicked();
            break;
        case 6:
            ui->m_pRadioBtn6->setChecked( true );
            on_m_pRadioBtn6_clicked();
            break;
        case 8:
            ui->m_pRadioBtn8->setChecked( true );
            on_m_pRadioBtn8_clicked();
            break;
        case 9:
            ui->m_pRadioBtn9->setChecked( true );
            on_m_pRadioBtn9_clicked();
            break;
        case 12:
            ui->m_pRadioBtn12->setChecked( true );
            on_m_pRadioBtn12_clicked();
            break;
        default:
            ui->m_pRadioBtn16->setChecked( true );
            on_m_pRadioBtn16_clicked();
            break;
        }

        bModifySignalWindowOrGroupdisplay = true;
    }

    // 如果其中一个有改变则需要刷新数据
    if ( bModifySignalWindowOrGroupdisplay ) {
        ui->m_pLocationGroupWidget->Refresh(m_pGroupDisplayWidget, m_pSignalWindowWidget);
    }

    // 刷新高亮位置，如果是清屏则需要清除所有高亮矩形
    if (NULL == m_pSignalWindowWidget) {
        ui->m_pLocationGroupWidget->ClearHighLight();
        ui->m_pLocationWidget->ClearHighLight();
    } else {
        // 以左上角往下偏移5个像素点作为判断依据
        QPointF pt = m_pSignalWindowWidget->mapTo(pSignalMgr, m_pSignalWindowWidget->rect().topLeft());

        // 刷新单屏内矩形
        int viewX = ui->m_pLocationGroupWidget->rect().width() * (pt.x()) / pSignalMgr->rect().width();
        int viewY = ui->m_pLocationGroupWidget->rect().height() * (pt.y()) / pSignalMgr->rect().height();

        ui->m_pLocationGroupWidget->HighLight( QPoint(viewX, viewY) );

        // 刷新分割内矩形
        BCSingleDisplayWidget *pDisplayItem = m_pGroupDisplayWidget->GetSingleDisplay( QPoint(pt.x(), pt.y()) );
        if (NULL == pDisplayItem)
            return;

        // 坐标转换成单屏坐标
        int nSingleDisplayW = pDisplayItem->rect().width();
        int nSingleDisplayH = pDisplayItem->rect().height();
        QPoint singlePt = QPoint(pt.x(), pt.y());
        while (singlePt.x() > nSingleDisplayW) {
            singlePt.setX(singlePt.x()-nSingleDisplayW);
        }
        while (singlePt.y() > nSingleDisplayH) {
            singlePt.setY(singlePt.y()-nSingleDisplayH);
        }

        int labelX = ui->m_pLocationWidget->rect().width() * (singlePt.x()) / nSingleDisplayW;
        int labelY = ui->m_pLocationWidget->rect().height() * (singlePt.y()) / nSingleDisplayH;

        ui->m_pLocationWidget->RefreshHight( QPoint(labelX, labelY) );
    }
}

void BCLocationDlg::ResizeSignalWindow(bool b)
{
    m_bLocationDisplay = b;

    // 获得高亮的单屏矩形百分比
    QRectF singleDisplayRelationRect = ui->m_pLocationGroupWidget->GetSingleDisplayRelationRect();

    MainWindow *pApplication = BCCommon::Application();
    BCMChannel *pChannel = pApplication->GetCurrentInputChannel();
    if (NULL == pChannel)
        return;

    if (NULL != m_pSignalWindowWidget) {
        if (m_pSignalWindowWidget->GetInputChannel() != pChannel) {
            m_pSignalWindowWidget = NULL;
        }
    }

    BCRoomMainWidget *pRoomWidget = m_pGroupDisplayWidget->GetRoomWidget();
    if ( m_bLocationDisplay ) {
        // 单屏位置
        int dLeft = qRound(m_pGroupDisplayWidget->GetMGroupDisplay()->GetGroupDisplaySize().width() * singleDisplayRelationRect.left());
        int dTop = qRound(m_pGroupDisplayWidget->GetMGroupDisplay()->GetGroupDisplaySize().height() * singleDisplayRelationRect.top());
        int dWidth = qRound(m_pGroupDisplayWidget->GetMGroupDisplay()->GetGroupDisplaySize().width() * singleDisplayRelationRect.width());
        int dHeight = qRound(m_pGroupDisplayWidget->GetMGroupDisplay()->GetGroupDisplaySize().height() * singleDisplayRelationRect.height());

        if ( BCCommon::g_bConnectWithServer ) {
            BCCommunication *pCommunication = BCCommunication::Application();
            if (NULL == m_pSignalWindowWidget) {
                pCommunication->Winsize(m_pGroupDisplayWidget->GetMGroupDisplay()->GetGroupDisplayID(), m_pSignalWindowWidget->GetInputChannel()->GetChannelID(), pRoomWidget->CreateWindowID(pChannel),
                                        dLeft, dTop, dLeft+dWidth, dTop+dHeight, m_pSignalWindowWidget->GetInputChannel()->GetChannelType(), m_pSignalWindowWidget->GetInputChannel()->getCopyIndex());
            } else {
                pCommunication->Winsize(m_pGroupDisplayWidget->GetMGroupDisplay()->GetGroupDisplayID(), pChannel->GetChannelID(), m_pSignalWindowWidget->GetWindowID(),
                                        dLeft, dTop, dLeft+dWidth, dTop+dHeight, pChannel->GetChannelType(), pChannel->getCopyIndex());
            }
        } else {
            if (NULL == m_pSignalWindowWidget) {
                m_pSignalWindowWidget = pRoomWidget->AddSignalWindow(dLeft, dTop, dWidth, dHeight, m_pGroupDisplayWidget, pChannel);
            } else {
                m_pSignalWindowWidget->SetSignalWindowResize(dLeft, dTop, dWidth, dHeight);
            }
        }
    } else {
        QRectF rect = ui->m_pLocationWidget->GetHightRect();
        if ( rect.isEmpty() )
            return;

        // 单屏位置
        double dLeft = m_pGroupDisplayWidget->GetMGroupDisplay()->GetGroupDisplaySize().width() * singleDisplayRelationRect.left();
        double dTop = m_pGroupDisplayWidget->GetMGroupDisplay()->GetGroupDisplaySize().height() * singleDisplayRelationRect.top();
        double dWidth = m_pGroupDisplayWidget->GetMGroupDisplay()->GetGroupDisplaySize().width() * singleDisplayRelationRect.width();
        double dHeight = m_pGroupDisplayWidget->GetMGroupDisplay()->GetGroupDisplaySize().height() * singleDisplayRelationRect.height();

        // 单屏分割位置
        dLeft += dWidth * rect.left();
        dTop += dHeight * rect.top();
        dWidth *= rect.width();
        dHeight *= rect.height();

        if ( BCCommon::g_bConnectWithServer ) {
            BCCommunication *pCommunication = BCCommunication::Application();
            if (NULL == m_pSignalWindowWidget) {
                pCommunication->Winsize(m_pGroupDisplayWidget->GetMGroupDisplay()->GetGroupDisplayID(), pChannel->GetChannelID(), pRoomWidget->CreateWindowID(pChannel),
                                        dLeft, dTop, dLeft+dWidth, dTop+dHeight, pChannel->GetChannelType(), pChannel->getCopyIndex());
            } else {
                pCommunication->Winsize(m_pGroupDisplayWidget->GetMGroupDisplay()->GetGroupDisplayID(), m_pSignalWindowWidget->GetInputChannel()->GetChannelID(), m_pSignalWindowWidget->GetWindowID(),
                                        dLeft, dTop, dLeft+dWidth, dTop+dHeight, m_pSignalWindowWidget->GetInputChannel()->GetChannelType(), m_pSignalWindowWidget->GetInputChannel()->getCopyIndex());
            }
        } else {
            if (NULL == m_pSignalWindowWidget) {
                m_pSignalWindowWidget = pRoomWidget->AddSignalWindow(dLeft, dTop, dWidth, dHeight, m_pGroupDisplayWidget, pChannel);
            } else {
                m_pSignalWindowWidget->SetSignalWindowResize(dLeft, dTop, dWidth, dHeight);
            }
        }
    }
}

void BCLocationDlg::on_m_pRadioBtn1_clicked()
{
    ui->m_pLocationWidget->ReBuildLocationWidget(1, 1);

    if (NULL != m_pGroupDisplayWidget)
        m_pGroupDisplayWidget->RefreshSegmentation( 1 );
}

void BCLocationDlg::on_m_pRadioBtn4_clicked()
{
    ui->m_pLocationWidget->ReBuildLocationWidget(2, 2);

    if (NULL != m_pGroupDisplayWidget)
        m_pGroupDisplayWidget->RefreshSegmentation( 4 );
}

void BCLocationDlg::on_m_pRadioBtn6_clicked()
{
    ui->m_pLocationWidget->ReBuildLocationWidget(2, 3);

    if (NULL != m_pGroupDisplayWidget)
        m_pGroupDisplayWidget->RefreshSegmentation( 6 );
}

void BCLocationDlg::on_m_pRadioBtn8_clicked()
{
    ui->m_pLocationWidget->ReBuildLocationWidget(2, 4);

    if (NULL != m_pGroupDisplayWidget)
        m_pGroupDisplayWidget->RefreshSegmentation( 8 );
}

void BCLocationDlg::on_m_pRadioBtn9_clicked()
{
    ui->m_pLocationWidget->ReBuildLocationWidget(3, 3);

    if (NULL != m_pGroupDisplayWidget)
        m_pGroupDisplayWidget->RefreshSegmentation( 9 );
}

void BCLocationDlg::on_m_pRadioBtn12_clicked()
{
    ui->m_pLocationWidget->ReBuildLocationWidget(3, 4);

    if (NULL != m_pGroupDisplayWidget)
        m_pGroupDisplayWidget->RefreshSegmentation( 12 );
}

void BCLocationDlg::on_m_pRadioBtn16_clicked()
{
    ui->m_pLocationWidget->ReBuildLocationWidget(4, 4);

    if (NULL != m_pGroupDisplayWidget)
        m_pGroupDisplayWidget->RefreshSegmentation( 16 );
}
