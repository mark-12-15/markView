#include "BCSetControlDlg.h"
#include "ui_BCSetControlDlg.h"
#include <QDebug>
#include "../Common/BCXMLManager.h"
#include "../common/BCCommon.h"

BCSetControlDlg::BCSetControlDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSetControlDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("输入设置"));
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));

    //读取xml
    QList< QMap<QString,QString> > list;
    list = ReadXml();


    //显示tabwidget
    //选中
    ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
    //选中一行
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //自动调整宽度
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    //屏蔽列表头
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(0);

    QStringList header;
    header<<tr("输入通道")<<tr("输入通道名称")<<tr("关联设备")<<tr("关联端口");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    QHeaderView *pheader = ui->tableWidget->horizontalHeader();
    BCCommon::SetSystemFont(pheader);

    int count = 6;
    for(int i = 0 ; i < count; i++){
        int row_count = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row_count);

        QTableWidgetItem* item = new QTableWidgetItem(list.at(i).value("InputChannel"));
        item->setTextAlignment(Qt::AlignCenter);
        item->setFlags(item->flags()&~(Qt::ItemIsEditable));
        ui->tableWidget->setItem(row_count,0,item);

        QTableWidgetItem* item1 = new QTableWidgetItem(list.at(i).value("InputChannelName"));
        item1->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row_count,1,item1);

        QTableWidgetItem* item2 = new QTableWidgetItem(list.at(i).value("RelevanceDevice"));
        item2->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row_count,2,item2);

        QTableWidgetItem* item3 = new QTableWidgetItem(list.at(i).value("InputPort"));
        item3->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row_count,3,item3);
    }

    m_combo = new QComboBox();
    m_combo->addItem(tr("无"));
    m_combo->addItem(tr("默认矩形"));

    m_spin = new QSpinBox();
    m_spin->setRange(0,65535);

    connect(ui->tableWidget,SIGNAL(itemClicked(QTableWidgetItem*)),
            this,SLOT(slot_itemClicked(QTableWidgetItem*)));

    //默认字体
    BCCommon::SetSystemFont(ui->tableWidget);
}

BCSetControlDlg::~BCSetControlDlg()
{

    delete ui;
}

void BCSetControlDlg::on_pushButton_OK_clicked()
{
    //保存xml
    WriteXml();
    this->close();
}

void BCSetControlDlg::on_pushButton_CANNEL_clicked()
{
    this->close();
}

void BCSetControlDlg::on_pushButton_RESET_clicked()
{
//    BCXMLManager *manager = new BCXMLManager;
//    if(!manager->IsExistXmlFile("../xml/BCSetControlDlg.xml")){

//    }
//    else{
//        for(int i = 0; i < 6; i++){
//            QMap<QString,QString>maptemp;
//            maptemp["InputChannel"] = QString("%1").arg(i);
//            maptemp["InputChannelName"] = tr("VGA输入1");
//            maptemp["RelevanceDevice"] = tr("默认矩形");
//            maptemp["InputPort"] = tr("0");
//            manager->UpdateAttributes(QString("data%1").arg(i),maptemp);
//        }
//    }
}

void BCSetControlDlg::slot_itemClicked(QTableWidgetItem* item){
    m_combo->close();
    m_spin->close();
    if(item->column() == 2){
        m_combo = new QComboBox();
        m_combo->addItem(tr("无"));
        m_combo->addItem(tr("默认矩形"));
        connect(m_combo, SIGNAL(currentIndexChanged(QString)),this,SLOT(slot_currentIndexChanged(QString)));
        if(item->text() == tr("无"))
            m_combo->setCurrentIndex(0);
        else
            m_combo->setCurrentIndex(1);
        ui->tableWidget->setCellWidget(item->row(),item->column(),m_combo);
    }
    if(item->column() == 3){
        m_spin = new QSpinBox();
        m_spin->setValue(item->text().toInt());
        connect(m_spin, SIGNAL(valueChanged(QString)),this,SLOT(slot_valueChanged(QString)));

        ui->tableWidget->setCellWidget(item->row(),item->column(),m_spin);
    }
}

void BCSetControlDlg::slot_currentIndexChanged(QString str){
    QTableWidgetItem *item = ui->tableWidget->currentItem();
    if( NULL != item)
      item->setText(str);
}
void BCSetControlDlg::slot_valueChanged(QString str){
    QTableWidgetItem *item = ui->tableWidget->currentItem();
    if( NULL != item)
      item->setText(str);
}

QList< QMap<QString,QString> > BCSetControlDlg::ReadXml(){
    BCXMLManager *manager = new BCXMLManager;
    QList< QMap<QString,QString> > list;
    list = manager->DOM("../xml/BCSetControlDlg.xml");
    return list;
}

void BCSetControlDlg::WriteXml(){
    BCXMLManager *manager = new BCXMLManager;
    if(!manager->IsExistXmlFile("../xml/BCSetControlDlg.xml"))
    {
        manager->CreateXMLFile("../xml/BCSetControlDlg.xml");
        for(int i = 0; i < 6; i++){
            manager->CreateNode(QString("data%1").arg(i));
        }
        manager->CreateNode("header");

        QMap<QString,QString>map;
        map["MainInputChannel"] = tr("输入通道");
        map["MainInputChannelName"] = tr("输入通道名称");
        map["MainRelevanceDevice"] = tr("关联设备");
        map["MainInputPort"] = tr("关联端口");
        manager->AddAttribute("header",map);


        for(int i = 0; i < 6; i++){
            QMap<QString,QString>maptemp;
            maptemp["InputChannel"] = QString("%1").arg(i);
            maptemp["InputChannelName"] = tr("VGA输入1");
            maptemp["RelevanceDevice"] = tr("默认矩形");
            maptemp["InputPort"] = "0";
            manager->AddAttribute(QString("data%1").arg(i),maptemp);
        }

    }
    else
    {
        for(int i = 0; i < 6; i++){
            QMap<QString,QString>maptemp;
            maptemp["InputChannel"] = ui->tableWidget->item(i,0)->text();
            maptemp["InputChannelName"] = ui->tableWidget->item(i,1)->text();
            maptemp["RelevanceDevice"] = ui->tableWidget->item(i,2)->text();
            maptemp["InputPort"] = ui->tableWidget->item(i,3)->text();
            manager->UpdateAttributes(QString("data%1").arg(i),maptemp);
        }

    }
}
