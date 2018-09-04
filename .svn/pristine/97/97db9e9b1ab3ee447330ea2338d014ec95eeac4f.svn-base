#include "BCSignal.h"
#include "ui_BCSignal.h"
#include <QListWidget>
#include <QScrollBar>
#include "BCWidgetBtn.h"
#include "../Model/BCMChannel.h"
#include "../Model/BCMGroupChannel.h"
#include "../View/BCSignalTreeWidget.h"
#include "../Common/BCCommon.h"
#include "BCSignalListWidgetData.h"

// 预览小窗的尺寸
#define PREVIEWWIDTH    240
#define PREVIEWHEIGHT   156

BCSignal::BCSignal(bool bVisible, int minHeight, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCSignal)
{
    m_pHeaderBtn = NULL;

    m_bModifyHeight = false;
    m_bPress = false;

    ui->setupUi(this);
    setAttribute( Qt::WA_Hover,true);

    // 设置最小显示高度
    m_minHeight = minHeight;
    ui->m_pBodyFrame->setMinimumHeight(minHeight);

    // 初始化ui格式
    init(bVisible);

    // 刷新界面数据
    Refresh();

    // 默认打开预览
    beginTime = beginTime.addMSecs( -1000 );
    ui->m_pShowVedioCheckBox->setVisible( false );
    on_m_pShowVedioCheckBox_clicked( true );
    onRefreshVedioStatus();
}

void BCSignal::init(bool bVisible)
{
    // 默认显示列表
    m_bShowVedio = false;
    m_bTempCloseEcho = false;

    // 添加自定义列表头，可以控制隐藏和显示
    m_pHeaderBtn = new BCWidgetBtn(this, MainWindow::CUSTINPUTCHANNELSSIGSRC, bVisible);
    ui->verticalLayout->addWidget(m_pHeaderBtn);

    connect(m_pHeaderBtn, SIGNAL(sigSetVisible(bool)), this, SLOT(onSetVisible(bool)));
    onSetVisible( bVisible );

    // 初始化显示模式，并且默认为文字显示
    ui->m_pShowModeComboBox->addItem(tr("列表"));
    ui->m_pShowModeComboBox->addItem(tr("网格"));

    ui->m_pShowModeComboBox->setCurrentIndex(0);
    on_m_pShowModeComboBox_currentIndexChanged(0);

    // 初始化视频显示的格式
    beginTime = QTime::currentTime();
    m_nScrollMinValue = 0;
    m_nScrollMaxValue = 1;

    // 设置字体
    BCCommon::SetSystemFont(this);
}

void BCSignal::onSetVisible(bool bVisible)
{
    ui->m_pBodyFrame->setVisible( bVisible );
}

bool BCSignal::IsVisible()
{
    return m_pHeaderBtn->IsVisible();
}

