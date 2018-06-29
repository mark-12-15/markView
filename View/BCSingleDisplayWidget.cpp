#include "BCSingleDisplayWidget.h"
#include "ui_BCSingleDisplayWidget.h"
#include "../Model/BCMDisplay.h"
#include "../Model/BCMGroupDisplay.h"
#include "../Model/BCMRoom.h"
#include "../Common/BCCommon.h"
#include "BCSingleDisplayVirtualWidget.h"
#include "../Setting/BCSettingSingleDisplaySwitchConfigDlg.h"
#include "../Setting/BCSettingRoomVirtualResolutionDlg.h"
#include "../Setting/BCSettingLEDResolutionDlg.h"
#include "BCSignalName.h"

BCSingleDisplayWidget::BCSingleDisplayWidget(BCMDisplay *pMDisplay, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCSingleDisplayWidget)
{
    ui->setupUi(this);

    m_pMDisplay = pMDisplay;
    m_nSegmentation = -1;

    // 房间类型如果是矩阵，则标签显示在下面中间位置，否则在左上角
    BCMGroupDisplay *pMGroupDisplay = pMDisplay->GetMGroupDisplay();
    if (NULL != pMGroupDisplay) {
        BCMRoom *pMRoom = pMGroupDisplay->GetRoom();
        if (NULL != pMRoom) {
            Qt::Alignment alignment = (4 == pMRoom->GetType()) ? (Qt::AlignHCenter | Qt::AlignBottom) : (Qt::AlignLeft | Qt::AlignTop);
            ui->m_pNameLabel->setAlignment( alignment );
        }
    }

    ui->m_pNameLabel->setText( m_pMDisplay->GetDisplayName() );

    // init singledisplayrect
    RefreshSegmentation( m_pMDisplay->GetSegmentation() );
}

BCSingleDisplayWidget::~BCSingleDisplayWidget()
{
    while ( !m_lstSingleDisplayRect.isEmpty() )
        delete m_lstSingleDisplayRect.takeFirst();

    delete ui;
}

QString BCSingleDisplayWidget::GetDisplayName()
{
    return m_pMDisplay->GetDisplayName();
}

void BCSingleDisplayWidget::RefreshSegmentation(int n)
{
    if (n == m_nSegmentation)
        return;

    // 1.赋值分割数
    m_nSegmentation = n;

    // 2.删除所有虚拟矩形
    while ( !m_lstSingleDisplayRect.isEmpty() )
        delete m_lstSingleDisplayRect.takeFirst();

    // 3.根据分割数确定行列数
    int r = 1;
    int c = 1;
    switch ( m_nSegmentation ) {
    case 1:
        r = 1;
        c = 1;
        break;
    case 4:
        r = 2;
        c = 2;
        break;
    case 6:
        r = 2;
        c = 3;
        break;
    case 8:
        r = 2;
        c = 4;
        break;
    case 9:
        r = 3;
        c = 3;
        break;
    case 12:
        r = 3;
        c = 4;
        break;
    default:
        r = 4;
        c = 4;
        break;
    }

    // 单个矩形的尺寸
    int nSingleRectWidth = this->size().width() / r;
    int nSingleRectHeight = this->size().height() / c;

    // 4.重新生成矩形
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            BCSingleDisplayVirtualWidget *pDisplayVirWidget = new BCSingleDisplayVirtualWidget(r, c, i, j, this);

            // 移动位置
            pDisplayVirWidget->move(nSingleRectWidth*pDisplayVirWidget->m_i, nSingleRectHeight*pDisplayVirWidget->m_j);

            // 可能出现不能整除的情况
            pDisplayVirWidget->resize(nSingleRectWidth, nSingleRectHeight);

            m_lstSingleDisplayRect.append( pDisplayVirWidget );
        }
    }
}

