#ifndef BCSETTINGSIGNALWINDOWPROPERTYDLG_H
#define BCSETTINGSIGNALWINDOWPROPERTYDLG_H

#include <QDialog>

namespace Ui {
class BCSettingSignalWindowPropertyDlg;
}

class BCSignalWindowDisplayWidget;
class BCSettingSignalWindowPropertyDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingSignalWindowPropertyDlg(BCSignalWindowDisplayWidget *pWidget, QWidget *parent = 0);
    ~BCSettingSignalWindowPropertyDlg();

private slots:
    void on_m_pCancelBtn_clicked();

    void on_m_pOkBtn_clicked();

private:
    Ui::BCSettingSignalWindowPropertyDlg *ui;

    void Init();

    BCSignalWindowDisplayWidget *m_pWidget;
};

#endif // BCSETTINGSIGNALWINDOWPROPERTYDLG_H
