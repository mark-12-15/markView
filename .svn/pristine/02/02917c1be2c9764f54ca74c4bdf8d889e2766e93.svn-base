#ifndef BCVEDIOPLAYERTHREAD_H
#define BCVEDIOPLAYERTHREAD_H

#include <QThread>

class BCVedioManager;
class BCVedioPlayerThread : public QThread
{
public:
    BCVedioPlayerThread(BCVedioManager *parent = NULL);
    ~BCVedioPlayerThread();

    void run();

    void Quit();

private:
    bool m_bQuit;   // 退出标识

    uint8_t		*SrcData[4];
    int			SrcLinesize[4];

    uint8_t		*DesData[4];
    int			DesLinesize[4];

    BCVedioManager *m_parent;
};

#endif // BCVEDIOPLAYERTHREAD_H
