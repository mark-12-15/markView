#include "logindialog.h"
#include "ui_logindialog.h"
#include "mydialog.h"

#include <QMessageBox>
#include <QSettings>
#include <QDebug>
#include "rootdialog.h"
#include <QPainter>
#include <QRegion>
#include <QMovie>
#include "../Common/BCCommon.h"
#include "../Common/BCXMLManager.h"
#include "../Common/BCPurviewManager.h"
#include "../Common/BCCommunication.h"
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setFixedSize(400,355);

    this->setWindowTitle(tr("登陆窗口"));
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));
    /*
    *设置界面布局
    */
    this->setUpUI();
    /*
    *初始化
    */
    this->init();
    connect(ui->checkBox,SIGNAL(clicked(bool)),this,SLOT(clcikCheckBox()));
    saveAllFramesWhenProjectInitializing();
    getAllFramesFromeServerAfterSetted();

    isTrue = true;
    ui->frame_up->show();
    ui->frame_down->hide();
    QValidator* validator = new QIntValidator( 0, 65535, this );
    ui->lineEdit_port->setValidator(validator);
    ui->lineEdit_ip->setInputMask("000.000.000.000; ");
}

LoginDialog::~LoginDialog()
{
   delete ui;

}
 /*
*设置界面布局
 */
void LoginDialog::setUpUI()
{
    ui->checkBox->setText(tr("记住密码"));
    ui->userNameEdit->setEditable(true);
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
    ui->login->setText(tr("登 陆"));
    ui->login->setStyleSheet("QPushButton{background-color:rgb(60, 195, 240);  color: white;  "
    " border-radius: 5px;  border: 1px groove lightblue;}");

    QMovie *backTopImage = new QMovie(BCCommon::g_qsImageFilePrefix+"br.gif");
    backTopImage->setScaledSize(QSize(419,160));
    ui->topBackLabel->setMovie(backTopImage);
    backTopImage->start();

    QPixmap display_img(BCCommon::g_qsImageFilePrefix+"timg.jpg");
    display_img = display_img.scaled(80,80,Qt::KeepAspectRatio);
    ui->iconImage->setPixmap(display_img);
    ui->iconImage_2->setPixmap(display_img);

}

 /*
*设置事件
 */
void LoginDialog::on_settingsBut_clicked()
{
    MyDialog dialog;
    dialog.exec();
}

bool LoginDialog::checkPassword(QString name,QString pas)
{
    MainWindow *pApplication = BCCommon::Application();
    QList<BCSUser *> users;
    users = pApplication->GetSystemUsers();
    foreach (BCSUser *user, users)
    {
        if(user->m_qsLoginName == name && user->m_qsPassword == pas)
        {
            //  进行XML文件的创建以及重新排列
            this->UpdateLoginXML(name,pas);

            pApplication->SetCurrentUser( user );

            return true;
        }
    }
    return false;
}

void LoginDialog::UpdateLoginXML(QString name,QString pas)
{
    BCXMLManager *manager = new BCXMLManager;

    if(manager->IsExistXmlFile("../xml/BCLogin.xml") == false)
    {
      manager->CreateXMLFile("../xml/BCLogin.xml");
    }
    if(manager->ContainTheNode(name) == false)
    {
        manager->CreateNode(name);
        QMap<QString,QString> map;
        map["passWord"] = pas;
        manager->AddAttribute(name,map);
    }
    manager->MoveNodeTo(name,0);
}

 /*
*登陆事件
 */

void LoginDialog::on_login_clicked()
{
    QString userName = qPrintable(ui->userNameEdit->currentText());
    QString passWord = qPrintable(ui->passwordEdit->text());
    if(userName.isEmpty())
    {
        QMessageBox::information(this,"error","用户名不能为空");
        return;
    }

    // 是否连接服务器
    BCCommon::g_bConnectWithServer = (Qt::Checked == ui->m_pConnectServer->checkState()) ? true : false;
    if ( !BCCommon::g_bConnectWithServer ) {

        // 加载系统人员权限数据
        MainWindow *pApplication = BCCommon::Application();
        pApplication->LoadSystemUser();

        int res = checkPassword(userName,passWord) ? 1 : -1;
        SetServerRes( res );
    } else {

        // 当连接服务器时需要等待异步调用
        BCCommunication *pCommunication = BCCommunication::Application();
        //pCommunication->RequestLogin(this, userName, passWord);
    }
}

