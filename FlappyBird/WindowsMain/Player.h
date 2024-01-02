#pragma once
#include "FlipBookActor.h"
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
class Player : public FlipbookActor
{
public:
	using Super = FlipbookActor;
private:
	float _gravity;
	float _jump;
	Vector2 _velocity;
	class BoxCollider* _scoreBox;
	class BoxCollider* _collider;
	int _score;
	Flipbook* _moveFlipbook[3];
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void Move(Vector2 direction);
	void SetPlayerInfo(CenterRect body,double gravity, float jump);
public:
	void UpdateInput();
	void UpdateJumpFall();
	void UpdateGravity();
	int GetScore() { return _score; }
public:
	virtual void OnComponentBeginOverlap(class Collider* collider, class Collider* other) override;
	virtual void OnComponentEndOverlap(class Collider* collider, class Collider* other) override;
};

