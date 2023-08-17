#include <iostream>
#include <time.h>

using namespace std;

void main()
{
	/// <summary>
	/// group by 3 
	/// for i 1 4
	///  for j
	/// 
	///       4 7
	/// 
	/// 
	///       7 9
	/// 
	/// 
	/// </summary>

	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			cout << j << " * " << i << " = " << i * j<<"\t";
		}
		cout << endl;
	}
}