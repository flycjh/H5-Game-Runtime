#include "stdafx.h"
#include "OpenGl.h"
#include <string>
#include <algorithm>
#include "OpenglContext.h"


int Init(ESContext *esContext)
{
	UserData *userData = (UserData*)esContext->userData;
	const char vShaderStr[] =
		"attribute vec4 a_position;   \n"
		"attribute vec2 a_texCoord;   \n"
		"varying vec2 v_texCoord;     \n"
		"void main()                  \n"
		"{                            \n"
		"   gl_Position = a_position; \n"
		"   v_texCoord = a_texCoord;  \n"
		"}                            \n";

	const char fShaderStr[] =
		"precision mediump float;                            \n"
		"varying vec2 v_texCoord;                            \n"
		"uniform sampler2D s_texture;                        \n"
		"void main()                                         \n"
		"{                                                   \n"
		"  gl_FragColor = texture2D( s_texture, v_texCoord );\n"
		"}                                                   \n";

	// Load the shaders and get a linked program object
	userData->programObject = esLoadProgram(vShaderStr, fShaderStr);

	// Get the attribute locations
	userData->positionLoc = glGetAttribLocation(userData->programObject, "a_position");
	userData->texCoordLoc = glGetAttribLocation(userData->programObject, "a_texCoord");

	// Get the sampler location
	userData->samplerLoc = glGetUniformLocation(userData->programObject, "s_texture");

	// Load the texture
//	userData->textureId = CreateSimpleTexture2D();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepthf(0);

	return TRUE;
}










COpenGl::COpenGl()
{

	m_nWidth = 960;
	m_nHeight = 640;

}


COpenGl::~COpenGl()
{

}


EGLBoolean COpenGl::CreateEGLContext(EGLNativeWindowType hWnd, EGLDisplay* eglDisplay,
	EGLContext* eglContext, EGLSurface* eglSurface,
	EGLint attribList[])
{
	EGLint numConfigs;
	EGLint majorVersion;
	EGLint minorVersion;
	EGLDisplay display;
	EGLContext context;
	EGLSurface surface;
	EGLConfig config;
	EGLint contextAttribs[] = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE, EGL_NONE };

	// Get Display
	HDC dc = GetDC(hWnd);
	display = eglGetDisplay(dc);
	ReleaseDC(hWnd, dc);
	if (display == EGL_NO_DISPLAY)
	{
		return EGL_FALSE;
	}

	// Initialize EGL
	if (!eglInitialize(display, &majorVersion, &minorVersion))
	{
		return EGL_FALSE;
	}

	// Get configs
	if (!eglGetConfigs(display, NULL, 0, &numConfigs))
	{
		return EGL_FALSE;
	}
	
	// Choose config
	if (!eglChooseConfig(display, attribList, &config, 1, &numConfigs))
	{
		return EGL_FALSE;
	}

	// Create a surface
	surface = eglCreateWindowSurface(display, config, (EGLNativeWindowType)hWnd, NULL);
	if (surface == EGL_NO_SURFACE)
	{
		return EGL_FALSE;
	}

	// Create a GL context
	context = eglCreateContext(display, config, EGL_NO_CONTEXT, contextAttribs);
	if (context == EGL_NO_CONTEXT)
	{
		return EGL_FALSE;
	}

	// Make the context current
	if (!eglMakeCurrent(display, surface, surface, context))
	{
		return EGL_FALSE;
	}

	*eglDisplay = display;
	*eglSurface = surface;
	*eglContext = context;
	return EGL_TRUE;
}
bool COpenGl::CreateFromHwnd(HWND hwnd,int width,int height)
{

	GLuint flags = ES_WINDOW_RGB;
	esInitContext(&esContext);
	esContext.userData = &userData;

	EGLint attribList[] =
	{
		EGL_RED_SIZE, 8,
		EGL_GREEN_SIZE, 8,
		EGL_BLUE_SIZE, 8,
		EGL_ALPHA_SIZE, (flags & ES_WINDOW_ALPHA) ? 8 : EGL_DONT_CARE,
		EGL_DEPTH_SIZE, (flags & ES_WINDOW_DEPTH) ? 8 : EGL_DONT_CARE,
		EGL_STENCIL_SIZE, (flags & ES_WINDOW_STENCIL) ? 8 : EGL_DONT_CARE,
		EGL_SAMPLE_BUFFERS, (flags & ES_WINDOW_MULTISAMPLE) ? 1 : 0,
		EGL_NONE
	};


	m_nWidth=esContext.width = width;
	m_nHeight=esContext.height = height;
	esContext.hWnd = hwnd;

	if (!CreateEGLContext(esContext.hWnd,
		&esContext.eglDisplay,
		&esContext.eglContext,
		&esContext.eglSurface,
		attribList))
	{
		return GL_FALSE;
	}


	Init(&esContext);


	return GL_TRUE;
}


