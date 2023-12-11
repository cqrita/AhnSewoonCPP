#pragma once
#include "Scene.h"
class Dev1Scene : public Scene
{
public:
	using Super = Scene;
private:
	class Player* _player = nullptr;
	class SpriteActor* _background = nullptr;
	float _speed;
	float _score;
	int _level;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void SetPlayerResource();
	void ChangeScene();
};

