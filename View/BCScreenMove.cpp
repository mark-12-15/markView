#include "BCScreenMove.h"
#include "ui_BCScreenMove.h"
#include <QValidator>
#include <QRegExpValidator>
#include "../Common/BCCommon.h"
BCScreenMove::BCScreenMove(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCScreenMove)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    setWindowTitle(tr("移动设置"));
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));

    ui->label_1->setText(tr("左移动"));
    ui->label_2->setText(tr("右移动"));
    ui->label_3->setText(tr("上移动"));
    ui->label_4->setText(tr("下移动"));
    ui->lineEdit_1->setAlignment(Qt::AlignRight);
    ui->lineEdit_2->setAlignment(Qt::AlignRight);
    ui->lineEdit_3->setAlignment(Qt::AlignRight);
    ui->lineEdit_4->setAlignment(Qt::AlignRight);

    QRegExp regx("[0-9]+$");
    QValidator *validator = new QRegExpValidator(regx);
    ui->lineEdit_1->setValidator( validator );
    ui->lineEdit_2->setValidator( validator );
    ui->lineEdit_3->setValidator( validator );
    ui->lineEdit_4->setValidator( validator );
}

BCScreenMove::~BCScreenMove()
{
    delete ui;
}

void BCScreenMove::on_horizontalSlider_1_valueChanged(int value)
{
    ui->lineEdit_1->setText(QString("%1").arg(value));
}

void BCScreenMove::on_horizontalSlider_2_valueChanged(int value)
{
    ui->lineEdit_2->setText(QString("%1").arg(value));
}

void BCScreenMove::on_horizontalSlider_3_valueChanged(int value)
{
    ui->lineEdit_3->setText(QString("%1").arg(value));
}

void BCScreenMove::on_horizontalSlider_4_valueChanged(int value)
{
    ui->lineEdit_4->setText(QString("%1").arg(value));
}

void BCScreenMove::on_lineEdit_1_textChanged(const QString &arg1)
{
    ui->horizontalSlider_1->setValue(arg1.toInt());
}

void BCScreenMove::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->horizontalSlider_2->setValue(arg1.toInt());
}

void BCScreenMove::on_lineEdit_3_textChanged(const QString &arg1)
{
    ui->horizontalSlider_3->setValue(arg1.toInt());
}

void BCScreenMove::on_lineEdit_4_textChanged(const QString &arg1)
{
    ui->horizontalSlider_4->setValue(arg1.toInt());
}
