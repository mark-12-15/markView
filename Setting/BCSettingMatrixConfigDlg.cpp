#include "BCSettingMatrixConfigDlg.h"
#include "ui_BCSettingMatrixConfigDlg.h"

#define ICON_SIZE 48

//class BCMatrixListWidgetItem : public QListWidgetItem
//{
//public:
//    BCMatrixListWidgetItem(int id, QListWidget *parent = NULL);

//    void SetName(const QString &qsName) {
//        m_qsName = qsName;
//        this->setText( m_qsName );
//    }

//    QString m_qsName;
//    int     m_nGroupID;
//    int     m_nDisplayCount;
//    int     m_nStartChannel;        // 起始通道ID
//    int     m_nResolution;          // 0-4 分辨代表1920*1080... -1代表自定义
//    int     m_nCustomResolutionX;
//    int     m_nCustomResolutionY;
//    int     m_nArrayX;
//    int     m_nArrayY;
//    int     m_nType;                // 0:LCD 1:LED 2:融合
//    bool    m_bModify;              // 记录是否修改
//};

//BCMatrixListWidgetItem::BCMatrixListWidgetItem(int id, QListWidget *parent)
//    :QListWidgetItem(parent)
//{
//    m_qsName = QObject::tr("拼接屏%1").arg(parent->count()-1);
//    m_nGroupID = id;
//    m_nStartChannel = 0;
//    m_nDisplayCount = 4;
//    m_nArrayX = 2;
//    m_nArrayY = 2;
//    m_nResolution = 0;
//    m_nCustomResolutionX = 1920;
//    m_nCustomResolutionY = 1080;
//    m_nType = 0;
//    m_bModify = false;

//    this->setTextAlignment(Qt::AlignHCenter); // 对齐方式
//    this->setSizeHint (QSize(ICON_SIZE + 20, ICON_SIZE + 20));
//    this->setIcon(QIcon(BCCommon::g_qsApplicationDefaultStylePath + QString("/montage64.png")));
//    this->setText( m_qsName );
//}

// --------------------------------------------------------------------------------------------------------------------------------------
BCSettingMatrixConfigDlg::BCSettingMatrixConfigDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingMatrixConfigDlg)
{
    ui->setupUi(this);
}

BCSettingMatrixConfigDlg::~BCSettingMatrixConfigDlg()
{
    delete ui;
}

void BCSettingMatrixConfigDlg::on_m_pAddBtn_clicked()
{

}
