#include "BCMonitorWidgetData.h"
#include "ui_BCMonitorWidgetData.h"
#include <QDebug>
#include <QMimeData>
#include <QDrag>
#include <QTimer>
#include <QScrollBar>
#include "../Common/BCCommon.h"
#include "../Model/BCMRoom.h"
#include "../Model/BCMChannel.h"
#include "../Player/BCVedioManager.h"

// 定义预监窗口的尺寸
#define REVIEWWIDTH     240
#define REVIEWHEIGHT    136

BCMonitorWidget::BCMonitorWidget(QWidget *parent) :
    QListWidget(parent)
{
    this->setViewMode(QListView::IconMode);
    this->setResizeMode( QListView::Adjust);
    this->setFlow(QListView::LeftToRight);
    this->setSpacing(16);

    beginTime = beginTime.addMSecs( -1000 );
    connect(verticalScrollBar(), SIGNAL(actionTriggered(int)), this, SLOT(onActionTriggered(int)));

    Refresh();
}

BCMonitorWidget::~BCMonitorWidget()
{
    this->clear();
}

void BCMonitorWidget::resizeEvent(QResizeEvent *e)
{
    // 更新布局
    QListWidget::resizeEvent( e );

    // 更新显示区域
    onActionTriggered(1);
}

void BCMonitorWidget::onActionTriggered(int /*value*/)
{
    // 1秒钟后刷新状态
    beginTime = QTime::currentTime();
    QTimer::singleShot(100, this, SLOT(onRefreshVedioStatus()));
}

void BCMonitorWidget::onRefreshVedioStatus()
{
    // 如果连续多次操作滚动条则最后一次再刷新
    int nOffsetTime = beginTime.msecsTo( QTime::currentTime() );
    if (nOffsetTime < 100)
        return;

    // 对矩形区域进行矩形切割，根据切割点判断是否有需要显示的item
    QRect rect = QRect(0, 0, this->width(), this->height());

    // 不在范围内的直接关闭
    MainWindow *pApplication = BCCommon::Application();
    QList<BCMChannel *> lstChannel = pApplication->GetInputChannels();

    // 关联物理输入通道
    int nPreviewCount = (BCCommon::g_nMonitorCount == -1) ? lstChannel.count() : BCCommon::g_nMonitorCount;
    for (int i = 0; i < nPreviewCount; i++) {
        QListWidgetItem *pItem = this->item( i );
        BCMonitorWidgetData *pWidget = dynamic_cast<BCMonitorWidgetData *>( this->itemWidget( pItem ) );
        if (NULL == pWidget)
            continue;

        QPoint ptLT = pWidget->mapTo(this, pWidget->rect().topLeft());
        QPoint ptRB = pWidget->mapTo(this, pWidget->rect().bottomRight());
        pWidget->RefreshEchoStatus(rect.intersects( QRect(ptLT, ptRB) ) ? false : true);
    }
}
void BCMonitorWidget::Refresh()
{
    // 1.清空链表
    this->clear();

    // 2.获得当前房间的预监窗口数量
    MainWindow *pApplication = BCCommon::Application();
    QList<BCMChannel *> lstChannel = pApplication->GetInputChannels();

    int nPreviewCount = (BCCommon::g_nMonitorCount == -1) ? lstChannel.count() : BCCommon::g_nMonitorCount;

    // 3.初始化链表
    for(int i = 0; i < nPreviewCount; i++) {
        QListWidgetItem *pItem = new QListWidgetItem();
        pItem->setSizeHint(QSize(REVIEWWIDTH, REVIEWHEIGHT));

        this->addItem(pItem);

        // item关联Widget
        int nChannelID = i%lstChannel.count();
        BCMChannel *pChannel = lstChannel.at( nChannelID );
        this->setItemWidget(pItem, new BCMonitorWidgetData(i, pChannel->GetChannelID(), pChannel->GetChannelType(), pChannel->GetChannelBaseName(), this));
    }
}

