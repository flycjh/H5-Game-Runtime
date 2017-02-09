#pragma once
class CArrayBuffer
{
public:
	float m_nGrowMul = 1.5f;
	uint8_t*m_pBuffer = nullptr;
	int m_nBufLen = 0;//���ݵĴ�С
	int m_nBufSize = 0;//ʵ�ʷ���Ĵ�С
	CArrayBuffer();
	~CArrayBuffer();

	void RemoveAll();


	void AddData(const void*pBuf, int nLen);
	void RemoveData(int nLen);//��ǰ��ɾ��
	uint8_t*GetBuffer();
	int GetLength();
	void Resize(int nLen);
	void AddString(const std::string &str);
};

