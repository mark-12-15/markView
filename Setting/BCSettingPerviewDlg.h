#ifndef BCSettingPerviewDlg_H
#define BCSettingPerviewDlg_H

#include <QDialog>
#include <QDomNodeList>
#include <QMap>

namespace Ui {
class BCSettingPerviewDlg;
}

class QTreeWidgetItem;
class BCSettingPerviewDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingPerviewDlg(QWidget *parent = 0);
    ~BCSettingPerviewDlg();

private slots:
    void onCurrentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

    void on_removeBut_clicked();

    void on_addBut_clicked();

    void on_m_pModifyBtn_clicked();

    void on_m_pResetDefaultMainToolBarBtn_clicked();

    void onItemChanged(QTreeWidgetItem *item, int column);

    void on_m_pModifyPerviewBtn_clicked();

private:
    Ui::BCSettingPerviewDlg *ui;

    void Init();
    bool GetDomNode(const QDomNodeList &lst, const QString &qsNodeName, QDomNode &node);

    void RefreshTreeWidget(int userid, int level);
    void updateParentItem(QTreeWidgetItem* item);
    void updateChildItem(QTreeWidgetItem* item, int checkState);

    // 链表中存储3种权限默认可控制的按钮
    QList<int>  m_lstManagerID;
    QList<int>  m_lstOperatorID;
    QList<int>  m_lstUserID;

    // 记录级别和级别名称的关系
    QMap<int, QString> m_map;
};

#endif // BCSettingPerviewDlg_H
