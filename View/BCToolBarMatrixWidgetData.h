#ifndef BCTOOLBARMATRIXWIDGETDATA_H
#define BCTOOLBARMATRIXWIDGETDATA_H

#include <QListWidget>
#include <QGraphicsView>

class BCToolBarMatrixWidget : public QListWidget
{
public:
    explicit BCToolBarMatrixWidget(QWidget *parent = 0);
    ~BCToolBarMatrixWidget();

    void SetSignalWindowNULL(int winid);

private:
    // 刷新内部数据
    void Refresh();

    int m_nOutputCount;
};

class BCDisplayItemManager;
class BCSignalWindowDisplayItem;
class BCToolBarMatrixWidgetData : public QGraphicsView
{
    Q_OBJECT

public:
    explicit BCToolBarMatrixWidgetData(int index, BCToolBarMatrixWidget *pMatrixWidget);
    ~BCToolBarMatrixWidgetData();

    void SetSignalWindowNULL(int winid);

private:
    void dropEvent(QDropEvent*);
    void contextMenuEvent(QContextMenuEvent* event);
    void resizeEvent(QResizeEvent * event);

    void SetSegmentation(int n);

    QGraphicsScene          *m_pScene;          // 主窗体对应的Scene

    BCDisplayItemManager    *m_pSignalManager;  // 默认添加信号窗管理类
    BCDisplayItemManager    *m_pGroupDisplay;   // 构造默认屏组

    BCSignalWindowDisplayItem *m_pSignalWindow1;// 默认就四个窗口
    BCSignalWindowDisplayItem *m_pSignalWindow2;
    BCSignalWindowDisplayItem *m_pSignalWindow3;
    BCSignalWindowDisplayItem *m_pSignalWindow4;

    int m_nSegCount;    // 分屏数量1/4

    BCToolBarMatrixWidget *m_pMatrixWidget;
};

#endif // BCTOOLBARMATRIXWIDGETDATA_H
