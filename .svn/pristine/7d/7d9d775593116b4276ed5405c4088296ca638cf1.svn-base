#include "BCSettingEDIDDlg.h"
#include "ui_BCSettingEDIDDlg.h"
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"

BCSettingEDIDDlg::BCSettingEDIDDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingEDIDDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    // 最后一个tab需要隐藏某些项来实现，所以这里限制高度，否则界面会有大块空白
    this->setFixedSize(this->width(), 480);

    // 传入DLL库进行赋值
    m_pEDIDConfig = new BSEDIDConfig;

    Refresh();
}

BCSettingEDIDDlg::~BCSettingEDIDDlg()
{
    if (NULL != m_pEDIDConfig) {
        delete m_pEDIDConfig;
        m_pEDIDConfig = NULL;
    }

    delete ui;
}

void BCSettingEDIDDlg::Refresh()
{
//    BCLocalServer *pLocalServer = BCLocalServer::Application();
//    pLocalServer->GetEDIDConfig( m_pEDIDConfig );

//    QString qsVendorID = QString(m_pEDIDConfig->cVendorID[0])+QString(m_pEDIDConfig->cVendorID[1])+QString(m_pEDIDConfig->cVendorID[2]);
//    QString qsProduct = QString(m_pEDIDConfig->cProduct[0])+QString(m_pEDIDConfig->cProduct[1])+QString(m_pEDIDConfig->cProduct[2])+QString(m_pEDIDConfig->cProduct[3]);
//    ui->m_pCurrentName->setText(qsVendorID + qsProduct);

//    // general
//    ui->m_pGeneralVendorIDLE->setText( qsVendorID );
//    ui->m_pGeneralProductLE->setText( qsProduct );
//    ui->m_pGeneralSerialLE->setText( QString::number(m_pEDIDConfig->nSerial) );
//    ui->m_pGeneralMfgWeekLE->setText( QString::number(m_pEDIDConfig->nMfgWeek) );
//    ui->m_pGeneralMfgYearLE->setText( QString::number(m_pEDIDConfig->nMfgYear) );

//    ui->m_pGeneralVersionLE->setText( QString::number(m_pEDIDConfig->nVersion) );
//    ui->m_pGeneralRevisionLE->setText( QString::number(m_pEDIDConfig->nRevision) );
//    ui->m_pGeneralChecksumLE->setText( QString::number(m_pEDIDConfig->nChecksum) );
//    ui->m_pGeneralVersionLE->setEnabled( false );
//    ui->m_pGeneralRevisionLE->setEnabled( false );
//    ui->m_pGeneralChecksumLE->setEnabled( false );

//    ui->m_pGeneralExtensionLE->setText( QString::number(m_pEDIDConfig->nExtensions) );

//    // basic display parameters
//    if ( m_pEDIDConfig->nIsAnalog ) {
//        ui->m_pDisplayAnalogRB->setChecked( true );
//        on_m_pDisplayAnalogRB_clicked();
//    } else {
//        ui->m_pDisplayDigitalRB->setChecked( true );
//        on_m_pDisplayDigitalRB_clicked();
//    }

//    switch ( m_pEDIDConfig->nSignalLevelIndex ) {
//    case 0:
//        ui->m_pDisplaySignalLevel1RB->setChecked( true );
//        break;
//    case 1:
//        ui->m_pDisplaySignalLevel2RB->setChecked( true );
//        break;
//    case 2:
//        ui->m_pDisplaySignalLevel3RB->setChecked( true );
//        break;
//    default:
//        ui->m_pDisplaySignalLevel4RB->setChecked( true );
//        break;
//    }
//    ui->m_pDisplaySignalLevelSetupCB->setChecked( m_pEDIDConfig->nSetupExpected ? true : false );
//    ui->m_pDisplaySyncInput1CB->setChecked( m_pEDIDConfig->nSeparateSyncs ? true : false );
//    ui->m_pDisplaySyncInput2CB->setChecked( m_pEDIDConfig->nCompositeSyncs ? true : false );
//    ui->m_pDisplaySyncInput3CB->setChecked( m_pEDIDConfig->nSyncOnGreenVideo ? true : false );
//    ui->m_pDisplaySyncInput4CB->setChecked( m_pEDIDConfig->nSerrationOfVsync ? true : false );
//    ui->m_pDisplayDFPCB->setChecked( m_pEDIDConfig->nDFP ? true : false );

//    ui->m_pDisplayStandbyCB->setChecked( m_pEDIDConfig->nStandby ? true : false );
//    ui->m_pDisplaySuspendCB->setChecked( m_pEDIDConfig->nSuspend ? true : false );
//    ui->m_pDisplayActiveOffCB->setChecked( m_pEDIDConfig->nActiveOff ? true : false );
//    switch ( m_pEDIDConfig->nDisplayType ) {
//    case 0:
//        ui->m_pDisplayType1RB->setChecked( true );
//        break;
//    case 1:
//        ui->m_pDisplayType2RB->setChecked( true );
//        break;
//    case 2:
//        ui->m_pDisplayType3RB->setChecked( true );
//        break;
//    default:
//        ui->m_pDisplayType4RB->setChecked( true );
//        break;
//    }
//    ui->m_pDisplayRGBCB->setChecked( m_pEDIDConfig->nSRGB ? true : false );
//    ui->m_pDisplayGTFCB->setChecked( m_pEDIDConfig->nGTF ? true : false );
//    ui->m_pDisplayPreferredCB->setChecked( m_pEDIDConfig->nPreferredTiming ? true : false );

//    ui->m_pDisplayMaxHSizeLE->setText( QString::number(m_pEDIDConfig->nMaxHImageSize) );
//    ui->m_pDisplayMaxVSizeLE->setText( QString::number(m_pEDIDConfig->nMaxVImageSize) );
//    ui->m_pDisplayGammaValueLE->setText( QString::number(m_pEDIDConfig->nGammaValue*100) );

//    // color / established timings
//    ui->m_pColorRedXLE->setText( QString::number(m_pEDIDConfig->nRedX/1000, 'f', 3));
//    ui->m_pColorRedYLE->setText( QString::number(m_pEDIDConfig->nRedY/1000, 'f', 3));
//    ui->m_pColorGreenXLE->setText( QString::number(m_pEDIDConfig->nGreenX/1000, 'f', 3));
//    ui->m_pColorGreenYLE->setText( QString::number(m_pEDIDConfig->nGreenY/1000, 'f', 3));
//    ui->m_pColorBlueXLE->setText( QString::number(m_pEDIDConfig->nBlueX/1000, 'f', 3));
//    ui->m_pColorBlueYLE->setText( QString::number(m_pEDIDConfig->nBlueY/1000, 'f', 3));
//    ui->m_pColorWhiteXLE->setText( QString::number(m_pEDIDConfig->nWhiteX/1000, 'f', 3));
//    ui->m_pColorWhiteYLE->setText( QString::number(m_pEDIDConfig->nWhiteY/1000, 'f', 3));

//    ui->m_pColorEstablished1CB->setChecked( m_pEDIDConfig->nEstablishTiming1 ? true : false );
//    ui->m_pColorEstablished2CB->setChecked( m_pEDIDConfig->nEstablishTiming2 ? true : false );
//    ui->m_pColorEstablished3CB->setChecked( m_pEDIDConfig->nEstablishTiming3 ? true : false );
//    ui->m_pColorEstablished4CB->setChecked( m_pEDIDConfig->nEstablishTiming4 ? true : false );
//    ui->m_pColorEstablished5CB->setChecked( m_pEDIDConfig->nEstablishTiming5 ? true : false );
//    ui->m_pColorEstablished6CB->setChecked( m_pEDIDConfig->nEstablishTiming6 ? true : false );
//    ui->m_pColorEstablished7CB->setChecked( m_pEDIDConfig->nEstablishTiming7 ? true : false );
//    ui->m_pColorEstablished8CB->setChecked( m_pEDIDConfig->nEstablishTiming8 ? true : false );
//    ui->m_pColorEstablished9CB->setChecked( m_pEDIDConfig->nEstablishTiming9 ? true : false );
//    ui->m_pColorEstablished10CB->setChecked( m_pEDIDConfig->nEstablishTiming10 ? true : false );
//    ui->m_pColorEstablished11CB->setChecked( m_pEDIDConfig->nEstablishTiming11 ? true : false );
//    ui->m_pColorEstablished12CB->setChecked( m_pEDIDConfig->nEstablishTiming12 ? true : false );
//    ui->m_pColorEstablished13CB->setChecked( m_pEDIDConfig->nEstablishTiming13 ? true : false );
//    ui->m_pColorEstablished14CB->setChecked( m_pEDIDConfig->nEstablishTiming14 ? true : false );
//    ui->m_pColorEstablished15CB->setChecked( m_pEDIDConfig->nEstablishTiming15 ? true : false );
//    ui->m_pColorEstablished16CB->setChecked( m_pEDIDConfig->nEstablishTiming16 ? true : false );
//    ui->m_pColorEstablished17CB->setChecked( m_pEDIDConfig->nEstablishTiming17 ? true : false );

//    // standard timings
//    // 初始化只显示前四个
//    ui->m_pSTimingView1RB->setChecked( true );
//    ui->m_pSTiming1GB->setTitle( QString("Timing ID#1") );
//    ui->m_pSTimingEnable1CB->setChecked( m_pEDIDConfig->nTimingEnable1 ? true : false );
//    on_m_pSTimingEnable1CB_clicked( m_pEDIDConfig->nTimingEnable1 ? true : false );
//    ui->m_pSTimingActive1LE->setText( QString::number(m_pEDIDConfig->nHActive1) );
//    ui->m_pSTimingRefresh1LE->setText( QString::number(m_pEDIDConfig->nRefresh1) );
//    switch ( m_pEDIDConfig->nAspectRatioIndex1 ) {
//    case 0:
//        ui->m_pSTimingAspect11RB->setChecked( true );
//        break;
//    case 1:
//        ui->m_pSTimingAspect12RB->setChecked( true );
//        break;
//    case 2:
//        ui->m_pSTimingAspect13RB->setChecked( true );
//        break;
//    default:
//        ui->m_pSTimingAspect14RB->setChecked( true );
//        break;
//    }

//    ui->m_pSTiming2GB->setTitle( QString("Timing ID#2") );
//    ui->m_pSTimingEnable2CB->setChecked( m_pEDIDConfig->nTimingEnable2 ? true : false );
//    on_m_pSTimingEnable2CB_clicked( m_pEDIDConfig->nTimingEnable2 ? true : false );
//    ui->m_pSTimingActive2LE->setText( QString::number(m_pEDIDConfig->nHActive2) );
//    ui->m_pSTimingRefresh2LE->setText( QString::number(m_pEDIDConfig->nRefresh2) );
//    switch ( m_pEDIDConfig->nAspectRatioIndex2 ) {
//    case 0:
//        ui->m_pSTimingAspect21RB->setChecked( true );
//        break;
//    case 1:
//        ui->m_pSTimingAspect22RB->setChecked( true );
//        break;
//    case 2:
//        ui->m_pSTimingAspect23RB->setChecked( true );
//        break;
//    default:
//        ui->m_pSTimingAspect24RB->setChecked( true );
//        break;
//    }

//    ui->m_pSTiming3GB->setTitle( QString("Timing ID#3") );
//    ui->m_pSTimingEnable3CB->setChecked( m_pEDIDConfig->nTimingEnable3 ? true : false );
//    on_m_pSTimingEnable3CB_clicked( m_pEDIDConfig->nTimingEnable3 ? true : false );
//    ui->m_pSTimingActive3LE->setText( QString::number(m_pEDIDConfig->nHActive3) );
//    ui->m_pSTimingRefresh3LE->setText( QString::number(m_pEDIDConfig->nRefresh3) );
//    switch ( m_pEDIDConfig->nAspectRatioIndex3 ) {
//    case 0:
//        ui->m_pSTimingAspect31RB->setChecked( true );
//        break;
//    case 1:
//        ui->m_pSTimingAspect32RB->setChecked( true );
//        break;
//    case 2:
//        ui->m_pSTimingAspect33RB->setChecked( true );
//        break;
//    default:
//        ui->m_pSTimingAspect34RB->setChecked( true );
//        break;
//    }

//    ui->m_pSTiming4GB->setTitle( QString("Timing ID#4") );
//    ui->m_pSTimingEnable4CB->setChecked( m_pEDIDConfig->nTimingEnable4 ? true : false );
//    on_m_pSTimingEnable4CB_clicked( m_pEDIDConfig->nTimingEnable4 ? true : false );
//    ui->m_pSTimingActive4LE->setText( QString::number(m_pEDIDConfig->nHActive4) );
//    ui->m_pSTimingRefresh4LE->setText( QString::number(m_pEDIDConfig->nRefresh4) );
//    switch ( m_pEDIDConfig->nAspectRatioIndex4 ) {
//    case 0:
//        ui->m_pSTimingAspect41RB->setChecked( true );
//        break;
//    case 1:
//        ui->m_pSTimingAspect42RB->setChecked( true );
//        break;
//    case 2:
//        ui->m_pSTimingAspect43RB->setChecked( true );
//        break;
//    default:
//        ui->m_pSTimingAspect44RB->setChecked( true );
//        break;
//    }

//    // detailed timings
//    ui->m_pDTimingBlock1RB->setChecked( true );

//    // 类型模块
//    ui->m_pDTimingBlockParasGB->setTitle( QString("Block #1") );
//    ui->m_pDTimingDescriptorGB->setEnabled( false );
//    ui->m_pDTimingTimingRB->setChecked( true );

//    // 参数模块
//    ui->m_pDTimingDataTypeGB->hide();
//    ui->m_pDTimingDataTypeParasGB->hide();
//    ui->m_pDTimingTimingsGB->show();
//    ui->m_pDTimingStereoDisplayGB->show();
//    ui->m_pDTimingSyncSchemeGB->show();

//    // timing paras
//    SetDetailedTimingTimingPara(m_pEDIDConfig->nBlock1Pixel, m_pEDIDConfig->nBlock1HActive, m_pEDIDConfig->nBlock1HBlank,
//                                m_pEDIDConfig->nBlock1HSync1, m_pEDIDConfig->nBlock1HSync2, m_pEDIDConfig->nBlock1HImage, m_pEDIDConfig->nBlock1HBorder,
//                                m_pEDIDConfig->nBlock1Interlaced, m_pEDIDConfig->nBlock1VActive, m_pEDIDConfig->nBlock1VBlank,
//                                m_pEDIDConfig->nBlock1VSync1, m_pEDIDConfig->nBlock1VSync2, m_pEDIDConfig->nBlock1VImage, m_pEDIDConfig->nBlock1VBorder,
//                                m_pEDIDConfig->nBlock1StereoDisplayType, m_pEDIDConfig->nBlock1SyncSchemeType,
//                                m_pEDIDConfig->nBlock1SyncSchemePara1, m_pEDIDConfig->nBlock1SyncSchemePara2);

//    // 刷新数据后显示第一页
//    ui->m_pTableWidget->setCurrentIndex( 0 );
}

void BCSettingEDIDDlg::on_m_pDisplayAnalogRB_clicked()
{
    ui->m_pDisplaySignalLevelGB->setEnabled( true );
    ui->m_pDisplaySyncInputGB->setEnabled( true );

    ui->m_pDisplayDFPCB->setEnabled( false );
}

void BCSettingEDIDDlg::on_m_pDisplayDigitalRB_clicked()
{
    ui->m_pDisplaySignalLevelGB->setEnabled( false );
    ui->m_pDisplaySyncInputGB->setEnabled( false );

    ui->m_pDisplayDFPCB->setEnabled( true );
}

void BCSettingEDIDDlg::on_m_pSTimingEnable1CB_clicked(bool bChecked)
{
    ui->m_pSTimingActive1LE->setEnabled( bChecked );
    ui->m_pSTimingRefresh1LE->setEnabled( bChecked );
    ui->m_pSTimingRatio1GB->setEnabled( bChecked );
}

void BCSettingEDIDDlg::on_m_pSTimingEnable2CB_clicked(bool bChecked)
{
    ui->m_pSTimingActive2LE->setEnabled( bChecked );
    ui->m_pSTimingRefresh2LE->setEnabled( bChecked );
    ui->m_pSTimingRatio2GB->setEnabled( bChecked );
}

void BCSettingEDIDDlg::on_m_pSTimingEnable3CB_clicked(bool bChecked)
{
    ui->m_pSTimingActive3LE->setEnabled( bChecked );
    ui->m_pSTimingRefresh3LE->setEnabled( bChecked );
    ui->m_pSTimingRatio3GB->setEnabled( bChecked );
}

