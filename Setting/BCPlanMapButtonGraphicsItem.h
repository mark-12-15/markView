/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：预案地图上的自定义按钮
*********************************************************************************************************************************/
#ifndef BCPLANMAPBUTTONGRAPHICSITEM_H
#define BCPLANMAPBUTTONGRAPHICSITEM_H

#include <QGraphicsRectItem>

class QTableWidgetItem;
class BCPlanMapButtonGraphicsItem : public QGraphicsRectItem
{
public:
    BCPlanMapButtonGraphicsItem(const QString &id, const QString &text, QPointF pos, QGraphicsItem *parent=0);
    ~BCPlanMapButtonGraphicsItem();

    const QString &GetID();
    const QString &GetText();
    //QPointF GetPos();

    void SetTableWidgetItem(QTableWidgetItem *pItem);

private:
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget*/);

    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
private:
    QGraphicsSimpleTextItem *m_pText;   // button text

    QTableWidgetItem    *m_pTableWidgetItem;

    QString m_qsId;
    QString m_qsText;
    bool m_bPress;
    double m_x;
    double m_y;
};

inline const QString &BCPlanMapButtonGraphicsItem::GetID()
{
    return m_qsId;
}

inline const QString &BCPlanMapButtonGraphicsItem::GetText()
{
    return m_qsText;
}

//inline QPointF BCPlanMapButtonGraphicsItem::GetPos()
//{
//    return mapToScene(rect().topLeft());
//}

#endif // BCPLANMAPBUTTONGRAPHICSITEM_H
