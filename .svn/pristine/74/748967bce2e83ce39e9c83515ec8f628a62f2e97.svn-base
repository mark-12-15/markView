#include "BCMatrixOutputNodeWidget.h"
#include "ui_BCMatrixOutputNodeWidget.h"
#include <QPainter>
#include <QMenu>
#include <QResizeEvent>
#include "BCMatrixRoomWidget.h"
#include "BCScreenName.h"
#include "../Common/BCCommon.h"
#include "../Model/BCMMatrix.h"

BCMatrixOutputNodeWidget::BCMatrixOutputNodeWidget(const sMatrixNode &node, BCMatrixRoomWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCMatrixOutputNodeWidget)
{
    ui->setupUi(this);

    m_parent = parent;
    m_bDoubleNode = false;
    m_nSwitchID2 = -1;

    m_node1 = node;
    m_nSwitchID1 = m_node1.nSwitchID;
    ui->m_pStatusLabel1->setText((-1 == m_nSwitchID1) ? m_node1.name : QString("%1\n%2").arg(m_node1.name).arg(m_parent->GetInputNodeName(m_nSwitchID1)));
    m_bHighLight1 = false;
    m_bHighLight2 = false;

    ui->m_pNodeIconLabel2->setVisible( false );
    ui->m_pStatusLabel2->setVisible( false );

    // 添加事件过滤
    ui->m_pNodeWidget1->installEventFilter( this );
    ui->m_pNodeWidget2->installEventFilter( this );
}

BCMatrixOutputNodeWidget::~BCMatrixOutputNodeWidget()
{
    delete ui;
}

void BCMatrixOutputNodeWidget::SetDoubleNode(const sMatrixNode &node)
{
    ui->m_pNodeIconLabel2->setVisible( true );
    ui->m_pStatusLabel2->setVisible( true );

    m_bDoubleNode = true;
    m_node2 = node;
    m_nSwitchID2 = m_node2.nSwitchID;
    ui->m_pStatusLabel2->setText((-1 == m_nSwitchID2) ? m_node2.name : QString("%1\n%2").arg(m_node2.name).arg(m_parent->GetInputNodeName(m_nSwitchID2)));
}

void BCMatrixOutputNodeWidget::resizeEvent(QResizeEvent *event)
{
    int nWidth = event->size().width();
    if (nWidth < 20)
        return;

    int nWidgetWidth = (nWidth-18)/2;
    ui->m_pNodeWidget1->setMaximumWidth( nWidgetWidth );
    ui->m_pNodeWidget2->setMaximumWidth( nWidgetWidth );

    this->repaint();
}

void BCMatrixOutputNodeWidget::RefreshSwitchUI(QList<QPoint> lst)
{
    m_nSwitchID1 = -1;
    ui->m_pStatusLabel1->setText((-1 == m_nSwitchID1) ? m_node1.name : QString("%1\n输入%2").arg(m_node1.name).arg(m_nSwitchID1));
    m_nSwitchID2 = -1;
    ui->m_pStatusLabel2->setText((-1 == m_nSwitchID2) ? m_node2.name : QString("%1\n输入%2").arg(m_node2.name).arg(m_nSwitchID2));

    for (int i = 0; i < lst.count(); i++) {
        QPoint pt = lst.at( i );

        if (m_node1.id == pt.y()) {
            m_nSwitchID1 = pt.x();
            ui->m_pStatusLabel1->setText((-1 == m_nSwitchID1) ? m_node1.name : QString("%1\n输入%2").arg(m_node1.name).arg(m_nSwitchID1));
        }

        if (m_node2.id == pt.y()) {
            m_nSwitchID2 = pt.x();
            ui->m_pStatusLabel2->setText((-1 == m_nSwitchID2) ? m_node2.name : QString("%1\n输入%2").arg(m_node2.name).arg(m_nSwitchID2));
        }
    }
}

void BCMatrixOutputNodeWidget::GetSwitchInfo(QPoint &pt1, QPoint &pt2)
{
    pt1.setX(m_nSwitchID1);
    pt1.setY(m_node1.id);
    pt2.setX(m_nSwitchID2);
    pt2.setY(m_node2.id);
}

