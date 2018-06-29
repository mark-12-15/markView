/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：与服务器通讯类
*********************************************************************************************************************************/
#ifndef BCCOMMUNICATION_H
#define BCCOMMUNICATION_H

#include <QTcpSocket>
#include <QTimer>
#include <QTime>

class sWindowScene;
class BCLoginDlg;
class BCCommunication : public QObject
{
    Q_OBJECT
public:
    // 静态接口构造和销毁
    static BCCommunication *Application();
    static void Destroy();

    // 可主动设置IP和端口，每次设置重新连接
    void SetIPAndPort(const QString &ip, int port);

    // ------------------------------------------------------------------------------------------------------------------------------
    // 请求登录
    void RequestLogin(BCLoginDlg *pLoginDlg, const QString &usr, const QString &pwd);

    // 请求用户配置信息
    void RequestConfig(const QString &key, int userid);

    // 向服务器发送开窗指令
    void Winsize(int groupid, int chid, int winid, int l, int t, int r, int b, int type, int copyIndex);

    // 请求关窗
    void RequestWinSwitch(int gid, int winid, int chid, int type, int copyIndex);

    // 向服务器发送清屏指令
    void Reset(const QString &ids);

    // 请求控制分两种，1：移动窗口，2：场景轮训，3：预布局
    void RequestControlBySignalWindow(int groupid, int chid, int chtype, int winid);
    void RequestControlByGroupScene(int roomid, int groupsceneid);
    void RequestControlByFloorPlanning(int roomid, int groupsceneid);

    // 请求结束
    void RequestOver(int roomid);

    // 场景
    void RequestAddWindowScene(sWindowScene swindowscene, int roomid, int groupsceneid);
    void RequestDeleteWindowScene(int id, int roomid, int groupsceneid);
    void RequestUpdateWindowScene(int id, int roomid, int groupsceneid, int cycle, const QString &name);
    void RequestUpdateWindowScene(sWindowScene swindowscene, int roomid, int groupsceneid);
    void RequestLoadWindowScene(int nGroupDisplayID, int id);

    // IPV
    void SetIPVedioCurrentIP(int cid, int winid, int segmentation, int currentSegmentaion, const QString &ip, int boardcardid, int boardcardpos);
    void SetIPVedioSegmentation(int cid, int segmentation, int boardcardid, int boardcardpos);

    // 字幕
    void SetSubTitles(int visible, int beginChid, int endChid, int r, int g, int b, int posx, int posy, const QString &text);

    // 切边
    void SetCutArea(int chid, int left, int right, int top, int bottom);

    // 输入通道名称
    void UpdateInputChannel(int userid, int chid, int chtype, const QString &text);

    // 更新场景顺序
    void UpdateSceneSort(int roomid, int groupid, QMap<int, int> map);  // k-v: 场景ID和序列号

    // 修改用户密码
    void ModifyUser(int id, const QString &usr, const QString &psw);

    QString     m_ip;               // ip

private slots:
   void onRevData();    // 接收来自服务端的数据
   void onDisplayError(QAbstractSocket::SocketError);
   void onTimeout();    // 定时重连服务器

private:
    BCCommunication();
    ~BCCommunication();

    // 接收单个命令
    void RevSingleData(const QString &cmd);

    // 解析jsonKey
    QString DecodeJsonKey(const QString &json);

    // 标准的JSON
    QString EncodeStandardJson(const QString &k, const QString &v);
    QString GetJsonValueByKey(const QString &json, const QString &key, QString valueKey = "cmdValue");
    int GetStandardJsonResult(const QString &json); // 标准JSON返回值会在根目录的Key为cmdResult中

    // 构造请求添加场景JSON
    QString EncodeSceneJson(const QString &k, sWindowScene swindowscene, int roomid, int groupsceneid);

    // 构造场景顺序JSON
    QString EncodeSceneSortJson(int userid, int roomid, int groupid, QMap<int, int> map);

    // ----------------------------------------------------------------------------------------------------------------------
    // 服务器通知
    void ServerWinsize(int groupid, int channelid, int chtype, int windowid, int l, int t, int r, int b);
    void ServerWinswitch(int groupid, int channelid, int chtype, int windowid);
    void ServerMoveSignalWindow(int groupid, int channelid, int chtype, int windowid);
    void ServerReset(const QString &ids);
    void ServerAddScene(int nRoomID, int nGroupSceneID, sWindowScene swindowscene);
    void ServerDeleteScene(int nRoomID, int nGroupSceneID, int sceneid);
    void ServerUpdateScene(int nRoomID, int nGroupSceneID, int sceneid, int cycle, const QString &name);
    void ServerUpdateScene(int nRoomID, int nGroupSceneID, sWindowScene swindowscene);
    void ServerLoadWindowScene(int nGroupDisplayID, int sceneid);
    void ServerLoopGroupScene(int nRoomID, int nGroupSceneID);
    void ServerFloorPlanning(int nRoomID, int nGroupSceneID);
    void ServerUpdateInputChannel(int chid, int chtype, const QString &text);
    void ServerUpdateSceneSort(int roomid, int groupsceneid, QMap<int, int> map);

    sWindowScene DecodeSceneJson(const QString &json, int &roomid, int &groupsceneid);

    // 刷新场景界面
    void RefreshSceneWidget();

    // 发送数据
    int SendCmd(const QString &cmd);

private:
    static BCCommunication *m_pCommunication;

    int         m_nCacheTimes;      // 通讯缓存次数，支持最大缓存数据为连续3次
    QString     m_qsCacheJson;      // 通讯的缓存JSON，因为大的数据可能一个JSON传不过来

    QTcpSocket  *m_pSocket;         // 通讯socket
    QTimer      *m_pOneSecondTimer; // 通讯保持的timer
    int         m_nHeartBeatCount;  // 心跳次数
    QTime       m_timeOfPreview;        // 10ms内执行过指令则不发送心跳包

    int         m_port;             // port

    // 相关对象
    BCLoginDlg                  *m_pLoginDlg;           // 登录对话框
};

#endif // BCCOMMUNICATION_H
