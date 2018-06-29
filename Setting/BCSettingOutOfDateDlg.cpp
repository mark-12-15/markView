#include "BCSettingOutOfDateDlg.h"
#include "ui_BCSettingOutOfDateDlg.h"

#include "../Common/BCCommon.h"
#include "../Setting/BCSettingOutSideCommandDlg.h"

BCSettingOutOfDateDlg::BCSettingOutOfDateDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingOutOfDateDlg)
{
    ui->setupUi(this);

    setWindowTitle(tr("设备过期警告"));
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));
}

BCSettingOutOfDateDlg::~BCSettingOutOfDateDlg()
{
    delete ui;
}

void BCSettingOutOfDateDlg::on_pushButton_clicked()
{
    MainWindow *pMainWindow = BCCommon::Application();

    pMainWindow->onTrayIconQuit();
}

void BCSettingOutOfDateDlg::on_m_pUnlockBtn_clicked()
{
    this->close();

    BCSettingOutSideCommandDlg *pDlg = new BCSettingOutSideCommandDlg(1, BCCommon::Application());
    pDlg->exec();
}
