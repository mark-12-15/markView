#include "BCRibbonMainToolBarAction.h"

#include <QFileIconProvider>
#include <QAction>
#include "../Common/BCCommon.h"
#include "BCLocationDlg.h"
#include "BCToolBar.h"

#include "../Setting/BCSettingDisplayInfoDlg.h"
#include "../Setting/AlarmManagement.h"
#include "../Setting/LogQueryDialog.h"
#include "../Setting/BCSettingPerviewDlg.h"
#include "../Setting/BCOtherDeviceControlDlg.h"
#include "../Setting/BCSettingOtherDeviceControlDlg.h"
#include "../Setting/BCExProcessDialog.h"
#include "../Setting/BCSettingTaskPlanningDlg.h"
#include "../Setting/BCWarningLogWindow.h"
#include "../Setting/BCAbout.h"
//#include "../Setting/BCSettingEDIDDlg.h"
#include "../View/BCScene.h"
#include "../View/BCFaceWidget.h"
#include "../Setting/BCSettingDisplyModelStyle.h"
#include "../Setting/BCSettingMainPanelStyle.h"
#include "../Setting/BCSettingLanguageDlg.h"
#include "../Setting/BCSettingPasswordStyle.h"
#include "../Setting/BCSettingCommunicationDlg.h"
#include "../View/BCSetSignalDlg.h"
#include "../Setting/BCSettingBoardCardDlg.h"
#include "../Setting/BCPlanMapDlg.h"
#include "../Setting/BCSettingBatchSubTitlesDlg.h"
#include "../Setting/BCSettingDeviceFormatDlg.h"
#include "../Setting/BCSettingOutSideCommandDlg.h"
#include "../Setting/BCSettingDisplaySwitchConfigDlg.h"
#include "../Setting/BCSettingAutoReadInputChannelConfigDlg.h"
#include "../Model/BCMGroupScene.h"
#include "../View/BCAutoDateDlg.h"
#include "../Common/BCLocalServer.h"
#include "../Common/BCCommunication.h"
#include "../Model/BCMRoom.h"
#include "../Setting/BCSettingWindowCopyConfigDlg.h"
#include "../Setting/BCSettingRemoveShadowDlg.h"
#include "../Setting/BCSettingModifyVP2000IPDlg.h"
#include "../Setting/BCSettingMatrixFormatDlg.h"
#include "../Setting/BCSettingOutsideInterfaceDlg.h"

BCRibbonMainToolBarAction::BCRibbonMainToolBarAction(BCRibbonMainToolBar::BUTTONTYPE eType,
                                                     const BCRibbonMainToolBar::ButtonInfo &btn,
                                                     const QIcon &icon, const QString &text,
                                                     QObject *parent)
    :QAction(icon, text, parent)
{
    m_eType = eType;
    m_btn = btn;
    m_pWindow = NULL;
    m_pOtherDeviceMgrDlg = NULL;
    m_pLocationDlg = NULL;

    init();
}

BCRibbonMainToolBarAction::BCRibbonMainToolBarAction(const QString &qsExtendPath, QObject *parent)
    :QAction(parent)
{
    m_eType = BCRibbonMainToolBar::EXTEND;
    m_qsExtendPath = qsExtendPath;
    m_pWindow = NULL;
    m_pOtherDeviceMgrDlg = NULL;
    m_pLocationDlg = NULL;

    init();
}

BCRibbonMainToolBarAction::~BCRibbonMainToolBarAction()
{
    if (NULL != m_pWindow) {
        delete m_pWindow;
        m_pWindow = NULL;
    }

    if (NULL != m_pOtherDeviceMgrDlg) {
        delete m_pOtherDeviceMgrDlg;
        m_pOtherDeviceMgrDlg = NULL;
    }

    if (NULL != m_pLocationDlg) {
        delete m_pLocationDlg;
        m_pLocationDlg = NULL;
    }
}

