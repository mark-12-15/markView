#ifndef BCSCENE_H
#define BCSCENE_H

#include <QWidget>

namespace Ui {
class BCScene;
}

class BCWidgetBtn;
class BCMWindowScene;
class BCScene : public QWidget
{
    Q_OBJECT

public:
    explicit BCScene(bool bVisible, int minHeight, QWidget *parent = 0);
    ~BCScene();

    // 刷新数据
    void Refresh();

    // 是否隐藏内容
    bool IsVisible();

    /* 对外开放接口，成功返回true，失败false；参数2为备用参数
     *  0：轮训
     *  1：添加场景
     *  2：删除场景
     *  3：更新场景
     *  4：场景设置
     *  5：修改名称
     *  6：清空场景
     */
    bool SetAction(int type);

    // 设置界面轮训时间及是否显示
    void SetLoopTime(int value);

    // 编辑场景的轮巡时间
    void SetSceneEditable();

    int m_minHeight;

private slots:
    void onSetVisible(bool);
    void on_spinBox_valueChanged(int value);
    void on_comboBox_currentIndexChanged(int index);

    void on_m_pSelectAllBtn_clicked();

private:
    void BuildWindowScene(BCMWindowScene *pWindowScene);

    bool eventFilter(QObject *obj, QEvent *e);
    bool event(QEvent *event);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

    bool m_bModifyHeight;       // 是否修改高度，悬停到最下面时值为true
    bool m_bPress;

private:
    Ui::BCScene *ui;

    BCWidgetBtn         *m_pHeaderBtn;
};

#endif // BCSCENE_H
