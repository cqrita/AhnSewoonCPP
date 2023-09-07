#pragma once
class MainGame;
class Hand
{
	//MainGame을 가지고 올 수 있다면
	//2가지
	//여기서 MainGame을 가지고올수있는 방법
	//1. Hand에서 MainGame의 포인터를 들고있는다.
	//2. MainGame이 전역변수라면..
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