/*********************************************************************************************************************************
* 作    者：liyz
* 摘    要：信号源按钮弹出对话框
*********************************************************************************************************************************/
#ifndef BCSETSIGNALDLG_H
#define BCSETSIGNALDLG_H

#include <QDialog>

namespace Ui {
class BCSetSignalDlg;
}

// 信号源自定义Item
class BCMChannel;
class BCMGroupChannel;
class QTreeWidgetItem;
class BCSetSignalDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSetSignalDlg(QWidget *parent = 0);
    ~BCSetSignalDlg();

private slots:
    void on_m_pResetSignalSourceBtn_clicked();

    void on_m_pOkBtn_clicked();
    void on_m_pCancelBtn_clicked();

    void on_m_pAddGroupInputChannelBtn_clicked();
    void on_m_pClearGroupInputChannelBtn_clicked();
    void on_m_pModifyInputChannelBtn_clicked();

    // 当item内容发生变化时执行，更新数据内的名称
    void onItemChanged(QTreeWidgetItem *item, int column);

    void on_m_pDelGroupInputChannelBtn_clicked();

private:
    bool eventFilter(QObject *, QEvent *);
    void closeEvent(QCloseEvent *);

    /*  返回信号源的排序
     *  参数：0当前排序；1默认排序
     *  返回值：使用元类型代替自定义类型，QPoint的x表示信号源类型，y表示是否勾选
     */
    QList<QPoint> GetSignalSourceSort(int type = 0);

    // 设置信号源是排序，参数说明同上
    void SetSignalSourceSort(QList<QPoint>);

    // 已经添加的链表中是否存在通道
    bool IsExistInputChannel(BCMChannel *pChannel);

    void Init();

private:
    Ui::BCSetSignalDlg *ui;

    bool m_bPressOK;                                    // 是否点击了确定按钮，因为可以点击红叉关闭，所以添加此变量
    QList<BCMGroupChannel *> m_lstGroupInputChannels;   // 输入通道组链表，缓存数据，点OK时更新到MainWindow，点Cancel时删除数据
};

#endif // BCSETSIGNALDLG_H
