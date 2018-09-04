#ifndef BCSIGNALTREEWIDGETITEM_H
#define BCSIGNALTREEWIDGETITEM_H

#include <QTreeWidgetItem>

class BCMGroupChannel;
class BCMChannel;
class BCSignalTreeWidgetItem : public QTreeWidgetItem
{
public:
    BCSignalTreeWidgetItem(BCMGroupChannel *pGroupChannel, QTreeWidget *parent);
    BCSignalTreeWidgetItem(BCMChannel *pChannel, QTreeWidgetItem *parent);

    bool IsChannel();

    BCMChannel *GetChannel();
    BCMGroupChannel *GetGroupChannel();

private:
    BCMGroupChannel *m_pGroupChannel;
    BCMChannel *m_pChannel;
};

inline BCMChannel *BCSignalTreeWidgetItem::GetChannel()
{
    return m_pChannel;
}

inline BCMGroupChannel *BCSignalTreeWidgetItem::GetGroupChannel()
{
    return m_pGroupChannel;
}

#endif // BCSIGNALTREEWIDGETITEM_H
