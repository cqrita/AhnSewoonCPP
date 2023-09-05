#include "stdafx.h"
#define MY_NUMBER 10
#define BRACKET_LEFT [
#define BRACKET_RIGHT ]
#define EQUAL =
#define ADD(a, b) a + b
#define MINUS(a,b) a-b
#define MULTIPLE(a,b) a*b
#define DIVIDE(a,b) a/b

#define SAFE_DELETE(p) {if(p) {delete p; p=nullptr;}}
#define SAFE_DELETE_ARRAY(pArr) {if(pArr){ delete[] pArr; pArr=nullptr;}}
#define SAFE_RELEASE(p) {if(p) {p->Release();}}

class Unit
{
public:
	int _hp;
	int _damage;
	void Init()
	{

	}
	void Release()
	{

	}
};

void main()
{
	//macro
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		arr BRACKET_LEFT i BRACKET_RIGHT EQUAL i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr BRACKET_LEFT i BRACKET_RIGHT << endl;
	}
	// macro functions
	cout << 1 << " + " << 2 << " = " << ADD(1, 2) << endl;
	double num1=0, num2=0;
	int fun;
	cout << "input num1 : ";
	cin >> num1;
	cout << "input num2 : ";
	cin >> num2;
	cout << "input function +(0) -(1) *(2) /(3) : ";
	cin >> fun;
	switch (fun)
	{
	case 0:
		cout << num1 << " + " << num2 << " = " << ADD(num1, num2) << endl;
		break;
	case 1:
		cout << num1 << " - " << num2 << " = " << MINUS(num1, num2) << endl;
		break;
	case 2:
		cout << num1 << " * " << num2 << " = " << MULTIPLE(num1, num2) << endl;
		break;
	case 3:
		cout << num1 << " / " << num2 << " = " << DIVIDE(num1, num2) << endl;
		break;
	default:
		break;
	}
	Unit* slime = new Unit();
	slime->Init();
	slime->Release();
	delete slime;
	if (slime)
	{
		cout << "in slime" << endl;
	}
	Unit* slime1 = new Unit();
	slime1->Init();
	slime1->Release();
	SAFE_DELETE(slime1);
	if (slime1)
	{
		cout << "in slime1" << endl;
	}
	//garbage value
	
	cout << slime << endl;
	cout << slime1 << endl;

	Unit* UnitList = new Unit[100]{};
	SAFE_DELETE_ARRAY(UnitList);

}