void BCRibbonMainToolBarAction::init()
{
    MainWindow *pApplication = BCCommon::Application();
    switch ( m_eType ) {
    case BCRibbonMainToolBar::COMMUNICATION:
        // 通讯设置
        QObject::connect(this, SIGNAL(triggered(bool)), pApplication, SLOT(onRefreshConnect()));
        break;
    case BCRibbonMainToolBar::WINDOWSCENELOOP:
        // 轮训设置
        QObject::connect(this, SIGNAL(triggered(bool)), this, SLOT(onLoopSceneChanged(bool)));
        break;
    case BCRibbonMainToolBar::CLEARDISPLAY:
        // 清空屏幕
        QObject::connect(this, SIGNAL(triggered(bool)), pApplication, SLOT(onClearCurrentGroupDisplaySignalWindow()));
        break;
    case BCRibbonMainToolBar::LOCATION:
        // 快递定位
        QObject::connect(this, SIGNAL(triggered(bool)), this, SLOT(onLocation(bool)));
        break;
    case BCRibbonMainToolBar::RUNINBACKGROUND:
        // 后台运行
        QObject::connect(this, SIGNAL(triggered(bool)), pApplication, SLOT(onHide()));
        break;
    case BCRibbonMainToolBar::QUIT:
        // 退出系统
        QObject::connect(this, SIGNAL(triggered(bool)), pApplication, SLOT(onTrayIconQuit()));
        break;
    case BCRibbonMainToolBar::OPENALLECHO:
        // 打开或关闭所有信号窗的回显
        QObject::connect(this, SIGNAL(triggered(bool)), pApplication, SLOT(onSetAllSignalEchoVisibel()));
        break;
    case BCRibbonMainToolBar::DISPLAYSWITCH:
        // 打开或关闭当前大屏显示与否
        QObject::connect(this, SIGNAL(triggered(bool)), this, SLOT(onDisplaySwitch()));
        break;
    case BCRibbonMainToolBar::FLOORPLANNINGSWITCH:
        QObject::connect(this, SIGNAL(triggered(bool)), pApplication, SLOT(onSetFloorPlanningSwitch()));
        break;
    case BCRibbonMainToolBar::FLOORPLANNINGSYNC:
        QObject::connect(this, SIGNAL(triggered(bool)), pApplication, SLOT(onSetFloorPlanningSync()));
        break;
    case BCRibbonMainToolBar::SYNCCHRONIZATION:
    case BCRibbonMainToolBar::SINGLESYNCCHRONIZATION:
        // 打开或关闭所有信号窗的回显
        QObject::connect(this, SIGNAL(triggered(bool)), this, SLOT(onSync()));
        break;
//    case BCRibbonMainToolBar::GROUPSCENE: {
//        QString qsIconPath = BCCommon::g_bGroupScene ? m_btn.m_qsIconOnPath : m_btn.m_qsIconOffPath;
//        this->setIcon(QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+qsIconPath));

//        QObject::connect(this, SIGNAL(triggered(bool)), this, SLOT(onGroupScene()));
//    }
//        break;
    case BCRibbonMainToolBar::EXTEND: {
            QFileInfo fileinfo( m_qsExtendPath );
            QFileIconProvider iconProvider;
            QIcon srcIcon = iconProvider.icon(fileinfo);
            QPixmap pix = srcIcon.pixmap(48, 48);
            setIcon( QIcon(pix.scaled(48, 48)) );
            setText( fileinfo.baseName() );

            // 打开外部程序
            QObject::connect(this, SIGNAL(triggered(bool)), this, SLOT(onExtend(bool)));
        }
        break;
    case BCRibbonMainToolBar::EDIDINPUT:
    case BCRibbonMainToolBar::EDITOUTPUT:
        // 打开外部程序
        QObject::connect(this, SIGNAL(triggered(bool)), this, SLOT(onEDIDSetting(bool)));
        break;
        // 工具条显示与否
    case BCRibbonMainToolBar::SIGNALSOURCETOOLBAR:
    case BCRibbonMainToolBar::REVIEWTOOLBAR:
    case BCRibbonMainToolBar::EXTENDTOOLBAR:
        QObject::connect(this, SIGNAL(triggered(bool)), this, SLOT(onVisibleToolBar(bool)));
        break;
    case BCRibbonMainToolBar::LOGOFF:
        QObject::connect(this, SIGNAL(triggered(bool)), pApplication, SLOT(onSwitchUser(bool)));
        break;
    case BCRibbonMainToolBar::DEBUGDLG:
        QObject::connect(this, SIGNAL(triggered(bool)), pApplication, SLOT(onDebugDlgVisble()));
        break;
    case BCRibbonMainToolBar::WINDOWSCENEADD:
    case BCRibbonMainToolBar::WINDOWSCENEDELETE:
    case BCRibbonMainToolBar::WINDOWSCENEUPDATE:
    case BCRibbonMainToolBar::WINDOWSCENESET:
        QObject::connect(this, SIGNAL(triggered(bool)), this, SLOT(onSceneSet(bool)));
        break;
    case BCRibbonMainToolBar::OTHERDEVICE:
        QObject::connect(this, SIGNAL(triggered(bool)), this, SLOT(onOtherDeviceMgr()));
        break;
    case BCRibbonMainToolBar::SIGNALSOURCESET:
    case BCRibbonMainToolBar::SKINSET:
    case BCRibbonMainToolBar::LOGINSET:
    case BCRibbonMainToolBar::STARTUPSET:
    case BCRibbonMainToolBar::CLICKCLOSESET:
    case BCRibbonMainToolBar::LANGUAGE:
    case BCRibbonMainToolBar::DEVICESEARCH:
    case BCRibbonMainToolBar::DEVICEPARAMETER:
    case BCRibbonMainToolBar::MATRIXSET:
    case BCRibbonMainToolBar::DEVICEDISPLAYINFO:
    case BCRibbonMainToolBar::DEVICETIMING:
    case BCRibbonMainToolBar::DEVICETEST:
    case BCRibbonMainToolBar::WARNINGMANAGER:
    case BCRibbonMainToolBar::WARNINGLOG:
    case BCRibbonMainToolBar::OPERATIONLOG:
    case BCRibbonMainToolBar::PURVIEW:
    case BCRibbonMainToolBar::MODIFYPASSWORD:
    case BCRibbonMainToolBar::CONFIGFILE:
    case BCRibbonMainToolBar::ABOUT:
    case BCRibbonMainToolBar::BOARDBITMAP:
    case BCRibbonMainToolBar::EXTENDMANAGER:
    case BCRibbonMainToolBar::CHECKUPDATE:
    case BCRibbonMainToolBar::LISENCE:
    case BCRibbonMainToolBar::SYSTEMBACKUP:
    case BCRibbonMainToolBar::SYSTEMRESTORE:
    case BCRibbonMainToolBar::INPUTSET:
    case BCRibbonMainToolBar::DEVICEDISPLAYSET:
    case BCRibbonMainToolBar::MONITORSET:
    case BCRibbonMainToolBar::PLANMAP:
    case BCRibbonMainToolBar::BATCHSUBTITLES:
    case BCRibbonMainToolBar::DEVICEFORMAT:
    case BCRibbonMainToolBar::OUTSIDECOMMAND:
    case BCRibbonMainToolBar::DISPLAYSWITCHCONFIG:
    case BCRibbonMainToolBar::AUTOREADINPUTCONFIG:
    case BCRibbonMainToolBar::WINDOWCOPYCONFIG:
    case BCRibbonMainToolBar::MODIFYDEVICEIP:
    case BCRibbonMainToolBar::REMOVESHADOW:
    case BCRibbonMainToolBar::MATRIXFORMAT:
    case BCRibbonMainToolBar::OUTSIZEINTERFACE:
        QObject::connect(this, SIGNAL(triggered(bool)), this, SLOT(onShowDialog(bool)));
        break;
    default:
        break;
    }
}

