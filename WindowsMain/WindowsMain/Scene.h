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
