#include <iostream>
#include <Windows.h>

using namespace std;
class MainGame
{

};
void main()
{
	//pointer array dynamic allocation

	int* myNumber = new int(3);
	delete myNumber;
	myNumber = nullptr;

	MainGame* mainGame = new MainGame();
	delete mainGame;
	mainGame = nullptr;

	//array dynamic allocation
	int input;
	cout << "input number";
	cin >> input;
	//int arr[input] = { 0, };
	int* ptrArr = new int[input] {0, };
	for (int i = 0; i < input; i++)
	{
		ptrArr[i] = i;
	}
	int arr[52] = { 0, };
	for (int i = 0; i < 52; i++)
	{
		*(arr + i) = i;
	}
	delete[] ptrArr;
}