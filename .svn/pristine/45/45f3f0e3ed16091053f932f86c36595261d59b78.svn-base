#include "BCRoomWidget.h"
#include <QResizeEvent>
#include <QVBoxLayout>
#include <QToolButton>
#include "../Common/BCCommon.h"
#include "../Model/BCMRoom.h"
#include "../Model/BCMGroupDisplay.h"
#include "../Model/BCMChannel.h"
#include "../Model/BCMGroupDisplay.h"
#include "../Model/BCMDisplay.h"
#include "../Model/BCMWindowScene.h"
#include "../Model/BCMChannel.h"
#include "../Common/BCCommunication.h"
#include "../Common/BCLocalServer.h"
#include "BCGroupDisplayWidget.h"
#include "BCSignalWindowDisplayWidget.h"
#include "BCRibbonMainToolBar.h"
#include "BCRibbonMainToolBarAction.h"
#include "BCToolBar.h"
#include "BCRibbonMainToolBarAction.h"
#include "BCFaceWidget.h"
#include "BCControl.h"
#include "BCSignalWindowDisplayWidget.h"
#include "BCSingleDisplayWidget.h"
#include "BCSingleDisplayVirtualWidget.h"
#include "BCMatrixRoomWidget.h"
#include "../Model/BCMMatrix.h"
#include "BCMatrix.h"

//#define JOINTMATRIXTOPTOONE     // 联控时固定将顶层窗口切换成1

BCRoomMainWidget::BCRoomMainWidget(BCMRoom *pMRoom, BCRoomWidget *parent)
    :QWidget(parent)
{
    // 设置允许拖拽
    setAcceptDrops( true );

    m_pMRoom = pMRoom;

    // 关联data和ui
    m_pMRoom->SetSignalWidgetManager( this );

    m_x = 0;
    m_y = 0;
    m_bPress = false;
    m_pInputChannel = NULL;
    m_pCurrentSceneGroup = NULL;
    m_pCurrentSignalWindow = NULL;
    m_bFloorPlanning = false;

    // 虚拟矩形框，默认隐藏
    m_pVirtualRectItem = new QWidget( this );
    m_pVirtualRectItem->setAutoFillBackground( true );
    m_pVirtualRectItem->setStyleSheet( "border:1px dashed black" ); // dotted solid double dashed
    m_pVirtualRectItem->hide();

    // init groupdisplay
    QList<BCMGroupDisplay *> lstGroupDisplay = m_pMRoom->GetGroupDisplay();
    for (int i = 0; i < lstGroupDisplay.count(); i++) {
        BCMGroupDisplay *pMGroupDisplay = lstGroupDisplay.at( i );

        BCGroupDisplayWidget *pGroupDisplayWidget = new BCGroupDisplayWidget(pMGroupDisplay, this);

        m_lstGroupDisplayWidget.append( pGroupDisplayWidget );
    }
}

BCRoomMainWidget::~BCRoomMainWidget()
{
    while ( !m_lstSignalWindow.isEmpty() )
        delete m_lstSignalWindow.takeFirst();

    while ( !m_lstGroupDisplayWidget.isEmpty() )
        delete m_lstGroupDisplayWidget.takeFirst();

    while ( !m_lstSignalWindowOfFloorPlanning.isEmpty() )
        delete m_lstSignalWindowOfFloorPlanning.takeFirst();
}

void BCRoomMainWidget::resizeEvent(QResizeEvent *e)
{
    QSize roomVirSize = e->size();
    qDebug() << roomVirSize << "~~~~";
    QSizeF roomFactSize = m_pMRoom->GetWallSize();

    for (int i = 0; i < m_lstGroupDisplayWidget.count(); i++) {
        BCGroupDisplayWidget *pGroupDisplayWidget = m_lstGroupDisplayWidget.at( i );

        BCMGroupDisplay *pMGroupDisplay = pGroupDisplayWidget->GetMGroupDisplay();
        QRectF groupFactRect = pMGroupDisplay->GetRect();

        // 移动位置
        int groupVirX = roomVirSize.width() * groupFactRect.left() / roomFactSize.width();
        int groupVirY = roomVirSize.height() * groupFactRect.top() / roomFactSize.height();
        pGroupDisplayWidget->move(groupVirX, groupVirY);

        int groupVirW = roomVirSize.width() * groupFactRect.width() / roomFactSize.width();
        int groupVirH = roomVirSize.height() * groupFactRect.height() / roomFactSize.height();
        pGroupDisplayWidget->resize(groupVirW, groupVirH);
    }

    // 对信号窗进行缩放
    for (int i = 0; i < m_lstSignalWindow.count(); i++) {
        BCSignalWindowDisplayWidget *pWidget = m_lstSignalWindow.at( i );

        QRect sigFactRect = pWidget->GetFactRect();
        QRect sigVirRect = this->MapToVirtualRect(sigFactRect.left(), sigFactRect.top(), sigFactRect.width(), sigFactRect.height());

        pWidget->ResizeRect(sigVirRect.left(), sigVirRect.top(), sigVirRect.width(), sigVirRect.height());
    }

    e->accept();
}

void BCRoomMainWidget::SetFloorPlanning(bool b)
{
    if (m_bFloorPlanning == b)
        return;

    m_bFloorPlanning = b;

    // 当打开预布局时需要记录当前信号窗数据
    if ( m_bFloorPlanning ) {
        QListIterator<BCSignalWindowDisplayWidget *> it( m_lstSignalWindow );
        while (it.hasNext()) {
            BCSignalWindowDisplayWidget *pSignalWindow = it.next();
            if (NULL == pSignalWindow)
                continue;

            BCMChannel *pChannel = pSignalWindow->GetInputChannel();
            if (NULL == pChannel)
                continue;

            // 构造场景数据
            BCWindowSceneData *pWindowData = new BCWindowSceneData();
            pWindowData->m_nScreenGroupID = pSignalWindow->GetGroupDisplay()->GetMGroupDisplay()->GetGroupDisplayID();
            pWindowData->m_nChannelID = pChannel->GetChannelID();
            pWindowData->m_nChannelType = pChannel->GetChannelType();
            pWindowData->m_nWindowID = pSignalWindow->GetWindowID();
            pWindowData->m_nCopyIndex = pSignalWindow->GetCopyIndex();
            pWindowData->m_rect = pSignalWindow->GetFactRect();

            // 如果通道类型是9代表是IPV窗口，需要记录分割和使用的IP链表，链表个数必须是16个
            pWindowData->m_nIPVSegmentation = (9 == pChannel->GetSignalSource()) ? pSignalWindow->GetIPVedioSegmentationCount() : -1;
            QList<BCSignalWindowIPVWidget *> lstSubDisplayItem = pSignalWindow->GetSubDisplayItem();
            if (36 == lstSubDisplayItem.count()) {
                for (int i = 0; i < lstSubDisplayItem.count(); i++) {
                    BCSignalWindowIPVWidget *pSubDisplayItem = lstSubDisplayItem.at( i );
                    pWindowData->m_lstIP.append( pSubDisplayItem->m_qsUrl );
                }
            } else {
                pWindowData->m_lstIP.clear();

                for (int i = 0; i < 36; i++) {
                    pWindowData->m_lstIP.append( QString::null );
                }
            }

            m_lstSignalWindowOfFloorPlanning.append( pWindowData );
        }
    } else {
        while ( !m_lstSignalWindowOfFloorPlanning.isEmpty() )
            delete m_lstSignalWindowOfFloorPlanning.takeFirst();
    }
}

