#include "BCSettingPerviewDlg.h"
#include "ui_BCSettingPerviewDlg.h"
#include <QMessageBox>
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"
#include "../View/BCRibbonMainToolBar.h"

class BCPerviewTreeWidgetItem : public QTreeWidgetItem
{
public:
    BCPerviewTreeWidgetItem(int type, int value, const QString &text, QTreeWidget *parent);
    BCPerviewTreeWidgetItem(int type, int value, const QString &text, QTreeWidgetItem *parent);

    int m_type;
    int m_value;
};

BCPerviewTreeWidgetItem::BCPerviewTreeWidgetItem(int type, int value, const QString &text, QTreeWidget *parent)
    :QTreeWidgetItem( parent )
{
    m_type = type;
    m_value = value;

    this->setText(0, text);
}

BCPerviewTreeWidgetItem::BCPerviewTreeWidgetItem(int type, int value, const QString &text, QTreeWidgetItem *parent)
    :QTreeWidgetItem( parent )
{
    m_type = type;
    m_value = value;

    this->setText(0, text);
}

// -----------------------------------------------------------------------------------------------------------------------------

BCSettingPerviewDlg::BCSettingPerviewDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingPerviewDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("用户管理"));
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));

    m_map.insert(0, tr("系统用户"));
    m_map.insert(1, tr("管理员"));
    m_map.insert(2, tr("操作员"));
    m_map.insert(3, tr("用户"));

    // 3中级别用户的默认权限
    m_lstManagerID << 100 << 101 << 148 << 144 << 143 << 102 << 103 << 104 << 105 << 106 << 111 << 167 << 169 << 170 << 112
                   << 153 << 171 << 168 << 176 << 177 << 172 << 128 << 131 << 126 << 127 << 129 << 130 << 108 << 110 << 175 << 173 << 139;
    m_lstOperatorID << 100 << 101 << 148 << 144 << 143 << 102 << 103 << 104 << 105 << 106 << 111 << 167 << 169 << 170 << 112
                    << 177 << 128 << 131 << 126 << 127 << 108 << 110 << 173;
    m_lstUserID << 100 << 101 << 148 << 144 << 143 << 102 << 106 << 111 << 167 << 169 << 170 << 112
                << 177 << 128 << 131 << 126 << 127 << 108 << 110;

    Init();
}

BCSettingPerviewDlg::~BCSettingPerviewDlg()
{
    delete ui;
}

void BCSettingPerviewDlg::Init()
{
    // 设置属性
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中
    ui->tableWidget->setShowGrid(false);//不显示内部的格子线条
    connect(ui->tableWidget, SIGNAL(currentCellChanged(int, int, int, int)), this, SLOT(onCurrentCellChanged(int,int,int,int)));

    ui->treeWidget->setHeaderHidden(true);

    // 设置列名
    QStringList lstHeader;
    lstHeader << tr("ID") << tr("用户名") << tr("密码") << tr("权限");
    ui->tableWidget->setHorizontalHeaderLabels( lstHeader );
    ui->tableWidget->setColumnWidth(0, 30);

    // 添加数据
    BCLocalServer *pServer = BCLocalServer::Application();
    QStringList lstUsers = pServer->GetUsers();

    // 如果是空或者数量不是4的倍数则数据不对，直接返回
    if (lstUsers.isEmpty() || (lstUsers.count()%4 != 0))
        return;

    int nCount = lstUsers.count() / 4;

    QStringList lstValidUsers;
    MainWindow *pMainWindow = BCCommon::Application();
    BCSUser *pUser = pMainWindow->GetCurrentUser();
    if (pUser->level != 0) { // 只有root可见
        ui->m_pResetDefaultMainToolBarBtn->setVisible( false );
    }
    for (int i = 0; i < nCount; i++) {
        int id = lstUsers.at(i*4 + 0).toInt();
        int level = lstUsers.at(i*4 + 3).toInt();

        // 下级用于看不了上级用户权限
        if (pUser->level > level)
            continue;
        else if (pUser->level == level) {   // 如果同级只能看自己的用户
            if (pUser->id != id)
                continue;
        }

        lstValidUsers << lstUsers.at(i*4 + 0)
                      << lstUsers.at(i*4 + 1)
                      << lstUsers.at(i*4 + 2)
                      << lstUsers.at(i*4 + 3);
    }

    nCount = lstValidUsers.count() / 4;
    ui->tableWidget->setRowCount( nCount );

    for (int i = 0; i < nCount; i++) {
        QString qsID = lstValidUsers.at(i*4 + 0);
        QString qsUser = lstValidUsers.at(i*4 + 1);
        QString qsPassword = lstValidUsers.at(i*4 + 2);
        int level = lstValidUsers.at(i*4 + 3).toInt();

        QTableWidgetItem *pItem1 = new QTableWidgetItem( qsID );
        QTableWidgetItem *pItem2 = new QTableWidgetItem( qsUser );
        QTableWidgetItem *pItem3 = new QTableWidgetItem( qsPassword );
        QTableWidgetItem *pItem4 = new QTableWidgetItem( m_map.value(level) );

        ui->tableWidget->setItem(i, 0, pItem1);
        ui->tableWidget->setItem(i, 1, pItem2);
        ui->tableWidget->setItem(i, 2, pItem3);
        ui->tableWidget->setItem(i, 3, pItem4);
    }
}

