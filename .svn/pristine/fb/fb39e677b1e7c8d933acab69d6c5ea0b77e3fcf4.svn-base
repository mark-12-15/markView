#ifndef BCOTHERDEVICECONTROLDLG_H
#define BCOTHERDEVICECONTROLDLG_H

#include <QDialog>
#include <QToolButton>

namespace Ui {
class BCOtherDeviceControlDlg;
}

class QTcpSocket;
class BCOtherDeviceControlDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCOtherDeviceControlDlg(QWidget *parent = 0);
    ~BCOtherDeviceControlDlg();

private slots:
    void on_m_pDisplayOnBtn_clicked();

    void on_m_pDisplayOffBtn_clicked();

    void on_m_pLightingOnBtn_clicked();

    void on_m_pLightingOffBtn_clicked();

    void on_m_pAudioPlusBtn_clicked();

    void on_m_pAudioReduceBtn_clicked();

    void on_m_pAudioSilenceBtn_clicked();

    void on_m_pVedioZoomOnBtn_clicked();

    void on_m_pVedioZoomOffBtn_clicked();

    void on_m_pVedioFocusOnBtn_clicked();

    void on_m_pVedioFocusOffBtn_clicked();

    void on_m_pVedioTopBtn_clicked();

    void on_m_pVedioRightBtn_clicked();

    void on_m_pVedioBottomBtn_clicked();

    void on_m_pVedioLeftTopBtn_clicked();

    void on_m_pVedioRightTopBtn_clicked();

    void on_m_pVedioLeftBottomBtn_clicked();

    void on_m_pVedioRightBottomBtn_clicked();

    void on_m_pVedioStopBtn_clicked();

    void on_m_pVedioLeftBtn_clicked();

private:
    Ui::BCOtherDeviceControlDlg *ui;

    void SetToolButtonIcon(QToolButton *pBtn, QString qsIconPath, int w = 40, int h = 40);

    QTcpSocket *m_pDisplayTcpSocket;
    QTcpSocket *m_pLightingTcpSocket;
    QTcpSocket *m_pAudioTcpSocket;
    QTcpSocket *m_pVedioTcpSocket;
};

#endif // BCOTHERDEVICECONTROLDLG_H
