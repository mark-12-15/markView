#include "BCMChannel.h"
#include "../Common/BCLocalServer.h"
#include "../Common/BCCommunication.h"
#include "../Common/BCCommon.h"
#include "BCMSubTitlesScene.h"
#include "../View/BCGroupDisplayWidget.h"
#include "../View/BCSignalWindowDisplayWidget.h"
#include "BCMGroupDisplay.h"
#include <QUdpSocket>

BCMChannel::BCMChannel(int id)
{
    m_id = id;
    m_bIsEnable = true;
    m_resolution = QSize(1920, 1080);
    m_nBoardCardID = 0;
    m_nBoardCardPos = 0;
    m_pRemoteSocket = NULL;
    m_nAudoFlag = 0;
    m_nEnableEcho = 0;

    m_pSubTitles = new BCMSubTitlesSceneData();
}

BCMChannel::~BCMChannel()
{
    // 只对链表做清空处理，数据不在此处析构
    m_mapLastRect.clear();
    m_mapCustomName.clear();

    if (NULL != m_pRemoteSocket) {
        m_pRemoteSocket->disconnectFromHost();
        m_pRemoteSocket->deleteLater();
    }
}

void BCMChannel::SetRemoteIP(const QString &ip, bool bSave)
{
    m_qsRemoteIP = ip;
    if (NULL == m_pRemoteSocket)
        m_pRemoteSocket = new QUdpSocket();

    if ( !bSave )
        return;

    // save to db
    if ( !BCCommon::g_bConnectWithServer ) {
        BCLocalServer *pServer = BCLocalServer::Application();
        pServer->UpdateInputChannelRemoteIP(m_nChanneltype, m_id, m_qsRemoteIP);
    }
}

void BCMChannel::SetSubTitlePower(int i, bool bSendCmd)
{
    m_pSubTitles->m_nVisible = i;

    if ( !bSendCmd )
        return;

    // 刷新所有信号窗的显示状态
    QListIterator<BCSignalWindowDisplayWidget *> it( m_lstSignalDisplayWidget );
    while ( it.hasNext() ) {
        BCSignalWindowDisplayWidget *pSignalWidget = it.next();
        pSignalWidget->RefreshSubTitle();
    }

    // save to db
    if ( !BCCommon::g_bConnectWithServer ) {
        BCLocalServer *pServer = BCLocalServer::Application();
        pServer->UpdateInputChannelSubTitlePower(m_nChanneltype, m_id, i);
    }
}

void BCMChannel::SendRemoteCmd(const QString &cmd)
{
    if (NULL != m_pRemoteSocket) {
        m_pRemoteSocket->writeDatagram(cmd.toLatin1(), QHostAddress(m_qsRemoteIP), 8811);
        m_pRemoteSocket->flush();
    }
}

void BCMChannel::SetChannelName(const QString &qs, bool bSendCmd)
{
    m_name = qs;

    if ( bSendCmd ) {
        MainWindow *pMainWindow = BCCommon::Application();
        BCSUser *pCurrentUser = pMainWindow->GetCurrentUser();
        if (NULL == pCurrentUser)
            return;
        if ( BCCommon::g_bConnectWithServer ) {
            BCCommunication *pServer = BCCommunication::Application();
            pServer->UpdateInputChannel(pCurrentUser->id, m_id, m_nChanneltype, m_name);
        } else {
            BCLocalServer *pServer = BCLocalServer::Application();
            pServer->UpdateInputChannel(pCurrentUser->id, pServer->m_qsConnectIPWithoutDLL, m_id, m_nChanneltype, m_name);
        }
    }
}

void BCMChannel::SetChannelCustomName(BCMGroupChannel *pGroupChannel, const QString &qs)
{
    if ((NULL == pGroupChannel) || qs.isEmpty())
        return;

    // 如果已经存在名字则移除
    if ( m_mapCustomName.contains(pGroupChannel) )
        m_mapCustomName.remove( pGroupChannel );

    m_mapCustomName.insert(pGroupChannel, qs);
}

