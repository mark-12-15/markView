#ifndef EDIDDIALOG_H
#define EDIDDIALOG_H

#include <QDialog>

namespace Ui {
class EDIDDialog;
}

class EDIDDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EDIDDialog(QWidget *parent = 0);
    ~EDIDDialog();
    void changeContent();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

private:
    Ui::EDIDDialog *ui;
    void init();
    void saveInXML();
    QString resolutionX;
    QString resolutionY;
    QString resolutionZ;
};

#endif // EDIDDIALOG_H
