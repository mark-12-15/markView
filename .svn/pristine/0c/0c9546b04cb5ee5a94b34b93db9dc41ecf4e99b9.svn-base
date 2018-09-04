#include "TestColor.h"
#include "ui_TestColor.h"
#include "../Common/BCCommon.h"
#include "../Common/BCXMLManager.h"
#include "../Common/BCLocalServer.h"

TestColor::TestColor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestColor)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    setWindowTitle(tr("网格测试"));
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));

    init();

//    BCLocalServer *pLocalServer = BCLocalServer::Application();
//    pLocalServer->GetTestDeviceConfig();
}

TestColor::~TestColor()
{
    delete ui;
}

void TestColor::on_pushButton_clicked()
{
    if(ui->rightBack->isHidden())
    {
        ui->rightBack->show();
        ui->pushButton->setText(tr("高级 <<"));
    }
    else
    {
       this->hideSubViews();
    }

}

void TestColor::hideSubViews()
{
    ui->rightBack->hide();
    ui->pushButton->setText(tr("高级 >>"));
}

void TestColor::loadData()
{
    BCXMLManager *manager = new BCXMLManager;
   QList<QMap<QString,QString> > list;
   list = manager->DOM("../xml/testColor.xml");
   if(list.count() > 0)
   {
       H1 = list.at(0).value("H1");
       V1 = list.at(0).value("V1");
       H2 = list.at(0).value("H2");
       V2 = list.at(0).value("V2");
       Value = list.at(0).value("value");
   }

   ui->spinBox_H1->setValue(H1.toInt());
   ui->spinBox_V1->setValue(V1.toInt());
   ui->spinBox_H2->setValue(H2.toInt());
   ui->spinBox_V2->setValue(V2.toInt());
   ui->verticalSlider->setValue(Value.toInt());

}

void TestColor::saveInXML()
{
    QMap<QString,QString>map;
    map["value"] = QString::number(ui->verticalSlider->value());
    map["H1"] = QString::number(ui->spinBox_H1->value());
    map["V1"] = QString::number(ui->spinBox_V1->value());
    map["H2"] = QString::number(ui->spinBox_H2->value());
    map["V2"] = QString::number(ui->spinBox_V2->value());
    BCXMLManager *manager = new BCXMLManager;
    if(!manager->IsExistXmlFile("../xml/testColor.xml"))
    {
        manager->CreateXMLFile("../xml/testColor.xml");
        manager->CreateNode("nomal");
        manager->AddAttribute("nomal",map);
    }
    else
    {
        manager->UpdateAttributes("nomal",map);
    }
}

void TestColor::on_pushButton_2_clicked()
{
    saveInXML();


//    BCLocalServer *pLocalServer = BCLocalServer::Application();
//    pLocalServer->SetTestDeviceConfig();

    close();
}
void TestColor::on_pushButton_3_clicked()
{
    close();
}
void TestColor::init()
{
    setFixedSize(378,400);
    QPixmap device_img(BCCommon::g_qsImageFilePrefix+"default/testColor.png");
    if ( !device_img.isNull() ) {
        device_img = device_img.scaled(51,51,Qt::KeepAspectRatio);
        ui->label_image->setPixmap(device_img);
    }
    ui->label_LeftTiele->setText(tr("色彩图形"));
    ui->label_rightTitle->setText(tr("网络图形"));
    ui->label_rightCount->setText(tr("网络数量"));
    ui->label_h1->setText(tr("横向栅格1:"));
    ui->label_v1->setText(tr("纵向栅格1:"));
    ui->label_h2->setText(tr("横向栅格2:"));
    ui->label_v2->setText(tr("纵向栅格2:"));
    ui->pushButton->setText(tr("高级 >>"));
    ui->pushButton_2->setText(tr("确定"));
    ui->pushButton_3->setText(tr("取消"));
    loadData();
    ui->label_16->setText(QString::number(ui->verticalSlider->value()) + "%");
    hideSubViews();
}

