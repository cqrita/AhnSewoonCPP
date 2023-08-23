#include <iostream>
#include <time.h>

using namespace std;

void main()
{
	srand(time(NULL));
	// input left hand
	// input right hand
	// print left hand
	// print right hand
	// rand com left hand
	// rand com right hand
	// print com left hand
	// print com right hand
	// select my hand 
	// print last my hand
	// rand select com hand
	// print last com hand
	// validate winner 
	// print winner
	// 
	// 
	// 
	// 
	// 
	//
	int myHand[2];
	cout << "input left hand 0 scissors 1 rock 2 paper" << endl;
	cin >> myHand[0];
	cout << "input right hand 0 scissors 1 rock 2 paper" << endl;
	cin >> myHand[1];
	for (int i = 0; i < 2; i++)
	{
		switch (myHand[i])
		{
		case 0:
			cout << "scissors";
			break;
		case 1:
			cout << "rock";
			break;
		case 2:
			cout << "paper";
			break;
		}
	}
	int comHand[2];
	for (int i = 0; i < 2; i++)
	{
		comHand[i] = rand() % 3;
		switch (comHand[i])
		{
		case 0:
			cout << "scissors";
			break;
		case 1:
			cout << "rock";
			break;
		case 2:
			cout << "paper";
			break;
		}
	}
	cout << "input hand 0 left 1 right" << endl;
	int handInput,lastMyHand;
	cin >> handInput;
	if (handInput == 0)
	{
		lastMyHand = myHand[0];
	}
	else
	{
		lastMyHand = myHand[1];
	}
	int comRand, lastComHand;
	comRand=rand()%3;
	if (handInput == 0)
	{
		lastComHand = comHand[0];
	}
	else
	{
		lastComHand = comHand[1];
	}
	if (lastMyHand == 0 && lastComHand == 1)
	{
		cout << "lose" << endl;
	}
	else if (lastMyHand == 1 && lastComHand == 2)
	{
		cout << "lose" << endl;
	}
	else if (lastMyHand == 2 && lastComHand == 0)
	{
		cout << "lose" << endl;
	}
	else if (lastMyHand == lastComHand)
	{
		cout << "draw" << endl;
	}
	else
	{
		cout << "win" << endl;
	}
}