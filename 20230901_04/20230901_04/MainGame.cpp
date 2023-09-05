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

	CustomConsole.GotoXY(0, 0);	cout << "��������������������������������������������������������������������������������������������������������";
	CustomConsole.GotoXY(0, 1);	cout << "��                                                  ��";
	CustomConsole.GotoXY(0, 2);	cout << "��                                                  ��";
	CustomConsole.GotoXY(0, 3);	cout << "��                                                  ��";
	CustomConsole.GotoXY(0, 4);	cout << "��                                                  ��";
	CustomConsole.GotoXY(0, 5);	cout << "��                                                  ��";
	CustomConsole.GotoXY(0, 6);	cout << "��                                                  ��";
	CustomConsole.GotoXY(0, 7);	cout << "��                                                  ��";
	CustomConsole.GotoXY(0, 8);	cout << "��                                                  ��";
	CustomConsole.GotoXY(0, 9);	cout << "��                                                  ��";
	CustomConsole.GotoXY(0, 10);	cout << "��                                                  ��";
	CustomConsole.GotoXY(0, 11);	cout << "��                                                  ��";
	CustomConsole.GotoXY(0, 12);	cout << "��������������������������������������������������������������������������������������������������������";
	_star._x = rand() % 23 + 1;
	_star._y = rand() % 8 + 1;
	CustomConsole.GotoXY(_star._x * 2, _star._y);
	cout << "��";
	_score = 0;
	_character->Render();
}

void MainGame::Update(int deltaTime)
{
	char input = '\0';
	if (_kbhit())
	{
		input = _getch();
		CustomConsole.GotoXY(_star._x * 2, _star._y);
		cout << "��";
	}
	if ((_character->_x == _star._x && _character->_y == _star._y) || (_character->_x + 1 >= _star._x && _character->_x <= _star._x && _character->_y + 1 <= _star._y && _character->_y + 2 >= _star._y))
	{
		_star._x = rand() % 23 + 1;
		_star._y = rand() % 8 + 1;
		_score++;
		CustomConsole.ClearArea(_star._x * 2, _star._y, _star._x * 2, _star._y);
	}
	_character->Update(deltaTime, input);
	

	
	CustomConsole.GotoXY(_star._x * 2, _star._y);
	cout << "��";
	CustomConsole.GotoXY(0, 15);
	cout << "Score : " << _score << "                 ";
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

