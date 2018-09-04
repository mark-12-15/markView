#include "systemsetting.h"
#include "ui_systemsetting.h"
#include <QDebug>
#include <QColorDialog>
#include <QComboBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QPainter>
#include <QPicture>
#include <QScrollBar>
#include <QMouseEvent>
#include "mydialog.h"
#include "logindialog.h"
#include "../Common/BCCommon.h"
#include "UIButton.h"
#include "BCSetingCustomSkin.h"
#include "BCSettingDeviceSet.h"
#include "BCSettingSystemSet.h"
#include "BCSettingMainPanelStyle.h"
#include "BCSettingDisplyModelStyle.h"
#include "BCSettingChangeLanguageStyle.h"
bool didCreatedDeviceLabel;//记录是否已经创建过deviceLabel
bool didCreatedSystemLabel;//记录有没有已经创建过systemLabel
bool didCreatedAddSkinLabel;//记录有没有已经点击过+号创建过Label


SystemSetting::SystemSetting(SelectedDisplay selected, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemSetting)
{
    ui->setupUi(this);
    setWindowTitle(tr("更多设置"));
     this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));
    _selectedPosition = selected;

    setFixedSize(675,470);
    this->layout()->setMargin(0);
    didCreatedDeviceLabel = false;
    didCreatedAddSkinLabel = false;
    didCreatedSystemLabel = false;

   this->setScrollBar(ui->scrollArea);

    QLabel *topBack = new QLabel(this);
    topBack->move(0,0);
    topBack->resize(675,50);
    topBack->setStyleSheet("background-color:rgb(235,235,235);  color: black;");
   this->createTopButton(topBack,"屏幕显示",QPoint(10,15),BCCommon::g_qsImageFilePrefix+"default/display.jpg");
   this->createTopButton(topBack,"设备设置",QPoint(140,15),BCCommon::g_qsImageFilePrefix+"default/softWall.jpg");
   this->createTopButton(topBack,"系统设置",QPoint(270,15),BCCommon::g_qsImageFilePrefix+"default/user.jpg");
    connect(ui->scrollArea->verticalScrollBar(),SIGNAL(valueChanged(int)),SLOT(scrollAreaBarValueChange(int)));

     // ui->label_mainPanel->setText(tr("主面版"));
    QLabel *leftBack = new QLabel(this);
    leftBack->setStyleSheet("background-color:rgb(235,235,235);  color: black;");
    leftBack->setMinimumWidth(110);
    ui->leftVLayout->addWidget(leftBack);
    QVBoxLayout *leftBackLayout = new QVBoxLayout;
    leftBackLayout->setMargin(0);
    leftBackLayout->setSpacing(0);
    leftBack->setLayout(leftBackLayout);
    this->createLeftUILabel(leftBack,"   主面版",QPoint(0,0));
    this->createLeftUILabel(leftBack,"   皮肤",QPoint(0,0));
    this->createLeftUILabel(leftBack,"   登陆",QPoint(0,0));
    this->createLeftUILabel(leftBack,"   显示模式",QPoint(0,0));
    this->createLeftUILabel(leftBack,"   语言选择",QPoint(0,0));
    this->createLeftUILabel(leftBack,"   自定义工具条",QPoint(0,0));
   // ui->leftVLayout->addStretch();
    leftBackLayout->addStretch();
    _label_back1 = _labelBacks.at(0).value<UILabel *>();
    _label_back2 = _labelBacks.at(1).value<UILabel *>();
    _label_back3 = _labelBacks.at(2).value<UILabel *>();
    _label_back4 = _labelBacks.at(3).value<UILabel *>();
    _label_back5 = _labelBacks.at(4).value<UILabel *>();
    _label_back6 = _labelBacks.at(5).value<UILabel *>();


   //创建自定义工具条里面的label
   this->createImageLabelInCustomeTool("D:/images/tool4.jpg",QPoint(10,8));
   this->createImageLabelInCustomeTool("D:/images/tool5.png",QPoint(50,8));
   this->createImageLabelInCustomeTool("D:/images/tool7.png",QPoint(90,8));
   this->createImageLabelInCustomeTool("D:/images/tool6.jpg",QPoint(130,8));
   this->createImageLabelInCustomeTool("D:/images/tool2.jpg",QPoint(170,8));

    //--------------------chuangjian----------------
    QVBoxLayout *pScrollLayout = new QVBoxLayout;
    _pScrollLayout = pScrollLayout;
    ui->scrollArea->widget()->setLayout(pScrollLayout);

    QStringList text_mainPanel;
    text_mainPanel<<"主面版："<<"关闭面板时："<<"隐藏到任务栏通知区域不退出程序"<<"退出程序";
    BCSettingMainPanelStyle *mainPanel = new BCSettingMainPanelStyle(this,&text_mainPanel);
    _pScrollLayout->addWidget(mainPanel);


    QStringList text_skin;
    text_skin<<"皮肤："<<"您可以自由定制适合您的界面风格："<<"皮肤设置";
     this->createSimpleStyle(text_skin,BCSettingSimpleStyle::creatSkinClection);

    QStringList text_login;
    text_login<<"登陆："<<"自定义登陆界面布局："<<"去设置";
     this->createSimpleStyle(text_login,BCSettingSimpleStyle::setLoginView);

    QStringList text_displayModel;
    text_displayModel<<"显示模式："<<"初始化显示模式："<<"正常"<<"W"<<"1000"<<"H"<<"600"<<"最大化"<<"全屏";
    BCSettingDisplyModelStyle *displayWidget = new BCSettingDisplyModelStyle(this,&text_displayModel);
    _pScrollLayout->addWidget(displayWidget);


    QStringList text_language;
    text_language<<"语言选择："<<"设置程序语言为："<<"中文"<<"根据地区智能更换语言"<<"当前地区改编后在程序启动时友好提示";
    BCSettingChangeLanguageStyle *languageWidget = new BCSettingChangeLanguageStyle(this,&text_language);
    _pScrollLayout->addWidget(languageWidget);
    _pScrollLayout->addStretch();


    setWindowTitle(tr("屏幕显示"));
 //this->shouldImplicated(_selectedPosition);


}

