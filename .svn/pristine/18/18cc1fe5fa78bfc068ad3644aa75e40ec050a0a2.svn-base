#ifndef BCSETTINGWAITINGDLG_H
#define BCSETTINGWAITINGDLG_H

#include <QDialog>

namespace Ui {
class BCSettingWaitingDlg;
}

class BCSettingWaitingDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingWaitingDlg(QWidget *parent = 0);
    ~BCSettingWaitingDlg();

private slots:
    void onInit();
    void onTimeOut();

private:
    Ui::BCSettingWaitingDlg *ui;

    QTimer *m_pTimer;   // 用来查看初始化的标志位
    int     m_timeout;  // timeout次数
};

#endif // BCSETTINGWAITINGDLG_H
