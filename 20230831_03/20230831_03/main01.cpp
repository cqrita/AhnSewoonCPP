#include "stdafx.h"
#include "MainGame.h"
void main()
{
	//MainGame Class
	// player com
	//Player Class
	//hand 1 hand 2
	//update
	//select left right
	//get winner
	//end
	MainGame* mainGame = new MainGame();
	while (mainGame->IsGameEnd() == false)
	{
		mainGame->Update();
	}
	delete mainGame;
	mainGame = nullptr;
}