#include <iostream>
using namespace std;
void main()
{
	//3. 1~1000

	int sum = 0;
	for (int i = 1; i <= 1000; i++)
	{
		if (i % 2 == 0 || i % 3 == 0)
		{
			if (i % 6 != 0)
			{
				sum += 1;
			}
		}
	}
	cout << "sum : " << sum << endl;
}