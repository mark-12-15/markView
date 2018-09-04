/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：预案地图对话框内的预案链表
*********************************************************************************************************************************/
#ifndef BCPlanMapTreeWidget_H
#define BCPlanMapTreeWidget_H

#include <QTreeWidget>
class BCPlanMapTreeWidget : public QTreeWidget
{
public:
    BCPlanMapTreeWidget(QWidget *parent = 0);

private:
    void mouseMoveEvent(QMouseEvent*event);
    void mouseReleaseEvent(QMouseEvent*event);
    void dragEnterEvent(QDragEnterEvent *event);

    bool m_bDrag;   // 记录是否拖拽
};

#endif // BCPlanMapTreeWidget_H
