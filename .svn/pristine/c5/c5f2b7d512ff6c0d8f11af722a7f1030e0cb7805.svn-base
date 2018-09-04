#include "BCSettingDisplaySwitchConfigDlg.h"
#include "ui_BCSettingDisplaySwitchConfigDlg.h"
#include "../Common/BCCommon.h"
#include "BCSettingDisplaySwitchRoomWidget.h"
#include "BCSettingDisplayMakerConfigDlg.h"

BCSettingDisplaySwitchConfigDlg::BCSettingDisplaySwitchConfigDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingDisplaySwitchConfigDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("屏幕配置"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    // 背景色颜色有误差，需要设置一下
    ui->m_pScrollArea->setAutoFillBackground( false );

    // 初始化大屏厂家
    InitDisplayMaker();

    // 设置房间列表的layout
    QVBoxLayout *pRoomLayout = new QVBoxLayout( ui->widget );
    ui->widget->setLayout( pRoomLayout );

    // 循环房间列表
    MainWindow *pMainWindow = BCCommon::Application();
    QList<BCMRoom *> lstRoom = pMainWindow->GetMRooms();
    for (int i = 0; i < lstRoom.count(); i++) {
        BCMRoom *pRoom = lstRoom.at( i );
        BCSettingDisplaySwitchRoomWidget *pRoomWidget = new BCSettingDisplaySwitchRoomWidget(pRoom, this);
        pRoomWidget->RefreshDisplayMaker( m_lstDisplayMaker );

        m_lstRoomWidget.append( pRoomWidget );

        pRoomLayout->addWidget( pRoomWidget );
    }
}

BCSettingDisplaySwitchConfigDlg::~BCSettingDisplaySwitchConfigDlg()
{
    delete ui;
}

void BCSettingDisplaySwitchConfigDlg::InitDisplayMaker()
{
    // 判断文件是否可读
    QFile file( QString("../xml/BCDisplaySwitchMakerConfig.xml") );
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

    for (int i = 0; i < docElem.childNodes().count(); i++) {
        QDomNode nodeRoom = docElem.childNodes().at(i);
        if ( !nodeRoom.isElement() )
            continue;

        sDisplayMaker smaker;
        QDomElement eleRoom = nodeRoom.toElement();
        smaker.maker = eleRoom.attribute(QString("Maker"));
        smaker.cmdType = eleRoom.attribute(QString("CmdType")).toInt();
        smaker.onCmd = eleRoom.attribute(QString("OnCmd"));
        smaker.offCmd = eleRoom.attribute(QString("OffCmd"));

        m_lstDisplayMaker.append( smaker );
    }
}

void BCSettingDisplaySwitchConfigDlg::SetDisplayMaker(const QList<sDisplayMaker> &lstDisplayMaker)
{
    // 刷新界面
    m_lstDisplayMaker = lstDisplayMaker;
    for (int i = 0; i < m_lstRoomWidget.count(); i++) {
        BCSettingDisplaySwitchRoomWidget *pRoomWidget = m_lstRoomWidget.at( i );
        pRoomWidget->RefreshDisplayMaker( m_lstDisplayMaker );
    }

    // 保存到文件
    QDomDocument doc;
    QDomElement eleRoot = doc.createElement(QString("BR"));

    for (int i = 0; i < lstDisplayMaker.count(); i++) {
        sDisplayMaker smaker = lstDisplayMaker.at( i );

        QDomElement eleRoomNode = doc.createElement(QString("Node"));
        eleRoomNode.setAttribute(QString("Maker"), smaker.maker);
        eleRoomNode.setAttribute(QString("CmdType"), smaker.cmdType);
        eleRoomNode.setAttribute(QString("OnCmd"), smaker.onCmd);
        eleRoomNode.setAttribute(QString("OffCmd"), smaker.offCmd);

        eleRoot.appendChild( eleRoomNode );
    }

    // 添加根节点
    doc.appendChild( eleRoot );

    // 写入文件
    QFile file( QString("../xml/BCDisplaySwitchMakerConfig.xml") );
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}

void BCSettingDisplaySwitchConfigDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingDisplaySwitchConfigDlg::on_m_pOKBtn_clicked()
{
    for (int i = 0; i < m_lstRoomWidget.count(); i++) {
        BCSettingDisplaySwitchRoomWidget *pRoomWidget = m_lstRoomWidget.at( i );
        pRoomWidget->SaveConfig();
    }

    this->accept();
}

void BCSettingDisplaySwitchConfigDlg::on_m_pDisplayMakerBtn_clicked()
{
    BCSettingDisplayMakerConfigDlg *pDlg = new BCSettingDisplayMakerConfigDlg(m_lstDisplayMaker, this);
    pDlg->exec();
}
