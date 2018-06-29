/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：主窗体类，添加各种toolbar，主操作界面
*********************************************************************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtitanRibbon.h>
#include <QSystemTrayIcon>
#include <QDomDocument>
#include <QMap>

// 用户
class sTab;
struct BCSUser
{
    int id;
    QString loginName;
    QString password;
    int level;  // 级别 0 1 2 3

    QList<sTab> lstTab;
};

// 屏组移动偏移量
struct BCSWinsizeOffset
{
    int gid;
    int l;
    int t;
};

class BCMMatrix;
class BCMatrixRoomWidget;
class BCSettingDebugDlg;
class sTaskPlanning;
class BCRoomWidget;
class sMatrix;
class QGraphicsView;
class BCCommon;
class BCToolBar;
class BCMRoom;
class BCMGroupDisplay;
class BCMDisplay;
class BCMInputDevice;
class BCMChannel;
class BCMGroupChannel;
class BCSUser;
class BCRibbonMainToolBar;
class BCSettingOutOfDateDlg;
class MainWindow : public Qtitan::RibbonMainWindow
{
    Q_OBJECT

public:
    // toolbar类型
    enum TOOLBARTYPE{
        MAINTOOLBAR,            // 主工具条
        SIGNALSOURCETOOLBAR,    // 信号源工具条
        REVIEWTOOLBAR,          // 预监工具条
        MATRIXTOOLBAR,          // 矩阵切换工具条
        EXTENDTOOLBAR           // 扩展工具条
    };

    // 根据数据初始化房间
    void InitRoom();
    void ClearRoom();

    // 房间VIEW
    void RefreshRoomName();

    // 房间MODEL
    BCMRoom *GetCurrentMRoom();
    const QList<BCMRoom *> &GetMRooms();
    BCMRoom *GetMRoom(int id);
    BCMRoom *GetMRoomByGroupDisplayID(int id);

    // 返回当前房间，如果联控时候矩阵和拼接有关联，当前显示为矩阵，但返回关联拼接的房间
    BCMRoom *GetCurrentSceneMRoom();

    // 物理输入通道
    void AddInputChannel(BCMChannel *pChannel);
    BCMChannel *GetInputChannel(int id, int type);

    // 返回物理通道链表
    const QList<BCMChannel *> &GetInputChannels();

    // 自定义输入通道
    void AddGroupInputChannel(BCMGroupChannel *pGroupChannel);
    void RemoveGroupInputChannel(BCMGroupChannel *pGroupChannel);
    BCMGroupChannel *GetGroupInputChannel(const QString &id);

    const QList<BCMGroupChannel *> &GetGroupInputChannels();
    void SetGroupInputChannels(QList<BCMGroupChannel *> lstGroupChannel);

    // 是否启用自定义输入通道
    void SetUseGroupInputChannels(bool b);
    bool IsUseGroupInputChannels();

    // 获得自定义输入通道ID
    int GetGroupChannelID();

    // 返回当前房间Widget
    BCRoomWidget *GetCurrentRoomWidget();

    // 初始化工具条
    void InitToolBars();
    // 添加ToolBar
    BCToolBar *AddToolBar(TOOLBARTYPE eToolBarType);
    BCToolBar *GetToolBar(const QString &qsToolBarName);
    BCToolBar *GetToolBar(TOOLBARTYPE eToolBarType);
    const QList<BCToolBar *> &GetToolBars();

    // 返回主工具条
    BCRibbonMainToolBar *GetRibbonMainToolBar();

    // 刷新翻译；针对本程序主名称、主工具条、数据源工具条、预监工具条、房间及开窗、托盘
    void RefreshLanguage();

    // 获得输入工具条当前输入通道
    BCMChannel *GetCurrentInputChannel();

    // Show，内部区分标准、最大化、全屏显示
    void Show();

    // ***************************************************************************************************** 本地数据接口
    // 从xml加载数据，加载之后可对应调用相关接口
    void LoadGenaralConfig();
    void LoadInputChannelConfig();
    void ClearSystemData();

    void LoadDataFromLocalServer();     // 从本地服务器请求数据

    // ***************************************************************************************************** 服务器通讯接口
    void LoadDataFromServer(int dataType = 0);                  // 根据用户请求服务器上的数据
    void DealMainToolBarDataFromServer(const QString &json);    // 处理服务器返回的主工具条权限json
    void DealRoomDataFromServer(const QString &json);           // 处理服务器返回的房间json
    void DealInputChannelDataFromServer(const QString &json);   // 处理服务器返回的输入通道json
    void DealServerResult(bool b);                              // 根据以上数据处理情况关闭或者是显示主窗口
    // *****************************************************************************************************

