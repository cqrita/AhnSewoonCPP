#pragma once
class Player
{
private:
	RECT _body;
	float _speed;
public:
	RECT GetCollision() { return _body; };
public:
	void Move(Vector2 direction);
public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};

