#include "BCLocalDatabase.h"
#include <QVariant>
#include <QLibrary>
#include <QSqlQuery>
#include <QDebug>
#include <QUuid>
#include "../Common/BCCommon.h"
#include "BCLocalServer.h"
#include "BCLocalTcpSocket.h"
#include "BCLocalSerialPort.h"
#include "../Model/BCMRoom.h"
#include "../Model/BCMGroupDisplay.h"

// 数据库相关宏
#define CONNECTNAME "BSDB"
#define USER        "sa"
#define PASSWORD    "Br123456"

//#define ZHONGDAABOUT    // 关于图标需要显示

BCLocalDatabase::BCLocalDatabase(BCLocalServer *pServer)
{
    m_pServer = pServer;
    m_pLocalTcpSocket = NULL;
    m_pLocalSerialPort = NULL;

    // 初始化创建数据表
    InitDataBase( QString("brLocal.db") );
}

BCLocalDatabase::~BCLocalDatabase()
{
    if ( m_dbconn.isOpen() )
        m_dbconn.close();

    if (NULL != m_pLocalTcpSocket) {
        delete m_pLocalTcpSocket;
        m_pLocalTcpSocket = NULL;
    }

    if (NULL != m_pLocalSerialPort) {
        delete m_pLocalSerialPort;
        m_pLocalSerialPort = NULL;
    }
}

QPoint BCLocalDatabase::Authenticate(const QString &usr, const QString &pwd)
{
    QSqlQuery query( m_dbconn );

    QString sql = QString("SELECT BSID, BSLEVEL FROM BSUSERS WHERE BSUSER = '%1' AND BSPASSWORD = '%2'")
            .arg( usr )
            .arg( pwd );

    query.exec( sql );

    // 如果有记录则返回用户索引
    if ( query.next() ) {
        return QPoint(query.value("BSID").toInt(), query.value("BSLEVEL").toInt());
    }

    // 没找到用户则返回-1
    return QPoint(-1, -1);
}

void BCLocalDatabase::AddGroupScene(int /*userid*/, const QString &deviceip, int id, int nRoomID, int nIsNormalLoop, int nIsLoop, int nLoopInterval, const QString &qsName)
{
    m_dbconn.transaction();

    QSqlQuery query( m_dbconn );

    // 1.判断是否有记录
    query.exec( QString("select 1 from BSGroupScenes where BSID = %1 and bsRoomGUID "
                        "IN (SELECT bsGUID FROM BSRooms WHERE bsId = %2 AND bsDeviceIP = '%3')")
                 .arg( id )
                 .arg( nRoomID )
                 .arg( deviceip ) );

    // 2.如果没有记录则插入数据
    if ( !query.next() ) {
        QString qsGUID = QUuid::createUuid().toString();
        query.exec( QString("INSERT INTO BSGROUPSCENES(bsGUID, bsRoomGUID, BSID, BSNAME, bsIsNormalLoop, BSISLOOP, BSLOOPINTERVAL) "
                            "SELECT '%1', bsGUID, %2, '%3', %4, %5, %6 FROM BSRooms WHERE bsId = %7 AND bsDeviceIP = '%8' ")
                    .arg( qsGUID )
                    .arg( id )
                    .arg( qsName )
                    .arg( nIsNormalLoop )
                    .arg( nIsLoop )
                    .arg( nLoopInterval )
                    .arg( nRoomID )
                    .arg( deviceip ) );
    }

    m_dbconn.commit();
}

void BCLocalDatabase::AddScene(int /*userid*/, const QString &deviceip, int id, int nRoomID, int nGroupSceneID, int nIsCycle, const QString &qsName, int nLoopInterval)
{
    QSqlQuery query( m_dbconn );

    // 1.判断是否有记录
    query.exec( QString("select 1 from BSSCENES where BSID = %1 and bsGroupSceneGUID "
                        "IN (SELECT bsGUID FROM BSGroupScenes WHERE bsId = %2 AND bsRoomGUID "
                        "IN (SELECT bsGUID FROM BSRooms WHERE bsId = %3 AND bsDeviceIP = '%4')) ")
                 .arg( id )
                 .arg( nGroupSceneID )
                 .arg( nRoomID )
                 .arg( deviceip ) );

    // 2.如果没有记录则插入数据
    if ( !query.next() ) {
        // 插入场景数据
        QString qsGUID = QUuid::createUuid().toString();
        query.exec( QString("INSERT INTO BSSCENES(bsGUID, bsGroupSceneGUID, BSID, BSNAME, BSISCYCLE, bsSort, bsLoopInterval) "
                            "SELECT '%1', bsGUID, %2, '%3', %4, 1, %5 FROM BSGroupScenes WHERE bsId = %6 AND bsRoomGUID "
                            "IN (SELECT bsGUID FROM BSRooms WHERE bsId = %7 AND bsDeviceIP = '%8')")
                    .arg( qsGUID )
                    .arg( id )
                    .arg( qsName )
                    .arg( nIsCycle )
                    .arg( nLoopInterval )
                    .arg( nGroupSceneID )
                    .arg( nRoomID )
                    .arg( deviceip ) );
    }
}

void BCLocalDatabase::AddSceneData(const QString &deviceip, int nRoomID, int nGroupSceneID, int nSceneID, int nGroupDisplayID, int nChannelID, int nChannelType, int nCopyIndex,
                                   int nLeft, int nTop, int nWidth, int nHeight, int nIPVSegmentationCount, QStringList lstIPVIP,
                                   const QString &/*title*/, int winid)
{
    QSqlQuery query( m_dbconn );

    QString qsIpv;
    for (int i = 0; i < lstIPVIP.count(); i++) {
        qsIpv.append( lstIPVIP.at(i) );
        if (i != lstIPVIP.count()-1)
            qsIpv.append(";");
    }

    QString sql = QString( "INSERT INTO BSSCENEDATAS(bsGUID, bsSceneGUID, BSGROUPDISPLAYID, bsChannelID, bsCopyIndex, BSLEFT, BSTOP, BSWIDTH, BSHEIGHT, "
                           "bsIPVSegmentation, bsIPVIP, BSWINID, bsChannelType) "
                           "SELECT '%1', bsGUID, %2, %3, %4, %5, %6, %7, %8, "
                           "%9, '%10', %11, %12 "
                           "FROM BSScenes WHERE bsId = %13 AND bsGroupSceneGUID "
                           "IN (SELECT bsGUID FROM BSGroupScenes WHERE bsId = %14 AND bsRoomGUID "
                           "IN (SELECT bsGUID FROM BSRooms WHERE bsId = %15 AND bsDeviceIP = '%16'))")
           .arg( QUuid::createUuid().toString() )
           .arg( nGroupDisplayID )
           .arg( nChannelID )
           .arg( nCopyIndex )
           .arg( nLeft )
           .arg( nTop )
           .arg( nWidth )
           .arg( nHeight )
           .arg( nIPVSegmentationCount )
           .arg( qsIpv )
           .arg( winid )
           .arg( nChannelType )
           .arg( nSceneID )
           .arg( nGroupSceneID )
           .arg( nRoomID )
           .arg( deviceip );

    query.exec( sql );
}

void BCLocalDatabase::RemoveGroupScene(const QString &deviceip, int nRoomID, int nGroupID)
{
    m_dbconn.transaction();

    QSqlQuery query( m_dbconn );

    // 删除场景数据
    query.exec( QString("DELETE FROM BSSceneDatas WHERE bsSceneGUID "
                        "IN (SELECT bsGUID FROM BSSCENES where bsGroupSceneGUID "
                        "IN (SELECT bsGUID FROM BSGroupScenes WHERE bsId = %1 AND bsRoomGUID "
                        "IN (SELECT bsGUID FROM BSRooms WHERE bsId = %2 AND bsDeviceIP = '%3'))) ")
                .arg( nGroupID )
                .arg( nRoomID )
                .arg( deviceip ) );

    // 删除场景
    query.exec( QString("DELETE FROM BSSCENES where bsGroupSceneGUID "
                        "IN (SELECT bsGUID FROM BSGroupScenes WHERE bsId = %1 AND bsRoomGUID "
                        "IN (SELECT bsGUID FROM BSRooms WHERE bsId = %2 AND bsDeviceIP = '%3')) ")
                .arg( nGroupID )
                .arg( nRoomID )
                .arg( deviceip ) );

    // 删除场景组数据
    query.exec( QString("DELETE FROM BSGROUPSCENES WHERE BSID = %1 AND bsRoomGUID "
                        "IN (SELECT bsGUID FROM BSRooms WHERE bsId = %2 AND bsDeviceIP = '%3')")
          .arg( nGroupID )
          .arg( nRoomID )
          .arg( deviceip ) );

    m_dbconn.commit();
}

void BCLocalDatabase::RemoveScene(const QString &deviceip, int nRoomID, int nGroupID, int nSceneID)
{
    m_dbconn.transaction();

    QSqlQuery query( m_dbconn );

    // 删除场景数据
    query.exec( QString("DELETE FROM BSSceneDatas WHERE bsSceneGUID "
                        "IN (SELECT bsGUID FROM BSSCENES where bsId = %1 AND bsGroupSceneGUID "
                        "IN (SELECT bsGUID FROM BSGroupScenes WHERE bsId = %2 AND bsRoomGUID "
                        "IN (SELECT bsGUID FROM BSRooms WHERE bsId = %3 AND bsDeviceIP = '%4'))) ")
                .arg( nSceneID )
                .arg( nGroupID )
                .arg( nRoomID )
                .arg( deviceip ) );

    // 删除场景
    query.exec( QString("DELETE FROM BSSCENES where bsId = %1 AND bsGroupSceneGUID "
                        "IN (SELECT bsGUID FROM BSGroupScenes WHERE bsId = %2 AND bsRoomGUID "
                        "IN (SELECT bsGUID FROM BSRooms WHERE bsId = %3 AND bsDeviceIP = '%4')) ")
                .arg( nSceneID )
                .arg( nGroupID )
                .arg( nRoomID )
                .arg( deviceip ) );

    m_dbconn.commit();
}

void BCLocalDatabase::RemoveSceneData(const QString &deviceip, int nRoomID, int nGroupID, int nSceneID)
{
    QSqlQuery query( m_dbconn );

    // 删除场景数据
    query.exec( QString("DELETE FROM BSSceneDatas WHERE bsSceneGUID "
                        "IN (SELECT bsGUID FROM BSSCENES where bsId = %1 AND bsGroupSceneGUID "
                        "IN (SELECT bsGUID FROM BSGroupScenes WHERE bsId = %2 AND bsRoomGUID "
                        "IN (SELECT bsGUID FROM BSRooms WHERE bsId = %3 AND bsDeviceIP = '%4'))) ")
                .arg( nSceneID )
                .arg( nGroupID )
                .arg( nRoomID )
                .arg( deviceip ) );
}

// 更新场景组
void BCLocalDatabase::UpdateGroupScene(int /*userid*/, const QString &deviceip, int id, int nRoomID, int nIsNormalLoop, int nIsLoop, int nLoopInterval, const QString &qsName)
{
    QSqlQuery query( m_dbconn );

    query.exec( QString("UPDATE BSGroupScenes SET bsIsNormalLoop = %1, BSISLOOP = %2, BSLOOPINTERVAL = %3, BSNAME = '%4' "
                        "WHERE bsId = %5 AND bsRoomGUID "
                        "IN (SELECT bsGUID FROM BSRooms WHERE bsId = %6 AND bsDeviceIP = '%7'))")
                .arg( nIsNormalLoop )
                .arg( nIsLoop )
                .arg( nLoopInterval )
                .arg( qsName )
                .arg( id )
                .arg( nRoomID )
                .arg( deviceip ) );
}

// 更新场景
void BCLocalDatabase::UpdateScene(int /*userid*/, const QString &deviceip, int id, int nRoomID, int nGroupSceneID, int nIsCycle, const QString &qsName, int nLoopInterval)
{
    QSqlQuery query( m_dbconn );

    query.exec( QString("UPDATE BSScenes SET bsIsCycle = %1, BSNAME = '%2', bsLoopInterval = %3 "
                        "WHERE bsId = %4 AND bsGroupSceneGUID "
                        "IN (SELECT bsGUID FROM BSGroupScenes WHERE bsId = %5 AND bsRoomGUID "
                        "IN (SELECT bsGUID FROM BSRooms WHERE bsId = %6 AND bsDeviceIP = '%7'))")
                    .arg( nIsCycle )
                    .arg( qsName )
                    .arg( nLoopInterval )
                    .arg( id )
                    .arg( nGroupSceneID )
                    .arg( nRoomID )
                    .arg( deviceip ) );
}

void BCLocalDatabase::AddGroupInputChannel(int userid, const QString &deviceip, int id, const QString &qsName)
{
    QSqlQuery query( m_dbconn );

    QString sql = QString("INSERT INTO BSCustomGroupInputChannel(bsGUID, bsId, bsDeviceIP, bsUserId, BSNAME, bsSort) "
                          "VALUES('%1', %2, '%3', %4, '%5', 1)")
            .arg( QUuid::createUuid().toString() )
            .arg( id )
            .arg( deviceip )
            .arg( 1 )
            .arg( qsName );

    query.exec( sql );
}

void BCLocalDatabase::AddGroupInputChannelMid(int userid, const QString &deviceip, int id, int type, int groupid, const QString &qsName)
{
    QSqlQuery query( m_dbconn );

    query.exec( QString("INSERT INTO BSCustomGroupInputChannelMid(bsGUID, bsGroupGUID, bsInputChannelGUID, bsInputChannelName) "
                        "SELECT '%1', "
                        "(SELECT bsGUID FROM BSCustomGroupInputChannel WHERE bsUserId = %2 AND bsDeviceIP = '%3' AND bsId = %4), "
                        "bsGUID, '%5' FROM BSInputChannels WHERE bsDeviceIP = '%6' AND bsId = %7 AND bsType = %8 ")
          .arg( QUuid::createUuid().toString() )
          .arg( 1 )
          .arg( deviceip )
          .arg( groupid )
          .arg( qsName )
          .arg( deviceip )
          .arg( id )
          .arg( type ) );
}

// 删除自定义通道组
void BCLocalDatabase::RemoveGroupInputChannel(int /*userid*/, const QString &deviceip, int id)
{
    m_dbconn.transaction();

    QSqlQuery query( m_dbconn );

    query.exec( QString("DELETE FROM BSCustomGroupInputChannelMid WHERE bsGroupGUID "
                        "IN (SELECT bsGUID FROM BSCustomGroupInputChannel WHERE bsId = %1 AND bsDeviceIP = '%2' AND bsUserId = %3) ")
                .arg( id ).arg( deviceip ).arg( 1 ) );

    query.exec( QString("DELETE FROM BSCustomGroupInputChannel WHERE bsId = %1 AND bsDeviceIP = '%2' AND bsUserId = %3 ")
                .arg( id ).arg( deviceip ).arg( 1 ) );

    m_dbconn.commit();
}

// 更新自定义通道组
void BCLocalDatabase::UpdateGroupInputChannel(int /*userid*/, const QString &deviceip, int id, const QString &qsName)
{
    QSqlQuery query( m_dbconn );

    query.exec( QString("UPDATE BSCustomGroupInputChannel SET BSNAME = '%1' "
                        "WHERE bsId = %2 AND bsDeviceIP = '%3' AND bsUserId = %4 ")
          .arg( qsName )
          .arg( id )
          .arg( deviceip )
          .arg( 1 ) );
}

// 更新自定义通道中间表
void BCLocalDatabase::UpdateGroupInputChannelMid(int /*userid*/, const QString &deviceip, int id, int type, int groupid, const QString &qsName)
{
    QSqlQuery query( m_dbconn );

    query.exec( QString("UPDATE BSCustomGroupInputChannelMid SET bsInputChannelName = '%1' "
                        "WHERE bsGroupGUID "
                        "IN (SELECT bsGUID FROM BSCustomGroupInputChannel WHERE bsId = %2 AND bsDeviceIP = '%3' AND bsUserId = %4) AND bsInputChannelGUID "
                        "IN (SELECT bsGUID FROM BSInputChannels WHERE bsId = %5 AND bsType = %6 AND bsDeviceIP = '%7')")
          .arg( qsName )
          .arg( groupid )
          .arg( deviceip )
          .arg( 1 )
          .arg( id )
          .arg( type )
          .arg( deviceip ) );
}

bool BCLocalDatabase::IsExistInputChannel(int /*userid*/, const QString &deviceip, int id, int type)
{
    QSqlQuery query( m_dbconn );

    QString sql = QString("SELECT 1 FROM BSINPUTCHANNELS WHERE bsUserID = %1 AND bsDeviceIP = '%2' AND bsId = %3 AND bsType = %4 ")
            .arg( 1 ).arg( deviceip ).arg( id ).arg( type );

    query.exec( sql );

    return query.next();
}