void BCMonitorWidget::RefreshEchoStatus(bool bTempCloseEcho)
{
    static bool bRefreshOK = true;
    if ( !bRefreshOK )
        return;

    bRefreshOK = false;

    MainWindow *pApplication = BCCommon::Application();
    QList<BCMChannel *> lstChannel = pApplication->GetInputChannels();

    // 关联物理输入通道
    int nPreviewCount = (BCCommon::g_nMonitorCount == -1) ? pApplication->GetInputChannels().count() : BCCommon::g_nMonitorCount;
    for (int i = 0; i < nPreviewCount; i++) {
        QListWidgetItem *pItem = this->item( i );
        BCMonitorWidgetData *pWidget = dynamic_cast<BCMonitorWidgetData *>( this->itemWidget( pItem ) );
        if (NULL == pWidget)
            continue;

        pWidget->RefreshEchoStatus( bTempCloseEcho );
    }

    bRefreshOK = true;
}

void BCMonitorWidget::SetPreviewVisible(bool b)
{
    static bool bRefreshOK = true;
    if ( !bRefreshOK )
        return;

    bRefreshOK = false;

    MainWindow *pApplication = BCCommon::Application();
    QList<BCMChannel *> lstChannel = pApplication->GetInputChannels();

    QRect rect = QRect(0, 0, this->width(), this->height());

    // 关联物理输入通道
    int nPreviewCount = (BCCommon::g_nMonitorCount == -1) ? lstChannel.count() : BCCommon::g_nMonitorCount;
    for (int i = 0; i < nPreviewCount; i++) {
        QListWidgetItem *pItem = this->item( i );
        BCMonitorWidgetData *pWidget = dynamic_cast<BCMonitorWidgetData *>( this->itemWidget( pItem ) );
        if (NULL == pWidget)
            continue;

        // 如果在显示范围内则显示，否则临时关闭
        QPoint ptLT = pWidget->mapTo(this, pWidget->rect().topLeft());
        QPoint ptRB = pWidget->mapTo(this, pWidget->rect().bottomRight());
        pWidget->RefreshEchoStatus(rect.intersects( QRect(ptLT, ptRB) ) ? false : true);

        // 循环显示输入通道
        pWidget->SetEcho(b);
    }

    bRefreshOK = true;
}

BCMonitorWidgetData::BCMonitorWidgetData(int /*index*/, int chid, int chType, const QString &name, BCMonitorWidget *pPreviewWidget) :
    QWidget(pPreviewWidget),
    ui(new Ui::BCMonitorWidgetData)
{
    ui->setupUi(this);
    this->setAcceptDrops(true);
    this->setMaximumWidth( REVIEWWIDTH );
    this->setMinimumWidth( REVIEWWIDTH );

    // 设置显示名称
    m_pPreviewWidget = pPreviewWidget;
    //ui->label->setText(QString::number(index+1));
    ui->label->setText( name );

    // 构造回显单元
    m_bTempCloseEcho = false;
    m_bPlaying = false;
    m_nChannelID = chid;
    m_nChannelType = chType;
}

BCMonitorWidgetData::~BCMonitorWidgetData()
{
    this->SetEcho( false );

    delete ui;
}

void BCMonitorWidgetData::contextMenuEvent(QContextMenuEvent* /*event*/){
    QMenu menu;
    QAction *pOpenAction = menu.addAction(tr("打开视频"));
    QAction *pCloseAction = menu.addAction(tr("关闭视频"));
    menu.addSeparator();
    QAction *pOpenAllVedioAction = menu.addAction(tr("打开全部视频"));
    QAction *pCloseAllVedioAction = menu.addAction(tr("关闭全部视频"));

    pOpenAction->setCheckable(true);
    pCloseAction->setCheckable(true);

    pOpenAction->setChecked( m_bPlaying );
    pCloseAction->setChecked( !m_bPlaying );

    // 显示menu
    QAction *pSelectAction = menu.exec(QCursor::pos());
    if (pSelectAction == pOpenAction) {
        SetEcho( true );
    }
    if (pSelectAction == pCloseAction) {
        SetEcho( false );
    }
    if (pSelectAction == pOpenAllVedioAction) {
        m_pPreviewWidget->SetPreviewVisible( true );
    }
    if (pSelectAction == pCloseAllVedioAction) {
        m_pPreviewWidget->SetPreviewVisible( false );
    }
}

//拖拽事件
void BCMonitorWidgetData::dragEnterEvent(QDragEnterEvent* event){
    //相同类不能放
    BCMonitorWidgetData* source = qobject_cast<BCMonitorWidgetData*>(event->source());
    if ( source )
        return;

    if (event->mimeData()->hasFormat("inputChannel"))
       event->accept();
    else
       event->ignore();
}

