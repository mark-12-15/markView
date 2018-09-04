#include "BCToolBarMatrixWidgetData.h"
#include <QMenu>
#include <QDropEvent>
#include <QMimeData>
#include "BCDisplayItemManager.h"
#include "BCBackGroundDisplayItem.h"
#include "../Common/BCCommon.h"
#include "BCDisplayItemManager.h"
#include "BCSignalWindowDisplayItem.h"

// 定义预监窗口的尺寸
#define REVIEWWIDTH     214
#define REVIEWHEIGHT    130

BCToolBarMatrixWidget::BCToolBarMatrixWidget(QWidget *parent) :
    QListWidget(parent)
{
    this->setViewMode(QListView::IconMode);
    this->setResizeMode( QListView::Adjust);
    this->setFlow(QListView::LeftToRight);
    this->setSpacing(16);

    m_nOutputCount = 8;
    Refresh();
}

BCToolBarMatrixWidget::~BCToolBarMatrixWidget()
{
    this->clear();
}

void BCToolBarMatrixWidget::Refresh()
{
    // 清空链表
    this->clear();

    for(int i = 0; i < m_nOutputCount; i++) {
        QListWidgetItem *pItem = new QListWidgetItem();
        pItem->setSizeHint(QSize(REVIEWWIDTH, REVIEWHEIGHT));

        this->addItem(pItem);

        // item关联Widget
        this->setItemWidget(pItem, new BCToolBarMatrixWidgetData(i, this));
    }
}

void BCToolBarMatrixWidget::SetSignalWindowNULL(int winid)
{
    for(int i = 0; i < m_nOutputCount; i++) {
        QListWidgetItem *pItem = this->item( i );
        if (NULL == pItem)
            continue;

        BCToolBarMatrixWidgetData *pWidget = dynamic_cast<BCToolBarMatrixWidgetData *>( this->itemWidget( pItem ) );
        if (NULL == pWidget)
            continue;

        pWidget->SetSignalWindowNULL( winid );
    }
}

// ---------------------------------------------------------------------------------------------------------------------

BCToolBarMatrixWidgetData::BCToolBarMatrixWidgetData(int index, BCToolBarMatrixWidget *pMatrixWidget) :
    QGraphicsView(pMatrixWidget)
{
    this->setAcceptDrops(true);
    this->setMaximumWidth( REVIEWWIDTH );
    this->setMinimumWidth( REVIEWWIDTH );

    // 设置显示名称
    m_pMatrixWidget = pMatrixWidget;

    m_nSegCount = 1;

    m_pScene = new QGraphicsScene( this );
    setScene( m_pScene );

    // 构造开窗管理类
    m_pSignalManager = new BCDisplayItemManager(0, 0, 100, 100);
    m_pSignalManager->SetDisplayItemType( BCCommon::SIGNALWINDOWMANAGER );  // !!!
    m_pScene->addItem( m_pSignalManager );
    m_pSignalManager->setZValue( 10 );  // !!! 必须指定，否则默认为0

    // 添加屏组
    m_pGroupDisplay = new BCDisplayItemManager(0, 0, 100, 100, NULL);
    m_pGroupDisplay->SetSimpleDevice( true );
    m_pScene->addItem( m_pGroupDisplay );

    // 添加单屏
    BCBackGroundDisplayItem *pDisplayItem = new BCBackGroundDisplayItem(0, 0, 100, 100, NULL, m_pGroupDisplay);
    pDisplayItem->SetDisplayText("123");
    pDisplayItem->RefreshSegmentation( 1 );

    m_pSignalWindow1 = NULL;
    m_pSignalWindow2 = NULL;
    m_pSignalWindow3 = NULL;
    m_pSignalWindow4 = NULL;
}

BCToolBarMatrixWidgetData::~BCToolBarMatrixWidgetData()
{
    // delete managers
    QList<QGraphicsItem *> lst = m_pScene->items();
    QListIterator<QGraphicsItem *> it( lst );
    while (it.hasNext()) {
        BCDisplayItemManager *pMgr = dynamic_cast<BCDisplayItemManager *>( it.next() );
        if (NULL == pMgr)
            continue;

        delete pMgr;
        pMgr = NULL;
    }

    // delete scene
    delete m_pScene;
    m_pScene = NULL;
}

void BCToolBarMatrixWidgetData::resizeEvent(QResizeEvent * event)
{
    QSize size = event->size();

    // 修改scene尺寸
    m_pScene->setSceneRect( 0.0, 0.0, size.width(), size.height() );

    BCDisplayItemManager *pItemMgr = NULL;
    QList<QGraphicsItem*> lstItems = m_pScene->items();
    QListIterator<QGraphicsItem*> it( lstItems );
    while ( it.hasNext() ) {
        pItemMgr = dynamic_cast<BCDisplayItemManager *>( it.next() );
        if (NULL == pItemMgr)
            continue;

        // 信号窗管理类单独设置
        if (m_pSignalManager == pItemMgr)
            continue;

        double dX = pItemMgr->GetRectItemRelativePos().x()*0.01 * size.width();
        double dY = pItemMgr->GetRectItemRelativePos().y()*0.01 * size.height();
        double dW = pItemMgr->GetRectItemRelativePos().width()*0.01 * size.width();
        double dH = pItemMgr->GetRectItemRelativePos().height()*0.01 * size.height();

        pItemMgr->ResizeRect(dX, dY, dW, dH);
    }

    // !!! 设置信号窗尺寸，必须在其他屏组之后设置，因为信号窗边界是根据屏组边界计算的，只有屏组尺寸正确才能确保信号窗尺寸正确
    m_pSignalManager->ResizeRect(0.0, 0.0, size.width(), size.height());

    event->accept();
}

