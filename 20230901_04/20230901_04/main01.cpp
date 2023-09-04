#include "stdafx.h"
#include "MainGame.h"

void main()
{
	MainGame* mainGame = new MainGame();
	mainGame->Init();

	long prevTick = GetTickCount64();
	long currentTick = GetTickCount64();
	while (false == mainGame->IsGameEnd())
	{
		long currentTick = GetTickCount64();
		mainGame->Update(currentTick - prevTick);
		prevTick = currentTick;
	}

	mainGame->Release();
	delete mainGame;
	mainGame = nullptr;
}