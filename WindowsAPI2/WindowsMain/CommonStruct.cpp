#include"stdafx.h"
#include "CommonStruct.h"
#include "CommonFunction.h"


RECT CenterRect::ToRect()
{
	RECT rc;
	rc = Rect::MakeRect(x - width / 2, y - height / 2, width, height);
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