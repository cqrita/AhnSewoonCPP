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
	return CenterRect{_pos.x,_pos.y,static_cast<float>(_size.x),static_cast<float>(_size.y) };
}

void UI::SetRect(CenterRect Rect)
{
	_pos.x = Rect.x;
	_pos.y = Rect.y;
	_size.x = static_cast<int>(Rect.width);
	_size.y = static_cast<int>(Rect.height);
}

bool UI::IsInMouse()
{
	return Collision::PtInRect(GetRect(), _mousePos);
}
