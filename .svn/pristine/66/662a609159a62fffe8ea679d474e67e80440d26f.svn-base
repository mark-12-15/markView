#include "BCSignalTreeWidget.h"
#include <QDebug>
#include <QDrag>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMenu>
#include <QAction>
#include <QTreeWidgetItem>
#include "BCSignalName.h"
#include "../Model/BCMRoom.h"
#include "../Common/BCCommunication.h"
#include "../Model/BCMGroupChannel.h"
#include "../Model/BCMChannel.h"
#include "../Common/BCCommon.h"
#include "../Model/BCMGroupDisplay.h"
#include "BCSettingModifyEDIDDialog.h"
#include "../Common/BCLocalServer.h"
#include "BCRoomWidget.h"
#include "BCGroupDisplayWidget.h"
#include "BCSettingCutInputChannelDlg.h"
#include "BCSettingSubTitlesDlg.h"
#include "BCSettingIPVedioIPDlg.h"
#include "BCFaceWidget.h"
#include "BCToolBar.h"

BCSignalTreeWidgetItem::BCSignalTreeWidgetItem(BCMGroupChannel *pGroupChannel, QTreeWidget *parent)
    :QTreeWidgetItem(parent)
{
    m_pGroupChannel = pGroupChannel;
    m_pChannel = NULL;

    RefreshName( 0 );
}

BCSignalTreeWidgetItem::BCSignalTreeWidgetItem(BCMChannel *pChannel, QTreeWidgetItem *parent)
    :QTreeWidgetItem(parent)
{
    m_pChannel = pChannel;
    m_pGroupChannel = NULL;

    RefreshName( 1 );
}

void BCSignalTreeWidgetItem::RefreshName(int type)
{
    if (0 == type) {
        if (NULL == m_pGroupChannel)
            return;

        // 设置图片和文字
        this->setText(0, m_pGroupChannel->GetName());
    } else if (1 == type) {
        if (NULL == m_pChannel)
            return;

        // 设置图片和文字
        MainWindow *pApplication = BCCommon::Application();
        this->setText(0, m_pChannel->GetChannelBaseName()+m_pChannel->GetChannelName());
        this->setIcon(0, QIcon(pApplication->GetInputChannelIcon(m_pChannel->GetSignalSource())));
    }
}

bool BCSignalTreeWidgetItem::IsChannel()
{
    return (NULL == m_pChannel) ? false : true;
}

// ----------------------------------------------------------------------------------------------------------------------------------------

BCSignalTreeWidget::BCSignalTreeWidget(QWidget *parent)
    :QTreeWidget(parent)
{
    setHeaderHidden(true);

    setStyleSheet( "QTreeView::item:hover{background-color:rgb(0,255,0,50)}" "QTreeView::item:selected{background-color:rgb(255,0,0,100)}" );
}

BCSignalTreeWidget::~BCSignalTreeWidget()
{

}

void BCSignalTreeWidget::dragEnterEvent(QDragEnterEvent* event)
{
    if (event->mimeData()->hasFormat("inputChannel")) {
        event->accept();
    } else {
        event->ignore();
    }
}

void BCSignalTreeWidget::mouseMoveEvent (QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton) {
        QList<QString> listdata;
        // 单选
        BCSignalTreeWidgetItem *pDragItem = dynamic_cast<BCSignalTreeWidgetItem*>( this->itemAt( event->pos() ) );
        if (NULL != pDragItem) {
            listdata << "0";       //0 类型标识
            listdata << QString::number(pDragItem->GetChannel()->GetChannelType());
            listdata << QString::number(pDragItem->GetChannel()->GetChannelID());
        }

        if ( listdata.isEmpty() )
            return;

        QByteArray exData;
        QDataStream dataStream(&exData,QIODevice::WriteOnly);
        dataStream <<listdata;

        QDrag *drag = new QDrag(this);
        QMimeData *mimeData = new QMimeData();
        mimeData->setData("inputChannel", exData);
        drag->setMimeData(mimeData);

        drag->exec(Qt::CopyAction);
    }

    QTreeWidget::mouseMoveEvent( event );
}

void BCSignalTreeWidget::mouseReleaseEvent(QMouseEvent* event)
{
    QTreeWidget::mouseReleaseEvent(event);
}

