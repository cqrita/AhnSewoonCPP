#include "stdafx.h"
#include "Hand.h"


void Hand::Init()
{

}
void Hand::Release()
{

}

void Hand::SetMyHand(int hand)
{
	if (hand >= RSP_END)
	{
		cout << "경고!" << endl;
	}

	_hand = hand;
}

void Hand::SetComHand()
{
	if (_mainGame->GetSet() % 3 == 2)
	{
		Hand* playerHand = _mainGame->GetHand(eHandKind::HANDKIND_PLAYER);
		if (playerHand->GetHand() == RSP_ROCK)
		{
			_hand = RSP_PAPER;
		}
		else if (playerHand->GetHand() == RSP_SCISSOR)
		{
			_hand = RSP_ROCK;
		}
		else if (playerHand->GetHand() == RSP_PAPER)
		{
			_hand = RSP_SCISSOR;
		}
	}
	else
	{
		_hand = rand() % 3;
	}
}

int Hand::GetHand()
{
	return _hand;
}

//문자열
string Hand::GetHandName()
{
	switch (_hand)
	{
	case RSP_ROCK:
		return "바위";
		break;
	case RSP_SCISSOR:
		return "가위";
		break;
	case RSP_PAPER:
		return "보";
		break;
	}
}