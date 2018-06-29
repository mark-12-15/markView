#include "BCMGroupDisplay.h"

#include "BCMChannel.h"
#include "BCMDisplay.h"

BCMGroupDisplay::BCMGroupDisplay(BCMRoom *pRoom)
{
    m_pRoom = pRoom;
    m_pGroupDisplayWidget = NULL;
    m_nDisplayMode = 0;
    m_nUseVirArray = 0;
}

BCMGroupDisplay::~BCMGroupDisplay()
{
    // 清空屏幕链表
    while ( !m_lstDisplay.isEmpty() )
        delete m_lstDisplay.takeFirst();
}

void BCMGroupDisplay::AddDisplay(BCMDisplay *pDisplay)
{
    if (NULL == pDisplay)
        return;

    m_lstDisplay.append( pDisplay );
}

bool BCMGroupDisplay::IsSimpleDevice()
{
    return (bool)m_nDisplayMode;
}

BCMDisplay *BCMGroupDisplay::GetDisplay(int id)
{
    for (int i = 0; i < m_lstDisplay.count(); i++) {
        BCMDisplay *pDisplay = m_lstDisplay.at( i );
        if (pDisplay->GetDisplayID() == id)
            return pDisplay;
    }

    return NULL;
}