void BCSignalTreeWidget::mouseDoubleClickEvent(QMouseEvent *)
{
    // 双击槽函数的参数
    QTreeWidgetItem* item = this->currentItem();
    if (NULL == item)
        return;

    // 根据ID找到输入通道
    BCMChannel *pChannel = ((BCSignalTreeWidgetItem*)item)->GetChannel();
    if (NULL == pChannel)
        return;

    MainWindow *pApplication = BCCommon::Application();

    BCRoomWidget *pRoomWidget = pApplication->GetCurrentRoomWidget();
    BCRoomMainWidget *pRoomMainWidget = pRoomWidget->GetRoomMainWidget();
    BCGroupDisplayWidget *pGroupDisplayWidget = pRoomMainWidget->GetCurrentGroupDisplay();
    if (NULL == pGroupDisplayWidget)
        return;

    BCMGroupDisplay *pMGroupDisplay = pGroupDisplayWidget->GetMGroupDisplay();
    if (NULL == pMGroupDisplay)
        return;
    QRectF rect;
    if ( !pChannel->IsHaveLastRect( pMGroupDisplay ) ) {
        int ArrangeX = pMGroupDisplay->GetArraySize().width();
        int ArrangeY = pMGroupDisplay->GetArraySize().height();

        rect.setLeft(0);
        rect.setTop(0);
        rect.setWidth(pMGroupDisplay->GetRect().width() / ArrangeX);
        rect.setHeight(pMGroupDisplay->GetRect().height()/ ArrangeY);
    } else {
        rect = pChannel->GetChannelLastRect( pMGroupDisplay );
    }

    // 向服务器发送winsize请求，以下设置放到服务器回复里处理
    if ( BCCommon::g_bConnectWithServer ) {
        if ( pRoomMainWidget->IsFloorPlanningSwitch() ) {   // 如果是打开了预布局则先添加窗口
            pRoomMainWidget->ServerWinsize(pGroupDisplayWidget, pChannel, pRoomMainWidget->CreateWindowID(pChannel), rect.left(), rect.top(), rect.width(), rect.height());
        } else {
            BCCommunication *pCommunication = BCCommunication::Application();
            pCommunication->Winsize(pMGroupDisplay->GetGroupDisplayID(), pChannel->GetChannelID(), pRoomMainWidget->CreateWindowID(pChannel),
                                    rect.left(), rect.top(), rect.right(), rect.bottom(), pChannel->GetChannelType(), pChannel->getCopyIndex());
        }
    } else {
        pRoomMainWidget->AddSignalWindow(rect.left(), rect.top(), rect.width(), rect.height(), pGroupDisplayWidget, pChannel);

        pRoomMainWidget->RefreshSignalWindowTextDisplay();
    }
}

