#include "BCDecoder.h"
#include "ui_BCDecoder.h"
#include "../Common/BCCommon.h"
#include <QFileDialog>
#include <QAxObject>

// ---------------------------------------------------------------------------------------------------------------------------
// 读取IPV文件使用的类
class BCIPVNode
{
public:
    BCIPVNode(int level, const QString &name, const QString &ip, const QString &decoder, const QString &resolution, BCIPVNode *parent) {
        m_nLevel = level;
        m_qsName = name;
        m_qsIP = ip;
        m_qsDecoder = decoder;
        m_qsResolution = resolution;
        m_parent = parent;
    }
    ~BCIPVNode() {
        while ( !m_lstChild.isEmpty() )
            delete m_lstChild.takeFirst();
    }

    int     m_nLevel;       // 级别
    QString m_qsName;       // 名称
    QString m_qsIP;         // IP
    QString m_qsDecoder;    // 编码类型
    QString m_qsResolution; // 分辨率

    BCIPVNode           *m_parent;      // 父节点
    QList<BCIPVNode *>  m_lstChild;     // 孩子链表
};
// ---------------------------------------------------------------------------------------------------------------------------

BCDecoder::BCDecoder(bool bVisible, int minHeight, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCDecoder)
{
    m_pHeaderBtn = NULL;

    m_bModifyHeight = false;
    m_bPress = false;

    ui->setupUi(this);
    setAttribute( Qt::WA_Hover,true);

    m_minHeight = minHeight;
    ui->frame->setMinimumHeight(minHeight);

    // init header
    m_pHeaderBtn = new BCWidgetBtn(this, MainWindow::DECODERSIGSRC, bVisible);
    ui->verticalLayout->addWidget(m_pHeaderBtn);

    connect(m_pHeaderBtn, SIGNAL(sigSetVisible(bool)), this, SLOT(onSetVisible(bool)));
    onSetVisible( bVisible );

    // 设置权限
    MainWindow *pMainWindow = BCCommon::Application();
    if (pMainWindow->GetCurrentUser()->level > 1) {
        ui->m_pSelectFileBtn->setVisible( false );
        ui->m_pExportBtn->setVisible( false );
    }
}

BCDecoder::~BCDecoder()
{
    delete ui;
}

void BCDecoder::onSetVisible(bool bVisible)
{
    ui->frame->setVisible( bVisible );
}

bool BCDecoder::IsVisible()
{
    return m_pHeaderBtn->IsVisible();
}

/*
 *  1.解析txt文件，并转存成xml文件
 *  2.可以分父子关系，使用制表符区分，excel转存txt时默认使用制表符
 *  3.父节点只有一个属性(name)，子节点有三个属性(name, ip, maker)
 */

void BCDecoder::on_m_pSelectFileBtn_clicked()
{
    QFileDialog dlg( this );
    dlg.setNameFilter(tr("IP List (*.txt *.xls *.xlsx)"));
    if ( dlg.exec() ) {
        QStringList fileList = dlg.selectedFiles();
        if ( fileList.isEmpty() )
            return;

        // 构造根节点
        BCIPVNode *pRootNode = new BCIPVNode(-1, "root", "Default", "H264", "1920*1080", NULL);

        QString qsPath = fileList.first();
        if ( qsPath.contains(".txt") ) {
            ReadTextFile(qsPath, pRootNode);
        } else if (qsPath.contains(".xls") || qsPath.contains(".xlsx")) {
            ReadExcelFile(qsPath, pRootNode);
        }

        // 更新XML文件内容
        UpdateXmlContent( pRootNode );

        // 析构节点数据
        delete pRootNode;
        pRootNode = NULL;
    }
}

void BCDecoder::on_m_pExportBtn_clicked()
{
    QFileDialog dlg( this );
    //dlg.setNameFilter(tr("IP List (*.txt *.xls *.xlsx)"));
    dlg.setNameFilter(tr("IP List (*.txt)"));
    if ( dlg.exec() ) {
        QStringList fileList = dlg.selectedFiles();
        if ( fileList.isEmpty() )
            return;

        QFile file( fileList.first() );
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream in(&file);

        for (int i = 0; i < ui->m_pDecoderTreeWidget->topLevelItemCount(); i++) {
            WriteTextFile(ui->m_pDecoderTreeWidget->topLevelItem(i), in);
            if (i != ui->m_pDecoderTreeWidget->topLevelItemCount()-1) {
                in << "\n";
            }
        }

        file.close();
    }
}

