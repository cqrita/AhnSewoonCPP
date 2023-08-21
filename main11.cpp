#include <iostream>
#include <time.h>
using namespace std;
void main()
{
	srand(time(NULL));
	//
	// make array to 45
	// for i to 7
	//	pick rand to 45-i
	//	swap postion with 45-i
	//	print
	// 
	//
	int arr[45];
	for (int i = 0; i < 45; i++)
	{
		arr[i] = i + 1;
	}
	for (int i = 0; i < 7; i++)
	{
		int randNum = rand() % (45 - i);
		cout << arr[randNum]<<endl;
		arr[randNum] = arr[44 - i];
	}
}