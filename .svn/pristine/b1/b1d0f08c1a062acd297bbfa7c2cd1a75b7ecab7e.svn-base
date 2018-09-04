/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：物理输入通道链表，分文字和视频两种显示模式
*********************************************************************************************************************************/
#ifndef BCCONTROL_H
#define BCCONTROL_H

#include <QWidget>
#include <QTime>
#include <QTcpSocket>

namespace Ui {
class BCControl;
}

class BCMChannel;
class BCWidgetBtn;
class BCControl : public QWidget
{
    Q_OBJECT

public:
    explicit BCControl(bool bVisible, int minHeight, QWidget *parent = 0);
    ~BCControl();

    // 刷新内部结构
    void Refresh();

    // 刷新tooltip
    void RefreshToopTip();

    // 刷新入口信号源名称
    void RefreshInputChannelName();

    // 记录是否显示视频
    bool IsShowVedio();

    // 是否隐藏内容
    bool IsVisible();

    // 高亮输入通道
    void HighLightInputChannel(BCMChannel *pChannel);

    int m_minHeight;

    void SetTabVisibleFalse(int type);

    BCMChannel *GetCurrentChannel();

private slots:
    void onSetVisible(bool);

    void on_m_pShowVedioCheckBox_clicked(bool checked);
    void on_m_pShowModeComboBox_currentIndexChanged(int index);

    void onActionTriggered(int value);
    void onRangeChanged(int min, int max);

    void onRefreshVedioStatus();

    // 读取状态信息
    void onTimeOut();
    void onReadConfigTimeOut();
    void onRecvTcpMessage();

private:
    void init(bool bVisible);

    bool event(QEvent *event);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

    bool m_bModifyHeight;       // 是否修改高度，悬停到最下面时值为true
    bool m_bPress;

    // 读取状态信息
    void new_push_rd_stat_for_sys(unsigned char cmdtype,unsigned short ipid);
    bool new_filter_rd_stat_buffer(unsigned char ptr[],unsigned int len);
    unsigned short NewCrcDat(unsigned short g_BlendingCodeA,unsigned short g_BlendingMaxNumber,unsigned short g_BLENDING_BUFFER[]);
    unsigned int make_status_data_addr(unsigned short tmp_g_code_id);

private:
    Ui::BCControl *ui;

    BCWidgetBtn *m_pHeaderBtn;  // 自定义Header
    bool        m_bShowVedio;   // 是否显示预监

    QTime       beginTime;          // 记录滚动轴时间
    int         m_nScrollMinValue;  // 记录滚动轴的最大最小值
    int         m_nScrollMaxValue;

    bool        m_bTempCloseEcho;   // 临时关闭回显，打开时恢复回显状态

    // 设置定时器10秒钟读取一次输入通道信息
    QTimer          *m_pTimer;              // 定时发送数据
    QTimer          *m_pReadConfigTimer;    // 定时读取数据
    QTcpSocket      *m_pSocket;

    int             m_nTimerTimes;

    unsigned short  g_code_id;
    unsigned int    g_local_stat;

    unsigned char   g_stat_wr_addr;
    unsigned char   g_stat_rd_addr;

    unsigned int	new_filter_wait_buffer_len;
    unsigned int    new_filter_rd_buffer_len;
    unsigned int    g_stat_len_array[64];
    unsigned char   g_stat_str[64][256];
    unsigned short	g_rd_stat_buf[8][8192];
    unsigned char	new_filter_rd_buffer[40960];
};

inline bool BCControl::IsShowVedio()
{
    return m_bShowVedio;
}

#endif // BCCONTROL_H
