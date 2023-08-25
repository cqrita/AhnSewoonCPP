#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
void Gotoxy(int x, int y)
{
	COORD pos{ x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void main()
{
	while (true)
	{
		Gotoxy(10, 3);
		cout << "안녕하세요" << endl;
		int currentArrow = 0;
		int y = 1;
		Gotoxy(5, y++);
		cout << "┌──────────────────────────┐";
		Gotoxy(5, y++);
		cout << "│                          │";
		Gotoxy(5, y++);
		cout << "│                          │";
		Gotoxy(5, y++);
		cout << "│                          │";
		Gotoxy(5, y++);
		cout << "│                          │";
		Gotoxy(5, y++);
		cout << "│                          │";
		Gotoxy(5, y++);
		cout << "└──────────────────────────┘";

		system("pause");
		if (_kbhit())
		{
			cout << "키보드 입력받음";
			char ch = _getch();
			switch (ch)
			{
			case 'w':
			case 's':

			default:
				break;
			}
		}
		Sleep(500);
	}
}