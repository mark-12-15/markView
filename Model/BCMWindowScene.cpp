#include "BCMWindowScene.h"
#include <QtGlobal>

#include "BCMGroupScene.h"
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"
#include "../Common/BCCommunication.h"
#include "../Model/BCMRoom.h"
#include "../Model/BCMChannel.h"
#include "../Model/BCMGroupDisplay.h"
#include "../View/BCSignalWindowDisplayWidget.h"
#include "../View/BCGroupDisplayWidget.h"
#include "../View/BCRoomWidget.h"
#include "BCMMatrix.h"

BCMWindowScene::BCMWindowScene(BCMGroupScene *pGroupScene)
{
    m_pRoom = NULL;
    m_pGroupScene = pGroupScene;
    m_bIsCycled = false;
    m_nLoopInterval = 3;
}

BCMWindowScene::BCMWindowScene(BCMRoom *pRoom)
{
    m_pRoom = pRoom;
    m_pGroupScene = NULL;
    m_bIsCycled = false;
    m_nLoopInterval = 3;
}

BCMWindowScene::~BCMWindowScene()
{
    while ( !m_lstData.isEmpty() )
        delete m_lstData.takeFirst();
}

void BCMWindowScene::AddWindowSceneData(BCWindowSceneData *pData)
{
    m_lstData.append( pData );
}

bool BCMWindowScene::Save(bool bConnectServer)
{
    // 归属不可同时为空
    if ((NULL == m_pRoom) && (NULL == m_pGroupScene))
        return false;

    // 取信号窗管理类和房间尺寸
    BCMRoom *pMRoom = (NULL == m_pRoom) ? m_pGroupScene->GetRoom() : m_pRoom;

    BCRoomMainWidget *pSignalManager = pMRoom->GetSignalWidgetManager();
    if (NULL == pSignalManager)
        return false;

    QList<BCSignalWindowDisplayWidget *> lstSignalWindows = pSignalManager->GetSignalWindows();
    QListIterator<BCSignalWindowDisplayWidget *> it( lstSignalWindows );
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

        // 将场景数据添加到场景链表中
        this->AddWindowSceneData( pWindowData );
    }

    if ( !bConnectServer )
        return true;

    // 发送指令

    // 循环房间内屏组，多个屏组使用save，因为可能一个房间内多个屏组同时保存成一个场景，需要同时保存和同时调用
    QList<BCMGroupDisplay *> lstGroupDisplays = pMRoom->GetGroupDisplay();
    QListIterator<BCMGroupDisplay *> itGroupDisplay( lstGroupDisplays );
    while ( itGroupDisplay.hasNext() ) {
        BCMGroupDisplay *pGroupDisplay = itGroupDisplay.next();
        if (NULL == pGroupDisplay)
            continue;

        int nGroupDisplayID = pGroupDisplay->GetGroupDisplayID();

        // 本地或者服务器
        if ( !BCCommon::g_bConnectWithServer ) {
            BCLocalServer *pServer = BCLocalServer::Application();
            pServer->save(nGroupDisplayID, m_id);

            // 判断是否有关联矩阵，如果有需要联控
            MainWindow *pMainWindow = BCCommon::Application();
            QList<int> lstMatrixID = pMainWindow->GetRelationMatrixID( nGroupDisplayID );
            if ( !lstMatrixID.isEmpty() ) {
                for (int i = 0; i < lstMatrixID.count(); i++) {
                    int matrixID = lstMatrixID.at( i );
                    BCMMatrix *pMatrix = pMainWindow->GetMMatrix( matrixID );
                    if (NULL != pMatrix) {
                        pMatrix->Save( m_id );
                    }
                }
            }
        } else {
//            BCCommunication *pCommunication = BCCommunication::Application();
//            pCommunication->Gsave(nGroupDisplayID, m_id.toInt());
        }
    }

    // 存本地数据库
    int nGroupSceneID = (NULL == m_pGroupScene) ? 0 : m_pGroupScene->GetGroupSceneID();
    QListIterator<BCWindowSceneData *> itSceneData( m_lstData );
    while ( itSceneData.hasNext() ) {
        BCWindowSceneData *pSceneData = itSceneData.next();

        if ( !BCCommon::g_bConnectWithServer ) {
            BCLocalServer *pServer = BCLocalServer::Application();
            // 添加场景内数据到数据库
            pServer->AddSceneData(pMRoom->GetRoomID(), nGroupSceneID, m_id, pSceneData->m_nScreenGroupID,
                                  pSceneData->m_nChannelID, pSceneData->m_nChannelType, pSceneData->m_nCopyIndex, pSceneData->m_rect.left(), pSceneData->m_rect.top(),
                                  pSceneData->m_rect.width(), pSceneData->m_rect.height(), pSceneData->m_nIPVSegmentation, pSceneData->m_lstIP,
                                  "pSceneData->m_qsTitle", pSceneData->m_nWindowID);
        } else {
            // 服务器不需要进行操作
        }
    }

    return true;
}

