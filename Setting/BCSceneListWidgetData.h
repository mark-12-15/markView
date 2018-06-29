#ifndef BCSCENELISTWIDGETDATA_H
#define BCSCENELISTWIDGETDATA_H

#include <QGraphicsView>
#include <QGraphicsRectItem>

// 场景专用的矩形框
class BCSceneListWidgetDataRectItem : public QGraphicsRectItem
{
public:
    BCSceneListWidgetDataRectItem(int type, const QString &name, QGraphicsItem *parent = NULL);

    int m_type;
    QString m_name;

private:
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget*/);
};

class BCMWindowScene;
class QLabel;
class BCSceneListWidgetData : public QWidget
{
public:
    BCSceneListWidgetData(BCMWindowScene *pWindowScene, QWidget *parent=NULL);
    ~BCSceneListWidgetData();

private:
    void resizeEvent(QResizeEvent * event);
    void contextMenuEvent(QContextMenuEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

    void Refresh();

private:
    QGraphicsView   *m_pGraphicsView;
    QGraphicsScene  *m_pScene;
    BCMWindowScene  *m_pWindowScene;
    QLabel          *m_pStatusLabel;
};

#endif // BCSCENELISTWIDGETDATA_H
