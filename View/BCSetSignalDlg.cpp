#include "BCSetSignalDlg.h"
#include "ui_BCSetSignalDlg.h"
#include <QDebug>
#include <QListWidgetItem>
#include <QTreeWidgetItem>
#include <QMessageBox>
#include "../Common/BCCommon.h"
#include "../Common/BCCommon.h"
#include "../View/BCFaceWidget.h"
#include "../View/BCToolBar.h"
#include "../Model/BCMRoom.h"
#include "../Model/BCMGroupDisplay.h"
#include "../Model/BCMGroupChannel.h"
#include "../Model/BCMChannel.h"

// ---------------------------------------------------------------------------------------------------------------
// 信号源自定义Item
class BCSignalSourceListWidgetItem : public QListWidgetItem
{
public:
    BCSignalSourceListWidgetItem(QPoint pt, QListWidget *parent);

    int m_type; // 记录当前的类型
};

BCSignalSourceListWidgetItem::BCSignalSourceListWidgetItem(QPoint pt, QListWidget *parent)
    :QListWidgetItem( parent )
{
    MainWindow *pApplication = BCCommon::Application();

    m_type = pt.x();
    this->setIcon(QIcon(pApplication->GetSignalSourceIcon((MainWindow::SIGNALSOURCETYPE)pt.x())));
    this->setText(pApplication->GetSignalSourceName((MainWindow::SIGNALSOURCETYPE)pt.x()));
    this->setCheckState((-1 != pt.y()) ? Qt::Checked : Qt::Unchecked);

    parent->addItem( this );
}

// ---------------------------------------------------------------------------------------------------------------


class BCGroupChannelTreeWidgetItem : public QTreeWidgetItem
{
public:
    BCGroupChannelTreeWidgetItem(BCMGroupChannel *pGroupChannel, QTreeWidget *parent);
    BCGroupChannelTreeWidgetItem(BCMGroupChannel *pGroupChannel, BCMChannel *pChannel, QTreeWidgetItem *parent);
    BCGroupChannelTreeWidgetItem(BCMChannel *pChannel, QTreeWidget *parent);

    // 是否是输入通道
    bool IsChannel() {
        return (NULL != m_pChannel) ? true : false;
    }

    BCMGroupChannel *m_pGroupChannel;
    BCMChannel *m_pChannel;
};

// ---------------------------------------------------------------------------------------------------------------
BCGroupChannelTreeWidgetItem::BCGroupChannelTreeWidgetItem(BCMGroupChannel *pGroupChannel, QTreeWidget *parent)
    :QTreeWidgetItem( parent )
{
    m_pGroupChannel = pGroupChannel;
    m_pChannel = NULL;

    this->setText(0, m_pGroupChannel->GetName());
}

BCGroupChannelTreeWidgetItem::BCGroupChannelTreeWidgetItem(BCMGroupChannel *pGroupChannel, BCMChannel *pChannel, QTreeWidgetItem *parent)
    :QTreeWidgetItem( parent )
{
    m_pGroupChannel = pGroupChannel;
    m_pChannel = pChannel;

    MainWindow *pApplication = BCCommon::Application();

    // 设置图标
    this->setIcon(0, QIcon(pApplication->GetInputChannelIcon(m_pChannel->GetSignalSource())));

    // 设置名称
    QString qsCustomName = m_pChannel->GetChannelCustomName( m_pGroupChannel );
    if ( qsCustomName.isEmpty() ) {
        qsCustomName = m_pChannel->GetChannelName();
        m_pChannel->SetChannelCustomName(m_pGroupChannel, qsCustomName);
    }

    this->setText(0, qsCustomName);
}

