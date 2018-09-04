#include "BCSceneTreeWidget.h"

#include <QDebug>
#include <QMessageBox>
#include "../View/BCScene.h"
#include "../View/BCToolBar.h"
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"
#include "../Common/BCCommunication.h"
#include "../Model/BCMRoom.h"
#include "../Model/BCMWindowScene.h"
#include "../Model/BCMGroupScene.h"
#include "../Model/BCMGroupDisplay.h"
#include "../Model/BCMChannel.h"
#include "BCRibbonMainToolBar.h"
#include "BCRibbonMainToolBarAction.h"
#include "BCSceneTreeWidgetItem.h"
#include "BCScreenDlg.h"
#include "BCScreenTimeDlg.h"
#include "BCScreenName.h"
#include "BCSignalWindowDisplayItem.h"
#include "BCSignalWindowBodySubDisplayItem.h"
#include "BCDisplayItemManager.h"
#include "../View/BCRoomWidget.h"
#include "../View/BCGroupDisplayWidget.h"
#include "../View/BCSignalWindowDisplayWidget.h"

BCSceneTreeWidget::BCSceneTreeWidget(QWidget *parent)
    :QTreeWidget(parent)
{
    m_pSceneWidget = NULL;
    m_pSystemplay = NULL;

    // 增加多选操作 ctrl和shift
    this->setSelectionMode(QAbstractItemView::ExtendedSelection);
    this->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->setHeaderHidden(true);

    // 连接信号槽
    connect(this,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(onItemDoubleClicked(QTreeWidgetItem*,int)));
}

BCSceneTreeWidget::~BCSceneTreeWidget(){

}


void BCSceneTreeWidget::Refresh()
{
    // 取当前房间
    MainWindow *pMainWindow = BCCommon::Application();
    BCMRoom *pRoom = pMainWindow->GetCurrentSceneMRoom();
    if (NULL == pRoom)
        return;

    // 清空数据
    this->clear();

    // 循环添加场景组
    BCMGroupScene *pGroupScene = pRoom->GetGroupScene( 0 );
    if (NULL == pGroupScene)
        return;

    // 循环添加场景
    QList<BCMWindowScene *> lstWindowScene = pGroupScene->GetWindowScenes();
    for(int j = 0; j < lstWindowScene.count(); j++) {
        BCMWindowScene *pWindowScene = lstWindowScene.at(j);

        BCSceneTreeWidgetItem *pWindowSceneItem = new BCSceneTreeWidgetItem(pWindowScene, this);
        this->addTopLevelItem( pWindowSceneItem );
    }

    // 展开显示
    this->expandAll();
}

void BCSceneTreeWidget::onItemDoubleClicked(QTreeWidgetItem *pItem, int)
{
    // 强转当前点击item
    BCSceneTreeWidgetItem *pGroupSceneItem = dynamic_cast<BCSceneTreeWidgetItem *>( pItem );
    if (NULL == pGroupSceneItem)
        return;

    // 显示当前场景
    BCMWindowScene *pWindowScene = pGroupSceneItem->GetWindowScene();
    if (NULL != pWindowScene) {
        if ( !BCCommon::g_bConnectWithServer ) {
            pWindowScene->Show();
        } else {
            BCCommunication *pCommunication = BCCommunication::Application();
            pCommunication->RequestLoadWindowScene(pWindowScene->GetGroupScene()->GetRoom()->GetRoomID(),
                                                   pWindowScene->GetWindowSceneID());
        }
    }
}

/* 对外开放接口
 *  0：轮巡
 *  1：添加场景
 *  2：删除场景
 *  3：更新场景
 *  4：场景设置
 *  5：修改名称
 *  6：清空场景
 */
