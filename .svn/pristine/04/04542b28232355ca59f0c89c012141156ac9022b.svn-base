#include "BCSceneListWidgetData.h"
#include "../Model/BCMWindowScene.h"
#include "../Common/BCCommon.h"
#include "../Model/BCMRoom.h"
#include "../Model/BCMGroupDisplay.h"
#include "../Model/BCMChannel.h"
#include <QLabel>
#include <QVBoxLayout>

BCSceneListWidgetDataRectItem::BCSceneListWidgetDataRectItem(int type, const QString &name, QGraphicsItem *parent)
    :QGraphicsRectItem(parent)
{
    m_type = type;
    m_name = name;
}

void BCSceneListWidgetDataRectItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget*/)
{
    switch ( m_type ) {
    case 1:     // 屏组
        // 设置边线
        painter->setPen(QPen(QBrush(QColor(BCCommon::g_nSingleDisplayLineColorR,
                                           BCCommon::g_nSingleDisplayLineColorG,
                                           BCCommon::g_nSingleDisplayLineColorB,
                                           BCCommon::g_nSingleDisplayLineColorA)),
                             BCCommon::g_nSingleDisplayLineWidth,
                             Qt::PenStyle(BCCommon::g_nSingleDisplayLineStyle)));

        // 设置颜色填充
        painter->setBrush(QBrush(QColor(BCCommon::g_nSingleDisplayFillColorR,
                                        BCCommon::g_nSingleDisplayFillColorG,
                                        BCCommon::g_nSingleDisplayFillColorB,
                                        BCCommon::g_nSingleDisplayFillColorA)));
        break;
    default:    // 窗口
        painter->setPen(QPen(QBrush(QColor(BCCommon::g_nSignalWindowBodyLineColorR,
                                           BCCommon::g_nSignalWindowBodyLineColorG,
                                           BCCommon::g_nSignalWindowBodyLineColorB,
                                           BCCommon::g_nSignalWindowBodyLineColorA)),
                             BCCommon::g_nSignalWindowBodyLineWidth,
                             Qt::PenStyle(BCCommon::g_nSignalWindowBodyLineStyle)));

        // 设置颜色填充
        painter->setBrush(QBrush(QColor(BCCommon::g_nSignalWindowBodyFillColorR,
                                        BCCommon::g_nSignalWindowBodyFillColorG,
                                        BCCommon::g_nSignalWindowBodyFillColorB,
                                        BCCommon::g_nSignalWindowBodyFillColorA)));
        break;
    }

    // 绘制文字
    if ( !m_name.isNull() ) {
        painter->setPen(Qt::black);
//        QRect boundingRect = QRect(rect().left(), rect().top(), rect().width(), rect().height());
//        painter->drawText(boundingRect, 0, m_name, &boundingRect);
        painter->drawText(rect(), Qt::AlignCenter, m_name);
    }

    // 绘制矩形
    painter->drawRect( rect() );
}

// ------------------------------------------------------------------------------------------------------------------------------------
BCSceneListWidgetData::BCSceneListWidgetData(BCMWindowScene *pWindowScene, QWidget *parent)
    :QWidget(parent)
{
    m_pWindowScene = pWindowScene;

    // 构造scene
    m_pGraphicsView = new QGraphicsView( this );
    m_pScene = new QGraphicsScene( m_pGraphicsView );
    m_pGraphicsView->setScene( m_pScene );

    m_pStatusLabel = new QLabel( this );
    m_pStatusLabel->setMinimumHeight( 20 );
    m_pStatusLabel->setMaximumHeight( 20 );
    m_pStatusLabel->setText( pWindowScene->GetWindowSceneName() );
    m_pStatusLabel->setAlignment( Qt::AlignHCenter );

    QVBoxLayout *pLayout = new QVBoxLayout( this );
    pLayout->addWidget( m_pGraphicsView );
    pLayout->addWidget( m_pStatusLabel );
    pLayout->setMargin( 0 );
    pLayout->setSpacing( 0 );
    this->setLayout( pLayout );

    Refresh();
}

BCSceneListWidgetData::~BCSceneListWidgetData()
{

}

