#ifndef BCSETTINGDEBUGDLG_H
#define BCSETTINGDEBUGDLG_H

#include <QDialog>

namespace Ui {
class BCSettingDebugDlg;
}

class BCSettingDebugDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingDebugDlg(QWidget *parent = 0);
    ~BCSettingDebugDlg();

    void AddCmd(const QString &cmd);

private slots:
    void on_m_pClearBtn_clicked();

    void on_m_pSendBtn_clicked();

private:
    Ui::BCSettingDebugDlg *ui;
};

#endif // BCSETTINGDEBUGDLG_H
