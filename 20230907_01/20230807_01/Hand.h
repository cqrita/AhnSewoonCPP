#pragma once
class MainGame;
class Hand
{
	//MainGame�� ������ �� �� �ִٸ�
	//2����
	//���⼭ MainGame�� ������ü��ִ� ���
	//1. Hand���� MainGame�� �����͸� ����ִ´�.
	//2. MainGame�� �����������..
private:
	int _hand;
public:
	void Init();
	void Release();
	void SetMyHand(int hand);
	void SetComHand();

	int GetHand();
	string GetHandName();
};