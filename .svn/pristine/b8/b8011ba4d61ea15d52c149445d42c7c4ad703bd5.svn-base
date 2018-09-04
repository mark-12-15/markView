#include "BCSettingTaskDetailDlg.h"
#include "ui_BCSettingTaskDetailDlg.h"
#include <QMessageBox>
#include <QDebug>
#include "../Common/BCCommon.h"
#include "../Model/BCMRoom.h"
#include "../Model/BCMGroupScene.h"
#include "../Model/BCMWindowScene.h"
#include "BCSettingTaskPlanningDlg.h"

BCDateButton::BCDateButton(QWidget *parent)
    :QPushButton( parent )
{
    m_bSelected = false;

    connect(this, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
}

void BCDateButton::SetSelected(bool b)
{
    m_bSelected = b;

    QString qsIconPath = m_bSelected ? QString(BCCommon::g_qsApplicationDefaultStylePath+"/selected.jpg") : QString("");
    setIcon(QIcon(qsIconPath));
}

void BCDateButton::onClicked()
{
    SetSelected( !m_bSelected );
}

// -----------------------------------------------------------------------------------------------------------------------

BCSettingTaskDetailDlg::BCSettingTaskDetailDlg(int type, BCSettingTaskPlanningDlg *parent, int id, int taskType, QString time, QString cycle, int roomid, int sceneid) :
    QDialog(parent),
    ui(new Ui::BCSettingTaskDetailDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("任务明细"));
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));

    m_type = type;
    m_parent = parent;
    m_id = id;

    // init room combBox
    MainWindow *pMainWindow = BCCommon::Application();
    QList<BCMRoom *> lstRoom = pMainWindow->GetMRooms();
    for (int i = 0; i < lstRoom.count(); i++) {
        BCMRoom *pRoom = lstRoom.at( i );

        // 添加房间ID
        ui->m_pRoomCombBox->addItem( QString::number(pRoom->GetRoomID()) );

        // 添加场景ID
        QList<BCMGroupScene *> lstGroupScene = pRoom->GetGroupScenes();
        for (int j = 0; j < lstGroupScene.count(); j++) {
            BCMGroupScene *pGroupScene = lstGroupScene.at( j );
            QList<BCMWindowScene *> lstScene = pGroupScene->GetWindowScenes();
            for (int k = 0; k < lstScene.count(); k++) {
                BCMWindowScene *pScene = lstScene.at( k );

                ui->m_pSceneIDComboBox->addItem(pScene->GetWindowSceneName(), pScene->GetWindowSceneID());
            }
        }
    }

    // init task para
    ui->m_pTaskTypeCombBox->setCurrentIndex( taskType );
    ui->m_pTaskTimeEdit->setTime( QTime::fromString(time, "hh:mm") );
    ui->m_pMondayBtn->SetSelected(cycle.contains("1") ? true : false);
    ui->m_pTuesdayBtn->SetSelected(cycle.contains("2") ? true : false);
    ui->m_pWednesdayBtn->SetSelected(cycle.contains("3") ? true : false);
    ui->m_pThursdayBtn->SetSelected(cycle.contains("4") ? true : false);
    ui->m_pFridayBtn->SetSelected(cycle.contains("5") ? true : false);
    ui->m_pSaturdayBtn->SetSelected(cycle.contains("6") ? true : false);
    ui->m_pSundayBtn->SetSelected(cycle.contains("7") ? true : false);
    ui->m_pRoomCombBox->setCurrentIndex((-1 == roomid) ? 0 : ui->m_pRoomCombBox->findText(QString::number(roomid)));
    //ui->m_pSceneIDLineEdit->setText( QString::number(sceneid) );
    int nSceneIndex = ui->m_pSceneIDComboBox->findData( sceneid );
    ui->m_pSceneIDComboBox->setCurrentIndex((-1 == nSceneIndex) ? 0 : nSceneIndex);

    on_m_pTaskTypeCombBox_currentIndexChanged( taskType );
}

BCSettingTaskDetailDlg::~BCSettingTaskDetailDlg()
{
    delete ui;
}

void BCSettingTaskDetailDlg::on_m_pTaskTypeCombBox_currentIndexChanged(int index)
{
    ui->m_pSceneLable->setVisible((4 != index) ? false : true);
    ui->m_pSceneIDComboBox->setVisible((4 != index) ? false : true);
}

void BCSettingTaskDetailDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingTaskDetailDlg::on_m_pOKBtn_clicked()
{
    int taskType = ui->m_pTaskTypeCombBox->currentIndex();
    QString time = ui->m_pTaskTimeEdit->time().toString("hh:mm");
    if ("00:00" == time) {
        QMessageBox::warning(this,
                             tr("警告"),
                             tr("请设置执行时间!"),
                             QMessageBox::Ok);
        return;
    }
    QString cycle;
    cycle.append(ui->m_pMondayBtn->m_bSelected ? "1" : "");
    cycle.append(ui->m_pTuesdayBtn->m_bSelected ? "2" : "");
    cycle.append(ui->m_pWednesdayBtn->m_bSelected ? "3" : "");
    cycle.append(ui->m_pThursdayBtn->m_bSelected ? "4" : "");
    cycle.append(ui->m_pFridayBtn->m_bSelected ? "5" : "");
    cycle.append(ui->m_pSaturdayBtn->m_bSelected ? "6" : "");
    cycle.append(ui->m_pSundayBtn->m_bSelected ? "7" : "");
    if ( cycle.isEmpty() ) {
        QMessageBox::warning(this,
                             tr("警告"),
                             tr("请设置轮巡周期!"),
                             QMessageBox::Ok);
        return;
    }

    int roomid = ui->m_pRoomCombBox->currentText().toInt();
    //int sceneid = ui->m_pSceneIDLineEdit->text().toInt();
    int sceneid = ui->m_pSceneIDComboBox->currentData().toInt();

    if (m_type == 0)
        m_parent->AddTask(taskType, time, cycle, roomid, sceneid);
    if (m_type == 1)
        m_parent->ModifyTask(m_id, taskType, time, cycle, roomid, sceneid);

    this->accept();
}
