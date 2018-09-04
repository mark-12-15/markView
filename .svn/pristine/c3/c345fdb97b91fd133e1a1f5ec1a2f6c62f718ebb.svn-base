#include "BCMDisplay.h"
#include "BCMGroupDisplay.h"
#include "../Common/BCLocalServer.h"
#include "BCMRoom.h"

BCMDisplay::BCMDisplay(BCMGroupDisplay *pGroupDisplay)
{
    m_pGroupDisplay = pGroupDisplay;
    m_nSegmentation = 1;
}

BCMDisplay::~BCMDisplay()
{

}

void BCMDisplay::SetSwitchOn(int i, bool bSendCmd)
{
    switchStatus = i;

    if ( !bSendCmd )
        return;

    if (NULL == m_pGroupDisplay)
        return;

    // 修改数据库
    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->UpdateDisplayBaseInfo(m_pGroupDisplay->GetGroupDisplayID(), m_id, m_name, switchStatus, switchoncmd, switchoffcmd);

    QString cmd = QString::null;
    QStringList lstCmd = (1 == switchStatus) ? switchoncmd.split(" ") : switchoffcmd.split(" ");
    for (int i = 0; i < lstCmd.count(); i++) {
        QString singleCmd = lstCmd.at( i );
        cmd.append(QChar(singleCmd.toInt(NULL, 16)));
    }

    if ( !cmd.isEmpty() ) {
        m_pGroupDisplay->GetRoom()->SendCmd( cmd );
    }
}

void BCMDisplay::SetSwitchOnCmd(const QString &cmd, bool bSendCmd)
{
    switchoncmd = cmd;

    if ( !bSendCmd )
        return;

    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->UpdateDisplayBaseInfo(m_pGroupDisplay->GetGroupDisplayID(), m_id, m_name, switchStatus, switchoncmd, switchoffcmd);
}

void BCMDisplay::SetSwitchOffCmd(const QString &cmd, bool bSendCmd)
{
    switchoffcmd = cmd;

    if ( !bSendCmd )
        return;

    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->UpdateDisplayBaseInfo(m_pGroupDisplay->GetGroupDisplayID(), m_id, m_name, switchStatus, switchoncmd, switchoncmd);
}

void BCMDisplay::SetDisplayName(const QString &qs, bool bSendCmd)
{
    m_name = qs;

    if ( !bSendCmd )
        return;

    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->UpdateDisplayBaseInfo(m_pGroupDisplay->GetGroupDisplayID(), m_id, m_name, switchStatus, switchoncmd, switchoffcmd);
}
