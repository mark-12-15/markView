#ifndef BCMATRIXINPUTNODEWIDGET_H
#define BCMATRIXINPUTNODEWIDGET_H

#include <QWidget>
#include "../Common/BCLocalServer.h"

namespace Ui {
class BCMatrixInputNodeWidget;
}

class BCMatrixRoomWidget;
class BCMatrixInputNodeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BCMatrixInputNodeWidget(const sMatrixNode &node, BCMatrixRoomWidget *parent = 0);
    ~BCMatrixInputNodeWidget();

    // 设置第二个输入节点
    void SetDoubleNode(const sMatrixNode &m_node);

    // 根据父指针的点判断是否需要高亮，高亮的返回节点ID，否则返回-1
    int GetNodeID(QPoint pt);

private:
    Ui::BCMatrixInputNodeWidget *ui;

    bool eventFilter(QObject *, QEvent *);
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);

    void ModifyName(int type);
    void ModifyInputType(int in, int type);
    void ModifyResolution(int type);
    void CutSignal();

    BCMatrixRoomWidget *m_parent;

    bool m_bDoubleNode;     // 是否有两个节点
    sMatrixNode m_node1;
    sMatrixNode m_node2;

    bool m_bHighLight1;     // 是否是高亮状态
    bool m_bHighLight2;     // 是否是高亮状态
};

#endif // BCMATRIXINPUTNODEWIDGET_H
