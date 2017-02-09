// XiaobaiEngine.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "XiaobaiEngine.h"
#include "JSVMInterface.h"
#include "OpenGl.h"
#include "HtmlCanvas.h"
#include <comdef.h>
#include <gdiplus.h>
#include "win32\ImageDecoderWin32.h"
#include "win32\SystemInterfaceWIN32.h"
#include "win32\HttpRequestWIN32.h"
#include "win32\AudioWIN32.h"

#pragma comment(lib,"gdiplus.lib")


#define MAX_LOADSTRING 100
HWND g_hWnd;

// ȫ�ֱ���: 
HINSTANCE hInst;								// ��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
TCHAR szWindowClass[MAX_LOADSTRING];			// ����������

// �˴���ģ���а����ĺ�����ǰ������: 
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);




int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO:  �ڴ˷��ô��롣
	

	









	MSG msg;
	HACCEL hAccelTable;

	// ��ʼ��ȫ���ַ���
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_XIAOBAIENGINE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��: 
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	ULONG_PTR m_gdiplusToken;
	Gdiplus::GdiplusStartupInput StartupInput;
	GdiplusStartup(&m_gdiplusToken, &StartupInput, NULL);


	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_XIAOBAIENGINE));


	WSADATA WsaData;
	WSAStartup(0x0101, &WsaData);




	RECT rc;
	GetClientRect(g_hWnd, &rc);
	COpenGl::GetInstance()->CreateFromHwnd(g_hWnd, rc.right, rc.bottom);

	OpenglContext::InitProgram();

	OpenglContext::SetViewPort(0, 0, rc.right, rc.bottom);




	COpenGl::GetInstance()->BeginRender();
	gl.Viewport(0, 0, OpenglContext::GetWidth(), OpenglContext::GetHeight());
	
	

	ImageDecoderWIN32 imgdec;
	JSVM::GetInstance()->SetImageDecoder(&imgdec);
	SystemInterfaceWIN32 sysint;
	JSVM::GetInstance()->SetSystemInterface(&sysint);
	HttpRequestWIN32 httpreq;
	JSVM::GetInstance()->SetHttpRequestInterface(&httpreq);
	FileIOInterface fileio;
	JSVM::GetInstance()->SetFileIOInterface(&fileio);
	AudioWIN32 aud;
	JSVM::GetInstance()->SetAudioInterface(&aud);
	SocketInterface sock;
	JSVM::GetInstance()->SetSocketInterface(&sock);

	JSVM::GetInstance()->initEnvironment();







//	JSVM::GetInstance()->m_bEnableWebgl = false;
// 
// 	JSVM::GetInstance()->SetRootPath("E:\\mfc\\XiaobaiEngine2\\Debug");
// 	JSVM::GetInstance()->runScript("websock.js");


// 	JSVM::GetInstance()->SetRootPath("E:\\mfc\\XiaobaiEngine2\\Debug");
// 	JSVM::GetInstance()->runScript("img.js");

//	JSVM::GetInstance()->LoadHtml("E:\\mfc\\XiaobaiEngine2\\Debug\\img.htm");

//  	JSVM::GetInstance()->runScript("gc.js");
// 	JSVM::GetInstance()->OnLoad();
	

// 	JSVM::GetInstance()->SetRootPath("D:\\tdownload\\cocos2d-js-v3.6\\cocos2d-js-v3.6\\samples\\js-tests");
// 	JSVM::GetInstance()->runScript("../../frameworks/cocos2d-html5/CCBoot.js");
// 	JSVM::GetInstance()->runScript("main.js");

// 	JSVM::GetInstance()->SetRootPath("D:\\egret\\HelloAirCraftJS\\HelloAirCraftJS");
// 	JSVM::GetInstance()->runScript("frameworks\\cocos2d-html5\\CCBoot.js");
// 	JSVM::GetInstance()->runScript("main.js");
// 	JSVM::GetInstance()->OnLoad();




//	JSVM::GetInstance()->LoadHtml("E:\\H5games\\HelloAirCraftJS\\HelloAirCraftJS\\index.html");


	//JSVM::GetInstance()->LoadHtml("E:\\H5games\\h5WebGLexamples\\ch02\\HelloPoint1.html");
//	JSVM::GetInstance()->LoadHtml("E:\\Desktop\\wjbp\\index.html");
//	JSVM::GetInstance()->LoadHtml("d:\\Desktop\\HelloAirCraftJS\\index.html");

//	JSVM::GetInstance()->LoadHtml("e:\\Desktop\\dfj\\index.html");
//	JSVM::GetInstance()->LoadHtml("D:\\tdownload\\΢��С��ϷԴ��80��\\΢��С��ϷԴ��80��\\games\\shenjingmao/index.html");
//	JSVM::GetInstance()->LoadHtml("D:/tdownload/΢��С��ϷԴ��80��/΢��С��ϷԴ��80��/games/kanshu/index.html");
//	JSVM::GetInstance()->LoadHtml("D:/tdownload/΢��С��ϷԴ��80��/΢��С��ϷԴ��80��/games/feidegenggao/index.html");
//	JSVM::GetInstance()->LoadHtml("D:/tdownload/΢��С��ϷԴ��80��/΢��С��ϷԴ��80��/games/gongfumao/index.html");
//	JSVM::GetInstance()->LoadHtml("D:/tdownload/΢��С��ϷԴ��80��/΢��С��ϷԴ��80��/games/qixi1/index.html");
//	JSVM::GetInstance()->LoadHtml("E:\\Desktop\\wdxnc\\wdxnc.htm");
//	JSVM::GetInstance()->LoadHtml("D:\\tdownload\\cocos2d-js-v3.6\\cocos2d-js-v3.6\\samples\\js-moonwarriors\\index.html");
//	JSVM::GetInstance()->LoadHtml("E:\\Desktop\\niren\\index.html");