void BCSettingEDIDDlg::on_m_pSTimingEnable4CB_clicked(bool bChecked)
{
    ui->m_pSTimingActive4LE->setEnabled( bChecked );
    ui->m_pSTimingRefresh4LE->setEnabled( bChecked );
    ui->m_pSTimingRatio4GB->setEnabled( bChecked );
}

void BCSettingEDIDDlg::SaveStandardTimingPara()
{
    if (ui->m_pSTiming1GB->title() == "Timing ID#1") {
        m_pEDIDConfig->nTimingEnable1 = ui->m_pSTimingEnable1CB->isChecked() ? 1 : 0;
        m_pEDIDConfig->nHActive1 = ui->m_pSTimingActive1LE->text().toInt();
        m_pEDIDConfig->nRefresh1 = ui->m_pSTimingRefresh1LE->text().toInt();
        m_pEDIDConfig->nAspectRatioIndex1 = ui->m_pSTimingAspect11RB->isChecked() ?
                    0 : ui->m_pSTimingAspect12RB->isChecked() ?
                        1 : ui->m_pSTimingAspect13RB->isChecked() ? 2 : 3;

        m_pEDIDConfig->nTimingEnable2 = ui->m_pSTimingEnable2CB->isChecked() ? 1 : 0;
        m_pEDIDConfig->nHActive2 = ui->m_pSTimingActive2LE->text().toInt();
        m_pEDIDConfig->nRefresh2 = ui->m_pSTimingRefresh2LE->text().toInt();
        m_pEDIDConfig->nAspectRatioIndex2 = ui->m_pSTimingAspect21RB->isChecked() ?
                    0 : ui->m_pSTimingAspect22RB->isChecked() ?
                        1 : ui->m_pSTimingAspect23RB->isChecked() ? 2 : 3;

        m_pEDIDConfig->nTimingEnable3 = ui->m_pSTimingEnable3CB->isChecked() ? 1 : 0;
        m_pEDIDConfig->nHActive3 = ui->m_pSTimingActive3LE->text().toInt();
        m_pEDIDConfig->nRefresh3 = ui->m_pSTimingRefresh3LE->text().toInt();
        m_pEDIDConfig->nAspectRatioIndex3 = ui->m_pSTimingAspect31RB->isChecked() ?
                    0 : ui->m_pSTimingAspect32RB->isChecked() ?
                        1 : ui->m_pSTimingAspect33RB->isChecked() ? 2 : 3;

        m_pEDIDConfig->nTimingEnable4 = ui->m_pSTimingEnable4CB->isChecked() ? 1 : 0;
        m_pEDIDConfig->nHActive4 = ui->m_pSTimingActive4LE->text().toInt();
        m_pEDIDConfig->nRefresh4 = ui->m_pSTimingRefresh4LE->text().toInt();
        m_pEDIDConfig->nAspectRatioIndex4 = ui->m_pSTimingAspect41RB->isChecked() ?
                    0 : ui->m_pSTimingAspect42RB->isChecked() ?
                        1 : ui->m_pSTimingAspect43RB->isChecked() ? 2 : 3;
    } else {
        m_pEDIDConfig->nTimingEnable5 = ui->m_pSTimingEnable1CB->isChecked() ? 1 : 0;
        m_pEDIDConfig->nHActive5 = ui->m_pSTimingActive1LE->text().toInt();
        m_pEDIDConfig->nRefresh5 = ui->m_pSTimingRefresh1LE->text().toInt();
        m_pEDIDConfig->nAspectRatioIndex5 = ui->m_pSTimingAspect11RB->isChecked() ?
                    0 : ui->m_pSTimingAspect12RB->isChecked() ?
                        1 : ui->m_pSTimingAspect13RB->isChecked() ? 2 : 3;

        m_pEDIDConfig->nTimingEnable6 = ui->m_pSTimingEnable2CB->isChecked() ? 1 : 0;
        m_pEDIDConfig->nHActive6 = ui->m_pSTimingActive2LE->text().toInt();
        m_pEDIDConfig->nRefresh6 = ui->m_pSTimingRefresh2LE->text().toInt();
        m_pEDIDConfig->nAspectRatioIndex6 = ui->m_pSTimingAspect21RB->isChecked() ?
                    0 : ui->m_pSTimingAspect22RB->isChecked() ?
                        1 : ui->m_pSTimingAspect23RB->isChecked() ? 2 : 3;

        m_pEDIDConfig->nTimingEnable7 = ui->m_pSTimingEnable3CB->isChecked() ? 1 : 0;
        m_pEDIDConfig->nHActive7 = ui->m_pSTimingActive3LE->text().toInt();
        m_pEDIDConfig->nRefresh7 = ui->m_pSTimingRefresh3LE->text().toInt();
        m_pEDIDConfig->nAspectRatioIndex7 = ui->m_pSTimingAspect31RB->isChecked() ?
                    0 : ui->m_pSTimingAspect32RB->isChecked() ?
                        1 : ui->m_pSTimingAspect33RB->isChecked() ? 2 : 3;

        m_pEDIDConfig->nTimingEnable8 = ui->m_pSTimingEnable4CB->isChecked() ? 1 : 0;
        m_pEDIDConfig->nHActive8 = ui->m_pSTimingActive4LE->text().toInt();
        m_pEDIDConfig->nRefresh8 = ui->m_pSTimingRefresh4LE->text().toInt();
        m_pEDIDConfig->nAspectRatioIndex8 = ui->m_pSTimingAspect41RB->isChecked() ?
                    0 : ui->m_pSTimingAspect42RB->isChecked() ?
                        1 : ui->m_pSTimingAspect43RB->isChecked() ? 2 : 3;
    }
}

void BCSettingEDIDDlg::on_m_pSTimingView1RB_clicked()
{
    // 保存数据
    SaveStandardTimingPara();

    ui->m_pSTiming1GB->setTitle( QString("Timing ID#1") );
    ui->m_pSTimingEnable1CB->setChecked( m_pEDIDConfig->nTimingEnable1 ? true : false );
    on_m_pSTimingEnable1CB_clicked( m_pEDIDConfig->nTimingEnable1 ? true : false );
    ui->m_pSTimingActive1LE->setText( QString::number(m_pEDIDConfig->nHActive1) );
    ui->m_pSTimingRefresh1LE->setText( QString::number(m_pEDIDConfig->nRefresh1) );
    switch ( m_pEDIDConfig->nAspectRatioIndex1 ) {
    case 0:
        ui->m_pSTimingAspect11RB->setChecked( true );
        break;
    case 1:
        ui->m_pSTimingAspect12RB->setChecked( true );
        break;
    case 2:
        ui->m_pSTimingAspect13RB->setChecked( true );
        break;
    default:
        ui->m_pSTimingAspect14RB->setChecked( true );
        break;
    }

    ui->m_pSTiming2GB->setTitle( QString("Timing ID#2") );
    ui->m_pSTimingEnable2CB->setChecked( m_pEDIDConfig->nTimingEnable2 ? true : false );
    on_m_pSTimingEnable2CB_clicked( m_pEDIDConfig->nTimingEnable2 ? true : false );
    ui->m_pSTimingActive2LE->setText( QString::number(m_pEDIDConfig->nHActive2) );
    ui->m_pSTimingRefresh2LE->setText( QString::number(m_pEDIDConfig->nRefresh2) );
    switch ( m_pEDIDConfig->nAspectRatioIndex2 ) {
    case 0:
        ui->m_pSTimingAspect21RB->setChecked( true );
        break;
    case 1:
        ui->m_pSTimingAspect22RB->setChecked( true );
        break;
    case 2:
        ui->m_pSTimingAspect23RB->setChecked( true );
        break;
    default:
        ui->m_pSTimingAspect24RB->setChecked( true );
        break;
    }

    ui->m_pSTiming3GB->setTitle( QString("Timing ID#3") );
    ui->m_pSTimingEnable3CB->setChecked( m_pEDIDConfig->nTimingEnable3 ? true : false );
    on_m_pSTimingEnable3CB_clicked( m_pEDIDConfig->nTimingEnable3 ? true : false );
    ui->m_pSTimingActive3LE->setText( QString::number(m_pEDIDConfig->nHActive3) );
    ui->m_pSTimingRefresh3LE->setText( QString::number(m_pEDIDConfig->nRefresh3) );
    switch ( m_pEDIDConfig->nAspectRatioIndex3 ) {
    case 0:
        ui->m_pSTimingAspect31RB->setChecked( true );
        break;
    case 1:
        ui->m_pSTimingAspect32RB->setChecked( true );
        break;
    case 2:
        ui->m_pSTimingAspect33RB->setChecked( true );
        break;
    default:
        ui->m_pSTimingAspect34RB->setChecked( true );
        break;
    }

    ui->m_pSTiming4GB->setTitle( QString("Timing ID#4") );
    ui->m_pSTimingEnable4CB->setChecked( m_pEDIDConfig->nTimingEnable4 ? true : false );
    on_m_pSTimingEnable4CB_clicked( m_pEDIDConfig->nTimingEnable4 ? true : false );
    ui->m_pSTimingActive4LE->setText( QString::number(m_pEDIDConfig->nHActive4) );
    ui->m_pSTimingRefresh4LE->setText( QString::number(m_pEDIDConfig->nRefresh4) );
    switch ( m_pEDIDConfig->nAspectRatioIndex4 ) {
    case 0:
        ui->m_pSTimingAspect41RB->setChecked( true );
        break;
    case 1:
        ui->m_pSTimingAspect42RB->setChecked( true );
        break;
    case 2:
        ui->m_pSTimingAspect43RB->setChecked( true );
        break;
    default:
        ui->m_pSTimingAspect44RB->setChecked( true );
        break;
    }
}

void BCSettingEDIDDlg::on_m_pSTimingView2RB_clicked()
{
    // 保存数据
    SaveStandardTimingPara();

    ui->m_pSTiming1GB->setTitle( QString("Timing ID#5") );
    ui->m_pSTimingEnable1CB->setChecked( m_pEDIDConfig->nTimingEnable5 ? true : false );
    ui->m_pSTimingActive1LE->setText( QString::number(m_pEDIDConfig->nHActive5) );
    ui->m_pSTimingRefresh1LE->setText( QString::number(m_pEDIDConfig->nRefresh5) );
    switch ( m_pEDIDConfig->nAspectRatioIndex5 ) {
    case 0:
        ui->m_pSTimingAspect11RB->setChecked( true );
        break;
    case 1:
        ui->m_pSTimingAspect12RB->setChecked( true );
        break;
    case 2:
        ui->m_pSTimingAspect13RB->setChecked( true );
        break;
    default:
        ui->m_pSTimingAspect14RB->setChecked( true );
        break;
    }

    ui->m_pSTiming2GB->setTitle( QString("Timing ID#6") );
    ui->m_pSTimingEnable2CB->setChecked( m_pEDIDConfig->nTimingEnable6 ? true : false );
    ui->m_pSTimingActive2LE->setText( QString::number(m_pEDIDConfig->nHActive6) );
    ui->m_pSTimingRefresh2LE->setText( QString::number(m_pEDIDConfig->nRefresh6) );
    switch ( m_pEDIDConfig->nAspectRatioIndex6 ) {
    case 0:
        ui->m_pSTimingAspect21RB->setChecked( true );
        break;
    case 1:
        ui->m_pSTimingAspect22RB->setChecked( true );
        break;
    case 2:
        ui->m_pSTimingAspect23RB->setChecked( true );
        break;
    default:
        ui->m_pSTimingAspect24RB->setChecked( true );
        break;
    }

    ui->m_pSTiming3GB->setTitle( QString("Timing ID#7") );
    ui->m_pSTimingEnable3CB->setChecked( m_pEDIDConfig->nTimingEnable7 ? true : false );
    ui->m_pSTimingActive3LE->setText( QString::number(m_pEDIDConfig->nHActive7) );
    ui->m_pSTimingRefresh3LE->setText( QString::number(m_pEDIDConfig->nRefresh7) );
    switch ( m_pEDIDConfig->nAspectRatioIndex7 ) {
    case 0:
        ui->m_pSTimingAspect31RB->setChecked( true );
        break;
    case 1:
        ui->m_pSTimingAspect32RB->setChecked( true );
        break;
    case 2:
        ui->m_pSTimingAspect33RB->setChecked( true );
        break;
    default:
        ui->m_pSTimingAspect34RB->setChecked( true );
        break;
    }

    ui->m_pSTiming4GB->setTitle( QString("Timing ID#8") );
    ui->m_pSTimingEnable4CB->setChecked( m_pEDIDConfig->nTimingEnable8 ? true : false );
    ui->m_pSTimingActive4LE->setText( QString::number(m_pEDIDConfig->nHActive8) );
    ui->m_pSTimingRefresh4LE->setText( QString::number(m_pEDIDConfig->nRefresh8) );
    switch ( m_pEDIDConfig->nAspectRatioIndex8 ) {
    case 0:
        ui->m_pSTimingAspect41RB->setChecked( true );
        break;
    case 1:
        ui->m_pSTimingAspect42RB->setChecked( true );
        break;
    case 2:
        ui->m_pSTimingAspect43RB->setChecked( true );
        break;
    default:
        ui->m_pSTimingAspect44RB->setChecked( true );
        break;
    }
}

