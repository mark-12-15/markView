/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：本地串口通讯类，当不使用DLL时使用，获得通道、屏组等信息
*********************************************************************************************************************************/
#ifndef BCLOCALSERIALPORT_H
#define BCLOCALSERIALPORT_H

#include <QtSerialPort/QSerialPort>
#include <QRect>

// 临时使用
struct sSerialSignalWindow {
    int gid;        // 屏组ID
    int chid;       // 通道ID
    int winid;      // 窗口ID
    QRect rect;     // 位置

    int sort;       // 屏组内排序，数字越小越靠上
};

class QTimer;
class BSBoardCard;
class BCLocalSerialPort : public QSerialPort
{
    Q_OBJECT
public:
    BCLocalSerialPort(QObject *parent=NULL);
    ~BCLocalSerialPort();

    void RequestConfig(int type);

signals:
    void sigDemoMode();
    // VP4000机器的配置信息
    void sigVP4000Config(QStringList lstInputChannel, QStringList lstGroupDisplay, QStringList lstDefaultScene);

    // VP2000机器的配置信息
    void sigVP2000Config(int timeout, int arrX, int arrY, int resX, int resY, int pcCount, int vedioCount, int hdCount);

    // VP2000机器的IP
    void sigVP2000IP(int timeout, const QString &ip);

private:
    void Init();

    void sortSignalWindow(QList<sSerialSignalWindow> *pList);
    static bool compareSignalWindow(const sSerialSignalWindow &win1, const sSerialSignalWindow &win2);

    int             m_nRequestcount;// 请求服务器次数，最多7次
    int             m_nType;        // 记录请求配置的类型

    QTimer *m_pTimer;
    int m_nTimerTimes;

    QByteArray m_byteRecv;  // 接收的数据

private slots:
    void onRecvMessage();
    void onTimeOut();
};

#endif // BCLOCALSERIALPORT_H
