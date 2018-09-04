/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：房间类
*********************************************************************************************************************************/
#ifndef BCMROOM_H
#define BCMROOM_H

#include <QString>
#include <QList>
#include <QSize>
#include <QSerialPort>
#include <QTimer>
#include <QMutex>

class BCRoomMainWidget;
class QTcpSocket;
class BCMGroupScene;
class BCMWindowScene;
class BCMGroupDisplay;
class BCMRoom : public QObject
{
    Q_OBJECT

public:
    BCMRoom(int id);
    ~BCMRoom();

    void AddGroupDisplay(BCMGroupDisplay *pGroupDisplay);
    const QList<BCMGroupDisplay *> &GetGroupDisplay();
    BCMGroupDisplay *GetGroupDisplay(int id);

    void RemoveGroupDisplay(BCMGroupDisplay *pGroupDisplay);
    void ClearGroupDisplay();

    void SetRoomID(int qs);
    int GetRoomID();

    void SetRoomName(const QString &qs, bool bSendCmd = false);
    const QString &GetRoomName();

    void SetWallSize(double w, double h);
    QSizeF GetWallSize(bool bVir = true);

    void SetIsUseVirSize(int n);
    int IsUseVirSize();

    void SetWallVirSize(int w, int h);
    QSize GetWallVirSize();

    BCMWindowScene *GetDefaultWindowScene();

    void AddGroupScene(BCMGroupScene *pGroupScene);
    const QList<BCMGroupScene *> &GetGroupScenes();
    BCMGroupScene *GetGroupScene(int id);

    void RemoveLastGroupScene();
    void RemoveGroupScene(const QString &id);
    void RemoveGroupScene(BCMGroupScene *pGroupScene);
    void ClearGroupScene();

    // 一个房间内的场景ID不能重复，该函数返回待添加的场景ID
    int GetWindowSceneID();

    bool IsExistWindowScene(int id);

    void SetSignalWidgetManager(BCRoomMainWidget *pMgr);
    BCRoomMainWidget *GetSignalWidgetManager();

    void SetType(int type);
    int GetType();

    // 屏幕开关
    void SetSwitchConfig(int isNet, const QString &ip, int port, const QString &com, int baudrate, int databit, int stopbit, const QString &checkBit, const QString &streamctrl,
                         int type, const QString &cmdon, const QString &cmdoff, bool bSendCmd = false);
    int GetSwitchIsNetConnect();
    const QString &GetSwitchIP();
    int GetSwitchPort();
    const QString &GetSwitchCom();
    int GetSwitchBaudRate();
    int GetSwitchDataBit();
    int GetSwitchStopBit();
    const QString &GetSwitchCheckBit();
    const QString &GetSwitchStreamCtrl();
    int GetSwitchType();
    const QString &GetSwitchOnCmd();
    const QString &GetSwitchOffCmd();

    bool IsSwitchOn();
    void SetSwitchOn(bool b, bool bSendCmd = true);
    void SendCmd(const QString &cmd);

    // 轮巡
    void SetLoopWindowScene(bool b);
    bool IsLoopWindowScene();

    QMutex  m_mutex;                    // 轮巡的线程锁

private slots:
    void onLoopWindowScene();

protected:
    int m_id;
    QString m_name;
    int m_type;     // 0:LCD,1:LED,2:融合,3:4K,4:Matrix

    double m_dWidth;
    double m_dHeight;

    int m_nIsUseVirResotluion;  // 是否使用虚拟分辨率
    QSize m_nVirSize;           // 虚拟分辨率

    QList<BCMGroupDisplay *>    m_lstGroupDisplay;  // 屏组链表

    BCMWindowScene              *m_pDefaultScene;   // 默认场景
    QList<BCMGroupScene *>      m_lstGroupScene;    // 场景组链表

    BCRoomMainWidget            *m_pSignalWidgetMgr;// ui的信号窗管理类

    int isConnectByNet;             // 是否网络通信
    QString switchip;
    int switchport;
    QString qsCurrentCom;           // 串口号
    int nCurrentBaudRate;           // 波特率
    int nCurrentDataBit;            // 数据位
    int nCurrentStopBit;            // 停止位
    QString qsCurrentCheckBit;      // 校验位
    QString qsCurrentStreamCtrl;    // 控制流
    int switchtype; // 0:16 1:text
    QString switchoncmd;
    QString switchoffcmd;

