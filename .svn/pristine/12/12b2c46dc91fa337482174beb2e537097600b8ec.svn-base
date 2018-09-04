#include "BCBackGroundDisplayItem.h"

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include "QGraphicsWidget"
#include "BCDisplayItemManager.h"
#include "BCVirtualRectDisplayItem.h"
#include "BCDisplayWallView.h"
#include "BCDisplayWall.h"
#include "BCTextDisplayItem.h"
#include "../Model/BCMDisplay.h"
#include "../Model/BCMDisplayRect.h"
BCBackGroundDisplayItem::BCBackGroundDisplayItem(double x, double y, double w, double h, BCMDisplay *pMDisplay, QGraphicsItem * parent)
    :BCDisplayItem(BCCommon::BACKGROUND, x, y, w, h, parent, 0)
{
    // 赋值数据类
    m_pMDisplay = pMDisplay;
    m_bSegmentation = -1;

    // 需设置此属性，否则无法接收悬停事件
    setAcceptHoverEvents(true);

    // 构造两个文字对象
    m_pDefaultTextItem = new BCTextDisplayItem("", this);
    m_pTextItem = new BCTextDisplayItem("", this);

    // 初始化文字设置
    RefreshDisplayTextColor();
    RefreshDisplayTextFont();
    RefreshDisplayTextPos();
    RefreshIsShowDisplayText();

    // 鼠标移动时共有属性
    m_x = 0.0;
    m_y = 0.0;
    m_bPress = false;
    m_bClone = false;

    // 初始化矩形
    InitVirtualRect();
}

BCBackGroundDisplayItem::~BCBackGroundDisplayItem()
{
    // 删除内部对象
    QList<QGraphicsItem *> lst = childItems();
    while ( !lst.isEmpty() )
        delete lst.takeFirst();
}

void BCBackGroundDisplayItem::InitVirtualRect()
{
    if (NULL == m_pMDisplay)\
        return;

    m_pDefaultTextItem->SetText( m_pMDisplay->GetDisplayName() );

//    // 获得数据规定组屏的尺寸
//    QSizeF sizeDisplay = QSizeF(m_pMDisplay->GetRect().width(), m_pMDisplay->GetRect().height());

//    // 循环单屏
//    QList<BCMDisplayRect *> lstRects = m_pMDisplay->GetDisplayRects();
//    m_bSegmentation = lstRects.count();

//    QListIterator<BCMDisplayRect *> itRect( lstRects );
//    while ( itRect.hasNext() ) {
//        BCMDisplayRect *pMRect = itRect.next();
//        if (NULL == pMRect)
//            continue;

//        // 添加ui单屏
//        QRectF rectRect = pMRect->GetRect();
//        this->AddVirtualRect( 100*rectRect.left()/sizeDisplay.width(),
//                              100*rectRect.top()/sizeDisplay.height(),
//                              100*rectRect.width()/sizeDisplay.width(),
//                              100*rectRect.height()/sizeDisplay.height(),
//                              pMRect);
//    }

    RefreshSegmentation( m_pMDisplay->GetSegmentation() );
}

void BCBackGroundDisplayItem::RefreshSegmentation(int n)
{
    if (n == m_bSegmentation)
        return;

    // 1.赋值分割数
    m_bSegmentation = n;

    // 2.删除所有虚拟矩形
    QList<QGraphicsItem *> lstGraphicsItem = this->childItems();
    QListIterator<QGraphicsItem *> it( lstGraphicsItem );
    while ( it.hasNext() ) {
        BCVirtualRectDisplayItem *pRectItem = dynamic_cast<BCVirtualRectDisplayItem *>( it.next() );
        if (NULL == pRectItem)
            continue;

        delete pRectItem;
        pRectItem = NULL;
    }

    // 3.根据分割数确定行列数
    int r = 1;
    int c = 1;
    switch ( m_bSegmentation ) {
    case 1:
        r = 1;
        c = 1;
        break;
    case 4:
        r = 2;
        c = 2;
        break;
    case 6:
        r = 2;
        c = 3;
        break;
    case 8:
        r = 2;
        c = 4;
        break;
    case 9:
        r = 3;
        c = 3;
        break;
    case 12:
        r = 3;
        c = 4;
        break;
    default:
        r = 4;
        c = 4;
        break;
    }

    // 4.重新生成矩形
    double dRectWidth = 100.0/c;
    double dRectHeight = 100.0/r;
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            double x = dRectWidth * j;
            double y = dRectHeight * i;

            AddVirtualRect(x, y, dRectWidth, dRectHeight, NULL);
//            BCVirtualRectDisplayItem *pRectItem = AddVirtualRect(x, y, dRectWidth, dRectHeight, NULL);
//            if (NULL != pRectItem)
//                pRectItem->update();
        }
    }
}

