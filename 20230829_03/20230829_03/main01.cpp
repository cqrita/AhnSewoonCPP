#include "main.h"
#include "MainGame.h"
void main()
{
	// card 52
	//player 10
	//dealer 10
	// while
	// if second check hit stand
	// if hit
	// get cards
	// add cards
	// check ace
	// check loser
	// if stand
	// while
	// dealer add until 17=>
	// add cards
	// check ace
	// check loser
	//
	// check winner loser

	MainGame mainGame;
	mainGame.Init();

	//false == mainGame.IsGameEnd()
	while (!mainGame.IsGameEnd())
	{
		mainGame.Update();
	}

	mainGame.Release();

}