#include <Windows.h>
LRESULT CALLBACK WndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
int APIENTRY WinMain(HINSTANCE hinstance, HINSTANCE prevhInstance, char* lpszcharparam, int nCmdShow)
{
	const char* title = "window";
	WNDCLASS wndclass{};
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hInstance = hinstance;
	wndclass.lpszClassName = title;
	wndclass.lpszMenuName = NULL;
	wndclass.style = CS_VREDRAW | CS_HREDRAW;
	wndclass.lpfnWndProc = WndProc;
	RegisterClass(&wndclass);
	HWND hwnd = CreateWindow(title, title, WS_OVERLAPPEDWINDOW, 0, 0, 500, 500, NULL, NULL, hinstance, NULL);
	ShowWindow(hwnd, nCmdShow);
	MSG message{};
	while (GetMessage(&message, hwnd, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
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
		HDC hdc= BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd,message, wParam, lParam);
	}
}
