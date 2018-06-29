#include "BCSignalWindowDisplayWidget.h"
#include "ui_BCSignalWindowDisplayWidget.h"
#include <float.h>
#include <QAction>
#include <QMenu>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "BCToolBar.h"
#include "BCRibbonMainToolBarAction.h"
#include "../Common/BCCommunication.h"
#include "../Common/BCLocalServer.h"
#include "../Model/BCMChannel.h"
#include "../Model/BCMGroupDisplay.h"
#include "../Model/BCMRoom.h"
#include "../Model/BCMDisplay.h"
#include "../Setting/BCSettingSignalWindowPropertyDlg.h"
#include "../Setting/BCSettingCutInputChannelDlg.h"
#include "../Player/BCVedioManager.h"
#include "BCFaceWidget.h"
#include "BCRoomWidget.h"
#include "BCGroupDisplayWidget.h"
#include "BCSingleDisplayVirtualWidget.h"
#include "../Setting/BCSettingIPVSignalWindowLoopConfigDlg.h"
#include "../Setting/BCSettingChannelRemoteIPDlg.h"
#include "BCDecoder.h"
#include "../Model/BCMSubTitlesScene.h"
#include "../Common/BCCommon.h"

BCSignalWindowIPVWidget::BCSignalWindowIPVWidget(int index, BCSignalWindowDisplayWidget *pSigWindow, QWidget *parent)
    :QWidget(parent)
{
    this->setAcceptDrops( true );

    m_parent = pSigWindow;
    m_nIndex = index;
    this->show();
}

BCSignalWindowIPVWidget::~BCSignalWindowIPVWidget()
{

}

void BCSignalWindowIPVWidget::SetURL(const QString &url)
{
    if ( url.isEmpty() )
        return;

    m_qsUrl = url;
    this->setToolTip(m_qsUrl);

    // 根据URL查找Name
    MainWindow *pApplication = BCCommon::Application();
    BCToolBar *pToolBar = pApplication->GetToolBar(MainWindow::SIGNALSOURCETOOLBAR);
    if (NULL != pToolBar) {
        BCFaceWidget *pSignalSourceWidget = dynamic_cast<BCFaceWidget *>( pToolBar->widget() );
        if (NULL != pSignalSourceWidget) {
            BCDecoder *pDecoderWidget = dynamic_cast<BCDecoder *>(pSignalSourceWidget->GetWidget(MainWindow::DECODERSIGSRC));
            if(NULL != pDecoderWidget) {
                QList<sIPInfo> lstIP = pDecoderWidget->GetIPList();
                for (int i = 0; i < lstIP.count(); i++) {
                    sIPInfo sip = lstIP.at( i );
                    if (sip.url == m_qsUrl) {
                        m_qsName = sip.name;
                        break;
                    }
                }
            }
        }
    }

    this->repaint();
}

void BCSignalWindowIPVWidget::SendIPVedioListCmd()
{
    // 找到输入通道的数据类
    BCMChannel *pChannel = m_parent->GetInputChannel();
    if (NULL == pChannel)
        return;

    int winid = m_parent->GetWindowID();
    int chid = pChannel->GetChannelID();
    int nIPVSegmentation = m_parent->GetIPVedioSegmentationCount();

    if ( BCCommon::g_bConnectWithServer ) {
        BCCommunication *pCommunication = BCCommunication::Application();
        pCommunication->SetIPVedioCurrentIP(chid, winid, nIPVSegmentation, m_nIndex, m_qsUrl, pChannel->GetBoardCardID(), pChannel->GetBoardCardPos());
    } else {
        BCLocalServer *pServer = BCLocalServer::Application();

        QStringList lstPara = m_qsResolution.split("*");
        if (lstPara.count() == 2) {
            pServer->SetIPVedioCurrentIP(chid, winid, nIPVSegmentation, m_nIndex, m_qsUrl,
                                         pChannel->GetBoardCardID(), pChannel->GetBoardCardPos(), m_qsDecoder.contains("H264")?96:265,
                                         lstPara.first().toInt(), lstPara.last().toInt());
        }

    }

    // 刷新最后一次的位置
    m_parent->RefreshLastIpvIP(m_nIndex, m_qsUrl);
}

//拖拽事件
void BCSignalWindowIPVWidget::dragEnterEvent(QDragEnterEvent* event)
{
    if (event->mimeData()->hasFormat("IPVedioData"))
       event->accept();
    else
       event->ignore();
}

void BCSignalWindowIPVWidget::dropEvent(QDropEvent *e)
{
    if (e->mimeData()->hasFormat("IPVedioData")) {
        // 可用于接收拖拽参数
        const QMimeData *mimeData = e->mimeData();
        QByteArray exData = mimeData->data("IPVedioData");
        QDataStream dataStream (&exData, QIODevice::ReadOnly);
        QStringList lstData;

        dataStream >> lstData;

        // 拖拽数据44成对、依次排列，分别为name, ip, decoder, resolution
        int nInputCount = lstData.count();
        if (nInputCount%4 != 0)
            return;

        m_qsName = lstData.at( 0 );
        m_qsUrl = lstData.at( 1 );
        m_qsDecoder = lstData.at( 2 );
        m_qsResolution = lstData.at( 3 );

        // 设置tooptip，并刷新界面背景色显示
        this->setToolTip(m_qsUrl);
        this->update();

        SendIPVedioListCmd();

        e->accept();
    } else {
        e->ignore();
    }
}

void BCSignalWindowIPVWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // 设置边框
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine));

    // 绘制整体
    if (!m_parent->IsEcho() && !m_qsUrl.isEmpty()) {
        painter.setBrush( QBrush(QColor(255, 174, 201, 125)));
    }

    QRect rect = this->rect();

    // 绘制矩形
    painter.drawRect( QRectF(rect.left(), rect.top(), rect.width()-1, rect.height()-1) );

    // 绘制文字
    if (!m_qsName.isEmpty() && !m_qsUrl.isEmpty()) {
        QFont font = painter.font();
        font.setFamily("微软雅黑");
        painter.setFont(font);
        painter.drawText(rect, Qt::AlignCenter, m_qsName);
    }
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------

BCSignalWindowDisplayWidget::BCSignalWindowDisplayWidget(BCGroupDisplayWidget *pGroupDisplayWidget, int x, int y, int w, int h, BCMChannel *pChannel, int winid, BCRoomMainWidget *pSignalWindowMgr, bool bSendCmd) :
    QWidget(pSignalWindowMgr),
    ui(new Ui::BCSignalWindowDisplayWidget)
{
    // 是否远程控制，事件里判断是否远程控制，那时候还没有加载UI控件
    m_bRemote = false;

    ui->setupUi(this);

    setAttribute(Qt::WA_Hover, true);
    //this->setMouseTracking( true );
    m_eResizePos = UNRESIZE;

    m_rectFact = QRect(x, y, w, h);
    // 信号窗管理类
    m_pSignalWindowMgr = pSignalWindowMgr;
    // 记录归属组别
    m_pGroupDisplayWidget = pGroupDisplayWidget;
    // 记录输入通道
    m_pInputChannel = pChannel;
    m_nWindowID = winid;
    m_nCopyIndex = pChannel->getCopyIndex();    // 则设置复制窗口的索引

    // 默认不加锁，可以移动和缩放
    m_bLock = false;
    // 记录是否是全屏状态
    m_bFullScene = false;
    // 回显开关
    m_bEcho = false;
    // 透明度
    m_transparent = 200;

    // IPV需要创建timer
    m_nIPVLoopInterval = 3;
    if (9 == m_pInputChannel->GetSignalSource()) {
        m_pIPVLoopTimer = new QTimer( this );
        m_pIPVLoopTimer->setInterval( m_nIPVLoopInterval*1000 );
        connect(m_pIPVLoopTimer, SIGNAL(timeout()), this, SLOT(onIPVTimeout()));
    } else {
        m_pIPVLoopTimer = NULL;
    }

    // 如果是IPV则显示矩形块
    ui->m_pGenaralBodyWidget->setVisible( 9 == m_pInputChannel->GetSignalSource() ? false : true );
    ui->m_pIPVBodyWidget->setVisible( 9 == m_pInputChannel->GetSignalSource() ? true : false );

    // 鼠标移动时共有属性
    m_x = 0.0;
    m_y = 0.0;
    m_bPress = false;

    ui->m_pLockBtn->setIcon(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowTitleUnLockButtonImagePath));
    ui->m_pCloseBtn->setIcon(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowTitleCloseButtonImagePath));

    // 全屏和恢复合并成一个按钮，默认显示全屏
    QString qsFullscreenPath = BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+(m_bFullScene?BCCommon::g_qsSignalWindowTitleUnFullScreenButtonImagePath:BCCommon::g_qsSignalWindowTitleFullScreenButtonImagePath);
    ui->m_pFullscreenBtn->setIcon(QIcon(qsFullscreenPath));
    ui->m_pWindowShowBtn->setVisible( false );

    MainWindow *pMainWindow = BCCommon::Application();
    if (pMainWindow->GetCurrentUser()->level > 2) {
        ui->m_pLockBtn->setVisible( false );
    }

    // set ipv segment
    m_nIPVSegmentation = m_pInputChannel->GetChannelLastSegmentation( m_pGroupDisplayWidget->GetMGroupDisplay() );
    SetIPVedioSegmentationCount(m_nIPVSegmentation, false);

    // 根据给定的位置比例重置矩形
    QRect virRect = m_pSignalWindowMgr->MapToVirtualRect(x, y, w, h);
    ResizeRect(virRect.left(), virRect.top(), virRect.width(), virRect.height(), bSendCmd, false, false);   // 使用实际坐标值

    // for remote service
    QString qsRemoteIcon = m_bRemote?"remoteon16.png":"remoteoff16.png";
    ui->m_pRemoteBtn->setIcon(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+qsRemoteIcon));

    // 全局判断是否显示穿透功能
    ui->m_pRemoteBtn->setVisible( BCCommon::g_bContainsRemote );

    // 刷新字幕设置按钮
    RefreshSubTitle();

    // 矩阵模式下不可以修改窗口尺寸
    if (4 == m_pSignalWindowMgr->GetMRoom()->GetType()) {
        setAttribute(Qt::WA_Hover, false);
        ui->m_pLockBtn->setVisible( false );
        ui->m_pFullscreenBtn->setVisible( false );
        ui->m_pWindowShowBtn->setVisible( false );
        ui->m_pRemoteBtn->setVisible( false );
        ui->m_pSubTitleLabel->setVisible( false );
    }

    // 淡入效果
    //QTimer::singleShot(10, this, SLOT(onConstructionTimeout()));
}

