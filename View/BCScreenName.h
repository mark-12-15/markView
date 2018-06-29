#ifndef BCSCREENNAME_H
#define BCSCREENNAME_H

#include <QDialog>

namespace Ui {
class BCScreenName;
}

class BCScreenName : public QDialog
{
    Q_OBJECT

public:
    explicit BCScreenName(QString str, QWidget *parent = 0);
    ~BCScreenName();
     QString name;

private slots:
    void on_m_pOKBtn_clicked();
    void on_m_pCancelBtn_clicked();

private:
    Ui::BCScreenName *ui;

};

#endif // BCSCREENNAME_H
