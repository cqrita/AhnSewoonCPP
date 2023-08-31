#include <iostream>
using namespace std;
void main()
{
	//1. pointer -array
	//*, &
	//*
	//&

	int** a=nullptr;

	int arr[52] = { 0 };
	int* ptr = arr;

	cout << "arr : " << arr << endl;
	cout << "ptr : " << ptr << endl;


	for (int i = 0; i < 52; i++)
	{
		arr[i] = i;
	}
	cout << "arr[0] : " << arr[0] << endl;
	cout << "arr[1] : " << arr[1] << endl;

	cout << "*ptr : " << *ptr << endl;
	cout << "*(ptr + 1) : " << *(ptr + 1) << endl;
	cout << "*(ptr + 2) : " << *(ptr + 2) << endl;
	for (int i = 0; i < 52; i++)
	{
		cout << "*(ptr+"<<i<<") : " << *(ptr + i) << endl;
	}
	for (int i = 0; i < 52; i++)
	{
		cout << "ptr[i] : " << ptr[i] << endl;
	}

}