void BCSettingEDIDDlg::SaveDetailedTimingPreBlockPara()
{
    if (ui->m_pDTimingBlockParasGB->title() == "Block #1") {
        m_pEDIDConfig->nBlock1Pixel = ui->m_pDTimingPixelLE->text().toInt();
        m_pEDIDConfig->nBlock1HActive = ui->m_pDTimingHActiveLE->text().toInt();
        m_pEDIDConfig->nBlock1HBlank = ui->m_pDTimingHBlankLE->text().toInt();
        m_pEDIDConfig->nBlock1HSync1 = ui->m_pDTimingHSync1LE->text().toInt();
        m_pEDIDConfig->nBlock1HSync2 = ui->m_pDTimingHSync2LE->text().toInt();
        m_pEDIDConfig->nBlock1HImage = ui->m_pDTimingHImageLE->text().toInt();
        m_pEDIDConfig->nBlock1HBorder = ui->m_pDTimingHBorderLE->text().toInt();
        m_pEDIDConfig->nBlock1Interlaced = (int)ui->m_pDTimingInterlacedCB->isChecked();
        m_pEDIDConfig->nBlock1VActive = ui->m_pDTimingVActiveLE->text().toInt();
        m_pEDIDConfig->nBlock1VBlank = ui->m_pDTimingVBlankLE->text().toInt();
        m_pEDIDConfig->nBlock1VSync1 = ui->m_pDTimingVSync1LE->text().toInt();
        m_pEDIDConfig->nBlock1VSync2 = ui->m_pDTimingVSync2LE->text().toInt();
        m_pEDIDConfig->nBlock1VImage = ui->m_pDTimingVImageLE->text().toInt();
        m_pEDIDConfig->nBlock1VBorder = ui->m_pDTimingVBorderLE->text().toInt();
        m_pEDIDConfig->nBlock1StereoDisplayType = ui->m_pDTimingNormalyRB->isChecked() ?
                    0 : ui->m_pDTimingFSRRB->isChecked() ?
                        1 : ui->m_pDTimingFSLRB->isChecked() ?
                            2 : ui->m_pDTiming4WayRB->isChecked() ?
                                3: ui->m_pDTiming2WayRRB->isChecked() ?
                                    4 : ui->m_pDTiming2WayLRB->isChecked() ? 5 : 6;
        m_pEDIDConfig->nBlock1SyncSchemeType = ui->m_pDTimingAnalogRB->isChecked() ?
                    0 : ui->m_pDTimingAnalogBipolarRB->isChecked() ?
                        1 : ui->m_pDTimingDigitalComposionRB->isChecked() ? 2 : 3;
        m_pEDIDConfig->nBlock1SyncSchemePara1 = (int)ui->m_pDTimingSyncSchemePara1CB->isChecked();
        m_pEDIDConfig->nBlock1SyncSchemePara2 = (int)ui->m_pDTimingSyncSchemePara2CB->isChecked();
    }

    if (ui->m_pDTimingBlockParasGB->title() == "Block #2") {
        if ( ui->m_pDTimingTimingRB->isChecked() ) {
            m_pEDIDConfig->nBlock2Pixel = ui->m_pDTimingPixelLE->text().toInt();
            m_pEDIDConfig->nBlock2HActive = ui->m_pDTimingHActiveLE->text().toInt();
            m_pEDIDConfig->nBlock2HBlank = ui->m_pDTimingHBlankLE->text().toInt();
            m_pEDIDConfig->nBlock2HSync1 = ui->m_pDTimingHSync1LE->text().toInt();
            m_pEDIDConfig->nBlock2HSync2 = ui->m_pDTimingHSync2LE->text().toInt();
            m_pEDIDConfig->nBlock2HImage = ui->m_pDTimingHImageLE->text().toInt();
            m_pEDIDConfig->nBlock2HBorder = ui->m_pDTimingHBorderLE->text().toInt();
            m_pEDIDConfig->nBlock2Interlaced = (int)ui->m_pDTimingInterlacedCB->isChecked();
            m_pEDIDConfig->nBlock2VActive = ui->m_pDTimingVActiveLE->text().toInt();
            m_pEDIDConfig->nBlock2VBlank = ui->m_pDTimingVBlankLE->text().toInt();
            m_pEDIDConfig->nBlock2VSync1 = ui->m_pDTimingVSync1LE->text().toInt();
            m_pEDIDConfig->nBlock2VSync2 = ui->m_pDTimingVSync2LE->text().toInt();
            m_pEDIDConfig->nBlock2VImage = ui->m_pDTimingVImageLE->text().toInt();
            m_pEDIDConfig->nBlock2VBorder = ui->m_pDTimingVBorderLE->text().toInt();
            m_pEDIDConfig->nBlock2StereoDisplayType = ui->m_pDTimingNormalyRB->isChecked() ?
                        0 : ui->m_pDTimingFSRRB->isChecked() ?
                            1 : ui->m_pDTimingFSLRB->isChecked() ?
                                2 : ui->m_pDTiming4WayRB->isChecked() ?
                                    3: ui->m_pDTiming2WayRRB->isChecked() ?
                                        4 : ui->m_pDTiming2WayLRB->isChecked() ? 5 : 6;
            m_pEDIDConfig->nBlock2SyncSchemeType = ui->m_pDTimingAnalogRB->isChecked() ?
                        0 : ui->m_pDTimingAnalogBipolarRB->isChecked() ?
                            1 : ui->m_pDTimingDigitalComposionRB->isChecked() ? 2 : 3;
            m_pEDIDConfig->nBlock2SyncSchemePara1 = (int)ui->m_pDTimingSyncSchemePara1CB->isChecked();
            m_pEDIDConfig->nBlock2SyncSchemePara2 = (int)ui->m_pDTimingSyncSchemePara2CB->isChecked();
        } else {
            m_pEDIDConfig->nBlock2DataTypeIndex = ui->m_pDTimingDataType1RB->isChecked() ?
                        0 : ui->m_pDTimingDataType2RB->isChecked() ?
                            1 : ui->m_pDTimingDataType3RB->isChecked() ?
                                2 : ui->m_pDTimingDataType4RB->isChecked() ?
                                    3 : ui->m_pDTimingDataType5RB->isChecked() ?
                                        4 : ui->m_pDTimingDataType6RB->isChecked() ?
                                            5 : ui->m_pDTimingDataType7RB->isChecked() ? 6 : 7;

            // 设置参数
            switch (m_pEDIDConfig->nBlock2DataTypeIndex) {
            case 0:
                strcpy(m_pEDIDConfig->cBlock2SerialNumber, BCCommon::getTextStr(ui->m_pDTimingMax13LE->text()));
                break;
            case 1:
                strcpy(m_pEDIDConfig->cBlock2ASCIIString, BCCommon::getTextStr(ui->m_pDTimingMax13LE->text()));
                break;
            case 2:
                m_pEDIDConfig->nBlock2MinVRate = ui->m_pDTimingMinVRateLE->text().toInt();
                m_pEDIDConfig->nBlock2MaxVRate = ui->m_pDTimingMaxVRateLE->text().toInt();
                m_pEDIDConfig->nBlock2MinHRate = ui->m_pDTimingMinHRateLE->text().toInt();
                m_pEDIDConfig->nBlock2MaxHRate = ui->m_pDTimingMaxHRateLE->text().toInt();
                m_pEDIDConfig->nBlock2MaxPxlClk = ui->m_pDTimingMaxPxlClkLE->text().toInt();
                m_pEDIDConfig->nBlock2SecondaryTiming = ui->m_pDTimingSecondaryTimingCB->isChecked() ? 1 : 0;
                m_pEDIDConfig->nBlock2Start = ui->m_pDTimingStartLE->text().toInt();
                m_pEDIDConfig->nBlock2K = ui->m_pDTimingKLE->text().toInt();
                m_pEDIDConfig->nBlock2C = ui->m_pDTimingCLE->text().toInt();
                m_pEDIDConfig->nBlock2T = ui->m_pDTimingTLE->text().toInt();
                m_pEDIDConfig->nBlock2M = ui->m_pDTimingMLE->text().toInt();
                break;
            case 3:
                strcpy(m_pEDIDConfig->cBlock2MonitorName, BCCommon::getTextStr(ui->m_pDTimingMax13LE->text()));
                break;
            case 4:
                m_pEDIDConfig->nBlock2UsePointData1 = ui->m_pDTimingUsePointData1CB->isChecked() ? 1 : 0;
                m_pEDIDConfig->nBlock2WhitePoint1 = ui->m_pDTimingWhitePoint1LE->text().toInt();
                m_pEDIDConfig->nBlock2WhiteX1 = ui->m_pDTimingWhiteX1LE->text().toInt();
                m_pEDIDConfig->nBlock2WhiteY1 = ui->m_pDTimingWhiteY1LE->text().toInt();
                m_pEDIDConfig->nBlock2Gamma1 = ui->m_pDTimingGamma1LE->text().toInt();

                m_pEDIDConfig->nBlock2UsePointData2 = ui->m_pDTimingUsePointData2CB->isChecked() ? 1 : 0;
                m_pEDIDConfig->nBlock2WhitePoint2 = ui->m_pDTimingWhitePoint2LE->text().toInt();
                m_pEDIDConfig->nBlock2WhiteX2 = ui->m_pDTimingWhiteX2LE->text().toInt();
                m_pEDIDConfig->nBlock2WhiteY2 = ui->m_pDTimingWhiteY2LE->text().toInt();
                m_pEDIDConfig->nBlock2Gamma2 = ui->m_pDTimingGamma2LE->text().toInt();
                break;
            case 5:
                // 1-2
                if ( ui->m_pDTimingIDView1RB->isChecked() ) {
                    m_pEDIDConfig->nBlock2TimingID1Active = ui->m_pDTimingIDAction1LE->text().toInt();
                    m_pEDIDConfig->nBlock2TimingID1Refresh = ui->m_pDTimingIDRefresh1LE->text().toInt();
                    m_pEDIDConfig->nBlock2TimingID1AspectIndex = ui->m_pDTimingIDAspect11RB->isChecked() ?
                                0 : ui->m_pDTimingIDAspect12RB->isChecked() ?
                                    1 : ui->m_pDTimingIDAspect13RB->isChecked() ? 2 : 3;

                    m_pEDIDConfig->nBlock2TimingID2Active = ui->m_pDTimingIDAction2LE->text().toInt();
                    m_pEDIDConfig->nBlock2TimingID2Refresh = ui->m_pDTimingIDRefresh2LE->text().toInt();
                    m_pEDIDConfig->nBlock2TimingID2AspectIndex = ui->m_pDTimingIDAspect21RB->isChecked() ?
                                0 : ui->m_pDTimingIDAspect22RB->isChecked() ?
                                    1 : ui->m_pDTimingIDAspect23RB->isChecked() ? 2 : 3;
                }

                // 3-4
                if ( ui->m_pDTimingIDView2RB->isChecked() ) {
                    m_pEDIDConfig->nBlock2TimingID3Active = ui->m_pDTimingIDAction1LE->text().toInt();
                    m_pEDIDConfig->nBlock2TimingID3Refresh = ui->m_pDTimingIDRefresh1LE->text().toInt();
                    m_pEDIDConfig->nBlock2TimingID3AspectIndex = ui->m_pDTimingIDAspect11RB->isChecked() ?
                                0 : ui->m_pDTimingIDAspect12RB->isChecked() ?
                                    1 : ui->m_pDTimingIDAspect13RB->isChecked() ? 2 : 3;

                    m_pEDIDConfig->nBlock2TimingID4Active = ui->m_pDTimingIDAction2LE->text().toInt();
                    m_pEDIDConfig->nBlock2TimingID4Refresh = ui->m_pDTimingIDRefresh2LE->text().toInt();
                    m_pEDIDConfig->nBlock2TimingID4AspectIndex = ui->m_pDTimingIDAspect21RB->isChecked() ?
                                0 : ui->m_pDTimingIDAspect22RB->isChecked() ?
                                    1 : ui->m_pDTimingIDAspect23RB->isChecked() ? 2 : 3;

                }

                // 5-6
                if ( ui->m_pDTimingIDView3RB->isChecked() ) {
                    m_pEDIDConfig->nBlock2TimingID5Active = ui->m_pDTimingIDAction1LE->text().toInt();
                    m_pEDIDConfig->nBlock2TimingID5Refresh = ui->m_pDTimingIDRefresh1LE->text().toInt();
                    m_pEDIDConfig->nBlock2TimingID5AspectIndex = ui->m_pDTimingIDAspect11RB->isChecked() ?
                                0 : ui->m_pDTimingIDAspect12RB->isChecked() ?
                                    1 : ui->m_pDTimingIDAspect13RB->isChecked() ? 2 : 3;

                    m_pEDIDConfig->nBlock2TimingID6Active = ui->m_pDTimingIDAction2LE->text().toInt();
                    m_pEDIDConfig->nBlock2TimingID6Refresh = ui->m_pDTimingIDRefresh2LE->text().toInt();
                    m_pEDIDConfig->nBlock2TimingID6AspectIndex = ui->m_pDTimingIDAspect21RB->isChecked() ?
                                0 : ui->m_pDTimingIDAspect22RB->isChecked() ?
                                    1 : ui->m_pDTimingIDAspect23RB->isChecked() ? 2 : 3;

                }

                break;
            case 6:
                break;
            default:
                strcpy(m_pEDIDConfig->cBlock2MfgDefined, BCCommon::getTextStr(ui->m_pDTimingMax13LE->text()));
                break;
            }
        }
    }

    if (ui->m_pDTimingBlockParasGB->title() == "Block #3") {
        if ( ui->m_pDTimingTimingRB->isChecked() ) {
            m_pEDIDConfig->nBlock3Pixel = ui->m_pDTimingPixelLE->text().toInt();
            m_pEDIDConfig->nBlock3HActive = ui->m_pDTimingHActiveLE->text().toInt();
            m_pEDIDConfig->nBlock3HBlank = ui->m_pDTimingHBlankLE->text().toInt();
            m_pEDIDConfig->nBlock3HSync1 = ui->m_pDTimingHSync1LE->text().toInt();
            m_pEDIDConfig->nBlock3HSync2 = ui->m_pDTimingHSync2LE->text().toInt();
            m_pEDIDConfig->nBlock3HImage = ui->m_pDTimingHImageLE->text().toInt();
            m_pEDIDConfig->nBlock3HBorder = ui->m_pDTimingHBorderLE->text().toInt();
            m_pEDIDConfig->nBlock3Interlaced = (int)ui->m_pDTimingInterlacedCB->isChecked();
            m_pEDIDConfig->nBlock3VActive = ui->m_pDTimingVActiveLE->text().toInt();
            m_pEDIDConfig->nBlock3VBlank = ui->m_pDTimingVBlankLE->text().toInt();
            m_pEDIDConfig->nBlock3VSync1 = ui->m_pDTimingVSync1LE->text().toInt();
            m_pEDIDConfig->nBlock3VSync2 = ui->m_pDTimingVSync2LE->text().toInt();
            m_pEDIDConfig->nBlock3VImage = ui->m_pDTimingVImageLE->text().toInt();
            m_pEDIDConfig->nBlock3VBorder = ui->m_pDTimingVBorderLE->text().toInt();
            m_pEDIDConfig->nBlock3StereoDisplayType = ui->m_pDTimingNormalyRB->isChecked() ?
                        0 : ui->m_pDTimingFSRRB->isChecked() ?
                            1 : ui->m_pDTimingFSLRB->isChecked() ?
                                2 : ui->m_pDTiming4WayRB->isChecked() ?
                                    3: ui->m_pDTiming2WayRRB->isChecked() ?
                                        4 : ui->m_pDTiming2WayLRB->isChecked() ? 5 : 6;
            m_pEDIDConfig->nBlock3SyncSchemeType = ui->m_pDTimingAnalogRB->isChecked() ?
                        0 : ui->m_pDTimingAnalogBipolarRB->isChecked() ?
                            1 : ui->m_pDTimingDigitalComposionRB->isChecked() ? 2 : 3;
            m_pEDIDConfig->nBlock3SyncSchemePara1 = (int)ui->m_pDTimingSyncSchemePara1CB->isChecked();
            m_pEDIDConfig->nBlock3SyncSchemePara2 = (int)ui->m_pDTimingSyncSchemePara2CB->isChecked();
        } else {
            m_pEDIDConfig->nBlock3DataTypeIndex = ui->m_pDTimingDataType1RB->isChecked() ?
                        0 : ui->m_pDTimingDataType2RB->isChecked() ?
                            1 : ui->m_pDTimingDataType3RB->isChecked() ?
                                2 : ui->m_pDTimingDataType4RB->isChecked() ?
                                    3 : ui->m_pDTimingDataType5RB->isChecked() ?
                                        4 : ui->m_pDTimingDataType6RB->isChecked() ?
                                            5 : ui->m_pDTimingDataType7RB->isChecked() ? 6 : 7;

            // 设置参数
            switch (m_pEDIDConfig->nBlock3DataTypeIndex) {
            case 0:
                strcpy(m_pEDIDConfig->cBlock3SerialNumber, BCCommon::getTextStr(ui->m_pDTimingMax13LE->text()));
                break;
            case 1:
                strcpy(m_pEDIDConfig->cBlock3ASCIIString, BCCommon::getTextStr(ui->m_pDTimingMax13LE->text()));
                break;
            case 2:
                m_pEDIDConfig->nBlock3MinVRate = ui->m_pDTimingMinVRateLE->text().toInt();
                m_pEDIDConfig->nBlock3MaxVRate = ui->m_pDTimingMaxVRateLE->text().toInt();
                m_pEDIDConfig->nBlock3MinHRate = ui->m_pDTimingMinHRateLE->text().toInt();
                m_pEDIDConfig->nBlock3MaxHRate = ui->m_pDTimingMaxHRateLE->text().toInt();
                m_pEDIDConfig->nBlock3MaxPxlClk = ui->m_pDTimingMaxPxlClkLE->text().toInt();
                m_pEDIDConfig->nBlock3SecondaryTiming = ui->m_pDTimingSecondaryTimingCB->isChecked() ? 1 : 0;
                m_pEDIDConfig->nBlock3Start = ui->m_pDTimingStartLE->text().toInt();
                m_pEDIDConfig->nBlock3K = ui->m_pDTimingKLE->text().toInt();
                m_pEDIDConfig->nBlock3C = ui->m_pDTimingCLE->text().toInt();
                m_pEDIDConfig->nBlock3T = ui->m_pDTimingTLE->text().toInt();
                m_pEDIDConfig->nBlock3M = ui->m_pDTimingMLE->text().toInt();
                break;
            case 3:
                strcpy(m_pEDIDConfig->cBlock3MonitorName, BCCommon::getTextStr(ui->m_pDTimingMax13LE->text()));
                break;
            case 4:
                m_pEDIDConfig->nBlock3UsePointData1 = ui->m_pDTimingUsePointData1CB->isChecked() ? 1 : 0;
                m_pEDIDConfig->nBlock3WhitePoint1 = ui->m_pDTimingWhitePoint1LE->text().toInt();
                m_pEDIDConfig->nBlock3WhiteX1 = ui->m_pDTimingWhiteX1LE->text().toInt();
                m_pEDIDConfig->nBlock3WhiteY1 = ui->m_pDTimingWhiteY1LE->text().toInt();
                m_pEDIDConfig->nBlock3Gamma1 = ui->m_pDTimingGamma1LE->text().toInt();

                m_pEDIDConfig->nBlock3UsePointData2 = ui->m_pDTimingUsePointData2CB->isChecked() ? 1 : 0;
                m_pEDIDConfig->nBlock3WhitePoint2 = ui->m_pDTimingWhitePoint2LE->text().toInt();
                m_pEDIDConfig->nBlock3WhiteX2 = ui->m_pDTimingWhiteX2LE->text().toInt();
                m_pEDIDConfig->nBlock3WhiteY2 = ui->m_pDTimingWhiteY2LE->text().toInt();
                m_pEDIDConfig->nBlock3Gamma2 = ui->m_pDTimingGamma2LE->text().toInt();
                break;
            case 5:
                // 1-2
                if ( ui->m_pDTimingIDView1RB->isChecked() ) {
                    m_pEDIDConfig->nBlock3TimingID1Active = ui->m_pDTimingIDAction1LE->text().toInt();
                    m_pEDIDConfig->nBlock3TimingID1Refresh = ui->m_pDTimingIDRefresh1LE->text().toInt();
                    m_pEDIDConfig->nBlock3TimingID1AspectIndex = ui->m_pDTimingIDAspect11RB->isChecked() ?
                                0 : ui->m_pDTimingIDAspect12RB->isChecked() ?
                                    1 : ui->m_pDTimingIDAspect13RB->isChecked() ? 2 : 3;

                    m_pEDIDConfig->nBlock3TimingID2Active = ui->m_pDTimingIDAction2LE->text().toInt();
                    m_pEDIDConfig->nBlock3TimingID2Refresh = ui->m_pDTimingIDRefresh2LE->text().toInt();
                    m_pEDIDConfig->nBlock3TimingID2AspectIndex = ui->m_pDTimingIDAspect21RB->isChecked() ?
                                0 : ui->m_pDTimingIDAspect22RB->isChecked() ?
                                    1 : ui->m_pDTimingIDAspect23RB->isChecked() ? 2 : 3;
                }

                // 3-4
                if ( ui->m_pDTimingIDView2RB->isChecked() ) {
                    m_pEDIDConfig->nBlock3TimingID3Active = ui->m_pDTimingIDAction1LE->text().toInt();
                    m_pEDIDConfig->nBlock3TimingID3Refresh = ui->m_pDTimingIDRefresh1LE->text().toInt();
                    m_pEDIDConfig->nBlock3TimingID3AspectIndex = ui->m_pDTimingIDAspect11RB->isChecked() ?
                                0 : ui->m_pDTimingIDAspect12RB->isChecked() ?
                                    1 : ui->m_pDTimingIDAspect13RB->isChecked() ? 2 : 3;

                    m_pEDIDConfig->nBlock3TimingID4Active = ui->m_pDTimingIDAction2LE->text().toInt();
                    m_pEDIDConfig->nBlock3TimingID4Refresh = ui->m_pDTimingIDRefresh2LE->text().toInt();
                    m_pEDIDConfig->nBlock3TimingID4AspectIndex = ui->m_pDTimingIDAspect21RB->isChecked() ?
                                0 : ui->m_pDTimingIDAspect22RB->isChecked() ?
                                    1 : ui->m_pDTimingIDAspect23RB->isChecked() ? 2 : 3;

                }

                // 5-6
                if ( ui->m_pDTimingIDView3RB->isChecked() ) {
                    m_pEDIDConfig->nBlock3TimingID5Active = ui->m_pDTimingIDAction1LE->text().toInt();
                    m_pEDIDConfig->nBlock3TimingID5Refresh = ui->m_pDTimingIDRefresh1LE->text().toInt();
                    m_pEDIDConfig->nBlock3TimingID5AspectIndex = ui->m_pDTimingIDAspect11RB->isChecked() ?
                                0 : ui->m_pDTimingIDAspect12RB->isChecked() ?
                                    1 : ui->m_pDTimingIDAspect13RB->isChecked() ? 2 : 3;

                    m_pEDIDConfig->nBlock3TimingID6Active = ui->m_pDTimingIDAction2LE->text().toInt();
                    m_pEDIDConfig->nBlock3TimingID6Refresh = ui->m_pDTimingIDRefresh2LE->text().toInt();
                    m_pEDIDConfig->nBlock3TimingID6AspectIndex = ui->m_pDTimingIDAspect21RB->isChecked() ?
                                0 : ui->m_pDTimingIDAspect22RB->isChecked() ?
                                    1 : ui->m_pDTimingIDAspect23RB->isChecked() ? 2 : 3;

                }

                break;
            case 6:
                break;
            default:
                strcpy(m_pEDIDConfig->cBlock3MfgDefined, BCCommon::getTextStr(ui->m_pDTimingMax13LE->text()));
                break;
            }
        }
    }

    if (ui->m_pDTimingBlockParasGB->title() == "Block #4") {
        if ( ui->m_pDTimingTimingRB->isChecked() ) {
            m_pEDIDConfig->nBlock4Pixel = ui->m_pDTimingPixelLE->text().toInt();
            m_pEDIDConfig->nBlock4HActive = ui->m_pDTimingHActiveLE->text().toInt();
            m_pEDIDConfig->nBlock4HBlank = ui->m_pDTimingHBlankLE->text().toInt();
            m_pEDIDConfig->nBlock4HSync1 = ui->m_pDTimingHSync1LE->text().toInt();
            m_pEDIDConfig->nBlock4HSync2 = ui->m_pDTimingHSync2LE->text().toInt();
            m_pEDIDConfig->nBlock4HImage = ui->m_pDTimingHImageLE->text().toInt();
            m_pEDIDConfig->nBlock4HBorder = ui->m_pDTimingHBorderLE->text().toInt();
            m_pEDIDConfig->nBlock4Interlaced = (int)ui->m_pDTimingInterlacedCB->isChecked();
            m_pEDIDConfig->nBlock4VActive = ui->m_pDTimingVActiveLE->text().toInt();
            m_pEDIDConfig->nBlock4VBlank = ui->m_pDTimingVBlankLE->text().toInt();
            m_pEDIDConfig->nBlock4VSync1 = ui->m_pDTimingVSync1LE->text().toInt();
            m_pEDIDConfig->nBlock4VSync2 = ui->m_pDTimingVSync2LE->text().toInt();
            m_pEDIDConfig->nBlock4VImage = ui->m_pDTimingVImageLE->text().toInt();
            m_pEDIDConfig->nBlock4VBorder = ui->m_pDTimingVBorderLE->text().toInt();
            m_pEDIDConfig->nBlock4StereoDisplayType = ui->m_pDTimingNormalyRB->isChecked() ?
                        0 : ui->m_pDTimingFSRRB->isChecked() ?
                            1 : ui->m_pDTimingFSLRB->isChecked() ?
                                2 : ui->m_pDTiming4WayRB->isChecked() ?
                                    3: ui->m_pDTiming2WayRRB->isChecked() ?
                                        4 : ui->m_pDTiming2WayLRB->isChecked() ? 5 : 6;
            m_pEDIDConfig->nBlock4SyncSchemeType = ui->m_pDTimingAnalogRB->isChecked() ?
                        0 : ui->m_pDTimingAnalogBipolarRB->isChecked() ?
                            1 : ui->m_pDTimingDigitalComposionRB->isChecked() ? 2 : 3;
            m_pEDIDConfig->nBlock4SyncSchemePara1 = (int)ui->m_pDTimingSyncSchemePara1CB->isChecked();
            m_pEDIDConfig->nBlock4SyncSchemePara2 = (int)ui->m_pDTimingSyncSchemePara2CB->isChecked();
        } else {
            m_pEDIDConfig->nBlock4DataTypeIndex = ui->m_pDTimingDataType1RB->isChecked() ?
                        0 : ui->m_pDTimingDataType2RB->isChecked() ?
                            1 : ui->m_pDTimingDataType3RB->isChecked() ?
                                2 : ui->m_pDTimingDataType4RB->isChecked() ?
                                    3 : ui->m_pDTimingDataType5RB->isChecked() ?
                                        4 : ui->m_pDTimingDataType6RB->isChecked() ?
                                            5 : ui->m_pDTimingDataType7RB->isChecked() ? 6 : 7;

            // 设置参数
            switch (m_pEDIDConfig->nBlock4DataTypeIndex) {
            case 0:
                strcpy(m_pEDIDConfig->cBlock4SerialNumber, BCCommon::getTextStr(ui->m_pDTimingMax13LE->text()));
                break;
            case 1:
                strcpy(m_pEDIDConfig->cBlock4ASCIIString, BCCommon::getTextStr(ui->m_pDTimingMax13LE->text()));
                break;
            case 2:
                m_pEDIDConfig->nBlock4MinVRate = ui->m_pDTimingMinVRateLE->text().toInt();
                m_pEDIDConfig->nBlock4MaxVRate = ui->m_pDTimingMaxVRateLE->text().toInt();
                m_pEDIDConfig->nBlock4MinHRate = ui->m_pDTimingMinHRateLE->text().toInt();
                m_pEDIDConfig->nBlock4MaxHRate = ui->m_pDTimingMaxHRateLE->text().toInt();
                m_pEDIDConfig->nBlock4MaxPxlClk = ui->m_pDTimingMaxPxlClkLE->text().toInt();
                m_pEDIDConfig->nBlock4SecondaryTiming = ui->m_pDTimingSecondaryTimingCB->isChecked() ? 1 : 0;
                m_pEDIDConfig->nBlock4Start = ui->m_pDTimingStartLE->text().toInt();
                m_pEDIDConfig->nBlock4K = ui->m_pDTimingKLE->text().toInt();
                m_pEDIDConfig->nBlock4C = ui->m_pDTimingCLE->text().toInt();
                m_pEDIDConfig->nBlock4T = ui->m_pDTimingTLE->text().toInt();
                m_pEDIDConfig->nBlock4M = ui->m_pDTimingMLE->text().toInt();
                break;
            case 3:
                strcpy(m_pEDIDConfig->cBlock4MonitorName, BCCommon::getTextStr(ui->m_pDTimingMax13LE->text()));
                break;
            case 4:
                m_pEDIDConfig->nBlock4UsePointData1 = ui->m_pDTimingUsePointData1CB->isChecked() ? 1 : 0;
                m_pEDIDConfig->nBlock4WhitePoint1 = ui->m_pDTimingWhitePoint1LE->text().toInt();
                m_pEDIDConfig->nBlock4WhiteX1 = ui->m_pDTimingWhiteX1LE->text().toInt();
                m_pEDIDConfig->nBlock4WhiteY1 = ui->m_pDTimingWhiteY1LE->text().toInt();
                m_pEDIDConfig->nBlock4Gamma1 = ui->m_pDTimingGamma1LE->text().toInt();

                m_pEDIDConfig->nBlock4UsePointData2 = ui->m_pDTimingUsePointData2CB->isChecked() ? 1 : 0;
                m_pEDIDConfig->nBlock4WhitePoint2 = ui->m_pDTimingWhitePoint2LE->text().toInt();
                m_pEDIDConfig->nBlock4WhiteX2 = ui->m_pDTimingWhiteX2LE->text().toInt();
                m_pEDIDConfig->nBlock4WhiteY2 = ui->m_pDTimingWhiteY2LE->text().toInt();
                m_pEDIDConfig->nBlock4Gamma2 = ui->m_pDTimingGamma2LE->text().toInt();
                break;
            case 5:
                // 1-2
                if ( ui->m_pDTimingIDView1RB->isChecked() ) {
                    m_pEDIDConfig->nBlock4TimingID1Active = ui->m_pDTimingIDAction1LE->text().toInt();
                    m_pEDIDConfig->nBlock4TimingID1Refresh = ui->m_pDTimingIDRefresh1LE->text().toInt();
                    m_pEDIDConfig->nBlock4TimingID1AspectIndex = ui->m_pDTimingIDAspect11RB->isChecked() ?
                                0 : ui->m_pDTimingIDAspect12RB->isChecked() ?
                                    1 : ui->m_pDTimingIDAspect13RB->isChecked() ? 2 : 3;

                    m_pEDIDConfig->nBlock4TimingID2Active = ui->m_pDTimingIDAction2LE->text().toInt();
                    m_pEDIDConfig->nBlock4TimingID2Refresh = ui->m_pDTimingIDRefresh2LE->text().toInt();
                    m_pEDIDConfig->nBlock4TimingID2AspectIndex = ui->m_pDTimingIDAspect21RB->isChecked() ?
                                0 : ui->m_pDTimingIDAspect22RB->isChecked() ?
                                    1 : ui->m_pDTimingIDAspect23RB->isChecked() ? 2 : 3;
                }

                // 3-4
                if ( ui->m_pDTimingIDView2RB->isChecked() ) {
                    m_pEDIDConfig->nBlock4TimingID3Active = ui->m_pDTimingIDAction1LE->text().toInt();
                    m_pEDIDConfig->nBlock4TimingID3Refresh = ui->m_pDTimingIDRefresh1LE->text().toInt();
                    m_pEDIDConfig->nBlock4TimingID3AspectIndex = ui->m_pDTimingIDAspect11RB->isChecked() ?
                                0 : ui->m_pDTimingIDAspect12RB->isChecked() ?
                                    1 : ui->m_pDTimingIDAspect13RB->isChecked() ? 2 : 3;

                    m_pEDIDConfig->nBlock4TimingID4Active = ui->m_pDTimingIDAction2LE->text().toInt();
                    m_pEDIDConfig->nBlock4TimingID4Refresh = ui->m_pDTimingIDRefresh2LE->text().toInt();
                    m_pEDIDConfig->nBlock4TimingID4AspectIndex = ui->m_pDTimingIDAspect21RB->isChecked() ?
                                0 : ui->m_pDTimingIDAspect22RB->isChecked() ?
                                    1 : ui->m_pDTimingIDAspect23RB->isChecked() ? 2 : 3;

                }

                // 5-6
                if ( ui->m_pDTimingIDView3RB->isChecked() ) {
                    m_pEDIDConfig->nBlock4TimingID5Active = ui->m_pDTimingIDAction1LE->text().toInt();
                    m_pEDIDConfig->nBlock4TimingID5Refresh = ui->m_pDTimingIDRefresh1LE->text().toInt();
                    m_pEDIDConfig->nBlock4TimingID5AspectIndex = ui->m_pDTimingIDAspect11RB->isChecked() ?
                                0 : ui->m_pDTimingIDAspect12RB->isChecked() ?
                                    1 : ui->m_pDTimingIDAspect13RB->isChecked() ? 2 : 3;

                    m_pEDIDConfig->nBlock4TimingID6Active = ui->m_pDTimingIDAction2LE->text().toInt();
                    m_pEDIDConfig->nBlock4TimingID6Refresh = ui->m_pDTimingIDRefresh2LE->text().toInt();
                    m_pEDIDConfig->nBlock4TimingID6AspectIndex = ui->m_pDTimingIDAspect21RB->isChecked() ?
                                0 : ui->m_pDTimingIDAspect22RB->isChecked() ?
                                    1 : ui->m_pDTimingIDAspect23RB->isChecked() ? 2 : 3;

                }

                break;
            case 6:
                break;
            default:
                strcpy(m_pEDIDConfig->cBlock4MfgDefined, BCCommon::getTextStr(ui->m_pDTimingMax13LE->text()));
                break;
            }
        }
    }
}

