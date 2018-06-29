#ifndef ACCOUNT_H
#define ACCOUNT_H

/*=================================================================================================================
 *
 *
 * =================================================================================================================
 *
 */

#include <iostream>
#include <QString>
#include <QMap>
class Account
{
public:

    Account();
    /*
    *   参数描述userName：用户名
    *          password：密码
    *          rootStyle：权限角色（管理员、操作员、查看员）
    */
   Account( QString userName,QString password,QString rootStyle);

//所有属性的setter方法
   /*
    *每个用户的信号源、输出端、场景、任务系统以及软件相对应的权限以字符串的形式存储 如：(1,5,9)就代表他有顺序标号1,5,9的权限
    *
    *
    */
   void setUserName(QString userName);
   void setPassword(QString password);
   void setRootStyle(QString rootStyle);
   void setWallNumber(QString wallNumber);
   void setSignalSource(QString singSource);
   void setOutPut(QString outPut);
   void setScence(QString scence);
   void setTask(QString task);
   void setSoftWare(QString softWare);




//所有属性的get方法
   QString userName() const;
   QString password() const;
   QString rootStyle() const;
   QString wallNumber() const;
   QString signalSource() const;
   QString outPut() const;
   QString scence() const;
   QString task() const;
   QString softWare() const;


//
private:
   QString _name;
   QString _psd;
   QString _style;
   QString _wallNum;
   QString _signalSource;
   QString _outPut;
   QString _scence;
   QString _task;
   QString _softWare;

};

#endif // ACCOUNT_H