void BCSettingPerviewDlg::onCurrentCellChanged(int currentRow, int /*currentColumn*/, int previousRow, int /*previousColumn*/)
{
    if (currentRow == previousRow)
        return;

    QString qsID = ui->tableWidget->item(currentRow, 0)->text();
    QString qsUser = ui->tableWidget->item(currentRow, 1)->text();
    QString qsPsw = ui->tableWidget->item(currentRow, 2)->text();
    QString qsLevel = ui->tableWidget->item(currentRow, 3)->text();
    int level = m_map.key( qsLevel );

    ui->userNameEdit->setText( qsUser );
    ui->passwordEdit->setText( qsPsw );
    if (0 == level) {
        ui->m_pModifyBtn->setEnabled( false );
    } else {
        ui->m_pModifyBtn->setEnabled( true );
        ui->m_pUserPreviewComboBox->setCurrentIndex( level-1 );
    }

    RefreshTreeWidget(qsID.toInt(), level);
}

void BCSettingPerviewDlg::on_removeBut_clicked()
{
   if(ui->tableWidget->currentRow() == -1)
       return;

   int id = ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->text().toInt();
   QString user = ui->tableWidget->item(ui->tableWidget->currentRow(), 1)->text();
   if (user == "root") {
       QMessageBox::information(this, tr("提示"), tr("系统默认用户，不可删除!"));
       return;
   }

   BCLocalServer *pServer = BCLocalServer::Application();
   pServer->RemoveUser( id );

   ui->tableWidget->removeRow( ui->tableWidget->currentRow() );
}

