#include "stdafx.h"
#include <vector>
void main()
{
	vector<int> myVec;
	for (int i = 0; i < 10; i++)
	{
		myVec.push_back(i + 1);
	}
	for (int i = 0; i < myVec.size(); i++)
	{
		cout << myVec[i] << endl;
	}
	//itreator
	//auto 
	cout << endl;

	for (auto iter = myVec.begin(); iter < myVec.end(); iter++)
	{
		cout << *iter << endl;
	}
	cout << endl;
	for (auto iter = myVec.rbegin(); iter < myVec.rend(); iter++)
	{
		
		cout << *iter << endl;
	}
	cout << endl;

	//copy
	for (int number : myVec)
	{
		cout << number << endl;
	}
	cout << endl;

	//reference
	for (int& number : myVec)
	{
		cout << number << endl;
	}
	cout << endl;

	myVec.pop_back();
	auto iter = myVec.begin();
	myVec.erase(iter + 3);
	for (int i = 0; i < myVec.size(); i++)
	{
		cout << myVec[i] << endl;
	}

}