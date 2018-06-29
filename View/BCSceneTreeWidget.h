#ifndef BCSCENETREEWIDGET_H
#define BCSCENETREEWIDGET_H

#include <QTreeWidget>

class BCScene;
class BCSystemplan;
class BCMRoom;
class BCSceneTreeWidgetItem;
class BCSceneTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit BCSceneTreeWidget(QWidget *parent=NULL);
    ~BCSceneTreeWidget();

    void SetSceneWidget(BCScene *pSceneWidget);
    void SetSceneWidget(BCSystemplan *pSystemplay);

    // 根据当前房间刷新数据
    void Refresh();

    /* 对外开放接口
     *  1：添加场景
     *  2：删除场景
     *  3：更新场景
     *  4：场景设置
     *  5：修改名称
     *  6：清空场景
     */
    bool SetAction(int type);

    bool SetLoopAction(bool &b);

    void SetLoopTime(int value);

    // type标识移动类型，1：上移 2：下移 3：置顶 4：置底
    void MoveWindowScene(int type);

    // 添加或者移除轮训
    void SetLoopWindowScene(bool b);

private slots:
    // 鼠标双击，显示场景
    void onItemDoubleClicked(QTreeWidgetItem*, int);

private:
    /*  右键菜单说明
     *  空白:
     *      1.添加场景组
     *      2.清空场景组
     *  单选:
     *      1.场景组:
     *              1.添加场景
     *              2.修改名称
     *              3.设置轮训时间
     *              4.打开轮训(先关闭其他的轮训开关，刷新界面按钮显示)
     *              5.关闭轮训
     *      2.场景
     *              1.预览场景
     *              2.删除场景
     *              3.修改名称
     *              4.添加轮训
     *              5.移除轮训
     *  多选(只对场景生效，如其中有场景组数据则不显示):
     *      1.删除场景
     *      2.添加多个场景轮训
     *      3.移除多个场景轮训
     */
    void contextMenuEvent(QContextMenuEvent* event);

    //void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    void ClearWindowScene(BCMRoom *pRoom);

    void AddWindowScene(BCSceneTreeWidgetItem *pGroupSceneItem);
    void SetLoopTime();
    void ModifySceneLoopInterval(BCSceneTreeWidgetItem *pGroupSceneItem);
    void ModifyGroupSceneName(BCSceneTreeWidgetItem *pGroupSceneItem);

    void PreviewWindowScene(BCSceneTreeWidgetItem *pWindowSceneItem);
    void UpdateWindowScene(BCSceneTreeWidgetItem *pWindowSceneItem);
    void DeleteWindowScene(QList<QTreeWidgetItem*> lstItems);

    BCScene *m_pSceneWidget;
    BCSystemplan *m_pSystemplay;    // 系统预案，默认放场景
};

inline void BCSceneTreeWidget::SetSceneWidget(BCScene *pSceneWidget)
{
    m_pSceneWidget = pSceneWidget;
}

inline void BCSceneTreeWidget::SetSceneWidget(BCSystemplan *pSystemplay)
{
    m_pSystemplay = pSystemplay;
}

#endif // BCSCENETREEWIDGET_H
