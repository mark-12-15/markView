/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：移植并整合的VS2010 BRPlayer代码
*********************************************************************************************************************************/
#ifndef BCVeioDecodeThread_H
#define BCVeioDecodeThread_H

#include <QThread>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMutex>
#include <QTimer>

#include "hi3531/hi_config.h"
#include "hi3531/hi_h264api.h"

extern "C"
{
    #include "libavcodec/avcodec.h"
    #include "libavcodec/avfft.h"
    #include "libavformat/avformat.h"
    #include "libavformat/avio.h"
    #include "libswscale/swscale.h"
    #include "libavutil/common.h"
    #include "libavutil/avstring.h"
    #include "libavutil/imgutils.h"
    #include "libavutil/time.h"
    #include "libavdevice/avdevice.h"
    #include "libswresample/swresample.h"

    #include "SDL2/SDL.h"
    #include "SDL2/SDL_events.h"
    #include "SDL2/SDL_thread.h"
}

typedef struct dec_hi3531_app{
    HI_S32				m_hi3531_end;
    H264_DEC_ATTR_S		m_hi3531_dec_attrbute;
    H264_DEC_FRAME_S	m_hi3531_dec_frame;
    H264_LIBINFO_S		m_hi3531_lib_info;
    HI_HDL				m_hi3531_handle;
    HI_U32				m_hi3531_imageenhanceenable;
    HI_U32				m_hi3531_multithreadenable;
    HI_U32				m_hi3531_strenthcoeff;
    HI_S32				m_hi3531_deinterlaceenable;
    HI_S32				m_hi3531_directoutputenable;
    HI_S32				m_hi3531_showframeinfo;
    HI_U32				m_hi3531_flags;
    HI_S32				m_hi3531_result;
    HI_U8				*m_hi3531_main_ptr;
    HI_U8				*m_hi3531_main_info_aux_ptr;
    HI_U32				m_hi3531_main_info_id[16];
    HI_U8				m_hi3531_pic_cnt;
    HI_U32				m_hi3531_linesize;
    HI_U8				m_hi3531_tcp_ch;
}dec_hi3531_app;

// 解码线程
class BCVedioWindow;
class BCVedioManager;
class BCVeioDecodeThread : public QThread
{
    Q_OBJECT

public:
    BCVeioDecodeThread(const QString &ip, int port, int id, BCVedioManager *parent = NULL);
    ~BCVeioDecodeThread();

    unsigned char   *main_buffer_ptr;   // 数据链表，最大长度16*1024*1024
    unsigned int    main_buffer_len;    // 数据的长度

    void run();

    void SetConnectInfo(const QString &ip, int port);
    void DisConnectSocket();// disconnect socket
    void ConnectSocket();   // reconnect socket
    bool IsConnected();     // isconnected socket

    void ReadyQuit();   // disconnect slot, stop sokect
    void Quit();        // delete socket, quit thread

signals:
    void sigAppendVedioFrame(int id, const QByteArray &pY, const QByteArray &pU, const QByteArray &pV,
                            HI_U32 width, HI_U32 height, HI_U32 yStride, HI_U32 uvStride, const QByteArray &tmp_prew_pos_tab);

private slots:
    void onRecvTcpMessage();

private:
    bool init_hi3531_h264_decode();

private:
    BCVedioManager *m_parent;
    QMutex m_mutex;

    QList<QByteArray> m_lstRecvByteArr;

    QTcpSocket *m_pSocket;

    QString m_ip;
    int m_port;
    int m_id;       // 编号
    bool m_bQuit;   // 退出标识
    int m_nDelayCount;  // 延时帧数

    dec_hi3531_app g_dec_hi3531_app;

    UINT			tmp_local_time_id;
    HI_U8			tmp_line_mask_id_ptr[2048];
    HI_U8			tmp_line_mask_id_ptr_a[2048];
    unsigned int	target_pos_tab[256][5];
};

#endif // BCVeioDecodeThread_H
