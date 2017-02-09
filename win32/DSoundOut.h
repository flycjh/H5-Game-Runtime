#pragma once

#include <mmsystem.h>
#include <dsound.h>

//ʹ��DirectSound����PCM����


class CDSoundOut;
class CDSoundOutDelegate
{
public:
	virtual void OnPlayEnd(CDSoundOut*pSound)=NULL;
};




class  CDSoundOut
{
public:
	CDSoundOut(void);
	~CDSoundOut(void);


// #define MAX_AUDIO_BUF 2
// #define BUFFERNOTIFYSIZE /*192000*/8192

protected:
	HWND m_hWnd;

	LPDIRECTSOUNDBUFFER8 m_pDSBuffer8 ; //buffer
	LPDIRECTSOUND8 m_pDsd ; //dsound
	LPDIRECTSOUNDNOTIFY8 m_pDSNotify ; 
	DSBPOSITIONNOTIFY m_aPosNotify;// [MAX_AUDIO_BUF];//����֪ͨ��־������

	HANDLE m_event=0;// [MAX_AUDIO_BUF];
//	DWORD m_dwNextWriteOffset ;

//	BOOL m_bMute;//�Ƿ���


//	CBuffer m_Buffer;
//	CWinThread *m_PlayCheckThread;
	
	WAVEFORMATEX m_WaveFormat;
	
public:
	DWORD m_dwBufferBytes = 0;


	BOOL Init(HWND hWnd, LPWAVEFORMATEX pWaveFormat, DWORD dwBufferBytes, BYTE*pData);
	BOOL Uninit();


	void start(unsigned long dwFrom,bool bLoop);
	void stop();
	void pause();
	void seek(unsigned long dwTo);
	unsigned long GetCurrentPosition();
	bool IsStop();
	//	void Mute(BOOL bMute);

	
	//write��������������Ļ�������0,�ڲ����껺������ֹͣ����
//	void WriteEnd();

//	static UINT t_PlayCheck(LPVOID pParam);

	//��PCM����д��׼������
// 	int Write(unsigned char *pcm, int pcmlen);
// 
// 	int GetBufferMS();//ȡ�û�û���ŵĻ����ж��ٺ���
protected:
//	DWORD GetFreeBuffer();
	//д��g_pDSBuffer8
//	int WriteBuffer(BYTE*pData,int nDataLen);

};
