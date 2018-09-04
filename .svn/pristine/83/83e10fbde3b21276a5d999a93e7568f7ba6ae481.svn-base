#ifndef BCMATRIXROOMWIDGET_H
#define BCMATRIXROOMWIDGET_H

#include <QWidget>
#include <QScrollArea>
#include "../Common/BCLocalServer.h"

namespace Ui {
class BCMatrixRoomWidget;
}

class BCMMatrix;
class BCMatrixInputNodeWidget;
class BCMatrixOutputNodeWidget;
class BCMatrixRoomWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BCMatrixRoomWidget(BCMMatrix *pMatrix, QWidget *parent = 0);
    ~BCMatrixRoomWidget();

    // 返回输入节点的名字
    QString GetInputNodeName(int id);

    // 设置节点名称
    void SetNodeName(int output, int id, const QString &name);

    void Load(int id);
    void Save(int id);
    void Update(int id);
    void Clear();
    void Remove(int id);
    void ModifySceneName(int id, const QString &str);

    // 切换指令
    void SetSwitch(int inID, int outID);

    BCMMatrix *GetMMatrix();
    void UpdateMMatrix(BCMMatrix * pMatrix);

private:
    void mousePressEvent(QMouseEvent *event);

    void AddNode(QScrollArea *pWidget, int type);

private:
    Ui::BCMatrixRoomWidget *ui;

    BCMMatrix *m_pMatrix;
    int m_nCurrentInputNodeID;

    QList<BCMatrixInputNodeWidget *>    m_lstInputNodeWidget;
    QList<BCMatrixOutputNodeWidget *>   m_lstOutputNodeWidget;
};

inline BCMMatrix *BCMatrixRoomWidget::GetMMatrix()
{
    return m_pMatrix;
}

inline void BCMatrixRoomWidget::UpdateMMatrix(BCMMatrix * pMatrix)
{
    m_pMatrix = pMatrix;
}

#endif // BCMATRIXROOMWIDGET_H
