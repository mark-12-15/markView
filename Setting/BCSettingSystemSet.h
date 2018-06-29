#ifndef BCSETTINGSYSTEMSET_H
#define BCSETTINGSYSTEMSET_H

#include <QWidget>
#include <QVBoxLayout>
#include "BCSettingSimpleStyle.h"
namespace Ui {
class BCSettingSystemSet;
}

class BCSettingSystemSet : public QWidget
{
    Q_OBJECT

public:
    explicit BCSettingSystemSet(QWidget *parent = 0);
    ~BCSettingSystemSet();
private slots:
    void initSubViews();
    /*
   *创建simple类型的widget
     */
   void createSimpleStyle(QStringList list,BCSettingSimpleStyle::PushButtonFunction butFunction);
   void clickLeftLabel();
   void scrollAreaBarValueChange(int value);

    void test();


private:
    Ui::BCSettingSystemSet *ui;
    QVBoxLayout *_pScrollLayout;
    QPushButton *_lastLeftBut;
};

#endif // BCSETTINGSYSTEMSET_H