bool BCSceneTreeWidget::SetAction(int type)
{
    int nSelectItemCount = selectedItems().count();
    switch ( type ) {
    case 1: {   // 添加场景，只有选中场景组时才生效
        AddWindowScene( NULL );
    }
        break;
    case 2: {   // 删除场景
        DeleteWindowScene( selectedItems() );
    }
        break;
    case 3: {   // 更新场景，只有选中一个场景时生效
        if (nSelectItemCount != 1)
            return false;

        BCSceneTreeWidgetItem *pGroupSceneItem = dynamic_cast<BCSceneTreeWidgetItem *>( selectedItems().first() );
        if (NULL == pGroupSceneItem)
            return false;

        UpdateWindowScene( pGroupSceneItem );
    }
        break;
    case 4: {   // 场景设置，只有选中场景组时才生效
        SetLoopTime();
    }
        break;
    case 5: {   // 修改名称
        if (nSelectItemCount != 1)
            return false;

        BCSceneTreeWidgetItem *pGroupSceneItem = dynamic_cast<BCSceneTreeWidgetItem *>( selectedItems().first() );
        if (NULL == pGroupSceneItem)
            return false;

        ModifyGroupSceneName( pGroupSceneItem );
    }
        break;
    default:
        break;
    }

    return true;
}

void BCSceneTreeWidget::ModifyGroupSceneName(BCSceneTreeWidgetItem *pGroupSceneItem)
{
    // 获得名称
    BCMWindowScene *pWindowScene = pGroupSceneItem->GetWindowScene();
    QString qsName = pWindowScene->GetWindowSceneName();

    // 显示修改对话框并重新设置名称
    BCScreenName dlg(qsName, this);
    if(dlg.exec() == QDialog::Accepted){
        qsName = dlg.name;

        if ( !BCCommon::g_bConnectWithServer ) {
            pWindowScene->SetWindowSceneName(qsName);
            pGroupSceneItem->setText(0, qsName);
        } else {
            BCCommunication *pCommunication = BCCommunication::Application();
            pCommunication->RequestUpdateWindowScene(pWindowScene->GetWindowSceneID(), pWindowScene->GetGroupScene()->GetRoom()->GetRoomID(),
                                                     pWindowScene->GetGroupScene()->GetGroupSceneID(), pWindowScene->IsCycled() ? 1 : 0, qsName);
        }
    }
}

bool BCSceneTreeWidget::SetLoopAction(bool &b)
{
    MainWindow *pMainWindow = BCCommon::Application();
    BCMRoom *pRoom = pMainWindow->GetCurrentMRoom();
    if (NULL == pRoom)
        return false;

    BCMGroupScene *pGroupScene = pRoom->GetGroupScene( 0 );
    if (NULL == pGroupScene)
        return false;

    pGroupScene->SetLoopWindowScene( !pGroupScene->IsLoopWindowScene() );

    // 记录是否轮巡，开启轮巡为1，关闭为0
    b = pGroupScene->IsLoopWindowScene();

    return true;
}

void BCSceneTreeWidget::SetLoopTime(int value)
{
    MainWindow *pMainWindow = BCCommon::Application();
    BCMRoom *pRoom = pMainWindow->GetCurrentMRoom();
    if (NULL == pRoom)
        return;

    BCMGroupScene *pGroupScene = pRoom->GetGroupScene( 0 );
    if (NULL == pGroupScene)
        return;

    pGroupScene->SetLoopWindowSceneInterval( value );
}

void BCSceneTreeWidget::mouseMoveEvent(QMouseEvent */*event*/)
{
    // 防止鼠标点中一个拖拽时选中多个
}

/*  右键菜单说明
 *  空白:
 *      1.添加场景组
 *      2.清空场景组
 *  单选:
 *      1.场景组:
 *              1.添加场景
 *              2.修改名称
 *              3.设置轮巡时间
 *              4.打开轮巡(先关闭其他的轮巡开关，刷新界面按钮显示)
 *              5.关闭轮巡
 *      2.场景
 *              1.预览场景
 *              2.删除场景
 *              3.修改名称
 *              4.添加轮巡
 *              5.移除轮巡
 *  多选(只对场景生效，如其中有场景组数据则不显示):
 *      1.删除场景
 *      2.添加多个场景轮巡
 *      3.移除多个场景轮巡
 */
