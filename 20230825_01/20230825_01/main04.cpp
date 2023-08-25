#include <iostream>
using namespace std;
enum eCardShape
{
	SPACE,
	DIAMOND,
	HEART,
	CLOVER,
	END
};
void PrintCard(int card)
{
	int shape = card / 13;
	switch (shape)
	{
	case SPACE:
		cout << "♠";
		break;
	case DIAMOND:
		cout << "◆";
		break;
	case HEART:
		cout << "♥";
		break;
	case CLOVER:
		cout << "♣";
		break;
	default:
		break;
	}

	int num = card % 13 + 1;
	switch (num)
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
		cout << num;
		break;
	}

}
void main()
{
	srand(time(NULL));
	// 52 cards
	int cardArr[52] = {};
	// initialize
	// 0~12 space A~K ♠
	// 13~25 diamond ♦
	// 26~38 heart ♥
	// 38~51 clover ♣
	// 
	//
	for (int i = 0; i < 52; i++)
	{
		cardArr[i]=i;
	}
	for (int i = 0; i < 100000; i++)
	{
		int num1 = rand() % 52;
		int num2 = rand() % 52;
		int temp = cardArr[num1];
		cardArr[num1] = cardArr[num2];
		cardArr[num2] = temp;
	}
	//draw card
	for (int i = 0; i < 52; i++)
	{
		PrintCard(cardArr[i]);
		cout << endl;
	}

	int playerCard = cardArr[0];
	int comCard = cardArr[1];
	cout << "PlayerCard: ";
	PrintCard(playerCard);
	cout << endl;
	cout << "ComCard: ";
	PrintCard(comCard);
	cout << endl;

	// check card %13
	// check card /13
	if (playerCard % 13 +1> comCard % 13+1)
	{
		cout << "Player Win" << endl;
	}
	else if (playerCard % 13+1 < comCard % 13+1)
	{
		cout << "Com Win" << endl;
	}
	else
	{
		if (playerCard / 13 > comCard / 13)
		{
			cout << "Player Win" << endl;
		}
		else
		{
			cout << "Com Win" << endl;
		}
	}

	

}