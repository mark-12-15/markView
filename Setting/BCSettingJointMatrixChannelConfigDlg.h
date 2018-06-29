#ifndef BCSETTINGJOINTMATRIXCHANNELCONFIGDLG_H
#define BCSETTINGJOINTMATRIXCHANNELCONFIGDLG_H

#include <QDialog>

namespace Ui {
class BCSettingJointMatrixChannelConfigDlg;
}

class BCCmdMatrixListWidgetItem;
class BCSettingJointMatrixChannelConfigDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingJointMatrixChannelConfigDlg(BCCmdMatrixListWidgetItem *pItem, QWidget *parent = 0);
    ~BCSettingJointMatrixChannelConfigDlg();

private slots:
    void on_m_pCancelBtn_clicked();

    void on_m_pOKBtn_clicked();

private:
    Ui::BCSettingJointMatrixChannelConfigDlg *ui;

    bool eventFilter(QObject *target, QEvent *event);

    BCCmdMatrixListWidgetItem *m_pItem;
};

#endif // BCSETTINGJOINTMATRIXCHANNELCONFIGDLG_H
