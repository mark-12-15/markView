#include "BCSettingDeviceFormatDlg.h"
#include "ui_BCSettingDeviceFormatDlg.h"
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"
#include "../Model/BCMRoom.h"
#include "../Model/BCMGroupDisplay.h"
#include "../Model/BCMChannel.h"
#include "BCSettingWaitingDlg.h"
#include "BCSettingDeviceCustomResolutionDlg.h"

#define ICON_SIZE 48

#define ISHAVELED       // 是否存在LED

// 自定义输入分辨率
struct SCustomResoluion {
    int liveW;      // 活动水平像素
    int liveH;      // 活动垂直像素
    int preW;       // 水平前沿
    int preH;       // 垂直前沿
    int syncW;      // 水平同步宽度
    int syncH;      // 垂直同步官渡
    int totalW;     // 水平总数
    int totalH;     // 垂直总数
    int polarityW;  // 水平同步极性1:+, 0:-
    int polarityH;  // 垂直同步极性1:+, 0:-
    int hertz;      // 刷新频率
};

class BCCmdRoomListWidgetItem : public QListWidgetItem
{
public:
    BCCmdRoomListWidgetItem(int id, QListWidget *parent = NULL);

    void SetName(const QString &qsName) {
        m_qsName = qsName;
        this->setText( m_qsName );
    }

    QString m_qsName;
    int     m_nGroupID;
    int     m_nStartChannel;        // 起始通道ID
    int     m_nResolution;          // 0-4 分辨代表1920*1080... -1代表自定义
    int     m_nCustomResolutionX;
    int     m_nCustomResolutionY;
    int     m_nArrayX;
    int     m_nArrayY;
    int     m_nType;                // 0:LCD 1:LED 2:融合 3:4K 4:Matrix

    int     m_nUseVir;              // 是否使用虚拟分辨率
    int     m_nVirWidth;
    int     m_nVirHeight;

    bool    m_bLEDConfig;           // 是否使用LED配置对话框
    int     m_resoluX;
    int     m_resoluY;
    QList<int> lstSetXYPara;        // 5个参数是一组
};

BCCmdRoomListWidgetItem::BCCmdRoomListWidgetItem(int id, QListWidget *parent)
    :QListWidgetItem(parent)
{
    m_qsName = QObject::tr("GROUP%1").arg(parent->count()-1);
    m_nGroupID = id;
    m_nStartChannel = 0;
    m_nArrayX = 2;
    m_nArrayY = 2;
    m_nResolution = 0;
    m_nCustomResolutionX = 1920;
    m_nCustomResolutionY = 1080;
    m_nType = 0;
    m_bLEDConfig = false;

    m_nUseVir = 0;
    m_nVirWidth = 3840;
    m_nVirHeight = 2160;

    this->setTextAlignment(Qt::AlignHCenter); // 对齐方式
    this->setSizeHint (QSize(ICON_SIZE + 20, ICON_SIZE + 20));
    this->setIcon(QIcon(BCCommon::g_qsApplicationDefaultStylePath + QString("/montage64.png")));
    this->setText( m_qsName );
}

// --------------------------------------------------------------------------------------------------------------------------------------

