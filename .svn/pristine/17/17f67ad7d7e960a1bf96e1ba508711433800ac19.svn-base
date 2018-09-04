#include "HardWareParameter.h"
#include "ui_HardWareParameter.h"
#include "../Common/BCCommon.h"
#include "../Common/BCXMLManager.h"
HardWareParameter::HardWareParameter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HardWareParameter)
{
        ui->setupUi(this);
        setFixedSize(800,260);
        setWindowTitle(tr("参数设置"));
        this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));
        init();
}

HardWareParameter::~HardWareParameter()
{
        delete ui;
}

void HardWareParameter::init()
{
        BCXMLManager *manager = new BCXMLManager;
        QList<QMap<QString,QString> >list;
        list = manager->DOM("../xml/hardWareParameter.xml");
        if(list.count() > 0)
        {
            S2 = list.at(0).value("S2");
            S1 = list.at(0).value("S1");
            C1 = list.at(1).value("C1");
            C2 = list.at(1).value("C2");
            P1 = list.at(2).value("P1");
            cNumber = list.at(3).value("cNumber");
            screenName = list.at(3).value("screenName");
            baudRate = list.at(3).value("baudRate");
            rNumber = list.at(3).value("rNumber");
            netAddress = list.at(3).value("netAddress");
            Hposition = list.at(3).value("Hposition");
            off = list.at(3).value("off");
            Vposition = list.at(3).value("Vposition");
            netPort = list.at(3).value("netPort");
            resolutionY = list.at(3).value("resolutionY");
            resolutionX = list.at(3).value("resolutionX");
        }

        ui->comboBox->addItem(C1);
        ui->comboBox->addItem(C2);
        ui->comboBox_2->addItem(P1);
        ui->comboBox_3->addItem(S1);
        ui->comboBox_3->addItem(S2);
        ui->checkBox->setChecked(off.toInt());
        ui->edit_Screen->setText(screenName);
        ui->edit_Row->setText(rNumber);
        ui->edit_Cloumn->setText(cNumber);
        ui->edit_HP->setText(Hposition);
        ui->edit_VP->setText(Vposition);
        ui->edit_netIP->setText(netAddress);
        ui->edit_netPort->setText(netPort);
        ui->edit_ResolutionX->setText(resolutionX);
        ui->edit_ResolutionY->setText(resolutionY);
        ui->edit_baudRate->setText(baudRate);

        ui->label->setText(tr("选择屏幕组"));
        ui->label_2->setText(tr("通讯方式"));
        ui->label_3->setText(tr("串行端口"));
        ui->label_4->setText(tr("波特率"));
        ui->label_5->setText(tr("网络地址"));
        ui->label_6->setText(tr("屏幕组名称"));
        ui->label_7->setText(tr("排列数"));
        ui->label_8->setText(tr("分辨率"));
        ui->label_9->setText(tr("网络端口"));
        ui->label_10->setText(tr("X"));
        ui->label_11->setText(tr("X"));
        ui->label_12->setText(tr("水平起始位置"));
        ui->label_13->setText(tr("垂直起始位置"));
        ui->checkBox->setText(tr("屏幕开关"));
        ui->pushButton->setText(tr("应用"));


}

void HardWareParameter::saveInXML()
{
    BCXMLManager *manager = new BCXMLManager;
    if(!manager->IsExistXmlFile("../xml/hardWareParameter.xml"))
    {
        manager->CreateXMLFile("../xml/hardWareParameter.xml");
        manager->CreateNode("screenSec");
        QMap<QString,QString>map;
        map["S1"] = "1.LED屏(6x2)";
        map["S2"] = "2.LED屏(4x2)";
        manager->AddAttribute("screenSec",map);      
    }
    else
    {
        QMap<QString,QString>map3;
        map3["off"] = ui->checkBox->isChecked() ? "1" : "0";
        map3["screenName"] = ui->edit_Screen->text();
        map3["rNumber"] = ui->edit_Row->text();
        map3["cNumber"] = ui->edit_Cloumn->text();
        map3["Hposition"] = ui->edit_HP->text();
        map3["baudRate"] = ui->edit_baudRate->text();
        map3["resolutionX"] = ui->edit_ResolutionX->text();
        map3["resolutionY"] = ui->edit_ResolutionY->text();
        map3["Vposition"] = ui->edit_VP->text();
        map3["netAddress"] = ui->edit_netIP->text();
        map3["netPort"] = ui->edit_netPort->text();
        manager->UpdateAttributes("other",map3);
    }

}

void HardWareParameter::on_pushButton_2_clicked()
{
        close();
}

void HardWareParameter::on_pushButton_clicked()
{
        saveInXML();
        close();
}


