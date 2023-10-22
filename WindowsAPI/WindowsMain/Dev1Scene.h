#pragma once
#include "Scene.h"
class Dev1Scene : public Scene
{
private:
	class Player* _player = nullptr;

	class SpriteActor* _background = nullptr;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
private:
	float _enemyUpdate;
	float _enemyTimer;
private:
	void EnemyUpdate();
};

