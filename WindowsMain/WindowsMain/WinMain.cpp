//headers
#include <Windows.h>

//globals
HINSTANCE _hInstance;
HWND _hwnd;
char _title[250] = "Happy Windows API";

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
	wndClass.lpszClassName = _title; // class name
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
		_title //lpClassName
		,_title, //lpWindowName
		WS_OVERLAPPEDWINDOW //dwStyle
		,0 //x
		,0 //y
		,500 //nWidth
		,500 //nHeight
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
		if (PeekMessage(&message, _hwnd, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}
	return 0;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc= BeginPaint(hWnd,&ps);
		EndPaint(hWnd, &ps);
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}
