#ifndef BCSettingTaskDetailDlg_H
#define BCSettingTaskDetailDlg_H

#include <QPushButton>
#include <QDialog>

// 重写日期按钮
class BCDateButton : public QPushButton
{
    Q_OBJECT
public:
    BCDateButton(QWidget *parent = NULL);

    void SetSelected(bool b);

    bool m_bSelected;

private slots:
    void onClicked();
};

namespace Ui {
class BCSettingTaskDetailDlg;
}

class BCSettingTaskPlanningDlg;
class BCSettingTaskDetailDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingTaskDetailDlg(int type, BCSettingTaskPlanningDlg *parent = 0, int id = -1, int taskType = 0, QString time = "00:00", QString cycle = "", int roomid = -1, int sceneid = -1);
    ~BCSettingTaskDetailDlg();

private slots:
    void on_m_pTaskTypeCombBox_currentIndexChanged(int index);

    void on_m_pCancelBtn_clicked();

    void on_m_pOKBtn_clicked();

private:
    Ui::BCSettingTaskDetailDlg *ui;

    BCSettingTaskPlanningDlg *m_parent;
    int m_type; // 0新建，1修改
    int m_id;   // 修改时使用
};

#endif // BCSettingTaskDetailDlg_H