BCSignalWindowDisplayWidget::~BCSignalWindowDisplayWidget()
{
    qDebug() << "BCSignalWindowDisplayWidget::~BCSignalWindowDisplayWidget()";

    // 如果是回显状态则关闭回显
    if ( m_bEcho ) {
        this->SetEcho( false );
    }

    if (NULL != m_pIPVLoopTimer) {
        m_pIPVLoopTimer->stop();
        m_pIPVLoopTimer->deleteLater();
    }

    delete ui;
}

void BCSignalWindowDisplayWidget::onConstructionTimeout()
{
    m_transparent = m_transparent+5;
    if (m_transparent >= 220)
        m_transparent = 220;
    else
        QTimer::singleShot(10, this, SLOT(onConstructionTimeout()));

    this->update();
}

//void BCSignalWindowDisplayWidget::closeEvent(QCloseEvent *e)
//{
//    // 淡出效果
//    QTimer::singleShot(10, this, SLOT(onDestructionTimeout()));
//    e->ignore();    // 添加为了保证不隐藏
//}

void BCSignalWindowDisplayWidget::onDestructionTimeout()
{
    m_transparent = m_transparent-5;
    if (m_transparent <= 0) {
        m_transparent = 0;
        this->deleteLater();
    } else
        QTimer::singleShot(10, this, SLOT(onDestructionTimeout()));

    this->repaint();
}

void BCSignalWindowDisplayWidget::RefreshSubTitle()
{
    QString qsSubTitleIcon = (1 == m_pInputChannel->GetSubTitles()->m_nVisible)?"subtitleon16.png":"subtitleoff16.png";
    ui->m_pSubTitleLabel->setPixmap( QPixmap(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+qsSubTitleIcon) );
}

void BCSignalWindowDisplayWidget::ResizeRectBySorption()
{
    if (!BCCommon::g_bOpenSignalWindowSorption || m_bLock)
        return;

    QPoint ptLT = this->mapTo(m_pSignalWindowMgr, this->rect().topLeft());
    QPoint ptRB = this->mapTo(m_pSignalWindowMgr, QPoint(this->rect().left()+this->rect().width(), this->rect().top()+this->rect().height()));

    // 记录四个边界，scene坐标
    int dSorptionL = ptLT.x();
    int dSorptionT = ptLT.y();
    int dSorptionR = ptRB.x();
    int dSorptionB = ptRB.y();

    // 排列和分屏模式
    QSize roomArray = m_pSignalWindowMgr->GetRoomArray();
    int segX = 1;
    int segY = 1;
    switch ( m_pSignalWindowMgr->GetSegmentation() ) {
    case 1:
        break;
    case 4:
        segX = 2;
        segY = 2;
        break;
    case 6:
        segX = 3;
        segY = 2;
        break;
    case 8:
        segX = 4;
        segY = 2;
        break;
    case 9:
        segX = 3;
        segY = 3;
        break;
    case 12:
        segX = 4;
        segY = 3;
        break;
    case 16:
        segX = 4;
        segY = 4;
        break;
    default:
        break;
    }

    int virSingleWidth = m_pSignalWindowMgr->rect().width()/(roomArray.width()*segX);
    int virSingleHeight = m_pSignalWindowMgr->rect().height()/(roomArray.height()*segY);
    for (int i = 0; i < roomArray.width()*segX; i++) {
        for (int j = 0; j < roomArray.height()*segY; j++) {
            QRectF virRect = QRectF(virSingleWidth*i, virSingleHeight*j, virSingleWidth, virSingleHeight);

            // 外扩
            dSorptionL = ((dSorptionL > virRect.left()) && (dSorptionL < virRect.left()+BCCommon::g_nSignalWindowSorptionWidth)) ? virRect.left() : dSorptionL;
            dSorptionL = ((dSorptionL > virRect.left()+virRect.width()) && (dSorptionL < virRect.left()+virRect.width()+BCCommon::g_nSignalWindowSorptionWidth)) ? virRect.left()+virRect.width() : dSorptionL;
            dSorptionR = ((dSorptionR < virRect.left()) && (dSorptionR > virRect.left()-BCCommon::g_nSignalWindowSorptionWidth)) ? virRect.left() : dSorptionR;
            dSorptionR = ((dSorptionR < virRect.left()+virRect.width()) && (dSorptionR > virRect.left()+virRect.width()-BCCommon::g_nSignalWindowSorptionWidth)) ? virRect.left()+virRect.width() : dSorptionR;
            dSorptionT = ((dSorptionT > virRect.top()) && (dSorptionT < virRect.top()+BCCommon::g_nSignalWindowSorptionWidth)) ? virRect.top() : dSorptionT;
            dSorptionT = ((dSorptionT > virRect.top()+virRect.height()) && (dSorptionT < virRect.top()+virRect.height()+BCCommon::g_nSignalWindowSorptionWidth)) ? virRect.top()+virRect.height() : dSorptionT;
            dSorptionB = ((dSorptionB < virRect.top()) && (dSorptionB > virRect.top()-BCCommon::g_nSignalWindowSorptionWidth)) ? virRect.top() : dSorptionB;
            dSorptionB = ((dSorptionB < virRect.top()+virRect.height()) && (dSorptionB > virRect.top()+virRect.height()-BCCommon::g_nSignalWindowSorptionWidth)) ? virRect.top()+virRect.height() : dSorptionB;

            // 内缩
            dSorptionL = ((dSorptionL < virRect.left()) && (dSorptionL > virRect.left()-BCCommon::g_nSignalWindowSorptionWidth)) ? virRect.left() : dSorptionL;
            dSorptionL = ((dSorptionL < virRect.left()+virRect.width()) && (dSorptionL > virRect.left()+virRect.width()-BCCommon::g_nSignalWindowSorptionWidth)) ? virRect.left()+virRect.width() : dSorptionL;
            dSorptionR = ((dSorptionR > virRect.left()) && (dSorptionR < virRect.left()+BCCommon::g_nSignalWindowSorptionWidth)) ? virRect.left() : dSorptionR;
            dSorptionR = ((dSorptionR > virRect.left()+virRect.width()) && (dSorptionR < virRect.left()+virRect.width()+BCCommon::g_nSignalWindowSorptionWidth)) ? virRect.left()+virRect.width() : dSorptionR;
            dSorptionT = ((dSorptionT < virRect.top()) && (dSorptionT > virRect.top()-BCCommon::g_nSignalWindowSorptionWidth)) ? virRect.top() : dSorptionT;
            dSorptionT = ((dSorptionT < virRect.top()+virRect.height()) && (dSorptionT > virRect.top()+virRect.height()-BCCommon::g_nSignalWindowSorptionWidth)) ? virRect.top()+virRect.height() : dSorptionT;
            dSorptionB = ((dSorptionB > virRect.top()) && (dSorptionB < virRect.top()+BCCommon::g_nSignalWindowSorptionWidth)) ? virRect.top() : dSorptionB;
            dSorptionB = ((dSorptionB > virRect.top()+virRect.height()) && (dSorptionB < virRect.top()+virRect.height()+BCCommon::g_nSignalWindowSorptionWidth)) ? virRect.top()+virRect.height() : dSorptionB;
        }
    }

    // 如果没有进行吸附，则宽度高度取当前尺寸，不进行转换，否则可能会有1像素的误差
    if ((dSorptionL == ptLT.x()) && (dSorptionT == ptLT.y()) && (dSorptionR == ptRB.x()) && (dSorptionB == ptRB.y())) {
        ResizeRect(dSorptionL, dSorptionT, this->rect().width(), this->rect().height(), true, true);
    } else {
        ResizeRect(dSorptionL, dSorptionT, dSorptionR-dSorptionL, dSorptionB-dSorptionT, true, true);
    }
}

