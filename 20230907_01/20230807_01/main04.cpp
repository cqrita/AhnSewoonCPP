#include <iostream>

using namespace std;

class Singleton
{
public:
	static Singleton& GetInstance()
	{
		static Singleton instance;
		return instance;
	}
	void Init() {}
	void Update() {}
	void Release() {}
private:
	Singleton() {}
};
#define GetSingleTon Singleton::GetInstance()
void main()
{
	//4. 싱글톤
	
	//프로그램자체에서 하나뿐인 객체를 만들기위한 패턴

	// MainGame같은 클래스는 프로그램에 1개만 존재하는게 설계자 생각과 일치
	// 이점.
	// 어디서나 쉽게 호출 가능하다.

	GetSingleTon.Init();
	GetSingleTon.Update();
	GetSingleTon.Release();
}