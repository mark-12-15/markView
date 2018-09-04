#include "BCSettingMonitorDlg.h"

#include "type.h"

#include "monitorparser.h"
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"
BCSettingMonitorDlg::BCSettingMonitorDlg(QWidget *parent)
    :QDialog(parent),
    ui(new Ui::BCSettingMonitorDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("监视器设置"));
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));
    Monitor monitor;

    MonitorParser parser;
    parser.parse(monitor);

    for (int i = 0; i < monitor.vect.count(); i++) {
        MonitorInfo info = monitor.vect.at(i);

        if (info.position == LEFT) {
            ui->checkBox->setChecked(info.enable);
            ui->spinBox->setValue(info.countH);
            ui->spinBox_2->setValue(info.countV);
            ui->checkBox_3->setChecked(info.isSupportControl);
        }

        if (info.position == RIGHT) {
            ui->checkBox_2->setChecked(info.enable);
            ui->spinBox_3->setValue(info.countH);
            ui->spinBox_4->setValue(info.countV);
            ui->checkBox_4->setChecked(info.isSupportControl);
        }

        if (info.position == TOP) {
            ui->checkBox_5->setChecked(info.enable);
            ui->spinBox_5->setValue(info.countH);
            ui->spinBox_6->setValue(info.countV);
            ui->checkBox_6->setChecked(info.isSupportControl);
        }

        if (info.position == BOTTOM) {
            ui->checkBox_8->setChecked(info.enable);
            ui->spinBox_7->setValue(info.countH);
            ui->spinBox_8->setValue(info.countV);
            ui->checkBox_9->setChecked(info.isSupportControl);
        }
    }

    ui->checkBox_7->setChecked(monitor.customEnable);
    ui->spinBox_9->setValue(monitor.customCount);

    ui->pushButton->hide();

//    BCLocalServer *pLocalServer = BCLocalServer::Application();
//    pLocalServer->GetMonitorConfig();
}

BCSettingMonitorDlg::~BCSettingMonitorDlg()
{
    delete ui;
}

void BCSettingMonitorDlg::on_pushButton_3_clicked()
{
    this->close();
}

void BCSettingMonitorDlg::on_pushButton_2_clicked()
{

    Monitor monitor;

    MonitorParser parser;

    MonitorInfo info;

    info.position = LEFT;
    info.enable = ui->checkBox->isChecked();
    info.countH = ui->spinBox->value();
    info.countV = ui->spinBox_2->value();
    info.isSupportControl = ui->checkBox_3->isChecked();
    monitor.vect.append(info);

    info.position = RIGHT;
    info.enable = ui->checkBox_2->isChecked();
    info.countH = ui->spinBox_3->value();
    info.countV = ui->spinBox_4->value();
    info.isSupportControl = ui->checkBox_4->isChecked();
    monitor.vect.append(info);

    info.position = TOP;
    info.enable = ui->checkBox_5->isChecked();
    info.countH = ui->spinBox_5->value();
    info.countV = ui->spinBox_6->value();
    info.isSupportControl = ui->checkBox_6->isChecked();
    monitor.vect.append(info);

    info.position = BOTTOM;
    info.enable = ui->checkBox_8->isChecked();
    info.countH = ui->spinBox_7->value();
    info.countV = ui->spinBox_8->value();
    info.isSupportControl = ui->checkBox_9->isChecked();
    monitor.vect.append(info);


    monitor.customEnable = ui->checkBox_7->isChecked();
    monitor.customCount = ui->spinBox_9->value();
    parser.setMonitor(monitor);


//    BCLocalServer *pLocalServer = BCLocalServer::Application();
//    pLocalServer->SetMonitorConfig();

    this->close();
}

void BCSettingMonitorDlg::on_m_pSetLeftCommunicationBtn_clicked()
{
//    BCLocalServer *pLocalServer = BCLocalServer::Application();
//    pLocalServer->SetMonitorCommunicationConfig(0);
}

void BCSettingMonitorDlg::on_m_pSetRightCommunicationBtn_clicked()
{
//    BCLocalServer *pLocalServer = BCLocalServer::Application();
//    pLocalServer->SetMonitorCommunicationConfig(1);
}

void BCSettingMonitorDlg::on_m_pSetTopCommunicationBtn_clicked()
{
//    BCLocalServer *pLocalServer = BCLocalServer::Application();
//    pLocalServer->SetMonitorCommunicationConfig(2);
}

void BCSettingMonitorDlg::on_m_pSetBottomCommunicationBtn_clicked()
{
//    BCLocalServer *pLocalServer = BCLocalServer::Application();
//    pLocalServer->SetMonitorCommunicationConfig(3);
}
