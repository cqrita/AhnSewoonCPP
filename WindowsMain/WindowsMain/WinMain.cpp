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
}

return 0;
}


//mouse click
// rect create
// rect vector push
// vector draw


RECT mainRect;
RECT subRect1;
RECT subRect2;
RECT* inRect;
RECT* outRect;

bool state;
POINT goalPoint{ -1,-1 };

// rect 1,2,3
// move function
// mouse ,keyboard
// collision function
// in,out
// 
// 
//
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
			1000 / 60,                 // 10-second interval 
			(TIMERPROC)NULL);     // no timer callback 

		mainRect = { 200,200,250,250 };
		subRect1 = { 100,100,300,300 };
		subRect2 = { 400,400,600,600 };
		inRect = &subRect1;
		outRect = &subRect2;
		state = false;
		break;
	}
	case WM_TIMER:
	{
		switch (wParam)
		{
		case 0:

			int gap = 0;
			RECT interRect1;
			RECT interRect2;
			RECT zeroRect = { 0,0,0,0 };
			
			IntersectRect(&interRect1, inRect, outRect);
			IntersectRect(&interRect2, &mainRect, &interRect1);
			
			if (false == (goalPoint.x == -1 && goalPoint.y == -1))
			{
				if (goalPoint.x < (mainRect.left+mainRect.right)/2)
				{
					gap = (mainRect.left + mainRect.right) / 2 - goalPoint.x;
					int movePoint = min(gap, 5);
					OffsetRect(&mainRect, -movePoint,0);
					int* arr = Rect::InsideRect(mainRect, *inRect);
					if (arr[0] == 1)
					{
						OffsetRect(inRect, -movePoint, 0);
						if (!EqualRect(&interRect1, &zeroRect)&& !EqualRect(&interRect2, &zeroRect)&&state==true)
						{
							int offset1 = (outRect->left + outRect->right) / 2;
							int offset2 = (mainRect.right - mainRect.left) / 2;
							int offset3 = (outRect->top + outRect->bottom) / 2;
							int offset4 = (mainRect.bottom - mainRect.top) / 2;

							SetRect(&mainRect, offset1 - offset2, offset3 - offset4, offset1 + offset2, offset3 + offset4);
							RECT* temp = inRect;
							inRect = outRect;
							outRect = temp;
						}
					}
					
				}
				if (goalPoint.x > (mainRect.left + mainRect.right) / 2)
				{
					gap = goalPoint.x - (mainRect.left + mainRect.right) / 2;
					int movePoint = min(gap, 5);
					OffsetRect(&mainRect, movePoint, 0);
					int* arr = Rect::InsideRect(mainRect, *inRect);
					if (arr[1] == 1 )
					{
						OffsetRect(inRect, movePoint, 0);
						if (!EqualRect(&interRect1, &zeroRect) && !EqualRect(&interRect2, &zeroRect) && state == true)
						{
							int offset1 = (outRect->left + outRect->right) / 2;
							int offset2 = (mainRect.right - mainRect.left) / 2;
							int offset3 = (outRect->top + outRect->bottom) / 2;
							int offset4 = (mainRect.bottom - mainRect.top) / 2;

							SetRect(&mainRect, offset1 - offset2, offset3 - offset4, offset1 + offset2, offset3 + offset4);
							RECT* temp = inRect;
							inRect = outRect;
							outRect = temp;
						}
					}
				}

				if (goalPoint.y < (mainRect.top + mainRect.bottom) / 2)
				{
					gap = (mainRect.top + mainRect.bottom) / 2 - goalPoint.y;
					int movePoint = min(gap, 5);
					OffsetRect(&mainRect,0 , -movePoint);
					int* arr = Rect::InsideRect(mainRect, *inRect);
					if (arr[2] == 1 )
					{
						OffsetRect(inRect, 0, -movePoint);
						if (!EqualRect(&interRect1, &zeroRect) && !EqualRect(&interRect2, &zeroRect) && state == true)
						{
							int offset1 = (outRect->left + outRect->right) / 2;
							int offset2 = (mainRect.right - mainRect.left) / 2;
							int offset3 = (outRect->top + outRect->bottom) / 2;
							int offset4 = (mainRect.bottom - mainRect.top) / 2;

							SetRect(&mainRect, offset1 - offset2, offset3 - offset4, offset1 + offset2, offset3 + offset4);
							RECT* temp = inRect;
							inRect = outRect;
							outRect = temp;
						}
					}
				}
				if (goalPoint.y > (mainRect.top + mainRect.bottom) / 2)
				{
					gap = goalPoint.y - (mainRect.top + mainRect.bottom) / 2;
					int movePoint = min(gap, 5);
					OffsetRect(&mainRect,0 , movePoint);
					int* arr = Rect::InsideRect(mainRect, *inRect);
					if (arr[3] == 1 )
					{
						OffsetRect(inRect, 0, movePoint);
						if (!EqualRect(&interRect1, &zeroRect) && !EqualRect(&interRect2, &zeroRect) && state == true)
						{
							int offset1 = (outRect->left + outRect->right) / 2;
							int offset2 = (mainRect.right - mainRect.left) / 2;
							int offset3 = (outRect->top + outRect->bottom) / 2;
							int offset4 = (mainRect.bottom - mainRect.top) / 2;

							SetRect(&mainRect, offset1 - offset2, offset3 - offset4, offset1 + offset2, offset3 + offset4);
							RECT* temp = inRect;
							inRect = outRect;
							outRect = temp;
						}
					}
				}
				
			}
			if (gap == 0)
			{
				goalPoint = { -1,-1 };
			}

			RECT rc;
			GetClientRect(_hwnd, &rc);
			InvalidateRect(_hwnd, &rc, true);
			

		}
		break;
	}
	case WM_KEYDOWN:
	{
		RECT interRect1;
		RECT interRect2;
		RECT zeroRect = { 0,0,0,0 };

		IntersectRect(&interRect1, inRect, outRect);
		IntersectRect(&interRect2, &mainRect, &interRect1);
		switch (wParam)
		{
		case VK_UP:
		{
			OffsetRect(&mainRect, 0, -5);
			int* arr = Rect::InsideRect(mainRect, *inRect);
			if (arr[2] == 1)
			{
				OffsetRect(inRect, 0, -5);
				if (!EqualRect(&interRect1, &zeroRect) && !EqualRect(&interRect2, &zeroRect) && state == true)
				{
					int offset1 = (outRect->left + outRect->right) / 2;
					int offset2 = (mainRect.right - mainRect.left) / 2;
					int offset3 = (outRect->top + outRect->bottom) / 2;
					int offset4 = (mainRect.bottom - mainRect.top) / 2;

					SetRect(&mainRect, offset1 - offset2, offset3 - offset4, offset1 + offset2, offset3 + offset4);
					RECT* temp = inRect;
					inRect = outRect;
					outRect = temp;
				}
			}
			break;
		}
			
		case VK_LEFT:
		{
			OffsetRect(&mainRect, -5, 0);
			int* arr = Rect::InsideRect(mainRect, *inRect);
			if (arr[0] == 1)
			{
				OffsetRect(inRect, -5, 0);
				if (!EqualRect(&interRect1, &zeroRect) && !EqualRect(&interRect2, &zeroRect) && state == true)
				{
					int offset1 = (outRect->left + outRect->right) / 2;
					int offset2 = (mainRect.right - mainRect.left) / 2;
					int offset3 = (outRect->top + outRect->bottom) / 2;
					int offset4 = (mainRect.bottom - mainRect.top) / 2;

					SetRect(&mainRect, offset1 - offset2, offset3 - offset4, offset1 + offset2, offset3 + offset4);
					RECT* temp = inRect;
					inRect = outRect;
					outRect = temp;
				}
			}
			break;
		}
			
		case VK_RIGHT:
		{
			OffsetRect(&mainRect, 5, 0);
			int* arr = Rect::InsideRect(mainRect, *inRect);
			if (arr[1] == 1)
			{
				OffsetRect(inRect, 5, 0);
				if (!EqualRect(&interRect1, &zeroRect) && !EqualRect(&interRect2, &zeroRect) && state == true)
				{
					int offset1 = (outRect->left + outRect->right) / 2;
					int offset2 = (mainRect.right - mainRect.left) / 2;
					int offset3 = (outRect->top + outRect->bottom) / 2;
					int offset4 = (mainRect.bottom - mainRect.top) / 2;

					SetRect(&mainRect, offset1 - offset2, offset3 - offset4, offset1 + offset2, offset3 + offset4);
					RECT* temp = inRect;
					inRect = outRect;
					outRect = temp;
				}
			}
			break;
		}
			
		case VK_DOWN:
		{
			OffsetRect(&mainRect, 0, 5);
			int* arr = Rect::InsideRect(mainRect, *inRect);
			if (arr[3] == 1)
			{
				OffsetRect(inRect, 0, 5);
				if (!EqualRect(&interRect1, &zeroRect) && !EqualRect(&interRect2, &zeroRect) && state == true)
				{
					int offset1 = (outRect->left + outRect->right) / 2;
					int offset2 = (mainRect.right - mainRect.left) / 2;
					int offset3 = (outRect->top + outRect->bottom) / 2;
					int offset4 = (mainRect.bottom - mainRect.top) / 2;

					SetRect(&mainRect, offset1 - offset2, offset3 - offset4, offset1 + offset2, offset3 + offset4);
					RECT* temp = inRect;
					inRect = outRect;
					outRect = temp;
				}
			}
			break;
		}
		case 0x31:
			state = !state;
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
		Draw::Rect(hdc, subRect1);
		if (state == true)
		{
			Draw::Rect(hdc, subRect2);
		}
		Draw::Rect(hdc, mainRect);
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
