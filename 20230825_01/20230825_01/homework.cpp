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
	// 13~25 diamond ◆
	// 26~38 heart ♥
	// 38~51 clover ♣
	// 
	//
	for (int i = 0; i < 52; i++)
	{
		cardArr[i] = i;
	}
	for (int i = 0; i < 100000; i++)
	{
		int num1 = rand() % 52;
		int num2 = rand() % 52;
		int temp = cardArr[num1];
		cardArr[num1] = cardArr[num2];
		cardArr[num2] = temp;
	}
	int pGold = 1000;
	int num = 0;
	while (pGold > 0&&num<50)
	{
		cout << "current gold : " << pGold <<endl;
		PrintCard(cardArr[num]);
		num++;
		PrintCard(cardArr[num]);
		num++;
		PrintCard(cardArr[num]);
		num++;
		PrintCard(cardArr[num]);
		num++;
		cout << endl;
		num++;
	}
}
//1. bingo
//2. high low seven