void BCSignalTreeWidget::contextMenuEvent(QContextMenuEvent* event)
{
    // 如果当前没有item则没有右键菜单，普通item只是修改名称，IPV弹出设置界面
    BCSignalTreeWidgetItem *pCurrentItem = dynamic_cast<BCSignalTreeWidgetItem*>(this->itemAt(event->pos()));
    if (NULL == pCurrentItem)
        return;

    BCMChannel *pChannel = pCurrentItem->GetChannel();
    if (NULL == pChannel)
        return;

    int nSignalSource = pChannel->GetSignalSource();

    MainWindow *pMainWindow = BCCommon::Application();

    QMenu menu;
    QAction *pModifyNameAction = NULL;
    QAction *pOpenSubTitlesAction = NULL;
    QAction *pCloseSubTitlesAction = NULL;
    QAction *pSubTitlesAction = NULL;
    QAction *pVGAAction = NULL;
    QAction *pVideoAction = NULL;
    QAction *pYPbPrAction = NULL;
    QAction *pDVIAction = NULL;
    QAction *pHDMIAction = NULL;
    QAction *pCutChannelsAction = NULL;
    QAction *pIPVSetAction = NULL;
    QAction *pHDEDIDAction = NULL;
    QMenu sigSrcMenu;
    sigSrcMenu.setTitle(tr("设置信号"));
    QMenu subTitlesMenu;
    subTitlesMenu.setTitle(tr("设置字幕"));


    int nChType = pChannel->GetChannelType();
    if (2 == nChType) { // 高清只显示编辑EDID
        pModifyNameAction = menu.addAction(tr("修改名称"));//修改，添加修改名称
        pHDEDIDAction = menu.addAction(tr("编辑EDID"));
    } else if (1 == nChType) {  // IPVEDIO不要字幕和裁剪
        pModifyNameAction = menu.addAction(tr("修改名称"));
        pIPVSetAction = (9 == nSignalSource) ? menu.addAction(tr("设置IPVideo")) : NULL;
    } else if (0 == nChType) {  // PC可以修改类型
        pModifyNameAction = menu.addAction(tr("修改名称"));
        pOpenSubTitlesAction = subTitlesMenu.addAction(tr("打开字幕"));
        pCloseSubTitlesAction = subTitlesMenu.addAction(tr("关闭字幕"));
        pSubTitlesAction = subTitlesMenu.addAction(tr("更多设置"));
        menu.addMenu( &subTitlesMenu );
        if (pMainWindow->GetCurrentUser()->level < 2) {
            pVGAAction = sigSrcMenu.addAction(tr("VGA"));
            pVideoAction = sigSrcMenu.addAction(tr("Video"));
            pYPbPrAction = sigSrcMenu.addAction(tr("YPbPr"));
            pDVIAction = sigSrcMenu.addAction(tr("DVI"));
            pHDMIAction = sigSrcMenu.addAction(tr("HDMI"));
            menu.addMenu( &sigSrcMenu );
        }

        if (pMainWindow->GetCurrentUser()->level < 3) {
            pCutChannelsAction = menu.addAction(tr("裁剪信号"));
        }
    } else if (3 == nChType) {  // Vedio
        pModifyNameAction = menu.addAction(tr("修改名称"));
        pOpenSubTitlesAction = subTitlesMenu.addAction(tr("打开字幕"));
        pCloseSubTitlesAction = subTitlesMenu.addAction(tr("关闭字幕"));
        pSubTitlesAction = subTitlesMenu.addAction(tr("更多设置"));
        menu.addMenu( &subTitlesMenu );
        if (pMainWindow->GetCurrentUser()->level < 3) {
            pCutChannelsAction = menu.addAction(tr("裁剪信号"));
        }
    }

    QAction *pSelectAction = menu.exec( QCursor::pos() );
    if (NULL == pSelectAction)
        return;

    if (pSelectAction == pModifyNameAction) {
        ModifyChannelName( pCurrentItem );
    }
    if (pSelectAction == pOpenSubTitlesAction) {
        OpenSubTitles( pChannel );
    }
    if (pSelectAction == pCloseSubTitlesAction) {
        CloseSubTitles( pChannel );
    }
    if (pSelectAction == pSubTitlesAction) {
        SetSubTitles( pChannel );
    }
    if (pSelectAction == pVGAAction) {
        SetInputChannelType(pChannel, 1);
    }
    if (pSelectAction == pVideoAction) {
        SetInputChannelType(pChannel, 2);
    }
    if (pSelectAction == pYPbPrAction) {
        SetInputChannelType(pChannel, 3);
    }
    if (pSelectAction == pDVIAction) {
        SetInputChannelType(pChannel, 4);
    }
    if (pSelectAction == pHDMIAction) {
        SetInputChannelType(pChannel, 5);
    }
    if (pSelectAction == pCutChannelsAction) {
        SetCutArea( pChannel );
    }
    if (pSelectAction == pIPVSetAction) {
        SetIPVConfig( pChannel );
    }
    if (pSelectAction == pHDEDIDAction) {
        ModifyChannelEDID( pChannel );
    }
}

void BCSignalTreeWidget::RefreshInputChannelName()
{
    for (int i = 0; i < this->topLevelItemCount(); i++) {
        BCSignalTreeWidgetItem *pGroupChannelItem = dynamic_cast<BCSignalTreeWidgetItem *>( this->topLevelItem( i ) );
        if (NULL == pGroupChannelItem)
            continue;

        pGroupChannelItem->RefreshName( 0 );
        for (int j = 0; j < pGroupChannelItem->childCount(); j++) {
            BCSignalTreeWidgetItem *pChannelItem = dynamic_cast<BCSignalTreeWidgetItem *>( pGroupChannelItem->child( j ) );
            if (NULL == pChannelItem)
                continue;

            pChannelItem->RefreshName( 1 );
        }
    }
}

