#include "BCSettingDisplayMakerConfigDlg.h"
#include "ui_BCSettingDisplayMakerConfigDlg.h"
#include "../Common/BCCommon.h"
#include "BCSettingDisplaySwitchConfigDlg.h"

#define ICON_SIZE 48

class BCDisplayMakerListWidgetItem : public QListWidgetItem
{
public:
    BCDisplayMakerListWidgetItem(const QString &name, QListWidget *parent = NULL);

    void SetName(const QString &qsName) {
        maker = qsName;
        this->setText( maker );
    }

    QString maker;

    int type;                       // 0:16进制 1:文本
    QString qsOnCmd;                // 打开指令
    QString qsOffCmd;               // 关闭指令
};

BCDisplayMakerListWidgetItem::BCDisplayMakerListWidgetItem(const QString &name, QListWidget *parent)
    :QListWidgetItem(parent)
{
    maker = name.isEmpty() ? "None" : name;
    type = 0;

    this->setText( maker );
    this->setTextAlignment(Qt::AlignHCenter); // 对齐方式
    this->setSizeHint (QSize(ICON_SIZE + 20, ICON_SIZE + 20));
    this->setIcon(QIcon(BCCommon::g_qsApplicationDefaultStylePath + QString("/montage64.png")));
    this->setText( maker );
}

BCSettingDisplayMakerConfigDlg::BCSettingDisplayMakerConfigDlg(const QList<sDisplayMaker> &lstDisplayMaker, BCSettingDisplaySwitchConfigDlg *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingDisplayMakerConfigDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("大屏厂家"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    m_parent = parent;

    ui->m_pListWidget->setIconSize(QSize(ICON_SIZE, ICON_SIZE));        //设置QListWidget中的单元项的图片大小
    ui->m_pListWidget->setResizeMode(QListView::Adjust);
    ui->m_pListWidget->setViewMode(QListView::IconMode);  //设置QListWidget的显示模式
    ui->m_pListWidget->setMovement(QListView::Static);    //设置QListWidget中的单元项不可被拖动
    ui->m_pListWidget->setSpacing(2);                     //设置QListWidget中的单元项的间距

    // 初始化list数据
    for (int i = 0 ; i < lstDisplayMaker.count(); i++) {
        sDisplayMaker smaker = lstDisplayMaker.at(i);

        // 新建item
        BCDisplayMakerListWidgetItem *pItem = new BCDisplayMakerListWidgetItem(smaker.maker, ui->m_pListWidget);
        pItem->type = smaker.cmdType;
        pItem->qsOnCmd = smaker.onCmd;
        pItem->qsOffCmd = smaker.offCmd;

        ui->m_pListWidget->addItem( pItem );
    }

    // 单击列表框动作
    if ( !lstDisplayMaker.isEmpty() ) {
        onCurrentItemChanged(ui->m_pListWidget->item(0), NULL);
    }
    connect(ui->m_pListWidget, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), this, SLOT(onCurrentItemChanged(QListWidgetItem*,QListWidgetItem*)));
}

BCSettingDisplayMakerConfigDlg::~BCSettingDisplayMakerConfigDlg()
{
    delete ui;
}

void BCSettingDisplayMakerConfigDlg::onCurrentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    BCDisplayMakerListWidgetItem *pPreItem = dynamic_cast<BCDisplayMakerListWidgetItem *>( previous );
    if (NULL != pPreItem) {
        // 1.保存前一个item
        pPreItem->maker = ui->m_pMakerLineEdit->text();
        pPreItem->type = ui->m_pCmdTypeComboBox->currentIndex();
        pPreItem->qsOnCmd = ui->m_pOnCmdLineEdit->text();
        pPreItem->qsOffCmd = ui->m_pOffCmdLineEdit->text();
    }

    BCDisplayMakerListWidgetItem *pCurrentItem = dynamic_cast<BCDisplayMakerListWidgetItem *>( current );
    if (NULL != pCurrentItem) {
        // 2.显示当前item
        ui->m_pMakerLineEdit->setText( pCurrentItem->maker );
        ui->m_pCmdTypeComboBox->setCurrentIndex( pCurrentItem->type );
        ui->m_pOnCmdLineEdit->setText( pCurrentItem->qsOnCmd );
        ui->m_pOffCmdLineEdit->setText( pCurrentItem->qsOffCmd );
    }
}

void BCSettingDisplayMakerConfigDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingDisplayMakerConfigDlg::on_m_pAddBtn_clicked()
{
    ui->m_pListWidget->addItem( new BCDisplayMakerListWidgetItem(QString::null, ui->m_pListWidget) );

    ui->m_pListWidget->setCurrentRow(ui->m_pListWidget->count()-1);
}

void BCSettingDisplayMakerConfigDlg::on_m_pDelBtn_clicked()
{
    ui->m_pListWidget->takeItem( ui->m_pListWidget->currentRow() );

    if (0 != ui->m_pListWidget->count())
        ui->m_pListWidget->setCurrentRow(0);
}

void BCSettingDisplayMakerConfigDlg::on_m_pModifyBtn_clicked()
{
    onCurrentItemChanged(NULL, ui->m_pListWidget->currentItem());
}

void BCSettingDisplayMakerConfigDlg::on_m_pOKBtn_clicked()
{
    // 1.保存当前房间修改
    onCurrentItemChanged(NULL, ui->m_pListWidget->currentItem());

    // 2.整理数据并修改文件
    QList<sDisplayMaker> lstDisplayMaker;
    for (int i = 0; i < ui->m_pListWidget->count(); i++) {
        BCDisplayMakerListWidgetItem *pItem = dynamic_cast<BCDisplayMakerListWidgetItem *>( ui->m_pListWidget->item( i ) );
        if (NULL == pItem)
            continue;

        sDisplayMaker smaker;
        smaker.maker = pItem->maker;
        smaker.cmdType = pItem->type;
        smaker.onCmd = pItem->qsOnCmd;
        smaker.offCmd = pItem->qsOffCmd;

        lstDisplayMaker.append( smaker );
    }

    m_parent->SetDisplayMaker( lstDisplayMaker );

    this->accept();
}
