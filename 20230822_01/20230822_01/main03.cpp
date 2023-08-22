#include <iostream>
#include <time.h>
using namespace std;
void main()
{
	srand(time(NULL));

	//lottery
	//1~45 array
	// array shuffle
	// pick seven
	// lotto[0] ~lotto[6]
	int lotto[45] = {0,};
	//array initialize
	//array for
	//
	// int lotto[45]={0.};
	// int lotto[45]{};
	// int lotto[45]={};
	//
	for (int i = 0; i < 45; i++)
	{
		lotto[i] = i + 1;
	}
	for (int i = 0; i < 1000000; i++)
	{
		int num1 = rand() % 45;
		int num2 = rand() % 45;

		int temp = lotto[num1];
		lotto[num1] = lotto[num2];
		lotto[num2] = temp;
	}
	for (int i = 0; i < 7; i++)
	{
		cout << lotto[i] << endl;
	}
}