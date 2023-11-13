#include "stdafx.h"
#include "Button.h"
#include "Sprite.h"
void Button::SetState(eButtonState state)
{
	if (_state == state) return;
	_state = state;
	_currentSprite = _sprites[static_cast<int>(_state)];
}

Button::Button()
{

}

Button::~Button()
{

}

void Button::Init()
{
	Super::Init();

	SetState(eButtonState::End);
}

void Button::Render(HDC hdc)
{
	Super::Render(hdc);

	if (_currentSprite == nullptr)
	{
		return;
	}
	Vector2Int size = _currentSprite->GetSize();
	BLENDFUNCTION bf;
	bf.AlphaFormat = AC_SRC_ALPHA;

	bf.BlendFlags = 0;

	bf.BlendOp = AC_SRC_OVER;
	bf.SourceConstantAlpha = _currentSprite->GetTransparent();
	TransparentBlt(hdc, (int)(_pos.x - _size.x / 2), (int)(_pos.y - _size.y / 2),
		(int)(_size.x), (int)(_size.y), _currentSprite->GetDC(), _currentSprite->GetPos().x, _currentSprite->GetPos().y, size.x, size.y, _currentSprite->GetTransparent());

}

void Button::Update()
{
	Super::Update();

	/*
	if(IsInMouse)
	if (key)
		pressed
	else if(key up)
		if state pressed
			clicked
	else if(key down)
	else
		hover
	else
	
		default
	
	*/
	if (IsInMouse())
	{
		if (Input->GetKeyDown(VK_LBUTTON))
		{
			SetState(eButtonState::Pressed);
		}
		else if (Input->GetKeyUp(VK_LBUTTON))
		{
			if (_state == eButtonState::Pressed)
			{
				if (_onClick)
				{
					_onClick();
				}
			}
		}
		else if (Input->GetKey(VK_LBUTTON))
		{

		}
		else
		{
			SetState(eButtonState::Hover);
		}
	}
	else
	{
		SetState(eButtonState::Default);

	}
}

void Button::Release()
{
	Super::Release();

}

