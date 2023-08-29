#include <iostream>
using namespace std;
void main()
{
	//pointer

	int a = 3;
	cout << a << endl;

	//int* int ptr
	int* aPtr = &a;


	cout << "aPtr : " << aPtr << endl;

	cout <<"a " << a << endl;
	cout <<"&a " << &a << endl;
	cout <<"aPtr " << aPtr << endl;
	cout <<"*aPtr " << *aPtr << endl;

	cout << sizeof(aPtr) << endl;

	int** aPtrPtr = &aPtr;
	cout << "aPtrPtr " << aPtrPtr << endl;
	cout << "*aPtrPtr " << *aPtrPtr << endl;
	cout << "**aPtrPtr " << **aPtrPtr << endl;

}