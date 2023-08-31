#pragma once
#include<iostream>
#include<Windows.h>
using namespace std;

enum Hand
{
	ROCK,
	SCISSORS,
	PAPER,
	END
};
class MainGame
{
public:
	int player;
	int com;
	bool gameEnd;
	void Init();
	void Update();
	bool IsGameEnd();
	void PrintHand(int hand);
	
};

