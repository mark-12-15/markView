#include "BCExProcessBtn.h"
#include <QProcess>
#include <QDir>
#include <QDebug>
#include <QFileIconProvider>
#include <QMouseEvent>

BCExProcessBtn::BCExProcessBtn(QString path,QWidget *parent)
    :QToolButton(parent)
{
    m_path = path;
    QFileInfo fileinfo(path);
    QFileIconProvider icon_provider;
    QIcon icon = icon_provider.icon(fileinfo);
    this->setText(fileinfo.baseName());
    this->setIcon(icon);
    this->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    connect(this,SIGNAL(leftButtonClicked()),this,SLOT(on_leftclicked()));
    connect(this,SIGNAL(rightButtonClicked()),this,SLOT(on_rightclicked()));

}
BCExProcessBtn::~BCExProcessBtn(){
    delete this;
}

void BCExProcessBtn::mouseReleaseEvent(QMouseEvent *e){
   if (Qt::LeftButton == e->button())
   {
       emit leftButtonClicked();
   }
   else if (Qt::RightButton == e->button())
   {
       emit rightButtonClicked();
   }
}

void BCExProcessBtn::on_leftclicked(){
    QProcess *myProcess = new QProcess();
    QString str;
    QDir dir;
    str = dir.toNativeSeparators(m_path);
    str = "\""+str+"\"";
    myProcess->start(str);

}

void BCExProcessBtn::on_rightclicked(){
    this->close();
}

