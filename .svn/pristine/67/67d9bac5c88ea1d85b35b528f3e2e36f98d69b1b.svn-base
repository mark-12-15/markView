#ifndef BCVIDEOCONTROL_H
#define BCVIDEOCONTROL_H

#include <QWidget>

namespace Ui {
    class BCVideoControl;
}

class BCWidgetBtn;
class QListWidgetItem;
class BCVideoControl : public QWidget
{
    Q_OBJECT

public:
    explicit BCVideoControl(bool bVisible, int minHeight, QWidget *parent = 0);
    ~BCVideoControl();

    // 是否隐藏内容
    bool IsVisible();
    int m_minHeight;

private slots:
    void onSetVisible(bool);
    void showContextMenu(const QPoint &pt);
    void onInitCameraWidget(QListWidgetItem*);

    void on_pushButton_clicked();           //新增按钮 -> 保存
    void on_pushButton_2_clicked();         //新增按钮 -> 返回

private:
    void LoadDiskVideoData();
    void SaveDiskVideoData();

    void ModifyItem();
    void DeleteItem();

    Ui::BCVideoControl *ui;
    BCWidgetBtn* m_pHeaderBtn;
};

#endif // BCVIDEOCONTROL_H