bool BCMWindowScene::Show(bool bConnectServer)
{
    // 归属不可同时为空
    if ((NULL == m_pRoom) && (NULL == m_pGroupScene))
        return false;

    MainWindow *pApplication = BCCommon::Application();

    // 取信号窗管理类和房间尺寸
    BCMRoom *pMRoom = (NULL == m_pRoom) ? m_pGroupScene->GetRoom() : m_pRoom;
    //QSizeF wallSize = pMRoom->GetWallSize();

    // 不发送指令的清空窗口，需要房间内所有屏组的ID值，多个用空格分开
    QString qsGroupDisplayIDs;
    for (int i = 0; i < m_lstData.count(); i++) {
        BCWindowSceneData *pWindowData = m_lstData.at( i );

        QString qsGroupDisplayID( pWindowData->m_nScreenGroupID );
        if ( !qsGroupDisplayIDs.contains(qsGroupDisplayID) ) {
            qsGroupDisplayIDs.append( QString("%1 ").arg(qsGroupDisplayID) );
        }
    }

    // 清空对话框，但不发送指令
    BCRoomMainWidget *pSignalManager = pMRoom->GetSignalWidgetManager();
    pSignalManager->ClearSignalWindow(qsGroupDisplayIDs, false);

    // 循环场景内数据类
    QListIterator<BCWindowSceneData *> it( m_lstData );
    while (it.hasNext()) {
        BCWindowSceneData *pWindowData = it.next();
        if (NULL == pWindowData)
            continue;

        // 根据ID找到屏组
        BCMGroupDisplay *pMGroupDisplay = pMRoom->GetGroupDisplay( pWindowData->m_nScreenGroupID );
        if (NULL == pMGroupDisplay)
            continue;

        // 根据ID找到输入通道
        BCMChannel *pChannel = pApplication->GetInputChannel(pWindowData->m_nChannelID, pWindowData->m_nChannelType);
        if (NULL == pChannel)
            continue;

        BCRoomMainWidget *pSignalManager = pMRoom->GetSignalWidgetManager();
        BCSignalWindowDisplayWidget *pSignalWindowItem = pSignalManager->AddSignalWindow(pWindowData->m_rect.left(),
                                                                                         pWindowData->m_rect.top(),
                                                                                         pWindowData->m_rect.width(),
                                                                                         pWindowData->m_rect.height(),
                                                                                         pMGroupDisplay->GetDisplayWidgetManager(), pChannel, pWindowData->m_nWindowID, false);
        if (NULL != pSignalWindowItem) {
            pSignalWindowItem->SetCopyIndex( pWindowData->m_nCopyIndex );
            if (NULL != pSignalWindowItem) {
                if (9 == pChannel->GetSignalSource()) {
                    pSignalWindowItem->SetIPVedioSegmentationCount(pWindowData->m_nIPVSegmentation);
                    pSignalWindowItem->SetIPVIP( pWindowData->m_lstIP );
                }
            }
        }
    }

    // 全局刷新下信号窗文字显示，因为信号窗先构造，后加入链表，而构造时调用resize，所以最后一个信号窗文字不会被刷新，需要手动调用一次
    pSignalManager->RefreshSignalWindowTextDisplay();

    // 发送指令
    if ( !bConnectServer )
        return true;

    // 循环房间内屏组，多个屏组使用load，因为可能一个房间内多个屏组同时保存成一个场景，需要同时保存和同时调用
    QList<BCMGroupDisplay *> lstGroupDisplays = pMRoom->GetGroupDisplay();
    QListIterator<BCMGroupDisplay *> itGroupDisplay( lstGroupDisplays );
    while ( itGroupDisplay.hasNext() ) {
        BCMGroupDisplay *pGroupDisplay = itGroupDisplay.next();
        if (NULL == pGroupDisplay)
            continue;

        int nGroupDisplayID = pGroupDisplay->GetGroupDisplayID();

        if ( !BCCommon::g_bConnectWithServer ) {
            BCLocalServer *pServer = BCLocalServer::Application();
            pServer->load(nGroupDisplayID, m_id);

            // 判断是否有关联矩阵，如果有需要联控
            MainWindow *pMainWindow = BCCommon::Application();
            QList<int> lstMatrixID = pMainWindow->GetRelationMatrixID( nGroupDisplayID );
            if ( !lstMatrixID.isEmpty() ) {
                for (int i = 0; i < lstMatrixID.count(); i++) {
                    int matrixID = lstMatrixID.at( i );
                    BCMMatrix *pMatrix = pMainWindow->GetMMatrix( matrixID );
                    if (NULL != pMatrix) {
                        pMatrix->Load( m_id );
                    }
                }
            }
        } else {
            // 服务器不做处理
            BCCommunication *pCommunication = BCCommunication::Application();
            pCommunication->RequestLoadWindowScene(nGroupDisplayID, m_id);
        }
    }

    return true;
}

