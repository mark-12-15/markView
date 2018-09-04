#include "BCMatrix.h"
#include "ui_BCMatrix.h"
#include "../Common/BCCommon.h"
#include "../Model/BCMMatrix.h"
#include "../Setting/BCSettingModifyNameDlg.h"

BCMatrixSignalSourceWidgetItem::BCMatrixSignalSourceWidgetItem(int id, const QString &name, QTreeWidget *parent, BCMatrixSignalSourceWidget *pWidget)
    : QTreeWidgetItem( parent )
{
    m_pWidget = pWidget;
    m_id = id;
    m_name = name;
    m_switchid = -1;

    this->setText(0, m_name);
}

void BCMatrixSignalSourceWidgetItem::SetSwitch(int id)
{
    m_switchid = id;

    for (int j = 0; j < m_pWidget->m_pMatrix->lstInputNode.count(); j++) {
        sMatrixNode nodeIn = m_pWidget->m_pMatrix->lstInputNode.at( j );
        if (nodeIn.id != m_switchid)
            continue;

        setText(0, QString("%1-->%2").arg(nodeIn.name).arg(m_name));
        break;
    }
}

void BCMatrixSignalSourceWidgetItem::RefreshName()
{
    if (-1 == m_switchid)
        return;

    for (int j = 0; j < m_pWidget->m_pMatrix->lstInputNode.count(); j++) {
        sMatrixNode nodeIn = m_pWidget->m_pMatrix->lstInputNode.at( j );
        if (nodeIn.id != m_switchid)
            continue;

        setText(0, QString("%1-->%2").arg(nodeIn.name).arg(m_name));
        break;
    }
}

// -------------------------------------------------------------------------------------------------------------------------

BCMatrixSignalSourceWidget::BCMatrixSignalSourceWidget(BCMMatrix *pMatrix, QWidget *parent)
    :QWidget( parent )
{
    m_pMatrix = pMatrix;

    // 新建输入和输出口
    m_pInputTreeWidget = new QTreeWidget( this );
    m_pOutputTreeWidget = new QTreeWidget( this );

    m_pInputTreeWidget->setStyleSheet( "QTreeView::item:hover{background-color:rgb(0,255,0,50)}" "QTreeView::item:selected{background-color:rgb(255,0,0,100)}" );
    m_pOutputTreeWidget->setStyleSheet( "QTreeView::item:hover{background-color:rgb(0,255,0,50)}" "QTreeView::item:selected{background-color:rgb(255,0,0,100)}" );

    // 设置layout
    QHBoxLayout *pLayout = new QHBoxLayout();
    pLayout->setMargin( 0 );
    pLayout->addWidget( m_pInputTreeWidget );
    pLayout->addWidget( m_pOutputTreeWidget );
    this->setLayout( pLayout );

    // init data
    m_pInputTreeWidget->setHeaderHidden( true );
    m_pOutputTreeWidget->setHeaderHidden( true );

    for (int i = 0; i < m_pMatrix->lstInputNode.count(); i++) {
        sMatrixNode node = m_pMatrix->lstInputNode.at( i );

        m_pInputTreeWidget->addTopLevelItem(new BCMatrixSignalSourceWidgetItem(node.id, node.name, m_pInputTreeWidget, this));
    }

    for (int i = 0; i < m_pMatrix->lstOutputNode.count(); i++) {
        sMatrixNode node = m_pMatrix->lstOutputNode.at( i );
        BCMatrixSignalSourceWidgetItem *pOutputItem = new BCMatrixSignalSourceWidgetItem(node.id, node.name, m_pOutputTreeWidget, this);
        m_pOutputTreeWidget->addTopLevelItem( pOutputItem );

        // 如果是切换则显示切换信息
        if (1 == node.nSwitch) {
            pOutputItem->SetSwitch( node.nSwitchID );
        }
    }

    // 输入节点需要完成拖拽功能
    m_pInputTreeWidget->viewport()->installEventFilter( this );
    // 输出节点显示是否有输入节点切换
    m_pOutputTreeWidget->viewport()->installEventFilter( this );
}

