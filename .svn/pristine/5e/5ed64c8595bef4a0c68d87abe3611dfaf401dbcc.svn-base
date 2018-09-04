#include "BCWarningLogWindow.h"
#include "ui_BCWarningLogWindow.h"
#include "../Common/BCCommon.h"
#include "../Common/BCXMLManager.h"
BCWarningLogWindow::BCWarningLogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCWarningLogWindow)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("报警日志"));
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));

    this->setTableViewAfterChange();
    saveInXML();
    init();
}



BCWarningLogWindow::~BCWarningLogWindow()
{
    delete ui;
}

void BCWarningLogWindow::setTableViewAfterChange()
{
     ui->tableWidget->verticalHeader()->hide();
     ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
     ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中
     ui->tableWidget->setShowGrid(false);//不显示内部的格子线条
     ui->tableWidget->setColumnWidth(0,90);//头部的宽度
     ui->tableWidget->setColumnWidth(1,90);
     ui->tableWidget->setColumnWidth(2,90);
     ui->tableWidget->setColumnWidth(3,133);
}

void BCWarningLogWindow::on_pushButton_2_clicked()
{
//    ui->tableWidget->clear();
//    this->reloadData(_dataArray);
    close();
}

void BCWarningLogWindow::init()
{
    ui->tableWidget->setColumnCount(4);

    BCXMLManager *manager = new BCXMLManager;

    _dataArray = manager->DOM("../xml/warningLog.xml");

    this->reloadData(_dataArray);

}

void BCWarningLogWindow::saveInXML()
{
    BCXMLManager *manager = new BCXMLManager;
    if(!manager->IsExistXmlFile("../xml/warningLog.xml"))
    {
        manager->CreateXMLFile("../xml/warningLog.xml");
        manager->CreateNode("E1");
        manager->CreateNode("E2");
        manager->CreateNode("E3");
        manager->CreateNode("E4");
        manager->CreateNode("E5");


        QMap<QString,QString>map;
        map["user"] = "Admin";
        map["grades"] = "高级";
        map["event"] = "转速低于100/分钟";
        map["time"] = "12:00";
        manager->AddAttribute("E1",map);


        map["user"] = "User1";
        map["grades"] = "中级";
        map["event"] = "温度过高";
        map["time"] = "15:00";
        manager->AddAttribute("E2",map);

        map["user"] = "Admin";
        map["grades"] = "高级";
        map["event"] = "转速高于300/分钟";
        map["time"] = "08:00";
        manager->AddAttribute("E3",map);


        map["user"] = "User2";
        map["grades"] = "初级";
        map["event"] = "转速低于100/分钟";
        map["time"] = "12:00";
        manager->AddAttribute("E4",map);


        map["user"] = "User3";
        map["grades"] = "初级";
        map["event"] = "视频字幕声音不一致";
        map["time"] = "08:00";
        manager->AddAttribute("E5",map);
    }
}

void BCWarningLogWindow::reloadData(QList<QMap<QString, QString> > dataArray)
{
    ui->tableWidget->setRowCount(dataArray.count());
    QStringList headers;
    headers<<"用户"<<"等级"<<"事件"<<"时间";
    QStringList keys;
    keys<<"user"<<"grades"<<"event"<<"time";
    QTableWidgetItem *newItem;
     for(int i = 0; i < dataArray.count();i++)
     {
          ui->tableWidget->setRowHeight(i,20);
          ui->tableWidget->setHorizontalHeaderLabels(headers);

         for(int j = 0;j< keys.count();j++)
         {
             newItem = new QTableWidgetItem(dataArray.at(i).value(keys.at(j)));
             ui->tableWidget->setItem(i,j,newItem);
         }
     }
}

void BCWarningLogWindow::on_QueryBut_clicked()
{
   QString user = ui->UserName->text();
   QString grades = ui->Grades->text();
   QString event = ui->Event->text();
   QString time = ui->Time->text();
   bool uNULL = user.isEmpty() ? true : false;
   bool gNULL = grades.isEmpty() ? true : false;
   bool eNULL = event.isEmpty() ? true : false;
   bool tNULL = time.isEmpty() ? true : false;

    QList<QMap<QString,QString> > result;
    for(int i = 0; i <_dataArray.count(); i++)
    {
        QMap<QString,QString> map;
        map = _dataArray.at(i);
        user = uNULL == true ? map.value("user") : user;
        grades = gNULL == true ? map.value("grades") : grades;
        event = eNULL == true ? map.value("event") : event;
        time = tNULL == true ? map.value("time") : time;
        if(map.value("user") == user && map.value("grades") == grades)
        {
            if(map.value("time") == time && map.value("event") == event)
            {
                result.append(map);
                ui->tableWidget->clear();
            }
        }
    }
    this->reloadData(result);
}
