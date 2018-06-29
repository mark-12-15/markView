#include "BCSettingSkinSet.h"
#include "ui_BCSettingSkinSet.h"
#include "BCSettingTestWindowStyle.h"
#include <QScrollBar>
BCSettingSkinSet::BCSettingSkinSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCSettingSkinSet)
{
    ui->setupUi(this);
    setWindowTitle(tr("主场景"));
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

    ui->scrollArea->setStyleSheet("QScrollArea{background-color:rgb(240,240,240);  color: white;"
                                  " border-radius: 0px;  border: 0px groove gray;}");
   // connect(ui->scrollArea->verticalScrollBar(),SIGNAL(valueChanged(int)),this,SLOT(scrollAreaBarValueChange(int)));

    /*
   *初始化界面
     */
    this->initSubViews();
}

BCSettingSkinSet::~BCSettingSkinSet()
{
        delete ui;
}
/*
* 初始化界面布局
 */
void BCSettingSkinSet::initSubViews()
{
        this->layout()->setMargin(0);
        this->layout()->setSpacing(0);

    //   float width = 80;
    //   float height = 50;

       ui->topLabel->setStyleSheet("background-color:rgb(235, 235, 235); color: black;");
         QLabel *topLabel = new QLabel(ui->topLabel);
         topLabel->resize(80,40);
         topLabel->move(10 ,5);
         QFont topFont("微软雅黑",10);
         topLabel->setFont(topFont);
         topLabel->setText(tr("主场景"));
        topLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
       // topLabel->setStyleSheet("QLabel:hover{background-color:rgb(93, 182, 179); color: black;}");

       ui->pushButton->setText(tr("      背景墙"));
       _lastLeftBut = ui->pushButton;
       ui->pushButton_2->setText(tr("      显示器"));
       ui->pushButton_3->setText(tr("      显示器内虚框"));
       ui->pushButton_4->setText(tr("      开窗"));
       ui->pushButton_5->setText(tr("      开窗标题"));
       ui->pushButton_6->setText(tr("      开创主题"));
       connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));
       connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));
       connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));
       connect(ui->pushButton_4,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));
       connect(ui->pushButton_5,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));
       connect(ui->pushButton_6,SIGNAL(clicked(bool)),this,SLOT(clickLeftLabel()));
       _lastLeftBut->setStyleSheet("QPushButton{background-color:rgb(255,255,255);  color: black;  "
                          " border-radius: 0px;  border: 0px groove gray;}"
                          "QPushButton:hover{background-color:rgb(205, 205, 205); color: black;}"
                          "QPushButton{text-align:left;}");

       QVBoxLayout *pScrollLayout = new QVBoxLayout;
       _pScrollLayout = pScrollLayout;
       ui->scrollArea->widget()->setLayout(pScrollLayout);

       QStringList texts;
       texts<<"填充颜色:"<<"您可以自定义填充颜色："<<"";
        this->createSimpleStyle(texts,BCSettingSimpleStyle::choiceColor);


       QVariant variant;
       QStringList texts_linW;
       texts_linW<<"线宽："<<"设置线条宽度默认是二号：";
       QStringList texts_linCom;
       texts_linCom<<"一号"<<"二号"<<"三号";
       BCSettingTestWindowStyle *lineWidth = new BCSettingTestWindowStyle(ui->scrollArea->widget(),&texts_linW,&texts_linCom);
       pScrollLayout->addWidget(lineWidth);
       variant.setValue(lineWidth);
       _allViews.append(variant);


       QStringList texts_lineStyle;
       texts_lineStyle<<"线条类型："<<"选择适合的线条类型：";
       QStringList texts_lineStyleCom;
       texts_lineStyleCom<<"网格测试"<<"灰色";
       BCSettingTestWindowStyle *lineStyle = new BCSettingTestWindowStyle(ui->scrollArea->widget(),&texts_lineStyle,&texts_lineStyleCom);
       pScrollLayout->addWidget(lineStyle);
       variant.setValue(lineStyle);
       _allViews.append(variant);


       QStringList texts_postion;
       texts_postion<<"文字位置："<<"您可以按照个人喜好设置文字的位置：";
       QStringList texts_postionCom;
       texts_postionCom<<"屏幕正下方"<<"屏幕中间"<<"屏幕正上方"<<"屏幕左上侧";
       BCSettingTestWindowStyle *linePosition = new BCSettingTestWindowStyle(ui->scrollArea->widget(),&texts_postion,&texts_postionCom);
       pScrollLayout->addWidget(linePosition);
       pScrollLayout->addStretch();
       variant.setValue(linePosition);
       _allViews.append(variant);
}
/*
* 创建simple类型的widget
 */
void BCSettingSkinSet::createSimpleStyle(QStringList list,BCSettingSimpleStyle::PushButtonFunction butFunction)
{
       BCSettingSimpleStyle *simple = new BCSettingSimpleStyle(ui->scrollArea->widget(),&list,butFunction);
       _pScrollLayout->addWidget(simple);

}

 /*
*点击了左侧的but
 */
int skinButClick = 0;
void BCSettingSkinSet::clickLeftLabel()
{
        QPushButton *but = static_cast <QPushButton *> (sender());
        if(but->text() == "      背景墙")
        {
           for(int i = 0; i<_allViews.size();i++){
               _allViews.at(i).value<QWidget *>()->setEnabled(false);
           }
        }else{
            for(int i = 0; i<_allViews.size();i++){
                _allViews.at(i).value<QWidget *>()->setEnabled(true);
            }
        }
        _lastLeftBut->setStyleSheet("QPushButton{background-color:rgb(235,235,235);  color: black;  "
                                    " border-radius: 0px;  border: 0px groove gray;}"
                                    "QPushButton:hover{background-color:rgb(205, 205, 205); color: black;}"
                                    "QPushButton{text-align:left;}");
       but->setStyleSheet("QPushButton{background-color:rgb(255,255,255);  color: black;  "
                          " border-radius: 0px;  border: 0px groove gray;}"
                          "QPushButton:hover{background-color:rgb(205, 205, 205); color: black;}"
                          "QPushButton{text-align:left;}");
        _lastLeftBut = but;
        if(skinButClick == 3){
             skinButClick = 0;
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
        }

        // ui->scrollArea->verticalScrollBar()->setValue(value);
}
/*
*滚动条的值改变了
 */
void BCSettingSkinSet::scrollAreaBarValueChange(int value)
{
        skinButClick = 3;

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

       }

}
