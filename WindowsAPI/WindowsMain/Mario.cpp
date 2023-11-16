#include "stdafx.h"
#include "Mario.h"
#include "Flipbook.h"
#include "Texture.h"
#include "Collider.h"
void Mario::Init()
{
    Super::Init();
    this->SetName("Player");
    SetState(ePlayerState::Idle);
	_JumpAmount = 0;
	_isJump = false;
	_jumpTimer = false;
}

void Mario::Render(HDC hdc)
{
    Super::Render(hdc);
}

void Mario::Update()
{
	Super::Update();
	UpdateInput();
	switch (_state)
	{
	case ePlayerState::Idle:
		UpdateIdle();
		break;
	case ePlayerState::Move:
		UpdateMove();
		break;
	case ePlayerState::Jump:
		UpdateJump();
		break;
	case ePlayerState::End:
		Alert("Player State Error", "Current State End");
	default:
		break;
	}
	
}

void Mario::Release()
{
	Super::Release();
}

void Mario::Move(Vector2 direction)
{
	_body.x += direction.x * _speed * DeltaTime;
	_body.y += direction.y * _speed * DeltaTime;
}

void Mario::SetPlayerInfo(int speed, CenterRect body)
{
	_speed = speed;
	_body = body;
	GET_SINGLE(ResourceManager)->LoadTexture("T_Character_Left", "Character/PlayerLeft.bmp", RGB(128, 128, 128));
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Left");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 1;
		info.loop = true;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Move_Left", info);
	}
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Left");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 0;
		info.loop = true;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Idle_Left", info);
	}
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Left");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 5;
		info.line = 2;
		info.loop = false;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Jump_Left", info);
	}
	GET_SINGLE(ResourceManager)->LoadTexture("T_Character_Right", "Character/PlayerRight.bmp", RGB(128, 128, 128));
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Right");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 1;
		info.loop = true;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Move_Right", info);
	}
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Right");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 0;
		info.loop = true;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Idle_Right", info);
	}
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Right");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 5;
		info.line = 2;
		info.loop = false;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Jump_Right", info);
	}

	_moveFlipbook[DirToInt(ePlayerDirection::RIGHT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Move_Right");
	_moveFlipbook[DirToInt(ePlayerDirection::LEFT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Move_Left");
	_idleFlipbook[DirToInt(ePlayerDirection::RIGHT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Idle_Right");
	_idleFlipbook[DirToInt(ePlayerDirection::LEFT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Idle_Left");
	_jumpFlipbook[DirToInt(ePlayerDirection::RIGHT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Jump_Right");
	_jumpFlipbook[DirToInt(ePlayerDirection::LEFT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Jump_Left");

	_spriteDir = ePlayerDirection::LEFT;

	SetFlipbook(_idleFlipbook[DirToInt(_spriteDir)]);
}

void Mario::SetState(ePlayerState state)
{
	if (_state == state) return;
	_state = state;
	_index = 0;
	_jumpTimer = false;
	switch (_state)
	{
	case ePlayerState::Idle:
		SetFlipbook(_idleFlipbook[DirToInt(_spriteDir)]);
		break;
	case ePlayerState::Move:
		SetFlipbook(_moveFlipbook[DirToInt(_spriteDir)]);
		break;
	case ePlayerState::Jump:
		SetFlipbook(_moveFlipbook[DirToInt(_spriteDir)]);
		break;
	case ePlayerState::End:
	default:
		break;
	}

}

void Mario::UpdateInput()
{
	_direction = Vector2{ 0,0 };
	if (GET_SINGLE(KeyManager)->GetKey('A'))
	{
		_direction = _direction + Vector2{ -1,0 };
		_spriteDir = ePlayerDirection::LEFT;
	}
	if (GET_SINGLE(KeyManager)->GetKey('D'))
	{
		_direction = _direction + Vector2{ 1,0 };
		_spriteDir = ePlayerDirection::RIGHT;
	}
	if (GET_SINGLE(KeyManager)->GetKey('W') && CanChangeDirection())
	{
		_isJump = true;
	}
	_direction = _direction + Vector2{ 0,-_JumpAmount };
}

void Mario::UpdateMove()
{
	if (EPSILON < _direction.Length())
	{
		_direction.Normalize();
		SetFlipbook(_moveFlipbook[DirToInt(_spriteDir)]);
		Move(_direction);
	}
	ePlayerState newState = ePlayerState::Move;
	uint32 currentOrder = 0;

	if (currentOrder <= 1 && false == (EPSILON < _direction.Length()))
	{
		newState = ePlayerState::Idle;
		currentOrder = 1;
	}
	if (currentOrder <= 2 && true == _isJump)
	{
		newState = ePlayerState::Jump;
		currentOrder = 2;
	}
	SetState(newState);
}

void Mario::UpdateIdle()
{
	ePlayerState newState = ePlayerState::Idle;
	uint32 currentOrder = 0;

	if (currentOrder <= 2 && EPSILON < _direction.Length())
	{
		newState = ePlayerState::Move;
		currentOrder = 2;
	}
	if (currentOrder <= 3 && true == _isJump)
	{
		newState = ePlayerState::Jump;
		currentOrder = 3;
	}
	this->SetState(newState);

}

void Mario::UpdateJump()
{
	if (_jumpTimer == false)
	{
		_JumpAmount += DeltaTime*3;
	}
	else
	{
		_JumpAmount -= DeltaTime*3;
	}
	if (_JumpAmount > 1)
	{
		_jumpTimer = true;
	}
	if (_JumpAmount < -2)
	{
		_isJump = false;
		_JumpAmount = 0;
	}
	if (EPSILON < _direction.Length())
	{
		SetFlipbook(_jumpFlipbook[DirToInt(_spriteDir)]);
		Move(_direction);
	}
	ePlayerState newState = ePlayerState::Jump;
	uint32 currentOrder = 0;

	if (currentOrder <= 1 && false == (EPSILON < _direction.Length()))
	{
		newState = ePlayerState::Idle;
		currentOrder = 1;
	}
	if (currentOrder <= 3 && false == _isJump && EPSILON < _direction.Length())
	{
		newState = ePlayerState::Move;
		currentOrder = 3;
	}
	this->SetState(newState);
}

bool Mario::CanChangeDirection()
{
	ePlayerState state = GetState();
	if (state == ePlayerState::Idle || state == ePlayerState::Move)
	{
		return true;
	}
	return false;
}

void Mario::OnComponentBeginOverlap(Collider* collider, Collider* other)
{
	if (other->GetCollisionLayer()== CollisionLayerType::CLT_WALL)
	{
		_isJump = false;
	}
	_JumpAmount = 0;
	cout << "hit" << endl;
}

void Mario::OnComponentEndOverlap(Collider* collider, Collider* other)
{

}
