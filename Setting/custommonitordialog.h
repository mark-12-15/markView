#ifndef CUSTOMMONITORDIALOG_H
#define CUSTOMMONITORDIALOG_H

#include <QDialog>
#include "ui_custommonitordialog.h"

class CustomMonitorDialog : public QDialog, private Ui::CustomMonitorDialog
{
    Q_OBJECT
public:
    CustomMonitorDialog();
private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // CUSTOMMONITORDIALOG_H
