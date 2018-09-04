#include "QueryDevice.h"
#include "ui_QueryDevice.h"
#include "../Common/BCCommon.h"
QueryDevice::QueryDevice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueryDevice)
{
    ui->setupUi(this);
    setFixedSize(650,308);
    setWindowTitle(tr("检测设备"));
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));
    /*
  * Label相关设置
     */
    ui->label_topBack->setStyleSheet(" border-radius: 5px;  border: 1px groove gray;");
    ui->label_belowBack->setStyleSheet(" border-radius: 5px;  border: 1px groove gray;");
    ui->label_topTitle->setText(tr("控制器通讯端口配置"));
    ui->label_IP->setText(tr("设备IP地址:"));
    ui->label_port->setText(tr("端口:"));
    ui->label_port2->setText(tr("端口:"));
    ui->label_com->setText(tr("COM口:"));
    ui->label_btl->setText(tr("波特率:"));
    ui->label_timeLater->setText(tr("通讯延时(ms)"));
    ui->label_belowTitle->setText(tr("网络监测配置"));

    ui->checkBox->setText(tr("服务器选项:"));
    ui->checkBox->setChecked(true);


    ui->comboBox->insertItem(0,tr("COM1"));
    ui->comboBox->setEnabled(false);
    ui->comboBox_2->setEnabled(false);
    ui->comboBox_2->insertItem(0,"1200");
    ui->comboBox_2->insertItem(1,"2400");
    ui->comboBox_2->insertItem(2,"4800");
    ui->comboBox_2->insertItem(3,"9600");
    ui->comboBox_2->insertItem(4,"19200");
    ui->comboBox_2->insertItem(5,"38400");
    ui->comboBox_2->insertItem(6,"76800");
    ui->comboBox_2->setCurrentIndex(3);
    ui->comboBox_3->insertItem(0,"博睿科技报警9688协议");
    ui->comboBox_3->insertItem(1,"博睿科技报警1314协议");


    ui->radioButton->setText(tr("选用NET连接"));
    ui->radioButton->setChecked(true);
    ui->radioButton_2->setText(tr("选用COM连接"));

    /*
   * 按钮相关设置
     */
    ui->pushButton_cancel->setText(tr("取消"));
    ui->pushButton_choice->setText(tr("选择"));
    ui->pushButton_more->setText(tr("高级>>"));
    ui->pushButton_search->setText(tr("搜索"));
    ui->pushButton_sure->setText(tr("确定"));

    /*
  *Edit相关设置
     */
    ui->lineEdit_IP->setText(tr("192.168.1.65"));
    ui->lineEdit_port->setText(tr("1024"));
    ui->lineEdit_port2->setText(tr("2000"));
    ui->lineEdit_timeLater->setText(tr("0"));

    QStringList headers;
          headers<<"用户"<<"等级"<<"事件"<<"时间";
//QTableWidgetItem *newItem;
//for(int i = 0; i < 3;i++){
    //ui->tableWidget->setRowHeight(i,20);
ui->tableWidget->setHorizontalHeaderLabels(headers);

}

QueryDevice::~QueryDevice()
{
    delete ui;
}

void QueryDevice::on_pushButton_cancel_clicked()
{
    close();
}
