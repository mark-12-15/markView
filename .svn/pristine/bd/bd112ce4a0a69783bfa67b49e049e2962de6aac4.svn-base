#include "BCPlanMapDlg.h"
#include "ui_BCPlanMapDlg.h"
#include <QFile>
#include <QFileDialog>
#include <QDomDocument>
#include "BCPlanMapGraphicsRectItem.h"
#include "BCPlanMapGraphicsView.h"
#include "BCPlanMapButtonGraphicsItem.h"
#include "../Common/BCCommon.h"

BCPlanMapDlg::BCPlanMapDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCPlanMapDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("预案地图"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    init();

    // test
    BCPlanMapGraphicsView *pMapView = dynamic_cast<BCPlanMapGraphicsView *>( ui->pMapView );
    if (NULL != pMapView) {
        pMapView->AddPlanMap( "../resource/image/map.bmp" );
    }
}

BCPlanMapDlg::~BCPlanMapDlg()
{
    delete ui;
}

void BCPlanMapDlg::on_pCancel_clicked()
{
    this->close();
}

void BCPlanMapDlg::init()
{
    // 初始化操作地图的四个按钮
    ui->pBtnZoomIn->setIconSize(QSize(24, 24));
    ui->pBtnZoomOut->setIconSize(QSize(24, 24));
    ui->pBtnZoomFitBest->setIconSize(QSize(24, 24));
    ui->pBtnZoomOriginal->setIconSize(QSize(24, 24));

    ui->pBtnZoomIn->setIcon( QIcon(BCCommon::g_qsApplicationDefaultStylePath + "/mapzoomin24.png") );
    ui->pBtnZoomOut->setIcon( QIcon(BCCommon::g_qsApplicationDefaultStylePath + "/mapzoomout24.png") );
    ui->pBtnZoomFitBest->setIcon( QIcon(BCCommon::g_qsApplicationDefaultStylePath + "/mapzoomfitbest24.png") );
    ui->pBtnZoomOriginal->setIcon( QIcon(BCCommon::g_qsApplicationDefaultStylePath + "/mapzoomoriginal24.png") );

    // 初始化预案窗口不显示header
    ui->pPlanTreeWidget->setHeaderHidden( true );
    BCCommon::SetSystemFont( ui->pPlanTreeWidget );
    QStringList lstSystemPlan = loadSystemPlan();
    for (int i = 0; i < lstSystemPlan.count(); i++) {
        QTreeWidgetItem *pItem = new QTreeWidgetItem();
        pItem->setText(0, lstSystemPlan.at(i+1));
        pItem->setData(1, 0, lstSystemPlan.at(i));

        ui->pPlanTreeWidget->addTopLevelItem( pItem );

        i++;
    }

    // 初始化地图上的按钮链表widget
    ui->pButtonTableWidget->setColumnCount( 3 );
    QStringList lst;
    lst << tr("序号") << tr("预案") << tr("坐标");
    ui->pButtonTableWidget->setHorizontalHeaderLabels(lst);
    QHeaderView *pButtonTableWidgetHeader = ui->pButtonTableWidget->horizontalHeader();
    if (NULL != pButtonTableWidgetHeader) {
        BCCommon::SetSystemFont( pButtonTableWidgetHeader );
    }

    ui->pButtonTableWidget->setColumnWidth(0, 50);
}

void BCPlanMapDlg::AddButton(BCPlanMapButtonGraphicsItem *pButton)
{
    if (NULL == pButton)
        return;

    int nRowCount = ui->pButtonTableWidget->rowCount();
    ui->pButtonTableWidget->setRowCount( nRowCount+1 );

    ui->pButtonTableWidget->setItem(nRowCount, 0, new QTableWidgetItem(QString()));
    ui->pButtonTableWidget->setItem(nRowCount, 1, new QTableWidgetItem( pButton->GetText() ));
    QTableWidgetItem *pPosItem = new QTableWidgetItem( QString() );
    ui->pButtonTableWidget->setItem(nRowCount, 2, pPosItem);
    pButton->SetTableWidgetItem( pPosItem );

    for (int i = 0; i < nRowCount+1; i++) {
        QTableWidgetItem *pItem = ui->pButtonTableWidget->item(i, 0);
        if (NULL == pItem)
            continue;

        pItem->setText( QString::number(i+1) );
    }
}

QStringList BCPlanMapDlg::loadSystemPlan()
{
    QStringList lstSystemPlan;

    QFile file( QString("../xml/BCPlanMap.xml") );
    if(!file.open(QIODevice::ReadOnly)){
        return lstSystemPlan;
    }

    // 将文件内容读到QDomDocument中
    QDomDocument doc;
    bool bLoadFile = doc.setContent(&file);
    file.close();

    if ( !bLoadFile )
        return lstSystemPlan;

    // 二级链表
    QDomElement docElem = doc.documentElement();
    QDomNodeList lstNodes = docElem.childNodes();

    for (int i = 0; i < lstNodes.count(); i++) {
        QDomNode nodePlan = lstNodes.at(i);
        if (nodePlan.nodeName() != "systemPlan")
            continue;

        if ( !nodePlan.isElement() )
            continue;

        QDomElement elePlan = nodePlan.toElement();
        lstSystemPlan.append( elePlan.attribute("id") );
        lstSystemPlan.append( elePlan.attribute("name") );
    }

    return lstSystemPlan;
}

void BCPlanMapDlg::on_pSelectMap_clicked()
{
    QFileDialog *dlg = new QFileDialog;
    if (dlg->exec()) {
        QStringList fileList = dlg->selectedFiles();

        BCPlanMapGraphicsView *pMapView = dynamic_cast<BCPlanMapGraphicsView *>( ui->pMapView );
        if (NULL != pMapView) {
            pMapView->AddPlanMap( fileList.at(0) );
        }
    }
}

void BCPlanMapDlg::on_pBtnZoomOut_clicked()
{
    BCPlanMapGraphicsView *pMapView = dynamic_cast<BCPlanMapGraphicsView *>( ui->pMapView );
    if (NULL != pMapView) {
        pMapView->ZoomOut();
    }
}

void BCPlanMapDlg::on_pBtnZoomIn_clicked()
{
    BCPlanMapGraphicsView *pMapView = dynamic_cast<BCPlanMapGraphicsView *>( ui->pMapView );
    if (NULL != pMapView) {
        pMapView->ZoomIn();
    }
}

void BCPlanMapDlg::on_pBtnZoomFitBest_clicked()
{
    BCPlanMapGraphicsView *pMapView = dynamic_cast<BCPlanMapGraphicsView *>( ui->pMapView );
    if (NULL != pMapView) {
        pMapView->ZoomFitBest();
    }
}

void BCPlanMapDlg::on_pBtnZoomOriginal_clicked()
{
    BCPlanMapGraphicsView *pMapView = dynamic_cast<BCPlanMapGraphicsView *>( ui->pMapView );
    if (NULL != pMapView) {
        pMapView->ZoomOriginal();
    }
}

void BCPlanMapDlg::on_pClearMap_clicked()
{
    BCPlanMapGraphicsView *pMapView = dynamic_cast<BCPlanMapGraphicsView *>( ui->pMapView );
    if (NULL != pMapView) {
        pMapView->ClearPlanMap();
    }
}
