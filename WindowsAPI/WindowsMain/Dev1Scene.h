#pragma once
#include "Scene.h"
class Dev1Scene : public Scene
{
private:
	class Player* _player = nullptr;
	
	vector<class Enemy*> _enemies;
private:
	float _EnemySpawnRate;
	float _EnemySpawnTimer;
	int _score;
	int _hit;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void SpawnEnemy();
	void Collision();
};

