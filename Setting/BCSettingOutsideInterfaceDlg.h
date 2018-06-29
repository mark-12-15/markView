#ifndef BCSETTINGOUTSIDEINTERFACEDLG_H
#define BCSETTINGOUTSIDEINTERFACEDLG_H

#include <QDialog>

namespace Ui {
class BCSettingOutsideInterfaceDlg;
}

class BCSettingOutsideInterfaceDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingOutsideInterfaceDlg(QWidget *parent = 0);
    ~BCSettingOutsideInterfaceDlg();

private slots:
    void on_m_pConnectBtn1_clicked();

private:
    Ui::BCSettingOutsideInterfaceDlg *ui;
};

#endif // BCSETTINGOUTSIDEINTERFACEDLG_H
