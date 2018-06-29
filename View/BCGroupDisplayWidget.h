#ifndef BCGROUPDISPLAYWIDGET_H
#define BCGROUPDISPLAYWIDGET_H

#include <QWidget>

class BCRoomMainWidget;
class BCMGroupDisplay;
class BCSingleDisplayWidget;
class BCGroupDisplayWidget : public QWidget
{
    Q_OBJECT
public:
    BCGroupDisplayWidget(BCMGroupDisplay *pMGroupDisplay, BCRoomMainWidget *parent = 0);
    ~BCGroupDisplayWidget();

    BCMGroupDisplay *GetMGroupDisplay();
    BCRoomMainWidget *GetRoomWidget();

    const QList<BCSingleDisplayWidget *> &GetSingleDisplay();

    BCSingleDisplayWidget *GetSingleDisplay(QPoint pt);

    // 设置分割数
    void RefreshSegmentation(int n);
    int GetSegmentation();

protected:
    void resizeEvent(QResizeEvent *e);

    void paintEvent(QPaintEvent *e);

private:
    BCRoomMainWidget *m_parent;
    BCMGroupDisplay *m_pMGroupDisplay;

    QImage  m_imageSrc;
    QImage  m_image;

    QList<BCSingleDisplayWidget *>  m_lstSingleDisplay;
};

inline BCRoomMainWidget *BCGroupDisplayWidget::GetRoomWidget()
{
    return m_parent;
}

inline BCMGroupDisplay *BCGroupDisplayWidget::GetMGroupDisplay()
{
    return m_pMGroupDisplay;
}

inline const QList<BCSingleDisplayWidget *> &BCGroupDisplayWidget::GetSingleDisplay()
{
    return m_lstSingleDisplay;
}

#endif // BCGROUPDISPLAYWIDGET_H