void BCSceneListWidgetData::Refresh()
{
    if (NULL == m_pWindowScene)
        return;

    m_pScene->clear();

    MainWindow *pApplication = BCCommon::Application();

    BCMRoom *pRoom = NULL;
    QStringList lstGroupDisplay;    // 存储涉及到的屏组
    QList<BCWindowSceneData *> lstWindowSceneData = m_pWindowScene->GetWindowSceneData();
    for (int i = 0; i < lstWindowSceneData.count(); i++) {
        BCWindowSceneData *pWindowSceneData = lstWindowSceneData.at(i);

        if ( !lstGroupDisplay.contains( QString::number(pWindowSceneData->m_nScreenGroupID) ) ) {
            lstGroupDisplay.append( QString::number(pWindowSceneData->m_nScreenGroupID) );

            // 绘制房间
            if (NULL == pRoom) {
                pRoom = pApplication->GetMRoomByGroupDisplayID( pWindowSceneData->m_nScreenGroupID );
            }

            // 绘制屏组矩形
            if (NULL != pRoom) {
                BCMGroupDisplay *pGroupDisplay = pRoom->GetGroupDisplay( pWindowSceneData->m_nScreenGroupID );
                if (NULL != pGroupDisplay) {
                    QSizeF roomSize = pRoom->GetWallSize();
                    QRectF groupDisplayRect = pGroupDisplay->GetRect();

                    QRectF virtualRoomRect = m_pScene->sceneRect();
                    double dL = virtualRoomRect.width() * groupDisplayRect.left()/roomSize.width();
                    double dT = virtualRoomRect.height() * groupDisplayRect.top()/roomSize.height();
                    double dW = virtualRoomRect.width() * groupDisplayRect.width()/roomSize.width();
                    double dH = virtualRoomRect.height() * groupDisplayRect.height()/roomSize.height();

                    BCSceneListWidgetDataRectItem *pRectItem = new BCSceneListWidgetDataRectItem(1, QString::null);
                    pRectItem->setRect(dL, dT, dW, dH);

                    m_pScene->addItem( pRectItem );
                }
            }
        }

        if (NULL == pRoom)
            continue;

        QSizeF roomSize = pRoom->GetWallSize();
        QRectF signalRect = pWindowSceneData->m_rect;

        QRectF virtualRoomRect = m_pScene->sceneRect();
        double dL = virtualRoomRect.width() * signalRect.left()/roomSize.width();
        double dT = virtualRoomRect.height() * signalRect.top()/roomSize.height();
        double dW = virtualRoomRect.width() * signalRect.width()/roomSize.width();
        double dH = virtualRoomRect.height() * signalRect.height()/roomSize.height();

        QString name;
        BCMChannel *pChannel = pApplication->GetInputChannel(pWindowSceneData->m_nChannelID, pWindowSceneData->m_nChannelType);
        if (NULL != pChannel) {
            name = QString::number(pChannel->GetChannelID()+1);//pChannel->GetChannelBaseName();
        }
        BCSceneListWidgetDataRectItem *pRectItem = new BCSceneListWidgetDataRectItem(2, name);
        pRectItem->setRect(dL, dT, dW, dH);

        m_pScene->addItem( pRectItem );
    }
}

void BCSceneListWidgetData::resizeEvent(QResizeEvent * event)
{
    QSize size = event->size();

    // 修改scene尺寸
    //m_pScene->setSceneRect(QRectF(0, 0, size.width(), size.height()-20));
    m_pScene->setSceneRect( QRectF(0, 0, m_pGraphicsView->rect().width()-3, m_pGraphicsView->rect().height()-3) );
    Refresh();

    event->accept();
}

void BCSceneListWidgetData::contextMenuEvent(QContextMenuEvent */*event*/)
{
    QMenu menu;
    QAction *pShowScene = menu.addAction(QObject::tr("预览场景"));
    QAction *pUpdateScene = menu.addAction(QObject::tr("更新场景"));

    // 显示菜单
    QAction *pSelectAction = menu.exec(QCursor::pos());
    if (NULL == pSelectAction)
        return;

    if (pShowScene == pSelectAction) {
        m_pWindowScene->Show();
    }

    if (pUpdateScene == pSelectAction) {
        m_pWindowScene->Update();
        this->Refresh();
    }
}

void BCSceneListWidgetData::mouseDoubleClickEvent(QMouseEvent */*event*/)
{
    m_pWindowScene->Show();
}
