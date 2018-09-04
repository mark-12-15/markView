/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：板位图对话框
*********************************************************************************************************************************/
#ifndef BCSETTINGBOARDCARDDLG_H
#define BCSETTINGBOARDCARDDLG_H

#include <QDialog>
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsRectItem>

// 板卡内节点可视化item
class BSBoardCardNode;
class BCSettingBoardCardItem;
class BCSettingBoardCardNodeItem : public QGraphicsRectItem
{
public:
    BCSettingBoardCardNodeItem(BSBoardCardNode *pBoardCardNode, BCSettingBoardCardItem *parent);
    ~BCSettingBoardCardNodeItem();

    void Refresh(double dScale, double dCardOffsetX, double dCardOffsetY);

    void SetHighLight(bool b);
    bool IsHighLight();

    double  m_dScale;       // 图片缩放比例
    bool    m_bHighLight;

    BSBoardCardNode *m_pBoardCardNode;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
// --------------------------------------------------------------------------------------------------------------------------

// 板卡可视化item
class BSBoardCard;
class BCSettingBoardCardItem : public QGraphicsRectItem
{
public:
    BCSettingBoardCardItem(BSBoardCard *pBoardCard, int nPosX, int nPosY, double dOffsetX, double dOffsetY);
    ~BCSettingBoardCardItem();

    void Refresh(double dScale, double dOffsetX, double dOffsetY);

    BSBoardCard *m_pBoardCard;

    int m_nPosX;        // 在整体的位置
    int m_nPosY;

    double  m_dScale;
    double  m_dOffsetX;     // 偏移量
    double  m_dOffsetY;

    bool    m_bHighLight;   // 高亮状态，只记录状态

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
// --------------------------------------------------------------------------------------------------------------------------

// 显示板位图的graphicsView
class BCSettingBoardCardDlg;
class BCSettingBoardCardGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    BCSettingBoardCardGraphicsView(QWidget *parent = Q_NULLPTR);
    ~BCSettingBoardCardGraphicsView();

    void Init(BCSettingBoardCardDlg *pBoardCardDlg, BSBoardCard *pBoardCard, int type);

protected:
    // 向下依次传递resize命令
    void resizeEvent(QResizeEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent *event);

    void SetScale(double dScale);

    void RefreshBoardCard();

    BCSettingBoardCardNodeItem *GetBoardCardNode(QPointF pt);
    void ReverseHighLight(QPointF pt);  // ctrl+leftBtn时调用，反转高亮状态
    bool HighLight(QPointF pt);
    bool HighLight(QRectF rect);
    void ClearHighLight();

private:
    BCSettingBoardCardDlg   *m_pBoardCardDlg;

    QGraphicsScene          *m_pScene;

    BSBoardCard             *m_pBoardCard;  // 板卡数据
    int                     m_nType;        // 类型，1:4U, 2:14U

    double  m_dViewScale;   // 缩放比例

    QPointF m_beginPos;
    QRectF  m_mouseRect;    // 鼠标框选的矩形
    int     m_nMouseType;   // -1：无任何操作，0：点击，1：点中节点

    QLabel  *m_pLabel;
};

// --------------------------------------------------------------------------------------------------------------------------

namespace Ui {
class BCSettingBoardCardDlg;
}

class BCLocalTcpSocket;
class BCSettingBoardCardDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingBoardCardDlg(QWidget *parent = 0);
    ~BCSettingBoardCardDlg();

    // 刷新右侧信息，输入、输出节点
    void RefreshNodeInfo(BCSettingBoardCardNodeItem *pNodeItem);

    // 刷新右侧信息，分组信息
    void RefreshNodeInfo(QList<BCSettingBoardCardNodeItem *> lstItem);

    // 刷新板卡位置信息
    void RefreshBoardCardPos(int pos);

private slots:
    void onBoardCard(int timeout, int type);    // type=1: 4U, =2: 8U
    void onDeviceStatus(int timeout, int nVoltageOfDevice, int nElectricityOfDevice, int nRotationSpeedOfFan1, int nRotationSpeedOfFan2,
                        int nRotationSpeedOfFan3, int nRotationSpeedOfFan4, int nRotationSpeedOfFan5, int nRotationSpeedOfFan6,
                        int nRotationSpeedOfFan7, int nRotationSpeedOfFan8);
    void onBoardCardStatus(int timeout, int nCoreVoltageOfChip1, int nRoundVoltageOfChip1, int nCoreElectricityOfChip1, int nRoundElectricityOfChip1,
                           int nCoreVoltageOfChip2, int nRoundVoltageOfChip2, int nCoreElectricityOfChip2, int nRoundElectricityOfChip2,
                           int nVoltageOfMemorizer, int nElectricityOfMemorizer, int nVoltageOfInput, int nElectricityOfInput);
    void onTimeOut();

private:
    void Init();

    void DestroyBoardCardData();

private:
    Ui::BCSettingBoardCardDlg *ui;

    BCLocalTcpSocket    *m_pTcpSocket;  // 本地数据，取板位图数据

    BCSettingBoardCardNodeItem *m_pNodeItem;    // 当前选中节点
    QTimer  *m_pTimer;  // 5秒钟定时器，定时发送设备状态请求
    int m_nBoardPos;    // 点中的板卡，用来显示板卡信息

    BSBoardCard *m_pBoardCard;  // 展会临时添加
};

#endif // BCSETTINGBOARDCARDDLG_H
