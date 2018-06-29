#ifndef BCSIGNALSROUCESCENEVIEWWIDGET_H
#define BCSIGNALSROUCESCENEVIEWWIDGET_H

#include <QWidget>

class QTreeWidget;
class QListWidget;
class BCMGroupScene;
class QTreeWidgetItem;
class BCSignalSrouceSceneViewTreeWidgetItem;
class BCSignalSrouceSceneViewWidget : public QWidget
{
public:
    BCSignalSrouceSceneViewWidget(BCMGroupScene *pGroupScene, int showType, QWidget *parent);
    ~BCSignalSrouceSceneViewWidget();

    // 刷新界面，showType(显示模式：0列表模式，1网格模式)
    void Refresh(int showType);

    /* 对外开放接口
     *  1：添加场景
     *  2：删除场景
     *  3：更新场景
     *  4：场景设置
     *  5：修改名称
     *  6：清空场景
     */
    bool SetAction(int type);

    // 批量设置轮巡时间
    void SetBatchLoopTime(int value);

    // 返回显示模式
    int GetShowType();

    // 编辑场景的轮巡时间
    void SetSceneEditable();

    void SetSelectAll(bool b);
    bool IsSelectAll();

    BCMGroupScene *GetMGroupScene();

private:
    bool eventFilter(QObject *, QEvent *);

    void RefreshTreeWidget();
    void RefreshListWidget();

    void ClearWindowScene();
    void AddWindowScene();
    void DeleteWindowScene(QList<QTreeWidgetItem*> lstItems);
    void UpdateWindowScene(BCSignalSrouceSceneViewTreeWidgetItem *pWindowSceneItem);
    void ModifyWindowSceneName(BCSignalSrouceSceneViewTreeWidgetItem *pGroupSceneItem);
    void SetLoopWindowScene(bool b);
    // type标识移动类型，1：上移 2：下移 3：置顶 4：置底
    void MoveWindowScene(int type);

    BCMGroupScene   *m_pGroupScene;
    QTreeWidget     *m_pTreeWidget;
    QListWidget     *m_pListWidget;
    bool            m_bSelectAll;       // 是否全选
};

inline bool BCSignalSrouceSceneViewWidget::IsSelectAll()
{
    return m_bSelectAll;
}

inline BCMGroupScene *BCSignalSrouceSceneViewWidget::GetMGroupScene()
{
    return m_pGroupScene;
}

#endif // BCSIGNALSROUCESCENEVIEWWIDGET_H
