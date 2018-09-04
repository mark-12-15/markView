#ifndef BCMONITORWIDGETIDATA_H
#define BCMONITORWIDGETIDATA_H

#include <QListWidget>
#include <QTime>

class BCMonitorWidget : public QListWidget
{
    Q_OBJECT

public:
    explicit BCMonitorWidget(QWidget *parent = 0);
    ~BCMonitorWidget();

    // 刷新内部数据
    void Refresh();

    // 打开全部回显
    void SetPreviewVisible(bool b);

    // 刷新回显状态
    void RefreshEchoStatus(bool bTempCloseEcho);

private slots:
    void onActionTriggered(int value);
    void onRefreshVedioStatus();

private:
    void resizeEvent(QResizeEvent *);
    QTime       beginTime;          // 记录滚动轴时间
};

namespace Ui {
class BCMonitorWidgetData;
}

class BCMChannel;
class BCMonitorWidgetData : public QWidget
{
    Q_OBJECT

public:
    explicit BCMonitorWidgetData(int index, int chid, int chType, const QString &name, BCMonitorWidget *pPreviewWidget);
    ~BCMonitorWidgetData();

    void SetEcho(bool);

    // 刷新回显状态
    void RefreshEchoStatus(bool bTempCloseEcho);
    int m_nChannelID;       // 通道ID
    int m_nChannelType;     // 通道type

private:
    Ui::BCMonitorWidgetData *ui;

    void dropEvent(QDropEvent*);
    void dragEnterEvent(QDragEnterEvent*);
    void mousePressEvent(QMouseEvent*);
    void contextMenuEvent(QContextMenuEvent* event);

    void RefreshName();

    bool m_bTempCloseEcho;  // 是否临时关闭
    bool m_bPlaying;        // 是否正在播放

    BCMonitorWidget *m_pPreviewWidget;
};

#endif // BCMONITORWIDGETIDATA_H