bool COpenGl::SetupPixFormat(HDC hdc) 
{
	static PIXELFORMATDESCRIPTOR pfd = //�������ظ�ʽ
	{
		sizeof(PIXELFORMATDESCRIPTOR), // ������ʽ�������Ĵ�С
		1,         // �汾��
		PFD_DRAW_TO_WINDOW |    // ��ʽ֧�ִ���
		PFD_SUPPORT_OPENGL |    // ��ʽ����֧��OpenGL
		PFD_DOUBLEBUFFER,     // ����֧��˫����
		PFD_TYPE_RGBA,      // ���� RGBA ��ʽ
		24,         // 24λɫ����ȣ���1.67ǧ������ɫ
		0, 0, 0, 0, 0, 0,     // ���Ե�ɫ��λ
		0,         // ��Alpha����
		0,         // ����Shift Bit
		0,         // ���ۼӻ���
		0, 0, 0, 0,       // ���Ծۼ�λ
		32,         // 32λ Z-���� (��Ȼ���)
		0,         // ���ɰ建��
		0,         // �޸�������
		PFD_MAIN_PLANE,      // ����ͼ��
		0,         // Reserved
		0, 0, 0        // ���Բ�����
	};

	int nIndex = ChoosePixelFormat(hdc, &pfd); //ѡ��ոն�������ظ�ʽ
	if (nIndex == 0) return FALSE;

	return SetPixelFormat(hdc, nIndex, &pfd)==TRUE;   //�������ظ�ʽ
}
bool COpenGl::BeginRender()
{
	
	if (!eglMakeCurrent(esContext.eglDisplay, esContext.eglSurface, esContext.eglSurface, esContext.eglContext))
	{
		return EGL_FALSE;
	}
	assert(!glGetError());


	glDisable(GL_DEPTH_TEST);    // �ر���Ȳ���
	assert(!glGetError());
	glEnable(GL_BLEND);
	assert(!glGetError());
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	assert(!glGetError());
// 	glEnable(GL_ALPHA_BITS);
// 	assert(!glGetError());


//	glViewport(0, 0, OpenglContext::GetWidth(), OpenglContext::GetHeight());
	glClearColor(0,0,0,0);
	glClearDepthf(0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

 	return true;
}

void COpenGl::EndRender()
{
	eglSwapBuffers(esContext.eglDisplay, esContext.eglSurface);
	
}

bool COpenGl::IsInit()
{
	return this->esContext.hWnd != 0;

}

void COpenGl::SetSize(int width, int height)
{
	
	if (!eglMakeCurrent(esContext.eglDisplay, esContext.eglSurface, esContext.eglSurface, esContext.eglContext))
	{
		return ;
	}
	m_nWidth = width;
	m_nHeight = height;
 //	glViewport(0,0, width, height);

}
// 
// float COpenGl::WindowPointToGlPointX(float x)
// {
// 	return 2.0f*x / m_nWidth - 1;
// }
// float COpenGl::WindowPointToGlPointY(float y)
// {
// 	return -2.0f*y / m_nHeight + 1;
// }
// float COpenGl::GlPointToWindowPointX(float x)
// {
// 	return (x + 1)*m_nWidth*0.5f;
// }
// float COpenGl::GlPointToWindowPointY(float y)
// {
// 	return m_nHeight - (y + 1)*m_nHeight*0.5f;
// }

GLuint COpenGl::LoadProgram(const char *vertShaderSrc, const char *fragShaderSrc)
{
	return esLoadProgram(vertShaderSrc, fragShaderSrc);
}

void COpenGl::DeleteProgram(GLuint program)
{
	glDeleteProgram(program);
}

COpenGl COpenGl::_instance;

