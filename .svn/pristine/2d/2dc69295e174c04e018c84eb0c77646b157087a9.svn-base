/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：信号窗场景数据类
*********************************************************************************************************************************/
#ifndef BCMWINDOWSCENE_H
#define BCMWINDOWSCENE_H

#include <QMap>
#include <QRectF>
class BCMChannel;
class BCMGroupScene;
class BCMRoom;

// 窗口场景内数据类
struct BCWindowSceneData
{
    int         m_nChannelID;       // 信号ID
    int         m_nChannelType;     // 信号ID
    int         m_nWindowID;        // window id
    int         m_nCopyIndex;       // 第几个复制窗口
    int         m_nScreenGroupID;   // 屏幕ID
    //QString     m_qsTitle;        // 标题
    QRectF      m_rect;             // 实际位置

    int         m_nIPVSegmentation; // IPV分割数
    QStringList m_lstIP;            // IPV使用的IPV链表，共16个
};

class BCMWindowScene
{
public:
    BCMWindowScene(BCMGroupScene *pGroupScene);
    BCMWindowScene(BCMRoom *pRoom);
    ~BCMWindowScene();

    BCMGroupScene *GetGroupScene();

    // 针对当前显示墙进行保存、显示、更新操作，参数标识是否和服务器通讯
    bool Save(bool bConnectServer = true);
    bool Show(bool bConnectServer = true);
    bool Update();
    void Clear(bool bConnectServer = true);

    void AddWindowSceneData(BCWindowSceneData *pData);
    const QList<BCWindowSceneData *> &GetWindowSceneData();

    void SetWindowSceneID(int qs);
    int GetWindowSceneID();

    void SetWindowSceneBaseName(const QString &qs);
    const QString &GetWindowSceneBaseName();

    void SetWindowSceneName(const QString &qs, bool bSave = true);
    const QString &GetWindowSceneName();

    void SetWindowSceneLoopInterval(int interval, bool bSave = true);
    int GetWindowSceneLoopInterval();

    void SetIsCycled(bool b, bool bSave = true);
    bool IsCycled();

protected:
    QList<BCWindowSceneData *>  m_lstData;

    BCMRoom         *m_pRoom;       // 默认场景时使用
    BCMGroupScene   *m_pGroupScene; // 归属场景组时使用

    int m_id;
    QString m_qsBaseName;
    QString m_name;
    bool    m_bIsCycled;
    int m_nLoopInterval;
};

inline BCMGroupScene *BCMWindowScene::GetGroupScene()
{
    return m_pGroupScene;
}

inline const QList<BCWindowSceneData *> &BCMWindowScene::GetWindowSceneData()
{
    return m_lstData;
}

inline void BCMWindowScene::SetWindowSceneID(int qs)
{
    m_id = qs;
}

inline int BCMWindowScene::GetWindowSceneID()
{
    return m_id;
}

inline void BCMWindowScene::SetWindowSceneBaseName(const QString &qs)
{
    m_qsBaseName = qs;
}

inline const QString &BCMWindowScene::GetWindowSceneBaseName()
{
    return m_qsBaseName;
}

inline const QString &BCMWindowScene::GetWindowSceneName()
{
    return m_name;
}

inline int BCMWindowScene::GetWindowSceneLoopInterval()
{
    return m_nLoopInterval;
}

inline bool BCMWindowScene::IsCycled()
{
    return m_bIsCycled;
}

#endif // BCMWINDOWSCENE_H
