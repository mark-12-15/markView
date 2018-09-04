#ifndef MONITORPARSER_H
#define MONITORPARSER_H

#include <QObject>
#include <QDomElement>
#include "type.h"

class MonitorParser : public QObject
{
    Q_OBJECT
public:
    MonitorParser();

    void parse(Monitor& monitor);

    void setMonitor(const Monitor& monitor);

private:
    void parseMonitor(QDomElement elem, MonitorInfo& info);
    void setMonitorInfo(QDomElement& elem, const MonitorInfo& info);
};

#endif // MONITORPARSER_H
