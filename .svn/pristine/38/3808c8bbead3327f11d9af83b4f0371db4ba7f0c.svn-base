/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：本地TCP SOCKET类，当不使用DLL时使用，获得通道、屏组等信息
*********************************************************************************************************************************/
#ifndef BCLOCALTCPSOCKET_H
#define BCLOCALTCPSOCKET_H

#include <QTcpSocket>
#include <QList>
#include <QRect>
#include <QFile>

// 临时使用
struct sSignalWindow {
    int gid;        // 屏组ID
    int chid;       // 通道ID
    int winid;      // 窗口ID
    QRect rect;     // 位置

    int sort;       // 屏组内排序，数字越小越靠上
};

class BSBoardCard;
class QTimer;
class BCLocalTcpSocket : public QObject
{
    Q_OBJECT

public:
    BCLocalTcpSocket(const QString &ip, int port);
    ~BCLocalTcpSocket();

    // 请求配置(1-5拟作废)
    // 1:VP4000所有信息
    // 10.VP2000
    void RequestConfig(int type);

    BSBoardCard *GetBoardCardData();

signals:
    // 输入通道的信号，参数1标识是否超时，参数2中4个为一组输入通道，分别是分辨率X、分辨率Y、是否可用、信号类型(0 VGA  1 DVI  2 CVBS  3 YPbPr  4 HDMI  5 S-V  6 HDVI  7 SDI  8 DP  9 IPV  10 HDBaseT  11 FIBER)
    void sigChannel(int timeout, QStringList lstData);
    void sigGroupDisplay(int timeout, QStringList lstData);

    // 板卡数据信号，type标识机器类型，1:4U, 2:14U
    void sigBoardCard(int timeout, int type);

    // 设备状态信号
    /*  int		nVoltageOfDevice;			// 设备电压
        int		nElectricityOfDevice;		// 设备电流

        int		nRotationSpeedOfFan1;		// 风扇1转速
        int		nRotationSpeedOfFan2;		// 风扇2转速
        int		nRotationSpeedOfFan3;		// 风扇3转速
        int		nRotationSpeedOfFan4;		// 风扇4转速
        int		nRotationSpeedOfFan5;		// 风扇5转速
        int		nRotationSpeedOfFan6;		// 风扇6转速
        int		nRotationSpeedOfFan7;		// 风扇7转速
        int		nRotationSpeedOfFan8;		// 风扇8转速
    */
    void sigDeviceStatus(int timeout, int nVoltageOfDevice, int nElectricityOfDevice, int nRotationSpeedOfFan1, int nRotationSpeedOfFan2,
                                                                 int nRotationSpeedOfFan3, int nRotationSpeedOfFan4, int nRotationSpeedOfFan5, int nRotationSpeedOfFan6,
                                                                 int nRotationSpeedOfFan7, int nRotationSpeedOfFan8);

    // 板卡状态信号
    /*  int		nCoreVoltageOfChip1;		// 芯片1核心电压
        int		nRoundVoltageOfChip1;		// 芯片1外围电压
        int		nCoreElectricityOfChip1;	// 芯片1核心电流
        int		nRoundElectricityOfChip1;	// 芯片1外围电流

        int		nCoreVoltageOfChip2;		// 芯片2核心电压
        int		nRoundVoltageOfChip2;		// 芯片2外围电压
        int		nCoreElectricityOfChip2;	// 芯片2核心电流
        int		nRoundElectricityOfChip2;	// 芯片2外围电流

        int		nVoltageOfMemorizer;		// 存储器电压
        int		nElectricityOfMemorizer;	// 存储器电流

        int		nVoltageOfInput;			// 入口电压
        int		nElectricityOfInput;		// 入口电流
    */
    void sigBoardCardStatus(int timeout, int nCoreVoltageOfChip1, int nRoundVoltageOfChip1, int nCoreElectricityOfChip1, int nRoundElectricityOfChip1,
                           int nCoreVoltageOfChip2, int nRoundVoltageOfChip2, int nCoreElectricityOfChip2, int nRoundElectricityOfChip2,
                           int nVoltageOfMemorizer, int nElectricityOfMemorizer, int nVoltageOfInput, int nElectricityOfInput);

    // VP4000机器的配置信息
    void sigVP4000Config(QStringList lstInputChannel, QStringList lstGroupDisplay, QStringList lstDefaultScene);
    // VP2000机器的配置信息
    void sigVP2000Config(int timeout, int arrX, int arrY, int resX, int resY, int pcCount, int vedioCount, int hdCount);
    // 演示模式
    void sigDemoMode();
private:
    // 自定义比较函数
    void sortSignalWindow(QList<sSignalWindow> *pList);
    static bool compareSignalWindow(const sSignalWindow &win1, const sSignalWindow &win2);

    void DestroyBoardCardData();

    QTcpSocket      *m_pTcpSocket;
    QString         m_ip;
    int             m_port;

    BSBoardCard     *m_pBoardCard;  // 板卡数据

    QByteArray      m_byteRecv;     // 接收的数据
    int             m_nRequestcount;// 请求服务器次数，最多7次
    int             m_nType;        // 记录请求配置的类型

    QTimer          *m_pTimer;
    int             m_nTimerTimes;

private slots:
    void onRecvTcpMessage();
    void onTimeOut();
};

inline BSBoardCard *BCLocalTcpSocket::GetBoardCardData()
{
    return m_pBoardCard;
}

#endif // BCLOCALTCPSOCKET_H
