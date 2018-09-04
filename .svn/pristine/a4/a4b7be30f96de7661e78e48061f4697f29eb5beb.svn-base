#include "BCSettingDisplyModelStyle.h"
#include "ui_BCSettingDisplyModelStyle.h"
#include "../Common/BCCommon.h"
#include <QPushButton>
#include "../Common/BCXMLManager.h"
BCSettingDisplyModelStyle::BCSettingDisplyModelStyle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingDisplyModelStyle)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("启动设置"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    switch ( BCCommon::g_bApplicationDefaultDisplayMode ) {
    case 0:
        ui->m_pRadioBtn1->setChecked( true );
        break;
    case 1:
        ui->m_pRadioBtn2->setChecked( true );
        break;
    case 2:
        ui->m_pRadioBtn3->setChecked( true );
        break;
    case 3:
        ui->m_pRadioBtn4->setChecked( true );
        break;
    default:
        break;
    }
    ui->m_pWLineEdit->setText( QString::number(BCCommon::g_bApplicationNomarlDisplayWidth));
    ui->m_pHLineEdit->setText( QString::number(BCCommon::g_bApplicationNomarlDisplayHeight));
}

BCSettingDisplyModelStyle::~BCSettingDisplyModelStyle()
{
    delete ui;
}

void BCSettingDisplyModelStyle::on_m_pOKBtn_clicked()
{
    if ( ui->m_pRadioBtn1->isChecked() ) {
        BCCommon::g_bApplicationDefaultDisplayMode = 0;
    } else if ( ui->m_pRadioBtn2->isChecked() ) {
        BCCommon::g_bApplicationDefaultDisplayMode = 1;
    } else if ( ui->m_pRadioBtn3->isChecked() ) {
        BCCommon::g_bApplicationDefaultDisplayMode = 2;
    } else if ( ui->m_pRadioBtn4->isChecked() ) {
        BCCommon::g_bApplicationDefaultDisplayMode = 3;
    }
    BCCommon::g_bApplicationNomarlDisplayWidth = ui->m_pWLineEdit->text().toInt();
    BCCommon::g_bApplicationNomarlDisplayHeight = ui->m_pHLineEdit->text().toInt();

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
            docElem.setAttribute("AppDefaultDisplayMode", BCCommon::g_bApplicationDefaultDisplayMode);
            docElem.setAttribute("AppNomarlDisplayWidth", BCCommon::g_bApplicationNomarlDisplayWidth);
            docElem.setAttribute("AppNomarlDisplayHeight", BCCommon::g_bApplicationNomarlDisplayHeight);

            // 写入文件
            if( file.open(QIODevice::WriteOnly | QIODevice::Truncate) ) {
                QTextStream out(&file);
                doc.save(out,4);
                file.close();
            }
        }
    }

    // 重新显示
    MainWindow *pMainWindow = BCCommon::Application();
    pMainWindow->Show();

    close();
}

void BCSettingDisplyModelStyle::on_m_pCancelBtn_clicked()
{
    this->reject();
}