bool BCLocalDatabase::IsExistRoom(int /*userid*/, const QString &deviceip, int id)
{
    QSqlQuery query( m_dbconn );

    QString sql = QString("SELECT 1 FROM BSROOMS WHERE bsUserID = %1 AND bsDeviceIP = '%2' AND BSID = %3 ")
            .arg( 1 ).arg( deviceip ).arg( id );

    query.exec( sql );

    return query.next();
}

QString BCLocalDatabase::IsExistGroupDisplay(int /*userid*/, const QString &deviceip, int id)
{
    QSqlQuery query( m_dbconn );

    QString sql = QString("SELECT bsGUID FROM BSGROUPDISPLAYS "
                          "WHERE bsId = %1 AND bsRoomGUID IN "
                          "(SELECT bsGUID FROM BSRooms WHERE bsUserID = %2 AND bsDeviceIP = '%3') ")
            .arg( id ).arg( 1 ).arg( deviceip );

    query.exec( sql );

    if ( query.next() ) {
        return query.value("bsGUID").toString();
    }

    return QString::null;
}

bool BCLocalDatabase::IsExistDevice(const QString &deviceip)
{
    QSqlQuery query( m_dbconn );

    query.exec( QString("SELECT 1 FROM BSROOMS WHERE bsDeviceIP = '%1'").arg( deviceip ) );

    return query.next();
}

bool BCLocalDatabase::IsExistDisplay(const QString &qsGroupDisplayGUID, int id)
{
    QSqlQuery query( m_dbconn );

    QString sql = QString("SELECT 1 FROM BSDisplays "
                          "WHERE bsId = %1 AND bsGroupDisplayGUID = '%2' ")
            .arg( id ).arg( qsGroupDisplayGUID );

    query.exec( sql );

    return query.next();
}

void BCLocalDatabase::UpdateInputChannel(int /*userid*/, const QString &deviceip, int id, int type, const QString &qsName)
{
    QSqlQuery query( m_dbconn );

    query.exec( QString("UPDATE BSINPUTCHANNELS SET BSNAME = '%1' "
                        "WHERE bsDeviceIP = '%2' AND bsId = %3 AND bsType = %4 ")
          .arg( qsName )
          .arg( deviceip )
          .arg( id )
          .arg( type ) );
}

void BCLocalDatabase::UpdateRoomName(int /*userid*/, const QString &deviceip, int id, const QString &qsName)
{
    QSqlQuery query( m_dbconn );

    query.exec( QString("UPDATE BSRooms SET bsName = '%1'"
                        "WHERE bsId = %2 AND bsDeviceIP = '%3' ")
                .arg( qsName ).arg( id ).arg( deviceip ));
}

void BCLocalDatabase::UpdateRoomFormat(const QString &deviceip, int roomid, int roomtype, int arrX, int arrY, int resoluX, int resoluY)
{
    MainWindow *pMainWindow = BCCommon::Application();
    BCSUser *pCurrentUser = pMainWindow->GetCurrentUser();
    if (NULL == pCurrentUser)
        return;

    m_dbconn.transaction();

    QSqlQuery query( m_dbconn );

    // 更新房间
    query.exec( QString("UPDATE BSRooms SET bsWidth = %1, bsHeight = %2, bsDeviceType = %3 "
                        "WHERE bsId = %4 AND bsDeviceIP = '%5' ")
                .arg( arrX*resoluX )
                .arg( arrY*resoluY )
                .arg( roomtype )
                .arg( roomid )
                .arg( deviceip ));

    // 更新屏组
    query.exec( QString("UPDATE BSGroupDisplays SET bsArrayX = %1, bsArrayY = %2, bsResolutionX = %3, bsResolutionY = %4, "
                        "bsWidth = %5, bsHeight = %6 "
                        "WHERE bsRoomGUID "
                        "IN (SELECT bsGUID FROM BSRooms WHERE bsId = %7 AND bsDeviceIP = '%8')")
                .arg( arrX ).arg( arrY ).arg( resoluX ).arg( resoluY ).arg( arrX*resoluX ).arg( arrY*resoluY ).arg( roomid ).arg( deviceip ));

    if (GetDisplayCount(1, deviceip, roomid) != arrX*arrY) {
        // 删除单屏
        query.exec( QString("DELETE FROM BSDisplays WHERE bsGroupDisplayGUID "
                            "IN (SELECT bsGUID FROM BSGroupDisplays WHERE bsRoomGUID "
                            "IN (SELECT bsGUID FROM BSRooms WHERE bsId = %1 AND bsDeviceIP = '%2')) ")
                    .arg( roomid ).arg( deviceip ));

        // 添加单屏和用户单屏
        for (int y = 0; y < arrY; y++) {
            for (int x = 0; x < arrX; x++) {
                int displayid = (y*arrX) + x;
                QString displayName = QString("%1").arg(y*arrX + x+1, 3, 10, QChar('0'));

                // 添加单屏
                QString qsDisplayGUID = QUuid::createUuid().toString();
                query.exec( QString("INSERT INTO BSDISPLAYS(bsGUID, bsGroupDisplayGUID, BSID, BSNAME, BSRESOLUTIONX, BSRESOLUTIONY, "
                                           "BSLEFT, BSTOP, BSWIDTH, BSHEIGHT, bsLEDResolutionX, bsLEDResolutionY, bsSegmentation) "
                                    "SELECT '%1', bsGUID, %2, '%3', %4, %5, %6, %7, %8, %9, %10, %11, 1 FROM BSGroupDisplays "
                                    "WHERE bsRoomGUID "
                                    "IN (SELECT bsGUID FROM BSRooms WHERE bsId = %12 AND bsDeviceIP = '%13')")
                            .arg( qsDisplayGUID )
                            .arg( displayid )
                            .arg( displayName )
                            .arg( resoluX )
                            .arg( resoluY )
                            .arg( x*resoluX )
                            .arg( y*resoluY )
                            .arg( resoluX )
                            .arg( resoluY )
                            .arg( resoluX )
                            .arg( resoluY )
                            .arg( roomid )
                            .arg( deviceip ));
            }
        }
    } else {
        // 更新单屏
        for (int y = 0; y < arrY; y++) {
            for (int x = 0; x < arrX; x++) {
                int displayid = (y*arrX) + x;
                query.exec( QString("UPDATE BSDISPLAYS SET BSRESOLUTIONX = %1, BSRESOLUTIONY = %2, "
                                    "BSLEFT = %3, BSTOP = %4, BSWIDTH = %5, BSHEIGHT = %6 "
                                    "WHERE bsId = %7 AND bsGroupDisplayGUID "
                                    "IN (SELECT bsGUID FROM BSGroupDisplays WHERE bsRoomGUID "
                                    "IN (SELECT bsGUID FROM BSRooms WHERE bsId = %8 AND bsDeviceIP = '%9'))")
                            .arg( resoluX )
                            .arg( resoluY )
                            .arg( x*resoluX )
                            .arg( y*resoluY )
                            .arg( resoluX )
                            .arg( resoluY )
                            .arg( displayid )
                            .arg( roomid ).arg( deviceip ));
            }
        }
    }

    m_dbconn.commit();
}

void BCLocalDatabase::UpdateRoomSwitchConfig(const QString &deviceip, int roomid,
                                             int isNet, const QString &ip, int port, const QString &com, int baudrate, int databit, int stopbit, const QString &checkBit, const QString &streamctrl,
                                             int type, const QString &cmdon, const QString &cmdoff)
{
    QSqlQuery query( m_dbconn );

    query.exec( QString("UPDATE BSRooms SET bsIsNetConnect = %1, bsSwitchIP = '%2', bsSwitchPort = %3, "
                        "bsSwitchCom = '%4', bsSwitchBaudRate = %5, bsSwitchDataBit = %6, bsSwitchStopBit = %7, bsSwitchCheckBit = '%8', bsSwitchStreamCtrl = '%9', "
                        "bsSwitchCmdType = %10, bsSwitchOnCmd = '%11', bsSwitchOffCmd = '%12' "
                        "WHERE bsId = %13 AND bsDeviceIP = '%14' ")
                .arg( isNet )
                .arg( ip )
                .arg( port )
                .arg( com )
                .arg( baudrate )
                .arg( databit )
                .arg( stopbit )
                .arg( checkBit )
                .arg( streamctrl )
                .arg( type )
                .arg( cmdon )
                .arg( cmdoff )
                .arg( roomid )
                .arg( deviceip ));
}

void BCLocalDatabase::UpdateRoomSwitchStatus(const QString &deviceip, int roomid, int n)
{
    QSqlQuery query( m_dbconn );

    query.exec( QString("UPDATE BSRooms SET bsSwitchStatus = %1 "
                        "WHERE bsId = %2 AND bsDeviceIP = '%3' ")
                .arg( n )
                .arg( roomid )
                .arg( deviceip ));
}

void BCLocalDatabase::UpdateRoomIP(const QString &srcIP, const QString &newIP)
{
    QSqlQuery query( m_dbconn );

    query.exec( QString("UPDATE BSRooms "
                        "SET bsDeviceIP = '%1' "
                        "WHERE bsDeviceIP = '%2' ").arg(newIP).arg(srcIP) );
}

void BCLocalDatabase::UpdateRoomLEDSize(const QString &deviceip, int id, QList<int> lst)
{
    if (0 != (lst.count()%3))
        return;

    m_dbconn.transaction();
    QSqlQuery query( m_dbconn );

    int displayCount = lst.count()/3;
    for (int i = 0; i < displayCount; i++) {
        int displayid = lst.at(3*i+0);
        int resolutionX = lst.at(3*i+1);
        int resolutionY = lst.at(3*i+2);

        // 添加单屏
        query.exec( QString("UPDATE BSDISPLAYS "
                            "SET BSLEDRESOLUTIONX = %1, BSLEDRESOLUTIONY = %2 "
                            "WHERE BSID = %3 AND bsGroupDisplayGUID IN "
                            "(SELECT bsGUID FROM BSGROUPDISPLAYS WHERE bsRoomGUID = "
                            "(SELECT bsGUID FROM BSROOMS WHERE bsDeviceIP = '%4' AND bsId = %5))")
                    .arg( resolutionX )
                    .arg( resolutionY )
                    .arg( displayid )
                    .arg( deviceip )
                    .arg( id ) );
    }

    m_dbconn.commit();
}

void BCLocalDatabase::UpdateRoomVirSize(const QString &deviceip, int id, int useVir, int virWidth, int virHeight, int useVirSeg, int virArrX, int virArrY)
{
    m_dbconn.transaction();
    QSqlQuery query( m_dbconn );

    query.exec( QString("SELECT A.bsGUID, B.bsGUID groupGUID, A.bsWidth, A.bsHeight, B.bsArrayX, B.bsArrayY, B.bsResolutionX, B.bsResolutionY "
                        "FROM BSROOMS A, BSGroupDisplays B "
                        "WHERE A.bsGUID = B.bsRoomGUID AND A.bsDeviceIP = '%1' AND A.bsId = %2 ")
                .arg( deviceip )
                .arg( id ));

    if ( query.next() ) {
        QString qsRoomGUID = query.value("bsGUID").toString();
        QString qsGroupGUID = query.value("groupGUID").toString();
        int formatx = query.value("bsArrayX").toInt();
        int formaty = query.value("bsArrayY").toInt();
        int resolutionx = query.value("bsResolutionX").toInt();
        int resolutiony = query.value("bsResolutionY").toInt();

        int xsize = formatx * resolutionx;
        int ysize = formaty * resolutiony;

        int xsizeSrc = query.value("bsWidth").toInt();
        int ysizeSrc = query.value("bsHeight").toInt();

        // 更新房间
        query.exec( QString("UPDATE BSROOMS "
                            "SET bsIsUseVirtualResotluion = %1, bsVirWidth = %2, bsVirHeight = %3 "
                            "WHERE bsGUID = '%4' ")
                    .arg( useVir )
                    .arg( virWidth )
                    .arg( virHeight )
                    .arg( qsRoomGUID ));

        // 是否使用虚拟分割
        if (1 == useVirSeg) {
            formatx = virArrX;
            formaty = virArrY;
        }

        // 如果是使用虚拟分辨率则取虚拟分辨率的值
        if (1 == useVir){
            resolutionx = virWidth / formatx;
            resolutiony = virHeight / formaty;

            xsize = virWidth;
            ysize = virHeight;
        } else {
            xsize = xsizeSrc;
            ysize = ysizeSrc;

            resolutionx = xsize / formatx;
            resolutiony = ysize / formaty;
        }

        query.exec( QString("UPDATE BSGROUPDISPLAYS "
                            "SET BSRESOLUTIONX = %1, BSRESOLUTIONY = %2, BSWIDTH = %3, BSHEIGHT = %4, "
                            "bsIsUseVirtualArray = %5, bsVirArrayX = %6, bsVirArrayY = %7 "
                            "WHERE bsRoomGUID = '%8' " )
                    .arg( resolutionx )
                    .arg( resolutiony )
                    .arg( xsize )
                    .arg( ysize )
                    .arg( useVirSeg )
                    .arg( virArrX )
                    .arg( virArrY )
                    .arg( qsRoomGUID ) );

        // 删除单屏表
        query.exec( QString("DELETE FROM BSDisplays WHERE bsGroupDisplayGUID = '%1'")
                    .arg( qsGroupGUID ));
        // 添加单屏
        for (int y = 0; y < formaty; y++) {
            for (int x = 0; x < formatx; x++) {
                int displayid = (y*formatx) + x;
                QString displayName = QString("%1").arg(y*formatx + x+1, 3, 10, QChar('0'));

                // 添加单屏
                QString qsDisplayGUID = QUuid::createUuid().toString();
                query.exec( QString("INSERT INTO BSDISPLAYS(bsGUID, bsGroupDisplayGUID, BSID, BSNAME, BSRESOLUTIONX, BSRESOLUTIONY, "
                                           "BSLEFT, BSTOP, BSWIDTH, BSHEIGHT, bsLEDResolutionX, bsLEDResolutionY, bsSegmentation) "
                                      "VALUES ('%1', '%2', %3, '%4', %5, %6, %7, %8, %9, %10, %11, %12, 4)")
                            .arg( qsDisplayGUID )
                            .arg( qsGroupGUID )
                            .arg( displayid )
                            .arg( displayName )
                            .arg( resolutionx )
                            .arg( resolutiony )
                            .arg( x*resolutionx )
                            .arg( y*resolutiony )
                            .arg( resolutionx )
                            .arg( resolutiony )
                            .arg( resolutionx )
                            .arg( resolutiony ) );
            }
        }
    }

    m_dbconn.commit();
}

