/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：设置设备规模对话框
*********************************************************************************************************************************/
#ifndef BCSETTINGDEVICEFORMATDLG_H
#define BCSETTINGDEVICEFORMATDLG_H

#include <QDialog>

namespace Ui {
class BCSettingDeviceFormatDlg;
}

class SCustomResoluion;
class BCSettingDeviceFormatDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingDeviceFormatDlg(QWidget *parent = 0);
    ~BCSettingDeviceFormatDlg();

    void SetLEDConfig(int resoluX, int resoluY);
    void AddSetXYPara(int chid, int l, int t, int r, int b);

private slots:
    void onCurrentRowChanged(int);
    void on_m_pAddGroupBtn_clicked();

    void on_m_pRemoveGroupBtn_clicked();

    void on_m_pNameLineEdit_textChanged(const QString &arg1);

    void on_m_pResolutionCombbox_currentIndexChanged(int index);

    void on_m_pOKBtn_clicked();

    void on_m_pArrayXLineEdit_valueChanged(int arg1);

    void on_m_pArrayYLineEdit_valueChanged(int arg1);

    void on_m_pGroupTypeCombox_currentIndexChanged(int index);

    void on_m_pAddResolutionBtn_clicked();

    void on_m_pDelResolutionBtn_clicked();

    void on_m_pModifyResolutionBtn_clicked();

    void on_m_pStartChannelLineEdit_valueChanged(int arg1);

    void on_m_pCancelBtn_clicked();

    void on_m_pApplyBtn_clicked();

    void on_m_pGroupIDSpinBox_valueChanged(int arg1);

    void onTimeout();
private:
    Ui::BCSettingDeviceFormatDlg *ui;

    void LoadCustomResolution();
    void UpdateCustomResolution();

    void CommitConfig();
    void AppendCmd(QString cmd, int time, int progress);

    QList<SCustomResoluion *> m_lstResolution;      // 自定义输入分辨率列表

    bool    m_bReload;  // 是否重新加载系统

    struct SFormatCmd {
        QString cmd;        // 执行的命令
        int nExecTime;      // 执行时间
        int nProgress;      // 对应百分比
    };

    QList<SFormatCmd> m_lstFormatCmd;
    QTimer *m_pTimer;
    int m_nCurrentTime;
};

#endif // BCSETTINGDEVICEFORMATDLG_H