void BCSignal::Refresh()
{
    // 这里有个开关控制是否显示自定义组
    MainWindow *pMainWindow = BCCommon::Application();
    if ( !pMainWindow->IsUseGroupInputChannels() )
        return;

    // 1.刷新treeWidget
    ui->m_pInputChannelTextTreeWidget->Refresh();

    // 2.刷新tabWidget
    ui->m_pInputChannelVedioTabWidget->clear();

    // 循环添加自定义信号组
    QList<BCMGroupChannel *> lstGroupChannel = pMainWindow->GetGroupInputChannels();
    QListIterator<BCMGroupChannel *> itGroup( lstGroupChannel );
    while ( itGroup.hasNext() ) {
        BCMGroupChannel *pGroupChannel = itGroup.next();

        // 构造listWidget并添加到tab页中
        QListWidget *pGroupChannelListWidget = new QListWidget( ui->m_pInputChannelVedioTabWidget );
        pGroupChannelListWidget->setViewMode(QListView::IconMode);
        pGroupChannelListWidget->setResizeMode( QListView::Adjust);
        pGroupChannelListWidget->setFlow(QListView::LeftToRight);
        pGroupChannelListWidget->setSpacing(5);
        connect(pGroupChannelListWidget->verticalScrollBar(), SIGNAL(actionTriggered(int)), this, SLOT(onActionTriggered(int)));
        connect(pGroupChannelListWidget->verticalScrollBar(), SIGNAL(rangeChanged(int,int)), this, SLOT(onRangeChanged(int, int)));

        ui->m_pInputChannelVedioTabWidget->addTab(pGroupChannelListWidget, pGroupChannel->GetName());

        // 循环添加信号
        QList<BCMChannel *> lstChannel = pGroupChannel->GetChannels();
        QListIterator<BCMChannel *> it( lstChannel );
        while ( it.hasNext() ) {
            BCMChannel *pChannel = it.next();

            QListWidgetItem *pChannelListWidgetItem = new QListWidgetItem( pGroupChannelListWidget );
            pChannelListWidgetItem->setSizeHint(QSize(PREVIEWWIDTH, PREVIEWHEIGHT));
            pGroupChannelListWidget->addItem(pChannelListWidgetItem);

            BCSignalListWidgetData *pChannelItemWidget = new BCSignalListWidgetData(pChannel, this);
            pGroupChannelListWidget->setItemWidget(pChannelListWidgetItem, pChannelItemWidget);
        }
    }
}

void BCSignal::RefreshInputChannelName()
{
    // 刷新列表
    ui->m_pInputChannelTextTreeWidget->RefreshInputChannelName();

    // 刷新网格
    for (int i = 0; i < ui->m_pInputChannelVedioTabWidget->count(); i++) {
        QListWidget *pGroupChannelListWidget = dynamic_cast<QListWidget *>( ui->m_pInputChannelVedioTabWidget->widget( i ) );
        if (NULL == pGroupChannelListWidget)
            continue;

        for (int j = 0; j < pGroupChannelListWidget->count(); j++) {
            QListWidgetItem *pChannelListWidgetItem = pGroupChannelListWidget->item( j );
            if (NULL == pChannelListWidgetItem)
                continue;

            // 取自定义的代理widget
            BCSignalListWidgetData *pInputChannelVedioItem = dynamic_cast<BCSignalListWidgetData *>( pGroupChannelListWidget->itemWidget( pChannelListWidgetItem ) );
            if (NULL == pInputChannelVedioItem)
                continue;

            pInputChannelVedioItem->RefreshInputChannelName();
        }
    }
}

BCMChannel* BCSignal::GetCurrentChannel()
{
    // 如果没有选择的item的则直接返回NULL
    if ( ui->m_pInputChannelTextTreeWidget->selectedItems().isEmpty() )
        return NULL;

    BCSignalTreeWidgetItem *pItem = dynamic_cast<BCSignalTreeWidgetItem *>( ui->m_pInputChannelTextTreeWidget->selectedItems().first() );
    if (NULL == pItem)
        return NULL;

    if ( !pItem->IsChannel() )
        return NULL;

    return pItem->GetChannel();
}

void BCSignal::on_m_pShowModeComboBox_currentIndexChanged(int index)
{
    bool bShowVedioList = (0 == index) ? false : true;
    ui->m_pInputChannelTextTreeWidget->setVisible( !bShowVedioList );
    ui->m_pInputChannelVedioTabWidget->setVisible( bShowVedioList );
    ui->m_pShowVedioCheckBox->setEnabled( bShowVedioList );

    m_bTempCloseEcho = !bShowVedioList;
    onRefreshVedioStatus();
}

void BCSignal::onActionTriggered(int /*value*/)
{
    // 1秒钟后刷新状态
    beginTime = QTime::currentTime();
    QTimer::singleShot(1000, this, SLOT(onRefreshVedioStatus()));
}


void BCSignal::onRangeChanged(int min, int max)
{
    // 记录滚动轴的最大最小值
    m_nScrollMinValue = min;
    m_nScrollMaxValue = max;
}

