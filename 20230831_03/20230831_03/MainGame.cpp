#include "stdafx.h"
#include "Player.h"
#include "MainGame.h"
MainGame::MainGame()
{
	player = new Player();
	com = new Player();
	Init();
}
MainGame::~MainGame()
{
	delete player;
	player = nullptr;
	delete com;
	com = nullptr;
	Release();
}
void MainGame::Init()
{
	srand(time(NULL));
	turn = 0;
}

void MainGame::Update()
{
	if (turn<2)
	{
		int y = 1;
		int currentArrow = 0;
		CustomConsole.SetCursor(tvision::CURSOR_OFF);
		while (turn<2)
		{
			y = 1;
			//ㅂ 한자 3 ㅂ 한자 ─
			CustomConsole.GotoXY(5, y++);
			cout << "┌───────────────────────────────────────";
			CustomConsole.GotoXY(5, y++);
			cout << "│  ";
			if (turn == 0)
			{
				cout << "input Left Hand";
			}
			else
			{
				cout << "input Right Hand";
			}
			CustomConsole.GotoXY(5, y++);
			cout << "│  ";
			if (currentArrow == 0)
			{
				cout << "▷▶ ROCK";
			}
			else
			{
				cout << "     ROCK";
			}
			CustomConsole.GotoXY(5, y++);
			cout << "│  ";
			if (currentArrow == 1)
			{
				cout << "▷▶ SCISSORS";
			}
			else
			{
				cout << "     SCISSORS";
			}
			CustomConsole.GotoXY(5, y++);
			cout << "│  ";
			if (currentArrow == 2)
			{
				cout << "▷▶ PAPER";
			}
			else
			{
				cout << "     PAPER";
			}
			CustomConsole.GotoXY(5, y++);
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
						CustomConsole.GotoXY(0, y++);
						if (turn == 0)
						{
							player->hand1 = ROCK;
						}
						else
						{
							player->hand2 = ROCK;
						}
						if (turn < 2)
						{
							turn++;
						}

						cout <<"You Have Selected ROCK" << endl;
						system("pause");
					}
					else if (currentArrow == 1)
					{
						CustomConsole.GotoXY(0, y++);
						if (turn == 0)
						{
							player->hand1 = SCISSORS;
						}
						else
						{
							player->hand2 = SCISSORS;
						}
						if (turn < 2)
						{
							turn++;
						}
						cout << "You Have Selected SCISSORS" << endl;
						system("pause");
					}
					else if (currentArrow == 2)
					{
						CustomConsole.GotoXY(0, y++);
						if (turn == 0)
						{
							player->hand1 = PAPER;
						}
						else
						{
							player->hand2 = PAPER;
						}
						if (turn < 2)
						{
							turn++;
						}

						cout << "You Have Selected PAPER" <<turn<< endl;
						system("pause");
					}
					break;
				default:
					break;
				}
			}
		}
		com->hand1 = rand() % 3;
		com->hand2 = rand() % 3;
		system("cls");
		cout << "player hand" << endl;
		player->Update(turn);
		cout << "com hand" << endl;
		com->Update(turn);
	}
	else
	{
		int y = 0;
		int currentArrow = 0;
		CustomConsole.SetCursor(tvision::CURSOR_OFF);
		while (turn<3)
		{
			y = 15;
			//ㅂ 한자 3 ㅂ 한자 ─
			CustomConsole.GotoXY(5, y++);
			cout << "┌───────────────────────────────────────";
			CustomConsole.GotoXY(5, y++);
			cout << "│  ";
			cout << "select Left Right";
			CustomConsole.GotoXY(5, y++);
			cout << "│  ";
			if (currentArrow == 0)
			{
				cout << "▷▶ LEFT";
			}
			else
			{
				cout << "     LEFT";
			}
			CustomConsole.GotoXY(5, y++);
			cout << "│  ";
			if (currentArrow == 1)
			{
				cout << "▷▶ RIGHT";
			}
			else
			{
				cout << "     RIGHT";
			}
			CustomConsole.GotoXY(5, y++);
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

					if (currentArrow > 1)
					{
						currentArrow = 1;
					}
					break;

				case 13:
					if (currentArrow == 0)
					{
						CustomConsole.GotoXY(0, y++);
						player->select = LEFT;
						turn++;
						cout <<"You Have Selected LEFT" << endl;
						system("pause");
					}
					else if (currentArrow == 1)
					{
						CustomConsole.GotoXY(0, y++);
						player->select = RIGHT;
						turn++;
						cout << "You Have Selected RIGHT" << endl;
						system("pause");
					}
					break;
				default:
					break;
				}
			}
		}
		com->select = rand()%2;
		system("cls");
		cout << "player hand"<<endl;
		player->Update(turn);
		cout << "com hand" << endl;
		com->Update(turn);
		if ((player->last == ROCK && com->last == SCISSORS) || (player->last == SCISSORS && com->last == PAPER) || (player->last == PAPER && com->last == ROCK))
		{
			cout << "PLAYER WIN" << endl;
		}
		else if (player->last == com->last)
		{
			cout << "DRAW" << endl;
		}
		else
		{
			cout << "PLAYER LOSE" << endl;
		}
		turn++;
	}
}
void MainGame::Release()
{

}

bool MainGame::IsGameEnd()
{
	if (turn > 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}
