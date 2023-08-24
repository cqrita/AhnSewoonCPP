#include <iostream>
#include <time.h>
using namespace std;

int _answer[4] = {};
int _input[4] = {};
int _strike = 0;
int _ball = 0;

bool IsValidation(int arr[])
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
	// 1. number baseball
	// pseudo code
	// 1
	// com number answer[4]
	// answer[0] ~ answer[3] random
	// if dup repeat
	// 2. player input
	// player input input[4]
	// input[0]~input[3]
	// 
	// 3.answer for loop
	//	input for loop
	//		if answer[i]==input[j]
	//			if i==j
	//				strike++
	//			else
	//				ball++
	// 
	// 
	// 4. strike ball print
	// 
	// 
	
	srand(time(NULL));
	bool isValidation;
	do
	{
		for (int i = 0; i < 4; i++)
		{
			if (i == 0)
			{
				_answer[i] = rand() % 9 + 1;
			}
			else
			{
				_answer[i] = rand() % 10;
			}
		}
		isValidation = IsValidation(_answer);

	} while (isValidation == false);
	cout << _answer[0] << _answer[1] << _answer[2] << _answer[3] << endl;
	while (true)
	{


		int temp;
		do
		{
			cout << "input number : ";
			cin >> temp;
			_input[0] = temp / 1000;
			_input[1] = temp / 100 % 10;
			_input[2] = temp / 10 % 10;
			_input[3] = temp % 10;
			isValidation = IsValidation(_input);
		} while (isValidation == false);
		cout << _input[0] << _input[1] << _input[2] << _input[3] << endl;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (_answer[i] == _input[j])
				{
					if (i == j)
					{
						_strike++;
					}
					else
					{
						_ball++;
					}
				}
			}
		}
		cout << "Strike : " << _strike << endl;
		cout << "Ball : " << _ball << endl;
		if (_strike == 4)
		{
			cout << "Game End" << endl;
			break;
		}
	}

}