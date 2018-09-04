#include "BCLocationGroupWidget.h"
#include <float.h>
#include <QVBoxLayout>
#include "../Common/BCCommon.h"
#include "BCLocationDlg.h"
#include "BCSignalWindowDisplayWidget.h"
#include "BCGroupDisplayWidget.h"
#include "../Model/BCMGroupDisplay.h"
#include "../Model/BCMDisplay.h"
#include "BCSingleDisplayWidget.h"

BCLocationGroupWidget::BCLocationGroupWidget(QWidget * parent)
    :QWidget(parent)
{
    // 设置主layout
    m_pMainLayout = new QVBoxLayout( this );
    m_pMainLayout->setContentsMargins(3, 3, 3, 3);
    m_pMainLayout->setSpacing( 0 );
    setLayout( m_pMainLayout );

    m_pLocationDlg          = NULL;
    m_pGroupDisplayWidget   = NULL;
    m_pSignalWindowWidget   = NULL;
}

BCLocationGroupWidget::~BCLocationGroupWidget()
{
    ClearItems();
}

void BCLocationGroupWidget::ClearItems()
{
    // 清除所有的layout
    while ( !m_pMainLayout->isEmpty() ) {
        QLayoutItem *pLayoutItem = m_pMainLayout->takeAt(0);
        if (NULL == pLayoutItem)
            continue;

        delete pLayoutItem;
        pLayoutItem = NULL;
    }

    // 清除所有label
    QObjectList lstWidgets = children();
    while ( !lstWidgets.isEmpty() ) {
        BCLocationLabel *pLabel = dynamic_cast<BCLocationLabel *>( lstWidgets.takeFirst() );
        if (NULL == pLabel)
            continue;

        delete pLabel;
        pLabel = NULL;
    }
}

void BCLocationGroupWidget::Refresh(BCGroupDisplayWidget *pSceneGroup, BCSignalWindowDisplayWidget *pSignalWindow)
{
    if (NULL == pSceneGroup)
        return;

    // 更新信号窗
    m_pSignalWindowWidget = pSignalWindow;

    // 传入屏组无变化时直接返回
    if (pSceneGroup == m_pGroupDisplayWidget)
        return;

    // 清空内部item
    ClearItems();

    // 更新屏组
    m_pGroupDisplayWidget = pSceneGroup;
    m_rect = m_pGroupDisplayWidget->GetMGroupDisplay()->GetRect();
    QSize arrSize = m_pGroupDisplayWidget->GetMGroupDisplay()->GetArraySize();

    int nColCount = arrSize.width();
    int nRowCount = arrSize.height();
    for (int i = 0; i < nRowCount; i++) {
        QHBoxLayout *pHLayout = new QHBoxLayout();

        for (int j = 0; j < nColCount; j++) {
            BCMDisplay *pMDisplay = m_pGroupDisplayWidget->GetMGroupDisplay()->GetDisplay(i*nColCount+j);
            QString qsText = (NULL == pMDisplay) ? "" : pMDisplay->GetDisplayName();
            BCLocationLabel *pLabel = new BCLocationLabel(i, j, qsText, this);
            pHLayout->addWidget( pLabel );
        }

        pHLayout->setContentsMargins(0, 0, 0, 0);
        m_pMainLayout->addLayout( pHLayout );
    }

    m_bPress = false;
    m_x = 0.0;
    m_y = 0.0;
}

void BCLocationGroupWidget::ClearHighLight()
{
    QObjectList lstWidgets = children();
    for (int i = 0; i < lstWidgets.count(); i++) {
        BCLocationLabel *pLabel = dynamic_cast<BCLocationLabel *>( lstWidgets.at(i) );
        if (NULL == pLabel)
            continue;

        // 设置高亮
        pLabel->SetHightLight( false );
    }
}

void BCLocationGroupWidget::HighLight(QRect rect)
{
    ClearHighLight();

    QObjectList lstWidgets = children();
    for (int i = 0; i < lstWidgets.count(); i++) {
        BCLocationLabel *pLabel = dynamic_cast<BCLocationLabel *>( lstWidgets.at(i) );
        if (NULL == pLabel)
            continue;

        QPoint tl = pLabel->mapToParent(pLabel->rect().topLeft());
        QPoint br = pLabel->mapToParent(pLabel->rect().bottomRight());
        QRect cRect(tl, br);
        if ( cRect.intersects(rect) )
            pLabel->SetHightLight( true );
    }
}

void BCLocationGroupWidget::HighLight(QPoint pt)
{
    ClearHighLight();

    BCLocationLabel *pLabel = dynamic_cast<BCLocationLabel *>( this->childAt( pt ) );
    if (NULL != pLabel)
        pLabel->SetHightLight( true );
}

void BCLocationGroupWidget::mousePressEvent(QMouseEvent *e)
{
    if(e->button()== Qt::LeftButton){
        m_bPress = true;

        // 记录点击的坐标
        m_x = e->pos().x();
        m_y = e->pos().y();

        HighLight( e->pos() );
    }
}

void BCLocationGroupWidget::mouseMoveEvent(QMouseEvent *e)
{
    if (m_bPress) {
        double x = (m_x < e->pos().x()) ? m_x : e->pos().x();
        double y = (m_y < e->pos().y()) ? m_y : e->pos().y();
        double w = qAbs(m_x - e->pos().x());
        double h = qAbs(m_y - e->pos().y());

        HighLight(QRect(x, y, w, h));
    }
}

void BCLocationGroupWidget::mouseReleaseEvent(QMouseEvent */*e*/)
{
    m_bPress = false;

    if (NULL != m_pLocationDlg)
        m_pLocationDlg->ResizeSignalWindow( true );
}

QRectF BCLocationGroupWidget::GetSingleDisplayRelationRect()
{
    // 计算矩形
    double l = DBL_MAX;
    double t = DBL_MAX;
    double r = DBL_MIN;
    double b = DBL_MIN;

    QSize arrSize = m_pGroupDisplayWidget->GetMGroupDisplay()->GetArraySize();

    QObjectList lstWidgets = children();
    for (int i = 0; i < lstWidgets.count(); i++) {
        BCLocationLabel *pLabel = dynamic_cast<BCLocationLabel *>( lstWidgets.at(i) );
        if (NULL == pLabel)
            continue;

        if ( !pLabel->m_bHightLight )
            continue;

        l = qMin(l, 1.0*pLabel->m_nCol);
        t = qMin(t, 1.0*pLabel->m_nRow);
        r = qMax(r, 1.0*pLabel->m_nCol+1);
        b = qMax(b, 1.0*pLabel->m_nRow+1);
    }

    l /= arrSize.width();
    t /= arrSize.height();
    r /= arrSize.width();
    b /= arrSize.height();
    return QRectF(l, t, r-l, b-t);
}
