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
	bool CircleInCircle(CenterCircle c1, CenterCircle c2)
	{
		float length = (c1.center - c2.center).Length();
		return length <= c1.radius + c2.radius;
	}
	bool RectInCircle(CenterRect rect, CenterCircle circle)
	{
		float dx = abs(rect.x - circle.center.x);
		float dy = abs(rect.y - circle.center.y);

		float distX = dx - rect.width / 2;
		float distY = dy - rect.height / 2;

		if (distX > circle.radius || distY > circle.radius) {
			return false;
		}

		if (distX <= 0 || distY <= 0) {
			return true;
		}

		float cornerDistance_sq = (distX * distX) + (distY * distY);

		return cornerDistance_sq <= (circle.radius * circle.radius);

	}
}

void Draw::Rect(HDC hdc, RECT rc, Vector2Int cameraPos)
{
	
	Rectangle(hdc, rc.left - cameraPos.x + WIN_SIZE_WIDTH / 2, rc.top - cameraPos.y + WIN_SIZE_HEIGHT / 2, rc.right - cameraPos.x + WIN_SIZE_WIDTH / 2, rc.bottom - cameraPos.y + WIN_SIZE_HEIGHT / 2);
	
}