void BCRibbonMainToolBarAction::onLoopSceneChanged(bool)
{
    MainWindow *pApplication = BCCommon::Application();
    BCToolBar *pToolBar = pApplication->GetToolBar(MainWindow::SIGNALSOURCETOOLBAR);
    if (NULL == pToolBar)
        return;

    BCMRoom *pMRoom = pApplication->GetCurrentSceneMRoom();
    if (NULL != pMRoom) {
        pMRoom->SetLoopWindowScene( !pMRoom->IsLoopWindowScene() );

        QString qsIconPath = pMRoom->IsLoopWindowScene() ? m_btn.m_qsIconOnPath : m_btn.m_qsIconOffPath;
        this->setIcon(QIcon( BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+qsIconPath ));
        this->setText(pMRoom->IsLoopWindowScene() ? tr("停止轮巡") : tr("启动轮巡"));
    } else {
        BCCommunication *pCommunication = BCCommunication::Application();
        if ( !pMRoom->IsLoopWindowScene() ) {
            pCommunication->RequestControlByGroupScene(pMRoom->GetRoomID(), 0);
        } else {
            // 如果是关闭轮训则直接结束请求
            pCommunication->RequestOver( pMRoom->GetRoomID() );

            // 直接改变图标为未选中
            this->setIcon(QIcon( BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+m_btn.m_qsIconOffPath ));
        }
    }
}

