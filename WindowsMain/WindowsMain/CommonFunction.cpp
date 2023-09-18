#include "stdafx.h"
#include "CommonFunction.h"

namespace Collision
{
	bool PtInRect(CenterRect Rect, POINT pt)
	{
		if ((Rect.x - Rect.width / 2 <= pt.x) && (Rect.x + Rect.width / 2 >= pt.x) && (Rect.y - Rect.height / 2 <= pt.y) && (Rect.y + Rect.height / 2 >= pt.y))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool RecttInRect(CenterRect Rect1, CenterRect Rect2)
	{
		POINT pt[4];
		
		pt[0] = { Rect1.x - Rect1.width / 2 ,Rect1.y - Rect1.height / 2 };
		pt[1] = { Rect1.x + Rect1.width / 2,Rect1.y - Rect1.height / 2 };
		pt[2] = { Rect1.x - Rect1.width / 2,Rect1.y + Rect1.height / 2 };
		pt[3] = { Rect1.x + Rect1.width / 2,Rect1.y + Rect1.height / 2 };
		for (int i = 0; i < 4; i++)
		{
			if (PtInRect(Rect2, pt[i]))
			{
				return true;
			}
		}
		return false;
	}
}
namespace Rect
{
	int* InsideRect(RECT rect1, RECT rect2)
	{
		int arr[4] = { 0,0,0,0 };
		if (rect1.left < rect2.left)
		{
			arr[0] = 1;
		}
		if (rect1.right > rect2.right)
		{
			arr[1] = 1;
		}
		if (rect1.top < rect2.top)
		{
			arr[2] = 1;
		}
		if (rect1.bottom > rect2.bottom)
		{
			arr[3] = 1;
		}
		return arr;
	}

	int* OutsideRect(RECT rect1, RECT rect2)
	{
		int arr[4] = { 0,0,0,0 };
		
		if (rect1.left < rect2.right)
		{
			arr[0] = 1;
		}
		if (rect1.right > rect2.left)
		{
			arr[1] = 1;
		}
		if (rect1.top < rect2.bottom)
		{
			arr[2] = 1;
		}
		if (rect1.bottom > rect2.top)
		{
			arr[3] = 1;
		}
		return arr;
	}
}