void TestColor::on_verticalSlider_sliderMoved(int position)
{
    ui->label_16->setText(QString::number(position) + "%");
}


void TestColor::on_pushButton_red_clicked()
{
    ui->pushButton_red->setText(tr("选中"));
    ui->pushButton_green->setText(tr(""));
    ui->pushButton_blue->setText(tr(""));
    ui->pushButton_yellow->setText(tr(""));
    ui->pushButton_fen->setText(tr(""));
    ui->pushButton_lv->setText(tr(""));
    ui->pushButton_white->setText(tr(""));

//    BCLocalServer *pLocalServer = BCLocalServer::Application();
//    pLocalServer->SetTestDeviceColor(0);
}

void TestColor::on_pushButton_green_clicked()
{
    ui->pushButton_red->setText(tr(""));
    ui->pushButton_green->setText(tr("选中"));
    ui->pushButton_blue->setText(tr(""));
    ui->pushButton_yellow->setText(tr(""));
    ui->pushButton_fen->setText(tr(""));
    ui->pushButton_lv->setText(tr(""));
    ui->pushButton_white->setText(tr(""));

//    BCLocalServer *pLocalServer = BCLocalServer::Application();
//    pLocalServer->SetTestDeviceColor(1);
}

void TestColor::on_pushButton_blue_clicked()
{
    ui->pushButton_red->setText(tr(""));
    ui->pushButton_green->setText(tr(""));
    ui->pushButton_blue->setText(tr("选中"));
    ui->pushButton_yellow->setText(tr(""));
    ui->pushButton_fen->setText(tr(""));
    ui->pushButton_lv->setText(tr(""));
    ui->pushButton_white->setText(tr(""));

//    BCLocalServer *pLocalServer = BCLocalServer::Application();
//    pLocalServer->SetTestDeviceColor(2);
}

void TestColor::on_pushButton_yellow_clicked()
{
    ui->pushButton_red->setText(tr(""));
    ui->pushButton_green->setText(tr(""));
    ui->pushButton_blue->setText(tr(""));
    ui->pushButton_yellow->setText(tr("选中"));
    ui->pushButton_fen->setText(tr(""));
    ui->pushButton_lv->setText(tr(""));
    ui->pushButton_white->setText(tr(""));

//    BCLocalServer *pLocalServer = BCLocalServer::Application();
//    pLocalServer->SetTestDeviceColor(3);
}

void TestColor::on_pushButton_fen_clicked()
{
    ui->pushButton_red->setText(tr(""));
    ui->pushButton_green->setText(tr(""));
    ui->pushButton_blue->setText(tr(""));
    ui->pushButton_yellow->setText(tr(""));
    ui->pushButton_fen->setText(tr("选中"));
    ui->pushButton_lv->setText(tr(""));
    ui->pushButton_white->setText(tr(""));

//    BCLocalServer *pLocalServer = BCLocalServer::Application();
//    pLocalServer->SetTestDeviceColor(4);
}

void TestColor::on_pushButton_lv_clicked()
{
    ui->pushButton_red->setText(tr(""));
    ui->pushButton_green->setText(tr(""));
    ui->pushButton_blue->setText(tr(""));
    ui->pushButton_yellow->setText(tr(""));
    ui->pushButton_fen->setText(tr(""));
    ui->pushButton_lv->setText(tr("选中"));
    ui->pushButton_white->setText(tr(""));

//    BCLocalServer *pLocalServer = BCLocalServer::Application();
//    pLocalServer->SetTestDeviceColor(5);
}

void TestColor::on_pushButton_white_clicked()
{
    ui->pushButton_red->setText(tr(""));
    ui->pushButton_green->setText(tr(""));
    ui->pushButton_blue->setText(tr(""));
    ui->pushButton_yellow->setText(tr(""));
    ui->pushButton_fen->setText(tr(""));
    ui->pushButton_lv->setText(tr(""));
    ui->pushButton_white->setText(tr("选中"));

//    BCLocalServer *pLocalServer = BCLocalServer::Application();
//    pLocalServer->SetTestDeviceColor(6);

}
