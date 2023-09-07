#include <iostream>

using namespace std;

//��������
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

	// �޸𸮱��� (4����)
	// Heap, Stack, Code, Data
	
	// Code ����
	//  - �츮�� ���� �ҽ��ڵ�
	
	// Data ���� (������� �ʴ� ������ �����ϴ� ��)
	//  - 1. ���� ����
	//  - 2. static ����

	// ��������
	// ���� �ٱ����� (�߰�ȣ�� ���� ���¿���) ��������

	// static ����
	// � �Լ�, Ŭ���� �� �ѹ� ����ǰ��� ��� ȣ��ɶ����� 
	// ���� �ν��Ͻ��� ȣ��ȴ�.


	for (int i = 0; i < 10; i++)
	{
		int myNum = GetMyNumber();
		cout << myNum << endl;
	}

}