void BCSignalWindowDisplayWidget::ResizeRect(int x, int y, int w, int h, bool bSendCmd, bool bReSend, bool bMapToFact)
{
    // 数据不合法直接返回
    if ((x==0) && (y==0) && (w==0) && (h==0))
        return;

    // 转换成实际坐标
    if (bSendCmd && bMapToFact) {
        m_rectFact = m_pSignalWindowMgr->MapToFactRect(x, y, w, h);
    }

    // 预布局则不发送指令
    if ( m_pSignalWindowMgr->IsFloorPlanningSwitch() ) {
        bSendCmd = false;
    }

    bool bUpdateEcho = false;   // 只有当尺寸变化时才更新预监回显
    if ( !BCCommon::g_bConnectWithServer ) {    // 单机直接修改位置
        bUpdateEcho = ((this->size().width() != w) || (this->size().height() != h)) ? true : false;
        this->resize(w, h);
        this->move(x, y);
    } else if ( !bSendCmd ) {   // 服务器如果不发送指令可以直接移动位置
        this->resize(w, h);
        this->move(x, y);
    }

    // 刷新IPV窗口
    SetIPVedioSegmentationCount(m_nIPVSegmentation, false);

    // 刷新文字显示
    RefreshTextDisplay();

    // winsize通讯，吸附时最后一次坐标连续发送，以防指令丢失
    if ( bSendCmd ) {
        int nSendCount = bReSend ? 2 : 1;
        for (int i = 0; i < nSendCount; i++) {
            if ( bReSend ) {
                if (0 == BCCommon::g_nDeviceType) {     // vp2000间隔250ms
                    QThread::msleep( 250 );
                }
            }

            Winsize( bUpdateEcho );
        }

        // 记录输入通道当前屏组上次开窗位置
        m_pInputChannel->SetChannelLastRect(m_pGroupDisplayWidget->GetMGroupDisplay(), QRectF(m_rectFact));
    }
}

void BCSignalWindowDisplayWidget::RefreshTextDisplay()
{
    // 修改header
    ui->m_pWindowTitleLabel->setText( m_pInputChannel->GetChannelBaseName()+m_pInputChannel->GetChannelName() );
    //ui->m_pWindowTitleLabel->setText( m_pInputChannel->GetChannelBaseName());//改变信号窗标题，去中文

    // 修改body
    QString qsWindowFlag = QObject::tr("窗口标识");
    QString qsWindowSignalSource = QObject::tr("信号源");
    ui->m_pWindowFlagLabel->setText(
                QString("%1:%2\r\n%3:%4")
                .arg(qsWindowFlag).arg( m_nWindowID+1 )
                .arg(qsWindowSignalSource).arg( m_pInputChannel->GetChannelID()+1 ) );
}

void BCSignalWindowDisplayWidget::SetLock(bool bLock)
{
    m_bLock = bLock;

    // 刷新图标
    QString qsIconPath = m_bLock ? BCCommon::g_qsSignalWindowTitleLockButtonImagePath : BCCommon::g_qsSignalWindowTitleUnLockButtonImagePath;
    ui->m_pLockBtn->setIcon( QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+qsIconPath) );
}

void BCSignalWindowDisplayWidget::SetFullScene(bool b)
{
    if ( m_bLock )
        return;

    // 赋值状态值
    m_bFullScene = b;
    if ( m_bFullScene ) {
        // 记录窗口尺寸
        m_rectBeforeFullScene = QRect(this->mapTo(m_pSignalWindowMgr, this->rect().topLeft()),
                                      this->mapTo(m_pSignalWindowMgr, this->rect().bottomRight()));
        QRectF rect = m_pSignalWindowMgr->rect();

        ResizeRect(rect.left(), rect.top(), rect.width(), rect.height(), true);
    } else {
        ResizeRect(m_rectBeforeFullScene.x(), m_rectBeforeFullScene.y(), m_rectBeforeFullScene.width(), m_rectBeforeFullScene.height(), true);
    }

    m_pSignalWindowMgr->SetSignalWindowTop( this );
}
// 缩放到单屏
void BCSignalWindowDisplayWidget::ScaleToSingleDisplay()
{
    if ( m_bLock )
        return;

    // 窗口左上角对应的虚拟矩形
    QPoint ptLT = this->mapTo(m_pSignalWindowMgr, this->rect().topLeft());

    // 外扩吸附值包含的矩形块
    QList<BCSingleDisplayVirtualWidget *> lstSorption = m_pSignalWindowMgr->GetSingleDisplayVirtualWidget();

    // 当外扩和内缩同时满足时，取外扩矩形
    QListIterator<BCSingleDisplayVirtualWidget *> it( lstSorption );
    while ( it.hasNext() ) {
        BCSingleDisplayVirtualWidget *pItem = it.next();

        // 虚拟矩形的尺寸
        QPoint virLT = pItem->mapTo(m_pSignalWindowMgr, pItem->rect().topLeft());
        //QPoint virRB = pItem->mapTo(m_pSignalWindowMgr, pItem->rect().bottomRight());
        QPoint virRB = pItem->mapTo(m_pSignalWindowMgr, QPoint(pItem->rect().left()+pItem->rect().width(), pItem->rect().top()+pItem->rect().height()));
        QRectF virRect = QRect(virLT, virRB);

        // 矩形框包含左上角继续
        if ( !virRect.contains( ptLT ) )
            continue;

        // 重置信号窗
        ResizeRect(virRect.x(), virRect.y(), virRect.width(), virRect.height(), true);

        break;
    }
}

// 缩放到所占屏（铺满当前屏）
void BCSignalWindowDisplayWidget::ScaleToOverlapDisplay()
{
    if ( m_bLock )
        return;

    // 窗口左上角对应的虚拟矩形
    QPoint ptLT = this->mapTo(m_pSignalWindowMgr, this->rect().topLeft());
    QPoint ptRB = this->mapTo(m_pSignalWindowMgr, this->rect().bottomRight());
    QRect sigRect(ptLT, ptRB);

    // 排列和分屏模式
    QSize roomArray = m_pSignalWindowMgr->GetRoomArray();
    int segX = 1;
    int segY = 1;
    switch ( m_pSignalWindowMgr->GetSegmentation() ) {
    case 1:
        break;
    case 4:
        segX = 2;
        segY = 2;
        break;
    case 6:
        segX = 3;
        segY = 2;
        break;
    case 8:
        segX = 4;
        segY = 2;
        break;
    case 9:
        segX = 3;
        segY = 3;
        break;
    case 12:
        segX = 4;
        segY = 3;
        break;
    case 16:
        segX = 4;
        segY = 4;
        break;
    default:
        break;
    }

    QList<QRect> lstSorption;
    int virSingleWidth = m_pSignalWindowMgr->rect().width()/(roomArray.width()*segX);
    int virSingleHeight = m_pSignalWindowMgr->rect().height()/(roomArray.height()*segY);
    for (int i = 0; i < roomArray.width()*segX; i++) {
        for (int j = 0; j < roomArray.height()*segY; j++) {
            lstSorption.append( QRect(virSingleWidth*i, virSingleHeight*j, virSingleWidth, virSingleHeight) );
        }
    }

    // 记录边界值
    double dL = DBL_MAX;
    double dR = DBL_MIN;
    double dT = DBL_MAX;
    double dB = DBL_MIN;

    // 当外扩和内缩同时满足时，取外扩矩形
    for (int i = 0; i < lstSorption.count(); i++) {
        QRect virRect = lstSorption.at( i );

        // 矩形框包含左上角继续
        if ( !sigRect.intersects( virRect ) )
            continue;

        dL = dL < virRect.left() ? dL : virRect.left();
        dR = dR > virRect.left()+virRect.width() ? dR : virRect.left()+virRect.width();
        dT = dT < virRect.top() ? dT : virRect.top();
        dB = dB > virRect.top()+virRect.height() ? dB : virRect.top()+virRect.height();
    }

    // 重置信号窗
    ResizeRect(dL, dT, dR-dL, dB-dT, true);
}

void BCSignalWindowDisplayWidget::RefreshEchoStatus(bool bTempCloseEcho)
{
    if ( bTempCloseEcho ) {
        if ( !m_bEcho ) {
            return;
        } else {
            SetEcho( false );
            m_bEcho = true;
        }
    } else {
        if ( !m_bEcho ) {
            return;
        } else {
            m_bEcho = false;
            SetEcho( true );
            m_bEcho = true;
        }
    }
}

