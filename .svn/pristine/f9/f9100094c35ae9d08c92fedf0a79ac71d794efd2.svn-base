#ifndef BCSETTINGDEVICECUSTOMRESOLUTIONDLG_H
#define BCSETTINGDEVICECUSTOMRESOLUTIONDLG_H

#include <QDialog>

namespace Ui {
class BCSettingDeviceCustomResolutionDlg;
}

class BCSettingDeviceCustomResolutionDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingDeviceCustomResolutionDlg(int liveW, int liveH, int preW, int preH, int syncW, int syncH, int totalW, int totalH, int polarityW, int polarityH, int hertz, QWidget *parent = 0);
    ~BCSettingDeviceCustomResolutionDlg();

    int m_liveW;
    int m_liveH;
    int m_preW;
    int m_preH;
    int m_syncW;
    int m_syncH;
    int m_totalW;
    int m_totalH;
    int m_polarityW;
    int m_polarityH;
    int m_hertz;

private slots:
    void on_m_pOKBtn_clicked();

    void on_m_pCancelBtn_clicked();

private:
    Ui::BCSettingDeviceCustomResolutionDlg *ui;
};

#endif // BCSETTINGDEVICECUSTOMRESOLUTIONDLG_H
