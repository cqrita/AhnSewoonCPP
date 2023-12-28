#pragma once
class Game
{
private:

public:
	void Init();
	void Update();
	void Render();
	void Release();

//gdiplus
private:
	ULONG_PTR _gdiPlusToken;
//double buffering
private:
	HDC _hdc;
	HDC _hdcBack;
	HBITMAP _bmpBack;

};