void BCRibbonMainToolBarAction::onSync()
{
    BCLocalServer *pServer = BCLocalServer::Application();

    if (BCRibbonMainToolBar::SYNCCHRONIZATION == m_eType) {
        bool bSync = pServer->IsSynchronization();
        pServer->SetSynchronization( !bSync );

        QString qsIconPath = !bSync ? m_btn.m_qsIconOnPath : m_btn.m_qsIconOffPath;
        this->setIcon(QIcon( BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+qsIconPath ));
    } else {
        pServer->SingleSync();
    }

}

void BCRibbonMainToolBarAction::onGroupScene()
{
//    BCCommon::g_bGroupScene = !BCCommon::g_bGroupScene;

//    // 1.修改图标
//    QString qsIconPath = BCCommon::g_bGroupScene ? m_btn.m_qsIconOnPath : m_btn.m_qsIconOffPath;
//    this->setIcon(QIcon( BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+qsIconPath ));

//    // 2.刷新场景内数据
//    MainWindow *pApplication = BCCommon::Application();
//    BCToolBar *pToolBar = pApplication->GetToolBar(MainWindow::SIGNALSOURCETOOLBAR);
//    if (NULL == pToolBar)
//        return;

//    BCFaceWidget* pWidget = dynamic_cast<BCFaceWidget *>( pToolBar->widget() );
//    if (NULL == pWidget)
//        return;

//    pWidget->Refresh( 0 );
}

void BCRibbonMainToolBarAction::onDisplaySwitch()
{
    MainWindow *pApplication = BCCommon::Application();
    BCMRoom *pRoom = pApplication->GetCurrentMRoom();
    if (NULL == pRoom)
        return;

    bool bIsSwitchOn = pRoom->IsSwitchOn();
    pRoom->SetSwitchOn( !bIsSwitchOn );

    QString qsIconPath = !bIsSwitchOn ? m_btn.m_qsIconOnPath : m_btn.m_qsIconOffPath;
    this->setIcon(QIcon( BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+qsIconPath ));
}

void BCRibbonMainToolBarAction::RefreshPreview()
{
    MainWindow *pApplication = BCCommon::Application();

    QString qsIconPath = pApplication->IsOpenAllSignalEcho() ? m_btn.m_qsIconOnPath : m_btn.m_qsIconOffPath;
    this->setIcon(QIcon( BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+qsIconPath ));
}

