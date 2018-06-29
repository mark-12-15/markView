#include "BCSettingMainPanelStyle.h"
#include "ui_BCSettingMainPanelStyle.h"
#include <QDebug>
#include <QPushButton>
#include "../Common/BCCommon.h"

BCSettingMainPanelStyle::BCSettingMainPanelStyle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingMainPanelStyle)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("关闭选项"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    // 初始化
    ui->m_pQuitToTrayRadioBtn->setChecked( BCCommon::g_bApplicationQuitToTrayIcon );
    ui->m_pQuitRadioBtn->setChecked( !BCCommon::g_bApplicationQuitToTrayIcon );
}

BCSettingMainPanelStyle::~BCSettingMainPanelStyle()
{
    delete ui;
}

void BCSettingMainPanelStyle::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingMainPanelStyle::on_m_pOKBtn_clicked()
{
    BCCommon::g_bApplicationQuitToTrayIcon = ui->m_pQuitToTrayRadioBtn->isChecked();

    // 写入文件
    QFile file( QString("../xml/BCGenaralConfig.xml") );
    if ( file.open(QIODevice::ReadOnly)) {

        // 将文件内容读到QDomDocument中
        QDomDocument doc;
        bool bLoadFile = doc.setContent(&file);
        file.close();

        if ( bLoadFile ) {
            // 二级链表
            QDomElement docElem = doc.documentElement();
            docElem.setAttribute("QuitToTray", BCCommon::g_bApplicationQuitToTrayIcon ? 1 : 0 );

            // 写入文件
            if( file.open(QIODevice::WriteOnly | QIODevice::Truncate) ) {
                QTextStream out(&file);
                doc.save(out,4);
                file.close();
            }
        }
    }

    this->accept();
}
