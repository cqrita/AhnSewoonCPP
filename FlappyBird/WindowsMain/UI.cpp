#include "stdafx.h"
#include "UI.h"

UI::UI()
{

}

UI::~UI()
{

}

void UI::Init()
{

}

void UI::Render(HDC hdc)
{

}

void UI::Update()
{

}

void UI::Release()
{

}

CenterRect UI::GetRect()
{
	return _body;
}

void UI::SetRect(CenterRect Rect)
{
	_body = Rect;
}

bool UI::IsInMouse()
{
	return Collision::PtInRect(GetRect(), _mousePos);
}
