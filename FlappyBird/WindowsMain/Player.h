#pragma once
#include "FlipbookActor.h"
enum class ePlayerDirection :int
{
	RIGHT,
	LEFT,
	END
};
enum class eWallDirection :int
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
	END
};
enum class ePlayerState
{
	Idle,
	Move,
	JumpFall,
	End
};
class Player : public FlipbookActor
{
public:
	using Super = FlipbookActor;
private:
	float _speed;
	float _gravity;
	int _missileStat;
	Vector2 _velocity;
	bool _IsAttackFlag;
	bool _IsAttack;
	bool _onHit;
	Flipbook* _idleFlipbook[4];
	Flipbook* _moveFlipbook[4];
	Flipbook* _attackFlipbook[4];
	Flipbook* _hitFlipbook[4];
	ePlayerDirection _spriteDir= ePlayerDirection::RIGHT;
	ePlayerState _state = ePlayerState::JumpFall;

	int DirToInt(ePlayerDirection dir) { return static_cast<int>(dir); }
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void Move(Vector2 direction);
	void SetPlayerInfo(float speed, CenterRect body);
	void SetState(ePlayerState state);
	ePlayerState GetState() { return _state; }
public:
	void UpdateInput();
	void UpdateMove();
	void UpdateIdle();
	void UpdateJumpFall();
	void UpdateGravity();
	bool CanChangeDirection();
	bool CanJump();
	eWallDirection AdjustPosition(class Collider* collider, class Collider* other);

public:
	virtual void OnComponentBeginOverlap(class Collider* collider, class Collider* other) override;
	virtual void OnComponentEndOverlap(class Collider* collider, class Collider* other) override;

};

