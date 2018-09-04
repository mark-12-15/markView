#include "ThreadFile.h"
#include <QTextStream>
#include <QDateTime>
#include <QDebug>
ThreadFile::ThreadFile()
{

}

void ThreadFile::run(){
    m_file.setFileName("Heart.txt");
    if (!m_file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QDateTime nowtime = QDateTime::currentDateTime();
    while(1){
        if(nowtime.toString("yyyy-MM-dd hh:mm:ss") != QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")){
            QTextStream out(&m_file);
            out << "Heart:" << nowtime.toString("yyyy-MM-dd hh:mm:ss") << "\n";
            nowtime = QDateTime::currentDateTime();
        }
   }

}
