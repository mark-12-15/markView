#ifndef BCSettingDisplaySetDlg_H
#define BCSettingDisplaySetDlg_H

#include <QDialog>
namespace Ui {
class BCSettingDisplaySetDlg;
}

class BCSettingDisplaySetDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingDisplaySetDlg(QWidget *parent = 0);
    ~BCSettingDisplaySetDlg();

private slots:
    void on_checkBox_10_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_checkBox_ON_clicked();

    void on_checkBox_OFF_clicked();

    void on_radio_serial_clicked();

    void on_radio_TCP_clicked();

    void on_radio_UDP_clicked();

    void on_radio_Serial2_clicked();

private:
    Ui::BCSettingDisplaySetDlg *ui;
    void init();
    void setSubViewEnabled(bool b);
    //         点击自动开机 和自动关机
    void setCheckBoxEnabled(bool b);
};

#endif // BCSettingDisplaySetDlg_H
