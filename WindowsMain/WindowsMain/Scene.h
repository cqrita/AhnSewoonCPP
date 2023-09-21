#pragma once
class Scene
{
private:
	CenterRect _player;
	vector<class Projectile*> _missile;
	int _speed;
public:
	void Init();
	void Render(HDC hdc);
	void Update();
	void Release();
};
class Projectile
{
	CenterRect _body;
	float _speed;
	Vector2 _direction;
public:
	void Init(Vector2 spawnPos, Vector2 direction);
	void Update();
	void Render(HDC hdc);
	void Release();
};
