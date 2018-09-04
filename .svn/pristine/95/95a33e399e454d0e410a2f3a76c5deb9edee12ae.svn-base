#include "BCScene.h"
#include "ui_BCScene.h"
#include "../Common/BCCommon.h"
#include "BCWidgetBtn.h"
#include "../View/BCSceneTreeWidget.h"
#include "../Model/BCMGroupScene.h"
#include "../Model/BCMRoom.h"
#include "BCRibbonMainToolBarAction.h"
#include "BCSceneListWidgetData.h"
#include "BCSignalSrouceSceneViewWidget.h"
#include "BCScreenName.h"

// 预览小窗的尺寸
#define PREVIEWWIDTH    240
#define PREVIEWHEIGHT   156

BCScene::BCScene(bool bVisible, int minHeight, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCScene)
{
    m_pHeaderBtn = NULL;

    m_bModifyHeight = false;
    m_bPress = false;

    ui->setupUi(this);
    setAttribute( Qt::WA_Hover,true);

    m_pHeaderBtn = new BCWidgetBtn(this, MainWindow::WINDOWSCENESIGSRC, bVisible);
    ui->verticalLayout->addWidget(m_pHeaderBtn);
    connect(m_pHeaderBtn, SIGNAL(sigSetVisible(bool)), this, SLOT(onSetVisible(bool)));
    onSetVisible( bVisible );

    m_minHeight = minHeight;
    ui->frame->setMinimumHeight(minHeight);

    //默认字体
    BCCommon::SetSystemFont(this);

    Refresh();

    // 安装事件过滤器
    ui->m_pSceneTabWidget->installEventFilter( this );              // 修改名称和删除场景组菜单
    ui->m_pSceneTabWidget->tabBar()->installEventFilter( this );    // 鼠标左键点【+】添加场景组
}

BCScene::~BCScene()
{
    delete m_pHeaderBtn;
    m_pHeaderBtn = NULL;

    delete ui;
}

void BCScene::onSetVisible(bool bVisible)
{
    ui->frame->setVisible( bVisible );
}

bool BCScene::IsVisible()
{
    return m_pHeaderBtn->IsVisible();
}

void BCScene::Refresh()
{
    MainWindow *pMainWindow = BCCommon::Application();
    BCMatrixRoomWidget *pMatrixRoomWidget = pMainWindow->GetCurrentMatrixSceneWidget();

    // 判断显示拼接场景还是矩阵场景界面
    ui->m_pNomalWidget->setVisible(NULL == pMatrixRoomWidget);
    ui->m_pMatrixTreeWidget->setVisible(NULL != pMatrixRoomWidget);

    if (NULL == pMatrixRoomWidget) {
        BCMRoom *pRoom = pMainWindow->GetCurrentSceneMRoom();
        if (NULL == pRoom)
            return;

        // 析构内部矩形
        for (int i = 0; i < ui->m_pSceneTabWidget->count(); i++) {
            delete ui->m_pSceneTabWidget->widget(i);
        }
        ui->m_pSceneTabWidget->clear(); // 只是清空，内部并没有删除

        // 添加场景组
        QList<BCMGroupScene *> lstGroupScene = pRoom->GetGroupScenes();
        for (int i = 0; i < lstGroupScene.count(); i++) {
            BCMGroupScene *pGroupScene = lstGroupScene.at( i );

            ui->m_pSceneTabWidget->addTab(new BCSignalSrouceSceneViewWidget(pGroupScene, 0, ui->m_pSceneTabWidget),
                                          pGroupScene->GetGroupSceneName());
        }
        ui->m_pSceneTabWidget->addTab(new QWidget(ui->m_pSceneTabWidget), "+");
    } else {
        ui->m_pMatrixTreeWidget->Refresh();
    }
}

bool BCScene::eventFilter(QObject *obj, QEvent *e)
{
    if (obj == ui->m_pSceneTabWidget) {
        if (e->type() == QEvent::ContextMenu) {
            QContextMenuEvent *pMenuEvent = static_cast<QContextMenuEvent *>( e );
            int tabIndex = ui->m_pSceneTabWidget->tabBar()->tabAt( pMenuEvent->pos() );
            if (-1 != tabIndex) {
                BCSignalSrouceSceneViewWidget *pWidget = dynamic_cast<BCSignalSrouceSceneViewWidget *>( ui->m_pSceneTabWidget->widget( tabIndex ) );
                if (NULL != pWidget) {
                    BCMGroupScene *pGroupScene = pWidget->GetMGroupScene();

                    QMenu menu;
                    QAction *pModifyNameAction = menu.addAction(tr("修改名称"));
                    QAction *pDelGroupAction = (0 == pGroupScene->GetGroupSceneID()) ? NULL : menu.addAction(tr("删除场景组"));
                    QAction *pSelectAction = menu.exec( QCursor::pos() );
                    if (pModifyNameAction == pSelectAction) {
                        BCScreenName dlg(pGroupScene->GetGroupSceneName(), this);
                        if(dlg.exec() == QDialog::Accepted) {
                            // data
                            pGroupScene->SetGroupSceneName( dlg.name );

                            // ui
                            ui->m_pSceneTabWidget->setTabText(tabIndex, dlg.name);
                        }
                    }

                    if ((NULL != pDelGroupAction) && (pDelGroupAction == pSelectAction)) {
                        BCMRoom *pRoom = pGroupScene->GetRoom();
                        pRoom->RemoveGroupScene( pGroupScene );

                        // 刷新界面
                        this->Refresh();
                    }
                }
            }
        }
    } else if (obj == ui->m_pSceneTabWidget->tabBar()) {
        if (e->type() == QEvent::MouseButtonPress) {
            QMouseEvent *pMouseEvent = static_cast<QMouseEvent *>( e );
            if(pMouseEvent->button() == Qt::LeftButton) {
                int tabIndex = ui->m_pSceneTabWidget->tabBar()->tabAt( pMouseEvent->pos() );
                if (-1 != tabIndex) {
                    // 如果点击最后一个则新建场景组
                    if (tabIndex != ui->m_pSceneTabWidget->count()-1)
                        return QWidget::eventFilter(obj, e);

                    MainWindow *pMainWindow = BCCommon::Application();
                    BCMRoom *pRoom = pMainWindow->GetCurrentSceneMRoom();
                    if (NULL == pRoom)
                        return QWidget::eventFilter(obj, e);

                    pRoom->AddGroupScene( new BCMGroupScene( pRoom ) );

                    // 刷新界面
                    Refresh();
                }
            }
        }
    }

    return QWidget::eventFilter(obj, e);
}

