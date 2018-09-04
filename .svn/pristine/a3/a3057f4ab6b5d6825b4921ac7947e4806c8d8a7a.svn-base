#include "BCSettingMatrixFormatDlg.h"
#include "ui_BCSettingMatrixFormatDlg.h"
#include <QSerialPortInfo>
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"
#include "../Model/BCMRoom.h"
#include "../Model/BCMWindowScene.h"
#include "../Model/BCMMatrix.h"
#include "BCSettingJointMatrixChannelConfigDlg.h"

#define ICON_SIZE 48

BCCmdMatrixListWidgetItem::BCCmdMatrixListWidgetItem(int id, QListWidget *parent)
    :QListWidgetItem(parent)
{
    m_id = id;
    name = "Matrix";

    isConnectByNet = 1;             // 是否网络通信
    ip = "192.168.1.3";                     // 网络通信IP
    port = 8001;                       // 网络通信端口
    qsCurrentCom = "COM1";           // 串口号
    nCurrentBaudRate = 115200;           // 波特率
    nCurrentDataBit = 8;            // 数据位
    nCurrentStopBit = 1;            // 停止位
    qsCurrentCheckBit = "None";      // 校验位
    qsCurrentStreamCtrl = "None";    // 控制流

    cmdType = 1;
    isOn = 1;                       // 大屏开关状态
    qsOnCmd = "";                // 打开指令
    qsOffCmd = "";               // 关闭指令

    switchFlag = "%1b%2."; // 切换指令表达式，如SW %1 %2...
    loadFlag = "%1.";   // 调取指令，如%1.
    saveFlag = "%1,";   // 保存指令，如%1,
    jointSceneRoomID = -1;
    jointWithVP4000 = 0;

    this->setTextAlignment(Qt::AlignHCenter); // 对齐方式
    this->setSizeHint (QSize(ICON_SIZE + 20, ICON_SIZE + 20));
    this->setIcon(QIcon(BCCommon::g_qsApplicationDefaultStylePath + QString("/montage64.png")));
    this->setText( name );
}

// ---------------------------------------------------------------------------------------------------------------------------------------------

