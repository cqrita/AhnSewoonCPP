#pragma once
enum HandSelect
{
	RIGHT,
	LEFT,
	NONE
};
enum HandState
{
	ROCK,
	SCISSORS,
	PAPER,
	END
};
void PrintHand(int x,int y,int hand);

class Player
{
public:
	int hand1;
	int hand2;
	int select;
	int last;
	void Init();
	void Update(int x, int y, int turn);
	void Release();
};

