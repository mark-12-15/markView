#ifndef BCSettingMatrixDlg_H
#define BCSettingMatrixDlg_H

#include <QDialog>

namespace Ui {
class BCSettingMatrixDlg;
}

class BCSettingMatrixDlg : public QDialog
{
    Q_OBJECT
public:
    BCSettingMatrixDlg(QWidget *parent = 0);
    ~BCSettingMatrixDlg();

private slots:
    void on_m_pCancelBtn_clicked();
    void on_m_pOkBtn_clicked();

    void onStateChangedOfVGA(int);
    void onStateChangedOfVideo(int);
    void onStateChangedOfDVI(int);
    void onStateChangedOfHDMI(int);
    void onStateChangedOfSDI(int);
    void onStateChangedOfAudio(int);

    void on_m_pVGASetBtn_clicked();

    void on_m_pVideoSetBtn_clicked();

    void on_m_pDVISetBtn_clicked();

    void on_m_pHDMISetBtn_clicked();

    void on_m_pSDISetBtn_clicked();

    void on_m_pAudioSetBtn_clicked();

    void on_m_pVGAPreSetBtn_clicked();

    void on_m_pVideoPreSetBtn_clicked();

    void on_m_pDVIPreSetBtn_clicked();

    void on_m_pHDMIPreSetBtn_clicked();

    void on_m_pSDIPreSetBtn_clicked();

    void on_m_pAudioPreSetBtn_clicked();

private:
    Ui::BCSettingMatrixDlg *ui;

    void Init();
};

#endif // BCSettingMatrixDlg_H
