#pragma once
#include "CommonStruct.h"
#include <vector>
#include "Vector2Int.h"
namespace Rect
{
	inline RECT MakeRect(int x, int y, int width, int height)
	{
		RECT rc;
		rc.left = x;
		rc.top = y;
		rc.right = x + width;
		rc.bottom = y + height;

		return rc;
	}

	inline CenterRect MakeCenterRect(float x, float y, float width, float height)
	{
		CenterRect rc;
		rc.x = x;
		rc.y = y;
		rc.width = width;
		rc.height = height;

		return rc;
	}
	inline void ChangeToNormalValue(RECT& rc)
	{
		if (rc.left > rc.right)
		{
			swap(rc.left, rc.right);
		}
		if (rc.top > rc.bottom)
		{
			swap(rc.top, rc.bottom);
		}
	}
}
namespace Circle
{
	inline CenterCircle MakeCenterCircle(float x, float y, float radius)
	{
		CenterCircle rc;
		rc.center.x = x;
		rc.center.y = y;
		rc.radius = radius;
		return rc;
	}
}
namespace Draw
{
	inline void Rect(HDC hdc,RECT rc)
	{
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
	}
	void Rect(HDC hdc, RECT rc, Vector2Int cameraPos);
	

	inline void Rect(HDC hdc, CenterRect rc)
	{
		Rectangle(hdc,
			static_cast<int>(rc.x - rc.width / 2),	//left
			static_cast<int>(rc.y - rc.height / 2),	//top
			static_cast<int>(rc.x + rc.width / 2),	//right
			static_cast<int>(rc.y + rc.height / 2)	//bottom
		);
	}
	inline void Circle(HDC hdc, RECT rc)
	{
		Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);
	}
	inline void Circle(HDC hdc, CenterRect rc)
	{
		Ellipse(hdc,
			static_cast<int>(rc.x - rc.width / 2),	//left
			static_cast<int>(rc.y - rc.height / 2),	//top
			static_cast<int>(rc.x + rc.width / 2),	//right
			static_cast<int>(rc.y + rc.height / 2)	//bottom
		);
	}
	inline void Line(HDC hdc, Vector2 startPos, Vector2 endPos)
	{
		MoveToEx(hdc, static_cast<int>(startPos.x), static_cast<int>(startPos.y), (LPPOINT)NULL);
		LineTo(hdc, static_cast<int>(endPos.x), static_cast<int>(endPos.y));
	}
}

namespace Random
{
	inline int GetInt(int fromInclude, int toExclude)
	{
		return fromInclude + rand() %( toExclude - fromInclude);
	}
	inline float GetFloat(int fromInclude, int toExclude)
	{
		float random = static_cast<float> (rand()) / static_cast<float>(RAND_MAX);

		return fromInclude  +random*(toExclude - fromInclude);
	}
}
namespace Collision
{
	bool PtInRect(CenterRect Rect, POINT pt);
	bool RectInRect(CenterRect Rect1, CenterRect Rect2);
	bool CircleInCircle(CenterCircle c1, CenterCircle c2);
	bool RectInCircle(CenterRect rect1, CenterCircle c2);
}
