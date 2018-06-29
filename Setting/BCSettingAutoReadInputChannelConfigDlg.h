#ifndef BCSETTINGAUTOREADINPUTCHANNELCONFIGDLG_H
#define BCSETTINGAUTOREADINPUTCHANNELCONFIGDLG_H

#include <QDialog>

namespace Ui {
class BCSettingAutoReadInputChannelConfigDlg;
}

class BCSettingAutoReadInputChannelConfigDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingAutoReadInputChannelConfigDlg(QWidget *parent = 0);
    ~BCSettingAutoReadInputChannelConfigDlg();

private slots:
    void on_m_pCancelBtn_clicked();

    void on_m_pOKBtn_clicked();

    void on_m_pIsUseCheckBox_released();

private:
    Ui::BCSettingAutoReadInputChannelConfigDlg *ui;
};

#endif // BCSETTINGAUTOREADINPUTCHANNELCONFIGDLG_H
