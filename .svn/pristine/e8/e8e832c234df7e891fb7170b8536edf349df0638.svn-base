#ifndef BCSETTINGEDIDDLG_H
#define BCSETTINGEDIDDLG_H

#include <QDialog>

namespace Ui {
class BCSettingEDIDDlg;
}


class BSEDIDConfig;
class BCSettingEDIDDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingEDIDDlg(QWidget *parent = 0);
    ~BCSettingEDIDDlg();

private slots:
    void on_m_pDisplayAnalogRB_clicked();

    void on_m_pDisplayDigitalRB_clicked();

    void on_m_pSTimingEnable1CB_clicked(bool checked);

    void on_m_pSTimingEnable2CB_clicked(bool checked);

    void on_m_pSTimingEnable3CB_clicked(bool checked);

    void on_m_pSTimingEnable4CB_clicked(bool checked);

    void on_m_pSTimingView1RB_clicked();

    void on_m_pSTimingView2RB_clicked();

    void on_m_pDTimingBlock1RB_clicked();

    void on_m_pDTimingBlock2RB_clicked();

    void on_m_pDTimingBlock3RB_clicked();

    void on_m_pDTimingBlock4RB_clicked();

    void on_m_pDTimingTimingRB_clicked();

    void on_m_pDTimingMonitorRB_clicked();

    void on_m_pDTimingDataType1RB_clicked();

    void on_m_pDTimingDataType2RB_clicked();

    void on_m_pDTimingDataType3RB_clicked();

    void on_m_pDTimingDataType4RB_clicked();

    void on_m_pDTimingDataType5RB_clicked();

    void on_m_pDTimingDataType6RB_clicked();

    void on_m_pDTimingDataType7RB_clicked();

    void on_m_pDTimingDataType8RB_clicked();

    void on_m_pDTimingSecondaryTimingCB_clicked(bool checked);

    void on_m_pDTimingUsePointData1CB_clicked(bool checked);

    void on_m_pDTimingUsePointData2CB_clicked(bool checked);

    void on_m_pDTimingIDView1RB_clicked();

    void on_m_pDTimingIDView2RB_clicked();

    void on_m_pDTimingIDView3RB_clicked();

    void on_m_pDTimingAnalogRB_clicked();

    void on_m_pDTimingAnalogBipolarRB_clicked();

    void on_m_pDTimingDigitalComposionRB_clicked();

    void on_m_pDTimingDigitalSeparaRB_clicked();

    void on_m_pLoadBtn_clicked();

    void on_m_pSaveBtn_clicked();

private:
    Ui::BCSettingEDIDDlg *ui;

    void Refresh();
    void SetDetailedTimingDataTypeVisible(int index);
    void SetDetailedTimingDataTypePara0(char *para);
    void SetDetailedTimingDataTypePara2(int minVRate, int maxVRate, int minHRate, int maxHRate,
                                        int maxPxl, int secondary, int start, int k, int c, int t, int m);
    void SetDetailedTimingDataTypePara4(int usePointData1, int whitePoint1, int whiteX1, int whiteY1, int gamma1,
                                        int usePointData2, int whitePoint2, int whiteX2, int whiteY2, int gamma2);
    void SetDetailedTimingDataTypePara5(int active1, int refresh1, int aspectIndex1,
                                        int active2, int refresh2, int aspectIndex2, int index=1);

    void SetDetailedTimingTimingPara(int pixel, int hActive, int hBlank, int hSync1, int hSync2, int hImage, int hBorder,
                                     int interlaced, int vActive, int vBlank, int vSync1, int vSync2, int vImage, int vBorder,
                                     int stereoType, int syncType, int syncPara1, int syncPara2);

    // 当切换detailed timing的block时，保存上一个block的数据
    void SaveDetailedTimingPreBlockPara();

    // 当切换detailed timing的monitor下的standard timing下的View时调用
    void SaveDetailedTimingPreTimingIDPara();

    // 当切换standard timing的view时调用
    void SaveStandardTimingPara();

    BSEDIDConfig *m_pEDIDConfig;
};

#endif // BCSETTINGEDIDDLG_H
