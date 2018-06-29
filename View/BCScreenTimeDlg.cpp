#include "BCScreenTimeDlg.h"
#include "ui_BCScreenTimeDlg.h"

BCScreenTimeDlg::BCScreenTimeDlg(int num,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCScreenTimeDlg)
{
    ui->setupUi(this);
    m_number = num;
    ui->spinBox->setValue(m_number);
}

BCScreenTimeDlg::~BCScreenTimeDlg()
{
    delete ui;
}

int BCScreenTimeDlg::GetNum(){
    return this->m_number;
}

void BCScreenTimeDlg::on_pushButton_ok_clicked()
{
    m_number = ui->spinBox->value();
    this->accept();
    this->close();
}

void BCScreenTimeDlg::on_pushButton_cannel_clicked()
{
    this->reject();
    this->close();
}