BCSettingMatrixFormatDlg::BCSettingMatrixFormatDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingMatrixFormatDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("规模设置"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    ui->m_pListWidget->setIconSize(QSize(ICON_SIZE, ICON_SIZE));        //设置QListWidget中的单元项的图片大小
    ui->m_pListWidget->setResizeMode(QListView::Adjust);
    ui->m_pListWidget->setViewMode(QListView::IconMode);  //设置QListWidget的显示模式
    ui->m_pListWidget->setMovement(QListView::Static);    //设置QListWidget中的单元项不可被拖动
    ui->m_pListWidget->setSpacing(2);                     //设置QListWidget中的单元项的间距

    // 初始化是否级联
    ui->m_pJointCheckBox->setChecked((-1 != BCCommon::g_nIsContainsMatrix) ? true : false);

    MainWindow *pApplication = BCCommon::Application();

    // 权限控制
    if (pApplication->GetCurrentUser()->level > 1) {
        ui->m_pJointCheckBox->setVisible( false );
        ui->m_pSwitchCmdLabel->setVisible( false );
        ui->m_pSwitchCmdLineEdit->setVisible( false );
        ui->m_pLoadLabel->setVisible( false );
        ui->m_pLoadLineEdit->setVisible( false );
        ui->m_pSaveLabel->setVisible( false );
        ui->m_pSaveLineEdit->setVisible( false );

        ui->m_pJointSceneCheckBox->setVisible( false );
        ui->m_pRoomComboBox->setVisible( false );
        ui->m_pJointWithVP4000CheckBox->setVisible( false );
        ui->m_pJointWithVP4000ConfigBtn->setVisible( false );
    }

    QList<BCMMatrix *> lstMatrix = pApplication->GetMMatrix();

    // 初始化list数据
    for (int i = 0 ; i < lstMatrix.count(); i++) {
        BCMMatrix *pMatrix = lstMatrix.at(i);

        // 新建item
        BCCmdMatrixListWidgetItem *pItem = new BCCmdMatrixListWidgetItem(pMatrix->id, ui->m_pListWidget);
        pItem->SetName( pMatrix->name );
        pItem->isConnectByNet = pMatrix->isConnectByNet;             // 是否网络通信
        pItem->ip = pMatrix->ip;                     // 网络通信IP
        pItem->port = pMatrix->port;                       // 网络通信端口
        pItem->qsCurrentCom = pMatrix->qsCurrentCom;           // 串口号
        pItem->nCurrentBaudRate = pMatrix->nCurrentBaudRate;           // 波特率
        pItem->nCurrentDataBit = pMatrix->nCurrentDataBit;            // 数据位
        pItem->nCurrentStopBit = pMatrix->nCurrentStopBit;            // 停止位
        pItem->qsCurrentCheckBit = pMatrix->qsCurrentCheckBit;      // 校验位
        pItem->qsCurrentStreamCtrl = pMatrix->qsCurrentStreamCtrl;    // 控制流

        pItem->isOn = pMatrix->isOn;                       // 大屏开关状态
        pItem->qsOnCmd = pMatrix->qsOnCmd;                // 打开指令
        pItem->qsOffCmd = pMatrix->qsOffCmd;               // 关闭指令

        pItem->cmdType = pMatrix->cmdType;
        pItem->switchFlag = pMatrix->switchFlag; // 切换指令表达式，如SW %1 %2...
        pItem->loadFlag = pMatrix->loadFlag;   // 调取指令，如%1.
        pItem->saveFlag = pMatrix->saveFlag;   // 保存指令，如%1,
        pItem->jointSceneRoomID = pMatrix->jointSceneRoomID;
        pItem->jointWithVP4000 = pMatrix->jointWithVP4000;

        pItem->lstInputNode = pMatrix->lstInputNode;
        pItem->lstOutputNode = pMatrix->lstOutputNode;
        pItem->lstScene = pMatrix->lstScene;

        ui->m_pListWidget->addItem( pItem );
    }

    // 初始化房间链表
    QList<BCMRoom *> lstRoom = pApplication->GetMRooms();
    for (int i = 0; i < lstRoom.count(); i++) {
        BCMRoom *pRoom = lstRoom.at( i );
        ui->m_pRoomComboBox->addItem( QString("%1(%2)").arg(pRoom->GetRoomName()).arg(pRoom->GetRoomID()) );
    }

    // 初始化COM连接参数
    QList<QSerialPortInfo> lstSerialPort = QSerialPortInfo::availablePorts();
    for (int i = 0; i < lstSerialPort.count(); i++) {
        QSerialPortInfo info = lstSerialPort.at( i );
        ui->m_pComComBox->addItem( info.portName() );
    }

    // 单击列表框动作
    if ( !lstMatrix.isEmpty() ) {
        onCurrentItemChanged(ui->m_pListWidget->item(0), NULL);
        ui->m_pListWidget->setCurrentRow( 0 );
    }
    connect(ui->m_pListWidget, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), this, SLOT(onCurrentItemChanged(QListWidgetItem*,QListWidgetItem*)));
}

BCSettingMatrixFormatDlg::~BCSettingMatrixFormatDlg()
{
    delete ui;
}

