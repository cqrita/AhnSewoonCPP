#include "stdafx.h"
#include "CommonFunction.h"
#include "Types.h"

namespace Draw
{
	void Rect(HDC hdc, RECT rc, Vector2Int cameraPos)
	{
		Rectangle(hdc,
			rc.left - cameraPos.x + WIN_SIZE_WIDTH / 2,
			rc.top - cameraPos.y + WIN_SIZE_HEIGHT / 2,
			rc.right - cameraPos.x + WIN_SIZE_WIDTH / 2,
			rc.bottom - cameraPos.y + WIN_SIZE_HEIGHT / 2);
	}
}

namespace Collision
{

	bool PtInRect(CenterRect rect, POINT pt)
	{
		if (rect.x - rect.width / 2 <= pt.x && pt.x <= rect.x + rect.width / 2  //가로 체크
			&& rect.y - rect.height / 2 <= pt.y && pt.y <= rect.y + rect.height / 2)	//세로체크
		{
			return true;
		}

		return false;
	}


	bool RectInRect(CenterRect rect1, CenterRect rect2)
	{
		RECT tmp;
		RECT r1 = rect1.ToRect();
		RECT r2 = rect2.ToRect();
		return IntersectRect(&tmp, &r1, &r2);

		POINT pt1 = { static_cast<int>(rect2.x - rect2.width / 2), static_cast<int>(rect2.y - rect2.height / 2) };
		POINT pt2 = { static_cast<int>(rect2.x + rect2.width / 2), static_cast<int>(rect2.y - rect2.height / 2) };
		POINT pt3 = { static_cast<int>(rect2.x - rect2.width / 2), static_cast<int>(rect2.y + rect2.height / 2) };
		POINT pt4 = { static_cast<int>(rect2.x + rect2.width / 2), static_cast<int>(rect2.y + rect2.height / 2) };

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



		return false;
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