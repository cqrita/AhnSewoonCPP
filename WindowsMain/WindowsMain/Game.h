#pragma once
class Game
{
private:

public:
	void Init();
	void Update();
	void Render();
	void Release();


private:
	HDC _hdc;
	HDC _hdcBack;
	HBITMAP _bmpBack;

};

