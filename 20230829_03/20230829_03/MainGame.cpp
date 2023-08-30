#include "MainGame.h"
#include "main.h"
#include "CardUtil.h"
void MainGame::Init()
{
	srand(time(NULL));
	for (int i = 0; i < 52; i++)
	{
		card[i] = i;
	}
	random_shuffle(&card[0], &card[51]);
	for (int i = 0; i < 10; i++)
	{
		player[i] = -1;
		dealer[i] = -1;
	}
	playerSum = 0;
	dealerSum = 0;
	cardIndex = 0;
	turn = 0;
	playerIndex = 0;
	dealerIndex = 0;
	stand = false;
	gameEnd = false;
}

void MainGame::Update()
{
	system("cls");
	if (turn == 0)
	{
		HandCards(playerIndex, player);
		HandCards(playerIndex, player);
		HandCards(dealerIndex, dealer);
		HandCards(dealerIndex, dealer);
		PrintHands(stand);
		int input=0;
		cout << "hit(0) or stand(1) : ";
		cin >> input;
		if (input == 0)
		{
			HandCards(playerIndex, player);
		}
		else
		{
			stand = true;
		}
	}
	else if (stand == false)
	{
		PrintHands(stand);
		int input=0;
		cout << "hit(0) or stand(1) : ";
		cin >> input;
		if (input == 0)
		{
			HandCards(playerIndex, player);
		}
		else
		{
			stand = true;
		}
	}
	else
	{
		PrintHands(stand);
		if (SumCards(dealer) < 17)
		{
			HandCards(dealerIndex, dealer);
		}
		else
		{
			gameEnd=true;
		}
	}
	system("cls");
	PrintHands(stand);
	if (SumCards(player) > 21)
	{
		cout << "Player Burst Player Lost" << endl;
		gameEnd = true;
	}
	else if (SumCards(dealer) > 21)
	{
		cout << "Dealer Burst Player Win" << endl;
		gameEnd = true;
	}
	else if (gameEnd == true)
	{
		if (SumCards(player) > SumCards(dealer))
		{
			cout << "Player Win" << endl;
		}
		else if (SumCards(player) < SumCards(dealer))
		{
			cout << "Player Lost" << endl;
		}
		else
		{
			cout << "Draw" << endl;
		}
	}
	turn++;
	system("pause");
}

void MainGame::Release()
{

}

bool MainGame::IsGameEnd()
{
	return gameEnd;
}

int MainGame::SumCards(int cards[])
{
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		if (cards[i] == -1)
		{
			break;
		}
		else if (cards[i] % 13 + 1 < 10)
		{
			sum = sum + cards[i]%13+1;
		}
		else
		{
			sum = sum + 10;
		}
	}
	if (sum < 21)
	{
		for (int i = 0; i < 10; i++)
		{
			if (cards[i] == -1)
			{
				break;
			}
			else if (cards[i] % 13 + 1 == 1)
			{
				if (sum + 10 <= 21)
				{
					sum = sum + 10;
				}
				break;
			}
		}
	}
	return sum;
}

void MainGame::PrintHands(bool Stand)
{
	cout << "Player Hand" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (player[i] != -1)
		{
			PrintCard(player[i]);
			cout << '\t';
		}
		else
		{
			break;
		}
	}
	cout << endl;
	cout << "Player Sum : " << SumCards(player) << endl;
	cout << "Dealer Hand" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (dealer[i] != -1)
		{
			if (Stand == false && i == 1)
			{
				cout << "??" << '\t';
				break;
			}
			else
			{
				PrintCard(dealer[i]);
				cout << '\t';
			}
		}
		else
		{
			break;
		}
	}
	cout << endl;
	if (stand)
	{
		cout << "Dealer Sum : " << SumCards(dealer) << endl;
	}
}

void MainGame::HandCards(int& index, int hand[])
{
	hand[index] = card[cardIndex];
	index++;
	cardIndex++;
}
