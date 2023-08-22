#include <iostream>
#include <time.h>
using namespace std;
void main()
{

	//timetable
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << i << " * " <<j<<" = " << i * j << endl;
		}
		cout << endl;
	}
	//i=>1,2,3 4,5,6 7,8,9
	for (int i = 0; i < 3; i++)
	{
		//j =>9
		for (int j = 0; j < 9; j++)
		{
			// k group by three
			for (int k = 0; k < 3; k++)
			{
				cout << i*3+k + 1 << " * " << k + 1 << " = " << (i*3 + k + 1) * (k + 1) << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}



	// scissors rock paper
	// get hand input1
	// get hand input2
	// print hand input1 input2
	// rand com input1
	// rand com input2
	// print com input1 input2
	// select left right
	// print handLast
	// rand left right
	// print comLast
	// print win lost
	srand(time(NULL));
	int myHand[2];
	cout << "input left hand scissors(0) rock(1) paper(2)" << endl;
	cin >> myHand[0];
	cout << "input right hand scissors(0) rock(1) paper(2)" << endl;
	cin >> myHand[1];
	cout << "my left hand is ";
	switch (myHand[0])
	{
	case 0:
		cout << "scissors" << endl;
		break;
	case 1:
		cout << "rock" << endl;
		break;
	case 2:
		cout << "paper" << endl;
		break;
	}
	cout << "my right hand is ";
	switch (myHand[1])
	{
	case 0:
		cout << "scissors" << endl;
		break;
	case 1:
		cout << "rock" << endl;
		break;
	case 2:
		cout << "paper" << endl;
		break;
	}
	int comHand[2];
	comHand[0] = rand() % 3;
	comHand[1] = rand() % 3;
	cout << "com left hand is ";
	switch (comHand[0])
	{
	case 0:
		cout << "scissors" << endl;
		break;
	case 1:
		cout << "rock" << endl;
		break;
	case 2:
		cout << "paper" << endl;
		break;
	}
	cout << "com right hand is ";
	switch (comHand[1])
	{
	case 0:
		cout << "scissors" << endl;
		break;
	case 1:
		cout << "rock" << endl;
		break;
	case 2:
		cout << "paper" << endl;
		break;
	}
	int mySelect, myLastHand = 0;
	cout << "select left(0) right(1)" << endl;
	cin >> mySelect;
	switch (mySelect)
	{
	case 0:
		myLastHand = myHand[0];
		break;
	case 1:
		myLastHand = myHand[1];
	}
	cout << "my last hand is ";
	switch (myLastHand)
	{
	case 0:
		cout << "scissors" << endl;
		break;
	case 1:
		cout << "rock" << endl;
		break;
	case 2:
		cout << "paper" << endl;
		break;
	}
	int comSelect, comLastHand = 0;
	comSelect = rand() % 2;
	switch (comSelect)
	{
	case 0:
		comLastHand = comHand[0];
		break;
	case 1:
		comLastHand = comHand[1];
	}
	cout << "com last hand is ";
	switch (comLastHand)
	{
	case 0:
		cout << "scissors" << endl;
		break;
	case 1:
		cout << "rock" << endl;
		break;
	case 2:
		cout << "paper" << endl;
		break;
	}
	if (myLastHand == 0 && comLastHand == 1)
	{
		cout << "Lost" << endl;
	}
	else if (myLastHand == 1 && comLastHand == 2)
	{
		cout << "Lost" << endl;
	}

	else if (myLastHand == 2 && comLastHand == 0)
	{
		cout << "Lost" << endl;
	}

	else if (myLastHand == comLastHand)
	{
		cout << "Draw" << endl;
	}
	else
	{
		cout << "Won" << endl;
	}

}