void BCSceneTreeWidget::contextMenuEvent(QContextMenuEvent* /*event*/)
{
    QMenu menu;
    QAction *pClearWindowScene = NULL;

    QAction *pAddWindowScene = NULL;
    QAction *pModifyGroupSceneName = NULL;
    QAction *pLoopSceneInterval = NULL;

    QAction *pPreviewWindowScene = NULL;
    QAction *pUpdateWindowScene = NULL;
    QAction *pDelWindowScene = NULL;        // 和批量删除共用
    QAction *pModifyWindowSceneName = NULL;
    QAction *pAddLoop = NULL;               // 和批量添加轮巡共用
    QAction *pRemoveLoop = NULL;            // 和批量清除轮巡共用

    QAction *pMoveToTop = NULL;
    QAction *pMoveToBottom = NULL;
    QAction *pMoveToUp = NULL;
    QAction *pMoveToDown = NULL;

    // 数据类
    BCSceneTreeWidgetItem *pGroupSceneItem = NULL;

    // 根据选中item的数量判断显示哪种菜单
    int nSelectItemCount = selectedItems().count();
    switch ( nSelectItemCount ) {
    case 0: {   // 空白
        pAddWindowScene = menu.addAction(tr("添加场景"));
        pClearWindowScene = menu.addAction(tr("清空场景"));
    }
        break;
    case 1: {   // 单选
        // 场景
        pPreviewWindowScene = menu.addAction(tr("预览场景"));
        pUpdateWindowScene = menu.addAction(tr("更新场景"));
        pDelWindowScene = menu.addAction(tr("删除场景"));
        pModifyWindowSceneName = menu.addAction(tr("修改名称"));
        menu.addSeparator();
        pLoopSceneInterval = menu.addAction(tr("设置轮巡时间"));
        pAddLoop = menu.addAction(tr("添加轮巡"));
        pRemoveLoop = menu.addAction(tr("移除轮巡"));
        menu.addSeparator();
        pMoveToUp = menu.addAction(tr("上移"));
        pMoveToDown = menu.addAction(tr("下移"));
        pMoveToTop = menu.addAction(tr("置顶"));
        pMoveToBottom = menu.addAction(tr("置底"));

        // 勾选轮巡标识
        pGroupSceneItem = dynamic_cast<BCSceneTreeWidgetItem *>( selectedItems().first() );
        if (NULL != pGroupSceneItem) {
            BCMWindowScene *pWindowScene = pGroupSceneItem->GetWindowScene();
            if (NULL != pWindowScene) {
                pAddLoop->setCheckable( true );
                pRemoveLoop->setCheckable( true );

                pAddLoop->setChecked( pWindowScene->IsCycled() );
                pRemoveLoop->setChecked( !pWindowScene->IsCycled() );
            }
        }
    }
        break;
    default: {  // 多选
        pDelWindowScene = menu.addAction(tr("删除场景"));
        menu.addSeparator();
        pAddLoop = menu.addAction(tr("批量添加轮巡"));
        pRemoveLoop = menu.addAction(tr("批量移除轮巡"));
    }
        break;
    }

    // 显示菜单
    QAction *pSelectAction = menu.exec(QCursor::pos());
    if (NULL == pSelectAction)
        return;

    MainWindow *pMainWindow = BCCommon::Application();
    BCMRoom *pRoom = pMainWindow->GetCurrentSceneMRoom();
    if (NULL == pRoom)
        return;

    // 清空场景
    if (pClearWindowScene == pSelectAction) {
        ClearWindowScene( pRoom );
    }
    // 添加场景
    if (pAddWindowScene == pSelectAction) {
        AddWindowScene( pGroupSceneItem );
    }
    // 修改场景组名称
    if (pModifyWindowSceneName == pSelectAction) {
        ModifyGroupSceneName( pGroupSceneItem );
    }
    // 预览场景
    if (pPreviewWindowScene == pSelectAction) {
        PreviewWindowScene( pGroupSceneItem );
    }
    // 更新场景
    if (pUpdateWindowScene == pSelectAction) {
        UpdateWindowScene( pGroupSceneItem );
    }
    // 删除场景
    if (pDelWindowScene == pSelectAction) {
        DeleteWindowScene( selectedItems() );
    }
    // 添加轮巡
    if (pAddLoop == pSelectAction) {
        SetLoopWindowScene(true);
    }
    // 移除轮巡
    if (pRemoveLoop == pSelectAction) {
        SetLoopWindowScene(false);
    }
    // 设置场景轮巡时间
    if (pLoopSceneInterval == pSelectAction) {
        ModifySceneLoopInterval( pGroupSceneItem );
    }
    // 在屏组内移动场景
    if (pMoveToTop == pSelectAction) {
        MoveWindowScene( 3 );
    }
    if (pMoveToBottom == pSelectAction) {
        MoveWindowScene( 4 );
    }
    if (pMoveToUp == pSelectAction) {
        MoveWindowScene( 1 );
    }
    if (pMoveToDown == pSelectAction) {
        MoveWindowScene( 2 );
    }
}

