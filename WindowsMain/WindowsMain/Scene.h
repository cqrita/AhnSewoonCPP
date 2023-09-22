#pragma once
enum class State
{
	WIN,
	LOSE,
	DEFAULT
};
//make enemy vector
// render
// update
// collision check
// score
class Scene
{
private:
	CenterRect _player;
	vector<class Projectile*> _missile;
	vector<RECT> _enemies;
	int _score;
	float _spawnRate;
	float _spawnTimer;
	int _speed;
public:
	void Init();
	void Render(HDC hdc);
	void Update();
	void Release();
public:
	State _gameState;
};
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
