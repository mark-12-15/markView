#ifndef BCSETTINGROOMVIRTUALRESOLUTIONDLG_H
#define BCSETTINGROOMVIRTUALRESOLUTIONDLG_H

#include <QDialog>

namespace Ui {
class BCSettingRoomVirtualResolutionDlg;
}

class BCMRoom;
class BCSettingRoomVirtualResolutionDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingRoomVirtualResolutionDlg(BCMRoom *pRoom, QWidget *parent = 0);
    ~BCSettingRoomVirtualResolutionDlg();

private slots:
    void on_m_pCancelBtn_clicked();

    void on_m_pApplyBtn_clicked();

private:
    Ui::BCSettingRoomVirtualResolutionDlg *ui;

    BCMRoom *m_pRoom;
};

#endif // BCSETTINGROOMVIRTUALRESOLUTIONDLG_H
