#ifndef BCSETTINGIPVCONFIGDLG_H
#define BCSETTINGIPVCONFIGDLG_H

#include <QDialog>
#include <QMap>

namespace Ui {
class BCSettingIPVConfigDlg;
}

class BCMChannel;
class BCSettingIPVConfigDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingIPVConfigDlg(BCMChannel *pChannel, QWidget *parent = 0);

    ~BCSettingIPVConfigDlg();

private slots:
    void on_m_pOKBtn_clicked();
    void on_m_pCancelBtn_clicked();

private:
    Ui::BCSettingIPVConfigDlg *ui;

    void init();

    BCMChannel      *m_pChannel;
    QMap<int, int>  m_mapSegmentAndIndex;   // 记录分割数和combbox索引的对应关系
};

#endif // BCSETTINGIPVCONFIGDLG_H
