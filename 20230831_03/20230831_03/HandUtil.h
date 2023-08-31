#pragma once
#include "stdafx.h"
enum HandState
{
	ROCK,
	SCICSSORS,
	PAPER,
	END
};
void PrintHand(int hand)
{
	switch (hand)
	{
	case ROCK:
		cout << "    _______" << endl;
		cout << "---'   ____)" << endl;
		cout << "      (_____)" << endl;
		cout << "      (_____)" << endl;
		cout << "      (____)" << endl;
		cout << "---.__(___)" << endl;
		break;
	case SCICSSORS:
		cout << "	_______" << endl;
		cout << "---'   ____)___" << endl;
		cout << "		  ______)" << endl;
		cout << "	   __________)" << endl;
		cout << "	  (____)" << endl;
		cout << "---.__(___)" << endl;
		break;
	case PAPER:
		cout << "	_______" << endl;
		cout << "---'   ____)___" << endl;
		cout << "		  _______)" << endl;
		cout << "	   __________)" << endl;
		cout << "		 _______)" << endl;
		cout << "---.__________)" << endl;
		break;
	}
}
