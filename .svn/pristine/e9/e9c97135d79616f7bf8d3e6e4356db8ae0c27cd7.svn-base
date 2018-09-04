#include "BCVideoControl.h"
#include "ui_BCVideoControl.h"
#include "../Common/BCCommon.h"
#include "BCWidgetBtn.h"
#include "../Setting/BCSettingCameraWidgetDlg.h"

class BCVideoListWidgetItem : public QListWidgetItem
{
public:
    BCVideoListWidgetItem(QString m_btnName);
    BCVideoListWidgetItem(QString m_divName, QString m_divIP, QString m_divPort, QString m_divUser, QString m_divPasswd);

    QString m_divName;
    QString m_divIP;
    QString m_divPort;
    QString m_divUser;
    QString m_divPasswd;
};

BCVideoListWidgetItem::BCVideoListWidgetItem(QString m_btnName)
{
    this->setText( m_btnName );
    this->setIcon( QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+"diskVideoAdd64.png") );
}

BCVideoListWidgetItem::BCVideoListWidgetItem(QString m_divName,QString m_divIP, QString m_divPort, QString m_divUser, QString m_divPasswd)
{
    this->m_divName = m_divName;
    this->m_divIP = m_divIP;
    this->m_divPort = m_divPort;
    this->m_divUser = m_divUser;
    this->m_divPasswd = m_divPasswd;

    this->setIcon( QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+"diskVideo48.png") );
    this->setText( m_divName );
}
// ======================================================================================

BCVideoControl::BCVideoControl(bool bVisible, int minHeight, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCVideoControl)
{
    ui->setupUi(this);
    m_pHeaderBtn = new BCWidgetBtn(this, MainWindow::VIDEOCONTROLSIGSRC, bVisible);
    connect(m_pHeaderBtn, SIGNAL(sigSetVisible(bool)), this, SLOT(onSetVisible(bool)));
    ui->frame->setMinimumHeight( minHeight - 100 );
    ui->frame->setVisible(false);
    ui->verticalLayout->addWidget(m_pHeaderBtn);

    this->setAttribute(Qt::WA_DeleteOnClose);

    // ListWidget Property
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);            // 右键菜单
    ui->listWidget->setViewMode( QListView::IconMode );                     // 显示矩形块
    ui->listWidget->setMovement( QListView::Static );
    ui->listWidget->setIconSize( QSize(45,45) );
    ui->listWidget->setGridSize( QSize(75,75) );
    ui->listWidget->setResizeMode( QListWidget::Adjust );
    ui->listWidget->insertItem(0, new BCVideoListWidgetItem(tr("添加")));    // 添加默认按钮

    LoadDiskVideoData();
    connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(onInitCameraWidget(QListWidgetItem*)));
    connect(ui->listWidget,SIGNAL(customContextMenuRequested(const QPoint&)),this,SLOT(showContextMenu(const QPoint&)));
}

BCVideoControl::~BCVideoControl()
{
    delete ui;
}

void BCVideoControl::onSetVisible(bool bVisible)
{
    ui->frame->setVisible(false);
    ui->frame_2->setVisible(bVisible);
}

bool BCVideoControl::IsVisible()
{
    return m_pHeaderBtn->IsVisible();
}

//编辑设备信息-保存按钮
void BCVideoControl::on_pushButton_clicked()
{
    BCVideoListWidgetItem *pItem = dynamic_cast<BCVideoListWidgetItem *>( ui->listWidget->currentItem() );
    if (NULL == pItem)
        return;

    if ( !pItem->m_divName.isEmpty() ) { // 修改
        pItem->m_divName = ui->lineEdit_divName->text();
        pItem->m_divIP = ui->lineEdit_divIP->text();
        pItem->m_divPort = ui->lineEdit_divPort->text();
        pItem->m_divUser = ui->lineEdit_divUser->text();
        pItem->m_divPasswd = ui->lineEdit_divPasswd->text();
        pItem->setText( ui->lineEdit_divName->text() );
     } else {   // 新建
         int index = ui->listWidget->count() - 1;
         ui->listWidget->insertItem(index, new BCVideoListWidgetItem(ui->lineEdit_divName->text(), ui->lineEdit_divIP->text(), ui->lineEdit_divPort->text(), ui->lineEdit_divUser->text(), ui->lineEdit_divPasswd->text()));
     }

     SaveDiskVideoData();
     on_pushButton_2_clicked();
}

void BCVideoControl::on_pushButton_2_clicked()  // 返回按钮
{
    ui->frame->setVisible(false);
    ui->frame_2->setVisible(true);
}

