#include "BCSettingMatrixDlg.h"
#include "ui_BCSettingMatrixDlg.h"
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"

BCSettingMatrixDlg::BCSettingMatrixDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingMatrixDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("矩阵设置"));
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));

    Init();
}

BCSettingMatrixDlg::~BCSettingMatrixDlg()
{
    delete ui;
}

void BCSettingMatrixDlg::Init()
{
    // 设置标题和图标
    this->setWindowTitle(tr("矩阵设置"));
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));

    // 连接信号槽
    connect(ui->m_pVGAMatrixCheckBox, SIGNAL(stateChanged(int)), this, SLOT(onStateChangedOfVGA(int)));
    connect(ui->m_pVideoMatrixCheckBox, SIGNAL(stateChanged(int)), this, SLOT(onStateChangedOfVideo(int)));
    connect(ui->m_pDVIMatrixCheckBox, SIGNAL(stateChanged(int)), this, SLOT(onStateChangedOfDVI(int)));
    connect(ui->m_pHDMIMatrixCheckBox, SIGNAL(stateChanged(int)), this, SLOT(onStateChangedOfHDMI(int)));
    connect(ui->m_pSDIMatrixCheckBox, SIGNAL(stateChanged(int)), this, SLOT(onStateChangedOfSDI(int)));
    connect(ui->m_pAudioMatrixCheckBox, SIGNAL(stateChanged(int)), this, SLOT(onStateChangedOfAudio(int)));

//    BCLocalServer *pServer = BCLocalServer::Application();
//    BSMatrix *pMatrix = pServer->GetMatrixData();
//    if (NULL == pMatrix)
//        return;

//    ui->m_pVGAMatrixCheckBox->setChecked( (1==pMatrix->isVGAMatrix) ? true : false );
//    ui->m_pInputPortCountOfVGASpinBox->setValue( pMatrix->inputPortCountOfVGA );
//    ui->m_pMontageAddOfVGASpinBox->setValue( pMatrix->montageAddOfVGA );
//    ui->m_pCommunicationParaVGALineEdit->setText( QString::fromLocal8Bit(pMatrix->communicationParaVGA) );
//    onStateChangedOfVGA( pMatrix->isVGAMatrix );

//    ui->m_pVideoMatrixCheckBox->setChecked( (1==pMatrix->isVideoMatrix) ? true : false );
//    ui->m_pInputPortCountOfVideoSpinBox->setValue( pMatrix->inputPortCountOfVideo );
//    ui->m_pMontageAddOfVideoSpinBox->setValue( pMatrix->montageAddOfVideo );
//    ui->m_pCommunicationParaVideoLineEdit->setText( QString::fromLocal8Bit(pMatrix->communicationParaVideo) );
//    onStateChangedOfVideo( pMatrix->isVideoMatrix );

//    ui->m_pDVIMatrixCheckBox->setChecked( (1==pMatrix->isDVIMatrix) ? true : false );
//    ui->m_pInputPortCountOfDVISpinBox->setValue( pMatrix->inputPortCountOfDVI );
//    ui->m_pMontageAddOfDVISpinBox->setValue( pMatrix->montageAddOfDVI );
//    ui->m_pCommunicationParaDVILineEdit->setText( QString::fromLocal8Bit(pMatrix->communicationParaDVI) );
//    onStateChangedOfDVI( pMatrix->isDVIMatrix );

//    ui->m_pHDMIMatrixCheckBox->setChecked( (1==pMatrix->isHDMIMatrix) ? true : false );
//    ui->m_pInputPortCountOfHDMISpinBox->setValue( pMatrix->inputPortCountOfHDMI );
//    ui->m_pMontageAddOfHDMISpinBox->setValue( pMatrix->montageAddOfHDMI );
//    ui->m_pCommunicationParaHDMILineEdit->setText( QString::fromLocal8Bit(pMatrix->communicationParaHDMI) );
//    onStateChangedOfHDMI( pMatrix->isHDMIMatrix );

//    ui->m_pSDIMatrixCheckBox->setChecked( (1==pMatrix->isSDIMatrix) ? true : false );
//    ui->m_pInputPortCountOfSDISpinBox->setValue( pMatrix->inputPortCountOfSDI );
//    ui->m_pMontageAddOfSDISpinBox->setValue( pMatrix->montageAddOfSDI );
//    ui->m_pCommunicationParaSDILineEdit->setText( QString::fromLocal8Bit(pMatrix->communicationParaSDI) );
//    onStateChangedOfSDI( pMatrix->isSDIMatrix );

//    ui->m_pAudioMatrixCheckBox->setChecked( (1==pMatrix->isAudioMatrix) ? true : false );
//    ui->m_pInputPortCountOfAudioSpinBox->setValue( pMatrix->inputPortCountOfAudio );
//    ui->m_pMontageAddOfAudioSpinBox->setValue( pMatrix->montageAddOfAudio );
//    ui->m_pCommunicationParaAudioLineEdit->setText( QString::fromLocal8Bit(pMatrix->communicationParaAudio) );
//    onStateChangedOfAudio( pMatrix->isAudioMatrix );
}

void BCSettingMatrixDlg::onStateChangedOfVGA(int s)
{
    bool bEnabled = (0 == s) ? false : true;

    ui->m_pInputPortCountOfVGASpinBox->setEnabled( bEnabled );
    ui->m_pMontageAddOfVGASpinBox->setEnabled( bEnabled );
    ui->m_pCommunicationParaVGALineEdit->setEnabled( bEnabled );
    ui->m_pVGASetBtn->setEnabled( bEnabled );
    ui->m_pVGAPreSetBtn->setEnabled( bEnabled );
}

