#include "graphview.h"
#include <QGraphicsRectItem>
#include <QScrollBar>
#include <QDebug>

GraphView::GraphView()
{


    QGraphicsScene *scene = new  QGraphicsScene();
    //QScrollBar *vbar = verticalScrollBar();
    //QScrollBar *hbar = horizontalScrollBar();
    scene->setSceneRect( 0, 0, 640, 480  );

    resize(640, 480);

    setFrameStyle(Sunken | StyledPanel);
    setRenderHint(QPainter::Antialiasing, false);
    setDragMode(QGraphicsView::RubberBandDrag);
    setOptimizationFlags(QGraphicsView::DontSavePainterState);
    setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);


    int x = 0;
    int y = 0;
    for (int i = 1; i <= 4; i++) {


        if (i == 2) {
            x += 100;
        }
        if (i == 3) {
            x = 0;
            y = 100;
        }
        if (i == 4) {
            x = 100;
            y = 100;
        }

       // QGraphicsRectItem  *rect=scene->addRect(QRectF(x,y,100,100));

        QGraphicsRectItem *rect = new QGraphicsRectItem(0, 0, 100, 100);
        scene->addItem(rect);
        rect->setPos(x, y);
        rect->setData(1, i);


        rect->setFlags( QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsSelectable );
        rect->setBrush( QBrush(QColor(0, 0, 0, 150)) );
    }



    this->setScene(scene);

    connect( scene, SIGNAL( focusItemChanged(QGraphicsItem *, QGraphicsItem *, Qt::FocusReason) ), this, SLOT( doIt(QGraphicsItem *, QGraphicsItem *, Qt::FocusReason) ));

}

void GraphView::doIt(QGraphicsItem * newFocusItem, QGraphicsItem * oldFocusItem, Qt::FocusReason reason)
{
    int index = newFocusItem->data(1).toInt();
    emit sendData(index);
}

