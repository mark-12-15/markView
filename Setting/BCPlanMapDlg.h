/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：预案地图对话框类
*********************************************************************************************************************************/
#ifndef BCPLANMAPDLG_H
#define BCPLANMAPDLG_H

#include <QDialog>

namespace Ui {
class BCPlanMapDlg;
}

class QGraphicsPixmapItem;
class BCPlanMapGraphicsRectItem;
class BCPlanMapButtonGraphicsItem;
class BCPlanMapDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCPlanMapDlg(QWidget *parent = 0);
    ~BCPlanMapDlg();

    void AddButton(BCPlanMapButtonGraphicsItem *pButton);

private slots:
    void on_pCancel_clicked();
    void on_pSelectMap_clicked();
    void on_pBtnZoomOut_clicked();
    void on_pBtnZoomIn_clicked();
    void on_pBtnZoomFitBest_clicked();
    void on_pBtnZoomOriginal_clicked();
    void on_pClearMap_clicked();

private:
    void init();            // 初始化对话框
    QStringList loadSystemPlan();  // 加载系统预案

private:
    Ui::BCPlanMapDlg *ui;
};

#endif // BCPLANMAPDLG_H
