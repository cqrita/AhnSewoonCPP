#include <iostream>
#include "MainGame.h"
using namespace std;
void main()
{
	//2. pointer, dynamic allocation


	int num1 = 3;

	//static allocation
	int num2 = 3;
	int arr[52] = { 0, };
	
	//stack ,heap

	//stack static allocation smaller faster
	//heap dynamic allocation bigger slower

	// dynamic allocation
	int* num = nullptr;
	num	= new int(3);

	if (true)
	{
		int num3 = 0;
	}
	delete num;
	num = nullptr;

	MainGame* mainGame = new MainGame();
	mainGame->Init();
	if (mainGame->IsGameEnd() == false)
	{
		mainGame->Update();
	}
	delete mainGame;
	mainGame = nullptr;
}