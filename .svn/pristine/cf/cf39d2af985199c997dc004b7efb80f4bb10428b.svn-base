#include "BCSettingLEDResolutionDlg.h"
#include "ui_BCSettingLEDResolutionDlg.h"
#include "../View/BCTextDisplayItem.h"
#include "../Common/BCCommon.h"
#include <QMessageBox>
#include "../Common/BCLocalServer.h"
#include "BCSettingDeviceFormatDlg.h"
#include "../Model/BCMRoom.h"
#include "../Model/BCMGroupDisplay.h"
#include "../Model/BCMDisplay.h"

// 显示的单屏
class BCSettingLEDResolutionSingleDisplay : public QGraphicsRectItem
{
public:
    BCSettingLEDResolutionSingleDisplay(BCMDisplay *pDisplay, int arrX, int arrY, int i, int j, QGraphicsItem *parent =NULL);
    ~BCSettingLEDResolutionSingleDisplay();

    void Refresh(); // 刷新大小

    void SetHighLight(bool b);
    bool IsHighLight();

    void SetDisplayWidth(int w);
    void SetDisplayHeight(int h);

    int     m_id;
    int     m_resolutionX;
    int     m_resolutionY;

    int     m_arrX;
    int     m_arrY;
    int     m_i;            // 屏组中的位置
    int     m_j;

protected:
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget*/);

    QString m_text;

    bool    m_bHighLight;   // 是否高亮
    BCMDisplay *m_pDisplay;
};

BCSettingLEDResolutionSingleDisplay::BCSettingLEDResolutionSingleDisplay(BCMDisplay *pDisplay, int arrX, int arrY, int i, int j, QGraphicsItem *parent)
    :QGraphicsRectItem(parent)
{
    m_pDisplay = pDisplay;

    m_bHighLight = false;

    m_arrX = arrX;
    m_arrY = arrY;
    m_i = i;
    m_j = j;

    m_id = m_pDisplay->GetDisplayID();
    m_resolutionX = m_pDisplay->GetLEDResolution().width();
    m_resolutionY = m_pDisplay->GetLEDResolution().height();
    m_text = QString("%1*%2").arg(m_resolutionX).arg(m_resolutionY);
    this->update();
}

BCSettingLEDResolutionSingleDisplay::~BCSettingLEDResolutionSingleDisplay()
{

}

void BCSettingLEDResolutionSingleDisplay::Refresh()
{
    QRectF rect = this->scene()->sceneRect();
    double dSingleDisplayWidth = 1.0 * rect.width() / m_arrX;
    double dSingleDisplayHeight = 1.0 * rect.height() / m_arrY;

    // 设置矩形大小
    setRect(m_j*dSingleDisplayWidth, m_i*dSingleDisplayHeight, dSingleDisplayWidth, dSingleDisplayHeight);
    this->update();
}

void BCSettingLEDResolutionSingleDisplay::SetHighLight(bool b)
{
    m_bHighLight = b;
    this->update();
}

bool BCSettingLEDResolutionSingleDisplay::IsHighLight()
{
    return m_bHighLight;
}

void BCSettingLEDResolutionSingleDisplay::SetDisplayWidth(int w)
{
    m_resolutionX = w;
    m_text = QString("%1*%2").arg(m_resolutionX).arg(m_resolutionY);
    this->update();
}

void BCSettingLEDResolutionSingleDisplay::SetDisplayHeight(int h)
{
    m_resolutionY = h;
    m_text = QString("%1*%2").arg(m_resolutionX).arg(m_resolutionY);
    this->update();
}

void BCSettingLEDResolutionSingleDisplay::paint(QPainter * painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget*/)
{
    painter->setPen(QPen(QBrush(QColor(BCCommon::g_nSingleDisplayLineColorR,
                                       BCCommon::g_nSingleDisplayLineColorG,
                                       BCCommon::g_nSingleDisplayLineColorB,
                                       BCCommon::g_nSingleDisplayLineColorA)),
                         BCCommon::g_nSingleDisplayLineWidth,
                         Qt::PenStyle(BCCommon::g_nSingleDisplayLineStyle)));

    painter->setBrush(QBrush(QColor(BCCommon::g_nSingleDisplayFillColorR,
                                    BCCommon::g_nSingleDisplayFillColorG,
                                    BCCommon::g_nSingleDisplayFillColorB,
                                    m_bHighLight ? BCCommon::g_nSingleDisplayFillColorA : 80)));

    painter->drawRoundedRect(rect(), BCCommon::g_nSingleDisplayRectRadius, BCCommon::g_nSingleDisplayRectRadius);

    painter->drawText(rect(), m_text);
}

