#include "BCScreenDlg.h"
#include "ui_BCScreenDlg.h"
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include "../common/BCCommon.h"
#include "../Model/BCMGroupScene.h"
#include "../Model/BCMWindowScene.h"
#include "../Model/BCMRoom.h"

BCScreenDlg::BCScreenDlg(BCMGroupScene *pGroupScene, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCScreenDlg)
{
    ui->setupUi(this);

    // 设置基本属性
    this->setWindowTitle(tr("添加场景"));
    this->setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    ui->lineEdit->setAlignment(Qt::AlignLeft);
    ui->checkBox->setChecked(true);

    // 变量初始化
    m_pGroupScene = pGroupScene;

    int id = m_pGroupScene->GetRoom()->GetWindowSceneID();
    ui->spinBox->setValue( id );
    ui->lineEdit->setText( tr("场景(%1)").arg(id) );
}

BCScreenDlg::~BCScreenDlg()
{
    delete ui;
}

void BCScreenDlg::on_spinBox_valueChanged(int n)
{
    if(ui->checkBox->isChecked()) {
        ui->lineEdit->setText( tr("场景(%1)").arg(n) );
    }
}

void BCScreenDlg::on_pushButton_ok_clicked()
{
    if ( m_pGroupScene->GetRoom()->IsExistWindowScene( ui->spinBox->value()) ) {
        QMessageBox box(QMessageBox::Warning,tr("警告"),tr("场景编号冲突，请更换！"));
        box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
        box.setButtonText (QMessageBox::Ok,QString(tr("确 定")));
        box.setButtonText (QMessageBox::Cancel,QString(tr("取 消")));
        box.exec ();
    } else {
        this->accept();
    }
}

void BCScreenDlg::on_pushButton_cannel_clicked()
{
    this->reject();
}

BCMWindowScene *BCScreenDlg::GetWindowScene()
{
    // 构造场景对象
    BCMWindowScene *pWindowScene = new BCMWindowScene( m_pGroupScene );
    pWindowScene->SetWindowSceneID( ui->spinBox->value() );
    pWindowScene->SetWindowSceneName( ui->lineEdit->text() );
    pWindowScene->SetIsCycled( ui->checkBox_poll->isChecked() );

    m_pGroupScene->AddWindowScene( pWindowScene );

    return pWindowScene;
}
