/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：显示墙类
* 说    明：ZValue默认值为0，选中为1
*********************************************************************************************************************************/
#ifndef BCBACKGROUNDDISPLAYITEM_H
#define BCBACKGROUNDDISPLAYITEM_H

#include "BCDisplayItem.h"

class BCDisplayWallView;
class BCDisplayItemManager;
class BCVirtualRectDisplayItem;
class BCTextDisplayItem;
class BCMDisplay;
class BCMDisplayRect;
class BCBackGroundDisplayItem : public BCDisplayItem
{
public:
    BCBackGroundDisplayItem(double x, double y, double w, double h, BCMDisplay *pMDisplay, QGraphicsItem * parent);
    ~BCBackGroundDisplayItem();

    BCBackGroundDisplayItem(const BCBackGroundDisplayItem &item);
    BCBackGroundDisplayItem *Clone();
    bool IsClone();

    BCMDisplay *GetMDisplay();

    // 添加矩形框
    BCVirtualRectDisplayItem * AddVirtualRect(double x, double y, double w, double h, BCMDisplayRect *pMRect);

    // 重置矩形框和内部虚框大小
    void ResizeRect(double x, double y, double w, double h);

    // 刷新分割数
    void RefreshSegmentation(int n);
    int GetSegmentation();

    // 文字设置
    void SetDisplayText(const QString &qsText);
    void SetDisplayDefaultText(const QString &qsText);

    // 刷新文字设置
    void RefreshDisplayTextColor();
    void RefreshDisplayTextFont();
    void RefreshDisplayTextPos();
    void RefreshIsShowDisplayText();

    void SetHighLight(bool b);
    bool IsHighLight();

private:
    void InitVirtualRect();
    void SetDisplayTextPos(bool bDefaultText);

protected:
    // 菜单事件
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *e);

    // 鼠标事件拖动内部窗体
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);

    // 绘制背景色
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);

protected:
    bool m_bPress;
    double m_x;
    double m_y;

    BCTextDisplayItem *m_pDefaultTextItem;      // 文字显示块，显示区域位置，如2:1
    BCTextDisplayItem *m_pTextItem;             // 文字显示块，显示屏幕信息，如运行状态良好...

    BCMDisplay *m_pMDisplay;                    // 单个屏幕的数据类
    int         m_bSegmentation;                // 单屏的分割数，可以不与数据同步
                                                // 1 4 6 8 9 12 16

    bool    m_bClone;                           // 是否是克隆显示器，快速定位对话框中使用的是克隆
};

inline BCMDisplay *BCBackGroundDisplayItem::GetMDisplay()
{
    return m_pMDisplay;
}

inline bool BCBackGroundDisplayItem::IsClone()
{
    return m_bClone;
}

inline int BCBackGroundDisplayItem::GetSegmentation()
{
    return m_bSegmentation;
}

#endif // BCBACKGROUNDDISPLAYITEM_H
