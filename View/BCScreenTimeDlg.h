#ifndef BCSCREENTIMEDLG_H
#define BCSCREENTIMEDLG_H

#include <QDialog>
#include <QAbstractButton>
#include <QPushButton>
namespace Ui {
class BCScreenTimeDlg;
}

class BCScreenTimeDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCScreenTimeDlg(int num,QWidget *parent = 0);
    ~BCScreenTimeDlg();
    int GetNum();

private slots:

    void on_pushButton_ok_clicked();

    void on_pushButton_cannel_clicked();

private:
    Ui::BCScreenTimeDlg *ui;
    int m_number;
};

#endif // BCSCREENTIMEDLG_H
