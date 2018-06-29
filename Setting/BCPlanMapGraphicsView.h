/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：预案地图显示地图的GraphicsView
*********************************************************************************************************************************/
#ifndef BCPLANMAPGRAPHICSVIEW_H
#define BCPLANMAPGRAPHICSVIEW_H

#include <QGraphicsView>

class BCPlanMapGraphicsRectItem;
class BCPlanMapGraphicsView : public QGraphicsView
{
public:
    BCPlanMapGraphicsView(QWidget *parent = 0);
    ~BCPlanMapGraphicsView();

    void AddPlanMap(const QString &path);
    void ClearPlanMap();

    void ZoomIn();
    void ZoomOut();
    void ZoomFitBest();
    void ZoomOriginal();

private:
    void resizeEvent(QResizeEvent *e);

    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    /* 返回光标类型
     * 0:什么都没选中
     * 1:选中自定义按钮
     * 2:选中地图
     */
    bool IsPlanMapButton(QPointF pt);

private:
    BCPlanMapGraphicsRectItem *m_pGraphicsManager;
    QGraphicsPixmapItem *m_pPixmapItem;

    double  m_dScale;       // 缩放倍数
    double  m_dScaleStep;   // 缩放步长

    QSize   m_sizeView;     // 当前先是窗体的尺寸
    QString m_qsMapPath;    // 地图路径

    int     m_nPressType;   // 0没点击，1点击按钮，2点击地图
    QPoint  m_ptStart;      // 鼠标点击起始点
};

#endif // BCPLANMAPGRAPHICSVIEW_H
