#include "stdafx.h"

class Unit
{
public:

	Unit()
	{
		cout << "constructor" << endl;
	}
	~Unit()
	{
		cout << "destructor" << endl;
	}
	void Init()
	{
		cout << "Unit::Init()" << endl;
	}
	void Release()
	{
		cout << "Unit::Release()" << endl;
	}

};


void main()
{
	//2.constructor 
	Unit* myUnit = new Unit();
	myUnit->Init();
	{
		Unit myUnit2;
		system("pause");
	}
	myUnit->Release();
	delete myUnit;
	myUnit = nullptr;


	//new delete
	//lazy initializtion


}