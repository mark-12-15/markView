#ifndef BCABOUT_H
#define BCABOUT_H

#include <QDialog>

namespace Ui {
class BCAbout;
}

class BCAbout : public QDialog
{
    Q_OBJECT

public:
    explicit BCAbout(QWidget *parent = 0);
    ~BCAbout();

private slots:
    void on_pushButton_clicked();

    void openUrl(QString url);

private:
    Ui::BCAbout *ui;
};

#endif // BCABOUT_H
