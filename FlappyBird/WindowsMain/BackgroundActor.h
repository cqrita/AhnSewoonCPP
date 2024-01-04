#pragma once
#include "Actor.h"
struct BackgroundLayer
{
	class SpriteActor* Sky;
	class Wall* Ground;
};
class BackgroundActor :public Actor
{
public:
	using Super = Actor;
public:
	int _speed=500;
	Vector2 _size= Vector2(WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT);
private:
	class SpriteActor* _background[8];
	class Wall* _bottom[8];
	class PipeActor* _pipe = nullptr;

	vector<BackgroundLayer*> _backgroundLayer;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void SetSpeed(int speed);
	void SetSize(Vector2 size);
};

