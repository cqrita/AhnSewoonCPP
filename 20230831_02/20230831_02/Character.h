#pragma once
class Character
{
public:
	int _x;
	int _y;
	void Init();
	void Update(char inputKey);
	void Release();
	void Render();
};

