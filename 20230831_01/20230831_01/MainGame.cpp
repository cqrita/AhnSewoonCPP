#include "MainGame.h"

void MainGame::Init()
{
	srand(time(NULL));
	player = END;
	com = END;
	gameEnd = false;
}

void MainGame::Update()
{
	system("cls");
	int input;
	cout << "input hand ROCK(0) SCISSORS(1) PAPER(2) : ";
	cin >> input;
	player = input;
	com = rand() % 3;
	cout << "player hand : ";
	PrintHand(player);
	cout << endl;
	cout << "com hand : ";
	PrintHand(com);
	cout << endl;
	if ((player == ROCK && com == SCISSORS) || (player == SCISSORS && com == PAPER) || (player == PAPER && com == ROCK))
	{
		cout << "player win" << endl;
	}
	else if (player == com)
	{
		cout << "draw" << endl;
	}
	else
	{
		cout << "player lose" << endl;
	}
	gameEnd = true;
	system("pause");
}

bool MainGame::IsGameEnd()
{
	return gameEnd;
}

void MainGame::PrintHand(int hand)
{
	switch (hand)
	{
	case ROCK:
		cout << "ROCK";
		break;
	case SCISSORS:
		cout << "SCISSORS";
		break;
	case PAPER:
		cout << "PAPER";
		break;

	default:
		break;
	}
}