void BCSignalWindowDisplayWidget::SetEcho(bool b)
{
    // 如果回显状态没有变化则直接返回
    if (m_bEcho == b)
        return;

    m_bEcho = b;

    BCVedioManager *pVideoMgr = BCVedioManager::Application();
    if( m_bEcho ) {
        // 如果是IPV则显示矩形块
        pVideoMgr->AddEcho((HWND)ui->m_pBodyWidget->winId(), m_pInputChannel->GetChannelID(), 0, 0, this->rect().width(), this->rect().height());
        ui->m_pBodyWidget->setUpdatesEnabled( false );
    } else {
        ui->m_pBodyWidget->setUpdatesEnabled( true );
        pVideoMgr->RemoveEcho((HWND)ui->m_pBodyWidget->winId());
    }
}

void BCSignalWindowDisplayWidget::SetSignalPosition(int type)
{
    bool bRes = false;
    switch (type) {
    case 0:
        bRes = m_pSignalWindowMgr->SetSignalWindowTop( this );
        break;
    case 1:
        bRes = m_pSignalWindowMgr->SetSignalWindowBottom( this );
        break;
    case 2:
        bRes = m_pSignalWindowMgr->SetSignalWindowMoveToTop( this );
        break;
    case 3:
        bRes = m_pSignalWindowMgr->SetSignalWindowMoveToBottom( this );
        break;
    case 4:
        bRes = m_pSignalWindowMgr->RemoveSignalWindowDisplayItem( this );
        break;
    default:
        break;
    }

    // 刷新内部信号窗文字显示，主要是叠放次序，如果叠放次序没有变化则没有必要刷新
    if ( bRes ) {
        m_pSignalWindowMgr->RefreshSignalWindowTextDisplay();
    }
}

void BCSignalWindowDisplayWidget::SetInputChannel(BCMChannel *pChannel)
{
    // 如果通道没有变化则直接返回
    if (pChannel == m_pInputChannel)
        return;

//    int chid = m_pInputChannel->GetChannelID();
//    int chType = m_pInputChannel->GetChannelType();

    // 重新赋值输入通道，并刷新内部显示
    m_pInputChannel->RemoveSignalWindowDisplayWidget( this );
    m_pInputChannel = pChannel;
    m_pInputChannel->AddSignalWindowDisplayWidget( this );
    RefreshTextDisplay();

    // 发送一次指令
    Winsize( true );

    // ??? 暂时置顶，硬件支持后去掉
    SetSignalPosition( 0 );

    // 如果是回显状态，则需要重新刷新下视频
    if ( m_bEcho ) {
        SetEcho( false );
        SetEcho( true );
    }
}

void BCSignalWindowDisplayWidget::Winsize(bool bUpdateEcho)
{
    if ((NULL == m_pGroupDisplayWidget) || (NULL == m_pInputChannel))
        return;

    // 切换矩阵这里是空
    BCMGroupDisplay *pMGroupDisplay = m_pGroupDisplayWidget->GetMGroupDisplay();
    if (NULL == pMGroupDisplay)
        return;

    int groupid = pMGroupDisplay->GetGroupDisplayID();

    // 和服务器通讯
    if ( BCCommon::g_bConnectWithServer ) {
        BCCommunication *pCommunication = BCCommunication::Application();
        pCommunication->Winsize(groupid, m_pInputChannel->GetChannelID(), m_nWindowID, m_rectFact.left(), m_rectFact.top(), m_rectFact.left()+m_rectFact.width(), m_rectFact.top()+m_rectFact.height(), m_pInputChannel->GetChannelType(), m_nCopyIndex);
    } else {
        // 打开预监回显，否则移动会出现串图像情况
        MainWindow *pMainWindow = BCCommon::Application();
        pMainWindow->SetPreviewDeviceSwitch( true );

        BCLocalServer *pServer = BCLocalServer::Application();
        pServer->winsize(groupid, m_pInputChannel->GetChannelID(), m_nWindowID, m_rectFact.left(), m_rectFact.top(), m_rectFact.left()+m_rectFact.width(), m_rectFact.top()+m_rectFact.height(), m_pInputChannel->GetChannelType(), m_nCopyIndex);
    }

    // 更新回显单元
    if(m_bEcho && bUpdateEcho) {
        BCVedioManager *pVideoMgr = BCVedioManager::Application();
        pVideoMgr->UpdateEcho((HWND)ui->m_pBodyWidget->winId(), 0, 0, this->rect().width(), this->rect().height());
    }
}

void BCSignalWindowDisplayWidget::SetSignalWindowProperty()
{
    BCSettingSignalWindowPropertyDlg *pDlg = new BCSettingSignalWindowPropertyDlg(this, BCCommon::Application());
    pDlg->exec();
}

void BCSignalWindowDisplayWidget::SetSignalWindowTitle(const QString &title)
{
    QString qsChannelSrcName = m_pInputChannel->GetChannelName();
    if (qsChannelSrcName != title) {
        m_pInputChannel->SetChannelName(title, true);

        // 通知工具栏刷新
        MainWindow *pApplication = BCCommon::Application();
        BCToolBar *pToolBar = pApplication->GetToolBar(MainWindow::SIGNALSOURCETOOLBAR);
        if (NULL != pToolBar) {
            BCFaceWidget* pWidget = dynamic_cast<BCFaceWidget *>( pToolBar->widget() );
            if (NULL != pWidget) {
                pWidget->Refresh( 0 );
            }
        }
    }

    ui->m_pWindowTitleLabel->setText(  m_pInputChannel->GetChannelBaseName()+title );
}

QString BCSignalWindowDisplayWidget::GetSignalWindowTitle()
{
    return ui->m_pWindowTitleLabel->text();
}

void BCSignalWindowDisplayWidget::SetSignalWindowResize(int x, int y, int w, int h, bool bSendCmd)
{
    m_rectFact = QRect(x, y, w, h);

    QRect virRect = m_pSignalWindowMgr->MapToVirtualRect(x, y, w, h);
    ResizeRect(virRect.x(), virRect.y(), virRect.width(), virRect.height(), bSendCmd, false, false);
}

void BCSignalWindowDisplayWidget::contextMenuEvent(QContextMenuEvent *e)
{
    // 穿透情况下不显示菜单
    if ( m_bRemote )
        return;

    // 矩阵不显示菜单
    if (4 == m_pSignalWindowMgr->GetMRoom()->GetType())
        return;

    // 构造菜单
    QMenu menu;
    BCCommon::SetSystemFont( &menu );

    QAction *pRapidWindowAction = menu.addAction(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionLocationIconPath), QObject::tr("快速定位"));

    QAction *pEchoAction = NULL;
    QAction *pCutChannelAction = NULL;
    // 回显为主工具条统一控制，窗口不单独添加开关
