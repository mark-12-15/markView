#include "BCSettingChangeLanguageStyle.h"
#include "ui_BCSettingChangeLanguageStyle.h"
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"

BCSettingChangeLanguageStyle::BCSettingChangeLanguageStyle(QWidget *parent)
    :QDialog(parent),
    ui(new Ui::BCSettingChangeLanguageStyle)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("语言支持"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    // init language
    QStringList lstLanguage;
    lstLanguage << tr("简体中文") << tr("繁体中文") << tr("英文") << tr("西班牙文") << tr("俄文") << tr("韩文");
    ui->comboBox->insertItems(0, lstLanguage);

    // 从服务器中取语言配置信息
    BCLocalServer *pServer = BCLocalServer::Application();
//    QPoint pt = pServer->GetLanguageConfig();
    QPoint pt;
    // 设置是否默认中文
    bool bDefaultChinese = (pt.x() == 1) ? true : false;
    ui->m_pDefaultChineseRadioBtn->setChecked( bDefaultChinese );
    ui->m_pLastSetRadioBtn->setChecked( !bDefaultChinese );

    // 设置默认语言
    if ( bDefaultChinese ) {
        ui->comboBox->setCurrentIndex( 0 );
    } else {
        if (pt.y() < lstLanguage.count())
            ui->comboBox->setCurrentIndex( pt.y() );
    }

    // init .qm file
    m_lstQmLanguage << QString("../resource/language/SIMPLIFIED_CHINESE.qm")
                    << QString("../resource/language/TRADITIONAL_CHINESE.qm")
                    << QString("../resource/language/ENGLISH.qm")
                    << QString("../resource/language/SPANISH.qm")
                    << QString("../resource/language/RUSSIAN.qm")
                    << QString("../resource/language/KOREAN.qm");
}

BCSettingChangeLanguageStyle::~BCSettingChangeLanguageStyle()
{
    delete ui;
}

void BCSettingChangeLanguageStyle::on_pushButton_clicked()
{
    // 根据索引判断选中哪种语言
    int nCurrentLanguageIndex = ui->comboBox->currentIndex();
    if ((nCurrentLanguageIndex > -1) && (nCurrentLanguageIndex < m_lstQmLanguage.count())) {
        BCCommon::SetLanguage( m_lstQmLanguage.at(nCurrentLanguageIndex) );
    }

    int nDefaultChinese = ui->m_pDefaultChineseRadioBtn->isChecked() ? 1 : 0;

    // 设置语言配置
    BCLocalServer *pServer = BCLocalServer::Application();
//    pServer->SetLanguageConfig( QPoint(nDefaultChinese, nCurrentLanguageIndex) );

    close();
}

void BCSettingChangeLanguageStyle::on_pushButton_2_clicked()
{
    close();
}
