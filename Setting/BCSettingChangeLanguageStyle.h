/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：语言支持的对话框
*********************************************************************************************************************************/
#ifndef BCSETTINGCHANGELANGUAGESTYLE_H
#define BCSETTINGCHANGELANGUAGESTYLE_H

#include <QDialog>

namespace Ui {
class BCSettingChangeLanguageStyle;
}

class BCSettingChangeLanguageStyle : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingChangeLanguageStyle(QWidget *parent = 0);
    ~BCSettingChangeLanguageStyle();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::BCSettingChangeLanguageStyle *ui;

    QStringList m_lstQmLanguage;        // 跟界面的语言对应的qm文件路径
};

#endif // BCSETTINGCHANGELANGUAGESTYLE_H
