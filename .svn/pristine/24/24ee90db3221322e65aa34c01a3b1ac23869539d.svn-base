#include "BCSignalSrouceSceneViewWidget.h"
#include <QVBoxLayout>
#include <QTreeWidget>
#include <QListWidget>
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"
#include "../Common/BCCommunication.h"
#include "../Model/BCMGroupScene.h"
#include "../Model/BCMWindowScene.h"
#include "../Model/BCMRoom.h"
#include "../Model/BCMGroupDisplay.h"
#include "../Model/BCMChannel.h"
#include "BCSceneListWidgetData.h"
#include "BCScreenDlg.h"
#include "BCRoomWidget.h"
#include "BCSignalWindowDisplayWidget.h"
#include "BCScreenName.h"
#include "BCSignalWindowDisplayWidget.h"
#include "BCGroupDisplayWidget.h"

// 预览小窗的尺寸
#define PREVIEWWIDTH    240
#define PREVIEWHEIGHT   156

// 为了实现鼠标双击事件，直接在外层使用过滤器不起作用
class BCSignalSrouceSceneViewTreeWidgetItemWidget : public QWidget
{
public:
    BCSignalSrouceSceneViewTreeWidgetItemWidget(BCMWindowScene *pWindowScene, QWidget *parent);

private:
    void mouseDoubleClickEvent(QMouseEvent *);

    BCMWindowScene *m_pWindowScene;
};

BCSignalSrouceSceneViewTreeWidgetItemWidget::BCSignalSrouceSceneViewTreeWidgetItemWidget(BCMWindowScene *pWindowScene, QWidget *parent)
    :QWidget( parent )
{
    m_pWindowScene = pWindowScene;
}

