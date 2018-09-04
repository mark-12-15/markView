#ifndef BCSETTINGCHANNELREMOTEIPDLG_H
#define BCSETTINGCHANNELREMOTEIPDLG_H

#include <QDialog>

namespace Ui {
class BCSettingChannelRemoteIPDlg;
}

class BCMChannel;
class BCSettingChannelRemoteIPDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingChannelRemoteIPDlg(BCMChannel *pChannel, QWidget *parent = 0);
    ~BCSettingChannelRemoteIPDlg();

private slots:
    void on_m_pCancelBtn_clicked();

    void on_m_pOKBtn_clicked();

private:
    Ui::BCSettingChannelRemoteIPDlg *ui;

    BCMChannel *m_pChannel;
};

#endif // BCSETTINGCHANNELREMOTEIPDLG_H