void BCRoomMainWidget::SetFloorPlanningSync()
{
    // 打开窗口
    BCLocalServer *pServer = BCLocalServer::Application();
    BCCommunication *pCommunication = BCCommunication::Application();
    for (int i = 0; i < m_lstSignalWindow.count(); i++) {
        BCSignalWindowDisplayWidget *pSignalWindow = m_lstSignalWindow.at( i );
        BCMChannel *pChannel = pSignalWindow->GetInputChannel();
        if (NULL == pChannel)
            continue;

        for (int j = 0; j < m_lstSignalWindowOfFloorPlanning.count(); j++) {
            BCWindowSceneData *pWindowData = m_lstSignalWindowOfFloorPlanning.at( j );

            if ((pWindowData->m_nScreenGroupID == pSignalWindow->GetGroupDisplay()->GetMGroupDisplay()->GetGroupDisplayID())
                    && (pWindowData->m_nChannelID == pChannel->GetChannelID())
                    && (pWindowData->m_nChannelType == pChannel->GetChannelType())
                    && (pWindowData->m_nWindowID == pSignalWindow->GetWindowID())
                    && (pWindowData->m_nCopyIndex == pSignalWindow->GetCopyIndex())) {

                // 从链表中清除
                m_lstSignalWindowOfFloorPlanning.removeAt(j);
                delete pWindowData;
                pWindowData = NULL;
                j--;
            }
        }

        // 发送开窗指令
        QThread::msleep( 50 );
        if ( BCCommon::g_bConnectWithServer ) {
            pCommunication->Winsize(pSignalWindow->GetGroupDisplay()->GetMGroupDisplay()->GetGroupDisplayID(), pChannel->GetChannelID(), pSignalWindow->GetWindowID(),
                                    pSignalWindow->GetFactRect().left(), pSignalWindow->GetFactRect().top(), pSignalWindow->GetFactRect().left()+pSignalWindow->GetFactRect().width(), pSignalWindow->GetFactRect().top()+pSignalWindow->GetFactRect().height(),
                                    pChannel->GetChannelType(), pSignalWindow->GetCopyIndex());
        } else {
            pServer->winsize(pSignalWindow->GetGroupDisplay()->GetMGroupDisplay()->GetGroupDisplayID(), pChannel->GetChannelID(), pSignalWindow->GetWindowID(),
                             pSignalWindow->GetFactRect().left(), pSignalWindow->GetFactRect().top(), pSignalWindow->GetFactRect().left()+pSignalWindow->GetFactRect().width(), pSignalWindow->GetFactRect().top()+pSignalWindow->GetFactRect().height(),
                             pChannel->GetChannelType(), pSignalWindow->GetCopyIndex());
        }
    }

    // 关闭窗口
    for (int j = 0; j < m_lstSignalWindowOfFloorPlanning.count(); j++) {
        BCWindowSceneData *pWindowData = m_lstSignalWindowOfFloorPlanning.at( j );

        // 发送关窗指令
        QThread::msleep( 50 );
        if ( BCCommon::g_bConnectWithServer ) {
            pCommunication->RequestWinSwitch(pWindowData->m_nScreenGroupID, pWindowData->m_nWindowID, pWindowData->m_nChannelID, pWindowData->m_nChannelType, pWindowData->m_nCopyIndex);
        } else {
            pServer->winswitch(pWindowData->m_nScreenGroupID, pWindowData->m_nWindowID, pWindowData->m_nChannelID, pWindowData->m_nChannelType, pWindowData->m_nCopyIndex);
        }
    }

    // 清空窗口
    while ( !m_lstSignalWindowOfFloorPlanning.isEmpty() )
        delete m_lstSignalWindowOfFloorPlanning.takeFirst();

    // 同步窗口
    if ( m_bFloorPlanning ) {
        QListIterator<BCSignalWindowDisplayWidget *> it( m_lstSignalWindow );
        while (it.hasNext()) {
            BCSignalWindowDisplayWidget *pSignalWindow = it.next();
            if (NULL == pSignalWindow)
                continue;

            BCMChannel *pChannel = pSignalWindow->GetInputChannel();
            if (NULL == pChannel)
                continue;

            // 构造场景数据
            BCWindowSceneData *pWindowData = new BCWindowSceneData();
            pWindowData->m_nScreenGroupID = pSignalWindow->GetGroupDisplay()->GetMGroupDisplay()->GetGroupDisplayID();
            pWindowData->m_nChannelID = pChannel->GetChannelID();
            pWindowData->m_nChannelType = pChannel->GetChannelType();
            pWindowData->m_nWindowID = pSignalWindow->GetWindowID();
            pWindowData->m_nCopyIndex = pSignalWindow->GetCopyIndex();
            pWindowData->m_rect = pSignalWindow->GetFactRect();

            // 如果通道类型是9代表是IPV窗口，需要记录分割和使用的IP链表，链表个数必须是16个
            pWindowData->m_nIPVSegmentation = (9 == pChannel->GetSignalSource()) ? pSignalWindow->GetIPVedioSegmentationCount() : -1;
            QList<BCSignalWindowIPVWidget *> lstSubDisplayItem = pSignalWindow->GetSubDisplayItem();
            if (36 == lstSubDisplayItem.count()) {
                for (int i = 0; i < lstSubDisplayItem.count(); i++) {
                    BCSignalWindowIPVWidget *pSubDisplayItem = lstSubDisplayItem.at( i );
                    pWindowData->m_lstIP.append( pSubDisplayItem->m_qsUrl );
                }
            } else {
                pWindowData->m_lstIP.clear();

                for (int i = 0; i < 36; i++) {
                    pWindowData->m_lstIP.append( QString::null );
                }
            }

            m_lstSignalWindowOfFloorPlanning.append( pWindowData );
        }
    } else {
        while ( !m_lstSignalWindowOfFloorPlanning.isEmpty() )
            delete m_lstSignalWindowOfFloorPlanning.takeFirst();
    }
}

BCSignalWindowDisplayWidget *BCRoomMainWidget::AddSignalWindow(int x, int y, int w, int h, BCGroupDisplayWidget *pGroupDisplayWidget, BCMChannel *pChannel, int winid, bool bSendCmd)
{
    // 超出范围添加失败
    if ((x < 0) || (y < 0) || (w < 0) || (h < 0) || (NULL == pGroupDisplayWidget))
        return NULL;

    // 判断是否允许开窗
    if ( !pChannel->IsOpenWindowKey(pGroupDisplayWidget->GetMGroupDisplay()->GetGroupDisplayID()) )
        return NULL;

    // 重新计算winid
    winid = (winid == -1) ? CreateWindowID(pChannel) : winid;
    if (-1 == winid)
        return NULL;

    // 如果是预布局，不发送指令
    if ( m_bFloorPlanning ) {
        bSendCmd = false;
    }

    BCSignalWindowDisplayWidget *pWidget = new BCSignalWindowDisplayWidget(pGroupDisplayWidget, x, y, w, h, pChannel, winid, this, bSendCmd);
    pWidget->setVisible( true );
    m_lstSignalWindow.append( pWidget );
    RefreshSignalWindowZValue();
    pChannel->AddSignalWindowDisplayWidget( pWidget );

    // 添加信号窗时候如果已经是全局回显则打开回显开关
    MainWindow *pApplication = BCCommon::Application();
    pWidget->SetEcho( pApplication->IsOpenAllSignalEcho() );

    RefreshLocalDlg();

    return pWidget;
}

QRect BCRoomMainWidget::MapToVirtualRect(int x, int y, int w, int h)
{
    QSizeF wallFactSize = m_pMRoom->GetWallSize();
    QRect wallVirRect = this->rect();

    // 转换成房间的虚拟尺寸
    int virLeft = x * wallVirRect.width() / wallFactSize.width();
    int virRight = (x+w) * wallVirRect.width() / wallFactSize.width();
    int virTop = y * wallVirRect.height() / wallFactSize.height();
    int virBottom = (y+h) * wallVirRect.height() / wallFactSize.height();

    return QRect(virLeft, virTop, virRight-virLeft, virBottom-virTop);
}

QRect BCRoomMainWidget::MapToFactRect(int x, int y, int w, int h)
{
    QSizeF wallFactSize = m_pMRoom->GetWallSize();
    QRect wallVirRect = this->rect();

    // 转换成房间的虚拟尺寸
    int factLeft = x * wallFactSize.width() / wallVirRect.width();
    int factRight = (x+w) * wallFactSize.width() / wallVirRect.width();
    int factTop = y * wallFactSize.height() / wallVirRect.height();
    int factBottom = (y+h) * wallFactSize.height() / wallVirRect.height();

    qDebug() << wallFactSize << wallVirRect << "!!!!~~~~~";
    return QRect(factLeft, factTop, factRight-factLeft, factBottom-factTop);
}

