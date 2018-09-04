#ifndef BCSETTINGDISPLAYMAKERCONFIGDLG_H
#define BCSETTINGDISPLAYMAKERCONFIGDLG_H

#include <QDialog>

namespace Ui {
class BCSettingDisplayMakerConfigDlg;
}

class sDisplayMaker;
class QListWidgetItem;
class BCSettingDisplaySwitchConfigDlg;
class BCSettingDisplayMakerConfigDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingDisplayMakerConfigDlg(const QList<sDisplayMaker> &lstDisplayMaker, BCSettingDisplaySwitchConfigDlg *parent = 0);
    ~BCSettingDisplayMakerConfigDlg();

private slots:
    void onCurrentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
    void on_m_pCancelBtn_clicked();

    void on_m_pAddBtn_clicked();

    void on_m_pDelBtn_clicked();

    void on_m_pModifyBtn_clicked();

    void on_m_pOKBtn_clicked();

private:
    Ui::BCSettingDisplayMakerConfigDlg *ui;

    BCSettingDisplaySwitchConfigDlg *m_parent;
};

#endif // BCSETTINGDISPLAYMAKERCONFIGDLG_H
