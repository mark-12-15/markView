#include "BCSettingLanguageDlg.h"
#include "ui_BCSettingLanguageDlg.h"
#include "../Common/BCCommon.h"

BCSettingLanguageDlg::BCSettingLanguageDlg(QWidget *parent)
    :QDialog(parent),
    ui(new Ui::BCSettingLanguageDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    // 刷新语言中文显示
    RefreshLanguage();

    InitFromXml();

    // init .qm file
    m_lstQmLanguage << QString("../resource/language/SIMPLIFIED_CHINESE.qm")
                    //<< QString("../resource/language/TRADITIONAL_CHINESE.qm")
                    << QString("../resource/language/ENGLISH.qm")
                    //<< QString("../resource/language/SPANISH.qm")
                    //<< QString("../resource/language/RUSSIAN.qm")
                    //<< QString("../resource/language/KOREAN.qm")
                    << QString("../resource/language/FRENCH.qm");
}

BCSettingLanguageDlg::~BCSettingLanguageDlg()
{
    delete ui;
}

void BCSettingLanguageDlg::RefreshLanguage(bool bLocal)
{
    // 初始化标题
    this->setWindowTitle(tr("语言支持"));

    // 初始化语言选择控件
    ui->m_pSelectLanguageLabel->setText( tr("语言选择") );

    QStringList lstLanguage;
    //lstLanguage << tr("简体中文") << tr("繁体中文") << tr("英文") << tr("西班牙文") << tr("俄文") << tr("韩文") << tr("法语");
    lstLanguage << tr("简体中文") << tr("英文") << tr("法语");
    //lstLanguage << tr("简体中文") << tr("英文");
    int nCurrentIndex = ui->comboBox->currentIndex();
    ui->comboBox->clear();
    ui->comboBox->insertItems(0, lstLanguage);

    // 恢复显示
    if ((-1 != nCurrentIndex) && (nCurrentIndex < lstLanguage.count()))
        ui->comboBox->setCurrentIndex( nCurrentIndex );

    // 初始化RadioBtn
    ui->m_pDefaultChineseRadioBtn->setText( tr("默认中文") );
    ui->m_pLastSetRadioBtn->setText( tr("默认上次设置") );

    // 初始化按钮
    ui->m_pOkBtn->setText( tr("确认") );
    ui->m_pCancelBtn->setText( tr("取消") );
    ui->m_pApplyBtn->setText( tr("应用") );

    // 刷新整个软件的文字
    if ( !bLocal ) {
        MainWindow *pMainWindow = BCCommon::Application();
        pMainWindow->RefreshLanguage();
    }
}

void BCSettingLanguageDlg::InitFromXml()
{
    QFile file( QString("../xml/BCLanguageConfig.xml") );
    if(!file.open(QIODevice::ReadOnly)){
        return;
    }

    // 将文件内容读到QDomDocument中
    QDomDocument doc;
    bool bLoadFile = doc.setContent(&file);
    file.close();

    if ( !bLoadFile )
        return;

    // 二级链表
    QDomElement docElem = doc.documentElement();

    int nDefaultChinese = 0;
    int nLastIndex = 0;
    if ( !docElem.isNull() ) {
        nDefaultChinese = docElem.attribute("DefaultChinese").toInt();
        nLastIndex = docElem.attribute("LanguageLastIndex").toInt();
    }

    // 设置是否默认中文
    bool bDefaultChinese = (nDefaultChinese == 1) ? true : false;
    ui->m_pDefaultChineseRadioBtn->setChecked( bDefaultChinese );
    ui->m_pLastSetRadioBtn->setChecked( !bDefaultChinese );

    // 设置默认语言
    if ( bDefaultChinese ) {
        ui->comboBox->setCurrentIndex( 0 );
    } else {
        //if (nLastIndex < 7)
        if (nLastIndex < 3)
            ui->comboBox->setCurrentIndex( nLastIndex );
    }
}

void BCSettingLanguageDlg::UpdateXml()
{
    // 根据索引判断选中哪种语言
    int nCurrentLanguageIndex = ui->comboBox->currentIndex();
    if ((nCurrentLanguageIndex > -1) && (nCurrentLanguageIndex < m_lstQmLanguage.count())) {
        BCCommon::SetLanguage( m_lstQmLanguage.at(nCurrentLanguageIndex) );
    }

    int nDefaultChinese = ui->m_pDefaultChineseRadioBtn->isChecked() ? 1 : 0;

    // 写入文件
    QDomDocument doc;

    // 添加根节点
    QDomElement eleRoot = doc.createElement(QString("BR"));
    eleRoot.setAttribute(QString("DefaultChinese"), QString::number(nDefaultChinese));
    eleRoot.setAttribute(QString("LanguageLastIndex"), QString::number(nCurrentLanguageIndex));
    doc.appendChild( eleRoot );

    // 写入文件
    QFile file( QString("../xml/BCLanguageConfig.xml") );
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}

void BCSettingLanguageDlg::on_m_pOkBtn_clicked()
{
    // 更新XML
    UpdateXml();

    // 刷新界面
    on_m_pApplyBtn_clicked();

    this->accept();
}

void BCSettingLanguageDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingLanguageDlg::on_m_pApplyBtn_clicked()
{
    // 根据索引判断选中哪种语言
    int nCurrentLanguageIndex = ui->comboBox->currentIndex();
    if ((nCurrentLanguageIndex > -1) && (nCurrentLanguageIndex < m_lstQmLanguage.count())) {
        BCCommon::SetLanguage( m_lstQmLanguage.at(nCurrentLanguageIndex) );
    }

    RefreshLanguage( false );
}
