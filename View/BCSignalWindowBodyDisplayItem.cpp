#include "BCSignalWindowBodyDisplayItem.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "BCTextDisplayItem.h"
#include "BCSignalWindowDisplayItem.h"
#include "BCSignalWindowBodySubDisplayItem.h"
#include "../Player/BCVedioManager.h"
#include "../Model/BCMChannel.h"
#include "../Common/BCLocalServer.h"
#include "../Common/BCCommunication.h"

BCSignalWindowBodyDisplayItem::BCSignalWindowBodyDisplayItem(double x, double y, double w, double h, QGraphicsItem * parent, int r)
    :BCDisplayItem(BCCommon::SIGNALWINDOW, x, y, w, h, parent, r)
{
    // 单个显示器时绘制文字
    this->setZValue(11);

    /* 构造回显数据，包含3部分内容
     * 1.新建label，为了得到句柄并调用DLL接口使用SDL渲染，不显示
     * 2.新建pixmapItem，是真正的显示图片对象，大小同label一起变化
     * 3.新建定时器，在打开回显时开启，关闭回显时关闭，根据label的句柄定时从DLL中取得帧数据
     */
    MainWindow *pMainWindow = BCCommon::Application();
    m_pEchoLabel = new QLabel( pMainWindow );
    m_pEchoLabel->resize(1, 1);
    m_pEchoLabel->hide();

    m_pEchoPixmapItem = new QGraphicsPixmapItem(this);

    m_nFrameA = 120;
//    m_pEchoTimer = new QTimer();
//    m_pEchoTimer->setInterval(20);  // 设置timeout时间
//    QObject::connect(m_pEchoTimer, SIGNAL(timeout()), this, SLOT(onGetEchoFrame()));

    // 构造两个文字对象
    m_pDefaultTextItem = new BCTextDisplayItem("", this);
    m_pTextItem = new BCTextDisplayItem("", this);
    //m_pDisplayItem = new BCTextDisplayItem("", this);

    // 初始化文字设置
    RefreshDisplayTextColor();
    RefreshDisplayTextFont();
    RefreshDisplayTextPos();
    RefreshIsShowDisplayText();

    // 刷新IPV的矩形块
    m_nIPVSegmentation = 1;
    RefreshIPVDisplayItem( m_nIPVSegmentation );
}

BCSignalWindowBodyDisplayItem::~BCSignalWindowBodyDisplayItem()
{
    // 清除回显数据
//    m_pEchoTimer->stop();
//    delete m_pEchoTimer;
//    m_pEchoTimer = NULL;

    delete m_pEchoPixmapItem;
    m_pEchoPixmapItem = NULL;

    delete m_pEchoLabel;
    m_pEchoLabel = NULL;

    // 删除内部对象
    QList<QGraphicsItem *> lst = childItems();
    while ( !lst.isEmpty() )
        delete lst.takeFirst();
}

void BCSignalWindowBodyDisplayItem::SetEcho(bool b)
{
    if ( !BCCommon::g_bEchoModel )
        return;

    // 查找channelid
    BCSignalWindowDisplayItem *pSignalWindow = dynamic_cast<BCSignalWindowDisplayItem *>( this->parentItem() );
    BCMChannel *pChannel = pSignalWindow->GetInputChannel();
    if (NULL == pChannel)
        return;

    //BCVedioManager *pVideoMgr = BCVedioManager::Application();
    if ( b ) {
        qDebug() << (HWND)m_pEchoLabel->winId() << pChannel->GetChannelID();
        //pVideoMgr->AddEcho((HWND)m_pEchoLabel->winId(), pChannel->GetChannelID(), 0, 0, 0, m_EchoSize.width(), m_EchoSize.height());
        //pVideoMgr->AddEcho( this );

        //m_pEchoTimer->start();
    } else {
        //m_pEchoTimer->stop();

        //pVideoMgr->RemoveEcho( (HWND)m_pEchoLabel->winId() );
        //pVideoMgr->RemoveEcho( this );

        // 关闭回显之后将图片置空
        m_pEchoPixmapItem->setPixmap(QPixmap());
    }
}

void BCSignalWindowBodyDisplayItem::ResetEchoA()
{
    m_nFrameA = 120;
}

HWND BCSignalWindowBodyDisplayItem::GetEchoHandle()
{
    return (HWND)m_pEchoLabel->winId();
}