//    if ( BCCommon::g_bEchoModel ) {
//        pEchoAction = menu.addAction(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionEchoIconPath), QObject::tr("是否回显"));
//        pEchoAction->setCheckable( true );
//        pEchoAction->setChecked( m_bEcho );
//    }
    QAction *pChannelRemoteAction = NULL;
    if ( BCCommon::g_bContainsRemote ) {    // 全局变量控制是否显示穿透
        pChannelRemoteAction = menu.addAction(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/remoteconfig16.png"), QObject::tr("穿透IP"));
    }
    if ((m_pInputChannel->GetChannelType() == 0) || (m_pInputChannel->GetChannelType() == 3)) {
        MainWindow *pMainWindow = BCCommon::Application();
        if (pMainWindow->GetCurrentUser()->level < 3) {
            pCutChannelAction = menu.addAction(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionCutIconPath), QObject::tr("裁剪"));
        }
    }

    // 权限控制
    QAction *pSetTop = NULL;
    QAction *pSetBottom = NULL;
    QAction *pLock = NULL;
    MainWindow *pMainWindow = BCCommon::Application();
    if (pMainWindow->GetCurrentUser()->level < 3) {
        pSetTop = menu.addAction(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionTopIconPath), QObject::tr("置顶"));
        pSetBottom = menu.addAction(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionBottomIconPath), QObject::tr("置底"));
        pLock = menu.addAction(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionLockIconPath), QObject::tr("锁定位置"));
        pLock->setCheckable( true );
        pLock->setChecked( m_bLock );
    }
    QAction *pScaleToSingleDisplay = menu.addAction(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionScaleToSingleDisplayIconPath), QObject::tr("缩放到子屏"));
    QAction *pScaleToOverlapDisplay = menu.addAction(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionScaleToOverlapDisplayIconPath), QObject::tr("铺满当前屏"));
    QAction *pScaleToGroupDisplay = menu.addAction(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionScaleToAllDisplayIconPath), QObject::tr("铺满所有屏"));

    // ipv需要添加右键菜单
    QMenu ipvMenu;
    QMenu ipvLoopMenu;
    QAction *pIPVedioSegmentation1 = NULL;
    QAction *pIPVedioSegmentation4 = NULL;
    QAction *pIPVedioSegmentation6 = NULL;
    QAction *pIPVedioSegmentation8 = NULL;
    QAction *pIPVedioSegmentation9 = NULL;
    QAction *pIPVedioSegmentation12 = NULL;
    QAction *pIPVedioSegmentation16 = NULL;
    QAction *pIPVedioSegmentation25 = NULL;
    QAction *pIPVedioSegmentation36 = NULL;
    QAction *pIPVedioLoopOn = NULL;
    QAction *pIPVedioLoopOff = NULL;
    QAction *pIPVedioLoopConfig = NULL;
    if (m_pInputChannel->GetSignalSource() == 9) {
        ipvMenu.setIcon(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionScaleToAllDisplayIconPath));
        ipvMenu.setTitle(QObject::tr("IPVideo分割模式"));
        pIPVedioSegmentation1 = ipvMenu.addAction(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionScaleToAllDisplayIconPath), QObject::tr("全屏"));
        pIPVedioSegmentation4 = ipvMenu.addAction(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionScaleToAllDisplayIconPath), QObject::tr("4分割"));
        pIPVedioSegmentation6 = ipvMenu.addAction(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionScaleToAllDisplayIconPath), QObject::tr("6分割"));
        pIPVedioSegmentation8 = ipvMenu.addAction(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionScaleToAllDisplayIconPath), QObject::tr("8分割"));
        pIPVedioSegmentation9 = ipvMenu.addAction(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionScaleToAllDisplayIconPath), QObject::tr("9分割"));
        pIPVedioSegmentation12 = ipvMenu.addAction(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionScaleToAllDisplayIconPath), QObject::tr("12分割"));
        pIPVedioSegmentation16 = ipvMenu.addAction(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionScaleToAllDisplayIconPath), QObject::tr("16分割"));
        pIPVedioSegmentation25 = ipvMenu.addAction(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionScaleToAllDisplayIconPath), QObject::tr("25分割"));
        pIPVedioSegmentation36 = ipvMenu.addAction(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionScaleToAllDisplayIconPath), QObject::tr("36分割"));

        menu.addMenu( &ipvMenu );

        ipvLoopMenu.setIcon(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionScaleToAllDisplayIconPath));
        ipvLoopMenu.setTitle(QObject::tr("IPVideo轮巡"));
        pIPVedioLoopOn = ipvLoopMenu.addAction(QObject::tr("打开轮巡"));
        pIPVedioLoopOff = ipvLoopMenu.addAction(QObject::tr("关闭轮巡"));
        pIPVedioLoopConfig = ipvLoopMenu.addAction(QObject::tr("配置"));
        menu.addMenu( &ipvLoopMenu );
    }
    QAction *pClose = menu.addAction(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionCloseIconPath), QObject::tr("关闭"));
    QAction *pAttribute = menu.addAction(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+BCCommon::g_qsSignalWindowMenuActionAttributeIconPath), QObject::tr("属性"));

    // 返回选择的action
    QAction *pSelectedAction = menu.exec( this->mapToGlobal(e->pos()) );
    if (NULL != pSelectedAction) {
        // 快速定位
        if (pSelectedAction == pRapidWindowAction) {
            MainWindow *pApplication = BCCommon::Application();
            BCRibbonMainToolBar *pMainToolBar = pApplication->GetRibbonMainToolBar();
            if (NULL != pMainToolBar) {
                BCRibbonMainToolBarAction *pLocationBtn = pMainToolBar->GetButtonAction( BCRibbonMainToolBar::LOCATION );
                if (NULL != pLocationBtn) {
                    pLocationBtn->RefreshAndShowLocationDlg();
                }
            }
        }
        // 回显
        if (pSelectedAction == pEchoAction) {
            // 当打开全局回显时，不可以关闭单个窗口，因为和临时关闭可能存在冲突
            MainWindow *pMainWindow = BCCommon::Application();
            if ( !pMainWindow->IsOpenAllSignalEcho() ) {
                SetEcho( !m_bEcho );
            }
        }
        // 裁剪
        if (pSelectedAction == pCutChannelAction) {
            SetCutArea();
        }
        // 置顶
        if (pSelectedAction == pSetTop) {
            SetSignalPosition(0);
        }
        // 置底
        if (pSelectedAction == pSetBottom) {
            SetSignalPosition(1);
        }
        // 锁定
        if (pSelectedAction == pLock) {
            SetLock( !m_bLock );
        }
        // 缩放到单屏
        if (pSelectedAction == pScaleToSingleDisplay) {
            ScaleToSingleDisplay();
        }
        // 缩放到所占屏（铺满当前屏）
        if (pSelectedAction == pScaleToOverlapDisplay) {
            ScaleToOverlapDisplay();
        }
        // 全屏
        if (pSelectedAction == pScaleToGroupDisplay) {
            SetFullScene( true );
        }
        // IPV1分割
        if (pSelectedAction == pIPVedioSegmentation1) {
            SetIPVedioSegmentationCount( 1 );
        }
        if (pSelectedAction == pIPVedioSegmentation4) {
            SetIPVedioSegmentationCount( 4 );
        }
        if (pSelectedAction == pIPVedioSegmentation6) {
            SetIPVedioSegmentationCount( 6 );
        }
        if (pSelectedAction == pIPVedioSegmentation8) {
            SetIPVedioSegmentationCount( 8 );
        }
        if (pSelectedAction == pIPVedioSegmentation9) {
            SetIPVedioSegmentationCount( 9 );
        }
        if (pSelectedAction == pIPVedioSegmentation12) {
            SetIPVedioSegmentationCount( 12 );
        }
        if (pSelectedAction == pIPVedioSegmentation16) {
            SetIPVedioSegmentationCount( 16 );
        }
        if (pSelectedAction == pIPVedioSegmentation25) {
            SetIPVedioSegmentationCount( 25 );
        }
        if (pSelectedAction == pIPVedioSegmentation36) {
            SetIPVedioSegmentationCount( 36 );
        }
        // IPV轮巡设置
        if (pSelectedAction == pIPVedioLoopOn) {
            if (NULL != m_pIPVLoopTimer) {
                m_pIPVLoopTimer->setInterval( m_nIPVLoopInterval*1000 );
                m_pIPVLoopTimer->start();
            }
        }
        if (pSelectedAction == pIPVedioLoopOff) {
            if (NULL != m_pIPVLoopTimer)
                m_pIPVLoopTimer->stop();
        }
        if (pSelectedAction == pIPVedioLoopConfig) {
            BCSettingIPVSignalWindowLoopConfigDlg *pDlg = new BCSettingIPVSignalWindowLoopConfigDlg( this );
            pDlg->exec();
        }
        // 关闭
        if (pSelectedAction == pClose) {
            SetSignalPosition( 4 );
        }
        // 属性
        if (pSelectedAction == pAttribute) {
            SetSignalWindowProperty();
        }
        // 穿透IP设置
        if (pSelectedAction == pChannelRemoteAction) {
            BCSettingChannelRemoteIPDlg *pDlg = new BCSettingChannelRemoteIPDlg(m_pInputChannel, this);
            pDlg->exec();
        }
    }

    e->accept();
}

void BCSignalWindowDisplayWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    this->ScaleToOverlapDisplay();

    QWidget::mouseDoubleClickEvent( event );
}

void BCSignalWindowDisplayWidget::onIPVTimeout()
{
    if (9 != m_pInputChannel->GetSignalSource())
        return;

    if ( m_lstIPOfIPVLoop.isEmpty() )
        return;

    for (int i = 0; i < m_nIPVSegmentation; i++) {
        BCSignalWindowIPVWidget *pIPVWidget = m_lstSubDisplayItem.at( i );

        m_nIndexOfIPVLoop = (m_nIndexOfIPVLoop >= m_lstIPOfIPVLoop.count()) ? 0 : m_nIndexOfIPVLoop;
        QString url = m_lstIPOfIPVLoop.at( m_nIndexOfIPVLoop++ );

        pIPVWidget->SetURL( url );
        pIPVWidget->SendIPVedioListCmd();

        QThread::msleep( 300 );
    }
}

QStringList BCSignalWindowDisplayWidget::GetIPVList()
{
    QStringList lstRes;
    if (36 == m_lstSubDisplayItem.count()) {
        for (int i = 0; i < m_lstSubDisplayItem.count(); i++) {
            BCSignalWindowIPVWidget *pSubDisplayItem = m_lstSubDisplayItem.at( i );
            lstRes.append( pSubDisplayItem->m_qsUrl );
        }
    } else {
        for (int i = 0; i < 36; i++) {
            lstRes.append( QString::null );
        }
    }

    return lstRes;
}

QStringList BCSignalWindowDisplayWidget::GetIPVLoopList()
{
    return m_lstIPOfIPVLoop;
}

void BCSignalWindowDisplayWidget::SetIPVLoopList(const QStringList &lst)
{
    m_lstIPOfIPVLoop = lst;
}

void BCSignalWindowDisplayWidget::SetCutArea()
{
    BCSettingCutInputChannelDlg *pDlg = new BCSettingCutInputChannelDlg(m_pInputChannel, BCCommon::Application());
    pDlg->exec();
}

