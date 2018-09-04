#ifndef BCSETTINGCUTINPUTCHANNELDLG_H
#define BCSETTINGCUTINPUTCHANNELDLG_H

#include <QDialog>

namespace Ui {
class BCSettingCutInputChannelDlg;
}

class BCMChannel;
class BCSettingCutInputChannelDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingCutInputChannelDlg(BCMChannel *pChannel, QWidget *parent = 0);
    ~BCSettingCutInputChannelDlg();

private slots:
    void on_m_pCancelBtn_clicked();

    void on_m_pOkBtn_clicked();

//    void on_m_pTopLineEdit_textChanged(const QString &arg1);

//    void on_m_pBottomLineEdit_textChanged(const QString &arg1);

//    void on_m_pLeftLineEdit_textChanged(const QString &arg1);

//    void on_m_pRightLineEdit_textChanged(const QString &arg1);

    void on_m_pApplyBtn_clicked();

private:
    Ui::BCSettingCutInputChannelDlg *ui;

    void SendCmd();

    BCMChannel *m_pChannel;
};

#endif // BCSETTINGCUTINPUTCHANNELDLG_H
