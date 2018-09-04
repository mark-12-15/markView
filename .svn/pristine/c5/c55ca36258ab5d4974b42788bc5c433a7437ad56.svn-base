#include "monitorparser.h"
#include <QDomDocument>
#include <QDomNode>
#include <QFile>
#include <QTextStream>
#include <QDebug>


MonitorParser::MonitorParser()
{

}


void MonitorParser::parse(Monitor& monitor)
{

    QVector<MonitorInfo>& vect = monitor.vect;

    QDomDocument doc("mydocument");
    QFile file(QString("../xml/monitorconfig.xml"));
    if (!file.open(QIODevice::ReadOnly))
        return;
    if (!doc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();


    QDomElement root = doc.documentElement();
    QDomElement element = root.firstChildElement();

    while( !element.isNull() ) {

        MonitorInfo info;

        if( element.nodeName() == "left" ) {
            info.position = LEFT;
            parseMonitor(element, info);
        }

        if( element.nodeName() == "right" ) {
            info.position = RIGHT;
            parseMonitor(element, info);
        }

        if( element.nodeName() == "top" ) {
            info.position = TOP;
            parseMonitor(element, info);
        }

        if( element.nodeName() == "bottom" ) {
            info.position = BOTTOM;
            parseMonitor(element, info);
        }

        if( element.nodeName() == "customEnable" ) {
            monitor.customEnable = element.firstChild().nodeValue().toInt();
        }

        if( element.nodeName() == "customCount" ) {
            monitor.customCount = element.firstChild().nodeValue().toInt();
        }

        vect.append(info);
        element = element.nextSiblingElement();
    }

}


void MonitorParser::parseMonitor(QDomElement elem, MonitorInfo& info)
{
    QDomElement element = elem.firstChildElement();
    while( !element.isNull() ) {

        if( element.nodeName() == "enable" ) {
            info.enable = element.firstChild().nodeValue().toInt();
        }

        if( element.nodeName() == "countH" ) {
            info.countH = element.firstChild().nodeValue().toInt();
        }

        if( element.nodeName() == "countV" ) {
            info.countV = element.firstChild().nodeValue().toInt();
        }

        if( element.nodeName() == "isSupportControl" ) {
            info.isSupportControl = element.firstChild().nodeValue().toInt();
        }

        element = element.nextSiblingElement();
    }

}





void MonitorParser::setMonitor(const Monitor& monitor)
{

    QVector<MonitorInfo> vect = monitor.vect;

    QDomDocument doc;
    QFile file(QString("../xml/monitorconfig.xml"));

    if (!file.open(QFile::ReadOnly))
        return;
    if (!doc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();


    QDomElement root = doc.documentElement();
    QDomElement element = root.firstChildElement();



    for (int i = 0; i < vect.size(); i++) {
        MonitorInfo info = vect.at(i);

        if (vect.at(i).position == LEFT) {

            while( !element.isNull() ) {
                if( element.nodeName() == "left" ) {
                    setMonitorInfo(element, info);
                }
                element = element.nextSiblingElement();
            }
            element = root.firstChildElement();
        }

        if (vect.at(i).position == RIGHT) {

            while( !element.isNull() ) {
                if( element.nodeName() == "right" ) {
                    setMonitorInfo(element, info);
                }
                element = element.nextSiblingElement();
            }
            element = root.firstChildElement();
        }

        if (vect.at(i).position == TOP) {

            while( !element.isNull() ) {
                if( element.nodeName() == "top" ) {
                    setMonitorInfo(element, info);
                }
                element = element.nextSiblingElement();
            }
            element = root.firstChildElement();
        }

        if (vect.at(i).position == BOTTOM) {

            while( !element.isNull() ) {
                if( element.nodeName() == "bottom" ) {
                    setMonitorInfo(element, info);
                }
                element = element.nextSiblingElement();
            }
            element = root.firstChildElement();
        }

    }


    while( !element.isNull() ) {

        if( element.nodeName() == "customEnable" ) {
            element.firstChild().setNodeValue( QString::number(monitor.customEnable));
        }
        if( element.nodeName() == "customCount" ) {
            element.firstChild().setNodeValue( QString::number(monitor.customCount));
        }
        element = element.nextSiblingElement();
    }




    QFile file2( QString("../xml/monitorconfig.xml") );
    if (!file2.open(QFile::WriteOnly | QFile::Truncate))
        return;

    QTextStream out(&file2);
    doc.save(out,4);
    file2.close();
}


void MonitorParser::setMonitorInfo(QDomElement& elem, const MonitorInfo& info)
{
    QDomElement element = elem.firstChildElement();
    while( !element.isNull() ) {
        if( element.nodeName() == "enable" ) {
            element.firstChild().setNodeValue( QString::number(info.enable));
        }

        if( element.nodeName() == "countH" ) {
            element.firstChild().setNodeValue( QString::number(info.countH));
        }

        if( element.nodeName() == "countV" ) {
            element.firstChild().setNodeValue( QString::number(info.countV));
        }

        if( element.nodeName() == "isSupportControl" ) {
            element.firstChild().setNodeValue( QString::number(info.isSupportControl));
        }

        element = element.nextSiblingElement();
    }
}




