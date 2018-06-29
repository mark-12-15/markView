/*********************************************************************************************************************************
* 作    者：liuwl
* 摘    要：媒体数据类
*********************************************************************************************************************************/
#ifndef BCMMEDIA_H
#define BCMMEDIA_H

class BCMChannel;
class BCMVedio;
class BCMAudio;
class BCMMedia
{
public:
    BCMMedia(BCMChannel *pChannel);

protected:
    BCMChannel  *m_pChannel;    // 归属通道

    BCMVedio    *m_pVedio;      // 视频
    BCMAudio    *m_pAudio;      // 音频
};

#endif // BCMMEDIA_H
