#include "BCMatrixInputNodeWidget.h"
#include "ui_BCMatrixInputNodeWidget.h"
#include <QPainter>
#include <QResizeEvent>
#include <QMenu>
#include "BCMatrixRoomWidget.h"
#include "BCScreenName.h"
#include "../Common/BCCommon.h"
#include "../Model/BCMMatrix.h"
#include "../Setting/BCSettingMatrixCutInputChannelDlg.h"

BCMatrixInputNodeWidget::BCMatrixInputNodeWidget(const sMatrixNode &node, BCMatrixRoomWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCMatrixInputNodeWidget)
{
    ui->setupUi(this);

    m_parent = parent;
    m_bHighLight1 = false;
    m_bHighLight2 = false;
    m_bDoubleNode = false;
    m_node1 = node;
    ui->m_pStatusLabel1->setText( m_node1.name );

    ui->m_pNodeIconLabel2->setVisible( false );
    ui->m_pStatusLabel2->setVisible( false );

    // 添加事件过滤
    ui->m_pNodeWidget1->installEventFilter( this );
    ui->m_pNodeWidget2->installEventFilter( this );
}

BCMatrixInputNodeWidget::~BCMatrixInputNodeWidget()
{
    delete ui;
}

void BCMatrixInputNodeWidget::SetDoubleNode(const sMatrixNode &node)
{
    ui->m_pNodeIconLabel2->setVisible( true );
    ui->m_pStatusLabel2->setVisible( true );

    m_bDoubleNode = true;
    m_node2 = node;
    ui->m_pStatusLabel2->setText( m_node2.name );
}

void BCMatrixInputNodeWidget::resizeEvent(QResizeEvent *event)
{
    int nWidth = event->size().width();
    if (nWidth < 20)
        return;

    int nWidgetWidth = (nWidth-18)/2;
    ui->m_pNodeWidget1->setMaximumWidth( nWidgetWidth );
    ui->m_pNodeWidget2->setMaximumWidth( nWidgetWidth );

    this->repaint();
}

int BCMatrixInputNodeWidget::GetNodeID(QPoint pt)
{
    int nResID = -1;
    QPoint pt1 = ui->m_pNodeWidget1->mapFrom(m_parent, pt);
    if (ui->m_pNodeWidget1->rect().contains( pt1 )) {
        m_bHighLight1 = true;
        nResID = m_node1.id;
    } else {
        m_bHighLight1 = false;
    }

    QPoint pt2 = ui->m_pNodeWidget2->mapFrom(m_parent, pt);
    if (ui->m_pNodeWidget2->rect().contains( pt2 )) {
        m_bHighLight2 = true;
        nResID = m_node2.id;
    } else {
        m_bHighLight2 = false;
    }

    this->repaint();

    return nResID;
}

void BCMatrixInputNodeWidget::ModifyName(int i)
{
    if ((i != 0) && (i != 1))
        return;

    QString str = (0 == i) ? m_node1.name : m_node2.name;
    BCScreenName *pDlg = new BCScreenName(str, BCCommon::Application());
    if (pDlg->exec() != QDialog::Accepted)
        return;

    str = pDlg->name;

    // 1.修改界面
    if (0 == i) {
        m_node1.name = str;
        ui->m_pStatusLabel1->setText( str );
    } else {
        m_node2.name = str;
        ui->m_pStatusLabel2->setText( str );
    }

    // 2.修改文件
    m_parent->SetNodeName(0, (0 == i) ? m_node1.id : m_node2.id, str);
}

void BCMatrixInputNodeWidget::ModifyInputType(int in, int type)
{
    BCMMatrix *pMatrix = m_parent->GetMMatrix();
    pMatrix->SendCmd( QString("vt6inputmode %1 %2\r\n").arg((0 == in) ? m_node1.id : m_node2.id).arg(type) );
}

