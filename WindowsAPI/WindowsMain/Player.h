#pragma once
#include "SpriteActor.h"
enum class eWallDirection :int
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
	END
};
enum class ePlayerDirection :int
{
	UP,
	NORMAL,
	DOWN,
	END
};
class Player : public SpriteActor
{
public:
	using Super = SpriteActor;
private:
	float _gravity;
	Vector2 _velocity;
	Sprite* _moveSprite[3];
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void Move(Vector2 direction);
	void SetPlayerInfo(CenterRect body);
public:
	void UpdateInput();
	void UpdateJumpFall();
	void UpdateGravity();

public:
	virtual void OnComponentBeginOverlap(class Collider* collider, class Collider* other) override;
	virtual void OnComponentEndOverlap(class Collider* collider, class Collider* other) override;
};