void BCLocalDatabase::UpdateRoomConfig(const QString &deviceip, QList<sRoomConfig> lst)
{
    MainWindow *pMainWindow = BCCommon::Application();
    BCSUser *pCurrentUser = pMainWindow->GetCurrentUser();
    if (NULL == pCurrentUser)
        return;

    bool bRebuild = true;
    QList<BCMRoom *> lstMRoom = pMainWindow->GetMRooms();
    if (lstMRoom.count() == lst.count()) {
        for (int i = 0; i < lst.count(); i++) {
            sRoomConfig sroom = lst.at( i );

            int groupid = sroom.id;
            int formatx = sroom.arrayX;
            int formaty = sroom.arrayY;
            int resolutionx = sroom.resolutionX;
            int resolutiony = sroom.resolutionY;

            bRebuild = true;
            for (int j = 0; j < lstMRoom.count(); j++) {
                BCMRoom *pRoom = lstMRoom.at( j );
                int roomid = pRoom->GetRoomID();
                if (roomid != groupid)
                    continue;

                BCMGroupDisplay *pGroupDisplay = pRoom->GetGroupDisplay( roomid );
                if (NULL == pGroupDisplay)
                    continue;

                QSize array = pGroupDisplay->GetArraySize();
                QSizeF size = pRoom->GetWallSize( false );
                if ((formatx == array.width()) && (formaty == array.height()) &&
                        (resolutionx*formatx == size.width()) && (resolutiony*formaty == size.height())) {
                    bRebuild = false;
                    break;
                }
            }

            if ( bRebuild )
                break;
        }
    } else {
        bRebuild = true;
    }

    // 1.如果规模变化则重构
    // 2.如果规模没发生变化则修改其他字段

    m_dbconn.transaction();
    QSqlQuery query( m_dbconn );

    if ( bRebuild ) {
        // 1.删除数据

        // 删除单屏表
        query.exec( QString("DELETE FROM BSDisplays WHERE bsGroupDisplayGUID "
                            "IN (SELECT bsGUID FROM BSGroupDisplays WHERE bsRoomGUID "
                            "IN (SELECT bsGUID FROM BSRooms WHERE bsDeviceIP = '%1'))")
                    .arg( deviceip ));
        // 删除屏组表
        query.exec( QString("DELETE FROM BSGroupDisplays WHERE bsRoomGUID "
                            "IN (SELECT bsGUID FROM BSRooms WHERE bsDeviceIP = '%1')")
                    .arg( deviceip ));

        // 删除房间表
        query.exec( QString("DELETE FROM BSRooms WHERE bsDeviceIP = '%1'")
                    .arg( deviceip ));

        // 2.添加新数据

        // 返回输入通道数据
        for (int i = 0; i < lst.count(); i++) {
            sRoomConfig sroom = lst.at( i );

            int groupid = sroom.id;
            int formatx = sroom.arrayX;
            int formaty = sroom.arrayY;
            int resolutionx = sroom.resolutionX;
            int resolutiony = sroom.resolutionY;

            int xsize = formatx * resolutionx;
            int ysize = formaty * resolutiony;

            // 添加房间
            QString qsRoomGUID = QUuid::createUuid().toString();
            query.exec( QString("INSERT INTO BSROOMS(bsGUID, BSID, bsDeviceIP, bsDeviceType, BSNAME, BSWIDTH, BSHEIGHT, bsIsUseVirtualResotluion, bsVirWidth, bsVirHeight, "
                                "bsIsNetConnect, bsSwitchIP, bsSwitchPort, bsSwitchCom, bsSwitchBaudRate, bsSwitchDataBit, "
                                "bsSwitchStopBit, bsSwitchCheckBit, bsSwitchStreamCtrl, bsSwitchCmdType, bsSwitchOnCmd, bsSwitchOffCmd, bsSwitchStatus) "
                                  "VALUES ('%1', %2, '%3', %4, '%5', %6, %7, %8, %9, %10, "
                                "1, '', 9000, 'COM1', 9600, 8, 1, 'None', 'None', 1, '', '', 1)")
                        .arg( qsRoomGUID )
                        .arg( groupid )
                        .arg( deviceip )
                        .arg( sroom.type )
                        .arg( sroom.name )
                        .arg( xsize )
                        .arg( ysize )
                        .arg( sroom.isUseVir )
                        .arg( sroom.virWidth )
                        .arg( sroom.virHeight ));

            // 是否使用虚拟分割
            if (1 == sroom.isUseVirSeg) {
                formatx = sroom.virArrX;
                formaty = sroom.virArrY;
            }

            // 如果是使用虚拟分辨率则取虚拟分辨率的值
            if (1 == sroom.isUseVir) {
                resolutionx = sroom.virWidth / formatx;
                resolutiony = sroom.virHeight / formaty;

                xsize = sroom.virWidth;
                ysize = sroom.virHeight;
            }

            // 添加屏组
            QString qsGroupDisplayGUID = QUuid::createUuid().toString();
            query.exec( QString("INSERT INTO BSGROUPDISPLAYS(bsGUID, bsRoomGUID, BSID, BSNAME, BSARRAYX, BSARRAYY, BSRESOLUTIONX, BSRESOLUTIONY, "
                                  "BSSEGMENTATIONX, BSSEGMENTATIONY, BSLEFT, BSTOP, BSWIDTH, BSHEIGHT, bsIsUseVirtualArray, bsVirArrayX, bsVirArrayY ) "
                                  "VALUES ('%1', '%2', %3, '%4', %5, %6, %7, %8, %9, %10, %11, %12, %13, %14, %15, %16, %17)")
                        .arg( qsGroupDisplayGUID )
                        .arg( qsRoomGUID )
                        .arg( groupid )
                        .arg( sroom.name )
                        .arg( formatx )
                        .arg( formaty )
                        .arg( resolutionx )
                        .arg( resolutiony )
                        .arg( formatx )
                        .arg( formaty )
                        .arg( 0 )
                        .arg( 0 )
                        .arg( xsize )
                        .arg( ysize )
                        .arg( sroom.isUseVirSeg )
                        .arg( sroom.virArrX )
                        .arg( sroom.virArrY ) );

            // 添加单屏
            for (int y = 0; y < formaty; y++) {
                for (int x = 0; x < formatx; x++) {
                    int displayid = (y*formatx) + x;
                    QString displayName = QString("%1").arg(y*formatx + x+1, 3, 10, QChar('0'));

                    // 添加单屏
                    QString qsDisplayGUID = QUuid::createUuid().toString();
                    query.exec( QString("INSERT INTO BSDISPLAYS(bsGUID, bsGroupDisplayGUID, BSID, BSNAME, BSRESOLUTIONX, BSRESOLUTIONY, "
                                               "BSLEFT, BSTOP, BSWIDTH, BSHEIGHT, bsLEDResolutionX, bsLEDResolutionY, bsSegmentation) "
                                          "VALUES ('%1', '%2', %3, '%4', %5, %6, %7, %8, %9, %10, %11, %12, 4)")
                                .arg( qsDisplayGUID )
                                .arg( qsGroupDisplayGUID )
                                .arg( displayid )
                                .arg( displayName )
                                .arg( resolutionx )
                                .arg( resolutiony )
                                .arg( x*resolutionx )
                                .arg( y*resolutiony )
                                .arg( resolutionx )
                                .arg( resolutiony )
                                .arg( resolutionx )
                                .arg( resolutiony ) );
                }
            }
        }
    } else {
        // 返回输入通道数据
        for (int i = 0; i < lst.count(); i++) {
            sRoomConfig sroom = lst.at( i );

            int groupid = sroom.id;
            int formatx = sroom.arrayX;
            int formaty = sroom.arrayY;
            int resolutionx = sroom.resolutionX;
            int resolutiony = sroom.resolutionY;

            // 添加房间
            query.exec( QString("UPDATE BSROOMS "
                                "SET bsDeviceType = %1, BSNAME = '%2', bsIsUseVirtualResotluion = %3, bsVirWidth = %4, bsVirHeight = %5 "
                                "WHERE bsDeviceIP = '%6' AND BSID = %7 ")
                        .arg( sroom.type )
                        .arg( sroom.name )
                        .arg( sroom.isUseVir )
                        .arg( sroom.virWidth )
                        .arg( sroom.virHeight )
                        .arg( deviceip )
                        .arg( groupid ) );

            // 是否使用虚拟分屏
            if (1 == sroom.isUseVirSeg) {
                formatx = sroom.virArrX;
                formaty = sroom.virArrY;
            }

            int xsize = formatx * resolutionx;
            int ysize = formaty * resolutiony;

            // 如果是使用虚拟分辨率则取虚拟分辨率的值
            if (1 == sroom.isUseVir) {
                resolutionx = sroom.virWidth / formatx;
                resolutiony = sroom.virHeight / formaty;

                xsize = sroom.virWidth;
                ysize = sroom.virHeight;
            }

            // 添加屏组
            query.exec( QString("UPDATE BSGROUPDISPLAYS "
                                "SET BSNAME = '%1', BSRESOLUTIONX = %2, BSRESOLUTIONY = %3, BSWIDTH = %4, BSHEIGHT = %5, "
                                "bsIsUseVirtualArray = %6, bsVirArrayX = %7, bsVirArrayY = %8 "
                                "WHERE bsRoomGUID IN (SELECT bsGUID FROM BSROOMS WHERE bsDeviceIP = '%9' AND BSID = %10)" )
                        .arg( sroom.name )
                        .arg( resolutionx )
                        .arg( resolutiony )
                        .arg( xsize )
                        .arg( ysize )
                        .arg( sroom.isUseVirSeg )
                        .arg( sroom.virArrX )
                        .arg( sroom.virArrY )
                        .arg( deviceip )
                        .arg( groupid ) );

            // 添加单屏
            for (int y = 0; y < formaty; y++) {
                for (int x = 0; x < formatx; x++) {
                    int displayid = (y*formatx) + x;
                    // 添加单屏
                    query.exec( QString("UPDATE BSDISPLAYS "
                                        "SET BSRESOLUTIONX = %1, BSRESOLUTIONY = %2, BSLEFT = %3, BSTOP = %4, BSWIDTH = %5, BSHEIGHT = %6 "
                                        "WHERE BSID = %7 AND bsGroupDisplayGUID IN (SELECT bsGUID FROM BSGROUPDISPLAYS "
                                        "   WHERE bsRoomGUID IN (SELECT bsGUID FROM BSROOMS WHERE bsDeviceIP = '%8' AND BSID = %9))")
                                .arg( resolutionx )
                                .arg( resolutiony )
                                .arg( x*resolutionx )
                                .arg( y*resolutiony )
                                .arg( resolutionx )
                                .arg( resolutiony )
                                .arg( displayid )
                                .arg( deviceip )
                                .arg( groupid ) );
                }
            }
        }
    }

    m_dbconn.commit();
}

void BCLocalDatabase::SetCutArea(int /*userid*/, const QString &deviceip, int id, int type, int left, int right, int top, int bottom)
{
    QSqlQuery query( m_dbconn );

    // 切割范围所有用户共用
    QString sql = QString("UPDATE BSINPUTCHANNELS SET bsCutLeft = %1, bsCutRight = %2, bsCutTop = %3, bsCutBottom = %4 "
                          "WHERE bsDeviceIP = '%5' AND bsId = %6 AND bsType = %7 ")
            .arg(left)
            .arg(right)
            .arg(top)
            .arg(bottom)
            //.arg(userid)
            .arg(deviceip)
            .arg(id)
            .arg(type);

    query.exec( sql );
}

void BCLocalDatabase::UpdateSceneSort(int userid, const QString &deviceip, int roomid, int groupid, QMap<int, int> map)
{
    m_dbconn.transaction();

    QSqlQuery query( m_dbconn );

    QList<int> lst = map.keys();
    for (int i = 0; i < lst.count(); i++) {
        int id = lst.at(i);
        int sort = map.value(id);

        query.exec( QString("UPDATE BSScenes SET bsSort = %1 "
                            "WHERE bsId = %2 AND bsGroupSceneGUID "
                            "IN (SELECT bsGUID FROM BSGroupScenes WHERE bsId = %3 AND bsRoomGUID "
                            "IN (SELECT bsGUID FROM BSRooms WHERE bsId = %4 AND bsDeviceIP = '%5')) ")
              .arg(sort)
              .arg(id)
              .arg(groupid)
              .arg(roomid)
              .arg(deviceip) );
    }

    m_dbconn.commit();
}

// -----------------------------------------------------------------------------------------------------------------
QStringList BCLocalDatabase::GetUsers()
{
    QSqlQuery query( m_dbconn );

    QString sql = QString("SELECT A.bsId, A.bsUser, A.bsPassword, A.bsLevel "
                          "FROM BSUsers A ");

    query.exec( sql );

    // 循环返回结果
    QStringList lstRes;
    while ( query.next() ) {
        QString qsID = query.value("bsId").toString();
        QString qsUser = query.value("bsUser").toString();
        QString qsPassword = query.value("bsPassword").toString();
        QString qsLevel = query.value("bsLevel").toString();

        lstRes << qsID << qsUser << qsPassword << qsLevel;
    }

    return lstRes;
}

void BCLocalDatabase::AddUser(int id, const QString &usr, const QString &psw, int level)
{
    QSqlQuery query( m_dbconn );

    QString sql = QString("INSERT INTO BSUSERS(BSID, BSUSER, BSPASSWORD, BSLEVEL) VALUES(%1, '%2', '%3', %4)")
            .arg(id).arg(usr).arg(psw).arg(level);

    query.exec( sql );
}

void BCLocalDatabase::ModifyUser(int id, const QString &usr, const QString &psw, int level)
{
    QSqlQuery query( m_dbconn );

    QString sql = (-1 == level) ?
                QString("UPDATE BSUSERS SET BSUSER = '%1', BSPASSWORD = '%2' "
                          "WHERE BSID = %3 ")
            .arg(usr).arg(psw).arg(id)
              :
                QString("UPDATE BSUSERS SET BSUSER = '%1', BSPASSWORD = '%2', BSLEVEL = %3 "
                          "WHERE BSID = %4 ")
            .arg(usr).arg(psw).arg(level).arg(id);

    query.exec( sql );
}

void BCLocalDatabase::RemoveUser(int id)
{
    QSqlQuery query( m_dbconn );

    QString sql = QString("DELETE FROM BSUSERS WHERE BSID = %1")
            .arg(id);

    query.exec( sql );

    // 清除用户权限
    RemoveUserMainToolBar( id );
}

// 任务计划
QList<sTaskPlanning> BCLocalDatabase::GetTaskPlanning(int creatorID)
{
    QList<sTaskPlanning> lstRes;

    QSqlQuery query( m_dbconn );

    QString sql = QString("SELECT A.bsID, A.bsTaskType, A.bsCycle, A.bsExecTime, A.bsCreatorID, A.bsCreateTime, A.bsRoomType, A.bsRoomID, "
                          "A.bsSceneID "
                          "FROM BSTaskPlanning A ");

    // 如果限制了创建人则添加条件限制
    if (-1 != creatorID) {
        sql += QString("WHERE A.bsCreatorID = %1 ").arg(creatorID);
    }

    query.exec( sql );

    // 循环返回结果
    while ( query.next() ) {
        sTaskPlanning stask;
        stask.id = query.value("bsID").toInt();
        stask.taskType = query.value("bsTaskType").toInt();
        stask.cycle = query.value("bsCycle").toString();
        stask.time = query.value("bsExecTime").toString();
        stask.creatorID = query.value("bsCreatorID").toInt();
        stask.createTime = query.value("bsCreateTime").toString();
        stask.roomType = query.value("bsRoomType").toInt();
        stask.roomID = query.value("bsRoomID").toInt();
        stask.sceneID = query.value("bsSceneID").toInt();
        stask.bExec = false;

        lstRes.append( stask );
    }

    return lstRes;
}

void BCLocalDatabase::SetTaskPlanning(QList<sTaskPlanning> lst)
{
    m_dbconn.transaction();

    QSqlQuery query( m_dbconn );

    // 1.清空数据
    query.exec( QString("DELETE FROM BSTaskPlanning") );

    // 2.循环添加数据
    for (int i = 0; i < lst.count(); i++) {
        sTaskPlanning stask = lst.at(i);

        query.exec( QString("INSERT INTO BSTaskPlanning(bsTaskType, bsCycle, bsExecTime, bsCreatorID, bsCreateTime, bsRoomType, bsRoomID, "
                                "bsSceneID, bsID) "
                            "VALUES(%1, '%2', '%3', %4, '%5', %6, %7, "
                                "%8, %9) ")
                    .arg(stask.taskType).arg(stask.cycle).arg(stask.time).arg(stask.creatorID).arg(stask.createTime).arg(stask.roomType).arg(stask.roomID)
                    .arg(stask.sceneID).arg(stask.id));
    }

    m_dbconn.commit();
}

// 添加任务计划，返回计划ID
int BCLocalDatabase::AddTaskPlanning(sTaskPlanning stask)
{
    m_dbconn.transaction();

    QSqlQuery query( m_dbconn );

    // 1.获取任务的ID值，从0开始，自动增加
    QList<int> lstID;
    query.exec( QString("SELECT bsID FROM BSTaskPlanning") );
    while ( query.next() ) {
        lstID.append( query.value("bsID").toInt() );
    }

    int id = 0;
    for (int i = 0; i < lstID.count()+1; i++) {
        if (lstID.contains(i))
            continue;

        id = i;
        break;
    }

    // 2.插入任务计划数据
    query.exec( QString("INSERT INTO BSTaskPlanning(bsTaskType, bsCycle, bsExecTime, bsCreatorID, bsCreateTime, bsRoomType, bsRoomID, "
                            "bsSceneID, bsID) "
                        "VALUES(%1, '%2', '%3', %4, '%5', %6, %7, "
                            "%8, %9) ")
                .arg(stask.taskType).arg(stask.cycle).arg(stask.time).arg(stask.creatorID).arg(stask.createTime).arg(stask.roomType).arg(stask.roomID)
                .arg(stask.sceneID).arg(id));

    m_dbconn.commit();

    return id;
}

// 删除任务计划
void BCLocalDatabase::RemoveTaskPlanning(int id)
{
    QSqlQuery query( m_dbconn );

    query.exec( QString("DELETE FROM BSTaskPlanning WHERE bsID = %1").arg(id) );
}

void BCLocalDatabase::ModifyTaskPlanning(sTaskPlanning stask)
{
    QSqlQuery query( m_dbconn );

    QString sql = QString("UPDATE BSTaskPlanning "
                          "SET bsTaskType = %1, bsCycle = '%2', bsExecTime = '%3', bsCreatorID = %4, bsCreateTime = '%5', bsRoomType = %6, "
                          "bsRoomID = %7, bsSceneID = %8 "
                          "WHERE bsID = %9 ")
            .arg( stask.taskType ).arg( stask.cycle ).arg( stask.time ).arg( stask.creatorID ).arg( stask.createTime )
            .arg( stask.roomType ).arg( stask.roomID ).arg( stask.sceneID ).arg( stask.id );

    query.exec( sql );

}

