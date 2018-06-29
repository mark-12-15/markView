/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：默认左侧的工具条内widget类，里面嵌套10个独立的模块，模块类型见MainWindow
*********************************************************************************************************************************/
#ifndef BCFACEWIDGET_H
#define BCFACEWIDGET_H

#include <QWidget>
#include "MainWindow.h"

namespace Ui {
class BCFaceWidget;
}

class SSigSrcObject;
class BCFaceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BCFaceWidget(QWidget *parent = 0);
    ~BCFaceWidget();

    // 刷新里面的控件，默认为重构，如果为0则只刷新数据
    void Refresh(int nReconstruction = 1);

    // 刷新信号源的名称，0:刷新物理信号源的名字，1:刷新自定义组的信号源的名字
    void RefreshChannelName(int type = 0);

    // 返回对应的控件
    QWidget* GetWidget(MainWindow::SIGNALSOURCETYPE eType);

private:
    QList<SSigSrcObject> GetSignalSourceSort();
    void UpdateSignalSourceSort();

private:
    Ui::BCFaceWidget *ui;
};

#endif // BCFACEWIDGET_H