void BCSettingPerviewDlg::on_addBut_clicked()
{
    if ( ui->userNameEdit->text().isEmpty() ) {
        QMessageBox::information(this, tr("提示"), tr("用户名不能为空!"));
        return;
    }

    QString qsUser = ui->userNameEdit->text();
    QString qsPsw = ui->passwordEdit->text();

    // 确定添加用户的ID
    QList<int> lstExistID;
    for(int i = 0; i < ui->tableWidget->rowCount(); i++) {
        QString qsExistUser = ui->tableWidget->item(i, 1)->text();
        if (qsExistUser == qsUser) {
            QMessageBox::information(this, tr("提示"), tr("用户名已存在!"));
            return;
        }

        int nExistID = ui->tableWidget->item(i, 0)->text().toInt();
        lstExistID.append( nExistID );
    }

    int nAddID = ui->tableWidget->rowCount();
    for (int i = 1; i < ui->tableWidget->rowCount()+2; i++) {
        if ( lstExistID.contains( i ) )
            continue;

        nAddID = i;
        break;
    }

    int level = ui->m_pUserPreviewComboBox->currentIndex()+1;
    MainWindow *pMainWindow = BCCommon::Application();
    BCSUser *pUser = pMainWindow->GetCurrentUser();
    if (pUser->level >= level) {
        QMessageBox::information(this, tr("提示"), tr("不可添加同级别或级别更高的用户!"));
        return;
    }

    // 添加数据库
    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->AddUser(nAddID, qsUser, qsPsw, level);

    // 添加数据库内的级别是level的默认权限
    QList<sTab> lstTab = pServer->GetUserMainToolBar( 0 );  // admin是所有权限
    QList<sTab> lstUserTab;                                 // 根据级别构造用户tab
    QList<int> lstLevelButton = (1 == level) ? m_lstManagerID : ((2 == level) ? m_lstOperatorID : m_lstUserID);

    for (int i = 0; i < lstTab.count(); i++) {
        sTab stab = lstTab.at( i );

        sTab userstab;
        userstab.tab = stab.tab;

        for (int j = 0; j < stab.lstGroup.count(); j++) {
            sGroup sgroup = stab.lstGroup.at( j );

            sGroup usersgroup;
            usersgroup.group = sgroup.group;

            // 判断是否包含当前按钮
            for (int k = 0; k < sgroup.lstButton.count(); k++) {
                int button = sgroup.lstButton.at( k );

                if ( lstLevelButton.contains(button) )
                    usersgroup.lstButton.append( button );
            }

            if ( !usersgroup.lstButton.isEmpty() )
                userstab.lstGroup.append( usersgroup );
        }

        if ( !userstab.lstGroup.isEmpty() )
            lstUserTab.append( userstab );
    }

    // 添加到数据库
    pServer->SetUserMainToolBar(nAddID, lstUserTab);

    // 添加界面
    int nRowCount = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(nRowCount+1);

    QTableWidgetItem *pItem1 = new QTableWidgetItem( QString::number(nAddID) );
    QTableWidgetItem *pItem2 = new QTableWidgetItem( qsUser );
    QTableWidgetItem *pItem3 = new QTableWidgetItem( qsPsw );
    QTableWidgetItem *pItem4 = new QTableWidgetItem( ui->m_pUserPreviewComboBox->currentText() );

    ui->tableWidget->setItem(nRowCount, 0, pItem1);
    ui->tableWidget->setItem(nRowCount, 1, pItem2);
    ui->tableWidget->setItem(nRowCount, 2, pItem3);
    ui->tableWidget->setItem(nRowCount, 3, pItem4);

    // 修改treewidget的权限
    ui->tableWidget->setCurrentItem( pItem1 );
}

void BCSettingPerviewDlg::on_m_pModifyBtn_clicked()
{
    if(ui->tableWidget->currentRow() == -1) {
        QMessageBox::information(this, tr("提示"), tr("请选中修改的用户!"));
        return;
    }

    if ( ui->userNameEdit->text().isEmpty() ) {
        QMessageBox::information(this, tr("提示"), tr("用户名不能为空!"));
        return;
    }

    QString qsUser = ui->userNameEdit->text();
    QString qsPsw = ui->passwordEdit->text();
    QString qsLevel = ui->m_pUserPreviewComboBox->currentText();

    int id = ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->text().toInt();
    ui->tableWidget->item(ui->tableWidget->currentRow(), 1)->setText( qsUser );
    ui->tableWidget->item(ui->tableWidget->currentRow(), 2)->setText( qsPsw );
    ui->tableWidget->item(ui->tableWidget->currentRow(), 3)->setText( qsLevel );

    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->ModifyUser(id, qsUser, qsPsw, m_map.key(qsLevel));
}

