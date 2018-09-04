#include "BCSettingDeviceFormatLEDDlg.h"
#include "ui_BCSettingDeviceFormatLEDDlg.h"
#include "../View/BCTextDisplayItem.h"
#include "../Common/BCCommon.h"
#include <QMessageBox>
#include "../Common/BCLocalServer.h"
#include "BCSettingDeviceFormatDlg.h"

// 显示的单屏
class BCSettingSingleDisplay : public QGraphicsRectItem
{
public:
    BCSettingSingleDisplay(int arrX, int arrY, int i, int j, QGraphicsItem *parent =NULL);
    ~BCSettingSingleDisplay();

    void Refresh(); // 刷新大小

    void SetHighLight(bool b);
    bool IsHighLight();

    void SetDisplayText(const QString &text);
    QSize GetSize();

    int     m_arrX;
    int     m_arrY;
    int     m_i;            // 屏组中的位置
    int     m_j;

protected:
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget*/);

    BCTextDisplayItem *m_pTextItem; // 文字显示块，显示屏幕信息

    bool    m_bHighLight;   // 是否高亮
};

BCSettingSingleDisplay::BCSettingSingleDisplay(int arrX, int arrY, int i, int j, QGraphicsItem *parent)
    :QGraphicsRectItem(parent)
{
    m_pTextItem = new BCTextDisplayItem(this);

    m_bHighLight = false;

    m_arrX = arrX;
    m_arrY = arrY;
    m_i = i;
    m_j = j;
}

BCSettingSingleDisplay::~BCSettingSingleDisplay()
{
    delete m_pTextItem;
    m_pTextItem = NULL;
}

void BCSettingSingleDisplay::Refresh()
{
    QRectF rect = this->scene()->sceneRect();
    double dSingleDisplayWidth = 1.0 * rect.width() / m_arrX;
    double dSingleDisplayHeight = 1.0 * rect.height() / m_arrY;

    // 设置矩形大小
    setRect(m_j*dSingleDisplayWidth, m_i*dSingleDisplayHeight, dSingleDisplayWidth, dSingleDisplayHeight);
    this->update();
}

void BCSettingSingleDisplay::SetHighLight(bool b)
{
    m_bHighLight = b;
    this->update();
}

bool BCSettingSingleDisplay::IsHighLight()
{
    return m_bHighLight;
}

void BCSettingSingleDisplay::SetDisplayText(const QString &text)
{
    m_pTextItem->SetText( text );
    this->update();
}

QSize BCSettingSingleDisplay::GetSize()
{
    QSize size(0, 0);
    QString text = m_pTextItem->text();
    if ( !text.contains("*") )
        return size;

    QStringList lst = text.split("*");
    if (lst.count() != 2)
        return size;

    size.setWidth( lst.at(0).toInt() );
    size.setHeight( lst.at(1).toInt() );

    return size;
}

void BCSettingSingleDisplay::paint(QPainter * painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget*/)
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

    m_pTextItem->setPos(rect().left(), rect().top());
}

// -------------------------------------------------------------------------------------------------------

BCSettingDeviceFormatLEDView::BCSettingDeviceFormatLEDView(QWidget *parent)
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

BCSettingDeviceFormatLEDView::~BCSettingDeviceFormatLEDView()
{
    delete m_pScene;
    m_pScene = NULL;
}

void BCSettingDeviceFormatLEDView::Init(int id, int arrX, int arrY, BCSettingDeviceFormatLEDDlg *pDlg)
{
    m_pDlg = pDlg;
    m_id = id;
    m_arrX = arrX;
    m_arrY = arrY;

    for (int i = 0; i < arrY; i++) {
        for (int j = 0; j < arrX; j++) {
            BCSettingSingleDisplay *pItem = new BCSettingSingleDisplay(arrX, arrY, i, j);
            m_pScene->addItem( pItem );

            // 刷新矩形区域
            pItem->Refresh();
        }
    }
}

void BCSettingDeviceFormatLEDView::resizeEvent(QResizeEvent * event)
{
    QSize size = event->size();
    m_pScene->setSceneRect(0.0, 0.0, size.width(), size.height());

    QList<QGraphicsItem *> lst = m_pScene->items();
    for (int i = 0; i < lst.count(); i++) {
        BCSettingSingleDisplay *pItem = dynamic_cast<BCSettingSingleDisplay *>( lst.at(i) );
        if (NULL == pItem)
            continue;

        pItem->Refresh();
    }
}