//	JSVM::GetInstance()->LoadHtml("E:\\Desktop\\cqyx\\index.html");
//	JSVM::GetInstance()->LoadHtml("E:\\mfc\\XiaobaiEngine2\\Debug\\websocket.htm");
//	JSVM::GetInstance()->LoadHtml("C:\\Users\\Administrator\\Documents\\Tencent Files\\3055942331\\FileRecv\\index_ws����.html");
//	JSVM::GetInstance()->LoadHtml("E:\\Desktop\\zxyx\\zxyxlogin.zxyxh5.game12580.com\\game\\index.htm");
//	JSVM::GetInstance()->LoadHtml("http://zxyxlogin.zxyxh5.game12580.com/game/login_ouwan.php?openid=e8258222acc1bf2d&ts=1440583818&sign=db4451d252b4f3f7dd2f71b72aa66486&from=ouwan&chnid=0");
//	JSVM::GetInstance()->LoadHtml("http://localhost/game/index.htm");
//	JSVM::GetInstance()->LoadHtml("http://game.zorropk.com/web/wujibengpao/index.html");
	JSVM::GetInstance()->LoadHtml("http://192.168.1.158/index.html");
//	JSVM::GetInstance()->LoadHtml("http://game.5wanpk.com/zftest/fksc/index.html");
//	JSVM::GetInstance()->LoadHtml("http://game.5wanpk.com/zftest/x5hylxj/index.html");


//	RenderCanvasFBO();

	COpenGl::GetInstance()->EndRender();

	DWORD t = timeGetTime();
	std::vector<HtmlCanvas*>canvasList;
	char str[100];
	DWORD s_nFrames = 0;
	DWORD nTime = GetTickCount();
	while (true)
	{
		while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			if (msg.message == WM_QUIT)goto ends;
		}
// 		DWORD t2 = timeGetTime();
// 		if(t2-t<16)continue;//����60fps
// 		t = t2;

		JSVM::GetInstance()->MainLoop();
		gl.SetState(nullptr);
		JSVM::GetInstance()->RenderCanvasFBO();

		COpenGl::GetInstance()->EndRender();
		s_nFrames++;
		DWORD t = GetTickCount();
		if (t - nTime >= 1000)
		{
			sprintf_s(str,sizeof(str), "%gfps", s_nFrames*1000.0 / (t - nTime));
			s_nFrames = 0;
			nTime = t;
			SetWindowText(g_hWnd, str);
		}

	}
ends:

	JSVM::GetInstance()->disposeEnvironment();
	OpenglContext::Cleanup();
	gl.Cleanup();
	Gdiplus::GdiplusShutdown(m_gdiplusToken);
	WSACleanup();
	return (int) msg.wParam;
}



//
//  ����:  MyRegisterClass()
//
//  Ŀ��:  ע�ᴰ���ࡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_XIAOBAIENGINE));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_XIAOBAIENGINE);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   ����:  InitInstance(HINSTANCE, int)
//
//   Ŀ��:  ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{


   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

   g_hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
      CW_USEDEFAULT, 0, 640/*CW_USEDEFAULT*/,1000 /*0*/, NULL, NULL, hInstance, NULL);

   if (!g_hWnd)
   {
      return FALSE;
   }

   ShowWindow(g_hWnd, nCmdShow);
   UpdateWindow(g_hWnd);

   return TRUE;
}

//
//  ����:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// �����˵�ѡ��: 
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
		{
			do
			{
				CTRLMSG msg;
				msg.hCtrl = CTRLHANDLE::FromHandle((HWND)lParam);
				if (!msg.hCtrl)break;
				
				switch (wmEvent)
				{
				case EN_SETFOCUS:
					msg.msg = CTRLMSG::MT_FOCUS; break;
				case EN_KILLFOCUS:
					msg.msg = CTRLMSG::MT_BLUR; break;
				case EN_CHANGE:
					msg.msg = CTRLMSG::MT_INPUT; break;
				default:return DefWindowProc(hWnd, message, wParam, lParam);
				}
				msg.wParam = wParam;
				msg.lParam = lParam;

				JSVM::GetInstance()->GetSystemInterface()->OnCtrlMsg(msg);
				
			} while (false);
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		}
		break;
	case WM_SIZE:
	{
		int width = LOWORD(lParam);
		int height = HIWORD(lParam);
		OpenglContext::SetViewPort(0, 0, width, height);
		JSVM::GetInstance()->OnSize(width, height);
		break;
	}
	case WM_LBUTTONDOWN:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		JSVM::GetInstance()->OnTouchStart(0,x, y, x, y, wParam&MK_ALT, wParam&MK_SHIFT, wParam&MK_CONTROL);
		JSVM::GetInstance()->SendOnTouchEvent(JSVM::_TouchEvent::TT_START);
		break;
	}
	case WM_LBUTTONUP:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		JSVM::GetInstance()->OnTouchEnd(0, x, y, x, y, wParam&MK_ALT, wParam&MK_SHIFT, wParam&MK_CONTROL);
		JSVM::GetInstance()->SendOnTouchEvent(JSVM::_TouchEvent::TT_END);
		break;
	}
	case WM_MOUSEMOVE:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		JSVM::GetInstance()->OnTouchMove(0, x, y, x, y, wParam&MK_ALT, wParam&MK_SHIFT, wParam&MK_CONTROL);
		JSVM::GetInstance()->SendOnTouchEvent(JSVM::_TouchEvent::TT_MOVE);
	}
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO:  �ڴ���������ͼ����...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// �����ڡ������Ϣ�������
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
