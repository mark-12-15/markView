#ifndef BCSETTINGDISPLAYSWITCHROOMWIDGET_H
#define BCSETTINGDISPLAYSWITCHROOMWIDGET_H

#include <QWidget>

namespace Ui {
class BCSettingDisplaySwitchRoomWidget;
}

class BCMRoom;
class sDisplayMaker;
class BCSettingDisplaySwitchConfigDlg;
class BCSettingDisplaySwitchRoomWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BCSettingDisplaySwitchRoomWidget(BCMRoom *pRoom, BCSettingDisplaySwitchConfigDlg *parent = 0);
    ~BCSettingDisplaySwitchRoomWidget();

    void SaveConfig();

    // 刷新大屏厂家combbox
    void RefreshDisplayMaker(QList<sDisplayMaker> lstMaker);

private slots:
    void on_m_pDisplayMakerComboBox_currentIndexChanged(int index);

private:
    Ui::BCSettingDisplaySwitchRoomWidget *ui;

    BCMRoom *m_pRoom;
    QList<sDisplayMaker> m_lstMaker;
    BCSettingDisplaySwitchConfigDlg *m_parent;
};

#endif // BCSETTINGDISPLAYSWITCHROOMWIDGET_H
