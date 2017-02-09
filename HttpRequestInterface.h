#pragma once
#include <string>

//HTTP����ӿڣ�Ҳ����֧�ֱ����ļ���ȡ
enum RESPONSETYPE
{
	RST_TEXT,
	RST_ARRAYBUFFER,
	RST_BLOB,
	RST_DOCUMENT,
	RST_JSON,
};

class HttpRequestInterface
{
public:
	HttpRequestInterface();
	virtual ~HttpRequestInterface();
	//����HTTP GET����ȡ�÷�������(ANSI��UTF-8),���ص�pDataRet��������ͷ�,����ֵ���ɹ�200��δ�ҵ�404
	virtual int SendGetRequest(const char*szURL, RESPONSETYPE respType, const char*szReferer, char*&pDataRet, int &nRetLen);
	virtual int SendPostRequest(const char*szURL, const char*szPostData, int nDataLen, const char*szContentType, const char*szReferer, char*&pDataRet, int &nRetLen);
	virtual int SendPostOrGetRequest(const char*szURL, const char*szType, const char*szPostData, int nDataLen, const char*szContentType, const char*szReferer, char*&pDataRet, int &nRetLen);
	std::string GetFileToCachePath(const std::string&szURL);
};