// -------------------------------------------------------------------------------------------------------

BCSettingLEDResolutionView::BCSettingLEDResolutionView(QWidget *parent)
    :QGraphicsView(parent)
{
    m_pDlg = NULL;

    m_pScene = new QGraphicsScene( this );
    this->setScene( m_pScene );

    // 每次初始化重新定义scene尺寸
    m_pScene->setSceneRect( 0.0, 0.0, this->rect().width(), this->rect().height() );

    m_bPress = false;
    m_x = 0.0;
    m_y = 0.0;

    m_arrX = 1;
    m_arrY = 1;
}

BCSettingLEDResolutionView::~BCSettingLEDResolutionView()
{
    delete m_pScene;
    m_pScene = NULL;
}

void BCSettingLEDResolutionView::Init(BCSettingLEDResolutionDlg *pDlg)
{
    m_pDlg = pDlg;
    m_id = pDlg->m_pRoom->GetRoomID();
    BCMGroupDisplay *pGroupDisplay = pDlg->m_pRoom->GetGroupDisplay( m_id );
    m_arrX = pGroupDisplay->GetArraySize( false ).width();
    m_arrY = pGroupDisplay->GetArraySize( false ).height();

    for (int i = 0; i < m_arrY; i++) {
        for (int j = 0; j < m_arrX; j++) {
            int displayid = j+m_arrX*i;
            BCMDisplay *pDisplay = pGroupDisplay->GetDisplay( displayid );
            if (NULL == pDisplay)
                continue;

            BCSettingLEDResolutionSingleDisplay *pItem = new BCSettingLEDResolutionSingleDisplay(pDisplay, m_arrX, m_arrY, i, j);
            m_pScene->addItem( pItem );

            // 刷新矩形区域
            pItem->Refresh();
        }
    }
}

void BCSettingLEDResolutionView::resizeEvent(QResizeEvent * event)
{
    QSize size = event->size();
    m_pScene->setSceneRect(0.0, 0.0, size.width(), size.height());

    QList<QGraphicsItem *> lst = m_pScene->items();
    for (int i = 0; i < lst.count(); i++) {
        BCSettingLEDResolutionSingleDisplay *pItem = dynamic_cast<BCSettingLEDResolutionSingleDisplay *>( lst.at(i) );
        if (NULL == pItem)
            continue;

        pItem->Refresh();
    }
}

// 鼠标事件选中单个显示器
void BCSettingLEDResolutionView::mousePressEvent(QMouseEvent *e)
{
    if(e->button()== Qt::LeftButton){
        m_bPress = true;

        // 记录点击的坐标
        m_x = e->pos().x();
        m_y = e->pos().y();

        HighLight(QPoint(m_x, m_y));
    }
}

void BCSettingLEDResolutionView::mouseMoveEvent(QMouseEvent *e)
{
    if (m_bPress) {
        double x = (m_x < e->pos().x()) ? m_x : e->pos().x();
        double y = (m_y < e->pos().y()) ? m_y : e->pos().y();
        double w = qAbs(m_x - e->pos().x());
        double h = qAbs(m_y - e->pos().y());

        HighLight(QRect(x, y, w, h));
    }
}

void BCSettingLEDResolutionView::mouseReleaseEvent(QMouseEvent */*e*/)
{
    m_bPress = false;
}

void BCSettingLEDResolutionView::HighLight(QPoint pt)
{
    ClearHighLight();

    QPointF ptScene = this->mapToScene( pt );
    QList<QGraphicsItem *> lst = m_pScene->items( ptScene );
    QListIterator<QGraphicsItem *> it( lst );
    while (it.hasNext()) {
        BCSettingLEDResolutionSingleDisplay *pItem = dynamic_cast<BCSettingLEDResolutionSingleDisplay *>( it.next() );
        if (NULL == pItem)
            continue;

        pItem->SetHighLight( true );
    }
}

