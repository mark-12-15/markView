/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：设置设备规模时弹出的LED设置界面，屏幕显示放到类中作为提升类
*********************************************************************************************************************************/
#ifndef BCSETTINGDEVICEFORMATLEDDLG_H
#define BCSETTINGDEVICEFORMATLEDDLG_H

#include <QDialog>
#include <QGraphicsView>

class BCSettingDeviceFormatLEDDlg;
class BCSettingDeviceFormatLEDView : public QGraphicsView
{
    Q_OBJECT

public:
    BCSettingDeviceFormatLEDView(QWidget *parent=NULL);
    ~BCSettingDeviceFormatLEDView();

    void Init(int id, int arrX, int arrY, BCSettingDeviceFormatLEDDlg *pDlg);

    // 框选设置单屏的分辨率
    void SetSingleDisplayResolution(int x, int y);

    // 批量设置单屏的分辨率
    void SetBatchDisplayResolution(int stanX, int stanY, int noStanX, int noStanY, int noStanPos);

    // 判断屏幕是否有效，判断依据是所有屏幕都设置了有效分辨率
    bool IsGroupDisplayValid();

    // 根据屏幕设置下发指令
    void SendCommand();

protected:
    // 向下依次传递resize命令
    void resizeEvent(QResizeEvent * event);

    // 鼠标事件选中单个显示器
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    void HighLight(QPoint pt);
    void HighLight(QRect rect);
    void ClearHighLight();

private:
    BCSettingDeviceFormatLEDDlg *m_pDlg;
    QGraphicsScene *m_pScene;

    bool m_bPress;
    double m_x;
    double m_y;

    QRectF m_rect;    // 关联的屏组的相对位置

    int m_arrX;
    int m_arrY;

    int m_id;
};

// -------------------------------------------------------------------------------------------------------

namespace Ui {
class BCSettingDeviceFormatLEDDlg;
}

class BCSettingDeviceFormatDlg;
class BCSettingDeviceFormatLEDDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingDeviceFormatLEDDlg(int id, int row, int col, BCSettingDeviceFormatDlg *parent = 0);
    ~BCSettingDeviceFormatLEDDlg();

    void SetCommandProgressValue(int value);

    BCSettingDeviceFormatDlg *m_pFormatDlg;

private slots:
    void on_m_pSingleApplyBtn_clicked();

    void on_m_pBatchApplyBtn_clicked();

    void on_m_pSendCmdBtn_clicked();

    void on_m_pCancelBtn_clicked();

private:
    Ui::BCSettingDeviceFormatLEDDlg *ui;
};

#endif // BCSETTINGDEVICEFORMATLEDDLG_H