void BCSettingMatrixFormatDlg::onCurrentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    BCCmdMatrixListWidgetItem *pPreItem = dynamic_cast<BCCmdMatrixListWidgetItem *>( previous );
    if (NULL != pPreItem) {
        // 1.保存前一个item
        pPreItem->name = ui->m_pNameLineEdit->text();
        pPreItem->cmdType = ui->m_pCmdTypeComboBox->currentIndex();
        pPreItem->switchFlag = ui->m_pSwitchCmdLineEdit->text();
        pPreItem->loadFlag = ui->m_pLoadLineEdit->text();
        pPreItem->saveFlag = ui->m_pSaveLineEdit->text();
        if ( ui->m_pJointSceneCheckBox->isChecked() ) {
            QString qsRoomText = ui->m_pRoomComboBox->currentText();
            QString qsRoomIDText = qsRoomText.right(qsRoomText.count()-qsRoomText.indexOf("(")-1);
            qsRoomIDText = qsRoomIDText.left( qsRoomIDText.count()-1 );
            pPreItem->jointSceneRoomID = qsRoomIDText.toInt();
        } else {
            pPreItem->jointSceneRoomID = -1;
        }
        pPreItem->jointWithVP4000 = ui->m_pJointWithVP4000CheckBox->isChecked() ? 1 : 0;
        pPreItem->isConnectByNet = ui->m_pUseNetConnectRadioBtn->isChecked() ? 1 : 0;
        pPreItem->qsCurrentCom = ui->m_pComComBox->currentText();
        pPreItem->nCurrentBaudRate = ui->m_pBaudRateComBox->currentText().toInt();
        pPreItem->nCurrentDataBit = ui->m_pDataBitComBox->currentText().toInt();
        pPreItem->nCurrentStopBit = ui->m_pStopBitComBox->currentText().toInt();
        pPreItem->qsCurrentCheckBit = ui->m_pCheckBitComBox->currentText();
        pPreItem->qsCurrentStreamCtrl = ui->m_pStreamCtrlComBox->currentText();
        pPreItem->ip = ui->m_pNetIPLineEdit->text();
        pPreItem->port = ui->m_pNetPortLineEdit->text().toInt();

        // 起始ID
        int nStartID = ui->m_pStartIDSpinBox->value();

        // 输入和输出数量需要进行判断，因为需要保留之前的设置
        int inputCount = ui->m_pInCountLineEdit->text().toInt();
        if (pPreItem->lstInputNode.count() != inputCount) {
            // 如果把数量改少了从后面减掉多余的节点
            if (pPreItem->lstInputNode.count() > inputCount) {
                while (pPreItem->lstInputNode.count() != inputCount) {
                    pPreItem->lstInputNode.takeLast();
                }
            } else {
                while (pPreItem->lstInputNode.count() != inputCount) {
                    sMatrixNode snode;
                    snode.id = pPreItem->lstInputNode.count()+nStartID;
                    snode.name = tr("输入%1").arg(snode.id);
                    snode.nSwitch = 0;
                    snode.nSwitchID = -1;
                    snode.isOn = 1;
                    snode.qsOnCmd = "";
                    snode.qsOffCmd = "";
                    snode.cutl = 0;
                    snode.cutr = 0;
                    snode.cutt = 0;
                    snode.cutb = 0;
                    pPreItem->lstInputNode.append( snode );
                }
            }
        }
        int outputCount = ui->m_pOutCountLineEdit->text().toInt();
        if (pPreItem->lstOutputNode.count() != outputCount) {
            // 如果把数量改少了从后面减掉多余的节点
            if (pPreItem->lstOutputNode.count() > outputCount) {
                while (pPreItem->lstOutputNode.count() != outputCount) {
                    pPreItem->lstOutputNode.takeLast();
                }
            } else {
                while (pPreItem->lstOutputNode.count() != outputCount) {
                    sMatrixNode snode;
                    snode.id = pPreItem->lstOutputNode.count()+nStartID;
                    snode.name = tr("输出%1").arg(snode.id);
                    snode.nSwitch = 0;
                    snode.nSwitchID = -1;
                    snode.isOn = 1;
                    snode.qsOnCmd = "";
                    snode.qsOffCmd = "";
                    snode.cutl = 0;
                    snode.cutr = 0;
                    snode.cutt = 0;
                    snode.cutb = 0;
                    snode.jointWithVP4000ChannelID = -1;
                    snode.jointWithVP2000ChannelType = -1;
                    pPreItem->lstOutputNode.append( snode );
                }
            }
        }
    }

    BCCmdMatrixListWidgetItem *pCurrentItem = dynamic_cast<BCCmdMatrixListWidgetItem *>( current );
    if (NULL != pCurrentItem) {
        // 2.显示当前item
        ui->m_pNameLineEdit->setText( pCurrentItem->name );
        ui->m_pCmdTypeComboBox->setCurrentIndex( pCurrentItem->cmdType );
        ui->m_pSwitchCmdLineEdit->setText( pCurrentItem->switchFlag );
        ui->m_pLoadLineEdit->setText( pCurrentItem->loadFlag );
        ui->m_pSaveLineEdit->setText( pCurrentItem->saveFlag );
        ui->m_pInCountLineEdit->setText( QString::number(pCurrentItem->lstInputNode.count()) );
        ui->m_pOutCountLineEdit->setText( QString::number(pCurrentItem->lstOutputNode.count()) );
        ui->m_pJointSceneCheckBox->setChecked((-1 == pCurrentItem->jointSceneRoomID) ? false : true);
        if (-1 != pCurrentItem->jointSceneRoomID) {
            for (int i = 0; i < ui->m_pRoomComboBox->count(); i++) {
                QString qsRoomText = ui->m_pRoomComboBox->itemText( i );
                QString qsRoomIDText = qsRoomText.right(qsRoomText.count()-qsRoomText.indexOf("(")-1);
                if ( !qsRoomIDText.contains(QString::number(pCurrentItem->jointSceneRoomID)) )
                    continue;

                ui->m_pRoomComboBox->setCurrentIndex( i );
                break;
            }
        }

        ui->m_pJointWithVP4000CheckBox->setChecked((1 == pCurrentItem->jointWithVP4000) ? true : false);
        ui->m_pUseComConnectRadioBtn->setChecked((1 == pCurrentItem->isConnectByNet) ? false : true);
        ui->m_pUseNetConnectRadioBtn->setChecked((1 == pCurrentItem->isConnectByNet) ? true : false);

        ui->m_pComComBox->setCurrentText( pCurrentItem->qsCurrentCom );
        ui->m_pBaudRateComBox->setCurrentText( QString::number(pCurrentItem->nCurrentBaudRate) );
        ui->m_pDataBitComBox->setCurrentText( QString::number(pCurrentItem->nCurrentDataBit) );
        ui->m_pStopBitComBox->setCurrentText( QString::number(pCurrentItem->nCurrentStopBit) );
        ui->m_pCheckBitComBox->setCurrentText( pCurrentItem->qsCurrentCheckBit );
        ui->m_pStreamCtrlComBox->setCurrentText( pCurrentItem->qsCurrentStreamCtrl );
        ui->m_pNetIPLineEdit->setText( pCurrentItem->ip );
        ui->m_pNetPortLineEdit->setText( QString::number(pCurrentItem->port) );

        // 设置起始ID值
        int nStartID = 0;
        for (int i = 0; i < pCurrentItem->lstInputNode.count(); i++) {
            sMatrixNode node = pCurrentItem->lstInputNode.at( i );
            nStartID = qMin(nStartID, node.id);
        }
        ui->m_pStartIDSpinBox->setValue( nStartID );
    }
}

