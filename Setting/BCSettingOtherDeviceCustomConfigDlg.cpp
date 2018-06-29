#include "BCSettingOtherDeviceCustomConfigDlg.h"
#include "ui_BCSettingOtherDeviceCustomConfigDlg.h"

BCSettingOtherDeviceCustomConfigDlg::BCSettingOtherDeviceCustomConfigDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingOtherDeviceCustomConfigDlg)
{
    ui->setupUi(this);
}

BCSettingOtherDeviceCustomConfigDlg::~BCSettingOtherDeviceCustomConfigDlg()
{
    delete ui;
}