void BCDecoder::WriteTextFile(QTreeWidgetItem *pItem, QTextStream &in)
{
    BCDecoderTreeWidgetItem *pSelfItem = dynamic_cast<BCDecoderTreeWidgetItem *>( pItem );
    if (NULL == pSelfItem)
        return;

    // 添加缩进
    for (int i = 0; i < pSelfItem->m_nLevel; i++) {
        in << "\t";
    }

    // add data
    in << pSelfItem->m_qsName << "\t" << pSelfItem->m_qsIP << "\t" << pSelfItem->m_qsDecoder << "\t" << pSelfItem->m_qsResolution;

    // add enter
    if (0 != pSelfItem->childCount()) {
        in << "\n";
    }

    // add children
    for (int j = 0; j < pSelfItem->childCount(); j++) {
        WriteTextFile(pSelfItem->child( j ), in);
        if (j != pSelfItem->childCount()-1) {
            in << "\n";
        }
    }
}

bool BCDecoder::IsExistNextNode(QTreeWidgetItem *pItem)
{
    if (NULL == pItem)
        return false;

    int index = -1;
    if (NULL == pItem->parent()) {
        index = pItem->treeWidget()->indexOfTopLevelItem( pItem );
        if (index == pItem->treeWidget()->topLevelItemCount()-1)
            return false;
        else
            return true;
    } else {
        index = pItem->parent()->indexOfChild( pItem );
        if (index == pItem->parent()->childCount()-1)
            return IsExistNextNode( pItem->parent() );
        else
            return true;
    }
}

