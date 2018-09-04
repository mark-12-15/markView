#ifndef TESTCOLOR_H
#define TESTCOLOR_H

#include <QDialog>

namespace Ui {
class TestColor;
}

class TestColor : public QDialog
{
    Q_OBJECT

public:
    explicit TestColor(QWidget *parent = 0);
    ~TestColor();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_verticalSlider_sliderMoved(int position);


    void on_pushButton_red_clicked();

    void on_pushButton_green_clicked();

    void on_pushButton_blue_clicked();

    void on_pushButton_yellow_clicked();

    void on_pushButton_fen_clicked();

    void on_pushButton_lv_clicked();

    void on_pushButton_white_clicked();

private:
    Ui::TestColor *ui;
    void init();
    void hideSubViews();
    void loadData();
    void saveInXML();
    QString H1;
    QString V1;
    QString H2;
    QString V2;
    QString Value;
};

#endif // TESTCOLOR_H