// !!!暂时只为快速开窗使用，所以不需要复制内部矩形
BCBackGroundDisplayItem::BCBackGroundDisplayItem(const BCBackGroundDisplayItem &item) : BCDisplayItem(item)
{
    m_bClone = true;
    m_pDefaultTextItem = (NULL == item.m_pDefaultTextItem) ? NULL : new BCTextDisplayItem(item.m_pDefaultTextItem->text(), this);
    m_pTextItem = (NULL == item.m_pTextItem) ? NULL : new BCTextDisplayItem(item.m_pTextItem->text(), this);

    new BCVirtualRectDisplayItem(0, 0, 100, 100, NULL, this);
}

BCBackGroundDisplayItem *BCBackGroundDisplayItem::Clone()
{
    return new BCBackGroundDisplayItem( *this );
}

BCVirtualRectDisplayItem * BCBackGroundDisplayItem::AddVirtualRect(double x, double y, double w, double h, BCMDisplayRect *pMRect)
{
    return new BCVirtualRectDisplayItem(x, y, w, h, pMRect, this);
}

void BCBackGroundDisplayItem::ResizeRect(double x, double y, double w, double h)
{
    // 改变自身矩形大小
    setRect(x, y, w, h);

    // 重绘内部图形
    BCVirtualRectDisplayItem *pRectItem = NULL;
    QList<QGraphicsItem*> lstItems = this->childItems();
    QListIterator<QGraphicsItem*> it( lstItems );
    while ( it.hasNext() ) {
        pRectItem = dynamic_cast<BCVirtualRectDisplayItem *>( it.next() );
        if (NULL == pRectItem)
            continue;

        double dX = x + (pRectItem->GetRectItemRelativePos().x() * 0.01 * w);
        double dY = y + (pRectItem->GetRectItemRelativePos().y() * 0.01 * h);
        double dW = pRectItem->GetRectItemRelativePos().width() * 0.01 * w;
        double dH = pRectItem->GetRectItemRelativePos().height() * 0.01 * h;

        QPointF relativePos = pRectItem->mapFromParent(dX, dY);

        pRectItem->setRect(relativePos.x(), relativePos.y(), dW, dH);
    }

    // 修改相对坐标
    BCDisplayItemManager *pItemManager = dynamic_cast<BCDisplayItemManager *>( this->parentItem() );
    if (NULL != pItemManager) {
        m_dX = (qAbs(mapToParent(x, 0).x() - pItemManager->rect().x()) / pItemManager->rect().width()) * 100;
        m_dY = (qAbs(mapToParent(0, y).y() - pItemManager->rect().y()) / pItemManager->rect().height()) * 100;
        m_dW = (w / pItemManager->rect().width()) * 100;
        m_dH = (h / pItemManager->rect().height()) * 100;
    }
}

void BCBackGroundDisplayItem::SetDisplayText(const QString &qsText)
{
    if (NULL == m_pTextItem)
        return;

    m_pTextItem->SetText( qsText );
}

void BCBackGroundDisplayItem::SetDisplayDefaultText(const QString &qsText)
{
    if (NULL == m_pDefaultTextItem)
        return;

    m_pDefaultTextItem->SetText( qsText );
}