QString BCMChannel::GetChannelCustomName(BCMGroupChannel *pGroupChannel)
{
    return m_mapCustomName.value( pGroupChannel );
}

void BCMChannel::SetChannelLastRect(BCMGroupDisplay *pGroupDisplay, const QRectF &rect)
{
    if (NULL == pGroupDisplay)
        return;

    // 保证只有一个矩形
    if (m_mapLastRect.contains(pGroupDisplay)) {
        m_mapLastRect.remove( pGroupDisplay );
    }

    m_mapLastRect.insert(pGroupDisplay, rect);
}

bool BCMChannel::IsHaveLastRect(BCMGroupDisplay *pGroupDisplay)
{
    return m_mapLastRect.contains( pGroupDisplay );
}

QRectF BCMChannel::GetChannelLastRect(BCMGroupDisplay *pGroupDisplay)
{
    return m_mapLastRect.value( pGroupDisplay );
}

void BCMChannel::SetChannelLastSegmentaion(BCMGroupDisplay *pGroupDisplay, int seg)
{
    if (NULL == pGroupDisplay)
        return;

    // 保证只有一个矩形
    if (m_mapLastIpvSegment.contains(pGroupDisplay)) {
        m_mapLastIpvSegment.remove( pGroupDisplay );
    }

    m_mapLastIpvSegment.insert(pGroupDisplay, seg);
}

int BCMChannel::GetChannelLastSegmentation(BCMGroupDisplay *pGroupDisplay)
{
    if ( !m_mapLastIpvSegment.contains(pGroupDisplay) )
        return 1;

    return m_mapLastIpvSegment.value( pGroupDisplay );
}

void BCMChannel::SetChannelLastIpvIPList(BCMGroupDisplay *pGroupDisplay, QStringList lst)
{
    if (NULL == pGroupDisplay)
        return;

    // 保证只有一个矩形
    if (m_mapLastIpvIPList.contains(pGroupDisplay)) {
        m_mapLastIpvIPList.remove( pGroupDisplay );
    }

    m_mapLastIpvIPList.insert(pGroupDisplay, lst);
}

QStringList BCMChannel::GetChannelLastIpvIPList(BCMGroupDisplay *pGroupDisplay)
{
    return m_mapLastIpvIPList.value( pGroupDisplay );
}

void BCMChannel::AddSignalWindowDisplayWidget(BCSignalWindowDisplayWidget *pItem)
{
    if ( !m_lstSignalDisplayWidget.contains(pItem) )
        m_lstSignalDisplayWidget.append(pItem);
}

void BCMChannel::RemoveSignalWindowDisplayWidget(BCSignalWindowDisplayWidget *pItem)
{
    m_lstSignalDisplayWidget.removeOne( pItem );
}

int BCMChannel::GetSignalWindowDisplayWidgetCount()
{
    return m_lstSignalDisplayWidget.count();
}

void BCMChannel::SetCutArea(int left, int right, int top, int bottom, bool bSendCmd)
{
    bool bExecL = (m_nCutLeft != left) ? true : false;
    bool bExecR = (m_nCutRight != right) ? true : false;
    bool bExecT = (m_nCutTop != top) ? true : false;
    bool bExecB = (m_nCutBottom != bottom) ? true : false;

    m_nCutLeft = left;
    m_nCutRight = right;
    m_nCutTop = top;
    m_nCutBottom = bottom;

    // 发送指令
    if ( bSendCmd ) {
        MainWindow *pMainWindow = BCCommon::Application();
        BCSUser *pCurrentUser = pMainWindow->GetCurrentUser();
        if (NULL == pCurrentUser)
            return;

        if ( BCCommon::g_bConnectWithServer ) {
            BCCommunication *pServer = BCCommunication::Application();
            pServer->SetCutArea(m_id, left, right, top, bottom);
        } else {
            BCLocalServer *pServer = BCLocalServer::Application();
            pServer->SetCutArea(pCurrentUser->id, pServer->m_qsConnectIPWithoutDLL, m_id, m_nChanneltype, m_nBoardCardID, m_nBoardCardPos, left, bExecL, right, bExecR, top, bExecT, bottom, bExecB);
        }
    }
}

