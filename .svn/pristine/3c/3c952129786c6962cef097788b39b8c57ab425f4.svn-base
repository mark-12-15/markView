#ifndef BCSCREENBTN_H
#define BCSCREENBTN_H

#include <QPushButton>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>

class BCScreenBtn : public QPushButton
{
    Q_OBJECT
public:
    explicit BCScreenBtn(QWidget *parent = 0);
    ~BCScreenBtn();
    void setNum(const int index);
    int getNum();
    void setName(const QString name);

signals:
    void rightButtonClicked();
    void signal_close(int index);

private slots:
    void on_changeaction(bool);
    void on_deleteaction(bool);

private:
    void mouseReleaseEvent(QMouseEvent* e);
    void contextMenuEvent(QContextMenuEvent* event);
    int m_num;
    QString m_name;
    QMenu* m_menu;
    QAction* m_change_action;
    QAction* m_delete_action;
};

#endif // BCSCREENBTN_H
