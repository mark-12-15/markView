#ifndef ALARMMANAGEMENT_H
#define ALARMMANAGEMENT_H

#include <QDialog>
#include <QTreeWidgetItem>
#include <QCheckBox>
namespace Ui {
class AlarmManagement;
}

class AlarmManagement : public QDialog
{
    Q_OBJECT

public:
    explicit AlarmManagement(QWidget *parent = 0);
    ~AlarmManagement();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();
    /*
   *添加checBox
     */
    void AddTreeNode(QTreeWidgetItem *root,QStringList texts);
    /*
   *点击了分组的checkBox
     */
    void clickSectionBox();
    /*
   * 点击分组的checkBox抽取
     */
   void changeBoxStateInSection(QCheckBox *section, int index);

   /*
  * 点击全选和全不选按钮的抽取
    */
   void checkAllBoxByTopLeavelIndex(int index,bool clickState);

   void on_pushButton_3_clicked();

private:
    Ui::AlarmManagement *ui;
    void init();
};

#endif // ALARMMANAGEMENT_H