void BCSettingEDIDDlg::on_m_pDTimingBlock1RB_clicked()
{
    // save data
    SaveDetailedTimingPreBlockPara();

    // 类型模块
    ui->m_pDTimingBlockParasGB->setTitle( QString("Block #1") );
    ui->m_pDTimingDescriptorGB->setEnabled( false );
    ui->m_pDTimingTimingRB->setChecked( true );

    // 参数模块
    ui->m_pDTimingDataTypeGB->hide();
    ui->m_pDTimingDataTypeParasGB->hide();
    ui->m_pDTimingTimingsGB->show();
    ui->m_pDTimingStereoDisplayGB->show();
    ui->m_pDTimingSyncSchemeGB->show();

    // timing paras
    SetDetailedTimingTimingPara(m_pEDIDConfig->nBlock1Pixel, m_pEDIDConfig->nBlock1HActive, m_pEDIDConfig->nBlock1HBlank,
                                m_pEDIDConfig->nBlock1HSync1, m_pEDIDConfig->nBlock1HSync2, m_pEDIDConfig->nBlock1HImage, m_pEDIDConfig->nBlock1HBorder,
                                m_pEDIDConfig->nBlock1Interlaced, m_pEDIDConfig->nBlock1VActive, m_pEDIDConfig->nBlock1VBlank,
                                m_pEDIDConfig->nBlock1VSync1, m_pEDIDConfig->nBlock1VSync2, m_pEDIDConfig->nBlock1VImage, m_pEDIDConfig->nBlock1VBorder,
                                m_pEDIDConfig->nBlock1StereoDisplayType, m_pEDIDConfig->nBlock1SyncSchemeType,
                                m_pEDIDConfig->nBlock1SyncSchemePara1, m_pEDIDConfig->nBlock1SyncSchemePara2);
}

