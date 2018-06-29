/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：通道组类
*********************************************************************************************************************************/
#ifndef BCMGROUPCHANNEL_H
#define BCMGROUPCHANNEL_H

#include <QList>

class BCMChannel;
class BCMGroupChannel
{
public:
    BCMGroupChannel(const QString &qsID);
    ~BCMGroupChannel();

    BCMGroupChannel(const BCMGroupChannel &other);

    BCMGroupChannel *Clone();

    const QString &GetID();

    const QString &GetName();
    void SetName(const QString &name);

    bool AddChannel(BCMChannel *pChannel);
    void RemoveChannel(BCMChannel *pChannel);

    const QList<BCMChannel *> &GetChannels();

private:
    QString m_qsID;
    QString m_qsName;
    QList<BCMChannel *> m_lstChannel;
};

inline const QList<BCMChannel *> &BCMGroupChannel::GetChannels()
{
    return m_lstChannel;
}

inline const QString &BCMGroupChannel::GetID()
{
    return m_qsID;
}

inline const QString &BCMGroupChannel::GetName()
{
    return m_qsName;
}

inline void BCMGroupChannel::SetName(const QString &name)
{
    m_qsName = name;
}

#endif // BCMGROUPCHANNEL_H
