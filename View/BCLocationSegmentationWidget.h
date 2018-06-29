/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：快速开窗分割的widget
*********************************************************************************************************************************/
#ifndef BCLOCATIONSEGMENTATIONWIDGET_H
#define BCLOCATIONSEGMENTATIONWIDGET_H

#include <QWidget>

class QVBoxLayout;
class BCLocationDlg;
class BCLocationSegmentationWidget : public QWidget
{
public:
    BCLocationSegmentationWidget(QWidget *parent);

    void SetLocationDlg(BCLocationDlg *pDlg);

    // 根据行、列重构快速定位的Widget
    void ReBuildLocationWidget(int r, int c);

    // 刷新分割的高亮状态，默认为清空高亮
    void RefreshHight(QRect rect = QRect(0,0,0,0));
    void RefreshHight(QPoint pt);

    void ClearHighLight();

    // 返回高亮的矩形
    QRectF GetHightRect();

private:
    // 鼠标事件选中单个显示器
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    // 清空快速定位的Widget
    void ClearLocationWidget();

private:
    QVBoxLayout     *m_pMainLayout;
    BCLocationDlg   *m_pLocationDlg;    // 快速定位对话框

    bool    m_bPress;   // 鼠标是否点击，左键生效
    QPoint  m_beginPt;  // 鼠标点击的起始点
    int     m_nRowCount;// 行数
    int     m_nColCount;// 列数
};

inline void BCLocationSegmentationWidget::SetLocationDlg(BCLocationDlg *pDlg)
{
    m_pLocationDlg = pDlg;
}

#endif // BCLOCATIONSEGMENTATIONWIDGET_H
