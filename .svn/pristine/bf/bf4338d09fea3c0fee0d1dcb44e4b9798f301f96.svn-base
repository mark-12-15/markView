#ifndef MATRIXPARSER_H
#define MATRIXPARSER_H

#include <QObject>
#include <QDomElement>
#include "type.h"

#include <QVector>

class MatrixParser : public QObject
{
public:
    MatrixParser();

    void parse(QVector<ChannelInfo>& vect);
    void setChannels(const QVector<ChannelInfo>& vect);

private:
    void parseChannel(QDomElement elem, ChannelInfo& info);
    void setChannelInfo(QDomElement& elem, const ChannelInfo& info);
};

#endif // MATRIXPARSER_H

