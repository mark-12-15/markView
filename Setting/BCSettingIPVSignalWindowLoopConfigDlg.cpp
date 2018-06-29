#include "BCSettingIPVSignalWindowLoopConfigDlg.h"
#include "ui_BCSettingIPVSignalWindowLoopConfigDlg.h"
#include "../Common/BCCommon.h"
#include "../View/BCSignalWindowDisplayWidget.h"
// 自定义QTreeWidgetItem
class BCIPTreeWidgetItem : public QTreeWidgetItem
{
public:
    BCIPTreeWidgetItem(bool bChecked, const QString &name, const QString &ip, const QString &decoder, const QString &resolution, int nLevel, QTreeWidget *parent);
    BCIPTreeWidgetItem(bool bChecked, const QString &name, const QString &ip, const QString &decoder, const QString &resolution, int nLevel, QTreeWidgetItem *parent);
    ~BCIPTreeWidgetItem();

    void SetAttribute(const QString &name, const QString &ip, const QString &decoder, const QString &resolution);

    QString m_qsName;
    QString m_qsIP;
    QString m_qsDecoder;
    QString m_qsResolution;
    int     m_nLevel;
};

BCIPTreeWidgetItem::BCIPTreeWidgetItem(bool bChecked, const QString &name, const QString &ip, const QString &decoder, const QString &resolution, int nLevel, QTreeWidget *parent)
    :QTreeWidgetItem( parent )
{
    this->setCheckState(0, bChecked ? Qt::Checked : Qt::Unchecked);
    m_nLevel = nLevel;
    SetAttribute(name, ip, decoder, resolution);
}

BCIPTreeWidgetItem::BCIPTreeWidgetItem(bool bChecked, const QString &name, const QString &ip, const QString &decoder, const QString &resolution, int nLevel, QTreeWidgetItem *parent)
    :QTreeWidgetItem( parent )
{
    this->setCheckState(0, bChecked ? Qt::Checked : Qt::Unchecked);
    m_nLevel = nLevel;
    SetAttribute(name, ip, decoder, resolution);
}

BCIPTreeWidgetItem::~BCIPTreeWidgetItem()
{
}

void BCIPTreeWidgetItem::SetAttribute(const QString &name, const QString &ip, const QString &decoder, const QString &resolution)
{
    m_qsName = name;
    m_qsIP = ip;
    m_qsDecoder = decoder;
    m_qsResolution = resolution;

    this->setText(0, m_qsName);
    QString qsNameHeader = QObject::tr("名称");
    QString qsIPHeader = QObject::tr("视频地址");
    QString qsDecoderHeader = QObject::tr("编码方式");
    QString qsResolutionHeader = QObject::tr("分辨率");
    this->setToolTip(0, QString("%1: %2 \n%3: %4 \n%5: %6 \n%7: %8")
                     .arg(qsNameHeader).arg(m_qsName)
                     .arg(qsIPHeader).arg(m_qsIP)
                     .arg(qsDecoderHeader).arg(m_qsDecoder)
                     .arg(qsResolutionHeader).arg(m_qsResolution));
}
// ---------------------------------------------------------------------------------------------------------------------------------

