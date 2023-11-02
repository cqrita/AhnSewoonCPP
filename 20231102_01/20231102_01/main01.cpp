#include <iostream>
using namespace std;
int main()
{
	//monster 1
	//mushroom 2
	//star 3
	//character 4
	unsigned int colliderCheckLayer1=0b0111;
	unsigned int colliderCheckLayer2=0b1001;
	unsigned int colliderLayerMonster = 0b1;
	unsigned int colliderLayerMushroom = 0b10;
	unsigned int colliderLayerStar = 0b100;
	unsigned int colliderLayerCharacter = 0b1000;
	//& , | , ~ , << , >>
	if (colliderCheckLayer1 & colliderLayerCharacter)
	{

	}
	unsigned int a = -1;
	cout << a << endl;

	//0x
	unsigned int b = 0xffffffff;
	cout << b << endl;
	int c = 0xfffffff;
	cout << c << endl;



}