BCSettingDeviceFormatDlg::BCSettingDeviceFormatDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingDeviceFormatDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("规模设置"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    m_nCurrentTime = 0;
    m_pTimer = NULL;
    m_bReload = false;
    ui->m_pListWidget->setIconSize(QSize(ICON_SIZE, ICON_SIZE));        //设置QListWidget中的单元项的图片大小
    ui->m_pListWidget->setResizeMode(QListView::Adjust);
    ui->m_pListWidget->setViewMode(QListView::IconMode);  //设置QListWidget的显示模式
    ui->m_pListWidget->setMovement(QListView::Static);    //设置QListWidget中的单元项不可被拖动
    ui->m_pListWidget->setSpacing(2);                     //设置QListWidget中的单元项的间距

    // 初始化进度条
    ui->progressBar->setMaximum(1000);
    ui->progressBar->setValue( 0 );

    // 加载自定义分辨率
    LoadCustomResolution();

    MainWindow *pApplication = BCCommon::Application();

    QList<BCMRoom *> lstRooms = pApplication->GetMRooms();
    int nResolutionType = 0;

    // 初始化list数据
    int nStartChannel = 0;
    for (int i = 0 ; i < lstRooms.count(); i++) {
        BCMRoom *pRoom = lstRooms.at(i);

        QList<BCMGroupDisplay *> lstGroupDisplay = pRoom->GetGroupDisplay();
        for (int j = 0; j < lstGroupDisplay.count(); j++) {
            BCMGroupDisplay *pGroupDisplay = lstGroupDisplay.at(j);
            QSize arraySize = pGroupDisplay->GetArraySize( false );
            int nResolutionX = pRoom->GetWallSize(false).width() / arraySize.width();
            int nResolutionY = pRoom->GetWallSize(false).height() / arraySize.height();
            if ((1920 == nResolutionX) && (1080 == nResolutionY))
                nResolutionType = 0;
            else if ((1400 == nResolutionX) && (1050 == nResolutionY))
                nResolutionType = 1;
            else if ((1366 == nResolutionX) && (768 == nResolutionY))
                nResolutionType = 2;
            else if ((1280 == nResolutionX) && (720 == nResolutionY))
                nResolutionType = 3;
            else if ((1024 == nResolutionX) && (768 == nResolutionY))
                nResolutionType = 4;
            else
                nResolutionType = 8;

            // 新建item
            BCCmdRoomListWidgetItem *pItem = new BCCmdRoomListWidgetItem(pRoom->GetRoomID(), ui->m_pListWidget);
            pItem->SetName( pRoom->GetRoomName() );
            pItem->m_nArrayX = arraySize.width();
            pItem->m_nArrayY = arraySize.height();
            pItem->m_nStartChannel = nStartChannel;
            pItem->m_nResolution = nResolutionType;
            pItem->m_nCustomResolutionX = nResolutionX;
            pItem->m_nCustomResolutionY = nResolutionY;
            pItem->m_nType = pRoom->GetType();
            pItem->m_nUseVir = pRoom->IsUseVirSize();
            pItem->m_nVirWidth = pRoom->GetWallVirSize().width();
            pItem->m_nVirHeight = pRoom->GetWallVirSize().height();

            ui->m_pListWidget->addItem( pItem );

            nStartChannel += pItem->m_nArrayX*pItem->m_nArrayY;

            // 如果起始位置是奇数，则自动跳一个口(目前硬件不支持，只能偶数是起始口)
            if (nStartChannel%2 == 1) {
                nStartChannel++;
            }
        }
    }

    // 单击列表框动作
    connect(ui->m_pListWidget, SIGNAL(currentRowChanged(int)), this, SLOT(onCurrentRowChanged(int)));
    if ( !lstRooms.isEmpty() ) {
        ui->m_pListWidget->setCurrentRow(0);
        on_m_pGroupTypeCombox_currentIndexChanged( lstRooms.first()->GetType() );
    }

    // 权限控制
    if (pApplication->GetCurrentUser()->level > 1) {
        ui->m_pCustomResolutionLabel->setVisible( false );
        ui->m_pCustomResolutionWidget->setVisible( false );
    }

    // VP2000 不能分组
    if (BCCommon::g_nDeviceType == 0) {
        ui->m_pAddGroupBtn->setVisible( false );
        ui->m_pRemoveGroupBtn->setVisible( false );
    }
}

BCSettingDeviceFormatDlg::~BCSettingDeviceFormatDlg()
{
    // 清空自定义分辨率链表
    UpdateCustomResolution();
    while ( !m_lstResolution.isEmpty() )
        delete m_lstResolution.takeFirst();

    if (NULL != m_pTimer) {
        m_pTimer->deleteLater();
    }

    delete ui;

    // 重新加载数据
    if ( m_bReload ) {
        BCSettingWaitingDlg *pDlg = new BCSettingWaitingDlg();
        pDlg->show();
    }
}

