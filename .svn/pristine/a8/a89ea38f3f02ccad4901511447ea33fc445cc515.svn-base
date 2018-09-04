#ifndef LOGQUERYDIALOG_H
#define LOGQUERYDIALOG_H

#include <QDialog>
#include <QTableWidget>




namespace Ui {
class LogQueryDialog;
}

class LogQueryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LogQueryDialog(QWidget *parent = 0);
    ~LogQueryDialog();
private slots:
    /*
*  设置TableView
    */
    void setTableVidget();
    /*
*  每次在查询完时因为model改变了得重新设置tableView的相关属性
    */
    void setTableViewAfterChange();
    void reloadData(QList<QMap<QString, QString> > dataArray);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::LogQueryDialog *ui;
    QTableWidget *myTableView;
    //从XML文件中读取到的数组
    QList<QMap<QString,QString> >_dataArray;
};

#endif // LOGQUERYDIALOG_H
