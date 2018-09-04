#include "BCMatrixRoomWidget.h"
#include "ui_BCMatrixRoomWidget.h"
#include "BCMatrixInputNodeWidget.h"
#include "BCMatrixOutputNodeWidget.h"
#include <QTcpSocket>
#include <QMouseEvent>
#include "../Common/BCLocalServer.h"
#include "../Common/BCCommon.h"
#include "../Model/BCMMatrix.h"

BCMatrixRoomWidget::BCMatrixRoomWidget(BCMMatrix *pMatrix, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCMatrixRoomWidget)
{
    ui->setupUi(this);

    m_pMatrix = pMatrix;
    m_nCurrentInputNodeID = -1;

    AddNode(ui->m_pInputScrollArea, 0);
    AddNode(ui->m_pOutputScrollArea, 1);
}

BCMatrixRoomWidget::~BCMatrixRoomWidget()
{
    delete ui;
}

void BCMatrixRoomWidget::mousePressEvent(QMouseEvent *event)
{
    // 只处理鼠标左键，选择输入和切换输出
    if (event->button() != Qt::LeftButton) {
        return;
    }

    int nInputAreaWidth = this->size().width() / 2;
    if (event->pos().x() < nInputAreaWidth) {
        bool bNoSelectInputNode = true;
        QListIterator<BCMatrixInputNodeWidget *> it( m_lstInputNodeWidget );
        while ( it.hasNext() ) {
            BCMatrixInputNodeWidget *pWidget = it.next();
            int n = pWidget->GetNodeID( event->pos() );
            if (-1 != n) {
                bNoSelectInputNode = false;
                m_nCurrentInputNodeID = n;
            }
        }

        // 如果没有选中的输入节点则初始化当前节点ID
        if ( bNoSelectInputNode )
            m_nCurrentInputNodeID = -1;
        else {
            QListIterator<BCMatrixOutputNodeWidget *> itOut( m_lstOutputNodeWidget );
            while ( itOut.hasNext() ) {
                BCMatrixOutputNodeWidget *pOutWidget = itOut.next();
                pOutWidget->RefreshHighLight( m_nCurrentInputNodeID );
            }
        }
    } else {
        QString qsName;
        if (-1 != m_nCurrentInputNodeID) {
            for (int i = 0; i < m_pMatrix->lstInputNode.count(); i++) {
                sMatrixNode node = m_pMatrix->lstInputNode.at( i );
                if (node.id != m_nCurrentInputNodeID)
                    continue;

                qsName = node.name;
                break;
            }

            QListIterator<BCMatrixOutputNodeWidget *> it( m_lstOutputNodeWidget );
            while ( it.hasNext() ) {
                BCMatrixOutputNodeWidget *pWidget = it.next();
                pWidget->RefreshSwitchNode(m_nCurrentInputNodeID, qsName, event->pos());
            }
        }
    }
}

void BCMatrixRoomWidget::AddNode(QScrollArea *pScrollArea, int type)
{
    // 添加输入
    QWidget *pWidget = new QWidget( pScrollArea );
    pScrollArea->setWidget( pWidget );

    QVBoxLayout *pLayout = new QVBoxLayout( pWidget );
    pWidget->setLayout( pLayout );

    pLayout->addStretch();
    if (0 == type) {
        for (int i = 0; i < m_pMatrix->lstInputNode.count(); i++) {
            // 奇数节点直接跳过
            if (i%2 == 1)
                continue;

            sMatrixNode node1 = m_pMatrix->lstInputNode.at( i );
            BCMatrixInputNodeWidget *pNodeWidget = new BCMatrixInputNodeWidget(node1, this);

            pLayout->addWidget( pNodeWidget );
            m_lstInputNodeWidget.append( pNodeWidget );

            // 将第二个节点赋值
            if (i+1 != m_pMatrix->lstInputNode.count()) {
                sMatrixNode node2 = m_pMatrix->lstInputNode.at( i+1 );
                pNodeWidget->SetDoubleNode( node2 );
            }
        }
    } else {
        for (int i = 0; i < m_pMatrix->lstOutputNode.count(); i++) {
            // 奇数节点直接跳过
            if (i%2 == 1)
                continue;

            sMatrixNode node1 = m_pMatrix->lstOutputNode.at( i );
            BCMatrixOutputNodeWidget *pNodeWidget = new BCMatrixOutputNodeWidget(node1, this);

            pLayout->addWidget( pNodeWidget );
            m_lstOutputNodeWidget.append( pNodeWidget );

            // 将第二个节点赋值
            if (i+1 != m_pMatrix->lstOutputNode.count()) {
                sMatrixNode node2 = m_pMatrix->lstOutputNode.at( i+1 );
                pNodeWidget->SetDoubleNode( node2 );
            }
        }
    }
    pLayout->addStretch();
}

