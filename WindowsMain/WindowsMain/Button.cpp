#include "stdafx.h"
#include "Button.h"

Button::Button()
{

}

Button::~Button()
{

}

void Button::Init()
{

}

void Button::Render(HDC hdc)
{
	Draw::Rect(hdc, GetRect());
}

void Button::Update()
{
	/*
	if(mouse collide)
	{
		if(mouse click)
		{
			state=pressed
		}
		else
		{
			if(state== pressd)
			{
				click event
			}
			state=hover
		}
	}
	else
	{
	default
	}
	*/
	if (IsInMouse())
	{
		if (GET_SINGLE(KeyManager)->GetKey(VK_LBUTTON)&& _state == eButtonState::Hover)
		{
			_state = eButtonState::Pressed;
		}
		else
		{
			if (_state == eButtonState::Pressed)
			{
				if (_onClick)
				{
					_onClick();
				}
				_state = eButtonState::Hover;
			}
			if (_state == eButtonState::Default&& !GET_SINGLE(KeyManager)->GetKey(VK_LBUTTON))
			{
				_state = eButtonState::Hover;
			}
		}
	}
	else
	{
		_state = eButtonState::Default;

	}
}

void Button::Release()
{

}