void BCRibbonMainToolBarAction::RefreshFloorPlanning()
{
    MainWindow *pApplication = BCCommon::Application();

    QString qsIconPath = pApplication->IsFloorPlanningSwitch() ? m_btn.m_qsIconOnPath : m_btn.m_qsIconOffPath;
    this->setIcon(QIcon( BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+qsIconPath ));
    this->setText(pApplication->IsFloorPlanningSwitch() ? tr("正常模式") : tr("预设模式"));
}

void BCRibbonMainToolBarAction::RefreshCommunication()
{
    QString qsIconPath = BCCommon::g_bConnectStatusOK ? m_btn.m_qsIconOnPath : m_btn.m_qsIconOffPath;
    this->setIcon(QIcon( BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+qsIconPath ));
}

void BCRibbonMainToolBarAction::Refresh(BCMRoom *pRoom)
{
    // 判断类型
    if (BCRibbonMainToolBar::DISPLAYSWITCH != m_eType)
        return;

    QString qsIconPath = pRoom->IsSwitchOn() ? m_btn.m_qsIconOnPath : m_btn.m_qsIconOffPath;
    this->setIcon(QIcon( BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+qsIconPath ));
}

void BCRibbonMainToolBarAction::DestroyLocationDlg()
{
    if (NULL != m_pLocationDlg) {
        delete m_pLocationDlg;
        m_pLocationDlg = NULL;
    }
}

void BCRibbonMainToolBarAction::onLocation(bool)
{
    if (NULL == m_pLocationDlg) {
        m_pLocationDlg = new BCLocationDlg( BCCommon::Application() );
    }

    m_pLocationDlg->show();
    m_pLocationDlg->Refresh();
}

void BCRibbonMainToolBarAction::RefreshLocationDlg()
{
    // 判断类型
    if (BCRibbonMainToolBar::LOCATION != m_eType)
        return;

    // 判断是否构造了
    if (NULL == m_pLocationDlg)
        return;

    // 判断是否显示
    if ( !m_pLocationDlg->isVisible() )
        return;

    // 刷新
    m_pLocationDlg->Refresh();
}

void BCRibbonMainToolBarAction::RefreshAndShowLocationDlg()
{
    // 判断类型
    if (BCRibbonMainToolBar::LOCATION != m_eType)
        return;

    // 显示定位对话框
    onLocation(true);
}

void BCRibbonMainToolBarAction::onExtend(bool)
{
    // 程序退出自动释放进程
    QProcess *pProcess = new QProcess();
    QString qs = QDir::toNativeSeparators( m_qsExtendPath );
    qs = "\""+qs+"\"";
    pProcess->start(qs);
}

void BCRibbonMainToolBarAction::onEDIDSetting(bool)
{
    // 程序退出自动释放进程
//    QProcess *pProcess = new QProcess();
//    QString qs = QDir::toNativeSeparators( "EdidEditor.exe" );
//    qs = "\""+qs+"\"";
//    pProcess->start(qs);
//    BCSettingEDIDDlg *pDlg = new BCSettingEDIDDlg( BCCommon::Application() );
//    pDlg->exec();
}

void BCRibbonMainToolBarAction::onVisibleToolBar(bool)
{
    MainWindow::TOOLBARTYPE eType;
    switch (m_eType) {
    case BCRibbonMainToolBar::MAINTOOLBAR:
        eType = MainWindow::MAINTOOLBAR;
        break;
    case BCRibbonMainToolBar::SIGNALSOURCETOOLBAR:
        eType = MainWindow::SIGNALSOURCETOOLBAR;
        break;
    case BCRibbonMainToolBar::REVIEWTOOLBAR:
        eType = MainWindow::REVIEWTOOLBAR;
        break;
    case BCRibbonMainToolBar::EXTENDTOOLBAR:
        eType = MainWindow::EXTENDTOOLBAR;
        break;
    default:
        return;
    }

    MainWindow *pApplication = BCCommon::Application();
    BCToolBar *pToolBar = pApplication->GetToolBar( eType );
    if (NULL != pToolBar) {
        pToolBar->setVisible( !pToolBar->isVisible() );
    }
}

