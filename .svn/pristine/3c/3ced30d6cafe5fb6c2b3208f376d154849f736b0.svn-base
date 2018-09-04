#include "BCTextDisplayItem.h"
#include "BCSignalWindowTitleDisplayItem.h"
#include "BCSignalWindowBodyDisplayItem.h"
#include "BCSignalWindowBodySubDisplayItem.h"
#include "../Common/BCCommon.h"

BCTextDisplayItem::BCTextDisplayItem(QGraphicsItem * parent)
    :QGraphicsSimpleTextItem(parent)
{
    setAcceptHoverEvents( false );

    m_dTextPosOffsetX = 0.0;
    m_dTextPosOffsetY = 0.0;

    m_nTextLineColorR = 0;
    m_nTextLineColorG = 0;
    m_nTextLineColorB = 0;
    m_nTextLineColorA = 255;
    m_nTextLineWidth = 1;
    m_nTextLineStyle = 1;

    m_qsFontFamily = BCCommon::g_qsDefaultFontFamily;
    m_nFontSize = 12;
}

BCTextDisplayItem::BCTextDisplayItem(const QString & text, QGraphicsItem * parent)
    :QGraphicsSimpleTextItem(text, parent)
{
    setAcceptHoverEvents( false );

    m_dTextPosOffsetX = 0.0;
    m_dTextPosOffsetY = 0.0;

    m_nTextLineColorR = 0;
    m_nTextLineColorG = 0;
    m_nTextLineColorB = 0;
    m_nTextLineColorA = 255;
    m_nTextLineWidth = 1;
    m_nTextLineStyle = 1;

    m_qsFontFamily = BCCommon::g_qsDefaultFontFamily;
    m_nFontSize = 12;
}

void BCTextDisplayItem::SetText(const QString &qsText)
{
    this->setText( qsText );

    this->update();
}

void BCTextDisplayItem::SetTextPosOffset(double x, double y)
{
    m_dTextPosOffsetX = x;
    m_dTextPosOffsetY = y;

    //this->update();
}

void BCTextDisplayItem::SetFontColor(int r, int g, int b, int a)
{
    m_nTextLineColorR = r;
    m_nTextLineColorG = g;
    m_nTextLineColorB = b;
    m_nTextLineColorA = a;

    //this->update();
}

void BCTextDisplayItem::SetFontFamily(const QString &qsFontFamily)
{
    m_qsFontFamily = qsFontFamily;

    //this->update();
}

void BCTextDisplayItem::SetFontSize(int size)
{
    m_nFontSize = size;

    //this->update();
}

void BCTextDisplayItem::SetPainterClipRect(QPainter * painter, QRectF parentRect)
{
    // 计算父矩形和本矩形四个边线的偏移量
    double dOffsetL = this->mapToParent(m_boundingRect.left(), m_boundingRect.top()).x() - parentRect.left();
    double dOffsetT = this->mapToParent(m_boundingRect.left(), m_boundingRect.top()).y() - parentRect.top();
    double dOffsetR = this->mapToParent(m_boundingRect.right(), m_boundingRect.bottom()).x() - parentRect.right();
    double dOffsetB = this->mapToParent(m_boundingRect.right(), m_boundingRect.bottom()).y() - parentRect.bottom();
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

    // 如果宽度或者高度小于容错范围则直接将宽高赋值成0
    if ((rect.width() < BCCommon::g_dPermissionError) || (rect.height() < BCCommon::g_dPermissionError))
        rect = QRectF(rect.left(), rect.top(), 0.0, 0.0);

    painter->setClipRect(rect);
}

void BCTextDisplayItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget*/)
{
    // 设置字体、字号
    QFont font = painter->font();
    font.setFamily( m_qsFontFamily );
    font.setPixelSize( m_nFontSize );
    painter->setFont( font );

    // 设置字体颜色
    painter->setPen(QPen(QBrush(QColor(m_nTextLineColorR,
                                       m_nTextLineColorG,
                                       m_nTextLineColorB,
                                       m_nTextLineColorA)),
                         m_nTextLineWidth,
                         Qt::PenStyle(m_nTextLineStyle)));

    // 文字占用的矩形尺寸，需计算偏移量
    m_boundingRect = painter->boundingRect(QRectF(this->boundingRect().left()+m_dTextPosOffsetX,
                                                  this->boundingRect().top()+m_dTextPosOffsetY,
                                                  this->boundingRect().width(),
                                                  this->boundingRect().height()), Qt::AlignLeft, this->text());

    // 根据父类矩形对文字区域进行剪切
    BCSignalWindowTitleDisplayItem *pSignalWindowTitleItem = dynamic_cast<BCSignalWindowTitleDisplayItem *>( this->parentItem() );
    if (NULL != pSignalWindowTitleItem) {
        SetPainterClipRect(painter, pSignalWindowTitleItem->GetSignalWindowTitlePaintRect());
//        // 计算父矩形和本矩形四个边线的偏移量
//        double dOffsetL = this->mapToParent(m_boundingRect.left(), m_boundingRect.top()).x() - pSignalWindowTitleItem->GetSignalWindowTitlePaintRect().left();
//        double dOffsetT = this->mapToParent(m_boundingRect.left(), m_boundingRect.top()).y() - pSignalWindowTitleItem->GetSignalWindowTitlePaintRect().top();
//        double dOffsetR = this->mapToParent(m_boundingRect.right(), m_boundingRect.bottom()).x() - pSignalWindowTitleItem->GetSignalWindowTitlePaintRect().right();
//        double dOffsetB = this->mapToParent(m_boundingRect.right(), m_boundingRect.bottom()).y() - pSignalWindowTitleItem->GetSignalWindowTitlePaintRect().bottom();
//        // 如果父矩形和本矩形没有交集则清除偏移量
//        dOffsetL = (dOffsetL > 0.0) ? 0.0 : dOffsetL;
//        dOffsetT = (dOffsetT > 0.0) ? 0.0 : dOffsetT;
//        dOffsetR = (dOffsetR < 0.0) ? 0.0 : dOffsetR;
//        dOffsetB = (dOffsetB < 0.0) ? 0.0 : dOffsetB;

//        // 根据偏移量对矩形进行剪切
//        QRectF rect = QRectF(m_boundingRect.left()-dOffsetL,
//                             m_boundingRect.top()-dOffsetT,
//                             m_boundingRect.width()-dOffsetR,
//                             m_boundingRect.height()-dOffsetB);

//        // 如果宽度或者高度小于容错范围则直接将宽高赋值成0
//        if ((rect.width() < BCCommon::g_dPermissionError) || (rect.height() < BCCommon::g_dPermissionError))
//            rect = QRectF(rect.left(), rect.top(), 0.0, 0.0);

//        painter->setClipRect(rect);
    }

    // 根据父类矩形对文字区域进行剪切
    BCSignalWindowBodyDisplayItem *pSignalWindowBodyItem = dynamic_cast<BCSignalWindowBodyDisplayItem *>( this->parentItem() );
    if (NULL != pSignalWindowBodyItem) {
        SetPainterClipRect(painter, pSignalWindowBodyItem->GetSignalWindowBodyPaintRect());
//        // 计算父矩形和本矩形四个边线的偏移量
//        double dOffsetL = this->mapToParent(m_boundingRect.left(), m_boundingRect.top()).x() - pSignalWindowBodyItem->GetSignalWindowBodyPaintRect().left();
//        double dOffsetT = this->mapToParent(m_boundingRect.left(), m_boundingRect.top()).y() - pSignalWindowBodyItem->GetSignalWindowBodyPaintRect().top();
//        double dOffsetR = this->mapToParent(m_boundingRect.right(), m_boundingRect.bottom()).x() - pSignalWindowBodyItem->GetSignalWindowBodyPaintRect().right();
//        double dOffsetB = this->mapToParent(m_boundingRect.right(), m_boundingRect.bottom()).y() - pSignalWindowBodyItem->GetSignalWindowBodyPaintRect().bottom();
//        // 如果父矩形和本矩形没有交集则清除偏移量
//        dOffsetL = (dOffsetL > 0.0) ? 0.0 : dOffsetL;
//        dOffsetT = (dOffsetT > 0.0) ? 0.0 : dOffsetT;
//        dOffsetR = (dOffsetR < 0.0) ? 0.0 : dOffsetR;
//        dOffsetB = (dOffsetB < 0.0) ? 0.0 : dOffsetB;

//        // 根据偏移量对矩形进行剪切
//        QRectF rect = QRectF(m_boundingRect.left()-dOffsetL,
//                             m_boundingRect.top()-dOffsetT,
//                             m_boundingRect.width()-dOffsetR,
//                             m_boundingRect.height()-dOffsetB);

//        // 如果宽度或者高度小于容错范围则直接将宽高赋值成0
//        if ((rect.width() < BCCommon::g_dPermissionError) || (rect.height() < BCCommon::g_dPermissionError))
//            rect = QRectF(rect.left(), rect.top(), 0.0, 0.0);

//        painter->setClipRect(rect);
    }

    QTransform trans = painter->worldTransform();
    double scale = trans.m11();
    painter->scale(1/scale, 1/scale);

    // 绘制文字
    painter->drawText(QRectF(m_boundingRect.left(),
                             m_boundingRect.top(),
                             m_boundingRect.width()+2,
                             m_boundingRect.height()+2), Qt::AlignLeft, this->text());
}
