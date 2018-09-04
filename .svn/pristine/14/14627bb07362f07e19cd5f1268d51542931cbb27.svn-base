/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：主函数，需要与服务器通讯，并完成系统初始化工作
*********************************************************************************************************************************/
#include "MainWindow.h"
#include <QApplication>
#include <QMessageBox>

#include "../Common/BCCommon.h"
#include "../Common/BCCommunication.h"
#include "../Common/BCLocalServer.h"
#include "../Setting/BCLoginDlg.h"
#include "../Setting/BCSettingCommunicationDlg.h"
#include "../Setting/BCSettingWaitingDlg.h"
#include "../Setting/BCSettingRepeatApplicationWarningDlg.h"

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(new RibbonStyle);

    // 设置编码
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    // 加载语言
    BCCommon::InitLanguage();

    // 创建共享内存，保证只启动一次应用程序
    QSharedMemory shared_memory;
    shared_memory.setKey(QString("markView"));
    if(shared_memory.attach()) {
        BCSettingRepeatApplicationWarningDlg dlg;
        dlg.exec();

        return 0;
    }

    shared_memory.create(1);

    // 登录界面
    BCLoginDlg loginDlg;
    // 登录不成功则弹窗提示并且返回
    if(loginDlg.exec() != QDialog::Accepted) {
        // 删除远程服务器
        BCCommunication::Destroy();
        // 删除本地服务器
        BCLocalServer::Destroy();
        return 0;
    }

    // 公共接口调用应用程序
    MainWindow *pApplication = BCCommon::Application();
    pApplication->LoadGenaralConfig();

    // 判断是否是连接服务器
    // ??? 服务器的矩阵联控暂时没写

    if ( BCCommon::g_bConnectWithServer ) {
        BCSettingWaitingDlg *pDlg = new BCSettingWaitingDlg();
        pDlg->show();
    } else {
        if (BCCommon::g_nIsContainsMatrix == 1) {
            // 如果只显示矩阵则不提示通讯设置对话框
            pApplication->RefreshMainWindow();
        } else {
            // 弹出通讯设置对话框
            BCSettingCommunicationDlg *pCommunicationDlg = new BCSettingCommunicationDlg();
            if(pCommunicationDlg->exec() != QDialog::Accepted) {
                // 删除远程服务器
                BCCommunication::Destroy();
                // 删除本地服务器
                BCLocalServer::Destroy();
                return 0;
            }
        }
    }

    return a.exec();
}