void BCVideoControl::LoadDiskVideoData()
{
    QFile file( QString("../xml/BCCameraConf.xml"));
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        return;
    }
    QDomDocument doc;
    bool bLoadFile = doc.setContent(&file,true);
    if ( !bLoadFile ) {
        return;
    }
    QDomElement docElem = doc.documentElement();
    QDomNodeList cNode = docElem.childNodes();
    for (int i = 0; !cNode.isEmpty() && i < cNode.count(); i++ ) {
        QDomElement ele = cNode.at(i).toElement();

        QString divName = ele.attribute("divName");
        QString divIP = ele.attribute("divIP");
        QString divPort = ele.attribute("divPort");
        QString divUser = ele.attribute("divUser");
        QString divPasswd = ele.attribute("divPasswd");

        int index = ui->listWidget->count() - 1;
        ui->listWidget->insertItem(index, new BCVideoListWidgetItem(divName, divIP, divPort, divUser, divPasswd));
    }
    file.close();
}

void BCVideoControl::SaveDiskVideoData()
{
    //可直接覆盖xml中的数据
    QDomDocument doc;
    QDomElement eleRoot = doc.createElement(QString("DIV"));
    for(int i = 0; i < ui->listWidget->count()-1; i++) {
        BCVideoListWidgetItem *pItem = dynamic_cast<BCVideoListWidgetItem *>( ui->listWidget->item(i) );
        if (NULL == pItem)
            continue;

        QDomElement elechild = doc.createElement(QString("INFO"));
        elechild.setAttribute(QString("divName"), pItem->m_divName);
        elechild.setAttribute(QString("divIP"), pItem->m_divIP);
        elechild.setAttribute(QString("divPort"), pItem->m_divPort);
        elechild.setAttribute(QString("divUser"), pItem->m_divUser);
        elechild.setAttribute(QString("divPasswd"), pItem->m_divPasswd);
        eleRoot.appendChild(elechild);
    }
    doc.appendChild(eleRoot);
    QFile file( QString("../xml/BCCameraConf.xml") );
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}

void BCVideoControl::showContextMenu(const QPoint &pt)
{
    BCVideoListWidgetItem *pItem = dynamic_cast<BCVideoListWidgetItem *>( ui->listWidget->currentItem() );
    if (NULL == pItem)
        return;

    // 添加按钮
    if ( pItem->m_divName.isEmpty() )
        return;

    QPoint globalPos = ui->listWidget->mapToGlobal( pt );
    QMenu menu;
    QAction *pModifyAction = menu.addAction(tr("修改"));
    QAction *pDelAction = menu.addAction(tr("删除"));

    QAction *pSelectAction = menu.exec(globalPos);
    if (pSelectAction == pModifyAction) {
        ModifyItem();
    }
    if (pSelectAction == pDelAction) {
        DeleteItem();
    }
}

//进入摄像机界面
void BCVideoControl::onInitCameraWidget(QListWidgetItem *pSrcItem)
{
    BCVideoListWidgetItem *pItem = dynamic_cast<BCVideoListWidgetItem *>( pSrcItem );
    if (NULL == pItem)
        return;

    if ( pItem->m_divName.isEmpty() ) { // 添加
        ui->frame_2->setVisible(false);
        ui->frame->setVisible(true);

        //清空界面
        ui->lineEdit_divIP->clear();
        ui->lineEdit_divName->clear();
        ui->lineEdit_divPasswd->clear();
        ui->lineEdit_divPort->clear();
        ui->lineEdit_divUser->clear();
    } else {    // 摄像机主操作界面
        QStringList lstDivInfo;
        lstDivInfo << pItem->m_divName << pItem->m_divIP << pItem->m_divPort << pItem->m_divUser << pItem->m_divPasswd;
        BCSettingCameraWidgetDlg *pDlg =  new BCSettingCameraWidgetDlg( lstDivInfo );
        pDlg->exec();
    }
}

//修改按钮
void BCVideoControl::ModifyItem()
{
    BCVideoListWidgetItem *pItem = dynamic_cast<BCVideoListWidgetItem *>( ui->listWidget->currentItem() );
    if (NULL == pItem)
        return;

    ui->frame->setVisible(true);
    ui->frame_2->setVisible(false);

    ui->lineEdit_divName->setText( pItem->m_divName );
    ui->lineEdit_divIP->setText( pItem->m_divIP );
    ui->lineEdit_divPort->setText( pItem->m_divPort );
    ui->lineEdit_divUser->setText( pItem->m_divUser );
    ui->lineEdit_divPasswd->setText( pItem->m_divPort );
}

void BCVideoControl::DeleteItem()
{
    BCVideoListWidgetItem *pItem = dynamic_cast<BCVideoListWidgetItem *>( ui->listWidget->currentItem() );
    if (NULL == pItem)
        return;

    delete pItem;
    pItem = NULL;

    SaveDiskVideoData();
}
