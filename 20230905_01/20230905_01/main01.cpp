#include "stdafx.h"
#include <vector>
#define SAFE_DELETE(p) {if(p) {delete p; p=nullptr;}}
#define SAFE_DELETE_ARRAY(pArr) {if(pArr){ delete[] pArr; pArr=nullptr;}}
#define SAFE_RELEASE(p) {if(p) {p->Release();}}

template <typename Data>
class MyVector
{
public:
	Data* _arr;
	//vector size
	int _size;
	//arr size
	int _capacity;

	MyVector()
	{
		_arr = new Data[1]{ };
		_size = 0;
		_capacity = 1;
	}
	~MyVector()
	{
		SAFE_DELETE_ARRAY(_arr);
		_size = 0;
		_capacity = 0;
	}
	void push_back(Data data)
	{
		// size++
		// if _capacity < _size
		// new arr
		// copy arr
		// add value
		_size++;
		if (_capacity < _size)
		{
			_capacity = _size * 2;
			Data* newArr = new Data[_capacity] {};
			for (int i = 0; i < _size - 1; i++)
			{
				newArr[i] = _arr[i];
			}
			SAFE_DELETE_ARRAY(_arr);
			_arr = newArr;
		}
		_arr[_size - 1] = data;
	}
	void pop_back()
	{
		_size--;
	}
	int size()
	{
		return _size;
	}
	Data at(int index)
	{
		return _arr[index];
	}
	Data operator [](int index)
	{
		return this->at(index);
	}
};
void main()
{
	//vector
	vector<int> myVec;
	myVec.push_back(1);
	myVec.push_back(2);
	myVec.push_back(3);
	for (int i = 0; i < myVec.size(); i++)
	{
		cout << myVec[i] << endl;
	}
	myVec.pop_back();
	cout << "Last index : " << myVec.at(myVec.size() - 1) << endl;

	MyVector<double> myVec1;
	myVec1.push_back(1.1);
	myVec1.push_back(2.1);
	myVec1.push_back(3.1);
	for (int i = 0; i < myVec1.size(); i++)
	{
		cout << myVec1[i] << endl;
	}
	myVec1.pop_back();
	cout << "Last index : " << myVec1[myVec1.size() - 1] << endl;
}
