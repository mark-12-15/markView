#ifndef BCSETTINGDEVICESET_H
#define BCSETTINGDEVICESET_H

#include <QWidget>
#include <QVBoxLayout>
#include "BCSettingSimpleStyle.h"
namespace Ui {
class BCSettingDeviceSet;
}

class BCSettingDeviceSet : public QWidget
{
    Q_OBJECT

public:
    explicit BCSettingDeviceSet(QWidget *parent = 0);
    ~BCSettingDeviceSet();
private slots:
    void initSubViews();
    /*
   *创建simple类型的widget
     */
    void createSimpleStyle(QStringList list,BCSettingSimpleStyle::PushButtonFunction butFunction);
    void test();
    void clickLeftLabel();
    void scrollAreaBarValueChange(int value);

private:
    Ui::BCSettingDeviceSet *ui;
    QVBoxLayout *_pScrollLayout;
    QPushButton *_lastLeftBut;
};

#endif // BCSETTINGDEVICESET_H
