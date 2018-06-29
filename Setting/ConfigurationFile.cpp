#include "ConfigurationFile.h"
#include "ui_ConfigurationFile.h"
#include <QFileDialog>
#include <QDebug>
#include "../Common/BCCommon.h"
ConfigurationFile::ConfigurationFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigurationFile)
{
        ui->setupUi(this);
        this->setAttribute(Qt::WA_DeleteOnClose);

        this->setWindowTitle(tr("配置文件"));
        this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));
}

ConfigurationFile::~ConfigurationFile()
{
       delete ui;
}

 /*
* 打开文件
  */
void ConfigurationFile::on_pushButton_clicked()
{
        QString fileName = GetFileName(ui->lineEdit);
        ui->lineEdit->setText(fileName);

}


void ConfigurationFile::on_pushButton_2_clicked()
{
        QString fileName = GetFileName(ui->lineEdit_2);
        ui->lineEdit_2->setText(fileName);
}

void ConfigurationFile::on_pushButton_3_clicked()
{
        QString fileName = GetFileName(ui->lineEdit_3);
        ui->lineEdit_3->setText(fileName);
}

void ConfigurationFile::on_pushButton_4_clicked()
{
        QString fileName = GetFileName(ui->lineEdit_4);
        ui->lineEdit_4->setText(fileName);
}

void ConfigurationFile::on_pushButton_5_clicked()
{
        QString fileName = GetFileName(ui->lineEdit_5);
        ui->lineEdit_5->setText(fileName);
}

QString ConfigurationFile::GetFileName(QLineEdit *edit)
{
        QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"),"/home/jana",tr("XML Files (*.xml)"));
        if( fileName.isEmpty() )
        {
            return edit->text();
        }
        return fileName;
}

//确定按钮槽
void ConfigurationFile::on_pushButton_6_clicked()
{
        close();
}
//取消按钮槽
void ConfigurationFile::on_pushButton_7_clicked()
{
        close();
}
