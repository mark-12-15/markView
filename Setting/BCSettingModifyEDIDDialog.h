#ifndef BCSETTINGMODIFYEDIDDIALOG_H
#define BCSETTINGMODIFYEDIDDIALOG_H

#include <QDialog>

namespace Ui {
class BCSettingModifyEDIDDialog;
}

class BCMChannel;
class BCSettingModifyEDIDDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingModifyEDIDDialog(BCMChannel *pChannel, QWidget *parent = 0);
    ~BCSettingModifyEDIDDialog();

private slots:
    void on_m_pCancelBtn_clicked();

    void on_m_pOKBtn_clicked();

private:
    Ui::BCSettingModifyEDIDDialog *ui;

    BCMChannel *m_pChannel;
};

#endif // BCSETTINGMODIFYEDIDDIALOG_H
