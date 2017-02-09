#pragma once
#include "OpenglFBO.h"
#include "ImageDecoderInterface.h"
//ÿ��canvas������Ⱦ���Լ������������У�����canvasִ����Ϻ��ͳһ������������Ⱦ����
class OpenglContext
{
public:
	struct VIEWPORT
	{
		int x = 0;
		int y = 0;
		int width = 0;
		int height = 0;
	};
	static VIEWPORT s_rcViewPort;
// 
// 
// 	static float WindowPointToGlPointX(float x)
// 	{
// 		return 2.0f*x / s_rcViewPort.width - 1;
// 	}
// 	static float WindowPointToGlPointY(float y)
// 	{
// 		return -2.0f*y / s_rcViewPort.height + 1;
// 	}
// 	static float GlPointToWindowPointX(float x)
// 	{
// 		return (x + 1)*s_rcViewPort.width*0.5f;
// 	}
// 	static float GlPointToWindowPointY(float y)
// 	{
// 		return s_rcViewPort.height - (y + 1)*s_rcViewPort.height*0.5f;
// 	}

	class SingleColorProgram//��ɫ���shader
	{
	public:
		GLuint m_Program = 0;
		bool Init();
		void Uninit();
		operator GLuint()
		{
			return m_Program;
		}
		void SetColor(float r, float g, float b, float a);
		void SetVertexPosition(GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* ptr);
	};
	class LinearGradientProgram//���Խ������ɫ��shader
	{
	public:
		GLuint m_Program = 0;
		bool Init();
		void Uninit();
		operator GLuint()
		{
			return m_Program;
		}
		void SetTextureUnit(GLint i);//����ɫ�Ŀ��1��������
		void SetPosition(DXPOINT A, DXPOINT B, float viewportWidth, float viewportHeight);//�������㡢�յ�����
		void SetAlpha(float fAlpha);
		void SetVertexPosition(GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* ptr);
	};


	class TextureProgram//��ͨ��ʹ��һ�������shader
	{
	public:
		GLuint m_Program = 0;
		bool Init();
		void Uninit();
		operator GLuint();
		void SetVertexPosition(GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* ptr);
		void SetTexturePosition(GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* ptr);
		void SetTextureUnit(GLint i);
		void SetAlpha(float fAlpha);
		void SetMatrix(MATRIX* mat);
	};
	

// 	class FillColorTextProgram//ʹ�����ɫ��ʾ����ͼƬ��shader
// 	{
// 	public:
// 		GLuint m_Program = 0;
// 		bool Init();
// 		void Uninit();
// 		operator GLuint()
// 		{
// 			return m_Program;
// 		}
// 		void SetVertexPosition(GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* ptr);
// 		void SetTexturePosition(GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* ptr);
// 		void SetTextureUnit(GLint i);
// 		void SetMatrix(MATRIX* mat);
// 		enum FILLSTYLE
// 		{
// 			FS_COLOR,//��͸��������䵥ɫ
// 		};
// 		void SetFillColorStyle(FILLSTYLE style)
// 		{
// 
// 		}
// 
// 	};

	static SingleColorProgram s_SingleColorProgram;//��ɫ���
	static TextureProgram s_TextureProgram;//�������
	static LinearGradientProgram s_LinearGradientProgram;//���Խ������
	static bool InitProgram();
	static bool Cleanup();
	static void SetViewPort(int x, int y, int width, int height);
	static int GetX();
	static int GetY();
	static int GetWidth();
	static int GetHeight();
//	static DXPOINT WindowPointToGlPoint(const DXPOINT &vPos);
	static GLuint CreateGlTexID(const ImageData&imgData);
};