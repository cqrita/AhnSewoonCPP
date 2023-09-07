#include "stdafx.h"
#include <string>
MainGame* _mainGame = nullptr;

void main()
{
	//string
	string str = "string";
	str = "23";
	//c style
	char name[250] = "string";
	//name = "mystring"
	//pointer != string
	strcpy_s(name, "myString");
	cout << name << endl;
	str = "Hello World";
	//string vector 

	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
	}
	str = "ÇÑ±Û";
	//string vector 
	cout << endl;
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
	}
	str = "Hello World";
	cout << endl;
	cout << endl;
	for (auto iter = str.begin(); iter < str.end(); iter++)
	{
		if (iter != str.begin())
		{
			if (*iter != *(iter - 1))
			{
				cout << *iter;
			}
		}
		else
		{
			cout << *iter;
		}
	}
	cout << endl;
	for (auto iter = str.rbegin(); iter < str.rend(); iter++)
	{
		cout << *iter;
	}
}