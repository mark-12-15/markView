#ifndef BCSETTINGOTHERDEVICECONTROLDLG_H
#define BCSETTINGOTHERDEVICECONTROLDLG_H

#include <QDialog>
#include <QPushButton>

class QTcpSocket;
class BCVedioBtn : public QPushButton
{
public:
    BCVedioBtn(QWidget *parent);

    void SetTcpSocket(QTcpSocket *pTcpSocket) {
        m_pTcpSocket = pTcpSocket;
    }

private:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

    QTcpSocket *m_pTcpSocket;
};
// ------------------------------------------------------------------------------------------

namespace Ui {
class BCSettingOtherDeviceControlDlg;
}

class BCSettingOtherDeviceControlDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingOtherDeviceControlDlg(QWidget *parent = 0);
    ~BCSettingOtherDeviceControlDlg();

private slots:
    void onReconnect();

    void on_m_pMainVedioBtn_clicked();
    void on_m_pDisplayMainBtn_clicked();
    void on_m_pMainAudioBtn_clicked();

    void on_m_pPowerBtn_clicked();
    
    void on_m_pDisplayHDMIBtn_clicked();
    void on_m_pDisplayDVIBtn_clicked();
    void on_m_pDisplayVideo1Btn_clicked();
    void on_m_pdisplayVIDEO2Btn_clicked();
    void on_m_pDisplayVGABtn_clicked();
    
    void on_m_pAudioSlider1_valueChanged(int value);
    void on_m_pAudioSlider2_valueChanged(int value);
    
    void on_m_pVedioOn1_clicked();
    void on_m_pVedioOff1_clicked();

    void on_m_pRoom1Btn_clicked();

    void on_m_pRoom2Btn_clicked();

    void on_m_pRoom3Btn_clicked();

    void on_m_pRoom4Btn_clicked();

    void on_m_pVedioOff2_clicked();

    void on_m_pVedioOff3_clicked();

    void on_m_pVedioOff4_clicked();

    void on_m_pVedioOn2_clicked();

    void on_m_pVedioOn3_clicked();

    void on_m_pVedioOn4_clicked();

    void on_m_pAudioSlider3_valueChanged(int value);

    void on_m_pAudioSlider4_valueChanged(int value);

    void on_m_pMainLightBtn_clicked();

    void on_m_pMainTVBtn_clicked();

    void on_m_pMainCurtainBtn_clicked();

private:
    Ui::BCSettingOtherDeviceControlDlg *ui;

    void SendCmd();

    QTcpSocket *m_pTcpSocket;
    int m_nType;    // 1：屏幕，2：音频，3：摄像头
    bool m_bPower;  // 屏幕开关
};

#endif // BCSETTINGOTHERDEVICECONTROLDLG_H
