/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：数据源窗口内的解码器输入内的TreeWidget，因为要实现拖拽操作，所以重写TreeWidget类
*********************************************************************************************************************************/
#ifndef BCDECODERTREEWIDGET_H
#define BCDECODERTREEWIDGET_H

#include <QTreeWidget>
#include <QDomElement>
#include "BCDecoder.h"

// 自定义QTreeWidgetItem
class BCDecoderTreeWidgetItem : public QTreeWidgetItem
{
public:
    BCDecoderTreeWidgetItem(const QString &name, const QString &ip, const QString &decoder, const QString &resolution, int nLevel, QTreeWidget *parent);
    BCDecoderTreeWidgetItem(const QString &name, const QString &ip, const QString &decoder, const QString &resolution, int nLevel, QTreeWidgetItem *parent);
    ~BCDecoderTreeWidgetItem();

    void SetAttribute(const QString &name, const QString &ip, const QString &decoder, const QString &resolution);

    QString m_qsName;
    QString m_qsIP;
    QString m_qsDecoder;
    QString m_qsResolution;
    int     m_nLevel;
};

class BCDecoderTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    BCDecoderTreeWidget(QWidget *parent = NULL);

    QString GetName(QString url);

    // 根据xml刷新数据
    void Refresh();

    // 过滤
    void Filter(const QString &text);

    QList<sIPInfo> m_lstCameraIP;       // 摄像头IP列表

private:
    //void dragEnterEvent(QDragEnterEvent*);
    void mousePressEvent(QMouseEvent*);
    void contextMenuEvent(QContextMenuEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *);

    // 右键菜单
    void AddIPVedioNode(int type, QTreeWidgetItem *pItem);
    void DelIPVedioNode(QTreeWidgetItem *pItem);
    void ModifyIPVedioNode(QTreeWidgetItem *pItem);
    void MoveIPVedioNode(int type, QTreeWidgetItem *pItem); // type表示移动类型，0:向上,1:向下,2:置顶,3:置底

    // 根据xml刷新数据时使用
    void AddNode(QDomElement &ele, QTreeWidgetItem *pItem);

    // 过滤
    void Filter(QTreeWidgetItem *pItem, const QString &text);
    void SetParentNoHidden(QTreeWidgetItem *pItem); // 设置父节点显示

    // 更新xml内容
    void UpdateXmlContent();
    void AddNode(QDomDocument &doc, QDomElement &parent, QTreeWidgetItem *pItem);
};

#endif // BCDECODERTREEWIDGET_H