void BCSignalSrouceSceneViewTreeWidgetItemWidget::mouseDoubleClickEvent(QMouseEvent *)
{
    m_pWindowScene->Show();
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------

// treeWidget的自定义item
class BCSignalSrouceSceneViewTreeWidgetItem : public QTreeWidgetItem
{
public:
    BCSignalSrouceSceneViewTreeWidgetItem(BCMWindowScene *pWindowScene, QTreeWidget *parent);

    void SetText(const QString &text);
    void SetEditable(bool b);
    void RefreshInterval();
    void SetLoopWindowScene(bool b);
    void SaveInterval();
    void SetSelectAll(bool b);

    BCMWindowScene  *m_pWindowScene;    // 场景数据

    int         m_nType;            // 0:icon+text  1:checkbox
    QLabel      *m_pIconLabel;      // 显示ICON
    QLabel      *m_pTextLabel;      // 显示text
    QCheckBox   *m_pCheckBox;
    QLineEdit   *m_pLineEdit;
    QLabel      *m_pUnitLabel;      // 显示单位
};

BCSignalSrouceSceneViewTreeWidgetItem::BCSignalSrouceSceneViewTreeWidgetItem(BCMWindowScene *pWindowScene, QTreeWidget *parent)
    :QTreeWidgetItem(parent)
{
    m_pWindowScene = pWindowScene;

    // 测试场景
    BCSignalSrouceSceneViewTreeWidgetItemWidget *pWidget = new BCSignalSrouceSceneViewTreeWidgetItemWidget(m_pWindowScene, parent);
    pWidget->setMaximumHeight( 25 );
    pWidget->setMinimumHeight( 25 );
    QHBoxLayout *pLayout = new QHBoxLayout();
    pLayout->setMargin( 0 );
    m_pIconLabel = new QLabel();
    m_pIconLabel->setMinimumSize(16, 16);
    m_pIconLabel->setMaximumSize(16, 16);
    m_pTextLabel = new QLabel();
    m_pCheckBox = new QCheckBox( pWidget );
    m_pCheckBox->setText( m_pWindowScene->GetWindowSceneName() );
    m_pLineEdit = new QLineEdit( pWidget );
    m_pLineEdit->setMaximumWidth( 50 );
    m_pLineEdit->setMinimumWidth( 50 );
    m_pLineEdit->setText( QString::number(m_pWindowScene->GetWindowSceneLoopInterval()) );
    m_pUnitLabel = new QLabel( "s " );
    pLayout->addWidget( m_pIconLabel );
    pLayout->addWidget( m_pTextLabel );
    pLayout->addWidget( m_pCheckBox );
    pLayout->addStretch();
    pLayout->addWidget( m_pLineEdit );
    pLayout->addWidget( m_pUnitLabel );
    pWidget->setLayout( pLayout );

    parent->setItemWidget(this, 0, pWidget);
}

void BCSignalSrouceSceneViewTreeWidgetItem::SetText(const QString &text)
{
    // data
    m_pWindowScene->SetWindowSceneName( text );

    // ui
    m_pTextLabel->setText( text );
    m_pCheckBox->setText( text );
}

void BCSignalSrouceSceneViewTreeWidgetItem::SaveInterval()
{
    if ( !m_pCheckBox->isVisible() )
        return;

    m_pWindowScene->SetIsCycled( m_pCheckBox->isChecked() );
    m_pWindowScene->SetWindowSceneLoopInterval( m_pLineEdit->text().toInt() );
}

void BCSignalSrouceSceneViewTreeWidgetItem::SetSelectAll(bool b)
{
    if ( !m_pCheckBox->isVisible() )
        return;

    m_pCheckBox->setChecked( b );
}

void BCSignalSrouceSceneViewTreeWidgetItem::SetEditable(bool b)
{
    if ( !b ) {    // 正常模式
        m_pCheckBox->setVisible( false );
        m_pIconLabel->setVisible( true );
        m_pTextLabel->setVisible( true );

        QString qsIconPath = m_pWindowScene->IsCycled() ? QString("/sceneon16.png") : QString("/sceneoff16.png");
        m_pIconLabel->setPixmap( QPixmap::fromImage(QImage(BCCommon::g_qsApplicationDefaultStylePath+qsIconPath).scaled(16, 16)) );

        m_pTextLabel->setText( m_pWindowScene->GetWindowSceneName() );

        m_pLineEdit->setEnabled( false );
    } else {            // 勾选模式
        m_pIconLabel->setVisible( false );
        m_pTextLabel->setVisible( false );
        m_pCheckBox->setVisible( true );

        m_pCheckBox->setChecked( m_pWindowScene->IsCycled() );
        m_pCheckBox->setText( m_pWindowScene->GetWindowSceneName() );

        m_pLineEdit->setEnabled( true );
    }
}

void BCSignalSrouceSceneViewTreeWidgetItem::SetLoopWindowScene(bool b)
{
    m_pWindowScene->SetIsCycled( b );
    QString qsIconPath = m_pWindowScene->IsCycled() ? QString("/sceneon16.png") : QString("/sceneoff16.png");
    m_pIconLabel->setPixmap( QPixmap::fromImage(QImage(BCCommon::g_qsApplicationDefaultStylePath+qsIconPath).scaled(16, 16)) );
}

void BCSignalSrouceSceneViewTreeWidgetItem::RefreshInterval()
{
    m_pLineEdit->setText( QString::number(m_pWindowScene->GetWindowSceneLoopInterval()) );
}

// ---------------------------------------------------------------------------------------------------------------------------------------
BCSignalSrouceSceneViewWidget::BCSignalSrouceSceneViewWidget(BCMGroupScene *pGroupScene, int showType, QWidget *parent)
    :QWidget( parent )
{
    m_pGroupScene = pGroupScene;

    m_bSelectAll = false;
    m_pTreeWidget = new QTreeWidget( this );
//    m_pTreeWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);  // 增加多选
//    m_pTreeWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_pTreeWidget->setHeaderHidden( true );

    m_pListWidget = new QListWidget( this );
    m_pListWidget->setViewMode(QListView::IconMode);                        // 设置图标显示
    m_pListWidget->setResizeMode( QListView::Adjust);
    m_pListWidget->setFlow(QListView::LeftToRight);
    m_pListWidget->setSpacing(5);

    QVBoxLayout *pLayout = new QVBoxLayout();
    pLayout->setSpacing( 0 );
    pLayout->setMargin( 0 );
    pLayout->addWidget( m_pTreeWidget );
    pLayout->addWidget( m_pListWidget );
    this->setLayout( pLayout );

    // 安装事件过滤器
    m_pTreeWidget->installEventFilter( this );
    m_pListWidget->installEventFilter( this );

    Refresh( showType );
}

BCSignalSrouceSceneViewWidget::~BCSignalSrouceSceneViewWidget()
{
}

int BCSignalSrouceSceneViewWidget::GetShowType()
{
    return m_pTreeWidget->isVisible() ? 0 : 1;
}

void BCSignalSrouceSceneViewWidget::SetSceneEditable()
{
    MainWindow *pMainWindow = BCCommon::Application();

    for (int i = 0; i < m_pTreeWidget->topLevelItemCount(); i++) {
        BCSignalSrouceSceneViewTreeWidgetItem *pItem = dynamic_cast<BCSignalSrouceSceneViewTreeWidgetItem *>( m_pTreeWidget->topLevelItem(i) );
        if (NULL == pItem)
            continue;

        // 取消编辑模式之前先保存
        if ( !pMainWindow->IsWindowSceneSetSwitch() ) {
            pItem->SaveInterval();
        }

        pItem->SetEditable( pMainWindow->IsWindowSceneSetSwitch() );
    }
}

void BCSignalSrouceSceneViewWidget::SetSelectAll(bool b)
{
    m_bSelectAll = b;
    for (int i = 0; i < m_pTreeWidget->topLevelItemCount(); i++) {
        BCSignalSrouceSceneViewTreeWidgetItem *pItem = dynamic_cast<BCSignalSrouceSceneViewTreeWidgetItem *>( m_pTreeWidget->topLevelItem(i) );
        if (NULL == pItem)
            continue;

        pItem->SetSelectAll( m_bSelectAll );
    }
}

void BCSignalSrouceSceneViewWidget::Refresh(int showType)
{
    // init ui
    m_pTreeWidget->setVisible((0 == showType) ? true : false);
    m_pListWidget->setVisible((1 == showType) ? true : false);

    if (NULL == m_pGroupScene)
        return;

    // 1.初始化树形链表
    RefreshTreeWidget();

    // 2.初始化图片链表
    RefreshListWidget();

}

void BCSignalSrouceSceneViewWidget::RefreshTreeWidget()
{
    // 取当前房间
    MainWindow *pMainWindow = BCCommon::Application();
    BCMRoom *pRoom = pMainWindow->GetCurrentSceneMRoom();
    if (NULL == pRoom)
        return;

    // 清空数据
    m_pTreeWidget->clear();

    // 循环添加场景
    QList<BCMWindowScene *> lstWindowScene = m_pGroupScene->GetWindowScenes();
    for(int j = 0; j < lstWindowScene.count(); j++) {
        BCMWindowScene *pWindowScene = lstWindowScene.at(j);

        BCSignalSrouceSceneViewTreeWidgetItem *pWindowSceneItem = new BCSignalSrouceSceneViewTreeWidgetItem(pWindowScene, m_pTreeWidget);
        pWindowSceneItem->SetEditable( pMainWindow->IsWindowSceneSetSwitch() );
        m_pTreeWidget->addTopLevelItem( pWindowSceneItem );
    }

    // 展开显示
    m_pTreeWidget->expandAll();
}

void BCSignalSrouceSceneViewWidget::RefreshListWidget()
{
    MainWindow *pMainWindow = BCCommon::Application();
    BCMRoom *pRoom = pMainWindow->GetCurrentSceneMRoom();
    if (NULL == pRoom)
        return;

    m_pListWidget->clear();

    // 循环构建场景图片数据
    QList<BCMWindowScene *> lstWindowScene = m_pGroupScene->GetWindowScenes();
    for (int i = 0; i < lstWindowScene.count(); i++) {
        BCMWindowScene *pWindowScene = lstWindowScene.at( i );

        // 新建item并添加到链表
        QListWidgetItem *pItem = new QListWidgetItem( m_pListWidget );
        pItem->setSizeHint(QSize(PREVIEWWIDTH, PREVIEWHEIGHT));
        m_pListWidget->addItem(pItem);

        // 关联item和widget
        m_pListWidget->setItemWidget(pItem, new BCSceneListWidgetData(pWindowScene, this));
    }

    // ??? 临时这么做，原因是当预览模式时如果添加两个场景是横向排列的，但横向显示不全，只能通过修改容器尺寸来让场景自适应容器才能变成竖向排列，接口函数目前没找到
    m_pListWidget->resize(m_pListWidget->rect().width()-1, m_pListWidget->rect().height());
    m_pListWidget->resize(m_pListWidget->rect().width()+1, m_pListWidget->rect().height());
}

void BCSignalSrouceSceneViewWidget::SetBatchLoopTime(int value)
{
    MainWindow *pMainWindow = BCCommon::Application();
    if ( !pMainWindow->IsWindowSceneSetSwitch() )
        return;

    // 设置数据类
    QList<BCMWindowScene *> lstWindowScene = m_pGroupScene->GetWindowScenes();
    for(int j = 0; j < lstWindowScene.count(); j++) {
        BCMWindowScene *pWindowScene = lstWindowScene.at(j);
        pWindowScene->SetWindowSceneLoopInterval( value );
    }

    // 刷新UI类
    if ( m_pTreeWidget->isVisible() ) {
        for (int i = 0; i < m_pTreeWidget->topLevelItemCount(); i++) {
            BCSignalSrouceSceneViewTreeWidgetItem *pItem = dynamic_cast<BCSignalSrouceSceneViewTreeWidgetItem *>( m_pTreeWidget->topLevelItem( i ) );
            if (NULL != pItem)
                pItem->RefreshInterval();
        }
    }
}

bool BCSignalSrouceSceneViewWidget::eventFilter(QObject *obj, QEvent *e)
{
    if (obj == m_pTreeWidget) {             // 所有针对场景操作
        if (e->type() == QEvent::ContextMenu) {
            // 设置权限
            MainWindow *pMainWindow = BCCommon::Application();

            QMenu menu;
            QAction *pClearWindowScene = NULL;

            QAction *pAddWindowScene = NULL;

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
            QContextMenuEvent *pMenuEvent = static_cast<QContextMenuEvent *>( e );
            BCSignalSrouceSceneViewTreeWidgetItem *pSceneItem = dynamic_cast<BCSignalSrouceSceneViewTreeWidgetItem *>( m_pTreeWidget->itemAt( pMenuEvent->pos() ));

            // 根据选中item的数量判断显示哪种菜单
            //int nSelectItemCount = m_pTreeWidget->selectedItems().count();
            int nSelectItemCount = (NULL == pSceneItem) ? 0 : 1;
            switch ( nSelectItemCount ) {
            case 0: {   // 空白
                if (pMainWindow->GetCurrentUser()->level < 3) {
                    pAddWindowScene = menu.addAction(QObject::tr("添加场景"));
                }
                pClearWindowScene = menu.addAction(QObject::tr("清空场景"));
            }
                break;
            case 1: {   // 单选
                // 场景
                if (pMainWindow->GetCurrentUser()->level < 3) {
                    pPreviewWindowScene = menu.addAction(QObject::tr("应用场景"));
                    pUpdateWindowScene = menu.addAction(QObject::tr("更新场景"));
                }
                pDelWindowScene = menu.addAction(QObject::tr("删除场景"));
                pModifyWindowSceneName = menu.addAction(QObject::tr("修改名称"));
                menu.addSeparator();
                pAddLoop = menu.addAction(QObject::tr("添加轮巡"));
                pRemoveLoop = menu.addAction(QObject::tr("移除轮巡"));
                menu.addSeparator();
                pMoveToUp = menu.addAction(QObject::tr("上移"));
                pMoveToDown = menu.addAction(QObject::tr("下移"));
                pMoveToTop = menu.addAction(QObject::tr("置顶"));
                pMoveToBottom = menu.addAction(QObject::tr("置底"));

                // 勾选轮巡标识
                //pSceneItem = dynamic_cast<BCSignalSrouceSceneViewTreeWidgetItem *>( m_pTreeWidget->selectedItems().first() );
                //if (NULL != pSceneItem) {
                    pAddLoop->setCheckable( true );
                    pRemoveLoop->setCheckable( true );

                    pAddLoop->setChecked( pSceneItem->m_pWindowScene->IsCycled() );
                    pRemoveLoop->setChecked( !pSceneItem->m_pWindowScene->IsCycled() );
                //}
            }
                break;
            default: {  // 多选
                pDelWindowScene = menu.addAction(QObject::tr("删除场景"));
                menu.addSeparator();
                pAddLoop = menu.addAction(QObject::tr("批量添加轮巡"));
                pRemoveLoop = menu.addAction(QObject::tr("批量移除轮巡"));
            }
                break;
            }

            // 显示菜单
            QAction *pSelectAction = menu.exec(QCursor::pos());
            if (NULL == pSelectAction)
                return QWidget::eventFilter(obj, e);

            BCMRoom *pRoom = pMainWindow->GetCurrentSceneMRoom();
            if (NULL == pRoom)
                return QWidget::eventFilter(obj, e);

            // 清空场景
            if (pClearWindowScene == pSelectAction) {
                ClearWindowScene();
            }
            // 添加场景
            if (pAddWindowScene == pSelectAction) {
                AddWindowScene();
            }
            // 修改场景名称
            if (pModifyWindowSceneName == pSelectAction) {
                ModifyWindowSceneName( pSceneItem );
            }
            // 预览场景
            if (pPreviewWindowScene == pSelectAction) {
                pSceneItem->m_pWindowScene->Show();
            }
            // 更新场景
            if (pUpdateWindowScene == pSelectAction) {
                UpdateWindowScene( pSceneItem );
            }
            // 删除场景
            if (pDelWindowScene == pSelectAction) {
                DeleteWindowScene( m_pTreeWidget->selectedItems() );
            }
            // 添加轮巡
            if (pAddLoop == pSelectAction) {
                SetLoopWindowScene(true);
            }
            // 移除轮巡
            if (pRemoveLoop == pSelectAction) {
                SetLoopWindowScene(false);
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
    }

    return QWidget::eventFilter(obj, e);
}


// type标识移动类型，1：上移 2：下移 3：置顶 4：置底
void BCSignalSrouceSceneViewWidget::MoveWindowScene(int type)
{
    BCSignalSrouceSceneViewTreeWidgetItem *pSceneItem = dynamic_cast<BCSignalSrouceSceneViewTreeWidgetItem *>( m_pTreeWidget->selectedItems().first() );
    if (NULL == pSceneItem)
        return;

    if (NULL != m_pGroupScene) {
        switch ( type ) {
        case 1:
            m_pGroupScene->MoveToUp( pSceneItem->m_pWindowScene );
            break;
        case 2:
            m_pGroupScene->MoveToDown( pSceneItem->m_pWindowScene );
            break;
        case 3:
            m_pGroupScene->MoveToTop( pSceneItem->m_pWindowScene );
            break;
        case 4:
            m_pGroupScene->MoveToBottom( pSceneItem->m_pWindowScene );
            break;
        default:
            break;
        }
    }

    RefreshTreeWidget();
    RefreshListWidget();
}

void BCSignalSrouceSceneViewWidget::SetLoopWindowScene(bool b)
{
    QListIterator<QTreeWidgetItem*> it( m_pTreeWidget->selectedItems() );
    while ( it.hasNext() ) {
        BCSignalSrouceSceneViewTreeWidgetItem *pWindowSceneItem = dynamic_cast<BCSignalSrouceSceneViewTreeWidgetItem *>( it.next() );
        if (NULL == pWindowSceneItem)
            continue;

        if ( !BCCommon::g_bConnectWithServer ) {
            // 修改轮巡
            pWindowSceneItem->SetLoopWindowScene( b );
        } else {
            // 当连接服务器时需要等待异步调用
            BCCommunication *pCommunication = BCCommunication::Application();
            pCommunication->RequestUpdateWindowScene(pWindowSceneItem->m_pWindowScene->GetWindowSceneID(),
                                                     m_pGroupScene->GetRoom()->GetRoomID(),
                                                     m_pGroupScene->GetGroupSceneID(),
                                                     b ? 1 : 0,
                                                     pWindowSceneItem->m_pWindowScene->GetWindowSceneName());
        }
    }
}

void BCSignalSrouceSceneViewWidget::ClearWindowScene()
{
    m_pGroupScene->ClearWindowScene();

    // 刷新内部数据
    RefreshTreeWidget();
    RefreshListWidget();
}

bool BCSignalSrouceSceneViewWidget::SetAction(int type)
{
    int nSelectItemCount = m_pTreeWidget->selectedItems().count();
    switch ( type ) {
    case 1: {   // 添加场景
        AddWindowScene();
    }
        break;
    case 2: {   // 删除场景
        DeleteWindowScene( m_pTreeWidget->selectedItems() );
    }
        break;
    case 3: {   // 更新场景，只有选中一个场景时生效
        if (nSelectItemCount != 1)
            return false;

        BCSignalSrouceSceneViewTreeWidgetItem *pGroupSceneItem = dynamic_cast<BCSignalSrouceSceneViewTreeWidgetItem *>( m_pTreeWidget->selectedItems().first() );
        if (NULL == pGroupSceneItem)
            return false;

        UpdateWindowScene( pGroupSceneItem );
    }
        break;
    case 4:     // 场景设置【作废，原来是设置时间，现在每个场景单独设置轮巡时间】
        SetSceneEditable();
        break;
    case 5: {   // 修改名称
        if (nSelectItemCount != 1)
            return false;

        BCSignalSrouceSceneViewTreeWidgetItem *pGroupSceneItem = dynamic_cast<BCSignalSrouceSceneViewTreeWidgetItem *>( m_pTreeWidget->selectedItems().first() );
        if (NULL == pGroupSceneItem)
            return false;

        ModifyWindowSceneName( pGroupSceneItem );
    }
        break;
    default:
        break;
    }

    return true;
}

void BCSignalSrouceSceneViewWidget::AddWindowScene()
{
    // 取当前房间
    MainWindow *pMainWindow = BCCommon::Application();
    BCMRoom *pRoom = pMainWindow->GetCurrentSceneMRoom();
    if (NULL == pRoom)
        return;

    BCScreenDlg *pDlg = new BCScreenDlg(m_pGroupScene, this);
    if(pDlg->exec() == QDialog::Accepted) {
        BCMWindowScene *pWindowScene = pDlg->GetWindowScene();
        pWindowScene->Save( !BCCommon::g_bConnectWithServer );

        if ( !BCCommon::g_bConnectWithServer ) {
            Refresh( GetShowType() );
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

            m_pGroupScene->RemoveWindowScene( pWindowScene->GetWindowSceneID() );

            BCCommunication *pCommunication = BCCommunication::Application();
            pCommunication->RequestAddWindowScene(swindowscene, pRoom->GetRoomID(), m_pGroupScene->GetGroupSceneID());
        }
    }

    if ( m_pTreeWidget->isVisible() )
        m_pTreeWidget->expandAll();
}

void BCSignalSrouceSceneViewWidget::DeleteWindowScene(QList<QTreeWidgetItem*> lstItems)
{
    QListIterator<QTreeWidgetItem*> it( lstItems );
    while ( it.hasNext() ) {
        BCSignalSrouceSceneViewTreeWidgetItem *pWindowSceneItem = dynamic_cast<BCSignalSrouceSceneViewTreeWidgetItem *>( it.next() );
        if (NULL == pWindowSceneItem)
            continue;

        BCMGroupScene *pGroupScene = pWindowSceneItem->m_pWindowScene->GetGroupScene();
        if (NULL == pGroupScene)
            return;

        if ( !BCCommon::g_bConnectWithServer ) {
            pGroupScene->DeleteWindowScene( pWindowSceneItem->m_pWindowScene );
            m_pTreeWidget->takeTopLevelItem( m_pTreeWidget->indexOfTopLevelItem(pWindowSceneItem) );

            delete pWindowSceneItem;
            pWindowSceneItem = NULL;
        } else {
            // 当连接服务器时需要等待异步调用
            BCCommunication *pCommunication = BCCommunication::Application();
            pCommunication->RequestDeleteWindowScene(pWindowSceneItem->m_pWindowScene->GetWindowSceneID(),
                                                     pGroupScene->GetRoom()->GetRoomID(), pGroupScene->GetGroupSceneID());
        }
    }
}


void BCSignalSrouceSceneViewWidget::UpdateWindowScene(BCSignalSrouceSceneViewTreeWidgetItem *pWindowSceneItem)
{
    if ( !BCCommon::g_bConnectWithServer ) {
        pWindowSceneItem->m_pWindowScene->Update();
    } else {
        BCMGroupScene *pGroupScene = pWindowSceneItem->m_pWindowScene->GetGroupScene();
        if (NULL == pGroupScene)
            return;

        // 取信号窗管理类和房间尺寸
        BCMRoom *pMRoom = pGroupScene->GetRoom();
        if (NULL == pMRoom)
            return;

        sWindowScene swindowscene;
        swindowscene.id = pWindowSceneItem->m_pWindowScene->GetWindowSceneID();
        swindowscene.cycle = pWindowSceneItem->m_pWindowScene->IsCycled() ? 1 : 0;
        swindowscene.name = pWindowSceneItem->m_pWindowScene->GetWindowSceneName();

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

        // 当连接服务器时需要等待异步调用
        BCCommunication *pCommunication = BCCommunication::Application();
        pCommunication->RequestUpdateWindowScene(swindowscene, pMRoom->GetRoomID(), pGroupScene->GetGroupSceneID());
    }
}

void BCSignalSrouceSceneViewWidget::ModifyWindowSceneName(BCSignalSrouceSceneViewTreeWidgetItem *pGroupSceneItem)
{
    // 获得名称
    QString qsName = pGroupSceneItem->m_pWindowScene->GetWindowSceneName();

    // 显示修改对话框并重新设置名称
    BCScreenName dlg(qsName, this);
    if(dlg.exec() == QDialog::Accepted){
        qsName = dlg.name;

        if ( !BCCommon::g_bConnectWithServer ) {
            pGroupSceneItem->m_pWindowScene->SetWindowSceneName(qsName);
            pGroupSceneItem->SetText( qsName );
        } else {
            BCCommunication *pCommunication = BCCommunication::Application();
            pCommunication->RequestUpdateWindowScene(pGroupSceneItem->m_pWindowScene->GetWindowSceneID(),
                                                     pGroupSceneItem->m_pWindowScene->GetGroupScene()->GetRoom()->GetRoomID(),
                                                     pGroupSceneItem->m_pWindowScene->GetGroupScene()->GetGroupSceneID(),
                                                     pGroupSceneItem->m_pWindowScene->IsCycled() ? 1 : 0, qsName);
        }
    }
}
