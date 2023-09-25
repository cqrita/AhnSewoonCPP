#pragma once
class Projectile
{
	float _speed;
	Vector2 _direction;
	CenterRect _body;
public:
	CenterRect GetCollision() { return _body; };
public:
	void Init(Vector2 spawnPos, Vector2 direction);
	void Update();
	void Render(HDC hdc);
	void Release();
};
