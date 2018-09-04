#ifndef BCSCENETREEWIDGETITEM_H
#define BCSCENETREEWIDGETITEM_H

#include <QTreeWidgetItem>

class BCMGroupScene;
class BCMWindowScene;
class BCSceneTreeWidgetItem : public QTreeWidgetItem
{
public:
    // 非组模式，topLevel是场景
    BCSceneTreeWidgetItem(BCMWindowScene *pWindowScene, QTreeWidget *parent);
    ~BCSceneTreeWidgetItem();

    // 返回数据
    BCMWindowScene *GetWindowScene();

    // 设置是否添加到轮训
    void SetLoopWindowScene(bool b);

    // 设置轮巡时间
    void SetLoopInterval(int n);

private:
    BCMWindowScene  *m_pWindowScene;    // 场景数据
};

inline BCMWindowScene* BCSceneTreeWidgetItem::GetWindowScene(){
    return m_pWindowScene;
}

#endif // BCSCENETREEWIDGETITEM_H
