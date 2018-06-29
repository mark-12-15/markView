#include "BCRibbonMainToolBar.h"

#include "../Main/MainWindow.h"
#include "../Common/BCCommon.h"
#include "BCRibbonMainToolBarAction.h"
#include "../Common/BCLocalServer.h"
#include "../Model/BCMRoom.h"

class BCRibbonPage : public RibbonPage
{
public:
    BCRibbonPage();
};

BCRibbonMainToolBar::BCRibbonMainToolBar()
    :QObject(0)
{
    // 扩展page和group专用
    pExtendPage = NULL;
    pExtendGroup = NULL;

    RefreshMap();
}

BCRibbonMainToolBar::~BCRibbonMainToolBar()
{
}

void BCRibbonMainToolBar::RefreshMap()
{
    m_mapMainTabTypeName.clear();
    m_mapMainTabTypeName.insert(MAIN, QObject::tr("主功能"));
    m_mapMainTabTypeName.insert(SET, QObject::tr("设置"));
    m_mapMainTabTypeName.insert(OTHERTAB, QObject::tr("其他"));
    m_mapMainTabTypeName.insert(GENERIC, QObject::tr("常用功能"));
    m_mapMainTabTypeName.insert(DEVICECONFIG, QObject::tr("设备配置"));
    m_mapMainTabTypeName.insert(SYSMANAGER, QObject::tr("系统管理"));

    m_mapMainGroupTypeName.clear();
    m_mapMainGroupTypeName.insert(WINDOWMANAGER, QObject::tr("窗口管理"));
    m_mapMainGroupTypeName.insert(SCENEMANAGER, QObject::tr("场景"));
    m_mapMainGroupTypeName.insert(DEVICE, QObject::tr("设备"));
    m_mapMainGroupTypeName.insert(SYSTEM, QObject::tr("系统"));
    m_mapMainGroupTypeName.insert(EXTENDGROUP, QObject::tr("外部工具"));
    m_mapMainGroupTypeName.insert(OTHERGROUP, QObject::tr("其他"));
    m_mapMainGroupTypeName.insert(TOOLBAR, QObject::tr("工具栏"));
    m_mapMainGroupTypeName.insert(CONNECTCONFIG, QObject::tr("窗口管理"));
    m_mapMainGroupTypeName.insert(VIEWCONFIG, QObject::tr("显示配置"));
    m_mapMainGroupTypeName.insert(FUNCAIONCONFIG, QObject::tr("功能配置"));
    m_mapMainGroupTypeName.insert(FLOORPLANNING, QObject::tr("布局预设"));

    m_mapMainButtonTypeName.clear();
    m_mapMainButtonTypeName.insert(LOCATION, ButtonInfo(QObject::tr("窗口定位"), QObject::tr("快速定位窗口"), QString("location32.png")));
    m_mapMainButtonTypeName.insert(CLEARDISPLAY, ButtonInfo(QObject::tr("清空屏幕"), QObject::tr("清空屏幕"), QString("clear32.png")));
    m_mapMainButtonTypeName.insert(WINDOWSCENELOOP, ButtonInfo(QObject::tr("启动轮巡"), QObject::tr("场景轮巡开关"), QString("loopoff132.png"), QString("loopon132.png")));
    m_mapMainButtonTypeName.insert(WINDOWSCENEADD, ButtonInfo(QObject::tr("添加场景"), QObject::tr("添加场景"), QString("addscene32.png")));
    m_mapMainButtonTypeName.insert(WINDOWSCENEDELETE, ButtonInfo(QObject::tr("删除场景"), QObject::tr("删除场景"), QString("deletescene32.png")));
    m_mapMainButtonTypeName.insert(WINDOWSCENEUPDATE, ButtonInfo(QObject::tr("更新场景"), QObject::tr("更新场景"), QString("updatescene32.png")));
    m_mapMainButtonTypeName.insert(WINDOWSCENESET, ButtonInfo(QObject::tr("轮巡设置"), QObject::tr("轮巡设置"), QString("scenesetoff32.png"), QString("sceneseton32.png")));
    //m_mapMainButtonTypeName.insert(ABOUT, ButtonInfo(QObject::tr("关于"), QObject::tr("关于"), QString("about32.png")));
    m_mapMainButtonTypeName.insert(ABOUT, ButtonInfo(QObject::tr("关于"), QObject::tr("关于"), QString("about32.png")));
    m_mapMainButtonTypeName.insert(RUNINBACKGROUND, ButtonInfo(QObject::tr("后台运行"), QObject::tr("后台运行"), QString("runbackground32.png")));
    m_mapMainButtonTypeName.insert(LOGOFF, ButtonInfo(QObject::tr("切换用户"), QObject::tr("切换用户"), QString("logoff32.png")));
    m_mapMainButtonTypeName.insert(QUIT, ButtonInfo(QObject::tr("退出系统"), QObject::tr("退出系统"), QString("exit32.png")));

    m_mapMainButtonTypeName.insert(COMMUNICATION, ButtonInfo(QObject::tr("通讯开关"), QObject::tr("通讯开关"), QString("connectoff32.png"), QString("connecton32.png")));
    m_mapMainButtonTypeName.insert(DEVICESEARCH, ButtonInfo(QObject::tr("通讯"), QObject::tr("通讯"), QString("devicesearch32.png")));
    m_mapMainButtonTypeName.insert(DEVICEPARAMETER, ButtonInfo(QObject::tr("拼接"), QObject::tr("拼接"), QString("devicepara32.png")));
    m_mapMainButtonTypeName.insert(MATRIXSET, ButtonInfo(QObject::tr("矩阵"), QObject::tr("矩阵"), QString("matrix32.png")));
    m_mapMainButtonTypeName.insert(DEVICEDISPLAYINFO, ButtonInfo(QObject::tr("屏幕信息"), QObject::tr("屏幕信息"), QString("displayinfo32.png")));
    m_mapMainButtonTypeName.insert(DEVICEDISPLAYSET, ButtonInfo(QObject::tr("屏幕设置"), QObject::tr("屏幕设置"), QString("displayset32.png")));
    m_mapMainButtonTypeName.insert(MONITORSET, ButtonInfo(QObject::tr("监视器"), QObject::tr("监视器"), QString("monitorset32.png")));
    m_mapMainButtonTypeName.insert(INPUTSET, ButtonInfo(QObject::tr("输入"), QObject::tr("输入"), QString("inputset32.png")));
    m_mapMainButtonTypeName.insert(SIGNALSOURCESET, ButtonInfo(QObject::tr("信号源"), QObject::tr("信号源"), QString("signalsource32.png")));
    m_mapMainButtonTypeName.insert(BOARDBITMAP, ButtonInfo(QObject::tr("板位图"), QObject::tr("板位图"), QString("boardbitmap32.png")));
    m_mapMainButtonTypeName.insert(DEVICETEST, ButtonInfo(QObject::tr("设备测试"), QObject::tr("设备测试"), QString("test32.png")));
    m_mapMainButtonTypeName.insert(EDIDINPUT, ButtonInfo(QObject::tr("EDID输入"), QObject::tr("EDID输入"), QString("edidin32.png")));
    m_mapMainButtonTypeName.insert(EDITOUTPUT, ButtonInfo(QObject::tr("EDID输出"), QObject::tr("EDID输出"), QString("edidout32.png")));

    m_mapMainButtonTypeName.insert(SKINSET, ButtonInfo(QObject::tr("皮肤设置"), QObject::tr("皮肤设置"), QString("skin32.png")));
    m_mapMainButtonTypeName.insert(LOGINSET, ButtonInfo(QObject::tr("登录设置"), QObject::tr("登录界面设置"), QString("loginset32.png")));
    m_mapMainButtonTypeName.insert(STARTUPSET, ButtonInfo(QObject::tr("启动设置"), QObject::tr("软件初始化显示设置"), QString("startup32.png")));
    m_mapMainButtonTypeName.insert(CLICKCLOSESET, ButtonInfo(QObject::tr("关闭选项"), QObject::tr("关闭主面板时是否退出程序"), QString("clickclose32.png")));
    m_mapMainButtonTypeName.insert(LANGUAGE, ButtonInfo(QObject::tr("语言选择"), QObject::tr("语言选择"), QString("language32.png")));
    m_mapMainButtonTypeName.insert(PURVIEW, ButtonInfo(QObject::tr("人员权限"), QObject::tr("人员权限"), QString("purview32.png")));
    m_mapMainButtonTypeName.insert(MODIFYPASSWORD, ButtonInfo(QObject::tr("修改密码"), QObject::tr("修改密码"), QString("modifypassword32.png")));

    m_mapMainButtonTypeName.insert(DEVICETIMING, ButtonInfo(QObject::tr("定时任务"), QObject::tr("定时任务"), QString("timer32.png")));
    m_mapMainButtonTypeName.insert(WARNINGMANAGER, ButtonInfo(QObject::tr("报警管理"), QObject::tr("报警管理"), QString("warning32.png")));
    m_mapMainButtonTypeName.insert(WARNINGLOG, ButtonInfo(QObject::tr("报警日志"), QObject::tr("报警日志"), QString("warninglog32.png")));
    m_mapMainButtonTypeName.insert(OPERATIONLOG, ButtonInfo(QObject::tr("操作日志"), QObject::tr("操作日志"), QString("operatelog32.png")));
    m_mapMainButtonTypeName.insert(CONFIGFILE, ButtonInfo(QObject::tr("配置文件"), QObject::tr("配置文件"), QString("configure32.png")));
    m_mapMainButtonTypeName.insert(SYSTEMBACKUP, ButtonInfo(QObject::tr("系统备份"), QObject::tr("系统备份"), QString("systembackup32.png")));
    m_mapMainButtonTypeName.insert(SYSTEMRESTORE, ButtonInfo(QObject::tr("系统还原"), QObject::tr("系统还原"), QString("systemrestore32.png")));
    m_mapMainButtonTypeName.insert(CHECKUPDATE, ButtonInfo(QObject::tr("检查更新"), QObject::tr("检查更新"), QString("checkupdate32.png")));
    m_mapMainButtonTypeName.insert(LISENCE, ButtonInfo(QObject::tr("系统升级"), QObject::tr("系统升级"), QString("lisence32.png")));

    m_mapMainButtonTypeName.insert(EXTENDMANAGER, ButtonInfo(QObject::tr("外部工具"), QObject::tr("外部工具管理"), QString("extendManager32.png")));

    m_mapMainButtonTypeName.insert(MAINTOOLBAR, ButtonInfo(QObject::tr("主窗口"), QObject::tr("主窗口显示控制"), QString("maintoolbar32.png")));
    m_mapMainButtonTypeName.insert(SIGNALSOURCETOOLBAR, ButtonInfo(QObject::tr("信号源窗口"), QObject::tr("信号源窗口显示控制"), QString("inputtoolbaron32.png")));
    m_mapMainButtonTypeName.insert(REVIEWTOOLBAR, ButtonInfo(QObject::tr("预监"), QObject::tr("预监窗口显示控制"), QString("reviewtoolbaron32.png")));
    m_mapMainButtonTypeName.insert(EXTENDTOOLBAR, ButtonInfo(QObject::tr("扩展窗口"), QObject::tr("扩展窗口显示控制"), QString("extendtoolbaron32.png")));

    m_mapMainButtonTypeName.insert(PLANMAP, ButtonInfo(QObject::tr("地图"), QObject::tr("预案地图"), QString("planmap32.png")));
    m_mapMainButtonTypeName.insert(OTHERDEVICE, ButtonInfo(QObject::tr("外部设备"), QObject::tr("外部设备"), QString("otherdevice32.png")));
    m_mapMainButtonTypeName.insert(OPENALLECHO, ButtonInfo(QObject::tr("回显"), QObject::tr("所有信号窗回显"), QString("allechooff32.png"), QString("allechoon32.png")));
    m_mapMainButtonTypeName.insert(SYNCCHRONIZATION, ButtonInfo(QObject::tr("同步"), QObject::tr("实时同步其他设备状态"), QString("syncoff32.png"), QString("syncon32.png")));
    m_mapMainButtonTypeName.insert(SINGLESYNCCHRONIZATION, ButtonInfo(QObject::tr("单次同步"), QObject::tr("同步其他设备状态"), QString("syncoff32.png")));
    m_mapMainButtonTypeName.insert(GROUPSCENE, ButtonInfo(QObject::tr("分组开关"), QObject::tr("是否启用场景组"), QString("groupsceneoff32.png"), QString("groupsceneon32.png")));
    m_mapMainButtonTypeName.insert(BATCHSUBTITLES, ButtonInfo(QObject::tr("字幕设置"), QObject::tr("批量设置字幕"), QString("subtitles32.png")));
    m_mapMainButtonTypeName.insert(DEVICEFORMAT, ButtonInfo(QObject::tr("输出配置"), QObject::tr("修改设备规模"), QString("deviceformat32.png")));
    m_mapMainButtonTypeName.insert(OUTSIDECOMMAND, ButtonInfo(QObject::tr("增值服务"), QObject::tr("执行厂家配置文件"), QString("outsidecmd32.png")));

    // 155-166 是对融倍祺界面的专用按钮
    m_mapMainButtonTypeName.insert(CONNECTWITHSERIALPORT, ButtonInfo(QObject::tr("串口连接"), QObject::tr("串口连接"), QString("connectwithserialport32.png")));
    m_mapMainButtonTypeName.insert(CONNECTWITHNET, ButtonInfo(QObject::tr("网络连接"), QObject::tr("网络连接"), QString("connectwithnet32.png")));
    m_mapMainButtonTypeName.insert(COMMUNICATION, ButtonInfo(QObject::tr("通讯开关"), QObject::tr("通讯开关"), QString("connectoff32.png"), QString("connecton32.png")));
    m_mapMainButtonTypeName.insert(CONNECTSET, ButtonInfo(QObject::tr("设置"), QObject::tr("设置"), QString("startup32.png")));

    m_mapMainButtonTypeName.insert(VIEWCONFIG1, ButtonInfo(QObject::tr("参数配置"), QObject::tr("参数配置"), QString("loginset32.png")));
    m_mapMainButtonTypeName.insert(MATRIXSET1, ButtonInfo(QObject::tr("矩阵"), QObject::tr("外设矩阵"), QString("matrix32.png")));
    m_mapMainButtonTypeName.insert(MATRIXSET2, ButtonInfo(QObject::tr("外设矩阵2"), QObject::tr("外设矩阵2"), QString("matrix32.png")));
    m_mapMainButtonTypeName.insert(DEVICEDISPLAYINFO1, ButtonInfo(QObject::tr("大屏"), QObject::tr("大屏"), QString("displayinfo32.png")));

    m_mapMainButtonTypeName.insert(DEVICETEST1, ButtonInfo(QObject::tr("颜色调试"), QObject::tr("颜色调试"), QString("test32.png")));
    m_mapMainButtonTypeName.insert(DISPLAYCOORDINATE, ButtonInfo(QObject::tr("屏幕坐标设置"), QObject::tr("屏幕坐标设置"), QString("location32.png")));
    m_mapMainButtonTypeName.insert(OPENALLECHO1, ButtonInfo(QObject::tr("预监设置"), QObject::tr("预监设置"), QString("reviewtoolbaron32.png")));
    m_mapMainButtonTypeName.insert(OPENALLECHO2, ButtonInfo(QObject::tr("回显设置"), QObject::tr("回显设置"), QString("allecho32.png")));
    m_mapMainButtonTypeName.insert(TASKSET, ButtonInfo(QObject::tr("任务设置"), QObject::tr("任务设置"), QString("operatelog32.png")));

    m_mapMainButtonTypeName.insert(DISPLAYSWITCH, ButtonInfo(QObject::tr("屏幕开关"), QObject::tr("屏幕开关"), QString("ScreenOn.png"), QString("ScreenOff.png")));
    m_mapMainButtonTypeName.insert(DISPLAYSWITCHCONFIG, ButtonInfo(QObject::tr("屏幕开关设置"), QObject::tr("屏幕开关设置"), QString("ScreenSetup.png")));
    m_mapMainButtonTypeName.insert(FLOORPLANNINGSWITCH, ButtonInfo(QObject::tr("预设模式"), QObject::tr("预布局"), QString("floorplanningon32.png"), QString("floorplanningoff32.png")));
    m_mapMainButtonTypeName.insert(FLOORPLANNINGSYNC, ButtonInfo(QObject::tr("应用布局"), QObject::tr("应用布局"), QString("floorplanningsync32.png")));
    m_mapMainButtonTypeName.insert(AUTOREADINPUTCONFIG, ButtonInfo(QObject::tr("输入源配置"), QObject::tr("输入源配置"), QString("autoreadinputchannel32.png")));
    m_mapMainButtonTypeName.insert(DEBUGDLG, ButtonInfo(QObject::tr("调试窗口"), QObject::tr("调试窗口"), QString("debug32.png")));
    m_mapMainButtonTypeName.insert(WINDOWCOPYCONFIG, ButtonInfo(QObject::tr("窗口复制"), QObject::tr("窗口复制数量设置"), QString("wincopy32.png")));
    m_mapMainButtonTypeName.insert(MODIFYDEVICEIP, ButtonInfo(QObject::tr("修改IP"), QObject::tr("修改IP"), QString("modifyVP2000IP32.png")));
    m_mapMainButtonTypeName.insert(REMOVESHADOW, ButtonInfo(QObject::tr("边框削影"), QObject::tr("边框削影"), QString("removeshadow32.png")));
    m_mapMainButtonTypeName.insert(MATRIXFORMAT, ButtonInfo(QObject::tr("矩阵配置"), QObject::tr("矩阵规模"), QString("matrixformat32.png")));
    m_mapMainButtonTypeName.insert(OUTSIZEINTERFACE, ButtonInfo(QObject::tr("外部接口"), QObject::tr("外部接口"), QString("outsideinterface32.png")));
}

