#pragma once
#include "Macros.h"
#include <string>

//ͼ���ļ��������ӿڣ����ò�ͬƽ̨��Ӧ�Ľ��뷽ʽ�����շ���RGBA32λ����(�涨ԭ�������Ͻǣ�
class ImageData
{
public:
	int nWidth;
	int nHeight;
	int nYOffset = 0;//�������֣����textbaseline!=top����nYOffset������Ϊ-baselineheight
	uint32_t*pData=nullptr;
	~ImageData()
	{
		Cleanup();
	}
	void Cleanup()
	{
		delete[]pData;
		pData = nullptr;
		nYOffset = 0;
	}
	bool IsInit()
	{
		return pData != nullptr;
	}
	void SwapY(uint32_t*pOutData) const
	{
		for (int y = 0; y <nHeight; y++)
		{
			for (int x = 0; x < nWidth; x++)
			{
				pOutData[(nHeight - y - 1)*nWidth + x] = pData[y*nWidth + x];
			}
		}
	}
};

class FontInfo
{
public:
	std::string szFontName;
	int nFontSize=0;
};

enum _TEXTBASELINE
{//http://www.w3school.com.cn/tags/canvas_textbaseline.asp
	TB_ALPHABETIC,
	TB_TOP,
	TB_BOTTOM,
	TB_MIDDLE,
	TB_HANGING,
	TB_ideographic,
};
enum _TEXTALIGN
{//http://www.w3school.com.cn/tags/canvas_textalign.asp
	AL_LEFT,
	AL_RIGHT,
	AL_CENTER,
};


class ImageDecoderInterface
{
public:
	virtual ~ImageDecoderInterface(){};
	virtual bool DecodeFile(const char*szFilePath, ImageData&Data);//�����ļ���Data
	virtual bool DecodeData(void*pData, int nDataLen, ImageData&Data) = 0;//�����ļ�����Data
//	virtual bool DecodeFromByteArray(unsigned char* pBuf, unsigned long nlen, ImageData& Data) = 0;
	virtual bool CreateStringImage(const char*szText, const FontInfo&Fontinfo, ImageData&Data, bool bMeasureOnly, uint32_t nColor, _TEXTBASELINE baseline = TB_TOP) = 0;//�ַ���תλͼ��ֻ���ɺڰ�λͼ�����ɫ��Ҫ��������bMeasureOnly���Ƿ�ֻ���λͼ��С��������λͼ
};

