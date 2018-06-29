#include "BCStudyView.h"

#include <QGraphicsPixmapItem>
BCStudyView::BCStudyView(QWidget * parent)
    :QGraphicsView(parent)
{
    setStyleSheet("background: transparent");

    m_pScene = new QGraphicsScene( this );
    setScene( m_pScene );
}

BCStudyView::~BCStudyView()
{
    // delete scene
    delete m_pScene;
    m_pScene = NULL;
}

void BCStudyView::AddNotice(const QString &qsImagePath, const QPointF &pos)
{
    QGraphicsPixmapItem *pNoticePixmap = new QGraphicsPixmapItem(
                QPixmap(qsImagePath));

    m_pScene->addItem( pNoticePixmap );
    pNoticePixmap->setPos(pos.x(), pos.y());

    // 显示
    this->show();
}

void BCStudyView::ClearScreen()
{
    // 清除内部元素
    QList<QGraphicsItem*> lst = m_pScene->items();
    while ( !lst.isEmpty() )
        delete lst.takeFirst();

    // 隐藏
    this->hide();
}
