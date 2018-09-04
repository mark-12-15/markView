/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：信号窗标题类
* 说    明：内部包含四个按钮和窗体名称说明
*********************************************************************************************************************************/
#ifndef BCSIGNALWINDOWTITLEDISPLAYITEM_H
#define BCSIGNALWINDOWTITLEDISPLAYITEM_H

#include "BCDisplayItem.h"
#include "BCButtonDisplayItem.h"

class BCTextDisplayItem;
class BCSignalWindowTitleDisplayItem : public BCDisplayItem
{
public:
    BCSignalWindowTitleDisplayItem(double x, double y, double w, double h, QGraphicsItem * parent = 0, int r = 0);
    ~BCSignalWindowTitleDisplayItem();

    void ResizeRect(double x, double y, double w, double h);

    // 刷新按钮图标
    void RefreshButtonIcon();

    // 文字设置
    void SetDisplayText(const QString &qsText);
    const QString &GetDisplayText();

    // 刷新文字设置
    void RefreshDisplayTextColor();
    void RefreshDisplayTextFont();
    void RefreshDisplayTextPos();
    void RefreshIsShowDisplayItem();

    // 单独设置可见性
    void SetTextItemVisible(bool b);
    bool IsTextItemVisible();

    void SetLockButtonVisible(bool b);
    bool IsLockButtonVisible();

    void SetFullSceneButtonVisible(bool b);
    bool IsFullSceneButtonVisible();

    void SetWindowButtonVisible(bool b);
    bool IsWindowButtonVisible();

    void SetCloseButtonVisible(bool b);
    bool IsCloseButtonVisible();

    // 返回信号窗标题绘制区域
    const QRectF &GetSignalWindowTitlePaintRect();

protected:
    // 绘制背景色
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);

private:
    QString m_qsTitle;
    BCTextDisplayItem *m_pTextItem;         // 文字显示块

    BCButtonDisplayItem *m_pBtnLock;        // 锁定按钮
    BCButtonDisplayItem *m_pBtnFullscreen;  // 全屏按钮
    BCButtonDisplayItem *m_pBtnWindowShow;  // 窗口化按钮，退出全屏
    BCButtonDisplayItem *m_pBtnClose;       // 关闭按钮

    QRectF m_rectPaint; // 绘制矩形，如窗口拖动到屏组外部，外部区域不绘制

    // 单独开关
    bool m_bTextItemVisible;
    bool m_bLockBtnVisible;
    bool m_bFullscreenBtnVisible;
    bool m_bWindowBtnVisible;
    bool m_bCloseBtnVisible;
};

inline const QRectF &BCSignalWindowTitleDisplayItem::GetSignalWindowTitlePaintRect()
{
    return m_rectPaint;
}

inline const QString &BCSignalWindowTitleDisplayItem::GetDisplayText()
{
    return m_qsTitle;
}

#endif // BCSIGNALWINDOWTITLEDISPLAYITEM_H
