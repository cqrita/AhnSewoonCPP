#include <iostream>
#include <Windows.h>
#include "KeyManager.h"
using namespace std;
int main()
{
	int cnt = 0;
	while (true)
	{
		if (KEYMANAGER->GetKeyDown(VK_UP))
		{
			cout << 1 << endl;
		}
		if (KEYMANAGER->GetKey(VK_DOWN))
		{
			cout << 2 << endl;
		}

	}

	//& , |, ! AND OR NOT

	//singleton
}