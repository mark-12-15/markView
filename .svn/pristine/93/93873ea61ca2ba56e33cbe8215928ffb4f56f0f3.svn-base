#ifndef BCMMATRIX_H
#define BCMMATRIX_H

#include "../Common/BCLocalServer.h"

class BCMMatrix
{
public:
    BCMMatrix();

    void Load(int id);
    void Save(int id);
    // 切换指令
    void SetSwitch(int inID, int outID);

    void SetMatrixName(int output, int nodeid, const QString &name);    // 参数1表示是否是输出口，0输入，1输出；

    void SetMatrixRoomName(const QString &text);

    void SetCut(int id, int l, int r, int t, int b);

    // 发送指令
    void SendCmd(const QString &cmd);

    void ConnectDevice();   // 连接设备

    // 基础属性
    int id;
    QString name;

    int isConnectByNet;             // 是否网络通信
    QString ip;                     // 网络通信IP
    int port;                       // 网络通信端口
    QString qsCurrentCom;           // 串口号
    int nCurrentBaudRate;           // 波特率
    int nCurrentDataBit;            // 数据位
    int nCurrentStopBit;            // 停止位
    QString qsCurrentCheckBit;      // 校验位
    QString qsCurrentStreamCtrl;    // 控制流

    int isOn;                       // 大屏开关状态
    QString qsOnCmd;                // 打开指令
    QString qsOffCmd;               // 关闭指令

    int cmdType;        // 指令类型，0：16进制，1：Ascii码
    QString switchFlag; // 切换指令表达式，如SW %1 %2...
    QString loadFlag;   // 调取指令，如%1.
    QString saveFlag;   // 保存指令，如%1,

    int jointSceneRoomID;           // 是否关联调用场景，关联的拼控调用场景时将调用当前矩阵的场景

    int jointWithVP4000;            // 是否联控设备，如果联控设备矩阵输出口直接对应设备的输入口

    QList<sMatrixNode>  lstInputNode;   // 输入节点
    QList<sMatrixNode>  lstOutputNode;  // 输出节点
    QList<sMatrixScene> lstScene;       // 场景列表

private:
    QTcpSocket  *m_pTcpSocket;              // TCP通讯
    QSerialPort m_serial;                   // 串口通讯
};

#endif // BCMMATRIX_H
