#ifndef CONTROLLERPARSER_H
#define CONTROLLERPARSER_H

#include <QObject>
#include <QDomElement>

#include "type.h"

class ControllerParser : QObject
{
public:
    ControllerParser();
    void parse(ControllerInfo&);
    void setController(ControllerInfo info);
private:
    void parseOutput(QDomElement, ControllerInfo&);
    void parseInput(QDomElement, ControllerInfo&);

    void setOutput(QDomElement &elem, const ControllerInfo& info);
    void setIntput(QDomElement &elem, const ControllerInfo& info);
};

#endif // CONTROLLERPARSER_H
