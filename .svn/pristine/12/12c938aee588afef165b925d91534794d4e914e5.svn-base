#ifndef BCSETTINGSIMPLESTYLE_H
#define BCSETTINGSIMPLESTYLE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
namespace Ui {
class BCSettingSimpleStyle;
}

class BCSettingSimpleStyle : public QWidget
{
    Q_OBJECT

public:
    enum PushButtonFunction{
        creatSkinClection,                //创建皮肤九宫格子
        setLoginView,                     //设置登陆界面
        boardBitmap,                      //察看板位图
        takeOn_of,                        //开关机设置
        hardwareParameters,               //硬件参数设置
        queryDevice,                      //检测设备
        EDID,                             //EDID
        deviceControl,                    //外设控制
        queryLog,                         //日志查询
        userManagement,                   //用户管理
        configurationFilePath,            //配置文件路径
        back_up,                          //备份
        lookForUpdates,                   //检查更新
        aboutUs,                          //关于我们
        choiceColor                       //选择填充颜色
    };

    explicit BCSettingSimpleStyle(QWidget *parent = 0,QStringList *texts = NULL,PushButtonFunction fuction = aboutUs);
    ~BCSettingSimpleStyle();

private slots:
    void initSubViews();                  //初始化界面
    void fouctionCreatSkinClection();     //创建皮肤九宫格
    void fouctionSetLoginView();          //自定义登陆界面
    void fouctionBoardBitmap();           //察看板位图
    void fouctionTakeOn_of();             //开关机设置
    void fouctionHardwareParameters();    //硬件参数设置
    void fouctionQueryDevice();           //检测设备
    void fouctionEDID();                  //EDID
    void fouctionDeviceControl();         //外设控制
    void fouctionQueryLog();              //日志查询
    void fouctionUserManagement();        //用户管理
    void fouctionConfigurationFilePath(); //配置文件路径
    void fouctionBack_up();               //备份
    void fouctionLookForUpdates();        //检查更新
    void fouctionAboutUs();               //关于我们
    void fouctionChoiceColor();           //选择填充颜色



private:
    Ui::BCSettingSimpleStyle *ui;
    PushButtonFunction _butFuction;
    QLabel *_skinPopLabel;
};

#endif // BCSETTINGSIMPLESTYLE_H
