#include "BCLocationSegmentationWidget.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <float.h>
#include "../Common/BCCommon.h"
#include "BCLocationDlg.h"

BCLocationSegmentationWidget::BCLocationSegmentationWidget(QWidget *parent)
    :QWidget(parent)
{
    // 设置主layout
    m_pMainLayout = new QVBoxLayout( this );
    m_pMainLayout->setContentsMargins(3, 3, 3, 3);
    m_pMainLayout->setSpacing( 0 );
    setLayout( m_pMainLayout );

    m_pLocationDlg = NULL;
    m_bPress = false;
    m_beginPt = QPoint(0, 0);

    m_nRowCount = 0;
    m_nColCount = 0;
}

void BCLocationSegmentationWidget::mousePressEvent(QMouseEvent *e)
{
    if (e->button() != Qt::LeftButton)
        return;

    m_bPress = true;

    m_beginPt = e->pos();
    RefreshHight( QRect(m_beginPt, m_beginPt) );
}

void BCLocationSegmentationWidget::mouseMoveEvent(QMouseEvent *e)
{
    if ( !m_bPress )
        return;

    QPoint currentPt = e->pos();

    QRect rect;
    rect.setLeft( (m_beginPt.x() > currentPt.x()) ? currentPt.x() : m_beginPt.x() );
    rect.setRight( (m_beginPt.x() > currentPt.x()) ? m_beginPt.x() : currentPt.x() );
    rect.setTop( (m_beginPt.y() > currentPt.y()) ? currentPt.y() : m_beginPt.y() );
    rect.setBottom( (m_beginPt.y() > currentPt.y()) ? m_beginPt.y() : currentPt.y() );

    RefreshHight( rect );
}

void BCLocationSegmentationWidget::mouseReleaseEvent(QMouseEvent */*e*/)
{
    m_bPress = false;
    m_beginPt = QPoint(0, 0);

    if (NULL != m_pLocationDlg)
        m_pLocationDlg->ResizeSignalWindow( false );
}

void BCLocationSegmentationWidget::ReBuildLocationWidget(int r, int c)
{
    ClearLocationWidget();

    m_nRowCount = r;
    m_nColCount = c;
    for (int i = 0; i < m_nRowCount; i++) {
        QHBoxLayout *pHLayout = new QHBoxLayout();

        for (int j = 0; j < m_nColCount; j++) {
            BCLocationLabel *pLabel = new BCLocationLabel(i, j, "", this);
            pHLayout->addWidget( pLabel );
        }

        pHLayout->setContentsMargins(0, 0, 0, 0);
        m_pMainLayout->addLayout( pHLayout );
    }
}

void BCLocationSegmentationWidget::ClearLocationWidget()
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

void BCLocationSegmentationWidget::ClearHighLight()
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

void BCLocationSegmentationWidget::RefreshHight(QRect rect)
{
    // 清除所有label
    QObjectList lstWidgets = children();
    for (int i = 0; i < lstWidgets.count(); i++) {
        BCLocationLabel *pLabel = dynamic_cast<BCLocationLabel *>( lstWidgets.at(i) );
        if (NULL == pLabel)
            continue;

        // 获得label的坐标，转换到当前空间
        QRect labelRect = QRect(pLabel->mapToParent(pLabel->rect().topLeft()), pLabel->mapToParent(pLabel->rect().bottomRight()));

        // 设置高亮
        pLabel->SetHightLight( labelRect.intersects(rect) );
    }
}

void BCLocationSegmentationWidget::RefreshHight(QPoint pt)
{
    ClearHighLight();

    BCLocationLabel *pLabel = dynamic_cast<BCLocationLabel *>( this->childAt( pt ) );
    if (NULL != pLabel)
        pLabel->SetHightLight( true );
}

QRectF BCLocationSegmentationWidget::GetHightRect()
{
    // 计算矩形
    double l = DBL_MAX;
    double t = DBL_MAX;
    double r = DBL_MIN;
    double b = DBL_MIN;

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

    l /= m_nRowCount;
    t /= m_nColCount;
    r /= m_nRowCount;
    b /= m_nColCount;
    return QRectF(l, t, r-l, b-t);
}
