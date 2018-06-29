#ifndef BCSETTINGWINDOWCOPYCONFIGDLG_H
#define BCSETTINGWINDOWCOPYCONFIGDLG_H

#include <QDialog>

namespace Ui {
class BCSettingWindowCopyConfigDlg;
}

class BCSettingWindowCopyConfigDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingWindowCopyConfigDlg(QWidget *parent = 0);
    ~BCSettingWindowCopyConfigDlg();

private slots:
    void on_m_pCancelBtn_clicked();

    void on_m_pOKBtn_clicked();

    void on_m_pOpenWindowCopyBtn_clicked();

    void on_m_pCloseWindowCopyBtn_clicked();

private:
    Ui::BCSettingWindowCopyConfigDlg *ui;

    int m_nMaxCopyCount;    // 支持最大复制数量
    int m_nPCCount;
    int m_nVideoCount;
};

#endif // BCSETTINGWINDOWCOPYCONFIGDLG_H