void BCSettingEDIDDlg::on_m_pDTimingBlock2RB_clicked()
{
    // save data
    SaveDetailedTimingPreBlockPara();

    ui->m_pDTimingBlockParasGB->setTitle( QString("Block #2") );
    ui->m_pDTimingDescriptorGB->setEnabled( true );

    if ( m_pEDIDConfig->nBlock2Type ) {
        ui->m_pDTimingTimingRB->setChecked( true );

        // 参数模块
        ui->m_pDTimingDataTypeGB->hide();
        ui->m_pDTimingDataTypeParasGB->hide();
        ui->m_pDTimingTimingsGB->show();
        ui->m_pDTimingStereoDisplayGB->show();
        ui->m_pDTimingSyncSchemeGB->show();

        // timing paras
        SetDetailedTimingTimingPara(m_pEDIDConfig->nBlock2Pixel, m_pEDIDConfig->nBlock2HActive, m_pEDIDConfig->nBlock2HBlank,
                                    m_pEDIDConfig->nBlock2HSync1, m_pEDIDConfig->nBlock2HSync2, m_pEDIDConfig->nBlock2HImage, m_pEDIDConfig->nBlock2HBorder,
                                    m_pEDIDConfig->nBlock2Interlaced, m_pEDIDConfig->nBlock2VActive, m_pEDIDConfig->nBlock2VBlank,
                                    m_pEDIDConfig->nBlock2VSync1, m_pEDIDConfig->nBlock2VSync2, m_pEDIDConfig->nBlock2VImage, m_pEDIDConfig->nBlock2VBorder,
                                    m_pEDIDConfig->nBlock2StereoDisplayType, m_pEDIDConfig->nBlock2SyncSchemeType,
                                    m_pEDIDConfig->nBlock2SyncSchemePara1, m_pEDIDConfig->nBlock2SyncSchemePara2);
    } else {
        ui->m_pDTimingMonitorRB->setChecked( true );

        // 参数模块
        ui->m_pDTimingDataTypeGB->show();
        ui->m_pDTimingDataTypeParasGB->show();

        ui->m_pDTimingTimingsGB->hide();
        ui->m_pDTimingStereoDisplayGB->hide();
        ui->m_pDTimingSyncSchemeGB->hide();

        // monitor paras
        // 设置隐藏项
        SetDetailedTimingDataTypeVisible( m_pEDIDConfig->nBlock2DataTypeIndex );

        // 设置参数
        switch (m_pEDIDConfig->nBlock2DataTypeIndex) {
        case 0:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock2SerialNumber );
            break;
        case 1:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock2ASCIIString );
            break;
        case 2:
            SetDetailedTimingDataTypePara2(m_pEDIDConfig->nBlock2MinVRate, m_pEDIDConfig->nBlock2MaxVRate,
                                           m_pEDIDConfig->nBlock2MinHRate, m_pEDIDConfig->nBlock2MaxHRate,
                                           m_pEDIDConfig->nBlock2MaxPxlClk, m_pEDIDConfig->nBlock2SecondaryTiming,
                                           m_pEDIDConfig->nBlock2Start, m_pEDIDConfig->nBlock2K, m_pEDIDConfig->nBlock2C, m_pEDIDConfig->nBlock2T, m_pEDIDConfig->nBlock2M);
            break;
        case 3:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock2MonitorName );
            break;
        case 4:
            SetDetailedTimingDataTypePara4(m_pEDIDConfig->nBlock2UsePointData1, m_pEDIDConfig->nBlock2WhitePoint1,
                                           m_pEDIDConfig->nBlock2WhiteX1, m_pEDIDConfig->nBlock2WhiteY1, m_pEDIDConfig->nBlock2Gamma1,
                                           m_pEDIDConfig->nBlock2UsePointData2, m_pEDIDConfig->nBlock2WhitePoint2,
                                           m_pEDIDConfig->nBlock2WhiteX2, m_pEDIDConfig->nBlock2WhiteY2, m_pEDIDConfig->nBlock2Gamma2);
            break;
        case 5:
            SetDetailedTimingDataTypePara5(m_pEDIDConfig->nBlock2TimingID1Active, m_pEDIDConfig->nBlock2TimingID1Refresh, m_pEDIDConfig->nBlock2TimingID1AspectIndex,
                                           m_pEDIDConfig->nBlock2TimingID2Active, m_pEDIDConfig->nBlock2TimingID2Refresh, m_pEDIDConfig->nBlock2TimingID2AspectIndex);
            break;
        case 6:
            break;
        default:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock2MfgDefined );
            break;
        }
    }
}

void BCSettingEDIDDlg::on_m_pDTimingBlock3RB_clicked()
{
    // save data
    SaveDetailedTimingPreBlockPara();

    ui->m_pDTimingBlockParasGB->setTitle( QString("Block #3") );
    ui->m_pDTimingDescriptorGB->setEnabled( true );

    if ( m_pEDIDConfig->nBlock3Type ) {
        ui->m_pDTimingTimingRB->setChecked( true );

        // 参数模块
        ui->m_pDTimingDataTypeGB->hide();
        ui->m_pDTimingDataTypeParasGB->hide();
        ui->m_pDTimingTimingsGB->show();
        ui->m_pDTimingStereoDisplayGB->show();
        ui->m_pDTimingSyncSchemeGB->show();

        // timing paras
        SetDetailedTimingTimingPara(m_pEDIDConfig->nBlock3Pixel, m_pEDIDConfig->nBlock3HActive, m_pEDIDConfig->nBlock3HBlank,
                                    m_pEDIDConfig->nBlock3HSync1, m_pEDIDConfig->nBlock3HSync2, m_pEDIDConfig->nBlock3HImage, m_pEDIDConfig->nBlock3HBorder,
                                    m_pEDIDConfig->nBlock3Interlaced, m_pEDIDConfig->nBlock3VActive, m_pEDIDConfig->nBlock3VBlank,
                                    m_pEDIDConfig->nBlock3VSync1, m_pEDIDConfig->nBlock3VSync2, m_pEDIDConfig->nBlock3VImage, m_pEDIDConfig->nBlock3VBorder,
                                    m_pEDIDConfig->nBlock3StereoDisplayType, m_pEDIDConfig->nBlock3SyncSchemeType,
                                    m_pEDIDConfig->nBlock3SyncSchemePara1, m_pEDIDConfig->nBlock3SyncSchemePara2);
    } else {
        ui->m_pDTimingMonitorRB->setChecked( true );

        // 参数模块
        ui->m_pDTimingDataTypeGB->show();
        ui->m_pDTimingDataTypeParasGB->show();

        ui->m_pDTimingTimingsGB->hide();
        ui->m_pDTimingStereoDisplayGB->hide();
        ui->m_pDTimingSyncSchemeGB->hide();

        // monitor paras
        // 设置隐藏项
        SetDetailedTimingDataTypeVisible( m_pEDIDConfig->nBlock3DataTypeIndex );

        // 设置参数
        switch (m_pEDIDConfig->nBlock3DataTypeIndex) {
        case 0:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock3SerialNumber );
            break;
        case 1:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock3ASCIIString );
            break;
        case 2:
            SetDetailedTimingDataTypePara2(m_pEDIDConfig->nBlock3MinVRate, m_pEDIDConfig->nBlock3MaxVRate,
                                           m_pEDIDConfig->nBlock3MinHRate, m_pEDIDConfig->nBlock3MaxHRate,
                                           m_pEDIDConfig->nBlock3MaxPxlClk, m_pEDIDConfig->nBlock3SecondaryTiming,
                                           m_pEDIDConfig->nBlock3Start, m_pEDIDConfig->nBlock3K, m_pEDIDConfig->nBlock3C, m_pEDIDConfig->nBlock3T, m_pEDIDConfig->nBlock3M);
            break;
        case 3:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock3MonitorName );
            break;
        case 4:
            SetDetailedTimingDataTypePara4(m_pEDIDConfig->nBlock3UsePointData1, m_pEDIDConfig->nBlock3WhitePoint1,
                                           m_pEDIDConfig->nBlock3WhiteX1, m_pEDIDConfig->nBlock3WhiteY1, m_pEDIDConfig->nBlock3Gamma1,
                                           m_pEDIDConfig->nBlock3UsePointData2, m_pEDIDConfig->nBlock3WhitePoint2,
                                           m_pEDIDConfig->nBlock3WhiteX2, m_pEDIDConfig->nBlock3WhiteY2, m_pEDIDConfig->nBlock3Gamma2);
            break;
        case 5:
            SetDetailedTimingDataTypePara5(m_pEDIDConfig->nBlock3TimingID1Active, m_pEDIDConfig->nBlock3TimingID1Refresh, m_pEDIDConfig->nBlock3TimingID1AspectIndex,
                                           m_pEDIDConfig->nBlock3TimingID2Active, m_pEDIDConfig->nBlock3TimingID2Refresh, m_pEDIDConfig->nBlock3TimingID2AspectIndex);
            break;
        case 6:
            break;
        default:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock3MfgDefined );
            break;
        }
    }
}

void BCSettingEDIDDlg::on_m_pDTimingBlock4RB_clicked()
{
    // save data
    SaveDetailedTimingPreBlockPara();

    ui->m_pDTimingBlockParasGB->setTitle( QString("Block #4") );
    ui->m_pDTimingDescriptorGB->setEnabled( true );

    if ( m_pEDIDConfig->nBlock4Type ) {
        ui->m_pDTimingTimingRB->setChecked( true );

        // 参数模块
        ui->m_pDTimingDataTypeGB->hide();
        ui->m_pDTimingDataTypeParasGB->hide();
        ui->m_pDTimingTimingsGB->show();
        ui->m_pDTimingStereoDisplayGB->show();
        ui->m_pDTimingSyncSchemeGB->show();

        // timing paras
        SetDetailedTimingTimingPara(m_pEDIDConfig->nBlock4Pixel, m_pEDIDConfig->nBlock4HActive, m_pEDIDConfig->nBlock4HBlank,
                                    m_pEDIDConfig->nBlock4HSync1, m_pEDIDConfig->nBlock4HSync2, m_pEDIDConfig->nBlock4HImage, m_pEDIDConfig->nBlock4HBorder,
                                    m_pEDIDConfig->nBlock4Interlaced, m_pEDIDConfig->nBlock4VActive, m_pEDIDConfig->nBlock4VBlank,
                                    m_pEDIDConfig->nBlock4VSync1, m_pEDIDConfig->nBlock4VSync2, m_pEDIDConfig->nBlock4VImage, m_pEDIDConfig->nBlock4VBorder,
                                    m_pEDIDConfig->nBlock4StereoDisplayType, m_pEDIDConfig->nBlock4SyncSchemeType,
                                    m_pEDIDConfig->nBlock4SyncSchemePara1, m_pEDIDConfig->nBlock4SyncSchemePara2);
    } else {
        ui->m_pDTimingMonitorRB->setChecked( true );

        // 参数模块
        ui->m_pDTimingDataTypeGB->show();
        ui->m_pDTimingDataTypeParasGB->show();

        ui->m_pDTimingTimingsGB->hide();
        ui->m_pDTimingStereoDisplayGB->hide();
        ui->m_pDTimingSyncSchemeGB->hide();

        // monitor paras
        // 设置隐藏项
        SetDetailedTimingDataTypeVisible( m_pEDIDConfig->nBlock4DataTypeIndex );

        // 设置参数
        switch (m_pEDIDConfig->nBlock4DataTypeIndex) {
        case 0:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock4SerialNumber );
            break;
        case 1:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock4ASCIIString );
            break;
        case 2:
            SetDetailedTimingDataTypePara2(m_pEDIDConfig->nBlock4MinVRate, m_pEDIDConfig->nBlock4MaxVRate,
                                           m_pEDIDConfig->nBlock4MinHRate, m_pEDIDConfig->nBlock4MaxHRate,
                                           m_pEDIDConfig->nBlock4MaxPxlClk, m_pEDIDConfig->nBlock4SecondaryTiming,
                                           m_pEDIDConfig->nBlock4Start, m_pEDIDConfig->nBlock4K, m_pEDIDConfig->nBlock4C, m_pEDIDConfig->nBlock4T, m_pEDIDConfig->nBlock4M);
            break;
        case 3:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock4MonitorName );
            break;
        case 4:
            SetDetailedTimingDataTypePara4(m_pEDIDConfig->nBlock4UsePointData1, m_pEDIDConfig->nBlock4WhitePoint1,
                                           m_pEDIDConfig->nBlock4WhiteX1, m_pEDIDConfig->nBlock4WhiteY1, m_pEDIDConfig->nBlock4Gamma1,
                                           m_pEDIDConfig->nBlock4UsePointData2, m_pEDIDConfig->nBlock4WhitePoint2,
                                           m_pEDIDConfig->nBlock4WhiteX2, m_pEDIDConfig->nBlock4WhiteY2, m_pEDIDConfig->nBlock4Gamma2);
            break;
        case 5:
            SetDetailedTimingDataTypePara5(m_pEDIDConfig->nBlock4TimingID1Active, m_pEDIDConfig->nBlock4TimingID1Refresh, m_pEDIDConfig->nBlock4TimingID1AspectIndex,
                                           m_pEDIDConfig->nBlock4TimingID2Active, m_pEDIDConfig->nBlock4TimingID2Refresh, m_pEDIDConfig->nBlock4TimingID2AspectIndex);
            break;
        case 6:
            break;
        default:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock4MfgDefined );
            break;
        }
    }
}

// --------------------------------------------------------------------------------------------------------------------------------
//  detailed timings设置Datatype参数时，因为的多个widget，所以需要根据情况进行隐藏和显示
void BCSettingEDIDDlg::SetDetailedTimingDataTypeVisible(int index)
{
    switch ( index ) {
    case 0:
        ui->m_pDTimingDataType1RB->setChecked( true );

        ui->m_pDTimingDataTypeParasGB->setTitle( QString("Monitor Serial Number") );
        ui->m_pDTimingDataTypeParasWidget1->show();
        ui->m_pDTimingDataTypeParasWidget2->hide();
        ui->m_pDTimingDataTypeParasWidget3->hide();
        ui->m_pDTimingDataTypeParasWidget4->hide();
        break;
    case 1:
        ui->m_pDTimingDataType2RB->setChecked( true );

        ui->m_pDTimingDataTypeParasGB->setTitle( QString("ASCII String") );
        ui->m_pDTimingDataTypeParasWidget1->show();
        ui->m_pDTimingDataTypeParasWidget2->hide();
        ui->m_pDTimingDataTypeParasWidget3->hide();
        ui->m_pDTimingDataTypeParasWidget4->hide();
        break;
    case 2:
        ui->m_pDTimingDataType3RB->setChecked( true );

        ui->m_pDTimingDataTypeParasWidget1->hide();
        ui->m_pDTimingDataTypeParasWidget2->show();
        ui->m_pDTimingDataTypeParasWidget3->hide();
        ui->m_pDTimingDataTypeParasWidget4->hide();
        break;
    case 3:
        ui->m_pDTimingDataType4RB->setChecked( true );

        ui->m_pDTimingDataTypeParasGB->setTitle( QString("Monitor Name") );
        ui->m_pDTimingDataTypeParasWidget1->show();
        ui->m_pDTimingDataTypeParasWidget2->hide();
        ui->m_pDTimingDataTypeParasWidget3->hide();
        ui->m_pDTimingDataTypeParasWidget4->hide();
        break;
    case 4:
        ui->m_pDTimingDataType5RB->setChecked( true );

        ui->m_pDTimingDataTypeParasWidget1->hide();
        ui->m_pDTimingDataTypeParasWidget2->hide();
        ui->m_pDTimingDataTypeParasWidget3->show();
        ui->m_pDTimingDataTypeParasWidget4->hide();
        break;
    case 5:
        ui->m_pDTimingDataType6RB->setChecked( true );

        ui->m_pDTimingDataTypeParasWidget1->hide();
        ui->m_pDTimingDataTypeParasWidget2->hide();
        ui->m_pDTimingDataTypeParasWidget3->hide();
        ui->m_pDTimingDataTypeParasWidget4->show();
        break;
    case 6:
        ui->m_pDTimingDataType7RB->setChecked( true );

        ui->m_pDTimingDataTypeParasWidget1->hide();
        ui->m_pDTimingDataTypeParasWidget2->hide();
        ui->m_pDTimingDataTypeParasWidget3->hide();
        ui->m_pDTimingDataTypeParasWidget4->hide();
        break;
    default:
        ui->m_pDTimingDataType8RB->setChecked( true );

        ui->m_pDTimingDataTypeParasGB->setTitle( QString("Mfg. Defined") );
        ui->m_pDTimingDataTypeParasWidget1->show();
        ui->m_pDTimingDataTypeParasWidget2->hide();
        ui->m_pDTimingDataTypeParasWidget3->hide();
        ui->m_pDTimingDataTypeParasWidget4->hide();
        break;
    }
}

// detailed timing设置datatype参数时其中一项
void BCSettingEDIDDlg::SetDetailedTimingDataTypePara0(char *para)
{
    ui->m_pDTimingMax13LE->setText( QString(para) );
}

