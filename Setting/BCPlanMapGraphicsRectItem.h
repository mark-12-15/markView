/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：预案地图自定义按钮管理类，主要实现dropEvent
*********************************************************************************************************************************/
#ifndef BCPLANMAPGRAPHICSRECTITEM_H
#define BCPLANMAPGRAPHICSRECTITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneDragDropEvent>

class BCPlanMapButtonGraphicsItem;
class BCPlanMapGraphicsRectItem : public QGraphicsRectItem
{
public:
    BCPlanMapGraphicsRectItem(QGraphicsItem *parent = 0);
    ~BCPlanMapGraphicsRectItem();

private:
    void dropEvent(QGraphicsSceneDragDropEvent *e);

    bool IsExistButton(const QString &id);
    void AddButton(BCPlanMapButtonGraphicsItem *pButton);

private:
    QList<BCPlanMapButtonGraphicsItem *>    m_lstButtonItem;
};

#endif // BCPLANMAPGRAPHICSRECTITEM_H
