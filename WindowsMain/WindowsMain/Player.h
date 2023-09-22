#pragma once
class Player
{
private:
	CenterRect _body;
	float _speed;
	vector<class Projectile*> _projectiles;

public:
	vector<class Projectile*> GetProjectiles() { return _projectiles; };
	void RemoveProjectile(int index);
public:
	void Shot();
	void Move(Vector2 direction);
public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};

