#pragma once
class HttpParser
{
public:
	HttpParser();
	~HttpParser();

	int m_nRetCode = 0;//����200/404��
	int m_nContentLength = 0;//���ݳ���
	int m_DataOffset = 0;//����ָ��
	bool m_bTransferEncodingChunked = false;

	bool m_bHaveContentLength = false;
	bool Parse(char*pData);
};

