/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：单个显示器、开窗等窗体上的文字类
*********************************************************************************************************************************/
#ifndef BCTEXTDISPLAYITEM_H
#define BCTEXTDISPLAYITEM_H

#include <QGraphicsSimpleTextItem>

class BCTextDisplayItem : public QGraphicsSimpleTextItem
{
public:
    BCTextDisplayItem(QGraphicsItem * parent = 0);
    BCTextDisplayItem(const QString & text, QGraphicsItem * parent = 0);

    const QRectF &GetBoundingRect();

    void SetText(const QString &qsText);
    void SetTextPosOffset(double x, double y);

    void SetFontColor(int r, int g, int b, int a);
    void SetFontFamily(const QString &qsFontFamily);
    void SetFontSize(int size);

protected:
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
    void SetPainterClipRect(QPainter * painter, QRectF rect);

    double m_dTextPosOffsetX;
    double m_dTextPosOffsetY;

    int m_nTextLineColorR;
    int m_nTextLineColorG;
    int m_nTextLineColorB;
    int m_nTextLineColorA;
    int m_nTextLineWidth;
    int m_nTextLineStyle;

    QString m_qsFontFamily;
    int m_nFontSize;

    QRectF  m_boundingRect; // 文字占的矩形位置
};

inline const QRectF &BCTextDisplayItem::GetBoundingRect()
{
    return m_boundingRect;
}

#endif // BCTEXTDISPLAYITEM_H
