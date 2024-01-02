#include "stdafx.h"
#include "Button.h"
#include "Sprite.h"
void Button::SetState(eButtonState state)
{
	if (_state == state) return;
	_state = state;
	if (_sprites[static_cast<int>(_state)] == nullptr) return;
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

	SetState(eButtonState::Default);
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
	TransparentBlt(hdc, (int)(_body.x - _body.width / 2), (int)(_body.y - _body.height / 2) ,
		(int)(_body.width), (int)(_body.height), _currentSprite->GetDC(), _currentSprite->GetPos().x, _currentSprite->GetPos().y, size.x, size.y, _currentSprite->GetTransparent());


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

