/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：快速开窗View
*********************************************************************************************************************************/
#ifndef BCLocationGroupWidget_H
#define BCLocationGroupWidget_H

#include <QWidget>
#include <QLabel>
#include <QGroupBox>
#include "BCGridView.h"

class QVBoxLayout;
class BCLocationDlg;
class BCGroupDisplayWidget;
class BCSignalWindowDisplayWidget;
class BCLocationGroupWidget : public QWidget
{
public:
    BCLocationGroupWidget(QWidget * parent = 0);
    ~BCLocationGroupWidget();

    void SetLocationDlg(BCLocationDlg *pDlg);

    // 刷新默认屏组及信号窗
    void Refresh(BCGroupDisplayWidget *pSceneGroup, BCSignalWindowDisplayWidget *pSignalWindow);

    void HighLight(QPoint pt);
    void ClearHighLight();

    // 返回单屏定位的矩形百分比位置(0, 50, 50, 50)
    QRectF GetSingleDisplayRelationRect();

protected:
    void HighLight(QRect rect);

    void ClearItems();

    // 鼠标事件选中单个显示器
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

protected:
    BCLocationDlg   *m_pLocationDlg;    // 快速定位对话框

    QVBoxLayout *m_pMainLayout;

    bool m_bPress;
    double m_x;
    double m_y;

    QRectF m_rect;    // 关联的屏组的相对位置

    BCGroupDisplayWidget        *m_pGroupDisplayWidget; // 快速开窗对应的屏组
    BCSignalWindowDisplayWidget *m_pSignalWindowWidget; // 快速开窗对应的信号窗
};

inline void BCLocationGroupWidget::SetLocationDlg(BCLocationDlg *pDlg)
{
    m_pLocationDlg = pDlg;
}

#endif // BCLocationGroupWidget_H
