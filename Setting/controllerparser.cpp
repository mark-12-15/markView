#include "controllerparser.h"

#include "type.h"

#include <QDomDocument>
#include <QDomNode>
#include <QFile>
#include <QTextStream>
#include <QDebug>


ControllerParser::ControllerParser()
{

}

void ControllerParser::parse(ControllerInfo& info)
{

    ControllerInfo courseInfo;

    QDomDocument doc("mydocument");
    QFile file(QString("../xml/controllersetting.xml"));
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
        if( element.nodeName() == "output" ) {
            parseOutput(element, info);
        }

        if( element.nodeName() == "input" ) {
            parseInput(element, info);
        }


        element = element.nextSiblingElement();
    }

}

void ControllerParser::parseOutput(QDomElement elem, ControllerInfo& info)
{
    QDomElement element = elem.firstChildElement();
    while( !element.isNull() ) {

        if( element.nodeName() == "resolutionWide" ) {
            info.resolutionWide = element.firstChild().nodeValue().toInt();
        }

        if( element.nodeName() == "resolutionHeight" ) {
            info.resolutionHeight = element.firstChild().nodeValue().toInt();
        }

        if( element.nodeName() == "physicalH" ) {
            info.physicalH = element.firstChild().nodeValue().toInt();
        }

        if( element.nodeName() == "physicalV" ) {
            info.physicalV = element.firstChild().nodeValue().toInt();
        }

        if( element.nodeName() == "logicalH" ) {
            info.logicalH = element.firstChild().nodeValue().toInt();
        }

        if( element.nodeName() == "logicalV" ) {
            info.logicalV = element.firstChild().nodeValue().toInt();
        }

        if( element.nodeName() == "bottomEnable" ) {
            info.bottomEnable = element.firstChild().nodeValue().toInt();
        }

        if( element.nodeName() == "bottomCount" ) {
            info.bottomCount = element.firstChild().nodeValue().toInt();
        }

        if( element.nodeName() == "refreshRate" ) {
            int refreshRate = element.firstChild().nodeValue().toInt();
            if (refreshRate == 75) {
                info.refreshRate = 0;
            }
            if (refreshRate == 60) {
                info.refreshRate = 1;
            }
        }

        if( element.nodeName() == "borderH" ) {
            info.borderH = element.firstChild().nodeValue().toInt();
        }

        if( element.nodeName() == "borderV" ) {
            info.borderV = element.firstChild().nodeValue().toInt();
        }

        element = element.nextSiblingElement();
    }

}


void ControllerParser::parseInput(QDomElement elem, ControllerInfo& info)
{
    QDomElement element = elem.firstChildElement();
    while( !element.isNull() ) {
        if( element.nodeName() == "type" ) {
            info.type = element.firstChild().nodeValue().toInt();
        }

        if( element.nodeName() == "startPosition" ) {
            info.startPosition = element.firstChild().nodeValue().toInt();
        }

        if( element.nodeName() == "count" ) {
            info.count = element.firstChild().nodeValue().toInt();
        }
        element = element.nextSiblingElement();
    }
}


void ControllerParser::setController(ControllerInfo info)
{
    QDomDocument doc;
    QFile file(QString("../xml/controllersetting.xml"));

    if (!file.open(QFile::ReadOnly))
        return;
    if (!doc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();


    QDomElement root = doc.documentElement();
    QDomElement element = root.firstChildElement();

    while( !element.isNull() ) {
        if( element.nodeName() == "output" ) {
            setOutput(element, info);
        }

        if( element.nodeName() == "input" ) {
            setIntput(element, info);
        }

        element = element.nextSiblingElement();
    }

    QFile file2(QString("../xml/controllersetting.xml") );
    if (!file2.open(QFile::WriteOnly | QFile::Truncate))
        return;

    QTextStream out(&file2);
    doc.save(out,4);
    file2.close();
}


void ControllerParser::setOutput(QDomElement &elem, const ControllerInfo& info)
{
    QDomElement element = elem.firstChildElement();
    while( !element.isNull() ) {
        if( element.nodeName() == "resolutionWide" ) {
            element.firstChild().setNodeValue( QString::number(info.resolutionWide));
        }

        if( element.nodeName() == "resolutionHeight" ) {
            element.firstChild().setNodeValue( QString::number(info.resolutionHeight));
        }

        if( element.nodeName() == "physicalH" ) {
            element.firstChild().setNodeValue( QString::number(info.physicalH));
        }

        if( element.nodeName() == "physicalV" ) {
            element.firstChild().setNodeValue( QString::number(info.physicalV));
        }

        if( element.nodeName() == "logicalH" ) {
            element.firstChild().setNodeValue( QString::number(info.logicalH));
        }

        if( element.nodeName() == "logicalV" ) {
            element.firstChild().setNodeValue( QString::number(info.logicalV));
        }

        if( element.nodeName() == "bottomEnable" ) {
            element.firstChild().setNodeValue( QString::number(info.bottomEnable));
        }

        if( element.nodeName() == "bottomCount" ) {
            element.firstChild().setNodeValue( QString::number(info.bottomCount));
        }

        if( element.nodeName() == "refreshRate" ) {
            element.firstChild().setNodeValue( QString::number(info.refreshRate));
        }

        if( element.nodeName() == "borderH" ) {
            element.firstChild().setNodeValue( QString::number(info.borderH));
        }

        if( element.nodeName() == "borderV" ) {
            element.firstChild().setNodeValue( QString::number(info.borderV));
        }

        element = element.nextSiblingElement();
    }
}

void ControllerParser::setIntput(QDomElement &elem, const ControllerInfo& info)
{
    QDomElement element = elem.firstChildElement();
    while( !element.isNull() ) {
        if( element.nodeName() == "type" ) {
            element.firstChild().setNodeValue( QString::number(info.type));
        }

        if( element.nodeName() == "startPosition" ) {
            element.firstChild().setNodeValue( QString::number(info.startPosition));
        }

        if( element.nodeName() == "count" ) {
            element.firstChild().setNodeValue( QString::number(info.count));
        }
        element = element.nextSiblingElement();
    }
}




