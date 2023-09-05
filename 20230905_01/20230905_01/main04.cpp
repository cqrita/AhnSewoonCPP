#include"stdafx.h"

class Number
{
public:
	int _number;
	void Init(int number);
	void Release();
	Number operator+(Number otherNumber);
	Number operator-(Number otherNumber);
	Number operator*(Number otherNumber);
	Number operator/(Number otherNumber);
};

void Number::Init(int number)
{
	_number = number;
}
void Number::Release()
{

}
Number Number::operator+(Number otherNumber)
{
	Number returnValue;
	int number = this->_number + otherNumber._number;
	returnValue.Init(number);
	return returnValue;
}
Number Number::operator-(Number otherNumber)
{
	Number returnValue;
	int number = this->_number - otherNumber._number;
	returnValue.Init(number);
	return returnValue;
}
Number Number::operator*(Number otherNumber)
{
	Number returnValue;
	int number = this->_number * otherNumber._number;
	returnValue.Init(number);
	return returnValue;
}
Number Number::operator/(Number otherNumber)
{
	Number returnValue;
	int number = this->_number / otherNumber._number;
	returnValue.Init(number);
	return returnValue;
}
void main()
{
	//operator
	Number myNum1;
	myNum1.Init(5);
	Number myNum2;
	myNum2.Init(3);
	Number myNum3 = myNum1 + myNum2;
	cout << myNum3._number << endl;


	Number num1, num2, num3;
	int inNum;
	int inFun;
	cout << "input num1 : ";
	cin >> inNum;
	num1.Init(inNum);
	cout << "input num2 : ";
	cin >> inNum;
	num2.Init(inNum);
	cout << "input function +(0) -(1) *(2) /(3) : ";
	cin >> inFun;
	switch (inFun)
	{
	case 0:
		num3 = num1 + num2;
		cout << num1._number << " + " << num2._number << " = " << num3._number << endl;
		break;
	case 1:
		num3 = num1 - num2;
		cout << num1._number << " - " << num2._number << " = " << num3._number << endl;
		break;
	case 2:
		num3 = num1 * num2;
		cout << num1._number << " * " << num2._number << " = " << num3._number << endl;
		break;
	case 3:
		num3 = num1 / num2;
		cout << num1._number << " / " << num2._number << " = " << num3._number << endl;
		break;
	default:
		break;
	}
}