void BCRibbonMainToolBar::Build()
{
    MainWindow *pApplication = BCCommon::Application();
    BCSUser *pUser = pApplication->GetCurrentUser();
    if (NULL == pUser)
        return;

    BCMRoom *pMRoom = pApplication->GetCurrentSceneMRoom();

    QList<sTab> lstTab = pUser->lstTab;

    // 先清除page ui
    pApplication->ribbonBar()->clearPages();
    // 清空内存
    m_mapTabPage.clear();
    m_mapGroup.clear();
    QList<QAction *> lstDelAction = m_mapButtonAction.values();
    while ( !lstDelAction.isEmpty() )
        delete lstDelAction.takeFirst();
    m_mapButtonAction.clear();

    // 显示logo
    //pApplication->ribbonBar()->setLogoPixmap(Qt::AlignRight, QPixmap::fromImage(QImage(BCCommon::g_qsImageFilePrefix+"/backgroup/background.jpg").scaled(1008,80,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    //pApplication->ribbonBar()->setLogoPixmap(Qt::AlignLeft, QPixmap::fromImage(QImage(BCCommon::g_qsImageFilePrefix+"/backgroup/background.jpg")));

    // 循环tab
    for (int i = 0; i < lstTab.count(); i++) {
        sTab stab = lstTab.at( i );

        // 添加tab
        RibbonPage* page = pApplication->ribbonBar()->addPage( m_mapMainTabTypeName.value((TABTYPE)stab.tab) );

        m_mapTabPage.insert((TABTYPE)stab.tab, page);

        // 记录管理扩展工具
        if ((TABTYPE)stab.tab == OTHERTAB)
            pExtendPage = page;

        // 循环group
        for (int j = 0; j < stab.lstGroup.count(); j++) {
            sGroup sgroup = stab.lstGroup.at(j);

            Qtitan::RibbonGroup* group = page->addGroup( m_mapMainGroupTypeName.value((GROUPTYPE)sgroup.group) );

            m_mapGroup.insert((GROUPTYPE)sgroup.group, group);

            // 扩展工具组时记录ribbon group
            if ((GROUPTYPE)sgroup.group == EXTENDGROUP)
                pExtendGroup = group;

            RibbonToolBarControl* toolBar = new RibbonToolBarControl(group);

            // 循环button
            for (int k = 0; k < sgroup.lstButton.count(); k++) {
                int nBtnType = sgroup.lstButton.at(k);

                // 如果没有预监回显模块，则过滤掉回显按钮148和预监工具条144
                if ( !BCCommon::g_bEchoModel ) {
                    if ((nBtnType == 148) || (nBtnType == 144))
                        continue;
                }

                // VP2000才对应有 窗口复制 修改IP 削影 功能
                if (0 != BCCommon::g_nDeviceType) {
                    if ((nBtnType == 173) || (nBtnType == 174) || (nBtnType == 175))
                        continue;
                }

                // 如果只有矩阵则不显示通讯开关按钮
                if (BCCommon::g_nIsContainsMatrix == 1) {
                    if (nBtnType == 111)
                        continue;
                }

                ButtonInfo btn = m_mapMainButtonTypeName.value( (BUTTONTYPE)nBtnType );

                // 根据当前房间显示图片
                QString qsDefaultIconPath = BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+btn.m_qsIconOffPath;
                if (nBtnType == 167) {  // 屏幕开关状态
                    if (NULL != pMRoom) {
                        qsDefaultIconPath = BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+(pMRoom->IsSwitchOn() ? btn.m_qsIconOnPath : btn.m_qsIconOffPath);
                    }
                }
                if (nBtnType == 102) {  // 场景轮巡状态
                    if (NULL != pMRoom) {
                        qsDefaultIconPath = BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+(pMRoom->IsLoopWindowScene() ? btn.m_qsIconOnPath : btn.m_qsIconOffPath);
                    }
                }

                QAction *pAction = new BCRibbonMainToolBarAction((BUTTONTYPE)nBtnType,
                                                                 btn,
                                                                 QIcon(qsDefaultIconPath),
                                                                 btn.m_qsText,
                                                                 this);
                toolBar->addAction(pAction, Qt::ToolButtonTextUnderIcon);

                // 将action添加到map中维护
                m_mapButtonAction.insert((BUTTONTYPE)nBtnType, pAction);
            }

            // 只能按钮添加之后再添加
            group->addControl(toolBar);
        }
    }
}

