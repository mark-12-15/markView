/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：本地数据库类，跟其他类完全解耦
*********************************************************************************************************************************/
#ifndef BCLOCALDATABASE_H
#define BCLOCALDATABASE_H

#include <QMap>
#include <QPoint>
#include <QObject>
#include <QSqlDatabase>

class sTaskPlanning;
class sMatrix;
class sTab;
class sInputChannel;
class sCustomInputChannel;
class sRoom;
class sRoomConfig;
class sGroupScene;
class sWindowScene;
class BCLocalServer;
class BCLocalTcpSocket;
class BCLocalSerialPort;
class BCLocalDatabase : public QObject
{
    Q_OBJECT
public:
    BCLocalDatabase(BCLocalServer *pServer=NULL);
    ~BCLocalDatabase();

    bool InitDataBaseData();                        // 初始化数据库内数据，读DLL

    // 验证用户
    QPoint Authenticate(const QString &usr, const QString &pwd);

    // 场景操作接口
    void AddGroupScene(int userid, const QString &deviceip, int id, int nRoomID, int nIsNormalLoop, int nIsLoop, int nLoopInterval, const QString &qsName);
    void AddScene(int userid, const QString &deviceip, int id, int nRoomID, int nGroupSceneID, int nIsCycle, const QString &qsName, int nLoopInterval);
    void AddSceneData(const QString &deviceip, int nRoomID, int nGroupSceneID, int nSceneID, int nGroupDisplayID, int nChannelID, int nChannelType, int nCopyIndex,
                      int nLeft, int nTop, int nWidth, int nHeight, int nIPVSegmentationCount, QStringList lstIPVIP,
                      const QString &title, int winid);

    void RemoveGroupScene(const QString &deviceip, int nRoomID, int nGroupID);
    void RemoveScene(const QString &deviceip, int nRoomID, int nGroupID, int nSceneID);
    void RemoveSceneData(const QString &deviceip, int nRoomID, int nGroupID, int nSceneID);

    void UpdateGroupScene(int userid, const QString &deviceip, int id, int nRoomID, int nIsNormalLoop, int nIsLoop, int nLoopInterval, const QString &qsName);
    void UpdateScene(int userid, const QString &deviceip, int id, int nRoomID, int nGroupSceneID, int nIsCycle, const QString &qsName, int nLoopInterval);

    void UpdateSceneSort(int userid, const QString &deviceip, int roomid, int groupid, QMap<int, int> map); // 更新场景的排序，k-v: 场景ID和序列号

    // 自定义通道操作接口
    void AddGroupInputChannel(int userid, const QString &deviceip, int id, const QString &qsName);
    void AddGroupInputChannelMid(int userid, const QString &deviceip, int id, int type, int groupid, const QString &qsName);

    void RemoveGroupInputChannel(int userid, const QString &deviceip, int id);

    void UpdateGroupInputChannel(int userid, const QString &deviceip, int id, const QString &qsName);
    void UpdateGroupInputChannelMid(int userid, const QString &deviceip, int id, int type, int groupid, const QString &qsName);

    // 物理输入通道接口
    void UpdateInputChannel(int userid, const QString &deviceip, int id, int type, const QString &qsName);
    void SetCutArea(int userid, const QString &deviceip, int id, int type, int left, int right, int top, int bottom);

    // 更新房间及屏组名称
    void UpdateRoomName(int userid, const QString &deviceip, int id, const QString &qsName);

    // 更新房间规模，当是LED或者是融合时需要设定不规则尺寸
    void UpdateRoomFormat(const QString &deviceip, int roomid, int roomtype, int arrX, int arrY, int resoluX, int resoluY);

    // 更新房间屏幕开关机配置信息
    void UpdateRoomSwitchConfig(const QString &deviceip, int roomid,
                                int isNet, const QString &ip, int port, const QString &com, int baudrate, int databit, int stopbit, const QString &checkBit, const QString &streamctrl,
                                int type, const QString &cmdon, const QString &cmdoff);

    // 更新房间屏幕是否打开状态
    void UpdateRoomSwitchStatus(const QString &deviceip, int roomid, int n);

    // 更新房间配置
    void UpdateRoomConfig(const QString &deviceip, QList<sRoomConfig> lst);

    // 更新房间虚拟尺寸
    void UpdateRoomVirSize(const QString &deviceip, int id, int useVir, int width, int height, int useVirSeg, int virArrX, int virArrY);

    // 更新房间的LED虚拟尺寸，lst是3的倍数，id ledresolutionX ledresolutionY
    void UpdateRoomLEDSize(const QString &deviceip, int id, QList<int> lst);

    void UpdateDisplayBaseInfo(const QString &deviceip, int roomid, int id, const QString &name, int status, const QString &onCmd, const QString &offCmd);

    // 更新设备IP
    void UpdateRoomIP(const QString &srcIP, const QString &newIP);

    // 更新通道的远程控制IP
    void UpdateInputChannelRemoteIP(const QString &deviceip, int type, int id, const QString &ip);

    // 更新通道的远程控制IP
    void UpdateInputChannelSubTitlePower(const QString &deviceip, int type, int id, int power);

