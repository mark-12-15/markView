#ifndef BCSETTINGSUBTITLESDLG_H
#define BCSETTINGSUBTITLESDLG_H

#include <QDialog>

namespace Ui {
class BCSettingSubTitlesDlg;
}

class BCMChannel;
class BCSettingSubTitlesDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingSubTitlesDlg(BCMChannel *pChannel, QWidget *parent = 0);
    ~BCSettingSubTitlesDlg();

private slots:
    void on_m_pColorBtn_clicked();

    void on_m_pCancelBtn_clicked();

    void on_m_pOkBtn_clicked();

    void on_m_pApplyBtn_clicked();

private:
    Ui::BCSettingSubTitlesDlg *ui;

    BCMChannel *m_pChannel;
};

#endif // BCSETTINGSUBTITLESDLG_H
