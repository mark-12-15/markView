#ifndef BCROOMWIDGET_H
#define BCROOMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QSlider>

class BCMRoom;
class BCMChannel;
class BCWindowSceneData;
class QVBoxLayout;
class BCRoomWidget;
class BCGroupDisplayWidget;
class BCSignalWindowDisplayWidget;
class BCSingleDisplayVirtualWidget;
class BCRoomMainWidget : public QWidget
{
    Q_OBJECT
public:
    BCRoomMainWidget(BCMRoom *pMRoom, BCRoomWidget *parent = 0);
    ~BCRoomMainWidget();

    // 返回房间数据类
    BCMRoom *GetMRoom();

    // 返回屏组数据类
    const QList<BCGroupDisplayWidget *> &GetGroupDisplayWidget();

    // 返回单屏虚拟矩形数据类
    QList<BCSingleDisplayVirtualWidget *> GetSingleDisplayVirtualWidget();

    // 添加信号窗，尺寸是实际尺寸
    BCSignalWindowDisplayWidget *AddSignalWindow(int x, int y, int w, int h, BCGroupDisplayWidget *pGroupDisplayWidget, BCMChannel *pChannel, int winid=-1, bool bSendCmd=true);

    // 服务器同步开窗
    BCSignalWindowDisplayWidget *ServerWinsize(BCGroupDisplayWidget *pGroupDisplayWidget, BCMChannel *pChannel, int winid, int x, int y, int w, int h);

    // 根据实际尺寸转换成虚拟尺寸
    QRect MapToVirtualRect(int x, int y, int w, int h);

    // 根据虚拟尺寸转换成实际尺寸
    QRect MapToFactRect(int x, int y, int w, int h);

    // 根据虚拟尺寸转换成实际尺寸
    QPoint MapToFactPoint(int x, int y);

    // 服务器对关窗请求的回复
    void ServerWinSwitchResult(bool b, BCSignalWindowDisplayWidget *pItem);

    // 服务器对清屏请求的回复
    void ServerResetResult(bool b);

    // 返回信号窗链表
    const QList<BCSignalWindowDisplayWidget *> &GetSignalWindows();

    // 设置所有信号窗的回显状态
    void SetAllSignalEchoVisibel(bool b);

    // 刷新回显状态
    void RefreshEchoStatus(bool bTempCloseEcho);

    // 返回当前信号窗
    BCSignalWindowDisplayWidget *GetCurrentSignalWindow();

    // ??? 通过winid取信号窗，如果是VP2000的需要添加chid和chtype字段
    BCSignalWindowDisplayWidget *GetSignalWindowByWindowID(int winid);

    // 刷新分割数
    void RefreshSegmentation(int n);
    int GetSegmentation();

    // 返回房间排列数
    QSize GetRoomArray();

    // 刷新信号窗文字
    void RefreshSignalWindowTextDisplay();
    // 返回窗口叠放序号
    int GetSignalWindowIndex(BCSignalWindowDisplayWidget *pItem);
    // 将窗口置顶
    bool SetSignalWindowTop(BCSignalWindowDisplayWidget *pItem);
    // 将窗口置底
    bool SetSignalWindowBottom(BCSignalWindowDisplayWidget *pItem);
    // 将窗口上移
    bool SetSignalWindowMoveToTop(BCSignalWindowDisplayWidget *pItem);
    // 将窗口下移
    bool SetSignalWindowMoveToBottom(BCSignalWindowDisplayWidget *pItem);
    // 删除单个信号窗
    bool RemoveSignalWindowDisplayItem(BCSignalWindowDisplayWidget *pItem, bool bSendCmd = true);
    // 清空信号窗
    void ClearSignalWindow(const QString &qsGroupDisplayIDs, bool bSendCmd = true);

    // 生成winID，原则是根据ChannelType分组，从0开始，中间有空缺补充空缺，如已经有0，1，3则新开窗winID为2
    int CreateWindowID(BCMChannel *pChannel);

    // 返回当前屏组
    BCGroupDisplayWidget *GetCurrentGroupDisplay();

    // 设置预布局
    void SetFloorPlanning(bool b);
    bool IsFloorPlanningSwitch();
    // 同步预布局
    void SetFloorPlanningSync();

protected:
    void resizeEvent(QResizeEvent *e);

