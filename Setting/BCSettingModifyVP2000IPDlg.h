#ifndef BCSETTINGMODIFYVP2000IPDLG_H
#define BCSETTINGMODIFYVP2000IPDLG_H

#include <QDialog>

namespace Ui {
class BCSettingModifyVP2000IPDlg;
}

class BCSettingModifyVP2000IPDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingModifyVP2000IPDlg(QWidget *parent = 0);
    ~BCSettingModifyVP2000IPDlg();

private slots:
    void on_m_pCancelBtn_clicked();

    void on_m_pOKBtn_clicked();

private:
    Ui::BCSettingModifyVP2000IPDlg *ui;
};

#endif // BCSETTINGMODIFYVP2000IPDLG_H
