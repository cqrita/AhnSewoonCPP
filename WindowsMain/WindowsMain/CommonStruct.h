#pragma once

struct CenterRect
{
	float x, y, width, height;
	RECT ToRect();
	class Gdiplus::Rect ToGdiRect();
	static CenterRect FromRect(RECT rect);
};