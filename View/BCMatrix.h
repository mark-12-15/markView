#ifndef BCMATRIX_H
#define BCMATRIX_H

#include <QWidget>
#include <QTreeWidget>
#include "BCWidgetBtn.h"

class BCMatrixSignalSourceWidget;
class BCMatrixSignalSourceWidgetItem : public QTreeWidgetItem
{
public:
    BCMatrixSignalSourceWidgetItem(int id, const QString &name, QTreeWidget *parent, BCMatrixSignalSourceWidget *pWidget);

    void SetSwitch(int id); // 设置输出节点切换
    void RefreshName();     // 刷新显示

    BCMatrixSignalSourceWidget *m_pWidget;
    int m_id;
    QString m_name;
    int m_switchid;     // 对输出节点使用
};

class BCMatrixSignalSourceWidget : public QWidget
{
public:
    BCMatrixSignalSourceWidget(BCMMatrix *pMatrix, QWidget *parent);

    BCMMatrix *m_pMatrix;

    QTreeWidget *m_pInputTreeWidget;
    QTreeWidget *m_pOutputTreeWidget;

private:
    bool eventFilter(QObject *target, QEvent *event);
};

// -----------------------------------------------------------------------------------------------------------------------

namespace Ui {
class BCMatrix;
}

class BCMatrix : public QWidget
{
    Q_OBJECT

public:
    explicit BCMatrix(bool bVisible, int minHeight, QWidget *parent = 0);
    ~BCMatrix();

    // 是否隐藏内容
    bool IsVisible();

    int m_minHeight;

    // 刷新切换信息
    void RefreshSwitch(int roomID, int inID, int outID);

private slots:
    void onSetVisible(bool);

private:
    Ui::BCMatrix *ui;

    void Init();

    bool event(QEvent *event);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

    bool m_bModifyHeight;       // 是否修改高度，悬停到最下面时值为true
    bool m_bPress;

    BCWidgetBtn* m_pHeaderBtn;
};

#endif // BCMATRIX_H
