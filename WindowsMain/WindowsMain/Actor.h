#pragma once
class Actor
{
public:
	virtual void Init() {}
	virtual void Render(HDC hdc) {}
	virtual void Update() {}
	virtual void Release() {}

};