    bool m_bSwitchOn;   // 是否打开了开关
    QTcpSocket  *m_pSwitchSocket;
    QSerialPort m_serial;                   // 串口通讯

    // 场景轮巡
    bool    m_bLoopWindowScene;         // 是否轮训信号窗场景
    QTimer  *m_pWindowSceneTimer;       // 循环信号窗定时器
    int     m_nLoopWindowSceneIndex;    // 循环信号窗索引
    int     m_nWindowSceneTimeIndex;    // 非常规轮巡模式时场景内时间索引
};

inline bool BCMRoom::IsLoopWindowScene()
{
    return m_bLoopWindowScene;
}

inline bool BCMRoom::IsSwitchOn()
{
    return m_bSwitchOn;
}

inline int BCMRoom::GetSwitchIsNetConnect()
{
    return isConnectByNet;
}

inline const QString &BCMRoom::GetSwitchIP()
{
    return switchip;
}

inline int BCMRoom::GetSwitchPort()
{
    return switchport;
}

inline const QString &BCMRoom::GetSwitchCom()
{
    return qsCurrentCom;
}

inline int BCMRoom::GetSwitchBaudRate()
{
    return nCurrentBaudRate;
}

inline int BCMRoom::GetSwitchDataBit()
{
    return nCurrentDataBit;
}

inline int BCMRoom::GetSwitchStopBit()
{
    return nCurrentStopBit;
}

inline const QString &BCMRoom::GetSwitchCheckBit()
{
    return qsCurrentCheckBit;
}

inline const QString &BCMRoom::GetSwitchStreamCtrl()
{
    return qsCurrentStreamCtrl;
}

inline int BCMRoom::GetSwitchType()
{
    return switchtype;
}

inline const QString &BCMRoom::GetSwitchOnCmd()
{
    return switchoncmd;
}

inline const QString &BCMRoom::GetSwitchOffCmd()
{
    return switchoffcmd;
}

inline void BCMRoom::SetType(int type)
{
    m_type = type;
}

inline int BCMRoom::GetType()
{
    return m_type;
}

inline void BCMRoom::SetSignalWidgetManager(BCRoomMainWidget *pMgr)
{
    m_pSignalWidgetMgr = pMgr;
}

inline BCRoomMainWidget *BCMRoom::GetSignalWidgetManager()
{
    return m_pSignalWidgetMgr;
}

inline const QList<BCMGroupDisplay *> &BCMRoom::GetGroupDisplay()
{
    return m_lstGroupDisplay;
}

inline void BCMRoom::SetRoomID(int qs)
{
    m_id = qs;
}

inline int BCMRoom::GetRoomID()
{
    return m_id;
}

inline const QString &BCMRoom::GetRoomName()
{
    return m_name;
}

inline void BCMRoom::SetWallSize(double w, double h)
{
    m_dWidth = w;
    m_dHeight = h;
}

inline QSizeF BCMRoom::GetWallSize(bool bVir)
{
    if ( bVir )
        return (1 == m_nIsUseVirResotluion) ? QSizeF(m_nVirSize.width(), m_nVirSize.height()) : QSizeF(m_dWidth, m_dHeight);
    else
        return QSizeF(m_dWidth, m_dHeight);
}

inline BCMWindowScene *BCMRoom::GetDefaultWindowScene()
{
    return m_pDefaultScene;
}

inline const QList<BCMGroupScene *> &BCMRoom::GetGroupScenes()
{
    return m_lstGroupScene;
}

inline void BCMRoom::SetIsUseVirSize(int n)
{
    m_nIsUseVirResotluion = n;
}

inline int BCMRoom::IsUseVirSize()
{
    return m_nIsUseVirResotluion;
}

inline void BCMRoom::SetWallVirSize(int w, int h)
{
    m_nVirSize = QSize(w, h);
}

inline QSize BCMRoom::GetWallVirSize()
{
    return m_nVirSize;
}

#endif // BCMROOM_H
