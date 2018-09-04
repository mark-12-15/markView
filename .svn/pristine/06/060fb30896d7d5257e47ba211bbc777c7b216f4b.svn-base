#ifndef BCOUTSIDEINTERFACESERVER_H
#define BCOUTSIDEINTERFACESERVER_H

#include <QObject>
#include <QSerialPort>

class BCOutsideInterfaceServer: public QObject
{
    Q_OBJECT
public:
    // 静态接口构造和销毁
    static BCOutsideInterfaceServer *Application();
    static void Destroy();

    void Connect();
    bool IsConnected();

    QString     m_qsCurrentCom;             // 当前COM口
    int         m_nCurrentBaudRate;         // 当前波特率
    int         m_nCurrentDataBit;          // 当前数据位
    int         m_nCurrentStopBit;          // 当前停止位
    QString     m_qsCurrentCheckBit;        // 当前校验位
    QString     m_qsCurrentStreamCtrl;      // 当前流控制

private slots:
    void onRecvSerialData();

private:
    BCOutsideInterfaceServer();
    ~BCOutsideInterfaceServer();

    static BCOutsideInterfaceServer *m_pApplication;

    QSerialPort     m_serial;                   // 串口通讯
    QList<QPoint>   m_lstChannelMap;            // 输入通道对应表，对应BCOutsideInterfaceChannelMapConfig.xml文件，因为可能会出现重复的，所以没用map
};

#endif // BCOUTSIDEINTERFACESERVER_H
