/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：数据源窗口内的解码器输入，实则为IPVedio的输入链表，提供选择文件、筛选、拖拽信号的功能
*********************************************************************************************************************************/
#ifndef BCDECODER_H
#define BCDECODER_H

#include <QWidget>
#include "BCWidgetBtn.h"

namespace Ui {
class BCDecoder;
}

struct sIPInfo {
    QString name;
    QString url;
    QString resolution;
    QString decoder;
};

class BCIPVNode;
class BCWidgetBtn;
class QTreeWidgetItem;
class BCDecoder : public QWidget
{
    Q_OBJECT

public:
    explicit BCDecoder(bool bVisible, int minHeight, QWidget *parent = 0);
    ~BCDecoder();

    QString GetName(QString url);

    // 是否隐藏内容
    bool IsVisible();

    int m_minHeight;

    // 摄像头IP列表
    const QList<sIPInfo> &GetIPList();

private slots:
    void onSetVisible(bool);

    void on_m_pSelectFileBtn_clicked();
    void on_m_pFilterLineEdit_textChanged(const QString &arg1);

    void on_m_pExportBtn_clicked();

private:
    Ui::BCDecoder *ui;

    void ReadTextFile(const QString &path, BCIPVNode *pRootNode);
    void ReadExcelFile(const QString &path, BCIPVNode *pRootNode);

    void UpdateXmlContent(BCIPVNode *pNode);
    void AddNode(QDomDocument &doc, QDomElement &parent, BCIPVNode *pNode);

    void WriteTextFile(QTreeWidgetItem *pItem, QTextStream &in);
    bool IsExistNextNode(QTreeWidgetItem *pItem);

    bool event(QEvent *event);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

    bool m_bModifyHeight;       // 是否修改高度，悬停到最下面时值为true
    bool m_bPress;

    BCWidgetBtn* m_pHeaderBtn;
};

#endif // BCDECODER_H