// 拖放
void BCMonitorWidgetData::dropEvent(QDropEvent* e)
{
    // 查看是否是输入通道标识
    if (e->mimeData()->hasFormat("inputChannel")){

        // 可用于接收拖拽参数
        const QMimeData *mimeData = e->mimeData();
        QByteArray exData = mimeData->data("inputChannel");
        QDataStream dataStream (&exData, QIODevice::ReadOnly);
        QList<QString> lstData;

        // 一个输入通道为3个参数
        dataStream >> lstData;
        int nInputCount = lstData.count();
        if ((nInputCount < 3) || (nInputCount%3 != 0))
            return;

        // 拖拽过来的chid
        int nDropChType = lstData.at(1).toInt();
        int nDropChID = lstData.at(2).toInt();

        // 在播放时，如果拖拽过来的chid没变化则直接返回，如果有变化则停止后替换chid重新播放
        if ( m_bPlaying ) {
            if ((nDropChID == m_nChannelID) && (m_nChannelType == nDropChType))
                return;

            SetEcho( false );
            m_nChannelID = nDropChID;
            m_nChannelType = nDropChType;
            SetEcho( true );
        } else {
            m_nChannelID = nDropChID;
            m_nChannelType = nDropChType;
            SetEcho( true );
        }

        // 刷新名字显示
        RefreshName();
    }
}

void BCMonitorWidgetData::RefreshName()
{
    MainWindow *pApplication = BCCommon::Application();
    BCMChannel *pChannel = pApplication->GetInputChannel(m_nChannelID, m_nChannelType);
    if (NULL != pChannel) {
        ui->label->setText( pChannel->GetChannelBaseName() );
    }
}

void BCMonitorWidgetData::mousePressEvent(QMouseEvent* e){
    if (e->button() == Qt::LeftButton){
        // 如果当前没有数据则直接返回
        if ((-1 == m_nChannelID) || (-1 == m_nChannelType))
            return;

        QByteArray exData;
        QDataStream dataStream(&exData,QIODevice::WriteOnly);

        QList<QString> listdata;

        listdata.append("1");       //1 类型标识
        listdata.append( QString::number(m_nChannelType) );
        listdata.append( QString::number(m_nChannelID) );

        dataStream << listdata;
        QDrag *drag = new QDrag(this);
        QMimeData *mimeData = new QMimeData();
        mimeData->setData("inputChannel", exData);
        drag->setMimeData(mimeData);
        drag->exec(Qt::CopyAction);
    }
}

void BCMonitorWidgetData::RefreshEchoStatus(bool bTempCloseEcho)
{
    m_bTempCloseEcho = bTempCloseEcho;
    if ( m_bTempCloseEcho ) {
        if ( !m_bPlaying ) {
            return;
        } else {
            SetEcho( false );
            m_bPlaying = true;
        }
    } else {
        if ( !m_bPlaying ) {
            return;
        } else {
            m_bPlaying = false;
            SetEcho( true );
            m_bPlaying = true;
        }
    }
}

// 设置回显开关
void BCMonitorWidgetData::SetEcho(bool bOpen)
{
    if ( !BCCommon::g_bEchoModel )
        return;

    // 如果修改的播放标识没有变化则直接退出
    if (m_bPlaying == bOpen)
        return;

    m_bPlaying = bOpen;
    if (m_bPlaying && m_bTempCloseEcho)
        return;

    BCVedioManager *pVideoMgr = BCVedioManager::Application();
    if( m_bPlaying ) {
        // 如果当前chid不合法则直接返回
        if ((-1 == m_nChannelID) || (-1 == m_nChannelType))
            return;

        ui->label_view->setUpdatesEnabled( false );
        pVideoMgr->AddEcho((HWND)ui->label_view->winId(), m_nChannelID, 0, 0, REVIEWWIDTH, REVIEWHEIGHT);

        //m_bPlaying = true;
    } else {
        ui->label_view->setUpdatesEnabled( true );
        pVideoMgr->RemoveEcho((HWND)ui->label_view->winId());

        //m_bPlaying = false;
    }
}
