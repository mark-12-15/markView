/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：ribbon风格的主工具条上的按钮类
*********************************************************************************************************************************/
#ifndef BCRIBBONMAINTOOLBARACTION_H
#define BCRIBBONMAINTOOLBARACTION_H

#include <QAction>
#include "BCRibbonMainToolBar.h"

class BCMRoom;
class BCMGroupScene;
class BCOtherDeviceControlDlg;
class BCSettingOtherDeviceControlDlg;
class BCLocationDlg;
class BCRibbonMainToolBarAction : public QAction
{
    Q_OBJECT

public:
    BCRibbonMainToolBarAction(BCRibbonMainToolBar::BUTTONTYPE eType,
                              const BCRibbonMainToolBar::ButtonInfo &btn,
                              const QIcon &icon, const QString &text,
                              QObject *parent = 0);
    BCRibbonMainToolBarAction(const QString &qsExtendPath, QObject *parent = 0);
    ~BCRibbonMainToolBarAction();

    void Refresh();                             // 刷新皮肤，暂时不使用...
    //void Refresh(BCMGroupScene *pGroupScene);   // 刷新是否轮训
    void RefreshSceneLoop(BCMRoom *pRoom);      // 刷新是否轮训
    void Refresh(BCMRoom *pRoom);               // 刷新是否打开开关
    void RefreshLocationDlg();                  // 刷新快速定位对话框
    void RefreshAndShowLocationDlg();           // 刷新并且显示定位对话框
    void RefreshPreview();                      // 刷新预监回显状态
    void RefreshFloorPlanning();                // 刷新预布局状态
    void RefreshCommunication();                // 刷新通讯状态

    void DestroyLocationDlg();

private slots:
    void onLoopSceneChanged(bool);
    void onLocation(bool);
    void onExtend(bool);
    void onEDIDSetting(bool);
    void onSync();          // 同步按钮
    void onGroupScene();    // 是否启用场景组按钮
    void onDisplaySwitch(); // 屏幕开关

    void onVisibleToolBar(bool);
    void onSceneSet(bool);
    void onOtherDeviceMgr();

    void onShowDialog(bool);

private:
    void init();

    QWidget *m_pWindow; // 和按钮相关联的开窗基类
    //BCOtherDeviceControlDlg     *m_pOtherDeviceMgrDlg;  // 外设控制对话框
    BCSettingOtherDeviceControlDlg  *m_pOtherDeviceMgrDlg;  // 外设控制对话框
    BCLocationDlg               *m_pLocationDlg;        // 快速定位Dialog

    QString                     m_qsExtendPath;         // 扩展按钮全路径

    BCRibbonMainToolBar::BUTTONTYPE m_eType;
    BCRibbonMainToolBar::ButtonInfo m_btn;
};

#endif // BCRIBBONMAINTOOLBARACTION_H
