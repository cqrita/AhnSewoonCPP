#pragma once
class Player
{
private:
	CenterRect _body;
	float _speed;
public:
	CenterRect GetCollision() { return _body; };
public:
	void Move(Vector2 direction);
public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};

