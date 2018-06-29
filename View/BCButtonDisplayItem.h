/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：自定义button类
*********************************************************************************************************************************/
#ifndef BCBUTTONDISPLAYITEM_H
#define BCBUTTONDISPLAYITEM_H

#include <QGraphicsPixmapItem>

class BCButtonDisplayItem : public QGraphicsPixmapItem
{
public:
    // 信号窗标题上按钮类型
    enum SIGNALWINDOWTITLEBUTTONTYPE {
        LOCK,       // 锁定按钮
        WINWOD,     // 窗口按钮
        FULLSCENE,  // 全屏按钮
        CLOSE       // 关闭按钮
    };

    BCButtonDisplayItem(SIGNALWINDOWTITLEBUTTONTYPE eType, QGraphicsItem * parent = 0);

    void RefreshIcon();

protected:
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);

    // 使用悬停事件更换图片展示按钮激活状态
    void hoverEnterEvent(QGraphicsSceneHoverEvent *);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *);

    // 响应按钮点击事件
    void mousePressEvent(QGraphicsSceneMouseEvent *);

    SIGNALWINDOWTITLEBUTTONTYPE m_eType; // 按钮类型
    QRectF  m_boundingRect; // 图片占的矩形位置
    QString m_qsIconPath;
};

#endif // BCBUTTONDISPLAYITEM_H