void LoginDialog::SetServerRes(int res)
{
    if (-1 == res)
        QMessageBox::information(this, "error","用户名或密码错误!");
    else {
        if ( BCCommon::g_bConnectWithServer ) {
            MainWindow *pApplication = BCCommon::Application();

            BCSUser *pUser = new BCSUser;
            pUser->m_id = QString::number(res);
            pUser->m_qsName = ui->userNameEdit->currentText();
            pUser->m_qsPassword = ui->passwordEdit->text();
            pUser->m_qsPurviewLevel = QString::number(0);
            pApplication->SetCurrentUser( pUser );
        }

        accept();
    }
}

 /*
*将所有的frame保存起来方便用户恢复默认时使用
 */
void LoginDialog::saveAllFramesWhenProjectInitializing()
{
    BCXMLManager *manager = new BCXMLManager;

    if(!manager->IsExistXmlFile("../xml/LoginInitialize.xml"))
    {
            manager->CreateXMLFile("../xml/LoginInitialize.xml");
            manager->CreateNode("backLabel");
            manager->CreateNode("iconImage");
            manager->CreateNode("userNameEdit");
            manager->CreateNode("passwordEdit");
            manager->CreateNode("login");

            QMap<QString,QString>map;

            changeMapValue(&map,ui->backLabel->frameGeometry());
            manager->AddAttribute("backLabel",map);

            changeMapValue(&map,ui->iconImage->frameGeometry());
            manager->AddAttribute("iconImage",map);

            changeMapValue(&map,ui->userNameEdit->frameGeometry());
            manager->AddAttribute("userNameEdit",map);

            changeMapValue(&map,ui->passwordEdit->frameGeometry());
            manager->AddAttribute("passwordEdit",map);

            changeMapValue(&map,ui->login->frameGeometry());
            manager->AddAttribute("login",map);
    }
}

void LoginDialog::changeMapValue(QMap<QString,QString> *map,QRect r)
{
    map->insert("X",QString::number(r.x()));
    map->insert("Y",QString::number(r.y()));
    map->insert("W",QString::number(r.width()));
    map->insert("H",QString::number(r.height()));
}
 /*
*从server上获取界面布局的预留接口
 */
void LoginDialog::getAllFramesFromeServerAfterSetted()
{
    BCXMLManager *manager = new BCXMLManager;
    QList<QMap<QString,QString> >list;
    list = manager->DOM("../xml/LoginSet.xml");
    if(list.count() <= 0) return;
    getMapInArray(list,0);
    ui->backLabel->setGeometry(X,Y,W,H);
    getMapInArray(list,1);
    ui->iconImage->setGeometry(X,Y,W,H);
    getMapInArray(list,2);
    ui->userNameEdit->setGeometry(X,Y,W,H);
    getMapInArray(list,3);
    ui->passwordEdit->setGeometry(X,Y,W,H);
    getMapInArray(list,4);
    ui->login->setGeometry(X,Y,W,H);
}


void LoginDialog::getMapInArray(QList<QMap<QString,QString> >list, int i)
{
    if(list.count() > 0)
    {
         X = list.at(i).value("X").toInt();
         Y = list.at(i).value("Y").toInt()-156;
         W = list.at(i).value("W").toInt();
         H = list.at(i).value("H").toInt();
    }
}


 /*
 *初始化
  */
 void LoginDialog::init()
 {
             BCXMLManager *manager = new BCXMLManager;
             QList <QMap<QString,QString> >users;
             users = manager->DOM("../xml/BCLogin.xml");

             int user_count = users.count();
             for(int i = 0; i < user_count; i++)
             {
                 ui->userNameEdit->insertItem(i,users.at(i).value("element"));
             }

             if(user_count > 0)
             {
                  ui->passwordEdit->setFocus();
             }
             else
             {
                  ui->userNameEdit->setFocus();
             }
             if(ui->checkBox->checkState())
             {
                 ui->passwordEdit->setText(users.at(0).value("passWord"));
                 ui->login->setFocus();
             }
 }
 /*
 *点击记住密码
  */
void LoginDialog::clcikCheckBox()
{
        if(ui->checkBox->checkState())
        {
            //记住
        }
        else
        {
            //不记住
        }
}
/*
*临时测试的按钮
*/
void LoginDialog::on_pushButton_clicked()
{
            RootDialog root;
            root.exec();
}

void LoginDialog::enterEvent(QEvent */*event*/)
{
           setCursor(Qt::PointingHandCursor);
}


void LoginDialog::on_toolButton_server_clicked()
{
    if(isTrue){
        isTrue = false;
        ui->frame_up->hide();
        ui->frame_down->show();
    }
    else{
        isTrue = true;
        ui->frame_up->show();
        ui->frame_down->hide();
    }
    m_ip = ui->lineEdit_ip->text();
    m_port = ui->lineEdit_port->text();
}