void BCSingleDisplayWidget::contextMenuEvent(QContextMenuEvent *e)
{
    // 构造菜单
    QMenu menu;
    BCCommon::SetSystemFont( &menu );

    QAction *pModifyNameAction = menu.addAction(QObject::tr("修改名称"));
    QAction *pSwtichOnAction = menu.addAction(QObject::tr("打开屏幕"));
    pSwtichOnAction->setChecked((1 == m_pMDisplay->IsSwitchOn()) ? true : false );
    QAction *pSwtichOffAction = menu.addAction(QObject::tr("关闭屏幕"));
    pSwtichOffAction->setChecked((0 == m_pMDisplay->IsSwitchOn()) ? true : false );
    QAction *pConfigAction = menu.addAction(QObject::tr("单屏指令配置"));
    QAction *pVirResolutionAction = NULL;
    QAction *pLEDResolutionAction = NULL;
    BCMRoom *pRoom = m_pMDisplay->GetMGroupDisplay()->GetRoom();
    MainWindow *pMainWindow = BCCommon::Application();
    if (pMainWindow->GetCurrentUser()->level < 2) {
        pVirResolutionAction = menu.addAction(QObject::tr("设置虚拟分辨率"));

        if (NULL != pRoom) {
            if (1 == pRoom->GetType()) {    // 只有LED显示菜单
                pLEDResolutionAction = menu.addAction(QObject::tr("LED规模设置"));
            }
        }
    }

    // 返回选择的action
    QAction *pSelectedAction = menu.exec( this->mapToGlobal(e->pos()) );
    if (NULL != pSelectedAction) {
        if (pSelectedAction == pModifyNameAction) {
            BCSignalName *pDlg = new BCSignalName(m_pMDisplay->GetDisplayName(), BCCommon::Application());
            if (pDlg->exec() == QDialog::Accepted) {
                m_pMDisplay->SetDisplayName(pDlg->m_str, true);
                ui->m_pNameLabel->setText( m_pMDisplay->GetDisplayName() );
            }
        }
        if (pSelectedAction == pSwtichOnAction) {
            m_pMDisplay->SetSwitchOn(1, true);
        }
        if (pSelectedAction == pSwtichOffAction) {
            m_pMDisplay->SetSwitchOn(0, true);
        }
        if (pSelectedAction == pConfigAction) {
            BCSettingSingleDisplaySwitchConfigDlg *pDlg = new BCSettingSingleDisplaySwitchConfigDlg(m_pMDisplay, this);
            pDlg->exec();
        }
        if (pSelectedAction == pVirResolutionAction) {
            BCSettingRoomVirtualResolutionDlg *pDlg = new BCSettingRoomVirtualResolutionDlg(m_pMDisplay->GetMGroupDisplay()->GetRoom(), this);
            pDlg->exec();
        }
        if (pSelectedAction == pLEDResolutionAction) {
            BCSettingLEDResolutionDlg *pDlg = new BCSettingLEDResolutionDlg(pRoom, this);
            pDlg->exec();
        }
    }

    e->accept();
}

void BCSingleDisplayWidget::resizeEvent(QResizeEvent *e)
{
    QSize displayVirSize = e->size();

    for (int i = 0; i < m_lstSingleDisplayRect.count(); i++) {
        BCSingleDisplayVirtualWidget *pDisplayVirWidget = m_lstSingleDisplayRect.at( i );

        // 单个矩形的尺寸
        int nSingleRectWidth = displayVirSize.width() / pDisplayVirWidget->m_row;
        int nSingleRectHeight = displayVirSize.height() / pDisplayVirWidget->m_col;

        // 移动位置
        pDisplayVirWidget->move(nSingleRectWidth*pDisplayVirWidget->m_i, nSingleRectHeight*pDisplayVirWidget->m_j);

        // 可能出现不能整除的情况
        pDisplayVirWidget->resize(nSingleRectWidth, nSingleRectHeight);
    }

    e->accept();
}

void BCSingleDisplayWidget::paintEvent(QPaintEvent */*e*/)
{
    QPainter painter(this);

    // 设置pen
    painter.setPen(QPen(Qt::black,1,Qt::SolidLine));
    // 绘制矩形
    painter.drawRect( rect() );
}
