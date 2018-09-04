#ifndef BCSettingSingleDisplaySwitchConfigDlg_H
#define BCSettingSingleDisplaySwitchConfigDlg_H

#include <QDialog>

namespace Ui {
class BCSettingSingleDisplaySwitchConfigDlg;
}

class BCMDisplay;
class BCSettingSingleDisplaySwitchConfigDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingSingleDisplaySwitchConfigDlg(BCMDisplay *pMDisplay, QWidget *parent = 0);
    ~BCSettingSingleDisplaySwitchConfigDlg();

private slots:
    void on_m_pCancelBtn_clicked();

    void on_m_pOKBtn_clicked();

private:
    Ui::BCSettingSingleDisplaySwitchConfigDlg *ui;

    BCMDisplay  *m_pMDisplay;
};

#endif // BCSettingSingleDisplaySwitchConfigDlg_H
