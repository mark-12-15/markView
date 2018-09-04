#ifndef BCEXPROCESSDIALOG_H
#define BCEXPROCESSDIALOG_H

#include <QDialog>
#include <QTableWidgetItem>

namespace Ui {
class BCExProcessDialog;
}

class BCExProcessDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BCExProcessDialog(QStringList list, QWidget *parent = 0);
    ~BCExProcessDialog();
    //外部调用接口exe
    void Run(uint index);
    QString GetPath(uint index);

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_buttonBox_accepted();

    void on_m_pOKBtn_clicked();

    void on_m_pCancelBtn_clicked();

private:
    Ui::BCExProcessDialog *ui;
    void SetTabelWidget(uint row,uint column,QTableWidgetItem* item);
    QStringList m_list;
    void DataShow();

};

#endif // BCEXPROCESSDIALOG_H
