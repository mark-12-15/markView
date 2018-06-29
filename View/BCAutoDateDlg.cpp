#include "BCAutoDateDlg.h"
#include "ui_BCAutoDateDlg.h"
#include <QMessageBox>
#include <QProcess>
#include <QDir>
#include <QTimer>
#include "../Common/BCXMLManager.h"
#include "../Common/BCCommon.h"

BCAutoDateDlg::BCAutoDateDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCAutoDateDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("系统升级"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    //this->setWindowFlags(Qt::WindowMinimizeButtonHint |Qt::WindowCloseButtonHint);
//    q_reply = NULL;
//    m_file = NULL;
//    ui->progressBar->setValue(0);
//    m_istrue = true;
//    ui->label_size->setText(tr("0 bytes"));
//    QList< QMap<QString,QString> > listold = ReadXml("../xml/BCVersion.xml");
//    ui->label_version->setText(listold.at(0).value("Version"));

//    q_manager = new QNetworkAccessManager(this);
//    m_pTimer = new QTimer;
//    //超时处理
//    connect(m_pTimer,SIGNAL(timeout()),this,SLOT(slot_requestTimeout()));//超时信号

}

BCAutoDateDlg::~BCAutoDateDlg()
{
//    m_pTimer->stop();
//    delete m_pTimer;
//    m_pTimer = NULL;

    delete ui;
}


void BCAutoDateDlg::InitURL(QString str){
    m_url = str;
    if(!m_url.isValid()){
        SetErrorMessage(tr("不是有效url"));
        return;
    }
    if(m_url.scheme() != "http")
    {
        SetErrorMessage(tr("URL必须是http开头"));
        return;
    }
    if (m_url.path().isEmpty())
    {
        SetErrorMessage(tr("URL路径为空"));
        return;
    }
    QFileInfo info(m_url.path());
    QString fileName("../"+info.fileName());
    if(fileName.isEmpty())
    {
        SetErrorMessage(tr("文件名为空"));
        return;
    }
    m_file = new QFile(fileName);
    if(!m_file->open(QIODevice::WriteOnly)){
        delete m_file;
        m_file = NULL;
        return;
    }
}

void BCAutoDateDlg::on_pushButton_down_clicked()
{
//    ui->pushButton_down->setEnabled(false);

//    //使用同步事件确保第一个网络请求可以下载成功，在下载第二个网络请求

//    //第一个调用同步接收事件
//    QEventLoop eventloop;
//    InitURL("http://www.brillview.com/weixin/php/tool/ExcelFiles/BCVersion.xml");//BCVersion.xml
//    startRequest(m_url);
//    connect(q_reply, SIGNAL(finished()), &eventloop, SLOT(quit()));
//    eventloop.exec();


//    //比较version版本
//    bool version = true;
//    QList< QMap<QString,QString> > listold = ReadXml("../xml/BCVersion.xml");
//    QList< QMap<QString,QString> > listnew = ReadXml("../BCVersion.xml");
//    QString strold = listold.at(0).value("Version");
//    QString strnew = listnew.at(0).value("Version");
//    QString str = QString("当前版本：%1 - 最新版本：%2 \n是否更新软件？").arg(strold).arg(strnew);
//    QMessageBox box(QMessageBox::Warning,tr("提示"),str);
//    box.setWindowFlags(Qt::WindowStaysOnTopHint);
//    box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
//    box.setButtonText (QMessageBox::Ok,QString(tr("确 定")));
//    box.setButtonText (QMessageBox::Cancel,QString(tr("取 消")));

//    switch(box.exec()){
//        case QMessageBox::Ok :{
//            if(strold.compare(strnew) == 0){
//                version = false;
//            }
//            else{
//                version = true;
//            }
//            break;
//        }
//        case QMessageBox::Cancel :{
//            version = false;
//            break;

//        }
//    }
//    if(version == true){
//        //第二个调用异步接收事件
//        InitURL("http://www.brillview.com/weixin/php/tool/ExcelFiles/BrillviewSetup.exe");//BrillviewSetup.exe
//        startRequest(m_url);
//        //第一个q_reply接收完数据不做处理 第二个q_reply退出要做处理
//        connect(q_reply,SIGNAL(finished()),this,SLOT(slot_Finished()));
//    }else{

//        deleteInit();

//        QFile file("../BCVersion.xml");
//        file.remove();
//        QFile file1("../BrillviewSetup.exe");
//        file1.remove();
//    }
//    ui->pushButton_down->setEnabled(true);
}

void BCAutoDateDlg::startRequest(QUrl url){
    QNetworkRequest qheader;
    qheader.setUrl(url);
    QString Range="bytes="+QString::number(m_file->size())+"-";//告诉服务器从size起开始传输
    qheader.setRawHeader("Range",Range.toLatin1());
    if(q_reply != NULL){
        q_reply->deleteLater();
        q_reply = NULL;
    }
      qDebug()<<"q_manager1:"<<q_manager;
    q_reply = q_manager->get(qheader);
    qDebug()<<"q_manager2:"<<q_manager;
   //下载完成后
   //connect(q_reply,SIGNAL(finished()),this,SLOT(slot_Finished()));
   //读取数据
    connect(q_reply,SIGNAL(readyRead()),this,SLOT(slot_ReadyRead()));
   //更新进度条
    connect(q_reply,SIGNAL(downloadProgress(qint64,qint64)),
            this,SLOT(slot_downloadProgress(qint64,qint64)));

}