void BCSettingDeviceFormatDlg::SetLEDConfig(int resoluX, int resoluY)
{
    BCCmdRoomListWidgetItem *pItem = dynamic_cast<BCCmdRoomListWidgetItem *>( ui->m_pListWidget->currentItem() );
    if (NULL == pItem)
        return;

    pItem->m_bLEDConfig = true;
    pItem->m_resoluX = resoluX;
    pItem->m_resoluY = resoluY;
}

void BCSettingDeviceFormatDlg::AddSetXYPara(int chid, int l, int t, int r, int b)
{
    BCCmdRoomListWidgetItem *pItem = dynamic_cast<BCCmdRoomListWidgetItem *>( ui->m_pListWidget->currentItem() );
    if (NULL == pItem)
        return;

    pItem->lstSetXYPara << chid << l << t << r << b;
}

void BCSettingDeviceFormatDlg::LoadCustomResolution()
{
    QFile file( QString("../xml/BCCustomResolutionConfig.xml") );
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

    // 循环自定义分辨率
    for (int i = 0; i < docElem.childNodes().count(); i++) {
        QDomNode nodeResolution = docElem.childNodes().at(i);
        if ( !nodeResolution.isElement() )
            continue;

        QDomElement eleResolution = nodeResolution.toElement();

        // 创建自定义分辨率
        SCustomResoluion *pSresolution = new SCustomResoluion;
        pSresolution->liveW = eleResolution.attribute("liveW").toInt();
        pSresolution->liveH = eleResolution.attribute("liveH").toInt();
        pSresolution->preW = eleResolution.attribute("preW").toInt();
        pSresolution->preH = eleResolution.attribute("preH").toInt();
        pSresolution->syncW = eleResolution.attribute("syncW").toInt();
        pSresolution->syncH = eleResolution.attribute("syncH").toInt();
        pSresolution->totalW = eleResolution.attribute("totalW").toInt();
        pSresolution->totalH = eleResolution.attribute("totalH").toInt();
        pSresolution->polarityW = eleResolution.attribute("polarityW").toInt();
        pSresolution->polarityH = eleResolution.attribute("polarityH").toInt();
        pSresolution->hertz = eleResolution.attribute("hertz").toInt();

        m_lstResolution.append( pSresolution );

        // 直接添加到下拉框
        ui->m_pResolutionCombbox->addItem( QString("%1*%2").arg(pSresolution->liveW).arg(pSresolution->liveH) );
    }

    // 控制按钮是否可用
    ui->m_pDelResolutionBtn->setEnabled( false );
    ui->m_pModifyResolutionBtn->setEnabled( false );
}

void BCSettingDeviceFormatDlg::UpdateCustomResolution()
{
    QDomDocument doc;

    // 添加根节点
    QDomElement eleRoot = doc.createElement(QString("BR"));
    doc.appendChild( eleRoot );

    // 循环添加子节点
    for (int i = 0; i < m_lstResolution.count(); i++) {
        SCustomResoluion *pSresolution = m_lstResolution.at( i );

        QDomElement eleNode = doc.createElement(QString("Resolution"));
        eleNode.setAttribute("liveW", pSresolution->liveW);
        eleNode.setAttribute("liveH", pSresolution->liveH);
        eleNode.setAttribute("preW", pSresolution->preW);
        eleNode.setAttribute("preH", pSresolution->preH);
        eleNode.setAttribute("syncW", pSresolution->syncW);
        eleNode.setAttribute("syncH", pSresolution->syncH);
        eleNode.setAttribute("totalW", pSresolution->totalW);
        eleNode.setAttribute("totalH", pSresolution->totalH);
        eleNode.setAttribute("polarityW", pSresolution->polarityW);
        eleNode.setAttribute("polarityH", pSresolution->polarityH);
        eleNode.setAttribute("hertz", pSresolution->hertz);

        eleRoot.appendChild( eleNode );
    }

    // 写入文件
    QFile file( QString("../xml/BCCustomResolutionConfig.xml") );
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}

