#include "BCPlanMapButtonGraphicsItem.h"

#include <QPainter>
#include <QTableWidgetItem>
#include <QGraphicsSceneMouseEvent>
#include <qDebug>
BCPlanMapButtonGraphicsItem::BCPlanMapButtonGraphicsItem(const QString &id, const QString &text, QPointF pos, QGraphicsItem *parent)
    :QGraphicsRectItem(parent)
{
    m_qsId = id;
    m_qsText = text;
    m_x = 0.0;
    m_y = 0.0;
    m_bPress = false;
    m_pTableWidgetItem = NULL;

    m_pText = new QGraphicsSimpleTextItem(m_qsText, this);

    // 设置按钮初始位置
    this->setRect(pos.x(), pos.y(), 75, 25);

    QString qsTempText = m_qsText;
    while ( 1 ) {
        QRectF testRect = m_pText->boundingRect();
        QRectF buttonRect = this->rect();

        // 当文字的尺寸小于按钮尺寸时退出
        if ((testRect.width() < buttonRect.width()) && (testRect.height() < buttonRect.height()))
            break;
        else {
            qsTempText = qsTempText.left(qsTempText.count()-1);
            m_pText->setText( qsTempText );
        }
    }
}

BCPlanMapButtonGraphicsItem::~BCPlanMapButtonGraphicsItem()
{
}

void BCPlanMapButtonGraphicsItem::SetTableWidgetItem(QTableWidgetItem *pItem)
{
    m_pTableWidgetItem = pItem;
    m_pTableWidgetItem->setText(QString("(%1, %2)")
                                .arg(mapToScene(rect().topLeft()).x())
                                .arg(mapToScene(rect().topLeft()).y()));
}

void BCPlanMapButtonGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    // 点击单个屏幕时
    if(event->button()== Qt::LeftButton){
        m_bPress = true;

        // 相对于scene左上角的坐标，缩放不影响坐标
        m_x = event->scenePos().x() - mapToScene(rect().left(), 0).x();
        m_y = event->scenePos().y() - mapToScene(0, rect().top()).y();
    }
}

void BCPlanMapButtonGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
    // 点击单个屏幕时
    if (m_bPress) {
        // 矩形左上角坐标，缩放无影响
        int x = event->scenePos().x() - m_x;
        int y = event->scenePos().y() - m_y;

        // 移动位置需要去掉矩形相对位置
        this->setPos(x - rect().left(), y - rect().top());

        if (NULL != m_pTableWidgetItem) {
            m_pTableWidgetItem->setText(QString("(%1, %2)")
                                        .arg(x)
                                        .arg(y));
        }
    }
}

void BCPlanMapButtonGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent */*event*/)
{
    m_bPress = false;
}

void BCPlanMapButtonGraphicsItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget*/)
{
    // 缩放比例
    QTransform trans = painter->worldTransform();
    double dScale = trans.m11();

    // 设置边线
    painter->setPen(QPen(QBrush(QColor(0, 0, 0)), 1/dScale, Qt::SolidLine));

    // 设置颜色填充，渐变色
    painter->setBrush(QBrush(QColor(155, 155, 155)));

    // 重绘矩形
    painter->drawRect(rect());

    // 重绘内部文字
    int nTextX = rect().center().x() - (m_pText->boundingRect().width()/2);
    int nTextY = rect().center().y() - (m_pText->boundingRect().height()/2);
    m_pText->setPos(nTextX, nTextY);
}