bool BCMatrixSignalSourceWidget::eventFilter(QObject *target, QEvent *event)
{
    if (target == m_pOutputTreeWidget->viewport()) {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *pMouseEvent = static_cast<QMouseEvent *>(event);
            if (NULL != pMouseEvent) {
                BCMatrixSignalSourceWidgetItem *pOutputItem = dynamic_cast<BCMatrixSignalSourceWidgetItem *>( m_pOutputTreeWidget->itemAt( pMouseEvent->pos() ) );
                BCMatrixSignalSourceWidgetItem *pInputItem = dynamic_cast<BCMatrixSignalSourceWidgetItem *>( m_pInputTreeWidget->currentItem() );
                if ((NULL != pInputItem) && (NULL != pOutputItem)) {
                    m_pMatrix->SetSwitch(pInputItem->m_id, pOutputItem->m_id);
                    pOutputItem->SetSwitch( pInputItem->m_id );
                }
            }
        } else if (event->type() == QEvent::ContextMenu) {
            QContextMenuEvent *pMenuEvent = static_cast<QContextMenuEvent *>(event);
            if (NULL != pMenuEvent) {
                BCMatrixSignalSourceWidgetItem *pOutputItem = dynamic_cast<BCMatrixSignalSourceWidgetItem *>( m_pOutputTreeWidget->itemAt( pMenuEvent->pos() ) );
                if (NULL != pOutputItem) {
                    QMenu menu;
                    QAction *pModifyAction = menu.addAction(QObject::tr("修改名称"));
                    if (pModifyAction == menu.exec( m_pOutputTreeWidget->mapToGlobal(pMenuEvent->pos()) )) {
                        QString qsItemName = pOutputItem->m_name;
                        BCSettingModifyNameDlg *pDlg = new BCSettingModifyNameDlg(qsItemName, BCCommon::Application());
                        if (pDlg->exec() == QDialog::Accepted) {
                            QString newStr = pDlg->GetString();

                            m_pMatrix->SetMatrixName(1, pOutputItem->m_id, newStr);
                            pOutputItem->m_name = newStr;
                            pOutputItem->RefreshName();
                        }
                    }
                }
            }
        }
    } else if (target == m_pInputTreeWidget->viewport()) {
        if (event->type() == QEvent::ContextMenu) {
            QContextMenuEvent *pMenuEvent = static_cast<QContextMenuEvent *>(event);
            if (NULL != pMenuEvent) {
                BCMatrixSignalSourceWidgetItem *pInputItem = dynamic_cast<BCMatrixSignalSourceWidgetItem *>( m_pInputTreeWidget->itemAt( pMenuEvent->pos() ) );
                if (NULL != pInputItem) {
                    QMenu menu;
                    QAction *pModifyAction = menu.addAction(QObject::tr("修改名称"));
                    if (pModifyAction == menu.exec( m_pInputTreeWidget->mapToGlobal(pMenuEvent->pos()) )) {
                        QString qsItemName = pInputItem->m_name;
                        BCSettingModifyNameDlg *pDlg = new BCSettingModifyNameDlg(qsItemName, BCCommon::Application());
                        if (pDlg->exec() == QDialog::Accepted) {
                            QString newStr = pDlg->GetString();

                            m_pMatrix->SetMatrixName(0, pInputItem->m_id, newStr);
                            pInputItem->setText(0, newStr);
                            for (int i = 0; i < m_pOutputTreeWidget->topLevelItemCount(); i++) {
                                BCMatrixSignalSourceWidgetItem *pTempOutputItem = dynamic_cast<BCMatrixSignalSourceWidgetItem *>( m_pOutputTreeWidget->topLevelItem( i ));
                                if (NULL == pTempOutputItem)
                                    continue;
                                pTempOutputItem->RefreshName();
                            }
                        }
                    }
                }
            }
        } else if (event->type() == QEvent::DragEnter) {
            QDragEnterEvent *pDragEnterEvent = static_cast<QDragEnterEvent *>(event);
            if (NULL != pDragEnterEvent) {
                if (pDragEnterEvent->mimeData()->hasFormat("jointinputChannel")) {
                    pDragEnterEvent->accept();
                } else {
                    pDragEnterEvent->ignore();
                }
            }
        } else if (event->type() == QEvent::MouseMove) {
            QMouseEvent *pMouseEvent = static_cast<QMouseEvent *>(event);
            if (NULL != pMouseEvent) {
                if(pMouseEvent->buttons() & Qt::LeftButton) {
                    QList<QString> listdata;
                    // 单选
                    BCMatrixSignalSourceWidgetItem *pDragItem = dynamic_cast<BCMatrixSignalSourceWidgetItem*>( m_pInputTreeWidget->itemAt( pMouseEvent->pos() ) );
                    if (NULL != pDragItem) {
                        listdata << QString::number(m_pMatrix->id);
                        listdata << QString::number(pDragItem->m_id);
                    }

                    if ( listdata.isEmpty() )
                        return QWidget::eventFilter(target, event);

                    QByteArray exData;
                    QDataStream dataStream(&exData,QIODevice::WriteOnly);
                    dataStream <<listdata;

                    QDrag *drag = new QDrag(this);
                    QMimeData *mimeData = new QMimeData();
                    mimeData->setData("jointinputChannel", exData);
                    drag->setMimeData(mimeData);

                    drag->exec(Qt::CopyAction);
                }
            }
        }
    }

    return QWidget::eventFilter(target, event);
}

