/*********************************************************************************************************************************
* 作    者：liyuzhe
* 时    间：2016.5.7
* 功    能：treewidget的数据类
*********************************************************************************************************************************/

#ifndef BCTREEDATA_H
#define BCTREEDATA_H

#include <QList>
#include <QTreeWidgetItem>

enum AU_AI{
    //0：全显示 1：音频  2：视频
    ALL = 0,
    AUDIO,
    VIDEO,
};

class BCTreeData : public QObject
{
    Q_OBJECT
public:
    explicit BCTreeData(QObject *parent = 0);
    QList<QTreeWidgetItem *> GetList();
    void Init(int index);
    void DeviceInit(const int index);
    void ScreenInit();

private:
    QList<QTreeWidgetItem *> m_rootList;
    QMap<QString,QIcon> m_publicIconMap;
};

#endif // BCTREEDATA_H
