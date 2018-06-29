#include "BCSettingSystemSet.h"
#include "ui_BCSettingSystemSet.h"
#include "BCSettingServerStyle.h"
#include "BCSettingTestWindowStyle.h"
#include "BCSettingPasswordStyle.h"
#include <QScrollBar>
#include <QDebug>
BCSettingSystemSet::BCSettingSystemSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCSettingSystemSet)
{
    ui->setupUi(this);
    ui->scrollArea->verticalScrollBar()->setStyleSheet("QScrollBar:vertical"
                                                        "{"
                                                            "width:12px;"
                                                            "background:rgba(0,0,0,0%);"
                                                            "margin:0px,0px,0px,0px;"
                                                            "padding-top:9px;"
                                                            "padding-bottom:9px;"
                                                        "}"

                                                        "QScrollBar::handle:vertical"
                                                        "{"
                                                            "width:12px;"
                                                            "background:rgba(0,0,0,25%);"
                                                            "border-radius:4px;"
                                                            "min-height:20;"
                                                        "}"

                                                        "QScrollBar::handle:vertical:hover"
                                                        "{"
                                                            "width:12px;"
                                                            "background:rgba(0,0,0,50%);"
                                                            "border-radius:4px;"
                                                            "min-height:20;"
                                                        "}"
                                                        "QScrollBar::add-line:vertical"
                                                        "{"
                                                            "height:9px;width:12px;"
                                                            "border-image:url(../resource/image/3.png);"
                                                            "subcontrol-position:bottom;"
                                                        "}"
                                                        "QScrollBar::sub-line:vertical"
                                                        "{"
                                                            "height:9px;width:12px;"
                                                            "border-image:url(../resource/image/1.png);"
                                                            "subcontrol-position:top;"
                                                        "}"
                                                        "QScrollBar::add-line:vertical:hover"
                                                        "{"
                                                            "height:9px;width:12px;"
                                                            "border-image:url(../resource/image/4.png);"
                                                            "subcontrol-position:bottom;"
                                                        "}"
                                                        "QScrollBar::sub-line:vertical:hover"
                                                        "{"
                                                            "height:9px;width:12px;"
                                                            "border-image:url(../resource/image/2.png);"
                                                            "subcontrol-position:top;"
                                                        "}"
                                                        "QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical"
                                                        "{"
                                                            "background:rgba(0,0,0,10%);"
                                                            "border-radius:4px;"
                                                        "}"
                                                        );
        connect(ui->scrollArea->verticalScrollBar(),SIGNAL(valueChanged(int)),this,SLOT(scrollAreaBarValueChange(int)));
        this->initSubViews();
}

BCSettingSystemSet::~BCSettingSystemSet()
{
        delete ui;
}
/*
* 初始化界面布局
 */