void BCSignal::onRefreshVedioStatus()
{
    // 如果不显示视频直接返回
    if ( !m_bShowVedio )
        return;

    // 如果连续多次操作滚动条则最后一次再刷新
    int nOffsetTime = beginTime.msecsTo( QTime::currentTime() );
    if (nOffsetTime < 1000)
        return;

    QListWidget *m_pInputChannelVedioListWidget = dynamic_cast<QListWidget *>( ui->m_pInputChannelVedioTabWidget->currentWidget() );
    if (NULL == m_pInputChannelVedioListWidget)
        return;

    // 计算滚动条的范围
    int nScrollViewHeight = m_pInputChannelVedioListWidget->verticalScrollBar()->height();
    int nScrollMinValue = m_pInputChannelVedioListWidget->verticalScrollBar()->value();
    int nScrollMaxValue = nScrollMinValue+nScrollViewHeight;
    double dSingleChannelHeight = 1.0*(m_nScrollMaxValue-m_nScrollMinValue+nScrollViewHeight)/m_pInputChannelVedioListWidget->count();

    QListWidgetItem *pItem = NULL;
    BCSignalListWidgetData *pInputChannelVedioItem = NULL;
    for (int i = 0; i < m_pInputChannelVedioListWidget->count(); i++) {
        pItem = m_pInputChannelVedioListWidget->item(i);
        if (NULL == pItem)
            continue;

        // 取自定义的代理widget
        pInputChannelVedioItem = dynamic_cast<BCSignalListWidgetData *>( m_pInputChannelVedioListWidget->itemWidget( pItem ) );
        if (NULL == pInputChannelVedioItem)
            continue;

        // 计算每个通道的范围
        double dChannelMinValue = m_nScrollMinValue + i*dSingleChannelHeight;
        double dChannelMaxValue = dChannelMinValue + dSingleChannelHeight;

        // 判断是否相交
        bool bPreview = false;
        if ( !m_bTempCloseEcho ) {
            if (((dChannelMinValue >= nScrollMinValue) && (dChannelMinValue <= nScrollMaxValue))
                    || ((dChannelMaxValue >= nScrollMinValue) && (dChannelMaxValue <= nScrollMaxValue))) {
                // 打开回显
                bPreview = true;
            }
        }

        pInputChannelVedioItem->SetEcho( bPreview );
    }
}

void BCSignal::on_m_pInputChannelVedioTabWidget_currentChanged(int index)
{
    // 暂时关闭其他tab页的视频
    for (int i = 0; i < ui->m_pInputChannelVedioTabWidget->count(); i++) {
        QListWidget *m_pInputChannelVedioListWidget = dynamic_cast<QListWidget *>( ui->m_pInputChannelVedioTabWidget->widget(i) );
        if (NULL == m_pInputChannelVedioListWidget)
            return;

        // 计算滚动条的范围
        int nScrollViewHeight = m_pInputChannelVedioListWidget->verticalScrollBar()->height();
        int nScrollMinValue = m_pInputChannelVedioListWidget->verticalScrollBar()->value();
        int nScrollMaxValue = nScrollMinValue+nScrollViewHeight;
        double dSingleChannelHeight = 1.0*(m_nScrollMaxValue-m_nScrollMinValue+nScrollViewHeight)/m_pInputChannelVedioListWidget->count();

        QListWidgetItem *pItem = NULL;
        BCSignalListWidgetData *pInputChannelVedioItem = NULL;
        for (int j = 0; j < m_pInputChannelVedioListWidget->count(); j++) {
            pItem = m_pInputChannelVedioListWidget->item(j);
            if (NULL == pItem)
                continue;

            // 取自定义的代理widget
            pInputChannelVedioItem = dynamic_cast<BCSignalListWidgetData *>( m_pInputChannelVedioListWidget->itemWidget( pItem ) );
            if (NULL == pInputChannelVedioItem)
                continue;

            // 计算每个通道的范围
            double dChannelMinValue = m_nScrollMinValue + j*dSingleChannelHeight;
            double dChannelMaxValue = dChannelMinValue + dSingleChannelHeight;

            // 判断是否相交
            bool bPreview = false;
            if ( !m_bTempCloseEcho ) {
                if (((dChannelMinValue >= nScrollMinValue) && (dChannelMinValue <= nScrollMaxValue))
                        || ((dChannelMaxValue >= nScrollMinValue) && (dChannelMaxValue <= nScrollMaxValue))) {
                    // 打开回显
                    bPreview = true;
                }
            }

            // 如果不是当前页则全部关闭回显
            if (i != index)
                bPreview = false;

            pInputChannelVedioItem->SetEcho( bPreview );
        }
    }
}

