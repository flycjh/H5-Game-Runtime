// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// XiaobaiEngine.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

// TODO:  �� STDAFX.H ��
// �����κ�����ĸ���ͷ�ļ����������ڴ��ļ�������
#ifndef _WIN32
char * _itoa(int _Val, char * _DstBuf, int _Radix)
{
	if (_Radix == 10)
		sprintf(_DstBuf, "%d", _Val);
	else if (_Radix == 16)
		sprintf(_DstBuf, "%x", _Val);
	else assert(0);
	return _DstBuf;
}


#endif

uint32_t GetTime()
{
#ifdef _WIN32
	return GetTickCount();
#else 
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
#endif
}

#ifdef _WIN32
void pthread_mutex_init(pthread_mutex_t*mutex, int i)
{
	InitializeCriticalSection(mutex);
}
void pthread_mutex_destroy(pthread_mutex_t*mutex)
{
	DeleteCriticalSection(mutex);
}
void pthread_mutex_unlock(pthread_mutex_t*mutex)
{
	LeaveCriticalSection(mutex);
}
void pthread_mutex_lock(pthread_mutex_t *mutex)
{
	EnterCriticalSection(mutex);
}
int pthread_mutex_trylock(pthread_mutex_t*mutex)
{
	return !TryEnterCriticalSection(mutex);
}
#endif