BCGroupChannelTreeWidgetItem::BCGroupChannelTreeWidgetItem(BCMChannel *pChannel, QTreeWidget *parent)
    :QTreeWidgetItem( parent )
{
    m_pGroupChannel = NULL;
    m_pChannel = pChannel;

    MainWindow *pApplication = BCCommon::Application();

    // 设置图标
    this->setIcon(0, QIcon(pApplication->GetInputChannelIcon(m_pChannel->GetSignalSource())));

    // 设置名称
    this->setText(0, m_pChannel->GetChannelName());
}

// ---------------------------------------------------------------------------------------------------------------

BCSetSignalDlg::BCSetSignalDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSetSignalDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("信号源设置"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    // 默认字体
    BCCommon::SetSystemFont(this);

    // init
    Init();
}

BCSetSignalDlg::~BCSetSignalDlg()
{
    delete ui;
}

QList<QPoint> BCSetSignalDlg::GetSignalSourceSort(int type)
{
    // 结果链表
    QList<QPoint> lstRes;

    QFile file( QString("../xml/BCSignalSourceConfig.xml") );
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "open BCSignalSourceConfig.xml error.";
        return lstRes;
    }

    // 将文件内容读到QDomDocument中
    QDomDocument doc;
    bool bLoadFile = doc.setContent(&file);
    file.close();

    if ( !bLoadFile ) {
        qDebug() << "load BCSignalSourceConfig.xml error.";
        return lstRes;
    }

    // 二级链表
    QDomElement docElem = doc.documentElement();

    QString qsGetNodeName = (0 == type) ? QString("currentSort") : QString("defaultSort");
    for (int i = 0; i < docElem.childNodes().count(); i++) {
        QDomNode nodeSortType = docElem.childNodes().at(i);

        // nodeName 分两种currentSort为当前排序，defaultSort为默认排序
        QString qsSortType = nodeSortType.nodeName();
        if (qsSortType != qsGetNodeName)
            continue;

        for (int j = 0; j < nodeSortType.childNodes().count(); j++) {
            QDomNode nodeType = nodeSortType.childNodes().at(j);
            if ( !nodeType.isElement() )
                continue;

            QDomElement eleType = nodeType.toElement();
            int nType = eleType.attribute(QString("type")).toInt();
            int nValid = eleType.attribute(QString("valid")).toInt();

            // 构造元对象并添加到链表
            QPoint pt(nType, nValid);
            lstRes.append( pt );
        }
    }

    return lstRes;
}

void BCSetSignalDlg::SetSignalSourceSort(QList<QPoint> lst)
{
    QFile file( QString("../xml/BCSignalSourceConfig.xml") );
    if(!file.open(QIODevice::ReadOnly)){
        return;
    }

    // 将文件内容读到QDomDocument中
    QDomDocument doc;
    bool bLoadFile = doc.setContent(&file);
    file.close();

    if ( !bLoadFile )
        return;

    // 二级链表
    QDomElement docElem = doc.documentElement();

    // 删除原有排序
    for (int i = 0; i < docElem.childNodes().count(); i++) {
        QDomNode nodeSortType = docElem.childNodes().at(i);

        QString qsSortType = nodeSortType.nodeName();
        if (qsSortType != QString("currentSort"))
            continue;

        // 删除节点
        docElem.removeChild( nodeSortType );

        break;
    }

    // 创建当前排序节点
    QDomElement eleCurrentSort = doc.createElement(QString("currentSort"));
    QListIterator<QPoint> it( lst );
    while (it.hasNext()) {
        QPoint pt = it.next();

        // 创建currentSort节点信息
        QDomElement eleCurrentSortNode = doc.createElement(QString("node"));
        eleCurrentSortNode.setAttribute(QString("type"), QString::number(pt.x()));
        eleCurrentSortNode.setAttribute(QString("valid"), QString::number(pt.y()));
        eleCurrentSortNode.setAttribute(QString("px"), QString::number(300));

        // 添加到根节点
        eleCurrentSort.appendChild( eleCurrentSortNode );
    }

    // 添加当前排序根节点
    docElem.appendChild( eleCurrentSort );

    // 写入文件
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}

