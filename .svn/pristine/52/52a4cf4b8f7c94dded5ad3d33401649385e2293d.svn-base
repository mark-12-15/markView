#ifndef BCSettingTaskPlanningDlg_H
#define BCSettingTaskPlanningDlg_H

#include <QDialog>

namespace Ui {
class BCSettingTaskPlanningDlg;
}

class sTaskPlanning;
class BCSettingTaskPlanningDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingTaskPlanningDlg(QWidget *parent = 0);
    ~BCSettingTaskPlanningDlg();

    void AddTask(int taskType, QString time, QString cycle, int roomid, int sceneid);
    void ModifyTask(int id, int taskType, QString time, QString cycle, int roomid, int sceneid);

private slots:
    void on_m_pAddBtn_clicked();
    void on_m_pModifyBtn_clicked();
    void on_m_pRemoveBtn_clicked();
    void on_m_pClearBtn_clicked();

private:
    Ui::BCSettingTaskPlanningDlg *ui;

    void Refresh();

    QList<sTaskPlanning> m_lstTask;
};

#endif // BCSettingTaskPlanningDlg_H
