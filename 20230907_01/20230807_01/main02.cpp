#include <iostream>

using namespace std;

//전역변수
int _myVariable = 3;


int GetMyNumber()
{
	static int myNum = 0;
	myNum++;

	return myNum;
}

void main()
{
	//2. static

	// 메모리구조 (4종류)
	// Heap, Stack, Code, Data
	
	// Code 영역
	//  - 우리가 적은 소스코드
	
	// Data 영역 (사라지지 않는 변수를 저장하는 곳)
	//  - 1. 전역 변수
	//  - 2. static 변수

	// 전역변수
	// 가장 바깥에서 (중괄호가 없는 상태에서) 변수선언

	// static 변수
	// 어떤 함수, 클래스 등 한번 선언되고나면 계속 호출될때마다 
	// 같은 인스턴스가 호출된다.


	for (int i = 0; i < 10; i++)
	{
		int myNum = GetMyNumber();
		cout << myNum << endl;
	}

}