void BCSceneTreeWidget::ModifySceneLoopInterval(BCSceneTreeWidgetItem *pSceneItem)
{
    if (NULL == pSceneItem)
        return;

    BCMWindowScene *pWindowScene = pSceneItem->GetWindowScene();
    int nLoopTime = pWindowScene->GetWindowSceneLoopInterval();

    BCScreenTimeDlg *pDlg = new BCScreenTimeDlg(nLoopTime, this);
    if(pDlg->exec() == QDialog::Accepted){
        nLoopTime = pDlg->GetNum();

        // 设置数据轮巡时间
        pSceneItem->SetLoopInterval( nLoopTime );
    }
}

// type标识移动类型，1：上移 2：下移 3：置顶 4：置底
void BCSceneTreeWidget::MoveWindowScene(int type)
{
    BCSceneTreeWidgetItem *pSceneItem = dynamic_cast<BCSceneTreeWidgetItem *>( selectedItems().first() );
    if (NULL == pSceneItem)
        return;

    BCMWindowScene *pWindowScene = pSceneItem->GetWindowScene();
    int sceneid = pWindowScene->GetWindowSceneID();
    BCMGroupScene *pGroupScene = pWindowScene->GetGroupScene();
    if (NULL != pGroupScene) {
        switch ( type ) {
        case 1:
            pGroupScene->MoveToUp( pWindowScene );
            break;
        case 2:
            pGroupScene->MoveToDown( pWindowScene );
            break;
        case 3:
            pGroupScene->MoveToTop( pWindowScene );
            break;
        case 4:
            pGroupScene->MoveToBottom( pWindowScene );
            break;
        default:
            break;
        }
    }

    this->Refresh();

    // 需要设置场景的选中状态，因为可能连续点击上移 下移
    // 只做非组场景
    for (int i = 0; i < this->topLevelItemCount(); i++) {
        BCSceneTreeWidgetItem *pSceneItem = dynamic_cast<BCSceneTreeWidgetItem *>( this->topLevelItem( i ) );
        if (NULL == pSceneItem)
            continue;

        BCMWindowScene *pWindowScene = pSceneItem->GetWindowScene();
        if (sceneid != pWindowScene->GetWindowSceneID())
            continue;

        this->setCurrentItem( pSceneItem );
        break;
    }
}

void BCSceneTreeWidget::ClearWindowScene(BCMRoom *pRoom)
{
    if (NULL == pRoom)
        return;

    BCMGroupScene *pGroupScene = pRoom->GetGroupScene( 0 );
    if (NULL == pGroupScene)
        return;

    pGroupScene->ClearWindowScene();
    this->clear();
}

