#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
namespace Ui {
class LoginDialog;
}
class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

    // 返回服务器验证结果
    void SetServerRes(int res);

private slots:
    void on_settingsBut_clicked();

    void setUpUI();                                                //UI的普通设置
    void saveAllFramesWhenProjectInitializing();                   //保存初始化的布局方便用户恢复默认设置
    void changeMapValue(QMap<QString,QString> *map,QRect r);                //
    /*=================================
     *从server上获取界面布局的预留接口
     * ===============================
     */
    void getAllFramesFromeServerAfterSetted();                     //从server上获取用户自定义后的布局

    /**
     * @brief init 初始化
     */
    void init();
    /*
    *点击记住密码
     */
    void clcikCheckBox();

    void on_login_clicked();

    void on_pushButton_clicked();



    void on_toolButton_server_clicked();

private:
    Ui::LoginDialog *ui;
   void UpdateLoginXML(QString name,QString pas);
   bool checkPassword(QString name,QString pas);
   void getMapInArray(QList<QMap<QString,QString> >list, int i);


   int X;
   int Y;
   int W;
   int H;
   bool isTrue;
   QString m_ip;
   QString m_port;

protected:
    void enterEvent(QEvent *event);

};

#endif // LOGINDIALOG_H
