#include "BCPlanMapGraphicsView.h"

#include <QResizeEvent>
#include <QScrollBar>
#include "BCPlanMapGraphicsRectItem.h"
#include "BCPlanMapButtonGraphicsItem.h"
BCPlanMapGraphicsView::BCPlanMapGraphicsView(QWidget *parent)
    :QGraphicsView( parent )
{
    // 初始化地图
    QGraphicsScene *pScene = new QGraphicsScene( this );
    this->setScene( pScene );

    // 添加按钮管理类
    m_pGraphicsManager = new BCPlanMapGraphicsRectItem();
    pScene->addItem( m_pGraphicsManager );

    // 添加图片对象
    m_pPixmapItem = NULL;

    m_dScale = 1.0;
    m_dScaleStep = 0.1;
    m_nPressType = 0;

    this->setMouseTracking( true );
}

BCPlanMapGraphicsView::~BCPlanMapGraphicsView()
{
    // delete items
    QGraphicsScene *pScene = this->scene();
    QList<QGraphicsItem *> lst = pScene->items();
    while ( !lst.isEmpty() )
        delete lst.takeFirst();

    // delete scene
    delete pScene;
    pScene = NULL;
}

void BCPlanMapGraphicsView::resizeEvent(QResizeEvent *e)
{
    QSize size = e->size();
    m_sizeView = size;
    QGraphicsScene *pScene = this->scene();

    // 有地图时secene尺寸和地图尺寸一致
    if (NULL == m_pPixmapItem) {
        pScene->setSceneRect(0, 0, size.width(), size.height());
    } else {
        pScene->setSceneRect(0, 0, m_pPixmapItem->boundingRect().width(), m_pPixmapItem->boundingRect().height());
    }

    m_pGraphicsManager->setRect(0, 0, pScene->sceneRect().width(), pScene->sceneRect().height());
}

void BCPlanMapGraphicsView::mousePressEvent(QMouseEvent *e)
{
    if (e->button()== Qt::LeftButton) {
        m_nPressType = IsPlanMapButton( this->mapToScene(e->pos()) ) ? 1 : 2;

        if (NULL == m_pPixmapItem) {
            setCursor( Qt::ArrowCursor );
        } else {
            m_ptStart = e->pos();
            setCursor( Qt::ClosedHandCursor );
        }
    }

    QGraphicsView::mousePressEvent( e );
}

void BCPlanMapGraphicsView::mouseMoveEvent(QMouseEvent *e)
{
    if (NULL != m_pPixmapItem) {
        if (0 != m_nPressType) {
            setCursor( Qt::ClosedHandCursor );

            if (2 == m_nPressType) {
                int offsetX = e->pos().x() - m_ptStart.x();
                int offsetY = e->pos().y() - m_ptStart.y();
                m_ptStart = e->pos();

                int nScrollVValue = this->verticalScrollBar()->value();
                int nScrollHValue = this->horizontalScrollBar()->value();
                this->verticalScrollBar()->setValue(nScrollVValue - offsetY);
                this->horizontalScrollBar()->setValue(nScrollHValue - offsetX);
            }
        }
        else
            setCursor( Qt::OpenHandCursor );
    } else {
        setCursor( Qt::ArrowCursor );
    }
    QGraphicsView::mouseMoveEvent( e );
}

void BCPlanMapGraphicsView::mouseReleaseEvent(QMouseEvent *e)
{
    m_nPressType = 0;
    if (NULL == m_pPixmapItem) {
        setCursor( Qt::ArrowCursor );
    } else {
        setCursor( Qt::OpenHandCursor );
    }
    QGraphicsView::mouseReleaseEvent( e );
}

bool BCPlanMapGraphicsView::IsPlanMapButton(QPointF pt)
{
    QGraphicsScene *pScene = this->scene();
    QList<QGraphicsItem *> lstItems = pScene->items( pt );
    QListIterator<QGraphicsItem *> it( lstItems );
    while ( it.hasNext() ) {
        // 自定义按钮
        BCPlanMapButtonGraphicsItem *pButton = dynamic_cast<BCPlanMapButtonGraphicsItem *>( it.next() );
        if (NULL != pButton) {
            return true;
        }
    }

    return false;
}

void BCPlanMapGraphicsView::AddPlanMap(const QString &path)
{
    m_qsMapPath = path;
    QGraphicsScene *pScene = this->scene();

    if (NULL == m_pPixmapItem) {
        m_pPixmapItem = new QGraphicsPixmapItem();
        pScene->addItem( m_pPixmapItem );
    }

    m_pPixmapItem->setPixmap( QPixmap( path ) );

    // 重新对scene赋值
    pScene->setSceneRect(0, 0, m_pPixmapItem->boundingRect().width(), m_pPixmapItem->boundingRect().height());

    m_pGraphicsManager->setRect(0, 0, pScene->sceneRect().width(), pScene->sceneRect().height());
}

void BCPlanMapGraphicsView::ClearPlanMap()
{
    // 删除地图
    if (NULL != m_pPixmapItem) {
        delete m_pPixmapItem;
        m_pPixmapItem = NULL;
    }

    // 更新缩放比例
    m_dScale = 1.0;
    resetTransform();

    // 重新对scene赋值
    QGraphicsScene *pScene = this->scene();
    pScene->setSceneRect(0, 0, m_sizeView.width(), m_sizeView.height());

    m_pGraphicsManager->setRect(0, 0, pScene->sceneRect().width(), pScene->sceneRect().height());
}

void BCPlanMapGraphicsView::ZoomIn()
{
    m_dScale += m_dScaleStep;

    resetTransform();
    scale(m_dScale, m_dScale);
}

void BCPlanMapGraphicsView::ZoomOut()
{
    m_dScale -= m_dScaleStep;

    resetTransform();
    scale(m_dScale, m_dScale);
}

void BCPlanMapGraphicsView::ZoomFitBest()
{
    m_dScale = 1.0;
    resetTransform();

    if (NULL != m_pPixmapItem) {
        m_pPixmapItem->setPixmap( QPixmap::fromImage( QImage(m_qsMapPath).scaled(m_sizeView, Qt::IgnoreAspectRatio) ) );

        // 重新对scene赋值
        QGraphicsScene *pScene = this->scene();
        pScene->setSceneRect(0, 0, m_sizeView.width(), m_sizeView.height());

        m_pGraphicsManager->setRect(0, 0, pScene->sceneRect().width(), pScene->sceneRect().height());
    }
}

void BCPlanMapGraphicsView::ZoomOriginal()
{
    m_dScale = 1.0;
    resetTransform();

    if (NULL != m_pPixmapItem) {
        m_pPixmapItem->setPixmap( QPixmap( m_qsMapPath ) );

        // 重新对scene赋值
        QGraphicsScene *pScene = this->scene();
        pScene->setSceneRect(0, 0, m_pPixmapItem->boundingRect().width(), m_pPixmapItem->boundingRect().height());

        m_pGraphicsManager->setRect(0, 0, pScene->sceneRect().width(), pScene->sceneRect().height());
    }
}
