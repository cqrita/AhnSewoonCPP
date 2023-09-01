#include "stdafx.h"
#include "Player.h"
void Player::Init()
{
	hand1 = END;
	hand2 = END;
	select = NONE;
	last = END;
}

void Player::Update(int x,int y,int turn)
{
	if (turn <2)
	{
		PrintHand(x, y,hand1);
		y = y + 20;
		PrintHand(x, y + 80,hand2);
	}
	else
	{
		if (select == RIGHT)
		{
			PrintHand(x, y,hand1);
			last = hand1;
		}
		else
		{
			PrintHand(x, y,hand2);
			last = hand2;
		}
	}
}

void Player::Release()
{

}
void PrintHand(int x,int y,int hand)
{
	switch (hand)
	{
	case ROCK:
		CustomConsole.GotoXY(x, y++);
		cout << "    _______" ;
		CustomConsole.GotoXY(x, y++);
		cout << "---'   ____)";
		CustomConsole.GotoXY(x, y++);
		cout << "      (_____)" ;
		CustomConsole.GotoXY(x, y++);
		cout << "      (_____)" ;
		CustomConsole.GotoXY(x, y++);
		cout << "      (____)" ;
		CustomConsole.GotoXY(x, y++);
		cout << "---.__(___)" ;
		break;
	case SCISSORS:
		CustomConsole.GotoXY(x, y++);
		cout << "	_______" ;
		CustomConsole.GotoXY(x, y++);
		cout << "---'   ____)___" ;
		CustomConsole.GotoXY(x, y++);
		cout << "		  ______)" ;
		CustomConsole.GotoXY(x, y++);
		cout << "	   __________)" ;
		CustomConsole.GotoXY(x, y++);
		cout << "	  (____)" ;
		CustomConsole.GotoXY(x, y++);
		cout << "---.__(___)" ;
		break;
	case PAPER:
		CustomConsole.GotoXY(x, y++);
		cout << "	_______" ;
		CustomConsole.GotoXY(x, y++);
		cout << "---'   ____)___" ;
		CustomConsole.GotoXY(x, y++);
		cout << "		  _______)" ;
		CustomConsole.GotoXY(x, y++);
		cout << "	   __________)" ;
		CustomConsole.GotoXY(x, y++);
		cout << "		 _______)" ;
		CustomConsole.GotoXY(x, y++);
		cout << "---.__________)" ;
		break;
	}
}