QString BCMatrixRoomWidget::GetInputNodeName(int id)
{
    QString qsName;
    for (int i = 0; i < m_pMatrix->lstInputNode.count(); i++) {
        sMatrixNode node = m_pMatrix->lstInputNode.at( i );
        if (node.id != id)
            continue;

        qsName = node.name;
    }

    return qsName;
}

void BCMatrixRoomWidget::SetNodeName(int output, int id, const QString &name)
{
    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->SetMatrixName(m_pMatrix->id, output, id, name);
}

void BCMatrixRoomWidget::Load(int id)
{
    // 发送指令
    m_pMatrix->Load( id );

    // 更新界面
    for (int i = 0; i < m_pMatrix->lstScene.count(); i++) {
        sMatrixScene scene = m_pMatrix->lstScene.at( i );
        if (scene.id != id)
            continue;

        for (int i = 0; i < m_lstOutputNodeWidget.count(); i++) {
            BCMatrixOutputNodeWidget *pWidget = m_lstOutputNodeWidget.at( i );
            pWidget->RefreshSwitchUI( scene.lstSwitchInfo );
        }
    }
}

void BCMatrixRoomWidget::Save(int id)
{
    // 发送指令
    m_pMatrix->Save( id );

    // 返回切换信息
    QList<QPoint> lstSwitch;
    for (int i = 0; i < m_lstOutputNodeWidget.count(); i++) {
        BCMatrixOutputNodeWidget *pWidget = m_lstOutputNodeWidget.at( i );

        QPoint pt1, pt2;
        pWidget->GetSwitchInfo(pt1, pt2);

        if (pt1.x() != -1)
            lstSwitch.append( pt1 );
        if (pt2.x() != -1)
            lstSwitch.append( pt2 );
    }

    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->AddMatrixScene(m_pMatrix->id, id, tr("场景%1").arg(id), lstSwitch);
}

void BCMatrixRoomWidget::Update(int id)
{
    // 发送指令
    m_pMatrix->Save( id );

    // 返回切换信息
    QList<QPoint> lstSwitch;
    for (int i = 0; i < m_lstOutputNodeWidget.count(); i++) {
        BCMatrixOutputNodeWidget *pWidget = m_lstOutputNodeWidget.at( i );

        QPoint pt1, pt2;
        pWidget->GetSwitchInfo(pt1, pt2);

        if (pt1.x() != -1)
            lstSwitch.append( pt1 );
        if (pt2.x() != -1)
            lstSwitch.append( pt2 );
    }

    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->UpdateMatrixScene(m_pMatrix->id, id, lstSwitch);
}

void BCMatrixRoomWidget::Clear()
{
    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->ClearMatrixScene( m_pMatrix->id );
}

void BCMatrixRoomWidget::Remove(int id)
{
    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->RemoveMatrixScene(m_pMatrix->id, id);
}

void BCMatrixRoomWidget::ModifySceneName(int id, const QString &str)
{
    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->UpdateMatrixScene(m_pMatrix->id, id, str);
}

void BCMatrixRoomWidget::SetSwitch(int inID, int outID)
{
    // 发送指令到设备
    m_pMatrix->SetSwitch(inID, outID);
}

