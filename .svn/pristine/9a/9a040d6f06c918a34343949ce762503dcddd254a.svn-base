#include "BCSettingDisplaySetNetSetDlg.h"
#include "ui_BCSettingDisplaySetNetSetDlg.h"
#include "../Common/BCCommon.h"
BCSettingDisplaySetNetSetDlg::BCSettingDisplaySetNetSetDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingDisplaySetNetSetDlg)
{
        ui->setupUi(this);
        this->setAttribute(Qt::WA_DeleteOnClose);

        this->setWindowTitle(tr("大屏高级网络设置"));
        this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));

        this->setFixedSize(358,380);
        ui->label->setText(tr("屏幕号"));
        ui->label_2->setText(tr("IP地址"));
        ui->label_3->setText(tr("1"));
        ui->label_4->setText(tr("2"));
        ui->label_5->setText(tr("3"));
        ui->label_6->setText(tr("4"));
}

BCSettingDisplaySetNetSetDlg::~BCSettingDisplaySetNetSetDlg()
{
        delete ui;
}

void BCSettingDisplaySetNetSetDlg::SetStyleSheet(QLabel *lab)
{
        lab->setStyleSheet("QLabel{background-color:rgb(255, 255, 255);  color: white;  "
                       " border-radius: 0px;  border: 1px groove gray;}");
}

void BCSettingDisplaySetNetSetDlg::on_pushButton_2_clicked()
{
        close();
}

void BCSettingDisplaySetNetSetDlg::on_pushButton_clicked()
{
    close();
}




