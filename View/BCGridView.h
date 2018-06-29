#ifndef BCGRIDVIEW_H
#define BCGRIDVIEW_H

#include <QWidget>
#include "QRadioButton"
class BCGridView : public QWidget
{
    Q_OBJECT
public:
    explicit BCGridView(QWidget *parent = 0,int count = 4);
    void setRadioButton(QRadioButton *radBut);
void test();
signals:

public slots:
    void clickRadioBut();
    void creatSubViews(int count);
protected:


private:
    void deleateSubView();
    QRadioButton *m_radioBut;
    QRadioButton *m_radioButSix;
    QRadioButton *m_radioButEight;
    QRadioButton *m_radioButNine;
    QRadioButton *m_radioButTwelve;
    QRadioButton *m_radioButSixteen;
    bool m_mousePress;
};

#endif // BCGRIDVIEW_H
