#include "BCControl.h"
#include "ui_BCControl.h"
#include <QScrollBar>
#include "BCWidgetBtn.h"
#include "../Model/BCMGroupDisplay.h"
#include "../Model/BCMChannel.h"
#include "BCSignalListWidgetData.h"
#include "../Common/BCLocalServer.h"
#include "../Common/BCCommon.h"

// 预览小窗的尺寸
#define PREVIEWWIDTH    240
#define PREVIEWHEIGHT   156

BCControl::BCControl(bool bVisible, int minHeight, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCControl)
{
    m_pHeaderBtn = NULL;

    m_bModifyHeight = false;
    m_bPress = false;

    ui->setupUi(this);
    setAttribute( Qt::WA_Hover,true);

    // 设置最小显示高度
    m_minHeight = minHeight;
    ui->m_pBodyFrame->setMinimumHeight(minHeight);

    // 初始化ui格式
    init( bVisible );

    m_pSocket = NULL;
    m_pTimer = NULL;
    m_pReadConfigTimer = NULL;

    // VP2000没有预监回显
    if (0 == BCCommon::g_nDeviceType) {
        ui->m_pHeaderWidget->setVisible( false );
    }

    // 不显示预监内容
    ui->m_pHeaderWidget->setVisible( false );

    // 刷新界面数据
    Refresh();

    // channel status
    g_local_stat = -1;

    new_filter_wait_buffer_len=0;
    new_filter_rd_buffer_len=0;
    g_stat_wr_addr = 0;
    g_stat_rd_addr = 0;
    for(int i=0;i<8;i++) {
        g_rd_stat_buf[i][0] = 0;
    }
    memset(new_filter_rd_buffer,0,40960);

    // init tcp socket
    m_pSocket = NULL;
    m_pTimer = NULL;
    m_pReadConfigTimer = NULL;
    BCLocalServer *pServer = BCLocalServer::Application();
    if ( 0 ) {
    // 条件依次是 不是服务器 不是演示模式 && 网络连接 && (VP2000A || VP4000)
    //if (!BCCommon::g_bConnectWithServer && (0 != pServer->m_nIsDemoMode) && pServer->m_bIsNetConnect && (1 == BCCommon::g_nDeviceType || 2 == BCCommon::g_nDeviceType)) {
        m_pSocket = new QTcpSocket( this );
        QHostAddress hostAddress;
        hostAddress.setAddress( pServer->m_qsConnectIPWithoutDLL );
        m_pSocket->connectToHost(hostAddress, pServer->m_qsConnectPortWithoutDLL.toInt());
        m_pSocket->waitForConnected( 50 );
        connect(m_pSocket, SIGNAL(readyRead()), this, SLOT(onRecvTcpMessage()));

        // timerZ
        m_pTimer = new QTimer( this );
        m_pTimer->setInterval( 5000 );
        connect(m_pTimer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
        m_pTimer->start();

        m_nTimerTimes = 0;
        m_pReadConfigTimer = new QTimer( this );
        m_pReadConfigTimer->setInterval( 10 );
        connect(m_pReadConfigTimer, SIGNAL(timeout()), this, SLOT(onReadConfigTimeOut()));
    }

    // 默认打开预览
    beginTime = beginTime.addMSecs( -1000 );
    ui->m_pShowVedioCheckBox->setVisible( false );
    on_m_pShowVedioCheckBox_clicked( true );
    onRefreshVedioStatus();
}

BCControl::~BCControl()
{
    if (NULL != m_pTimer) {
        disconnect(m_pTimer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
        m_pTimer->stop();
        m_pTimer->deleteLater();
    }

    if (NULL != m_pReadConfigTimer) {
        disconnect(m_pReadConfigTimer, SIGNAL(timeout()), this, SLOT(onReadConfigTimeOut()));
        m_pReadConfigTimer->stop();
        m_pReadConfigTimer->deleteLater();
    }

    if (NULL != m_pSocket) {
        m_pSocket->disconnectFromHost();
        m_pSocket->deleteLater();
    }

    // 关闭预览
    on_m_pShowVedioCheckBox_clicked( false );

    // 删除header的自定义button
    if (NULL != m_pHeaderBtn) {
        delete m_pHeaderBtn;
        m_pHeaderBtn = NULL;
    }

    delete ui;
}

void BCControl::onSetVisible(bool bVisible)
{
    ui->m_pBodyFrame->setVisible( bVisible );
}

bool BCControl::IsVisible()
{
    return m_pHeaderBtn->IsVisible();
}

void BCControl::init(bool bVisible)
{
    // 默认显示列表
    m_bShowVedio = false;
    m_bTempCloseEcho = false;

    // 添加自定义列表头，可以控制隐藏和显示
    m_pHeaderBtn = new BCWidgetBtn(this, MainWindow::INPUTCHANNELSSIGSRC, bVisible);
    ui->verticalLayout->addWidget(m_pHeaderBtn);

    connect(m_pHeaderBtn, SIGNAL(sigSetVisible(bool)), this, SLOT(onSetVisible(bool)));
    onSetVisible( bVisible );

    // 初始化显示模式，并且默认为文字显示
    ui->m_pShowModeComboBox->addItem(tr("列表"));
    ui->m_pShowModeComboBox->addItem(tr("网格"));

    ui->m_pShowModeComboBox->setCurrentIndex(0);
    on_m_pShowModeComboBox_currentIndexChanged(0);

    // 初始化视频显示的格式
    beginTime = QTime::currentTime();
    m_nScrollMinValue = 0;
    m_nScrollMaxValue = 1;
    ui->m_pInputChannelVedioListWidget->setViewMode(QListView::IconMode);
    ui->m_pInputChannelVedioListWidget->setResizeMode( QListView::Adjust);
    ui->m_pInputChannelVedioListWidget->setFlow(QListView::LeftToRight);
    ui->m_pInputChannelVedioListWidget->setSpacing(5);
    connect(ui->m_pInputChannelVedioListWidget->verticalScrollBar(), SIGNAL(actionTriggered(int)), this, SLOT(onActionTriggered(int)));
    connect(ui->m_pInputChannelVedioListWidget->verticalScrollBar(), SIGNAL(rangeChanged(int,int)), this, SLOT(onRangeChanged(int, int)));

    // 设置字体
    BCCommon::SetSystemFont(this);

    // 是否隐藏掉视频显示
    //ui->m_pHeaderWidget->setVisible( false );
}

BCMChannel *BCControl::GetCurrentChannel()
{
    QWidget *pWidget = ui->m_pInputChannelTextTabWidget->currentWidget();
    for (int i = 0; i < pWidget->children().count(); i++) {
        BCControlTreeWidget *pTreeWidget = dynamic_cast<BCControlTreeWidget *>( pWidget->children().at( i ) );
        if (NULL != pTreeWidget)
            return pTreeWidget->GetCurrentChannel();
    }

    return NULL;
}

void BCControl::RefreshToopTip()
{
    ui->m_pInputChannelTextListWidget1->RefreshToopTip();
    ui->m_pInputChannelTextListWidget2->RefreshToopTip();
    ui->m_pInputChannelTextListWidget3->RefreshToopTip();
    ui->m_pInputChannelTextListWidget4->RefreshToopTip();
}

void BCControl::RefreshInputChannelName()
{
    ui->m_pInputChannelTextListWidget1->RefreshInputChannelName();
    ui->m_pInputChannelTextListWidget2->RefreshInputChannelName();
    ui->m_pInputChannelTextListWidget3->RefreshInputChannelName();
    ui->m_pInputChannelTextListWidget4->RefreshInputChannelName();
}

void BCControl::SetTabVisibleFalse(int type)
{
    switch ( type ) {
    case 0:
        ui->m_pInputChannelTextTabWidget->removeTab( ui->m_pInputChannelTextTabWidget->indexOf(ui->tab) );
        //ui->tab->setVisible( false );
        break;
    case 1:
        ui->m_pInputChannelTextTabWidget->removeTab( ui->m_pInputChannelTextTabWidget->indexOf(ui->tab_2) );
        //ui->tab_2->setVisible( false );
        break;
    case 2:
        ui->m_pInputChannelTextTabWidget->removeTab( ui->m_pInputChannelTextTabWidget->indexOf(ui->tab_3) );
        //ui->tab_3->setVisible( false );
        break;
    default:
        ui->m_pInputChannelTextTabWidget->removeTab( ui->m_pInputChannelTextTabWidget->indexOf(ui->tab_4) );
        //ui->tab_4->setVisible( false );
        break;
    }
}

void BCControl::Refresh()
{
    // 内部含有两个链表，不带图像和带图像的，需要分开刷新
    MainWindow *pApplication = BCCommon::Application();

    // 初始化链表
    QList<BCMChannel*> lstChannels = pApplication->GetInputChannels();

    // 1.初始化不带图片的链表
    ui->m_pInputChannelTextListWidget1->Refresh(0, lstChannels, this);    // 电脑
    ui->m_pInputChannelTextListWidget2->Refresh(1, lstChannels, this);    // 视频
    ui->m_pInputChannelTextListWidget3->Refresh(2, lstChannels, this);    // 高清
    ui->m_pInputChannelTextListWidget4->Refresh(3, lstChannels, this);    // Vedio

    // 2.初始化带图片的链表
    ui->m_pInputChannelVedioListWidget->clear();

    QListIterator<BCMChannel*> it( lstChannels );
    while ( it.hasNext() ) {
        BCMChannel *pMChannel = it.next();

        // 新建item并添加到链表
        QListWidgetItem *pItem = new QListWidgetItem( ui->m_pInputChannelVedioListWidget );
        pItem->setSizeHint(QSize(PREVIEWWIDTH, PREVIEWHEIGHT));
        ui->m_pInputChannelVedioListWidget->addItem(pItem);

        // 关联item和widget
        ui->m_pInputChannelVedioListWidget->setItemWidget(pItem, new BCSignalListWidgetData(pMChannel, this));
    }
}

void BCControl::HighLightInputChannel(BCMChannel *pChannel)
{
    ui->m_pInputChannelTextListWidget1->HighLightInputChannel( pChannel );
    ui->m_pInputChannelTextListWidget2->HighLightInputChannel( pChannel );
    ui->m_pInputChannelTextListWidget3->HighLightInputChannel( pChannel );
    ui->m_pInputChannelTextListWidget4->HighLightInputChannel( pChannel );
}

void BCControl::on_m_pShowVedioCheckBox_clicked(bool bPreview)
{
    if (m_bShowVedio == bPreview)
        return;

    m_bShowVedio = bPreview;

    if ( m_bShowVedio ) {
        onRefreshVedioStatus();
    } else {
        QListWidgetItem *pItem = NULL;
        BCSignalListWidgetData *pInputChannelVedioItem = NULL;
        for (int i = 0; i < ui->m_pInputChannelVedioListWidget->count(); i++) {
            pItem = ui->m_pInputChannelVedioListWidget->item(i);
            if (NULL == pItem)
                continue;

            // 取自定义的代理widget
            pInputChannelVedioItem = dynamic_cast<BCSignalListWidgetData *>( ui->m_pInputChannelVedioListWidget->itemWidget( pItem ) );
            if (NULL == pInputChannelVedioItem)
                continue;

            pInputChannelVedioItem->SetEcho( bPreview );
        }
    }
}

void BCControl::on_m_pShowModeComboBox_currentIndexChanged(int index)
{
    bool bShowVedioList = (0 == index) ? false : true;
    ui->m_pInputChannelTextTabWidget->setVisible( !bShowVedioList );
    ui->m_pInputChannelVedioListWidget->setVisible( bShowVedioList );
    ui->m_pShowVedioCheckBox->setEnabled( bShowVedioList );

    m_bTempCloseEcho = !bShowVedioList;
    onRefreshVedioStatus();
}

void BCControl::onActionTriggered(int /*value*/)
{
    // 1秒钟后刷新状态
    beginTime = QTime::currentTime();
    QTimer::singleShot(1000, this, SLOT(onRefreshVedioStatus()));
}


void BCControl::onRangeChanged(int min, int max)
{
    // 记录滚动轴的最大最小值
    m_nScrollMinValue = min;
    m_nScrollMaxValue = max;
}

void BCControl::onRefreshVedioStatus()
{
    // 如果不显示视频直接返回
    if ( !m_bShowVedio )
        return;

    // 如果连续多次操作滚动条则最后一次再刷新
    int nOffsetTime = beginTime.msecsTo( QTime::currentTime() );
    if (nOffsetTime < 1000)
        return;

    // 计算滚动条的范围
    int nScrollViewHeight = ui->m_pInputChannelVedioListWidget->verticalScrollBar()->height();
    int nScrollMinValue = ui->m_pInputChannelVedioListWidget->verticalScrollBar()->value();
    int nScrollMaxValue = nScrollMinValue+nScrollViewHeight;
    double dSingleChannelHeight = 1.0*(m_nScrollMaxValue-m_nScrollMinValue+nScrollViewHeight)/ui->m_pInputChannelVedioListWidget->count();

    QListWidgetItem *pItem = NULL;
    BCSignalListWidgetData *pInputChannelVedioItem = NULL;
    for (int i = 0; i < ui->m_pInputChannelVedioListWidget->count(); i++) {
        pItem = ui->m_pInputChannelVedioListWidget->item(i);
        if (NULL == pItem)
            continue;

        // 取自定义的代理widget
        pInputChannelVedioItem = dynamic_cast<BCSignalListWidgetData *>( ui->m_pInputChannelVedioListWidget->itemWidget( pItem ) );
        if (NULL == pInputChannelVedioItem)
            continue;

        // 计算每个通道的范围
        double dChannelMinValue = m_nScrollMinValue + i*dSingleChannelHeight;
        double dChannelMaxValue = dChannelMinValue + dSingleChannelHeight;

        // 判断是否相交
        bool bPreview = false;
        if ( !m_bTempCloseEcho ) {
            if (((dChannelMinValue >= nScrollMinValue) && (dChannelMinValue <= nScrollMaxValue))
                    || ((dChannelMaxValue >= nScrollMinValue) && (dChannelMaxValue <= nScrollMaxValue))) {
                // 打开回显
                bPreview = true;
            }
        }

        pInputChannelVedioItem->SetEcho( bPreview );
    }
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------
void BCControl::new_push_rd_stat_for_sys(unsigned char cmdtype,unsigned short ipid)
{
    unsigned char		i,wStr[256];
    i = g_stat_wr_addr & 0x3f;
    g_stat_len_array[i] = cmdtype + ((32+11)<<8);
    if(cmdtype<=15)
    {
        wStr[0] = 0x21;
        wStr[1] = 0x16;
        wStr[2] = i&0xff;
        wStr[3] = (i>>8);
        wStr[4] = 1;
        wStr[5] = ipid;
        wStr[6] = (ipid>>8);
        wStr[7] = cmdtype;
        wStr[8] = 0;
        wStr[9] = 0xa4;
        wStr[10] = 0xa5;
        memcpy((unsigned char *)&g_stat_str[i][0],wStr,32);
        g_stat_wr_addr++;
        g_stat_wr_addr &= 0x3f;
    }
}

bool BCControl::new_filter_rd_stat_buffer(unsigned char	ptr[],unsigned int len)
{
    unsigned int	i,j,k;
    unsigned char	code_str[8];
    unsigned int	g_ser_rd_code[2]={0x16aaeca6,0x6677aa55};
    unsigned short	*g_data_ptr,c1,c2,stat_type,backboard_type;

    unsigned short	g_rd_stat_buf_wr_addr;

    for(i=0;i<8;i++)
    {
        code_str[i] = ptr[i];
    }
    i = ((unsigned int *)&code_str[0])[0];
    j = ((unsigned int *)&code_str[0])[1];
    g_data_ptr = (unsigned short *)ptr;

    int flag = 0;
    if((i==g_ser_rd_code[0])&&(j==g_ser_rd_code[1])&&(len<15360))
    {
        memcpy(new_filter_rd_buffer,ptr,len);
        new_filter_rd_buffer_len = len;
        new_filter_wait_buffer_len = g_data_ptr[6];
        new_filter_wait_buffer_len<<=1;
    }
    else	if((new_filter_rd_buffer_len<(8072*2))&&(len<25360))
    {
        flag = 1;
        memcpy(&new_filter_rd_buffer[new_filter_rd_buffer_len],ptr,len);
        new_filter_rd_buffer_len += len;
    }
    else
    {
        flag = 2;
        new_filter_wait_buffer_len = 0;
        new_filter_rd_buffer_len = 0;
    }

    if(new_filter_rd_buffer_len>=new_filter_wait_buffer_len)
    {
        new_filter_wait_buffer_len = 0;
        new_filter_rd_buffer_len = 0;
    }
    else
    {
        return false;
    }

    for(i=0;i<8;i++)
    {
        code_str[i] = ptr[i];
    }
    i = ((unsigned int *)&new_filter_rd_buffer[0])[0];
    j = ((unsigned int *)&new_filter_rd_buffer[0])[1];
    g_data_ptr = (unsigned short *)new_filter_rd_buffer;

    if((i==g_ser_rd_code[0])&&(j==g_ser_rd_code[1])&&(g_data_ptr[4]>=0x80)&&(g_data_ptr[4]<=0xaf)&&(g_data_ptr[6]<=2048*4))
    {
        stat_type = g_data_ptr[4]-0x80;
        k = g_data_ptr[6];
        c1 = NewCrcDat(stat_type,k,g_data_ptr);
        c2 = g_data_ptr[k];
        if(c1==c2)
        {
            stat_type += 0;
            backboard_type = g_data_ptr[7];
            g_rd_stat_buf_wr_addr &= 0x07;
            for(i=0;i<k;i++)
            {
                g_rd_stat_buf[g_rd_stat_buf_wr_addr][3+i] = g_data_ptr[8+i];
            }
            g_rd_stat_buf[g_rd_stat_buf_wr_addr][0] = k;
            g_rd_stat_buf[g_rd_stat_buf_wr_addr][2] = g_data_ptr[5];
            g_rd_stat_buf[g_rd_stat_buf_wr_addr][1] = g_data_ptr[7];
            g_rd_stat_buf_wr_addr++;
            g_rd_stat_buf_wr_addr &= 0x07;
            return	true;
        }
        return false;
    }
    return false;
}

unsigned short BCControl::NewCrcDat(unsigned short g_BlendingCodeA,unsigned short g_BlendingMaxNumber,unsigned short g_BLENDING_BUFFER[])
{
    unsigned short	i,C0;

    C0 = g_BlendingCodeA;
    for(i=0;i<g_BlendingMaxNumber;i++)
    {
        if(g_BLENDING_BUFFER[i]==0)
        {
            C0 += 0xffff;
        }
        else
        {
            C0 += g_BLENDING_BUFFER[i];
        }
    }
    return C0;
}

unsigned int BCControl::make_status_data_addr(unsigned short	tmp_g_code_id)//20170605
{
    unsigned short	tmpRefPos[8],*g_board_status_info;
    g_board_status_info = &g_rd_stat_buf[g_local_stat][0];
    tmpRefPos[0] = 12;
    tmpRefPos[1] = 14 + g_board_status_info[10-5]*16;
    tmpRefPos[2] = tmpRefPos[1] + g_board_status_info[8-5] + 1;
    tmpRefPos[3] = tmpRefPos[2] + g_board_status_info[8-5]*6 + 1;
    tmpRefPos[4] = tmpRefPos[3] + g_board_status_info[11-5]*4 + 0;
    tmpRefPos[5] = tmpRefPos[4] + 32;
    tmpRefPos[6] = tmpRefPos[5] + g_board_status_info[12-5];
    tmpRefPos[7] = tmpRefPos[6] + g_board_status_info[8-5]*2;
    return	tmpRefPos[tmp_g_code_id]-3;
}

void BCControl::onTimeOut()
{
    // if connect with serial, socket=NULL
    if (NULL == m_pSocket)
        return;

    // reconnect tcp
    BCLocalServer *pServer = BCLocalServer::Application();
    QAbstractSocket::SocketState socketState = m_pSocket->state();
    if ((socketState != QAbstractSocket::ConnectingState) && (socketState != QAbstractSocket::ConnectedState)) {
        QHostAddress hostAddress;
        hostAddress.setAddress( pServer->m_qsConnectIPWithoutDLL );
        m_pSocket->connectToHost(hostAddress, pServer->m_qsConnectPortWithoutDLL.toInt());
        m_pSocket->waitForConnected( 50 );
    }

    g_code_id = GetTickCount();
    new_push_rd_stat_for_sys(8, g_code_id);

    // tcp thread code
    if (g_stat_wr_addr != g_stat_rd_addr) {
        char cmdstr[256];
        int i =  g_stat_rd_addr & 0x3f;
        unsigned short cmdstrlen = 0;
        int	len = g_stat_len_array[i];
        len>>=8;
        if((len<64)&&(len>0))
        {
            memcpy((unsigned char *)cmdstr,g_stat_str[i],len);
            cmdstrlen = len;
        }

        g_stat_rd_addr++;
        g_stat_rd_addr &= 0x3f;

        m_pSocket->write((char *)cmdstr, cmdstrlen);

        m_pReadConfigTimer->start();
        m_nTimerTimes = 0;
    }
}

void BCControl::onRecvTcpMessage()
{
    char sstr[32768];
    int bread = m_pSocket->read((char *)sstr, 32768);
    new_filter_rd_stat_buffer((unsigned char *)sstr, bread);
}

void BCControl::onReadConfigTimeOut()
{
    m_nTimerTimes++;
    g_local_stat = 0xe0f0;
    for(int i=0;i<8;i++) {
        if(g_rd_stat_buf[i][0]==1032) {
            g_local_stat = i;

            break;
        }
    }

//    if (g_local_stat != 0xe0f0) {
//        unsigned short *g_board_status_info = (unsigned short *)&g_rd_stat_buf[g_local_stat][0];
//    for (int i = 0; i < 508; i++) {
//        qDebug() << g_board_status_info[i] << i;
//    }
//    }


    if (g_local_stat != 0xe0f0) {
        // success
        m_nTimerTimes = 0;

        m_pReadConfigTimer->stop();

        if (g_local_stat <= 7) {
            // ---------------------------------------------------------------------------------------------------------------------------
            // 输入通道
            //int n = make_status_data_addr(3);
            int n = 11; // 函数不对，可直接取11
            unsigned short *g_board_status_info = (unsigned short *)&g_rd_stat_buf[g_local_stat][0];
            int j = g_board_status_info[3+3];

            // liuwl 全局变量
            MainWindow *pMainWindow = BCCommon::Application();

            for(int i=0;i<j;i++)
            {
                // 这里可能需要添加是否可用字段
                unsigned short xpixels = g_board_status_info[n+i*4+0];
                unsigned short ypixels = g_board_status_info[n+i*4+1];
                unsigned short enable = g_board_status_info[n+i*4+2];
                unsigned short type = g_board_status_info[n+i*4+3];

                qDebug() << "channel: " << xpixels << ypixels << enable << type;

                // ----------------------------------------------------------------------------------------- begin
                // liuwl 根据通道ID和类型修改通道的分辨率和是否可用信息
                int chid = enable;   // 通道ID
                if (3 == type) // 3是高清，在数据库中类型是2
                    type = 2;
                else if (9 == type) // 9是IPV，在数据库中是1
                    type = 1;
                BCMChannel *pChannel = pMainWindow->GetInputChannel(chid, type);
                if (NULL != pChannel) {
                    pChannel->SetResolution(QSize(xpixels, ypixels));       // 分辨率
                    pChannel->SetIsEnable(1 ? true : false);    // true可用，false不可用
                }
                // ----------------------------------------------------------------------------------------- end
            }

            // liuwl 刷新界面悬停和图标显示
            this->RefreshToopTip();
        }
    } else if (m_nTimerTimes > 40) {
        m_pReadConfigTimer->stop();
        m_nTimerTimes = 0;
    }
}

bool BCControl::event(QEvent *event)
{
    if (NULL == m_pHeaderBtn)
        return false;

    // 如果隐藏则不出发悬停事件
    if ( !m_pHeaderBtn->IsVisible() )
        return false;

    if (event->type() == QEvent::HoverEnter || event->type() == QEvent::HoverLeave
            || event->type() == QEvent::HoverMove) {
        QHoverEvent* pHoverEvent = static_cast<QHoverEvent *>(event);

        // 判断是否需要调整窗口大小，下面为距离左上角的值
        int nltx = pHoverEvent->pos().x() - rect().x();
        int nlty = pHoverEvent->pos().y() - rect().y();

        // x在修改范围时
        if (nltx <= BCCommon::g_nMaxSizeOfModifyRect) {
            m_bModifyHeight = false;
            setCursor(Qt::ArrowCursor);
        } else if (qAbs(nltx-rect().width()) <= BCCommon::g_nMaxSizeOfModifyRect) {
            m_bModifyHeight = false;
            setCursor(Qt::ArrowCursor);
        } else {
            if (nlty <= BCCommon::g_nMaxSizeOfModifyRect) {
                // ↑
                m_bModifyHeight = true;
                setCursor(Qt::SizeVerCursor);
            } else if (qAbs(nlty-rect().height()) <= BCCommon::g_nMaxSizeOfModifyRect) {
                // ↓
                m_bModifyHeight = true;
                setCursor(Qt::SizeVerCursor);
            } else {
                // 不拉伸
                m_bModifyHeight = false;
                setCursor(Qt::ArrowCursor);
            }
        }
    }

    return QWidget::event(event);
}

void BCControl::mousePressEvent(QMouseEvent *e)
{
    if ((e->button() == Qt::LeftButton) && m_bModifyHeight) {
        m_bPress = true;
    }

    QWidget::mousePressEvent( e );
}

void BCControl::mouseMoveEvent(QMouseEvent *e)
{
    if( m_bPress ) {
        m_minHeight = e->pos().y() - m_pHeaderBtn->height()-10;

        ui->m_pBodyFrame->setMinimumHeight( m_minHeight );
    }

    QWidget::mouseMoveEvent( e );
}

void BCControl::mouseReleaseEvent(QMouseEvent *e)
{
    m_bPress = false;

    QWidget::mouseReleaseEvent( e );
}