void BCLocalDatabase::ClearTaskPlanning()
{
    QSqlQuery query( m_dbconn );

    query.exec( QString("DELETE FROM BSTaskPlanning") );
}

QList<sTab> BCLocalDatabase::GetUserMainToolBar(int userid)
{
    QList<sTab> lstTab;

    m_dbconn.transaction();

    QSqlQuery query1( m_dbconn );
    QSqlQuery query2( m_dbconn );
    QSqlQuery query3( m_dbconn );

    query1.exec( QString("SELECT bsGUID, BSTAB FROM BSMainToolBarTab WHERE bsUserId = '%1' ").arg(userid) );
    while ( query1.next() ) {
        int tab = query1.value("BSTAB").toInt();
        QString tabGUID = query1.value("bsGUID").toString();

        sTab stab;
        stab.tab = tab;

        query2.exec( QString("SELECT bsGUID, BSGROUP FROM BSMainToolBarGroup WHERE bsTabGUID = '%1' ").arg(tabGUID) );
        while ( query2.next() ) {
            int group = query2.value("BSGROUP").toInt();
            QString groupGUID = query2.value("bsGUID").toString();

            sGroup sgroup;
            sgroup.group = group;

            query3.exec( QString("SELECT BSBUTTON FROM BSMainToolBarButton WHERE bsGroupGUID = '%1' ").arg(groupGUID) );
            while ( query3.next() ) {
                int button = query3.value("BSBUTTON").toInt();

                sgroup.lstButton.append( button );
            }

            stab.lstGroup.append( sgroup );
        }

        lstTab.append( stab );
    }

    m_dbconn.commit();

    return lstTab;
}

void BCLocalDatabase::SetUserMainToolBar(int userid, QList<sTab> lstTab)
{
    m_dbconn.transaction();

    QSqlQuery query( m_dbconn );

    QString sql;

    // 清空权限
    RemoveUserMainToolBar(userid, false);

    // 添加权限
    for (int i = 0; i < lstTab.count(); i++) {
        sTab stab = lstTab.at(i);
        int tab = stab.tab;

        // insert tab
        QString qsTabGUID = QUuid::createUuid().toString();
        sql = QString("INSERT INTO BSMainToolBarTab(bsGUID, bsUserId, bsTab) "
                      "VALUES ('%1', %2, %3) ")
                .arg( qsTabGUID ).arg( userid ).arg( tab );
        query.exec( sql );

        for (int j = 0; j < stab.lstGroup.count(); j++) {
            sGroup sgroup = stab.lstGroup.at(j);
            int group = sgroup.group;

            // insert group
            QString qsGroupGUID = QUuid::createUuid().toString();
            sql = QString("INSERT INTO BSMainToolBarGroup(bsGUID, bsTabGUID, bsGroup) "
                          "VALUES ('%1', '%2', %3) ")
                    .arg( qsGroupGUID ).arg( qsTabGUID ).arg( group );
            query.exec( sql );

            for (int k = 0; k < sgroup.lstButton.count(); k++) {
                int button = sgroup.lstButton.at(k);

                // insert button
                sql = QString("INSERT INTO BSMainToolBarButton(bsGUID, bsGroupGUID, bsButton) "
                              "VALUES ('%1', '%2', %3) ")
                        .arg( QUuid::createUuid().toString() ).arg( qsGroupGUID ).arg( button );
                query.exec( sql );
            }
        }
    }

    m_dbconn.commit();
}

void BCLocalDatabase::RemoveUserMainToolBar(int userid, bool bUseTran)
{
    if ( bUseTran )
        m_dbconn.transaction();

    QSqlQuery query( m_dbconn );

    QString sql;

    // 清空权限
    sql = QString("DELETE FROM BSMainToolBarButton WHERE bsGroupGUID IN "
                  "(SELECT B.bsGUID FROM BSMainToolBarTab A, BSMainToolBarGroup B "
                  "WHERE A.bsGUID = B.bsTabGUID AND A.bsUserId = %1)").arg( userid );
    query.exec( sql );

    sql = QString("DELETE FROM BSMainToolBarGroup WHERE bsTabGUID IN "
                  "(SELECT bsGUID FROM BSMainToolBarTab "
                  "WHERE bsUserId = %1)").arg( userid );
    query.exec( sql );

    sql = QString("DELETE FROM BSMainToolBarTab WHERE bsUserId = %1 ").arg( userid );
    query.exec( sql );

    if ( bUseTran )
        m_dbconn.commit();
}

QList<sRoom> BCLocalDatabase::GetGroupDisplays(int /*userid*/, const QString &deviceip)
{
    // 返回结果
    QList<sRoom> lstRoom;

    m_dbconn.transaction();

    // 查询房间数据
    QSqlQuery query1( m_dbconn );
    QSqlQuery query2( m_dbconn );
    QSqlQuery query3( m_dbconn );

    query1.exec( QString("SELECT A.bsGUID, A.BSID, A.bsDeviceType, A.BSNAME, A.BSWIDTH, A.BSHEIGHT, A.bsIsUseVirtualResotluion, A.bsVirWidth, A.bsVirHeight, "
                         "A.bsIsNetConnect, A.bsSwitchIP, A.bsSwitchPort, A.bsSwitchCom, A.bsSwitchBaudRate, A.bsSwitchDataBit, A.bsSwitchStopBit, A.bsSwitchCheckBit, A.bsSwitchStreamCtrl, "
                         "A.bsSwitchCmdType, A.bsSwitchOnCmd, A.bsSwitchOffCmd, A.bsSwitchStatus "
                        "FROM BSROOMS A "
                        "WHERE A.bsDeviceIP = '%1' ").arg( deviceip ));

    // 循环房间
    while ( query1.next() ) {
        sRoom sroom;
        sroom.id = query1.value("BSID").toInt();
        sroom.type = query1.value("bsDeviceType").toInt();
        sroom.name = query1.value("BSNAME").toString();
        sroom.width = query1.value("BSWIDTH").toInt();
        sroom.height = query1.value("BSHEIGHT").toInt();
        sroom.isUseVir = query1.value("bsIsUseVirtualResotluion").toInt();
        sroom.virWidth = query1.value("bsVirWidth").toInt();
        sroom.virHeight = query1.value("bsVirHeight").toInt();
        sroom.isNetConnect = query1.value("bsIsNetConnect").toInt();
        sroom.switchip = query1.value("bsSwitchIP").toString();
        sroom.switchport = query1.value("bsSwitchPort").toInt();
        sroom.switchCom = query1.value("bsSwitchCom").toString();
        sroom.switchBaudRate = query1.value("bsSwitchBaudRate").toInt();
        sroom.switchDataBit = query1.value("bsSwitchDataBit").toInt();
        sroom.switchStopBit = query1.value("bsSwitchStopBit").toInt();
        sroom.switchCheckBit = query1.value("bsSwitchCheckBit").toString();
        sroom.switchStreamCtrl = query1.value("bsSwitchStreamCtrl").toString();
        sroom.switchtype = query1.value("bsSwitchCmdType").toInt();
        sroom.switchoncmd = query1.value("bsSwitchOnCmd").toString();
        sroom.switchoffcmd = query1.value("bsSwitchOffCmd").toString();
        sroom.switchStatus = query1.value("bsSwitchStatus").toInt();
        QString qsRoomGUID = query1.value("bsGUID").toString();

        query2.exec( QString("SELECT bsGUID, BSID, BSNAME, BSLEFT, BSTOP, BSWIDTH, BSHEIGHT, BSARRAYX, BSARRAYY, bsIsUseVirtualArray, bsVirArrayX, bsVirArrayY, "
                             "BSRESOLUTIONX, BSRESOLUTIONY, BSSEGMENTATIONX, BSSEGMENTATIONY "
                             "FROM BSGROUPDISPLAYS "
                             "WHERE bsRoomGUID = '%1' ")
                    .arg( qsRoomGUID ));

        // 循环屏组
        while ( query2.next() ) {
            sGroupDisplay sgroupdisplay;
            sgroupdisplay.id = query2.value("BSID").toInt();
            sgroupdisplay.name = query2.value("BSNAME").toString();
            sgroupdisplay.left = query2.value("BSLEFT").toDouble();
            sgroupdisplay.top = query2.value("BSTOP").toDouble();
            sgroupdisplay.width = query2.value("BSWIDTH").toInt();
            sgroupdisplay.height = query2.value("BSHEIGHT").toInt();
            sgroupdisplay.arrayX = query2.value("BSARRAYX").toInt();
            sgroupdisplay.arrayY = query2.value("BSARRAYY").toInt();
            sgroupdisplay.isUseVir = query2.value("bsIsUseVirtualArray").toInt();
            sgroupdisplay.virX = query2.value("bsVirArrayX").toInt();
            sgroupdisplay.virY = query2.value("bsVirArrayY").toInt();
            sgroupdisplay.resolutionX = query2.value("BSRESOLUTIONX").toInt();
            sgroupdisplay.resolutionY = query2.value("BSRESOLUTIONY").toInt();
            sgroupdisplay.segmentationX = query2.value("BSSEGMENTATIONX").toInt();
            sgroupdisplay.segmentationY = query2.value("BSSEGMENTATIONY").toInt();

            QString qsGroupDisplayGUID = query2.value("bsGUID").toString();

            query3.exec( QString("SELECT A.BSID, A.BSNAME, A.BSLEFT, A.BSTOP, A.BSRESOLUTIONX, A.BSRESOLUTIONY, A.bsSegmentation, "
                                 "A.bsSwitchStatus, A.bsOnCmd, A.bsOffCmd, A.bsLEDResolutionX, A.bsLEDResolutionY "
                                  "FROM BSDISPLAYS A "
                                  "WHERE A.bsGroupDisplayGUID = '%1' ")
                         .arg( qsGroupDisplayGUID ));

             // 循环单屏
             while ( query3.next() ) {
                 sDisplay sdisplay;
                 sdisplay.id = query3.value("BSID").toInt();
                 sdisplay.name = query3.value("BSNAME").toString();
                 sdisplay.left = query3.value("BSLEFT").toInt();
                 sdisplay.top = query3.value("BSTOP").toInt();
                 sdisplay.resolutionX = query3.value("BSRESOLUTIONX").toInt();
                 sdisplay.resolutionY = query3.value("BSRESOLUTIONY").toInt();
                 sdisplay.segmentation = query3.value("bsSegmentation").toInt();
                 sdisplay.switchStatus = query3.value("bsSwitchStatus").toInt();
                 sdisplay.switchoncmd = query3.value("bsOnCmd").toString();
                 sdisplay.switchoffcmd = query3.value("bsOffCmd").toString();
                 sdisplay.ledresolutionX = query3.value("bsLEDResolutionX").toInt();
                 sdisplay.ledresolutionY = query3.value("bsLEDResolutionY").toInt();

                 sgroupdisplay.lstDisplay.append( sdisplay );
             }

             sroom.lstGroupDisplay.append( sgroupdisplay );
        }

        lstRoom.append( sroom );
    }

    m_dbconn.commit();

    return lstRoom;
}

void BCLocalDatabase::UpdateDisplayBaseInfo(const QString &deviceip, int roomid, int id, const QString &name, int status, const QString &onCmd, const QString &offCmd)
{
    QSqlQuery query( m_dbconn );

    query.exec( QString("UPDATE BSDisplays "
                        "SET bsName = '%1', bsSwitchStatus = %2, bsOnCmd = '%3', bsOffCmd = '%4' "
                        "WHERE bsId = %5 AND bsGroupDisplayGUID "
                        "IN (SELECT bsGUID FROM BSGroupDisplays WHERE bsRoomGUID "
                        "IN (SELECT bsGUID FROM BSRooms WHERE bsId = %6 AND bsDeviceIP = '%7'))")
                .arg( name )
                .arg( status )
                .arg( onCmd )
                .arg( offCmd )
                .arg( id )
                .arg( roomid )
                .arg( deviceip ));
}
void BCLocalDatabase::UpdateInputChannelRemoteIP(const QString &deviceip, int type, int id, const QString &ip)
{
    QSqlQuery query( m_dbconn );
    QString sql = QString("UPDATE BSINPUTCHANNELS "
                          "SET bsRemoteIP = '%1' "
                          "WHERE bsDeviceIP = '%2' AND BSTYPE = %3 AND BSID = %4 ")
            .arg(ip).arg(deviceip).arg(type).arg(id);
    query.exec( sql );
}

void BCLocalDatabase::UpdateInputChannelSubTitlePower(const QString &deviceip, int type, int id, int power)
{
    QSqlQuery query( m_dbconn );
    QString sql = QString("UPDATE BSINPUTCHANNELS "
                          "SET bsSubTitlePower = %1 "
                          "WHERE bsDeviceIP = '%2' AND BSTYPE = %3 AND BSID = %4 ")
            .arg(power).arg(deviceip).arg(type).arg(id);
    query.exec( sql );
}

QList<sInputChannel> BCLocalDatabase::GetInputChannels(int /*userid*/, const QString &deviceip)
{
    // 返回结果
    QList<sInputChannel> lstRes1;
    QList<sInputChannel> lstRes2;
    QList<sInputChannel> lstRes3;
    QList<sInputChannel> lstRes4;
    QList<sInputChannel> lstRes;

    // 查询房间数据
    QSqlQuery query( m_dbconn );
    QString sql = QString("SELECT A.BSGUID, A.BSID, A.bsBaseName, A.BSNAME, A.BSTYPE, A.BSSIGNALSOURCE, A.bsRemoteIP, A.bsCutLeft, A.bsCutRight, A.bsCutTop, A.bsCutBottom, A.bsBoardCardID, A.bsBoardCardPos, A.bsSubTitlePower "
                          "FROM BSINPUTCHANNELS A "
                          "WHERE A.bsDeviceIP = '%1' "
                          "ORDER BY A.BSTYPE, A.BSID").arg(deviceip);

    query.exec( sql );

    // 循环返回结果
    while ( query.next() ) {
        sInputChannel sinputchannel;
        sinputchannel.id = query.value("BSID").toInt();
        sinputchannel.basename = query.value("bsBaseName").toString();
        sinputchannel.name = query.value("BSNAME").toString();
        sinputchannel.type = query.value("BSTYPE").toInt();
        sinputchannel.signalsource = query.value("BSSIGNALSOURCE").toInt();
        sinputchannel.remoteIP = query.value("bsRemoteIP").toString();
        sinputchannel.cutleft = query.value("bsCutLeft").toInt();
        sinputchannel.cuttop = query.value("bsCutTop").toInt();
        sinputchannel.cutright = query.value("bsCutRight").toInt();
        sinputchannel.cutbottom = query.value("bsCutBottom").toInt();
        sinputchannel.boardcardid = query.value("bsBoardCardID").toInt();
        sinputchannel.boardcardpos = query.value("bsBoardCardPos").toInt();
        sinputchannel.subtitlePower = query.value("bsSubTitlePower").toInt();

        if (0 == sinputchannel.type)
            lstRes1.append( sinputchannel );
        if (1 == sinputchannel.type)
            lstRes2.append( sinputchannel );
        if (2 == sinputchannel.type)
            lstRes3.append( sinputchannel );
        if (3 == sinputchannel.type)
            lstRes4.append( sinputchannel );
    }

    lstRes.append( lstRes1 );
    lstRes.append( lstRes2 );
    lstRes.append( lstRes4 );
    lstRes.append( lstRes3 );

    return lstRes;
}

