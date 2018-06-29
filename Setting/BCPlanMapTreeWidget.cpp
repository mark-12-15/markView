#include "BCPlanMapTreeWidget.h"
#include <QDropEvent>
#include <QMimeData>
#include <QDrag>
#include <QDebug>
#include <QByteArray>

BCPlanMapTreeWidget::BCPlanMapTreeWidget(QWidget *parent)
    :QTreeWidget( parent )
{
    m_bDrag = false;
    this->setAcceptDrops( true );
}

void BCPlanMapTreeWidget::mouseMoveEvent(QMouseEvent*/*event*/)
{
    if ( m_bDrag )
        return;

    // 当前选中的为空时直接返回
    QTreeWidgetItem *pCurrentItem = this->currentItem();
    if (NULL == pCurrentItem)
        return;

    QMimeData*mimeData=new QMimeData;    // 拖拽事件传递的数据参数
    QByteArray exData;
    QDataStream dataStream(&exData,QIODevice::WriteOnly);
    QStringList lstData;
    lstData << pCurrentItem->data(1, 0).toString() << pCurrentItem->text(0);
    dataStream << lstData;

    mimeData->setData("systemPlan", exData);
    QDrag *drag = new QDrag(this); // 将数据加载到对象中，可设置pixmap等显示
    drag->setMimeData(mimeData);
    drag->exec(); // 执行即可，参数默认为Qt::MoveAction，可将数据从src to target

    m_bDrag = true;
}

void BCPlanMapTreeWidget::mouseReleaseEvent(QMouseEvent*/*event*/)
{
    m_bDrag = false;
}

void BCPlanMapTreeWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("systemPlan"))
        event->accept();
    else
        event->ignore();
}