bool BCScene::SetAction(int type)
{
    MainWindow *pMainWindow = BCCommon::Application();
    BCMatrixRoomWidget *pMatrixRoomWidget = pMainWindow->GetCurrentMatrixSceneWidget();

    if (NULL == pMatrixRoomWidget) {
        BCSignalSrouceSceneViewWidget *pWidget = dynamic_cast<BCSignalSrouceSceneViewWidget *>( ui->m_pSceneTabWidget->currentWidget() );
        if (NULL == pWidget)
            return false;

        pWidget->SetAction(type);
    } else {
        return ui->m_pMatrixTreeWidget->SetAction(type);
    }

    return true;
}

void BCScene::SetLoopTime(int value)
{
    ui->spinBox->setValue( value );
}

// 编辑场景的轮巡时间
void BCScene::SetSceneEditable()
{
    BCSignalSrouceSceneViewWidget *pWidget = dynamic_cast<BCSignalSrouceSceneViewWidget *>( ui->m_pSceneTabWidget->currentWidget() );
    if (NULL == pWidget)
        return;

    pWidget->SetSceneEditable();
}

void BCScene::on_spinBox_valueChanged(int value)
{
    BCSignalSrouceSceneViewWidget *pWidget = dynamic_cast<BCSignalSrouceSceneViewWidget *>( ui->m_pSceneTabWidget->currentWidget() );
    if (NULL == pWidget)
        return;

    pWidget->SetBatchLoopTime( value );
}

void BCScene::on_comboBox_currentIndexChanged(int index)
{
    for (int i = 0; i < ui->m_pSceneTabWidget->count(); i++) {
        BCSignalSrouceSceneViewWidget *pWidget = dynamic_cast<BCSignalSrouceSceneViewWidget *>( ui->m_pSceneTabWidget->widget( i ) );
        if (NULL == pWidget)
            continue;

        pWidget->Refresh( index );
    }
}

void BCScene::on_m_pSelectAllBtn_clicked()
{
    BCSignalSrouceSceneViewWidget *pWidget = dynamic_cast<BCSignalSrouceSceneViewWidget *>( ui->m_pSceneTabWidget->currentWidget() );
    if (NULL == pWidget)
        return;

    pWidget->SetSelectAll( !pWidget->IsSelectAll() );
}

bool BCScene::event(QEvent *event)
{
    if (NULL == m_pHeaderBtn)
        return false;

    // 如果隐藏则不出发悬停事件
    if ( !m_pHeaderBtn->IsVisible() )
        return false;

    if (event->type() == QEvent::HoverEnter || event->type() == QEvent::HoverLeave
            || event->type() == QEvent::HoverMove) {
        QHoverEvent* pHoverEvent = static_cast<QHoverEvent *>(event);

        // 判断是否需要调整窗口大小，下面为距离左上角的值
        int nltx = pHoverEvent->pos().x() - rect().x();
        int nlty = pHoverEvent->pos().y() - rect().y();

        // x在修改范围时
        if (nltx <= BCCommon::g_nMaxSizeOfModifyRect) {
            m_bModifyHeight = false;
            setCursor(Qt::ArrowCursor);
        } else if (qAbs(nltx-rect().width()) <= BCCommon::g_nMaxSizeOfModifyRect) {
            m_bModifyHeight = false;
            setCursor(Qt::ArrowCursor);
        } else {
            if (nlty <= BCCommon::g_nMaxSizeOfModifyRect) {
                // ↑
                m_bModifyHeight = true;
                setCursor(Qt::SizeVerCursor);
            } else if (qAbs(nlty-rect().height()) <= BCCommon::g_nMaxSizeOfModifyRect) {
                // ↓
                m_bModifyHeight = true;
                setCursor(Qt::SizeVerCursor);
            } else {
                // 不拉伸
                m_bModifyHeight = false;
                setCursor(Qt::ArrowCursor);
            }
        }
    }

    return QWidget::event(event);
}

void BCScene::mousePressEvent(QMouseEvent *e)
{
    if ((e->button() == Qt::LeftButton) && m_bModifyHeight) {
        m_bPress = true;
    }

    QWidget::mousePressEvent( e );
}

void BCScene::mouseMoveEvent(QMouseEvent *e)
{
    if ( m_bPress ) {
        m_minHeight = e->pos().y() - m_pHeaderBtn->height() - 10;

        ui->frame->setMinimumHeight( m_minHeight );
    }

    QWidget::mouseMoveEvent( e );
}

void BCScene::mouseReleaseEvent(QMouseEvent *e)
{
    m_bPress = false;

    QWidget::mouseReleaseEvent( e );
}