    // 鼠标事件新建矩形
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    // 拖拽事件
    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent *e);

private:
    // 获得当前选中屏组
    BCGroupDisplayWidget *GetCurrentSceneManager(QPoint pt);
    // 获得当前位置的信号窗
    BCSignalWindowDisplayWidget *GetSignalWindowDisplayItem(QPoint pt);
    // 刷新信号窗的Z Value
    void RefreshSignalWindowZValue();
    // 刷新定位对话框
    void RefreshLocalDlg();
    // 拖拽开窗接口，如果连接服务器需要请求
    BCSignalWindowDisplayWidget *OpenSignalWindow(BCGroupDisplayWidget *pSceneGroup, BCMChannel *pChannel);
    // 是否属于级联通道
    bool IsJointMatrixChannel(int chid);
private:
    // 基础数据
    BCMRoom                                 *m_pMRoom;              // 数据类

    QList<BCGroupDisplayWidget *>           m_lstGroupDisplayWidget;// 屏组显示类
    QList<BCSignalWindowDisplayWidget *>    m_lstSignalWindow;      // 信号窗链表

    // 鼠标事件相关
    bool                        m_bPress;                   // 鼠标左键临时变量
    int                         m_x;
    int                         m_y;
    QWidget                     *m_pVirtualRectItem;        // 鼠标移动的虚拟窗，松开时判断是否要开窗
    BCMChannel                  *m_pInputChannel;           // 当前通道
    BCGroupDisplayWidget        *m_pCurrentSceneGroup;      // 当前开窗的屏组，鼠标点击赋值
    BCSignalWindowDisplayWidget *m_pCurrentSignalWindow;    // 当前信号窗

    bool                        m_bFloorPlanning;                   // 是否预布局
    QList<BCWindowSceneData *>  m_lstSignalWindowOfFloorPlanning;   // 预布局前的信号窗
};

inline BCMRoom *BCRoomMainWidget::GetMRoom()
{
    return m_pMRoom;
}

inline const QList<BCGroupDisplayWidget *> &BCRoomMainWidget::GetGroupDisplayWidget()
{
    return m_lstGroupDisplayWidget;
}

inline const QList<BCSignalWindowDisplayWidget *> &BCRoomMainWidget::GetSignalWindows()
{
    return m_lstSignalWindow;
}

inline bool BCRoomMainWidget::IsFloorPlanningSwitch()
{
    return m_bFloorPlanning;
}

// ---------------------------------------------------------------------------------------------

class BCRoomWidget : public QWidget
{
    Q_OBJECT
public:
    BCRoomWidget(BCMRoom *pMRoom, QWidget *parent = 0);
    ~BCRoomWidget();

    BCRoomMainWidget *GetRoomMainWidget();

    // 如果刷新分割数需要重新设置房间尺寸，因为size都是int值，可能会造成计算误差
    void RefreshSegmentation();

    // 清空当前房间的信号窗
    void ClearSignalWindow();

    // 设置预布局
    void SetFloorPlanning(bool b);
    bool IsFloorPlanningSwitch();
    // 同步预布局
    void SetFloorPlanningSync();

    // ??? 缩放功能

private slots:
    void onChangeViewScale(int v);
    void onReduceSliderValue();
    void onLargenSliderValue();

protected:
    void resizeEvent(QResizeEvent *e);

    void initWallView(BCMRoom *pMRoom, QVBoxLayout *pMainLayout);
    void initStatusWidget();

private:
    BCRoomMainWidget    *m_pMainWidget;     // 绘图区域，因为可能会按比例显示
    QLabel              *m_pTopLabel;       // 用来调整显示位置
    QLabel              *m_pLeftLabel;
    QLabel              *m_pBottomLabel;
    QLabel              *m_pRightLabel;

    QWidget             *m_pWidgetStatus;   // 屏幕墙自定义状态栏
    QSlider             *m_pSlider;         // 缩放显示区域控件
};

inline BCRoomMainWidget *BCRoomWidget::GetRoomMainWidget()
{
    return m_pMainWidget;
}

#endif // BCROOMWIDGET_H
