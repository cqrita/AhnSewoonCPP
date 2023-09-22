#include "stdafx.h"
#include "Game.h"


void Game::Init()
{
	_hdc = GetDC(_hwnd);
	_hdcBack = CreateCompatibleDC(_hdc);
	_bmpBack = CreateCompatibleBitmap(_hdc, WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT);
	HBITMAP preBmp = (HBITMAP)SelectObject(_hdcBack, _bmpBack);
	DeleteBitmap(preBmp);

	GET_SINGLE(TimeManager)->Init();
	GET_SINGLE(SceneManager)->Init();
	GET_SINGLE(KeyManager)->Init();
}
void Game::Update()
{
	GET_SINGLE(TimeManager)->Update();
	GET_SINGLE(SceneManager)->Update();

}
void Game::Render()
{
	GET_SINGLE(SceneManager)->Render(_hdcBack);
	
	unsigned int fps= GET_SINGLE(TimeManager)->GetFps();
	float deltaTime= GET_SINGLE(TimeManager)->GetDeltaTime();
	char str[250];
	sprintf_s(str, "FPS({%d}), DT({%f})", fps, deltaTime);
	TextOut(_hdcBack, 0, 0, str, strlen(str));

	BitBlt(_hdc, 0, 0, WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT, _hdcBack, 0, 0, SRCCOPY);
	PatBlt(_hdcBack, 0, 0, WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT, WHITENESS);
}
void Game::Release()
{
	GET_SINGLE(TimeManager)->Release();
	GET_SINGLE(SceneManager)->Release();
	GET_SINGLE(KeyManager)->Release();

}