void BCSettingPerviewDlg::on_m_pResetDefaultMainToolBarBtn_clicked()
{
    // 判断文件是否可读
    QFile file( QString("../xml/SystemPurviewData.xml") );
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
    QDomNodeList lstNodes = docElem.childNodes();

    QList<sTab> lstTab;

    // 加载权限表
    QDomNode nodePurviews;
    if ( GetDomNode(lstNodes, QString("SystemPurview"), nodePurviews) ) {
        // loop purview level
        if (nodePurviews.childNodes().count() > 0) {
            QDomNode nodePurview = nodePurviews.childNodes().at(0);
            if ( !nodePurview.isElement() )
                return;

            // 层级权限
            QDomElement elePurview = nodePurview.toElement();

            // 循环主工具条权限
            QDomNode nodeTabs;
            if ( GetDomNode(elePurview.childNodes(), QString("MainToolBar"), nodeTabs) ) {
                for (int j = 0; j < nodeTabs.childNodes().count(); j++) {
                    QDomNode nodeTab = nodeTabs.childNodes().at( j );
                    if (!nodeTab.isElement())
                        continue;

                    // 添加tab
                    QDomElement eleTab = nodeTab.toElement();
                    sTab stab;
                    stab.tab = eleTab.attribute("Type").toInt();
                    for (int k = 0; k < eleTab.childNodes().count(); k++) {
                        QDomNode nodeGroup = eleTab.childNodes().at( k );
                        if (!nodeGroup.isElement())
                            continue;

                        // 添加group
                        QDomElement eleGroup = nodeGroup.toElement();
                        sGroup sgroup;
                        sgroup.group = eleGroup.attribute("Type").toInt();
                        for (int l = 0; l < eleGroup.childNodes().count(); l++) {
                            QDomNode nodeButtonType = eleGroup.childNodes().at( l );
                            if (!nodeButtonType.isElement())
                                continue;

                            // 添加按钮
                            QDomElement eleButtonType = nodeButtonType.toElement();
                            QString qsButtonTypes = eleButtonType.attribute("Type");
                            if ( !qsButtonTypes.isEmpty() ) {
                                if ( qsButtonTypes.contains(";") ) {    // 如果是多个则分开后循环添加
                                    QStringList lstButtonTypes = qsButtonTypes.split(QString(";"));
                                    for (int m = 0; m < lstButtonTypes.count(); m++) {
                                        sgroup.lstButton.append( lstButtonTypes.at(m).toInt() );
                                    }
                                } else {    // 如果只有一个则直接添加
                                    sgroup.lstButton.append( qsButtonTypes.toInt() );
                                }
                            }
                        }

                        stab.lstGroup.append( sgroup );
                    }

                    lstTab.append( stab );
                }
            }
        }
    }

    BCLocalServer *pServer = BCLocalServer::Application();

    // 给root用户配置权限
    pServer->SetUserMainToolBar(0, lstTab);
}

bool BCSettingPerviewDlg::GetDomNode(const QDomNodeList &lst, const QString &qsNodeName, QDomNode &node)
{
    for (int i = 0; i < lst.count(); i++) {
        QDomNode tempNode = lst.at( i );
        if ( !tempNode.isElement() )
            continue;

        if (tempNode.nodeName() != qsNodeName)
            continue;

        // 赋值 node
        node = tempNode;
        return true;
    }

    return false;
}

