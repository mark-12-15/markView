/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：调用外部指令对话框
*********************************************************************************************************************************/
#ifndef BCSETTINGOUTSIDECOMMANDDLG_H
#define BCSETTINGOUTSIDECOMMANDDLG_H

#include <QDialog>

namespace Ui {
class BCSettingOutSideCommandDlg;
}

class BCSettingOutSideCommandDlg : public QDialog
{
    Q_OBJECT

public:
    // type标识普通指令和需要编码指令，0为普通指令，1为需要编码指令
    explicit BCSettingOutSideCommandDlg(int type, QWidget *parent = 0);
    ~BCSettingOutSideCommandDlg();

private slots:
    void on_m_pGetCodeBtn_clicked();

    void on_m_pSelectConfigFileBtn_clicked();

    void on_m_pSelectMd5FileBtn_clicked();

    void on_m_pExecBtn_clicked();

private:
    Ui::BCSettingOutSideCommandDlg *ui;
};

#endif // BCSETTINGOUTSIDECOMMANDDLG_H
