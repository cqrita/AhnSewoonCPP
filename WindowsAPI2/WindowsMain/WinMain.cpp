//headers
#include "stdafx.h"
#include "Game.h"
//globals
HINSTANCE _hInstance;
HWND _hwnd;
POINT _mousePos={};


//forward declaration
LRESULT CALLBACK WndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void SetWindowSize(int x, int y, int width, int height);
int APIENTRY WinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance, _In_ char* lpszCmdParam, _In_ int nCmdShow)
{
	//HINSTANCE hInstance Instance handle
	//HINSTANCE hPrevInstance Previous Instance handle
	//char* lpszCmdParam cmd parameters
	//int nCmdShow show
	_hInstance = hInstance;
	//ATOM WINAPI RegisterClassA(_In_ CONST WNDCLASSA * lpWndClass);
	//WNDCLASS window struct
	WNDCLASS wndClass{};
	wndClass.cbClsExtra = 0; // class extra memory
	wndClass.cbWndExtra = 0; //window extra memory
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //background colour
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);  //cursor
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);  //icon
	wndClass.hInstance = _hInstance; // Instance Handle
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = WIN_NAME; // class name
	wndClass.lpszMenuName = NULL; //menu name
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	// camel case myName
	// paskal case MyName
	//snake case my_name
	//Hungurian lpszMyName
	
	//window register
	RegisterClass(&wndClass);

	//window create
	//CreateWindowA(lpClassName, lpWindowName, dwStyle, x, y,nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)
	_hwnd = CreateWindow(
		WIN_NAME //lpClassName
		, WIN_NAME //lpWindowName
		, WS_OVERLAPPEDWINDOW //dwStyle
		, WIN_START_X //x
		, WIN_START_Y //y
		, WIN_SIZE_WIDTH //nWidth
		, WIN_SIZE_HEIGHT //nHeight
		, NULL //hWndParent
		, NULL //hMenu
		, _hInstance //hInstance
		, NULL //lpParam
	);
	//show window
	SetWindowSize(0, 0, WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT);
	ShowWindow(_hwnd, nCmdShow);
	
	Game game;
	//double buffer
	game.Init();
	//message loop
	MSG message{ 0 };
	while (message.message != WM_QUIT)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
			game.Update();
			game.Render();
		}
	}
	return 0;
}

POINT goalPoint{ -1,-1 };

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//rec vector

	switch (message)
	{
	case WM_CREATE:
	{
		srand(time(NULL));
		break;
	}

	case WM_MOUSEMOVE:
	{
		_mousePos.x = GET_X_LPARAM(lParam);
		_mousePos.y = GET_Y_LPARAM(lParam);
		break;
	}
	case WM_LBUTTONDOWN:
	{
		goalPoint = _mousePos;
		break;
	}
	
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}
void SetWindowSize(int x, int y, int width, int height)
{
	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;
	AdjustWindowRect(&rc, WS_CAPTION| WS_SYSMENU, false);
	SetWindowPos(_hwnd, NULL, x, y, rc.right-rc.left, rc.bottom - rc.top, SWP_NOZORDER | SWP_NOMOVE);
}