int BCSignalWindowBodyDisplayItem::GetChannelID()
{
    BCSignalWindowDisplayItem *pSignalWindow = dynamic_cast<BCSignalWindowDisplayItem *>( this->parentItem() );
    BCMChannel *pChannel = pSignalWindow->GetInputChannel();
    if (NULL == pChannel)
        return 0;

    return pChannel->GetChannelID();
}

QSize BCSignalWindowBodyDisplayItem::GetEchoSize()
{
    return m_EchoSize;
}

void BCSignalWindowBodyDisplayItem::SetEchoPixmap(const QPixmap &pixmap)
{
    if ( !pixmap.isNull() )
        m_pEchoPixmapItem->setPixmap( pixmap );
}

int BCSignalWindowBodyDisplayItem::GetEchoA()
{
    // 透明度渐变
    if (m_nFrameA < 255) {
        // 点中时图像一直是半透明的
        BCSignalWindowDisplayItem *pSignalWindow = dynamic_cast<BCSignalWindowDisplayItem *>( this->parentItem() );
        if ( !pSignalWindow->m_bPress )
            m_nFrameA = m_nFrameA+20;
    }

    // 最大不能超过255
    m_nFrameA = (m_nFrameA > 255) ? 255 : m_nFrameA;

    return m_nFrameA;
}

void BCSignalWindowBodyDisplayItem::onGetEchoFrame()
{
//    // 透明度渐变
//    if (m_nFrameA < 255)
//        m_nFrameA = m_nFrameA+4;

//    // 最大不能超过255
//    m_nFrameA = (m_nFrameA > 255) ? 255 : m_nFrameA;

//    // 回显管理类
//    BCVedioManager *pVideoMgr = BCVedioManager::Application();

//    QPixmap pixmap = pVideoMgr->GetEchoFrame((HWND)m_pEchoLabel->winId(), m_EchoSize.width(), m_EchoSize.height(), m_nFrameA);
//    if ( !pixmap.isNull() )
//        m_pEchoPixmapItem->setPixmap( pixmap );
}