void BCRibbonMainToolBarAction::onSceneSet(bool)
{
    MainWindow *pApplication = BCCommon::Application();
    BCToolBar *pToolBar = pApplication->GetToolBar(MainWindow::SIGNALSOURCETOOLBAR);
    if (NULL == pToolBar)
        return;

    BCFaceWidget* pWidget = dynamic_cast<BCFaceWidget *>( pToolBar->widget() );
    if (NULL == pWidget)
        return;

    BCScene *pScene = dynamic_cast<BCScene *>(pWidget->GetWidget(MainWindow::WINDOWSCENESIGSRC));
    if(pScene == NULL){
        return;
    }
    switch (m_eType) {
    case BCRibbonMainToolBar::WINDOWSCENEADD:
        pScene->SetAction( 1 );
        break;
    case BCRibbonMainToolBar::WINDOWSCENEDELETE:
        pScene->SetAction( 2 );
        break;
    case BCRibbonMainToolBar::WINDOWSCENEUPDATE:
        pScene->SetAction( 3 );
        break;
    case BCRibbonMainToolBar::WINDOWSCENESET: {
        pApplication->SetWindowSceneSetSwitch( !pApplication->IsWindowSceneSetSwitch() );
        pScene->SetAction( 4 );
        QString icon = pApplication->IsWindowSceneSetSwitch() ? m_btn.m_qsIconOnPath : m_btn.m_qsIconOffPath;
        this->setIcon( QIcon( BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+icon ) );
    }
        break;
    default:
        break;
    }
}

void BCRibbonMainToolBarAction::onOtherDeviceMgr()
{
    if (NULL == m_pOtherDeviceMgrDlg) {
        //m_pOtherDeviceMgrDlg = new BCOtherDeviceControlDlg( BCCommon::Application() );
        m_pOtherDeviceMgrDlg = new BCSettingOtherDeviceControlDlg( BCCommon::Application() );
    }

    m_pOtherDeviceMgrDlg->show();
}

