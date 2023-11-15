#pragma once
#include "FlipbookActor.h"
enum class ePlayerDirection :int
{
	LEFT,
	RIGHT,
	END
};
enum class ePlayerState
{
	Idle,
	Move,
	Jump,
	End
};
class Mario : public FlipbookActor
{
public:
	using Super = FlipbookActor;
private:
	int _speed;
	bool _isJump;
	float _JumpAmount;
	bool _jumpTimer;
	Flipbook* _idleFlipbook[2];
	Flipbook* _moveFlipbook[2];
	Flipbook* _jumpFlipbook[2];
	Vector2 _direction;
	ePlayerDirection _spriteDir = ePlayerDirection::END;
	ePlayerState _state = ePlayerState::Idle;

	int DirToInt(ePlayerDirection dir) { return static_cast<int>(dir); }
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void Move(Vector2 direction);
	void SetPlayerInfo(int speed, CenterRect body);
	void SetState(ePlayerState state);
	ePlayerState GetState() { return _state; }
public:
	void UpdateInput();
	void UpdateMove();
	void UpdateIdle();
	void UpdateJump();
	bool CanChangeDirection();
public:
	virtual void OnComponentBeginOverlap(class Collider* collider, class Collider* other) override;
	virtual void OnComponentEndOverlap(class Collider* collider, class Collider* other) override;
};

