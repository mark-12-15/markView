/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：场景组数据类，一个房间内可能有多个屏组，所以场景组归属房间不能归属屏组
*********************************************************************************************************************************/
#ifndef BCMGROUPSCENE_H
#define BCMGROUPSCENE_H

#include <QObject>
#include <QTimer>

class BCMWindowScene;
class BCMSubTitlesScene;
class BCMRoom;
class BCMGroupScene : public QObject
{
    Q_OBJECT
public:
    BCMGroupScene(BCMRoom *pRoom);
    ~BCMGroupScene();

    BCMRoom *GetRoom();

    void AddWindowScene(BCMWindowScene *pWindowScene);
    const QList<BCMWindowScene *> &GetWindowScenes();
    BCMWindowScene *GetWindowScene(int id);

    // 删除场景
    void RemoveWindowScene(int id);
    void DeleteWindowScene(BCMWindowScene *pWindowScene);
    void ClearWindowScene();

    // 判断场景组内是否存在当前ID的场景
    bool IsExistWindowScene(const QString &id);

    void SetGroupSceneName(const QString &qsName, bool bSave = true);
    const QString &GetGroupSceneName();

    // 返回屏组ID
    int GetGroupSceneID();

    // 外部设置ID
    void SetGroupSceneID(int id);

    // 更新场景次序
    void UpdateWindowSceneSort();
    void UpdateWindowSceneSort(QMap<int, int> map);

    // 移动场景
    void MoveToUp(BCMWindowScene *pWindowScene);
    void MoveToDown(BCMWindowScene *pWindowScene);
    void MoveToTop(BCMWindowScene *pWindowScene);
    void MoveToBottom(BCMWindowScene *pWindowScene);

protected:
    void CreateGroupSceneID();

protected:
    BCMRoom *m_pRoom;   // 归属房间

    int m_nID;          // 场景组ID，整个系统唯一值，不按房间分组
    QString m_qsName;   // 场景组名称

    QList<BCMWindowScene *> m_lstWindowScene;           // 信号窗场景
    QList<BCMSubTitlesScene *>  m_lstSubTitlesScene;    // 字幕场景
};

inline BCMRoom *BCMGroupScene::GetRoom()
{
    return m_pRoom;
}

inline int BCMGroupScene::GetGroupSceneID()
{
    return m_nID;
}

inline void BCMGroupScene::SetGroupSceneID(int id)
{
    m_nID = id;
}

inline const QList<BCMWindowScene *> &BCMGroupScene::GetWindowScenes()
{
    return m_lstWindowScene;
}

inline const QString &BCMGroupScene::GetGroupSceneName()
{
    return m_qsName;
}

#endif // BCMGROUPSCENE_H
