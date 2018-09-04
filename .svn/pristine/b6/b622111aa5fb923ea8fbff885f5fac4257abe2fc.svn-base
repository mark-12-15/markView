#include "BCTreeData.h"
#include <QString>
#include <QDebug>

BCTreeData::BCTreeData(QObject *parent)
    :QObject(parent)
{
    m_publicIconMap[QStringLiteral("PC_Project")] = QIcon(QStringLiteral(":/Image/PC.png"));
    m_publicIconMap[QStringLiteral("HD_Project")] = QIcon(QStringLiteral(":/Image/HD.png"));
    m_publicIconMap[QStringLiteral("VIDEO_Project")] = QIcon(QStringLiteral(":/Image/VIDEO.png"));
    m_publicIconMap[QStringLiteral("AUDIO_Project")] = QIcon(QStringLiteral(":/Image/AUDIO.png"));
    m_publicIconMap[QStringLiteral("DVI_Project")] = QIcon(QStringLiteral(":/Image/DVI.png"));
    m_publicIconMap[QStringLiteral("VGA_Project")] = QIcon(QStringLiteral(":/Image/VGA.png"));
    m_publicIconMap[QStringLiteral("IPV_Project")] = QIcon(QStringLiteral(":/Image/IPV.png"));

}

QList<QTreeWidgetItem *> BCTreeData::GetList(){
    return this->m_rootList;
}

void BCTreeData::Init(int index){
    m_rootList.clear();
    QTreeWidgetItem *imageItemRoot1 = new QTreeWidgetItem;   //添加第一个父节点
    imageItemRoot1->setFlags(imageItemRoot1->flags()|Qt::ItemIsEditable);//可编辑

    imageItemRoot1->setText(0,tr("PC"));
    imageItemRoot1->setIcon(0,m_publicIconMap[QStringLiteral("PC_Project")]);
    m_rootList.append(imageItemRoot1);

    if(index != VIDEO){
        QTreeWidgetItem *imageItemChlid1_1 = new QTreeWidgetItem(); //添加子节点
        imageItemChlid1_1->setFlags(imageItemChlid1_1->flags()|Qt::ItemIsEditable);
        imageItemChlid1_1->setText(0,tr("音频"));
        imageItemChlid1_1->setIcon(0,m_publicIconMap[QStringLiteral("AUDIO_Project")]);
        imageItemRoot1->addChild(imageItemChlid1_1);
    }

    if(index != AUDIO){
        QTreeWidgetItem *imageItemChlid1_2 = new QTreeWidgetItem(); //添加子节点
        imageItemChlid1_2->setFlags(imageItemChlid1_2->flags()|Qt::ItemIsEditable);
        imageItemChlid1_2->setText(0,tr("视频"));
        imageItemChlid1_2->setIcon(0,m_publicIconMap[QStringLiteral("VGA_Project")]);
        imageItemRoot1->addChild(imageItemChlid1_2);
    }


    QTreeWidgetItem *imageItemRoot2 = new QTreeWidgetItem;   //添加第二个父节点
    imageItemRoot2->setFlags(imageItemRoot2->flags()|Qt::ItemIsEditable);
    imageItemRoot2->setText(0,tr("HD"));
    imageItemRoot2->setIcon(0,m_publicIconMap[QStringLiteral("HD_Project")]);
    m_rootList.append(imageItemRoot2);

    if(index != VIDEO){
        QTreeWidgetItem *imageItemChlid2_1 = new QTreeWidgetItem(); //添加子节点
        imageItemChlid2_1->setFlags(imageItemChlid2_1->flags()|Qt::ItemIsEditable);
        imageItemChlid2_1->setText(0,tr("音频"));
        imageItemChlid2_1->setIcon(0,m_publicIconMap[QStringLiteral("AUDIO_Project")]);
        imageItemRoot2->addChild(imageItemChlid2_1);
    }

    if(index != AUDIO){
        QTreeWidgetItem *imageItemChlid2_2 = new QTreeWidgetItem(); //添加子节点
        imageItemChlid2_2->setFlags(imageItemChlid2_2->flags()|Qt::ItemIsEditable);
        imageItemChlid2_2->setText(0,tr("视频"));
        imageItemChlid2_2->setIcon(0,m_publicIconMap[QStringLiteral("DVI_Project")]);
        imageItemRoot2->addChild(imageItemChlid2_2);
    }

}

void BCTreeData::DeviceInit(const int index){
    m_rootList.clear();
    for(int i = 0 ;i < index; i++){
        QTreeWidgetItem *imageItemRoot1 = new QTreeWidgetItem;   //添加第一个父节点
        QString str = tr("通道")+QString("%1").arg(i);
        imageItemRoot1->setText(0,str);
        m_rootList.append(imageItemRoot1);
    }
}

void BCTreeData::ScreenInit(){
    m_rootList.clear();
    for(int i = 0 ;i < 4; i++){
        QTreeWidgetItem *imageItemRoot1 = new QTreeWidgetItem;   //添加第一个父节点
        QString str = tr("高鼎通")+QString("%1").arg(i);
        imageItemRoot1->setText(0,str);
        m_rootList.append(imageItemRoot1);
    }
}