void BCSceneTreeWidget::AddWindowScene(BCSceneTreeWidgetItem *pGroupSceneItem)
{
    // 取当前房间
    MainWindow *pMainWindow = BCCommon::Application();
    BCMRoom *pRoom = pMainWindow->GetCurrentSceneMRoom();
    if (NULL == pRoom)
        return;

    BCMGroupScene *pGroupScene = pRoom->GetGroupScene( 0 );
    if (NULL == pGroupScene)
        return;

    BCScreenDlg *pDlg = new BCScreenDlg(pGroupScene, this);
    if(pDlg->exec() == QDialog::Accepted) {
        BCMWindowScene *pWindowScene = pDlg->GetWindowScene();
        pWindowScene->Save( !BCCommon::g_bConnectWithServer );

        if ( !BCCommon::g_bConnectWithServer ) {
            m_pSceneWidget->Refresh();
        } else {
            // 构造场景数据
            sWindowScene swindowscene;
            swindowscene.id = pWindowScene->GetWindowSceneID();
            swindowscene.cycle = pWindowScene->IsCycled() ? 1 : 0;
            swindowscene.name = pWindowScene->GetWindowSceneName();

            QList<BCWindowSceneData *> lstWindowSceneData = pWindowScene->GetWindowSceneData();
            for (int i = 0; i < lstWindowSceneData.count(); i++) {
                BCWindowSceneData *pWindowSceneData = lstWindowSceneData.at( i );

                sWindowSceneData swindowscenedata;
                swindowscenedata.chid = pWindowSceneData->m_nChannelID;
                swindowscenedata.chtype = pWindowSceneData->m_nChannelType;
                swindowscenedata.winid = pWindowSceneData->m_nWindowID;
                swindowscenedata.copyIndex = pWindowSceneData->m_nCopyIndex;
                swindowscenedata.groupdisplayid = pWindowSceneData->m_nScreenGroupID;
                swindowscenedata.left = pWindowSceneData->m_rect.left();
                swindowscenedata.top = pWindowSceneData->m_rect.top();
                swindowscenedata.width = pWindowSceneData->m_rect.width();
                swindowscenedata.height = pWindowSceneData->m_rect.height();
                swindowscenedata.ipvSegmentation = pWindowSceneData->m_nIPVSegmentation;
                swindowscenedata.lstIP << pWindowSceneData->m_lstIP;

                swindowscene.lstData.append( swindowscenedata );
            }

            pGroupScene->RemoveWindowScene( pWindowScene->GetWindowSceneID() );

            BCCommunication *pCommunication = BCCommunication::Application();
            pCommunication->RequestAddWindowScene(swindowscene, pGroupScene->GetRoom()->GetRoomID(), pGroupScene->GetGroupSceneID());
        }
    }

    this->expandAll();
}

void BCSceneTreeWidget::SetLoopTime()
{
    // 取当前房间
    MainWindow *pMainWindow = BCCommon::Application();
    BCMRoom *pRoom = pMainWindow->GetCurrentMRoom();
    if (NULL == pRoom)
        return;

    BCMGroupScene *pGroupScene = pRoom->GetGroupScene( 0 );
    if (NULL == pGroupScene)
        return;

    int nLoopTime = pGroupScene->GetLoopWindowSceneInterval();

    // 弹出设置轮巡时间对话框
    BCScreenTimeDlg *pDlg = new BCScreenTimeDlg(nLoopTime, this);
    if(pDlg->exec() == QDialog::Accepted){
        nLoopTime = pDlg->GetNum();

        // 设置数据轮巡时间
        pGroupScene->SetLoopWindowSceneInterval( nLoopTime );
        // 界面跟着刷新
        if (NULL != m_pSceneWidget) {
            m_pSceneWidget->SetLoopTime(nLoopTime);
        }
    }
}

void BCSceneTreeWidget::PreviewWindowScene(BCSceneTreeWidgetItem *pWindowSceneItem)
{
    if (NULL == pWindowSceneItem)
        return;

    pWindowSceneItem->GetWindowScene()->Show();
}

