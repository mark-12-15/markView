#ifndef BCSettingMatrixFormatDlg_H
#define BCSettingMatrixFormatDlg_H

#include <QDialog>
#include <QListWidgetItem>

class sMatrixNode;
class sMatrixScene;
class BCCmdMatrixListWidgetItem : public QListWidgetItem
{
public:
    BCCmdMatrixListWidgetItem(int id, QListWidget *parent = NULL);

    void SetName(const QString &qsName) {
        name = qsName;
        this->setText( name );
    }

    int m_id;
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

    int cmdType;
    QString switchFlag; // 切换指令表达式，如SW %1 %2...
    QString loadFlag;   // 调取指令，如%1.
    QString saveFlag;   // 保存指令，如%1,
    int jointSceneRoomID;
    int jointWithVP4000;            // 是否联控设备，如果联控设备矩阵输出口直接对应设备的输入口

    QList<sMatrixNode>  lstInputNode;   // 输入节点
    QList<sMatrixNode>  lstOutputNode;  // 输出节点
    QList<sMatrixScene> lstScene;       // 场景列表
};
// ----------------------------------------------------------------------------------------------------------------------------------------

namespace Ui {
class BCSettingMatrixFormatDlg;
}

class QListWidgetItem;
class BCSettingMatrixFormatDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingMatrixFormatDlg(QWidget *parent = 0);
    ~BCSettingMatrixFormatDlg();

private slots:
    void onCurrentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_m_pAddBtn_clicked();

    void on_m_pRemoveBtn_clicked();

    void on_m_pCancelBtn_clicked();

    void on_m_pOKBtn_clicked();

    void on_m_pModifyBtn_clicked();

    void on_m_pJointWithVP4000ConfigBtn_clicked();

private:
    Ui::BCSettingMatrixFormatDlg *ui;

    int CreateMatrixID();   // 创建矩阵ID，从1开始
};

#endif // BCSettingMatrixFormatDlg_H
