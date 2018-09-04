#include "BCSingleDisplayVirtualWidget.h"
#include "../Common/BCCommon.h"
#include "../Model/BCMDisplay.h"

BCSingleDisplayVirtualWidget::BCSingleDisplayVirtualWidget(int row, int col, int i, int j, QWidget *parent) : QWidget(parent)
{
    m_row = row;
    m_col = col;
    m_i = i;
    m_j = j;

    this->show();
}

void BCSingleDisplayVirtualWidget::paintEvent(QPaintEvent */*e*/)
{
    QPainter painter(this);

    // 绘制背景色
    painter.setBrush( QBrush(QColor(BCCommon::g_nVirtualRectFillColorR,
                                    BCCommon::g_nVirtualRectFillColorG,
                                    BCCommon::g_nVirtualRectFillColorB,
                                    BCCommon::g_nVirtualRectFillColorA)));

    painter.setPen(QPen(Qt::black,1,Qt::NoPen));
    painter.drawRect( this->rect() );

    // 绘制边线，最边缘的线不需要绘制
    painter.setPen(QPen(Qt::black,1,Qt::DashLine));

    // 左边线
    if (m_i != 0) {
        painter.drawLine(rect().left(), rect().top(), rect().left(), rect().bottom());
    }
    // 上边线
    if (m_j != 0) {
        painter.drawLine(rect().left(), rect().top(), rect().right(), rect().top());
    }
}
