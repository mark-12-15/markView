#include "BCSettingRemoveShadowDlg.h"
#include "ui_BCSettingRemoveShadowDlg.h"
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"
#include "../Model/BCMRoom.h"
#include "../Model/BCMGroupDisplay.h"

BCSettingRemoveShadowDlg::BCSettingRemoveShadowDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingRemoveShadowDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    // 标题和图标
    setWindowTitle(tr("边框削影"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );
}

BCSettingRemoveShadowDlg::~BCSettingRemoveShadowDlg()
{
    delete ui;
}

void BCSettingRemoveShadowDlg::on_m_pCancelBtn_clicked()
{
    this->reject();
}

void BCSettingRemoveShadowDlg::on_m_pOKBtn_clicked()
{
    MainWindow *pMainWindow = BCCommon::Application();
    BCLocalServer *pServer = BCLocalServer::Application();

    BCMRoom *pRoom = pMainWindow->GetCurrentMRoom();
    if (NULL == pRoom)
        return;

    BCMGroupDisplay *pGroupDisplay = pRoom->GetGroupDisplay( pRoom->GetRoomID() );
    if (NULL == pGroupDisplay)
        return;

    int arrX = pGroupDisplay->GetArraySize().width();
    int arrY = pGroupDisplay->GetArraySize().height();
    int resX = pRoom->GetWallSize().width()/arrX;
    int resY = pRoom->GetWallSize().height()/arrY;
    int shaX = ui->m_pXLineEdit->text().toInt();
    int shaY = ui->m_pYLineEdit->text().toInt();
    pServer->SetDevice2000RemoveShadow(arrX, arrY, resX, resY, shaX, shaY);

    this->accept();
}
