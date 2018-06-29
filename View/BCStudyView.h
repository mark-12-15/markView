/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：整个软件的学习模块
*********************************************************************************************************************************/
#ifndef BCSTUDYVIEW_H
#define BCSTUDYVIEW_H

#include <QGraphicsView>

class BCStudyView : public QGraphicsView
{
public:
    BCStudyView(QWidget * parent = 0);
    ~BCStudyView();

    // 添加软件提示图片及位置，图片最好是GIF
    void AddNotice(const QString &qsImagePath, const QPointF &pos);

    // 清屏
    void ClearScreen();

protected:
    QGraphicsScene *m_pScene;
};

#endif // BCSTUDYVIEW_H
