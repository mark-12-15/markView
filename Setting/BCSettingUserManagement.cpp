#include "BCSettingUserManagement.h"
#include "ui_BCSettingUserManagement.h"

BCSettingUserManagement::BCSettingUserManagement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingUserManagement)
{
    ui->setupUi(this);
}

BCSettingUserManagement::~BCSettingUserManagement()
{
    delete ui;
}
