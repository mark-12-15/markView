#include "BCSettingWaitingDlg.h"
#include "ui_BCSettingWaitingDlg.h"
#include "../Common/BCLocalServer.h"
#include "../Common/BCCommon.h"

#define TIMEOUTCOUNT    10000/10     // 超时次数
#define QUITCOUNT       13000/10     // 超时次数

BCSettingWaitingDlg::BCSettingWaitingDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingWaitingDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);   // 关闭时自动析构
    setWindowFlags(Qt::FramelessWindowHint);    // 不显示标题

    // 延时初始化，否则会卡的界面显示不出来
    QTimer::singleShot(1, this, SLOT(onInit()));

    m_timeout = 0;
    m_pTimer = new QTimer( this );
    m_pTimer->setInterval( 10 );
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
    m_pTimer->start();
}

BCSettingWaitingDlg::~BCSettingWaitingDlg()
{
    delete ui;

    m_pTimer->stop();
    m_pTimer->deleteLater();
}

void BCSettingWaitingDlg::onInit()
{
    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->InitDataBaseData();
}

void BCSettingWaitingDlg::onTimeOut()
{
    m_timeout++;
    if (m_timeout > QUITCOUNT) {
        this->close();
    }
    if (m_timeout > TIMEOUTCOUNT) {
        int leaveSec = 3 - (m_timeout-TIMEOUTCOUNT)/100;
        ui->label->setText(tr("通讯超时,请检查设备和通讯设置,%1秒后关闭软件...").arg(leaveSec));
        return;
    }
    BCLocalServer *pServer = BCLocalServer::Application();
    if ( !pServer->m_bIsLoadDataOK )
        return;

    // 判断是否是连接服务器
    MainWindow *pApplication = BCCommon::Application();
    pApplication->RefreshMainWindow();//显示主界面

    pServer->m_bIsLoadDataOK = false;

    this->close();
}