// detailed timing设置datatype参数时其中一项
void BCSettingEDIDDlg::SetDetailedTimingDataTypePara2(int minVRate, int maxVRate, int minHRate, int maxHRate,
                                    int maxPxl, int secondary, int start, int k, int c, int t, int m)
{
    ui->m_pDTimingMinVRateLE->setText( QString::number(minVRate) );
    ui->m_pDTimingMaxVRateLE->setText( QString::number(maxVRate) );
    ui->m_pDTimingMinHRateLE->setText( QString::number(minHRate) );
    ui->m_pDTimingMaxHRateLE->setText( QString::number(maxHRate) );
    ui->m_pDTimingMaxPxlClkLE->setText( QString::number(maxPxl) );
    ui->m_pDTimingSecondaryTimingCB->setChecked( secondary ? true : false );
    ui->m_pDTimingStartLE->setText( QString::number(start) );
    ui->m_pDTimingKLE->setText( QString::number(k) );
    ui->m_pDTimingCLE->setText( QString::number(c) );
    ui->m_pDTimingTLE->setText( QString::number(t) );
    ui->m_pDTimingMLE->setText( QString::number(m) );
}

// detailed timing设置datatype参数时其中一项
void BCSettingEDIDDlg::SetDetailedTimingDataTypePara4(int usePointData1, int whitePoint1, int whiteX1, int whiteY1, int gamma1,
                                    int usePointData2, int whitePoint2, int whiteX2, int whiteY2, int gamma2)
{
    ui->m_pDTimingUsePointData1CB->setChecked( usePointData1 ? true : false );
    ui->m_pDTimingWhitePoint1LE->setEnabled( usePointData1 ? true : false );
    ui->m_pDTimingWhiteX1LE->setEnabled( usePointData1 ? true : false );
    ui->m_pDTimingWhiteY1LE->setEnabled( usePointData1 ? true : false );
    ui->m_pDTimingGamma1LE->setEnabled( usePointData1 ? true : false );
    ui->m_pDTimingWhitePoint1LE->setText( QString::number(whitePoint1) );
    ui->m_pDTimingWhiteX1LE->setText( QString::number(whiteX1) );
    ui->m_pDTimingWhiteY1LE->setText( QString::number(whiteY1) );
    ui->m_pDTimingGamma1LE->setText( QString::number(gamma1) );

    ui->m_pDTimingUsePointData2CB->setChecked( usePointData2 ? true : false );
    ui->m_pDTimingWhitePoint2LE->setEnabled( usePointData2 ? true : false );
    ui->m_pDTimingWhiteX2LE->setEnabled( usePointData2 ? true : false );
    ui->m_pDTimingWhiteY2LE->setEnabled( usePointData2 ? true : false );
    ui->m_pDTimingGamma2LE->setEnabled( usePointData2 ? true : false );
    ui->m_pDTimingWhitePoint2LE->setText( QString::number(whitePoint2) );
    ui->m_pDTimingWhiteX2LE->setText( QString::number(whiteX2) );
    ui->m_pDTimingWhiteY2LE->setText( QString::number(whiteY2) );
    ui->m_pDTimingGamma2LE->setText( QString::number(gamma2) );
}

// detailed timing设置datatype参数时其中一项
void BCSettingEDIDDlg::SetDetailedTimingDataTypePara5(int active1, int refresh1, int aspectIndex1,
                                    int active2, int refresh2, int aspectIndex2, int index)
{
    // 如果是初始化需要设置check状态
    if ((1 == index) && (!ui->m_pDTimingIDView1RB->isChecked()))
        ui->m_pDTimingIDView1RB->setChecked( true );
    if ((3 == index) && (!ui->m_pDTimingIDView2RB->isChecked()))
        ui->m_pDTimingIDView2RB->setChecked( true );
    if ((5 == index) && (!ui->m_pDTimingIDView3RB->isChecked()))
        ui->m_pDTimingIDView3RB->setChecked( true );

    ui->m_pDTimingID1GB->setTitle(QString("Timing ID #%1").arg(index));
    ui->m_pDTimingIDAction1LE->setText( QString::number(active1) );
    ui->m_pDTimingIDRefresh1LE->setText( QString::number(refresh1) );
    switch ( aspectIndex1 ) {
    case 0:
        ui->m_pDTimingIDAspect11RB->setChecked( true );
        break;
    case 1:
        ui->m_pDTimingIDAspect12RB->setChecked( true );
        break;
    case 2:
        ui->m_pDTimingIDAspect13RB->setChecked( true );
        break;
    default:
        ui->m_pDTimingIDAspect14RB->setChecked( true );
        break;
    }

    ui->m_pDTimingID1GB->setTitle(QString("Timing ID #%1").arg(index+1));
    ui->m_pDTimingIDAction2LE->setText( QString::number(active2) );
    ui->m_pDTimingIDRefresh2LE->setText( QString::number(refresh2) );
    switch ( aspectIndex2 ) {
    case 0:
        ui->m_pDTimingIDAspect21RB->setChecked( true );
        break;
    case 1:
        ui->m_pDTimingIDAspect22RB->setChecked( true );
        break;
    case 2:
        ui->m_pDTimingIDAspect23RB->setChecked( true );
        break;
    default:
        ui->m_pDTimingIDAspect24RB->setChecked( true );
        break;
    }
}

// detailed timing设置timing参数
void BCSettingEDIDDlg::SetDetailedTimingTimingPara(int pixel, int hActive, int hBlank, int hSync1, int hSync2, int hImage, int hBorder,
                                 int interlaced, int vActive, int vBlank, int vSync1, int vSync2, int vImage, int vBorder,
                                 int stereoType, int syncType, int syncPara1, int syncPara2)
{
    ui->m_pDTimingPixelLE->setText( QString::number(pixel) );
    ui->m_pDTimingHActiveLE->setText( QString::number(hActive) );
    ui->m_pDTimingHBlankLE->setText( QString::number(hBlank) );
    ui->m_pDTimingHSync1LE->setText( QString::number(hSync1) );
    ui->m_pDTimingHSync2LE->setText( QString::number(hSync2) );
    ui->m_pDTimingHImageLE->setText( QString::number(hImage) );
    ui->m_pDTimingHBorderLE->setText( QString::number(hBorder) );
    ui->m_pDTimingInterlacedCB->setChecked( interlaced ? true : false );
    ui->m_pDTimingVActiveLE->setText( QString::number(vActive) );
    ui->m_pDTimingVBlankLE->setText( QString::number(vBlank) );
    ui->m_pDTimingVSync1LE->setText( QString::number(vSync1) );
    ui->m_pDTimingVSync2LE->setText( QString::number(vSync2) );
    ui->m_pDTimingVImageLE->setText( QString::number(vImage) );
    ui->m_pDTimingVBorderLE->setText( QString::number(vBorder) );
    switch ( stereoType ) {
    case 0:
        ui->m_pDTimingNormalyRB->setChecked( true );
        break;
    case 1:
        ui->m_pDTimingFSRRB->setChecked( true );
        break;
    case 2:
        ui->m_pDTimingFSLRB->setChecked( true );
        break;
    case 3:
        ui->m_pDTiming4WayRB->setChecked( true );
        break;
    case 4:
        ui->m_pDTiming2WayRRB->setChecked( true );
        break;
    case 5:
        ui->m_pDTiming2WayLRB->setChecked( true );
        break;
    default:
        ui->m_pDTimingSideBySideRB->setChecked( true );
        break;
    }

    switch ( syncType ) {
    case 0:
        ui->m_pDTimingAnalogRB->setChecked( true );
        ui->m_pDTimingSyncSchemePara1CB->setText(QString("Serrate"));
        ui->m_pDTimingSyncSchemePara2CB->setText(QString("On RGB"));
        break;
    case 1:
        ui->m_pDTimingAnalogBipolarRB->setChecked( true );
        ui->m_pDTimingSyncSchemePara1CB->setText(QString("Serrate"));
        ui->m_pDTimingSyncSchemePara2CB->setText(QString("On RGB"));
        break;
    case 2:
        ui->m_pDTimingDigitalComposionRB->setChecked( true );
        ui->m_pDTimingSyncSchemePara1CB->setText(QString("Serrate"));
        ui->m_pDTimingSyncSchemePara2CB->setText(QString("Polarity (+)"));
        break;
    default:
        ui->m_pDTimingDigitalSeparaRB->setChecked( true );
        ui->m_pDTimingSyncSchemePara1CB->setText(QString("V Polarity (+)"));
        ui->m_pDTimingSyncSchemePara2CB->setText(QString("H Polarity (+)"));
        break;
    }

    ui->m_pDTimingSyncSchemePara1CB->setChecked( syncPara1 ? true : false );
    ui->m_pDTimingSyncSchemePara2CB->setChecked( syncPara2 ? true : false );
}
// --------------------------------------------------------------------------------------------------------------------------------


void BCSettingEDIDDlg::on_m_pDTimingTimingRB_clicked()
{
    // 参数模块
    ui->m_pDTimingDataTypeGB->hide();
    ui->m_pDTimingDataTypeParasGB->hide();
    ui->m_pDTimingTimingsGB->show();
    ui->m_pDTimingStereoDisplayGB->show();
    ui->m_pDTimingSyncSchemeGB->show();

    // timing paras
    if ( ui->m_pDTimingBlock2RB->isChecked() )
        SetDetailedTimingTimingPara(m_pEDIDConfig->nBlock2Pixel, m_pEDIDConfig->nBlock2HActive, m_pEDIDConfig->nBlock2HBlank,
                                    m_pEDIDConfig->nBlock2HSync1, m_pEDIDConfig->nBlock2HSync2, m_pEDIDConfig->nBlock2HImage, m_pEDIDConfig->nBlock2HBorder,
                                    m_pEDIDConfig->nBlock2Interlaced, m_pEDIDConfig->nBlock2VActive, m_pEDIDConfig->nBlock2VBlank,
                                    m_pEDIDConfig->nBlock2VSync1, m_pEDIDConfig->nBlock2VSync2, m_pEDIDConfig->nBlock2VImage, m_pEDIDConfig->nBlock2VBorder,
                                    m_pEDIDConfig->nBlock2StereoDisplayType, m_pEDIDConfig->nBlock2SyncSchemeType,
                                    m_pEDIDConfig->nBlock2SyncSchemePara1, m_pEDIDConfig->nBlock2SyncSchemePara2);
    else if ( ui->m_pDTimingBlock3RB->isChecked() )
        SetDetailedTimingTimingPara(m_pEDIDConfig->nBlock3Pixel, m_pEDIDConfig->nBlock3HActive, m_pEDIDConfig->nBlock3HBlank,
                                    m_pEDIDConfig->nBlock3HSync1, m_pEDIDConfig->nBlock3HSync2, m_pEDIDConfig->nBlock3HImage, m_pEDIDConfig->nBlock3HBorder,
                                    m_pEDIDConfig->nBlock3Interlaced, m_pEDIDConfig->nBlock3VActive, m_pEDIDConfig->nBlock3VBlank,
                                    m_pEDIDConfig->nBlock3VSync1, m_pEDIDConfig->nBlock3VSync2, m_pEDIDConfig->nBlock3VImage, m_pEDIDConfig->nBlock3VBorder,
                                    m_pEDIDConfig->nBlock3StereoDisplayType, m_pEDIDConfig->nBlock3SyncSchemeType,
                                    m_pEDIDConfig->nBlock3SyncSchemePara1, m_pEDIDConfig->nBlock3SyncSchemePara2);
    else if ( ui->m_pDTimingBlock4RB->isChecked() )
        SetDetailedTimingTimingPara(m_pEDIDConfig->nBlock4Pixel, m_pEDIDConfig->nBlock4HActive, m_pEDIDConfig->nBlock4HBlank,
                                    m_pEDIDConfig->nBlock4HSync1, m_pEDIDConfig->nBlock4HSync2, m_pEDIDConfig->nBlock4HImage, m_pEDIDConfig->nBlock4HBorder,
                                    m_pEDIDConfig->nBlock4Interlaced, m_pEDIDConfig->nBlock4VActive, m_pEDIDConfig->nBlock4VBlank,
                                    m_pEDIDConfig->nBlock4VSync1, m_pEDIDConfig->nBlock4VSync2, m_pEDIDConfig->nBlock4VImage, m_pEDIDConfig->nBlock4VBorder,
                                    m_pEDIDConfig->nBlock4StereoDisplayType, m_pEDIDConfig->nBlock4SyncSchemeType,
                                    m_pEDIDConfig->nBlock4SyncSchemePara1, m_pEDIDConfig->nBlock4SyncSchemePara2);
}

void BCSettingEDIDDlg::on_m_pDTimingMonitorRB_clicked()
{
    // 参数模块
    ui->m_pDTimingDataTypeGB->show();
    ui->m_pDTimingDataTypeParasGB->show();

    ui->m_pDTimingTimingsGB->hide();
    ui->m_pDTimingStereoDisplayGB->hide();
    ui->m_pDTimingSyncSchemeGB->hide();

    // 设置隐藏项,设置参数
    if ( ui->m_pDTimingBlock2RB->isChecked() ) {
        SetDetailedTimingDataTypeVisible( m_pEDIDConfig->nBlock2DataTypeIndex );
        switch (m_pEDIDConfig->nBlock2DataTypeIndex) {
        case 0:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock2SerialNumber );
            break;
        case 1:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock2ASCIIString );
            break;
        case 2:
            SetDetailedTimingDataTypePara2(m_pEDIDConfig->nBlock2MinVRate, m_pEDIDConfig->nBlock2MaxVRate,
                                           m_pEDIDConfig->nBlock2MinHRate, m_pEDIDConfig->nBlock2MaxHRate,
                                           m_pEDIDConfig->nBlock2MaxPxlClk, m_pEDIDConfig->nBlock2SecondaryTiming,
                                           m_pEDIDConfig->nBlock2Start, m_pEDIDConfig->nBlock2K, m_pEDIDConfig->nBlock2C, m_pEDIDConfig->nBlock2T, m_pEDIDConfig->nBlock2M);
            break;
        case 3:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock2MonitorName );
            break;
        case 4:
            SetDetailedTimingDataTypePara4(m_pEDIDConfig->nBlock2UsePointData1, m_pEDIDConfig->nBlock2WhitePoint1,
                                           m_pEDIDConfig->nBlock2WhiteX1, m_pEDIDConfig->nBlock2WhiteY1, m_pEDIDConfig->nBlock2Gamma1,
                                           m_pEDIDConfig->nBlock2UsePointData2, m_pEDIDConfig->nBlock2WhitePoint2,
                                           m_pEDIDConfig->nBlock2WhiteX2, m_pEDIDConfig->nBlock2WhiteY2, m_pEDIDConfig->nBlock2Gamma2);
            break;
        case 5:
            SetDetailedTimingDataTypePara5(m_pEDIDConfig->nBlock2TimingID1Active, m_pEDIDConfig->nBlock2TimingID1Refresh, m_pEDIDConfig->nBlock2TimingID1AspectIndex,
                                           m_pEDIDConfig->nBlock2TimingID2Active, m_pEDIDConfig->nBlock2TimingID2Refresh, m_pEDIDConfig->nBlock2TimingID2AspectIndex);
            break;
        case 6:
            break;
        default:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock2MfgDefined );
            break;
        }
    } else if ( ui->m_pDTimingBlock3RB->isChecked() ) {
        SetDetailedTimingDataTypeVisible( m_pEDIDConfig->nBlock3DataTypeIndex );
        switch (m_pEDIDConfig->nBlock3DataTypeIndex) {
        case 0:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock3SerialNumber );
            break;
        case 1:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock3ASCIIString );
            break;
        case 2:
            SetDetailedTimingDataTypePara2(m_pEDIDConfig->nBlock3MinVRate, m_pEDIDConfig->nBlock3MaxVRate,
                                           m_pEDIDConfig->nBlock3MinHRate, m_pEDIDConfig->nBlock3MaxHRate,
                                           m_pEDIDConfig->nBlock3MaxPxlClk, m_pEDIDConfig->nBlock3SecondaryTiming,
                                           m_pEDIDConfig->nBlock3Start, m_pEDIDConfig->nBlock3K, m_pEDIDConfig->nBlock3C, m_pEDIDConfig->nBlock3T, m_pEDIDConfig->nBlock3M);
            break;
        case 3:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock3MonitorName );
            break;
        case 4:
            SetDetailedTimingDataTypePara4(m_pEDIDConfig->nBlock3UsePointData1, m_pEDIDConfig->nBlock3WhitePoint1,
                                           m_pEDIDConfig->nBlock3WhiteX1, m_pEDIDConfig->nBlock3WhiteY1, m_pEDIDConfig->nBlock3Gamma1,
                                           m_pEDIDConfig->nBlock3UsePointData2, m_pEDIDConfig->nBlock3WhitePoint2,
                                           m_pEDIDConfig->nBlock3WhiteX2, m_pEDIDConfig->nBlock3WhiteY2, m_pEDIDConfig->nBlock3Gamma2);
            break;
        case 5:
            SetDetailedTimingDataTypePara5(m_pEDIDConfig->nBlock3TimingID1Active, m_pEDIDConfig->nBlock3TimingID1Refresh, m_pEDIDConfig->nBlock3TimingID1AspectIndex,
                                           m_pEDIDConfig->nBlock3TimingID2Active, m_pEDIDConfig->nBlock3TimingID2Refresh, m_pEDIDConfig->nBlock3TimingID2AspectIndex);
            break;
        case 6:
            break;
        default:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock3MfgDefined );
            break;
        }
    } else if ( ui->m_pDTimingBlock4RB->isChecked() ) {
        SetDetailedTimingDataTypeVisible( m_pEDIDConfig->nBlock4DataTypeIndex );
        switch (m_pEDIDConfig->nBlock4DataTypeIndex) {
        case 0:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock4SerialNumber );
            break;
        case 1:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock4ASCIIString );
            break;
        case 2:
            SetDetailedTimingDataTypePara2(m_pEDIDConfig->nBlock4MinVRate, m_pEDIDConfig->nBlock4MaxVRate,
                                           m_pEDIDConfig->nBlock4MinHRate, m_pEDIDConfig->nBlock4MaxHRate,
                                           m_pEDIDConfig->nBlock4MaxPxlClk, m_pEDIDConfig->nBlock4SecondaryTiming,
                                           m_pEDIDConfig->nBlock4Start, m_pEDIDConfig->nBlock4K, m_pEDIDConfig->nBlock4C, m_pEDIDConfig->nBlock4T, m_pEDIDConfig->nBlock4M);
            break;
        case 3:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock4MonitorName );
            break;
        case 4:
            SetDetailedTimingDataTypePara4(m_pEDIDConfig->nBlock4UsePointData1, m_pEDIDConfig->nBlock4WhitePoint1,
                                           m_pEDIDConfig->nBlock4WhiteX1, m_pEDIDConfig->nBlock4WhiteY1, m_pEDIDConfig->nBlock4Gamma1,
                                           m_pEDIDConfig->nBlock4UsePointData2, m_pEDIDConfig->nBlock4WhitePoint2,
                                           m_pEDIDConfig->nBlock4WhiteX2, m_pEDIDConfig->nBlock4WhiteY2, m_pEDIDConfig->nBlock4Gamma2);
            break;
        case 5:
            SetDetailedTimingDataTypePara5(m_pEDIDConfig->nBlock4TimingID1Active, m_pEDIDConfig->nBlock4TimingID1Refresh, m_pEDIDConfig->nBlock4TimingID1AspectIndex,
                                           m_pEDIDConfig->nBlock4TimingID2Active, m_pEDIDConfig->nBlock4TimingID2Refresh, m_pEDIDConfig->nBlock4TimingID2AspectIndex);
            break;
        case 6:
            break;
        default:
            SetDetailedTimingDataTypePara0( m_pEDIDConfig->cBlock4MfgDefined );
            break;
        }
    }
}