void BCSignal::on_m_pShowVedioCheckBox_clicked(bool bPreview)
{
    if (m_bShowVedio == bPreview)
        return;

    for (int i = 0; i < ui->m_pInputChannelVedioTabWidget->count(); i++) {
        QListWidget *pGroupChannelListWidget = dynamic_cast<QListWidget *>( ui->m_pInputChannelVedioTabWidget->widget( i ) );
        if (NULL == pGroupChannelListWidget)
            continue;

        for (int j = 0; j < pGroupChannelListWidget->count(); j++) {
            QListWidgetItem *pChannelListWidgetItem = pGroupChannelListWidget->item( j );
            if (NULL == pChannelListWidgetItem)
                continue;

            // 取自定义的代理widget
            BCSignalListWidgetData *pInputChannelVedioItem = dynamic_cast<BCSignalListWidgetData *>( pGroupChannelListWidget->itemWidget( pChannelListWidgetItem ) );
            if (NULL == pInputChannelVedioItem)
                continue;

            pInputChannelVedioItem->SetEcho( bPreview );
        }
    }

    m_bShowVedio = bPreview;
}

bool BCSignal::event(QEvent *event)
{
    if (NULL == m_pHeaderBtn)
        return false;

    // 如果隐藏则不出发悬停事件
    if ( !m_pHeaderBtn->IsVisible() )
        return false;

    if (event->type() == QEvent::HoverEnter || event->type() == QEvent::HoverLeave
            || event->type() == QEvent::HoverMove) {
        QHoverEvent* pHoverEvent = static_cast<QHoverEvent *>(event);

        // 判断是否需要调整窗口大小，下面为距离左上角的值
        int nltx = pHoverEvent->pos().x() - rect().x();
        int nlty = pHoverEvent->pos().y() - rect().y();

        // x在修改范围时
        if (nltx <= BCCommon::g_nMaxSizeOfModifyRect) {
            m_bModifyHeight = false;
            setCursor(Qt::ArrowCursor);
        } else if (qAbs(nltx-rect().width()) <= BCCommon::g_nMaxSizeOfModifyRect) {
            m_bModifyHeight = false;
            setCursor(Qt::ArrowCursor);
        } else {
            if (nlty <= BCCommon::g_nMaxSizeOfModifyRect) {
                // ↑
                m_bModifyHeight = true;
                setCursor(Qt::SizeVerCursor);
            } else if (qAbs(nlty-rect().height()) <= BCCommon::g_nMaxSizeOfModifyRect) {
                // ↓
                m_bModifyHeight = true;
                setCursor(Qt::SizeVerCursor);
            } else {
                // 不拉伸
                m_bModifyHeight = false;
                setCursor(Qt::ArrowCursor);
            }
        }
    }

    return QWidget::event(event);
}

void BCSignal::mousePressEvent(QMouseEvent *e)
{
    if ((e->button() == Qt::LeftButton) && m_bModifyHeight) {
        m_bPress = true;
    }

    QWidget::mousePressEvent( e );
}

void BCSignal::mouseMoveEvent(QMouseEvent *e)
{
    if( m_bPress ) {
        m_minHeight = e->pos().y() - m_pHeaderBtn->height() - 10;

        ui->m_pBodyFrame->setMinimumHeight( m_minHeight );
    }

    QWidget::mouseMoveEvent( e );
}

void BCSignal::mouseReleaseEvent(QMouseEvent *e)
{
    m_bPress = false;

    QWidget::mouseReleaseEvent( e );
}
