#pragma once
#include <bitset>
using namespace std;
#define KEYMAX 256
class KeyManager
{
DECLARE_SINGLE(KeyManager)
private:
	bitset<KEYMAX> _keyDown;
public:
	bool GetKeyDown(int vKey);
	bool GetKey(int vKey);
	
public:
	void Init();
	void Release();


};
