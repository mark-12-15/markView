#ifndef BCSETTINGIPVSIGNALWINDOWLOOPCONFIGDLG_H
#define BCSETTINGIPVSIGNALWINDOWLOOPCONFIGDLG_H

#include <QDialog>
#include <QDomElement>

namespace Ui {
class BCSettingIPVSignalWindowLoopConfigDlg;
}

class QTreeWidgetItem;
class BCIPTreeWidgetItem;
class BCSignalWindowDisplayWidget;
class BCSettingIPVSignalWindowLoopConfigDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingIPVSignalWindowLoopConfigDlg(BCSignalWindowDisplayWidget *parent = 0);
    ~BCSettingIPVSignalWindowLoopConfigDlg();

private slots:
    void onItemChanged(QTreeWidgetItem *item, int column);

    void on_m_pCancelBtn_clicked();

    void on_m_pOKBtn_clicked();

private:
    Ui::BCSettingIPVSignalWindowLoopConfigDlg *ui;

    void Refresh();
    void AddNode(QDomElement &ele, QTreeWidgetItem *pItem);
    void AddNode(BCIPTreeWidgetItem *pItem, QStringList &lstIPInfo);

    void updateParentItem(QTreeWidgetItem* item);
    void updateChildItem(QTreeWidgetItem* item, int checkState);

    BCSignalWindowDisplayWidget *m_parent;
};

#endif // BCSETTINGIPVSIGNALWINDOWLOOPCONFIGDLG_H
