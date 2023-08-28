#include <iostream>
//Console 관련된 헤더
#include <Windows.h>

//콘솔에서의 키보드 관련된 헤더
#include <conio.h> // console input output
using namespace std;

void Gotoxy(int x, int y)
{

	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetCursor(bool isShow)
{
	CONSOLE_CURSOR_INFO cursorInfo;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (isShow)
	{
		cursorInfo.bVisible = TRUE;
		cursorInfo.dwSize = 10;
	}
	else
	{
		cursorInfo.bVisible = FALSE;
		cursorInfo.dwSize = 10;
	}

	SetConsoleCursorInfo(hConsole, &cursorInfo);
}
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
	
	int y = 1;
	int currentArrow = 0;
	while (pGold > 0&&num<48)
	{
		SetCursor(true);
		Gotoxy(5, 1);
		int cur[5];
		for (int i = 0; i < 5; i++)
		{
			cur[i] = num;
			num++;
		}
		cout << "current gold : " << pGold<<endl;
		Gotoxy(5, 2);
		for (int i = 0; i < 4; i++)
		{
			PrintCard(cur[i]);
		}
		cout << endl;
		Gotoxy(5, 3);
		cout << "set betting gold : ";
		int betting;
		cin >> betting;
		pGold=pGold - betting;
		system("cls");
		SetCursor(false);
		bool screenFlag=true;
		while (screenFlag)
		{
			y = 1;
			//ㅂ 한자 3 ㅂ 한자 ─
			Gotoxy(5, y++);
			cout << "┌───────────────────────────────────────";
			Gotoxy(5, y++);
			cout << "│  ";
			cout << "current gold : "<<pGold;
			Gotoxy(5, y++);
			cout << "│  ";
			cout << "betting gold : " << betting;
			Gotoxy(5, y++);
			cout << "│  ";
			for (int i = 0; i < 4; i++)
			{
				PrintCard(cur[i]);
			}
			Gotoxy(5, y++);
			cout << "│  ";
			if (currentArrow == 0)
			{
				cout << "▷▶ 하이";
			}
			else
			{
				cout << "     하이";
			}
			Gotoxy(5, y++);
			cout << "│  ";
			if (currentArrow == 1)
			{
				cout << "▷▶ 로우";
			}
			else
			{
				cout << "     로우";
			}
			Gotoxy(5, y++);
			cout << "│  ";
			if (currentArrow == 2)
			{
				cout << "▷▶ 세븐";
			}
			else
			{
				cout << "     세븐";
			}
			Gotoxy(5, y++);
			cout << "└───────────────────────────────────────";


			//_kbhit() => 키보드 입력받을 때 들어오는 함수.
			if (_kbhit())
			{
				system("cls");
				//_getch() =>  어떤키가 눌렸는지 알려주는 함수.
				char ch = _getch();
				switch (ch)
				{
					//w키를 눌렀을때.
				case 'w':
					currentArrow--;
					if (currentArrow < 0)
					{
						currentArrow = 0;
					}
					break;
					//s키를 눌렀을때.
				case 's':
					currentArrow++;

					if (currentArrow > 2)
					{
						currentArrow = 2;
					}
					break;

				case 13:
					if (currentArrow == 0)
					{
						Gotoxy(0, 10);
						cout << "하이를 골랐습니다."<<endl;
						cout << "The card was : ";
						PrintCard(cur[4]);
						if (cur[4] % 13 + 1 > 7)
						{
							pGold = pGold + betting * 2;
						}
						screenFlag = false;
						cout << endl;
						system("pause");
					}
					else if (currentArrow == 1)
					{
						Gotoxy(0, 10);
						cout << "로우를 골랐습니다." << endl;
						cout << "The card was : ";
						PrintCard(cur[4]);
						if (cur[4] % 13 + 1 < 7)
						{
							pGold = pGold + betting * 2;
						}
						screenFlag = false;
						cout << endl;
						system("pause");
					}
					else if (currentArrow == 2)
					{
						Gotoxy(0, 10);
						cout << "세븐을 골랐습니다."<<endl;
						cout << "The card was : ";
						PrintCard(cur[4]);
						if (cur[4] % 13 + 1 == 7)
						{
							pGold = pGold + betting * 2;
						}
						screenFlag = false;
						cout << endl;
						system("pause");
					}
					break;
				default:
					break;
				}
			}

		}
	}
}
//1. bingo
//2. high low seven