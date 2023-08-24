#include <iostream>
using namespace std;

void makeTemp(int temp[])
{
	for (int i = 1; i <= 25; i++)
	{
		temp[i - 1] = i;
	}
}
void fillBoard(int temp[],int board[5][5])
{
	int num = 25;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int ran = rand() % num;
			board[i][j] = temp[ran];
			temp[ran] = temp[num - 1];
			num--;
		}
	}
}
int randNum(int temp[],int& num)
{
	int ran = rand() % num;
	temp[ran] = temp[num - 1];
	num--;
	return ran;
}
void printBoard(int board[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (board[i][j] == 0)
			{
				cout << '#' << '\t';
			}
			else
			{
				cout << board[i][j] << '\t';
			}
		}
		cout << endl;
	}
}
bool checkBingo(int board[5][5])
{
	bool bingo = false;
	for (int i = 0; i < 5; i++)
	{
		int start=0;
		bool tempBingo = true;
		for (int j = 0; j < 5; j++)
		{
			if (j == 0)
			{
				int start = board[i][j];
			}
			else
			{
				if (board[i][j] != start)
				{
					tempBingo = false;
				}
			}
		}
		if (tempBingo == true)
		{
			bingo = true;
			return bingo;
		}
	}
	for (int j = 0; j < 5; j++)
	{
		int start = 0;
		bool tempBingo = true;
		for (int i = 0; i < 5; i++)
		{
			if (i == 0)
			{
				int start = board[i][j];
			}
			else
			{
				if (board[i][j] != start)
				{
					tempBingo = false;
				}
			}
		}
		if (tempBingo == true)
		{
			bingo = true;
			return bingo;
		}
	}
	int start = 0;
	bool tempBingo = true;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == j)
			{
				if (i == 0)
				{
					start = board[i][j];
				}
				else
				{
					if (start != board[i][j])
					{
						tempBingo = false;
					}
				}
			}
		}
	}
	if (tempBingo == true)
	{
		bingo = true;
		return bingo;

	}
	start = 0;
	tempBingo = true;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i+j==5)
			{
				if (i == 5)
				{
					start = board[i][j];
				}
				else
				{
					if (start != board[i][j])
					{
						tempBingo = false;
					}
				}
			}
		}
	}
	if (tempBingo == true)
	{
		bingo = true;
		return bingo;

	}
	start = 0;
	tempBingo = true;

}
void inputNum(int input,int board[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (board[i][j] == input)
			{
				board[i][j] = 0;
			}
		}
	}
}
void main()
{
	// bingo game
	// player com
	// take turns

	//fillBoard
	//printBoard
	//getinput
	//getrand
	//checkbingo
	//repeat
	srand(time(NULL));

	int play[5][5];
	int com[5][5];

	int temp[25];
	makeTemp(temp);
	fillBoard(temp, play);
	makeTemp(temp);
	fillBoard(temp, com);
	cout << "player Board" << endl;
	printBoard(play);
	cout << "com Board" << endl;
	printBoard(com);
	makeTemp(temp);
	int num = 25;
	while (true)
	{
		cout << "my turn" << endl;
		int input;
		cout << "input num : ";
		cin >> input;
		inputNum(input, play);
		inputNum(input, com);

		cout << "player Board" << endl;
		printBoard(play);
		cout << "com Board" << endl;
		printBoard(com);

		if (checkBingo(play))
		{
			cout << "player win" << endl;
			break;
		}
		else if (checkBingo(com))
		{
			cout << "com win" << endl;
			break;
		}

		cout << "com turn" << endl;
		input = randNum(temp, num);
		inputNum(input, play);
		inputNum(input, com);

		cout << "player Board" << endl;
		printBoard(play);
		cout << "com Board" << endl;
		printBoard(com);

		if (checkBingo(play))
		{
			cout << "player win" << endl;
			break;
		}
		else if (checkBingo(com))
		{
			cout << "com win" << endl;
			break;
		}
	}
}