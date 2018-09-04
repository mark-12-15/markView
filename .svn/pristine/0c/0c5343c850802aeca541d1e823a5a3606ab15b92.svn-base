#include "BCSceneMatrixTreeWidget.h"

#include <QDebug>
#include <QMessageBox>
#include "../View/BCScene.h"
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"
#include "BCRibbonMainToolBar.h"
#include "BCRibbonMainToolBarAction.h"
#include "../Setting/BCSettingModifyNameDlg.h"
#include "../View/BCMatrixRoomWidget.h"
#include "../Model/BCMMatrix.h"

class BCMatrixTreeWidgetItem : public QTreeWidgetItem
{
public:
    BCMatrixTreeWidgetItem(sMatrixScene scene, QTreeWidget *parent);

    sMatrixScene m_scene;
};

BCMatrixTreeWidgetItem::BCMatrixTreeWidgetItem(sMatrixScene scene, QTreeWidget *parent)
    :QTreeWidgetItem(parent)
{
    m_scene = scene;
    this->setText(0, m_scene.name);
}

// -------------------------------------------------------------------------------------------------------------------------------------------

BCSceneMatrixTreeWidget::BCSceneMatrixTreeWidget(QWidget *parent)
    :QTreeWidget(parent)
{
    m_pSceneWidget = NULL;

    this->setHeaderHidden(true);

    // 连接信号槽
    connect(this,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(onItemDoubleClicked(QTreeWidgetItem*,int)));
}

BCSceneMatrixTreeWidget::~BCSceneMatrixTreeWidget(){

}


void BCSceneMatrixTreeWidget::Refresh()
{
    this->clear();

    MainWindow *pMainWindow = BCCommon::Application();
    BCMatrixRoomWidget *pRoomWidget = pMainWindow->GetCurrentMatrixSceneWidget();
    if (NULL == pRoomWidget)
        return;

    BCMMatrix *pMatrix = pRoomWidget->GetMMatrix();
    for (int i = 0; i < pMatrix->lstScene.count(); i++) {
        BCMatrixTreeWidgetItem *pWindowSceneItem = new BCMatrixTreeWidgetItem(pMatrix->lstScene.at(i), this);
        this->addTopLevelItem( pWindowSceneItem );
    }

    // 展开显示
    this->expandAll();
}

void BCSceneMatrixTreeWidget::onItemDoubleClicked(QTreeWidgetItem *pItem, int)
{
    // 强转当前点击item
    BCMatrixTreeWidgetItem *pSceneItem = dynamic_cast<BCMatrixTreeWidgetItem *>( pItem );
    if (NULL == pSceneItem)
        return;

    // ??? 显示当前场景
    MainWindow *pMainWindow = BCCommon::Application();
    BCMatrixRoomWidget *pRoomWidget = pMainWindow->GetCurrentMatrixWidget();
    if (NULL == pRoomWidget)
        return;

    pRoomWidget->Load( pSceneItem->m_scene.id );
}

void BCSceneMatrixTreeWidget::contextMenuEvent(QContextMenuEvent* event)
{
    QTreeWidgetItem *pSrcItem = this->itemAt( event->pos() );

    QMenu menu;
    QAction *pClearWindowScene = NULL;
    QAction *pAddWindowScene = NULL;

    QAction *pUpdateWindowScene = NULL;
    QAction *pDelWindowScene = NULL;        // 和批量删除共用
    QAction *pModifyWindowSceneName = NULL;

    // 根据选中item的数量判断显示哪种菜单
    if (NULL == pSrcItem) {
        pAddWindowScene = menu.addAction(tr("添加场景"));
        pClearWindowScene = menu.addAction(tr("清空场景"));
    } else {
        pUpdateWindowScene = menu.addAction(tr("更新场景"));
        pDelWindowScene = menu.addAction(tr("删除场景"));
        pModifyWindowSceneName = menu.addAction(tr("修改名称"));
    }

    // 显示菜单
    QAction *pSelectAction = menu.exec(QCursor::pos());
    if (NULL == pSelectAction)
        return;

    // 添加场景
    if (pAddWindowScene == pSelectAction) {
        AddWindowScene();
    }
    // 清空场景
    if (pClearWindowScene == pSelectAction) {
        MainWindow *pMainWindow = BCCommon::Application();
        BCMatrixRoomWidget *pRoomWidget = pMainWindow->GetCurrentMatrixWidget();
        if (NULL != pRoomWidget) {
            pRoomWidget->Clear();
            pMainWindow->RefreshMatrixData();
            this->Refresh();
        }
    }
    // 更新场景
    if (pUpdateWindowScene == pSelectAction) {
        BCMatrixTreeWidgetItem *pItem = dynamic_cast<BCMatrixTreeWidgetItem *>( pSrcItem );
        if (NULL != pItem) {
            MainWindow *pMainWindow = BCCommon::Application();
            BCMatrixRoomWidget *pRoomWidget = pMainWindow->GetCurrentMatrixWidget();
            if (NULL != pRoomWidget) {
                pRoomWidget->Update( pItem->m_scene.id );
                pMainWindow->RefreshMatrixData();
                this->Refresh();
            }
        }
    }
    // 删除场景
    if (pDelWindowScene == pSelectAction) {
        BCMatrixTreeWidgetItem *pItem = dynamic_cast<BCMatrixTreeWidgetItem *>( pSrcItem );
        if (NULL != pItem) {
            DeleteWindowScene( pItem->m_scene.id );
        }
    }
    // 修改场景名称
    if (pModifyWindowSceneName == pSelectAction) {
        BCMatrixTreeWidgetItem *pItem = dynamic_cast<BCMatrixTreeWidgetItem *>( pSrcItem );
        if (NULL != pItem) {
            ModifySceneName(pItem->m_scene.id, pItem->m_scene.name);
        }
    }
}

