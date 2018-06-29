#include "BCSignalName.h"
#include "ui_BCSignalName.h"
#include "../Common/BCCommon.h"
#include "../View/BCControlTreeWidget.h"
#include "../Model/BCMChannel.h"

BCSignalName::BCSignalName(QString str, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSignalName)
{
    ui->setupUi(this);

    setWindowTitle(tr("修改名称"));
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));

    m_pChannel = NULL;
    m_str = str;
    ui->lineEdit->setText(m_str);
}

BCSignalName::BCSignalName(BCMChannel *pChannel, QWidget *parent)
    :QDialog(parent),
      ui(new Ui::BCSignalName)
{
    ui->setupUi(this);

    setWindowTitle(tr("修改名称"));
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));

    m_pChannel = pChannel;
    ui->lineEdit->setText( m_pChannel->GetChannelName() );
}

BCSignalName::~BCSignalName()
{
    delete ui;
}

void BCSignalName::on_pushButton_clicked()
{
    m_str = ui->lineEdit->text();

    if (NULL != m_pChannel) {
        m_pChannel->SetChannelName(ui->lineEdit->text(), true);
    }

    this->accept();
}

void BCSignalName::on_pushButton_2_clicked()
{
    this->reject();
}
