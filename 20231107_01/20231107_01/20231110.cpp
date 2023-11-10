#include <iostream>
#include <string>
#include "StringUtility.h"
using namespace std;
int myStrlen(char* str)
{
	int size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	return size;
}
char* myStrcat(char* str1, char* str2)
{
	int i = strlen(str1);
	int j = 0;
	while (str2[j] != '\0')
	{
		str1[i] = str2[j];
		i++;
		j++;
	}
	str1[i] = '\0';
	return str1;
}
int myStrcmp(char* str1, char* str2)
{
	int str1len = strlen(str1);
	int str2len = strlen(str2);
	if (str1len != str2len)
	{
		return 1;
	}
	for (int i = 0; i < str1len; i++)
	{
		if (str1[i] == str2[i])
		{
			continue;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
void main()
{
	char str[5] = "0123";
	cout << str << endl;
	cout << strlen(str) << endl;
	cout << myStrlen(str) << endl;
	char cat1[128] = "1234";
	char cat2[10] = "55";
	strcat_s(cat1, cat2);
	cout<<myStrcat(cat1, cat2)<<endl;
	auto vec=Split("동해물과 백두산이 마르고 닳도록", ' ');
	for (string str : vec)
	{
		cout << str<<endl;
	}
}