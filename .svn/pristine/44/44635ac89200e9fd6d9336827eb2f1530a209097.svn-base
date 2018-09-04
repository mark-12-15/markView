#include "BCToolBar.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include "../Common/BCCommon.h"
#include "BCMonitorWidgetData.h"
#include "BCFaceWidget.h"

BCToolBar::BCToolBar(MainWindow::TOOLBARTYPE eToolBarType, QWidget * parent)
    :QDockWidget(parent)
{
    // 初始化
    m_eToolBarType = eToolBarType;

    QFont font = this->font();
    font.setFamily( BCCommon::g_qsDefaultFontFamily );
    this->setFont( font );

    // input and scene need left or right
    switch ( m_eToolBarType ) {
    case MainWindow::REVIEWTOOLBAR: {
        m_qsName = tr("预监窗口");
        BCMonitorWidget *pWidget = new BCMonitorWidget( this );
        this->setWidget( pWidget );

        // 设置可停靠位置
        //setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);
        setAllowedAreas(Qt::NoDockWidgetArea);                  // 不可停靠
        this->setFeatures( QDockWidget::DockWidgetClosable );   // 不可移动
        this->setMaximumHeight( 136+16+30 );                    // 136是视频高度，16的视频名称标签，30是上下左右距离边框距离
        this->setMinimumHeight( 136+16+30 );

        // 默认不显示预监工具条
        this->setVisible( false );
    }
        break;
    case MainWindow::MATRIXTOOLBAR: {
        m_qsName = tr("矩阵切换窗口");
        //
    }
        break;

    case MainWindow::SIGNALSOURCETOOLBAR: {
        m_qsName = tr("信号源窗口");
        BCFaceWidget* pWidget = new BCFaceWidget(this);
        this->setWidget(pWidget);

        // 设置可停靠位置，设置最小宽度是因为当视频链表为小视频时正好可以显示两列
        this->setMinimumWidth( 300 );
        this->setMaximumWidth( 400 );
        setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    }
        break;
    case MainWindow::EXTENDTOOLBAR: {
        m_qsName = tr("扩展窗口");

        // 设置可停靠位置
        setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    }
        break;
    default:
        m_qsName = tr("工具窗口");
        break;
    }

    // 设置dockwidgetTitle
    this->setWindowTitle( m_qsName );
}

BCToolBar::~BCToolBar()
{

}

void BCToolBar::onVisibel(bool /*b*/)
{
    if ( this->isVisible() )
        this->hide();
    else
        this->show();
}

void BCToolBar::closeEvent(QCloseEvent *e)
{
    this->hide();
    e->ignore();
}

void BCToolBar::showEvent(QShowEvent *)
{
    if (MainWindow::REVIEWTOOLBAR != m_eToolBarType)
        return;

    BCMonitorWidget *pWidget = dynamic_cast<BCMonitorWidget *>( this->widget() );
    if (NULL == pWidget)
        return;

    pWidget->SetPreviewVisible( true );
}

void BCToolBar::hideEvent(QHideEvent *)
{
    if (MainWindow::REVIEWTOOLBAR != m_eToolBarType)
        return;

    BCMonitorWidget *pWidget = dynamic_cast<BCMonitorWidget *>( this->widget() );
    if (NULL == pWidget)
        return;

    pWidget->RefreshEchoStatus( true );
}

void BCToolBar::RefreshLanguage()
{
    // 刷新内容
    switch ( m_eToolBarType ) {
    case MainWindow::REVIEWTOOLBAR: {
        m_qsName = tr("预监窗口");
        BCMonitorWidget *pWidget = dynamic_cast<BCMonitorWidget *>( this->widget() );
        if (NULL != pWidget) {
            // 暂时没有内容需要翻译
        }
    }
        break;

    case MainWindow::SIGNALSOURCETOOLBAR: {
        m_qsName = tr("信号源窗口");
        BCFaceWidget *pWidget = dynamic_cast<BCFaceWidget *>( this->widget() );
        if (NULL != pWidget) {
            pWidget->Refresh();
        }
    }
    default:
        break;
    }

    // 刷新标题
    this->setWindowTitle( m_qsName );
}