    // 当前登录用户
    BCSUser *GetCurrentUser();
    void SetCurrentUser(BCSUser *pUser);

    // 信号源类型
    enum SIGNALSOURCETYPE {
        INPUTCHANNELSSIGSRC,        // 控制器输入，输入通道物理链表
        CUSTINPUTCHANNELSSIGSRC,    // 信号源链表，自定义输入通道链表
        VIDEOCONTROLSIGSRC,         // 录像播放控制
        SYSPLANSIGSRC,              // 系统预案
        DECODERSIGSRC,              // 解码器输入
        CATCHNETDISPLAYSIGSRC,      // 网络抓屏输入
        MATRIXPANELSIGSRC,          // 矩阵面板
        MATRIXINPUTSIGSRC,          // 矩阵输入
        MATRIXSWAPSIGSRC,           // 矩阵切换
        WINDOWSCENESIGSRC,          // 场景链表
    };

    // 返回信号源图标的路径
    QString GetSignalSourceIcon(SIGNALSOURCETYPE type);

    // 返回信号源名称
    QString GetSignalSourceName(SIGNALSOURCETYPE type);

    // 返回输入通道数据源类型图标的路径
    QString GetInputChannelIcon(int nSignalSourceOfInputChannel);

    // 重新加载数据并刷新界面
    void RefreshMainWindow();

    // 刷新状态信息
    void RefreshStatusBar();

    // 所有信号窗的回显状态
    bool IsOpenAllSignalEcho();

    // 预布局开关
    bool IsFloorPlanningSwitch();

    // 服务器通知预布局打开
    void ServerFloorPlanningSwitchOn(int nRoomID, int nGroupSceneID);

    // 刷新任务计划
    void RefreshTaskPlanning();

    // 添加调试指令
    void AddDebugCmd(const QString &cmd);

    // 设置预监回显指令
    void SetPreviewDeviceSwitch(bool bOpen);

    // 矩阵相关
    void RefreshMatrixData();
    BCMatrixRoomWidget *GetCurrentMatrixWidget();
    BCMatrixRoomWidget *GetMatrixWidgetByID(int id);

    // 矩阵
    BCMatrixRoomWidget *GetCurrentMatrixSceneWidget();

    const QList<BCMMatrix *> &GetMMatrix();
    BCMMatrix *GetMMatrix(int id);

    // 根据房间ID返回对应矩阵ID，如果没有返回-1
    QList<int> GetRelationMatrixID(int roomid);

    QSize GetWinsizeOffset(int gid);

    // 场景设置相关
    bool IsWindowSceneSetSwitch();
    void SetWindowSceneSetSwitch(bool b);

public slots:
    void onHide();
    void onTrayIconQuit();
    void onCurrentRoomChanged(int);
    void onSwitchUser(bool);                        // 切换用户
    void onSetAllSignalEchoVisibel();               // 全部信号窗回显
    void onSetAllSignalEchoVisibelByTimer();        // 全部信号回显添加定时器
    void onClearCurrentGroupDisplaySignalWindow();  // 清空当前屏幕的信号窗
    void onSetFloorPlanningSwitch();                // 设置预布局开关
    void onSetFloorPlanningSync();                  // 同步预布局
    void onDebugDlgVisble();                        // 调用调试对话框
    void onRefreshConnect();                        // 刷新连接状态

protected:
    void closeEvent(QCloseEvent *event);
    bool eventFilter(QObject *obj, QEvent *e);

private slots:
    // 托盘的点击事件
    void onTrayIconActivated(QSystemTrayIcon::ActivationReason reason);
    void onTrayIconSet();
    void onTrayIconAbout();
    void onTrayIconCheckUpdate();
    void onTrayIconLogOff();

    void maximizeToggle();
    void minimizationChanged(bool minimized);
    void optionsTheme(QAction*);
    void setTitleGroupsVisible(bool);

    void onTimeOutOfOutOfDate();     // 设备过期的槽函数

private:
    // 初始化托盘
    void InitTrayIcon();
    // 初始化信号源相关的map
    void InitSignalSourceMap();
    // 返回屏组数据类
    BCMGroupDisplay *GetGroupDisplay(int id);
    // 返回单屏数据类
    BCMDisplay *GetDisplay(int groupDisplayID, int displayID);
    // 自定义主工具条右侧隐藏和选项按钮
    void createOptions();
    // 通讯接口
    void stop();
    // IPV窗口特殊处理，程序关闭时保存IPV窗口，启动时加载分割数等信息
    void SaveIPVWindow();
    void LoadIPVWindow();
    // 偏移量读取
    void LoadWinsizeOffsetConfig();

private:
    // 只能通过BCCommon初始化
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTabWidget              *m_pTabWidgetRooms;         // 房间
    QList<BCToolBar *>      m_lstToolBars;              // toolbar 链表

