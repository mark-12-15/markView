#ifndef BCCUTSCREEN_H
#define BCCUTSCREEN_H

#include <QWidget>
#include "BCWidgetBtn.h"
namespace Ui {
class BCCutScreen;
}

class BCCutScreen : public QWidget
{
    Q_OBJECT

public:
    explicit BCCutScreen(bool bVisible, int minHeight, QWidget *parent = 0);
    ~BCCutScreen();

    // 是否隐藏内容
    bool IsVisible();

    int m_minHeight;

private slots:
    void onSetVisible(bool);

private:
    Ui::BCCutScreen *ui;
    BCWidgetBtn* m_pHeaderBtn;
};

#endif // BCCUTSCREEN_H