QPoint BCRoomMainWidget::MapToFactPoint(int x, int y)
{
    QSizeF wallFactSize = m_pMRoom->GetWallSize();
    QRect wallVirRect = this->rect();

    // 转换成房间的虚拟尺寸
    int factLeft = x * wallFactSize.width() / wallVirRect.width();
    int factTop = y * wallFactSize.height() / wallVirRect.height();

    return QPoint(factLeft, factTop);
}

int BCRoomMainWidget::CreateWindowID(BCMChannel *pChannel)
{
    if (NULL == pChannel)
        return -1;

    // 如果不支持窗口复制，每个信号窗只能开一次
    if ( !BCCommon::g_bSignalWindowCopy ) {
        QListIterator<BCSignalWindowDisplayWidget *> it( m_lstSignalWindow );
        while ( it.hasNext() ) {
            BCSignalWindowDisplayWidget *pSignalWindow = it.next();
            if (NULL == pSignalWindow)
                continue;

            // 如果没有输入通道数据直接下一个
            BCMChannel *pCurrentChannel = pSignalWindow->GetInputChannel();
            if (NULL == pCurrentChannel)
                continue;

            if (pCurrentChannel->GetChannelID() == pChannel->GetChannelID())
                return -1;
        }
    }

    // 如果没有信号窗则WindowID为0
    if ( m_lstSignalWindow.isEmpty() )
        return 0;

    // 循环现有开窗获得WindowID
    QList<int> lstWindowIDs;
    QListIterator<BCSignalWindowDisplayWidget *> it( m_lstSignalWindow );
    while ( it.hasNext() ) {
        BCSignalWindowDisplayWidget *pSignalWindow = it.next();
        if (NULL == pSignalWindow)
            continue;

        // 如果没有输入通道数据直接下一个
        BCMChannel *pCurrentChannel = pSignalWindow->GetInputChannel();
        if (NULL == pCurrentChannel)
            continue;

        lstWindowIDs.append( pSignalWindow->GetWindowID() );
    }

    // 从0开始循环，如果中间有空缺直接返回，无空缺返回最后一个
    for (int i = 0; i < lstWindowIDs.count()+1; i++) {
        if (lstWindowIDs.contains(i))
            continue;

        return i;
    }

    return 0;
}

BCGroupDisplayWidget *BCRoomMainWidget::GetCurrentGroupDisplay()
{
    // 屏组应该有选中状态，但是目前一个房间只有一个屏组，直接返回第一个就可以
    return m_lstGroupDisplayWidget.first();
}

bool BCRoomMainWidget::RemoveSignalWindowDisplayItem(BCSignalWindowDisplayWidget *pItem, bool bSendCmd)
{
    if (NULL == pItem)
        return false;

    BCMChannel *pChannel = pItem->GetInputChannel();
    if (NULL == pChannel)
        return false;

    // 如果是预布局，不发送指令
    if ( m_bFloorPlanning ) {
        bSendCmd = false;
    }

    // 关窗的时候需要判断是哪种环境
    if ( bSendCmd ) {
        // 如果数据为空是切换矩阵
        BCGroupDisplayWidget *pSceneGroup = pItem->GetGroupDisplay();
        BCMGroupDisplay *pMGroupDisplay = pSceneGroup->GetMGroupDisplay();
        if (NULL == pMGroupDisplay) {
            ServerWinSwitchResult(true, pItem);
        } else {
            int groupid = pMGroupDisplay->GetGroupDisplayID();

            if ( !BCCommon::g_bConnectWithServer ) {
                // 1.单机版可以直接调用DLL接口
                BCLocalServer *pServer = BCLocalServer::Application();
                pServer->winswitch(groupid, pItem->GetWindowID(), pChannel->GetChannelID(), pChannel->GetChannelType(), pItem->GetCopyIndex());

                ServerWinSwitchResult(true, pItem);
            } else {
                // 2.服务器版需要先请求
                BCCommunication *pCommunication = BCCommunication::Application();
                pCommunication->RequestWinSwitch(groupid, pItem->GetWindowID(), pChannel->GetChannelID(), pChannel->GetChannelType(), pItem->GetCopyIndex());
            }
        }
    } else {
        ServerWinSwitchResult(true, pItem);
    }

    return true;
}

void BCRoomMainWidget::ServerWinSwitchResult(bool b, BCSignalWindowDisplayWidget *pItem)
{
    if ( !b )
        return;

    if (NULL == pItem)
        return;

    // 设置关闭回显
    pItem->SetEcho( false );

    // 设置父类
    m_lstSignalWindow.removeOne( pItem );
    RefreshSignalWindowZValue();

    // 将信号窗从通道中移除掉
    BCMChannel *pChannel = pItem->GetInputChannel();
    if (NULL != pChannel)
        pChannel->RemoveSignalWindowDisplayWidget( pItem );

    pItem->close();

    RefreshLocalDlg();
}

void BCRoomMainWidget::RefreshLocalDlg()
{
    // 刷新全局窗口定位代码
    MainWindow *pMainWindow = BCCommon::Application();
    BCRibbonMainToolBar *pMainToolBar = pMainWindow->GetRibbonMainToolBar();
    if (NULL == pMainToolBar)
        return;

    BCRibbonMainToolBarAction *pLocationBtn = pMainToolBar->GetButtonAction( BCRibbonMainToolBar::LOCATION );
    if (NULL != pLocationBtn) {
        pLocationBtn->RefreshLocationDlg();
    }

    // 刷新输入信号源的名称
    // 高亮输入通道
    MainWindow *pApplication = BCCommon::Application();
    BCToolBar *pToolBar = pApplication->GetToolBar(MainWindow::SIGNALSOURCETOOLBAR);
    if (NULL != pToolBar) {
        BCFaceWidget *pSignalSourceWidget = dynamic_cast<BCFaceWidget *>( pToolBar->widget() );
        if (NULL != pSignalSourceWidget) {
            BCControl *pInputChannelWidget = dynamic_cast<BCControl *>(pSignalSourceWidget->GetWidget(MainWindow::INPUTCHANNELSSIGSRC));
            if(NULL != pInputChannelWidget)
                pInputChannelWidget->RefreshInputChannelName();
        }
    }
}

BCSignalWindowDisplayWidget *BCRoomMainWidget::ServerWinsize(BCGroupDisplayWidget *pGroupDisplayWidget, BCMChannel *pChannel, int winid, int x, int y, int w, int h)
{
    // 两种情况：根据窗口标识判断是否存在开窗
    BCSignalWindowDisplayWidget *pSignalWindowWidget = GetSignalWindowByWindowID( winid );
    if (NULL == pSignalWindowWidget) {
        // 1.不存在则根据窗口标识进行开窗
        pSignalWindowWidget = AddSignalWindow(x, y, w, h, pGroupDisplayWidget, pChannel, winid, false);
    } else {
        // 2.存在则根据窗口标识修改位置
        pSignalWindowWidget->SetSignalWindowResize(x, y, w, h, false);
    }

    // 将信号窗置顶
    if (NULL != pSignalWindowWidget)
        SetSignalWindowTop( pSignalWindowWidget );

    return pSignalWindowWidget;
}

BCSignalWindowDisplayWidget *BCRoomMainWidget::GetSignalWindowByWindowID(int winid)
{
    QListIterator<BCSignalWindowDisplayWidget *> it( m_lstSignalWindow );
    while ( it.hasNext() ) {
        BCSignalWindowDisplayWidget *pSignalWidget = it.next();
        if (winid != pSignalWidget->GetWindowID())
            continue;

        return pSignalWidget;
    }

    return NULL;
}

void BCRoomMainWidget::SetAllSignalEchoVisibel(bool b)
{
    QListIterator<BCSignalWindowDisplayWidget *> it( m_lstSignalWindow );
    while ( it.hasNext() ) {
        BCSignalWindowDisplayWidget *pWindow = it.next();
        if (NULL == pWindow)
            continue;

        pWindow->SetEcho( b );
    }
}