int BCSettingMatrixFormatDlg::CreateMatrixID()
{
    QList<int> lstID;
    for (int i = 0; i < ui->m_pListWidget->count(); i++) {
        BCCmdMatrixListWidgetItem *pItem = dynamic_cast<BCCmdMatrixListWidgetItem *>( ui->m_pListWidget->item( i ) );
        if (NULL == pItem)
            continue;

        lstID.append( pItem->m_id );
    }

    // 从1开始循环，如果中间有空缺直接返回，无空缺返回最后一个
    for (int i = 1; i < lstID.count()+2; i++) {
        if (lstID.contains(i))
            continue;

        return i;
    }

    return 1;
}

void BCSettingMatrixFormatDlg::on_m_pAddBtn_clicked()
{
    ui->m_pListWidget->addItem( new BCCmdMatrixListWidgetItem(CreateMatrixID(), ui->m_pListWidget) );

    ui->m_pListWidget->setCurrentRow(ui->m_pListWidget->count()-1);
}

void BCSettingMatrixFormatDlg::on_m_pRemoveBtn_clicked()
{
    ui->m_pListWidget->takeItem( ui->m_pListWidget->currentRow() );

    if (0 != ui->m_pListWidget->count())
        ui->m_pListWidget->setCurrentRow(0);
}

void BCSettingMatrixFormatDlg::on_m_pModifyBtn_clicked()
{
    onCurrentItemChanged(NULL, ui->m_pListWidget->currentItem());
}

void BCSettingMatrixFormatDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingMatrixFormatDlg::on_m_pOKBtn_clicked()
{
    // 0.保存是否级联矩阵
    if (1 != BCCommon::g_nIsContainsMatrix) {   // 如果只显示矩阵则勾选无效
        BCCommon::g_nIsContainsMatrix = ui->m_pJointCheckBox->isChecked() ? 0 : -1;
        // 将设备类型写入文件
        QFile file( QString("../xml/BCGenaralConfig.xml") );
        if (file.open(QIODevice::ReadOnly)) {
            // 将文件内容读到QDomDocument中
            QDomDocument doc;
            bool bLoadFile = doc.setContent(&file);
            file.close();

            if ( bLoadFile ) {
                // 二级链表
                QDomElement docElem = doc.documentElement();
                docElem.setAttribute("IsContainsMatrix", BCCommon::g_nIsContainsMatrix);

                // 写入文件
                if ( file.open(QIODevice::WriteOnly | QIODevice::Truncate) ) {
                    QTextStream out(&file);
                    doc.save(out,4);
                    file.close();
                }
            }
        }
    }

    // 1.保存当前房间修改
    onCurrentItemChanged(NULL, ui->m_pListWidget->currentItem());

    // 2.修改数据库
    QList<sMatrix> lstMatrix;
    for (int i = 0; i < ui->m_pListWidget->count(); i++) {
        BCCmdMatrixListWidgetItem *pItem = dynamic_cast<BCCmdMatrixListWidgetItem *>( ui->m_pListWidget->item( i ) );
        if (NULL == pItem)
            continue;

        sMatrix smatrix;
        smatrix.id = pItem->m_id;
        smatrix.name = pItem->name;

        smatrix.isConnectByNet = pItem->isConnectByNet;             // 是否网络通信
        smatrix.ip = pItem->ip;                     // 网络通信IP
        smatrix.port = pItem->port;                       // 网络通信端口
        smatrix.qsCurrentCom = pItem->qsCurrentCom;           // 串口号
        smatrix.nCurrentBaudRate = pItem->nCurrentBaudRate;           // 波特率
        smatrix.nCurrentDataBit = pItem->nCurrentDataBit;            // 数据位
        smatrix.nCurrentStopBit = pItem->nCurrentStopBit;            // 停止位
        smatrix.qsCurrentCheckBit = pItem->qsCurrentCheckBit;      // 校验位
        smatrix.qsCurrentStreamCtrl = pItem->qsCurrentStreamCtrl;    // 控制流

        smatrix.isOn = pItem->isOn;                       // 大屏开关状态
        smatrix.qsOnCmd = pItem->qsOnCmd;                // 打开指令
        smatrix.qsOffCmd = pItem->qsOffCmd;               // 关闭指令

        smatrix.cmdType = pItem->cmdType;
        smatrix.switchFlag = pItem->switchFlag; // 切换指令表达式，如SW %1 %2...
        smatrix.loadFlag = pItem->loadFlag;   // 调取指令，如%1.
        smatrix.saveFlag = pItem->saveFlag;   // 保存指令，如%1,

        smatrix.jointSceneRoomID = pItem->jointSceneRoomID;           // 是否关联调用场景，关联的拼控调用场景时将调用当前矩阵的场景
        smatrix.jointWithVP4000 = pItem->jointWithVP4000;

        smatrix.lstInputNode = pItem->lstInputNode;   // 输入节点
        smatrix.lstOutputNode = pItem->lstOutputNode;  // 输出节点

//        for (int j = 0; j < pItem->lstOutputNode.count(); j++) {
//            qDebug() << pItem->lstOutputNode.at( j ).jointWithVP4000ChannelID;
//        }
        smatrix.lstScene = pItem->lstScene;       // 场景列表

        lstMatrix.append( smatrix );
    }

    MainWindow *pMainWindow = BCCommon::Application();
    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->SetMatrixConfig( lstMatrix );

    // 3.更新数据库默认场景
    QList<BCMRoom *> lstMRoom = pMainWindow->GetMRooms();
    for (int i = 0; i < lstMRoom.count(); i++) {
        BCMRoom *pRoom = lstMRoom.at( i );
        BCMWindowScene *pScene = pRoom->GetDefaultWindowScene();
        pScene->Update();
    }

    // 4.重新加载数据并显示
    pMainWindow->RefreshMainWindow();

    this->accept();
}

void BCSettingMatrixFormatDlg::on_m_pJointWithVP4000ConfigBtn_clicked()
{
    // 保存当前矩阵配置
    onCurrentItemChanged(NULL, ui->m_pListWidget->currentItem());

    // 找到当前的矩阵
    BCCmdMatrixListWidgetItem *pCurrentItem = dynamic_cast<BCCmdMatrixListWidgetItem *>( ui->m_pListWidget->currentItem() );
    if (NULL == pCurrentItem)
        return;

    // 显示配置对话框
    BCSettingJointMatrixChannelConfigDlg *pDlg = new BCSettingJointMatrixChannelConfigDlg(pCurrentItem, this);
    pDlg->exec();
}