bool BCMWindowScene::Update()
{
    this->Clear();
    return this->Save();
}

void BCMWindowScene::Clear(bool bConnectServer)
{
    while ( !m_lstData.isEmpty() )
        delete m_lstData.takeFirst();

    // 如果不通信则直接返回
    if ( !bConnectServer )
        return;

    // 删除原数据
    BCMRoom *pMRoom = (NULL == m_pRoom) ? m_pGroupScene->GetRoom() : m_pRoom;
    int nGroupSceneID = (NULL == m_pGroupScene) ? 0 : m_pGroupScene->GetGroupSceneID();

    if ( !BCCommon::g_bConnectWithServer ) {
        BCLocalServer *pServer = BCLocalServer::Application();
        pServer->RemoveSceneData(pMRoom->GetRoomID(), nGroupSceneID, m_id);
    } else {
        // 服务器不需要做操作
    }
}

void BCMWindowScene::SetWindowSceneName(const QString &qs, bool bSave)
{
    m_name = qs;

    if ( bSave ) {
        if ( !BCCommon::g_bConnectWithServer ) {
            // 本地数据库
            BCLocalServer *pServer = BCLocalServer::Application();

            // 更新数据
            if (NULL != m_pGroupScene) {
                pServer->UpdateScene(m_id,
                                     m_pGroupScene->GetRoom()->GetRoomID(),
                                     m_pGroupScene->GetGroupSceneID(),
                                     m_bIsCycled ? 1 : 0,
                                     m_name,
                                     m_nLoopInterval);
            }
        } else {
            // 服务器不需要做操作
        }
    }
}

void BCMWindowScene::SetWindowSceneLoopInterval(int interval, bool bSave)
{
    m_nLoopInterval = interval;

    if ( bSave ) {
        if ( !BCCommon::g_bConnectWithServer ) {
            // 本地数据库
            BCLocalServer *pServer = BCLocalServer::Application();

            // 更新数据
            if (NULL != m_pGroupScene) {
                pServer->UpdateScene(m_id,
                                     m_pGroupScene->GetRoom()->GetRoomID(),
                                     m_pGroupScene->GetGroupSceneID(),
                                     m_bIsCycled ? 1 : 0,
                                     m_name,
                                     m_nLoopInterval);
            }
        } else {
            // 服务器不需要做操作
        }
    }
}

void BCMWindowScene::SetIsCycled(bool b, bool bSave)
{
    m_bIsCycled = b;

    if ( bSave ) {
        if ( !BCCommon::g_bConnectWithServer ) {
            // 本地数据库
            BCLocalServer *pServer = BCLocalServer::Application();

            // 更新数据
            if (NULL != m_pGroupScene) {
                pServer->UpdateScene(m_id,
                                     m_pGroupScene->GetRoom()->GetRoomID(),
                                     m_pGroupScene->GetGroupSceneID(),
                                     m_bIsCycled ? 1 : 0,
                                     m_name,
                                     m_nLoopInterval);
            }
        } else {
            // 服务器不需要做操作
        }
    }
}
