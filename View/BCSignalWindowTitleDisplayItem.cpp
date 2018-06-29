#include "BCSignalWindowTitleDisplayItem.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include "BCSignalWindowDisplayItem.h"
#include "../Common/BCCommon.h"
#include "BCTextDisplayItem.h"
#include "../Model/BCMChannel.h"

BCSignalWindowTitleDisplayItem::BCSignalWindowTitleDisplayItem(double x, double y, double w, double h, QGraphicsItem * parent, int r)
    :BCDisplayItem(BCCommon::SIGNALWINDOWTITLE, x, y, w, h, parent, r)
{
    QString qsWindowID, qsChannelName;
    BCSignalWindowDisplayItem *pSignalWindowDisplayItem = dynamic_cast<BCSignalWindowDisplayItem*>( this->parentItem() );
    if (NULL != pSignalWindowDisplayItem) {
        qsWindowID = QString::number( pSignalWindowDisplayItem->GetWindowID() );
        BCMChannel *pChannel = pSignalWindowDisplayItem->GetInputChannel();
        qsChannelName = pChannel->GetChannelBaseName()+pChannel->GetChannelName();
    }

//    QString qsTitle = QObject::tr("窗口");
//    m_qsTitle = QString("%1%2").arg(qsTitle).arg(qsWindowID);
    m_qsTitle = qsChannelName;
    m_pTextItem = new BCTextDisplayItem(m_qsTitle, this);

    // 初始化文字设置
    RefreshDisplayTextColor();
    RefreshDisplayTextFont();
    RefreshDisplayTextPos();

    // 此处警告可忽略不记
    m_pBtnLock = new BCButtonDisplayItem(BCButtonDisplayItem::LOCK, this );
    m_pBtnFullscreen = new BCButtonDisplayItem(BCButtonDisplayItem::FULLSCENE, this );
    m_pBtnWindowShow = new BCButtonDisplayItem(BCButtonDisplayItem::WINWOD, this );
    m_pBtnClose = new BCButtonDisplayItem(BCButtonDisplayItem::CLOSE, this );

    // 初始化显示设置
    RefreshIsShowDisplayItem();

    // 按钮单独开关
    m_bTextItemVisible = true;
    m_bLockBtnVisible = true;
    m_bFullscreenBtnVisible = true;
    m_bWindowBtnVisible = true;
    m_bCloseBtnVisible = true;
}

BCSignalWindowTitleDisplayItem::~BCSignalWindowTitleDisplayItem()
{
    // 删除内部对象
    QList<QGraphicsItem *> lst = childItems();
    while ( !lst.isEmpty() )
        delete lst.takeFirst();
}

void BCSignalWindowTitleDisplayItem::ResizeRect(double x, double y, double w, double h)
{
    this->setRect(x, y, w, h);
    m_rectPaint = rect();

    if ( 0 ) {
        // 获得父类绘制区域，并计算本身绘制区域
        BCSignalWindowDisplayItem *pSignalWindowDisplayItem = dynamic_cast<BCSignalWindowDisplayItem*>( this->parentItem() );
        if (NULL != pSignalWindowDisplayItem) {
            QRectF parentRect = pSignalWindowDisplayItem->GetSignalWindowPaintRect();
            double dPaintL = (parentRect.left() < x) ? x : parentRect.left();
            double dPaintT = (parentRect.top() < y) ? y : parentRect.top();
            double dPaintR = (parentRect.right() < x+w) ? parentRect.right() : x+w;
            double dPaintB = (parentRect.bottom() < y+h) ? parentRect.bottom() : y+h;
            m_rectPaint = QRectF(dPaintL, dPaintT, dPaintR-dPaintL, dPaintB-dPaintT);

            // 如果宽度或者高度小于容错范围则直接将宽高赋值成0
            if ((m_rectPaint.width() < BCCommon::g_dPermissionError) || (m_rectPaint.height() < BCCommon::g_dPermissionError))
                m_rectPaint = QRectF(dPaintL, dPaintT, 0.0, 0.0);
        }
    }

    // 从右向左排列，尺寸暂时等于BCCommon::g_bSignalWindowTitleHeight
    QTransform trans = dynamic_cast<QGraphicsView *>(this->scene()->parent())->transform();
    double dScale = trans.m11();
    double dTitleHeight = BCCommon::g_nSignalWindowTitleHeight/dScale;
    double dIconSize = BCCommon::g_nSignalWindowTitleButtonIconSize/dScale;
    double dOffset = (dTitleHeight - dIconSize) / 2;
    m_pBtnClose->setPos(x+w-dTitleHeight+dOffset, y+dOffset);
    m_pBtnFullscreen->setPos(x+w-(2*dTitleHeight)+dOffset, y+dOffset);
    m_pBtnWindowShow->setPos(x+w-(3*dTitleHeight)+dOffset, y+dOffset);
    m_pBtnLock->setPos(x+w-(4*dTitleHeight)+dOffset, y+dOffset);
}

