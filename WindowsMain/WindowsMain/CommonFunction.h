#pragma once
#include "CommonStruct.h"
//

//Rect
namespace Rect
{
	//x,y 
	inline RECT MakeRect(int x, int y, int width, int height)
	{
		RECT rc;
		rc.left = x;
		rc.top = y;
		rc.right = x + width;
		rc.bottom = y + height;
		return rc;
	}

	inline CenterRect MakeCenterRect(int x, int y, int width, int height)
	{
		CenterRect center;
		center.x = x;
		center.y = y;
		center.width = width;
		center.height = height;
		return center;
	}
}

namespace Draw
{
	inline void Rect(HDC hdc,RECT rc)
	{
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
	}
	inline void Rect(HDC hdc, CenterRect rc)
	{
		Rectangle(hdc, rc.x-rc.width, rc.y-rc.height/2, rc.x+rc.height, rc.y+rc.height);
	}
}

namespace Random
{
	inline int GetInt(int fromInclude, int toExclude)
	{
		return rand() % (fromInclude + 1) + rand() % (toExclude - fromInclude);
	}
}
namespace Collision
{
	bool PtInRect(CenterRect Rect, POINT pt);
	bool RecttInRect(CenterRect Rect1, CenterRect Rect2);
}