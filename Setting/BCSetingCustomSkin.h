#ifndef BCSETINGCUSTOMSKIN_H
#define BCSETINGCUSTOMSKIN_H

#include <QWidget>
#include "UILabel.h"
namespace Ui {
class BCSetingCustomSkin;
}

class BCSetingCustomSkin : public QWidget
{
    Q_OBJECT

public:
    explicit BCSetingCustomSkin(QWidget *parent = 0);
    ~BCSetingCustomSkin();
public slots:
    void selectColor(UILabel *label);     //---------------------------------------填充颜色信号槽

private slots:


    void on_pushButton_cancel_clicked();

private:
    Ui::BCSetingCustomSkin *ui;
};

#endif // BCSETINGCUSTOMSKIN_H