void BCBackGroundDisplayItem::RefreshDisplayTextColor()
{
    if ((NULL == m_pTextItem) || (NULL == m_pDefaultTextItem))
        return;

    m_pTextItem->SetFontColor( BCCommon::g_nSignalWindowBodyTextColorR,
                               BCCommon::g_nSignalWindowBodyTextColorG,
                               BCCommon::g_nSignalWindowBodyTextColorB,
                               BCCommon::g_nSignalWindowBodyTextColorA);

    m_pDefaultTextItem->SetFontColor( BCCommon::g_nSignalWindowBodyTextColorR,
                               BCCommon::g_nSignalWindowBodyTextColorG,
                               BCCommon::g_nSignalWindowBodyTextColorB,
                               BCCommon::g_nSignalWindowBodyTextColorA);
}

void BCBackGroundDisplayItem::RefreshDisplayTextFont()
{
    if ((NULL == m_pTextItem) || (NULL == m_pDefaultTextItem))
        return;

    m_pTextItem->SetFontFamily( BCCommon::g_sSignalWindowBodyTextFamilyName );
    m_pTextItem->SetFontSize( BCCommon::g_nSignalWindowBodyTextSize );

    m_pDefaultTextItem->SetFontFamily( BCCommon::g_sSignalWindowBodyTextFamilyName );
    m_pDefaultTextItem->SetFontSize( BCCommon::g_nSignalWindowBodyTextSize );
}

void BCBackGroundDisplayItem::RefreshDisplayTextPos()
{
    SetDisplayTextPos( false );
    SetDisplayTextPos( true );
}

void BCBackGroundDisplayItem::RefreshIsShowDisplayText()
{
    if ((NULL == m_pTextItem) || (NULL == m_pDefaultTextItem))
        return;

    ( BCCommon::g_bShowSingleDisplayText ) ? m_pTextItem->show() : m_pTextItem->hide();
    ( BCCommon::g_bShowSingleDisplayDefaultText ) ? m_pDefaultTextItem->show() : m_pDefaultTextItem->hide();
}

void BCBackGroundDisplayItem::SetDisplayTextPos(bool bDefaultText)
{
    if ((NULL == m_pTextItem) || (NULL == m_pDefaultTextItem))
        return;

    BCTextDisplayItem *pTextItem = bDefaultText ? m_pDefaultTextItem : m_pTextItem;
    BCCommon::SINGLEDISPLAYTEXTPOS ePos = bDefaultText ? BCCommon::g_eSingleDisplayDefaultTextPos : BCCommon::g_eSingleDisplayTextPos;

    // 根据位置更新文字位置
    switch ( ePos ) {
    case BCCommon::LEFTTOP: {
        pTextItem->setPos(rect().left()+BCCommon::g_nSingleDisplayTextPosOffsetX,
                            rect().top()+BCCommon::g_nSingleDisplayTextPosOffsetY);
        }
        break;
    case BCCommon::LEFT: {
        int nTextY = rect().center().y() - (pTextItem->GetBoundingRect().height()/2);
        pTextItem->setPos(rect().left()+BCCommon::g_nSingleDisplayTextPosOffsetX,
                            nTextY+BCCommon::g_nSingleDisplayTextPosOffsetY);
        }
        break;
    case BCCommon::LEFTBOTTOM: {
        int nTextY = rect().bottom() - pTextItem->GetBoundingRect().height();
        pTextItem->setPos(rect().left()+BCCommon::g_nSingleDisplayTextPosOffsetX,
                            nTextY+BCCommon::g_nSingleDisplayTextPosOffsetY);
        }
        break;
    case BCCommon::TOP: {
        int nTextX = rect().center().x() - (pTextItem->GetBoundingRect().width()/2);
        pTextItem->setPos(nTextX+BCCommon::g_nSingleDisplayTextPosOffsetX,
                            rect().top()+BCCommon::g_nSingleDisplayTextPosOffsetY);
        }
        break;
    case BCCommon::CENTER: {
        int nTextX = rect().center().x() - (pTextItem->GetBoundingRect().width()/2);
        int nTextY = rect().center().y() - (pTextItem->GetBoundingRect().height()/2);

        pTextItem->setPos(nTextX+BCCommon::g_nSingleDisplayTextPosOffsetX,
                            nTextY+BCCommon::g_nSingleDisplayTextPosOffsetY);
        }
        break;
    case BCCommon::BOTTOM: {
        int nTextX = rect().center().x() - (pTextItem->GetBoundingRect().width()/2);
        pTextItem->setPos(nTextX+BCCommon::g_nSingleDisplayTextPosOffsetX,
                            rect().bottom()+BCCommon::g_nSingleDisplayTextPosOffsetY);
        }
        break;
    case BCCommon::RIGHTTOP: {
        int nTextX = rect().right() - pTextItem->GetBoundingRect().width();

        pTextItem->setPos(nTextX+BCCommon::g_nSingleDisplayTextPosOffsetX,
                            rect().top()+BCCommon::g_nSingleDisplayTextPosOffsetY);
        }
        break;
    case BCCommon::RIGHT: {
        int nTextX = rect().right() - pTextItem->GetBoundingRect().width();
        int nTextY = rect().center().y() - (pTextItem->GetBoundingRect().height()/2);

        pTextItem->setPos(nTextX+BCCommon::g_nSingleDisplayTextPosOffsetX,
                            nTextY+BCCommon::g_nSingleDisplayTextPosOffsetY);
        }
        break;
    case BCCommon::RIGHTBOTTOM: {
        int nTextX = rect().right() - pTextItem->GetBoundingRect().width();
        int nTextY = rect().bottom() - pTextItem->GetBoundingRect().height();

        pTextItem->setPos(nTextX+BCCommon::g_nSingleDisplayTextPosOffsetX,
                            nTextY+BCCommon::g_nSingleDisplayTextPosOffsetY);
        }
        break;
    }
}