void BCSignalTreeWidget::Refresh()
{
    // 清空数据
    this->clear();

    // 循环添加自定义信号组
    MainWindow *pMainWindow = BCCommon::Application();
    QList<BCMGroupChannel *> lstGroupChannel = pMainWindow->GetGroupInputChannels();
    QListIterator<BCMGroupChannel *> itGroup( lstGroupChannel );
    while ( itGroup.hasNext() ) {
        BCMGroupChannel *pGroupChannel = itGroup.next();

        BCSignalTreeWidgetItem *pGroupChannelItem = new BCSignalTreeWidgetItem(pGroupChannel, this);
        this->addTopLevelItem( pGroupChannelItem );

        // 循环添加信号
        QList<BCMChannel *> lstChannel = pGroupChannel->GetChannels();
        QListIterator<BCMChannel *> it( lstChannel );
        while ( it.hasNext() ) {
            BCMChannel *pChannel = it.next();

            BCSignalTreeWidgetItem *pChannelItem = new BCSignalTreeWidgetItem(pChannel, pGroupChannelItem);
            pGroupChannelItem->addChild( pChannelItem );
        }
    }

    this->expandAll();
}

void BCSignalTreeWidget::SetCutArea(BCMChannel *pChannel)
{
    BCSettingCutInputChannelDlg *pDlg = new BCSettingCutInputChannelDlg(pChannel, BCCommon::Application());
    pDlg->exec();
}

void BCSignalTreeWidget::SetSubTitles(BCMChannel *pChannel)
{
    if (NULL == pChannel)
        return;

    BCSettingSubTitlesDlg *pDlg = new BCSettingSubTitlesDlg(pChannel, BCCommon::Application());
    pDlg->exec();
}

void BCSignalTreeWidget::OpenSubTitles(BCMChannel *pChannel)
{
    if (NULL == pChannel)
        return;

    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->SetSubTitlesVisible(pChannel->GetChannelType(), pChannel->GetChannelID(), pChannel->GetChannelID(), 1, pChannel->GetBoardCardID(), pChannel->GetBoardCardPos());
}

void BCSignalTreeWidget::CloseSubTitles(BCMChannel *pChannel)
{
    if (NULL == pChannel)
        return;

    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->SetSubTitlesVisible(pChannel->GetChannelType(), pChannel->GetChannelID(), pChannel->GetChannelID(), 0, pChannel->GetBoardCardID(), pChannel->GetBoardCardPos());
}

void BCSignalTreeWidget::SetInputChannelType(BCMChannel *pChannel, int type)
{
    if (NULL == pChannel)
        return;

    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->SetInputChannelType(pChannel->GetChannelType(), pChannel->GetChannelID(), type, pChannel->GetBoardCardID(), pChannel->GetBoardCardPos());
}

void BCSignalTreeWidget::ModifyChannelEDID(BCMChannel *pChannel)
{
    BCSettingModifyEDIDDialog *pDlg = new BCSettingModifyEDIDDialog(pChannel, BCCommon::Application());
    pDlg->exec();
}

void BCSignalTreeWidget::ModifyChannelName(BCSignalTreeWidgetItem *pCurrentItem)
{
    BCMChannel *pChannel = pCurrentItem->GetChannel();
    if (NULL == pChannel)
        return;

    BCSignalName *pDlg = new BCSignalName(pChannel, BCCommon::Application());
    if (pDlg->exec() == QDialog::Accepted) {
        pCurrentItem->setText(0, pChannel->GetChannelBaseName()+pChannel->GetChannelName());

        // 同步物理信号源链表
        MainWindow *pApplication = BCCommon::Application();
        BCToolBar *pToolBar = pApplication->GetToolBar( MainWindow::SIGNALSOURCETOOLBAR );
        if (NULL == pToolBar)
            return;

        BCFaceWidget *pSignalSourceWidget = dynamic_cast<BCFaceWidget *>( pToolBar->widget() );
        if (NULL != pSignalSourceWidget)
            pSignalSourceWidget->RefreshChannelName( 0 );
    }
}

void BCSignalTreeWidget::SetIPVConfig(BCMChannel *pChannel)
{
    BCSettingIPVedioIPDlg *pDlg = new BCSettingIPVedioIPDlg(pChannel, this);
    pDlg->exec();
}
