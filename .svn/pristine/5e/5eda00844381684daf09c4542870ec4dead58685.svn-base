#ifndef BCSETTINGLEDRESOLUTIONDLG_H
#define BCSETTINGLEDRESOLUTIONDLG_H

#include <QDialog>
#include <QGraphicsView>

class BCSettingLEDResolutionDlg;
class BCSettingLEDResolutionView : public QGraphicsView
{
    Q_OBJECT

public:
    BCSettingLEDResolutionView(QWidget *parent=NULL);
    ~BCSettingLEDResolutionView();

    void Init(BCSettingLEDResolutionDlg *pDlg);

    // 框选设置单屏的分辨率
    void SetSingleDisplayResolutionX(int x);
    void SetSingleDisplayResolutionY(int y);

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
    BCSettingLEDResolutionDlg *m_pDlg;
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
class BCSettingLEDResolutionDlg;
}

class BCMRoom;
class BCSettingLEDResolutionDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingLEDResolutionDlg(BCMRoom *pRoom, QWidget *parent = 0);
    ~BCSettingLEDResolutionDlg();

    void SetCommandProgressValue(int value);

    BCMRoom *m_pRoom;

private slots:
    void on_m_pBatchApplyBtn_clicked();

    void on_m_pSendCmdBtn_clicked();

    void on_m_pCancelBtn_clicked();

    void on_m_pSingleXLineEdit_textChanged(const QString &arg1);

    void on_m_pSingleYLineEdit_textChanged(const QString &arg1);

    void on_m_pBatchSetBtn_clicked();

private:
    Ui::BCSettingLEDResolutionDlg *ui;
};

#endif // BCSETTINGLEDRESOLUTIONDLG_H
