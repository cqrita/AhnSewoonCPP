#pragma once
class Projectile
{
	float _speed;
	Vector2 _direction;
public:
	void Init(Vector2 spawnPos, Vector2 direction);
	void Update();
	void Render(HDC hdc);
	void Release();
public:
	CenterRect _body;
};
