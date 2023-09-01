#include "stdafx.h"
#include "Character.h"

void Character::Init()
{
	_x = 10;
	_y = 2;
}

void Character::Update(char inputKey)
{
	CustomConsole.GotoXY(_x * 2, _y); cout << "";

	CustomConsole.ClearArea(_x * 2, _y, (_x + 1) * 2, _y);
	char input = _getch();
	switch (input)
	{
	case 'w':
		break;
	case 's':
		break;
	}

}
void Character::Release()
{

}