void BCMatrixOutputNodeWidget::RefreshSwitchNode(int inputID, const QString &name, QPoint pt)
{
    QPoint pt1 = ui->m_pNodeWidget1->mapFrom(m_parent, pt);
    if (ui->m_pNodeWidget1->rect().contains( pt1 )) {
        m_nSwitchID1 = inputID;
        ui->m_pStatusLabel1->setText((-1 == m_nSwitchID1) ? m_node1.name : QString("%1\n%2").arg(m_node1.name).arg(name));
        m_bHighLight1 = (-1 == m_nSwitchID1) ? false : true;

        // 切换指令
        if (-1 != m_nSwitchID1) {
            m_parent->SetSwitch(m_nSwitchID1, m_node1.id);
        }
    }

    QPoint pt2 = ui->m_pNodeWidget2->mapFrom(m_parent, pt);
    if (ui->m_pNodeWidget2->rect().contains( pt2 )) {
        m_nSwitchID2 = inputID;
        ui->m_pStatusLabel2->setText((-1 == m_nSwitchID2) ? m_node2.name : QString("%1\n%2").arg(m_node2.name).arg(name));
        m_bHighLight2 = (-1 == m_nSwitchID2) ? false : true;

        // 切换指令
        if (-1 != m_nSwitchID2) {
            m_parent->SetSwitch(m_nSwitchID2, m_node2.id);
        }
    }

    this->repaint();
}

void BCMatrixOutputNodeWidget::ModifyName(int i)
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
    m_parent->SetNodeName(1, (0 == i) ? m_node1.id : m_node2.id, str);
}

void BCMatrixOutputNodeWidget::ModifyResolution(int in, int type)
{
    BCMMatrix *pMatrix = m_parent->GetMMatrix();
    pMatrix->SendCmd( QString("resolution %1 %2 %3\r\n").arg(m_node1.id).arg(m_node2.id).arg(type) );
    //pMatrix->SendCmd( QString("outputres %1 %2\r\n").arg((0 == in) ? m_node1.id : m_node2.id).arg(type) );
}

