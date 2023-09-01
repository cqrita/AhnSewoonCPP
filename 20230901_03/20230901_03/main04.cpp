#include <iostream>
#include <vector>

using namespace std;
void main()
{
	//data structure

	vector<int> myVec;
	for (int i = 0; i < 10; i++)
	{
		myVec.push_back(i);
	}
	for (int i = 0; i < myVec.size(); i++)
	{
		cout << myVec[i] << endl;
	}
	cout << endl;
	myVec.pop_back();
	for (int i = 0; i < myVec.size(); i++)
	{
		cout << myVec[i] << endl;
	}

}