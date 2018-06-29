#ifndef BCSettingDisplaySetNetSetDlg_H
#define BCSettingDisplaySetNetSetDlg_H

#include <QLabel>
#include <QDialog>
namespace Ui {
class BCSettingDisplaySetNetSetDlg;
}

class BCSettingDisplaySetNetSetDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingDisplaySetNetSetDlg(QWidget *parent = 0);
    ~BCSettingDisplaySetNetSetDlg();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::BCSettingDisplaySetNetSetDlg *ui;
    void SetStyleSheet(QLabel *lab);
};

#endif // BCSettingDisplaySetNetSetDlg_H
