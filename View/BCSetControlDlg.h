#ifndef BCSETCONTROLDLG_H
#define BCSETCONTROLDLG_H

#include <QDialog>
#include <QTableWidgetItem>
#include <QComboBox>
#include <QSpinBox>
#include <QList>
#include <QMap>

namespace Ui {
class BCSetControlDlg;
}

class BCSetControlDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSetControlDlg(QWidget *parent = 0);
    ~BCSetControlDlg();



private slots:
    void on_pushButton_OK_clicked();

    void on_pushButton_CANNEL_clicked();

    void on_pushButton_RESET_clicked();

    void slot_itemClicked(QTableWidgetItem*);

    void slot_currentIndexChanged(QString str);
    void slot_valueChanged(QString str);

private:
    Ui::BCSetControlDlg *ui;
    QComboBox* m_combo;
    QSpinBox* m_spin;
    QList<QMap<QString,QString>> ReadXml();
    void WriteXml();

};


#endif // BCSETCONTROLDLG_H
