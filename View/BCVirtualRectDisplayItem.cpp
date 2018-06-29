#include "BCVirtualRectDisplayItem.h"
#include "BCBackGroundDisplayItem.h"

BCVirtualRectDisplayItem::BCVirtualRectDisplayItem(double x, double y, double w, double h, BCMDisplayRect *pMRect, QGraphicsItem * parent)
    :BCDisplayItem(BCCommon::VIRTUALRECT, x, y, w, h, parent, 0)
{
    m_pMRect = pMRect;
    m_nType = 0;

    m_nVirtualRectFillColorA = BCCommon::g_nVirtualRectFillColorA;
}

BCVirtualRectDisplayItem::~BCVirtualRectDisplayItem()
{

}

BCVirtualRectDisplayItem::BCVirtualRectDisplayItem(const BCVirtualRectDisplayItem &item) : BCDisplayItem(item)
{
    m_nType = item.m_nType;
    m_nVirtualRectFillColorA = item.m_nVirtualRectFillColorA;
}

BCVirtualRectDisplayItem *BCVirtualRectDisplayItem::Clone()
{
    return new BCVirtualRectDisplayItem( *this );
}

void BCVirtualRectDisplayItem::SetHighLight(bool b)
{
    m_nVirtualRectFillColorA = b ? 255 : 0;
    this->update(this->rect());
}

bool BCVirtualRectDisplayItem::IsHighLight()
{
    return (m_nVirtualRectFillColorA == 0) ? false : true;
}

void BCVirtualRectDisplayItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget*/)
{
    // 缩放比例
    QTransform trans = painter->worldTransform();
    double dScale = trans.m11();

    BCBackGroundDisplayItem *pSingleDisplay = dynamic_cast<BCBackGroundDisplayItem *>( this->parentItem() );

    switch ( m_nType ) {
    case 0: // 单个显示屏内矩形框
        // 克隆单个显示器不绘制矩形边框
        if (NULL != pSingleDisplay) {
            if ( !pSingleDisplay->IsClone()) {
                painter->setPen(QPen(QBrush(QColor(BCCommon::g_nVirtualRectLineColorR,
                                                   BCCommon::g_nVirtualRectLineColorG,
                                                   BCCommon::g_nVirtualRectLineColorB,
                                                   BCCommon::g_nVirtualRectLineColorA)),
                                     BCCommon::g_nVirtualRectLineWidth/dScale,
                                     Qt::PenStyle(BCCommon::g_nVirtualRectLineStyle)));
            }
        }

        // 设置颜色填充
        painter->setBrush(QBrush(QColor(BCCommon::g_nVirtualRectFillColorR,
                                        BCCommon::g_nVirtualRectFillColorG,
                                        BCCommon::g_nVirtualRectFillColorB,
                                        m_nVirtualRectFillColorA)));

        painter->drawRect( rect() );
        break;
    case 1: // 信号窗内矩形框，可用来显示视频
        painter->setPen(QPen(QBrush(QColor(BCCommon::g_nVirtualRectLineColorR,
                                           BCCommon::g_nVirtualRectLineColorG,
                                           BCCommon::g_nVirtualRectLineColorB,
                                           BCCommon::g_nVirtualRectLineColorA)),
                             BCCommon::g_nVirtualRectLineWidth/dScale,
                             Qt::PenStyle(BCCommon::g_nVirtualRectLineStyle)));

        painter->drawRoundedRect(rect(), BCCommon::g_nVirtualRectRadius, BCCommon::g_nVirtualRectRadius);
        break;
    case 2: // 判断是否开窗的矩形框设置
        painter->setPen(QPen(QBrush(QColor(BCCommon::g_nVirtualSignalWindowLineColorR,
                                           BCCommon::g_nVirtualSignalWindowLineColorG,
                                           BCCommon::g_nVirtualSignalWindowLineColorB,
                                           BCCommon::g_nVirtualSignalWindowLineColorA)),
                             BCCommon::g_nVirtualSignalWindowLineWidth/dScale,
                             Qt::PenStyle(BCCommon::g_nVirtualSignalWindowLineStyle)));

        painter->drawRoundedRect(rect(), BCCommon::g_nVirtualRectRadius, BCCommon::g_nVirtualRectRadius);
        break;
    default:
        break;
    }
}