void BCRibbonMainToolBar::RefreshLanguage()
{
    RefreshMap();

    Build();
    return;

//    // 1.刷新tab
//    QList<TABTYPE> lstTabType = m_mapTabPage.keys();
//    QListIterator<TABTYPE> itTab( lstTabType );
//    while ( itTab.hasNext() ) {
//        TABTYPE type = itTab.next();

//        RibbonPage *pPage = m_mapTabPage.value( type );
//        pPage->setTitle( m_mapMainTabTypeName.value(type) );
//    }

//    // 2.刷新group
//    QList<GROUPTYPE> lstGroupType = m_mapGroup.keys();
//    QListIterator<GROUPTYPE> itGroup( lstGroupType );
//    while ( itGroup.hasNext() ) {
//        GROUPTYPE type = itGroup.next();

//        Qtitan::RibbonGroup *pGroup = m_mapGroup.value( type );
//        pGroup->setTitle( m_mapMainGroupTypeName.value(type) );
//    }

//    // 3.刷新button
//    QList<BUTTONTYPE> lstButtonType = m_mapButtonAction.keys();
//    QListIterator<BUTTONTYPE> itButton( lstButtonType );
//    while ( itButton.hasNext() ) {
//        BUTTONTYPE type = itButton.next();

//        QAction *pAction = m_mapButtonAction.value( type );
//        pAction->setText( m_mapMainButtonTypeName.value(type).m_qsText );
//    }
}

