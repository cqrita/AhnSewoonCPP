#include "stdafx.h"


class NumberInt
{
public:
	int _number;
	void Init(int number);
	void Release();
};

void NumberInt::Init(int number)
{
	_number = number;
}
void NumberInt::Release()
{

}


class NumberFloat
{
public:
	int _number;
	void Init(int number);
	void Release();
};

void NumberFloat::Init(int number)
{
	_number = number;
}
void NumberFloat::Release()
{

}

template <typename Data>
class Number
{
public:
	Data _number;
	void Init(Data number);
	void Release();

	Number<Data> operator+(Number<Data> otherNumber);
	Number<Data> operator-(Number<Data> otherNumber);
	Number<Data> operator*(Number<Data> otherNumber);
	Number<Data> operator/(Number<Data> otherNumber);
};
template <typename T>
void Number<T>::Init(T number)
{
	_number = number;
}

template <typename T>
void Number<T>::Release()
{
}

template <typename Data>
Number<Data> Number<Data>::operator+(Number<Data> otherNumber)
{
	Number<Data> returnValue;
	Data number = this->_number + otherNumber._number;
	returnValue.Init(number);
	return returnValue;
}
template <typename T>
Number<T> Number<T>::operator-(Number<T> otherNumber)
{
	Number<T> returnValue;
	T number = this->_number - otherNumber._number;
	returnValue.Init(number);
	return returnValue;
}
template <typename T>
Number<T> Number<T>::operator*(Number<T> otherNumber)
{
	Number<T> returnValue;
	T number = this->_number * otherNumber._number;
	returnValue.Init(number);
	return returnValue;
}
template <typename T>
Number<T> Number<T>::operator/(Number<T> otherNumber)
{
	Number<T> returnValue;
	T number = this->_number / otherNumber._number;
	returnValue.Init(number);
	return returnValue;
}


void main()
{
	// template
	NumberInt myNum1;
	myNum1.Init(2.5);
	cout << myNum1._number << endl;
	int type;
	cout << "input type int(0) double(1) : ";
	cin >> type;
	double inNum1,inNum2;
	int inFun;
	cout << "input num1 : ";
	cin >> inNum1;
	cout << "input num2 : ";
	cin >> inNum2;
	cout << "input function +(0) -(1) *(2) /(3) : ";
	cin >> inFun;
	
	if (type == 0)
	{
		Number<int> num1, num2, num3;
		num1.Init(inNum1);
		num2.Init(inNum2);
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
	else
	{
		Number<double> num1, num2, num3;
		num1.Init(inNum1);
		num2.Init(inNum2);
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
	
	
	
}