bool BCSetSignalDlg::IsExistInputChannel(BCMChannel *pChannel)
{
    QListIterator<BCMGroupChannel *> it( m_lstGroupInputChannels );
    while ( it.hasNext() ) {
        BCMGroupChannel *pGroupChannel = it.next();
        QList<BCMChannel *> lstChannel = pGroupChannel->GetChannels();

        QListIterator<BCMChannel *> itGroup( lstChannel );
        while ( itGroup.hasNext() ) {
            BCMChannel *pExistChannel = itGroup.next();
            if (pExistChannel == pChannel)
                return true;
        }
    }

    return false;
}

bool BCSetSignalDlg::eventFilter(QObject *obj, QEvent *e)
{
    // 拖事件
    if (ui->m_pInputChannelTreeWidget->viewport() == obj) {
        if (e->type() == QEvent::MouseButtonPress) {
            QMouseEvent *pMouseEvent = dynamic_cast<QMouseEvent *>( e );
            if (NULL != pMouseEvent) {
                if(pMouseEvent->buttons() & Qt::LeftButton) {
                    QList<QString> listdata;
                    // 单选
                    BCGroupChannelTreeWidgetItem *pDragItem = dynamic_cast<BCGroupChannelTreeWidgetItem*>( ui->m_pInputChannelTreeWidget->itemAt( pMouseEvent->pos() ) );
                    if (NULL != pDragItem) {
                        if ( !IsExistInputChannel( pDragItem->m_pChannel ) ) {
                            listdata << QString::number(pDragItem->m_pChannel->GetChannelType());
                            listdata << QString::number(pDragItem->m_pChannel->GetChannelID());
                        }
                    }

                    if ( !listdata.isEmpty() ) {
                        QByteArray exData;
                        QDataStream dataStream(&exData,QIODevice::WriteOnly);
                        dataStream <<listdata;

                        QDrag *drag = new QDrag(this);
                        QMimeData *mimeData = new QMimeData();
                        mimeData->setData("signalSourceInputChannel", exData);
                        drag->setMimeData(mimeData);

                        drag->exec(Qt::CopyAction);
                    }

                    return true;
                }
            }
        }
    }

    // 放事件
    if (ui->m_pGroupChannelTreeWidget == obj) {
        if (e->type() == QEvent::DragEnter) {
            QDragEnterEvent *pDragEvent = dynamic_cast<QDragEnterEvent *>( e );
            if (NULL != pDragEvent) {
                if (pDragEvent->mimeData()->hasFormat("signalSourceInputChannel")
                        || pDragEvent->mimeData()->hasFormat("removeSignalSourceInputChannel"))
                   pDragEvent->accept();
                else
                   pDragEvent->ignore();

                // 直接返回，不交给父事件处理
                return true;
            }
        }

        if (e->type() == QEvent::Drop) {
            QDropEvent *pDropEvent = dynamic_cast<QDropEvent *>( e );
            if (NULL != pDropEvent) {
                if (pDropEvent->mimeData()->hasFormat("signalSourceInputChannel")) {
                    // 可用于接收拖拽参数
                    const QMimeData *mimeData = pDropEvent->mimeData();
                    QByteArray exData = mimeData->data("signalSourceInputChannel");
                    QDataStream dataStream (&exData, QIODevice::ReadOnly);
                    QList<QString> lstData;

                    dataStream >> lstData;
                    if (2 == lstData.count()) {
                        int chType = lstData.at(0).toInt();
                        int chID = lstData.at(1).toInt();

                        MainWindow *pApplication = BCCommon::Application();
                        BCMChannel *pChannel = pApplication->GetInputChannel(chID, chType);
                        if (NULL != pChannel) {
                            // 获得自定义通道内的当前item
                            QTreeWidgetItem *pCurrentItem = ui->m_pGroupChannelTreeWidget->itemAt( pDropEvent->pos() );
                            if (NULL == pCurrentItem)
                                return QDialog::eventFilter(obj, e);

                            // 将自定义通道内的item强转成自定义类型
                            BCGroupChannelTreeWidgetItem *pCurrentGroupItem = dynamic_cast<BCGroupChannelTreeWidgetItem *>( pCurrentItem );
                            if (NULL == pCurrentGroupItem)
                                return QDialog::eventFilter(obj, e);

                            // 找到将要添加的自定义输入信号组
                            if ( pCurrentGroupItem->IsChannel() ) {
                                pCurrentGroupItem = dynamic_cast<BCGroupChannelTreeWidgetItem *>( pCurrentGroupItem->parent() );
                                if (NULL == pCurrentGroupItem)
                                    return QDialog::eventFilter(obj, e);
                            }

                            // add ui
                            pCurrentGroupItem->addChild( new BCGroupChannelTreeWidgetItem(pCurrentGroupItem->m_pGroupChannel, pChannel, pCurrentGroupItem) );

                            // add data
                            pCurrentGroupItem->m_pGroupChannel->AddChannel( pChannel );

                            // 添加后展开显示
                            ui->m_pGroupChannelTreeWidget->expandAll();
                        }
                    }
                } else if (pDropEvent->mimeData()->hasFormat("removeSignalSourceInputChannel")) {
                    // 可用于接收拖拽参数
                    const QMimeData *mimeData = pDropEvent->mimeData();
                    QByteArray exData = mimeData->data("removeSignalSourceInputChannel");
                    QDataStream dataStream (&exData, QIODevice::ReadOnly);
                    QList<QString> lstData;

                    dataStream >> lstData;
                    if (4 == lstData.count()) {
                        int chType = lstData.at(0).toInt();
                        int chID = lstData.at(1).toInt();
                        int x = lstData.at(2).toInt();
                        int y = lstData.at(3).toInt();

                        // 移动距离超过100px时算删除
                        QLineF line(x, y, pDropEvent->posF().x(), pDropEvent->posF().y());
                        if (line.length() > 100) {
                            MainWindow *pApplication = BCCommon::Application();
                            BCMChannel *pChannel = pApplication->GetInputChannel(chID, chType);
                            if (NULL != pChannel) {
                                for (int i = 0; i < ui->m_pGroupChannelTreeWidget->topLevelItemCount(); i++) {
                                    QTreeWidgetItem *pTopItem = ui->m_pGroupChannelTreeWidget->topLevelItem( i );
                                    BCGroupChannelTreeWidgetItem *pGroupItem = dynamic_cast<BCGroupChannelTreeWidgetItem *>( pTopItem );
                                    if (NULL == pGroupItem)
                                        continue;

                                    int bRemove = false;
                                    for (int j = 0; j < pGroupItem->childCount(); j++) {
                                        QTreeWidgetItem *pCurrentItem = pGroupItem->child( j );
                                        if (NULL == pCurrentItem)
                                            continue;

                                        BCGroupChannelTreeWidgetItem *pCurrentChannlItem = dynamic_cast<BCGroupChannelTreeWidgetItem *>( pCurrentItem );
                                        if (NULL == pCurrentChannlItem)
                                            continue;

                                        if (pCurrentChannlItem->m_pChannel != pChannel)
                                            continue;

                                        pGroupItem->m_pGroupChannel->RemoveChannel( pChannel );
                                        pGroupItem->removeChild( pCurrentChannlItem );

                                        bRemove = true;
                                        break;
                                    }

                                    if ( bRemove )
                                        break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (ui->m_pGroupChannelTreeWidget->viewport() == obj) {
        // 拖拽时从链表中删除
        if (e->type() == QEvent::MouseButtonPress) {
            QMouseEvent *pMouseEvent = dynamic_cast<QMouseEvent *>( e );
            if (NULL != pMouseEvent) {
                if(pMouseEvent->buttons() & Qt::LeftButton) {
                    QList<QString> listdata;
                    // 单选
                    BCGroupChannelTreeWidgetItem *pDragItem = dynamic_cast<BCGroupChannelTreeWidgetItem*>( ui->m_pGroupChannelTreeWidget->itemAt( pMouseEvent->pos() ) );
                    if (NULL != pDragItem) {
                        if (NULL != pDragItem->m_pChannel) {
                            listdata << QString::number(pDragItem->m_pChannel->GetChannelType());
                            listdata << QString::number(pDragItem->m_pChannel->GetChannelID());
                            listdata << QString::number(pMouseEvent->pos().x());
                            listdata << QString::number(pMouseEvent->pos().y());
                        }
                    }

                    if ( !listdata.isEmpty() ) {
                        QByteArray exData;
                        QDataStream dataStream(&exData,QIODevice::WriteOnly);
                        dataStream << listdata;

                        QDrag *drag = new QDrag(this);
                        QMimeData *mimeData = new QMimeData();
                        mimeData->setData("removeSignalSourceInputChannel", exData);
                        drag->setMimeData(mimeData);

                        drag->exec(Qt::CopyAction);
                    }

                    return true;
                }
            }
        }
    }

    return QDialog::eventFilter(obj, e);
}

void BCSetSignalDlg::Init()
{
    // 默认不保存数据
    m_bPressOK = false;

    // 添加事件过滤
    ui->m_pGroupChannelTreeWidget->setAcceptDrops( true );      // 添加数据到组
    ui->m_pGroupChannelTreeWidget->installEventFilter( this );
    ui->m_pGroupChannelTreeWidget->viewport()->installEventFilter( this );
    ui->m_pInputChannelTreeWidget->setAcceptDrops( true );      // 移除组内数据
    ui->m_pInputChannelTreeWidget->viewport()->installEventFilter( this );

    // 设置信号源链表的拖拽属性
    ui->m_pSignalSourceListWidget->setDragEnabled(true);
    ui->m_pSignalSourceListWidget->setDragDropMode(QAbstractItemView::DragDrop);
    ui->m_pSignalSourceListWidget->setDefaultDropAction(Qt::MoveAction);

    // 调用MainWindow单例
    MainWindow *pApplication = BCCommon::Application();

    // ---------------------------------------------------------------------------------------------------------------------------------------
    // 1.初始化信号源链表
    QList<QPoint> lstType = GetSignalSourceSort();
    QListIterator<QPoint> it( lstType );
    while (it.hasNext()) {
        QPoint pt = it.next();

        // 新建自定义类型，初始化在构造函数内
        new BCSignalSourceListWidgetItem(pt, ui->m_pSignalSourceListWidget);
    }

    // ---------------------------------------------------------------------------------------------------------------------------------------
    // 2.初始化物理输入通道链表

    // 循环物理通道链表
    QList<BCMChannel *> lstChannel = pApplication->GetInputChannels();
    QListIterator<BCMChannel *> itChannel( lstChannel );
    while (itChannel.hasNext()) {
        BCMChannel *pChannel = itChannel.next();

        ui->m_pInputChannelTreeWidget->addTopLevelItem( new BCGroupChannelTreeWidgetItem(pChannel, ui->m_pInputChannelTreeWidget) );
    }

    ui->m_pInputChannelTreeWidget->expandAll();

    // ---------------------------------------------------------------------------------------------------------------------------------------
    // 3.初始化自定义输入通道链表

    // 用临时变量保存自定义通道链表
    QList<BCMGroupChannel *> lstGroupChannel = pApplication->GetGroupInputChannels();
    QListIterator<BCMGroupChannel *> itTempGroup( lstGroupChannel );
    while ( itTempGroup.hasNext() ) {
        BCMGroupChannel *pGroupChannel = itTempGroup.next();

        m_lstGroupInputChannels.append( pGroupChannel->Clone() );
    }

    // 循环自定义通道组
    QListIterator<BCMGroupChannel *> itGroup( m_lstGroupInputChannels );
    while ( itGroup.hasNext() ) {
        BCMGroupChannel *pGroupChannel = itGroup.next();

        // 添加通道组
        BCGroupChannelTreeWidgetItem *pGroupChannelItem = new BCGroupChannelTreeWidgetItem(pGroupChannel, ui->m_pGroupChannelTreeWidget);
        ui->m_pGroupChannelTreeWidget->addTopLevelItem( pGroupChannelItem );

        // 循环通道组内通道
        QList<BCMChannel *> lstGroupChannels = pGroupChannel->GetChannels();
        QListIterator<BCMChannel *> itGroupChannel( lstGroupChannels );
        while ( itGroupChannel.hasNext() ) {
            BCMChannel *pChannel = itGroupChannel.next();

            // 添加通道
            BCGroupChannelTreeWidgetItem *pChannelItem = new BCGroupChannelTreeWidgetItem(pGroupChannel, pChannel, pGroupChannelItem);
            pGroupChannelItem->addChild( pChannelItem );
        }
    }

    // 当自定义输入通道有改变时响应槽函数
    connect(ui->m_pGroupChannelTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(onItemChanged(QTreeWidgetItem*,int)));

    ui->m_pGroupChannelTreeWidget->expandAll();
}

void BCSetSignalDlg::on_m_pResetSignalSourceBtn_clicked()
{
    // 初始化信号源链表
    ui->m_pSignalSourceListWidget->clear();

    QList<QPoint> lstType = GetSignalSourceSort( 1 );
    QListIterator<QPoint> it( lstType );
    while (it.hasNext()) {
        QPoint pt = it.next();

        // 添加到链表
        ui->m_pSignalSourceListWidget->addItem( new BCSignalSourceListWidgetItem(pt, ui->m_pSignalSourceListWidget) );
    }
}

void BCSetSignalDlg::closeEvent(QCloseEvent *event)
{
    if ( m_bPressOK ) {
        // 1.将信号源排序的结果写入到文件
        QList<QPoint> lstSignalSources;
        for (int i = 0; i < ui->m_pSignalSourceListWidget->count(); i++) {
            BCSignalSourceListWidgetItem *pItem = dynamic_cast<BCSignalSourceListWidgetItem *>( ui->m_pSignalSourceListWidget->item(i) );
            if (NULL == pItem)
                continue;

            int x = pItem->m_type;
            int y = (pItem->checkState() == Qt::Checked) ? 1 : -1;

            // 将结果添加到链表
            lstSignalSources.append(QPoint(x, y));
        }

        // 写入文件
        SetSignalSourceSort( lstSignalSources );

        // 2.更新自定义分组链表
        MainWindow *pApplication = BCCommon::Application();

        // 函数内部自动析构数据
        pApplication->SetGroupInputChannels( m_lstGroupInputChannels );

        // 3.更新faceWidget的排列
        BCToolBar *pToolBar = pApplication->GetToolBar(MainWindow::SIGNALSOURCETOOLBAR);
        if (NULL != pToolBar) {
            BCFaceWidget* pWidget = dynamic_cast<BCFaceWidget *>( pToolBar->widget() );
            if (NULL != pWidget) {
                pWidget->Refresh();
            }
        }
    } else {
        // 删除复制链表
        while ( !m_lstGroupInputChannels.isEmpty() )
            delete m_lstGroupInputChannels.takeFirst();
    }

    event->accept();
}

void BCSetSignalDlg::on_m_pCancelBtn_clicked()
{
    this->close();
}

void BCSetSignalDlg::on_m_pOkBtn_clicked()
{
    m_bPressOK = true;

    this->close();
}

void BCSetSignalDlg::on_m_pAddGroupInputChannelBtn_clicked()
{
    MainWindow *pApplication = BCCommon::Application();

    BCMGroupChannel *pGroupChannel = new BCMGroupChannel( QString::number(pApplication->GetGroupChannelID()) );

    // add data
    m_lstGroupInputChannels.append( pGroupChannel );

    // add ui
    BCGroupChannelTreeWidgetItem *pGroupChannelItem = new BCGroupChannelTreeWidgetItem(pGroupChannel, ui->m_pGroupChannelTreeWidget);
    ui->m_pGroupChannelTreeWidget->addTopLevelItem( pGroupChannelItem );
}

void BCSetSignalDlg::on_m_pClearGroupInputChannelBtn_clicked()
{
    // clear ui
    ui->m_pGroupChannelTreeWidget->clear();

    // clear data
    while ( !m_lstGroupInputChannels.isEmpty() )
        delete m_lstGroupInputChannels.takeFirst();
}

void BCSetSignalDlg::on_m_pModifyInputChannelBtn_clicked()
{
    QTreeWidgetItem *pCurrentItem = ui->m_pGroupChannelTreeWidget->currentItem();
    if (NULL == pCurrentItem)
        return;

    BCGroupChannelTreeWidgetItem *pCurrentChannlItem = dynamic_cast<BCGroupChannelTreeWidgetItem *>( pCurrentItem );
    if (NULL == pCurrentChannlItem)
        return;

    if (NULL != pCurrentChannlItem->m_pChannel)
        return;

    // 设置当前item可编辑
    pCurrentItem->setFlags(pCurrentItem->flags() | Qt::ItemIsEditable);
    ui->m_pGroupChannelTreeWidget->editItem( pCurrentItem );
}

void BCSetSignalDlg::onItemChanged(QTreeWidgetItem *item, int /*column*/)
{
    BCGroupChannelTreeWidgetItem *pItem = dynamic_cast<BCGroupChannelTreeWidgetItem *>( item );
    if (NULL == pItem)
        return;

    QString qsName = pItem->text(0);

    // 根据当前item的类型进行赋值
    if ( pItem->IsChannel() )
        pItem->m_pChannel->SetChannelCustomName(pItem->m_pGroupChannel, qsName);
    else
        pItem->m_pGroupChannel->SetName( qsName );
}

void BCSetSignalDlg::on_m_pDelGroupInputChannelBtn_clicked()
{
    QList<QTreeWidgetItem*> lstSelectedItems = ui->m_pGroupChannelTreeWidget->selectedItems();
    if (lstSelectedItems.count() == 0)
        return;

    // 只处理通道组类
    QList<BCGroupChannelTreeWidgetItem *> lstGroupItems;
    QListIterator<QTreeWidgetItem*> it( lstSelectedItems );
    while ( it.hasNext() ) {
        BCGroupChannelTreeWidgetItem *pItem = dynamic_cast<BCGroupChannelTreeWidgetItem *>( it.next() );
        if (NULL == pItem)
            continue;

        if ( pItem->IsChannel() )
            continue;

        lstGroupItems.append( pItem );
    }

    // 没有通道组则直接返回
    if (lstGroupItems.count() == 0)
        return;

    // 循环删除自定义组
    QListIterator<BCGroupChannelTreeWidgetItem *> itGroup( lstGroupItems );
    while ( itGroup.hasNext() ) {
        BCGroupChannelTreeWidgetItem *pGroupItem = itGroup.next();
        BCMGroupChannel *pGroupChannel = pGroupItem->m_pGroupChannel;

        // remove ui
        ui->m_pGroupChannelTreeWidget->takeTopLevelItem( ui->m_pGroupChannelTreeWidget->indexOfTopLevelItem( pGroupItem ) );

        // remove data
        m_lstGroupInputChannels.removeOne( pGroupChannel );

        // delete data
        delete pGroupChannel;
        pGroupChannel = NULL;
    }
}
