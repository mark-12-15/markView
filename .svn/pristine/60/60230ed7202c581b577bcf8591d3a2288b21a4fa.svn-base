#include "AlarmManagement.h"
#include "ui_AlarmManagement.h"
#include "../Common/BCCommon.h"

AlarmManagement::AlarmManagement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlarmManagement)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    setWindowTitle(tr("报警管理"));
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));

    init();
}

AlarmManagement::~AlarmManagement()
{
    delete ui;
}
/*
*全选按钮事件
 */
void AlarmManagement::on_pushButton_clicked()
{
    this->checkAllBoxByTopLeavelIndex(0,true);
    this->checkAllBoxByTopLeavelIndex(1,true);

}

 /*
* 全不选
  */
void AlarmManagement::on_pushButton_2_clicked()
{
   this->checkAllBoxByTopLeavelIndex(0,false);
   this->checkAllBoxByTopLeavelIndex(1,false);

}
void AlarmManagement::checkAllBoxByTopLeavelIndex(int index, bool clickState)
{
    QTreeWidgetItem *topLeavel = ui->treeWidget->topLevelItem(index);
    QCheckBox *box_1 = static_cast <QCheckBox *> (ui->treeWidget->itemWidget(topLeavel,0));
    box_1->setChecked(clickState);
    this->changeBoxStateInSection(box_1,index);
}
void AlarmManagement::on_pushButton_4_clicked()
{
    close();
}

void AlarmManagement::AddTreeNode(QTreeWidgetItem *root, QStringList texts)
{
    for(int i = 0; i < texts.size(); i++)
    {
        QCheckBox *box = new QCheckBox;
        box->setText(texts.at(i));
        QTreeWidgetItem *node = new QTreeWidgetItem;
        root->addChild(node);
        ui->treeWidget->setItemWidget(node,0,box);
    }
}
 /*
*点击了分组的checkBox
  */
void AlarmManagement::clickSectionBox()
{
    QCheckBox *box_section = static_cast <QCheckBox *> (sender());

    if(box_section->text() == "硬件")
    {
      this->changeBoxStateInSection(box_section,0);
    }
    else
    {
        this->changeBoxStateInSection(box_section,1);
    }

}
 /*
* 一次性选取该分组下的所有checkBox
  */
void AlarmManagement::changeBoxStateInSection(QCheckBox *section, int index)
{
    QTreeWidgetItem *root =  ui->treeWidget->topLevelItem(index);
    int childre_count =  root->childCount();
    for(int i = 0; i < childre_count; i++)
    {
       QCheckBox *box = static_cast <QCheckBox *> (ui->treeWidget->itemWidget(root->child(i),0));

         box->setChecked(section->isChecked());
    }

}

void AlarmManagement::on_pushButton_3_clicked()
{
    close();
}

void AlarmManagement::init()
{
    ui->treeWidget->setColumnCount(1);
    ui->treeWidget->setHeaderLabels(QStringList(tr("报警提示过滤器")));
    QTreeWidgetItem *root_1 = new QTreeWidgetItem;
    ui->treeWidget->addTopLevelItem(root_1);

    QCheckBox *box_1 = new QCheckBox;
    box_1->setText(tr("硬件"));
    ui->treeWidget->setItemWidget(root_1,0,box_1);

    QStringList texts;
    texts << tr("设备温度超过65度")
          << tr("设备分扇转速低于100转/分钟")
          << tr("设备分扇转速低高于300转/分钟")
          << tr("设备板卡工作异常")
          << tr("设备信息配置异常")
          << tr("设备有热插拔操作")
          << tr("当前输出分辨率非显示终端最佳分辨率")
          << tr("Admin管理员异地登陆")
          << tr("显示温度超过65度")
          << tr("显示单元风扇转速低于100转/分钟")
          << tr("入口信号丢失")
          << tr("系统数据被外部软件修改")
          << tr("有新版本软件，需要升级")
          << tr("用户密码，3分钟内错误输入5次")
          << tr("异常关机，系统数据恢复");

    this->AddTreeNode(root_1,texts);

    QTreeWidgetItem *root_2 = new QTreeWidgetItem;
    ui->treeWidget->addTopLevelItem(root_2);

    QCheckBox *box_2 = new QCheckBox;
    box_2->setText(tr("显示"));
    ui->treeWidget->setItemWidget(root_2,0,box_2);

    this->AddTreeNode(root_2,texts);

    connect(box_1,SIGNAL(clicked(bool)),this,SLOT(clickSectionBox()));
    connect(box_2,SIGNAL(clicked(bool)),this,SLOT(clickSectionBox()));
}
