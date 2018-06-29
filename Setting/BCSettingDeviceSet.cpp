#include "BCSettingDeviceSet.h"
#include "ui_BCSettingDeviceSet.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QDebug>
#include <QScrollBar>
#include "UILabel.h"

#include "BCSettingServerStyle.h"
#include "BCSettingTestWindowStyle.h"
BCSettingDeviceSet::BCSettingDeviceSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCSettingDeviceSet)
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
    /*
   *初始化界面
     */
    this->initSubViews();

}

BCSettingDeviceSet::~BCSettingDeviceSet()
{
    delete ui;
}


 /*
* 初始化界面布局
  */
void BCSettingDeviceSet::initSubViews()
{
        ui->scrollArea->setStyleSheet("QScrollArea{background-color:rgb(255,255,255);  color: white;"
                                      " border-radius: 0px;  border: 0px groove gray;}");

        this->layout()->setMargin(0);
        ui->leftLayout->setMargin(0);


        ui->pushButton->setText(tr("      服务器通讯"));
        _lastLeftBut = ui->pushButton;
        ui->pushButton->setStyleSheet("QPushButton{background-color:rgb(255,255,255);  color: black;  "
                              " border-radius: 0px;  border: 0px groove gray;}"
                              "QPushButton:hover{background-color:rgb(205, 205, 205); color: black;}"
                              "QPushButton{text-align:left;}");
        ui->pushButton_2->setText(tr("      板位图"));
        ui->pushButton_3->setText(tr("      自动开关机"));
        ui->pushButton_4->setText(tr("      硬件参数设置"));
        ui->pushButton_5->setText(tr("      测试窗口"));
        ui->pushButton_6->setText(tr("      检测设备"));
        ui->pushButton_7->setText(tr("      EDID"));
        ui->pushButton_8->setText(tr("      外设控制"));
        connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));
        connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));
        connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));
        connect(ui->pushButton_4,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));
        connect(ui->pushButton_5,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));
        connect(ui->pushButton_6,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));
        connect(ui->pushButton_7,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));
        connect(ui->pushButton_8,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));

        QVBoxLayout *pScrollLayout = new QVBoxLayout;
        _pScrollLayout = pScrollLayout;
        ui->scrollArea->widget()->setLayout(pScrollLayout);


        BCSettingServerStyle *server = new BCSettingServerStyle(ui->scrollArea->widget());
        pScrollLayout->addWidget(server);


        QStringList texts;
        texts<<"板位图:"<<"查看当前设置板位图"<<"查看板位图";
         this->createSimpleStyle(texts,BCSettingSimpleStyle::boardBitmap);

        QStringList texts_on;
        texts_on<<"自动开关机:"<<"您可以设置定时任务例如：开关机、轮巡等"<<"开关机设置";
        this->createSimpleStyle(texts_on,BCSettingSimpleStyle::takeOn_of);


        QStringList texts_hardWall;
        texts_hardWall<<"硬件参数设置:"<<"设置该设备的相关详细参数"<<"参数设置";
        this->createSimpleStyle(texts_hardWall,BCSettingSimpleStyle::hardwareParameters);


        QStringList texts_label;
        texts_label<<"窗口测试："<<"您可以选择不同的风格进行窗口测试：";
        QStringList texts_com;
        texts_com<<"网格测试"<<"灰色";
        BCSettingTestWindowStyle *testWindow = new BCSettingTestWindowStyle(ui->scrollArea->widget(),&texts_label,&texts_com);
        pScrollLayout->addWidget(testWindow);



        QStringList texts_query;
        texts_query<<"检测设备:"<<"检测局域网设备，并读取相关配置"<<"检测设备";
        this->createSimpleStyle(texts_query,BCSettingSimpleStyle::queryDevice);


        QStringList texts_EDID;
        texts_EDID<<"EDID:"<<"读取当前设备的EDID出入值"<<"EDID";
        this->createSimpleStyle(texts_EDID,BCSettingSimpleStyle::EDID);


        QStringList texts_controll;
        texts_controll<<"外设控制:"<<"您可以设置相关参数后控制外围设备"<<"外设控制";
        this->createSimpleStyle(texts_controll,BCSettingSimpleStyle::deviceControl);
        _pScrollLayout->addStretch();

}
 /*
* 创建simple类型的widget
  */
void BCSettingDeviceSet::createSimpleStyle(QStringList list,BCSettingSimpleStyle::PushButtonFunction butFunction)
{
        BCSettingSimpleStyle *simple = new BCSettingSimpleStyle(ui->scrollArea->widget(),&list,butFunction);
        _pScrollLayout->addWidget(simple);

}

void BCSettingDeviceSet::test()
{

}


/*
*点击了左侧的but
*/
int whose = 0;
void BCSettingDeviceSet::clickLeftLabel()
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

        if(whose == 3){
             whose = 0;
             return;
        }
        int value = 0;
        if(but == ui->pushButton_2){
           value = 100;
        }else if(but == ui->pushButton_3){
            value = 170;
        }else if(but == ui->pushButton_4){
            value = 242;
        }else if(but == ui->pushButton_5){

            value = 315;
        }else if (but == ui->pushButton_6){
            value = 387;
        }else if (but == ui->pushButton_7){
            value = 460;
        }else if (but == ui->pushButton_8){
            value = 536;
        }

         ui->scrollArea->verticalScrollBar()->setValue(value);

}

/*
*滚动条的值改变了
 */
void BCSettingDeviceSet::scrollAreaBarValueChange(int value)
{
        whose = 3;

       if(value <= 99){

             ui->pushButton->clicked(true);

       }else if (value > 99 && value < 170){
             ui->pushButton_2->clicked(true);

       }else if(value >= 170 && value < 239){
             ui->pushButton_3->clicked(true);

       }else if(value >= 239 && value < 315){

             ui->pushButton_4->clicked(true);

       }else if(value>=315 && value < 387){

             ui->pushButton_5->clicked(true);

       }else if(value>=387 && value < 460){

             ui->pushButton_6->clicked(true);

       }else if(value>=460 && value < 536){

             ui->pushButton_7->clicked(true);

       }else{

             ui->pushButton_8->clicked(true);
       }


}