    // -------------------------------------------------------------------------------------------------------------------------------------
    // 用户操作，返回用户信息时3个一组
    // "ID","1", "name":"admin", "password":""
    QStringList GetUsers();
    void AddUser(int id, const QString &usr, const QString &psw, int level);
    void ModifyUser(int id, const QString &usr, const QString &psw, int level);
    void RemoveUser(int id);

    // 任务计划
    QList<sTaskPlanning> GetTaskPlanning(int creatorID = -1);
    void SetTaskPlanning(QList<sTaskPlanning> lst);
    // 添加任务计划，返回计划ID
    int AddTaskPlanning(sTaskPlanning stask);
    // 删除任务计划
    void RemoveTaskPlanning(int id);
    // 修改任务计划
    void ModifyTaskPlanning(sTaskPlanning stask);
    // 清空任务计划
    void ClearTaskPlanning();

    // 用户主菜单索引
    QList<sTab> GetUserMainToolBar(int userid);
    void SetUserMainToolBar(int userid, QList<sTab> lstTab);
    void RemoveUserMainToolBar(int userid, bool bUseTran = true);

    QList<sRoom> GetGroupDisplays(int userid, const QString &deviceip);
    QList<sInputChannel> GetInputChannels(int userid, const QString &deviceip);

    QList<sGroupScene> GetGroupScene(int userid, const QString &deviceip, int roomid);
    QList<sWindowScene> GetWindowScene(int userid, const QString &deviceip, int roomid, int groupid, int sceneid);

    QList<sCustomInputChannel> GetCustomGroupInputChannels(int userid, const QString &deviceip);

    // 矩阵配置
    QList<sMatrix> GetMatrixConfig();
    void SetMatrixConfig(const QList<sMatrix> lstMatrix);
    void SetMatrixName(const QString &ip, int port, const QString &name);
    void SetMatrixSwitch(const QString &ip, int port, int inputid, int outputid);
    // -------------------------------------------------------------------------------------------------------------------------------------

private:
    bool InitDataBase(QString strDatabaseName);

    void ClearTable(const QString &qsTableName);    // 清空表格数据
    void ExecuteSql(const QString &sql);            // 执行SQL

    void UnvalidInputChannel();                     // 将输入通道设置成无效
    void UnvalidGroupDisplay();                     // 将房间和屏组设置成无效

    bool IsExistInputChannel(const QString &deviceip, int pCount, int vCount = 0, int hCount = 0, int veCount = 0);      // 是否存在输入通道

    // 是否存在屏组,lstConfig是屏组的配置，依次是ID, arrayX, arrayY, resolutionX, resolutionY
    bool IsExistGroupDisplay(const QString &deviceip, QList<int> lstConfig);
    int GetGroupDisplayCount(int userid, const QString &deviceip);
    int GetDisplayCount(int userid, const QString &deviceip, int groupid);

    void BuildDeviceInputChannel(int id, int nameid, int type, int boardcardid, int boardcardpos); // 第一个ID为实际ID，第二个ID为名字显示ID
    void BuildInputChannel(int pcCount, int ipvCount, int hdCount, int vCount);
    void BuildGroupDislay(QList<int> lstDeviceConfig, QStringList lstDefaultScene);  // lstDeviceConfig依次是房间ID，排列X、Y，单屏分辨率X、Y

    bool IsExistInputChannel(int userid, const QString &deviceip, int id, int type);    // 判断是否存在输入通道
    bool IsExistRoom(int userid, const QString &deviceip, int id);                      // 判断是否存在房间
    QString IsExistGroupDisplay(int userid, const QString &deviceip, int id);           // 判断是否存在屏组
    bool IsExistDisplay(const QString &qsGroupDisplayGUID, int id);                     // 判断是否存在单屏

    bool IsExistDevice(const QString &deviceip);                                    // 是否存在设备
    bool IsExistDeviceFormat(const QString &deviceip, QList<int> lstConfig);        // 是否存在规模

    QSqlDatabase    m_dbconn;           // 数据库连接
    BCLocalServer   *m_pServer;         // 关联的本地服务器

    void RequestVP2000Config();         // 读取VP2000设备的配置
    void RequestVP4000Config();
    BCLocalTcpSocket    *m_pLocalTcpSocket;     // 通过TCP获取机器配置信息
    BCLocalSerialPort   *m_pLocalSerialPort;    // 通过串口获取机器配置信息

private slots:
    //void onRecvInputChannel(int timeout, QStringList lstData);
    //void onRecvGroupDisplay(int timeout, QStringList lstData);

    /* lstInputChannel
     * 参数是4的整数倍，依次是ID(特殊值可表示不可用)，类型(0:PC 3:HDBase)，X分辨率，Y分辨率
     */
    void onVP4000Config(QStringList lstInputChannel, QStringList lstGroupDisplay, QStringList lstDefaultScene);
    void onVP2000Config(int timeout, int arrX, int arrY, int resX, int resY, int pcCount, int vedioCount, int hdCount);
    void onVP2000IP(int timeout, const QString &ip);
    void onDemoMode();
};

#endif // BCLOCALDATABASE_H
