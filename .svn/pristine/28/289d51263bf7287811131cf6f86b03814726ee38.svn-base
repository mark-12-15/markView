#include "BCSettingJointMatrixChannelConfigDlg.h"
#include "ui_BCSettingJointMatrixChannelConfigDlg.h"
#include "BCSettingMatrixFormatDlg.h"
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"
#include "../Model/BCMChannel.h"

class BCSettingJointMatrixTreeWidgetItem : public QTreeWidgetItem
{
public:
    BCSettingJointMatrixTreeWidgetItem(int id, int type, const QString &name) {
        m_id = id;
        m_type = type;
        m_name = name;

        this->setText(0, m_name);
    }
    BCSettingJointMatrixTreeWidgetItem(const sMatrixNode &node) {
        m_id = node.id;
        m_name = node.name;
        nSwitch = node.nSwitch;
        nSwitchID = node.nSwitchID;
        jointWithVP4000ChannelID = node.jointWithVP4000ChannelID;
        jointWithVP2000ChannelType = node.jointWithVP2000ChannelType;
        isOn = node.isOn;
        qsOnCmd = node.qsOnCmd;
        qsOffCmd = node.qsOffCmd;

        if (-1 == jointWithVP4000ChannelID) {
            this->setText(0, m_name);
        } else {
            MainWindow *pMainWindow = BCCommon::Application();
            QList<BCMChannel *> lstChannel = pMainWindow->GetInputChannels();
            for (int i = 0; i < lstChannel.count(); i++) {
                BCMChannel *pChannel = lstChannel.at( i );
                int chid = pChannel->GetChannelID();
                int chtype = pChannel->GetChannelType();
                if (BCCommon::g_nDeviceType == 0) { // vp2000
                    chtype = (4 == chtype) ? 1 : chtype;
                }
                // 4000只判断ID
                if (((BCCommon::g_nDeviceType == 1) || (BCCommon::g_nDeviceType == 2)) && (jointWithVP4000ChannelID == chid)) {
                    qDebug() << chid;
                    m_switchname = pChannel->GetChannelBaseName();
                    SetSwtich(jointWithVP4000ChannelID, jointWithVP2000ChannelType, m_switchname);
                }

                // 2000判断id和type
                if ((BCCommon::g_nDeviceType == 0) && (jointWithVP4000ChannelID == chid) && (jointWithVP2000ChannelType == chtype)) {
                    m_switchname = pChannel->GetChannelBaseName();
                    SetSwtich(jointWithVP4000ChannelID, jointWithVP2000ChannelType, m_switchname);
                }
            }
        }
    }

    void SetSwtich(int id, int type, const QString &name) {
        jointWithVP4000ChannelID = id;
        jointWithVP2000ChannelType = type;
        m_switchname = name;

        this->setText(0, (-1 == jointWithVP4000ChannelID) ? m_name : QString("%1 --> %2").arg(m_name).arg(m_switchname));
    }

    // 矩阵节点属性
    int m_id;
    int m_type;
    QString m_name;
    int nSwitch;    // 是否被切换信号
    int nSwitchID;  // 切换的信号ID

    int isOn;                       // 大屏开关状态
    QString qsOnCmd;                // 打开指令
    QString qsOffCmd;               // 关闭指令

    // 变量针对矩阵输出口
    int jointWithVP4000ChannelID;
    int jointWithVP2000ChannelType; // 级联设备的输入通道Type
    QString m_switchname;
};

