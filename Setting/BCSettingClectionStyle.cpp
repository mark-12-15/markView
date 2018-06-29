#include "BCSettingClectionStyle.h"
#include "ui_BCSettingClectionStyle.h"
#include <QLabel>
#include <QPushButton>
#include "../Common/BCCommon.h"
BCSettingClectionStyle::BCSettingClectionStyle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCSettingClectionStyle)
{
           ui->setupUi(this);
           this->setFixedSize(300,205);
           setWindowTitle(tr("皮肤设置"));

           initSubViews();
}

BCSettingClectionStyle::~BCSettingClectionStyle()
{
           delete ui;
}
 /*
*初始化界面
 */
void BCSettingClectionStyle::initSubViews()
{
          //创建label内部的子试图
           QLabel *subLabel = new QLabel(this);
           float width = 300;
           float height = 300;
           subLabel->resize(width,height);
           subLabel->move(0,0);
           subLabel->setStyleSheet("background-color:rgb(234, 237, 248); color: black;");

        //创建具体的小块label和but
           int count = 5;
           int clomCount = 3;
           float margin = 10;
           float width_cell = (width - 4 * margin)/clomCount;
           float height_cell = width_cell;
           QStringList lstSkin;
           lstSkin << "深蓝" << "浅蓝" << "浅绿" << "浅灰";
           for(int i = 0; i < count;i++){

                   QPushButton *label_cell = new QPushButton(subLabel);
                   if (i < lstSkin.count())
                       label_cell->setText( lstSkin.at(i) );


                   label_cell->resize(width_cell,height_cell);
                   label_cell->move((i%clomCount)*(width_cell + margin) + margin,(i/clomCount)*(height_cell + margin) + margin);
                   if(i == 0){
                        label_cell->setStyleSheet("QPushButton{background-color:rgb(33,129,204);  color: black;}"
                                                  "QPushButton:hover{background-color:rgba(33,129,204,0.5); color: black;}");
                   }else if(i == 1){

                   label_cell->setStyleSheet("QPushButton{background-color:rgb(172,204,255);  color: black;}"
                                             "QPushButton:hover{background-color:rgba(172,204,255,0.5); color: black;}");
                   }else if(i == 2){
                        label_cell->setStyleSheet("QPushButton{background-color:rgb(122,197,196);  color: black;}"
                                                  "QPushButton:hover{background-color:rgba(122,197,196,0.5); color: black;}");

                   }else if(i == 3){
                       label_cell->setStyleSheet("QPushButton{background-color:rgb(204,204,204);  color: black;}"
                                                 "QPushButton:hover{background-color:rgba(204,204,204,0.5); color: black;}");
                   }
                   if(i>=4){
                  label_cell->setStyleSheet("QPushButton{background-color:white;  color: black;  "
                                                " border-radius: 10px;  border: 2px groove gray;}"
                                                "QPushButton:hover{background-color:rgb(205, 205, 205); color: black;}"
                                                 "QPushButton:pressed{background-color:rgb((251, 202, 255)); }");
                   label_cell->clearMask();
                   label_cell->setBackgroundRole(QPalette::Base);
                   QPixmap pix;
                   pix.load("../icon.png");
                   label_cell->setIcon(pix);
                   label_cell->setIconSize(QSize(pix.width(),pix.height()));
                   qDebug()<<"图片"<<label_cell->iconSize();
                   label_cell->setToolTip("+");
                   label_cell->setText(tr("+"));
                   }else{

                   }
                   connect(label_cell,SIGNAL(clicked(bool)),this,SLOT(clickPopBut()));
        }
}
void BCSettingClectionStyle::clickPopBut()
{
                QPushButton *but;
                but = static_cast<QPushButton *> (sender());
                if(but->text() == "深蓝"){
                    BCCommon::SetApplicationSkin("DarkBlue");
                }else if(but->text() == "浅蓝"){
                     BCCommon::SetApplicationSkin("LightGreen");

                }else if(but->text() == "浅绿"){
                    BCCommon::SetApplicationSkin("LightBlue");
                }else if(but->text() == "浅灰"){
                    BCCommon::SetApplicationSkin("LightGray");
                }else {
                    //BCSettingSkinSet *set = new BCSettingSkinSet;
                    //   set->show();
                }
}
