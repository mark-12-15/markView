#include "BCGroupDisplayWidget.h"
#include "../Common/BCCommon.h"
#include "../Model/BCMGroupDisplay.h"
#include "../Model/BCMDisplay.h"
#include "BCSingleDisplayWidget.h"
#include "BCRoomWidget.h"

BCGroupDisplayWidget::BCGroupDisplayWidget(BCMGroupDisplay *pMGroupDisplay, BCRoomMainWidget *parent) : QWidget(parent)
{
    m_parent = parent;
    m_pMGroupDisplay = pMGroupDisplay;
    m_pMGroupDisplay->SetDisplayWidgetManager( this );
    //m_imageSrc = QImage(":image/backgroup/background.png");

    // init singledisplay
    QList<BCMDisplay *> lstDisplay = m_pMGroupDisplay->GetDisplays();
    for (int i = 0; i < lstDisplay.count(); i++) {
        BCMDisplay *pMDisplay = lstDisplay.at( i );

        BCSingleDisplayWidget *pDisplayWidget = new BCSingleDisplayWidget(pMDisplay, this);

        m_lstSingleDisplay.append( pDisplayWidget );
    }
}

BCGroupDisplayWidget::~BCGroupDisplayWidget()
{
    while ( !m_lstSingleDisplay.isEmpty() )
        delete m_lstSingleDisplay.takeFirst();
}

void BCGroupDisplayWidget::RefreshSegmentation(int n)
{
    QListIterator<BCSingleDisplayWidget *> it( m_lstSingleDisplay );
    while ( it.hasNext() ) {
        BCSingleDisplayWidget *pWidget = it.next();
        pWidget->RefreshSegmentation( n );
    }
}

int BCGroupDisplayWidget::GetSegmentation()
{
    QListIterator<BCSingleDisplayWidget *> it( m_lstSingleDisplay );
    while ( it.hasNext() ) {
        BCSingleDisplayWidget *pWidget = it.next();
        return pWidget->GetSegmentation();
    }

    return 1;
}

BCSingleDisplayWidget *BCGroupDisplayWidget::GetSingleDisplay(QPoint pt)
{
    QListIterator<BCSingleDisplayWidget *> it( m_lstSingleDisplay );
    while ( it.hasNext() ) {
        BCSingleDisplayWidget *pWidget = it.next();
        QPoint ptLT = pWidget->mapTo(m_parent, pWidget->rect().topLeft());
        QPoint ptRB = pWidget->mapTo(m_parent, pWidget->rect().bottomRight());

        QRect rect = QRect(ptLT, ptRB);
        if ( !rect.contains( pt ) )
            continue;

        return pWidget;
    }

    return NULL;
}

void BCGroupDisplayWidget::resizeEvent(QResizeEvent *e)
{
    QSize groupVirSize = e->size();
    QRectF groupFactRect = m_pMGroupDisplay->GetRect();

    for (int i = 0; i < m_lstSingleDisplay.count(); i++) {
        BCSingleDisplayWidget *pDisplayWidget = m_lstSingleDisplay.at( i );

        BCMDisplay *pMDisplay = pDisplayWidget->GetMDisplay();
        QRectF displayFactRect = pMDisplay->GetRect();

        // 移动位置
        int displayVirX = groupVirSize.width() * displayFactRect.left() / groupFactRect.width();
        int displayVirY = groupVirSize.height() * displayFactRect.top() / groupFactRect.height();
        pDisplayWidget->move(displayVirX, displayVirY);

        // ??? 可能出现不能整除的情况
        int displayVirW = groupVirSize.width() * displayFactRect.width() / groupFactRect.width();
        int displayVirH = groupVirSize.height() * displayFactRect.height() / groupFactRect.height();
        pDisplayWidget->resize(displayVirW, displayVirH);

        //qDebug() << displayVirX << displayVirY << displayVirW << displayVirH << "~~~~~~~~~~~~~~";
    }

    // ??? 对信号窗进行缩放
    //m_image = m_imageSrc.scaled(this->rect().width(), this->rect().height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    e->accept();
}

void BCGroupDisplayWidget::paintEvent(QPaintEvent */*e*/)
{
    QPainter painter(this);

    // 屏组区域黑色实线
    painter.setPen(QPen(Qt::black,1,Qt::SolidLine));
    painter.setBrush( QBrush(QColor(BCCommon::g_nSingleDisplayFillColorR,
                                    BCCommon::g_nSingleDisplayFillColorG,
                                    BCCommon::g_nSingleDisplayFillColorB,
                                    BCCommon::g_nSingleDisplayFillColorA)));

    painter.drawRect( QRect(rect().left(), rect().top(), rect().width()-1, rect().height()-1) );

    //painter.drawImage(QRect(rect().left(), rect().top(), rect().width(), rect().height()), m_image);
}