BCSettingJointMatrixChannelConfigDlg::BCSettingJointMatrixChannelConfigDlg(BCCmdMatrixListWidgetItem *pItem, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingJointMatrixChannelConfigDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("矩阵级联设置"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    m_pItem = pItem;

    // init
    ui->m_pMatrixTreeWidget->setHeaderHidden( true );
    ui->m_pVP4000TreeWidget->setHeaderHidden( true );

    // 添加矩阵输入口列表
    for (int i = 0; i < pItem->lstOutputNode.count(); i++) {
        sMatrixNode node = pItem->lstOutputNode.at( i );
        ui->m_pMatrixTreeWidget->addTopLevelItem( new BCSettingJointMatrixTreeWidgetItem( node ) );
    }

    // 添加输入通道
    MainWindow *pMainWindow = BCCommon::Application();
    QList<BCMChannel *> lstChannel = pMainWindow->GetInputChannels();
    for (int i = 0; i < lstChannel.count(); i++) {
        BCMChannel *pChannel = lstChannel.at( i );
        ui->m_pVP4000TreeWidget->addTopLevelItem( new BCSettingJointMatrixTreeWidgetItem(pChannel->GetChannelID(), pChannel->GetChannelType(), pChannel->GetChannelBaseName()) );
    }

    ui->m_pMatrixTreeWidget->viewport()->installEventFilter( this );
}

BCSettingJointMatrixChannelConfigDlg::~BCSettingJointMatrixChannelConfigDlg()
{
    delete ui;
}

bool BCSettingJointMatrixChannelConfigDlg::eventFilter(QObject *target, QEvent *event)
{
    if (target == ui->m_pMatrixTreeWidget->viewport()) {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *pMouseEvent = static_cast<QMouseEvent *>(event);
            if (NULL != pMouseEvent) {
                BCSettingJointMatrixTreeWidgetItem *pMatrixItem = dynamic_cast<BCSettingJointMatrixTreeWidgetItem *>( ui->m_pMatrixTreeWidget->itemAt( pMouseEvent->pos() ) );
                BCSettingJointMatrixTreeWidgetItem *pChannelItem = dynamic_cast<BCSettingJointMatrixTreeWidgetItem *>( ui->m_pVP4000TreeWidget->currentItem() );
                if ((NULL != pMatrixItem) && (NULL != pChannelItem)) {
                    pMatrixItem->SetSwtich(pChannelItem->m_id, pChannelItem->m_type, pChannelItem->m_name);
                    return true;
                }
            }
        } else if (event->type() == QEvent::MouseButtonDblClick) {
            QMouseEvent *pMouseEvent = static_cast<QMouseEvent *>(event);
            if (NULL != pMouseEvent) {
                BCSettingJointMatrixTreeWidgetItem *pMatrixItem = dynamic_cast<BCSettingJointMatrixTreeWidgetItem *>( ui->m_pMatrixTreeWidget->itemAt( pMouseEvent->pos() ) );
                if (NULL != pMatrixItem) {
                    pMatrixItem->SetSwtich(-1, -1, QString::null);
                    return true;
                }
            }
        }
    }

    return QDialog::eventFilter(target, event);
}

void BCSettingJointMatrixChannelConfigDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingJointMatrixChannelConfigDlg::on_m_pOKBtn_clicked()
{
    QList<QPoint> lst;
    m_pItem->lstOutputNode.clear();
    for (int i = 0; i < ui->m_pMatrixTreeWidget->topLevelItemCount(); i++) {
        BCSettingJointMatrixTreeWidgetItem *pItem = dynamic_cast<BCSettingJointMatrixTreeWidgetItem *>( ui->m_pMatrixTreeWidget->topLevelItem( i ) );
        if (NULL == pItem)
            continue;

        sMatrixNode node;
        node.id = pItem->m_id;
        node.name = pItem->m_name;
        node.nSwitch = pItem->nSwitch;
        node.nSwitchID = pItem->nSwitchID;
        node.jointWithVP4000ChannelID = pItem->jointWithVP4000ChannelID;
        node.jointWithVP2000ChannelType = pItem->jointWithVP2000ChannelType;
        node.isOn = pItem->isOn;
        node.qsOnCmd = pItem->m_id;
        node.qsOffCmd = pItem->qsOffCmd;

        m_pItem->lstOutputNode.append( node );

        lst.append( QPoint(node.id, node.jointWithVP4000ChannelID) );
    }

    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->UpdateMatrixJointChannel(m_pItem->m_id, lst);

    this->accept();
}
