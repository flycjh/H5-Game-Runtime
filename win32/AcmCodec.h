#pragma once

#include <MMSYSTEM.H>
#include <mmreg.h>
#include <msacm.H>
#pragma comment(lib,"Msacm32.lib")

// Locate a driver that supports a given format and return its ID
//Ѱ��һ��֧�ָ�����ʽ��������������ID
struct FIND_DRIVER_INFO{
	HACMDRIVERID hadid;//ָ��HACMDRIVERID�ľ��
	WORD wFormatTag;//32λ�޷������� ��ʽ��ǩ
	WAVEFORMATEX *pwfSrc;//Ҫƥ��ĸ�ʽ
//	DWORD nAvgBytesPerSec;//ö��ʱ�����ϴ�ö�ٵ�������
	int npwfDestSize;//Ŀ���ʽ��sizeof
	std::vector<WAVEFORMATEX*>arpwfDest;//ƥ������и�ʽ
	FIND_DRIVER_INFO()
	{
		hadid=0;
		wFormatTag=0;
		pwfSrc=0;
		npwfDestSize=0;
//		nAvgBytesPerSec=0xffffffff;
	}
	~FIND_DRIVER_INFO()
	{
		for(int i=0;i<arpwfDest.size();i++)
		{
			delete arpwfDest[i];
		}
		arpwfDest.clear();
	}
} ;//�ṹFIND_DRIVER_INFO����2��Ԫ��:HACMDRIVERID hadid ��WORD wFormatTag

//ʹ��ACM��Ƶ������
class  CAcmCodec
{
public:
	CAcmCodec(void);
	~CAcmCodec(void);

protected:
	WAVEFORMATEX m_wfSrcPCM;//Encode�����PCM��ʽ
	HACMDRIVERID m_hadid;

	WAVEFORMATEX* m_pwfMP3;//Encode�����MP3��ʽ(�Զ�����m_wfSrcPCMƥ��)
	WAVEFORMATEX* m_pwfPCM;//Encodeʱ�������PCM��ʽת�ɱ����������õ�PCM��ʽ

	HACMSTREAM m_hstrPCM;
	HACMSTREAM m_hstrPCMtoMP3;

	HACMDRIVER m_had ;

	ACMSTREAMHEADER strhdr;
	ACMSTREAMHEADER strhdr2;



	// callback function for format enumeration
	//����ö�ٸ�ʽ�Ļص�����
	static BOOL CALLBACK find_format_enum(HACMDRIVERID hadid, LPACMFORMATDETAILS pafd, DWORD dwInstance, DWORD fdwSupport);//LPACMFORMATDETAILS pafdָ��ACM��ʽ�����ָ��


	// callback function for driver enumeration
	//����ö�������Ļص�����
	static BOOL CALLBACK find_driver_enum(HACMDRIVERID hadid, DWORD dwInstance, DWORD fdwSupport);

	// locate the first driver that supports a given format tag
	//Ѱ��֧�ָ�����ʽ��ǩ�ĵ�һ������

	// get a description of the first format supported for a given tag
	//��ȡ���������� ��������ǵ�һ��֧�ָ�����ǩ��������
	WAVEFORMATEX* get_driver_format(HACMDRIVERID hadid, WORD wFormatTag,WAVEFORMATEX *pwfSrc);

public:
	static HACMDRIVERID find_driver(WORD wFormatTag);

	BOOL Init(DWORD nSamplesPerSec=22050,WORD wBitsPerSample=16,WORD nChannels=2,WORD wFormatTag = WAVE_FORMAT_MPEGLAYER3);

	void Uninit();

	BOOL Encode(BYTE*pSrcData,DWORD dwSrcBytes,OUT BYTE*&pBufferOut,OUT DWORD&nOutlen);

};

//////////////////////////////////////////////////////////////////////////
class  CAcmDecodec
{
protected:
// 	WAVEFORMATEX m_wfSrcMP3;//�����MP3��ʽ
// 	WAVEFORMATEX m_wfDestPCM;//�����PCM��ʽ
	HACMDRIVERID m_hadid;
	HACMSTREAM m_hstrMP3toPCM;
	HACMDRIVER m_had ;

	ACMSTREAMHEADER strhdr;
public:
	CAcmDecodec();
	~CAcmDecodec();


	BOOL Init(WAVEFORMATEX*pSrcMP3,WAVEFORMATEX*pDestPCM,WORD wFormatTag = WAVE_FORMAT_MPEGLAYER3);

	//���룬���سɹ������pSrcData����
	DWORD Decode(BYTE*pSrcData,DWORD dwSrcBytes/*,DWORD dwOrigBytes*/, OUT BYTE*&pBufferOut,OUT DWORD&nOutlen);

	void Uninit();


	bool DecodeFromFile(const char*szFile, OUT BYTE*&pBufferOut, OUT DWORD&nOutlen);

};
