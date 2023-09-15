#include <iostream>
using namespace std;

namespace SBS
{
	void Test()
	{
		cout << "SBS TEST" << endl;
	}
}
namespace MyCode
{
	void Test()
	{
		cout << "MyCode TEST" << endl;
	}
}

using namespace MyCode;
void main()
{
	//namespace
	SBS::Test();
	cout << "Hello" << endl;
	MyCode::Test();
	Test();
	//using namespace
}