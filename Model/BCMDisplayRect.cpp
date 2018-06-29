#include "BCMDisplayRect.h"
#include "BCMDisplay.h"
BCMDisplayRect::BCMDisplayRect(BCMDisplay *pDisplay, const QString &id)
{
    m_pDisplay = pDisplay;
    m_id = id;
}
