/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：ribbon风格的主工具条
*********************************************************************************************************************************/
#ifndef BCRIBBONMAINTOOLBAR_H
#define BCRIBBONMAINTOOLBAR_H

#include <QObject>
#include <QMap>

#include <QtitanRibbon.h>

class QAction;
class BCRibbonMainToolBarAction;
class BCRibbonMainToolBar : public QObject
{
    Q_OBJECT
public:
    // 主工具条中tab
    enum TABTYPE {
        MAIN,       // 主功能区
        SET,        // 设置
        OTHERTAB,   // 其他

        // 3-5
        GENERIC,        // 常用功能 2017-03-20 融倍祺
        DEVICECONFIG,   // 设备配置
        SYSMANAGER      // 系统管理
    };
    // 主工具条中group
    enum GROUPTYPE {
        WINDOWMANAGER,      // 窗口管理
        SCENEMANAGER,       // 场景管理
        DEVICE,             // 设备
        SYSTEM,             // 系统
        EXTENDGROUP,        // 扩展工具
        OTHERGROUP,         // 其他
        TOOLBAR,            // 工具栏

        // 7-9 融倍祺
        CONNECTCONFIG,      // 窗口管理
        VIEWCONFIG,         // 显示配置
        FUNCAIONCONFIG,     // 功能配置

        // 10
        FLOORPLANNING       // 预布局
    };
    // 主工具条中的button
    enum BUTTONTYPE {
        // 常规模式
        // 主功能
        LOCATION = 100,         // 窗口定位
        CLEARDISPLAY,           // 清空屏幕
        WINDOWSCENELOOP,        // 场景轮训开关
        WINDOWSCENEADD,         // 添加场景
        WINDOWSCENEDELETE,      // 删除场景
        WINDOWSCENEUPDATE,      // 更新场景
        WINDOWSCENESET,         // 场景设置
        ABOUT,                  // 关于
        RUNINBACKGROUND,        // 后台运行
        LOGOFF,                 // 注销，切换用户
        QUIT,                   // 退出系统

        // 111
        COMMUNICATION,          // 通讯开关
        DEVICESEARCH,           // 检测设备（通讯）
        DEVICEPARAMETER,        // 硬件参数（拼接）
        MATRIXSET,              // 矩阵
        DEVICEDISPLAYINFO,      // 屏幕信息
        DEVICEDISPLAYSET,       // 屏幕设置
        MONITORSET,             // 监视器
        INPUTSET,               // 输入
        SIGNALSOURCESET,        // 信号源
        BOARDBITMAP,            // 板位图
        DEVICETEST,             // 设备测试
        EDIDINPUT,              // EDIT输入
        EDITOUTPUT,             // EDIT输出

        // 124
        SKINSET,                // 皮肤设置
        LOGINSET,               // 登录界面设置
        STARTUPSET,             // 软件初始化显示设置
        CLICKCLOSESET,          // 关闭主面板时是否退出程序
        LANGUAGE,               // 语言选择
        PURVIEW,                // 人员权限
        MODIFYPASSWORD,         // 修改密码

        // 131
        DEVICETIMING,           // 定时任务
        WARNINGMANAGER,         // 报警管理
        WARNINGLOG,             // 报警日志
        OPERATIONLOG,           // 操作日志
        CONFIGFILE,             // 配置文件
        SYSTEMBACKUP,           // 系统备份
        SYSTEMRESTORE,          // 系统还原
        CHECKUPDATE,            // 检查更新
        LISENCE,                // 软件认证

        // 140
        EXTENDMANAGER,          // 外部工具管理
        EXTEND,                 // 外部程序

        // 142
        MAINTOOLBAR,            // 主工具显示控制
        SIGNALSOURCETOOLBAR,    // 信号源工具条
        REVIEWTOOLBAR,          // 预监工具条
        EXTENDTOOLBAR,          // 扩展工具条

        // 146
        PLANMAP,                // 预案地图

        // 147
        OTHERDEVICE,            // 外部设备

        // 148
        OPENALLECHO,            // 打开所有回显

        // 149
        SYNCCHRONIZATION,       // 打开同步按钮

        // 150
        SINGLESYNCCHRONIZATION, // 打开单次同步按钮

        // 151
        GROUPSCENE,             // 是否启用场景组

        // 152
        BATCHSUBTITLES,         // 批量设置字幕

        // 153
        DEVICEFORMAT,           // 设备规模

