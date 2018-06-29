#ifndef BCWARNINGLOGWINDOW_H
#define BCWARNINGLOGWINDOW_H

#include <QDialog>

namespace Ui {
class BCWarningLogWindow;
}

class BCWarningLogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BCWarningLogWindow(QWidget *parent = 0);
    ~BCWarningLogWindow();

    void setTableViewAfterChange();

private slots:
    void on_pushButton_2_clicked();

    void on_QueryBut_clicked();

private:
    Ui::BCWarningLogWindow *ui;
    void init();
    void saveInXML();
    void reloadData(QList<QMap<QString,QString> > dataArray);
    QList<QMap<QString,QString> >_dataArray;     //XML数据
};

#endif // BCWARNINGLOGWINDOW_H
