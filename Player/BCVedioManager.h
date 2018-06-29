/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：管理预监回显等视频显示类
*********************************************************************************************************************************/
#ifndef BCVedioMANAGER_H
#define BCVedioMANAGER_H

#include <windows.h>
#include <QUdpSocket>
#include <QTimer>
#include <QRect>
#include <QMutex>

typedef unsigned char   HI_U8;
typedef unsigned long   HI_U32;

// 显示的窗口类
class SDL_Window;
class SDL_Renderer;
class SDL_Texture;
class BCVedioManager;
class BCVedioWindow
{
public:
    BCVedioWindow(HWND wid, int chid, QRect rect);
    ~BCVedioWindow();

    HWND m_wid;     // 窗口ID
    int m_chid;     // 通道ID
    QRect m_rect;   // 绘制尺寸

    SDL_Window *pScreen;
    SDL_Renderer *pRenderer;
    SDL_Texture *pTexture;
    SDL_Texture *pYUVTexture;
};

// 视频帧
struct BCVedioFrame
{
    QByteArray pY;
    QByteArray pU;
    QByteArray pV;
    HI_U32 width;
    HI_U32 height;
    HI_U32 yStride;
    HI_U32 uvStride;

    QByteArray tmp_prew_pos_tab;
};

// 图像的管理类
class BCVeioDecodeThread;
class BCVedioPlayerThread;
class BCVedioManager : public QObject
{
    Q_OBJECT

public:
    static BCVedioManager *Application();
    static void Destroy();

    // 判断socket是否连接
    bool IsConnected();

    // 设置播放器连接属性
    void SetPlayerConnectConfig(const QString &ip, int port);

    // 添加回显
    void AddEcho(HWND wid, int chid, int x, int y, int w, int h);
    // 更新回显单元
    void UpdateEcho(HWND wid, int x, int y, int w, int h);
    // 删除回显
    void RemoveEcho(HWND wid);

    QList<BCVedioWindow *> m_lstWindow;

    void StartPlayerThread();
    void StopPlayerThread();

    QMutex m_mutexWindow;     // 链表的线程锁
    BYTE	tmp_bak_pos_tab[1024][2];

    // 视频帧数据链表
    QList<BCVedioFrame> m_lstFrameOfDecodeThread1;
    QList<BCVedioFrame> m_lstFrameOfDecodeThread2;
    QList<BCVedioFrame> m_lstFrameOfDecodeThread3;
    QList<BCVedioFrame> m_lstFrameOfDecodeThread4;
    QMutex m_mutexFrame;

public slots:
    void onTimeout();
    void onAppendVedioFrame(int id, const QByteArray &pY, const QByteArray &pU, const QByteArray &pV,
                            HI_U32 width, HI_U32 height, HI_U32 yStride, HI_U32 uvStride, const QByteArray &tmp_prew_pos_tab);
    void onRecvPreviewUdpData();

private:
    BCVedioManager();
    ~BCVedioManager();

    static BCVedioManager *m_pApplication;      // 唯一对象

    QString m_ip;
    int m_port;

    QList<unsigned int> m_lstIP;            // 固定4个，如192 168 0 1
    int         m_nDelayPlayTimes;
    int         m_nHeartTimes;              // 心跳包的次数，串口和网口共享变量
    QUdpSocket  *m_pPreviewUdpSocket;       // 广播的预监UDP
    QTimer      *m_pOneSecondTimer;         // 1秒定时器，用来检查网络连接
    bool        m_bStartThread;             // 是否开启了解码和播放线程
    BCVeioDecodeThread *m_pDecodeThread1;
    BCVeioDecodeThread *m_pDecodeThread2;
    BCVeioDecodeThread *m_pDecodeThread3;
    BCVeioDecodeThread *m_pDecodeThread4;

    BCVedioPlayerThread *m_pPlayerThread;
};

#endif // BCVedioMANAGER_H
