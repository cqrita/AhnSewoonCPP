#pragma once
class Enemy
{
private:
	CenterRect _body;
public:
	CenterRect GetCollision() { return _body; };
public:
	void Init(Vector2 position);
	void Update();
	void Render(HDC hdc);
	void Release();
};

