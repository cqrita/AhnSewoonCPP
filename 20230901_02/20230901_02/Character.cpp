#include "stdafx.h"
#include "Character.h"

void Character::Init()
{
	_x = 0;
	_y = 0;
	_animationIndex = 0;
	_animationTime = 0;
}

void Character::Update(int deltaTime, char inputKey)
{
	//캐릭터 애니메이션 코드
	//deltaTime이 쌓인값이 500이 넘으면 그떄 Index 변화
	_animationTime += deltaTime;
	if (500 < _animationTime)
	{
		//애니메이션 인덱스 변화! (0, 1, 2) 중에서만 변하도록!
		_animationTime = 0;
		_animationIndex++;
		_animationIndex %= 3;
		Erase();
		Render();
	}

}

void Character::Render()
{
	
}

void Character::Erase()
{
}

void Character::Release()
{
}