void BCRoomMainWidget::RefreshEchoStatus(bool bTempCloseEcho)
{
    QListIterator<BCSignalWindowDisplayWidget *> it( m_lstSignalWindow );
    while ( it.hasNext() ) {
        BCSignalWindowDisplayWidget *pWindow = it.next();
        if (NULL == pWindow)
            continue;

        pWindow->RefreshEchoStatus( bTempCloseEcho );
    }
}

void BCRoomMainWidget::RefreshSignalWindowTextDisplay()
{
    QListIterator<BCSignalWindowDisplayWidget *> it( m_lstSignalWindow );
    while ( it.hasNext() ) {
        BCSignalWindowDisplayWidget *pWindow = it.next();
        if (NULL == pWindow)
            continue;

        pWindow->RefreshTextDisplay();
    }
}

int BCRoomMainWidget::GetSignalWindowIndex(BCSignalWindowDisplayWidget *pItem)
{
    // 叠放序号从1开始
    return m_lstSignalWindow.indexOf( pItem ) + 1;
}

bool BCRoomMainWidget::SetSignalWindowTop(BCSignalWindowDisplayWidget *pItem)
{
    if (NULL == pItem)
        return false;

    if (!m_lstSignalWindow.contains(pItem))
        return false;

    int iCurrent = m_lstSignalWindow.indexOf(pItem);
    if (iCurrent != m_lstSignalWindow.count()-1) {
        for (int i = iCurrent; i < m_lstSignalWindow.count(); i++) {
            int j = i+1;
            if (j < m_lstSignalWindow.count())
                m_lstSignalWindow.swap(i , j);
        }

        // 刷新信号窗的叠放次序
        this->RefreshSignalWindowZValue();
    }

    // 置顶需要将指定的信号窗重新发送指令，预布局时不发送
//#ifdef JOINTMATRIXTOPTOONE
    if ( !BCCommon::g_bConnectWithServer ) {
        if (!m_bFloorPlanning && (iCurrent != m_lstSignalWindow.count()-1)) {
            BCLocalServer *pServer = BCLocalServer::Application();
            pServer->winup(m_pMRoom->GetRoomID(), pItem->GetWindowID());
            //pItem->Winsize( false );
        }
    }
//#endif

    // 刷新快速定位
    RefreshLocalDlg();

    // 高亮输入通道
    MainWindow *pApplication = BCCommon::Application();
    BCToolBar *pToolBar = pApplication->GetToolBar(MainWindow::SIGNALSOURCETOOLBAR);
    if (NULL != pToolBar) {
        BCFaceWidget *pSignalSourceWidget = dynamic_cast<BCFaceWidget *>( pToolBar->widget() );
        if (NULL != pSignalSourceWidget) {
            BCControl *pInputChannelWidget = dynamic_cast<BCControl *>(pSignalSourceWidget->GetWidget(MainWindow::INPUTCHANNELSSIGSRC));
            if(NULL != pInputChannelWidget)
                pInputChannelWidget->HighLightInputChannel( pItem->GetInputChannel() );
        }
    }

    return true;
}

bool BCRoomMainWidget::SetSignalWindowBottom(BCSignalWindowDisplayWidget *pItem)
{
    if (NULL == pItem)
        return false;

    if (!m_lstSignalWindow.contains(pItem))
        return false;

    int iCurrent = m_lstSignalWindow.indexOf(pItem);
    if (0 != iCurrent) {
        for (int i = iCurrent; i > 0; i--) {
            int j = i-1;
            if (j >= 0)
                m_lstSignalWindow.swap(i, j);
        }

        this->RefreshSignalWindowZValue();

        RefreshLocalDlg();
    }

    // 置底需要所有窗口都重新发送一遍指令
    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->windown(m_pMRoom->GetRoomID(), pItem->GetWindowID());
//    for (int i = 0; i < m_lstSignalWindow.count(); i++) {
//        pItem = m_lstSignalWindow.at( i );
//        pItem->Winsize( false );
//    }

    return true;
}

bool BCRoomMainWidget::SetSignalWindowMoveToTop(BCSignalWindowDisplayWidget *pItem)
{
    if (NULL == pItem)
        return false;

    if (!m_lstSignalWindow.contains(pItem))
        return false;

    int iCurrent = m_lstSignalWindow.indexOf(pItem);
    if (iCurrent+1 < m_lstSignalWindow.count()) {
        m_lstSignalWindow.swap(iCurrent, iCurrent+1);

        this->RefreshSignalWindowZValue();

        RefreshLocalDlg();
    }

    return true;
}

bool BCRoomMainWidget::SetSignalWindowMoveToBottom(BCSignalWindowDisplayWidget *pItem)
{
    if (NULL == pItem)
        return false;

    if (!m_lstSignalWindow.contains(pItem))
        return false;

    int iCurrent = m_lstSignalWindow.indexOf(pItem);
    if (iCurrent-1 >= 0) {
        m_lstSignalWindow.swap(iCurrent, iCurrent-1);

        RefreshSignalWindowZValue();

        RefreshLocalDlg();
    }

    return true;
}

BCSignalWindowDisplayWidget *BCRoomMainWidget::OpenSignalWindow(BCGroupDisplayWidget *pSceneGroup, BCMChannel *pChannel)
{
    // 当前屏组必须不能为空
    if ((NULL == pSceneGroup) || (NULL == pChannel))
        return NULL;

    QPoint virLT = m_pVirtualRectItem->mapTo(this, m_pVirtualRectItem->rect().topLeft());
    QPoint virRB = m_pVirtualRectItem->mapTo(this, m_pVirtualRectItem->rect().bottomRight());
    QRect rect = QRect(virLT, virRB);

    // 重置矩形范围
//    rect.setLeft(rect.left() < 0 ? 0 : rect.left());
//    rect.setTop(rect.top() < 0 ? 0 : rect.top());
//    rect.setRight(rect.right() > this->rect().right() ? this->rect().right() : rect.right());
//    rect.setBottom(rect.bottom() > this->rect().bottom() ? this->rect().bottom() : rect.bottom());

    QRect factRect = this->MapToFactRect(rect.left(), rect.top(), rect.width(), rect.height());
    qDebug() << rect << factRect << "|~~~~~~";

    // 如果矩形在范围内则开窗
    if ((rect.width() > BCCommon::g_nMinVirtualSizeOfCreateSignalWindow)
            && (rect.height() > BCCommon::g_nMinVirtualSizeOfCreateSignalWindow)) {
        if ( BCCommon::g_bConnectWithServer ) {
            if ( m_bFloorPlanning ) {   // 如果是打开了预布局则先添加窗口
                ServerWinsize(pSceneGroup, pChannel, CreateWindowID(pChannel), factRect.left(), factRect.top(), factRect.width(), factRect.height());
            } else {
                BCCommunication *pCommunication = BCCommunication::Application();
                pCommunication->Winsize(pSceneGroup->GetMGroupDisplay()->GetGroupDisplayID(), pChannel->GetChannelID(), CreateWindowID(pChannel),
                                        factRect.left(), factRect.top(), factRect.right(), factRect.bottom(), pChannel->GetChannelType(), pChannel->getCopyIndex());
            }
        } else {
            BCSignalWindowDisplayWidget *pCurrentSignalWindow = AddSignalWindow(factRect.left(), factRect.top(), factRect.width(), factRect.height(), pSceneGroup, pChannel);

            // 刷新信号窗的文字显示
            this->RefreshSignalWindowTextDisplay();

            return pCurrentSignalWindow;
        }
    }

    return NULL;
}

void BCRoomMainWidget::ServerResetResult(bool b)
{
    if ( !b )
        return;

    while ( !m_lstSignalWindow.isEmpty() ) {
        RemoveSignalWindowDisplayItem(m_lstSignalWindow.first(), false);
    }

    RefreshLocalDlg();
}