// 鼠标事件选中单个显示器
void BCSettingDeviceFormatLEDView::mousePressEvent(QMouseEvent *e)
{
    if(e->button()== Qt::LeftButton){
        m_bPress = true;

        // 记录点击的坐标
        m_x = e->pos().x();
        m_y = e->pos().y();

        HighLight(QPoint(m_x, m_y));
    }
}

void BCSettingDeviceFormatLEDView::mouseMoveEvent(QMouseEvent *e)
{
    if (m_bPress) {
        double x = (m_x < e->pos().x()) ? m_x : e->pos().x();
        double y = (m_y < e->pos().y()) ? m_y : e->pos().y();
        double w = qAbs(m_x - e->pos().x());
        double h = qAbs(m_y - e->pos().y());

        HighLight(QRect(x, y, w, h));
    }
}

void BCSettingDeviceFormatLEDView::mouseReleaseEvent(QMouseEvent */*e*/)
{
    m_bPress = false;
}

void BCSettingDeviceFormatLEDView::HighLight(QPoint pt)
{
    ClearHighLight();

    QPointF ptScene = this->mapToScene( pt );
    QList<QGraphicsItem *> lst = m_pScene->items( ptScene );
    QListIterator<QGraphicsItem *> it( lst );
    while (it.hasNext()) {
        BCSettingSingleDisplay *pItem = dynamic_cast<BCSettingSingleDisplay *>( it.next() );
        if (NULL == pItem)
            continue;

        pItem->SetHighLight( true );
    }
}

void BCSettingDeviceFormatLEDView::HighLight(QRect rect)
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
        BCSettingSingleDisplay *pItem = dynamic_cast<BCSettingSingleDisplay *>( it.next() );
        if (NULL == pItem)
            continue;

        pItem->SetHighLight( true );
    }
}

void BCSettingDeviceFormatLEDView::ClearHighLight()
{
    QList<QGraphicsItem *> lst = m_pScene->items();
    QListIterator<QGraphicsItem *> it( lst );
    while (it.hasNext()) {
        BCSettingSingleDisplay *pItem = dynamic_cast<BCSettingSingleDisplay *>( it.next() );
        if (NULL == pItem)
            continue;

        pItem->SetHighLight( false );
    }
}

bool BCSettingDeviceFormatLEDView::IsGroupDisplayValid()
{
    bool bValid = true;

    QList<QGraphicsItem *> lst = m_pScene->items();
    QListIterator<QGraphicsItem *> it( lst );
    while (it.hasNext()) {
        BCSettingSingleDisplay *pItem = dynamic_cast<BCSettingSingleDisplay *>( it.next() );
        if (NULL == pItem)
            continue;

        QSize size = pItem->GetSize();
        if (size.width() > 0 && size.height() > 0)
            continue;

        bValid = false;
        break;
    }

    return bValid;
}

