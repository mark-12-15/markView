#include "BCSettingBoardCardDlg.h"
#include "ui_BCSettingBoardCardDlg.h"
#include <QScrollBar>
#include <QGraphicsSceneHoverEvent>
#include "../Common/BCCommon.h"
#include "../Common/BCLocalTcpSocket.h"
#include "../Common/BCLocalServer.h"

// 板卡的尺寸
#define BACKIMAGEWIDTH  968
#define BACKIMAGEHEIGHT 95

// 板卡内节点的尺寸
#define NODEIMAGEWIDTH  192
#define NODEIMAGEHEIGHT 93

// 共分6级，蓝色（1个窗口），紫色，深紫，粉红，橙色（5个或者5个以上）
#define COLOROFGROUP1   QColor(0, 0, 255)
#define COLOROFGROUP2   QColor(153, 50, 204)
#define COLOROFGROUP3   QColor(75, 0, 130)
#define COLOROFGROUP4   QColor(255, 105, 180)
#define COLOROFGROUP5   QColor(255, 165, 0)

BCSettingBoardCardNodeItem::BCSettingBoardCardNodeItem(BSBoardCardNode *pBoardCardNode, BCSettingBoardCardItem *parent)
    :QGraphicsRectItem(parent)
{
    m_bHighLight = false;
    m_dScale    = 1.0;
    m_pBoardCardNode = pBoardCardNode;
}

BCSettingBoardCardNodeItem::~BCSettingBoardCardNodeItem()
{

}

void BCSettingBoardCardNodeItem::Refresh(double dScale, double dCardOffsetX, double dCardOffsetY)
{
    // 缩放的图片尺寸
    m_dScale = dScale;

    // 缩放的图片尺寸
    double dImageWidth = NODEIMAGEWIDTH*m_dScale;
    double dImageHeight = NODEIMAGEHEIGHT*m_dScale;

    // 绘制图片的起始位置
    double dPosX = ((m_pBoardCardNode->portName-1) * NODEIMAGEWIDTH + 0.5*(BACKIMAGEWIDTH - 4*NODEIMAGEWIDTH)) * m_dScale;
    double dPosY = 1 * m_dScale;

    this->setRect(dPosX+dCardOffsetX, dPosY+dCardOffsetY, dImageWidth, dImageHeight);

    this->update();
}

void BCSettingBoardCardNodeItem::SetHighLight(bool b)
{
    if (m_bHighLight == b)
        return;

    m_bHighLight = b;
    this->update();
}

bool BCSettingBoardCardNodeItem::IsHighLight()
{
    return m_bHighLight;
}

void BCSettingBoardCardNodeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/, QWidget */*widget*/)
{
    // 根据sceneRect尺寸自动设置字体
    int nFontSize = 4;
    QRectF sceneRect = this->scene()->sceneRect();
    if ((sceneRect.width() < 600) || (sceneRect.height() < 400))
        nFontSize = 4;
    else if ((sceneRect.width() < 700) || (sceneRect.height() < 500))
        nFontSize = 5;
    else if ((sceneRect.width() < 800) || (sceneRect.height() < 600))
        nFontSize = 6;
    else if ((sceneRect.width() < 900) || (sceneRect.height() < 700))
        nFontSize = 7;
    else
        nFontSize = 8;

    // 1.画底色，高亮是黑色，低亮的透明
    painter->fillRect(this->rect(), QColor(0, 0, 0, m_bHighLight ? 255 : 0));

    // 2.画图片，根据类型选择
    QString qsImagePath = (1 == m_pBoardCardNode->type) ? QString("board/p_DVI.png") : QString("board/p_HDBT.png");
    QPixmap pixmap = QPixmap(BCCommon::g_qsImageFilePrefix+qsImagePath)
              .scaled(this->rect().width(), this->rect().height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    painter->drawPixmap(this->rect(), pixmap, QRectF(0, 0, this->rect().width(), this->rect().height()));

    // 3.画文字，白色，在图片的下面1/3区域内绘制
    QFont font = painter->font();
    font.setPointSizeF( nFontSize );
    painter->setFont( font );

    painter->setPen(QColor(255, 255, 255));
    QString qsImageText = (1 == m_pBoardCardNode->type) ? QString("p_DVI") : QString("p_HDBT");
    painter->drawText(QRectF(this->rect().left(),
                             this->rect().height()*2/3+this->rect().top(),
                             this->rect().width(),
                             this->rect().height()*1/3),
                      Qt::AlignCenter, qsImageText);

    // 4.画连接状态，右下角的圆形，红色的无连接，绿色的有连接
    QColor validColor = (m_pBoardCardNode->valid == 1) ? QColor(0, 255, 0) : QColor(255, 0, 0);
    painter->setBrush(QBrush(validColor));
    painter->drawEllipse(this->rect().width()*13/16+this->rect().left(),
                         this->rect().height()*3/4+this->rect().top(),
                         this->rect().width()/10,
                         this->rect().width()/10);

    // 5.画组号，左上角的圆形内附数字
    if ((2 == m_pBoardCardNode->cardType) && (255 != m_pBoardCardNode->group)) {
        font.setPointSizeF( nFontSize+2 );
        painter->setFont( font );

        QColor backColor = Qt::gray;
        int nBackColorIndex = m_pBoardCardNode->group % 5;
        switch ( nBackColorIndex ) {
        case 0:
            backColor = COLOROFGROUP1;
            break;
        case 1:
            backColor = COLOROFGROUP2;
            break;
        case 2:
            backColor = COLOROFGROUP3;
            break;
        case 3:
            backColor = COLOROFGROUP4;
            break;
        case 4:
            backColor = COLOROFGROUP5;
            break;
        default:
            break;
        }

        painter->setBrush(QBrush(backColor));
        painter->drawEllipse(this->rect().left(), this->rect().top(), this->rect().height()/2, this->rect().height()/2);
        painter->drawText(QRectF(this->rect().left(), this->rect().top(), this->rect().height()/2, this->rect().height()/2), Qt::AlignCenter, QString::number(m_pBoardCardNode->group));
    }
}

// --------------------------------------------------------------------------------------------------------------------------

BCSettingBoardCardItem::BCSettingBoardCardItem(BSBoardCard *pBoardCard, int nPosX, int nPosY, double dOffsetX, double dOffsetY)
    :QGraphicsRectItem()
{
    m_pBoardCard = pBoardCard;
    m_dScale = 1.0;

    m_nPosX = nPosX;
    m_nPosY = nPosY;

    m_dOffsetX = dOffsetX;
    m_dOffsetY = dOffsetY;

    m_bHighLight = false;

    // 添加节点
    if (NULL != m_pBoardCard) {
        BSBoardCardNode *pBoardCardNode = m_pBoardCard->pNode;
        while (NULL != pBoardCardNode) {
            BCSettingBoardCardNodeItem *pNode = new BCSettingBoardCardNodeItem(pBoardCardNode, this);

            pBoardCardNode = pBoardCardNode->pNext;
        }
    }
}

BCSettingBoardCardItem::~BCSettingBoardCardItem()
{

}

void BCSettingBoardCardItem::Refresh(double dScale, double dOffsetX, double dOffsetY)
{
    if ((dScale < 0) || (dOffsetX < 0) || (dOffsetY < 0))
        return;

    m_dScale = dScale;

    m_dOffsetX = dOffsetX;
    m_dOffsetY = dOffsetY;

    double dPosX = (m_nPosX == 0) ? 0 : (BACKIMAGEWIDTH * dScale);
    double dPosY = m_nPosY * BACKIMAGEHEIGHT * dScale;
    this->setRect(dPosX+m_dOffsetX, dPosY+m_dOffsetY, BACKIMAGEWIDTH*m_dScale, BACKIMAGEHEIGHT*m_dScale);

    // 刷新节点
    QList<QGraphicsItem *> lstItems = this->childItems();
    for (int i = 0; i < lstItems.count(); i++) {
        BCSettingBoardCardNodeItem *pNode = dynamic_cast<BCSettingBoardCardNodeItem *>( lstItems.at(i) );
        if (NULL == pNode)
            continue;

        pNode->Refresh(dScale, dPosX+m_dOffsetX, dPosY+m_dOffsetY);
    }
}

void BCSettingBoardCardItem::paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/, QWidget */*widget*/)
{
    QPixmap pixmap = QPixmap(BCCommon::g_qsImageFilePrefix+"board/back.png")
              .scaled(BACKIMAGEWIDTH*m_dScale, BACKIMAGEHEIGHT*m_dScale, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    double dPosX = (m_nPosX == 0) ? 0 : (BACKIMAGEWIDTH * m_dScale);
    double dPosY = m_nPosY * BACKIMAGEHEIGHT * m_dScale;

    painter->drawPixmap(QRectF(dPosX+m_dOffsetX, dPosY+m_dOffsetY, BACKIMAGEWIDTH*m_dScale, BACKIMAGEHEIGHT*m_dScale),
                        pixmap,
                        QRectF(0, 0, BACKIMAGEWIDTH*m_dScale, BACKIMAGEHEIGHT*m_dScale));
}

// --------------------------------------------------------------------------------------------------------------------------

BCSettingBoardCardGraphicsView::BCSettingBoardCardGraphicsView(QWidget *parent)
    :QGraphicsView(parent)
{
    this->setMouseTracking(true);

    m_pBoardCardDlg = NULL;
    m_pBoardCard = NULL;
    m_pLabel = NULL;
    m_nType = -1;
    m_nMouseType = -1;
    m_dViewScale = 1.0;

    m_pScene = new QGraphicsScene( this );
    this->setScene( m_pScene );

    // 每次初始化重新定义scene尺寸
    m_pScene->setSceneRect( 0.0, 0.0, this->rect().width(), this->rect().height() );
}

BCSettingBoardCardGraphicsView::~BCSettingBoardCardGraphicsView()
{
    delete m_pScene;
    m_pScene = NULL;

    if (NULL != m_pLabel) {
        delete m_pLabel;
        m_pLabel = NULL;
    }
}

void BCSettingBoardCardGraphicsView::resizeEvent(QResizeEvent * event)
{
    QSize size = event->size();
    m_pScene->setSceneRect(0.0, 0.0, size.width(), size.height());

    RefreshBoardCard();
}

void BCSettingBoardCardGraphicsView::mousePressEvent(QMouseEvent *event)
{
    m_beginPos = event->pos();

    if (event->button() == Qt::LeftButton) {
        m_nMouseType = 0;

        if ( QApplication::keyboardModifiers () == Qt::ControlModifier) {
            ReverseHighLight( m_beginPos );

            // 判断高亮状态并刷新组信息
            QList<BCSettingBoardCardNodeItem *> lstNodeItem;
            QList<QGraphicsItem *> lstItems = m_pScene->items();
            for (int i = 0; i < lstItems.count(); i++) {
                BCSettingBoardCardNodeItem *pItem = dynamic_cast<BCSettingBoardCardNodeItem *>( lstItems.at(i) );
                if (NULL == pItem)
                    continue;

                if ( pItem->m_bHighLight )
                    lstNodeItem.append( pItem );
            }

            if (NULL != m_pBoardCardDlg)
                m_pBoardCardDlg->RefreshNodeInfo( lstNodeItem );
        } else {
            // 1.判断是否点中节点
            if ( HighLight( m_beginPos ) ) {
                m_nMouseType = 1;

                QList<QGraphicsItem *> lstItems = m_pScene->items();
                for (int i = 0; i < lstItems.count(); i++) {
                    BCSettingBoardCardNodeItem *pItem = dynamic_cast<BCSettingBoardCardNodeItem *>( lstItems.at(i) );
                    if (NULL == pItem)
                        continue;

                    if ( !pItem->IsHighLight() )
                        continue;

                    if (NULL != m_pBoardCardDlg)
                        m_pBoardCardDlg->RefreshNodeInfo( pItem );

                    break;
                }
            } else {
                if (NULL != m_pBoardCardDlg)
                    m_pBoardCardDlg->RefreshNodeInfo( NULL );
            }

            // 2.判断点中的板卡，因为需要取板卡状态
            QList<QGraphicsItem *> lstItems = m_pScene->items();
            for (int i = 0; i < lstItems.count(); i++) {
                BCSettingBoardCardItem *pItem = dynamic_cast<BCSettingBoardCardItem *>( lstItems.at(i) );
                if (NULL == pItem)
                    continue;

                if ( !pItem->m_bHighLight )
                    continue;

                if (NULL != m_pBoardCardDlg)
                    m_pBoardCardDlg->RefreshBoardCardPos( pItem->m_pBoardCard->pos+1 );

                break;
            }
        }
    }
}

void BCSettingBoardCardGraphicsView::mouseMoveEvent(QMouseEvent *e)
{
    QPointF currentPos = e->pos();

    if (0 == m_nMouseType) {
        // 如果没有点中节点则移动画布
        double dOffsetX = currentPos.x() - m_beginPos.x();
        double dOffsetY = currentPos.y() - m_beginPos.y();

        m_beginPos = currentPos;

        int cV = this->verticalScrollBar()->value();
        int cH = this->horizontalScrollBar()->value();

        this->verticalScrollBar()->setValue(cV - dOffsetY);
        this->horizontalScrollBar()->setValue(cH - dOffsetX);
    }

    if (1 == m_nMouseType) {
        // 画矩形
        double x = (m_beginPos.x() < e->pos().x()) ? m_beginPos.x() : e->pos().x();
        double y = (m_beginPos.y() < e->pos().y()) ? m_beginPos.y() : e->pos().y();
        double w = qAbs(m_beginPos.x() - e->pos().x());
        double h = qAbs(m_beginPos.y() - e->pos().y());

        HighLight(QRectF(x, y, w, h));

        // 判断高亮状态并刷新组信息
        QList<BCSettingBoardCardNodeItem *> lstNodeItem;
        QList<QGraphicsItem *> lstItems = m_pScene->items();
        for (int i = 0; i < lstItems.count(); i++) {
            BCSettingBoardCardNodeItem *pItem = dynamic_cast<BCSettingBoardCardNodeItem *>( lstItems.at(i) );
            if (NULL == pItem)
                continue;

            if ( pItem->m_bHighLight )
                lstNodeItem.append( pItem );
        }

        // 如果只有1个节点则显示节点信息
        if (NULL != m_pBoardCardDlg) {
            if (1 == lstNodeItem.count())
                m_pBoardCardDlg->RefreshNodeInfo( lstNodeItem.first() );
            else
                m_pBoardCardDlg->RefreshNodeInfo( lstNodeItem );
        }
    }

    if (-1 == m_nMouseType) {
        BCSettingBoardCardNodeItem *pCurrentItem = GetBoardCardNode( currentPos );
        if (NULL == pCurrentItem) {
            if (NULL != m_pLabel)
                m_pLabel->setVisible( false );
        } else {
            if (NULL == m_pLabel) {
                m_pLabel = new QLabel( this );
                m_pLabel->setMargin(10);
                m_pLabel->setStyleSheet("QLabel{background-color:rgb(234,242,251);  color: blue;border-radius: 10px;  border: 2px groove yellow;}");
                m_pLabel->setGeometry(0,0,120,140);
            }

            if (NULL != m_pLabel)
                m_pLabel->setVisible( true );

            m_pLabel->setText(QString("<font color=blue>%1    %2 <br> %3    %4<br>%5    %6"
                                      "<br>%7    %8<br>%9    %10<br>%11 XX    %12<br>%13 YY    %14<br>%15    %16</font>")
                                       .arg(QObject::tr("接口类型"))
                                       .arg(pCurrentItem->m_pBoardCardNode->type)
                                       .arg(QObject::tr("接口分类"))
                                       .arg(pCurrentItem->m_pBoardCardNode->cardType)
                                       .arg(QObject::tr("物理序号"))
                                       .arg(pCurrentItem->m_pBoardCardNode->valid)
                                       .arg(QObject::tr("板位"))
                                       .arg(pCurrentItem->m_pBoardCardNode->boardCardPos)
                                       .arg(QObject::tr("端口"))
                                       .arg(pCurrentItem->m_pBoardCardNode->portName)
                                       .arg(QObject::tr("分辨率"))
                                       .arg(pCurrentItem->m_pBoardCardNode->xx)
                                       .arg(QObject::tr("分辨率"))
                                       .arg(pCurrentItem->m_pBoardCardNode->yy)
                                       .arg(QObject::tr("组号"))
                                       .arg(pCurrentItem->m_pBoardCardNode->group));

            QRect labelRect = m_pLabel->frameGeometry();

            int offX = width() - ( currentPos.x() + labelRect.width() ); //水平超出大小
            int offY = height() - ( currentPos.y() + labelRect.height()+10 ); //竖直超出大小
            offX = offX < 0 ? -labelRect.width() : 0;
            offY = offY < 0 ? -labelRect.height() - 30 : 0;
            m_pLabel->move(currentPos.x() + offX, currentPos.y() + offY + 20);
        }
    }
}

void BCSettingBoardCardGraphicsView::mouseReleaseEvent(QMouseEvent* /*event*/)
{
    m_nMouseType = -1;
}

void BCSettingBoardCardGraphicsView::wheelEvent(QWheelEvent *event)
{
    if ((m_dViewScale < 0.0) || (m_dViewScale > 3.0))
        return;

    // 向上为正，向下为负，每下120度
    QPoint numDegrees = event->angleDelta();

    // 计算缩放值
    if (numDegrees.y() > 0) {
        m_dViewScale += 0.1;
    } else {
        m_dViewScale -= 0.1;
    }

    m_dViewScale = (m_dViewScale < 1.0) ? 1.0 : m_dViewScale;
    m_dViewScale = (m_dViewScale > 3.0) ? 3.0 : m_dViewScale;

    SetScale( m_dViewScale );
}

void BCSettingBoardCardGraphicsView::SetScale(double dScale)
{
    // scroll value of before scale
    int nBeforeValueH = horizontalScrollBar()->value();
    int nBeforeMaxValueH = horizontalScrollBar()->maximum();

    int nBeforeValueV = verticalScrollBar()->value();
    int nBeforeMaxValueV = verticalScrollBar()->maximum();

    // 恢复原尺寸再进行缩放
    resetTransform();
    scale(dScale, dScale);

    // set scroll value
    int nAfterMaxValueH = horizontalScrollBar()->maximum();
    if ((0 != nBeforeMaxValueH) && (0 != nAfterMaxValueH)) {
        int dValue = nBeforeValueH + ((nAfterMaxValueH-nBeforeMaxValueH) / 2);
        horizontalScrollBar()->setValue( dValue );
    }

    int nAfterMaxValueV = verticalScrollBar()->maximum();
    if ((0 != nBeforeMaxValueV) && (0 != nAfterMaxValueV)) {
        int dValue = nBeforeValueV + ((nAfterMaxValueV-nBeforeMaxValueV) / 2);
        verticalScrollBar()->setValue( dValue );
    }
}

void BCSettingBoardCardGraphicsView::Init(BCSettingBoardCardDlg *pBoardCardDlg, BSBoardCard *pBoardCard, int type)
{
    m_pBoardCardDlg = pBoardCardDlg;
    m_pBoardCard = pBoardCard;
    m_nType = type;

    RefreshBoardCard();
}

void BCSettingBoardCardGraphicsView::RefreshBoardCard()
{
    if ((NULL == m_pBoardCard) || (-1 == m_nType))
        return;

    int nBoardCardColCount = (1 == m_nType) ? 4 : 20;

    // 板卡图片尺寸
    int nImageWidth = BACKIMAGEWIDTH * 2;
    int nImageHeight = BACKIMAGEHEIGHT * nBoardCardColCount;
    // 绘制区域尺寸
    QRectF sceneRect = m_pScene->sceneRect();

    // 需要计算图片缩放比例和偏移量
    double dImageScale = 1.0;
    double dOffsetX = 0.0;
    double dOffsetY = 0.0;
    double dWHScaleDiff = (1.0*nImageWidth / nImageHeight) - (sceneRect.width() / sceneRect.height());
    if ((dWHScaleDiff > -BCCommon::g_dPermissionError) && (dWHScaleDiff < BCCommon::g_dPermissionError)) {
        dImageScale = sceneRect.width() / nImageWidth;
    } else if (dWHScaleDiff < -BCCommon::g_dPermissionError) {
        dImageScale = sceneRect.height() / nImageHeight;
        dOffsetX = (sceneRect.width() - (nImageWidth * dImageScale)) * 0.5;
    } else if (dWHScaleDiff > BCCommon::g_dPermissionError) {
        dImageScale = sceneRect.width() / nImageWidth;
        dOffsetY = (sceneRect.height() - (nImageHeight * dImageScale)) * 0.5;
    }

    // 添加板卡或者更新板卡位置
    QList<QGraphicsItem *> lstItems = m_pScene->items();
    if ( lstItems.isEmpty() ) {
        int i = 0;
        BSBoardCard *pFirstBoardCard = NULL;
        while (NULL != m_pBoardCard) {
            BCSettingBoardCardItem *pItem = new BCSettingBoardCardItem(m_pBoardCard, i%2, i/2, dOffsetX, dOffsetY);
            m_pScene->addItem( pItem );

            pItem->Refresh(dImageScale, dOffsetX, dOffsetY);

            if (NULL == pFirstBoardCard)
                pFirstBoardCard = m_pBoardCard;

            m_pBoardCard = m_pBoardCard->pNext;
            i++;
        }

        // 复位到Header
        m_pBoardCard = pFirstBoardCard;
    } else {
        for (int i = 0; i < lstItems.count(); i++) {
            BCSettingBoardCardItem *pItem = dynamic_cast<BCSettingBoardCardItem *>( lstItems.at(i) );
            if (NULL == pItem)
                continue;

            pItem->Refresh(dImageScale, dOffsetX, dOffsetY);
        }
    }
}

BCSettingBoardCardNodeItem *BCSettingBoardCardGraphicsView::GetBoardCardNode(QPointF pt)
{
    BCSettingBoardCardNodeItem *pItem = NULL;
    QPointF ptScene = this->mapToScene(pt.x(), pt.y());
    QList<QGraphicsItem *> lst = m_pScene->items( ptScene );
    QListIterator<QGraphicsItem *> it( lst );
    while (it.hasNext()) {
        pItem = dynamic_cast<BCSettingBoardCardNodeItem *>( it.next() );
        if (NULL != pItem)
            break;
    }

    return pItem;
}

void BCSettingBoardCardGraphicsView::ReverseHighLight(QPointF pt)
{
    QPointF ptScene = this->mapToScene(pt.x(), pt.y());
    QList<QGraphicsItem *> lst = m_pScene->items( ptScene );
    QListIterator<QGraphicsItem *> it( lst );
    while (it.hasNext()) {
        BCSettingBoardCardNodeItem *pItem = dynamic_cast<BCSettingBoardCardNodeItem *>( it.next() );
        if (NULL == pItem)
            continue;

        pItem->SetHighLight( !pItem->IsHighLight() );
    }
}

bool BCSettingBoardCardGraphicsView::HighLight(QPointF pt)
{
    ClearHighLight();

    bool bHighLight = false;
    QPointF ptScene = this->mapToScene(pt.x(), pt.y());
    QList<QGraphicsItem *> lst = m_pScene->items( ptScene );
    QListIterator<QGraphicsItem *> it( lst );
    while (it.hasNext()) {
        QGraphicsItem *pBaseItem = it.next();

        // 高亮节点
        BCSettingBoardCardNodeItem *pItem = dynamic_cast<BCSettingBoardCardNodeItem *>( pBaseItem );
        if (NULL != pItem) {
            pItem->SetHighLight( true );

            // 高亮归属板卡
            BCSettingBoardCardItem *pCardItem = dynamic_cast<BCSettingBoardCardItem *>( pItem->parentItem() );
            if (NULL != pCardItem)
                pCardItem->m_bHighLight = true;

            bHighLight = true;
        }

        // 高亮归属板卡
        BCSettingBoardCardItem *pCardItem = dynamic_cast<BCSettingBoardCardItem *>( pBaseItem );
        if (NULL != pCardItem)
            pCardItem->m_bHighLight = true;
    }

    return bHighLight;
}

bool BCSettingBoardCardGraphicsView::HighLight(QRectF rect)
{
    ClearHighLight();

    QPointF lt = this->mapToScene(rect.left(), rect.top());
    QPointF rb = this->mapToScene(rect.right(), rect.bottom());

    bool bIsLine = false;
    QPolygonF polygon;
    if ((qAbs(lt.x()-rb.x()) < BCCommon::g_dPermissionError) ||
            (qAbs(lt.y()-rb.y()) < BCCommon::g_dPermissionError)) {
        bIsLine = true;

        polygon << lt << rb;
    }

    bool bHighLight = false;
    QList<QGraphicsItem *> lst = m_pScene->items( bIsLine ? polygon : QRectF(lt.x(), lt.y(), rb.x()-lt.x(), rb.y()-lt.y()) );
    QListIterator<QGraphicsItem *> it( lst );
    while (it.hasNext()) {
        BCSettingBoardCardNodeItem *pItem = dynamic_cast<BCSettingBoardCardNodeItem *>( it.next() );
        if (NULL == pItem)
            continue;

        pItem->SetHighLight( true );
        bHighLight = true;
    }

    return bHighLight;
}

void BCSettingBoardCardGraphicsView::ClearHighLight()
{
    QList<QGraphicsItem *> lst = m_pScene->items();
    QListIterator<QGraphicsItem *> it( lst );
    while (it.hasNext()) {
        QGraphicsItem *pItem = it.next();

        BCSettingBoardCardNodeItem *pNodeItem = dynamic_cast<BCSettingBoardCardNodeItem *>( pItem );
        if (NULL != pNodeItem)
            pNodeItem->SetHighLight( false );

        BCSettingBoardCardItem *pCardItem = dynamic_cast<BCSettingBoardCardItem *>( pItem );
        if (NULL != pCardItem)
            pCardItem->m_bHighLight = false;

    }
}

// --------------------------------------------------------------------------------------------------------------------------
BCSettingBoardCardDlg::BCSettingBoardCardDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingBoardCardDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("板位图"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    m_pTcpSocket = NULL;
    m_pNodeItem = NULL;
    m_nBoardPos = 1;

    // 判断连接方式
    Init();

    // ??? 初始化板卡，展会测试
    onBoardCard(0, 20);

    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
    m_pTimer->start(5000);

    // 刷新右侧设置界面和板卡信息标题
    RefreshNodeInfo(NULL);
    RefreshBoardCardPos( 1 );
}

BCSettingBoardCardDlg::~BCSettingBoardCardDlg()
{
    if (NULL != m_pTcpSocket) {
        m_pTcpSocket->disconnect();
        m_pTcpSocket->deleteLater();
    }

    m_pTimer->stop();
    m_pTimer->deleteLater();

    delete ui;
}
void BCSettingBoardCardDlg::DestroyBoardCardData()
{
    while (NULL != m_pBoardCard) {
        while (NULL != m_pBoardCard->pNode) {
            BSBoardCardNode *pNextNode = m_pBoardCard->pNode->pNext;

            delete m_pBoardCard->pNode;
            m_pBoardCard->pNode = pNextNode;
        }

        BSBoardCard *pNext = m_pBoardCard->pNext;

        delete m_pBoardCard;
        m_pBoardCard = pNext;
    }
}
void BCSettingBoardCardDlg::Init()
{
    const unsigned char	index_14u_tab[40] = {0,10,1,11,2,12,3,13,4,14,5,15,6,16,7,17,8,18,9,19,20,30,21,31,22,32,23,33,24,34,25,35,26,36,27,37,28,38,29,39};

    m_pBoardCard = new BSBoardCard;
    BSBoardCard *pPreBoardCard = NULL;

    int nOutputNodeNum = 0;
    for (int i = 0; i < 40; i++) {
        BSBoardCard *pBoardCard = new BSBoardCard;
        pBoardCard->pos = i;
        pBoardCard->index = i;
        pBoardCard->pNext = NULL;

        int j = index_14u_tab[i];
        if ((j >= 0) && (j <= 5)) {
            pBoardCard->type = 1;

            BSBoardCardNode *pNode0 = new BSBoardCardNode;
            pNode0->boardCardPos = pBoardCard->pos;
            pNode0->group = 255;
            pNode0->port = 0;
            pNode0->portName = 1;
            pNode0->valid = 1;
            pNode0->xx = 1920;
            pNode0->yy = 1080;
            pNode0->arrayX = 0;
            pNode0->arrayY = 0;
            pNode0->arrayPosX = 0;
            pNode0->arrayPosY = 0;
            pNode0->cardType = 1;
            pNode0->type = 1;

            BSBoardCardNode *pNode2 = new BSBoardCardNode;
            pNode2->boardCardPos = pBoardCard->pos;
            pNode2->group = 255;
            pNode2->port = 2;
            pNode2->portName = 2;
            pNode2->valid = 1;
            pNode2->xx = 1920;
            pNode2->yy = 1080;
            pNode2->arrayX = 0;
            pNode2->arrayY = 0;
            pNode2->arrayPosX = 0;
            pNode2->arrayPosY = 0;
            pNode2->cardType = 1;
            pNode2->type = 1;

            pNode0->pNext = pNode2;

            BSBoardCardNode *pNode4 = new BSBoardCardNode;
            pNode4->boardCardPos = pBoardCard->pos;
            pNode4->group = 255;
            pNode4->port = 4;
            pNode4->portName = 3;
            pNode4->valid = 1;
            pNode4->xx = 1920;
            pNode4->yy = 1080;
            pNode4->arrayX = 0;
            pNode4->arrayY = 0;
            pNode4->arrayPosX = 0;
            pNode4->arrayPosY = 0;
            pNode4->cardType = 1;
            pNode4->type = 1;

            pNode2->pNext = pNode4;

            BSBoardCardNode *pNode6 = new BSBoardCardNode;
            pNode6->boardCardPos = pBoardCard->pos;
            pNode6->group = 255;
            pNode6->port = 6;
            pNode6->portName = 4;
            pNode6->valid = 1;
            pNode6->xx = 1920;
            pNode6->yy = 1080;
            pNode6->arrayX = 0;
            pNode6->arrayY = 0;
            pNode6->arrayPosX = 0;
            pNode6->arrayPosY = 0;
            pNode6->cardType = 1;
            pNode6->type = 1;
            pNode6->pNext = NULL;

            pNode4->pNext = pNode6;
            pBoardCard->pNode = pNode0;
        } else if ((j >= 20) && (j <= 25)) {
            int group0, group2, group4, group6;
            int xx = 1920;
            int yy = 1080;
            int arrayX, arrayY;
            int posx0, posy0, posx2, posy2, posx4, posy4, posx6, posy6;
            if (j == 20) {
                group0 = group2 = group4 = group6 = 0;
                arrayX = 4;
                arrayY = 3;
                posx0 = 0;
                posy0 = 0;
                posx2 = 1;
                posy2 = 0;
                posx4 = 2;
                posy4 = 0;
                posx6 = 3;
                posy6 = 0;
            } else if (j == 21) {
                group0 = group2 = group4 = group6 = 0;
                arrayX = 4;
                arrayY = 3;
                posx0 = 0;
                posy0 = 1;
                posx2 = 1;
                posy2 = 1;
                posx4 = 2;
                posy4 = 1;
                posx6 = 3;
                posy6 = 1;
            } else if (j == 22) {
                group0 = group2 = group4 = group6 = 0;
                arrayX = 4;
                arrayY = 3;
                posx0 = 0;
                posy0 = 2;
                posx2 = 1;
                posy2 = 2;
                posx4 = 2;
                posy4 = 2;
                posx6 = 3;
                posy6 = 2;
            } else if (j == 23) {
                group0 = group2 = group4 = group6 = 1;
                arrayX = 2;
                arrayY = 2;
                posx0 = 0;
                posy0 = 3;
                posx2 = 1;
                posy2 = 3;
                posx4 = 2;
                posy4 = 3;
                posx6 = 3;
                posy6 = 3;
            } else if (j == 24) {
                group0 = group2 = group4 = group6 = 2;
                arrayX = 2;
                arrayY = 2;
                posx0 = 0;
                posy0 = 0;
                posx2 = 1;
                posy2 = 0;
                posx4 = 1;
                posy4 = 0;
                posx6 = 1;
                posy6 = 1;
            } else if (j == 25) {
                group0 = group2 = group4 = group6 = 3;
                arrayX = 1;
                arrayY = 1;
                posx0 = 0;
                posy0 = 0;
                posx2 = 1;
                posy2 = 0;
                posx4 = 1;
                posy4 = 0;
                posx6 = 1;
                posy6 = 1;
            } else {
                group0 = 255;
                group2 = 255;
                group4 = 255;
                group6 = 255;
                arrayX = 0;
                arrayY = 0;
                posx0 = 0;
                posy0 = 0;
                posx2 = 0;
                posy2 = 0;
                posx4 = 0;
                posy4 = 0;
                posx6 = 0;
                posy6 = 0;
            }

            pBoardCard->type = 2;

            BSBoardCardNode *pNode0 = new BSBoardCardNode;
            pNode0->boardCardPos = pBoardCard->pos;
            pNode0->group = group0;
            pNode0->port = 0;
            pNode0->portName = 1;
            pNode0->valid = 1;
            pNode0->xx = xx;
            pNode0->yy = yy;
            pNode0->arrayX = arrayX;
            pNode0->arrayY = arrayY;
            pNode0->arrayPosX = posx0;
            pNode0->arrayPosY = posy0;
            pNode0->cardType = 2;
            pNode0->type = 1;
            nOutputNodeNum++;

            BSBoardCardNode *pNode2 = new BSBoardCardNode;
            pNode2->boardCardPos = pBoardCard->pos;
            pNode2->group = group2;
            pNode2->port = 2;
            pNode2->portName = 2;
            pNode2->valid = 1;
            pNode2->xx = xx;
            pNode2->yy = yy;
            pNode2->arrayX = arrayX;
            pNode2->arrayY = arrayY;
            pNode2->arrayPosX = posx2;
            pNode2->arrayPosY = posy2;
            pNode2->cardType = 2;
            pNode2->type = 1;
            nOutputNodeNum++;

            pNode0->pNext = pNode2;

            BSBoardCardNode *pNode4 = new BSBoardCardNode;
            pNode4->boardCardPos = pBoardCard->pos;
            pNode4->group = group4;
            pNode4->port = 4;
            pNode4->portName = 3;
            pNode4->valid = 1;
            pNode4->xx = xx;
            pNode4->yy = yy;
            pNode4->arrayX = arrayX;
            pNode4->arrayY = arrayY;
            pNode4->arrayPosX = posx4;
            pNode4->arrayPosY = posy4;
            pNode4->cardType = 2;
            pNode4->type = 1;
            nOutputNodeNum++;

            pNode2->pNext = pNode4;

            BSBoardCardNode *pNode6 = new BSBoardCardNode;
            pNode6->boardCardPos = pBoardCard->pos;
            pNode6->group = group6;
            pNode6->port = 6;
            pNode6->portName = 4;
            pNode6->valid = 1;
            pNode6->xx = xx;
            pNode6->yy = yy;
            pNode6->arrayX = arrayX;
            pNode6->arrayY = arrayY;
            pNode6->arrayPosX = posx6;
            pNode6->arrayPosY = posy6;
            pNode6->cardType = 2;
            pNode6->type = 1;
            pNode6->pNext = NULL;
            nOutputNodeNum++;

            pNode4->pNext = pNode6;
            pBoardCard->pNode = pNode0;
        }
        else
        {
            pBoardCard->type = 3;
            pBoardCard->pNode = NULL;
        }
        if (0 == i)
        {
            m_pBoardCard = pBoardCard;
        }

        if (NULL != pPreBoardCard)
        {
            pPreBoardCard->pNext = pBoardCard;
        }
        pPreBoardCard = pBoardCard;
    }


    BCLocalServer *pServer = BCLocalServer::Application();
    if (0 == pServer->m_nIsDemoMode) {
        // 如果是演示模式
    } else {
        if ( pServer->m_bIsNetConnect ) {
            // 不使用DLL通讯
            return; // ??? 展会临时
            m_pTcpSocket = new BCLocalTcpSocket(pServer->m_qsConnectIPWithoutDLL, pServer->m_qsConnectPortWithoutDLL.toInt());
            connect(m_pTcpSocket, SIGNAL(sigBoardCard(int,int)), this, SLOT(onBoardCard(int,int)));
            connect(m_pTcpSocket, SIGNAL(sigDeviceStatus(int,int,int,int,int,int,int,int,int,int,int)), this, SLOT(onDeviceStatus(int,int,int,int,int,int,int,int,int,int,int)));
            connect(m_pTcpSocket, SIGNAL(sigBoardCardStatus(int,int,int,int,int,int,int,int,int,int,int,int,int)), this, SLOT(onBoardCardStatus(int,int,int,int,int,int,int,int,int,int,int,int,int)));

            m_pTcpSocket->RequestConfig( 3 );
        } else {
            // ??? 串口连接，暂时不支持
        }
    }
}

void BCSettingBoardCardDlg::onTimeOut()
{
//    if (NULL == m_pTcpSocket)
//        return;

    // 请求设备状态
    //m_pTcpSocket->RequestConfig( 4 );
    // 请求板卡状态
    //m_pTcpSocket->RequestConfig( 5 );

    // ??? 展会测试
    int randomNum = QDateTime::currentDateTime().toTime_t() % 40;
    int randomNum2 = QDateTime::currentDateTime().offsetFromUtc() % 40;
    int randomArr[40] = {0,10,1,11,2,12,3,13,4,14,5,15,6,16,7,17,8,18,9,19,20,30,21,31,22,32,23,33,24,34,25,35,26,36,27,37,28,38,29,39};
    int baseNum = 2200;
    int fan1 = baseNum + randomArr[randomNum];
    int fan2 = baseNum - randomArr[randomNum];
    int fan3 = baseNum - randomArr[randomNum2];
    int fan4 = baseNum + randomArr[randomNum2];
    int fan5 = baseNum + randomArr[randomNum];
    int fan6 = baseNum - randomArr[randomNum];
    int fan7 = baseNum + randomArr[randomNum2];
    int fan8 = baseNum + randomArr[randomNum];

    onBoardCardStatus(0, 99, 331, 562, 120, 97, 332, 560, 126, 15, 200, 1196, 257);
    onDeviceStatus(0, 99, 331, fan1, fan2, fan3, fan4, fan5, fan6, fan7, fan8);
}

void BCSettingBoardCardDlg::onBoardCard(int timeout, int type)
{
    if (1 == timeout)
        return;

//    BSBoardCard *pBoardCard = m_pTcpSocket->GetBoardCardData();
//    ui->m_pGraphicsView->Init(this, pBoardCard, type);
    ui->m_pGraphicsView->Init(this, m_pBoardCard, type);

    // 关闭连接，只取一次数据
    //disconnect(m_pTcpSocket, SIGNAL(sigBoardCard(int,int)), this, SLOT(onBoardCard(int,int)));
}

void BCSettingBoardCardDlg::onDeviceStatus(int timeout, int nVoltageOfDevice, int nElectricityOfDevice, int nRotationSpeedOfFan1, int nRotationSpeedOfFan2,
                    int nRotationSpeedOfFan3, int nRotationSpeedOfFan4, int nRotationSpeedOfFan5, int nRotationSpeedOfFan6,
                    int nRotationSpeedOfFan7, int nRotationSpeedOfFan8)
{
    if (1 == timeout)
        return;

    ui->m_pVoltageOfDeviceLineEdit->setText( QString::number( nVoltageOfDevice/100.0, 'f', 2 ) );
    ui->m_pElectricityOfDeviceLineEdit->setText( QString::number( nElectricityOfDevice/100.0, 'f', 2 ) );
    ui->m_RotationSpeedOfFan1LineEdit->setText( QString::number(nRotationSpeedOfFan1) );
    ui->m_RotationSpeedOfFan2LineEdit->setText( QString::number(nRotationSpeedOfFan2) );
    ui->m_RotationSpeedOfFan3LineEdit->setText( QString::number(nRotationSpeedOfFan3) );
    ui->m_RotationSpeedOfFan4LineEdit->setText( QString::number(nRotationSpeedOfFan4) );
    ui->m_RotationSpeedOfFan5LineEdit->setText( QString::number(nRotationSpeedOfFan5) );
    ui->m_RotationSpeedOfFan6LineEdit->setText( QString::number(nRotationSpeedOfFan6) );
    ui->m_RotationSpeedOfFan7LineEdit->setText( QString::number(nRotationSpeedOfFan7) );
    ui->m_RotationSpeedOfFan8LineEdit->setText( QString::number(nRotationSpeedOfFan8) );
}

void BCSettingBoardCardDlg::onBoardCardStatus(int timeout, int nCoreVoltageOfChip1, int nRoundVoltageOfChip1, int nCoreElectricityOfChip1, int nRoundElectricityOfChip1,
                       int nCoreVoltageOfChip2, int nRoundVoltageOfChip2, int nCoreElectricityOfChip2, int nRoundElectricityOfChip2,
                       int nVoltageOfMemorizer, int nElectricityOfMemorizer, int nVoltageOfInput, int nElectricityOfInput)
{
    if (1 == timeout)
        return;

    ui->m_pCoreVoltageOfChip1LineEdit->setText( QString::number(nCoreVoltageOfChip1/100.0, 'f', 2) );
    ui->m_pRoundVoltageOfChip1LineEdit->setText( QString::number(nRoundVoltageOfChip1/100.0, 'f', 2) );
    ui->m_pCoreElectricityOfChip1LineEdit->setText( QString::number(nCoreElectricityOfChip1/100.0, 'f', 2) );
    ui->m_pRoundElectricityOfChip1LineEdit->setText( QString::number(nRoundElectricityOfChip1/100.0, 'f', 2) );

    ui->m_pCoreVoltageOfChip2LineEdit->setText( QString::number(nCoreVoltageOfChip2/100.0, 'f', 2) );
    ui->m_pRoundVoltageOfChip2LineEdit->setText( QString::number(nRoundVoltageOfChip2/100.0, 'f', 2) );
    ui->m_pCoreElectricityOfChip2LineEdit->setText( QString::number(nCoreElectricityOfChip2/100.0, 'f', 2) );
    ui->m_pRoundElectricityOfChip2LineEdit->setText( QString::number(nRoundElectricityOfChip2/100.0, 'f', 2) );

    ui->m_pVoltageOfMemorizerLineEdit->setText( QString::number(nVoltageOfMemorizer/100.0, 'f', 2) );
    ui->m_pElectricityOfMemorizerLineEdit->setText( QString::number(nElectricityOfMemorizer/100.0, 'f', 2) );
    ui->m_pVoltageOfInputLineEdit->setText( QString::number(nVoltageOfInput/100.0, 'f', 2) );
    ui->m_pElectricityOfInputLineEdit->setText( QString::number(nElectricityOfInput/100.0, 'f', 2) );
}

void BCSettingBoardCardDlg::RefreshNodeInfo(BCSettingBoardCardNodeItem *pNodeItem)
{
    m_pNodeItem = pNodeItem;

    // 没点中节点
    if (NULL == pNodeItem) {
        ui->m_pGroupLabel->setVisible( false );
        ui->m_pGroupLineEdit->setVisible( false );
        ui->m_pTypeLabel->setVisible( false );
        ui->m_pTypeLineEdit->setVisible( false );
        ui->m_pCardTypeLabel->setVisible( false );
        ui->m_pCardTypeLineEdit->setVisible( false );
        ui->m_pPortNameLabel->setVisible( false );
        ui->m_pPortNameLineEdit->setVisible( false );
        ui->m_pPortLabel->setVisible( false );
        ui->m_pPortLineEdit->setVisible( false );
        ui->m_pXXLabel->setVisible( false );
        ui->m_pXXLineEdit->setVisible( false );
        ui->m_pYYLabel->setVisible( false );
        ui->m_pYYLineEdit->setVisible( false );
        ui->m_pArrayXLabel->setVisible( false );
        ui->m_pArrayXLineEdit->setVisible( false );
        ui->m_pArrayYLabel->setVisible( false );
        ui->m_pArrayYLineEdit->setVisible( false );
        ui->m_pArrayPosXLabel->setVisible( false );
        ui->m_pArrayPosXLineEdit->setVisible( false );
        ui->m_pArrayPosYLabel->setVisible( false );
        ui->m_pArrayPosYLineEdit->setVisible( false );
        ui->m_pWarningLabel->setVisible( false );
        ui->m_pApplyBtn->setVisible( false );
    } else {
        ui->m_pGroupLabel->setVisible( false );
        ui->m_pGroupLineEdit->setVisible( false );
        ui->m_pTypeLabel->setVisible( true );
        ui->m_pTypeLineEdit->setVisible( true );
        ui->m_pCardTypeLabel->setVisible( true );
        ui->m_pCardTypeLineEdit->setVisible( true );
        ui->m_pPortNameLabel->setVisible( true );
        ui->m_pPortNameLineEdit->setVisible( true );
        ui->m_pPortLabel->setVisible( true );
        ui->m_pPortLineEdit->setVisible( true );
        ui->m_pXXLabel->setVisible( true );
        ui->m_pXXLineEdit->setVisible( true );
        ui->m_pYYLabel->setVisible( true );
        ui->m_pYYLineEdit->setVisible( true );
        ui->m_pArrayXLabel->setVisible((1 == m_pNodeItem->m_pBoardCardNode->cardType) ? false :true);
        ui->m_pArrayXLineEdit->setVisible((1 == m_pNodeItem->m_pBoardCardNode->cardType) ? false :true);
        ui->m_pArrayYLabel->setVisible((1 == m_pNodeItem->m_pBoardCardNode->cardType) ? false :true);
        ui->m_pArrayYLineEdit->setVisible((1 == m_pNodeItem->m_pBoardCardNode->cardType) ? false :true);
        ui->m_pArrayPosXLabel->setVisible((1 == m_pNodeItem->m_pBoardCardNode->cardType) ? false :true);
        ui->m_pArrayPosXLineEdit->setVisible((1 == m_pNodeItem->m_pBoardCardNode->cardType) ? false :true);
        ui->m_pArrayPosYLabel->setVisible((1 == m_pNodeItem->m_pBoardCardNode->cardType) ? false :true);
        ui->m_pArrayPosYLineEdit->setVisible((1 == m_pNodeItem->m_pBoardCardNode->cardType) ? false :true);
        ui->m_pWarningLabel->setVisible( false );
        ui->m_pApplyBtn->setVisible( true );

        // 可能被组信息设置成不可用
        ui->m_pGroupLineEdit->setEnabled( true );
        ui->m_pXXLineEdit->setEnabled( true );
        ui->m_pYYLineEdit->setEnabled( true );
        ui->m_pArrayXLineEdit->setEnabled( true );
        ui->m_pArrayYLineEdit->setEnabled( true );
        ui->m_pApplyBtn->setEnabled( true );

        ui->m_pTypeLineEdit->setText( (1 == m_pNodeItem->m_pBoardCardNode->type) ? QString("P_DVI") : QString("p_HDBT") );
        ui->m_pCardTypeLineEdit->setText( (1 == m_pNodeItem->m_pBoardCardNode->cardType) ? QString("B_Input") : QString("B_Output") );
        ui->m_pPortNameLineEdit->setText( QString::number(m_pNodeItem->m_pBoardCardNode->portName) );
        ui->m_pPortLineEdit->setText( QString::number(m_pNodeItem->m_pBoardCardNode->port) );
        ui->m_pXXLineEdit->setText( QString::number(m_pNodeItem->m_pBoardCardNode->xx) );
        ui->m_pYYLineEdit->setText( QString::number(m_pNodeItem->m_pBoardCardNode->yy) );
        ui->m_pArrayXLineEdit->setText( QString::number(m_pNodeItem->m_pBoardCardNode->arrayX) );
        ui->m_pArrayYLineEdit->setText( QString::number(m_pNodeItem->m_pBoardCardNode->arrayY) );
        ui->m_pArrayPosXLineEdit->setText( QString::number(m_pNodeItem->m_pBoardCardNode->arrayPosX) );
        ui->m_pArrayPosYLineEdit->setText( QString::number(m_pNodeItem->m_pBoardCardNode->arrayPosY) );
    }
}

void BCSettingBoardCardDlg::RefreshBoardCardPos(int pos)
{
    m_nBoardPos = pos;

    ui->m_pBoardCardGB->setTitle( tr("板卡信息%1").arg(pos) );
}

void BCSettingBoardCardDlg::RefreshNodeInfo(QList<BCSettingBoardCardNodeItem *> lstHighLightItem)
{
    ui->m_pGroupLabel->setVisible( true );
    ui->m_pGroupLineEdit->setVisible( true );
    ui->m_pTypeLabel->setVisible( false );
    ui->m_pTypeLineEdit->setVisible( false );
    ui->m_pCardTypeLabel->setVisible( false );
    ui->m_pCardTypeLineEdit->setVisible( false );
    ui->m_pPortNameLabel->setVisible( false );
    ui->m_pPortNameLineEdit->setVisible( false );
    ui->m_pPortLabel->setVisible( false );
    ui->m_pPortLineEdit->setVisible( false );
    ui->m_pXXLabel->setVisible( true );
    ui->m_pXXLineEdit->setVisible( true );
    ui->m_pYYLabel->setVisible( true );
    ui->m_pYYLineEdit->setVisible( true );
    ui->m_pArrayXLabel->setVisible( true );
    ui->m_pArrayXLineEdit->setVisible( true );
    ui->m_pArrayYLabel->setVisible( true );
    ui->m_pArrayYLineEdit->setVisible( true );
    ui->m_pArrayPosXLabel->setVisible( false );
    ui->m_pArrayPosXLineEdit->setVisible( false );
    ui->m_pArrayPosYLabel->setVisible( false );
    ui->m_pArrayPosYLineEdit->setVisible( false );
    ui->m_pApplyBtn->setVisible( true );

    // 判断是否是成对存在
    bool bDouble = false;
    QList<BCSettingBoardCardNodeItem *> lstItem = lstHighLightItem;
    while ( !lstItem.isEmpty() ) {
        BCSettingBoardCardNodeItem *pCurrentItem = lstItem.first();

        // 如果不是输出板卡则直接跳出
        if (2 != pCurrentItem->m_pBoardCardNode->cardType)
            break;

        // 查找是否有配对的item
        for (int i = 0; i < lstItem.count(); i++) {
            if ( bDouble )
                break;

            // 同一块板卡的相邻位置算一对
            BCSettingBoardCardNodeItem *pDoubleItem = lstItem.at(i);
            switch ( pCurrentItem->m_pBoardCardNode->port ) {
            case 0:
                if ((pCurrentItem->m_pBoardCardNode->boardCardPos == pDoubleItem->m_pBoardCardNode->boardCardPos) && (pDoubleItem->m_pBoardCardNode->port == 2)) {
                    bDouble = true;
                }
                break;
            case 2:
                if ((pCurrentItem->m_pBoardCardNode->boardCardPos == pDoubleItem->m_pBoardCardNode->boardCardPos) && (pDoubleItem->m_pBoardCardNode->port == 0)) {
                    bDouble = true;
                }
                break;
            case 4:
                if ((pCurrentItem->m_pBoardCardNode->boardCardPos == pDoubleItem->m_pBoardCardNode->boardCardPos) && (pDoubleItem->m_pBoardCardNode->port == 6)) {
                    bDouble = true;
                }
                break;
            case 6:
                if ((pCurrentItem->m_pBoardCardNode->boardCardPos == pDoubleItem->m_pBoardCardNode->boardCardPos) && (pDoubleItem->m_pBoardCardNode->port == 4)) {
                    bDouble = true;
                }
                break;
            default:
                break;
            }

            if ( bDouble )
                lstItem.removeOne( pDoubleItem );
        }

        // 没找到配对直接跳出
        if ( !bDouble )
            break;

        lstItem.removeOne( pCurrentItem );

        // 如果就剩1个，肯定不符合配对，跳出
        if (1 == lstItem.count()) {
            bDouble = false;
            break;
        }

        // 如果为空则全部配对成功，跳出
        if ( lstItem.isEmpty() ) {
            bDouble = true;
            break;
        }

        // 下次循环初始值
        bDouble = false;
    }

    // 根据配对情况设置分组信息是否可用
    ui->m_pWarningLabel->setVisible( !bDouble );
    ui->m_pGroupLineEdit->setEnabled( bDouble );
    ui->m_pXXLineEdit->setEnabled( bDouble );
    ui->m_pYYLineEdit->setEnabled( bDouble );
    ui->m_pArrayXLineEdit->setEnabled( bDouble );
    ui->m_pArrayYLineEdit->setEnabled( bDouble );
    ui->m_pApplyBtn->setEnabled( bDouble );

    // 对是否配对的处理
    if ( !bDouble ) {
        ui->m_pGroupLineEdit->setText( QString::null );
        ui->m_pXXLineEdit->setText( QString::null );
        ui->m_pYYLineEdit->setText( QString::null );
        ui->m_pArrayXLineEdit->setText( QString::null );
        ui->m_pArrayYLineEdit->setText( QString::null );
    } else {
        // bool 标识是否为空，当有一个值不相等时为空
        bool bGroup = false;
        bool bXX = false;
        bool bYY = false;
        bool bArrayX = false;
        bool bArrayY = false;
        QString qsGroup, qsXX, qsYY, qsArrayX, qsArrayY;
        for (int i = 0; i < lstHighLightItem.count(); i++) {
            BCSettingBoardCardNodeItem *pItem = lstHighLightItem.at(i);

            if ( qsGroup.isEmpty() )
                qsGroup = QString::number(pItem->m_pBoardCardNode->group);
            else if (qsGroup != QString::number(pItem->m_pBoardCardNode->group))
                bGroup = true;

            if ( qsXX.isEmpty() )
                qsXX = QString::number(pItem->m_pBoardCardNode->xx);
            else if (qsXX != QString::number(pItem->m_pBoardCardNode->xx))
                bXX = true;

            if ( qsYY.isEmpty() )
                qsYY = QString::number(pItem->m_pBoardCardNode->yy);
            else if (qsYY != QString::number(pItem->m_pBoardCardNode->yy))
                bYY = true;

            if ( qsArrayX.isEmpty() )
                qsArrayX = QString::number(pItem->m_pBoardCardNode->arrayX);
            else if (qsArrayX != QString::number(pItem->m_pBoardCardNode->arrayX))
                bArrayX = true;

            if ( qsArrayY.isEmpty() )
                qsArrayY = QString::number(pItem->m_pBoardCardNode->arrayY);
            else if (qsArrayY != QString::number(pItem->m_pBoardCardNode->arrayY))
                bArrayY = true;
        }

        ui->m_pGroupLineEdit->setText(bGroup ? "" : qsGroup);
        ui->m_pXXLineEdit->setText(bXX ? "" : qsXX);
        ui->m_pYYLineEdit->setText(bYY ? "" : qsYY);
        ui->m_pArrayXLineEdit->setText(bArrayX ? "" : qsArrayX);
        ui->m_pArrayYLineEdit->setText(bArrayY ? "" : qsArrayY);
    }
}
