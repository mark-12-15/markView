/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：语言支持的对话框
*********************************************************************************************************************************/
#ifndef BCSettingLanguageDlg_H
#define BCSettingLanguageDlg_H

#include <QDialog>

namespace Ui {
class BCSettingLanguageDlg;
}

class BCSettingLanguageDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingLanguageDlg(QWidget *parent = 0);
    ~BCSettingLanguageDlg();

    void RefreshLanguage(bool bLocal = true);

private slots:
    void on_m_pOkBtn_clicked();
    void on_m_pCancelBtn_clicked();
    void on_m_pApplyBtn_clicked();

private:
    Ui::BCSettingLanguageDlg *ui;

    void InitFromXml();
    void UpdateXml();

    QStringList m_lstQmLanguage;        // 跟界面的语言对应的qm文件路径
};

#endif // BCSettingLanguageDlg_H