SystemSetting::~SystemSetting()
{
    delete ui;
}

/*
*点击顶部按钮事件  隐藏当前显示的视图进行页面切换
 */
void SystemSetting::clickDisplayLab()
{
    QPushButton *but = static_cast<QPushButton *> (sender());
    _lastItemLableClicked->setStyleSheet("QPushButton{background-color:rgb(241,241,241);  color:black;}"
                                         "QPushButton:hover{color:black;" "border-radius: 0px;  border: 0.5px groove gray;}");
    but->setStyleSheet("QPushButton{background-color:rgb(241,241,241);  color:rgb(39,140,222);}"
                       "QPushButton:hover{color:rgb(39,140,222);" "border-radius: 0px;  border: 0.5px groove gray;}");
   _lastItemLableClicked = but;

    if(didCreatedSystemLabel == true){
         // _systemLabel->hide();
        _systemWidget->hide();
    }
    if(didCreatedDeviceLabel == true){
       // _deviceLabel->hide();
        _deviceWidget->hide();
    }

    if(but->text() == "系统设置"){
        setWindowTitle(tr("系统设置"));
        if(didCreatedSystemLabel == true){
            _systemWidget->show();
            return;
        }
            BCSettingSystemSet *systemSet = new BCSettingSystemSet(this);
            didCreatedSystemLabel = true;
            _systemWidget = systemSet;
            systemSet->move(-5,50);
            systemSet->resize(680,430);
            systemSet->show();
        //this->creatSystemView();
        return;
    }
    if(but->text() == "设备设置"){
        setWindowTitle(tr("设备设置"));
        if(didCreatedDeviceLabel == true){

            _deviceWidget->show();
            return;
        }
        BCSettingDeviceSet *deviceSet = new BCSettingDeviceSet(this);
        didCreatedDeviceLabel = true;
        _deviceWidget = deviceSet;
        deviceSet->move(0,50);
        deviceSet->resize(676,430);
       deviceSet->show();
        //this->creatDeviceView();
        return;
    }

}

/*
* 创建simple类型的widget
 */
void SystemSetting::createSimpleStyle(QStringList list,BCSettingSimpleStyle::PushButtonFunction butFunction)
{
   BCSettingSimpleStyle *simple = new BCSettingSimpleStyle(ui->scrollArea->widget(),&list,butFunction);
   _pScrollLayout->addWidget(simple);

}


  /*
*点击了Cancel按钮的信号槽
  */
void SystemSetting::clickCancelBut()
{
    _custemSkinLabel->hide();
}

/*
* 点击了主面版、皮肤、登陆等label
*/
int which = 0;
void SystemSetting::clickFirstViewLeftLabel(UILabel *label)
{


    _lastLabelClicked->setStyleSheet("UILabel:hover{background-color:rgb(205, 205, 205); color: black;}");

    _lastLabelClicked = label;

     label->setStyleSheet("UILabel{background-color:white;  color: black;}"
                     "UILabel:hover{background-color:rgb(205, 205, 205); color: black;}");


     if(which == 3){
          which = 0;
          return;
     }
     int value = 0;


     if(label == _label_back2){
        value = 100;
     }else if(label == _label_back3){
         value = 185;
     }else if(label == _label_back4){
         value = 260;
     }else if(label == _label_back5){
         value = 420;
     }else if (label == _label_back6){
         value = 530;
     }  

      ui->scrollArea->verticalScrollBar()->setValue(value);
}