void BCSignalWindowDisplayWidget::RefreshLastIpvIP(int n, QString ip)
{
    QStringList lstIpvList = m_pInputChannel->GetChannelLastIpvIPList( m_pGroupDisplayWidget->GetMGroupDisplay() );
    if ( lstIpvList.isEmpty() ) {
        for (int i = 0; i < 36; i++) {
            lstIpvList.append((n == i) ? ip : QString::null);
        }
    } else {
        if (lstIpvList.count() > n)
            lstIpvList.replace(n, ip);
    }

    m_pInputChannel->SetChannelLastIpvIPList(m_pGroupDisplayWidget->GetMGroupDisplay(), lstIpvList);
}

void BCSignalWindowDisplayWidget::SetIPVedioSegmentationCount(int n, bool bSendCmd)
{
    // 只有IPV才进行设置
    if (9 != m_pInputChannel->GetSignalSource())
        return;

    // 如果链表为空则新建数据并填充链表，链表默认16个，如果已经添加则修改其矩形
    if ( m_lstSubDisplayItem.isEmpty() ) {
        QStringList lstIpvList = m_pInputChannel->GetChannelLastIpvIPList( m_pGroupDisplayWidget->GetMGroupDisplay() );
        for (int i = 0; i < 36; i++) {
            BCSignalWindowIPVWidget *pWidget = new BCSignalWindowIPVWidget(i, this, ui->m_pIPVBodyWidget);
            m_lstSubDisplayItem.append( pWidget );
            pWidget->resize(1,1);
            pWidget->move(0, 0);

            if (lstIpvList.count() > i)
                pWidget->SetURL( lstIpvList.at(i) );
        }
    } else {
        for (int i = 0; i < m_lstSubDisplayItem.count(); i++) {
            BCSignalWindowIPVWidget *pWidget = m_lstSubDisplayItem.at(i);
            pWidget->resize(1,1);
            pWidget->move(0, 0);
        }
    }

    // 根据分割数获得宽和高，分割数:1,4,6,8,9,12,16,25,36
    int nWidth = 1;
    int nHeight = 1;
    int cmdSegment = 1;
    m_nIPVSegmentation = n; //pChannel->GetIPVSegmentation();
    switch ( m_nIPVSegmentation ) {
    case 1:
        cmdSegment = 1;
        nWidth = 1;
        nHeight = 1;
        break;
    case 4:
        cmdSegment = 2;
        nWidth = 2;
        nHeight = 2;
        break;
    case 6:
        cmdSegment = 2;
        nWidth = 3;
        nHeight = 2;
        break;
    case 8:
        cmdSegment = 2;
        nWidth = 4;
        nHeight = 2;
        break;
    case 9:
        cmdSegment = 3;
        nWidth = 3;
        nHeight = 3;
        break;
    case 12:
        cmdSegment = 3;
        nWidth = 4;
        nHeight = 3;
        break;
    case 16:
        cmdSegment = 4;
        nWidth = 4;
        nHeight = 4;
        break;
    case 25:
        cmdSegment = 5;
        nWidth = 5;
        nHeight = 5;
        break;
    case 36:
        cmdSegment = 6;
        nWidth = 6;
        nHeight = 6;
        break;
    default:
        cmdSegment = 1;
        nWidth = 1;
        nHeight = 1;
        break;
    }

    // 根据分割数重置矩形的尺寸
    // 尺寸本应取body的尺寸，但默认添加信号窗第一次自动resize的时候body尺寸没有变化时就运行到当前位置，所以只能用整体尺寸计算
    // 左右下为了迎合回显各缩进3px，信号窗的header固定24px
    //QSize size1 = ui->m_pBodyWidget->size();
    QSize size = this->size();
    size.setWidth(size.width()-6);
    size.setHeight(size.height()-24-3);
    int nSingleWidth = size.width() / nWidth;
    int nSingleHeight = size.height() / nHeight;
    for (int j = 0; j < nHeight; j++) {
        for (int i = 0; i < nWidth; i++) {
            BCSignalWindowIPVWidget *pIPVedioItem = m_lstSubDisplayItem.at(j*nWidth + i);
            pIPVedioItem->resize(nSingleWidth, nSingleHeight);
            pIPVedioItem->move(i*nSingleWidth, j*nSingleHeight);
        }
    }

    if ( bSendCmd ) {
        // 发送指令
        for (int i = 0; i < 1; i++) {
            if ( BCCommon::g_bConnectWithServer ) {
                BCCommunication *pCommunication = BCCommunication::Application();
                pCommunication->SetIPVedioSegmentation(m_pInputChannel->GetChannelID(), m_nIPVSegmentation, m_pInputChannel->GetBoardCardID(), m_pInputChannel->GetBoardCardPos());
            } else {
                BCLocalServer *pServer = BCLocalServer::Application();
                pServer->SetIPVedioSegmentation(m_pInputChannel->GetChannelID(), m_nIPVSegmentation, m_pInputChannel->GetBoardCardID(), m_pInputChannel->GetBoardCardPos());
            }
            //QThread::msleep( 100 );
        }

        // 设置最后一次分屏数
        m_pInputChannel->SetChannelLastSegmentaion(m_pGroupDisplayWidget->GetMGroupDisplay(), m_nIPVSegmentation);
    }
}

int BCSignalWindowDisplayWidget::GetIPVedioSegmentationCount()
{
    return m_nIPVSegmentation;
}

const QList<BCSignalWindowIPVWidget *> &BCSignalWindowDisplayWidget::GetSubDisplayItem()
{
    return m_lstSubDisplayItem;
}

void BCSignalWindowDisplayWidget::SetIPVIP(const QStringList &lstIP, bool bSendCmd)
{
    if (36 != lstIP.count())
        return;

    if (36 != m_lstSubDisplayItem.count())
        SetIPVedioSegmentationCount(m_nIPVSegmentation, false);

    for (int i = 0; i < 36; i++) {
        BCSignalWindowIPVWidget *pItem = m_lstSubDisplayItem.at( i );
        pItem->SetURL( lstIP.at(i) );

        if ( !bSendCmd )
            continue;

        // 如果没有URL则直接下次循环
        if ( pItem->m_qsUrl.isEmpty() )
            continue;

        // 发送指令
        for (int j = 0; j < 2; j++) {
            if ( BCCommon::g_bConnectWithServer ) {
                BCCommunication *pCommunication = BCCommunication::Application();
                pCommunication->SetIPVedioCurrentIP(m_pInputChannel->GetChannelID(), m_nWindowID, m_nIPVSegmentation, i, pItem->m_qsUrl, m_pInputChannel->GetBoardCardID(), m_pInputChannel->GetBoardCardPos());
            } else {
                BCLocalServer *pServer = BCLocalServer::Application();

                QStringList lstPara = pItem->m_qsResolution.split("*");
                if (lstPara.count() == 2) {
                    pServer->SetIPVedioCurrentIP(m_pInputChannel->GetChannelID(), m_nWindowID, m_nIPVSegmentation, i, pItem->m_qsUrl,
                                                 m_pInputChannel->GetBoardCardID(), m_pInputChannel->GetBoardCardPos(), pItem->m_qsDecoder.contains("H264")?96:265,
                                                 lstPara.first().toInt(), lstPara.last().toInt());
                }
            }
            //QThread::msleep( 100 );
        }

        //QThread::msleep( 50 );
    }
}

void BCSignalWindowDisplayWidget::ServerRequestControlResult()
{
    m_bPress = true;

    // 置顶
    SetSignalPosition(0);
}

void BCSignalWindowDisplayWidget::ServerWinSwitchResult(bool b)
{
    m_pSignalWindowMgr->ServerWinSwitchResult(b, this);
}

void BCSignalWindowDisplayWidget::mousePressEvent(QMouseEvent *event)
{
    // 矩阵不可移动
    if (4 == m_pSignalWindowMgr->GetMRoom()->GetType()) {
        QWidget::mousePressEvent(event);
        return;
    }

    // 点击单个屏幕时
    if ( !m_bLock ) {
        if(event->button()== Qt::LeftButton){

            // 相对于scene左上角的坐标，缩放不影响坐标
            m_x = event->pos().x();
            m_y = event->pos().y();

            // 向服务器发送winsize请求，以下设置放到服务器回复里处理
            if ( BCCommon::g_bConnectWithServer ) {
                BCCommunication *pCommunication = BCCommunication::Application();
                pCommunication->RequestControlBySignalWindow(m_pGroupDisplayWidget->GetMGroupDisplay()->GetGroupDisplayID(), m_pInputChannel->GetChannelID(),
                                                             m_pInputChannel->GetChannelType(), m_nWindowID);
            } else {
                m_bPress = true;

                // 置顶
                SetSignalPosition(0);
            }
        }
    }

    QWidget::mousePressEvent(event);
}