void BCSettingLEDResolutionView::HighLight(QRect rect)
{
    ClearHighLight();

    QPointF lt = this->mapToScene(rect.left(), rect.top());
    QPointF rb = this->mapToScene(rect.right(), rect.bottom());

    bool bIsLine = false;
    QPolygonF polygon;
    if ((qAbs(lt.x()-rb.x()) < BCCommon::g_dPermissionError) ||
            (qAbs(lt.y()-rb.y()) < BCCommon::g_dPermissionError)) {
        bIsLine = true;

        polygon << lt << rb;
    }
    QList<QGraphicsItem *> lst = m_pScene->items( bIsLine ? polygon : QRectF(lt.x(), lt.y(), rb.x()-lt.x(), rb.y()-lt.y()) );
    QListIterator<QGraphicsItem *> it( lst );
    while (it.hasNext()) {
        BCSettingLEDResolutionSingleDisplay *pItem = dynamic_cast<BCSettingLEDResolutionSingleDisplay *>( it.next() );
        if (NULL == pItem)
            continue;

        pItem->SetHighLight( true );
    }
}

void BCSettingLEDResolutionView::ClearHighLight()
{
    QList<QGraphicsItem *> lst = m_pScene->items();
    QListIterator<QGraphicsItem *> it( lst );
    while (it.hasNext()) {
        BCSettingLEDResolutionSingleDisplay *pItem = dynamic_cast<BCSettingLEDResolutionSingleDisplay *>( it.next() );
        if (NULL == pItem)
            continue;

        pItem->SetHighLight( false );
    }
}

bool BCSettingLEDResolutionView::IsGroupDisplayValid()
{
    bool bValid = true;

    QList<QGraphicsItem *> lst = m_pScene->items();
    QListIterator<QGraphicsItem *> it( lst );
    while (it.hasNext()) {
        BCSettingLEDResolutionSingleDisplay *pItem = dynamic_cast<BCSettingLEDResolutionSingleDisplay *>( it.next() );
        if (NULL == pItem)
            continue;

        if (pItem->m_resolutionX > 0 && pItem->m_resolutionY > 0)
            continue;

        bValid = false;
        break;
    }

    return bValid;
}