bool BCMatrixOutputNodeWidget::eventFilter(QObject *obj, QEvent *e)
{
    if (e->type() == QEvent::ContextMenu) {
        QMenu menu;
        QAction *pModifyNameAction = menu.addAction(tr("修改名称"));
        QMenu resolutinMenu;
        resolutinMenu.setTitle(tr("修改分辨率"));
//        QAction *pRes2 = resolutinMenu.addAction("1280*720");
//        QAction *pRes3 = resolutinMenu.addAction("1024*768");
//        QAction *pRes4 = resolutinMenu.addAction("1280*800");
//        QAction *pRes6 = resolutinMenu.addAction("1280*1024");
//        QAction *pRes7 = resolutinMenu.addAction("1360*768");
//        QAction *pRes8 = resolutinMenu.addAction("1366*768");
//        QAction *pRes9 = resolutinMenu.addAction("1440*900");
//        QAction *pRes10 = resolutinMenu.addAction("1400*1050");
//        QAction *pRes14 = resolutinMenu.addAction("1920*1080");
//        QAction *pRes15 = resolutinMenu.addAction("1920*1200");
        QAction *pRes2 = resolutinMenu.addAction("1920*1080@60Hz");
        QAction *pRes3 = resolutinMenu.addAction("1400*1050");
        QAction *pRes4 = resolutinMenu.addAction("1366*768");
        QAction *pRes6 = resolutinMenu.addAction("1280*720");
        QAction *pRes7 = resolutinMenu.addAction("1024*768");
        QAction *pRes8 = resolutinMenu.addAction("1920*1080@30Hz");
        QAction *pRes9 = resolutinMenu.addAction("1440*900@60Hz");
        "aspiration aspiration aspiration aspiration aspiration aspect aspect in this aspect aspire aspire aspire aspire aspire"
        "aspire to aspire to inspire until i expire. aspire to inspire until i expire. aspire to inspire until i expire"
        "aspire to inspire until i expire. aspiration aspiration aspiration. aspect in this aspect. in this aspect. in this aspect"
        "";
        menu.addMenu( &resolutinMenu );
        QAction *pSelectAction = menu.exec( QCursor::pos() );
        if (obj == ui->m_pNodeWidget1) {
            if (pModifyNameAction == pSelectAction) {
                ModifyName( 0 );
            }
            if (pRes2 == pSelectAction) {
                //ModifyResolution(0, 2);
                ModifyResolution(0, 0);
            }
            if (pRes3 == pSelectAction) {
                //ModifyResolution(0, 3);
                ModifyResolution(0, 1);
            }
            if (pRes4 == pSelectAction) {
                //ModifyResolution(0, 4);
                ModifyResolution(0, 2);
            }
            if (pRes6 == pSelectAction) {
                //ModifyResolution(0, 6);
                ModifyResolution(0, 3);
            }
            if (pRes7 == pSelectAction) {
                //ModifyResolution(0, 7);
                ModifyResolution(0, 4);
            }
            if (pRes8 == pSelectAction) {
                //ModifyResolution(0, 8);
                ModifyResolution(0, 7);
            }
            if (pRes9 == pSelectAction) {
                //ModifyResolution(0, 9);
                ModifyResolution(0, 8);
            }
//            if (pRes10 == pSelectAction) {
//                ModifyResolution(0, 10);
//            }
//            if (pRes14 == pSelectAction) {
//                ModifyResolution(0, 14);
//            }
//            if (pRes15 == pSelectAction) {
//                ModifyResolution(0, 15);
//            }
        }
        if (obj == ui->m_pNodeWidget2) {
            if ( m_bDoubleNode ) {
                if (pModifyNameAction == pSelectAction) {
                    ModifyName( 1 );
                }
                if (pRes2 == pSelectAction) {
                    //ModifyResolution(0, 2);
                    ModifyResolution(1, 0);
                }
                if (pRes3 == pSelectAction) {
                    //ModifyResolution(0, 3);
                    ModifyResolution(1, 1);
                }
                if (pRes4 == pSelectAction) {
                    //ModifyResolution(0, 4);
                    ModifyResolution(1, 2);
                }
                if (pRes6 == pSelectAction) {
                    //ModifyResolution(0, 6);
                    ModifyResolution(1, 3);
                }
                if (pRes7 == pSelectAction) {
                    //ModifyResolution(0, 7);
                    ModifyResolution(1, 4);
                }
                if (pRes8 == pSelectAction) {
                    //ModifyResolution(0, 8);
                    ModifyResolution(1, 7);
                }
                if (pRes9 == pSelectAction) {
                    //ModifyResolution(0, 9);
                    ModifyResolution(1, 8);
                }
//                if (pRes10 == pSelectAction) {
//                    ModifyResolution(1, 10);
//                }
//                if (pRes14 == pSelectAction) {
//                    ModifyResolution(1, 14);
//                }
//                if (pRes15 == pSelectAction) {
//                    ModifyResolution(1, 15);
//                }
            }
        }

        return true;
    } else {
        return QWidget::eventFilter(obj, e);
    }
}

void BCMatrixOutputNodeWidget::RefreshHighLight(int id)
{
    m_bHighLight1 = (m_nSwitchID1 == id) ? true : false;
    m_bHighLight2 = (m_nSwitchID2 == id) ? true : false;

    this->repaint();
}

void BCMatrixOutputNodeWidget::paintEvent(QPaintEvent */*event*/)
{
    QPainter p(this);

    // 画背景
    p.setPen(Qt::NoPen);
    QColor color1 = m_bHighLight1 ? QColor(202, 255, 112) : QColor(231, 251, 253);
    p.setBrush( QBrush(color1) );
    QPoint ptLT1 = ui->m_pNodeWidget1->mapTo(this, ui->m_pNodeWidget1->rect().topLeft());
    QPoint ptRB1 = ui->m_pNodeWidget1->mapTo(this, ui->m_pNodeWidget1->rect().bottomRight());
    QPoint ptLT2 = ui->m_pNodeWidget2->mapTo(this, ui->m_pNodeWidget2->rect().topLeft());
    QPoint ptRB2 = ui->m_pNodeWidget2->mapTo(this, ui->m_pNodeWidget2->rect().bottomRight());

    p.drawRoundedRect(QRect(ptLT1, ptRB1), 5, 5);

    if ( m_bDoubleNode ) {
        QColor color2 = m_bHighLight2 ? QColor(202, 255, 112) : QColor(231, 251, 253);
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
