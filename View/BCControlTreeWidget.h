/*********************************************************************************************************************************
* 作    者：liyz
* 摘    要：物理输入通道widget
*********************************************************************************************************************************/
#ifndef BCControlTreeWidget_H
#define BCControlTreeWidget_H

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QDomElement>

class BCMChannel;
class BCControl;
class BCControlTreeWidgetItem;
class BCControlTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit BCControlTreeWidget(QWidget *parent = 0);
    ~BCControlTreeWidget();

    // 刷新链表，0：电脑，1：Vedio，2：高清
    void Refresh(int type, const QList<BCMChannel*> &lstChannels, BCControl *parent);

    // 高亮输入通道
    void HighLightInputChannel(BCMChannel *pChannel);

    // 刷新tooptip和icon
    void RefreshToopTip();

    // 刷新入口信号源的名称
    void RefreshInputChannelName();

    BCMChannel *GetCurrentChannel();

private:
    void dragEnterEvent(QDragEnterEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseDoubleClickEvent(QMouseEvent *);
    void contextMenuEvent(QContextMenuEvent* event);

    void ModifyChannelName(BCControlTreeWidgetItem *pCurrentItem);
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
#endif // BCControlTreeWidget_H
