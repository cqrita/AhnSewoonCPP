#include <iostream>
using namespace std;
void Swap1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}
void Swap2(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void Swap3(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void main()
{
	//3. pointer function
	int num1 = 10;
	int num2 = 20;
	cout << num1 << ' ' << num2 << endl;
	Swap1(num1, num2);
	cout << num1 << ' ' << num2 << endl;
	Swap2(&num1, &num2);
	cout << num1 << ' ' << num2 << endl;
	Swap3(num1, num2);
	cout << num1 << ' ' << num2 << endl;



}