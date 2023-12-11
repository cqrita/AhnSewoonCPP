#pragma once
#include "FlipbookActor.h"
enum class eWallDirection :int
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
	END
};
class Player : public FlipbookActor
{
public:
	using Super = FlipbookActor;
private:
	float _speed;
	float _gravity;
	Vector2 _velocity;
	Flipbook* _moveFlipbook;
	Flipbook* _hitFlipbook;

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void Move(Vector2 direction);
	void SetPlayerInfo(float speed, CenterRect body);
public:
	void UpdateGravity();
	void UpdateInput();
	eWallDirection AdjustPosition(class Collider* collider, class Collider* other);

public:
	virtual void OnComponentBeginOverlap(class Collider* collider, class Collider* other) override;
	virtual void OnComponentEndOverlap(class Collider* collider, class Collider* other) override;

};