void BCSettingMatrixDlg::onStateChangedOfVideo(int s)
{
    bool bEnabled = (0 == s) ? false : true;

    ui->m_pInputPortCountOfVideoSpinBox->setEnabled( bEnabled );
    ui->m_pMontageAddOfVideoSpinBox->setEnabled( bEnabled );
    ui->m_pCommunicationParaVideoLineEdit->setEnabled( bEnabled );
    ui->m_pVideoSetBtn->setEnabled( bEnabled );
    ui->m_pVideoPreSetBtn->setEnabled( bEnabled );
}

void BCSettingMatrixDlg::onStateChangedOfDVI(int s)
{
    bool bEnabled = (0 == s) ? false : true;

    ui->m_pInputPortCountOfDVISpinBox->setEnabled( bEnabled );
    ui->m_pMontageAddOfDVISpinBox->setEnabled( bEnabled );
    ui->m_pCommunicationParaDVILineEdit->setEnabled( bEnabled );
    ui->m_pDVISetBtn->setEnabled( bEnabled );
    ui->m_pDVIPreSetBtn->setEnabled( bEnabled );
}

void BCSettingMatrixDlg::onStateChangedOfHDMI(int s)
{
    bool bEnabled = (0 == s) ? false : true;

    ui->m_pInputPortCountOfHDMISpinBox->setEnabled( bEnabled );
    ui->m_pMontageAddOfHDMISpinBox->setEnabled( bEnabled );
    ui->m_pCommunicationParaHDMILineEdit->setEnabled( bEnabled );
    ui->m_pHDMISetBtn->setEnabled( bEnabled );
    ui->m_pHDMIPreSetBtn->setEnabled( bEnabled );
}

void BCSettingMatrixDlg::onStateChangedOfSDI(int s)
{
    bool bEnabled = (0 == s) ? false : true;

    ui->m_pInputPortCountOfSDISpinBox->setEnabled( bEnabled );
    ui->m_pMontageAddOfSDISpinBox->setEnabled( bEnabled );
    ui->m_pCommunicationParaSDILineEdit->setEnabled( bEnabled );
    ui->m_pSDISetBtn->setEnabled( bEnabled );
    ui->m_pSDIPreSetBtn->setEnabled( bEnabled );
}

void BCSettingMatrixDlg::onStateChangedOfAudio(int s)
{
    bool bEnabled = (0 == s) ? false : true;

    ui->m_pInputPortCountOfAudioSpinBox->setEnabled( bEnabled );
    ui->m_pMontageAddOfAudioSpinBox->setEnabled( bEnabled );
    ui->m_pCommunicationParaAudioLineEdit->setEnabled( bEnabled );
    ui->m_pAudioSetBtn->setEnabled( bEnabled );
    ui->m_pAudioPreSetBtn->setEnabled( bEnabled );
}

void BCSettingMatrixDlg::on_m_pCancelBtn_clicked()
{
    this->close();
}

void BCSettingMatrixDlg::on_m_pOkBtn_clicked()
{
    this->close();
}

void BCSettingMatrixDlg::on_m_pVGASetBtn_clicked()
{
//    BCLocalServer *pServer = BCLocalServer::Application();
//    pServer->SetMatrixConfig( 0 );
}

void BCSettingMatrixDlg::on_m_pVideoSetBtn_clicked()
{
//    BCLocalServer *pServer = BCLocalServer::Application();
//    pServer->SetMatrixConfig( 1 );
}

void BCSettingMatrixDlg::on_m_pDVISetBtn_clicked()
{
//    BCLocalServer *pServer = BCLocalServer::Application();
//    pServer->SetMatrixConfig( 2 );
}

void BCSettingMatrixDlg::on_m_pHDMISetBtn_clicked()
{
//    BCLocalServer *pServer = BCLocalServer::Application();
//    pServer->SetMatrixConfig( 3 );
}

void BCSettingMatrixDlg::on_m_pSDISetBtn_clicked()
{
//    BCLocalServer *pServer = BCLocalServer::Application();
//    pServer->SetMatrixConfig( 4 );
}

void BCSettingMatrixDlg::on_m_pAudioSetBtn_clicked()
{
//    BCLocalServer *pServer = BCLocalServer::Application();
//    pServer->SetMatrixConfig( 5 );
}

void BCSettingMatrixDlg::on_m_pVGAPreSetBtn_clicked()
{
//    BCLocalServer *pServer = BCLocalServer::Application();
//    pServer->SetPreMatrixConfig( 0 );
}

void BCSettingMatrixDlg::on_m_pVideoPreSetBtn_clicked()
{
//    BCLocalServer *pServer = BCLocalServer::Application();
//    pServer->SetPreMatrixConfig( 1 );
}

void BCSettingMatrixDlg::on_m_pDVIPreSetBtn_clicked()
{
//    BCLocalServer *pServer = BCLocalServer::Application();
//    pServer->SetPreMatrixConfig( 2 );
}

void BCSettingMatrixDlg::on_m_pHDMIPreSetBtn_clicked()
{
//    BCLocalServer *pServer = BCLocalServer::Application();
//    pServer->SetPreMatrixConfig( 3 );
}

void BCSettingMatrixDlg::on_m_pSDIPreSetBtn_clicked()
{
//    BCLocalServer *pServer = BCLocalServer::Application();
//    pServer->SetPreMatrixConfig( 4 );
}

void BCSettingMatrixDlg::on_m_pAudioPreSetBtn_clicked()
{
//    BCLocalServer *pServer = BCLocalServer::Application();
//    pServer->SetPreMatrixConfig( 5 );
}
