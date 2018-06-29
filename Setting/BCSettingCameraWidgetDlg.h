#ifndef BCSETTINGCAMERAWIDGETDLG_H
#define BCSETTINGCAMERAWIDGETDLG_H

#include <QDialog>
#include <QWidget>
#include <QMouseEvent>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QMouseEvent>

typedef long LONG;

// ==================================================================
// BCCameraDisplayUnitWidget
class QToolButton;
class QLabel;
class BCSettingCameraWidgetDlg;
class BCCameraDisplayUnitWidget : public QWidget
{
    Q_OBJECT

public:
    BCCameraDisplayUnitWidget(BCSettingCameraWidgetDlg * settingCameraWidgetDlg = nullptr);
    ~BCCameraDisplayUnitWidget();

    void SetRealPlay(int chid, QString cChannelName);
    void SetRealPlayBack(QString sFileHandle, QString sFileName);

    int m_ChannelID;                //通道ID
    int m_iPlayhandle;              //播放句柄
    int m_iPlayBackhandle;          //回放句柄

    bool m_bSelected;               //是否被选中
    bool m_isVideo;                 //当前窗口是否在录像
    QToolButton * m_pStartVideobtn; //录像按钮
    QLabel * m_pTipLabel;           //显示信号源名称

    QWidget * m_pChildWidget;           //菜单窗
    QWidget * m_pChildWIdgetVideo;      //视频播放窗
    BCSettingCameraWidgetDlg * m_pSettingCameraWidgetDlg; //父窗口指针

    void InitChildWidget();            //加载子窗口
    void dragEnterEvent(QDragEnterEvent * dragEv);
    void dropEvent(QDropEvent * dropEv);
    void leaveEvent( QEvent * ev );
    bool eventFilter(QObject *obj, QEvent *ev);

private slots:
     void onStartVideobtnClicked(bool);         //录像按钮
};
// =======================================================================
namespace Ui {
class BCSettingCameraWidgetDlg;
}

class BCSettingCameraWidgetDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingCameraWidgetDlg(QStringList DivInfo, QWidget *parent = 0);
    ~BCSettingCameraWidgetDlg();

    BCCameraDisplayUnitWidget * SelectCameraWidget();                 //获取被选中的窗口
    void InitChildWidgetDlg(int h,int w);                   //初始化n乘n个窗口
    void LoginCamera(QStringList lstDivInfo);               //登录摄像机
    void CancelALLWidgetSelected();                         //取消窗口选中
    void InitInputChannel(QList<int> lstChannels);          //加载输入源
    void LoadVideoFile(QMap<QString, QString> mapFilenames);//加载录像文件
    QMap<int, QString> LoadRenameFile();                //读取重命名文件
    void UpLocadRenameFile();                               //写入重命名文件
    void StartPlatBackVideo(QString sFileHandle, QString sFileName, BCCameraDisplayUnitWidget * pDisplayWidget);
    void StartPlayVideo(int mChannel, BCCameraDisplayUnitWidget * pDisplayWidget, QString ChammelName); //按指定通道播放视频
    void DefaultPlayVideo();                                //默认播放
    void StartTranscribeVideo( int mChannel );              //开始录像
    void StopTranscribeVideo(int mChannel);                 //结束录像
    bool eventFilter(QObject * mObj, QEvent *mEv);

    QString GetCameraTreeWidgetItemText(int ItemID); //信号源
    QString GetCameraVideoFileTreeWidgetItemText(QString Itemhandle);

    LONG IUserID;                                          //设备注册句柄 - 每台录像机一个

private:
    void SendCameraCenterCtrl(int dir, int release);        // 统一发送云台指令，参数1：方向，参数2：是否鼠标释放事件
    void onChannelItemRename();       //修改名称 -> 编辑

    Ui::BCSettingCameraWidgetDlg *ui;

public slots:
    void onTreeWidgetDoubleClicked(QTreeWidgetItem*,int);           //切换分割模式

private slots:
    void on_pushButton_CameraLink_clicked();
    void on_pushButton_VideoSelect_clicked();

    //云台控制
    void on_toolButton_leftUP_pressed();
    void on_toolButton_leftUP_released();
    void on_toolButton_up_pressed();
    void on_toolButton_up_released();
    void on_toolButton_rightUp_pressed();
    void on_toolButton_rightUp_released();
    void on_toolButton_left_pressed();
    void on_toolButton_left_released();
    void on_toolButton_right_pressed();
    void on_toolButton_right_released();
    void on_toolButton_leftDown_pressed();
    void on_toolButton_leftDown_released();
    void on_toolButton_Down_pressed();
    void on_toolButton_Down_released();
    void on_toolButton_rightDown_pressed();
    void on_toolButton_rightDown_released();
    void on_toolButton_ZoomIn_pressed();
    void on_toolButton_ZoomIn_released();
    void on_toolButton_ZoomOut_pressed();
    void on_toolButton_ZoomOut_released();
};

#endif // BCSETTINGCAMERAWIDGETDLG_H