void BCRibbonMainToolBar::RefreshExtendGroup()
{
    if ((NULL == pExtendPage) || (NULL == pExtendGroup))
        return;

    // 将扩展工具管理按钮移除
    m_mapButtonAction.remove( EXTENDMANAGER );

    // remove group
    pExtendPage->removeGroup( pExtendGroup );

    // 添加group
    pExtendGroup = pExtendPage->addGroup( m_mapMainGroupTypeName.value( EXTENDGROUP ) );
    RibbonToolBarControl* toolBar = new RibbonToolBarControl( pExtendGroup );

    // 添加扩展工具管理按钮
    ButtonInfo btn = m_mapMainButtonTypeName.value(EXTENDMANAGER);
    QAction *pActionMgr = new BCRibbonMainToolBarAction(EXTENDMANAGER,
                                                     btn,
                                                     QIcon(BCCommon::g_qsImageFilePrefix+BCCommon::g_qsApplicationStyle+"/"+btn.m_qsIconOffPath),
                                                     btn.m_qsText,
                                                     this);
    toolBar->addAction(pActionMgr, Qt::ToolButtonTextUnderIcon);

    // 添加扩展工具管理按钮
    m_mapButtonAction.insert(EXTENDMANAGER, pActionMgr);

    // 添加扩展按钮
    for (int i = 0; i < m_lstExtendButtonPath.count(); i++) {
        QAction *pAction = new BCRibbonMainToolBarAction(m_lstExtendButtonPath.at(i), this);
        toolBar->addAction(pAction, Qt::ToolButtonTextUnderIcon);
    }

    pExtendGroup->addControl(toolBar);
}

BCRibbonMainToolBarAction *BCRibbonMainToolBar::GetButtonAction(BUTTONTYPE type)
{
    return dynamic_cast<BCRibbonMainToolBarAction *>( m_mapButtonAction.value( type ) );
}

void BCRibbonMainToolBar::RefreshIcon()
{
    QList<QAction *> lstButtons = m_mapButtonAction.values();
    QListIterator<QAction *> it( lstButtons );
    while ( it.hasNext() ) {
        BCRibbonMainToolBarAction *pBtn = dynamic_cast<BCRibbonMainToolBarAction *>( it.next() );
        if (NULL == pBtn)
            continue;

        pBtn->Refresh();
    }
}

QString BCRibbonMainToolBar::GetTabName(TABTYPE type)
{
    return m_mapMainTabTypeName.value( type );
}

QString BCRibbonMainToolBar::GetGroupName(GROUPTYPE type)
{
    return m_mapMainGroupTypeName.value( type );
}

QString BCRibbonMainToolBar::GetButtonName(BUTTONTYPE type)
{
    return m_mapMainButtonTypeName.value( type ).m_qsText;
}
