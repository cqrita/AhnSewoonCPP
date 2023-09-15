//headers
#include "stdafx.h"
//globals
HINSTANCE _hInstance;
HWND _hwnd;
POINT _mousePos={};

//forward declaration
LRESULT CALLBACK WndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

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
		,NULL //hWndParent
		,NULL //hMenu
		,_hInstance //hInstance
		,NULL //lpParam
	);
	//show window
	ShowWindow(_hwnd,nCmdShow);


	//message loop
	MSG message {0};
	while (message.message!=WM_QUIT)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}

	return 0;
}


//mouse click
// rect create
// rect vector push
// vector draw


RECT mainRect;
RECT subRect;

POINT goalPoint{ -1,-1 };
// mouse click set goal point to mouse click
//if goal point!=-1,-1
//move rect to goal point
//goal point <rec x
//goal point >rec
//goal point <rec y
//goal point >rec

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//rec vector
	
	switch (message)
	{
	case WM_CREATE:
	{
		srand(time(NULL));

		SetTimer(hWnd,             // handle to main window 
			0,            // timer identifier 
			1000/60,                 // 10-second interval 
			(TIMERPROC)NULL);     // no timer callback 

		mainRect = { 100,100,150,150 };
		subRect = { 200,200,250,250 };

		break;
	}
	case WM_TIMER:
	{
		switch (wParam)
		{
		case 0:
			// process the 10-second timer 


			
			if (false == (goalPoint.x == -1 && goalPoint.y == -1))
			{

			}
			

			RECT rc;
			GetClientRect(_hwnd, &rc);
			InvalidateRect(_hwnd, &rc, true);
			

		}
		break;
	}
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_UP:
			break;
		case VK_LEFT:

			break;
		case VK_RIGHT:
			break;
		case VK_DOWN:
			break;
		default:
			break;
		}

		break;
	}


	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc= BeginPaint(hWnd,&ps);
		// A => ascii code
		// W => wide character

		//rec draw
		Draw::Rect(hdc, mainRect);
		Draw::Rect(hdc, subRect);
		EndPaint(hWnd, &ps);
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
	case WM_RBUTTONDOWN:
	{
		break;
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}
