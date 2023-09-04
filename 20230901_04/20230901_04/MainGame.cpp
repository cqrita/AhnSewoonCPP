#include "stdafx.h"
#include "MainGame.h"
#include "Character.h"

void MainGame::Init()
{
	CustomConsole.SetCursor(tvision::CURSOR_OFF);
	_isGameEnd = false;

	_character = new Character();
	_character->Init();

	CustomConsole.GotoXY(0, 0);	cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖";
	CustomConsole.GotoXY(0, 1);	cout << "弛                                                  弛";
	CustomConsole.GotoXY(0, 2);	cout << "弛                                                  弛";
	CustomConsole.GotoXY(0, 3);	cout << "弛                                                  弛";
	CustomConsole.GotoXY(0, 4);	cout << "弛                                                  弛";
	CustomConsole.GotoXY(0, 5);	cout << "弛                                                  弛";
	CustomConsole.GotoXY(0, 6);	cout << "弛                                                  弛";
	CustomConsole.GotoXY(0, 7);	cout << "弛                                                  弛";
	CustomConsole.GotoXY(0, 8);	cout << "弛                                                  弛";
	CustomConsole.GotoXY(0, 9);	cout << "弛                                                  弛";
	CustomConsole.GotoXY(0, 10);	cout << "弛                                                  弛";
	CustomConsole.GotoXY(0, 11);	cout << "弛                                                  弛";
	CustomConsole.GotoXY(0, 12);	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎";


	_character->Render();
}

void MainGame::Update(int deltaTime)
{
	char input = '\0';
	if (_kbhit())
	{
		input = _getch();
	}
	_character->Update(deltaTime, input);

	CustomConsole.GotoXY(0, 15);
	cout << "DeltaTime : " << deltaTime << "                 ";


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

