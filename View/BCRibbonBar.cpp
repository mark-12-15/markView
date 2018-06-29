#include "BCRibbonBar.h"

BCRibbonBar::BCRibbonBar()
{
    this->showQuickAccess( false );
    this->setKeyTipsEnable( false );
    this->setKeyTipsComplement( false );
}

#include <QContextMenuEvent>
void BCRibbonBar::contextMenuEvent(QContextMenuEvent* event)
{
    event->ignore();
}
