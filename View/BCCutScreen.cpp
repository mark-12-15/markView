#include "BCCutScreen.h"
#include "ui_BCCutScreen.h"
#include "../Common/BCCommon.h"

BCCutScreen::BCCutScreen(bool bVisible, int minHeight, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCCutScreen)
{
    ui->setupUi(this);
    m_minHeight = minHeight;
    ui->frame->setMinimumHeight(minHeight);
    m_pHeaderBtn = new BCWidgetBtn(this, MainWindow::CATCHNETDISPLAYSIGSRC, bVisible);

    ui->verticalLayout->addWidget(m_pHeaderBtn);

    connect(m_pHeaderBtn, SIGNAL(sigSetVisible(bool)), this, SLOT(onSetVisible(bool)));
    onSetVisible( bVisible );
}

BCCutScreen::~BCCutScreen()
{
    delete ui;
}

void BCCutScreen::onSetVisible(bool bVisible)
{
    ui->frame->setVisible( bVisible );
}

bool BCCutScreen::IsVisible()
{
    return m_pHeaderBtn->IsVisible();
}
