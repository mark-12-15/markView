#include "BCButtonDisplayItem.h"

#include "../Common/BCCommon.h"
#include "BCSignalWindowDisplayItem.h"
#include "BCSignalWindowTitleDisplayItem.h"
#include "BCDisplayItemManager.h"
BCButtonDisplayItem::BCButtonDisplayItem(SIGNALWINDOWTITLEBUTTONTYPE eType, QGraphicsItem * parent)
    :QGraphicsPixmapItem(parent)
{
    // 需设置此属性，否则无法接收悬停事件
    setAcceptHoverEvents(true);

    m_eType = eType;

    switch (m_eType) {
    case LOCK:      // 锁定
        m_qsIconPath = BCCommon::g_qsSignalWindowTitleUnLockButtonImagePath;
        break;
    case WINWOD:    // 窗口
        m_qsIconPath = BCCommon::g_qsSignalWindowTitleUnFullScreenButtonImagePath;
        break;
    case FULLSCENE: // 全屏
        m_qsIconPath = BCCommon::g_qsSignalWindowTitleFullScreenButtonImagePath;
        break;
    case CLOSE:     // 关闭
        m_qsIconPath = BCCommon::g_qsSignalWindowTitleCloseButtonImagePath;
        break;
    default:
        break;
    }

    // 设置图片
    this->setPixmap(QPixmap(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+m_qsIconPath)
                    .scaled(BCCommon::g_nSignalWindowTitleButtonIconSize,
                            BCCommon::g_nSignalWindowTitleButtonIconSize,
                            Qt::IgnoreAspectRatio,
                            Qt::SmoothTransformation));
}

void BCButtonDisplayItem::RefreshIcon()
{
    switch (m_eType) {
    case LOCK: {    // 锁定
            BCSignalWindowDisplayItem *pSignalWindow = dynamic_cast<BCSignalWindowDisplayItem *>( this->parentItem()->parentItem());
            if (NULL != pSignalWindow) {
                // set pixmap
                m_qsIconPath = pSignalWindow->IsLocked() ? BCCommon::g_qsSignalWindowTitleLockButtonImagePath : BCCommon::g_qsSignalWindowTitleUnLockButtonImagePath;

                this->update();
            }
        }
        break;
    default:
        break;
    }
}

void BCButtonDisplayItem::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    //this->setPixmap(QPixmap(BCCommon::g_qsSignalWindowTitleLockButtonImagePath));
    BCCommon::g_nSignalWindowTitleButtonFillColorA = 125;
}

void BCButtonDisplayItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    BCCommon::g_nSignalWindowTitleButtonFillColorA = 0;
}

void BCButtonDisplayItem::hoverMoveEvent(QGraphicsSceneHoverEvent *)
{

}

void BCButtonDisplayItem::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    switch (m_eType) {
    case LOCK: {    // 锁定
            BCSignalWindowDisplayItem *pSignalWindow = dynamic_cast<BCSignalWindowDisplayItem *>( this->parentItem()->parentItem());
            if (NULL != pSignalWindow) {
                // set pixmap
                pSignalWindow->SetLock( !pSignalWindow->IsLocked() );
                m_qsIconPath = pSignalWindow->IsLocked() ? BCCommon::g_qsSignalWindowTitleLockButtonImagePath : BCCommon::g_qsSignalWindowTitleUnLockButtonImagePath;

                this->update();
            }
        }
        break;
    case WINWOD: { // 窗口
            BCSignalWindowDisplayItem *pSignalWindow = dynamic_cast<BCSignalWindowDisplayItem *>( this->parentItem()->parentItem());
            if (NULL != pSignalWindow) {
                // set pixmap
                pSignalWindow->SetFullScene(false);
            }
        }
        break;
    case FULLSCENE: { // 全屏
            BCSignalWindowDisplayItem *pSignalWindow = dynamic_cast<BCSignalWindowDisplayItem *>( this->parentItem()->parentItem());
            if (NULL != pSignalWindow) {
                // set pixmap
                pSignalWindow->SetFullScene(true);
            }
        }
        break;
    case CLOSE: {   // 关闭
            BCSignalWindowDisplayItem *pSignalWindow = dynamic_cast<BCSignalWindowDisplayItem *>( this->parentItem()->parentItem());
            BCDisplayItemManager *pManager = dynamic_cast<BCDisplayItemManager *>( pSignalWindow->parentItem() );
            if ((NULL != pSignalWindow) && (NULL != pManager)) {
                pManager->RemoveSignalWindowDisplayItem( pSignalWindow );
            }
        }
        break;
    default:
        break;
    }
}

void BCButtonDisplayItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget*/)
{
    // 文字占用的矩形尺寸，需计算偏移量
    m_boundingRect = this->boundingRect();

    // 根据父类矩形对文字区域进行剪切
    BCSignalWindowTitleDisplayItem *pSignalWindowTitleItem = dynamic_cast<BCSignalWindowTitleDisplayItem *>( this->parentItem() );
    if (NULL != pSignalWindowTitleItem) {
        // 计算父矩形和本矩形四个边线的偏移量
        double dOffsetL = this->mapToParent(m_boundingRect.left(), m_boundingRect.top()).x() - pSignalWindowTitleItem->GetSignalWindowTitlePaintRect().left();
        double dOffsetT = this->mapToParent(m_boundingRect.left(), m_boundingRect.top()).y() - pSignalWindowTitleItem->GetSignalWindowTitlePaintRect().top();
        double dOffsetR = this->mapToParent(m_boundingRect.right(), m_boundingRect.bottom()).x() - pSignalWindowTitleItem->GetSignalWindowTitlePaintRect().right();
        double dOffsetB = this->mapToParent(m_boundingRect.right(), m_boundingRect.bottom()).y() - pSignalWindowTitleItem->GetSignalWindowTitlePaintRect().bottom();
        // 如果父矩形和本矩形没有交集则清除偏移量
        dOffsetL = (dOffsetL > 0.0) ? 0.0 : dOffsetL;
        dOffsetT = (dOffsetT > 0.0) ? 0.0 : dOffsetT;
        dOffsetR = (dOffsetR < 0.0) ? 0.0 : dOffsetR;
        dOffsetB = (dOffsetB < 0.0) ? 0.0 : dOffsetB;

        // 根据偏移量对矩形进行剪切
        QRectF rect = QRectF(m_boundingRect.left()-dOffsetL,
                             m_boundingRect.top()-dOffsetT,
                             m_boundingRect.width()-dOffsetR,
                             m_boundingRect.height()-dOffsetB);

        painter->setClipRect(rect);
    }

    // 当有缩放时需要设置缩放比例
    QTransform trans = painter->worldTransform();
    double scale = trans.m11();
    painter->scale(1/scale, 1/scale);

    painter->drawPixmap(this->boundingRect(),
                        QPixmap(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+m_qsIconPath)
                        .scaled(BCCommon::g_nSignalWindowTitleButtonIconSize,
                                BCCommon::g_nSignalWindowTitleButtonIconSize,
                                Qt::IgnoreAspectRatio,
                                Qt::SmoothTransformation),
                        this->boundingRect());
}
