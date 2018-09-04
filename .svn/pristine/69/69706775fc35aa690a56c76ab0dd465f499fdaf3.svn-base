#ifndef BCSCREENSET_H
#define BCSCREENSET_H

#include <QDialog>
#include "BCScreenBtn.h"
#include <QGridLayout>

namespace Ui {
class BCScreenSet;
}

class BCScreenSet : public QDialog
{
    Q_OBJECT

public:
    explicit BCScreenSet(QWidget *parent = 0);
    ~BCScreenSet();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_signal_close(int index);

    void on_ScreenChange();
    void on_pushButton_2_clicked();

private:
    Ui::BCScreenSet *ui;

    QList<BCScreenBtn*> m_list;
    QGridLayout* layout2;
};

#endif // BCSCREENSET_H
