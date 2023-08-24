#include <iostream>
using namespace std;

void PlusOne1(int variable)
{
	variable++;
}

void PlusOne2(int& variable)
{
	variable++;
}


void main()
{
	//reference
	int a = 3;
	PlusOne1(a);
	cout << "a : " << a << endl;
	int b = 3;
	PlusOne2(b);
	cout << "b : " << b << endl;

}