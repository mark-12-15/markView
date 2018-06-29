#include "BCSettingDisplaySetDlg.h"
#include "ui_BCSettingDisplaySetDlg.h"
#include "../Common/BCCommon.h"
#include "../Common/BCXMLManager.h"
#include <QDebug>
#include "../Common/BCLocalServer.h"
#include "BCSettingDisplaySetNetSetDlg.h"

BCSettingDisplaySetDlg::BCSettingDisplaySetDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingDisplaySetDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("大屏通讯设置"));
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));

    init();

//    BCLocalServer *pLocalServer = BCLocalServer::Application();
//    pLocalServer->GetDisplayCommunicationConfig();
}

BCSettingDisplaySetDlg::~BCSettingDisplaySetDlg()
{
    delete ui;
}
//   环出串口连接radBut
void BCSettingDisplaySetDlg::on_radio_serial_clicked()
{
    ui->edit_IP->setEnabled(false);
    ui->dateEdit->setEnabled(false);
    setSubViewEnabled(false);
}
//TCP连接radBut
void BCSettingDisplaySetDlg::on_radio_TCP_clicked()
{
    ui->edit_IP->setEnabled(true);
    ui->dateEdit->setEnabled(true);
    setSubViewEnabled(false);
}

//UDP连接radBut
void BCSettingDisplaySetDlg::on_radio_UDP_clicked()
{
    ui->edit_IP->setEnabled(true);
    ui->dateEdit->setEnabled(true);
    setSubViewEnabled(false);
}

//使用串口连接
void BCSettingDisplaySetDlg::on_radio_Serial2_clicked()
{
    ui->edit_IP->setEnabled(true);
    ui->dateEdit->setEnabled(true);
    setSubViewEnabled(true);
}

//自动开机
void BCSettingDisplaySetDlg::on_checkBox_ON_clicked()
{
    ui->dateTimeEdit->setEnabled(ui->checkBox_ON->isChecked());
    setCheckBoxEnabled(ui->checkBox_ON->isChecked());
}


//自动关机
void BCSettingDisplaySetDlg::on_checkBox_OFF_clicked()
{
    ui->dateTimeEdit_2->setEnabled(ui->checkBox_OFF->isChecked());
    setCheckBoxEnabled(ui->checkBox_OFF->isChecked());
}

//关闭计算机时自动关机
void BCSettingDisplaySetDlg::on_checkBox_10_clicked()
{

}

void BCSettingDisplaySetDlg::setSubViewEnabled(bool b)
{
    ui->comboBox->setEnabled(b);
    ui->comboBox_2->setEnabled(b);
    ui->comboBox_3->setEnabled(b);
    ui->comboBox_4->setEnabled(b);
    ui->comboBox_5->setEnabled(b);
    ui->comboBox_6->setEnabled(b);
    ui->comboBox_7->setEnabled(b);
    ui->comboBox_8->setEnabled(b);
}

//点击自动开机 和自动关机
void BCSettingDisplaySetDlg::setCheckBoxEnabled(bool b)
{
    if(b == false)
    {
        if(ui->checkBox_ON->isChecked() || ui->checkBox_OFF->isChecked()) return;
    }
    ui->checkBox_3->setEnabled(b);
    ui->checkBox_4->setEnabled(b);
    ui->checkBox_5->setEnabled(b);
    ui->checkBox_6->setEnabled(b);
    ui->checkBox_7->setEnabled(b);
    ui->checkBox_1->setEnabled(b);
    ui->checkBox_2->setEnabled(b);

}
 /*
*高级按钮事件
 */
void BCSettingDisplaySetDlg::on_pushButton_clicked()
{
    BCSettingDisplaySetNetSetDlg *pDlg = new BCSettingDisplaySetNetSetDlg( this );
    pDlg->exec();
}
 /*
*取消按钮事件
 */
void BCSettingDisplaySetDlg::on_pushButton_3_clicked()
{
    close();
}
 /*
*确定按钮事件
 */
void BCSettingDisplaySetDlg::on_pushButton_2_clicked()
{
    QMap<QString,QString> map;
    map["off_Serial"] = ui->radio_serial->isChecked() ? "1" : "0";
    map["off_TCP"] = ui->radio_TCP->isChecked() ? "1" : "0";
    map["off_UDP"] = ui->radio_UDP->isChecked() ? "1" : "0";
    map["off_Serial2"] = ui->radio_Serial2->isChecked() ? "1" : "0";
    map["off_ON"] = ui->checkBox_ON->isChecked() ? "1" : "0";
    map["off_OFF"] = ui->checkBox_OFF->isChecked() ? "1" : "0";
    map["Port"] = ui->dateEdit->text();
    map["IPAddress"] = ui->edit_IP->text();

    BCXMLManager *manager = new BCXMLManager;
    if(!manager->IsExistXmlFile("../xml/BigScreen.xml"))
    {
       manager->CreateXMLFile("../xml/BigScreen.xml");
       manager->CreateNode("nomal");
       manager->AddAttribute("nomal",map);
    }
    else
    {
        manager->UpdateAttributes("nomal",map);
    }

//    BCLocalServer *pLocalServer = BCLocalServer::Application();
//    pLocalServer->SetDisplayCommunicationConfig();

    close();
}

void BCSettingDisplaySetDlg::init()
{
//    BCXMLManager *manager = new BCXMLManager;
//    QList<QMap<QString,QString> >list;
//    list = manager->DOM("../xml/BigScreen.xml");

    ui->comboBox_2->insertItem(0,"1200");
    ui->comboBox_2->insertItem(1,"2400");
    ui->comboBox_2->insertItem(2,"4800");
    ui->comboBox_2->insertItem(3,"9600");
    ui->comboBox_2->insertItem(4,"192200");
    ui->comboBox_2->insertItem(5,"384400");
    ui->comboBox->insertItem(0,"COM1");
    ui->comboBox_3->insertItem(0,"COM1");
    ui->comboBox_4->insertItem(0,"COM1");
    ui->comboBox_5->insertItem(0,"COM1");
    ui->comboBox_6->insertItem(0,"COM1");
    ui->comboBox_7->insertItem(0,"COM1");
    ui->comboBox_8->insertItem(0,"COM1");
    ui->radio_serial->setCheckable(true);
}




