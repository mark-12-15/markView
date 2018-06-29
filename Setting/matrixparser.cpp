#include "matrixparser.h"


#include "type.h"

#include <QDomDocument>
#include <QDomNode>
#include <QFile>
#include <QTextStream>
#include <QDebug>


MatrixParser::MatrixParser()
{

}



void MatrixParser::parse(QVector<ChannelInfo>& vect)
{


    QDomDocument doc("mydocument");
    QFile file(QString("../xml/matrixsetting.xml"));
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

        ChannelInfo info;

        if( element.nodeName() == "vga" ) {
            info.type = VGA;
            parseChannel(element, info);
        }

        if( element.nodeName() == "video" ) {
            info.type = VIDEO;
            parseChannel(element, info);
        }

        if( element.nodeName() == "dvi" ) {
            info.type = DVI;
            parseChannel(element, info);
        }

        if( element.nodeName() == "hdmi" ) {
            info.type = HDMI;
            parseChannel(element, info);
        }

        if( element.nodeName() == "sdi" ) {
            info.type = SDI;
            parseChannel(element, info);
        }

        if( element.nodeName() == "audeo" ) {
            info.type = AUDEO;
            parseChannel(element, info);
        }


        vect.append(info);
        element = element.nextSiblingElement();
    }

}

void MatrixParser::parseChannel(QDomElement elem, ChannelInfo& info)
{
    QDomElement element = elem.firstChildElement();
    while( !element.isNull() ) {

        if( element.nodeName() == "connect" ) {
            info.connect = element.firstChild().nodeValue().toInt();
        }

        if( element.nodeName() == "inputPortCount" ) {
            info.inputPortCount = element.firstChild().nodeValue().toInt();
        }

        if( element.nodeName() == "matrixAddress" ) {
            info.matrixAddress = element.firstChild().nodeValue().toInt();
        }

        element = element.nextSiblingElement();
    }

}


void MatrixParser::setChannels(const QVector<ChannelInfo>& vect)
{
    QDomDocument doc;
    QFile file(QString("../xml/matrixsetting.xml"));

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
        ChannelInfo info = vect.at(i);

        if (vect.at(i).type == VGA) {

            while( !element.isNull() ) {
                qDebug() << element.nodeName();
                if( element.nodeName() == "vga" ) {


                    setChannelInfo(element, info);
                }
                element = element.nextSiblingElement();
            }
            element = root.firstChildElement();
        }


        if (vect.at(i).type == VIDEO) {

            while( !element.isNull() ) {
                if( element.nodeName() == "video" ) {
                    setChannelInfo(element, info);
                }
                element = element.nextSiblingElement();
            }
            element = root.firstChildElement();
        }

        if (vect.at(i).type == DVI) {

            while( !element.isNull() ) {
                if( element.nodeName() == "dvi" ) {
                    setChannelInfo(element, info);
                }
                element = element.nextSiblingElement();
            }
            element = root.firstChildElement();
        }


        if (vect.at(i).type == HDMI) {

            while( !element.isNull() ) {
                if( element.nodeName() == "hdmi" ) {
                    setChannelInfo(element, info);
                }
                element = element.nextSiblingElement();
            }
            element = root.firstChildElement();
        }


        if (vect.at(i).type == SDI) {

            while( !element.isNull() ) {
                if( element.nodeName() == "sdi" ) {
                    setChannelInfo(element, info);
                }
                element = element.nextSiblingElement();
            }
            element = root.firstChildElement();
        }


        if (vect.at(i).type == AUDEO) {

            while( !element.isNull() ) {
                if( element.nodeName() == "audeo" ) {
                    setChannelInfo(element, info);
                }
                element = element.nextSiblingElement();
            }
            element = root.firstChildElement();
        }


    }

    QFile file2( QString("../xml/matrixsetting.xml") );
    if (!file2.open(QFile::WriteOnly | QFile::Truncate))
        return;

    QTextStream out(&file2);
    doc.save(out,4);
    file2.close();
}


void MatrixParser::setChannelInfo(QDomElement& elem, const ChannelInfo& info)
{
    QDomElement element = elem.firstChildElement();
    while( !element.isNull() ) {
        if( element.nodeName() == "connect" ) {
            element.firstChild().setNodeValue( QString::number(info.connect));
        }

        if( element.nodeName() == "inputPortCount" ) {
            element.firstChild().setNodeValue( QString::number(info.inputPortCount));
        }

        if( element.nodeName() == "matrixAddress" ) {
            element.firstChild().setNodeValue( QString::number(info.matrixAddress));
        }
        element = element.nextSiblingElement();
    }
}