/* 对外开放接口
 *  1：添加场景
 *  2：删除场景
 *  3：更新场景
 */
bool BCSceneMatrixTreeWidget::SetAction(int type)
{
    switch ( type ) {
    case 1:
        AddWindowScene();
        break;
    case 2:
        if (1 == selectedItems().count()) {
            BCMatrixTreeWidgetItem *pItem = dynamic_cast<BCMatrixTreeWidgetItem *>( selectedItems().first() );
            if (NULL != pItem) {
                DeleteWindowScene( pItem->m_scene.id );
            }
        }
        break;
    case 3:
        if (1 == selectedItems().count()) {
            BCMatrixTreeWidgetItem *pItem = dynamic_cast<BCMatrixTreeWidgetItem *>( selectedItems().first() );
            if (NULL != pItem) {
                MainWindow *pMainWindow = BCCommon::Application();
                BCMatrixRoomWidget *pRoomWidget = pMainWindow->GetCurrentMatrixWidget();
                if (NULL != pRoomWidget) {
                    pRoomWidget->Update( pItem->m_scene.id );
                    pMainWindow->RefreshMatrixData();
                    this->Refresh();
                }
            }
        }
        break;
    default:
        break;
    }

    return true;
}

void BCSceneMatrixTreeWidget::AddWindowScene()
{
    MainWindow *pMainWindow = BCCommon::Application();
    BCMatrixRoomWidget *pRoomWidget = pMainWindow->GetCurrentMatrixWidget();
    if (NULL == pRoomWidget)
        return;

    // 计算场景ID
    int id = 1;
    QList<int> lstID;
    BCMMatrix *pMatrix = pRoomWidget->GetMMatrix();
    for (int i = 0; i < pMatrix->lstScene.count(); i++) {
        sMatrixScene scene = pMatrix->lstScene.at( i );
        lstID.append( scene.id );
    }
    for (int i = 1; i < lstID.count()+2; i++) {
        if (lstID.contains( i ))
            continue;

        id = i;
        break;
    }

    // data
    pRoomWidget->Save( id );

    pMainWindow->RefreshMatrixData();
    this->Refresh();
}

void BCSceneMatrixTreeWidget::DeleteWindowScene(int id)
{
    MainWindow *pMainWindow = BCCommon::Application();
    BCMatrixRoomWidget *pRoomWidget = pMainWindow->GetCurrentMatrixWidget();
    if (NULL == pRoomWidget)
        return;

    pRoomWidget->Remove( id );

    pMainWindow->RefreshMatrixData();
    this->Refresh();
}

void BCSceneMatrixTreeWidget::ModifySceneName(int id, const QString &str)
{
    BCSettingModifyNameDlg *pDlg = new BCSettingModifyNameDlg(str, BCCommon::Application());
    if (pDlg->exec() != QDialog::Accepted)
        return;

    QString newStr = pDlg->GetString();

    MainWindow *pMainWindow = BCCommon::Application();
    BCMatrixRoomWidget *pRoomWidget = pMainWindow->GetCurrentMatrixWidget();
    if (NULL == pRoomWidget)
        return;

    pRoomWidget->ModifySceneName(id, newStr);

    pMainWindow->RefreshMatrixData();
    this->Refresh();
}