void BCToolBarMatrixWidgetData::contextMenuEvent(QContextMenuEvent* /*event*/){
    QMenu menu;
    QAction *pSeg1Action = menu.addAction(tr("整屏"));
    QAction *pSeg4Action = menu.addAction(tr("四分屏"));

    pSeg1Action->setCheckable(true);
    pSeg4Action->setCheckable(true);

    pSeg1Action->setChecked( (1 == m_nSegCount) ? true : false );
    pSeg4Action->setChecked( (4 == m_nSegCount) ? true : false );

    // 显示menu
    QAction *pSelectAction = menu.exec(QCursor::pos());
    if (pSelectAction == pSeg1Action) {
        SetSegmentation( 1 );
    }
    if (pSelectAction == pSeg4Action) {
        SetSegmentation( 4 );
    }
}

void BCToolBarMatrixWidgetData::SetSegmentation(int n)
{
    m_nSegCount = n;
    m_pGroupDisplay->RefreshSegmentation( m_nSegCount );

    if (1 == m_nSegCount) {
        if (NULL != m_pSignalWindow1) {
            m_pSignalWindow1->SetRectItemRelativePos(QRectF(0, 0, 100, 100));
            m_pSignalWindow1->ResizeRect(0, 0, this->size().width(), this->size().height());
        }

        if (NULL != m_pSignalWindow2) {
            m_pSignalWindow2->setVisible( false );
        }
        if (NULL != m_pSignalWindow3) {
            m_pSignalWindow3->setVisible( false );
        }
        if (NULL != m_pSignalWindow4) {
            m_pSignalWindow4->setVisible( false );
        }
    } else if (4 == m_nSegCount) {
        if (NULL != m_pSignalWindow1) {
            m_pSignalWindow1->SetRectItemRelativePos(QRectF(0, 0, 50, 50));
            m_pSignalWindow1->ResizeRect(0, 0, this->size().width()/2, this->size().height()/2);
        }

        if (NULL != m_pSignalWindow2) {
            m_pSignalWindow2->setVisible( true );
        }
        if (NULL != m_pSignalWindow3) {
            m_pSignalWindow3->setVisible( true );
        }
        if (NULL != m_pSignalWindow4) {
            m_pSignalWindow4->setVisible( true );
        }
    }

    this->update();
}

// 拖放
void BCToolBarMatrixWidgetData::dropEvent(QDropEvent* e)
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

        MainWindow *pMainWindow = BCCommon::Application();
        BCMChannel *pChannel = pMainWindow->GetInputChannel(nDropChID, nDropChType);

        if (1 == m_nSegCount) {
            if (NULL == m_pSignalWindow1) {
                m_pSignalWindow1 = new BCSignalWindowDisplayItem(m_pGroupDisplay, 0, 0, 100, 100, pChannel, 0, m_pSignalManager, false);
                m_pSignalWindow1->SetLock( true );
            } else {
                m_pSignalWindow1->SetInputChannel( pChannel );
                m_pSignalWindow1->SetRectItemRelativePos(QRectF(0, 0, 100, 100));
                m_pSignalWindow1->ResizeRect(0, 0, this->size().width(), this->size().height());
            }
        } else if (4 == m_nSegCount) {
            int left = e->pos().x() < (REVIEWWIDTH/2) ? 0 : 50;
            int top = e->pos().y() < (REVIEWHEIGHT/2) ? 0 : 50;

            if (0 == left) {
                if (0 == top) {
                    if (NULL == m_pSignalWindow1) {
                        m_pSignalWindow1 = new BCSignalWindowDisplayItem(m_pGroupDisplay, left, top, 50, 50, pChannel, 0, m_pSignalManager, false);
                        m_pSignalWindow1->SetLock( true );
                    } else {
                        m_pSignalWindow1->SetInputChannel( pChannel );
                        m_pSignalWindow1->SetRectItemRelativePos(QRectF(left, top, 50, 50));
                    }
                } else {
                    if (NULL == m_pSignalWindow3) {
                        m_pSignalWindow3 = new BCSignalWindowDisplayItem(m_pGroupDisplay, left, top, 50, 50, pChannel, 2, m_pSignalManager, false);
                        m_pSignalWindow3->SetLock( true );
                    } else {
                        m_pSignalWindow3->SetInputChannel( pChannel );
                        m_pSignalWindow3->SetRectItemRelativePos(QRectF(left, top, 50, 50));
                    }
                }
            } else {
                if (0 == top) {
                    if (NULL == m_pSignalWindow2) {
                        m_pSignalWindow2 = new BCSignalWindowDisplayItem(m_pGroupDisplay, left, top, 50, 50, pChannel, 1, m_pSignalManager, false);
                        m_pSignalWindow2->SetLock( true );
                    } else {
                        m_pSignalWindow2->SetInputChannel( pChannel );
                        m_pSignalWindow2->SetRectItemRelativePos(QRectF(left, top, 50, 50));
                    }
                } else {
                    if (NULL == m_pSignalWindow4) {
                        m_pSignalWindow4 = new BCSignalWindowDisplayItem(m_pGroupDisplay, left, top, 50, 50, pChannel, 3, m_pSignalManager, false);
                        m_pSignalWindow4->SetLock( true );
                    } else {
                        m_pSignalWindow4->SetInputChannel( pChannel );
                        m_pSignalWindow4->SetRectItemRelativePos(QRectF(left, top, 50, 50));
                    }
                }
            }
        }
    }
}

void BCToolBarMatrixWidgetData::SetSignalWindowNULL(int winid)
{
    if (1 == winid)
        m_pSignalWindow1 = NULL;
    else if (2 == winid)
        m_pSignalWindow2 = NULL;
    else if (3 == winid)
        m_pSignalWindow3 = NULL;
    else if (4 == winid)
        m_pSignalWindow4 = NULL;
}
