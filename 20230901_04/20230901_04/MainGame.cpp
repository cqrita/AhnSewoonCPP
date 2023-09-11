#include "stdafx.h"
#include "MainGame.h"
#include "Character.h"

void MainGame::Init()
{
	srand(time(NULL));
	CustomConsole.SetCursor(tvision::CURSOR_OFF);
	_isGameEnd = false;

	_character = new Character();
	_character->Init();

	CustomConsole.GotoXY(0, 0);	
	cout << "¦£";
	for (int i = 0; i < 50; i++)
	{
		cout << "¦¡";
	}
	cout << "¦¤";
	for (int i = 1; i < 12; i++)
	{
		CustomConsole.GotoXY(0, i);
		cout << "¦¢";
		for(int j=0;j<50;j++)
		{
			cout << " ";
		}
		cout << "¦¢";
	}
	CustomConsole.GotoXY(0, 12);	
	cout << "¦¦";
	for (int i = 0; i < 50; i++)
	{
		cout << "¦¡";
	}
	cout << "¦¥";

	_score = 0;
	_starDuration = 600;
	_starTimer = 100;
	_moveDuration = 200;
	_moveTimer = 0;

	_character->Render();
}

void MainGame::Update(int deltaTime)
{
	char input = '\0';
	if (_kbhit())
	{
		input = _getch();
	}
	_starTimer += deltaTime;
	_moveTimer += deltaTime;
	
	for (int i = 0; i < _stars.size(); i++)
	{
		Star _star = _stars[i];
		if ((_character->_x == _star._x && _character->_y == _star._y) || (_character->_x + 1 >= _star._x && _character->_x <= _star._x && _character->_y + 1 <= _star._y && _character->_y + 2 >= _star._y))
		{
			_score++;
			CustomConsole.ClearArea(_star._x * 2, _star._y, _star._x * 2, _star._y);
			_stars.erase(_stars.begin() + i);
		}
	}

	if (_starTimer > _starDuration)
	{
		if (_stars.size() < 10)
		{
			Star star;
			star._x = 24;
			star._y = rand() % 8 + 1;
			_stars.push_back(star);
		}
		_starTimer = 0;
	}

	if (_moveTimer > _moveDuration)
	{
		for (int i = 0; i < _stars.size(); i++)
		{
			Star _star = _stars[i];
			CustomConsole.ClearArea(_star._x * 2, _star._y, _star._x * 2, _star._y);
			_stars[i]._x = _stars[i]._x - 1;
			if (_star._x < 2)
			{
				_stars.erase(_stars.begin() + i);
			}
		}
		_moveTimer = 0;
	}

	_character->Update(deltaTime, input);
	

	for (int i = 0; i < _stars.size(); i++)
	{
		Star _star = _stars[i];
		CustomConsole.GotoXY(_star._x * 2, _star._y);
		cout << "¡Ú";
	}
	CustomConsole.GotoXY(0, 15);
	cout << "Score : " << _score << "                 ";
	if (_score > 30)
	{
		_isGameEnd = true;
	}
	CustomConsole.GotoXY(0, 16);
}

void MainGame::Release()
{
	_character->Release();
	delete _character;
	_character = nullptr;
}

bool MainGame::IsGameEnd()
{
	return _isGameEnd;
}