void BCSettingDeviceFormatLEDView::SendCommand()
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
        BCSettingSingleDisplay *pItem = dynamic_cast<BCSettingSingleDisplay *>( lst.at(i) );
        if (NULL == pItem)
            continue;

        QSize size = pItem->GetSize();
        width += size.width();
        height += size.height();

        m_pDlg->SetCommandProgressValue( nBaseValue += dOffsetValue );
    }

    resoluX = width / (m_arrX*m_arrY);
    resoluY = height / (m_arrX*m_arrY);

    pServer->SetFormatxy(m_arrX, m_arrY, resoluX, resoluY);
    m_pDlg->m_pFormatDlg->SetLEDConfig(resoluX, resoluY);
    m_pDlg->SetCommandProgressValue( nBaseValue += 3 );
    QThread::msleep( 300 );
    pServer->UpdateRoomFormat(m_id, 1, m_arrX, m_arrY, resoluX, resoluY);
    m_pDlg->SetCommandProgressValue( nBaseValue += 2 );
    QThread::msleep( 200 );

    // 单屏单独计算百分比
    nBaseValue = 20;
    dOffsetValue = 80.0 / m_arrX*m_arrY;

    m_pDlg->SetCommandProgressValue( nBaseValue );

    // 设置分屏尺寸
    QListIterator<QGraphicsItem *> it( lst );
    while (it.hasNext()) {
        BCSettingSingleDisplay *pItem = dynamic_cast<BCSettingSingleDisplay *>( it.next() );
        if (NULL == pItem)
            continue;

        QSize size = pItem->GetSize();

        // 需要找到所有左上角的单屏确定尺寸
        int nStartX = 0;
        int nStartY = 0;
        for (int i = 0; i < lst.count(); i++) {
            BCSettingSingleDisplay *pLeftTopItem = dynamic_cast<BCSettingSingleDisplay *>( lst.at(i) );
            if (NULL == pLeftTopItem)
                continue;

            // 1.如果同时都小于时，x和y方向同时增加
            if ((pLeftTopItem->m_i < pItem->m_i) && (pLeftTopItem->m_j < pItem->m_j)) {
                nStartX += pLeftTopItem->GetSize().width();
                nStartY += pLeftTopItem->GetSize().height();
            }

            // 2.如果x小于，y等于，只增加x方向
            if ((pLeftTopItem->m_i < pItem->m_i) && (pLeftTopItem->m_j == pItem->m_j)) {
                nStartY += pLeftTopItem->GetSize().height();
            }

            // 3.如果y小于，x等于，只增加y方向
            if ((pLeftTopItem->m_i == pItem->m_i) && (pLeftTopItem->m_j < pItem->m_j)) {
                nStartX += pLeftTopItem->GetSize().width();
            }
        }

        pServer->Setxy(m_id, pItem->m_i*pItem->m_arrX+pItem->m_j, nStartX, nStartY, size.width(), size.height());
        m_pDlg->m_pFormatDlg->AddSetXYPara(pItem->m_i*pItem->m_arrX+pItem->m_j, nStartX, nStartY, size.width(), size.height());
        QThread::msleep( 100 );

        m_pDlg->SetCommandProgressValue( nBaseValue += dOffsetValue );
    }

    m_pDlg->SetCommandProgressValue( 100 );
}

void BCSettingDeviceFormatLEDView::SetSingleDisplayResolution(int x, int y)
{
    QList<QGraphicsItem *> lst = m_pScene->items();
    QListIterator<QGraphicsItem *> it( lst );
    while (it.hasNext()) {
        BCSettingSingleDisplay *pItem = dynamic_cast<BCSettingSingleDisplay *>( it.next() );
        if (NULL == pItem)
            continue;

        if ( !pItem->IsHighLight() )
            continue;

        pItem->SetDisplayText(QString("%1*%2").arg(x).arg(y));
    }
}

void BCSettingDeviceFormatLEDView::SetBatchDisplayResolution(int stanX, int stanY, int noStanX, int noStanY, int noStanPos)
{
    QList<QGraphicsItem *> lst = m_pScene->items();
    QListIterator<QGraphicsItem *> it( lst );
    while (it.hasNext()) {
        BCSettingSingleDisplay *pItem = dynamic_cast<BCSettingSingleDisplay *>( it.next() );
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

        pItem->SetDisplayText(QString("%1*%2").arg(x).arg(y));
    }
}

// -------------------------------------------------------------------------------------------------------

BCSettingDeviceFormatLEDDlg::BCSettingDeviceFormatLEDDlg(int id, int row, int col, BCSettingDeviceFormatDlg *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingDeviceFormatLEDDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("LED规模设置"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    // 隐藏进度条
    ui->m_pCmdProgressBar->setVisible( false );

    m_pFormatDlg = parent;
    ui->m_pGraphicsView->Init(id, row, col, this);
    SetCommandProgressValue( 0 );
}

BCSettingDeviceFormatLEDDlg::~BCSettingDeviceFormatLEDDlg()
{
    delete ui;
}

void BCSettingDeviceFormatLEDDlg::SetCommandProgressValue(int value)
{
    ui->m_pCmdProgressBar->setValue( value );
}

// 框选的应用按钮
void BCSettingDeviceFormatLEDDlg::on_m_pSingleApplyBtn_clicked()
{
    int x = ui->m_pSingleXLineEdit->text().toInt();
    int y = ui->m_pSingleYLineEdit->text().toInt();

    // 数据不合法则返回
    if ((x <= 0) || (y <= 0))
        return;

    ui->m_pGraphicsView->SetSingleDisplayResolution(x, y);
}

// 批量的应用按钮
void BCSettingDeviceFormatLEDDlg::on_m_pBatchApplyBtn_clicked()
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

void BCSettingDeviceFormatLEDDlg::on_m_pSendCmdBtn_clicked()
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
}

void BCSettingDeviceFormatLEDDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}
