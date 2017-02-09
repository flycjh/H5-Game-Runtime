#pragma once
using namespace std;

class CBase64
{
public:
	CBase64();
	~CBase64();

	/*********************************************************
	* ����˵�������������ݽ���base64����
	* ����˵����[in]pIn      ��Ҫ���б��������
	[in]uInLen  ����������ֽ���
	[out]strOut ����Ľ���base64����֮����ַ���
	* ����ֵ  ��true����ɹ�,falseʧ��
	* ��  ��  ��ChenLi
	* ��дʱ�䣺2009-02-17
	**********************************************************/
	bool static Encode(const unsigned char *pIn, unsigned long uInLen, string& strOut);

	/*********************************************************
	* ����˵�������������ݽ���base64����
	* ����˵����[in]pIn          ��Ҫ���б��������
	[in]uInLen      ����������ֽ���
	[out]pOut       ����Ľ���base64����֮����ַ���
	[out]uOutLen    ����Ľ���base64����֮����ַ�������
	* ����ֵ  ��true����ɹ�,falseʧ��
	* ��  ��  ��ChenLi
	* ��дʱ�䣺2009-02-17
	**********************************************************/
	bool static Encode(const unsigned char *pIn, unsigned long uInLen, unsigned char *pOut, unsigned long *uOutLen);


	/*********************************************************
	* ����˵�������������ݽ���base64����
	* ����˵����[in]strIn        ��Ҫ���н��������
	[out]pOut       �������֮��Ľ�������
	[out]uOutLen    ����Ľ���֮����ֽ�������
	* ����ֵ  ��true����ɹ�,falseʧ��
	* ��  ��  ��ChenLi
	* ��дʱ�䣺2009-02-17
	**********************************************************/
	bool static Decode(const unsigned char *pIn, unsigned long uInLen, unsigned char *pOut, unsigned long *uOutLen);
};

