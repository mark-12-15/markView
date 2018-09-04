#ifndef BCAUTODATEDLG_H
#define BCAUTODATEDLG_H

/*软件自动更新类，通过使用http协议进行下载指定的路径文件
 *先通过xml进行版本比较，然后在下载安装文件exe.
 *支持断点下载，支持超时机制（5s）
*/

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QTextCodec>
#include <QNetworkReply>
#include <QFileInfo>

namespace Ui {
class BCAutoDateDlg;
}

class BCAutoDateDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCAutoDateDlg(QWidget *parent = 0);
    ~BCAutoDateDlg();

private slots:

    void on_pushButton_down_clicked();

    void slot_Finished();

    void slot_ReadyRead();

    void slot_downloadProgress(qint64,qint64);

    void on_pushButton_exit_clicked();

    void on_pushButton_2_clicked();

    void slot_requestTimeout();  //请求超时

private:
    Ui::BCAutoDateDlg *ui;
    QNetworkAccessManager* q_manager;
    QNetworkReply* q_reply;
    QUrl m_url;     //下载地址
    QFile* m_file;  //保存文件
    bool m_istrue;  //判断重连与暂停
    void startRequest(QUrl);  //启动网络请求
    void SetErrorMessage(QString); //提示box
    void removefilesindir(const QString&);//删除所有文件
    void InitURL(QString);//初始化url
    QList< QMap<QString,QString> > ReadXml(QString);
    void deleteInit(); //释放内存

    QTimer* m_pTimer; //请求超时计时器
};

#endif // BCAUTODATEDLG_H