QList<sGroupScene> BCLocalDatabase::GetGroupScene(int /*userid*/, const QString &deviceip, int roomid)
{
    QList<sGroupScene> lstGroupScene;

    m_dbconn.transaction();
    QSqlQuery query1( m_dbconn );
    QSqlQuery query2( m_dbconn );
    QSqlQuery query3( m_dbconn );

    query1.exec( QString("SELECT A.bsGUID, A.bsId, A.bsIsNormalLoop, A.bsIsLoop, A.bsLoopInterval, A.bsName "
                         "FROM BSGroupScenes A "
                         "WHERE A.bsRoomGUID "
                         "IN (SELECT bsGUID FROM BSRooms WHERE bsDeviceIP = '%1' AND bsId = %2)")
                 .arg( deviceip )
                 .arg( roomid ));

    // 循环场景组
    while ( query1.next() ) {
        sGroupScene sgroupscene;
        sgroupscene.id = query1.value("bsId").toInt();
        sgroupscene.normalloop = query1.value("bsIsNormalLoop").toInt();
        sgroupscene.loop = query1.value("bsIsLoop").toInt();
        sgroupscene.loopInterval = query1.value("bsLoopInterval").toInt();
        sgroupscene.name = query1.value("bsName").toString();

        // 128为默认场景，不添加到链表中
        QString qsGroupSceneGUID = query1.value("bsGUID").toString();
        query2.exec( QString("SELECT A.bsGUID, A.bsId, A.bsIsCycle, A.bsName, A.bsLoopInterval "
                             "FROM BSScenes A "
                             "WHERE A.BSID != 128 AND A.bsGroupSceneGUID = '%1' "
                             "ORDER BY A.bsSort ").arg( qsGroupSceneGUID ));

        // 循环场景
        while ( query2.next() ) {
            sWindowScene swindowscene;
            swindowscene.id = query2.value("BSID").toInt();
            swindowscene.cycle = query2.value("BSISCYCLE").toInt();
            swindowscene.loopInterval = query2.value("bsLoopInterval").toInt();
            swindowscene.name = query2.value("BSNAME").toString();

            QString qsSceneGUID = query2.value("bsGUID").toString();
            query3.exec( QString("SELECT BSGROUPDISPLAYID, bsChannelID, bsChannelType, bsCopyIndex, BSLEFT, BSTOP, BSWIDTH, BSHEIGHT, "
                                 "bsIPVSegmentation, bsIPVIP, BSWINID "
                                 "FROM BSSceneDatas "
                                 "WHERE bsSceneGUID = '%1' ")
                         .arg( qsSceneGUID ));

            // 循环场景数据
            while ( query3.next() ) {
                sWindowSceneData swindowscenedata;
                swindowscenedata.chid = query3.value("bsChannelID").toInt();
                swindowscenedata.chtype = query3.value("bsChannelType").toInt();
                swindowscenedata.winid = query3.value("BSWINID").toInt();
                swindowscenedata.copyIndex = query3.value("bsCopyIndex").toInt();
                swindowscenedata.groupdisplayid = query3.value("BSGROUPDISPLAYID").toInt();
                swindowscenedata.left = query3.value("BSLEFT").toInt();
                swindowscenedata.top = query3.value("BSTOP").toInt();
                swindowscenedata.width = query3.value("BSWIDTH").toInt();
                swindowscenedata.height = query3.value("BSHEIGHT").toInt();
                swindowscenedata.ipvSegmentation = query3.value("bsIPVSegmentation").toInt();
                QString qsIpv = query3.value("bsIPVIP").toString();
                swindowscenedata.lstIP = qsIpv.split(";");

                swindowscene.lstData.append( swindowscenedata );
            }

            sgroupscene.lstData.append( swindowscene );
        }

        lstGroupScene.append( sgroupscene );
    }

    m_dbconn.commit();

    return lstGroupScene;
}

QList<sWindowScene> BCLocalDatabase::GetWindowScene(int /*userid*/, const QString &deviceip, int roomid, int groupid, int sceneid)
{
    QList<sWindowScene> lstScene;

    m_dbconn.transaction();
    QSqlQuery query1( m_dbconn );
    QSqlQuery query2( m_dbconn );
    QSqlQuery query3( m_dbconn );

    query1.exec( QString("SELECT A.bsGUID "
                         "FROM BSGroupScenes A "
                         "WHERE A.bsId = %1 AND A.bsRoomGUID "
                         "IN (SELECT bsGUID FROM BSRooms WHERE bsDeviceIP = '%2' AND bsId = %3)")
                 .arg( groupid )
                 .arg( deviceip )
                 .arg( roomid ));

    // 循环场景组
    while ( query1.next() ) {
        QString qsGroupSceneGUID = query1.value("bsGUID").toString();
        query2.exec( QString("SELECT A.bsGUID, A.bsId, A.bsIsCycle, A.bsName, A.bsLoopInterval "
                             "FROM BSScenes A "
                             "WHERE A.bsId = %1 AND A.bsGroupSceneGUID = '%2' "
                             "ORDER BY A.bsSort ")
                     .arg( sceneid )
                     .arg( qsGroupSceneGUID ));

        // 循环场景
        while ( query2.next() ) {
            sWindowScene swindowscene;
            swindowscene.id = query2.value("BSID").toInt();
            swindowscene.cycle = query2.value("BSISCYCLE").toInt();
            swindowscene.loopInterval = query2.value("bsLoopInterval").toInt();
            swindowscene.name = query2.value("BSNAME").toString();

            QString qsSceneGUID = query2.value("bsGUID").toString();
            query3.exec( QString("SELECT BSGROUPDISPLAYID, bsChannelID, bsChannelType, bsCopyIndex, BSLEFT, BSTOP, BSWIDTH, BSHEIGHT, "
                                 "bsIPVSegmentation, bsIPVIP, BSWINID "
                                 "FROM BSSceneDatas "
                                 "WHERE bsSceneGUID = '%1' ")
                         .arg( qsSceneGUID ));

            // 循环场景数据
            while ( query3.next() ) {
                sWindowSceneData swindowscenedata;
                swindowscenedata.chid = query3.value("bsChannelID").toInt();
                swindowscenedata.chtype = query3.value("bsChannelType").toInt();
                swindowscenedata.winid = query3.value("BSWINID").toInt();
                swindowscenedata.copyIndex = query3.value("bsCopyIndex").toInt();
                swindowscenedata.groupdisplayid = query3.value("BSGROUPDISPLAYID").toInt();
                swindowscenedata.left = query3.value("BSLEFT").toInt();
                swindowscenedata.top = query3.value("BSTOP").toInt();
                swindowscenedata.width = query3.value("BSWIDTH").toInt();
                swindowscenedata.height = query3.value("BSHEIGHT").toInt();
                swindowscenedata.ipvSegmentation = query3.value("bsIPVSegmentation").toInt();
                QString qsIpv = query3.value("bsIPVIP").toString();
                swindowscenedata.lstIP = qsIpv.split(";");

                swindowscene.lstData.append( swindowscenedata );
            }

            lstScene.append( swindowscene );
        }
    }

    m_dbconn.commit();

    return lstScene;
}

QList<sCustomInputChannel> BCLocalDatabase::GetCustomGroupInputChannels(int /*userid*/, const QString &deviceip)
{
    QList<sCustomInputChannel> lstRes;

    m_dbconn.transaction();

    // 查询房间数据
    QSqlQuery query1( m_dbconn );
    QSqlQuery query2( m_dbconn );

    query1.exec( QString("SELECT bsGUID, bsId, bsName "
                         "FROM BSCustomGroupInputChannel "
                         "WHERE bsUserId = %1 AND bsDeviceIP = '%2' "
                         "ORDER BY bsSort").arg(1).arg(deviceip) );

    while ( query1.next() ) {

        sCustomInputChannel scustominputchannel;
        scustominputchannel.id = query1.value("bsId").toInt();
        scustominputchannel.name = query1.value("bsName").toString();

        QString qsGUID = query1.value("bsGUID").toString();
        query2.exec( QString( "SELECT A.BSID, A.BSNAME bsBaseName, B.BSINPUTCHANNELNAME, A.BSTYPE, A.BSSIGNALSOURCE, A.bsCutLeft, A.bsCutRight, A.bsCutTop, A.bsCutBottom, A.bsBoardCardID, A.bsBoardCardPos, A.bsSubTitlePower "
                              "FROM BSINPUTCHANNELS A, BSCustomGroupInputChannelMid B "
                              "WHERE A.bsGUID = B.bsInputChannelGUID AND B.bsGroupGUID = '%1' ")
                    .arg(qsGUID));

        // 循环返回结果
        while ( query2.next() ) {
            sInputChannel sinputchannel;
            sinputchannel.id = query2.value("BSID").toInt();
            sinputchannel.basename = query2.value("bsBaseName").toString();
            sinputchannel.name = query2.value("BSINPUTCHANNELNAME").toString();
            sinputchannel.type = query2.value("BSTYPE").toInt();
            sinputchannel.signalsource = query2.value("BSSIGNALSOURCE").toInt();
            sinputchannel.cutleft = query2.value("bsCutLeft").toInt();
            sinputchannel.cuttop = query2.value("bsCutTop").toInt();
            sinputchannel.cutright = query2.value("bsCutRight").toInt();
            sinputchannel.cutbottom = query2.value("bsCutBottom").toInt();
            sinputchannel.boardcardid = query2.value("bsBoardCardID").toInt();
            sinputchannel.boardcardpos = query2.value("bsBoardCardPos").toInt();
            sinputchannel.subtitlePower = query2.value("bsSubTitlePower").toInt();

            scustominputchannel.lstData.append( sinputchannel );
        }

        lstRes.append( scustominputchannel );
    }

    m_dbconn.commit();

    return lstRes;
}

void BCLocalDatabase::ClearTable(const QString &qsTableName)
{
    QSqlQuery query( m_dbconn );
    QString sql = QString("DELETE FROM %1")
            .arg(qsTableName);

    query.exec( sql );
}

void BCLocalDatabase::ExecuteSql(const QString &sql)
{
    QSqlQuery query( m_dbconn );
    query.exec( sql );
}

void BCLocalDatabase::UnvalidInputChannel()
{
    QSqlQuery query( m_dbconn );
    QString sqlInputChannel = QString("UPDATE BSInputChannels SET bsActive = 0");

    query.exec( sqlInputChannel );
}

void BCLocalDatabase::UnvalidGroupDisplay()
{
    QSqlQuery query( m_dbconn );

    query.exec( QString("UPDATE BSRooms SET bsActive = 0") );
    query.exec( QString("UPDATE BSGroupDisplays SET bsActive = 0") );
    query.exec( QString("UPDATE BSDisplays SET bsActive = 0") );
}


bool BCLocalDatabase::IsExistInputChannel(const QString &deviceip, int pCount, int vCount, int hCount, int veCount)
{
    QSqlQuery query( m_dbconn );

    bool bRebuild = false;
    query.exec( QString("SELECT "
                        "SUM( CASE bsType WHEN 0 THEN 1 ELSE 0 END) PCCOUNT, "
                        "SUM( CASE bsType WHEN 1 THEN 1 ELSE 0 END) VIDIOCOUNT, "
                        "SUM( CASE bsType WHEN 2 THEN 1 ELSE 0 END) HDCOUNT, "
                        "SUM( CASE bsType WHEN 3 THEN 1 ELSE 0 END) VECOUNT "
                        "FROM BSInputChannels WHERE bsDeviceIP = '%1' ").arg( deviceip ) );
    if ( query.next() ) {
        int nCount1 = query.value("PCCOUNT").toInt();
        int nCount2 = query.value("VIDIOCOUNT").toInt();
        int nCount3 = query.value("HDCOUNT").toInt();
        int nCount4 = query.value("VECOUNT").toInt();

        // 如果输入通道的规模没变则不需要重构
        if ((nCount1 == pCount) && (nCount2 == vCount) && (nCount3 == hCount) && (nCount4 == veCount))
            bRebuild = true;
    }

    return bRebuild;
}

// 是否存在屏组,lstConfig是屏组的配置，依次是ID, arrayX, arrayY, resolutionX, resolutionY
bool BCLocalDatabase::IsExistGroupDisplay(const QString &deviceip, QList<int> lstConfig)
{
    bool bExist = false;
    if (lstConfig.count()%5 != 0)
        return bExist;

    QSqlQuery query( m_dbconn );

    for (int i = 0; i < lstConfig.count()/5; i++) {
        int id = lstConfig.at( 5*i+0 );
        int arrayX = lstConfig.at( 5*i+1 );
        int arrayY = lstConfig.at( 5*i+2 );
        int resolutionX = lstConfig.at( 5*i+3 );
        int resolutionY = lstConfig.at( 5*i+4 );

        // 规模和单屏分辨率必须都满足
        query.exec( QString("SELECT A.bsDeviceType, B.bsArrayX, B.bsArrayY, A.bsWidth, A.bsHeight FROM BSRooms A, BSGroupDisplays B "
                            "WHERE A.bsGUID = B.bsRoomGUID AND A.bsDeviceIP = '%1' AND A.bsId = %2 ")
                    .arg( deviceip )
                    .arg( id ));

        if ( query.next() ) {
            int type = query.value("bsDeviceType").toInt();
            int queryArrayX = query.value("bsArrayX").toInt();
            int queryArrayY = query.value("bsArrayY").toInt();
            int queryResolutionX = query.value("bsWidth").toInt() / queryArrayX;
            int queryResolutionY = query.value("bsHeight").toInt() / queryArrayY;

            // 如果查到了，而且不是LCD则存在
            if (0 != type)
                bExist = true;
            else if ((queryArrayX == arrayX) && (queryArrayY == arrayY) && (queryResolutionX == resolutionX) && (queryResolutionY == resolutionY))
                bExist = true;
            else
                bExist = false;
        } else {
            bExist = false;
        }

        if ( !bExist )
            break;
    }

    return bExist;
}

bool BCLocalDatabase::IsExistDeviceFormat(const QString &deviceip, QList<int> lstConfig)
{
    bool bExist = false;

    // 1.如果规模格式不正确直接返回
    if (lstConfig.count()%5 != 0)
        return bExist;

    QSqlQuery query( m_dbconn );

    // 2.如果屏组数量不匹配直接返回
    query.exec( QString("SELECT COUNT(1) GCOUNT "
                        "FROM BSRooms "
                        "WHERE bsDeviceIP = '%1'")
                .arg( deviceip ) );

    if ( query.next() ) {
        int gCount = query.value("GCOUNT").toInt();
        if (lstConfig.count()/5 == gCount) {
            bExist = true;
        }
    }

    if ( !bExist )
        return bExist;

    // 3.如果每个屏组规模都一致则存在
    for (int i = 0; i < lstConfig.count()/5; i++) {
        int id = lstConfig.at( 5*i+0 );
        int arrayX = lstConfig.at( 5*i+1 );
        int arrayY = lstConfig.at( 5*i+2 );
        int resolutionX = lstConfig.at( 5*i+3 );
        int resolutionY = lstConfig.at( 5*i+4 );

        // 规模和单屏分辨率必须都满足
        query.exec( QString("SELECT A.bsDeviceType, B.bsArrayX, B.bsArrayY, A.bsWidth, A.bsHeight FROM BSRooms A, BSGroupDisplays B "
                            "WHERE A.bsGUID = B.bsRoomGUID AND A.bsDeviceIP = '%1' AND A.bsId = %2 ")
                    .arg( deviceip )
                    .arg( id ));

        if ( query.next() ) {
            int type = query.value("bsDeviceType").toInt();
            int queryArrayX = query.value("bsArrayX").toInt();
            int queryArrayY = query.value("bsArrayY").toInt();
            int queryResolutionX = query.value("bsWidth").toInt() / queryArrayX;
            int queryResolutionY = query.value("bsHeight").toInt() / queryArrayY;

            // 如果查到了，而且不是LCD则存在
            if (0 != type)
                bExist = true;
            else if ((queryArrayX == arrayX) && (queryArrayY == arrayY) && (queryResolutionX == resolutionX) && (queryResolutionY == resolutionY))
                bExist = true;
            else
                bExist = false;
        } else {
            bExist = false;
        }

        if ( !bExist )
            break;
    }

    return bExist;
}

int BCLocalDatabase::GetGroupDisplayCount(int /*userid*/, const QString &deviceip)
{
    QSqlQuery query( m_dbconn );

    query.exec( QString("SELECT COUNT(1) PCOUNT FROM BSRooms WHERE bsDeviceIP = '%1') ").arg( deviceip ) );

    if ( query.next() ) {
        return query.value("PCOUNT").toInt();
    }

    return 0;
}

int BCLocalDatabase::GetDisplayCount(int /*userid*/, const QString &deviceip, int groupid)
{
    QSqlQuery query( m_dbconn );

    query.exec( QString("SELECT COUNT(1) PCOUNT FROM BSDisplays WHERE bsGroupDisplayGUID "
                        "IN (SELECT bsGUID FROM BSGroupDisplays WHERE bsRoomGUID "
                        "IN (SELECT bsGUID FROM BSRooms WHERE bsDeviceIP = '%1' AND BSID = %2))").arg( deviceip ).arg(groupid) );

    if ( query.next() ) {
        return query.value("PCOUNT").toInt();
    }

    return 0;
}

QList<sMatrix> BCLocalDatabase::GetMatrixConfig()
{
   // 返回结果
   QList<sMatrix> lstMatrix;

   m_dbconn.transaction();

   // 查询房间数据
   QSqlQuery query1( m_dbconn );
   QSqlQuery query2( m_dbconn );

   query1.exec( QString("SELECT A.bsGUID, A.bsName, A.bsIP, A.bsPort FROM BSMatrix A ") );

   // 循环矩阵
   while ( query1.next() ) {
       sMatrix smatrix;
       smatrix.name = query1.value("bsName").toString();
       smatrix.ip = query1.value("bsIP").toString();
       smatrix.port = query1.value("bsPort").toInt();
       QString qsMatrixGUID = query1.value("bsGUID").toString();

       query2.exec( QString("SELECT bsType, bsID, bsIsSwitch, bsSwitchNodeID "
                            "FROM BSGROUPDISPLAYS "
                            "WHERE bsMatrixGUID = '%1' "
                            "ORDER BY BSTYPE, BSID")
                   .arg( qsMatrixGUID ));

       // 循环矩阵节点
       while ( query2.next() ) {
           sMatrixNode snode;
           snode.id = query2.value("BSID").toInt();
           snode.nSwitch = query2.value("bsIsSwitch").toInt();
           snode.nSwitchID = query2.value("bsSwitchNodeID").toInt();

           int type = query2.value("bsType").toInt();
           if (0 == type) {
               smatrix.lstInputNode.append( snode );
           } else {
               smatrix.lstOutputNode.append( snode );
           }
       }

       lstMatrix.append( smatrix );
   }

   m_dbconn.commit();

   return lstMatrix;
}

