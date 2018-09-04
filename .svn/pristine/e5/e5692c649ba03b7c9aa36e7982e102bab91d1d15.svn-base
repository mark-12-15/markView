/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：信号源工具条内的控件的自定义显示按钮
*********************************************************************************************************************************/
#ifndef BCWIDGETBTN_H
#define BCWIDGETBTN_H

#include <QWidget>
#include "MainWindow.h"

namespace Ui {
class BCWidgetBtn;
}

class BCWidgetBtn : public QWidget
{
    Q_OBJECT

public:
    explicit BCWidgetBtn(QWidget *parent, MainWindow::SIGNALSOURCETYPE eType, bool bVisible = true);
    ~BCWidgetBtn();

    bool IsVisible();

    void RefreshLanguage();

signals:
    void sigSetVisible(bool);

private:
    Ui::BCWidgetBtn *ui;
    void mousePressEvent(QMouseEvent* e);

    void init();
    void RefreshVisibleIcon(bool);

    MainWindow::SIGNALSOURCETYPE m_eType;
    bool    m_bVisible;     // 是否显示
};

inline bool BCWidgetBtn::IsVisible()
{
    return m_bVisible;
}

#endif // BCWIDGETBTN_H