void BCSettingDeviceFormatDlg::onCurrentRowChanged(int index)
{
    BCCmdRoomListWidgetItem *pItem = dynamic_cast<BCCmdRoomListWidgetItem *>( ui->m_pListWidget->item( index ) );
    if (NULL == pItem)
        return;

    ui->m_pNameLineEdit->setText( pItem->m_qsName );
    if (8 != pItem->m_nResolution) {    // 8是自定义分辨率
        ui->m_pResolutionCombbox->setCurrentIndex( pItem->m_nResolution );
    } else {
        int ii = ui->m_pResolutionCombbox->findText( QString("%1*%2").arg(pItem->m_nCustomResolutionX).arg(pItem->m_nCustomResolutionY) );
        //ui->m_pResolutionCombbox->setCurrentText(  );
        ii = (-1 == ii) ? 0 : ii; // 如果没有找到则默认第一个
        ui->m_pResolutionCombbox->setCurrentIndex( ii );
    }
    ui->m_pGroupIDSpinBox->setValue( pItem->m_nGroupID );
    ui->m_pStartChannelLineEdit->setValue( pItem->m_nStartChannel );
    ui->m_pArrayXLineEdit->setValue( pItem->m_nArrayX );
    ui->m_pArrayYLineEdit->setValue( pItem->m_nArrayY );
    ui->m_pGroupTypeCombox->setCurrentIndex( pItem->m_nType );
}