void BCSettingEDIDDlg::on_m_pDTimingDataType1RB_clicked()
{
    SetDetailedTimingDataTypeVisible( 0 );
}

void BCSettingEDIDDlg::on_m_pDTimingDataType2RB_clicked()
{
    SetDetailedTimingDataTypeVisible( 1 );
}

void BCSettingEDIDDlg::on_m_pDTimingDataType3RB_clicked()
{
    SetDetailedTimingDataTypeVisible( 2 );
}

void BCSettingEDIDDlg::on_m_pDTimingDataType4RB_clicked()
{
    SetDetailedTimingDataTypeVisible( 3 );
}

void BCSettingEDIDDlg::on_m_pDTimingDataType5RB_clicked()
{
    SetDetailedTimingDataTypeVisible( 4 );
}

void BCSettingEDIDDlg::on_m_pDTimingDataType6RB_clicked()
{
    SetDetailedTimingDataTypeVisible( 5 );
}

void BCSettingEDIDDlg::on_m_pDTimingDataType7RB_clicked()
{
    SetDetailedTimingDataTypeVisible( 6 );
}

void BCSettingEDIDDlg::on_m_pDTimingDataType8RB_clicked()
{
    SetDetailedTimingDataTypeVisible( 7 );
}

void BCSettingEDIDDlg::on_m_pDTimingSecondaryTimingCB_clicked(bool bChecked)
{
    ui->m_pDTimingStartLE->setEnabled( bChecked );
    ui->m_pDTimingKLE->setEnabled( bChecked );
    ui->m_pDTimingCLE->setEnabled( bChecked );
    ui->m_pDTimingTLE->setEnabled( bChecked );
    ui->m_pDTimingMLE->setEnabled( bChecked );
}

void BCSettingEDIDDlg::on_m_pDTimingUsePointData1CB_clicked(bool bChecked)
{
    ui->m_pDTimingWhitePoint1LE->setEnabled( bChecked );
    ui->m_pDTimingWhiteX1LE->setEnabled( bChecked );
    ui->m_pDTimingWhiteY1LE->setEnabled( bChecked );
    ui->m_pDTimingGamma1LE->setEnabled( bChecked );
}

void BCSettingEDIDDlg::on_m_pDTimingUsePointData2CB_clicked(bool bChecked)
{
    ui->m_pDTimingWhitePoint2LE->setEnabled( bChecked );
    ui->m_pDTimingWhiteX2LE->setEnabled( bChecked );
    ui->m_pDTimingWhiteY2LE->setEnabled( bChecked );
    ui->m_pDTimingGamma2LE->setEnabled( bChecked );
}

void BCSettingEDIDDlg::SaveDetailedTimingPreTimingIDPara()
{
    // 需要区分是哪个block的参数，只有234有可能
    // 1-2
    if (ui->m_pDTimingID1GB->title() == "Timing ID #1") {
        if (ui->m_pDTimingBlock2RB->isChecked()) {
            m_pEDIDConfig->nBlock2TimingID1Active = ui->m_pDTimingIDAction1LE->text().toInt();
            m_pEDIDConfig->nBlock2TimingID1Refresh = ui->m_pDTimingIDRefresh1LE->text().toInt();
            m_pEDIDConfig->nBlock2TimingID1AspectIndex = ui->m_pDTimingIDAspect11RB->isChecked() ?
                        0 : ui->m_pDTimingIDAspect12RB->isChecked() ?
                            1 : ui->m_pDTimingIDAspect13RB->isChecked() ? 2 : 3;

            m_pEDIDConfig->nBlock2TimingID2Active = ui->m_pDTimingIDAction2LE->text().toInt();
            m_pEDIDConfig->nBlock2TimingID2Refresh = ui->m_pDTimingIDRefresh2LE->text().toInt();
            m_pEDIDConfig->nBlock2TimingID2AspectIndex = ui->m_pDTimingIDAspect21RB->isChecked() ?
                        0 : ui->m_pDTimingIDAspect22RB->isChecked() ?
                            1 : ui->m_pDTimingIDAspect23RB->isChecked() ? 2 : 3;
        }
        if (ui->m_pDTimingBlock3RB->isChecked()) {
            m_pEDIDConfig->nBlock3TimingID1Active = ui->m_pDTimingIDAction1LE->text().toInt();
            m_pEDIDConfig->nBlock3TimingID1Refresh = ui->m_pDTimingIDRefresh1LE->text().toInt();
            m_pEDIDConfig->nBlock3TimingID1AspectIndex = ui->m_pDTimingIDAspect11RB->isChecked() ?
                        0 : ui->m_pDTimingIDAspect12RB->isChecked() ?
                            1 : ui->m_pDTimingIDAspect13RB->isChecked() ? 2 : 3;

            m_pEDIDConfig->nBlock3TimingID2Active = ui->m_pDTimingIDAction2LE->text().toInt();
            m_pEDIDConfig->nBlock3TimingID2Refresh = ui->m_pDTimingIDRefresh2LE->text().toInt();
            m_pEDIDConfig->nBlock3TimingID2AspectIndex = ui->m_pDTimingIDAspect21RB->isChecked() ?
                        0 : ui->m_pDTimingIDAspect22RB->isChecked() ?
                            1 : ui->m_pDTimingIDAspect23RB->isChecked() ? 2 : 3;
        }
        if (ui->m_pDTimingBlock4RB->isChecked()) {
            m_pEDIDConfig->nBlock4TimingID1Active = ui->m_pDTimingIDAction1LE->text().toInt();
            m_pEDIDConfig->nBlock4TimingID1Refresh = ui->m_pDTimingIDRefresh1LE->text().toInt();
            m_pEDIDConfig->nBlock4TimingID1AspectIndex = ui->m_pDTimingIDAspect11RB->isChecked() ?
                        0 : ui->m_pDTimingIDAspect12RB->isChecked() ?
                            1 : ui->m_pDTimingIDAspect13RB->isChecked() ? 2 : 3;

            m_pEDIDConfig->nBlock4TimingID2Active = ui->m_pDTimingIDAction2LE->text().toInt();
            m_pEDIDConfig->nBlock4TimingID2Refresh = ui->m_pDTimingIDRefresh2LE->text().toInt();
            m_pEDIDConfig->nBlock4TimingID2AspectIndex = ui->m_pDTimingIDAspect21RB->isChecked() ?
                        0 : ui->m_pDTimingIDAspect22RB->isChecked() ?
                            1 : ui->m_pDTimingIDAspect23RB->isChecked() ? 2 : 3;
        }
    }
    if (ui->m_pDTimingID1GB->title() == "Timing ID #3") {
        if (ui->m_pDTimingBlock2RB->isChecked()) {
            m_pEDIDConfig->nBlock2TimingID3Active = ui->m_pDTimingIDAction1LE->text().toInt();
            m_pEDIDConfig->nBlock2TimingID3Refresh = ui->m_pDTimingIDRefresh1LE->text().toInt();
            m_pEDIDConfig->nBlock2TimingID3AspectIndex = ui->m_pDTimingIDAspect11RB->isChecked() ?
                        0 : ui->m_pDTimingIDAspect12RB->isChecked() ?
                            1 : ui->m_pDTimingIDAspect13RB->isChecked() ? 2 : 3;

            m_pEDIDConfig->nBlock2TimingID4Active = ui->m_pDTimingIDAction2LE->text().toInt();
            m_pEDIDConfig->nBlock2TimingID4Refresh = ui->m_pDTimingIDRefresh2LE->text().toInt();
            m_pEDIDConfig->nBlock2TimingID4AspectIndex = ui->m_pDTimingIDAspect21RB->isChecked() ?
                        0 : ui->m_pDTimingIDAspect22RB->isChecked() ?
                            1 : ui->m_pDTimingIDAspect23RB->isChecked() ? 2 : 3;
        }
        if (ui->m_pDTimingBlock3RB->isChecked()) {
            m_pEDIDConfig->nBlock3TimingID3Active = ui->m_pDTimingIDAction1LE->text().toInt();
            m_pEDIDConfig->nBlock3TimingID3Refresh = ui->m_pDTimingIDRefresh1LE->text().toInt();
            m_pEDIDConfig->nBlock3TimingID3AspectIndex = ui->m_pDTimingIDAspect11RB->isChecked() ?
                        0 : ui->m_pDTimingIDAspect12RB->isChecked() ?
                            1 : ui->m_pDTimingIDAspect13RB->isChecked() ? 2 : 3;

            m_pEDIDConfig->nBlock3TimingID4Active = ui->m_pDTimingIDAction2LE->text().toInt();
            m_pEDIDConfig->nBlock3TimingID4Refresh = ui->m_pDTimingIDRefresh2LE->text().toInt();
            m_pEDIDConfig->nBlock3TimingID4AspectIndex = ui->m_pDTimingIDAspect21RB->isChecked() ?
                        0 : ui->m_pDTimingIDAspect22RB->isChecked() ?
                            1 : ui->m_pDTimingIDAspect23RB->isChecked() ? 2 : 3;
        }
        if (ui->m_pDTimingBlock4RB->isChecked()) {
            m_pEDIDConfig->nBlock4TimingID3Active = ui->m_pDTimingIDAction1LE->text().toInt();
            m_pEDIDConfig->nBlock4TimingID3Refresh = ui->m_pDTimingIDRefresh1LE->text().toInt();
            m_pEDIDConfig->nBlock4TimingID3AspectIndex = ui->m_pDTimingIDAspect11RB->isChecked() ?
                        0 : ui->m_pDTimingIDAspect12RB->isChecked() ?
                            1 : ui->m_pDTimingIDAspect13RB->isChecked() ? 2 : 3;

            m_pEDIDConfig->nBlock4TimingID4Active = ui->m_pDTimingIDAction2LE->text().toInt();
            m_pEDIDConfig->nBlock4TimingID4Refresh = ui->m_pDTimingIDRefresh2LE->text().toInt();
            m_pEDIDConfig->nBlock4TimingID4AspectIndex = ui->m_pDTimingIDAspect21RB->isChecked() ?
                        0 : ui->m_pDTimingIDAspect22RB->isChecked() ?
                            1 : ui->m_pDTimingIDAspect23RB->isChecked() ? 2 : 3;
        }
    }
    if (ui->m_pDTimingID1GB->title() == "Timing ID #5") {
        if (ui->m_pDTimingBlock2RB->isChecked()) {
            m_pEDIDConfig->nBlock2TimingID5Active = ui->m_pDTimingIDAction1LE->text().toInt();
            m_pEDIDConfig->nBlock2TimingID5Refresh = ui->m_pDTimingIDRefresh1LE->text().toInt();
            m_pEDIDConfig->nBlock2TimingID5AspectIndex = ui->m_pDTimingIDAspect11RB->isChecked() ?
                        0 : ui->m_pDTimingIDAspect12RB->isChecked() ?
                            1 : ui->m_pDTimingIDAspect13RB->isChecked() ? 2 : 3;

            m_pEDIDConfig->nBlock2TimingID6Active = ui->m_pDTimingIDAction2LE->text().toInt();
            m_pEDIDConfig->nBlock2TimingID6Refresh = ui->m_pDTimingIDRefresh2LE->text().toInt();
            m_pEDIDConfig->nBlock2TimingID6AspectIndex = ui->m_pDTimingIDAspect21RB->isChecked() ?
                        0 : ui->m_pDTimingIDAspect22RB->isChecked() ?
                            1 : ui->m_pDTimingIDAspect23RB->isChecked() ? 2 : 3;
        }
        if (ui->m_pDTimingBlock3RB->isChecked()) {
            m_pEDIDConfig->nBlock3TimingID5Active = ui->m_pDTimingIDAction1LE->text().toInt();
            m_pEDIDConfig->nBlock3TimingID5Refresh = ui->m_pDTimingIDRefresh1LE->text().toInt();
            m_pEDIDConfig->nBlock3TimingID5AspectIndex = ui->m_pDTimingIDAspect11RB->isChecked() ?
                        0 : ui->m_pDTimingIDAspect12RB->isChecked() ?
                            1 : ui->m_pDTimingIDAspect13RB->isChecked() ? 2 : 3;

            m_pEDIDConfig->nBlock3TimingID6Active = ui->m_pDTimingIDAction2LE->text().toInt();
            m_pEDIDConfig->nBlock3TimingID6Refresh = ui->m_pDTimingIDRefresh2LE->text().toInt();
            m_pEDIDConfig->nBlock3TimingID6AspectIndex = ui->m_pDTimingIDAspect21RB->isChecked() ?
                        0 : ui->m_pDTimingIDAspect22RB->isChecked() ?
                            1 : ui->m_pDTimingIDAspect23RB->isChecked() ? 2 : 3;
        }
        if (ui->m_pDTimingBlock4RB->isChecked()) {
            m_pEDIDConfig->nBlock4TimingID5Active = ui->m_pDTimingIDAction1LE->text().toInt();
            m_pEDIDConfig->nBlock4TimingID5Refresh = ui->m_pDTimingIDRefresh1LE->text().toInt();
            m_pEDIDConfig->nBlock4TimingID5AspectIndex = ui->m_pDTimingIDAspect11RB->isChecked() ?
                        0 : ui->m_pDTimingIDAspect12RB->isChecked() ?
                            1 : ui->m_pDTimingIDAspect13RB->isChecked() ? 2 : 3;

            m_pEDIDConfig->nBlock4TimingID6Active = ui->m_pDTimingIDAction2LE->text().toInt();
            m_pEDIDConfig->nBlock4TimingID6Refresh = ui->m_pDTimingIDRefresh2LE->text().toInt();
            m_pEDIDConfig->nBlock4TimingID6AspectIndex = ui->m_pDTimingIDAspect21RB->isChecked() ?
                        0 : ui->m_pDTimingIDAspect22RB->isChecked() ?
                            1 : ui->m_pDTimingIDAspect23RB->isChecked() ? 2 : 3;
        }
    }
}

