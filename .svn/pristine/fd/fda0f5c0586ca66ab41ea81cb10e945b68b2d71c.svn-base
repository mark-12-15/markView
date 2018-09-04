#ifndef BCSCREENDLG_H
#define BCSCREENDLG_H

#include <QDialog>

namespace Ui {
class BCScreenDlg;
}

class BCMGroupScene;
class BCMWindowScene;
class BCScreenDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCScreenDlg(BCMGroupScene *pGroupScene, QWidget *parent = 0);
    ~BCScreenDlg();

    BCMWindowScene *GetWindowScene();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_ok_clicked();
    void on_pushButton_cannel_clicked();

private:
    Ui::BCScreenDlg *ui;

    BCMGroupScene *m_pGroupScene;
};

#endif // BCSCREENDLG_H