// ---------------------------------------------------------------------------

BCMatrix::BCMatrix(bool bVisible, int minHeight, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCMatrix)
{
    m_pHeaderBtn = NULL;

    m_bModifyHeight = false;
    m_bPress = false;

    ui->setupUi(this);
    setAttribute( Qt::WA_Hover,true);

    m_minHeight = minHeight;
    ui->frame->setMinimumHeight(minHeight);
    m_pHeaderBtn = new BCWidgetBtn(this, MainWindow::MATRIXPANELSIGSRC, bVisible);
    ui->verticalLayout->addWidget(m_pHeaderBtn);

    connect(m_pHeaderBtn, SIGNAL(sigSetVisible(bool)), this, SLOT(onSetVisible(bool)));
    onSetVisible( bVisible );

    Init();
}

BCMatrix::~BCMatrix()
{
    delete ui;
}

void BCMatrix::onSetVisible(bool bVisible)
{
    ui->frame->setVisible( bVisible );
}

bool BCMatrix::IsVisible()
{
    return m_pHeaderBtn->IsVisible();
}

void BCMatrix::Init()
{
    // 清空
    ui->m_pTabWidget->clear();

    MainWindow *pMainWindow = BCCommon::Application();
    QList<BCMMatrix *> lstMatrix = pMainWindow->GetMMatrix();
    for (int i = 0; i < lstMatrix.count(); i++) {
        BCMMatrix *pMatrix = lstMatrix.at( i );

        // 判断是否是级联矩阵
        if (1 != pMatrix->jointWithVP4000)
            continue;

        ui->m_pTabWidget->addTab(new BCMatrixSignalSourceWidget(pMatrix, ui->m_pTabWidget), pMatrix->name);
    }
}

void BCMatrix::RefreshSwitch(int roomID, int inID, int outID)
{
    for (int i = 0; i < ui->m_pTabWidget->count(); i++) {
        BCMatrixSignalSourceWidget *pWidget = dynamic_cast<BCMatrixSignalSourceWidget *>( ui->m_pTabWidget->widget( i ) );
        if (NULL == pWidget)
            continue;

        if (roomID != pWidget->m_pMatrix->id)
            continue;

        // 查找输出节点
        for (int j = 0; j < pWidget->m_pOutputTreeWidget->topLevelItemCount(); j++) {
            BCMatrixSignalSourceWidgetItem *pItem = dynamic_cast<BCMatrixSignalSourceWidgetItem *>( pWidget->m_pOutputTreeWidget->topLevelItem( j ) );
            if (outID != pItem->m_id)
                continue;

            for (int k = 0; k < pWidget->m_pMatrix->lstInputNode.count(); k++) {
                sMatrixNode node = pWidget->m_pMatrix->lstInputNode.at( k );
                if (inID != node.id)
                    continue;

                pItem->setText(0, QString("%1-->%2").arg(node.name).arg(pItem->m_name));

                break;
            }

            break;
        }

        break;
    }
}


bool BCMatrix::event(QEvent *event)
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

void BCMatrix::mousePressEvent(QMouseEvent *e)
{
    if ((e->button() == Qt::LeftButton) && m_bModifyHeight) {
        m_bPress = true;
    }

    QWidget::mousePressEvent( e );
}

void BCMatrix::mouseMoveEvent(QMouseEvent *e)
{
    if ( m_bPress) {
        m_minHeight = e->pos().y() - m_pHeaderBtn->height() - 10;

        ui->frame->setMinimumHeight( m_minHeight );
    }

    QWidget::mouseMoveEvent( e );
}

void BCMatrix::mouseReleaseEvent(QMouseEvent *e)
{
    m_bPress = false;

    QWidget::mouseReleaseEvent( e );
}