void BCRoomMainWidget::ClearSignalWindow(const QString &qsGroupDisplayIDs, bool bSendCmd)
{
    // 如果是预布局，不发送指令
    if ( m_bFloorPlanning ) {
        bSendCmd = false;
    }

    // 变量为屏组ID
    if (BCCommon::g_bConnectWithServer) {
        if ( bSendCmd ) {
            BCCommunication *pCommunication = BCCommunication::Application();
            pCommunication->Reset(qsGroupDisplayIDs);
        } else
            ServerResetResult( true );
    } else {
        // 发送指令
        if ( bSendCmd ) {
            BCLocalServer *pServer = BCLocalServer::Application();
            pServer->reset( qsGroupDisplayIDs );
        }

        ServerResetResult( true );
    }

#ifdef JOINTMATRIXTOPTOONE
    // 判断是否有关联矩阵
    MainWindow *pMainWindow = BCCommon::Application();
    int matrixID = pMainWindow->GetRelationMatrixID( m_pMRoom->GetRoomID() );
    if (-1 != matrixID) {
        BCMatrixRoomWidget *pMatrixRoom = pMainWindow->GetMatrixWidgetByID( matrixID );
        if (NULL != pMatrixRoom) {
            if ( m_lstSignalWindow.isEmpty() ) {
                // 固定切换至1
                pMatrixRoom->SetSwitch(128, 1);
            }
        }
    }
#endif

    RefreshLocalDlg();
}

BCSignalWindowDisplayWidget *BCRoomMainWidget::GetCurrentSignalWindow()
{
    if ( m_lstSignalWindow.isEmpty() )
        return NULL;

    return m_lstSignalWindow.last();
}

void BCRoomMainWidget::RefreshSegmentation(int n)
{
    QListIterator<BCGroupDisplayWidget *> it( m_lstGroupDisplayWidget );
    while ( it.hasNext() ) {
        BCGroupDisplayWidget *pDispayItem = it.next();
        if (NULL == pDispayItem)
            continue;

        pDispayItem->RefreshSegmentation( n );
    }

    // 因为上面的虚拟矩形有变化，所以这里需要刷新界面
    //this->ResizeRect(rect().x(), rect().y(), rect().width(), rect().height());
}

int BCRoomMainWidget::GetSegmentation()
{
    // 循环屏组
    QListIterator<BCGroupDisplayWidget *> it( m_lstGroupDisplayWidget );
    while ( it.hasNext() ) {
        BCGroupDisplayWidget *pGroupDispayItem = it.next();

        // 循环单屏
        QList<BCSingleDisplayWidget *> lstDisplay = pGroupDispayItem->GetSingleDisplay();
        QListIterator<BCSingleDisplayWidget *> itDisplay( lstDisplay );
        while ( itDisplay.hasNext() ) {
            BCSingleDisplayWidget *pDisplayItem = itDisplay.next();

            return pDisplayItem->GetSegmentation();
        }
    }

    return 4;
}

QSize BCRoomMainWidget::GetRoomArray()
{
    // 循环屏组
    QListIterator<BCGroupDisplayWidget *> it( m_lstGroupDisplayWidget );
    while ( it.hasNext() ) {
        BCGroupDisplayWidget *pGroupDispayItem = it.next();
        BCMGroupDisplay *pMGroupDisplay = pGroupDispayItem->GetMGroupDisplay();
        if (NULL != pMGroupDisplay)
            return pMGroupDisplay->GetArraySize();
    }

    return QSize(2, 2);
}

BCGroupDisplayWidget *BCRoomMainWidget::GetCurrentSceneManager(QPoint pt)
{
    QListIterator<BCGroupDisplayWidget *> it( m_lstGroupDisplayWidget );
    while ( it.hasNext() ) {
        BCGroupDisplayWidget *pSceneGroup = it.next();
        if (NULL == pSceneGroup)
            continue;

        // 参数点如果在屏组范围内
        if ( !pSceneGroup->rect().contains(pt) )
            continue;

        return pSceneGroup;
    }

    return NULL;
}

QList<BCSingleDisplayVirtualWidget *> BCRoomMainWidget::GetSingleDisplayVirtualWidget()
{
    QList<BCSingleDisplayVirtualWidget *> lstRes;

    // 循环屏组
    QListIterator<BCGroupDisplayWidget *> it( m_lstGroupDisplayWidget );
    while ( it.hasNext() ) {
        BCGroupDisplayWidget *pSceneGroup = it.next();

        // 循环单屏
        QList<BCSingleDisplayWidget *> lstDisplay = pSceneGroup->GetSingleDisplay();
        QListIterator<BCSingleDisplayWidget *> itDisplay( lstDisplay );
        while ( itDisplay.hasNext() ) {
            BCSingleDisplayWidget *pDisplay = itDisplay.next();

            // 查找虚拟矩形，并添加到链表
            QList<BCSingleDisplayVirtualWidget *> lstVirWidget = pDisplay->GetSingleDisplayVirtualWidget();
            lstRes.append( lstVirWidget );
        }
    }

    return lstRes;
}

BCSignalWindowDisplayWidget *BCRoomMainWidget::GetSignalWindowDisplayItem(QPoint pt)
{
    // 先拖放最上层窗口
    for (int i = m_lstSignalWindow.count()-1; i > -1; i--) {
        BCSignalWindowDisplayWidget *pWidget = m_lstSignalWindow.at(i);

        QPoint ptLT = pWidget->mapTo(this, pWidget->rect().topLeft());
        QPoint ptRB = pWidget->mapTo(this, pWidget->rect().bottomRight());
        QRect rect = QRect(ptLT, ptRB);
        if ( !rect.contains( pt ) )
            continue;

        return pWidget;
    }

    return NULL;
}

void BCRoomMainWidget::RefreshSignalWindowZValue()
{
    for (int i = 0; i < m_lstSignalWindow.count(); i++) {
        BCSignalWindowDisplayWidget *pItem = m_lstSignalWindow.at( i );
        if (NULL == pItem)
            continue;

        pItem->raise();
    }

#ifdef JOINTMATRIXTOPTOONE
    // 判断是否有关联矩阵
    MainWindow *pMainWindow = BCCommon::Application();
    int matrixID = pMainWindow->GetRelationMatrixID( m_pMRoom->GetRoomID() );
    if (-1 != matrixID) {
        BCMatrixRoomWidget *pMatrixRoom = pMainWindow->GetMatrixWidgetByID( matrixID );
        if (NULL != pMatrixRoom) {
            if ( !m_lstSignalWindow.isEmpty() ) {
                BCSignalWindowDisplayWidget *pItem = m_lstSignalWindow.last();
                BCMChannel *pChannel = pItem->GetInputChannel();

                // 固定切换至1
                pMatrixRoom->SetSwitch(pChannel->GetChannelID()+1, 1);
            }
        }
    }
#endif
}

void BCRoomMainWidget::mousePressEvent(QMouseEvent *e)
{
    // 如果当前屏组是矩阵，则不允许划矩形开窗
    if (4 == m_pMRoom->GetType()) {
        QWidget::mousePressEvent( e );
        return;
    }

    // 获得当前点击信号窗
    m_pCurrentSignalWindow = GetSignalWindowDisplayItem( e->pos() );
    // 左键点击当前信号窗则将其置顶
    if ((NULL != m_pCurrentSignalWindow) && (e->button() == Qt::LeftButton)) {
        e->accept();
        return;
    }
    // 获得当前屏组
    m_pCurrentSceneGroup = this->GetCurrentSceneManager( e->pos() );
    if (NULL == m_pCurrentSceneGroup) {
        e->accept();
        return;
    }
    // 获得当前输入信号
    MainWindow *pApplication = BCCommon::Application();
    m_pInputChannel = pApplication->GetCurrentInputChannel();
    if (NULL == m_pInputChannel) {
        e->accept();
        return;
    }

    m_bPress = true;

    // 记录点击的坐标
    m_x = e->pos().x();
    m_y = e->pos().y();

    m_pVirtualRectItem->raise();
    m_pVirtualRectItem->show();
    m_pVirtualRectItem->move(m_x, m_y);
    m_pVirtualRectItem->resize(1, 1);

    QWidget::mousePressEvent( e );
}

