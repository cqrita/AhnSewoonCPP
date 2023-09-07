#include <iostream>

using namespace std;

class Unit
{
private:
	int _hp;
	int _defense;
	int _shield;
	int _damage;

public:
	void OnDamaged(int damage)
	{

	}

	void Heal()
	{
		this->_hp += 10;
	}
};

struct UnitData
{
public:
	int _hp;
	int _damage;

};

void main()
{
	//class 기초
	//class == struct
	//차이 없음.

	Unit unit;
	//unit._hp += 10;


	//private
	//  -> 자기자신만 사용 가능 (외부 허용x)
	//public
	//  -> 누구나 사용 가능 (외부 허용o)


	//private main문에서 사용불가능
	//public main문에서 사용가능

	//private는 사용안하는게 좋은거아닌가?

	// 클래스
	//  스파게티 코드
	//   --> A클래스에서 B클래스를 호출하는데
	//			B클래스에서 C클래스를 호출하고
	//			C클래스에서 A클래스를 호출해요

	//	A => B => C
	//	호출하는 방향은 한방향으로만 호출하는게 이상적인 구조
	//  

	//지금은 스파게티 코드를 많이 짜세요.

	//국룰 (다른언어도 결과적으로 class와 struct가 있기때문에)
	// Class는 변수는 private 함수는 public
	// struct는 Data의 의미를 가진 내용만 struct로

	// class => Heap영역  (동적할당)
	// struct => Stack영역  (정적할당)
	// struct => 기획자들이 사용할만한 엑셀데이터를 담는 곳

}