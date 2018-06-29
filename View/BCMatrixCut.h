#ifndef BCMATRIXCUT_H
#define BCMATRIXCUT_H

#include <QWidget>
#include "BCWidgetBtn.h"

namespace Ui {
class BCMatrixCut;
}

class BCMatrixCut : public QWidget
{
    Q_OBJECT

public:
    explicit BCMatrixCut(bool bVisible, int minHeight, QWidget *parent = 0);
    ~BCMatrixCut();

    // 是否隐藏内容
    bool IsVisible();

    int m_minHeight;

private slots:
    void onSetVisible(bool);

private:
    Ui::BCMatrixCut *ui;
    BCWidgetBtn* m_pHeaderBtn;
};

#endif // BCMATRIXCUT_H
