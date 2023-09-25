#pragma once
class Enemy
{
private:
	RECT _body;
	float _speed;
public:
	void Move(Vector2 direction);
public:
	RECT GetCollision() { return _body; };
public:
	void Init(Vector2 position);
	void Update();
	void Render(HDC hdc);
	void Release();
};

