#ifndef BCSUBBOXVIEW_H
#define BCSUBBOXVIEW_H

#include <QWidget>
#include <QLabel>
#include <QVariant>
class BCSubBoxView : public QLabel
{
    Q_OBJECT
public:
    explicit BCSubBoxView(QWidget *parent = 0);
    void SetActiveBackGround(bool b);
    QPoint _index;

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:

    QPoint beginPoint;
    bool g_mousePressed = false;

    QString m_qsBackGroundColor;
    QString m_qsActiveColor;

};

#endif // BCSUBBOXVIEW_H
