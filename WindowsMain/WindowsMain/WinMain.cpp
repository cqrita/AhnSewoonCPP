//headers
#include "stdafx.h"
//globals
HINSTANCE _hInstance;
HWND _hwnd;
POINT _mousePos={};
int num = 1;

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
		, WIN_NAME, //lpWindowName
		WS_OVERLAPPEDWINDOW //dwStyle
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
		else
		{
			SendMessage(_hwnd, WM_APP, 0, 0);
		}
	}

	return 0;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	vector<RECT> recs;
	for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			RECT rc;
			rc.left = 50 * j;
			rc.right = rc.left + 50;
			rc.top = 50 * i;
			rc.bottom = rc.top + 50;
			recs.push_back(rc);
		}
	}
	switch (message)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc= BeginPaint(hWnd,&ps);
		// A => ascii code
		// W => wide character

		for (int j = 0; j < recs.size(); j++)
		{
			RECT rc = recs[j];
			Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
			TextOut(hdc, rc.left + 20, rc.top + 20, to_string(j + 1).c_str(), 1);
		}

		for (int j = 1 ; j < 10; j++)
		{
			char charArr[250];
			sprintf_s(charArr,"%d * %d = %d", num,j, num *j);
			string str(charArr);
			TextOut(hdc, _mousePos.x, _mousePos.y+(j-1)*20, str.c_str(), str.size());
		}
		

		EndPaint(hWnd, &ps);
		break;
	}
	case WM_MOUSEMOVE:
	{
		_mousePos.x = GET_X_LPARAM(lParam);
		_mousePos.y = GET_Y_LPARAM(lParam);

		if (MK_RBUTTON == wParam)
		{
			cout << "X : " << _mousePos.x << endl;
			cout << "Y : " << _mousePos.y << endl;

		}
		RECT rc;
		GetClientRect(_hwnd, &rc);
		InvalidateRect(_hwnd, &rc, true);


		break;
	}
	case WM_LBUTTONDOWN:
	{
		for (int j = 0; j < recs.size(); j++)
		{
			RECT rc = recs[j];
			if (PtInRect(&rc, _mousePos))
			{
				num = j+1;
				cout << num << endl;
			}
		}
		RECT rc;
		GetClientRect(_hwnd, &rc);
		InvalidateRect(_hwnd, &rc, true);

		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}
