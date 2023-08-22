#include <iostream>
#include <time.h>
using namespace std;
enum eRockScissorPaper{
	ROCK, 
	SCISSOR,
	PAPER,
	END
};
enum eErrorCode
{
	ErrPlayerNoGold=-17001,
	ErrPlayerNoCrystal = -17002,

};
void main()
{
	// enum

	// named integer

	int myHand = 0;

	// enum
	// enum eRockScissorPaper{ROCK, SCISSOR,PAPER,END};
	int myHand1 = eRockScissorPaper::ROCK;
	eRockScissorPaper myHand2=ROCK;
	int myHand = 0;
	int comHand = rand() % END;
	cout << "input my hand 0 rock 1 scissors 2 paper" << endl;
	cout << "my hand is";
	switch (myHand)
	{
	case ROCK:
		cout << "rock" << endl;
	case SCISSOR:
		cout << "scissors" << endl;

	case PAPER:
		cout << "paper" << endl;

	default:
		break;
	}
	cout << "com hand is";
	switch (comHand)
	{
	case ROCK:
		cout << "rock" << endl;
	case SCISSOR:
		cout << "scissors" << endl;

	case PAPER:
		cout << "paper" << endl;

	default:
		break;
	}
	if (comHand == myHand)
	{
		cout << "draw" << endl;
	}
	else if (comHand == ROCK && myHand == SCISSOR || comHand == SCISSOR && myHand == PAPER || comHand == PAPER && myHand== ROCK)
	{
		cout << "loss" << endl;
	}
	else
	{
		cout << "win" << endl;
	}
}