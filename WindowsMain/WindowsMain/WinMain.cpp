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
		, NULL //hWndParent
		, NULL //hMenu
		, _hInstance //hInstance
		, NULL //lpParam
	);
	//show window
	ShowWindow(_hwnd, nCmdShow);
	
	
	//message loop
	MSG message{ 0 };
	while (message.message != WM_QUIT)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		SendMessage(_hwnd, WM_APP, 0, 0);
	}

	return 0;
}

POINT goalPoint{ -1,-1 };

//flickering
vector<RECT> rects;
int num;
int timeSum;
int duration;
int score;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//rec vector

	switch (message)
	{
	case WM_CREATE:
	{
		srand(time(NULL));


		for (int i = 0; i <3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				rects.push_back(RECT{ 100 + (j * 100),100 + (i * 100),200 + (j * 100),200 + (i * 100) });
			}
		}
		timeSum = 0;
		duration = 500;
		score = 0;
		break;
	}
	case WM_APP:
	{		
		timeSum++;
		if (timeSum > duration)
		{
			timeSum = 0;
			num = rand() % 9;
		}
		RECT rc;
		GetClientRect(_hwnd, &rc);
		InvalidateRect(_hwnd, &rc, true);
		break;
	}


	case WM_KEYDOWN:
	{
		switch (num)
		{
		case 0:
		{
			if (KEYMANAGER->GetKeyDown(VK_NUMPAD7))
			{
				score++;
			}
		}
		case 1:
		{
			if (KEYMANAGER->GetKeyDown(VK_NUMPAD8))
			{
				score++;
			}
		}

		case 2:
		{
			if (KEYMANAGER->GetKeyDown(VK_NUMPAD9))
			{
				score++;
			}
		}

		case 3:
		{
			if (KEYMANAGER->GetKeyDown(VK_NUMPAD4))
			{
				score++;
			}
		}

		case 4:
		{
			if (KEYMANAGER->GetKeyDown(VK_NUMPAD5))
			{
				score++;
			}
		}

		case 5:
		{
			if (KEYMANAGER->GetKeyDown(VK_NUMPAD6))
			{
				score++;
			}
		}

		case 6:
		{
			if (KEYMANAGER->GetKeyDown(VK_NUMPAD1))
			{
				score++;
			}
		}

		case 7:
		{
			if (KEYMANAGER->GetKeyDown(VK_NUMPAD2))
			{
				score++;
			}
		}

		case 8:
		{
			if (KEYMANAGER->GetKeyDown(VK_NUMPAD3))
			{
				score++;
			}
		}

		default:
			break;
		}
		cout << score << endl;
		break;
	}


	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc= BeginPaint(hWnd,&ps);
		for (int i = 0; i < 9; i++)
		{
			Draw::Rect(hdc, rects[i]);
			if (num == i)
			{
				Draw::Circle(hdc, rects[i]);
			}
		}
		RECT rt = { 400, 400, 700, 700 };
		string str = "score: " + to_string(score);
		DrawText(hdc, str.c_str(), -1, &rt, DT_CENTER | DT_WORDBREAK);


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
	case WM_ERASEBKGND:
		return 1;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}
