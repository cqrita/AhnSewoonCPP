#include <iostream>
#include <vector>
using namespace std;
void main()
{
	//2. vector
	//dynamic size
	//vector
	//int arr[100]={};
	vector<int> myVec;
	myVec.push_back(0);
	myVec.push_back(10);
	myVec.push_back(20);
	//pushback
	for (int i = 0; i < myVec.size(); i++)
	{
		cout << "myVec[" << i << "] : " << myVec[i] << endl;
	}
	vector<float> myVec2;
	myVec2.push_back(1.5);
	myVec2.push_back(3.2);
	for (int i = 0; i < myVec2.size(); i++)
	{
		cout << "myVec2[" << i << "] : " << myVec[i] << endl;
	}
	int board[5][5] = { 0, };
	vector<vector<int>> myBoard;
	for (int i = 0; i < 5; i++)
	{
		vector<int> row;
		for (int j = 0; j < 5; j++)
		{
			row.push_back(i * 5 + j);
		}
		myBoard.push_back(row);
	}
}