void BCSignalWindowDisplayWidget::mouseMoveEvent(QMouseEvent * event)
{
    // 点击单个屏幕时
    if (!m_bLock) {
        if (m_bPress) {
            // 矩形左上角坐标，缩放无影响
            int nOffsetX = event->pos().x() - m_x;
            int nOffsetY = event->pos().y() - m_y;

            // 转换成窗口管理类坐标
            QPoint ptLT = this->mapTo(m_pSignalWindowMgr, this->rect().topLeft());
            QPoint ptRB = this->mapTo(m_pSignalWindowMgr, this->rect().bottomRight());
            QPoint ptCurrentPos = this->mapTo(m_pSignalWindowMgr, event->pos());

            // 窗口管理类矩形框
            QRect parentRect = m_pSignalWindowMgr->rect();  // 父类坐标系坐标

            bool bSendCmd = true;

            // 需要考虑缩放比例，需要考虑到拖动范围
            switch (m_eResizePos) {
            case UNRESIZE: {
                int l = ptLT.x()+nOffsetX;
                int t = ptLT.y()+nOffsetY;

                // 允许拖动最小范围
                l = (l <= parentRect.left()) ? parentRect.left() : l;
                t = (t <= parentRect.top()) ? parentRect.top() : t;

                // 允许拖动最大范围
                l = (l >= parentRect.right()-this->rect().width()+1) ? parentRect.right()-this->rect().width()+1 : l;
                t = (t >= parentRect.bottom()-this->rect().height()+1) ? parentRect.bottom()-this->rect().height()+1 : t;

                l = (l < 0) ? 0 : l;
                t = (t < 0) ? 0 : t;

                // 2000时窗口漫游需要间隔200MS
//                if (0 == BCCommon::g_nDeviceType) {
//                    bSendCmd = false;
//                }

                ResizeRect(l, t, this->rect().width(), this->rect().height(), bSendCmd);
            }
                break;
            case RESIZELT: {
                // 最大最小值限定
                nOffsetX = (ptLT.x()+nOffsetX <= parentRect.left()) ? 0 : nOffsetX;
                nOffsetX = (ptLT.x()+nOffsetX >= ptRB.x()-BCCommon::g_nMinResizeSignalWindowSizeW) ? 0 : nOffsetX;

                nOffsetY = (ptLT.y()+nOffsetY <= parentRect.top()) ? 0 : nOffsetY;
                nOffsetY = (ptLT.y()+nOffsetY >= ptRB.y()-BCCommon::g_nMinResizeSignalWindowSizeH) ? 0 : nOffsetY;

                ResizeRect(ptLT.x()+nOffsetX, ptLT.y()+nOffsetY, this->rect().width()-nOffsetX, rect().height()-nOffsetY, bSendCmd);
                }
                break;
            case RESIZEL: {
                // 最大最小值限定
                nOffsetX = (ptLT.x()+nOffsetX <= parentRect.left()) ? 0 : nOffsetX;
                nOffsetX = (ptLT.x()+nOffsetX >= ptRB.x()-BCCommon::g_nMinResizeSignalWindowSizeW) ? 0 : nOffsetX;

                ResizeRect(ptLT.x()+nOffsetX, ptLT.y(), this->rect().width()-nOffsetX, rect().height(), bSendCmd);
                }
                break;
            case RESIZELB: {
                // 最大最小值限定
                nOffsetX = (ptLT.x()+nOffsetX <= parentRect.left()) ? 0 : nOffsetX;
                nOffsetX = (ptLT.x()+nOffsetX >= ptRB.x()-BCCommon::g_nMinResizeSignalWindowSizeW) ? 0 : nOffsetX;

                ptCurrentPos.setY( (ptCurrentPos.y() >= parentRect.bottom()) ? parentRect.bottom() : ptCurrentPos.y() );
                ptCurrentPos.setY( (ptCurrentPos.y() <= ptLT.y()+BCCommon::g_nMinResizeSignalWindowSizeH) ? ptLT.y()+BCCommon::g_nMinResizeSignalWindowSizeH : ptCurrentPos.y() );

                ResizeRect(ptLT.x()+nOffsetX, ptLT.y(), this->rect().width()-nOffsetX, ptCurrentPos.y()-ptLT.y(), bSendCmd);
                }
                break;
            case RESIZET: {
                nOffsetY = (ptLT.y()+nOffsetY <= parentRect.top()) ? 0 : nOffsetY;
                nOffsetY = (ptLT.y()+nOffsetY >= ptRB.y()-BCCommon::g_nMinResizeSignalWindowSizeH) ? 0 : nOffsetY;

                ResizeRect(ptLT.x(), ptLT.y()+nOffsetY, this->rect().width(), rect().height()-nOffsetY, bSendCmd);
                }
                break;
            case RESIZEB: {
                ptCurrentPos.setY( (ptCurrentPos.y() >= parentRect.bottom()) ? parentRect.bottom() : ptCurrentPos.y() );
                ptCurrentPos.setY( (ptCurrentPos.y() <= ptLT.y()+BCCommon::g_nMinResizeSignalWindowSizeH) ? ptLT.y()+BCCommon::g_nMinResizeSignalWindowSizeH : ptCurrentPos.y() );

                ResizeRect(ptLT.x(), ptLT.y(), this->rect().width(), ptCurrentPos.y()-ptLT.y(), bSendCmd);
                }
                break;
            case RESIZERT: {
                // 最大最小值限定
                ptCurrentPos.setX( (ptCurrentPos.x() >= parentRect.right()) ? parentRect.right() : ptCurrentPos.x() );
                ptCurrentPos.setX( (ptCurrentPos.x() <= ptLT.x()+BCCommon::g_nMinResizeSignalWindowSizeW) ? ptLT.x()+BCCommon::g_nMinResizeSignalWindowSizeW : ptCurrentPos.x() );

                nOffsetY = (ptLT.y()+nOffsetY <= parentRect.top()) ? 0 : nOffsetY;
                nOffsetY = (ptLT.y()+nOffsetY >= ptRB.y()-BCCommon::g_nMinResizeSignalWindowSizeH) ? 0 : nOffsetY;

                ResizeRect(ptLT.x(), ptLT.y()+nOffsetY, ptCurrentPos.x()-ptLT.x(), rect().height()-nOffsetY, bSendCmd);
                }
                break;
            case RESIZER: {
                // 最大最小值限定
                ptCurrentPos.setX( (ptCurrentPos.x() >= parentRect.right()) ? parentRect.right() : ptCurrentPos.x() );
                ptCurrentPos.setX( (ptCurrentPos.x() <= ptLT.x()+BCCommon::g_nMinResizeSignalWindowSizeW) ? ptLT.x()+BCCommon::g_nMinResizeSignalWindowSizeW : ptCurrentPos.x() );

                ResizeRect(ptLT.x(), ptLT.y(), ptCurrentPos.x()-ptLT.x(), rect().height(), bSendCmd);
                }
                break;
            case RESIZERB: {
                // 最大最小值限定
                ptCurrentPos.setX( (ptCurrentPos.x() >= parentRect.right()) ? parentRect.right() : ptCurrentPos.x() );
                ptCurrentPos.setX( (ptCurrentPos.x() <= ptLT.x()+BCCommon::g_nMinResizeSignalWindowSizeW) ? ptLT.x()+BCCommon::g_nMinResizeSignalWindowSizeW : ptCurrentPos.x() );

                ptCurrentPos.setY( (ptCurrentPos.y() >= parentRect.bottom()) ? parentRect.bottom() : ptCurrentPos.y() );
                ptCurrentPos.setY( (ptCurrentPos.y() <= ptLT.y()+BCCommon::g_nMinResizeSignalWindowSizeH) ? ptLT.y()+BCCommon::g_nMinResizeSignalWindowSizeH : ptCurrentPos.y() );

                ResizeRect(ptLT.x(), ptLT.y(), ptCurrentPos.x()-ptLT.x(), ptCurrentPos.y()-ptLT.y(), bSendCmd);
                }
                break;
            default:
                break;
            }

            // 刷新全局窗口定位代码
            MainWindow *pMainWindow = BCCommon::Application();
            BCRibbonMainToolBar *pMainToolBar = pMainWindow->GetRibbonMainToolBar();
            if (NULL == pMainToolBar)
                return;

            BCRibbonMainToolBarAction *pLocationBtn = pMainToolBar->GetButtonAction( BCRibbonMainToolBar::LOCATION );
            if (NULL != pLocationBtn) {
                pLocationBtn->RefreshLocationDlg();
            }
        }
    }

    QWidget::mouseMoveEvent(event);
}