void BCRibbonMainToolBarAction::onShowDialog(bool)
{
    // 点击时创建对话框
    QDialog *pDlg = NULL;
    switch ( m_eType ) {
    case BCRibbonMainToolBar::SKINSET:
        break;
    case BCRibbonMainToolBar::LOGINSET:
        //pDlg = new MyDialog( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::STARTUPSET:
        pDlg = new BCSettingDisplyModelStyle( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::CLICKCLOSESET:
        pDlg = new BCSettingMainPanelStyle(BCCommon::Application());
        break;
    case BCRibbonMainToolBar::LANGUAGE:
        pDlg = new BCSettingLanguageDlg( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::DEVICESEARCH:
        pDlg = new BCSettingCommunicationDlg( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::DEVICEPARAMETER:
        //pDlg = new BCSettingMontageDlg( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::MATRIXSET:
        //pDlg = new BCSettingMatrixDlg( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::DEVICEDISPLAYINFO:
        pDlg = new BCSettingDisplayInfoDlg( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::DEVICETIMING:
        pDlg = new BCSettingTaskPlanningDlg( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::DEVICETEST:
        //pDlg = new TestColor( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::WARNINGMANAGER:
        pDlg = new AlarmManagement( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::WARNINGLOG:
        pDlg = new BCWarningLogWindow( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::OPERATIONLOG:
        pDlg = new LogQueryDialog( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::PURVIEW:
        pDlg = new BCSettingPerviewDlg( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::MODIFYPASSWORD:
        pDlg = new BCSettingPasswordStyle(BCCommon::Application(), false);
        break;
    case BCRibbonMainToolBar::CONFIGFILE:
        //pDlg = new ConfigurationFile( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::ABOUT:
        pDlg = new BCAbout( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::BOARDBITMAP:
        //pDlg = new BCBoardSlot( BCCommon::Application() );
        pDlg = new BCSettingBoardCardDlg( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::EXTENDMANAGER: {
            BCRibbonMainToolBar *pMainToolBar = dynamic_cast<BCRibbonMainToolBar *>( parent() );
            if (NULL != pMainToolBar)
                pDlg = new BCExProcessDialog(pMainToolBar->GetExtendButtonPath(), BCCommon::Application());
        }
        break;
    case BCRibbonMainToolBar::CHECKUPDATE:
        pDlg = new BCAutoDateDlg( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::INPUTSET:
        //
        break;
    case BCRibbonMainToolBar::SIGNALSOURCESET:
        pDlg = new BCSetSignalDlg( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::DEVICEDISPLAYSET:
        //
        break;
    case BCRibbonMainToolBar::MONITORSET:
        //pDlg = new BCSettingMonitorDlg( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::PLANMAP:
        pDlg = new BCPlanMapDlg( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::BATCHSUBTITLES:
        pDlg = new BCSettingBatchSubTitlesDlg( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::DEVICEFORMAT:
        pDlg = new BCSettingDeviceFormatDlg( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::OUTSIDECOMMAND:
        pDlg = new BCSettingOutSideCommandDlg(0, BCCommon::Application());
        break;
    case BCRibbonMainToolBar::LISENCE:
        pDlg = new BCSettingOutSideCommandDlg(1, BCCommon::Application());
        break;
    case BCRibbonMainToolBar::DISPLAYSWITCHCONFIG:
        pDlg = new BCSettingDisplaySwitchConfigDlg( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::AUTOREADINPUTCONFIG:
        pDlg = new BCSettingAutoReadInputChannelConfigDlg( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::WINDOWCOPYCONFIG:
        pDlg = new BCSettingWindowCopyConfigDlg( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::MODIFYDEVICEIP:
        pDlg = new BCSettingModifyVP2000IPDlg( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::REMOVESHADOW:
        pDlg = new BCSettingRemoveShadowDlg( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::MATRIXFORMAT:
        pDlg = new BCSettingMatrixFormatDlg( BCCommon::Application() );
        break;
    case BCRibbonMainToolBar::OUTSIZEINTERFACE:
        pDlg = new BCSettingOutsideInterfaceDlg( BCCommon::Application() );
        break;
    default:
        break;
    }

    if (NULL == pDlg)
        return;

    pDlg->exec();
}

void BCRibbonMainToolBarAction::Refresh()
{
    // 开关类和扩展按钮不需要刷新皮肤
    if ((BCRibbonMainToolBar::EXTEND == m_eType) || (BCRibbonMainToolBar::WINDOWSCENELOOP == m_eType))
        return;

    this->setIcon( QIcon( BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+m_btn.m_qsIconOffPath ) );
}

//void BCRibbonMainToolBarAction::Refresh(BCMGroupScene *pGroupScene)
//{
//    // 只有轮训场景按钮设置有效
//    if ((m_eType != BCRibbonMainToolBar::WINDOWSCENELOOP) || (NULL == pGroupScene))
//        return;

//    QString qsIconPath = pGroupScene->IsLoopWindowScene() ? m_btn.m_qsIconOnPath : m_btn.m_qsIconOffPath;
//    this->setIcon(QIcon( BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+qsIconPath ));
//}

void BCRibbonMainToolBarAction::RefreshSceneLoop(BCMRoom *pRoom)
{
    // 只有轮训场景按钮设置有效
    if ((m_eType != BCRibbonMainToolBar::WINDOWSCENELOOP) || (NULL == pRoom))
        return;

    QString qsIconPath = pRoom->IsLoopWindowScene() ? m_btn.m_qsIconOnPath : m_btn.m_qsIconOffPath;
    this->setIcon(QIcon( BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+qsIconPath ));
}

