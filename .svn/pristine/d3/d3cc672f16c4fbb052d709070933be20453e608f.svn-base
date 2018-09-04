#ifndef BCSYSTEMPLAN_H
#define BCSYSTEMPLAN_H

#include <QWidget>
#include "BCWidgetBtn.h"
namespace Ui {
class BCSystemplan;
}

class BCMWindowScene;
class BCSystemplan : public QWidget
{
    Q_OBJECT

public:
    explicit BCSystemplan(bool bVisible, int minHeight, QWidget *parent = 0);
    ~BCSystemplan();

    // 是否隐藏内容
    bool IsVisible();

    int m_minHeight;

private slots:
    void onSetVisible(bool);

private:
    Ui::BCSystemplan *ui;
    BCWidgetBtn* m_pHeaderBtn;
};

#endif // BCSYSTEMPLAN_H
