#include "BCWidgetBtn.h"
#include "ui_BCWidgetBtn.h"
#include <QDebug>
#include "../Common/BCCommon.h"
BCWidgetBtn::BCWidgetBtn(QWidget *parent, MainWindow::SIGNALSOURCETYPE eType, bool bVisible) :
    QWidget(parent),
    ui(new Ui::BCWidgetBtn)
{
    ui->setupUi(this);

    m_eType = eType;
    m_bVisible = bVisible;

    init();
}

BCWidgetBtn::~BCWidgetBtn()
{
    delete ui;
}

void BCWidgetBtn::RefreshLanguage()
{
    MainWindow *pMainWindow = BCCommon::Application();

    QString qsName = pMainWindow->GetSignalSourceName( m_eType );

    ui->label_text->setText( qsName );
}

void BCWidgetBtn::init()
{
    MainWindow *pMainWindow = BCCommon::Application();

    QString qsIconPath = pMainWindow->GetSignalSourceIcon( m_eType );
    QString qsName = pMainWindow->GetSignalSourceName( m_eType );

    ui->label_text->setText( qsName );
    ui->label_left->setPixmap( QPixmap(qsIconPath).scaled(16, 16) );

    RefreshVisibleIcon( m_bVisible );

    //默认字体
    BCCommon::SetSystemFont(this, true);
    this->setStyleSheet(
                "QWidget:hover{background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(117, 147, 200, 255), stop:1 rgba(255, 255, 255, 255));}"
                );
}

void BCWidgetBtn::RefreshVisibleIcon(bool bVisible)
{
    QString qsIconName = bVisible ? QString("/pushup16.png") : QString("/pushdown16.png");

    QPixmap maptest = QPixmap::fromImage(QImage(BCCommon::g_qsApplicationDefaultStylePath+qsIconName).scaled(16, 16));
    ui->label_right->setPixmap(maptest);
}

void BCWidgetBtn::mousePressEvent(QMouseEvent* e){
    if(e->button() == Qt::LeftButton) {
        // 重新赋值是否显示标识
        m_bVisible = !m_bVisible;

        // 刷新图片
        RefreshVisibleIcon( m_bVisible );

        // 发送信号
        emit sigSetVisible( m_bVisible );
    }

    QWidget::mousePressEvent(e);
}
