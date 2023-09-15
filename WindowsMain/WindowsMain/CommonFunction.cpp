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