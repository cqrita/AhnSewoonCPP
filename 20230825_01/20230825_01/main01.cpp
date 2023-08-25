#include <iostream>
using namespace std;
bool validation(int arr[])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i != j)
			{
				if (arr[i] == arr[j])
				{
					return false;
				}
			}
		}
	}
	return true;
}
void main()
{
	srand(time(NULL));
	int com[4];
	int input[4];
	bool valid = false;
	do
	{
		for (int i = 0; i < 4; i++)
		{
			if (i == 0)
			{
				com[i] = rand() % 9 + 1;
			}
			else
			{
				com[i] = rand() % 10;
			}
		}
		valid = validation(com);
	} while (valid == false);
	cout << com[0] << com[1] << com[2] << com[3] << endl;
	while (true)
	{
		valid = false;
		do
		{
			int temp;
			cout << "input num : ";
			cin >> temp;
			input[0] = temp/1000;
			input[1] = temp / 100 % 10;
			input[2] = temp / 10 % 10;
			input[3] = temp % 10;
			valid = validation(input);
		} while (valid == false);
		int strike = 0;
		int ball = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (input[i] == com[j])
				{
					if (i == j)
					{
						strike++;
					}
					else
					{
						ball++;
					}
				}
			}
		}
		cout << "strike : " << strike << endl;
		cout << "ball : " << ball << endl;
		if (strike == 4)
		{
			cout << "game end" << endl;
			break;
		}
	}
}