void BCSettingLEDResolutionView::SendCommand()
{
    BCLocalServer *pServer = BCLocalServer::Application();

    // 屏组单独计算百分比
    int nBaseValue = 1;
    m_pDlg->SetCommandProgressValue( nBaseValue );

    QList<QGraphicsItem *> lst = m_pScene->items();

    // 设置总尺寸
    int width = 0;
    int height = 0;
    int resoluX = 0;
    int resoluY = 0;
    double dOffsetValue = 15.0 / lst.count();

    for (int i = 0; i < lst.count(); i++) {
        BCSettingLEDResolutionSingleDisplay *pItem = dynamic_cast<BCSettingLEDResolutionSingleDisplay *>( lst.at(i) );
        if (NULL == pItem)
            continue;

        width += pItem->m_resolutionX;
        height += pItem->m_resolutionY;

        m_pDlg->SetCommandProgressValue( nBaseValue += dOffsetValue );
    }

    resoluX = width / (m_arrX*m_arrY);
    resoluY = height / (m_arrX*m_arrY);

    m_pDlg->SetCommandProgressValue( nBaseValue += 3 );
    //pServer->UpdateRoomFormat(m_id, 1, m_arrX, m_arrY, resoluX, resoluY);
    m_pDlg->SetCommandProgressValue( nBaseValue += 2 );
    QThread::msleep( 200 );

    // 单屏单独计算百分比
    nBaseValue = 20;
    dOffsetValue = 80.0 / m_arrX*m_arrY;

    m_pDlg->SetCommandProgressValue( nBaseValue );

    // 系统分辨率
    QSizeF sysResolution = m_pDlg->m_pRoom->GetWallSize( false );
    int sysResX = sysResolution.width() / m_arrX;
    int sysResY = sysResolution.height() / m_arrY;

    // 设置分屏尺寸
    QList<int> lstLEDResolution;
    QListIterator<QGraphicsItem *> it( lst );
    it.toBack();    // 倒序循环
    while (it.hasPrevious()) {
        BCSettingLEDResolutionSingleDisplay *pItem = dynamic_cast<BCSettingLEDResolutionSingleDisplay *>( it.previous() );
        if (NULL == pItem)
            continue;

        lstLEDResolution << pItem->m_id << pItem->m_resolutionX << pItem->m_resolutionY;

        // 需要找到所有左上角的单屏确定尺寸
        int nStartX = 0;
        int nStartY = 0;
        for (int i = 0; i < lst.count(); i++) {
            BCSettingLEDResolutionSingleDisplay *pLeftTopItem = dynamic_cast<BCSettingLEDResolutionSingleDisplay *>( lst.at(i) );
            if (NULL == pLeftTopItem)
                continue;

            // 1.如果x小于，y等于，只增加x方向
            if ((pLeftTopItem->m_i < pItem->m_i) && (pLeftTopItem->m_j == pItem->m_j)) {
                nStartY += pLeftTopItem->m_resolutionY;
            }

            // 2.如果y小于，x等于，只增加y方向
            if ((pLeftTopItem->m_i == pItem->m_i) && (pLeftTopItem->m_j < pItem->m_j)) {
                nStartX += pLeftTopItem->m_resolutionX;
            }
        }

        if ((0 == nStartX) && (0 == nStartY)) {
            pServer->Setxy(m_id, pItem->m_i*pItem->m_arrX+pItem->m_j, 0, 0, sysResX, sysResY);
        } else {
            pServer->Setxy(m_id, pItem->m_i*pItem->m_arrX+pItem->m_j, nStartX, nStartY, nStartX + sysResX, nStartY + sysResY);
        }
        QThread::msleep( 100 );

        m_pDlg->SetCommandProgressValue( nBaseValue += dOffsetValue );
    }

    m_pDlg->SetCommandProgressValue( 100 );

    // 更新单屏的LED尺寸
    pServer->UpdateRoomLEDSize(m_pDlg->m_pRoom->GetRoomID(), lstLEDResolution);

    // 计算并更改虚拟屏的尺寸
    BCMGroupDisplay *pGroupDisplay = m_pDlg->m_pRoom->GetGroupDisplay( m_pDlg->m_pRoom->GetRoomID() );
    if (NULL != pGroupDisplay) {
        pServer->UpdateRoomVirSize(m_pDlg->m_pRoom->GetRoomID(), 1, resoluX*m_arrX, resoluY*m_arrY,
                                   pGroupDisplay->IsUseVirArraySize(), pGroupDisplay->GetArraySize().width(), pGroupDisplay->GetArraySize().height());
    }
}

void BCSettingLEDResolutionView::SetSingleDisplayResolutionX(int x)
{
    QList<QGraphicsItem *> lst = m_pScene->items();
    QListIterator<QGraphicsItem *> it( lst );
    while (it.hasNext()) {
        BCSettingLEDResolutionSingleDisplay *pItem = dynamic_cast<BCSettingLEDResolutionSingleDisplay *>( it.next() );
        if (NULL == pItem)
            continue;

        if ( !pItem->IsHighLight() )
            continue;

        pItem->SetDisplayWidth( x );
    }
}

void BCSettingLEDResolutionView::SetSingleDisplayResolutionY(int y)
{
    QList<QGraphicsItem *> lst = m_pScene->items();
    QListIterator<QGraphicsItem *> it( lst );
    while (it.hasNext()) {
        BCSettingLEDResolutionSingleDisplay *pItem = dynamic_cast<BCSettingLEDResolutionSingleDisplay *>( it.next() );
        if (NULL == pItem)
            continue;

        if ( !pItem->IsHighLight() )
            continue;

        pItem->SetDisplayHeight( y );
    }
}

