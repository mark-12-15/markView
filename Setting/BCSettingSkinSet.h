#ifndef BCSETTINGSKINSET_H
#define BCSETTINGSKINSET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "BCSettingSimpleStyle.h"
namespace Ui {
class BCSettingSkinSet;
}

class BCSettingSkinSet : public QWidget
{
    Q_OBJECT

public:
    explicit BCSettingSkinSet(QWidget *parent = 0);
    ~BCSettingSkinSet();
private slots:
    void initSubViews();
    /*
   *创建simple类型的widget
     */
    void createSimpleStyle(QStringList list,BCSettingSimpleStyle::PushButtonFunction butFunction);
    void clickLeftLabel();
    void scrollAreaBarValueChange(int value);

private:
    Ui::BCSettingSkinSet *ui;
    QVBoxLayout *_pScrollLayout;
    QList<QVariant>_allViews;                      //里面装着自定义皮肤界面中的Combox方便来回设置它们是否可编辑
    QPushButton *_lastLeftBut;                       //记录自定义皮肤左侧栏中上次选中的是哪个but 方便来回改变颜色
};

#endif // BCSETTINGSKINSET_H
