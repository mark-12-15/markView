#ifndef BCSETTINGMODIFYNAMEDLG_H
#define BCSETTINGMODIFYNAMEDLG_H

#include <QDialog>

namespace Ui {
class BCSettingModifyNameDlg;
}

class BCSettingModifyNameDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingModifyNameDlg(const QString &str, QWidget *parent = 0);
    ~BCSettingModifyNameDlg();

    QString GetString();

private slots:
    void on_m_pCancelBtn_clicked();

    void on_m_pOKBtn_clicked();

private:
    Ui::BCSettingModifyNameDlg *ui;

    QString m_str;
};

#endif // BCSETTINGMODIFYNAMEDLG_H