void BCRoomMainWidget::mouseMoveEvent(QMouseEvent *e)
{
    if ( m_bPress ) {
        int x = e->pos().x() - m_x;
        int y = e->pos().y() - m_y;

        double dL = (x > 0) ? m_x : e->pos().x();
        double dT = (y > 0) ? m_y : e->pos().y();

        // 修改矩形虚框的尺寸
        m_pVirtualRectItem->move(dL, dT);
        m_pVirtualRectItem->resize(qAbs(x), qAbs(y));
    }

    QWidget::mouseMoveEvent( e );
}

void BCRoomMainWidget::mouseReleaseEvent(QMouseEvent *e)
{
    m_bPress = false;
    m_pVirtualRectItem->hide();

    if (NULL == m_pCurrentSceneGroup) {
        e->accept();
        return;
    }

    // 开窗
    OpenSignalWindow(m_pCurrentSceneGroup, m_pInputChannel);

    m_pInputChannel = NULL;
    m_pCurrentSceneGroup = NULL;
    m_pCurrentSignalWindow = NULL;

    QWidget::mouseReleaseEvent( e );
}

//拖拽事件
void BCRoomMainWidget::dragEnterEvent(QDragEnterEvent* event)
{
    bool bInputChannel = event->mimeData()->hasFormat("inputChannel");
    bool bJointInputChannel = event->mimeData()->hasFormat("jointinputChannel");
    if (bInputChannel || bJointInputChannel)
       event->accept();
    else
       event->ignore();
}

void BCRoomMainWidget::dropEvent(QDropEvent *e)
{
    if (e->mimeData()->hasFormat("inputChannel")) {
        // 可用于接收拖拽参数
        const QMimeData *mimeData = e->mimeData();
        QByteArray exData = mimeData->data("inputChannel");
        QDataStream dataStream (&exData, QIODevice::ReadOnly);
        QList<QString> lstData;

        dataStream >> lstData;

        // 拖拽数据三三成对、依次排列，分别为EchoFlag, ChannelID, chtype...
        int nInputCount = lstData.count();
        if ((nInputCount < 3) || (nInputCount%3 != 0))
            return;

        // 拖拽通道的实际个数
        nInputCount /= 3;

        // 获得全局对象
        MainWindow *pMainWindow = BCCommon::Application();

        /* 拖拽原则：
         * 1.如果拖拽到已开窗口时，替换输入信号，如果拖拽多个则替换成第一个
         * 2.开窗单元为单屏内矩形；不对已存在窗口进行处理；如果拖拽多个则从拖拽位置依次开窗
         *
         * 另：拖拽复用矩形开窗函数OpenSignalWindow；全拼窗口大小取自m_pVirtualRectItem
         */

        // 判断是否有信号窗
        m_pCurrentSignalWindow = GetSignalWindowDisplayItem( e->pos() );
        if (NULL != m_pCurrentSignalWindow) {
            // 如果拖动到信号窗，需要更换输入信号

            // 根据设备ID和通道ID返回通道对象，无论几个只返回第一个
            BCMChannel *pChannel = pMainWindow->GetInputChannel(lstData.at(2).toInt(), lstData.at(1).toInt());
            if (NULL != pChannel) {
                if (BCCommon::g_nDeviceType == 0) { // VP2000
                    // 新开窗口
                    QRect rect = m_pCurrentSignalWindow->GetFactRect();
                    AddSignalWindow(rect.left(), rect.top(), rect.width(), rect.height(), m_pCurrentSignalWindow->GetGroupDisplay(), pChannel);

                    // 关闭原有窗口
                    RemoveSignalWindowDisplayItem( m_pCurrentSignalWindow );
                } else {
                    // 判断信号窗不是级联时替换信号
                    if ( !IsJointMatrixChannel(m_pCurrentSignalWindow->GetInputChannel()->GetChannelID()) ) {
                        m_pCurrentSignalWindow->SetInputChannel( pChannel );
                        if (1 == lstData.at(0).toInt())
                            m_pCurrentSignalWindow->SetEcho( true );
                    }
                }

                RefreshLocalDlg();
            }
        } else {
            // 获取屏组
            m_pCurrentSceneGroup = GetCurrentSceneManager( e->pos() );
            // 判断数量
            if (nInputCount >= 1) {
                // 只有一个的时候满单个显示器开窗
                BCMChannel *pChannel = pMainWindow->GetInputChannel(lstData.at(2).toInt(), lstData.at(1).toInt());
                if (NULL == pChannel)
                    return;

                // 得到当前虚拟矩形框
                BCSingleDisplayVirtualWidget *pCurrentSingleDisplayRect = dynamic_cast<BCSingleDisplayVirtualWidget *>( this->childAt( e->pos() ) );
                if (NULL == pCurrentSingleDisplayRect)
                    return;

                m_pVirtualRectItem->move( pCurrentSingleDisplayRect->mapTo(this, pCurrentSingleDisplayRect->rect().topLeft()) );
                m_pVirtualRectItem->resize( pCurrentSingleDisplayRect->size() );

                // 开窗
                m_pCurrentSignalWindow = OpenSignalWindow(m_pCurrentSceneGroup, pChannel);
                if (NULL != m_pCurrentSignalWindow) {
                    if (1 == lstData.at(0).toInt())
                        m_pCurrentSignalWindow->SetEcho( true );
                }
            }
        }

        // 刷新信号窗的文字显示
        this->RefreshSignalWindowTextDisplay();
    } else if (e->mimeData()->hasFormat("jointinputChannel")) {
        // 可用于接收拖拽参数
        const QMimeData *mimeData = e->mimeData();
        QByteArray exData = mimeData->data("jointinputChannel");
        QDataStream dataStream (&exData, QIODevice::ReadOnly);
        QList<QString> lstData;

        dataStream >> lstData;

        // 拖拽数据为matrixid, matrixintputid
        if (2 != lstData.count())
            return;

        int matrixid = lstData.at( 0 ).toInt();
        int matrixInputid = lstData.at( 1 ).toInt();

        // 获得全局对象
        MainWindow *pMainWindow = BCCommon::Application();
        BCMMatrix *pMatrix = pMainWindow->GetMMatrix( matrixid );
        if (NULL != pMatrix) {
            m_pCurrentSignalWindow = GetSignalWindowDisplayItem( e->pos() );
            if (NULL != m_pCurrentSignalWindow) {
                for (int i = 0; i < pMatrix->lstOutputNode.count(); i++) {
                    sMatrixNode node = pMatrix->lstOutputNode.at( i );

                    if (node.jointWithVP4000ChannelID != m_pCurrentSignalWindow->GetInputChannel()->GetChannelID())
                        continue;

                    //pMatrix->SetSwitch(matrixInputid, node.jointWithVP4000ChannelID+1);   // 切换
                    pMatrix->SetSwitch(matrixInputid, node.id);   // 切换

                    // 修改信号源侧显示
                    MainWindow *pApplication = BCCommon::Application();
                    BCToolBar *pToolBar = pApplication->GetToolBar(MainWindow::SIGNALSOURCETOOLBAR);
                    if (NULL != pToolBar) {
                        BCFaceWidget* pFaceWidget = dynamic_cast<BCFaceWidget *>( pToolBar->widget() );
                        if (NULL != pFaceWidget) {
                            BCMatrix *pMatrixWidget = dynamic_cast<BCMatrix *>(pFaceWidget->GetWidget(MainWindow::MATRIXPANELSIGSRC));
                            if (pMatrixWidget != NULL) {
                                //pMatrixWidget->RefreshSwitch(pMatrix->id, matrixInputid, node.jointWithVP4000ChannelID+1);
                                pMatrixWidget->RefreshSwitch(pMatrix->id, matrixInputid, node.id);
                            }
                        }
                    }
                    break;
                }
            } else {
                // 获取屏组
                m_pCurrentSceneGroup = GetCurrentSceneManager( e->pos() );
                // 判断是否允许开窗，条件为找到矩阵对应的
                for (int i = 0; i < pMatrix->lstOutputNode.count(); i++) {
                    sMatrixNode node = pMatrix->lstOutputNode.at( i );
                    if (-1 == node.jointWithVP4000ChannelID)
                        continue;

                    // 根据矩阵关联通道找channel数据类
                    BCMChannel *pChannel = pMainWindow->GetInputChannel(node.jointWithVP4000ChannelID, node.jointWithVP2000ChannelType);
                    if (NULL == pChannel)
                        continue;

                    // 判断数据类关联信号窗个数，如果已经开过窗了则不允许开窗
                    if (0 != pChannel->GetSignalWindowDisplayWidgetCount())
                        continue;

                    // 得到当前虚拟矩形框
                    BCSingleDisplayVirtualWidget *pCurrentSingleDisplayRect = dynamic_cast<BCSingleDisplayVirtualWidget *>( this->childAt( e->pos() ) );
                    if (NULL == pCurrentSingleDisplayRect)
                        return;

                    m_pVirtualRectItem->move( pCurrentSingleDisplayRect->mapTo(this, pCurrentSingleDisplayRect->rect().topLeft()) );
                    m_pVirtualRectItem->resize( pCurrentSingleDisplayRect->size() );

                    // 开窗
                    //pMatrix->SetSwitch(matrixInputid, node.jointWithVP4000ChannelID+1);   // 切换
                    pMatrix->SetSwitch(matrixInputid, node.id);   // 切换

                    // 修改信号源侧显示
                    MainWindow *pApplication = BCCommon::Application();
                    BCToolBar *pToolBar = pApplication->GetToolBar(MainWindow::SIGNALSOURCETOOLBAR);
                    if (NULL != pToolBar) {
                        BCFaceWidget* pFaceWidget = dynamic_cast<BCFaceWidget *>( pToolBar->widget() );
                        if (NULL != pFaceWidget) {
                            BCMatrix *pMatrixWidget = dynamic_cast<BCMatrix *>(pFaceWidget->GetWidget(MainWindow::MATRIXPANELSIGSRC));
                            if (pMatrixWidget != NULL) {
                                //pMatrixWidget->RefreshSwitch(pMatrix->id, matrixInputid, node.jointWithVP4000ChannelID+1);
                                pMatrixWidget->RefreshSwitch(pMatrix->id, matrixInputid, node.id);
                            }
                        }
                    }

                    m_pCurrentSignalWindow = OpenSignalWindow(m_pCurrentSceneGroup, pChannel);                   // 开窗

                    break;
                }
            }
        }
    } else {
        e->ignore();
    }

    // 高亮输入通道
    if (NULL != m_pCurrentSignalWindow) {
        MainWindow *pApplication = BCCommon::Application();
        BCToolBar *pToolBar = pApplication->GetToolBar(MainWindow::SIGNALSOURCETOOLBAR);
        if (NULL != pToolBar) {
            BCFaceWidget *pSignalSourceWidget = dynamic_cast<BCFaceWidget *>( pToolBar->widget() );
            if (NULL != pSignalSourceWidget) {
                BCControl *pInputChannelWidget = dynamic_cast<BCControl *>(pSignalSourceWidget->GetWidget(MainWindow::INPUTCHANNELSSIGSRC));
                if(NULL != pInputChannelWidget)
                    pInputChannelWidget->HighLightInputChannel( m_pCurrentSignalWindow->GetInputChannel() );
            }
        }
    }

    QWidget::dropEvent( e );
}