bool BCSignalWindowDisplayWidget::event(QEvent *event)
{
    if ( m_bRemote ) {  // 穿透处理
        if ( !ui->m_pGenaralBodyWidget->hasFocus() )
            ui->m_pGenaralBodyWidget->setFocus();

        qDebug() << event->type();
        if (event->type() == QEvent::HoverMove || event->type() == QEvent::MouseButtonDblClick || event->type() == QEvent::MouseButtonPress
                || event->type() == QEvent::MouseButtonRelease || event->type() == QEvent::KeyPress || event->type() == QEvent::KeyRelease) {

            QHoverEvent* pHoverEvent = dynamic_cast<QHoverEvent *>(event);
            if (NULL != pHoverEvent) {
                // 转换坐标到ui->m_pGenaralBodyWidget
                QPoint pos = ui->m_pGenaralBodyWidget->mapFrom(this, pHoverEvent->pos());

                double dx = 1.0*pos.x()/ui->m_pGenaralBodyWidget->rect().width();
                double dy = 1.0*pos.y()/ui->m_pGenaralBodyWidget->rect().height();
                int x = 10000.0*dx;
                int y = 10000.0*dy;

                int mouseFlag = 0x0001;

                if (0 != mouseFlag) {
                    QString cmd = QString("%1 %2 %3 %4%5")
                            .arg("M").arg(mouseFlag).arg(x).arg(y).arg("$$$$");

                    m_pInputChannel->SendRemoteCmd( cmd );
                }
            }

            // 鼠标事件
            QMouseEvent *pMouseEvent = dynamic_cast<QMouseEvent *>( event );
            if (NULL != pMouseEvent) {
                // 转换坐标到ui->m_pGenaralBodyWidget
                QPoint pos = ui->m_pGenaralBodyWidget->mapFrom(this, pMouseEvent->pos());

                double dx = 1.0*pos.x()/ui->m_pGenaralBodyWidget->rect().width();
                double dy = 1.0*pos.y()/ui->m_pGenaralBodyWidget->rect().height();
                int x = 10000.0*dx;
                int y = 10000.0*dy;

                int times = 1;
                int mouseFlag = 0;
                if (event->type() == QEvent::MouseMove) {
                    mouseFlag = 0x0001;
                } else if ((event->type() == QEvent::MouseButtonPress)
                    || (event->type() == QEvent::MouseButtonDblClick)){
                    if (pMouseEvent->button() == Qt::LeftButton) {
                        mouseFlag = 0x0002;
                    } else if (pMouseEvent->button() == Qt::RightButton) {
                        mouseFlag = 0x0008;
                    }
                } else if (event->type() == QEvent::MouseButtonRelease) {
                    if (pMouseEvent->button() == Qt::LeftButton) {
                        mouseFlag = 0x0004;
                    } else if (pMouseEvent->button() == Qt::RightButton) {
                        mouseFlag = 0x0010;
                    }
                } else if (event->type() == QEvent::MouseButtonDblClick) {
                    times = 2;
                    if (pMouseEvent->button() == Qt::LeftButton) {
                       mouseFlag = 0x0002;
                    } else if (pMouseEvent->button() == Qt::RightButton) {
                       mouseFlag = 0x0008;
                    }
               }

                if (0 != mouseFlag) {
                    QString cmd = QString("%1 %2 %3 %4%5")
                            .arg("M").arg(mouseFlag).arg(x).arg(y).arg("$$$$");

                    m_pInputChannel->SendRemoteCmd( cmd );
                }
            }

            // 键盘事件
            QKeyEvent *pKeyEvent = dynamic_cast<QKeyEvent *>( event );
            if (NULL != pKeyEvent) {

                QString qsFlag;
                if (event->type() == QEvent::KeyPress)
                    qsFlag = "KP";
                if (event->type() == QEvent::KeyRelease)
                    qsFlag = "KR";

                qDebug() << qsFlag << pKeyEvent->text() << pKeyEvent->nativeVirtualKey() << "~~~~~~~~~";
                if (18 != pKeyEvent->nativeVirtualKey()) {  // Alt 不发送，因为捕获不到释放事件
                    if ( !qsFlag.isEmpty() ) {
                        QString cmd = QString("%1 %2%3")
                                .arg(qsFlag).arg(pKeyEvent->nativeVirtualKey()).arg("$$$$");

                        m_pInputChannel->SendRemoteCmd( cmd );
                    }
                }

            }
        }

    }

    if (event->type() == QEvent::HoverEnter || event->type() == QEvent::HoverLeave
            || event->type() == QEvent::HoverMove) {
        QHoverEvent* pHoverEvent = static_cast<QHoverEvent *>(event);

        // 锁定和点击情况下不做处理
        if ( m_bLock || m_bPress )
            return false;

        // 判断是否需要调整窗口大小，下面为距离左上角的值
        int nltx = pHoverEvent->pos().x() - rect().x();
        int nlty = pHoverEvent->pos().y() - rect().y();

        // x在修改范围时
        if (nltx <= BCCommon::g_nMaxSizeOfModifyRect) {
            if (nlty <= BCCommon::g_nMaxSizeOfModifyRect) {
                // ↖
                m_eResizePos = RESIZELT;
                setCursor(Qt::SizeFDiagCursor);
            } else if (qAbs(nlty-rect().height()) <= BCCommon::g_nMaxSizeOfModifyRect) {
                // ↙
                m_eResizePos = RESIZELB;
                setCursor(Qt::SizeBDiagCursor);
            } else {
                // ←
                m_eResizePos = RESIZEL;
                setCursor(Qt::SizeHorCursor);
            }
        } else if (qAbs(nltx-rect().width()) <= BCCommon::g_nMaxSizeOfModifyRect) {
            if (nlty <= BCCommon::g_nMaxSizeOfModifyRect) {
                // ↗
                m_eResizePos = RESIZERT;
                setCursor(Qt::SizeBDiagCursor);
            } else if (qAbs(nlty-rect().height()) <= BCCommon::g_nMaxSizeOfModifyRect) {
                // ↘
                m_eResizePos = RESIZERB;
                setCursor(Qt::SizeFDiagCursor);
            } else {
                // →
                m_eResizePos = RESIZER;
                setCursor(Qt::SizeHorCursor);
            }
        } else {
            if (nlty <= BCCommon::g_nMaxSizeOfModifyRect) {
                // ↑
                m_eResizePos = RESIZET;
                setCursor(Qt::SizeVerCursor);
            } else if (qAbs(nlty-rect().height()) <= BCCommon::g_nMaxSizeOfModifyRect) {
                // ↓
                m_eResizePos = RESIZEB;
                setCursor(Qt::SizeVerCursor);
            } else {
                // 不拉伸
                m_eResizePos = UNRESIZE;
                setCursor(Qt::ArrowCursor);
            }
        }
    }

    return QWidget::event(event);
}

void BCSignalWindowDisplayWidget::mouseReleaseEvent(QMouseEvent *event)
{
    // 点击单个屏幕时
    if (!m_bLock) {
        if ( m_bPress ) {
            // 如果开启吸附则重置矩形尺寸
            if (BCCommon::g_bOpenSignalWindowSorption)
                ResizeRectBySorption();

            // 鼠标释放时发送结束标识
            if (m_bPress && BCCommon::g_bConnectWithServer) {
                m_bPress = false;

                MainWindow *pMainWindow = BCCommon::Application();
                BCMRoom *pRoom = pMainWindow->GetCurrentMRoom();
                if (NULL == pRoom)
                    return;

                BCCommunication *pCommunication = BCCommunication::Application();
                pCommunication->RequestOver( pRoom->GetRoomID() );
            }

            m_bPress = false;
        }
    }

    QWidget::mouseReleaseEvent(event);
}

void BCSignalWindowDisplayWidget::on_m_pLockBtn_clicked()
{
    this->SetLock( !m_bLock );
}

void BCSignalWindowDisplayWidget::on_m_pFullscreenBtn_clicked()
{
    if ( m_bLock )
        return;

    m_bFullScene = !m_bFullScene;
    QString qsFullscreenPath = BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+(m_bFullScene?BCCommon::g_qsSignalWindowTitleUnFullScreenButtonImagePath:BCCommon::g_qsSignalWindowTitleFullScreenButtonImagePath);
    ui->m_pFullscreenBtn->setIcon(QIcon(qsFullscreenPath));

    SetFullScene( m_bFullScene );
}

void BCSignalWindowDisplayWidget::on_m_pWindowShowBtn_clicked()
{
    SetFullScene( false );
}

void BCSignalWindowDisplayWidget::on_m_pCloseBtn_clicked()
{
    m_pSignalWindowMgr->RemoveSignalWindowDisplayItem( this );
}

void BCSignalWindowDisplayWidget::paintEvent(QPaintEvent */*e*/)
{
    QPainter painter(this);

    // 设置边框
    painter.setPen(QPen(Qt::black,1,Qt::SolidLine));

    // 绘制整体
    painter.setBrush( QBrush(/*m_bEcho ? Qt::black :*/ QColor(131, 180, 235, m_transparent)));
    painter.drawRect( QRect(rect().left(), rect().top(), rect().width()-1, rect().height()-1) );

    // 绘制header
    painter.setBrush( QBrush(QColor(250, 141, 69, m_transparent)));
    QRect rectHeader = ui->m_pHeaderWidget->rect();
    painter.drawRect( QRect(rectHeader.left(), rectHeader.top(), rectHeader.width()+5, rectHeader.height()) );
}

void BCSignalWindowDisplayWidget::on_m_pRemoteBtn_clicked()
{
    m_bRemote = !m_bRemote;
    SetLock( m_bRemote );   // 远程控制时需要锁定
    QString qsRemoteIcon = m_bRemote?"remoteon16.png":"remoteoff16.png";
    ui->m_pRemoteBtn->setIcon(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+qsRemoteIcon));
}