void BCDecoder::ReadTextFile(const QString &path, BCIPVNode *pRootNode)
{
    QFile file( path );
    if( !file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    BCIPVNode *pPreNode = pRootNode;
    while ( !file.atEnd() ) {
        QByteArray line = file.readLine();
        QString ip(line);
        ip.replace(QString("\n"), QString(""));     // 去掉回车换行符

        // 判断字符前有多少个制表符，并去掉制表符
        int nCurrentLevel = 0;
        for (int i = 1; i < ip.count(); i++) {
            QString qsIpHeader = ip.left(i);

            if (qsIpHeader.right(1) == QString("\t"))
                continue;

            // 去掉IP前的制表符
            ip = ip.right(ip.count()-i+1);
            nCurrentLevel = i-1;
            break;
        }

        // 获得当前行的属性，因为使用excel导出的数据是制表符分割的
        QString qsNodeName, qsNodeIP, qsNodeDecoder, qsNodeResolution;
        QStringList lstAttribute = ip.split("\t");
        int nAttributeCount = lstAttribute.count();
        if (nAttributeCount == 1) {
            qsNodeName = lstAttribute.first();
        } else if (nAttributeCount == 2) {
            qsNodeName = lstAttribute.at(0);
            qsNodeIP = lstAttribute.at(1);
        } else if (nAttributeCount > 3) {
            qsNodeName = lstAttribute.at(0);
            qsNodeIP = lstAttribute.at(1);
            qsNodeDecoder = lstAttribute.at(2);
            qsNodeResolution = lstAttribute.at(3);
        }

        // 1.级别相等时，父类相同
        if (pPreNode->m_nLevel == nCurrentLevel) {
            BCIPVNode *pFactParent = pPreNode->m_parent;
            if (NULL != pFactParent) {
                BCIPVNode *pCurrentNode = new BCIPVNode(nCurrentLevel, qsNodeName, qsNodeIP, qsNodeDecoder, qsNodeResolution, pFactParent);

                pFactParent->m_lstChild.append( pCurrentNode );
                pPreNode = pCurrentNode;
            }
        }

        // 2.当前级别少，需要向上找到父，然后添加子类
        if ((pPreNode->m_nLevel > nCurrentLevel) && (nCurrentLevel > -1)) {
            int nTimes = pPreNode->m_nLevel - nCurrentLevel;
            BCIPVNode *pFactParent = pPreNode->m_parent;
            while (nTimes != 0) {
                pFactParent = pFactParent->m_parent;
                if (NULL == pFactParent)
                    break;

                nTimes--;
            }

            if (NULL != pFactParent) {
                BCIPVNode *pCurrentNode = new BCIPVNode(nCurrentLevel, qsNodeName, qsNodeIP, qsNodeDecoder, qsNodeResolution, pFactParent);

                pFactParent->m_lstChild.append( pCurrentNode );
                pPreNode = pCurrentNode;
            }
        }

        // 3.当前级别多1，上一个添加子
        if (pPreNode->m_nLevel == nCurrentLevel-1) {
            BCIPVNode *pFactParent = pPreNode;
            if (NULL != pFactParent) {
                BCIPVNode *pCurrentNode = new BCIPVNode(nCurrentLevel, qsNodeName, qsNodeIP, qsNodeDecoder, qsNodeResolution, pFactParent);

                pFactParent->m_lstChild.append( pCurrentNode );
                pPreNode = pCurrentNode;
            }
        }

        // 4.其他情况视为数据有误
    }

    // 关闭txt文件
    file.close();
}

void BCDecoder::ReadExcelFile(const QString &path, BCIPVNode *pRootNode)
{
    qDebug() << path;
    QAxObject *excel = new QAxObject("Excel.Application");
    if ( !excel )
        return;

    // 获得第一个sheet页
    excel->dynamicCall("SetVisible(bool)", false);
    QAxObject *workbooks = excel->querySubObject("WorkBooks");
    QAxObject *workbook = workbooks->querySubObject("Open(QString, QVariant)", path);
    QAxObject *worksheet = workbook->querySubObject("WorkSheets(int)", 1);//打开第一个sheet

    QAxObject *usedrange = worksheet->querySubObject("UsedRange");//获取该sheet的使用范围对象
    QAxObject *rows = usedrange->querySubObject("Rows");
    QAxObject *columns = usedrange->querySubObject("Columns");

    int nRowStart = usedrange->property("Row").toInt();
    int nColStart = usedrange->property("Column").toInt();
    int nRows = rows->property("Count").toInt();
    int nCols = columns->property("Count").toInt();

    // 遍历所有数据
    BCIPVNode *pPreNode = pRootNode;
    for (int i = nRowStart; i < nRowStart+nRows; i++) {
        // 判断级别
        int nCurrentLevel = 0;
        for (int j = nColStart; j < nColStart+nCols-2; j++) {
            QAxObject *cell = worksheet->querySubObject("Cells(int,int)", i, j);
            QString qsName = cell->dynamicCall("Value2()").toString();

            if ( qsName.isEmpty() )
                continue;

            nCurrentLevel = j-nColStart;
            break;
        }

        // 根据级别取基础属性
        QAxObject *cell = worksheet->querySubObject("Cells(int,int)", i, nCurrentLevel+nColStart+0);
        QString qsNodeName = cell->dynamicCall("Value2()").toString();
        cell = worksheet->querySubObject("Cells(int,int)", i, nCurrentLevel+nColStart+1);
        QString qsNodeIP = cell->dynamicCall("Value2()").toString();
        cell = worksheet->querySubObject("Cells(int,int)", i, nCurrentLevel+nColStart+2);
        QString qsNodeDecoder = cell->dynamicCall("Value2()").toString();
        cell = worksheet->querySubObject("Cells(int,int)", i, nCurrentLevel+nColStart+3);
        QString qsNodeResolution = cell->dynamicCall("Value2()").toString();

        // 1.级别相等时，父类相同
        if (pPreNode->m_nLevel == nCurrentLevel) {
            BCIPVNode *pFactParent = pPreNode->m_parent;
            if (NULL != pFactParent) {
                BCIPVNode *pCurrentNode = new BCIPVNode(nCurrentLevel, qsNodeName, qsNodeIP, qsNodeDecoder, qsNodeResolution, pFactParent);

                pFactParent->m_lstChild.append( pCurrentNode );
                pPreNode = pCurrentNode;
            }
        }

        // 2.当前级别少，需要向上找到父，然后添加子类
        if ((pPreNode->m_nLevel > nCurrentLevel) && (nCurrentLevel > -1)) {
            int nTimes = pPreNode->m_nLevel - nCurrentLevel;
            BCIPVNode *pFactParent = pPreNode->m_parent;
            while (nTimes != 0) {
                pFactParent = pFactParent->m_parent;
                if (NULL == pFactParent)
                    break;

                nTimes--;
            }

            if (NULL != pFactParent) {
                BCIPVNode *pCurrentNode = new BCIPVNode(nCurrentLevel, qsNodeName, qsNodeIP, qsNodeDecoder, qsNodeResolution, pFactParent);

                pFactParent->m_lstChild.append( pCurrentNode );
                pPreNode = pCurrentNode;
            }
        }

        // 3.当前级别多1，上一个添加子
        if (pPreNode->m_nLevel == nCurrentLevel-1) {
            BCIPVNode *pFactParent = pPreNode;
            if (NULL != pFactParent) {
                BCIPVNode *pCurrentNode = new BCIPVNode(nCurrentLevel, qsNodeName, qsNodeIP, qsNodeDecoder, qsNodeResolution, pFactParent);

                pFactParent->m_lstChild.append( pCurrentNode );
                pPreNode = pCurrentNode;
            }
        }

        // 4.其他情况视为数据有误
    }

    workbook->dynamicCall("Close (Boolean)", false);

    excel->deleteLater();
    //delete excel;//一定要记得删除，要不线程中会一直打开excel.exe
}

void BCDecoder::UpdateXmlContent(BCIPVNode *pNode)
{
    QDomDocument doc;

    // 添加根节点
    QDomElement eleRoot = doc.createElement(QString("Node"));
    eleRoot.setAttribute(QString("name"), pNode->m_qsName);
    eleRoot.setAttribute(QString("ip"), pNode->m_qsIP);
    eleRoot.setAttribute(QString("decoder"), pNode->m_qsDecoder);
    eleRoot.setAttribute(QString("resolution"), pNode->m_qsResolution);
    eleRoot.setAttribute(QString("level"), QString::number(pNode->m_nLevel));
    doc.appendChild( eleRoot );

    // 循环添加子节点
    for (int i = 0; i < pNode->m_lstChild.count(); i++) {
        BCIPVNode *pChildNode = pNode->m_lstChild.at(i);

        AddNode(doc, eleRoot, pChildNode);
    }

    // 写入文件
    QFile file( QString("../xml/BCIPVideoConfig.xml") );
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();

    // 更新内部数据
    ui->m_pDecoderTreeWidget->Refresh();
}

QString BCDecoder::GetName(QString url)
{
    return ui->m_pDecoderTreeWidget->GetName( url );
}

void BCDecoder::AddNode(QDomDocument &doc, QDomElement &parent, BCIPVNode *pNode)
{
    if (NULL == pNode)
        return;

    QDomElement eleCurrentNode = doc.createElement(QString("Node"));
    eleCurrentNode.setAttribute(QString("name"), pNode->m_qsName);
    eleCurrentNode.setAttribute(QString("ip"), pNode->m_qsIP);
    eleCurrentNode.setAttribute(QString("decoder"), pNode->m_qsDecoder);
    eleCurrentNode.setAttribute(QString("resolution"), pNode->m_qsResolution);
    eleCurrentNode.setAttribute(QString("level"), pNode->m_nLevel);
    //QDomNode node = parent.appendChild( eleCurrentNode );
    parent.appendChild( eleCurrentNode );

    for (int i = 0; i < pNode->m_lstChild.count(); i++) {
        BCIPVNode *pChild = pNode->m_lstChild.at(i);
        AddNode(doc, eleCurrentNode, pChild);
    }
}

void BCDecoder::on_m_pFilterLineEdit_textChanged(const QString &arg1)
{
    // 更新内部数据
    ui->m_pDecoderTreeWidget->Filter( arg1 );
}

const QList<sIPInfo> &BCDecoder::GetIPList()
{
    return ui->m_pDecoderTreeWidget->m_lstCameraIP;
}

bool BCDecoder::event(QEvent *event)
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

void BCDecoder::mousePressEvent(QMouseEvent *e)
{
    if ((e->button() == Qt::LeftButton) && m_bModifyHeight) {
        m_bPress = true;
    }

    QWidget::mousePressEvent( e );
}

void BCDecoder::mouseMoveEvent(QMouseEvent *e)
{
    if( m_bPress ) {
        m_minHeight = e->pos().y() - m_pHeaderBtn->height() - 10;

        ui->frame->setMinimumHeight( m_minHeight );
    }

    QWidget::mouseMoveEvent( e );
}

void BCDecoder::mouseReleaseEvent(QMouseEvent *e)
{
    m_bPress = false;

    QWidget::mouseReleaseEvent( e );
}

