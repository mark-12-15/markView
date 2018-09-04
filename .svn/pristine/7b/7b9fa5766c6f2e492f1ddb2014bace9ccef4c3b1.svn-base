#include "BCVideoDisplayItem.h"

BCVideoDisplayItem::BCVideoDisplayItem(double x, double y, double w, double h, QGraphicsItem * parent)
    :QGraphicsPixmapItem(parent)
{
    // 记录图片相对位置
    m_dX = x;
    m_dY = y;
    m_dW = w;
    m_dH = h;
}

void BCVideoDisplayItem::SetImage(const QImage&image)
{
    this->setPixmap(QPixmap::fromImage(image));
}
