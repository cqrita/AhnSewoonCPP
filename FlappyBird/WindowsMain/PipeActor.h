#pragma once
#include "Actor.h"
class PipeActor :public Actor
{
public:
	using Super = Actor;
public:
	int _speed = 500;
	float _width;
	Vector2 _size = Vector2(WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT);

private:
	class Wall* _up[16];
	class Wall* _down[16];

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void SetWidth(float width);
	void SetSize(Vector2 size);
	void SetSpeed(int speed);
};

