#include <iostream>
using namespace std;
int _myHand = 0;
int _comHand = 0;
void PrintRockScissorPaper(int hand)
{
	switch (hand)
	{
	case 0:
		cout << "scissors" << endl;
		break;
	case 1:
		cout << "rock" << endl;
		break;
	case 2:
		cout << "paper" << endl;
		break;
	}
}
void main()
{
	srand(time(NULL));
	//2. function
	// module

	//PrintRockScissorPaper

	//datatype function(parameter)
	//{

	//}
	cout << "input hand 0 scissors 1 rock 2 paper" << endl;
	cin >> _myHand;
	cout << "my Hand : ";
	PrintRockScissorPaper(_myHand);
	_comHand = rand() % 3;
	cout << "com Hand : ";

	PrintRockScissorPaper(_comHand);


}