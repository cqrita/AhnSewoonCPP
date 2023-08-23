#include <iostream>
using namespace std;
void main()
{
	// homework
	// computer rand 4 comb no duplicates
	// repeat
	// if same place strike same num ball
	// 4 strike end

	// 0 to 9 fisher shuffle algo four times
	// get input 
	// for i input
	//	for j com
	// if i==j in arr same strike else arr same ball
	// 4 strike break

	srand(time(NULL));
	int arr[10];
	int answer[4];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < 4; i++)
	{
		int temp = rand() % (10 - i);
		answer[i]=arr[temp];
		arr[temp] = arr[9 - i];
	}
	while (true)
	{
		char inputRaw[5];
		int input[4];
		cout << "give 4 number input: ";
		cin >> inputRaw;
		input[0] = inputRaw[0] - '0';
		input[1] = inputRaw[1] - '0';
		input[2] = inputRaw[2] - '0';
		input[3] = inputRaw[3] - '0';
		int strike = 0;
		int ball = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (input[i] == answer[j])
				{
					if (i == j)
					{
						strike = strike + 1;
					}
					else
					{
						ball = ball + 1;
					}
				}
			}
		}
		cout << "strike : " << strike << endl;
		cout << "ball : " << ball << endl;
		if (strike == 4)
		{
			cout << "you win" << endl;
			break;
		}
	}
}