int BCMChannel::getCopyIndex()
{
    // 不是VP2000 一律返回-1
    if (BCCommon::g_nDeviceType != 0)
        return -1;

    // 循环现有开窗获得WindowID
    QList<int> lstWindowIDs;
    QListIterator<BCSignalWindowDisplayWidget *> it( m_lstSignalDisplayWidget );
    while ( it.hasNext() ) {
        BCSignalWindowDisplayWidget *pSignalWindow = it.next();
        if (NULL == pSignalWindow)
            continue;

        lstWindowIDs.append( pSignalWindow->GetCopyIndex() );
    }

    // 从0开始循环，如果中间有空缺直接返回，无空缺返回最后一个
    for (int i = -1; i < m_lstSignalDisplayWidget.count(); i++) {
        if (lstWindowIDs.contains(i))
            continue;

        return i;
    }

    return -1;
}

bool BCMChannel::IsOpenWindowKey(int groupdisplayid)
{
    if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) { // VP200A, VP4000
        if (m_nSignalSource == 9) {                 // 1.IPV不允许在不同屏组内重复开窗
            return true;   // 20170821 改为固定可以无限复制
        }

        if ( BCCommon::g_bSignalWindowCopy )        // 2.允许复制则允许开窗
            return true;
        else {                                      // 3.不允许复制如果屏组内没开过窗则可以开窗
            bool bExist = false;
            for (int i = 0; i < m_lstSignalDisplayWidget.count(); i++) {
                BCSignalWindowDisplayWidget *pItem = m_lstSignalDisplayWidget.at(i);
                if (NULL == pItem)
                    continue;

                // 屏组界面类
                BCGroupDisplayWidget *pGroupDisplay = pItem->GetGroupDisplay();
                if (NULL == pGroupDisplay)
                    continue;

                // 屏组数据类
                BCMGroupDisplay *pMGroupDisplay = pGroupDisplay->GetMGroupDisplay();
                if (NULL == pMGroupDisplay)
                    continue;

                if (groupdisplayid != pMGroupDisplay->GetGroupDisplayID())
                    continue;

                bExist = true;
                break;
            }

            return !bExist;
        }
    } else if (BCCommon::g_nDeviceType == 0) { // VP2000
        if ( BCCommon::g_bSignalWindowCopy ) {
            if (0 == m_nChanneltype) {
                if (m_lstSignalDisplayWidget.count() <= BCCommon::g_nSignalWindowCopyCount)         // 1.允许复制并且开窗数量小于限制数量则允许开窗
                    return true;
                else                                                                                // 2.允许复制并且开窗数量大于限制数量则不允许开窗
                    return false;
            } else if (3 == m_nChanneltype) {
                if (m_lstSignalDisplayWidget.count() <= BCCommon::g_nSignalWindowCopyCountOfVideo)  // 1.允许复制并且开窗数量小于限制数量则允许开窗
                    return true;
                else                                                                                // 2.允许复制并且开窗数量大于限制数量则不允许开窗
                    return false;
            } else if (2 == m_nChanneltype) {
                if ( m_lstSignalDisplayWidget.isEmpty() )                                           // 1.允许复制并且开窗数量小于限制数量则允许开窗
                    return true;
                else                                                                                // 2.允许复制并且开窗数量大于限制数量则不允许开窗
                    return false;
            } else
                return false;
        } else if (m_lstSignalDisplayWidget.isEmpty())                                  // 3.不允许复制如果没开过窗则可以开窗
            return true;
        else                                                                            // 4.不允许复制如果开过窗则不可以再开窗
            return false;
    }

    return true;
}
