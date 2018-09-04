#include "BCMatrixInput.h"
#include "ui_BCMatrixInput.h"
#include "../Common/BCCommon.h"

BCMatrixInput::BCMatrixInput(bool bVisible, int minHeight, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCMatrixInput)
{
    ui->setupUi(this);

    m_minHeight = minHeight;
    ui->frame->setMinimumHeight(minHeight);
    m_pHeaderBtn = new BCWidgetBtn(this, MainWindow::MATRIXINPUTSIGSRC, bVisible);
    ui->verticalLayout->addWidget(m_pHeaderBtn);

    connect(m_pHeaderBtn, SIGNAL(sigSetVisible(bool)), this, SLOT(onSetVisible(bool)));
    onSetVisible( bVisible );
}

BCMatrixInput::~BCMatrixInput()
{
    delete ui;
}

void BCMatrixInput::onSetVisible(bool bVisible)
{
    ui->frame->setVisible( bVisible );
}

bool BCMatrixInput::IsVisible()
{
    return m_pHeaderBtn->IsVisible();
}
