#include "BCScreenName.h"
#include "ui_BCScreenName.h"
#include "../Common/BCCommon.h"

BCScreenName::BCScreenName(QString str, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCScreenName)
{
    ui->setupUi(this);

    this->setWindowTitle(tr("修改名称"));
    this->setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    ui->label->setText(tr("名称"));
    ui->lineEdit->setText(str);
    ui->lineEdit->setAlignment(Qt::AlignLeft);

    name = str;
}

BCScreenName::~BCScreenName()
{
    delete ui;
}

void BCScreenName::on_m_pOKBtn_clicked()
{
    name = ui->lineEdit->text();
    this->accept();
}

void BCScreenName::on_m_pCancelBtn_clicked()
{
    this->reject();
}
