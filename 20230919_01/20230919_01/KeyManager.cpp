#include "KeyManager.h"
#include <Windows.h>

KeyManager* KeyManager::_instance = nullptr;

void KeyManager::Init()
{
	for (int i = 0; i < KEYMAX; i++)
	{
		_keyDown.set(i, false);
	}
}
void KeyManager::Release()
{

}

bool KeyManager::GetKeyDown(int vKey)
{
	if (GetAsyncKeyState(vKey) & 0x8000)
	{
		if (_keyDown[vKey] == false)
		{
			_keyDown.set(vKey, true);
			return true;
		}
	}
	else
	{
		_keyDown.set(vKey, false);
	}
	return false;
}
bool KeyManager::GetKey(int vKey)
{
	if (GetAsyncKeyState(vKey) & 0x8001)
	{
		return true;
	}
	return false;
}