bool BCRoomMainWidget::IsJointMatrixChannel(int chid)
{
    // 如果没有矩阵则直接返回false
    if (BCCommon::g_nIsContainsMatrix == -1)
        return false;

    MainWindow *pMainWindow = BCCommon::Application();
    QList<BCMMatrix *> lstMatrix = pMainWindow->GetMMatrix();
    for (int i = 0; i < lstMatrix.count(); i++) {
        BCMMatrix *pMatrix = lstMatrix.at( i );
        if (1 != pMatrix->jointWithVP4000)
            continue;

        for (int j = 0; j < pMatrix->lstOutputNode.count(); j++) {
            sMatrixNode node = pMatrix->lstOutputNode.at( j );
            if (chid == node.jointWithVP4000ChannelID)
                return true;
        }
    }

    return false;
}

// ---------------------------------------------------------------------------------------------
BCRoomWidget::BCRoomWidget(BCMRoom *pMRoom, QWidget *parent) : QWidget(parent)
{
    // 数据类
    m_pMainWidget   = NULL;
    m_pTopLabel     = NULL;
    m_pLeftLabel    = NULL;
    m_pBottomLabel  = NULL;
    m_pRightLabel   = NULL;

    // 创建vlayout
    QVBoxLayout *pMainLayout = new QVBoxLayout();
    pMainLayout->setContentsMargins(0, 0, 0, 0);
    pMainLayout->setMargin( 0 );
    pMainLayout->setSpacing( 0 );
    this->setLayout( pMainLayout );

    // 屏幕墙显示View，使用VLayout和HLayout组合的方式，面外设置四个Label，通过label控制居中并且按比例显示
    initWallView(pMRoom, pMainLayout);

    // 屏幕墙自定义状态栏
    m_pWidgetStatus = new QWidget();
    m_pWidgetStatus->setMaximumHeight( 45 );
    m_pWidgetStatus->setMinimumHeight( 45 );
    pMainLayout->addWidget( m_pWidgetStatus );

    // 初始化状态栏
    initStatusWidget();

    // 当前显示墙能够显示的最小尺寸
    //this->setMinimumSize(400, 300);
}

BCRoomWidget::~BCRoomWidget()
{
    // 析构中间区域
    if (NULL != m_pMainWidget) {
        delete m_pMainWidget;
        m_pMainWidget = NULL;
    }

    // 析构状态栏
    if (NULL != m_pWidgetStatus) {
        delete m_pWidgetStatus;
        m_pWidgetStatus = NULL;
    }
}

void BCRoomWidget::resizeEvent(QResizeEvent */*e*/)
{
    RefreshSegmentation();
}

void BCRoomWidget::ClearSignalWindow()
{
    BCMRoom *pRoom = m_pMainWidget->GetMRoom();

    QString ids = QString::null;
    QList<BCMGroupDisplay *> lstGroupDisplay = pRoom->GetGroupDisplay();
    for (int i = 0; i < lstGroupDisplay.count(); i++) {
        BCMGroupDisplay *pGroupDisplay = lstGroupDisplay.at(i);

        if ( ids.isEmpty() ) {
            ids = QString::number( pGroupDisplay->GetGroupDisplayID() );
        } else {
            ids = QString("%1 %2").arg(ids).arg(pGroupDisplay->GetGroupDisplayID());
        }
    }

    m_pMainWidget->ClearSignalWindow( ids );
}