/*
* 滑动了scrollArea的滚动条
*/
void SystemSetting::moveUILabel(int ofset)
{

   // ui->scrollArea_tool->horizontalScrollBar()->setValue( ui->scrollArea_tool->horizontalScrollBar()->value() + ofset);

}

 /*
* 取消按钮信号槽
  */
void SystemSetting::clickCancel()
{
    this->close();
}
/*
*创建顶部的三个按钮
 */
void SystemSetting::createTopButton(QLabel *parent, QString title, QPoint point, QString pictur)
{
             QFont font("微软雅黑",10);
    QPushButton *label_system = new QPushButton(parent);
             label_system->setText(title);
             label_system->resize(100,30);
             label_system->setIconSize(QSize(16,16));
             label_system->move(point);
             label_system->setFont(font);
            QPixmap system_img(pictur);
            system_img = system_img.scaled(39,39,Qt::KeepAspectRatio);
            label_system->setIcon(QIcon(system_img));
            label_system->setFlat(true);
            label_system->setStyleSheet("QPushButton{background-color:rgb(241,241,241);  color: black;}"
                                        "QPushButton:hover{color: black;" "border-radius: 0px;  border: 0.5px groove gray;}");
            if(title == "设备设置")
            {
                _label_device = label_system;

            }
            else if(title == "系统设置")
            {
                 _label_system = label_system;
            }
            else
            {
                _label_display = label_system;
               _lastItemLableClicked = label_system;//默认刚进来选中显示
                label_system->setStyleSheet("QPushButton{background-color:rgb(241,241,241);  color:rgb(39,140,222);}"
                                             "QPushButton:hover{color: rgb(39,140,222);" "border-radius: 0px;  border: 0.5px groove gray;}");
            }

  connect(label_system,SIGNAL(clicked(bool)),this,SLOT(clickDisplayLab()));


}

/*
*创建左侧的UILabel
 */
void SystemSetting::createLeftUILabel(QLabel *parent,QString title, QPoint point)
{
    QFont font("微软雅黑",9);
      UILabel *labelBack = new UILabel(parent);
      labelBack->setFont(font);
      labelBack->setText(title);
      labelBack->setFont(font);
      labelBack->setMargin(7);

      connect(labelBack,SIGNAL(Clicked(UILabel*)),this,SLOT(clickFirstViewLeftLabel(UILabel*)));
      if(title == "   主面版")
      {
          labelBack->setStyleSheet("QLabel{background-color:white;  color: black;}"
                                   "QLabel:hover{background-color:rgb(205, 205, 205); color: black;}");
          _lastLabelClicked = labelBack;
      }
      else
      {
          labelBack->setStyleSheet("QLabel:hover{background-color:rgb(205, 205, 205); color: black;}");

      }
     // ui->leftVLayout->addWidget(labelBack);

    parent->layout()->addWidget(labelBack);
      QVariant variant;
      variant.setValue(labelBack);
      _labelBacks.append(variant);

}

void SystemSetting::setScrollBar(QScrollArea *area)
{

    area->verticalScrollBar()->setStyleSheet("QScrollBar:vertical"
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
    ui->scrollArea->setStyleSheet("QScrollArea{background-color:rgb(255,255,255);  color: white;"
                                  " border-radius: 0px;  border: 0px groove gray;}");

}

/*
*创建自定义工具条中的Label
 */
void SystemSetting::createImageLabelInCustomeTool(QString imagePath, QPoint point)
{
   /*
    QPixmap img5(imagePath);
           img5 = img5.scaled(25,25,Qt::KeepAspectRatio);
           UILabel *label_scrollTool5 = new UILabel(ui->scrollAreaWidgetContents_2);
           label_scrollTool5->resize(40,30);
           label_scrollTool5->move(point);
           label_scrollTool5->setPixmap(img5);
           connect(label_scrollTool5,SIGNAL(mouseMove(int)),this,SLOT(moveUILabel(int)));
           */
}

/*
*滚动条的值改变了
 */
void SystemSetting::scrollAreaBarValueChange(int value)
{
    which = 3;
   if(value <= 90){
       this->clickFirstViewLeftLabel(_label_back1);

   }else if (value > 90 && value < 168){
       this->clickFirstViewLeftLabel(_label_back2);
   }else if(value >= 168 && value < 235){
        this->clickFirstViewLeftLabel(_label_back3);
   }else if(value >= 235 && value < 366){
       this->clickFirstViewLeftLabel(_label_back4);
   }else if(value>=366 && value < 600){
       this->clickFirstViewLeftLabel(_label_back5);
   }
}

void SystemSetting::mousePressEvent(QMouseEvent *event)
{

    if(didCreatePop == 88){
        _skinPopLabel->hide();

    }
}
 /*
* 滚轮事件
  */
void SystemSetting::wheelEvent(QWheelEvent *event)
{
    //qDebug()<<ui->scrollArea->verticalScrollBar()->value()<<"滚轮阿----";
}
