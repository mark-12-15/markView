/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：物理输入通道链表，分文字和视频两种显示模式，该类为显示视频的控件
*********************************************************************************************************************************/
#ifndef BCSIGNALLISTWIDGETDATA_H
#define BCSIGNALLISTWIDGETDATA_H

#include <QWidget>

namespace Ui {
class BCSignalListWidgetData;
}

class BCControl;
class BCSignal;
class BCMChannel;
class BCSignalListWidgetData : public QWidget
{
    Q_OBJECT

public:
    explicit BCSignalListWidgetData(BCMChannel *pChannel, BCControl *parent = 0);
    explicit BCSignalListWidgetData(BCMChannel *pChannel, BCSignal *parent = 0);
    ~BCSignalListWidgetData();

    void SetEcho(bool);

    void RefreshInputChannelName();

//signals:
//    void signal_data(BCMChannel*);

private:
    Ui::BCSignalListWidgetData *ui;

    void dragEnterEvent(QDragEnterEvent*);
    void mousePressEvent(QMouseEvent*);

    //数据成员变量
    BCMChannel* m_pChannel;
    HWND m_hd;

    BCControl *m_pInputChannelWidget;
    BCSignal *m_pGroupInputChannelWidget;
};

#endif // BCSIGNALLISTWIDGETDATA_H
