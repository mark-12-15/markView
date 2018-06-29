#ifndef BCRIBBONBAR_H
#define BCRIBBONBAR_H

#include "QtnRibbonBar.h"

class BCRibbonBar : public RibbonBar
{
public:
    BCRibbonBar();

protected:
    virtual void contextMenuEvent(QContextMenuEvent* event);
};

#endif // BCRIBBONBAR_H