    int                     m_nQuitFlag;                // 系统退出标识
    QSystemTrayIcon         *m_pTrayIcon;               // 托盘
    QLabel                  *m_pStatusLabel;            // 右下角状态标签

    bool                    m_bOpenAllSignalEcho;       // 是否打开全部信号窗的回显
    bool                    m_bWindowSceneSetSwitch;    // 是否设置场景

    BCSUser                 *m_pSystemUser;             // 记录当前系统用户
    QList<BCMRoom *>        m_lstRooms;                 // 房间
    QList<BCMChannel *>     m_lstInputChannels;         // 输入通道链表
    QList<BCMGroupChannel *>m_lstGroupInputChannels;    // 输入通道组链表
    bool                    m_bUseGroupInputChannels;   // 是否启用通道组
    QList<BCMMatrix *>      m_lstMatrix;                // 矩阵链表

    Qtitan::RibbonStyle     *m_ribbonStyle;             // ribbon风格类
    BCRibbonMainToolBar     *m_pMainToolBar;            // 自定义主工具条，内部对tab group button进行管理
    QAction                 *m_actionRibbonMinimize;    // 主工具条最小化按钮
    QMenu                   *m_menuOptions;
    QActionGroup            *m_styleActions;
    QList<QAction *>        m_lstRibbonAction;
    QList<BCSWinsizeOffset> m_lstWinsizeOffset;         // 记录winsize偏移量，加载一次

    QMap<SIGNALSOURCETYPE, QString> m_mapSignalSourceIconPath;      // 信号源对应的图片
    QMap<SIGNALSOURCETYPE, QString> m_mapSignalSourceName;          // 信号源对应的名称
    QMap<int, QString>              m_mapInputChannelIconPath;      // 输入通道对应的图片

    QTime                   m_timeOfPreview;            // 预监回显的time，10ms外如果有gwinsize指令则执行一次
    QTimer                  *m_pOutOfDateTimer;         // 设备过期检查的timer
    BCSettingOutOfDateDlg   *m_pOutOfDateDlg;           // 设备过期的提示对话框，因为要保证唯一性，所以用成员变量记录
    QList<sTaskPlanning>    m_lstTaskPlanning;          // 任务计划链表

    BCSettingDebugDlg       *m_pDebugDlg;

    friend class BCCommon;
};

inline bool MainWindow::IsWindowSceneSetSwitch()
{
    return m_bWindowSceneSetSwitch;
}

inline void MainWindow::SetWindowSceneSetSwitch(bool b)
{
    m_bWindowSceneSetSwitch = b;
}

inline const QList<BCMMatrix *> &MainWindow::GetMMatrix()
{
    return m_lstMatrix;
}

inline const QList<BCMRoom *> &MainWindow::GetMRooms()
{
    return m_lstRooms;
}

inline const QList<BCToolBar *> &MainWindow::GetToolBars()
{
    return m_lstToolBars;
}

inline const QList<BCMChannel *> &MainWindow::GetInputChannels()
{
    return m_lstInputChannels;
}

inline const QList<BCMGroupChannel *> &MainWindow::GetGroupInputChannels()
{
    return m_lstGroupInputChannels;
}

inline BCSUser *MainWindow::GetCurrentUser()
{
    return m_pSystemUser;
}

inline void MainWindow::SetCurrentUser(BCSUser *pUser)
{
    m_pSystemUser = pUser;
}

inline BCRibbonMainToolBar *MainWindow::GetRibbonMainToolBar()
{
    return m_pMainToolBar;
}

inline QString MainWindow::GetSignalSourceIcon(SIGNALSOURCETYPE type)
{
    return m_mapSignalSourceIconPath.value( type );
}

inline QString MainWindow::GetSignalSourceName(SIGNALSOURCETYPE type)
{
    return m_mapSignalSourceName.value( type );
}

inline QString MainWindow::GetInputChannelIcon(int nSignalSourceOfInputChannel)
{
    return m_mapInputChannelIconPath.value( nSignalSourceOfInputChannel );
}

inline void MainWindow::SetUseGroupInputChannels(bool b)
{
    m_bUseGroupInputChannels = b;
}

inline bool MainWindow::IsUseGroupInputChannels()
{
    return m_bUseGroupInputChannels;
}

inline bool MainWindow::IsOpenAllSignalEcho()
{
    return m_bOpenAllSignalEcho;
}

#endif // MAINWINDOW_H