void BCRoomWidget::RefreshSegmentation()
{
    QList<BCGroupDisplayWidget *> lstGroupDisplayWidget = m_pMainWidget->GetGroupDisplayWidget();
    if ( lstGroupDisplayWidget.isEmpty() )
        return;

    // 获得分组信息
    BCGroupDisplayWidget *pGroupDisplayWidget = lstGroupDisplayWidget.first();
    BCMGroupDisplay *pMGroupDisplay = pGroupDisplayWidget->GetMGroupDisplay();
    int nArrayX = pMGroupDisplay->GetArraySize().width();
    int nArrayY = pMGroupDisplay->GetArraySize().height();
    int nSegmentation = pGroupDisplayWidget->GetSegmentation();

    int r = 1;
    int c = 1;
    switch ( nSegmentation ) {
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

    // 中间尺寸必须是下面两个值的倍数
    int nMultipleX = nArrayX * c;
    int nMultipleY = nArrayY * r;

    // view 区域的尺寸
    QSize size = QSize(this->size().width(), this->size().height()-45);

    // 这里计算宽高比和全局变量做比较，如果不是标准比例则对内部屏组进行修正
    // 假设要求显示是比例显示，并且比例是16：9
    double dRatioOffset = (size.width()*1.0 / size.height()*1.0) - BCCommon::g_dWallDisplayWidthHeightRatio;
    /* 调整类型:
     * 0为不需要调整，当前view比例正好是规定比例时
     * 1为需要调整宽度，当前比例大于规定比例时证明当前高度比规定比例小，则按照当前高度调整宽度
     * -1为调整高度，情况正好和上一种相反
     * 注：double比较大小需要考虑误差，误差范围为BCCommon::g_dPermissionError
     */
    int nResizeType = 0;
    if (dRatioOffset > BCCommon::g_dPermissionError)
        nResizeType = 1;
    else if (dRatioOffset < -BCCommon::g_dPermissionError)
        nResizeType = -1;
    else
        nResizeType = 0;

    // 调整比例
    if (nResizeType == 1) {
        int dW = BCCommon::g_dWallDisplayWidthHeightRatio * size.height();   // 根据要求比例计算新的宽度
        while (dW%nMultipleX != 0) { // 宽度被6整除，可满足2或者3分割的倍数
            dW--;
        }

        int dWOffset = (size.width() - dW) * 0.5;

        m_pLeftLabel->setMaximumWidth( dWOffset );
        m_pLeftLabel->setMinimumWidth( dWOffset );
        m_pRightLabel->setMaximumWidth( dWOffset + ((size.width() - dW)%2) );   // 如果宽度不能被2整除则最后添加1像素
        m_pRightLabel->setMinimumWidth( dWOffset + ((size.width() - dW)%2) );

        // 如果高度不能被6整除则添加下边框
        int dH = size.height();
        int dOffsetH = 0;
        while (dH%nMultipleY != 0) {
            dH--;
            dOffsetH++;
        }

        m_pTopLabel->setMaximumHeight( 0 );
        m_pTopLabel->setMinimumHeight( 0 );
        m_pBottomLabel->setMaximumHeight( dOffsetH );
        m_pBottomLabel->setMinimumHeight( dOffsetH );
    }
    if (nResizeType == -1) {
        int dH = (1.0/BCCommon::g_dWallDisplayWidthHeightRatio) * size.width();   // 根据要求比例计算新的宽度
        while (dH%nMultipleY != 0) { // 高度被6整除，可满足2或者3分割的倍数
            dH--;
        }
        int dHOffset = (size.height() - dH) * 0.5;

        m_pTopLabel->setMaximumHeight( dHOffset );
        m_pTopLabel->setMinimumHeight( dHOffset );
        m_pBottomLabel->setMaximumHeight( dHOffset + ((size.height() - dH)%2) );
        m_pBottomLabel->setMinimumHeight( dHOffset + ((size.height() - dH)%2) );

        // 如果高度不能被6整除则添加下边框
        int dW = size.width();
        int dOffsetW = 0;
        while (dW%nMultipleX != 0) {
            dW--;
            dOffsetW++;
        }

        m_pLeftLabel->setMaximumWidth( 0 );
        m_pLeftLabel->setMinimumWidth( 0 );
        m_pRightLabel->setMaximumWidth( dOffsetW );
        m_pRightLabel->setMinimumWidth( dOffsetW );
    }
}

void BCRoomWidget::initWallView(BCMRoom *pMRoom, QVBoxLayout *pMainLayout)
{
    QVBoxLayout *pVLayout = new QVBoxLayout();
    pVLayout->setContentsMargins(0, 0, 0, 0);
    pVLayout->setMargin( 0 );
    pVLayout->setSpacing( 0 );

    // add top label
    m_pTopLabel = new QLabel( this );
    m_pTopLabel->setMaximumHeight( 0 );
    m_pTopLabel->setMinimumHeight( 0 );
    pVLayout->addWidget( m_pTopLabel );

    // create h layout
    QHBoxLayout *pHLayout = new QHBoxLayout();
    pHLayout->setContentsMargins(0, 0, 0, 0);
    pHLayout->setMargin( 0 );
    pHLayout->setSpacing( 0 );

    // add left label
    m_pLeftLabel = new QLabel( this );
    m_pLeftLabel->setMaximumWidth( 0 );
    m_pLeftLabel->setMinimumWidth( 0 );
    pHLayout->addWidget( m_pLeftLabel );

    // add wall view
    m_pMainWidget = new BCRoomMainWidget(pMRoom, this);
    pHLayout->addWidget( m_pMainWidget );

    // add right label
    m_pRightLabel = new QLabel( this );
    m_pRightLabel->setMaximumWidth( 0 );
    m_pRightLabel->setMinimumWidth( 0 );
    pHLayout->addWidget( m_pRightLabel );

    // v layout add h layout
    pVLayout->addLayout( pHLayout );

    // add bottom label
    m_pBottomLabel = new QLabel( this );
    m_pBottomLabel->setMaximumHeight( 0 );
    m_pBottomLabel->setMinimumHeight( 0 );
    pVLayout->addWidget( m_pBottomLabel );

    pMainLayout->addLayout( pVLayout );
}

void BCRoomWidget::initStatusWidget()
{
    if (NULL == m_pWidgetStatus)
        return;

    // 无边框和间距的layout
    QHBoxLayout *pStatusLayout = new QHBoxLayout( m_pWidgetStatus );
    pStatusLayout->setContentsMargins(0,0,20,0);

    pStatusLayout->setSpacing(0);
    m_pWidgetStatus->setLayout( pStatusLayout );

    // 状态栏内控件
    QToolButton *reduceBut = new QToolButton;
    reduceBut->setAutoRaise(true);
    reduceBut->setMaximumWidth(30);
    reduceBut->setIconSize(QSize(24,24));
    reduceBut->setIcon(QIcon(BCCommon::g_qsApplicationDefaultStylePath+"/zoomout24.png"));
    connect(reduceBut,SIGNAL(clicked(bool)),this,SLOT(onReduceSliderValue()));

    QToolButton *largenBut = new QToolButton;
    largenBut->setAutoRaise(true);
    largenBut->setMaximumWidth(30);
    largenBut->setIconSize(QSize(24,24));
    largenBut->setIcon(QIcon(BCCommon::g_qsApplicationDefaultStylePath+"/zoomin24.png"));
    connect(largenBut,SIGNAL(clicked(bool)),this,SLOT(onLargenSliderValue()));

    m_pSlider = new QSlider(Qt::Horizontal);
    m_pSlider->setMaximumWidth(100);
    m_pSlider->setTickInterval( 10 );
    m_pSlider->setStyleSheet("QSlider::groove:horizontal{\
                             height: 2px;\
                             background: qlineargradient(x1:0,y1:0, x2:0, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);\
                             margin: 2px 0;\
                             }\
                             QSlider::handle:horizontal{\
                             background: #b4b4b4;\
                             border: 1px solid #b4b4b4;\
                             width: 5px;\
                             margin: -12px 0;\
                             }");
    connect(m_pSlider, SIGNAL(valueChanged(int)), this, SLOT(onChangeViewScale(int)));

    // 添加弹簧保证控件在最右侧
//    pStatusLayout->addStretch();
//    pStatusLayout->addWidget( reduceBut );
//    pStatusLayout->addWidget( m_pSlider );
//    pStatusLayout->addWidget( largenBut );
}

void BCRoomWidget::onChangeViewScale(int v)
{
    //if (NULL == m_pMainView)
        return;

    double dStep = (BCCommon::g_dDisplayWallMaxScaleValue - 1) / 100.0;
    double dScale = 1.0+v*dStep;

    //m_pMainView->SetScale(dScale);
}

void BCRoomWidget::onReduceSliderValue()
{
    int value = m_pSlider->value();
    if(value >= m_pSlider->minimum() )
    {
        value--;
    }
    m_pSlider->setValue(value);

}

void BCRoomWidget::onLargenSliderValue()
{
    int value = m_pSlider->value();
    if(value < m_pSlider->maximum())
    {
        value++;
    }
    m_pSlider->setValue(value);
}

void BCRoomWidget::SetFloorPlanning(bool b)
{
    m_pMainWidget->SetFloorPlanning( b );
}

bool BCRoomWidget::IsFloorPlanningSwitch()
{
    return m_pMainWidget->IsFloorPlanningSwitch();
}

void BCRoomWidget::SetFloorPlanningSync()
{
    m_pMainWidget->SetFloorPlanningSync();
}
