#include "account.h"

Account::Account()
{

}

Account::Account(QString userName, QString password, QString rootStyle)
{
     _name = userName; _psd = password; _style = rootStyle;

}

/*================================================
*             Setter方法
* ================================================
*/
void Account::setUserName(QString userName)
{
    _name = userName;
}

void Account::setPassword(QString password)
{
    _psd = password;
}

void Account::setRootStyle(QString rootStyle)
{
    _style = rootStyle;
}

void Account::setWallNumber(QString wallNumber)
{
    _wallNum = wallNumber;
}

void Account::setSignalSource(QString singSource)
{
    _signalSource = singSource;
}

void Account::setOutPut(QString outPut)
{
    _outPut = outPut;
}

void Account::setScence(QString scence)
{
    _scence = scence;
}

void Account::setTask(QString task)
{
    _task = task;
}

void Account::setSoftWare(QString softWare)
{
    _softWare = softWare;
}

/*================================================
*             getter方法
* ================================================
*/


QString Account::userName() const
{
    return _name;
}

QString Account::password() const
{
    return _psd;
}


QString Account::rootStyle() const
{
    return _style;
}

QString Account::wallNumber() const
{
    return _wallNum;
}QString Account::signalSource() const
{
    return _signalSource;
}

QString Account::outPut() const
{
    return _outPut;
}QString Account::scence() const
{
    return _scence;
}

QString Account::task() const
{
    return _task;
}

QString Account::softWare() const
{
    return _softWare;
}