void BCLocalDatabase::SetMatrixName(const QString &ip, int port, const QString &name)
{
    QSqlQuery query( m_dbconn );

    query.exec( QString("UPDATE BSMatrix "
                        "SET bsName = '%1' "
                        "WHERE bsIP = '%2' AND bsPort = %3)")
                .arg(name).arg(ip).arg(port));
}

void BCLocalDatabase::SetMatrixConfig(const QList<sMatrix> lstMatrix)
{
    m_dbconn.transaction();

    // 查询房间数据
    QSqlQuery query( m_dbconn );

    for (int i = 0; i < lstMatrix.count(); i++) {
        sMatrix smatrix = lstMatrix.at( i );

        query.exec( QString("SELECT A.bsGUID FROM BSMatrix A "
                            "WHERE A.bsIP = '%1' AND A.bsPort = %2 ")
                    .arg( smatrix.ip).arg( smatrix.port ) );

        // 1.判断是否存在，如果存在先删除数据
        if ( query.next() ) {
            QString qsGUID = query.value("bsGUID").toString();

            query.exec( QString("DELETE FROM BSMatrixNode WHERE bsMatrixGUID = '%1'").arg( qsGUID ) );
            query.exec( QString("DELETE FROM BSMatrix WHERE bsGUID = '%1'").arg( qsGUID ) );
        }

        // 2.添加数据
        QString qsMatrixGUID = QUuid::createUuid().toString();
        query.exec( QString("INSERT INTO BSMatrix(bsGUID, bsName, bsIP, bsPort) VALUES('%1', '%2', '%3', %4)").arg(qsMatrixGUID).arg(smatrix.name).arg(smatrix.ip).arg(smatrix.port) );

        for (int j = 0; j < smatrix.lstInputNode.count(); j++) {
            sMatrixNode snode = smatrix.lstInputNode.at(j);

            query.exec( QString("INSERT INTO BSMatrixNode(bsGUID, bsMatrixGUID, bsID, bsType, bsIsSwitch, bsSwitchNodeID) VALUES('%1', '%2', %3, 0, %4, %5)")
                        .arg(QUuid::createUuid().toString()).arg(qsMatrixGUID).arg(snode.id).arg(snode.nSwitch).arg(snode.nSwitchID));
        }

        for (int j = 0; j < smatrix.lstOutputNode.count(); j++) {
            sMatrixNode snode = smatrix.lstOutputNode.at(j);

            query.exec( QString("INSERT INTO BSMatrixNode(bsGUID, bsMatrixGUID, bsID, bsType, bsIsSwitch, bsSwitchNodeID) VALUES('%1', '%2', %3, 1, %4, %5)")
                        .arg(QUuid::createUuid().toString()).arg(qsMatrixGUID).arg(snode.id).arg(snode.nSwitch).arg(snode.nSwitchID));
        }
    }

    m_dbconn.commit();
}

void BCLocalDatabase::SetMatrixSwitch(const QString &ip, int port, int inputid, int outputid)
{
    QSqlQuery query( m_dbconn );

    query.exec( QString("UPDATE BSMatrixNode "
                        "SET bsIsSwitch = 1, bsSwitchNodeID = %1 "
                        "WHERE bsType = 1 AND bsID = %2 AND bsMatrixGUID = (SELECT bsGUID FROM BSMatrix WHERE bsIP = '%3' AND bsPort = %4)")
                .arg(inputid).arg(outputid).arg(ip).arg(port));
}

bool BCLocalDatabase::InitDataBase(QString strDatabaseName)
{
    if (QSqlDatabase::contains( CONNECTNAME ))
        m_dbconn = QSqlDatabase::database( CONNECTNAME );    //添加数据库驱动
    else
        m_dbconn = QSqlDatabase::addDatabase("QSQLITE", CONNECTNAME);    //添加数据库驱动

    if ( m_dbconn.isOpenError() )
        return false;

    m_dbconn.setDatabaseName(strDatabaseName);  //在工程目录新建一个 *.db 的文件
    m_dbconn.setUserName( USER );
    m_dbconn.setPassword( PASSWORD );

    if( !m_dbconn.open() )
        return false;

    m_dbconn.transaction();

    QSqlQuery query( m_dbconn );  //以下执行相关QSL语句

    // 用户表
    query.exec("create table IF NOT EXISTS "
               "BSUsers("
               "bsIndex INTEGER PRIMARY KEY AUTOINCREMENT, "
               "bsId INTEGER, "
               "bsUser varchar(32), "
               "bsPassword varchar(32), "
               "bsLevel INTEGER, "              // 权限，0超级管理员(admin)，1管理员，2操作员，3用户
               "bsRemarks varchar(100))");

    // 用户UI界面主菜单权限表Tab
    query.exec("create table IF NOT EXISTS "
               "BSMainToolBarTab("
               "bsGUID UNIQUEIDENTIFIER PRIMARY KEY, "
               "bsUserId INTEGER, "                             // 用户ID
               "bsTab INTEGER) ");                              // tab索引

    // 用户UI界面主菜单权限表Group
    query.exec("create table IF NOT EXISTS "
               "BSMainToolBarGroup("
               "bsGUID UNIQUEIDENTIFIER PRIMARY KEY, "
               "bsTabGUID UNIQUEIDENTIFIER, "                   // tab GUID
               "bsGroup INTEGER) ");                            // group索引

    // 用户UI界面主菜单权限表Button
    query.exec("create table IF NOT EXISTS "
               "BSMainToolBarButton("
               "bsGUID UNIQUEIDENTIFIER PRIMARY KEY, "
               "bsGroupGUID UNIQUEIDENTIFIER, "                 // tab GUID
               "bsButton INTEGER) ");                           // button索引

    // 输入通道表
    query.exec("create table IF NOT EXISTS "
               "BSInputChannels("
               "bsGUID UNIQUEIDENTIFIER PRIMARY KEY, "
               "bsId INTEGER, "                                 // 可能有重复
               "bsType INTEGER, "                               // 0:pc 1:vedio 2:hd
               "bsDeviceIP varchar(32), "                       // 设备IP
               "bsBaseName varchar(32), "                       // 基础名字
               "bsName varchar(32), "                           // 名字
               "bsBoardCardID INTEGER, "                        // 板卡ID
               "bsBoardCardPos INTEGER, "                       // 板卡位置
               "bsSignalSource INTEGER, "
               "bsRemoteIP varchar(32), "                       // 远程控制的IP
               "bsSubTitlePower INTEGER, "                      // 字幕开关，默认是关闭的
               "bsCutLeft INTEGER, "
               "bsCutRight INTEGER, "
               "bsCutTop INTEGER, "
               "bsCutBottom INTEGER)");

    // 房间表
    query.exec("create table IF NOT EXISTS "
               "BSRooms("
               "bsGUID UNIQUEIDENTIFIER PRIMARY KEY, "
               "bsId INTEGER, "
               "bsDeviceIP varchar(32), "                       // 设备IP
               "bsDeviceType INTEGER, "                         // 设备类型，0:LCD,1:LED,2:融合,3:4K,4:Matrix
               "bsName varchar(32), "
               "bsWidth INTEGER, "
               "bsHeight INTEGER, "
               "bsIsUseVirtualResotluion INTEGER, "             // 是否使用虚拟分辨率
               "bsVirWidth INTEGER, "
               "bsVirHeight INTEGER, "
               "bsSwitchStatus INTEGER, "                       // 屏幕开关状态1/0
               "bsIsNetConnect INTEGER, "                       // 屏幕开关是否是网络通讯
               "bsSwitchIP varchar(32), "                       // 屏幕开关通讯IP
               "bsSwitchPort INTEGER, "                         // 屏幕开关通讯port
               "bsSwitchCom varchar(32), "                      // 屏幕开关串口号
               "bsSwitchBaudRate INTEGER, "                     // 屏幕开关波特率
               "bsSwitchDataBit INTEGER, "                      // 屏幕开关数据位
               "bsSwitchStopBit INTEGER, "                      // 屏幕开关停止位
               "bsSwitchCheckBit varchar(32), "                 // 屏幕开关校验位
               "bsSwitchStreamCtrl varchar(32), "               // 屏幕开关控制流
               "bsSwitchCmdType INTEGER, "                      // 屏幕开关指令类型0：16进制，1：普通文本
               "bsSwitchOnCmd varchar(200), "                   // 屏幕开指令
               "bsSwitchOffCmd varchar(200))");                 // 屏幕关指令

    // 屏组表
    query.exec("create table IF NOT EXISTS "
               "BSGroupDisplays("
               "bsGUID UNIQUEIDENTIFIER PRIMARY KEY, "
               "bsRoomGUID UNIQUEIDENTIFIER, "                  // 房间ID外键
               "bsId INTEGER, "
               "bsName varchar(32), "
               "bsArrayX INTEGER, "
               "bsArrayY INTEGER, "
               "bsIsUseVirtualArray INTEGER, "                  // 是否使用虚拟分屏
               "bsVirArrayX INTEGER, "
               "bsVirArrayY INTEGER, "
               "bsResolutionX INTEGER, "
               "bsResolutionY INTEGER, "
               "bsSegmentationX INTEGER, "
               "bsSegmentationY INTEGER, "
               "bsLeft INTEGER, "
               "bsTop INTEGER, "
               "bsWidth INTEGER, "
               "bsHeight INTEGER)");

    // 单屏表
    query.exec("create table IF NOT EXISTS "
               "BSDisplays("
               "bsGUID UNIQUEIDENTIFIER PRIMARY KEY, "
               "bsGroupDisplayGUID UNIQUEIDENTIFIER, "          // 屏组ID外键
               "bsId INTEGER, "
               "bsName varchar(32), "
               "bsResolutionX INTEGER, "
               "bsResolutionY INTEGER, "
               "bsLeft INTEGER, "
               "bsTop INTEGER, "
               "bsWidth INTEGER, "
               "bsHeight INTEGER, "
               "bsLEDResolutionX INTEGER, "                     // LED单屏分辨率X
               "bsLEDResolutionY INTEGER, "                     // LED单屏分辨率Y
               "bsSwitchStatus INTEGER, "                       // 单屏开关
               "bsOnCmd varchar(100), "
               "bsOffCmd varchar(100), "
               "bsSegmentation INTEGER)");                      // 单屏分割

    // 场景组表
    query.exec("create table IF NOT EXISTS "
               "BSGroupScenes("
               "bsGUID UNIQUEIDENTIFIER PRIMARY KEY, "
               "bsRoomGUID UNIQUEIDENTIFIER, "                  // GUID外键
               "bsId INTEGER, "
               "bsIsNormalLoop INTEGER, "                       // 是否常规轮训，0：常规，1：非常规，根据场景内的轮巡时间轮巡
               "bsIsLoop INTEGER, "                             // 是否轮训
               "bsLoopInterval INTEGER, "                       // 轮训间隔
               "bsName varchar(32))");

    // 场景表
    query.exec("create table IF NOT EXISTS "
               "BSScenes("
               "bsGUID UNIQUEIDENTIFIER PRIMARY KEY, "
               "bsGroupSceneGUID UNIQUEIDENTIFIER, "            // 场景组GUID外键
               "bsId INTEGER, "
               "bsName varchar(32), "
               "bsIsCycle INTEGER, "                            // 是否轮训
               "bsLoopInterval INTEGER, "                       // 轮训间隔
               "bsSort INTEGER)");                              // 根据用户自定义场景排序

    // 场景数据表
    query.exec("create table IF NOT EXISTS "
               "BSSceneDatas( "
               "bsGUID UNIQUEIDENTIFIER PRIMARY KEY, "
               "bsSceneGUID UNIQUEIDENTIFIER, "                 // 场景GUID外键
               "bsGroupDisplayID INTEGER, "                     // 屏组ID
               "bsChannelID INTEGER, "                          // 通道ID
               "bsChannelType INTEGER, "                        // 通道type
               "bsCopyIndex INTEGER, "                          // 通道复制索引，VP2000时使用
               "bsLeft INTEGER, "
               "bsTop INTEGER, "
               "bsWidth INTEGER, "
               "bsHeight INTEGER, "
               "bsIPVSegmentation INTEGER, "                    // 可能是IPV数据，需要记录分割和分割的IP
               "bsIPVIP varchar(2400), "
               "BSWINID INTEGER)");

    // 自定义通道组
    query.exec("create table IF NOT EXISTS "
               "BSCustomGroupInputChannel("
               "bsGUID UNIQUEIDENTIFIER PRIMARY KEY, "
               "bsId INTEGER, "
               "bsDeviceIP varchar(32), "                       // 设备IP
               "bsUserId INTEGER, "                             // 用户ID
               "bsName varchar(32), "
               "bsSort INTEGER)");                              // 排序

    // 通道组和通道关联表
    query.exec("create table IF NOT EXISTS "
               "BSCustomGroupInputChannelMid("
               "bsGUID UNIQUEIDENTIFIER PRIMARY KEY, "
               "bsGroupGUID UNIQUEIDENTIFIER, "                 // 自定义通道组ID
               "bsInputChannelGUID UNIQUEIDENTIFIER,"           // 通道ID
               "bsInputChannelName varchar(32))");              // 通道在组内的名字

    // 矩阵表
    query.exec("create table IF NOT EXISTS "
               "BSMatrix("
               "bsGUID UNIQUEIDENTIFIER PRIMARY KEY, "
               "bsName varchar(32), "                           // 名字
               "bsIP varchar(32), "                             // IP
               "bsPort INTEGER)");                              // 端口

    // 矩阵节点表
    query.exec("create table IF NOT EXISTS "
               "BSMatrixNode("
               "bsGUID UNIQUEIDENTIFIER PRIMARY KEY, "
               "bsMatrixGUID UNIQUEIDENTIFIER, "                // 矩阵外键
               "bsID INTEGER, "                                 // ID
               "bsType INTEGER, "                               // 类型，0：输入，1：输出
               "bsIsSwitch INTEGER, "                           // 是否被切指令
               "bsSwitchNodeID INTEGER)");                      // 切信号的ID，输入对应输出，输出对应输入

    // 任务计划表
    query.exec("create table IF NOT EXISTS "
               "BSTaskPlanning( "
               "bsGUID UNIQUEIDENTIFIER PRIMARY KEY, "
               "bsID INTEGER, "                                 // 任务ID
               "bsTaskType INTEGER, "                           // 任务类型，0：开机，1：关机，2：打开轮训，3：关闭轮训，4：调用场景
               "bsCycle varchar(32), "                          // 循环周期，从1-7，中间用空格分开，如"1 2 7"
               "bsExecTime varchar(32), "                       // 执行时间
               "bsCreatorID INTEGER, "                          // 创建人ID
               "bsCreateTime varchar(32), "                     // 创建时间
               "bsRoomType INTEGER, "                           // 房间类型，0：拼接，1：矩阵
               "bsRoomID INTEGER, "                             // 房间ID
               "bsSceneID INTEGER)");                           // 场景ID

    // 添加默认用户
    query.exec( QString("SELECT 1 FROM BSUSERS WHERE BSID = 1 ") );

    m_dbconn.commit();

    if ( !query.next() ) {
        // 添加默认用户
        query.exec( QString("INSERT INTO BSUSERS(BSID, BSUSER, BSPASSWORD, bsLevel) VALUES(0, 'root', '2003', 0)") );
        query.exec( QString("INSERT INTO BSUSERS(BSID, BSUSER, BSPASSWORD, bsLevel) VALUES(1, 'admin', '', 1)") );
        query.exec( QString("INSERT INTO BSUSERS(BSID, BSUSER, BSPASSWORD, bsLevel) VALUES(2, 'Operator', '', 2)") );
        query.exec( QString("INSERT INTO BSUSERS(BSID, BSUSER, BSPASSWORD, bsLevel) VALUES(3, 'User', '', 3)") );

        // 添加默认权限0 1
        QList<sTab> lstTab;
        sTab stab;
        stab.tab = 3;
        sGroup sgroup;
        sgroup.group = 7;
        sgroup.lstButton << 101 << 100 << 143 << 148 << 144;
        stab.lstGroup.append( sgroup );
        sgroup.group = 1;
        sgroup.lstButton.clear();
        sgroup.lstButton << 103 << 104 << 105 << 106 << 102;
        stab.lstGroup.append( sgroup );
        sgroup.group = 10;
        sgroup.lstButton.clear();
        sgroup.lstButton << 169 << 170;
        stab.lstGroup.append( sgroup );
        sgroup.group = 5;
        sgroup.lstButton.clear();
#ifndef ZHONGDAABOUT
        sgroup.lstButton << 111 << 167 << 108 << 110;
#else
        sgroup.lstButton << 111 << 167 << 107 << 108 << 110;
#endif
        stab.lstGroup.append( sgroup );
        lstTab.append( stab );

        stab.tab = 4;
        sgroup.group = 9;
        sgroup.lstButton.clear();
        sgroup.lstButton << 112 << 153 << 171 << 119 << 168 << 173 << 174 << 175 << 176;
        //sgroup.lstButton << 112 << 153 << 171 << 119 << 168 << 173 << 174 << 175 << 176 << 120;
        stab.lstGroup.clear();
        stab.lstGroup.append( sgroup );
        lstTab.append( stab );

        stab.tab = 5;
        sgroup.group = 9;
        sgroup.lstButton.clear();
        sgroup.lstButton << 172 << 128 << 131 << 139 << 126 << 127 << 129 << 130;
        stab.lstGroup.clear();
        stab.lstGroup.append( sgroup );
        lstTab.append( stab );

        SetUserMainToolBar(0, lstTab);
        SetUserMainToolBar(1, lstTab);

        // 操作员权限 2
        lstTab.clear();
        stab.tab = 3;
        sgroup.group = 7;
        sgroup.lstButton.clear();
        sgroup.lstButton << 101 << 100 << 143 << 148 << 144;
        stab.lstGroup.clear();
        stab.lstGroup.append( sgroup );
        sgroup.group = 1;
        sgroup.lstButton.clear();
        sgroup.lstButton << 103 << 104 << 105 << 106;
        stab.lstGroup.append( sgroup );
        sgroup.group = 10;
        sgroup.lstButton.clear();
        sgroup.lstButton << 169 << 170;
        stab.lstGroup.append( sgroup );
        sgroup.group = 5;
        sgroup.lstButton.clear();
#ifndef ZHONGDAABOUT
        sgroup.lstButton << 111 << 167 << 108 << 110;
#else
        sgroup.lstButton << 111 << 167 << 107 << 108 << 110;
#endif
        stab.lstGroup.append( sgroup );
        lstTab.append( stab );

        stab.tab = 4;
        sgroup.group = 9;
        sgroup.lstButton.clear();
        sgroup.lstButton << 112 << 173;
        stab.lstGroup.clear();
        stab.lstGroup.append( sgroup );
        lstTab.append( stab );

        stab.tab = 5;
        sgroup.group = 9;
        sgroup.lstButton.clear();
        sgroup.lstButton << 128 << 131 << 126 << 127;
        stab.lstGroup.clear();
        stab.lstGroup.append( sgroup );
        lstTab.append( stab );

        SetUserMainToolBar(2, lstTab);

        // 用户权限 3
        lstTab.clear();
        stab.tab = 3;
        sgroup.group = 7;
        sgroup.lstButton.clear();
        sgroup.lstButton << 101 << 100 << 143 << 148 << 144;
        stab.lstGroup.clear();
        stab.lstGroup.append( sgroup );
        sgroup.group = 1;
        sgroup.lstButton.clear();
        sgroup.lstButton << 106;
        stab.lstGroup.append( sgroup );
        sgroup.group = 10;
        sgroup.lstButton.clear();
        sgroup.lstButton << 169 << 170;
        stab.lstGroup.append( sgroup );
        sgroup.group = 5;
        sgroup.lstButton.clear();
#ifndef ZHONGDAABOUT
        sgroup.lstButton << 111 << 167 << 108 << 110;
#else
        sgroup.lstButton << 111 << 167 << 107 << 108 << 110;
#endif
        stab.lstGroup.append( sgroup );
        lstTab.append( stab );

        stab.tab = 4;
        sgroup.group = 9;
        sgroup.lstButton.clear();
        sgroup.lstButton << 112;
        stab.lstGroup.clear();
        stab.lstGroup.append( sgroup );
        lstTab.append( stab );

        stab.tab = 5;
        sgroup.group = 9;
        sgroup.lstButton.clear();
        sgroup.lstButton << 128 << 131 << 126 << 127;
        stab.lstGroup.clear();
        stab.lstGroup.append( sgroup );
        lstTab.append( stab );

        SetUserMainToolBar(3, lstTab);
    }

    return true;
}