void BCSettingDeviceFormatDlg::on_m_pAddGroupBtn_clicked()
{
    // 计算起始通道和ID
    int nStartChannel = 0;
    int nGroupID = 0;
    for (int i = 0; i < ui->m_pListWidget->count(); i++) {
        BCCmdRoomListWidgetItem *pItem = dynamic_cast<BCCmdRoomListWidgetItem *>( ui->m_pListWidget->item( i ) );
        if (NULL == pItem)
            continue;

        nStartChannel += pItem->m_nArrayX*pItem->m_nArrayY;
#ifdef ISHAVELED
        if (3 == pItem->m_nType) {  // ??? 如果是4K则通道数翻倍，放开LED后将2=》3
#else
        if (2 == pItem->m_nType) {  // ??? 如果是4K则通道数翻倍，放开LED后将2=》3
#endif
            nStartChannel += pItem->m_nArrayX*pItem->m_nArrayY;
        }

        // 取最大的GROUPID，依次顺延
        nGroupID = qMax(nGroupID, pItem->m_nGroupID);
    }

    BCCmdRoomListWidgetItem *pItem = new BCCmdRoomListWidgetItem(nGroupID+1, ui->m_pListWidget);
    pItem->m_nStartChannel = (nStartChannel%2 == 1) ? nStartChannel+1 : nStartChannel;  // 如果起始通道是奇数则+1

    ui->m_pListWidget->addItem( pItem );

    ui->m_pListWidget->setCurrentRow(ui->m_pListWidget->count()-1);

    m_bReload = false;
}

void BCSettingDeviceFormatDlg::on_m_pRemoveGroupBtn_clicked()
{
    int nRow = ui->m_pListWidget->currentRow();
    if (-1 == nRow)
        return;

    BCCmdRoomListWidgetItem *pItem = dynamic_cast<BCCmdRoomListWidgetItem *>( ui->m_pListWidget->takeItem( nRow ) );
    if (NULL != pItem) {
        delete pItem;
        pItem = NULL;
    }

    if (0 != ui->m_pListWidget->count())
        ui->m_pListWidget->setCurrentRow(0);

    m_bReload = false;
}

void BCSettingDeviceFormatDlg::on_m_pNameLineEdit_textChanged(const QString &arg1)
{
    BCCmdRoomListWidgetItem *pItem = dynamic_cast<BCCmdRoomListWidgetItem *>( ui->m_pListWidget->currentItem() );
    if (NULL == pItem)
        return;

    pItem->SetName( arg1 );

    m_bReload = false;
}

void BCSettingDeviceFormatDlg::on_m_pResolutionCombbox_currentIndexChanged(int index)
{
    // 常规分辨率不可修改
    ui->m_pDelResolutionBtn->setEnabled( (index < 5) ? false : true );
    ui->m_pModifyResolutionBtn->setEnabled( (index < 5) ? false : true );

    BCCmdRoomListWidgetItem *pItem = dynamic_cast<BCCmdRoomListWidgetItem *>( ui->m_pListWidget->currentItem() );
    if (NULL == pItem)
        return;

    ui->m_pResolutionCombbox->highlighted( index );

    // 如果是自定义分辨率需要分析分辨率后分别记录
    pItem->m_nResolution = (index < 5) ? index : 8;
    QStringList lstPara = ui->m_pResolutionCombbox->currentText().split("*");
    if (2 == lstPara.count()) {
        pItem->m_nCustomResolutionX = lstPara.at(0).toInt();
        pItem->m_nCustomResolutionY = lstPara.at(1).toInt();
    }

    m_bReload = false;
}

void BCSettingDeviceFormatDlg::on_m_pArrayXLineEdit_valueChanged(int arg1)
{
    BCCmdRoomListWidgetItem *pItem = dynamic_cast<BCCmdRoomListWidgetItem *>( ui->m_pListWidget->currentItem() );
    if (NULL == pItem)
        return;

    if (pItem->m_nArrayX == arg1)
        return;

    pItem->m_nArrayX = arg1;

    m_bReload = false;
}

void BCSettingDeviceFormatDlg::on_m_pArrayYLineEdit_valueChanged(int arg1)
{
    BCCmdRoomListWidgetItem *pItem = dynamic_cast<BCCmdRoomListWidgetItem *>( ui->m_pListWidget->currentItem() );
    if (NULL == pItem)
        return;

    if (pItem->m_nArrayY == arg1)
        return;

    pItem->m_nArrayY = arg1;

    m_bReload = false;
}

void BCSettingDeviceFormatDlg::on_m_pStartChannelLineEdit_valueChanged(int arg1)
{
    BCCmdRoomListWidgetItem *pItem = dynamic_cast<BCCmdRoomListWidgetItem *>( ui->m_pListWidget->currentItem() );
    if (NULL == pItem)
        return;

    if (pItem->m_nStartChannel == arg1)
        return;

    pItem->m_nStartChannel = arg1;

    m_bReload = false;
}

void BCSettingDeviceFormatDlg::on_m_pGroupTypeCombox_currentIndexChanged(int index)
{
    BCCmdRoomListWidgetItem *pItem = dynamic_cast<BCCmdRoomListWidgetItem *>( ui->m_pListWidget->currentItem() );
    if (NULL == pItem)
        return;

    if (pItem->m_nType == index)
        return;

    pItem->m_nType = index;

    // 4K显示分辨率3840*2160
#ifdef ISHAVELED
    if (3 == index) {
#else
    if (2 == index) {
#endif
        if (ui->m_pResolutionCombbox->count() > 5) {
            ui->m_pResolutionCombbox->setCurrentIndex(5);
        }
    } else {
        ui->m_pResolutionCombbox->setCurrentIndex(0);
    }

    m_bReload = false;
}

void BCSettingDeviceFormatDlg::on_m_pAddResolutionBtn_clicked()
{
    // 暂时没有具体算法，直接传入默认值
    BCSettingDeviceCustomResolutionDlg dlg(1920, 1080, 88, 4, 44, 5, 2200, 1125, 1, 1, 60, this);
    if (dlg.exec() == QDialog::Accepted) {
        SCustomResoluion *pResolution = new SCustomResoluion;
        pResolution->liveH = dlg.m_liveH;
        pResolution->liveW = dlg.m_liveW;
        pResolution->preW = dlg.m_preW;
        pResolution->preH = dlg.m_preH;
        pResolution->syncW = dlg.m_syncW;
        pResolution->syncH = dlg.m_syncH;
        pResolution->totalW = dlg.m_totalW;
        pResolution->totalH = dlg.m_totalH;
        pResolution->polarityW = dlg.m_polarityW;
        pResolution->polarityH = dlg.m_polarityH;
        pResolution->hertz = dlg.m_hertz;

        m_lstResolution.append( pResolution );
        ui->m_pResolutionCombbox->addItem( QString("%1*%2").arg(pResolution->liveW).arg(pResolution->liveH) );
    }
}

void BCSettingDeviceFormatDlg::on_m_pDelResolutionBtn_clicked()
{
    // 1.从combbox中移除掉
    int index = ui->m_pResolutionCombbox->currentIndex();
    ui->m_pResolutionCombbox->removeItem( index );
    if (ui->m_pResolutionCombbox->count() != 0)
        ui->m_pResolutionCombbox->setCurrentIndex( 0 );

    // 2.从链表中删除掉对象
    int nlstIndex = index - 5;
    if ((nlstIndex >= 0) && (nlstIndex < m_lstResolution.count())) {
        SCustomResoluion *pResolution = m_lstResolution.takeAt( nlstIndex );
        delete pResolution;
        pResolution = NULL;
    }
}

void BCSettingDeviceFormatDlg::on_m_pModifyResolutionBtn_clicked()
{
    // 前5个是固定分辨率
    int index = ui->m_pResolutionCombbox->currentIndex();
    int nlstIndex = index - 5;

    SCustomResoluion *pResolution = NULL;
    if ((nlstIndex >= 0) && (nlstIndex < m_lstResolution.count())) {
        pResolution = m_lstResolution.at( nlstIndex );
    }

    if (NULL == pResolution)
        return;

    BCSettingDeviceCustomResolutionDlg dlg(pResolution->liveW, pResolution->liveH, pResolution->preW, pResolution->preH,
                                           pResolution->syncW, pResolution->syncH, pResolution->totalW, pResolution->totalH,
                                           pResolution->polarityW, pResolution->polarityH, pResolution->hertz, this);
    if (dlg.exec() == QDialog::Accepted) {
        pResolution->liveH = dlg.m_liveH;
        pResolution->liveW = dlg.m_liveW;
        pResolution->preW = dlg.m_preW;
        pResolution->preH = dlg.m_preH;
        pResolution->syncW = dlg.m_syncW;
        pResolution->syncH = dlg.m_syncH;
        pResolution->totalW = dlg.m_totalW;
        pResolution->totalH = dlg.m_totalH;
        pResolution->polarityW = dlg.m_polarityW;
        pResolution->polarityH = dlg.m_polarityH;
        pResolution->hertz = dlg.m_hertz;

        ui->m_pResolutionCombbox->removeItem( index );
        ui->m_pResolutionCombbox->insertItem(index, QString("%1*%2").arg(pResolution->liveW).arg(pResolution->liveH) );
        ui->m_pResolutionCombbox->setCurrentIndex( index );
    }
}

void BCSettingDeviceFormatDlg::CommitConfig()
{
    int nExecTime = 0;
    int nProgress = 0;

    BCLocalServer *pServer = BCLocalServer::Application();
    if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) {  // VP2000A, VP4000
        // 发送清除所有窗口指令
        AppendCmd(pServer->GetRstGroup(), nExecTime, nProgress);
    }

    // 修改数据库的链表
    QList<sRoomConfig> lstConfig;

    int nGroupProgressValue = 900/ui->m_pListWidget->count()/4;

    // 设置每个组屏配置
    for (int i = 0; i < ui->m_pListWidget->count(); i++) {
        BCCmdRoomListWidgetItem *pItem = dynamic_cast<BCCmdRoomListWidgetItem *>( ui->m_pListWidget->item( i ) );
        if (NULL == pItem)
            continue;

        // 构造房间结构体
        sRoomConfig sroom;
        sroom.id = pItem->m_nGroupID;
        sroom.name = pItem->m_qsName;
        sroom.type = pItem->m_nType;
        sroom.arrayX = pItem->m_nArrayX;
        sroom.arrayY = pItem->m_nArrayY;
        sroom.isUseVir = pItem->m_nUseVir;
        sroom.virWidth = pItem->m_nVirWidth;
        sroom.virHeight = pItem->m_nVirHeight;

        switch ( pItem->m_nResolution) {
        case 0:
            sroom.resolutionX = 1920;
            sroom.resolutionY = 1080;
            break;
        case 1:
            sroom.resolutionX = 1400;
            sroom.resolutionY = 1050;
            break;
        case 2:
            sroom.resolutionX = 1366;
            sroom.resolutionY = 768;
            break;
        case 3:
            sroom.resolutionX = 1280;
            sroom.resolutionY = 720;
            break;
        case 4:
            sroom.resolutionX = 1024;
            sroom.resolutionY = 768;
            break;
        default:
            sroom.resolutionX = pItem->m_nCustomResolutionX;
            sroom.resolutionY = pItem->m_nCustomResolutionY;
            break;
        }

        // ??? 4K时分辨率固定为3840*2160
#ifdef ISHAVELED
        if (3 == sroom.type) {
#else
        if (2 == sroom.type) {
#endif
            sroom.resolutionX = 3840;
            sroom.resolutionY = 2160;
        }

        lstConfig.append( sroom );

        // LCD直接发送指令设置屏组分辨率,3:4K
        int nResolutionX = pItem->m_nCustomResolutionX;
        int nResolutionY = pItem->m_nCustomResolutionY;
        if ((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) {  // VP2000A, VP4000
            // ??? 起始通道是奇数时需要+1，硬件暂时不支持奇数输出口分组
            pItem->m_nStartChannel = ((pItem->m_nStartChannel % 2 == 1) ? 1 : 0) + pItem->m_nStartChannel;

            // 如果是自定义的分辨率，则需要发送指令设置分辨率
#ifdef ISHAVELED
            if ((8 == pItem->m_nResolution) && (3 != pItem->m_nType)) { // 不是4K的自定义分辨率需要单独发送指令
#else
            if ((8 == pItem->m_nResolution) && (2 != pItem->m_nType)) { // 不是4K的自定义分辨率需要单独发送指令
#endif
                int index = ui->m_pResolutionCombbox->findText(QString("%1*%2").arg(pItem->m_nCustomResolutionX).arg(pItem->m_nCustomResolutionY));
                int nlstIndex = index - 5;

                if ((nlstIndex >= 0) && (nlstIndex < m_lstResolution.count())) {
                    SCustomResoluion *pResolution = m_lstResolution.at( nlstIndex );

                    nExecTime += 100;
                    nProgress += nGroupProgressValue;
                    AppendCmd(pServer->GetCustomResolution(pResolution->liveW, pResolution->liveH,
                                                           pResolution->preW, pResolution->preH,
                                                           pResolution->syncW, pResolution->syncH,
                                                           pResolution->totalW, pResolution->totalH,
                                                           pResolution->polarityW, pResolution->polarityH,
                                                           pResolution->hertz), nExecTime, nProgress);
                }
            }

            ui->progressBar->setValue( ui->progressBar->value()+nGroupProgressValue );

            // 输出通道的数量，4K时翻倍
            int outChannelCount = pItem->m_nArrayX*pItem->m_nArrayY;
#ifdef ISHAVELED
            if (3 == pItem->m_nType) {
#else
            if (2 == pItem->m_nType) {
#endif
                outChannelCount *= 2;
            }
            // 通讯
            nExecTime += 100;
            nProgress += nGroupProgressValue;
            AppendCmd(pServer->GetGroup(sroom.id, pItem->m_nStartChannel, pItem->m_nStartChannel+outChannelCount-1), nExecTime, nProgress);

            nExecTime += 100;
            nProgress += nGroupProgressValue;
#ifdef ISHAVELED
            if (3 == pItem->m_nType) {  // 4K的resolution指令第三个参数默认为6
#else
            if (2 == pItem->m_nType) {  // 4K的resolution指令第三个参数默认为6
#endif
                AppendCmd(pServer->GetResolution(pItem->m_nStartChannel, pItem->m_nStartChannel+outChannelCount-1, 6), nExecTime, nProgress);
            } else {
                AppendCmd(pServer->GetResolution(pItem->m_nStartChannel, pItem->m_nStartChannel+outChannelCount-1, (8 == pItem->m_nResolution) ? 8 : pItem->m_nResolution), nExecTime, nProgress);
            }

            nExecTime += 100;
            nProgress += nGroupProgressValue;
#ifdef ISHAVELED
            if (3 == pItem->m_nType) {  // 4K的setgformatxy指令x需要乘以2，分辨率固定为1920*2160
#else
            if (2 == pItem->m_nType) {  // 4K的setgformatxy指令x需要乘以2，分辨率固定为1920*2160
#endif
                AppendCmd(pServer->GetGFormartxy(sroom.id, pItem->m_nArrayX*2, pItem->m_nArrayY, 1920, 2160), nExecTime, nProgress);
            } else {
                AppendCmd(pServer->GetGFormartxy(sroom.id, pItem->m_nArrayX, pItem->m_nArrayY, nResolutionX, nResolutionY), nExecTime, nProgress);
            }
        } else {   // VP2000
            nExecTime += 100;
            nProgress += nGroupProgressValue;
            AppendCmd(pServer->GetFormatxy(pItem->m_nArrayX, pItem->m_nArrayY, nResolutionX, nResolutionY), nExecTime, nProgress);

            nExecTime += 100;
            nProgress += nGroupProgressValue;
#ifdef ISHAVELED
            if (3 == pItem->m_nType) {  // 4K的resolution指令第三个参数默认为6
#else
            if (2 == pItem->m_nType) {  // 4K的resolution指令第三个参数默认为6
#endif
                AppendCmd(pServer->GetResolution(pItem->m_nStartChannel, pItem->m_nStartChannel+(pItem->m_nArrayX*pItem->m_nArrayY)-1, 6), nExecTime, nProgress);
            } else {
                AppendCmd(pServer->GetResolution(pItem->m_nStartChannel, pItem->m_nStartChannel+(pItem->m_nArrayX*pItem->m_nArrayY)-1, (8 == pItem->m_nResolution) ? 8 : pItem->m_nResolution), nExecTime, nProgress);
            }
        }

        nExecTime += 2000;
        nProgress += nGroupProgressValue;
        AppendCmd("", nExecTime, nProgress);
    }

    nExecTime += 100;
    nProgress = 950;
    AppendCmd("", nExecTime, nProgress);

    // 修改数据库
    pServer->UpdateRoomConfig( lstConfig );

    nExecTime += 5000;
    nProgress = 1000;
    AppendCmd("", nExecTime, nProgress);

    if (NULL == m_pTimer) {
        m_pTimer = new QTimer();
        m_pTimer->setInterval( 50 );
        connect(m_pTimer, SIGNAL(timeout()), this, SLOT(onTimeout()));
        m_pTimer->start();
    }

    m_bReload = true;
}

void BCSettingDeviceFormatDlg::AppendCmd(QString cmd, int time, int progress)
{
    SFormatCmd s;
    s.cmd = cmd;
    s.nExecTime = time;
    s.nProgress = progress;
    m_lstFormatCmd.append( s );
}
void BCSettingDeviceFormatDlg::on_m_pOKBtn_clicked()
{
    CommitConfig();
}

void BCSettingDeviceFormatDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingDeviceFormatDlg::on_m_pApplyBtn_clicked()
{
    CommitConfig();
}

void BCSettingDeviceFormatDlg::onTimeout()
{
    // 如果没有指令了直接停止
    if ( m_lstFormatCmd.isEmpty() ) {
        m_pTimer->stop();
        this->accept();
        return;
    }

    SFormatCmd sCmd = m_lstFormatCmd.first();
    if (sCmd.nExecTime == m_nCurrentTime) {
        if ( !sCmd.cmd.isEmpty() ) {
            BCLocalServer *pServer = BCLocalServer::Application();
            pServer->SendCmd( sCmd.cmd );
        }

        ui->progressBar->setValue( sCmd.nProgress );
        m_lstFormatCmd.takeFirst();
    }

    m_nCurrentTime += m_pTimer->interval();
}
void BCSettingDeviceFormatDlg::on_m_pGroupIDSpinBox_valueChanged(int arg1)
{
    BCCmdRoomListWidgetItem *pItem = dynamic_cast<BCCmdRoomListWidgetItem *>( ui->m_pListWidget->currentItem() );
    if (NULL == pItem)
        return;

    pItem->m_nGroupID = arg1;

    m_bReload = false;
}
