#pragma once
#include "main.h"
enum eCardShape
{
	CARDSHAPE_SPACE,
	CARDSHAPE_DIAMOND,
	CARDSHAPE_HEART,
	CARDSHAPE_CLOVER,
	CARDSHAPE_END,

};
void PrintCard(int cardNum)
{
	switch (cardNum / 13)
	{
	case CARDSHAPE_SPACE:
		cout << "¢¼";
		break;
	case CARDSHAPE_DIAMOND:
		cout << "¢¾";
		break;

	case CARDSHAPE_HEART:
		cout << "¡ß";
		break;

	case CARDSHAPE_CLOVER:
		cout << "¢À";
		break;
	}
	switch (cardNum % 13 + 1)
	{
	case 1:
		cout << "A";
		break;
	case 11:
		cout << "J";
		break;

	case 12:
		cout << "Q";
		break;

	case 13:
		cout << "K";
		break;
	default:
		cout << cardNum % 13 + 1;
		break;
	}
}
