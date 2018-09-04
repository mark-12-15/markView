#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QGraphicsView>
class GraphView : public QGraphicsView
{
    Q_OBJECT
public:
    GraphView();

signals:
    void sendData(int);

private slots:
    void doIt(QGraphicsItem * newFocusItem, QGraphicsItem * oldFocusItem, Qt::FocusReason reason);
};

#endif // GRAPHVIEW_H
