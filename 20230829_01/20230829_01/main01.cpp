#include <iostream>
using namespace std;

void makeTemp(int temp[])
{
	for (int i = 0; i < 25; i++)
	{
		temp[i] = i + 1;
	}
}
void randArr(int temp[], int arr[])
{
	for (int i = 0; i < 25; i++)
	{
		int num = rand() % (25 - i);
		arr[i] = temp[num];
		temp[num] = temp[24 - i];
	}
}
bool checkWin(int arr[])
{
	for (int i = 0; i < 5; i++)
	{
		bool check = true;
		for (int j = 0; j < 5; j++)
		{
			if (arr[i * 5 + j] != -1)
			{
				check = false;
			}
		}
		if (check == true)
		{
			return true;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		bool check = true;
		for (int j = 0; j < 5; j++)
		{
			if (arr[i + j * 5] != -1)
			{
				check = false;
			}
		}
		if (check == true)
		{
			return true;
		}
	}
	bool check = true;
	for (int i = 0; i < 5; i++)
	{
		if (arr[i * 5 + i] != -1)
		{
			check = false;
		}
	}
	if (check == true)
	{
		return true;
	}
	check = false;
	for (int i = 0; i < 5; i++)
	{
		if (arr[i * 5 + 4 - i] != -1)
		{
			check = false;
		}
	}
	if (check == true)
	{
		return true;
	}
}
void checkNum(int num,int arr[])
{
	for (int i = 0; i < 25; i++)
	{
		if(num==arr[i])
		{
			arr[i] = -1;
		}
	}
}
int comRand(int num, int temp[])
{
	
	int ran = rand() % (25 - num);
	temp[ran] = temp[24 - num];
	return ran;
}
void printArr(int arr[])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[i * 5 + j] == -1)
			{
				cout << "#" << '\t';
			}
			else
			{
				cout << arr[i * 5 + j] << '\t';
			}
		}
		cout << endl;
	}
}
void main()
{
	srand(time(NULL));
	int play[25];
	int com[25];
	int temp[25];
	makeTemp(temp);
	randArr(temp, play);
	makeTemp(temp);
	randArr(temp, com);
	int num = 0;
	cout << "player" << endl;
	printArr(play);
	cout << endl;
	cout << "com" << endl;
	printArr(com);
	while (true)
	{
		int input;
		cout << "input num : ";
		cin >> input;
		checkNum(input, play);
		checkNum(input, com);
		cout << "player" << endl;
		printArr(play);
		cout << endl;
		cout << "com" << endl;
		printArr(com);
		if (checkWin(play))
		{
			cout << "player win" << endl;
			break;
		}
		if (checkWin(com))
		{
			cout << "com win" << endl;
			break;
		}
		system("pause");
		int ran = comRand(num, temp);
		num++;
		checkNum(ran, play);
		checkNum(ran, com);
		cout << "player" << endl;
		printArr(play);
		cout << endl;
		cout << "com" << endl;
		printArr(com);
		if (checkWin(play))
		{
			cout << "player win" << endl;
			break;
		}
		if (checkWin(com))
		{
			cout << "com win" << endl;
			break;
		}
	}
}