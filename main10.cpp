#include <iostream>
using namespace std;
void main()
{
	// 1. 
	// for loop to 1000
	//	if 2% or 3% is zero but 6% is not zero 
	//		add to sum
	// 
	// 2. 
	// for i loop to 1000 
	//  for j loop to i
	//   if i%j is not zero for whole loop
	//		add to sum
	// no optimization
	// 
	//
	int sum1 = 0;

	for (int i = 1; i < 1001; i++)
	{
		if ((i % 2 == 0 || i % 3 == 0) && (i % 6 != 0))
		{
			sum1 = sum1 + i;
		}
	}
	cout << sum1 << endl;
	int sum2 = 0;
	bool flag;
	for (int i = 1; i < 1001; i++)
	{
		flag = false;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				flag = true;
			}
		}
		if (flag == false)
		{
			sum2 = sum2 + i;
		}
	}
	cout << sum2 << endl;

}