void BCSettingLEDResolutionView::SetBatchDisplayResolution(int stanX, int stanY, int noStanX, int noStanY, int noStanPos)
{
    QList<QGraphicsItem *> lst = m_pScene->items();
    QListIterator<QGraphicsItem *> it( lst );
    while (it.hasNext()) {
        BCSettingLEDResolutionSingleDisplay *pItem = dynamic_cast<BCSettingLEDResolutionSingleDisplay *>( it.next() );
        if (NULL == pItem)
            continue;

        // 判断非标准位置
        int x = stanX;
        int y = stanY;
        switch ( noStanPos ) {
        case 0: // 左上
            x = (pItem->m_j == 0) ? noStanX : stanX;
            y = (pItem->m_i == 0) ? noStanY : stanY;
            break;
        case 1: // 左下
            x = (pItem->m_j == 0) ? noStanX : stanX;
            y = (pItem->m_i == (pItem->m_arrY-1)) ? noStanY : stanY;
            break;
        case 2: // 右上
            x = (pItem->m_j == (pItem->m_arrX-1)) ? noStanX : stanX;
            y = (pItem->m_i == 0) ? noStanY : stanY;
            break;
        case 3: // 右下
            x = (pItem->m_j == (pItem->m_arrX-1)) ? noStanX : stanX;
            y = (pItem->m_i == (pItem->m_arrY-1)) ? noStanY : stanY;
            break;
        default:
            break;
        }

        //pItem->SetDisplayText(QString("%1*%2").arg(x).arg(y));
    }
}

// -------------------------------------------------------------------------------------------------------

BCSettingLEDResolutionDlg::BCSettingLEDResolutionDlg(BCMRoom *pRoom, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingLEDResolutionDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("LED规模设置"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    // 隐藏进度条
    ui->m_pCmdProgressBar->setVisible( false );
    // 隐藏
    ui->groupBox_2->setVisible( false );

    m_pRoom = pRoom;
    BCMGroupDisplay *pGroupDisplay = m_pRoom->GetGroupDisplay( m_pRoom->GetRoomID() );
    if (NULL != pGroupDisplay) {
        ui->m_pGraphicsView->Init( this );
    }
    SetCommandProgressValue( 0 );
}

BCSettingLEDResolutionDlg::~BCSettingLEDResolutionDlg()
{
    delete ui;
}

void BCSettingLEDResolutionDlg::on_m_pBatchSetBtn_clicked()
{
    ui->groupBox_2->setVisible( !ui->groupBox_2->isVisible() );
    ui->m_pBatchSetBtn->setText(ui->groupBox_2->isVisible() ? "<<" : ">>");
}

void BCSettingLEDResolutionDlg::SetCommandProgressValue(int value)
{
    ui->m_pCmdProgressBar->setValue( value );
}

// 批量的应用按钮
void BCSettingLEDResolutionDlg::on_m_pBatchApplyBtn_clicked()
{
    int nNoStanX = ui->m_pBatchNoStandXLineEdit->text().toInt();
    int nNoStanY = ui->m_pBatchNoStandYLineEdit->text().toInt();
    int nStanX = ui->m_pBatchStandXLineEdit->text().toInt();
    int nStanY = ui->m_pBatchStandYLineEdit->text().toInt();
    int nNoStanPos = ui->m_pBatchNoStandPosCombox->currentIndex();

    // 数据不合法则返回
    if ((nNoStanX <= 0) || (nNoStanY <= 0) || (nStanX <= 0) || (nStanY <= 0))
        return;

    ui->m_pGraphicsView->SetBatchDisplayResolution(nStanX, nStanY, nNoStanX, nNoStanY, nNoStanPos);
}

void BCSettingLEDResolutionDlg::on_m_pSendCmdBtn_clicked()
{
    if ( !ui->m_pGraphicsView->IsGroupDisplayValid() ) {
        QMessageBox::warning(this,
                             tr("警告"),
                             tr("请检查所有单屏是否都设置了正确分辨率!"),
                             QMessageBox::Ok);
        return;
    }

    ui->m_pGraphicsView->SendCommand();

    this->accept();

    // 刷新界面
    BCCommon::Application()->RefreshMainWindow();
}

void BCSettingLEDResolutionDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingLEDResolutionDlg::on_m_pSingleXLineEdit_textChanged(const QString &arg1)
{
    int x = arg1.toInt();

    // 数据不合法则返回
    if (x <= 0)
        return;

    ui->m_pGraphicsView->SetSingleDisplayResolutionX( x );
}

void BCSettingLEDResolutionDlg::on_m_pSingleYLineEdit_textChanged(const QString &arg1)
{
    int x = arg1.toInt();

    // 数据不合法则返回
    if (x <= 0)
        return;

    ui->m_pGraphicsView->SetSingleDisplayResolutionY( x );
}