void BCSettingPerviewDlg::RefreshTreeWidget(int userid, int level)
{
    BCRibbonMainToolBar *pMainToolBar = BCCommon::Application()->GetRibbonMainToolBar();
    if (NULL == pMainToolBar)
        return;

    ui->treeWidget->clear();
    disconnect(ui->treeWidget, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(onItemChanged(QTreeWidgetItem*,int)));

    BCLocalServer *pServer = BCLocalServer::Application();
    QList<sTab> lstTab = pServer->GetUserMainToolBar( 0 );

    // 取当前用户的权限
    bool bModifyUserPerview = true;
    if (0 == level) {
        bModifyUserPerview = false;
    }
    MainWindow *pMainWindow = BCCommon::Application();
    BCSUser *pUser = pMainWindow->GetCurrentUser();
    if (pUser->level == level) {
        bModifyUserPerview = false;
    }
    QList<int> lstUserTab;
    QList<int> lstUserGroup;
    QList<int> lstUserButton;
    if ( bModifyUserPerview ) {
        QList<sTab> lstUsersTab = pServer->GetUserMainToolBar( userid );
        for (int i = 0; i < lstUsersTab.count(); i++) {
            sTab stab = lstUsersTab.at(i);
            lstUserTab.append( stab.tab );
            for (int j = 0; j < stab.lstGroup.count(); j++) {
                sGroup sgroup = stab.lstGroup.at(j);
                lstUserGroup.append( sgroup.group );
                lstUserButton.append( sgroup.lstButton );
            }
        }
    }

    for (int i = 0; i < lstTab.count(); i++) {
        sTab stab = lstTab.at( i );

        BCPerviewTreeWidgetItem *pTabItem = new BCPerviewTreeWidgetItem(0, stab.tab, pMainToolBar->GetTabName((BCRibbonMainToolBar::TABTYPE)stab.tab), ui->treeWidget);
        ui->treeWidget->addTopLevelItem( pTabItem );

        int nGroupChecked = -1;
        for (int j = 0; j < stab.lstGroup.count(); j++) {
            sGroup sgroup = stab.lstGroup.at(j);

            BCPerviewTreeWidgetItem *pGroupItem = new BCPerviewTreeWidgetItem(1, sgroup.group, pMainToolBar->GetGroupName((BCRibbonMainToolBar::GROUPTYPE)sgroup.group), pTabItem);
            pTabItem->addChild( pGroupItem );

            int nButtonChecked = -1; // 全部勾选1，部分勾选0，没有勾选-1
            for (int k = 0; k < sgroup.lstButton.count(); k++) {
                int button = sgroup.lstButton.at( k );
                if ((129 == button) && (pUser->level > 1))
                    continue;

                BCPerviewTreeWidgetItem *pButtonItem = new BCPerviewTreeWidgetItem(2, button, pMainToolBar->GetButtonName((BCRibbonMainToolBar::BUTTONTYPE)button), pGroupItem);
                pGroupItem->addChild( pButtonItem );

                // 设置按钮是选择还是非选择
                if ( bModifyUserPerview ) {
                    if ( lstUserButton.contains(button) ) {
                        pButtonItem->setCheckState(0, Qt::Checked);
                        if (-1 == nButtonChecked) {
                            nButtonChecked = 1;
                        }
                    } else {
                        pButtonItem->setCheckState(0, Qt::Unchecked);
                        if (1 == nButtonChecked) {
                            nButtonChecked = 0;
                        }
                    }
                }
            }

            // 当没有按钮时是不选，否则判断是全选还是半选
            if ( bModifyUserPerview ) {
                if (-1 == nButtonChecked) {
                    pGroupItem->setCheckState(0, Qt::Unchecked);
                    if (1 == nGroupChecked) {
                        nGroupChecked = 0;
                    }
                } else if (1 == nButtonChecked) {
                    pGroupItem->setCheckState(0, Qt::Checked);
                    if (-1 == nGroupChecked) {
                        nGroupChecked = 1;
                    }
                } else {
                    pGroupItem->setCheckState(0, Qt::PartiallyChecked);
                    nGroupChecked = 0;
                }
            }
        }

        // 当没有组时是不选，否则判断是全选还是半选
        if ( bModifyUserPerview ) {
            if (-1 == nGroupChecked) {
                pTabItem->setCheckState(0, Qt::Unchecked);
            } else if (1 == nGroupChecked)
                pTabItem->setCheckState(0, Qt::Checked);
            else
                pTabItem->setCheckState(0, Qt::PartiallyChecked);
        }
    }

    ui->treeWidget->expandAll();

    connect(ui->treeWidget, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(onItemChanged(QTreeWidgetItem*,int)));
}

