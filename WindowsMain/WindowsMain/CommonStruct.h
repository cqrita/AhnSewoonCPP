#pragma once

struct CenterRect
{
	int x, y, width, height;
	RECT ToRect();
	static CenterRect FromRect(RECT rect);
};