void BCSettingEDIDDlg::on_m_pDTimingIDView1RB_clicked()
{
    // save data
    SaveDetailedTimingPreTimingIDPara();

    if (ui->m_pDTimingBlock2RB->isChecked())
        SetDetailedTimingDataTypePara5(m_pEDIDConfig->nBlock2TimingID1Active, m_pEDIDConfig->nBlock2TimingID1Refresh, m_pEDIDConfig->nBlock2TimingID1AspectIndex,
                                       m_pEDIDConfig->nBlock2TimingID2Active, m_pEDIDConfig->nBlock2TimingID2Refresh, m_pEDIDConfig->nBlock2TimingID2AspectIndex);
    else if (ui->m_pDTimingBlock3RB->isChecked())
        SetDetailedTimingDataTypePara5(m_pEDIDConfig->nBlock3TimingID1Active, m_pEDIDConfig->nBlock3TimingID1Refresh, m_pEDIDConfig->nBlock3TimingID1AspectIndex,
                                       m_pEDIDConfig->nBlock3TimingID2Active, m_pEDIDConfig->nBlock3TimingID2Refresh, m_pEDIDConfig->nBlock3TimingID2AspectIndex);
    else if (ui->m_pDTimingBlock4RB->isChecked())
        SetDetailedTimingDataTypePara5(m_pEDIDConfig->nBlock4TimingID1Active, m_pEDIDConfig->nBlock4TimingID1Refresh, m_pEDIDConfig->nBlock4TimingID1AspectIndex,
                                       m_pEDIDConfig->nBlock4TimingID2Active, m_pEDIDConfig->nBlock4TimingID2Refresh, m_pEDIDConfig->nBlock4TimingID2AspectIndex);
}

void BCSettingEDIDDlg::on_m_pDTimingIDView2RB_clicked()
{
    // save data
    SaveDetailedTimingPreTimingIDPara();

    if (ui->m_pDTimingBlock2RB->isChecked())
        SetDetailedTimingDataTypePara5(m_pEDIDConfig->nBlock2TimingID1Active, m_pEDIDConfig->nBlock2TimingID1Refresh, m_pEDIDConfig->nBlock2TimingID1AspectIndex,
                                       m_pEDIDConfig->nBlock2TimingID2Active, m_pEDIDConfig->nBlock2TimingID2Refresh, m_pEDIDConfig->nBlock2TimingID2AspectIndex, 3);
    else if (ui->m_pDTimingBlock3RB->isChecked())
        SetDetailedTimingDataTypePara5(m_pEDIDConfig->nBlock3TimingID1Active, m_pEDIDConfig->nBlock3TimingID1Refresh, m_pEDIDConfig->nBlock3TimingID1AspectIndex,
                                       m_pEDIDConfig->nBlock3TimingID2Active, m_pEDIDConfig->nBlock3TimingID2Refresh, m_pEDIDConfig->nBlock3TimingID2AspectIndex, 3);
    else if (ui->m_pDTimingBlock4RB->isChecked())
        SetDetailedTimingDataTypePara5(m_pEDIDConfig->nBlock4TimingID1Active, m_pEDIDConfig->nBlock4TimingID1Refresh, m_pEDIDConfig->nBlock4TimingID1AspectIndex,
                                       m_pEDIDConfig->nBlock4TimingID2Active, m_pEDIDConfig->nBlock4TimingID2Refresh, m_pEDIDConfig->nBlock4TimingID2AspectIndex, 3);
}

void BCSettingEDIDDlg::on_m_pDTimingIDView3RB_clicked()
{
    // save data
    SaveDetailedTimingPreTimingIDPara();

    if (ui->m_pDTimingBlock2RB->isChecked())
        SetDetailedTimingDataTypePara5(m_pEDIDConfig->nBlock2TimingID1Active, m_pEDIDConfig->nBlock2TimingID1Refresh, m_pEDIDConfig->nBlock2TimingID1AspectIndex,
                                       m_pEDIDConfig->nBlock2TimingID2Active, m_pEDIDConfig->nBlock2TimingID2Refresh, m_pEDIDConfig->nBlock2TimingID2AspectIndex, 5);
    else if (ui->m_pDTimingBlock3RB->isChecked())
        SetDetailedTimingDataTypePara5(m_pEDIDConfig->nBlock3TimingID1Active, m_pEDIDConfig->nBlock3TimingID1Refresh, m_pEDIDConfig->nBlock3TimingID1AspectIndex,
                                       m_pEDIDConfig->nBlock3TimingID2Active, m_pEDIDConfig->nBlock3TimingID2Refresh, m_pEDIDConfig->nBlock3TimingID2AspectIndex, 5);
    else if (ui->m_pDTimingBlock4RB->isChecked())
        SetDetailedTimingDataTypePara5(m_pEDIDConfig->nBlock4TimingID1Active, m_pEDIDConfig->nBlock4TimingID1Refresh, m_pEDIDConfig->nBlock4TimingID1AspectIndex,
                                       m_pEDIDConfig->nBlock4TimingID2Active, m_pEDIDConfig->nBlock4TimingID2Refresh, m_pEDIDConfig->nBlock4TimingID2AspectIndex, 5);
}

void BCSettingEDIDDlg::on_m_pDTimingAnalogRB_clicked()
{
    ui->m_pDTimingSyncSchemePara1CB->setText("Serrate");
    ui->m_pDTimingSyncSchemePara2CB->setText("On RGB");
}

void BCSettingEDIDDlg::on_m_pDTimingAnalogBipolarRB_clicked()
{
    ui->m_pDTimingSyncSchemePara1CB->setText("Serrate");
    ui->m_pDTimingSyncSchemePara2CB->setText("On RGB");
}

void BCSettingEDIDDlg::on_m_pDTimingDigitalComposionRB_clicked()
{
    ui->m_pDTimingSyncSchemePara1CB->setText("Serrate");
    ui->m_pDTimingSyncSchemePara2CB->setText("Polarity (+)");
}

void BCSettingEDIDDlg::on_m_pDTimingDigitalSeparaRB_clicked()
{
    ui->m_pDTimingSyncSchemePara1CB->setText("V Polarity (+)");
    ui->m_pDTimingSyncSchemePara2CB->setText("H Polarity (+)");
}

void BCSettingEDIDDlg::on_m_pLoadBtn_clicked()
{
    // 刷新数据
    Refresh();
}

void BCSettingEDIDDlg::on_m_pSaveBtn_clicked()
{
    // general
    strcpy(m_pEDIDConfig->cVendorID, BCCommon::getTextStr(ui->m_pGeneralVendorIDLE->text()));
    strcpy(m_pEDIDConfig->cProduct, BCCommon::getTextStr(ui->m_pGeneralProductLE->text()));
    m_pEDIDConfig->nSerial = ui->m_pGeneralSerialLE->text().toInt();
    m_pEDIDConfig->nMfgWeek = ui->m_pGeneralMfgWeekLE->text().toInt();
    m_pEDIDConfig->nMfgYear = ui->m_pGeneralMfgYearLE->text().toInt();

    m_pEDIDConfig->nVersion = ui->m_pGeneralVersionLE->text().toInt();
    m_pEDIDConfig->nRevision = ui->m_pGeneralRevisionLE->text().toInt();
    m_pEDIDConfig->nChecksum = ui->m_pGeneralChecksumLE->text().toInt();

    m_pEDIDConfig->nExtensions = ui->m_pGeneralExtensionLE->text().toInt();

    // basic display parameters
    m_pEDIDConfig->nIsAnalog = ui->m_pDisplayAnalogRB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nSignalLevelIndex = ui->m_pDisplaySignalLevel1RB->isChecked() ?
                0 : ui->m_pDisplaySignalLevel2RB->isChecked() ?
                    1 : ui->m_pDisplaySignalLevel3RB->isChecked() ? 2 : 3;

    m_pEDIDConfig->nSetupExpected = ui->m_pDisplaySignalLevelSetupCB->text().toInt();
    m_pEDIDConfig->nSeparateSyncs = ui->m_pDisplaySyncInput1CB->text().toInt();
    m_pEDIDConfig->nCompositeSyncs = ui->m_pDisplaySyncInput2CB->text().toInt();
    m_pEDIDConfig->nSyncOnGreenVideo = ui->m_pDisplaySyncInput3CB->text().toInt();
    m_pEDIDConfig->nSerrationOfVsync = ui->m_pDisplaySyncInput4CB->text().toInt();
    m_pEDIDConfig->nDFP = ui->m_pDisplayDFPCB->isChecked() ? 1 : 0;

    m_pEDIDConfig->nStandby = ui->m_pDisplayStandbyCB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nSuspend = ui->m_pDisplaySuspendCB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nActiveOff = ui->m_pDisplayActiveOffCB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nDisplayType = ui->m_pDisplayType1RB->isChecked() ?
                0 : ui->m_pDisplayType2RB->isChecked() ?
                    1 : ui->m_pDisplayType3RB->isChecked() ? 2 : 3;

    m_pEDIDConfig->nSRGB = ui->m_pDisplayRGBCB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nGTF = ui->m_pDisplayGTFCB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nPreferredTiming = ui->m_pDisplayPreferredCB->isChecked() ? 1 : 0;

    m_pEDIDConfig->nMaxHImageSize = ui->m_pDisplayMaxHSizeLE->text().toInt();
    m_pEDIDConfig->nMaxVImageSize = ui->m_pDisplayMaxVSizeLE->text().toInt();
    m_pEDIDConfig->nGammaValue = ui->m_pDisplayGammaValueLE->text().toInt()/100;

    // color / established timings
    m_pEDIDConfig->nRedX = ui->m_pColorRedXLE->text().toInt()*1000;
    m_pEDIDConfig->nRedY = ui->m_pColorRedYLE->text().toInt()*1000;
    m_pEDIDConfig->nGreenX = ui->m_pColorGreenXLE->text().toInt()*1000;
    m_pEDIDConfig->nGreenY = ui->m_pColorGreenYLE->text().toInt()*1000;
    m_pEDIDConfig->nBlueX = ui->m_pColorBlueXLE->text().toInt()*1000;
    m_pEDIDConfig->nBlueY = ui->m_pColorBlueYLE->text().toInt()*1000;
    m_pEDIDConfig->nWhiteX = ui->m_pColorWhiteXLE->text().toInt()*1000;
    m_pEDIDConfig->nWhiteY = ui->m_pColorWhiteYLE->text().toInt()*1000;

    m_pEDIDConfig->nEstablishTiming1 = ui->m_pColorEstablished1CB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nEstablishTiming2 = ui->m_pColorEstablished2CB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nEstablishTiming3 = ui->m_pColorEstablished3CB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nEstablishTiming4 = ui->m_pColorEstablished4CB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nEstablishTiming5 = ui->m_pColorEstablished5CB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nEstablishTiming6 = ui->m_pColorEstablished6CB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nEstablishTiming7 = ui->m_pColorEstablished7CB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nEstablishTiming8 = ui->m_pColorEstablished8CB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nEstablishTiming9 = ui->m_pColorEstablished9CB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nEstablishTiming10 = ui->m_pColorEstablished10CB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nEstablishTiming11 = ui->m_pColorEstablished11CB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nEstablishTiming12 = ui->m_pColorEstablished12CB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nEstablishTiming13 = ui->m_pColorEstablished13CB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nEstablishTiming14 = ui->m_pColorEstablished14CB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nEstablishTiming15 = ui->m_pColorEstablished15CB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nEstablishTiming16 = ui->m_pColorEstablished16CB->isChecked() ? 1 : 0;
    m_pEDIDConfig->nEstablishTiming17 = ui->m_pColorEstablished17CB->isChecked() ? 1 : 0;

    // standard timings
    // 初始化只显示前四个
    if ( ui->m_pSTimingView1RB->isChecked() ) {
        m_pEDIDConfig->nTimingEnable1 = ui->m_pSTimingEnable1CB->isChecked() ? true : false;
        m_pEDIDConfig->nHActive1 = ui->m_pSTimingActive1LE->text().toInt();
        m_pEDIDConfig->nRefresh1 = ui->m_pSTimingRefresh1LE->text().toInt();
        m_pEDIDConfig->nAspectRatioIndex1 = ui->m_pSTimingAspect11RB->isChecked() ?
                    0 : ui->m_pSTimingAspect12RB->isChecked() ?
                        1 : ui->m_pSTimingAspect13RB->isChecked() ? 2 : 3;

        m_pEDIDConfig->nTimingEnable2 = ui->m_pSTimingEnable2CB->isChecked() ? true : false;
        m_pEDIDConfig->nHActive2 = ui->m_pSTimingActive2LE->text().toInt();
        m_pEDIDConfig->nRefresh2 = ui->m_pSTimingRefresh2LE->text().toInt();
        m_pEDIDConfig->nAspectRatioIndex2 = ui->m_pSTimingAspect21RB->isChecked() ?
                    0 : ui->m_pSTimingAspect22RB->isChecked() ?
                        1 : ui->m_pSTimingAspect23RB->isChecked() ? 2 : 3;

        m_pEDIDConfig->nTimingEnable3 = ui->m_pSTimingEnable3CB->isChecked() ? true : false;
        m_pEDIDConfig->nHActive3 = ui->m_pSTimingActive3LE->text().toInt();
        m_pEDIDConfig->nRefresh3 = ui->m_pSTimingRefresh3LE->text().toInt();
        m_pEDIDConfig->nAspectRatioIndex3 = ui->m_pSTimingAspect31RB->isChecked() ?
                    0 : ui->m_pSTimingAspect32RB->isChecked() ?
                        1 : ui->m_pSTimingAspect33RB->isChecked() ? 2 : 3;

        m_pEDIDConfig->nTimingEnable4 = ui->m_pSTimingEnable4CB->isChecked() ? true : false;
        m_pEDIDConfig->nHActive4 = ui->m_pSTimingActive4LE->text().toInt();
        m_pEDIDConfig->nRefresh4 = ui->m_pSTimingRefresh4LE->text().toInt();
        m_pEDIDConfig->nAspectRatioIndex4 = ui->m_pSTimingAspect41RB->isChecked() ?
                    0 : ui->m_pSTimingAspect42RB->isChecked() ?
                        1 : ui->m_pSTimingAspect43RB->isChecked() ? 2 : 3;
    } else {
        m_pEDIDConfig->nTimingEnable5 = ui->m_pSTimingEnable1CB->isChecked() ? true : false;
        m_pEDIDConfig->nHActive5 = ui->m_pSTimingActive1LE->text().toInt();
        m_pEDIDConfig->nRefresh5 = ui->m_pSTimingRefresh1LE->text().toInt();
        m_pEDIDConfig->nAspectRatioIndex5 = ui->m_pSTimingAspect11RB->isChecked() ?
                    0 : ui->m_pSTimingAspect12RB->isChecked() ?
                        1 : ui->m_pSTimingAspect13RB->isChecked() ? 2 : 3;

        m_pEDIDConfig->nTimingEnable6 = ui->m_pSTimingEnable2CB->isChecked() ? true : false;
        m_pEDIDConfig->nHActive6 = ui->m_pSTimingActive2LE->text().toInt();
        m_pEDIDConfig->nRefresh6 = ui->m_pSTimingRefresh2LE->text().toInt();
        m_pEDIDConfig->nAspectRatioIndex6 = ui->m_pSTimingAspect21RB->isChecked() ?
                    0 : ui->m_pSTimingAspect22RB->isChecked() ?
                        1 : ui->m_pSTimingAspect23RB->isChecked() ? 2 : 3;

        m_pEDIDConfig->nTimingEnable7 = ui->m_pSTimingEnable3CB->isChecked() ? true : false;
        m_pEDIDConfig->nHActive7 = ui->m_pSTimingActive3LE->text().toInt();
        m_pEDIDConfig->nRefresh7 = ui->m_pSTimingRefresh3LE->text().toInt();
        m_pEDIDConfig->nAspectRatioIndex7 = ui->m_pSTimingAspect31RB->isChecked() ?
                    0 : ui->m_pSTimingAspect32RB->isChecked() ?
                        1 : ui->m_pSTimingAspect33RB->isChecked() ? 2 : 3;

        m_pEDIDConfig->nTimingEnable8 = ui->m_pSTimingEnable4CB->isChecked() ? true : false;
        m_pEDIDConfig->nHActive8 = ui->m_pSTimingActive4LE->text().toInt();
        m_pEDIDConfig->nRefresh8 = ui->m_pSTimingRefresh4LE->text().toInt();
        m_pEDIDConfig->nAspectRatioIndex8 = ui->m_pSTimingAspect41RB->isChecked() ?
                    0 : ui->m_pSTimingAspect42RB->isChecked() ?
                        1 : ui->m_pSTimingAspect43RB->isChecked() ? 2 : 3;
    }

    // detailed timings
    SaveDetailedTimingPreBlockPara();

    // save
//    BCLocalServer *pLocalServer = BCLocalServer::Application();
//    pLocalServer->SetEDIDConfig( m_pEDIDConfig );
}
