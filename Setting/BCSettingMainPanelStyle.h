#ifndef BCSETTINGMAINPANELSTYLE_H
#define BCSETTINGMAINPANELSTYLE_H

#include <QDialog>

namespace Ui {
class BCSettingMainPanelStyle;
}

class BCSettingMainPanelStyle : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingMainPanelStyle(QWidget *parent = 0);
    ~BCSettingMainPanelStyle();

private slots:
    void on_m_pCancelBtn_clicked();

    void on_m_pOKBtn_clicked();

private:
    Ui::BCSettingMainPanelStyle *ui;

};

#endif // BCSETTINGMAINPANELSTYLE_H
