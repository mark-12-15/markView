#include "BCSettingIPVConfigDlg.h"
#include "ui_BCSettingIPVConfigDlg.h"
#include "../Common/BCCommon.h"
#include "../Model/BCMChannel.h"

BCSettingIPVConfigDlg::BCSettingIPVConfigDlg(BCMChannel *pChannel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingIPVConfigDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("IPVideo设置"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    // 赋值数据对象
    m_pChannel = pChannel;

    // 记录对应关系
    m_mapSegmentAndIndex.insert(1, 0);
    m_mapSegmentAndIndex.insert(4, 1);
    m_mapSegmentAndIndex.insert(6, 2);
    m_mapSegmentAndIndex.insert(9, 3);
    m_mapSegmentAndIndex.insert(12, 4);
    m_mapSegmentAndIndex.insert(16, 5);

    init();
}

BCSettingIPVConfigDlg::~BCSettingIPVConfigDlg()
{
    delete ui;
}

void BCSettingIPVConfigDlg::init()
{
//    int n = m_pChannel->GetIPVSegmentation();
//    int index = m_mapSegmentAndIndex.value(n, 0);

//    if (ui->comboBox->count() > index)
//        ui->comboBox->setCurrentIndex( index );
}

void BCSettingIPVConfigDlg::on_m_pOKBtn_clicked()
{
    int index = ui->comboBox->currentIndex();
    int n = m_mapSegmentAndIndex.key(index, 1);
    //m_pChannel->SetIPVSegmentation( n );

    this->close();
}

void BCSettingIPVConfigDlg::on_m_pCancelBtn_clicked()
{
    this->close();
}
