/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：对IPV编辑的对话框，重载构造函数，分别构造添加和修改两种对话框
*********************************************************************************************************************************/
#ifndef BCSETTINGADDIPVEDIOTREEWIDGETITEMDLG_H
#define BCSETTINGADDIPVEDIOTREEWIDGETITEMDLG_H

#include <QDialog>

namespace Ui {
class BCSettingAddIPVedioTreeWidgetItemDlg;
}

class BCSettingAddIPVedioTreeWidgetItemDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingAddIPVedioTreeWidgetItemDlg(int type, QWidget *parent = 0);
    explicit BCSettingAddIPVedioTreeWidgetItemDlg(const QString &name, const QString &url, const QString &decoder, const QString &resolution, QWidget *parent = 0);
    ~BCSettingAddIPVedioTreeWidgetItemDlg();

    int     m_nPos; // 如果是根节点则字段无用，不是根节点则0表示同级节点，1表示子节点
    QString m_qsName;
    QString m_qsURL;
    QString m_qsDecoder;
    QString m_qsResolution;

private slots:
    void on_m_pOKBtn_clicked();

    void on_m_pCancelBtn_clicked();

private:
    Ui::BCSettingAddIPVedioTreeWidgetItemDlg *ui;

    int m_nType;    // 节点位置，0：根节点，1：子节点或者是同级节点
};

#endif // BCSETTINGADDIPVEDIOTREEWIDGETITEMDLG_H
