/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：嵌套在单个显示屏或者信号窗内的矩形框
* 说    明：ZValue默认为11
*********************************************************************************************************************************/
#ifndef BCVIRTUALRECTDISPLAYITEM_H
#define BCVIRTUALRECTDISPLAYITEM_H

#include "BCDisplayItem.h"

class BCBackGroundDisplayItem;
class BCMDisplayRect;
class BCVirtualRectDisplayItem : public BCDisplayItem
{
public:
    BCVirtualRectDisplayItem(double x, double y, double w, double h, BCMDisplayRect *pMRect, QGraphicsItem * parent);
    ~BCVirtualRectDisplayItem();

    BCVirtualRectDisplayItem(const BCVirtualRectDisplayItem &item);
    BCVirtualRectDisplayItem *Clone();

    const QString &GetVirtualRectID();
    void SetVirtualRectID(const QString &id);

    // 设置矩形类型，对应不同的绘制属性
    void SetRectType(int type);
    int GetRectType();

    // 设置高亮
    void SetHighLight(bool b);
    bool IsHighLight();

protected:
    // 绘制背景色
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);

protected:
    BCMDisplayRect      *m_pMRect;  // 矩形数据类

    QString m_id;                       // 如果是显示屏内矩形，会对应ID
    int m_nType;                    // 0为单个显示器内虚拟窗，1为信号窗内虚拟窗，2为虚拟开窗
    int m_nVirtualRectFillColorA;   // 矩形填充透明度
};

inline void BCVirtualRectDisplayItem::SetRectType(int type)
{
    m_nType = type;
}

inline int BCVirtualRectDisplayItem::GetRectType()
{
    return m_nType;
}

inline const QString &BCVirtualRectDisplayItem::GetVirtualRectID()
{
    return m_id;
}

inline void BCVirtualRectDisplayItem::SetVirtualRectID(const QString &id)
{
    m_id = id;
}

#endif // BCVIRTUALRECTDISPLAYITEM_H