void BCSceneTreeWidget::UpdateWindowScene(BCSceneTreeWidgetItem *pWindowSceneItem)
{
    if ( !BCCommon::g_bConnectWithServer ) {
        pWindowSceneItem->GetWindowScene()->Update();
    } else {
        BCMWindowScene *pWindowScene = pWindowSceneItem->GetWindowScene();
        if (NULL == pWindowScene)
            return;

        BCMGroupScene *pGroupScene = pWindowScene->GetGroupScene();
        if (NULL == pGroupScene)
            return;

        // 取信号窗管理类和房间尺寸
        BCMRoom *pMRoom = pGroupScene->GetRoom();
        if (NULL == pMRoom)
            return;

        sWindowScene swindowscene;
        swindowscene.id = pWindowScene->GetWindowSceneID();
        swindowscene.cycle = pWindowScene->IsCycled() ? 1 : 0;
        swindowscene.name = pWindowScene->GetWindowSceneName();

        if ( BCCommon::g_bSignalWindowByWidget ) {
            BCRoomMainWidget *pSignalManager = pMRoom->GetSignalWidgetManager();
            if (NULL == pSignalManager)
                return;

            // 循环所有信号窗，并将其转化成数据添加到场景中
            QList<BCSignalWindowDisplayWidget *> lstSignalWindows = pSignalManager->GetSignalWindows();
            for (int i = 0; i < lstSignalWindows.count(); i++) {
                BCSignalWindowDisplayWidget *pSignalWindow = lstSignalWindows.at( i );
                if (NULL == pSignalWindow)
                    continue;

                BCMChannel *pChannel = pSignalWindow->GetInputChannel();

                QRect rect = pSignalWindow->GetFactRect();

                sWindowSceneData swindowscenedata;
                swindowscenedata.groupdisplayid = pSignalWindow->GetGroupDisplay()->GetMGroupDisplay()->GetGroupDisplayID();
                swindowscenedata.chid = pChannel->GetChannelID();
                swindowscenedata.chtype = pChannel->GetChannelType();
                swindowscenedata.winid = pSignalWindow->GetWindowID();
                swindowscenedata.copyIndex = pSignalWindow->GetCopyIndex();
                swindowscenedata.left = rect.left();
                swindowscenedata.top = rect.top();
                swindowscenedata.width = rect.width();
                swindowscenedata.height = rect.height();
                swindowscenedata.ipvSegmentation = (9 == pChannel->GetSignalSource()) ? pSignalWindow->GetIPVedioSegmentationCount() : -1;

                QList<BCSignalWindowIPVWidget *> lstSubDisplayItem = pSignalWindow->GetSubDisplayItem();
                if (36 == lstSubDisplayItem.count()) {
                    for (int i = 0; i < lstSubDisplayItem.count(); i++) {
                        BCSignalWindowIPVWidget *pSubDisplayItem = lstSubDisplayItem.at( i );
                        swindowscenedata.lstIP.append( pSubDisplayItem->m_qsUrl );
                    }
                }

                if (swindowscenedata.lstIP.count() != 36) {
                    swindowscenedata.lstIP.clear();

                    for (int i = 0; i < 36; i++) {
                        swindowscenedata.lstIP.append( QString::null );
                    }
                }

                swindowscene.lstData.append( swindowscenedata );
            }
        } else {
            BCDisplayItemManager *pSignalManager = pMRoom->GetSignalItemManager();
            if (NULL == pSignalManager)
                return;

            // 循环所有信号窗，并将其转化成数据添加到场景中
            QList<BCSignalWindowDisplayItem *> lstSignalWindows = pSignalManager->GetSignalWindows();
            for (int i = 0; i < lstSignalWindows.count(); i++) {
                BCSignalWindowDisplayItem *pSignalWindow = lstSignalWindows.at( i );
                if (NULL == pSignalWindow)
                    continue;

                // 根据显示墙实际尺寸计算信号窗实际尺寸
                BCDisplayItemManager *pGroupDisplay = pSignalWindow->GetGroupDisplay();
                if (NULL == pGroupDisplay)
                    continue;

                BCMChannel *pChannel = pSignalWindow->GetInputChannel();

                QRectF rect = pGroupDisplay->GetSignalWindowFactSize( pSignalWindow );

                sWindowSceneData swindowscenedata;
                swindowscenedata.groupdisplayid = pSignalWindow->GetGroupDisplay()->GetMGroupDisplay()->GetGroupDisplayID();
                swindowscenedata.chid = pChannel->GetChannelID();
                swindowscenedata.chtype = pChannel->GetChannelType();
                swindowscenedata.winid = pSignalWindow->GetWindowID();
                swindowscenedata.copyIndex = pSignalWindow->GetCopyIndex();
                swindowscenedata.left = rect.left();
                swindowscenedata.top = rect.top();
                swindowscenedata.width = rect.width();
                swindowscenedata.height = rect.height();
                swindowscenedata.ipvSegmentation = (9 == pChannel->GetSignalSource()) ? pSignalWindow->GetIPVedioSegmentationCount() : -1;

                QList<BCSignalWindowBodySubDisplayItem *> lstSubDisplayItem = pSignalWindow->GetSubDisplayItem();
                if (36 == lstSubDisplayItem.count()) {
                    for (int i = 0; i < lstSubDisplayItem.count(); i++) {
                        BCSignalWindowBodySubDisplayItem *pSubDisplayItem = lstSubDisplayItem.at( i );
                        swindowscenedata.lstIP.append( pSubDisplayItem->m_qsUrl );
                    }
                }

                if (swindowscenedata.lstIP.count() != 36) {
                    swindowscenedata.lstIP.clear();

                    for (int i = 0; i < 36; i++) {
                        swindowscenedata.lstIP.append( QString::null );
                    }
                }

                swindowscene.lstData.append( swindowscenedata );
            }
        }

        // 当连接服务器时需要等待异步调用
        BCCommunication *pCommunication = BCCommunication::Application();
        pCommunication->RequestUpdateWindowScene(swindowscene, pMRoom->GetRoomID(), pGroupScene->GetGroupSceneID());
    }
}

