#pragma once
enum HandSelect
{
	RIGHT,
	LEFT,
	NONE
};
class Player
{
public:
	int hand1;
	int hand2;
	int select;
	void Init();
	void Update(int x, int y, int turn, int input, int input2);
	void Release();
};

