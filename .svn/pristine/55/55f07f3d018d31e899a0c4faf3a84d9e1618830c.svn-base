#include "BCSettingEDID.h"
#include "ui_BCSettingEDID.h"
#include <QDebug>
BCSettingEDID::BCSettingEDID(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCSettingEDID)
{
        ui->setupUi(this);
        this->setFixedSize(628,394);
        ui->groupBox_5->setHidden(true);
        this->setWindowTitle(tr("EDID设置"));
}

BCSettingEDID::~BCSettingEDID()
{
        delete ui;
}


void BCSettingEDID::on_checkBox_clicked()
{
        ui->groupBox_As1->setEnabled(ui->checkBox->isChecked());
}

void BCSettingEDID::on_checkBox_2_clicked()
{
        ui->groupBox_As2->setEnabled(ui->checkBox_2->isChecked());
}

void BCSettingEDID::on_checkBox_3_clicked()
{
        ui->groupBox_As3->setEnabled(ui->checkBox_3->isChecked());
}

void BCSettingEDID::on_checkBox_4_clicked()
{
        ui->groupBox_As4->setEnabled(ui->checkBox_4->isChecked());
}

void BCSettingEDID::on_radioButton_17_clicked()
{
        if(ui->radioButton_17->isChecked())
        {
            ui->radioButton_18->setChecked(false);
        }
        ui->groupBox_B1->setTitle(tr("Timing ID #1"));
        ui->groupBox_B2->setTitle(tr("Timing ID #2"));
        ui->groupBox_B3->setTitle(tr("Timing ID #3"));
        ui->groupBox_B4->setTitle(tr("Timing ID #4"));
}

void BCSettingEDID::on_radioButton_18_clicked()
{
        if(ui->radioButton_18->isChecked())
        {
            ui->radioButton_17->setChecked(false);
        }
        ui->groupBox_B1->setTitle(tr("Timing ID #5"));
        ui->groupBox_B2->setTitle(tr("Timing ID #6"));
        ui->groupBox_B3->setTitle(tr("Timing ID #7"));
        ui->groupBox_B4->setTitle(tr("Timing ID #8"));
}
#pragma-----Tab4

void BCSettingEDID::on_radioButton_19_clicked()
{
        this->TabFourth(true);
}

void BCSettingEDID::on_radioButton_20_clicked()
{
        this->TabFourth(false);
}

void BCSettingEDID::TabFourth(bool b)
{
        ui->groupBox_16->setEnabled(b);
        ui->groupBox_17->setEnabled(b);
        ui->checkBox_22->setEnabled(!b);
}


#pragma-------Tab5

void BCSettingEDID::TabFifth(bool b)
{
        ui->groupBox_23->setEnabled(b);
        ui->groupBox_5->setHidden(!b);
        ui->groupBox_25->setHidden(b);
        ui->groupBox_26->setHidden(b);
        ui->groupBox_27->setHidden(b);
}
//Block1-----RadBut事件
void BCSettingEDID::on_radioButton_29_clicked()
{
        this->TabFifth(false);
        ui->groupBox_24->setTitle(tr("Block #1"));
}

//Block2-----RadBut事件
void BCSettingEDID::on_radioButton_30_clicked()
{
        this->TabFifth(true);
        ui->radioButton_34->setChecked(true);
        ui->groupBox_24->setTitle(tr("Block #2"));
}

//Block3------RadBut事件
void BCSettingEDID::on_radioButton_31_clicked()
{
        this->TabFifth(true);
        ui->radioButton_34->setChecked(true);
        ui->groupBox_24->setTitle(tr("Block #3"));
}

//Block4 ----RadBut事件
void BCSettingEDID::on_radioButton_32_clicked()
{
        this->TabFifth(true);
        ui->radioButton_34->setChecked(true);
        ui->groupBox_24->setTitle(tr("Block #4"));
}

// Timing---RadBut事件
void BCSettingEDID::on_radioButton_33_clicked()
{
        this->TabFifth(false);
        ui->groupBox_23->setEnabled(true);
}

// Monition---RadBut事件
void BCSettingEDID::on_radioButton_34_clicked()
{
        this->TabFifth(true);

}
