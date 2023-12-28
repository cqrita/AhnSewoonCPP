#include "stdafx.h"
#include "CommonStruct.h"
#include "CommonFunction.h"

RECT CenterRect::ToRect()
{
	RECT rc = Rect::MakeRect(static_cast<int>(x - width / 2), static_cast<int>(y - height / 2), static_cast<int>(width), static_cast<int>(height));

	return rc;
}

Gdiplus::Rect CenterRect::ToGdiRect()
{
	Gdiplus::Rect rc = Gdiplus::Rect(static_cast<int>(x - width / 2), static_cast<int>(y - height / 2), static_cast<int>(width), static_cast<int>(height));

	return rc;
}

CenterRect CenterRect::FromRect(RECT rect)
{
	CenterRect centerRect = {};
	centerRect.x = static_cast<float>((rect.left + rect.right) / 2);
	centerRect.y = static_cast<float>((rect.top + rect.bottom) / 2);
	centerRect.width = static_cast<float>(rect.right - rect.left);
	centerRect.height = static_cast<float>(rect.bottom - rect.top);

	return centerRect;
}

Vector2 CenterRect::Position()
{
	return Vector2(x, y);
}

CenterRect CenterCircle::ToCenterRect()
{
	return { center.x, center.y, radius * 2,radius * 2 };
}