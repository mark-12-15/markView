/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：信号窗body类
* 说    明：内部可能有不规则矩形块
*********************************************************************************************************************************/
#ifndef BCSIGNALWINDOWBODYDISPLAYITEM_H
#define BCSIGNALWINDOWBODYDISPLAYITEM_H

#include "BCDisplayItem.h"

class BCTextDisplayItem;
class BCSignalWindowBodySubDisplayItem;
class BCSignalWindowBodyDisplayItem : public QObject, public BCDisplayItem
{
    Q_OBJECT
public:
    BCSignalWindowBodyDisplayItem(double x, double y, double w, double h, QGraphicsItem * parent = 0, int r = 0);
    ~BCSignalWindowBodyDisplayItem();

    // 重置矩形框和内部虚框大小
    void ResizeRect(double x, double y, double w, double h);

    // 文字设置
    void SetDisplayText(const QString &qsText);
    void SetDisplayDefaultText(const QString &qsText);
    void SetDisplayIDText(const QString &qsText);

    // 刷新文字设置
    void RefreshDisplayTextColor();
    void RefreshDisplayTextFont();
    void RefreshDisplayTextPos();
    void RefreshIsShowDisplayText();

    // 返回信号窗标题绘制区域
    const QRectF &GetSignalWindowBodyPaintRect();

    // 设置回显
    void SetEcho(bool b);

    // 重置回显图片的透明度
    void ResetEchoA();

    // 刷新IPV矩形块，根据channel的通道数重新绘制矩形
    void RefreshIPVDisplayItem(int n);

    int GetIPVedioSegmentationCount();

    // 发送IPV链表
    void SendIPVedioListCmd();

    // 返回子窗口链表，目前只有IPV才有
    const QList<BCSignalWindowBodySubDisplayItem *> &GetSubDisplayItem();
    void SetIPVIP(const QStringList &lstIP);

    // 返回回显的句柄
    HWND GetEchoHandle();
    int GetChannelID();
    QSize GetEchoSize();
    int GetEchoA();
    void SetEchoPixmap(const QPixmap &pixmap);

private slots:
    void onGetEchoFrame();

private:
    void SetDisplayTextPos(bool bDefaultText);

protected:
    // 绘制背景色
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);

protected:
    BCTextDisplayItem *m_pDefaultTextItem;      // 文字显示块，默认右下角，显示通道号、名字、入口信号类型
    BCTextDisplayItem *m_pTextItem;             // 文字显示块，默认左上角，显示物理屏坐标
    BCTextDisplayItem *m_pDisplayItem;          // 文字显示块，默认左下角，显示单屏

    QRectF m_rectPaint; // 绘制矩形，如窗口拖动到屏组外部，外部区域不绘制

    QLabel              *m_pEchoLabel;      // 回显Label
    QGraphicsPixmapItem *m_pEchoPixmapItem; // 回显pixmapItem
    //QTimer              *m_pEchoTimer;      // 回显定时器
    QSize               m_EchoSize;         // 回显的尺寸
    int                 m_nFrameA;          // 图片的透明度，最多255

    int                                         m_nIPVSegmentation;     // IPV使用，分割数，默认是1个不分割
    QList<BCSignalWindowBodySubDisplayItem *>   m_lstSubDisplayItem;    // IPV窗口内的矩形块，16个固定，普通窗口链表为空
};

inline const QRectF &BCSignalWindowBodyDisplayItem::GetSignalWindowBodyPaintRect()
{
    return m_rectPaint;
}

inline const QList<BCSignalWindowBodySubDisplayItem *> &BCSignalWindowBodyDisplayItem::GetSubDisplayItem()
{
    return m_lstSubDisplayItem;
}

inline int BCSignalWindowBodyDisplayItem::GetIPVedioSegmentationCount()
{
    return m_nIPVSegmentation;
}

#endif // BCSIGNALWINDOWBODYDISPLAYITEM_H