void BCBackGroundDisplayItem::SetHighLight(bool b)
{
    QList<QGraphicsItem*> lst = this->childItems();
    QListIterator<QGraphicsItem*> it( lst );
    while (it.hasNext()) {
        BCVirtualRectDisplayItem *pItem = dynamic_cast<BCVirtualRectDisplayItem *>( it.next() );
        if (NULL == pItem)
            continue;

        pItem->SetHighLight( b );
    }
}

bool BCBackGroundDisplayItem::IsHighLight()
{
    bool bHighLight = true;

    QList<QGraphicsItem*> lst = this->childItems();
    QListIterator<QGraphicsItem*> it( lst );
    while (it.hasNext()) {
        BCVirtualRectDisplayItem *pItem = dynamic_cast<BCVirtualRectDisplayItem *>( it.next() );
        if (NULL == pItem)
            continue;

        if ( pItem->IsHighLight() )
            continue;

        bHighLight = false;
        break;
    }

    return bHighLight;
}

#include <QMenu>
void BCBackGroundDisplayItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *e)
{
    return;
    // 构造菜单
    QMenu menu;
    QAction *pAllWindowScaleToSingleDisplay = menu.addAction(QObject::tr("所有窗口缩小到单个屏"));
    QAction *pSetSingleDisplayTitle = menu.addAction(QObject::tr("设定子屏幕标题"));
    QAction *pAlwaysShowSingleDisplayTitle = menu.addAction(QObject::tr("始终显示子屏幕标题"));
    pAlwaysShowSingleDisplayTitle->setCheckable( true );
    QAction *pSingleDisplayActive = menu.addAction(QObject::tr("子屏幕有效"));
    pSingleDisplayActive->setCheckable( true );

    // 返回选择的action
    QAction *pSelectedAction = menu.exec(e->screenPos());
    // 所有窗口缩小到单个屏
    if (pSelectedAction == pAllWindowScaleToSingleDisplay) {
        //
    }
    // 设定子屏幕标题
    if (pSelectedAction == pSetSingleDisplayTitle) {
        //
    }
    // 始终显示子屏幕标题
    if (pSelectedAction == pAlwaysShowSingleDisplayTitle) {
        //
    }
    // 子屏幕有效
    if (pSelectedAction == pSingleDisplayActive) {
        //
    }

    e->accept();
}

