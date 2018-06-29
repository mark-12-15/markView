/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：字幕场景数据类
*********************************************************************************************************************************/
#ifndef BCMSUBTITLESSCENE_H
#define BCMSUBTITLESSCENE_H

#include <QString>
#include <QColor>
#include <QPoint>

// 字幕场景数据类
class BCMSubTitlesSceneData
{
public:
    BCMSubTitlesSceneData() {
        m_qsText        = QString("Welcome");
        m_qsFamilyName  = QString("微软雅黑");
        m_nSize         = 12;
        m_color         = QColor(0, 0, 255);
        m_pos           = QPoint(0, 0);
        m_nVisible      = 0;
    }

    QString m_qsText;       // 字幕文本
    QString m_qsFamilyName; // 字幕字体
    int     m_nSize;        // 字幕字号
    QColor  m_color;        // 字幕颜色
    QPoint  m_pos;          // 字幕位置，分水平和垂直
    int     m_nVisible;     // 是否显示
};

class BCMSubTitlesScene
{
public:
    BCMSubTitlesScene();
};

#endif // BCMSUBTITLESSCENE_H
