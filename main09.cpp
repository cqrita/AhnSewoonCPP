#include <iostream>
#include <time.h>

using namespace std;

void main()
{
	/// <summary>
	/// 1.
	/// two loops
	/// i *j = i*j
	/// for i
	///		for j
	/// 2.
	/// group by 3 
	/// 2 loops 
	/// i *j = i*j 
	///	for i
	///		for j      
	/// three times
	/// 
	///      
	/// 
	/// 
	/// </summary>
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout << i << " * " << j << " = " << i * j << "\t";
			cout << endl;

		}
	}
	cout << endl;

	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			cout << j << " * " << i << " = " << i * j<<"\t";
		}
		cout << endl;
		
	}
	for (int i = 1; i < 10; i++)
	{	
		for (int j = 4; j < 7; j++)
		{
			cout << j << " * " << i << " = " << i * j << "\t";
		}
		cout << endl;
	}

	for (int i = 1; i < 10; i++)
	{
		for (int j = 7; j < 10; j++)
		{
			cout << j << " * " << i << " = " << i * j << "\t";
		}
		cout << endl;
	}
}