void BCSettingPerviewDlg::on_m_pModifyPerviewBtn_clicked()
{
    // 管理员不修改权限
    int id = ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->text().toInt();
    QString user = ui->tableWidget->item(ui->tableWidget->currentRow(), 1)->text();
    if (user == "root")
        return;

    QList<sTab> lstTab;

    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); i++) {
        BCPerviewTreeWidgetItem *pTabItem = dynamic_cast<BCPerviewTreeWidgetItem *>( ui->treeWidget->topLevelItem( i ) );
        if (NULL == pTabItem)
            continue;

        sTab stab;
        stab.tab = pTabItem->m_value;

        for (int j = 0; j < pTabItem->childCount(); j++) {
            BCPerviewTreeWidgetItem *pGroupItem = dynamic_cast<BCPerviewTreeWidgetItem *>( pTabItem->child(j) );
            if (NULL == pGroupItem)
                continue;

            sGroup sgroup;
            sgroup.group = pGroupItem->m_value;

            for (int k = 0; k < pGroupItem->childCount(); k++) {
                BCPerviewTreeWidgetItem *pButtonItem = dynamic_cast<BCPerviewTreeWidgetItem *>( pGroupItem->child(k) );
                if (NULL == pButtonItem)
                    continue;

                if (pButtonItem->checkState(0) == Qt::Checked)
                    sgroup.lstButton.append( pButtonItem->m_value );
            }

            if (pGroupItem->checkState(0) != Qt::Unchecked)
                stab.lstGroup.append( sgroup );
        }

        if (pTabItem->checkState(0) != Qt::Unchecked)
            lstTab.append( stab );
    }

    // 添加到数据库
    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->SetUserMainToolBar(id, lstTab);
}

void BCSettingPerviewDlg::onItemChanged(QTreeWidgetItem *item, int /*column*/)
{
    disconnect(ui->treeWidget, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(onItemChanged(QTreeWidgetItem*,int)));

    // 更新父节点
    updateParentItem(item);
    // 更新子节点
    updateChildItem(item, (Qt::Checked == item->checkState(0)) ? 1 : 0);

    connect(ui->treeWidget, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(onItemChanged(QTreeWidgetItem*,int)));
}

void BCSettingPerviewDlg::updateParentItem(QTreeWidgetItem* item)
{
    QTreeWidgetItem *parent = item->parent();
    if (parent == NULL)
        return;

    //选中的子节点个数
    double selectedCount = 0;
    int childCount = parent->childCount();
    for (int i = 0; i < childCount; i++){
        QTreeWidgetItem *childItem = parent->child(i);
        if (childItem->checkState(0) == Qt::Checked) {
            selectedCount++;
        } else if (childItem->checkState(0) == Qt::PartiallyChecked) {
            selectedCount += 0.5;
        }
    }

    if (selectedCount <= 0.01) {
        //选中状态
        parent->setCheckState(0, Qt::Unchecked);
    } else if (selectedCount > 0.01 && selectedCount < childCount-0.01){
        //部分选中状态
        parent->setCheckState(0, Qt::PartiallyChecked);
    } else if ((selectedCount > childCount-0.01) && (selectedCount < childCount+0.01)) {
        //未选中状态
        parent->setCheckState(0, Qt::Checked);
    }

    updateParentItem(parent);
}

void BCSettingPerviewDlg::updateChildItem(QTreeWidgetItem* item, int checkState)
{
    if (NULL == item)
        return;

    for (int i = 0; i < item->childCount(); i++) {
        QTreeWidgetItem *pChild = item->child(i);
        pChild->setCheckState(0, (checkState == 1) ? Qt::Checked : Qt::Unchecked);

        updateChildItem(pChild, checkState);
    }
}
