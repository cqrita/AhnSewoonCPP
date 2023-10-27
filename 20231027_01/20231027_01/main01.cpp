#include <iostream>
#include <vector>
#include <functional>
using namespace std;
void Call()
{
	cout << "function" << endl;
}
class Actor
{
public:
	void Call2()
	{
		cout << "call2" << endl;
	}
};
class Player :public Actor
{
public:
	void Call()
	{
		cout << "call" << endl;
	}
};
void main()
{
	
}