void BCBackGroundDisplayItem::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    // 点击单个屏幕时
    if (BCCommon::g_bMoveBackGround) {
        if(event->button()== Qt::LeftButton){
            m_bPress = true;

            // 相对于scene左上角的坐标，缩放不影响坐标
            m_x = event->scenePos().x() - mapToScene(rect().left(), 0).x();
            m_y = event->scenePos().y() - mapToScene(0, rect().top()).y();

            // 重置ZValue，保证当前激活窗口在前端
            BCDisplayItemManager *pDisplayWall = dynamic_cast<BCDisplayItemManager*>(this->scene()->parent());
            if (NULL != pDisplayWall) {
                pDisplayWall->ResetZValue();
            }
            this->setZValue(1);
        }
    }

    event->accept();
}

void BCBackGroundDisplayItem::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
    // 点击单个屏幕时
    if (BCCommon::g_bMoveBackGround) {
        if (m_bPress) {
            // 矩形左上角坐标，缩放无影响
            int x = event->scenePos().x() - m_x;
            int y = event->scenePos().y() - m_y;

            // 父类矩形框，缩放无影响
            QRectF parentRect = dynamic_cast<QGraphicsRectItem *>(parentItem())->rect();

            // 需要考虑缩放比例
            switch (m_eResizePos) {
            case UNRESIZE: {
                // 允许拖动最小范围
                x = (x < parentRect.left()) ? parentRect.left() : x;
                y = (y < parentRect.top()) ? parentRect.top() : y;

                // 允许拖动最大范围
                x = (x > parentRect.right()-rect().width()) ? parentRect.right()-rect().width() : x;
                y = (y > parentRect.bottom()-rect().height()) ? parentRect.bottom()-rect().height() : y;

                // 移动位置需要去掉矩形相对位置
                this->setPos(x - rect().left(), y - rect().top());
                ResizeRect(rect().x(), rect().y(), rect().width(), rect().height());
                }
                break;
            case RESIZELT: {
                // scene偏移量
                double nOffsetX = event->lastScenePos().x() - event->scenePos().x();
                double nOffsetY = event->lastScenePos().y() - event->scenePos().y();

                // X最大最小值限定
                nOffsetX = (x < parentRect.left()) ? mapToScene(rect().left(),0).x()-parentRect.left() : nOffsetX;
                nOffsetX = (x > mapToScene(rect().right()-BCCommon::g_nMinResizeBackGround, 0).x()) ? mapToScene(rect().left(),0).x()-mapToScene(rect().right()-BCCommon::g_nMinResizeBackGround, 0).x() : nOffsetX;

                // Y最大最小值限定
                nOffsetY = (y < parentRect.top()) ? mapToScene(0, rect().top()).y()-parentRect.top() : nOffsetY;
                nOffsetY = (y > mapToScene(0, rect().bottom()-BCCommon::g_nMinResizeBackGround).y()) ? mapToScene(0, rect().top()).y()-mapToScene(0, rect().bottom()-BCCommon::g_nMinResizeBackGround).y() : nOffsetY;

                // 重置矩形
                double dNewX = rect().x() - nOffsetX;
                double dNewY = rect().y() - nOffsetY;
                double dNewW = rect().width() + nOffsetX;
                double dNewH = rect().height() + nOffsetY;
                ResizeRect(dNewX, dNewY, dNewW, dNewH);
                }
                break;
            case RESIZEL: {
                // scene偏移量
                double nOffsetX = event->lastScenePos().x() - event->scenePos().x();

                // X最大最小值限定
                nOffsetX = (x < parentRect.left()) ? mapToScene(rect().left(),0).x()-parentRect.left() : nOffsetX;
                nOffsetX = (x > mapToScene(rect().right()-BCCommon::g_nMinResizeBackGround, 0).x()) ? mapToScene(rect().left(),0).x()-mapToScene(rect().right()-BCCommon::g_nMinResizeBackGround, 0).x() : nOffsetX;

                // 重置矩形
                double dNewX = rect().x() - nOffsetX;
                double dNewY = rect().y();
                double dNewW = rect().width() + nOffsetX;
                double dNewH = rect().height();
                ResizeRect(dNewX, dNewY, dNewW, dNewH);
                }
                break;
            case RESIZELB: {
                // scene偏移量
                double nOffsetX = event->lastScenePos().x() - event->scenePos().x();
                double nOffsetY = event->lastScenePos().y() - event->scenePos().y();

                // X最大最小值限定
                nOffsetX = (x < parentRect.left()) ? mapToScene(rect().left(),0).x()-parentRect.left() : nOffsetX;
                nOffsetX = (x > mapToScene(rect().right()-BCCommon::g_nMinResizeBackGround, 0).x()) ? mapToScene(rect().left(),0).x()-mapToScene(rect().right()-BCCommon::g_nMinResizeBackGround, 0).x() : nOffsetX;

                // Y最大最小值限定
                // !!!函数开始处y值的变化的，非左上角的值
                nOffsetY = (event->scenePos().y() < mapToScene(0, rect().top()+BCCommon::g_nMinResizeBackGround).y()) ? rect().height() - BCCommon::g_nMinResizeBackGround : nOffsetY;
                nOffsetY = (event->scenePos().y() > parentRect.bottom()) ? rect().height() - parentRect.bottom()+mapToScene(0, rect().top()).y() : nOffsetY;

                // 重置矩形
                double dNewX = rect().x() - nOffsetX;
                double dNewY = rect().y();
                double dNewW = rect().width() + nOffsetX;
                double dNewH = rect().height() - nOffsetY;
                ResizeRect(dNewX, dNewY, dNewW, dNewH);
                }
                break;
            case RESIZET: {
                // scene偏移量
                double nOffsetY = event->lastScenePos().y() - event->scenePos().y();

                // Y最大最小值限定
                nOffsetY = (y < parentRect.top()) ? mapToScene(0, rect().top()).y()-parentRect.top() : nOffsetY;
                nOffsetY = (y > mapToScene(0, rect().bottom()-BCCommon::g_nMinResizeBackGround).y()) ? mapToScene(0, rect().top()).y()-mapToScene(0, rect().bottom()-BCCommon::g_nMinResizeBackGround).y() : nOffsetY;

                // 重置矩形
                double dNewX = rect().x();
                double dNewY = rect().y() - nOffsetY;
                double dNewW = rect().width();
                double dNewH = rect().height() + nOffsetY;
                ResizeRect(dNewX, dNewY, dNewW, dNewH);
                }
                break;
            case RESIZEB: {
                // scene偏移量
                double nOffsetY = event->lastScenePos().y() - event->scenePos().y();

                // Y最大最小值限定
                // !!!函数开始处y值的变化的，非左上角的值
                nOffsetY = (event->scenePos().y() < mapToScene(0, rect().top()+BCCommon::g_nMinResizeBackGround).y()) ? rect().height() - BCCommon::g_nMinResizeBackGround : nOffsetY;
                nOffsetY = (event->scenePos().y() > parentRect.bottom()) ? rect().height() - parentRect.bottom()+mapToScene(0, rect().top()).y() : nOffsetY;

                // 重置矩形
                double dNewX = rect().x();
                double dNewY = rect().y();
                double dNewW = rect().width();
                double dNewH = rect().height() - nOffsetY;
                ResizeRect(dNewX, dNewY, dNewW, dNewH);
                }
                break;
            case RESIZERT: {
                // scene偏移量
                double nOffsetX = event->lastScenePos().x() - event->scenePos().x();
                double nOffsetY = event->lastScenePos().y() - event->scenePos().y();

                // X最大最小值限定
                nOffsetX = (event->scenePos().x() < mapToScene(rect().left(), 0).x()+BCCommon::g_nMinResizeBackGround) ? rect().width() - BCCommon::g_nMinResizeBackGround : nOffsetX;
                nOffsetX = (event->scenePos().x() > parentRect.right()) ? rect().width() - parentRect.right() + mapToScene(rect().left(), 0).x() : nOffsetX;

                // Y最大最小值限定
                nOffsetY = (y < parentRect.top()) ? mapToScene(0, rect().top()).y()-parentRect.top() : nOffsetY;
                nOffsetY = (y > mapToScene(0, rect().bottom()-BCCommon::g_nMinResizeBackGround).y()) ? mapToScene(0, rect().top()).y()-mapToScene(0, rect().bottom()-BCCommon::g_nMinResizeBackGround).y() : nOffsetY;

                // 重置矩形
                double dNewX = rect().x();
                double dNewY = rect().y() - nOffsetY;
                double dNewW = rect().width() - nOffsetX;
                double dNewH = rect().height() + nOffsetY;
                ResizeRect(dNewX, dNewY, dNewW, dNewH);
                }
                break;
            case RESIZER: {
                // scene偏移量
                double nOffsetX = event->lastScenePos().x() - event->scenePos().x();

                // X最大最小值限定
                nOffsetX = (event->scenePos().x() < mapToScene(rect().left(), 0).x()+BCCommon::g_nMinResizeBackGround) ? rect().width() - BCCommon::g_nMinResizeBackGround : nOffsetX;
                nOffsetX = (event->scenePos().x() > parentRect.right()) ? rect().width() - parentRect.right() + mapToScene(rect().left(), 0).x() : nOffsetX;

                // 重置矩形
                double dNewX = rect().x();
                double dNewY = rect().y();
                double dNewW = rect().width() - nOffsetX;
                double dNewH = rect().height();
                ResizeRect(dNewX, dNewY, dNewW, dNewH);
                }
                break;
            case RESIZERB: {
                // scene偏移量
                double nOffsetX = event->lastScenePos().x() - event->scenePos().x();
                double nOffsetY = event->lastScenePos().y() - event->scenePos().y();

                // X最大最小值限定
                nOffsetX = (event->scenePos().x() < mapToScene(rect().left(), 0).x()+BCCommon::g_nMinResizeBackGround) ? rect().width() - BCCommon::g_nMinResizeBackGround : nOffsetX;
                nOffsetX = (event->scenePos().x() > parentRect.right()) ? rect().width() - parentRect.right() + mapToScene(rect().left(), 0).x() : nOffsetX;

                // Y最大最小值限定
                // !!!函数开始处y值的变化的，非左上角的值
                nOffsetY = (event->scenePos().y() < mapToScene(0, rect().top()+BCCommon::g_nMinResizeBackGround).y()) ? rect().height() - BCCommon::g_nMinResizeBackGround : nOffsetY;
                nOffsetY = (event->scenePos().y() > parentRect.bottom()) ? rect().height() - parentRect.bottom()+mapToScene(0, rect().top()).y() : nOffsetY;

                // 重置矩形
                double dNewX = rect().x();
                double dNewY = rect().y();
                double dNewW = rect().width() - nOffsetX;
                double dNewH = rect().height() - nOffsetY;
                ResizeRect(dNewX, dNewY, dNewW, dNewH);
                }
                break;
            default:
                break;
            }
        }
    }

    QGraphicsItem::mouseMoveEvent(event);
}

void BCBackGroundDisplayItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    // 点击单个屏幕时
    if (BCCommon::g_bMoveBackGround) {
        m_bPress = false;
    }

    event->accept();
}

void BCBackGroundDisplayItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget*/)
{
    // 缩放比例
    QTransform trans = painter->worldTransform();
    double dScale = trans.m11();

    // 设置边线
    painter->setPen(QPen(QBrush(QColor(BCCommon::g_nSingleDisplayLineColorR,
                                       BCCommon::g_nSingleDisplayLineColorG,
                                       BCCommon::g_nSingleDisplayLineColorB,
                                       BCCommon::g_nSingleDisplayLineColorA)),
                         BCCommon::g_nSingleDisplayLineWidth/dScale,
                         Qt::PenStyle(BCCommon::g_nSingleDisplayLineStyle)));

    // 设置颜色填充
    painter->setBrush(QBrush(QColor(BCCommon::g_nSingleDisplayFillColorR,
                                    BCCommon::g_nSingleDisplayFillColorG,
                                    BCCommon::g_nSingleDisplayFillColorB,
                                    BCCommon::g_nSingleDisplayFillColorA)));

    // 重绘矩形，半径5（半径为圆角效果）
    painter->drawRoundedRect(rect(), BCCommon::g_nSingleDisplayRectRadius, BCCommon::g_nSingleDisplayRectRadius);

    // 重绘内部文字
    RefreshDisplayTextPos();
}