void BCSettingSystemSet::initSubViews()
{
       this->layout()->setMargin(0);
       this->layout()->setSpacing(0);
       ui->leftLayout->setMargin(0);
       ui->scrollArea->setStyleSheet("QScrollArea{background-color:rgb(255,255,255);  color: white;"
                                     " border-radius: 0px;  border: 0px groove gray;}");

       ui->pushButton->setText(tr("       日志查询"));
       ui->pushButton_2->setText(tr("       用户管理"));
       ui->pushButton_3->setText(tr("       配置文件"));
       ui->pushButton_4->setText(tr("       修改密码"));
       ui->pushButton_5->setText(tr("       备份及还原"));
       ui->pushButton_6->setText(tr("       版本信息"));
       ui->pushButton_7->setText(tr("       关于我们"));
       ui->pushButton_8->setText(tr("       软件认证"));
       connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));
       connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));
       connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));
       connect(ui->pushButton_4,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));
       connect(ui->pushButton_5,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));
       connect(ui->pushButton_6,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));
       connect(ui->pushButton_7,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));
       connect(ui->pushButton_8,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));
       _lastLeftBut = ui->pushButton;
       _lastLeftBut->setStyleSheet("QPushButton{background-color:rgb(255,255,255);  color: black;  "
                          " border-radius: 0px;  border: 0px groove gray;}"
                          "QPushButton:hover{background-color:rgb(205, 205, 205); color: black;}"
                          "QPushButton{text-align:left;}");



       QVBoxLayout *pScrollLayout = new QVBoxLayout;
       _pScrollLayout = pScrollLayout;
       ui->scrollArea->widget()->setLayout(pScrollLayout);


       QStringList texts_log;
       texts_log<<"日志查询:"<<"您可以按用户名、事件、时间段查询具体的操作日志"<<"日志查询";
       this->createSimpleStyle(texts_log,BCSettingSimpleStyle::queryLog);



       QStringList texts_user;
       texts_user<<"用户管理:"<<"管理员可以设置当前所有用户的权限"<<"用户管理";
       this->createSimpleStyle(texts_user,BCSettingSimpleStyle::userManagement);


       QStringList texts_file;
       texts_file<<"配置文件:"<<"通过修改文件路径修改配置文件"<<"查看路径";
       this->createSimpleStyle(texts_file,BCSettingSimpleStyle::configurationFilePath);

       BCSettingPasswordStyle *password = new BCSettingPasswordStyle(ui->scrollArea->widget());
       _pScrollLayout->addWidget(password);


    //?????备份还原--
       QStringList texts_backUp;
       texts_backUp<<"备份、还原:"<<"可备份当前设备状态、需要时一键恢复便可读取云信息"<<"备份";
       this->createSimpleStyle(texts_backUp,BCSettingSimpleStyle::back_up);


       QStringList texts_info;
       texts_info<<"版本信息:"<<"当前版本：  2.0"<<"检查更新";
       this->createSimpleStyle(texts_info,BCSettingSimpleStyle::lookForUpdates);


       QStringList texts_auoutUs;
       texts_auoutUs<<"关于我们:"<<"更多了解BR管理系统"<<"关于我们";
       this->createSimpleStyle(texts_auoutUs,BCSettingSimpleStyle::aboutUs);


       QStringList texts_softWall;
       texts_softWall<<"软件认证:"<<"您可以设置相关参数后控制外围设备"<<"软件认证";
       this->createSimpleStyle(texts_softWall,BCSettingSimpleStyle::aboutUs);
       _pScrollLayout->addStretch();

}
/*
* 创建simple类型的widget
 */
void BCSettingSystemSet::createSimpleStyle(QStringList list,BCSettingSimpleStyle::PushButtonFunction butFunction)
{
       BCSettingSimpleStyle *simple = new BCSettingSimpleStyle(ui->scrollArea->widget(),&list,butFunction);
       _pScrollLayout->addWidget(simple);

}
/*
*点击了左侧的but
*/
int mark = 0;
void BCSettingSystemSet::clickLeftLabel()
{
       QPushButton *but = static_cast <QPushButton *> (sender());
        _lastLeftBut->setStyleSheet("QPushButton{background-color:rgb(235,235,235);  color: black;  "
                                    " border-radius: 0px;  border: 0px groove gray;}"
                                    "QPushButton:hover{background-color:rgb(205, 205, 205); color: black;}"
                                    "QPushButton{text-align:left;}");
       but->setStyleSheet("QPushButton{background-color:rgb(255,255,255);  color: black;  "
                          " border-radius: 0px;  border: 0px groove gray;}"
                          "QPushButton:hover{background-color:rgb(205, 205, 205); color: black;}"
                          "QPushButton{text-align:left;}");
        _lastLeftBut = but;

        if(mark == 3){
             mark = 0;
             return;
        }
        int value = 0;
        if(but == ui->pushButton_2){
           value = 90;
        }else if(but == ui->pushButton_3){
            value = 165;
        }else if(but == ui->pushButton_4){
            value = 237;
        }else if(but == ui->pushButton_5){

            value = 319;
        }else if (but == ui->pushButton_6){
            value = 397;
        }else if (but == ui->pushButton_7){
            value = 470;
        }else if (but == ui->pushButton_8){
            value = 550;
        }

         ui->scrollArea->verticalScrollBar()->setValue(value);

}

/*
*滚动条的值改变了
 */
void BCSettingSystemSet::scrollAreaBarValueChange(int value)
{
        mark = 3;
       if(value <= 68){

            ui->pushButton->clicked(true);

       }else if (value >68  && value < 141){
            ui->pushButton_2->clicked(true);

       }else if(value >= 141 && value < 218){
            ui->pushButton_3->clicked(true);

       }else if(value >= 218 && value < 314){

            ui->pushButton_4->clicked(true);

       }else if(value>=314 && value < 388){

            ui->pushButton_5->clicked(true);

       }else if(value>=388 && value < 458){

            ui->pushButton_6->clicked(true);

       }else if(value>=458 && value < 534){

            ui->pushButton_7->clicked(true);

    }else{
            ui->pushButton_8->clicked(true);
       }


}
void BCSettingSystemSet::test()
{

}
