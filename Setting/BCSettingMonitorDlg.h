#ifndef BCSettingMonitorDlg_H
#define BCSettingMonitorDlg_H

#include <QDialog>
#include "ui_BCSettingMonitorDlg.h"

namespace Ui {
class BCSettingMonitorDlg;
}

class BCSettingMonitorDlg : public QDialog
{
    Q_OBJECT
public:
    BCSettingMonitorDlg(QWidget *parent = NULL);
    ~BCSettingMonitorDlg();

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_m_pSetLeftCommunicationBtn_clicked();
    void on_m_pSetRightCommunicationBtn_clicked();
    void on_m_pSetTopCommunicationBtn_clicked();
    void on_m_pSetBottomCommunicationBtn_clicked();

private:
    Ui::BCSettingMonitorDlg *ui;
};

#endif // BCSettingMonitorDlg_H