void BCSignalWindowTitleDisplayItem::RefreshButtonIcon()
{
    // 目前只涉及到锁定按钮
    m_pBtnLock->RefreshIcon();        // 锁定按钮
}

void BCSignalWindowTitleDisplayItem::SetDisplayText(const QString &qsText)
{
    m_qsTitle = qsText;
    m_pTextItem->SetText( qsText );

    this->update();
}

void BCSignalWindowTitleDisplayItem::RefreshDisplayTextColor()
{
    if (NULL == m_pTextItem)
        return;

    m_pTextItem->SetFontColor(BCCommon::g_nSignalWindowTitleTextColorR,
                              BCCommon::g_nSignalWindowTitleTextColorG,
                              BCCommon::g_nSignalWindowTitleTextColorB,
                              BCCommon::g_nSignalWindowTitleTextColorA);
}

void BCSignalWindowTitleDisplayItem::RefreshDisplayTextFont()
{
    if (NULL == m_pTextItem)
        return;

    m_pTextItem->SetFontFamily( BCCommon::g_sSignalWindowTitleTextFamilyName );
    m_pTextItem->SetFontSize( BCCommon::g_nSignalWindowTitleTextSize );
}

void BCSignalWindowTitleDisplayItem::RefreshDisplayTextPos()
{
    if (NULL == m_pTextItem)
        return;

    // 缩放比例
    QTransform trans = dynamic_cast<QGraphicsView *>(this->scene()->parent())->transform();
    double dScale = trans.m11();

    m_pTextItem->setPos(rect().topLeft());
    m_pTextItem->SetTextPosOffset(BCCommon::g_nSignalWindowTitleTextPosOffsetX/dScale, BCCommon::g_nSignalWindowTitleTextPosOffsetY/dScale);
}

void BCSignalWindowTitleDisplayItem::RefreshIsShowDisplayItem()
{
    ( BCCommon::g_bShowSignalWindowTitleText ) ? m_pTextItem->show() : m_pTextItem->hide();
    ( BCCommon::g_bShowSignalWindowTitleLockButton ) ? m_pBtnLock->show() : m_pBtnLock->hide();
    if ( BCCommon::g_bShowSignalWindowTitleFullScreenButton ) {
        m_pBtnFullscreen->show();
        m_pBtnWindowShow->show();
    } else {
        m_pBtnFullscreen->hide();
        m_pBtnWindowShow->hide();
    }
}

void BCSignalWindowTitleDisplayItem::SetTextItemVisible(bool b)
{
    m_bTextItemVisible = b;
    m_pTextItem->setVisible( b );
}

bool BCSignalWindowTitleDisplayItem::IsTextItemVisible()
{
    return m_bTextItemVisible;
}

void BCSignalWindowTitleDisplayItem::SetLockButtonVisible(bool b)
{
    m_bLockBtnVisible = b;
    m_pBtnLock->setVisible( b );
}

bool BCSignalWindowTitleDisplayItem::IsLockButtonVisible()
{
    return m_bLockBtnVisible;
}

void BCSignalWindowTitleDisplayItem::SetFullSceneButtonVisible(bool b)
{
    m_bFullscreenBtnVisible = b;
    m_pBtnFullscreen->setVisible( b );
}

bool BCSignalWindowTitleDisplayItem::IsFullSceneButtonVisible()
{
    return m_bFullscreenBtnVisible;
}

void BCSignalWindowTitleDisplayItem::SetWindowButtonVisible(bool b)
{
    m_bWindowBtnVisible = b;
    m_pBtnWindowShow->setVisible( b );
}

bool BCSignalWindowTitleDisplayItem::IsWindowButtonVisible()
{
    return m_bWindowBtnVisible;
}

void BCSignalWindowTitleDisplayItem::SetCloseButtonVisible(bool b)
{
    m_bCloseBtnVisible = b;
    m_pBtnClose->setVisible( b );
}

bool BCSignalWindowTitleDisplayItem::IsCloseButtonVisible()
{
    return m_bCloseBtnVisible;
}

void BCSignalWindowTitleDisplayItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget*/)
{
    // 缩放比例
    QTransform trans = painter->worldTransform();
    double dScale = trans.m11();

    painter->setPen(QPen(QBrush(QColor(BCCommon::g_nSignalWindowTitleLineColorR,
                                       BCCommon::g_nSignalWindowTitleLineColorG,
                                       BCCommon::g_nSignalWindowTitleLineColorB,
                                       BCCommon::g_nSignalWindowTitleLineColorA)),
                         BCCommon::g_nSignalWindowTitleLineWidth/dScale,
                         Qt::PenStyle(BCCommon::g_nSignalWindowTitleLineStyle)));

    painter->setBrush(QBrush(QColor(BCCommon::g_nSignalWindowTitleFillColorR,
                                    BCCommon::g_nSignalWindowTitleFillColorG,
                                    BCCommon::g_nSignalWindowTitleFillColorB,
                                    BCCommon::g_nSignalWindowTitleFillColorA)));

    // 重绘矩形
    painter->drawRect(m_rectPaint);

    // 刷新文字
    RefreshDisplayTextPos();
}
