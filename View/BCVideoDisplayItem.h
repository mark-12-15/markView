/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：信号窗内视频类，需要记录起始点及其宽高比
*********************************************************************************************************************************/
#ifndef BCVIDEODISPLAYITEM_H
#define BCVIDEODISPLAYITEM_H

#include <QGraphicsPixmapItem>

class BCVideoDisplayItem : public QGraphicsPixmapItem
{
public:
    BCVideoDisplayItem(double x, double y, double w, double h, QGraphicsItem * parent = 0);

    QRectF GetRectItemRelativePos();

    void SetImage(const QImage&image);

protected:
    double m_dX;
    double m_dY;
    double m_dW;
    double m_dH;
};

inline QRectF BCVideoDisplayItem::GetRectItemRelativePos()
{
    return QRectF(m_dX, m_dY, m_dW, m_dH);
}

#endif // BCVIDEODISPLAYITEM_H
