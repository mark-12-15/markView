#include "BCSettingTaskPlanningDlg.h"
#include "ui_BCSettingTaskPlanningDlg.h"
#include <QMessageBox>
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"
#include "BCSettingTaskDetailDlg.h"

BCSettingTaskPlanningDlg::BCSettingTaskPlanningDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingTaskPlanningDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("任务系统"));
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));

    // set tablewidget config
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中
    ui->tableWidget->setShowGrid(false);//不显示内部的格子线条

    // set button icon
    ui->m_pAddBtn->setIcon(QIcon(BCCommon::g_qsApplicationDefaultStylePath+"/add16.png"));
    ui->m_pModifyBtn->setIcon(QIcon(BCCommon::g_qsApplicationDefaultStylePath+"/modify16.png"));
    ui->m_pRemoveBtn->setIcon(QIcon(BCCommon::g_qsApplicationDefaultStylePath+"/delete16.png"));
    ui->m_pClearBtn->setIcon(QIcon(BCCommon::g_qsApplicationDefaultStylePath+"/clear16.png"));

    Refresh();
}

BCSettingTaskPlanningDlg::~BCSettingTaskPlanningDlg()
{
    delete ui;
}

void BCSettingTaskPlanningDlg::Refresh()
{
    // 清空链表
    ui->tableWidget->clear();

    // 查询数据
    BCLocalServer *pServer = BCLocalServer::Application();
    m_lstTask = pServer->GetTaskPlanning();

    // 设置标题、行列数
    QStringList lstHeader;
    lstHeader << tr("ID") << tr("任务") << tr("时间") << tr("星期") << tr("创建时间");
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels( lstHeader );
    ui->tableWidget->setRowCount(m_lstTask.size());

    QMap<int, QString> mapTaskType;
    mapTaskType.insert(0, tr("开机"));
    mapTaskType.insert(1, tr("关机"));
    mapTaskType.insert(2, tr("打开轮巡"));
    mapTaskType.insert(3, tr("关闭轮巡"));
    mapTaskType.insert(4, tr("调用场景"));
    for(int i = 0; i < m_lstTask.count(); i++)
    {
        sTaskPlanning stask = m_lstTask.at( i );

        QString qsCycle = QString::null;
        if ( stask.cycle.contains(QString::number(1)) )
            qsCycle = tr("周一");
        if ( stask.cycle.contains(QString::number(2)) )
            qsCycle.append( qsCycle.isEmpty() ? tr("周二") : tr("、周二") );
        if ( stask.cycle.contains(QString::number(3)) )
            qsCycle.append( qsCycle.isEmpty() ? tr("周三") : tr("、周三") );
        if ( stask.cycle.contains(QString::number(4)) )
            qsCycle.append( qsCycle.isEmpty() ? tr("周四") : tr("、周四") );
        if ( stask.cycle.contains(QString::number(5)) )
            qsCycle.append( qsCycle.isEmpty() ? tr("周五") : tr("、周五") );
        if ( stask.cycle.contains(QString::number(6)) )
            qsCycle.append( qsCycle.isEmpty() ? tr("周六") : tr("、周六") );
        if ( stask.cycle.contains(QString::number(7)) )
            qsCycle.append( qsCycle.isEmpty() ? tr("周日") : tr("、周日") );

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem( QString::number(stask.id) ));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem( mapTaskType.value(stask.taskType)) );
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem( stask.time ) );
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem( qsCycle ) );
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem( stask.createTime ));
    }
}

void BCSettingTaskPlanningDlg::on_m_pAddBtn_clicked()
{
    BCSettingTaskDetailDlg *pDlg = new BCSettingTaskDetailDlg(0, this);
    pDlg->exec();
}

void BCSettingTaskPlanningDlg::on_m_pModifyBtn_clicked()
{
    int row = ui->tableWidget->currentRow();
    if ((row < 0) || (row > m_lstTask.count()-1))
        return;

    sTaskPlanning stask = m_lstTask.at( row );

    BCSettingTaskDetailDlg *pDlg = new BCSettingTaskDetailDlg(1, this, stask.id, stask.taskType, stask.time, stask.cycle, stask.roomID, stask.sceneID);
    pDlg->exec();
}

void BCSettingTaskPlanningDlg::on_m_pRemoveBtn_clicked()
{
    int row = ui->tableWidget->currentRow();
    if ((row < 0) || (row > m_lstTask.count()-1))
        return;

    sTaskPlanning stask = m_lstTask.at( row );

    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->RemoveTaskPlanning( stask.id );
    this->Refresh();

    MainWindow *pMainWindow = BCCommon::Application();
    pMainWindow->RefreshTaskPlanning();
}

void BCSettingTaskPlanningDlg::on_m_pClearBtn_clicked()
{
    // 弹出对话框询问
    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->ClearTaskPlanning();
    this->Refresh();

    MainWindow *pMainWindow = BCCommon::Application();
    pMainWindow->RefreshTaskPlanning();
}

void BCSettingTaskPlanningDlg::AddTask(int taskType, QString time, QString cycle, int roomid, int sceneid)
{
    sTaskPlanning stask;
    stask.id = -1;
    stask.taskType = taskType;
    stask.time = time;
    stask.cycle = cycle;
    stask.roomID = roomid;
    stask.sceneID = sceneid;
    stask.creatorID = 1;
    stask.createTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->AddTaskPlanning( stask );
    this->Refresh();

    MainWindow *pMainWindow = BCCommon::Application();
    pMainWindow->RefreshTaskPlanning();
}

void BCSettingTaskPlanningDlg::ModifyTask(int id, int taskType, QString time, QString cycle, int roomid, int sceneid)
{
    sTaskPlanning stask;
    stask.id = id;
    stask.taskType = taskType;
    stask.time = time;
    stask.cycle = cycle;
    stask.roomID = roomid;
    stask.sceneID = sceneid;
    stask.creatorID = 1;
    stask.createTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    BCLocalServer *pServer = BCLocalServer::Application();
    pServer->ModifyTaskPlanning( stask );
    this->Refresh();

    MainWindow *pMainWindow = BCCommon::Application();
    pMainWindow->RefreshTaskPlanning();
}
