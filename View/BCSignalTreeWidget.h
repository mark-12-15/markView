/*********************************************************************************************************************************
* 作    者：liyz
* 摘    要：自定义输入通道TreeWidget
*********************************************************************************************************************************/
#ifndef BCSIGNALTREEWIDGET_H
#define BCSIGNALTREEWIDGET_H

#include <QTreeWidget>

class BCMGroupChannel;
class BCMChannel;
class BCSignalTreeWidgetItem : public QTreeWidgetItem
{
public:
    BCSignalTreeWidgetItem(BCMGroupChannel *pGroupChannel, QTreeWidget *parent);
    BCSignalTreeWidgetItem(BCMChannel *pChannel, QTreeWidgetItem *parent);

    // type=0刷新组名称,1刷新信号名称
    void RefreshName(int type = 0);

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

// ----------------------------------------------------------------------------------------------------------------------------------------

class BCSignalTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit BCSignalTreeWidget(QWidget *parent = 0);
    ~BCSignalTreeWidget();

    void Refresh();

    void RefreshInputChannelName();

private:
    void dragEnterEvent(QDragEnterEvent* event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseDoubleClickEvent(QMouseEvent *);
    void contextMenuEvent(QContextMenuEvent* event);

    void ModifyChannelName(BCSignalTreeWidgetItem *pCurrentItem);
    void SetIPVConfig(BCMChannel *pChannel);
    void SetSubTitles(BCMChannel *pChannel);                    // 设置字幕
    void OpenSubTitles(BCMChannel *pChannel);                    // 设置字幕
    void CloseSubTitles(BCMChannel *pChannel);                    // 设置字幕
    void SetInputChannelType(BCMChannel *pChannel, int type);   // 设置输入通道类型
    void SetCutArea(BCMChannel *pChannel);
    void ModifyChannelEDID(BCMChannel *pChannel);

    // 判断输入信号是否是联控矩阵使用的信号
    bool IsJointMatrixChannel(int chid);
};

#endif // BCSIGNALTREEWIDGET_H
