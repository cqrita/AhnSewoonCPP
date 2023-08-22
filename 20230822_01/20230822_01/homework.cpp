#include <iostream>
using namespace std;
void main()
{
	// homework
	// computer rand 4 comb no duplicates
	// repeat
	// if same place strike same num ball
	// 4 strike end

	// 0 to 9 fisher yeltz four times
	// get input /1000 -/1000 /100 -/1000 -/100 /10 %10
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

}