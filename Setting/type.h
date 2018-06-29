#ifndef TYPE_H
#define TYPE_H

#include <QVector>

typedef enum channeltype
{
    VGA,
    VIDEO,
    DVI,
    HDMI,
    SDI,
    AUDEO
} ChannelType;

typedef enum monitorposition
{
    LEFT,
    RIGHT,
    TOP,
    BOTTOM
} MonitorPosition;


typedef struct monitorinfo
{
    MonitorPosition position;
    int enable;
    int countH;
    int countV;
    int isSupportControl;

} MonitorInfo;

typedef struct monitor
{
    QVector<MonitorInfo> vect;
    int customEnable;
    int customCount;
} Monitor;

#endif // TYPE_H

