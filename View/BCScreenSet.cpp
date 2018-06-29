#include "BCScreenSet.h"
#include "ui_BCScreenSet.h"
#include <QColorDialog>
#include "BCTreeData.h"
#include "BCScreenBtn.h"
#include <QDebug>
#include "BCScreenName.h"
#include "../Common/BCCommon.h"

BCScreenSet::BCScreenSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCScreenSet)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    setWindowTitle(tr("字幕设置"));
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));

    //初始化
    ui->label->setText(tr("颜色显示板"));
    ui->label_1->setText(tr("字幕内容"));
    ui->label_2->setText(tr("字幕水平位置"));
    ui->label_3->setText(tr("字幕垂直位置"));
    ui->label_4->setText(tr("字幕颜色"));


    ui->pushButton->setText(tr("添加场景"));
    ui->pushButton_2->setText(tr("删除所有场景"));
    ui->pushButton_3->setText(tr("更新场景"));

    ui->pushButton_4->setText(tr("添加字幕"));
    ui->pushButton_5->setText(tr("删除字幕"));
    ui->pushButton_6->setText(tr("更新字幕"));

    ui->pushButton_7->setText(tr("调色板"));
    ui->pushButton_8->setText(tr("设置字幕"));
    ui->pushButton_9->setText(tr("发送字幕"));

    ui->lineEdit->setText(tr("字幕1"));
    ui->lineEdit_2->setText("0");
    ui->lineEdit_2->setAlignment(Qt::AlignRight);
    ui->lineEdit_3->setText("0");
    ui->lineEdit_3->setAlignment(Qt::AlignRight);

    ui->frame->setAutoFillBackground(true);
    QColor color(255,0,0);
    QPalette p = ui->frame->palette();
    p.setColor(QPalette::Window,color);
    ui->frame->setPalette(p);


    //初始化通道
    ui->treeWidget->setColumnCount(1);
    ui->treeWidget->setHeaderLabel(tr("输入方式"));
    BCTreeData* m_rootlist = new BCTreeData(this);
    m_rootlist->DeviceInit(16);
    ui->treeWidget->insertTopLevelItems(0,m_rootlist->GetList());  //将结点数据插入部件中
    ui->treeWidget->expandAll();

    ui->treeWidget_2->setColumnCount(1);
    ui->treeWidget_2->setHeaderLabel(tr("字幕名称"));
    m_rootlist->ScreenInit();
    ui->treeWidget_2->insertTopLevelItems(0,m_rootlist->GetList());  //将结点数据插入部件中
    ui->treeWidget_2->expandAll();


    ui->gridLayout_btn->setSpacing(5);
    ui->gridLayout_btn->setMargin(5);


    connect(ui->treeWidget_2,SIGNAL(itemSelectionChanged()),this,SLOT(on_ScreenChange()));

//    QSpacerItem* vspacer = new  QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
//    QSpacerItem* hspacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
//    QGridLayout* layout1 = new QGridLayout();


//    ui->scrollAreaWidgetContents->setLayout(layout1);
//    layout1->addLayout(layout2,0,0);
//    layout1->add(vspacer,0,1);
//    layout1->addItem(hspacer,1,0);
}

BCScreenSet::~BCScreenSet()
{
    delete ui;
}

void BCScreenSet::on_pushButton_7_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white,this);
    QPalette p = ui->frame->palette();
    p.setColor(QPalette::Window,color);
    ui->frame->setPalette(p);
}

void BCScreenSet::on_pushButton_clicked()
{
    QString str = tr("场景")+QString("%1").arg(m_list.size());
//    BCScreenName* name = new BCScreenName(str);
//    if(name->exec() == QDialog::Accepted){
//        str = name->name;
//    }
//    else{
//        return;
//    }
    BCScreenBtn* btn = new BCScreenBtn();
    btn->setNum(m_list.size());
    btn->setText(str);
    btn->setName(str);
    m_list.append(btn);

    connect(btn,SIGNAL(signal_close(int)),this,SLOT(on_signal_close(int)));

    //添加控件的定位
    int row = (m_list.size()- 1) / 5;
    int column = (m_list.size() - 1) % 5;

    ui->gridLayout_btn->addWidget(btn,row,column);
}

void BCScreenSet::on_signal_close(int index){
    //删除所有
    QLayoutItem *sizeBtn;
    while((sizeBtn = ui->gridLayout_btn->takeAt(0)) !=0)
    {
        sizeBtn->widget()->setParent(0);
        delete sizeBtn;
    }
    //删除点击的按键
    for(int j = 0 ;j < m_list.size(); j++){
        if(m_list.at(j)->getNum() == index)
        {
            m_list.removeAt(j);
        }
     }
    //重新排列
    int column = 0;
    int row = 0;
    for(int i = 0 ;i < m_list.size(); i++){
        if(column == 5){
           column = 0;
           row++;
        }
        layout2->addWidget(m_list.at(i),row,column);
        column++;
    }
}

void BCScreenSet::on_ScreenChange(){
    QTreeWidgetItem* item = ui->treeWidget_2->currentItem();
    if(item->text(0) == tr("高鼎通0")){
        ui->lineEdit->setText(tr("字幕方式1"));
        ui->lineEdit_2->setText("0");
        ui->lineEdit_3->setText("0");

        QColor color(255,250,120);
        QPalette p = ui->frame->palette();
        p.setColor(QPalette::Window,color);
        ui->frame->setPalette(p);
    }
    else if(item->text(0) == tr("高鼎通1")){
        ui->lineEdit->setText(tr("字幕方式2"));
        ui->lineEdit_2->setText("1080");
        ui->lineEdit_3->setText("1920");

        QColor color(25,230,30);
        QPalette p = ui->frame->palette();
        p.setColor(QPalette::Window,color);
        ui->frame->setPalette(p);
    }
    else if(item->text(0) == tr("高鼎通2")){
        ui->lineEdit->setText(tr("字幕方式3"));
        ui->lineEdit_2->setText("70");
        ui->lineEdit_3->setText("23");


        QColor color(25,20,30);
        QPalette p = ui->frame->palette();
        p.setColor(QPalette::Window,color);
        ui->frame->setPalette(p);
    }
    else{
        ui->lineEdit->setText(tr("字幕方法"));
        ui->lineEdit_2->setText("170");
        ui->lineEdit_3->setText("123");


        QColor color(125,120,130);
        QPalette p = ui->frame->palette();
        p.setColor(QPalette::Window,color);
        ui->frame->setPalette(p);
    }
}

void BCScreenSet::on_pushButton_2_clicked()
{
    QLayoutItem *sizeBtn;
    while((sizeBtn = ui->gridLayout_btn->takeAt(0)) !=0)
    {
        sizeBtn->widget()->setParent(0);
        delete sizeBtn;
    }
    m_list.clear();
}
