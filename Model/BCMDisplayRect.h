/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：屏幕内矩形框类
*********************************************************************************************************************************/
#ifndef BCMDISPLAYRECT_H
#define BCMDISPLAYRECT_H

#include <QRectF>
#include <QString>

class BCMDisplay;
class BCMDisplayRect
{
public:
    BCMDisplayRect(BCMDisplay *pDisplay, const QString &id);

    BCMDisplay *GetMDisplay();

    void SetRect(QRectF rect);
    QRectF GetRect();

private:
    BCMDisplay *m_pDisplay;
    QString m_id;

    QRectF m_rect;       // 单屏在组屏中的位置
};

inline BCMDisplay *BCMDisplayRect::GetMDisplay()
{
    return m_pDisplay;
}

inline void BCMDisplayRect::SetRect(QRectF rect)
{
    m_rect = rect;
}

inline QRectF BCMDisplayRect::GetRect()
{
    return m_rect;
}

#endif // BCMDISPLAYRECT_H
