/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：toolbar类，可单独停靠
*********************************************************************************************************************************/
#ifndef BCTOOLBAR_H
#define BCTOOLBAR_H

#include <QMap>
#include <QDockWidget>
#include "MainWindow.h"

class BCMainToolBarWidget;
class BCToolBar : public QDockWidget
{
    Q_OBJECT
public:
    BCToolBar(MainWindow::TOOLBARTYPE eToolBarType = MainWindow::MAINTOOLBAR, QWidget * parent = 0);
    ~BCToolBar();

    // 主工具条widget链表
    const QList<BCMainToolBarWidget *> &GetMainToolBarWidgets();

    // 返回toolbar名称
    const QString &GetToolBarName() const;

    // 返回工具条类型
    MainWindow::TOOLBARTYPE GetToolBarType();

    // 刷新翻译
    void RefreshLanguage();

public slots:
    void onVisibel(bool b);

protected:
    // 关闭事件
    void closeEvent(QCloseEvent *);

    // 对预监工具条特殊处理，隐藏时临时关闭视频
    void showEvent(QShowEvent *);
    void hideEvent(QHideEvent *);

private:
    MainWindow::TOOLBARTYPE m_eToolBarType;
    QString m_qsName;   // 工具条名称

    QList<BCMainToolBarWidget *>    m_lstMainToolBarWidget;
};

inline const QString &BCToolBar::GetToolBarName() const
{
    return m_qsName;
}

inline MainWindow::TOOLBARTYPE BCToolBar::GetToolBarType()
{
    return m_eToolBarType;
}

inline const QList<BCMainToolBarWidget *> &BCToolBar::GetMainToolBarWidgets()
{
    return m_lstMainToolBarWidget;
}

#endif // BCTOOLBAR_H