BCSettingIPVSignalWindowLoopConfigDlg::BCSettingIPVSignalWindowLoopConfigDlg(BCSignalWindowDisplayWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingIPVSignalWindowLoopConfigDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("IPV轮巡配置"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    m_parent = parent;
    ui->m_pIntervalSpinBox->setValue( m_parent->m_nIPVLoopInterval );

    Refresh();
}

BCSettingIPVSignalWindowLoopConfigDlg::~BCSettingIPVSignalWindowLoopConfigDlg()
{
    delete ui;
}

void BCSettingIPVSignalWindowLoopConfigDlg::Refresh()
{
    // 清空内部数据
    ui->m_pCameraTreeWidget->setHeaderHidden(true);
    ui->m_pCameraTreeWidget->clear();

    QFile file( QString("../xml/BCIPVideoConfig.xml") );
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

    // 添加数据
    for (int i = 0; i < docElem.childNodes().count(); i++) {
        QDomNode node = docElem.childNodes().at(i);
        if ( !node.isElement() )
            continue;

        QDomElement ele = node.toElement();
        AddNode(ele, NULL);
    }

    ui->m_pCameraTreeWidget->expandAll();

    connect(ui->m_pCameraTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(onItemChanged(QTreeWidgetItem*,int)));
}

void BCSettingIPVSignalWindowLoopConfigDlg::AddNode(QDomElement &ele, QTreeWidgetItem *pItem)
{
    // 获得属性
    int nLevel = ele.attribute("level").toInt();
    QString qsName = ele.attribute("name");
    QString qsIP = ele.attribute("ip");
    QString qsDecoder = ele.attribute("decoder");
    QString qsResolution = ele.attribute("resolution");

    // 构造treeWidgetItem
    BCIPTreeWidgetItem *pCurrentItem = NULL;
    if ( !qsName.isEmpty() ) {
        if (0 == nLevel) {
            pCurrentItem = new BCIPTreeWidgetItem(m_parent->m_lstIPOfIPVLoop.contains( qsIP ), qsName, qsIP, qsDecoder, qsResolution, nLevel, ui->m_pCameraTreeWidget);
            ui->m_pCameraTreeWidget->addTopLevelItem( pCurrentItem );
        } else {
            if (NULL == pItem)
                return;

            pCurrentItem = new BCIPTreeWidgetItem(m_parent->m_lstIPOfIPVLoop.contains( qsIP ), qsName, qsIP, qsDecoder, qsResolution, nLevel, pItem);
            pItem->addChild( pCurrentItem );
        }
    }

    if (NULL == pCurrentItem)
        return;

    // 递归添加子节点
    for (int i = 0; i < ele.childNodes().count(); i++) {
        QDomNode node = ele.childNodes().at(i);
        if ( !node.isElement() )
            continue;

        QDomElement eleChild = node.toElement();
        AddNode(eleChild, pCurrentItem);
    }
}


void BCSettingIPVSignalWindowLoopConfigDlg::onItemChanged(QTreeWidgetItem *item, int /*column*/)
{
    disconnect(ui->m_pCameraTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(onItemChanged(QTreeWidgetItem*,int)));

    // 更新父节点
    updateParentItem(item);
    // 更新子节点
    updateChildItem(item, (Qt::Checked == item->checkState(0)) ? 1 : 0);

    connect(ui->m_pCameraTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(onItemChanged(QTreeWidgetItem*,int)));
}

void BCSettingIPVSignalWindowLoopConfigDlg::updateParentItem(QTreeWidgetItem* item)
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

void BCSettingIPVSignalWindowLoopConfigDlg::updateChildItem(QTreeWidgetItem* item, int checkState)
{
    if (NULL == item)
        return;

    for (int i = 0; i < item->childCount(); i++) {
        QTreeWidgetItem *pChild = item->child(i);
        pChild->setCheckState(0, (checkState == 1) ? Qt::Checked : Qt::Unchecked);

        updateChildItem(pChild, checkState);
    }
}

void BCSettingIPVSignalWindowLoopConfigDlg::AddNode(BCIPTreeWidgetItem *pItem, QStringList &lstIPInfo)
{
    if (NULL == pItem)
        return;

    if (Qt::Checked == pItem->checkState( 0 )) {
        if ( !pItem->m_qsIP.isEmpty() ) {
            lstIPInfo.append( pItem->m_qsIP );
        }
    }

    for (int i = 0; i < pItem->childCount(); i++) {
        BCIPTreeWidgetItem *pChild = dynamic_cast<BCIPTreeWidgetItem *>( pItem->child( i ) );
        AddNode(pChild, lstIPInfo);
    }
}

void BCSettingIPVSignalWindowLoopConfigDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingIPVSignalWindowLoopConfigDlg::on_m_pOKBtn_clicked()
{
    QStringList lstIPInfo;
    for (int i = 0; i < ui->m_pCameraTreeWidget->topLevelItemCount(); i++) {
        BCIPTreeWidgetItem *pItem = dynamic_cast<BCIPTreeWidgetItem *>( ui->m_pCameraTreeWidget->topLevelItem( i ) );

        AddNode(pItem, lstIPInfo);
    }

    m_parent->m_nIPVLoopInterval = ui->m_pIntervalSpinBox->value();
    m_parent->m_lstIPOfIPVLoop = lstIPInfo;

    this->accept();
}
