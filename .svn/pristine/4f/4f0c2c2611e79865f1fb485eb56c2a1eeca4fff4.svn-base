#ifndef BCSettingMontageDlg_H
#define BCSettingMontageDlg_H

#include <QDialog>

namespace Ui {
class BCSettingMontageDlg;
}

class BCSettingMontageDlg : public QDialog
{
    Q_OBJECT
public:
    BCSettingMontageDlg(QWidget *parent = NULL);
    ~BCSettingMontageDlg();

private slots:
    void onResolutionValueChanged(int);

    void on_m_pOkBtn_clicked();
    void on_m_pCancelBtn_clicked();

    void on_m_pLoadLastStatusBtn_clicked();

    void on_m_pTestConfigBtn_clicked();

    void on_m_pInputSetBtn_clicked();

private:
    Ui::BCSettingMontageDlg *ui;

    void Init();

    QStringList m_lstResolution;    // 预设的屏幕分辨率
};

#endif // BCSettingMontageDlg_H
