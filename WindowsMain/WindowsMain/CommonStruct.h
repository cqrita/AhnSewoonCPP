#pragma once

struct CenterRect
{
	float x, y, width, height;

	RECT ToRect();
	Gdiplus::Rect ToGdiRect();
	Vector2 Position();

	static CenterRect FromRect(RECT rect);
};


struct CenterCircle
{
	Vector2 center;
	float radius;

	CenterRect ToCenterRect();
};