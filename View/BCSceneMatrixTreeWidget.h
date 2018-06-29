#ifndef BCSceneMatrixTreeWidget_H
#define BCSceneMatrixTreeWidget_H

#include <QTreeWidget>

class BCScene;
class BCSceneMatrixTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit BCSceneMatrixTreeWidget(QWidget *parent=NULL);
    ~BCSceneMatrixTreeWidget();

    void SetSceneWidget(BCScene *pSceneWidget);

    // 根据当前房间刷新数据
    void Refresh();

    // 添加或者移除轮训
    void SetLoopWindowScene(bool b);

    /* 对外开放接口
     *  1：添加场景
     *  2：删除场景
     *  3：更新场景
     */
    bool SetAction(int type);

private slots:
    // 鼠标双击，显示场景
    void onItemDoubleClicked(QTreeWidgetItem*, int);

private:
    void contextMenuEvent(QContextMenuEvent* event);

    void AddWindowScene();
    void DeleteWindowScene(int id);

    void ModifySceneName(int id, const QString &str);

    BCScene *m_pSceneWidget;
};

inline void BCSceneMatrixTreeWidget::SetSceneWidget(BCScene *pSceneWidget)
{
    m_pSceneWidget = pSceneWidget;
}
#endif // BCSceneMatrixTreeWidget_H
