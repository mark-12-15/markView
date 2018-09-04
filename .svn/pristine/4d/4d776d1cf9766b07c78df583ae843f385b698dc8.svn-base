#include "LogQueryDialog.h"
#include "ui_LogQueryDialog.h"

#include <QDomComment>
#include <QFile>
#include <QDebug>
#include <QDomNode>
#include <QtXml>
#include "../Common/BCCommon.h"
#include "../Common/BCXMLManager.h"
LogQueryDialog::LogQueryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogQueryDialog)
{
            ui->setupUi(this);
            this->setAttribute(Qt::WA_DeleteOnClose);

            setWindowTitle(tr("日志查询"));
            this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));

            /*
            * 设置TableVidget
            */
            this->setTableVidget();
}

LogQueryDialog::~LogQueryDialog()
{
            delete ui;
}

void LogQueryDialog::setTableVidget()
{

        BCXMLManager *manager = new BCXMLManager;
        _dataArray = manager->DOM("../xml/NewLogQuery.xml");
        this->reloadData(_dataArray);
}
/*
*  每次在查询完时因为model改变了得重新设置tableView的相关属性
*/
void LogQueryDialog::setTableViewAfterChange()
{
        myTableView->verticalHeader()->hide();
        myTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
        myTableView->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中
        myTableView->setShowGrid(false);//不显示内部的格子线条
        myTableView->setColumnWidth(0,140);//头部的宽度
        myTableView->setColumnWidth(1,160);
        myTableView->setColumnWidth(2,160);
        myTableView->setColumnWidth(3,200);
}
/*
* 刷新数据
*/
void LogQueryDialog::reloadData(QList<QMap<QString, QString> > dataArray)
{
    myTableView = ui->tableWidget;
    myTableView->setColumnCount(4);
    myTableView->setRowCount(dataArray.count());

    QStringList headers;
    headers<<"用户"<<"开始时间"<<"结束时间"<<"事件";
    myTableView->setHorizontalHeaderLabels(headers);
    QTableWidgetItem *newItem;
    for(int i = 0; i < dataArray.count();i++)
    {
            myTableView->setRowHeight(i,20);
            myTableView->horizontalHeader()->setFont(QFont("Times",10));
            QList<QString>allKeys;
            allKeys<<"User"<<"bTime"<<"eTime"<<"Event";
            for(int j = 0;j< allKeys.size();j++)
            {
                    QString key = allKeys.at(j);
                    newItem = new QTableWidgetItem(dataArray.at(i).value(key));
                    myTableView->setItem(i,j,newItem);
            }
    }
    //设置tableView的相关属性
    this->setTableViewAfterChange();
}



void LogQueryDialog::on_pushButton_2_clicked()
{
//    ui->tableWidget->clear();
//    this->reloadData(_dataArray);
            close();
}

void LogQueryDialog::on_pushButton_clicked()
{
        QString user = ui->userName->text();
        QString event = ui->event->text();
        QString bTime = ui->beginTime->text();
        QString eTime = ui->endTime->text();
        bool uNULL = user.isEmpty() ? true : false;
        bool eNULL = event.isEmpty() ? true : false;
        bool btNULL = bTime.isEmpty() ? true : false;
        bool etNULL = eTime.isEmpty() ? true : false;

         QList<QMap<QString,QString> > result;
         for(int i = 0; i <_dataArray.count(); i++)
         {
             QMap<QString,QString> map;
             map = _dataArray.at(i);
             user = uNULL == true ? map.value("User") : user;
             event = eNULL == true ? map.value("Event") : event;
             bTime = btNULL == true ? map.value("bTime") : bTime;
             eTime = etNULL == true ? map.value("eTime") : eTime;

             if(map.value("User") == user && map.value("bTime") == bTime)
             {
                 if(map.value("eTime") == eTime && map.value("Event") == event)
                 {
                     result.append(map);
                     ui->tableWidget->clear();
                 }
             }
         }
         this->reloadData(result);
}
