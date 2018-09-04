#ifndef BCSETTINGMATRIXCUTINPUTCHANNELDLG_H
#define BCSETTINGMATRIXCUTINPUTCHANNELDLG_H

#include <QDialog>

namespace Ui {
class BCSettingMatrixCutInputChannelDlg;
}

class BCMMatrix;
class BCSettingMatrixCutInputChannelDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingMatrixCutInputChannelDlg(BCMMatrix *pMatrix, int id, QWidget *parent = 0);
    ~BCSettingMatrixCutInputChannelDlg();

private slots:
    void on_m_pApplyBtn_clicked();

    void on_m_pCancelBtn_clicked();

    void on_m_pOkBtn_clicked();

private:
    Ui::BCSettingMatrixCutInputChannelDlg *ui;

    void SendCmd();

    BCMMatrix *m_pMatrix;
    int m_id;   // 输入节点ID
};

#endif // BCSETTINGMATRIXCUTINPUTCHANNELDLG_H
