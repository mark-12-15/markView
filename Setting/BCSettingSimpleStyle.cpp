#include "BCSettingSimpleStyle.h"
#include "ui_BCSettingSimpleStyle.h"
#include "BCSettingTimerTask.h"
#include "HardWareParameter.h"
#include "QueryDevice.h"
#include "EDIDDialog.h"
#include "LogQueryDialog.h"
#include "rootdialog.h"
#include "ConfigurationFile.h"
#include "BCAbout.h"
#include <QDebug>
#include <QColorDialog>
#include "systemsetting.h"
#include "mydialog.h"
#include "../Common/BCCommon.h"

BCSettingSimpleStyle::BCSettingSimpleStyle(QWidget *parent,QStringList *texts,PushButtonFunction fuction) :
    QWidget(parent),
    ui(new Ui::BCSettingSimpleStyle)
{
        ui->setupUi(this);
        _butFuction = fuction;
        ui->label->setText(texts->at(0));
        ui->label_2->setText(texts->at(1));
        ui->pushButton->setText(texts->at(2));
        ui->pushButton->setStyleSheet("QPushButton{background-color:rgb(244,244,244);  color: black;  "
                                     " border-radius: 2px;  border: 1px groove gray;}"
                                     "QPushButton:hover{background-color:rgb(190, 231, 253); color: black;}"
                                     "QPushButton:pressed{background-color:rgb((235, 236, 237)); }");

        /*
        *初始化界面
         */
        this->initSubViews();

}

BCSettingSimpleStyle::~BCSettingSimpleStyle()
{
        delete ui;
}

/*
*初始化界面
 */
void BCSettingSimpleStyle::initSubViews()
{
        switch (_butFuction) {
        case creatSkinClection:
            //创建皮肤九宫格
            connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(fouctionCreatSkinClection()));
            break;
        case setLoginView:
            //自定义登陆界面布局
            connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(fouctionSetLoginView()));
            break;
        case boardBitmap:
            //察看板位图
            connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(fouctionBoardBitmap()));
            break;
        case takeOn_of:
            //开关机设置
            connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(fouctionTakeOn_of()));
            break;
        case hardwareParameters:
            //硬件参数设置
            connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(fouctionHardwareParameters()));
            break;
        case queryDevice:
            //检测设备
            connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(fouctionQueryDevice()));
            break;
        case EDID:
            //EDID
            connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(fouctionEDID()));
            break;
        case deviceControl:
            //外设控制
            connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(fouctionDeviceControl()));
            break;
        case queryLog:
            //日志查询
            connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(fouctionQueryLog()));
            break;
        case userManagement:
            //用户管理
            connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(fouctionUserManagement()));
            break;
        case configurationFilePath:
            //配置文件路径
            connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(fouctionConfigurationFilePath()));
            break;
        case back_up:
            //备份
            connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(fouctionBack_up()));
            break;
        case lookForUpdates:
            //检查更新
            connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(fouctionLookForUpdates()));
            break;
        case choiceColor:
            //检查更新
            connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(fouctionChoiceColor()));
            break;
        default:
            //关于我们
            connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(fouctionAboutUs()));
            break;
        }
}

/*
*皮肤九宫格
 */
int didCreatePop = 0;
void BCSettingSimpleStyle::fouctionCreatSkinClection()
{

      if(didCreatePop != 88){

            didCreatePop = 88;
            SystemSetting *parent = static_cast <SystemSetting *> (this->parent()->parent()->parent()->parent());
            QLabel *label = new QLabel(parent);
            parent->didCreatePop = 88;
            parent->_skinPopLabel = label;
            _skinPopLabel = label;
            label->resize(675,470);
            label->move(0,0);
            QPalette myPalette;
            QColor myColor(188,188,188);
            myColor.setAlphaF(0.7);
            myPalette.setBrush(backgroundRole(),myColor);
            label->setPalette(myPalette);
            label->setAutoFillBackground(true);
            float x = (675 - 300)/2;
            float y = 100;
            //BCSettingClectionStyle *clectionView = new BCSettingClectionStyle(label);
            //clectionView->move(x,y);
      }
      _skinPopLabel->show();
}

 /*
*自定义登陆界面布局
 */
void BCSettingSimpleStyle::fouctionSetLoginView()
{
       MyDialog *dialog = new MyDialog;
       dialog->show();
}

 /*
*察看板位图
 */
void BCSettingSimpleStyle::fouctionBoardBitmap()
{

}


/*
* 开关机设置
 */
void BCSettingSimpleStyle::fouctionTakeOn_of()
{
        BCSettingTimerTask *timerTask = new BCSettingTimerTask;
        timerTask->show();
}
 /*
* 硬件参数设置
  */
void BCSettingSimpleStyle::fouctionHardwareParameters()
{
        HardWareParameter *hardWare = new HardWareParameter;
        hardWare->show();
}
 /*
* 检测设备
  */
void BCSettingSimpleStyle::fouctionQueryDevice()
{
        QueryDevice *queryDialog = new QueryDevice;
        queryDialog->show();
}
 /*
* EDID
  */
void BCSettingSimpleStyle::fouctionEDID()
{
        EDIDDialog *edid = new EDIDDialog;
        edid->show();
}
 /*
*外设控制
 */
void BCSettingSimpleStyle::fouctionDeviceControl()
{

}

 /*
*日志查询
 */
void BCSettingSimpleStyle::fouctionQueryLog()
{
        LogQueryDialog *logQuery = new LogQueryDialog;
        logQuery->show();
}

 /*
* 用户管理
  */
void BCSettingSimpleStyle::fouctionUserManagement()
{
        RootDialog *userManagement = new RootDialog;
        userManagement->show();
}

/*
* 配置文件路径
 */
void BCSettingSimpleStyle::fouctionConfigurationFilePath()
{
        ConfigurationFile confiDialog(this);
        confiDialog.exec();
}

 /*
*备份
 */
void BCSettingSimpleStyle::fouctionBack_up()
{

}

 /*
*检查更新
 */
void BCSettingSimpleStyle::fouctionLookForUpdates()
{

}

 /*
*关于我们
 */
void BCSettingSimpleStyle::fouctionAboutUs()
{
        BCAbout *about = new BCAbout();
        about->show();
}

/*
*选择填充颜色
 */
void BCSettingSimpleStyle::fouctionChoiceColor()
{
        QPushButton *but = static_cast <QPushButton *> (sender());
        QColorDialog dialog(Qt::red,this);
        dialog.setOption(QColorDialog::ShowAlphaChannel);

        dialog.exec();
        QColor color = dialog.currentColor();
        QPalette myPalette;
        QColor myColor(color.rgb());
        myColor.setAlphaF(color.alphaF());
        myPalette.setBrush(backgroundRole(),myColor);
        but->setPalette(myPalette);
        //but->setAutoFillBackground(true);
}