void BCSignalWindowBodyDisplayItem::ResizeRect(double x, double y, double w, double h)
{
    // 改变自身矩形大小
    double dSrcWidth = rect().width();
    double dSrcHeight = rect().height();
    setRect(x, y, w, h);
    m_EchoSize.setWidth( w );
    m_EchoSize.setHeight( h );

    BCSignalWindowDisplayItem *pSignalWindowDisplayItem = dynamic_cast<BCSignalWindowDisplayItem*>( this->parentItem() );
    if (NULL == pSignalWindowDisplayItem)
        return;

    m_rectPaint = rect();
    if ( 0 ) {
        // 获得父类绘制区域，并计算本身绘制区域
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

    // 重绘内部图形
    BCSignalWindowBodySubDisplayItem *pRectItem = NULL;
    QList<QGraphicsItem*> lstItems = this->childItems();
    QListIterator<QGraphicsItem*> it( lstItems );
    while ( it.hasNext() ) {
        pRectItem = dynamic_cast<BCSignalWindowBodySubDisplayItem *>( it.next() );
        if (NULL == pRectItem)
            continue;

        double dX = x + (pRectItem->GetRectItemRelativePos().x() * 0.01 * w);
        double dY = y + (pRectItem->GetRectItemRelativePos().y() * 0.01 * h);
        double dW = pRectItem->GetRectItemRelativePos().width() * 0.01 * w;
        double dH = pRectItem->GetRectItemRelativePos().height() * 0.01 * h;

        pRectItem->setRect(dX, dY, dW, dH);
    }

    // set text pos
    RefreshDisplayTextPos();

    // 刷新回显数据
    m_pEchoPixmapItem->setPos(x, y);
    if ( pSignalWindowDisplayItem->IsEcho() ) {
        // 如果宽和高没有编号则不刷新回显尺寸
        if ((qAbs(dSrcWidth - w) > BCCommon::g_dPermissionError) ||
                (qAbs(dSrcHeight - h) > BCCommon::g_dPermissionError)) {
            //BCVedioManager *pVideoMgr = BCVedioManager::Application();
            //pVideoMgr->UpdateEcho((HWND)m_pEchoLabel->winId(), 0, 0, m_EchoSize.width(), m_EchoSize.height());
            //pVideoMgr->UpdateEcho( this );
        }
    }

    //this->update();
}

void BCSignalWindowBodyDisplayItem::SendIPVedioListCmd()
{
    BCSignalWindowDisplayItem *pSignalWindowDisplayItem = dynamic_cast<BCSignalWindowDisplayItem*>( this->parentItem() );
    if (NULL == pSignalWindowDisplayItem)
        return;

    // 找到输入通道的数据类
    BCMChannel *pChannel = pSignalWindowDisplayItem->GetInputChannel();
    if (NULL == pChannel)
        return;

    if (m_lstSubDisplayItem.count() != 16)
        return;

//    int winid = pSignalWindowDisplayItem->GetWindowID();
//    int chid = pChannel->GetChannelID();

    char ip[16][255];
    for (int i = 0; i < m_lstSubDisplayItem.count(); i++) {
        BCSignalWindowBodySubDisplayItem *pItem = m_lstSubDisplayItem.at(i);

        strcpy(ip[i], BCCommon::getTextStr( pItem->m_qsUrl ));
    }
}

void BCSignalWindowBodyDisplayItem::SetIPVIP(const QStringList &lstIP)
{
    if (16 != lstIP.count())
        return;

    if (16 != m_lstSubDisplayItem.count())
        RefreshIPVDisplayItem( m_nIPVSegmentation );

    for (int i = 0; i < 16; i++) {
        BCSignalWindowBodySubDisplayItem *pItem = m_lstSubDisplayItem.at( i );
        pItem->m_qsUrl = lstIP.at(i);
        pItem->setToolTip( pItem->m_qsUrl );
        pItem->update();
    }
}

void BCSignalWindowBodyDisplayItem::RefreshIPVDisplayItem(int n)
{
    BCSignalWindowDisplayItem *pSignalWindowDisplayItem = dynamic_cast<BCSignalWindowDisplayItem*>( this->parentItem() );
    if (NULL == pSignalWindowDisplayItem)
        return;

    // 找到输入通道的数据类
    BCMChannel *pChannel = pSignalWindowDisplayItem->GetInputChannel();
    if (NULL == pChannel)
        return;

    // 只有IPV才进行设置
    if (9 != pChannel->GetSignalSource())
        return;

    // 如果链表为空则新建数据并填充链表，链表默认16个，如果已经添加则修改其矩形
    if ( m_lstSubDisplayItem.isEmpty() ) {
        for (int i = 0; i < 16; i++) {
            m_lstSubDisplayItem.append( new BCSignalWindowBodySubDisplayItem(0, 0, 0, 0, i, this) );
        }
    } else {
        for (int i = 0; i < m_lstSubDisplayItem.count(); i++) {
            BCSignalWindowBodySubDisplayItem *pItem = m_lstSubDisplayItem.at(i);
            pItem->SetRectItemRelativePos( QRectF(0, 0, 0, 0) );
            pItem->setRect(0,0,0,0);
        }
    }

    // 根据分割数获得宽和高，分割数:1,4,6,9,12,16
    int nWidth = 1;
    int nHeight = 1;
    m_nIPVSegmentation = n; //pChannel->GetIPVSegmentation();
    switch ( m_nIPVSegmentation ) {
    case 1:
        nWidth = 1;
        nHeight = 1;
        break;
    case 4:
        nWidth = 2;
        nHeight = 2;
        break;
    case 6:
        nWidth = 3;
        nHeight = 2;
        break;
    case 9:
        nWidth = 3;
        nHeight = 3;
        break;
    case 12:
        nWidth = 4;
        nHeight = 3;
        break;
    case 16:
        nWidth = 4;
        nHeight = 4;
        break;
    default:
        break;
    }

    // 根据分割数重置矩形的尺寸
    double dSingleWidth = 100.0 / nWidth;
    double dSingleHeight = 100.0 / nHeight;
    for (int j = 0; j < nHeight; j++) {
        for (int i = 0; i < nWidth; i++) {
            BCSignalWindowBodySubDisplayItem *pIPVedioItem = m_lstSubDisplayItem.at(j*nWidth + i);
            pIPVedioItem->SetRectItemRelativePos( QRectF(dSingleWidth*i,
                                                         dSingleHeight*j,
                                                         dSingleWidth,
                                                         dSingleHeight) );

            double dX = rect().x() + (dSingleWidth*i * 0.01 * rect().width());
            double dY = rect().y() + (dSingleHeight*j * 0.01 * rect().height());
            double dW = dSingleWidth * 0.01 * rect().width();
            double dH = dSingleHeight * 0.01 * rect().height();

            pIPVedioItem->setRect(dX, dY, dW, dH);
        }
    }

    // 发送指令
    if ( BCCommon::g_bConnectWithServer ) {
        BCCommunication *pCommunication = BCCommunication::Application();
        pCommunication->SetIPVedioSegmentation(pChannel->GetChannelID(), (1==m_nIPVSegmentation) ? 1 : 2, pChannel->GetBoardCardID(), pChannel->GetBoardCardPos());
    } else {
        BCLocalServer *pServer = BCLocalServer::Application();
        pServer->SetIPVedioSegmentation(pChannel->GetChannelID(), (1==m_nIPVSegmentation) ? 1 : 2, pChannel->GetBoardCardID(), pChannel->GetBoardCardPos());
    }
}

void BCSignalWindowBodyDisplayItem::SetDisplayText(const QString &qsText)
{
    if (NULL == m_pTextItem)
        return;

    m_pTextItem->SetText( qsText );

    this->update();
}

void BCSignalWindowBodyDisplayItem::SetDisplayDefaultText(const QString &/*qsText*/)
{
//    if (NULL == m_pDefaultTextItem)
//        return;

//    m_pDefaultTextItem->SetText( qsText );
}

void BCSignalWindowBodyDisplayItem::SetDisplayIDText(const QString &/*qsText*/)
{
//    if (NULL == m_pDisplayItem)
//        return;

//    m_pDisplayItem->SetText( qsText );
}

void BCSignalWindowBodyDisplayItem::RefreshDisplayTextColor()
{
    if ((NULL == m_pTextItem) || (NULL == m_pDefaultTextItem))
        return;

    m_pTextItem->SetFontColor( BCCommon::g_nSignalWindowBodyTextColorR,
                               BCCommon::g_nSignalWindowBodyTextColorG,
                               BCCommon::g_nSignalWindowBodyTextColorB,
                               BCCommon::g_nSignalWindowBodyTextColorA);

    m_pDefaultTextItem->SetFontColor(  BCCommon::g_nSignalWindowBodyTextColorR,
                                       BCCommon::g_nSignalWindowBodyTextColorG,
                                       BCCommon::g_nSignalWindowBodyTextColorB,
                                       BCCommon::g_nSignalWindowBodyTextColorA);

//    m_pDisplayItem->SetFontColor(  BCCommon::g_nSignalWindowBodyTextColorR,
//                                       BCCommon::g_nSignalWindowBodyTextColorG,
//                                       BCCommon::g_nSignalWindowBodyTextColorB,
//                                       BCCommon::g_nSignalWindowBodyTextColorA);
}

void BCSignalWindowBodyDisplayItem::RefreshDisplayTextFont()
{
    if ((NULL == m_pTextItem) || (NULL == m_pDefaultTextItem))
        return;

    m_pTextItem->SetFontFamily( BCCommon::g_sSignalWindowBodyTextFamilyName );
    m_pTextItem->SetFontSize( BCCommon::g_nSignalWindowBodyTextSize );

    m_pDefaultTextItem->SetFontFamily( BCCommon::g_sSignalWindowBodyTextFamilyName );
    m_pDefaultTextItem->SetFontSize( BCCommon::g_nSignalWindowBodyTextSize );

//    m_pDisplayItem->SetFontFamily( BCCommon::g_sSignalWindowBodyTextFamilyName );
//    m_pDisplayItem->SetFontSize( BCCommon::g_nSignalWindowBodyTextSize );
}

void BCSignalWindowBodyDisplayItem::RefreshDisplayTextPos()
{
    SetDisplayTextPos( false );
    //SetDisplayTextPos( true );
}

void BCSignalWindowBodyDisplayItem::RefreshIsShowDisplayText()
{
    if ((NULL == m_pTextItem) || (NULL == m_pDefaultTextItem))
        return;

    ( BCCommon::g_bShowSignalWindowBodyText ) ? m_pTextItem->show() : m_pTextItem->hide();
    ( BCCommon::g_bShowSignalWindowBodyDefaultText ) ? m_pDefaultTextItem->show() : m_pDefaultTextItem->hide();
}

void BCSignalWindowBodyDisplayItem::SetDisplayTextPos(bool bDefaultText)
{
    if ((NULL == m_pTextItem) || (NULL == m_pDefaultTextItem))
        return;

    // 缩放比例
    QTransform trans = dynamic_cast<QGraphicsView *>(this->scene()->parent())->transform();
    double dScale = trans.m11();

    BCTextDisplayItem *pTextItem = bDefaultText ? m_pDefaultTextItem : m_pTextItem;
    BCCommon::SINGLEDISPLAYTEXTPOS ePos = bDefaultText ? BCCommon::g_eSignalWindowBodyDefaultTextPos : BCCommon::g_eSignalWindowBodyTextPos;
    int nOffsetX = bDefaultText ? BCCommon::g_nSignalWindowBodyDefaultTextPosOffsetX/dScale : BCCommon::g_nSignalWindowBodyTextPosOffsetX/dScale;
    int nOffsetY = bDefaultText ? BCCommon::g_nSignalWindowBodyDefaultTextPosOffsetY/dScale : BCCommon::g_nSignalWindowBodyTextPosOffsetY/dScale;
    QSizeF rectBoundingSize = QSizeF(pTextItem->GetBoundingRect().width()/dScale, pTextItem->GetBoundingRect().height()/dScale);

    // 根据位置更新文字位置
    switch ( ePos ) {
    case BCCommon::LEFTTOP: {
        pTextItem->setPos(rect().left()+nOffsetX,
                            rect().top()+nOffsetY);
        }
        break;
    case BCCommon::LEFT: {
        int nTextY = rect().center().y() - (rectBoundingSize.height()/2);
        pTextItem->setPos(rect().left()+nOffsetX,
                            nTextY+nOffsetY);
        }
        break;
    case BCCommon::LEFTBOTTOM: {
        int nTextY = rect().bottom() - rectBoundingSize.height();
        pTextItem->setPos(rect().left()+nOffsetX,
                            nTextY+nOffsetY);
        }
        break;
    case BCCommon::TOP: {
        int nTextX = rect().center().x() - (rectBoundingSize.width()/2);
        pTextItem->setPos(nTextX+nOffsetX,
                            rect().top()+nOffsetY);
        }
        break;
    case BCCommon::CENTER: {
        int nTextX = rect().center().x() - (rectBoundingSize.width()/2);
        int nTextY = rect().center().y() - (rectBoundingSize.height()/2);

        pTextItem->setPos(nTextX+nOffsetX,
                            nTextY+nOffsetY);
        }
        break;
    case BCCommon::BOTTOM: {
        int nTextX = rect().center().x() - (rectBoundingSize.width()/2);
        pTextItem->setPos(nTextX+nOffsetX,
                            rect().bottom()+nOffsetY);
        }
        break;
    case BCCommon::RIGHTTOP: {
        int nTextX = rect().right() - rectBoundingSize.width();

        pTextItem->setPos(nTextX+nOffsetX,
                            rect().top()+nOffsetY);
        }
        break;
    case BCCommon::RIGHT: {
        int nTextX = rect().right() - rectBoundingSize.width();
        int nTextY = rect().center().y() - (rectBoundingSize.height()/2);

        pTextItem->setPos(nTextX+nOffsetX,
                            nTextY+nOffsetY);
        }
        break;
    case BCCommon::RIGHTBOTTOM: {
        int nTextX = rect().right() - rectBoundingSize.width();
        int nTextY = rect().bottom() - rectBoundingSize.height();

        pTextItem->setPos(nTextX+nOffsetX,
                            nTextY+nOffsetY);
        }
        break;
    }

    // ??? 单屏ID固定显示在左下角，暂时放这里
//    int nTextY = rect().bottom() - rectBoundingSize.height();
//    m_pDisplayItem->setPos(rect().left()+nOffsetX,
//                        nTextY+nOffsetY);

    //pTextItem->update();
}

void BCSignalWindowBodyDisplayItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget*/)
{
    // 缩放比例
    QTransform trans = painter->worldTransform();
    double dScale = trans.m11();

    // 设置边线，红色，宽度2，实线
    painter->setPen(QPen(QBrush(QColor(BCCommon::g_nSignalWindowBodyLineColorR,
                                       BCCommon::g_nSignalWindowBodyLineColorG,
                                       BCCommon::g_nSignalWindowBodyLineColorB,
                                       BCCommon::g_nSignalWindowBodyLineColorA)),
                         BCCommon::g_nSignalWindowBodyLineWidth/dScale,
                         Qt::PenStyle(BCCommon::g_nSignalWindowBodyLineStyle)));

    // 设置颜色填充
    painter->setBrush(QBrush(QColor(BCCommon::g_nSignalWindowBodyFillColorR,
                                    BCCommon::g_nSignalWindowBodyFillColorG,
                                    BCCommon::g_nSignalWindowBodyFillColorB,
                                    BCCommon::g_nSignalWindowBodyFillColorA)));

    painter->drawRect( m_rectPaint );

    // 刷新文字
    RefreshDisplayTextPos();
}