void BCSceneTreeWidget::DeleteWindowScene(QList<QTreeWidgetItem*> lstItems)
{
    QListIterator<QTreeWidgetItem*> it( lstItems );
    while ( it.hasNext() ) {
        BCSceneTreeWidgetItem *pWindowSceneItem = dynamic_cast<BCSceneTreeWidgetItem *>( it.next() );
        if (NULL == pWindowSceneItem)
            continue;

        BCMWindowScene *pWindowScene = pWindowSceneItem->GetWindowScene();
        BCMGroupScene *pGroupScene = pWindowScene->GetGroupScene();
        if (NULL == pGroupScene)
            return;

        if ( !BCCommon::g_bConnectWithServer ) {
            pGroupScene->DeleteWindowScene( pWindowScene );
            this->takeTopLevelItem( this->indexOfTopLevelItem(pWindowSceneItem) );

            delete pWindowSceneItem;
            pWindowSceneItem = NULL;
        } else {
            // 当连接服务器时需要等待异步调用
            BCCommunication *pCommunication = BCCommunication::Application();
            pCommunication->RequestDeleteWindowScene(pWindowScene->GetWindowSceneID(), pGroupScene->GetRoom()->GetRoomID(), pGroupScene->GetGroupSceneID());
        }
    }
}

void BCSceneTreeWidget::SetLoopWindowScene(bool b)
{
    QListIterator<QTreeWidgetItem*> it( selectedItems() );
    while ( it.hasNext() ) {
        BCSceneTreeWidgetItem *pWindowSceneItem = dynamic_cast<BCSceneTreeWidgetItem *>( it.next() );
        if (NULL == pWindowSceneItem)
            continue;

        if ( !BCCommon::g_bConnectWithServer ) {
            // 修改轮巡
            pWindowSceneItem->SetLoopWindowScene( b );
        } else {
            BCMWindowScene *pWindowScene = pWindowSceneItem->GetWindowScene();
            if (NULL == pWindowScene)
                return;

            // 当连接服务器时需要等待异步调用
            BCCommunication *pCommunication = BCCommunication::Application();
            pCommunication->RequestUpdateWindowScene(pWindowScene->GetWindowSceneID(),
                                                     pWindowScene->GetGroupScene()->GetRoom()->GetRoomID(),
                                                     pWindowScene->GetGroupScene()->GetGroupSceneID(),
                                                     b ? 1 : 0,
                                                     pWindowScene->GetWindowSceneName());
        }
    }
}
