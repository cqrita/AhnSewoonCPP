#pragma once

struct CenterRect
{
	float x, y, width, height;
	RECT ToRect();
	static CenterRect FromRect(RECT rect);
};