        // 154
        OUTSIDECOMMAND,         // 外部命令，增值服务

        // 155-166 是对融倍祺界面的专用按钮
        CONNECTWITHSERIALPORT,  // 串口连接
        CONNECTWITHNET,         // 网络连接
        CONNECTSET,             // 设置(连接配置)

        VIEWCONFIG1,            // 参数配置(显示配置)
        MATRIXSET1,             // 外设矩阵1
        MATRIXSET2,             // 外设矩阵2
        DEVICEDISPLAYINFO1,     // 大屏

        DEVICETEST1,            // 颜色调试
        DISPLAYCOORDINATE,      // 屏幕坐标设置
        OPENALLECHO1,           // 预监设置
        OPENALLECHO2,           // 回显设置
        TASKSET,                // 任务设置

        // 167
        DISPLAYSWITCH,          // 屏幕开关
        // 168
        DISPLAYSWITCHCONFIG,    // 屏幕开关设置

        // 169
        FLOORPLANNINGSWITCH,    // 预布局开关
        // 170
        FLOORPLANNINGSYNC,      // 预布局同步

        // 171
        AUTOREADINPUTCONFIG,    // 自动获取

        // 172
        DEBUGDLG,               // 调试窗口

        // 173
        WINDOWCOPYCONFIG,       // 信号窗复制数量，目前只针对VP2000设备

        // 174
        MODIFYDEVICEIP,         // 修改设备IP，目前只针对VP2000设备

        // 175
        REMOVESHADOW,           // 削影，目前只针对VP2000设备

        // 176
        MATRIXFORMAT,           // 矩阵规模

        // 177
        OUTSIZEINTERFACE        // 外部接口
    };

    // 记录按钮信息，使用类是因为重写构造函数，能在创建时传入多个值
    class ButtonInfo {
    public:
        ButtonInfo(const QString &text = QString::null,
                   const QString &toolTip = QString::null,
                   const QString &iconoff = QString::null,
                   const QString &iconon = QString::null) {
            m_qsText = text;
            m_qsTooltip = toolTip;
            m_qsIconOffPath = iconoff;
            m_qsIconOnPath = iconon;
        }

        QString m_qsIconOffPath;    // 按钮icon off
        QString m_qsIconOnPath;     // 按钮icon on
        QString m_qsText;
        QString m_qsTooltip;
    };

    BCRibbonMainToolBar();
    ~BCRibbonMainToolBar();

    void Build();   // 构造主工具条

    // 刷新翻译
    void RefreshLanguage();

    // 刷新map
    void RefreshMap();

    BCRibbonMainToolBarAction *GetButtonAction(BUTTONTYPE type);    // 根据类型返回按钮action

    const QStringList &GetExtendButtonPath();
    void SetExtendButtonPath(const QStringList &lst);

    void RefreshIcon();         // 刷新内部所有按钮的icon
    void RefreshExtendGroup();

    // 根据类型找名字
    QString GetTabName(TABTYPE type);
    QString GetGroupName(GROUPTYPE type);
    QString GetButtonName(BUTTONTYPE type);

private:
    RibbonPage          *pExtendPage;
    Qtitan::RibbonGroup *pExtendGroup;

    QStringList         m_lstExtendButtonPath;                  // 外部工具按钮使用，存外部工具的全路径

    QMap<TABTYPE, RibbonPage*>              m_mapTabPage;       // 定义了tab类型和对应的page
    QMap<GROUPTYPE, Qtitan::RibbonGroup*>   m_mapGroup;         // 定义了group类型和对应的ribbonGroup
    QMap<BUTTONTYPE, QAction*>              m_mapButtonAction;  // 定义了按钮类型和对应的action

    QMap<TABTYPE, QString>          m_mapMainTabTypeName;       // 定义类型和名字对应关系，供翻译使用
    QMap<GROUPTYPE, QString>        m_mapMainGroupTypeName;     // 定义类型和名字对应关系，供翻译使用
    QMap<BUTTONTYPE, ButtonInfo>    m_mapMainButtonTypeName;    // 定义类型和名字对应关系，供翻译使用
};

inline const QStringList &BCRibbonMainToolBar::GetExtendButtonPath()
{
    return m_lstExtendButtonPath;
}

inline void BCRibbonMainToolBar::SetExtendButtonPath(const QStringList &lst)
{
    m_lstExtendButtonPath = lst;
}

#endif // BCRIBBONMAINTOOLBAR_H
