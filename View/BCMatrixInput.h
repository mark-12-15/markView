#ifndef BCMATRIXINPUT_H
#define BCMATRIXINPUT_H

#include <QWidget>
#include "BCWidgetBtn.h"
namespace Ui {
class BCMatrixInput;
}

class BCMatrixInput : public QWidget
{
    Q_OBJECT

public:
    explicit BCMatrixInput(bool bVisible, int minHeight, QWidget *parent = 0);
    ~BCMatrixInput();

    // 是否隐藏内容
    bool IsVisible();

    int m_minHeight;

private slots:
    void onSetVisible(bool);

private:
    Ui::BCMatrixInput *ui;
    BCWidgetBtn* m_pHeaderBtn;
};

#endif // BCMATRIXINPUT_H