bool BCMatrixInputNodeWidget::eventFilter(QObject *obj, QEvent *e)
{
    if (e->type() == QEvent::ContextMenu) {
        QMenu menu;
        QAction *pModifyNameAction = menu.addAction(tr("修改名称"));
        QAction *pCutSignalAction = menu.addAction(tr("图像裁剪"));
        QMenu typeMenu;
        typeMenu.setTitle(tr("修改类型"));
        QAction *pVGA = typeMenu.addAction(tr("VGA"));
        QAction *pVideo = typeMenu.addAction(tr("VIDEO"));
        QAction *pWeight = typeMenu.addAction(tr("分量"));
        QAction *pDVI = typeMenu.addAction(tr("DVI"));
        QAction *pHDMI = typeMenu.addAction(tr("HDMI"));

        menu.addMenu( &typeMenu );
        QAction *pSelectAction = menu.exec( QCursor::pos() );
        if (obj == ui->m_pNodeWidget1) {
            if (pModifyNameAction == pSelectAction) {
                ModifyName( 0 );
            }
            if (pCutSignalAction == pSelectAction) {
                BCSettingMatrixCutInputChannelDlg *pDlg = new BCSettingMatrixCutInputChannelDlg(m_parent->GetMMatrix(), m_node1.id, m_parent);
                pDlg->exec();
            }
            if (pVGA == pSelectAction) {
                ModifyInputType(0, 1);
            }
            if (pVideo == pSelectAction) {
                ModifyInputType(0, 2);
            }
            if (pWeight == pSelectAction) {
                ModifyInputType(0, 3);
            }
            if (pDVI == pSelectAction) {
                ModifyInputType(0, 4);
            }
            if (pHDMI == pSelectAction) {
                ModifyInputType(0, 5);
            }
        }
        if (obj == ui->m_pNodeWidget2) {
            if ( m_bDoubleNode ) {
                if (pModifyNameAction == pSelectAction) {
                    ModifyName( 1 );
                }
                if (pCutSignalAction == pSelectAction) {
                    BCSettingMatrixCutInputChannelDlg *pDlg = new BCSettingMatrixCutInputChannelDlg(m_parent->GetMMatrix(), m_node2.id, m_parent);
                    pDlg->exec();
                }
                if (pVGA == pSelectAction) {
                    ModifyInputType(1, 1);
                }
                if (pVideo == pSelectAction) {
                    ModifyInputType(1, 2);
                }
                if (pWeight == pSelectAction) {
                    ModifyInputType(1, 3);
                }
                if (pDVI == pSelectAction) {
                    ModifyInputType(1, 4);
                }
                if (pHDMI == pSelectAction) {
                    ModifyInputType(1, 5);
                }
            }
        }

        return true;
    } else {
        return QWidget::eventFilter(obj, e);
    }
}

void BCMatrixInputNodeWidget::paintEvent(QPaintEvent */*event*/)
{
    QPainter p(this);

    // 画背景
    p.setPen(Qt::NoPen);
    QColor color1 = m_bHighLight1 ? QColor(149, 241, 255) : QColor(231, 251, 253);
    p.setBrush( QBrush(color1) );
    QPoint ptLT1 = ui->m_pNodeWidget1->mapTo(this, ui->m_pNodeWidget1->rect().topLeft());
    QPoint ptRB1 = ui->m_pNodeWidget1->mapTo(this, ui->m_pNodeWidget1->rect().bottomRight());
    QPoint ptLT2 = ui->m_pNodeWidget2->mapTo(this, ui->m_pNodeWidget2->rect().topLeft());
    QPoint ptRB2 = ui->m_pNodeWidget2->mapTo(this, ui->m_pNodeWidget2->rect().bottomRight());

    p.drawRoundedRect(QRect(ptLT1, ptRB1), 5, 5);

    if ( m_bDoubleNode ) {
        QColor color2 = m_bHighLight2 ? QColor(149, 241, 255) : QColor(231, 251, 253);
        p.setBrush( QBrush(color2) );
        p.drawRoundedRect(QRect(ptLT2, ptRB2), 5, 5);
    }

    // 画边框
    p.setPen( Qt::white );
    p.setBrush( Qt::NoBrush );
    p.drawRoundedRect(QRect(ptLT1, ptRB1), 5, 5);

    if ( m_bDoubleNode ) {
        p.drawRoundedRect(QRect(ptLT2, ptRB2), 5, 5);
    }
}
