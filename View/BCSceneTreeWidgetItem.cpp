#include "BCSceneTreeWidgetItem.h"

#include "../Common/BCCommon.h"
#include "../Model/BCMGroupScene.h"
#include "../Model/BCMWindowScene.h"
#include <QHBoxLayout>
BCSceneTreeWidgetItem::BCSceneTreeWidgetItem(BCMWindowScene *pWindowScene, QTreeWidget *parent)
    :QTreeWidgetItem(parent)
{
    m_pWindowScene = pWindowScene;

    QString qsIconPath = m_pWindowScene->IsCycled() ? QString("/sceneon16.png") : QString("/sceneoff16.png");
//    this->setIcon(0, QIcon(QPixmap::fromImage(QImage(BCCommon::g_qsApplicationDefaultStylePath+qsIconPath).scaled(16, 16))));
//    this->setText(0, m_pWindowScene->GetWindowSceneName());
//    this->setToolTip(0, QObject::tr("%1(是否轮巡:%2, 轮巡间隔:%3)")
//                     .arg(m_pWindowScene->GetWindowSceneName())
//                     .arg(m_pWindowScene->IsCycled() ? QObject::tr("是") : QObject::tr("否"))
//                     .arg(m_pWindowScene->GetWindowSceneLoopInterval()));

    // 测试场景
    QWidget *pWidget = new QWidget();
    QHBoxLayout *pLayout = new QHBoxLayout();
    QCheckBox *pCheckBox = new QCheckBox( pWidget );
    pCheckBox->setText( m_pWindowScene->GetWindowSceneName() );
    QLineEdit *pLineEdit = new QLineEdit( pWidget );
    pLineEdit->setText( QString::number(m_pWindowScene->GetWindowSceneLoopInterval()) );
    pLayout->addWidget( pCheckBox );
    pLayout->addStretch();
    pLayout->addWidget( pLineEdit );
    pWidget->setLayout( pLayout );

    parent->setItemWidget(this, 0, pWidget);

}

BCSceneTreeWidgetItem::~BCSceneTreeWidgetItem()
{
    m_pWindowScene = NULL;
}

void BCSceneTreeWidgetItem::SetLoopWindowScene(bool b)
{
    if (NULL == m_pWindowScene)
        return;

    m_pWindowScene->SetIsCycled( b );
    QString qsIconPath = b ? QString("/sceneon16.png") : QString("/sceneoff16.png");
    this->setIcon(0, QIcon(QPixmap::fromImage(QImage(BCCommon::g_qsApplicationDefaultStylePath+qsIconPath).scaled(16, 16))));

//    this->setToolTip(0, QObject::tr("%1(是否轮巡:%2, 轮巡间隔:%3)")
//                     .arg(m_pWindowScene->GetWindowSceneName())
//                     .arg(m_pWindowScene->IsCycled() ? QObject::tr("是") : QObject::tr("否"))
//                     .arg(m_pWindowScene->GetWindowSceneLoopInterval()));
}

void BCSceneTreeWidgetItem::SetLoopInterval(int n)
{
    m_pWindowScene->SetWindowSceneLoopInterval( n );

    this->setText(1, QString::number(m_pWindowScene->GetWindowSceneLoopInterval()));
//    this->setToolTip(0, QObject::tr("%1(是否轮巡:%2, 轮巡间隔:%3)")
//                     .arg(m_pWindowScene->GetWindowSceneName())
//                     .arg(m_pWindowScene->IsCycled() ? QObject::tr("是") : QObject::tr("否"))
//                     .arg(m_pWindowScene->GetWindowSceneLoopInterval()));
}


