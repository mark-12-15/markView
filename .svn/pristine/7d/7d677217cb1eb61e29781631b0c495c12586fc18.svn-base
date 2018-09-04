#include "EDIDDialog.h"
#include "ui_EDIDDialog.h"
#include "../Common/BCCommon.h"
#include "../Common/BCXMLManager.h"
EDIDDialog::EDIDDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EDIDDialog)
{
        ui->setupUi(this);
        this->setWindowTitle(tr("EDID"));
        this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));
        init();  //初始化
}

EDIDDialog::~EDIDDialog()
{
        delete ui;

}
 /*
* 对外留的接口
  */
void EDIDDialog::changeContent()
{
        ui->lineEdit->setText(tr(""));
        ui->lineEdit_2->setText(tr(""));
        ui->lineEdit_3->setText(tr(""));
}

void EDIDDialog::on_pushButton_5_clicked()
{
        close();
}

void EDIDDialog::on_pushButton_clicked()
{
        saveInXML();
        close();
}

void EDIDDialog::init()
{
        ui->label->setText(tr("分辨率"));
        ui->label_2->setText(tr("*"));
        ui->label_4->setText(tr("Hz"));
        ui->pushButton->setText(tr("确认"));
        ui->pushButton_5->setText(tr("取消"));
        this->setWindowTitle(QObject::tr("EDID设置窗口"));
        BCXMLManager *manager = new BCXMLManager;
        QList<QMap<QString,QString> >list;
        list = manager->DOM("../xml/EDID.xml");
        if(list.count() > 0)
        {
            resolutionX = list.at(0).value("x");
            resolutionY = list.at(0).value("y");
            resolutionZ = list.at(0).value("z");
        }
        ui->lineEdit->setText(resolutionX);
        ui->lineEdit_2->setText(resolutionY);
        ui->lineEdit_3->setText(resolutionZ);
}

void EDIDDialog::saveInXML()
{
        QMap<QString,QString>map;
        map["x"] = ui->lineEdit->text();
        map["y"] = ui->lineEdit_2->text();
        map["z"] = ui->lineEdit_3->text();
        BCXMLManager *manager = new BCXMLManager;
        if(!manager->IsExistXmlFile("../xml/EDID.xml"))
        {
            manager->CreateXMLFile("../xml/EDID.xml");
            manager->CreateNode("nomal");
            manager->AddAttribute("nomal",map);
        }
        else
        {
            manager->UpdateAttributes("nomal",map);
        }
}
