#ifndef BCMATRIXOUTPUTNODEWIDGET_H
#define BCMATRIXOUTPUTNODEWIDGET_H

#include <QWidget>
#include "../Common/BCLocalServer.h"

namespace Ui {
class BCMatrixOutputNodeWidget;
}

class BCMatrixRoomWidget;
class BCMatrixOutputNodeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BCMatrixOutputNodeWidget(const sMatrixNode &node, BCMatrixRoomWidget *parent = 0);
    ~BCMatrixOutputNodeWidget();

    // 设置第二个输入节点
    void SetDoubleNode(const sMatrixNode &m_node);

    // 刷新切换端口
    void RefreshSwitchNode(int inputID, const QString &name, QPoint pt);

    // 刷新界面切换
    void RefreshSwitchUI(QList<QPoint> lst);

    // 返回切换信息
    void GetSwitchInfo(QPoint &pt1, QPoint &pt2);

    // 刷新界面高亮
    void RefreshHighLight(int id);

private:
    Ui::BCMatrixOutputNodeWidget *ui;

    bool eventFilter(QObject *obj, QEvent *e);
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);

    void ModifyName(int i);
    void ModifyResolution(int in, int type);

    BCMatrixRoomWidget *m_parent;

    bool m_bDoubleNode;     // 是否有两个节点
    sMatrixNode m_node1;
    sMatrixNode m_node2;

    int m_nSwitchID1;       // 节点1切换的信号
    int m_nSwitchID2;       // 节点2切换的信号

    bool m_bHighLight1;     // 是否是高亮状态
    bool m_bHighLight2;     // 是否是高亮状态
};

#endif // BCMATRIXOUTPUTNODEWIDGET_H
