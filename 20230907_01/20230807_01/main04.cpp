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
	//4. �̱���
	
	//���α׷���ü���� �ϳ����� ��ü�� ��������� ����

	// MainGame���� Ŭ������ ���α׷��� 1���� �����ϴ°� ������ ������ ��ġ
	// ����.
	// ��𼭳� ���� ȣ�� �����ϴ�.

	GetSingleTon.Init();
	GetSingleTon.Update();
	GetSingleTon.Release();
}