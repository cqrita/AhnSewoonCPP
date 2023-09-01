#include "stdafx.h"
#include "Player.h"
void Player::Init()
{
	hand1 = END;
	hand2 = END;
	select = NONE;
	last = END;
}

void Player::Update(int turn)
{
	if (turn <2)
	{
		PrintHand(hand1);
		cout << endl;
		PrintHand(hand2);
	}
	else
	{
		if (select == RIGHT)
		{
			PrintHand(hand1);
			last = hand1;
		}
		else
		{
			PrintHand(hand2);
			last = hand2;
		}
	}
}

void Player::Release()
{

}
void PrintHand(int hand)
{
	switch (hand)
	{
	case ROCK:
		cout << "    _______" <<endl;
		cout << "---'   ____)" << endl;
		cout << "      (_____)" << endl;
		cout << "      (_____)" << endl;
		cout << "      (____)" << endl;
		cout << "---.__(___)" << endl;
		break;
	case SCISSORS:
		cout << "	_______" << endl;
		cout << "---'   ____)____" << endl;
		cout << "          ______)" << endl;
		cout << "      __________)" << endl;
		cout << "      (____)" << endl;
		cout << "---.__(___)" << endl;
		break;
	case PAPER:
		cout << "	_______" << endl;
		cout << "---'   ____)____" << endl;
		cout << "           ______)" << endl;
		cout << "   	  _______)" << endl;
		cout << "    	 _______)" << endl;
		cout << "---.__________)  " << endl;
		break;
	}
}