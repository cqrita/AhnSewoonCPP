#include "stdafx.h"
#include "MainGame.h"
#include "Character.h"
void MainGame::Init()
{
    _isGameEnd = false;
    _character = new Character();
    _character->Init();
}

void MainGame::Update()
{
    CustomConsole.GotoXY(0, 0); cout << "������������������������������������������";
    
}

void MainGame::Release()
{
    _character->Release();
    delete _character;
    _character = nullptr;
}

bool MainGame::IsGameEnd()
{
    return false;
}
