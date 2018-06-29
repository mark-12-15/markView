#include "BCSystemplan.h"
#include "ui_BCSystemplan.h"
#include "../Common/BCCommon.h"
#include "../Model/BCMWindowScene.h"
#include "BCRibbonMainToolBarAction.h"

BCSystemplan::BCSystemplan(bool bVisible, int minHeight, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCSystemplan)
{
    ui->setupUi(this);
    m_minHeight = minHeight;
    ui->frame->setMinimumHeight(minHeight);
    m_pHeaderBtn = new BCWidgetBtn(this, MainWindow::SYSPLANSIGSRC, bVisible);

    ui->verticalLayout->addWidget(m_pHeaderBtn);

    ui->m_pTreeWidget->setHeaderHidden(true);

    connect(m_pHeaderBtn, SIGNAL(sigSetVisible(bool)), this, SLOT(onSetVisible(bool)));
    onSetVisible( bVisible );

    //默认字体
    BCCommon::SetSystemFont(this);
}

BCSystemplan::~BCSystemplan()
{
    delete ui;
}

void BCSystemplan::onSetVisible(bool bVisible)
{
    ui->frame->setVisible( bVisible );
}

bool BCSystemplan::IsVisible()
{
    return m_pHeaderBtn->IsVisible();
}
