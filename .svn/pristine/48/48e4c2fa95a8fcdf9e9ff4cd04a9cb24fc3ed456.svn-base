#include "BCMGroupChannel.h"
#include <QObject>
BCMGroupChannel::BCMGroupChannel(const QString &qsID)
{
    m_qsID = qsID;
    m_qsName = QObject::tr("自定义分组");
}

BCMGroupChannel::~BCMGroupChannel()
{
    m_lstChannel.clear();
}

BCMGroupChannel::BCMGroupChannel(const BCMGroupChannel &other)
{
    this->m_qsID = other.m_qsID;
    this->m_qsName = other.m_qsName;
    this->m_lstChannel = other.m_lstChannel;
}

BCMGroupChannel *BCMGroupChannel::Clone()
{
    return new BCMGroupChannel(*this);
}

bool BCMGroupChannel::AddChannel(BCMChannel *pChannel)
{
    if (m_lstChannel.contains(pChannel))
        return false;

    m_lstChannel.append( pChannel );

    return true;
}

void BCMGroupChannel::RemoveChannel(BCMChannel *pChannel)
{
    m_lstChannel.removeOne( pChannel );
}