bool BCLocalDatabase::InitDataBaseData()
{
    // 初始化数据分以下几种类型
    /* 1.演示模式，直接返回，不保存数据库
     * 2.服务器，直接返回，数据通过TCP方式获得，保存到内存
     * 3.VP4000软件本身TCP通信
     * 4.VP4000软件本身串口通信
     * 5.VP2000软件本身TCP通信
     * 6.VP2000软件本身串口通信
     * 7.VP4000通过DLL通信，拟废除!!!
     */

    // 演示模式、服务器，直接返回
    if (BCCommon::g_bConnectWithServer || (0 == m_pServer->m_nIsDemoMode)) {
        return true;
    }

    // 软件本身通信
    if (0 == BCCommon::g_nDeviceType) {    // VP2000
        RequestVP2000Config();
    } else if ((1 == BCCommon::g_nDeviceType) || (2 == BCCommon::g_nDeviceType)) { // VP2000A, VP4000
        RequestVP4000Config();
    }

    return true;
}

void BCLocalDatabase::RequestVP2000Config()
{
    if ( m_pServer->m_bIsNetConnect ) {
        if (NULL == m_pLocalTcpSocket) {
            m_pLocalTcpSocket = new BCLocalTcpSocket(m_pServer->m_qsConnectIPWithoutDLL, m_pServer->m_qsConnectPortWithoutDLL.toInt());
            connect(m_pLocalTcpSocket, SIGNAL(sigVP2000Config(int,int,int,int,int,int,int,int)), this, SLOT(onVP2000Config(int,int,int,int,int,int,int,int)));
        }

        m_pLocalTcpSocket->RequestConfig( 10 );
    } else {
        if (NULL == m_pLocalSerialPort) {
            m_pLocalSerialPort = new BCLocalSerialPort();
            connect(m_pLocalSerialPort, SIGNAL(sigVP2000IP(int,QString)), this, SLOT(onVP2000IP(int,QString)));
            connect(m_pLocalSerialPort, SIGNAL(sigVP2000Config(int,int,int,int,int,int,int,int)), this, SLOT(onVP2000Config(int,int,int,int,int,int,int,int)));
        }

        m_pLocalSerialPort->RequestConfig( 11 );
    }
}

void BCLocalDatabase::RequestVP4000Config()
{
#ifdef CHANGCHUNPOWER
    QStringList lstInputChannel;
    if (0 == BCCommon::g_nIsUseInputChannelConfig) {
        for (int i = 0; i < 152; i++) {
            lstInputChannel.append( QString::number( i ) );
            lstInputChannel.append( QString::number( 0 ) );
            lstInputChannel.append( QString::number( 1920 ) );
            lstInputChannel.append( QString::number( 1080 ) );
        }
    } else {
        for (int i = 0; i < BCCommon::g_npcCount; i++) {
            lstInputChannel.append( QString::number( i+BCCommon::g_npcBeginID ) );
            lstInputChannel.append( QString::number( 0 ) );
            lstInputChannel.append( QString::number( 1920 ) );
            lstInputChannel.append( QString::number( 1080 ) );
        }
        for (int i = 0; i < BCCommon::g_nipvCount; i++) {
            lstInputChannel.append( QString::number( i+BCCommon::g_nipvBeginID ) );
            lstInputChannel.append( QString::number( 9 ) );
            lstInputChannel.append( QString::number( 1920 ) );
            lstInputChannel.append( QString::number( 1080 ) );
        }
        for (int i = 0; i < BCCommon::g_nvedioCount; i++) {
            lstInputChannel.append( QString::number( i+BCCommon::g_nvedioBeginID ) );
            lstInputChannel.append( QString::number( 8 ) );
            lstInputChannel.append( QString::number( 800 ) );
            lstInputChannel.append( QString::number( 540 ) );
        }
        for (int i = 0; i < BCCommon::g_nhdCount; i++) {
            lstInputChannel.append( QString::number( (i*2)+BCCommon::g_nhdBeginID ) );
            lstInputChannel.append( QString::number( 3 ) );
            lstInputChannel.append( QString::number( 3840 ) );
            lstInputChannel.append( QString::number( 2160 ) );
        }
    }

    QStringList lstGroupDisplay;
    lstGroupDisplay.append( QString::number( 1 ) );
    lstGroupDisplay.append( QString::number( 4 ) );
    lstGroupDisplay.append( QString::number( 6 ) );
    lstGroupDisplay.append( QString::number( 1366*4 ) );
    lstGroupDisplay.append( QString::number( 768*6 ) );
    lstGroupDisplay.append( QString::number( 0 ) );
    lstGroupDisplay.append( QString::number( 0 ) );

    lstGroupDisplay.append( QString::number( 2 ) );
    lstGroupDisplay.append( QString::number( 12 ) );
    lstGroupDisplay.append( QString::number( 4 ) );
    lstGroupDisplay.append( QString::number( 1920*12 ) );
    lstGroupDisplay.append( QString::number( 1080*4 ) );
    lstGroupDisplay.append( QString::number( 0 ) );
    lstGroupDisplay.append( QString::number( 0 ) );

    lstGroupDisplay.append( QString::number( 3 ) );
    lstGroupDisplay.append( QString::number( 4 ) );
    lstGroupDisplay.append( QString::number( 6 ) );
    lstGroupDisplay.append( QString::number( 1366*4 ) );
    lstGroupDisplay.append( QString::number( 768*6 ) );
    lstGroupDisplay.append( QString::number( 0 ) );
    lstGroupDisplay.append( QString::number( 0 ) );

    lstGroupDisplay.append( QString::number( 4 ) );
    lstGroupDisplay.append( QString::number( 2 ) );
    lstGroupDisplay.append( QString::number( 1 ) );
    lstGroupDisplay.append( QString::number( 1920*2 ) );
    lstGroupDisplay.append( QString::number( 1080*1 ) );
    lstGroupDisplay.append( QString::number( 0 ) );
    lstGroupDisplay.append( QString::number( 0 ) );

    lstGroupDisplay.append( QString::number( 5 ) );
    lstGroupDisplay.append( QString::number( 2 ) );
    lstGroupDisplay.append( QString::number( 2 ) );
    lstGroupDisplay.append( QString::number( 1366*2 ) );
    lstGroupDisplay.append( QString::number( 768*2 ) );
    lstGroupDisplay.append( QString::number( 0 ) );
    lstGroupDisplay.append( QString::number( 0 ) );

    lstGroupDisplay.append( QString::number( 6 ) );
    lstGroupDisplay.append( QString::number( 3 ) );
    lstGroupDisplay.append( QString::number( 3 ) );
    lstGroupDisplay.append( QString::number( 1366*3 ) );
    lstGroupDisplay.append( QString::number( 768*3 ) );
    lstGroupDisplay.append( QString::number( 0 ) );
    lstGroupDisplay.append( QString::number( 0 ) );

    lstGroupDisplay.append( QString::number( 7 ) );
    lstGroupDisplay.append( QString::number( 1 ) );
    lstGroupDisplay.append( QString::number( 1 ) );
    lstGroupDisplay.append( QString::number( 1920 ) );
    lstGroupDisplay.append( QString::number( 1080 ) );
    lstGroupDisplay.append( QString::number( 0 ) );
    lstGroupDisplay.append( QString::number( 0 ) );

    lstGroupDisplay.append( QString::number( 8 ) );
    lstGroupDisplay.append( QString::number( 1 ) );
    lstGroupDisplay.append( QString::number( 1 ) );
    lstGroupDisplay.append( QString::number( 1920 ) );
    lstGroupDisplay.append( QString::number( 1080 ) );
    lstGroupDisplay.append( QString::number( 0 ) );
    lstGroupDisplay.append( QString::number( 0 ) );

    QStringList lstDefaultScene;
    onVP4000Config(lstInputChannel, lstGroupDisplay, lstDefaultScene);
    return;
#endif

    if ( m_pServer->m_bIsNetConnect ) {
        if (NULL == m_pLocalTcpSocket) {
            m_pLocalTcpSocket = new BCLocalTcpSocket(m_pServer->m_qsConnectIPWithoutDLL, m_pServer->m_qsConnectPortWithoutDLL.toInt());
            connect(m_pLocalTcpSocket, SIGNAL(sigVP4000Config(QStringList,QStringList,QStringList)), this, SLOT(onVP4000Config(QStringList,QStringList,QStringList)));
            connect(m_pLocalTcpSocket, SIGNAL(sigDemoMode()), this, SLOT(onDemoMode()));
        }

        m_pLocalTcpSocket->RequestConfig( 1 );
    } else {
        if (NULL == m_pLocalSerialPort) {
            m_pLocalSerialPort = new BCLocalSerialPort();
            connect(m_pLocalSerialPort, SIGNAL(sigVP4000Config(QStringList,QStringList,QStringList)), this, SLOT(onVP4000Config(QStringList,QStringList,QStringList)));
            connect(m_pLocalSerialPort, SIGNAL(sigDemoMode()), this, SLOT(onDemoMode()));
        }

        m_pLocalSerialPort->RequestConfig( 1 );
    }
}

void BCLocalDatabase::onVP2000IP(int timeout, const QString &ip)
{
    if (0 != timeout)
        return;

    if ( !m_pServer->m_bIsNetConnect ) {
        m_pServer->m_qsConnectIPWithoutDLL = ip;
        m_pLocalSerialPort->RequestConfig( 10 );
    }
}

void BCLocalDatabase::onVP4000Config(QStringList lstInputChannel, QStringList lstGroupDisplay, QStringList lstDefaultScene)
{
    // 1.输入通道
    int nCount = lstInputChannel.count() / 6;
    if ((0 == nCount) || (0 != (lstInputChannel.count()%6)))
        return;

    int pcCount = 0;
    int vedioCount = 0; // ipv
    int hdCount = 0;
    int vCount = 0; // vedio
    for (int i = 0; i < nCount; i++) {
        int type = lstInputChannel.at(i*6 + 1).toInt();
        if (type == 0)
            pcCount++;
        if (type == 9) // ipv
            vedioCount++;
        if (type == 3)
            hdCount++;
        if (type == 8)  // vedio
            vCount++;
    }

    // 开始启动事务
    m_dbconn.transaction();

    QSqlQuery query( m_dbconn );
    // 判断机器规模是否发生变化
    if ( !IsExistInputChannel(m_pServer->m_qsConnectIPWithoutDLL, pcCount, vedioCount, hdCount, vCount) ) {
        // 清空自定义输入通道表内数据
        query.exec( QString("DELETE FROM BSCustomGroupInputChannelMid WHERE bsGroupGUID IN (SELECT bsGUID FROM BSCustomGroupInputChannel WHERE bsDeviceIP = '%1') ").arg( m_pServer->m_qsConnectIPWithoutDLL ) );
        query.exec( QString("DELETE FROM BSCustomGroupInputChannel WHERE bsDeviceIP = '%1' ").arg( m_pServer->m_qsConnectIPWithoutDLL ) );

        // 清空输入通道数据
        query.exec( QString("DELETE FROM BSInputChannels WHERE bsDeviceIP = '%1' ").arg( m_pServer->m_qsConnectIPWithoutDLL ) );

        int iPC = 0;
        int iVedio = 0;
        int iHDBase = 0;
        int iVe = 0;
        for (int i = 0; i < nCount; i++) {
            int chid = lstInputChannel.at(i*6 + 0).toInt();
            int type = lstInputChannel.at(i*6 + 1).toInt();
            int boardcardid = lstInputChannel.at(i*6 + 2).toInt();
            int boardcardpos = lstInputChannel.at(i*6 + 3).toInt();
            if (0 == type) {
                BuildDeviceInputChannel(chid, iPC++, 0, boardcardid, boardcardpos);
            }
            if (9 == type) {    // IPV类型
                BuildDeviceInputChannel(chid, iVedio++, 1, boardcardid, boardcardpos);
            }
            if (3 == type) {
                BuildDeviceInputChannel(chid, iHDBase++, 2, boardcardid, boardcardpos);
            }
            if (8 == type) {    // vedio
                BuildDeviceInputChannel(chid, iVe++, 3, boardcardid, boardcardpos);
            }
        }
    }

    // 提交事务
    m_dbconn.commit();

    // 2.屏组信息
    nCount = lstGroupDisplay.count() / 7;
    if ((0 == nCount) || (0 != (lstGroupDisplay.count()%7)))
        return;

    QList<int> lstDeviceConfig;
    for (int i = 0; i < nCount; i++) {
        lstDeviceConfig.append( lstGroupDisplay.at(i*7+0).toInt() );
        lstDeviceConfig.append( lstGroupDisplay.at(i*7+1).toInt() );
        lstDeviceConfig.append( lstGroupDisplay.at(i*7+2).toInt() );
        lstDeviceConfig.append( lstGroupDisplay.at(i*7+3).toInt() / lstGroupDisplay.at(i*7+1).toInt() );
        lstDeviceConfig.append( lstGroupDisplay.at(i*7+4).toInt() / lstGroupDisplay.at(i*7+2).toInt() );
    }

    // 构造屏组
    BuildGroupDislay(lstDeviceConfig, lstDefaultScene);

    // 加载完数据之后即删除tcp，否则影响其他操作
    if (NULL != m_pLocalTcpSocket) {
        delete m_pLocalTcpSocket;
        m_pLocalTcpSocket = NULL;
    }
    if (NULL != m_pLocalSerialPort) {
        delete m_pLocalSerialPort;
        m_pLocalSerialPort = NULL;
    }

    // 加载完数据的标志位
    m_pServer->SetLoadDataOK();
}

