#pragma once
#include <stdio.h>
#include <string>
#include "Mutexs.h"
//�ļ������ӿڣ���Ӧ������ϵͳ�ӿڣ�����HOOK��,Ĭ���Ѿ���fopen/fread/fwriteʵ��
class FileHandle
{
	friend class FileIOInterface;
	
public:
	FILE*pFile = NULL;
};
class FileIOInterface
{
public:
	enum SEEKTYPE
	{
		SE_BEGIN,
		SE_CURRENT,
		SE_END,
	};
	enum OPENMODE
	{
		OP_READ,//ֻ�����ļ������ڳ���
		OP_READWRITE,//��д���ļ������ڴ��������������
		OP_READAPPEND,//��д���ļ������ڴ��������ڲ����
	};

	virtual ~FileIOInterface();
	virtual FileHandle* Open(const char*szFilePath, OPENMODE mode);
	virtual void Close(FileHandle*fHandle) ;
	virtual long long GetLength(FileHandle*fHandle);
	virtual long long Seek(FileHandle*fHandle, SEEKTYPE type,long long nOffset) ;
	virtual long long Read(FileHandle*fHandle,void*pBuffer, int nLen) ;
	virtual long long Write(FileHandle*fHandle,const void*pBuffer, int nLen) ;
	virtual bool MakeDir(const std::string& szPath);
	virtual std::string Getdir(const char* path);
	virtual void RmDir(const std::string&szPath);//ɾ���ļ����ļ���
	bool IsDirectory(const char* szPath);
	bool IsFileExist(const char*szPath);
};

