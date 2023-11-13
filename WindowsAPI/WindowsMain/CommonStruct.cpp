#include"stdafx.h"
#include "CommonStruct.h"
#include "CommonFunction.h"


RECT CenterRect::ToRect()
{
	RECT rc;
	rc = Rect::MakeRect(x - width / 2, y - height / 2, width, height);
	return rc;
}
Gdiplus::Rect CenterRect::ToGdiRect()
{
	Gdiplus::Rect rc;
	rc = Gdiplus::Rect(x - width / 2, y - height / 2, width, height);
	return rc;
}
CenterRect CenterRect::FromRect(RECT rect)
{
	CenterRect centerRect = {};
	centerRect.x = static_cast<float>((rect.right + rect.left) / 2);
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
	return CenterRect(center.x,center.y,radius*2,radius*2);
}
