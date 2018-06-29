/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：快速开窗Dialog
*********************************************************************************************************************************/
#ifndef BCLOCATIONDLG_H
#define BCLOCATIONDLG_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class BCLocationDlg;
}

class BCLocationLabel : public QLabel
{
public:
    BCLocationLabel(int r, int c, const QString &text, QWidget *parent);

    // 设置是否高亮
    void SetHightLight(bool bHightLight);

    // 记录行列
    int     m_nRow;
    int     m_nCol;
    bool    m_bHightLight;
};

// ---------------------------------------------------------------------------------------------------------------------------------

class BCGroupDisplayWidget;
class BCSignalWindowDisplayWidget;
class BCLocationDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCLocationDlg(QWidget *parent = 0);
    ~BCLocationDlg();

    // 刷新屏幕及当前信号窗
    void Refresh();

    // 重置当前信号窗的位置
    void ResizeSignalWindow(bool b);

private slots:
    void on_m_pRadioBtn1_clicked();
    void on_m_pRadioBtn4_clicked();
    void on_m_pRadioBtn6_clicked();
    void on_m_pRadioBtn8_clicked();
    void on_m_pRadioBtn9_clicked();
    void on_m_pRadioBtn12_clicked();
    void on_m_pRadioBtn16_clicked();

private:
    Ui::BCLocationDlg *ui;

    bool                        m_bLocationDisplay;     // 是否是单屏定位

    BCGroupDisplayWidget        *m_pGroupDisplayWidget; // 快速开窗对应的屏组
    BCSignalWindowDisplayWidget *m_pSignalWindowWidget; // 快速开窗对应的信号窗
};

#endif // BCLOCATIONDLG_H
