#ifndef BCSETTINGBATCHSUBTITLESDLG_H
#define BCSETTINGBATCHSUBTITLESDLG_H

#include <QDialog>

namespace Ui {
class BCSettingBatchSubTitlesDlg;
}

class BCSettingBatchSubTitlesDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingBatchSubTitlesDlg(QWidget *parent = 0);
    ~BCSettingBatchSubTitlesDlg();

private slots:
    void on_m_pSubTitlesColorBtn_clicked();
    void on_m_pSubTitlesTextApplyBtn_clicked();
    void on_m_pSubTitlesPosApplyBtn_clicked();
    void on_m_pSubTitlesColorApplyBtn_clicked();
    void on_m_pSubTitlesVisibleApplyBtn_clicked();

private:
    Ui::BCSettingBatchSubTitlesDlg *ui;

    void SetSubTitles(int type);
};

#endif // BCSETTINGBATCHSUBTITLESDLG_H
