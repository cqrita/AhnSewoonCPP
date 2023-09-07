#include "stdafx.h"

MainGame* _mainGame = nullptr;
//���� ����
//��ü 5��Ģ
//ù ��°��
//����å�ӿ�Ģ
//�ϳ��� Ŭ�������� �������� ���� ���� ���ƶ�
//�ϳ��� �ӹ��� �����

//Hand
// -> ��
//  => SetHand(int hand) (���� ����� ����)
//  => GetHand() (���� ����� �´���)
//MainGame
// => �������������� ��
//		SetHands(); ��ǻ�ʹ� �������� ����.
//		SetHands(); ������ �Է¹��� ���� ����.
//		ShowHands(); ���� ������ �´��� UI�� ����Ѵ�.
//		ShowResult(); ���� �̰���� UI�� �����ش�.



void main() 
{
	srand(time(NULL));
	//5. ���������� classȭ
	_mainGame = new MainGame();
	_mainGame->Init();

	while (false == _mainGame->IsGameEnd())
	{
		_mainGame->Update();
	}

	_mainGame->Release();
	delete _mainGame;
	_mainGame = nullptr;

}