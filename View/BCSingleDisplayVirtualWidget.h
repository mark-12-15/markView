#ifndef BCSINGLEDISPLAYVIRTUALWIDGET_H
#define BCSINGLEDISPLAYVIRTUALWIDGET_H

#include <QWidget>

class BCSingleDisplayVirtualWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCSingleDisplayVirtualWidget(int row, int col, int i, int j, QWidget *parent = 0);

    // row和col记录整体数值，i和j记录当前矩形位置
    int m_row;
    int m_col;
    int m_i;
    int m_j;

protected:
    void paintEvent(QPaintEvent */*e*/);
};

#endif // BCSINGLEDISPLAYVIRTUALWIDGET_H
