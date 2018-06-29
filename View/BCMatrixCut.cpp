#include "BCMatrixCut.h"
#include "ui_BCMatrixCut.h"
#include "../Common/BCCommon.h"

BCMatrixCut::BCMatrixCut(bool bVisible, int minHeight, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCMatrixCut)
{
    ui->setupUi(this);
    m_pHeaderBtn = new BCWidgetBtn(this, MainWindow::MATRIXSWAPSIGSRC, bVisible);
    ui->verticalLayout->addWidget(m_pHeaderBtn);

    m_minHeight = minHeight;
    ui->frame->setMinimumHeight( minHeight );

    connect(m_pHeaderBtn, SIGNAL(sigSetVisible(bool)), this, SLOT(onSetVisible(bool)));
    onSetVisible( bVisible );
}

BCMatrixCut::~BCMatrixCut()
{
    delete ui;
}

void BCMatrixCut::onSetVisible(bool bVisible)
{
    ui->frame->setVisible( bVisible );
}

bool BCMatrixCut::IsVisible()
{
    return m_pHeaderBtn->IsVisible();
}
