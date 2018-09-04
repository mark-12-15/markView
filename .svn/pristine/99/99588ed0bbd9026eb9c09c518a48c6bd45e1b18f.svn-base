#include "treewidget.h"
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <QDebug>


TreeWidget::TreeWidget(QWidget * parent) : QTreeWidget(parent)
{

}

void TreeWidget::mousePressEvent(QMouseEvent *event)
{
//    TreeWidget *child = static_cast<TreeWidget*>(childAt(event->pos()));
//    if (!child)
//        return;

   // QString str = this->selectedItems().at(0)->text(0);

    QString str = this->itemAt(event->pos())->text(0);

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << str;

    qDebug() << str;
//! [1]

//! [2]
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);
//! [2]

//! [3]
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
 //   drag->setPixmap(pixmap);
 //   drag->setHotSpot(event->pos() - child->pos());
//! [3]

//    QPixmap tempPixmap = pixmap;
//    QPainter painter;
//    painter.begin(&tempPixmap);
//    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
//    painter.end();

//    child->setPixmap(tempPixmap);

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
//        child->close();
//    } else {
//        child->show();
//        child->setPixmap(pixmap);
    }
}

