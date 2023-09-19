#pragma once
#include <bitset>
using namespace std;
#define KEYMAX 256
class KeyManager
{
private:
	bitset<KEYMAX> _keyDown;
public:
	bool GetKeyDown(int vKey);
	bool GetKey(int vKey);
	
private:
	KeyManager() {};
	~KeyManager() {};
	void Init();
	void Release();
	static KeyManager* _instance;
public:
	static KeyManager* GetInstance()
	{
		if (_instance == nullptr)
		{
			_instance = new KeyManager();
		}
		return _instance;
	}
};
#define KEYMANAGER KeyManager::GetInstance()