void BCLocalDatabase::onDemoMode()
{
    m_pServer->SetDemoLoadDataOK();
}

void BCLocalDatabase::onVP2000Config(int timeout, int arrX, int arrY, int resX, int resY, int pcCount, int vedioCount, int hdCount)
{
    if (0 != timeout)
        return;

    // 1.构造输入通道
    BuildInputChannel(pcCount, 0, hdCount, vedioCount);

    // 2.构造房间数据
    QList<int> lstDeviceConfig;
    lstDeviceConfig << 0 << arrX << arrY << resX << resY;
    QStringList lstDefaultScene;
    BuildGroupDislay(lstDeviceConfig, lstDefaultScene);

    // 加载完数据之后即删除tcp，否则影响其他操作
    if (NULL != m_pLocalTcpSocket) {
        delete m_pLocalTcpSocket;
        m_pLocalTcpSocket = NULL;
    }
    if (NULL != m_pLocalSerialPort) {
        delete m_pLocalSerialPort;
        m_pLocalSerialPort = NULL;
    }

    // 加载完数据的标志位
    m_pServer->SetLoadDataOK();
}

void BCLocalDatabase::BuildDeviceInputChannel(int id, int nameid, int type, int boardcardid, int boardcardpos)
{
    // 构造名字
    QString qsBaseName, qsName;
    int signalSource = 0;
    if (0 == type) {
        signalSource = 0;
        qsName = QString("PC%1").arg(nameid+1);
        qsBaseName = QString("PC%1-").arg(nameid+1);
    }
    if (1 == type) {
        signalSource = 9;
        qsName = QString("IPV%1").arg(nameid+1);
        qsBaseName = QString("IPV%1-").arg(nameid+1);
    }
    if (2 == type) {
        signalSource = 4;
        qsName = QString("HD%1").arg(nameid+1);
        qsBaseName = QString("HD%1-").arg(nameid+1);
    }
    if (3 == type) {
        signalSource = 2;
        qsName = QString("Vedio%1").arg(nameid+1);
        qsBaseName = QString("V%1-").arg(nameid+1);
    }

    QString qsChannelGUID = QUuid::createUuid().toString();

    QSqlQuery query( m_dbconn );
    query.exec( QString("INSERT INTO BSINPUTCHANNELS(bsGUID, BSID, BSTYPE, bsDeviceIP, BSBASENAME, BSNAME, bsSignalSource, bsCutLeft, bsCutRight, bsCutTop, bsCutBottom, bsBoardCardID, bsBoardCardPos, bsSubTitlePower) "
                               "VALUES ('%1', %2, %3, '%4', '%5', '%6', %7, 0, 0, 0, 0, %8, %9, 0)")
                .arg( qsChannelGUID )
                .arg( id  )
                .arg( type )
                .arg( m_pServer->m_qsConnectIPWithoutDLL )
                .arg( qsBaseName )
                .arg( qsName )
                .arg( signalSource )
                .arg( boardcardid )
                .arg( boardcardpos ));
}

void BCLocalDatabase::BuildInputChannel(int pcCount, int ipvCount, int hdCount, int vCount)
{
    // 开始启动事务
    m_dbconn.transaction();

    QSqlQuery query( m_dbconn );
    // 判断机器规模是否发生变化
    if ( !IsExistInputChannel(m_pServer->m_qsConnectIPWithoutDLL, pcCount, ipvCount, hdCount, vCount) ) {
        // 清空自定义输入通道表内数据
        query.exec( QString("DELETE FROM BSCustomGroupInputChannelMid WHERE bsGroupGUID IN (SELECT bsGUID FROM BSCustomGroupInputChannel WHERE bsDeviceIP = '%1') ").arg( m_pServer->m_qsConnectIPWithoutDLL ) );
        query.exec( QString("DELETE FROM BSCustomGroupInputChannel WHERE bsDeviceIP = '%1' ").arg( m_pServer->m_qsConnectIPWithoutDLL ) );

        // 清空输入通道数据
        query.exec( QString("DELETE FROM BSInputChannels WHERE bsDeviceIP = '%1' ").arg( m_pServer->m_qsConnectIPWithoutDLL ) );

        for (int i = 0; i < pcCount; i++) {
            BuildDeviceInputChannel(i, i, 0, 0, 0);
        }
        for (int i = 0; i < vCount; i++) {
            int id = (BCCommon::g_nDeviceType == 0) ? i : pcCount+i;
            BuildDeviceInputChannel(id, i, 3, 0, 0);
        }
        for (int i = 0; i < hdCount; i++) {
            int id = (BCCommon::g_nDeviceType == 0) ? i : pcCount+vCount+i*2;
            BuildDeviceInputChannel(id, i, 2, 0, 0);
        }
    }

    // 提交事务
    m_dbconn.commit();
}

void BCLocalDatabase::BuildGroupDislay(QList<int> lstDeviceConfig, QStringList lstDefaultScene)
{
    int nCount = lstDeviceConfig.count() / 5;
    if (0 == nCount)
        return;

    // 开始启动事务
    m_dbconn.transaction();

    QSqlQuery query( m_dbconn );

    // 不考虑分用户情况(比如admin修改通道名称所有用户一致)，涉及到用户ID全部取1
    if ( !IsExistDeviceFormat(m_pServer->m_qsConnectIPWithoutDLL, lstDeviceConfig) ) {
        // 删除单屏表
        query.exec( QString("DELETE FROM BSDisplays WHERE bsGroupDisplayGUID "
                            "IN (SELECT bsGUID FROM BSGroupDisplays WHERE bsRoomGUID "
                            "IN (SELECT bsGUID FROM BSRooms WHERE bsDeviceIP = '%1'))")
                    .arg( m_pServer->m_qsConnectIPWithoutDLL ));
        // 删除屏组表
        query.exec( QString("DELETE FROM BSGroupDisplays WHERE bsRoomGUID "
                            "IN (SELECT bsGUID FROM BSRooms WHERE bsDeviceIP = '%1')")
                    .arg( m_pServer->m_qsConnectIPWithoutDLL ));
        // 删除场景数据表
        query.exec( QString("DELETE FROM BSSceneDatas WHERE bsSceneGUID "
                            "IN (SELECT bsGUID FROM BSScenes WHERE bsGroupSceneGUID "
                            "IN (SELECT bsGUID FROM BSGroupScenes WHERE bsRoomGUID "
                            "IN (SELECT bsGUID FROM BSRooms WHERE bsDeviceIP = '%1')))")
                    .arg( m_pServer->m_qsConnectIPWithoutDLL ));
        // 删除场景表
        query.exec( QString("DELETE FROM BSScenes WHERE bsGroupSceneGUID "
                            "IN (SELECT bsGUID FROM BSGroupScenes WHERE bsRoomGUID "
                            "IN (SELECT bsGUID FROM BSRooms WHERE bsDeviceIP = '%1'))")
                    .arg( m_pServer->m_qsConnectIPWithoutDLL ));
        // 删除场景组表
        query.exec( QString("DELETE FROM BSGroupScenes WHERE bsRoomGUID "
                            "IN (SELECT bsGUID FROM BSRooms WHERE bsDeviceIP = '%1')")
                    .arg( m_pServer->m_qsConnectIPWithoutDLL ));
        // 删除房间表
        query.exec( QString("DELETE FROM BSRooms WHERE bsDeviceIP = '%1'")
                    .arg( m_pServer->m_qsConnectIPWithoutDLL ));

        // 返回输入通道数据
        for (int i = 0; i < nCount; i++) {
            int groupid = lstDeviceConfig.at(i*5+0);
            int formatx = lstDeviceConfig.at(i*5+1);
            int formaty = lstDeviceConfig.at(i*5+2);
            int resolutionx = lstDeviceConfig.at(i*5+3);
            int resolutiony = lstDeviceConfig.at(i*5+4);

            int xsize = formatx * resolutionx;
            int ysize = formaty * resolutiony;

            // 添加房间
            QString qsRoomGUID = QUuid::createUuid().toString();
            query.exec( QString("INSERT INTO BSROOMS(bsGUID, BSID, bsDeviceIP, bsDeviceType, BSNAME, BSWIDTH, BSHEIGHT, "
                                "bsIsNetConnect, bsSwitchIP, bsSwitchPort, bsSwitchCom, bsSwitchBaudRate, bsSwitchDataBit, "
                                "bsSwitchStopBit, bsSwitchCheckBit, bsSwitchStreamCtrl, bsSwitchCmdType, bsSwitchOnCmd, bsSwitchOffCmd, bsSwitchStatus, "
                                "bsIsUseVirtualResotluion, bsVirWidth, bsVirHeight) "
                                  "VALUES ('%1', %2, '%3', 0, '%4', %5, %6, "
                                "1, '', 9000, 'COM1', 9600, 8, 1, 'None', 'None', 1, '', '', 1, 0, %7, %8)")
                        .arg( qsRoomGUID )
                        .arg( groupid )
                        .arg( m_pServer->m_qsConnectIPWithoutDLL )
                        .arg( QString("GROUP") )
                        .arg( xsize )
                        .arg( ysize )
                        .arg( xsize )
                        .arg( ysize ) );

            // 添加屏组
            QString qsGroupDisplayGUID = QUuid::createUuid().toString();
            query.exec( QString("INSERT INTO BSGROUPDISPLAYS(bsGUID, bsRoomGUID, BSID, BSNAME, BSARRAYX, BSARRAYY, BSRESOLUTIONX, BSRESOLUTIONY, "
                                  "BSSEGMENTATIONX, BSSEGMENTATIONY, BSLEFT, BSTOP, BSWIDTH, BSHEIGHT, bsIsUseVirtualArray, bsVirArrayX, bsVirArrayY) "
                                  "VALUES ('%1', '%2', %3, '%4', %5, %6, %7, %8, %9, %10, %11, %12, %13, %14, 0, %15, %16)")
                        .arg( qsGroupDisplayGUID )
                        .arg( qsRoomGUID )
                        .arg( groupid )
                        .arg( QString("GROUP") )
                        .arg( formatx )
                        .arg( formaty )
                        .arg( resolutionx )
                        .arg( resolutiony )
                        .arg( formatx )
                        .arg( formaty )
                        .arg( 0 )
                        .arg( 0 )
                        .arg( xsize )
                        .arg( ysize )
                        .arg( formatx )
                        .arg( formaty ) );

            // 添加单屏
            for (int y = 0; y < formaty; y++) {
                for (int x = 0; x < formatx; x++) {
                    int displayid = (y*formatx) + x;
                    QString displayName = QString("%1").arg(y*formatx + x+1, 3, 10, QChar('0'));

                    // 添加单屏
                    QString qsDisplayGUID = QUuid::createUuid().toString();
                    query.exec( QString("INSERT INTO BSDISPLAYS(bsGUID, bsGroupDisplayGUID, BSID, BSNAME, BSRESOLUTIONX, BSRESOLUTIONY, "
                                               "BSLEFT, BSTOP, BSWIDTH, BSHEIGHT, bsSwitchStatus, bsOnCmd, bsOffCmd, bsLEDResolutionX, bsLEDResolutionY, bsSegmentation) "
                                          "VALUES ('%1', '%2', %3, '%4', %5, %6, %7, %8, %9, %10, 1, '', '', %11, %12, 4)")
                                .arg( qsDisplayGUID )
                                .arg( qsGroupDisplayGUID )
                                .arg( displayid )
                                .arg( displayName )
                                .arg( resolutionx )
                                .arg( resolutiony )
                                .arg( x*resolutionx )
                                .arg( y*resolutiony )
                                .arg( resolutionx )
                                .arg( resolutiony )
                                .arg( resolutionx )
                                .arg( resolutiony ) );
                }
            }

            // 添加默认场景组
            QString qsGroupSceneGUID = QUuid::createUuid().toString();
            query.exec( QString("INSERT INTO BSGroupScenes(bsGUID, bsRoomGUID, bsId, bsName, bsIsNormalLoop, bsIsLoop, bsLoopInterval) "
                                  "VALUES ('%1', '%2', 0, '%3', 0, 0, 3)")
                        .arg( qsGroupSceneGUID )
                        .arg( qsRoomGUID )
                        .arg( QObject::tr("GROUP1") ));

            // 添加默认场景
            QString qsDefaultSceneGUID = QUuid::createUuid().toString();
            query.exec( QString("INSERT INTO BSScenes(bsGUID, bsGroupSceneGUID, bsId, bsName, bsIsCycle, bsSort, bsLoopInterval) "
                                  "VALUES ('%1', '%2', 128, '默认场景', 0, 0, 3)")
                        .arg( qsDefaultSceneGUID )
                        .arg( qsGroupSceneGUID ) );
        }
    }

#ifndef CHANGCHUNPOWER
    // 删除默认场景数据，只有4000类型设备能读取默认场景
    if ((1 == BCCommon::g_nDeviceType) || (2 == BCCommon::g_nDeviceType)) {
        query.exec( QString("DELETE FROM BSSceneDatas WHERE bsSceneGUID "
                            "IN (SELECT bsGUID FROM BSSCENES where bsId = %1 AND bsGroupSceneGUID "
                            "IN (SELECT bsGUID FROM BSGroupScenes WHERE bsRoomGUID "
                            "IN (SELECT bsGUID FROM BSRooms WHERE bsDeviceIP = '%4'))) ")
                    .arg( 128 )
                    .arg( m_pServer->m_qsConnectIPWithoutDLL ) );

        // 添加默认场景数据，缺少屏组ID
        int nDefaultWindowCount = lstDefaultScene.count() / 7;
        for (int j = 0; j < nDefaultWindowCount; j++) {
            int nGroupDisplayID = lstDefaultScene.at( 7*j+0 ).toInt();
            int winid = lstDefaultScene.at( 7*j+1 ).toInt();
            int chid = lstDefaultScene.at( 7*j+2 ).toInt();
            int left = lstDefaultScene.at( 7*j+3 ).toInt();
            int top = lstDefaultScene.at( 7*j+4 ).toInt();
            int width = lstDefaultScene.at( 7*j+5 ).toInt();
            int height = lstDefaultScene.at( 7*j+6 ).toInt();
            QString qsIpv;
            for (int iIpv = 0; iIpv < 36; iIpv++) {
                qsIpv.append(";");
            }
            QString sql = QString( "INSERT INTO BSSCENEDATAS(bsGUID, bsSceneGUID, BSGROUPDISPLAYID, bsChannelID, bsCopyIndex, BSLEFT, BSTOP, BSWIDTH, BSHEIGHT, "
                                   "bsIPVSegmentation, bsIPVIP, BSWINID, bsChannelID) "
                                   "SELECT '%1', bsGUID, %2, %3, %4, %5, %6, %7, %8, "
                                   "%9, '%10', %11, %12 "
                                   "FROM BSScenes WHERE bsId = %13 AND bsGroupSceneGUID "
                                   "IN (SELECT bsGUID FROM BSGroupScenes WHERE bsId = %14 AND bsRoomGUID "
                                   "IN (SELECT bsGUID FROM BSRooms WHERE bsId = %15 AND bsDeviceIP = '%16'))")
                        .arg( QUuid::createUuid().toString() )
                        .arg( nGroupDisplayID )
                        .arg( chid )
                        .arg( -1 )
                        .arg( left )
                        .arg( top )
                        .arg( width )
                        .arg( height )
                        .arg( -1 )
                        .arg( qsIpv )
                        .arg( winid )
                        .arg( chid )
                        .arg( 128 )
                        .arg( 0 )
                        .arg( nGroupDisplayID )
                        .arg( m_pServer->m_qsConnectIPWithoutDLL );
            query.exec( sql );
        }
    }
#endif

    // 提交事务
    m_dbconn.commit();
}