void BCAutoDateDlg::deleteInit(){
    m_pTimer->stop();
    if(q_reply != NULL){
        q_reply->deleteLater();
        q_reply = NULL;
    }
    if(m_file != NULL){
        m_file->flush();
        m_file->close();
        delete m_file;
        m_file = NULL;
    }
}

void BCAutoDateDlg::slot_Finished(){
    //超时处理
    QVariant status_code = q_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    //无错误返回
    qDebug()<<"q_replyerror:"<<q_reply->error();
    if(q_reply->error() == QNetworkReply::NoError)
    {
        deleteInit();
        q_manager->deleteLater();
        q_manager = NULL;

        //运行外部程序，关闭主程序
        QDir dir;
        QString str,str1;
    //    str = dir.toNativeSeparators("C:/Users/lyz/Desktop/BRI/uninst.exe");
    //    QProcess::execute("cmd",QStringList()<<"/c"<<str);
        removefilesindir("../");

        QProcess* myprocess = new QProcess();
        str1 = dir.toNativeSeparators("../BrillviewSetup.exe");
        myprocess->start("cmd",QStringList()<<"/c"<<str1);
        if(!myprocess->waitForStarted()){
            qDebug()<<myprocess->errorString();
        }
        qApp->quit();
    }else{
        //一开始http连接进行超时判断
         m_pTimer->start(5000);
    }

}

void BCAutoDateDlg::slot_ReadyRead(){
    if(m_file){
         m_file->write(q_reply->readAll());
     }
    //下载过程中http中断的超时判断
    if(m_pTimer->isActive()){
        m_pTimer->stop();
    }
    m_pTimer->start(5000);
}

void BCAutoDateDlg::slot_downloadProgress(qint64 bytesRead, qint64 totalBytes)
 {
    ui->progressBar->setMaximum(totalBytes); //最大值
    ui->progressBar->setValue(bytesRead);  //当前值
    ui->label_size->setText(QString("%1 bytes").arg(m_file->size()));
}

void BCAutoDateDlg::SetErrorMessage(QString str){
    QMessageBox box(QMessageBox::Warning,tr("错误"),str);
    box.setWindowFlags(Qt::WindowStaysOnTopHint);
    box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
    box.setButtonText (QMessageBox::Ok,QString(tr("确 定")));
    box.setButtonText (QMessageBox::Cancel,QString(tr("取 消")));
    box.exec ();
}

//删除路径下所有文件，保留xml和resource文件
void BCAutoDateDlg::removefilesindir(const QString& path)
{
  QDir dir(path);
  QFileInfoList info_list = dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoDotAndDotDot | QDir::NoSymLinks | QDir::AllDirs);
  foreach(QFileInfo file_info, info_list)
  {
    if (file_info.isDir())
    {
        if(file_info.baseName() == tr("xml")){

        }
        else if(file_info.baseName() == tr("resource")){

        }
        else{
            removefilesindir(file_info.absoluteFilePath());
        }

    }
    else if (file_info.isFile())
    {
      QFile file(file_info.absoluteFilePath());
      qDebug() << "remove file  : " << file_info.absoluteFilePath();
      if(file_info.baseName() != tr("BrillviewSetup"))
      {
           file.remove();
      }
    }
  }
  QDir temp_dir;
  temp_dir.rmdir(path) ;
  qDebug() << "remove empty dir : " << path;
}

void BCAutoDateDlg::on_pushButton_exit_clicked()
{
//    deleteInit();
//    if(m_pTimer != NULL){
//        m_pTimer->deleteLater();
//        m_pTimer = NULL;
//    }
    this->close();
}

void BCAutoDateDlg::on_pushButton_2_clicked()
{
//    q_reply->deleteLater();
//    q_reply = NULL;
//    m_pTimer->stop();
//    if(m_istrue){
//        m_istrue = false;
//        ui->pushButton_2->setText(tr("重连"));
//    }
//    else{
//        m_istrue = true;
//        startRequest(m_url);
//        ui->pushButton_2->setText(tr("暂停"));
//    }
}

//请求超时
void BCAutoDateDlg::slot_requestTimeout()
{
    q_reply->deleteLater();
    q_reply = NULL;
    m_pTimer->stop();
    SetErrorMessage("网络连接超时");
}

//
QList< QMap<QString,QString> > BCAutoDateDlg::ReadXml(QString str){
    BCXMLManager *manager = new BCXMLManager;
    QList< QMap<QString,QString> > list;
    list = manager->DOM(str);
    return list;
}
