#ifndef BCSETTINGDISPLAYSWITCHCONFIGDLG_H
#define BCSETTINGDISPLAYSWITCHCONFIGDLG_H

#include <QDialog>

// 大屏厂家结构体
struct sDisplayMaker {
    QString maker;
    int cmdType;        // 0:16进制  1:文本
    QString onCmd;
    QString offCmd;
};

namespace Ui {
class BCSettingDisplaySwitchConfigDlg;
}

class BCSettingDisplaySwitchRoomWidget;
class BCSettingDisplaySwitchConfigDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingDisplaySwitchConfigDlg(QWidget *parent = 0);
    ~BCSettingDisplaySwitchConfigDlg();

    void SetDisplayMaker(const QList<sDisplayMaker> &lstDisplayMaker);

private slots:
    void on_m_pCancelBtn_clicked();

    void on_m_pOKBtn_clicked();

    void on_m_pDisplayMakerBtn_clicked();

private:
    Ui::BCSettingDisplaySwitchConfigDlg *ui;

    void InitDisplayMaker();

    QList<BCSettingDisplaySwitchRoomWidget *>   m_lstRoomWidget;
    QList<sDisplayMaker> m_lstDisplayMaker;
};

#endif // BCSETTINGDISPLAYSWITCHCONFIGDLG_H
