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
	bool RectInRect(CenterRect rect1, CenterRect rect2)
	{
		POINT pt1 = { rect2.x - rect2.width / 2, rect2.y - rect2.height / 2 };
		POINT pt2 = { rect2.x + rect2.width / 2, rect2.y - rect2.height / 2 };
		POINT pt3 = { rect2.x - rect2.width / 2, rect2.y + rect2.height / 2 };
		POINT pt4 = { rect2.x + rect2.width / 2, rect2.y + rect2.height / 2 };

		if (PtInRect(rect1, pt1))
		{
			return true;
		}
		else if (PtInRect(rect1, pt2))
		{
			return true;
		}
		else if (PtInRect(rect1, pt3))
		{
			return true;
		}
		else if (PtInRect(rect1, pt4))
		{
			return true;
		}
	}
}


