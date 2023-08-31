#include "stdafx.h"
#include "Player.h"
#include "HandUtil.h"
void Player::Init()
{
	hand1 = END;
	hand2 = END;
	select = NONE;
}

void Player::Update(int x,int y,int turn,int input,int input2)
{
	if (turn == 0)
	{
		hand1 = input;
		CustomConsole.GotoXY(x, y);
		PrintHand(hand1);
		hand2 = input2;
		y = y + 20;
		CustomConsole.GotoXY(x, y);
		PrintHand(input2);
	}
	else
	{
		CustomConsole.GotoXY(x, y);
		select = input;
		if (select == RIGHT)
		{
			PrintHand(hand1);
		}
		else
		{
			PrintHand(hand2);
		}
	}
}

void Player::Release()
{

}
