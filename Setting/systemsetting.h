#ifndef SYSTEMSETTING_H
#define SYSTEMSETTING_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include "BCSettingSimpleStyle.h"
namespace Ui {
class SystemSetting;
}

class SystemSetting : public QWidget
{
    Q_OBJECT
    Q_ENUMS(SelectedDisplay)

public:
    enum SelectedDisplay{
        SelectedDisplayNone,
        SelectedDisplayMainPanel,//---------------------------主面版
        SelectedDisplaySkin,
        SelectedDisplayLogin,
        SelectedDisplayModel,//-------------------------------显示模式
        SelectedDisplayChoiceLanague,
        SelectedDisplayCustomToolBar,

        SelectedDeviceServerService,
        SelectedDeviceBoardBitmap,//---------------------------板位图
        SelectedDeviceAutoOn_off,//----------------------------自动开关机
        SelectedDeviceHardWare,//------------------------------硬件参数设置
        SelectedDeviceTestWindow,
        SelectedDeviceQueryDevice,//---------------------------检测设置
        SelectedDeviceEDID,
        SelectedDeviceControl,//-------------------------------外设控制

        SelectedSystemQueryJournaled,//------------------------日志查询
        SelectedSystemUserManagement,//------------------------用户管理
        SelectedSystemConfigurationFile,//---------------------配置文件
        SelectedSystemRevisePassword,//------------------------修改密码
        SelectedSystemBackup,//--------------------------------备份还原
        SelectedSystemVersionInfo,//---------------------------版本信息
        SelectedSystemAboutUs,//-------------------------------关于我们
        SelectedSystemSoftWare//-------------------------------软件认证
    };

    explicit SystemSetting(SelectedDisplay selected = SelectedDisplayNone, QWidget *parent = 0);
    ~SystemSetting();
    int didCreatePop;//---------------------------------------记录是否创建九宫格
    QLabel *_skinPopLabel;//-----------------------------------点击皮肤设置时pop出来的半透明label


    /****************************************
     * 点击label关联的信号
     ****************************************/
public slots:
    void createSimpleStyle(QStringList list,BCSettingSimpleStyle::PushButtonFunction butFunction);//创建SimpleStyleWidget
    void clickDisplayLab(); //-----------------------------------------------------点击了首界面的显示Label
    void clickFirstViewLeftLabel(UILabel *label);//--------------------------------点击了主面版、皮肤、登陆label信号槽
    void clickCancelBut();//-------------------------------------------------------点击了Cancel按钮的信号槽
    void moveUILabel(int ofset);//-------------------------------------------------正在拖拽UILabel；
    void clickCancel();
private slots:
    /*
    *创建顶部的三个按钮
     */
    void createTopButton(QLabel *parent, QString title,QPoint point,QString pictur);
    /*
    *创建左侧的UILabel
     */
    void createLeftUILabel(QLabel *parent, QString title,QPoint point);
    void setScrollBar(QScrollArea *area);
    /*
    *创建自定义工具条中的Label
     */
    void createImageLabelInCustomeTool(QString imagePath,QPoint point);


    /*
   *滚动条的值改变了
     */
    void scrollAreaBarValueChange(int value);

    void mousePressEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);


private:
    Ui::SystemSetting *ui;
    /*************
   *  全局变量或者属性
     ************/
    UILabel *_label_back1;
    UILabel *_label_back2;
    UILabel *_label_back3;
    UILabel *_label_back4;
    UILabel *_label_back5;
    UILabel *_label_back6;
    QList<QVariant> _labelBacks;
    QPushButton *_label_display;
    QPushButton *_label_device;
    QPushButton *_label_system;
    QWidget *_deviceWidget;//-----------------------------------------------------点击设备弹出来的Widget
    QWidget *_systemWidget;//-----------------------------------------------------点击系统弹出来的Widget
    QLabel *_deviceLabel;//-------------------------------------------------------电击设备弹出来的view
    QLabel *_systemLabel;//-------------------------------------------------------点击系统弹出来的View
    QLabel *_custemSkinLabel;//---------------------------------------------------点击+号按钮弹出来的视图
    QLabel *_lineLabel;//---------------------------------------------------------显示线条宽细的label
    QLabel *_textSizeBackLabel;//-------------------------------------------------承载着字体、字号大小的父试图
    QLabel *_textOffsetLabel;//---------------------------------------------------承载着文字偏移的父试图  由于上面的label有可能隐藏所以它得改变位置
    QLabel *_textOffsetLabel2;//--------------------------------------------------同上一样
    QPushButton *_lastItemLableClicked;//-----------------------------------------记录最上面那三个label上次选中的是谁方便来回改变颜色（显示、设备、系统）
    UILabel *_lastLabelClicked;//-------------------------------------------------记录主面版、皮肤等label中上次被选中的 方便来回改变颜色
    QScrollArea *_deviceScrollArea;//---------------------------------------------设备界面的ScrollArea在点击左侧label时让它滑动
    QScrollArea *_systemScrollArea;//---------------------------------------------系统界面的ScrollArea
    QLineEdit *_oldPasswordEdit;//------------------------------------------------旧密码输入框
    QLineEdit *_newPasswordEdit;//------------------------------------------------新密码输入框
    QString _testString;//--------------------------------------------------------暂时测试
   // Q_PROPERTY(SelectedDisplay selectedPositon READ selectedPositon WRITE setSelectedPositon NOTIFY selectedPositonChanged)
    SelectedDisplay _selectedPosition;//------------------------------------------暂时测试
     QVBoxLayout *_pScrollLayout;//-----------------------------------------------scrollArea内部的layout


};

#endif // SYSTEMSETTING_H
