#ifndef BCSIGNALNAME_H
#define BCSIGNALNAME_H

#include <QDialog>
#include <QAbstractButton>
#include <QPushButton>
namespace Ui {
class BCSignalName;
}

class BCMChannel;
class BCControlListWidgetItem;
class BCSignalName : public QDialog
{
    Q_OBJECT

public:
    explicit BCSignalName(QString, QWidget *parent = 0);
    BCSignalName(BCMChannel *pChannel, QWidget *parent = 0);
    ~BCSignalName();

    QString m_str;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::BCSignalName *ui;

    BCMChannel *m_pChannel;
};

#endif // BCSIGNALNAME_H
