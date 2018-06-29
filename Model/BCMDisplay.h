/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：屏幕数据类
*********************************************************************************************************************************/
#ifndef BCMDISPLAY_H
#define BCMDISPLAY_H

#include <QRectF>
#include <QList>
#include <QString>

class BCMGroupDisplay;
class BCMDisplay
{
public:
    BCMDisplay(BCMGroupDisplay *pGroupDisplay);
    ~BCMDisplay();

    BCMGroupDisplay *GetMGroupDisplay();

    void SetDisplayID(int id);
    int GetDisplayID();

    void SetDisplayName(const QString &qs, bool bSendCmd = false);
    const QString &GetDisplayName();

    void SetResolution(int w, int h);
    QSize GetResolution();

    void SetRect(QRectF rect);
    QRectF GetRect();

    void SetSegmentation(int n);
    int GetSegmentation();

    int IsSwitchOn();
    void SetSwitchOn(int i, bool bSendCmd = false);

    const QString &GetSwitchOnCmd();
    void SetSwitchOnCmd(const QString &cmd, bool bSendCmd = false);

    const QString &GetSwitchOffCmd();
    void SetSwitchOffCmd(const QString &cmd, bool bSendCmd = false);

    void SetLEDResolution(QSize size);
    QSize GetLEDResolution();

protected:
    BCMGroupDisplay *m_pGroupDisplay;

    int m_id;
    QString m_name;
    int m_nResolutionW;     // 单屏分辨率
    int m_nResolutionH;
    int m_nSegmentation;    // 单屏内的分割数

    QSize m_sizeLEDResolution;  // LED时使用

    QString switchoncmd;
    QString switchoffcmd;
    int switchStatus;       // 打开状态

    QRectF m_rect;          // 单屏在组屏中的位置
};

inline QSize BCMDisplay::GetLEDResolution()
{
    return m_sizeLEDResolution;
}
inline void BCMDisplay::SetLEDResolution(QSize size)
{
    m_sizeLEDResolution = size;
}

inline BCMGroupDisplay *BCMDisplay::GetMGroupDisplay()
{
    return m_pGroupDisplay;
}

inline void BCMDisplay::SetDisplayID(int id)
{
    m_id = id;
}

inline int BCMDisplay::GetDisplayID()
{
    return m_id;
}

inline const QString &BCMDisplay::GetDisplayName()
{
    return m_name;
}

inline void BCMDisplay::SetResolution(int w, int h)
{
    m_nResolutionW = w;
    m_nResolutionH = h;
}

inline QSize BCMDisplay::GetResolution()
{
    return QSize(m_nResolutionW, m_nResolutionH);
}

inline void BCMDisplay::SetRect(QRectF rect)
{
    m_rect = rect;
}

inline QRectF BCMDisplay::GetRect()
{
    return m_rect;
}

inline void BCMDisplay::SetSegmentation(int n)
{
    m_nSegmentation = n;
}

inline int BCMDisplay::GetSegmentation()
{
    return m_nSegmentation;
}

inline int BCMDisplay::IsSwitchOn()
{
    return switchStatus;
}

inline const QString &BCMDisplay::GetSwitchOnCmd()
{
    return switchoncmd;
}

inline const QString &BCMDisplay::GetSwitchOffCmd()
{
    return switchoffcmd;
}

#endif // BCMDISPLAY_H
