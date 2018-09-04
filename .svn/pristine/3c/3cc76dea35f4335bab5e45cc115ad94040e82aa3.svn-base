#ifndef HARDWAREPARAMETER_H
#define HARDWAREPARAMETER_H

#include <QDialog>

namespace Ui {
class HardWareParameter;
}

class HardWareParameter : public QDialog
{
    Q_OBJECT

public:
    explicit HardWareParameter(QWidget *parent = 0);
    ~HardWareParameter();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::HardWareParameter *ui;
    void init();
    void saveInXML();
    QString S2;
    QString S1;
    QString C1;
    QString C2;
    QString P1;
    QString cNumber;
    QString screenName;
    QString baudRate;
    QString rNumber;
    QString netAddress;
    QString Hposition;
    QString off;
    QString Vposition;
    QString netPort;
    QString resolutionY;
    QString resolutionX;
};

#endif // HARDWAREPARAMETER_H
