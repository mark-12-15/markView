#include "BCPlanMapGraphicsRectItem.h"
#include <QMimeData>
#include <QGraphicsScene>
#include <QDataStream>

#include "BCPlanMapDlg.h"
#include "BCPlanMapGraphicsView.h"
#include "BCPlanMapButtonGraphicsItem.h"
BCPlanMapGraphicsRectItem::BCPlanMapGraphicsRectItem(QGraphicsItem *parent)
    :QGraphicsRectItem( parent )
{
    this->setAcceptDrops( true );
    this->setZValue( 10 );  // 保证在地图上面

    this->setAcceptHoverEvents( true );
}

BCPlanMapGraphicsRectItem::~BCPlanMapGraphicsRectItem()
{
}

void BCPlanMapGraphicsRectItem::dropEvent(QGraphicsSceneDragDropEvent *e)
{
    if (e->mimeData()->hasFormat("systemPlan")) {
        const QMimeData *mimeData = e->mimeData();
        QByteArray exData = mimeData->data("systemPlan");
        QDataStream dataStream (&exData, QIODevice::ReadOnly);
        QList<QString> lstData;

        dataStream >> lstData;

        QString id = lstData.at(0);
        QString text = lstData.at(1);

        // 不包含当前ID时则新建
        if ( !IsExistButton(id) ) {
            BCPlanMapButtonGraphicsItem *pButtonItem = new BCPlanMapButtonGraphicsItem(id, text, e->pos(), this);

            AddButton( pButtonItem );
        }
    }
}

void BCPlanMapGraphicsRectItem::AddButton(BCPlanMapButtonGraphicsItem *pButton)
{
    // 首先添加到本类链表中
    m_lstButtonItem.append( pButton );

    // 添加到对话框中
    QList<QGraphicsView *> lstViews = this->scene()->views();
    if ( lstViews.isEmpty() )
        return;

    BCPlanMapGraphicsView *pView = dynamic_cast<BCPlanMapGraphicsView *>( lstViews.at(0) );
    if (NULL == pView)
        return;

    BCPlanMapDlg *pDlg = dynamic_cast<BCPlanMapDlg *>( pView->parentWidget() );
    if (NULL == pDlg)
        return;

    pDlg->AddButton( pButton );
}

bool BCPlanMapGraphicsRectItem::IsExistButton(const QString &id)
{
    QListIterator<BCPlanMapButtonGraphicsItem *> it( m_lstButtonItem );
    while ( it.hasNext() ) {
        BCPlanMapButtonGraphicsItem *pItem = it.next();
        if (NULL == pItem)
            continue;

        if (pItem->GetID() == id)
            return true;
    }

    return false;
}
