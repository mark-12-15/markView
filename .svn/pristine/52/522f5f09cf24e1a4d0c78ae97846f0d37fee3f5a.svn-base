/*********************************************************************************************************************************
* 作    者：liyuzhe
* 时    间：2016.5.12
* 功    能：外部调用exe进程功能实现类
*********************************************************************************************************************************/


#ifndef BCPROCESSBTN_H
#define BCPROCESSBTN_H

#include <QToolButton>
#include <QString>

class BCExProcessBtn : public QToolButton
{
    Q_OBJECT
public:
    explicit BCExProcessBtn(QString path,QWidget *parent = 0);
    ~BCExProcessBtn();
signals:
    void leftButtonClicked();
    void rightButtonClicked();
private slots:
    void on_leftclicked();
    void on_rightclicked();
private:
    QString m_path;
    void mouseReleaseEvent(QMouseEvent* e);
};

#endif // BCPROCESSBTN_H
