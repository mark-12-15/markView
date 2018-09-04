#include "BCSignalTreeWidgetItem.h"
#include "../Model/BCMChannel.h"
#include "../Model/BCMGroupChannel.h"
#include "../Common/BCCommon.h"

BCSignalTreeWidgetItem::BCSignalTreeWidgetItem(BCMGroupChannel *pGroupChannel, QTreeWidget *parent)
    :QTreeWidgetItem(parent)
{
    m_pGroupChannel = pGroupChannel;
    m_pChannel = NULL;

    // 设置图片和文字
    this->setText(0, m_pGroupChannel->GetName());
}

BCSignalTreeWidgetItem::BCSignalTreeWidgetItem(BCMChannel *pChannel, QTreeWidgetItem *parent)
    :QTreeWidgetItem(parent)
{
    m_pChannel = pChannel;
    m_pGroupChannel = NULL;

    // 设置图片和文字
    MainWindow *pApplication = BCCommon::Application();
    this->setText(0, m_pChannel->GetChannelBaseName()+m_pChannel->GetChannelName());
    this->setIcon(0, QIcon(pApplication->GetInputChannelIcon(m_pChannel->GetSignalSource())));
}

bool BCSignalTreeWidgetItem::IsChannel()
{
    return (NULL == m_pChannel) ? false : true;
}
