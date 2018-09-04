#ifndef BCSETTINGIPVEDIOIPDLG_H
#define BCSETTINGIPVEDIOIPDLG_H

#include <QDialog>

namespace Ui {
class BCSettingIPVedioIPDlg;
}

class BCMChannel;
class BCSettingIPVedioIPDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingIPVedioIPDlg(BCMChannel *pChannel, QWidget *parent = 0);
    ~BCSettingIPVedioIPDlg();

private slots:
    void on_m_pOKBtn_clicked();

    void on_m_pCancelBtn_clicked();

private:
    Ui::BCSettingIPVedioIPDlg *ui;

    BCMChannel *m_pChannel;
};

#endif // BCSETTINGIPVEDIOIPDLG_H
