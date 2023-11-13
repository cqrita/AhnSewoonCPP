#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "Scene.h"
#include "BoxCollider.h"
#include "Flipbook.h"
void Player::Init()
{
	Super::Init();
	this->SetName("Player");
	_missileStat = 1;
	_IsAttack = false;
	_onHit=false;
	SetState(ePlayerState::Idle);
}
void Player::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Player::Update()
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
	case ePlayerState::Attack:
		UpdateAttack();
		break;
	case ePlayerState::Hit:
		UpdateHit();
		break;
	case ePlayerState::End:
		Alert("Player State Error", "Current State End");
	default:
		break;
	}	
	
	
}
void Player::Release()
{
	Super::Release();

}
void Player::Move(Vector2 direction)
{
	_body.x += direction.x * _speed * DeltaTime;
	_body.y += direction.y * _speed * DeltaTime;
}
void Player::SetPlayerInfo(int speed,CenterRect body)
{
	_speed = speed;
	_body = body;
	_moveFlipbook[DirToInt(ePlayerDirection::DOWN)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Move_Down");
	_moveFlipbook[DirToInt(ePlayerDirection::UP)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Move_Up");
	_moveFlipbook[DirToInt(ePlayerDirection::RIGHT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Move_Right");
	_moveFlipbook[DirToInt(ePlayerDirection::LEFT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Move_Left");
	_idleFlipbook[DirToInt(ePlayerDirection::DOWN)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Idle_Down");
	_idleFlipbook[DirToInt(ePlayerDirection::UP)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Idle_Up");
	_idleFlipbook[DirToInt(ePlayerDirection::RIGHT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Idle_Right");
	_idleFlipbook[DirToInt(ePlayerDirection::LEFT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Idle_Left");
	_attackFlipbook[DirToInt(ePlayerDirection::DOWN)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Attack_Down");
	_attackFlipbook[DirToInt(ePlayerDirection::UP)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Attack_Up");
	_attackFlipbook[DirToInt(ePlayerDirection::RIGHT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Attack_Right");
	_attackFlipbook[DirToInt(ePlayerDirection::LEFT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Attack_Left");
	_hitFlipbook[DirToInt(ePlayerDirection::DOWN)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Hit_Down");
	_hitFlipbook[DirToInt(ePlayerDirection::UP)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Hit_Up");
	_hitFlipbook[DirToInt(ePlayerDirection::RIGHT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Hit_Right");
	_hitFlipbook[DirToInt(ePlayerDirection::LEFT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Hit_Left");

	_spriteDir = ePlayerDirection::DOWN;

	SetFlipbook(_idleFlipbook[DirToInt(_spriteDir)]);
}

void Player::SetState(ePlayerState state)
{
	if (_state == state) return;
	_state = state;
	_index = 0;
	switch (_state)
	{
	case ePlayerState::Idle:
		SetFlipbook(_idleFlipbook[DirToInt(_spriteDir)]);
		break;
	case ePlayerState::Move:
		SetFlipbook(_moveFlipbook[DirToInt(_spriteDir)]);
		break;
	case ePlayerState::Attack:
		SetFlipbook(_attackFlipbook[DirToInt(_spriteDir)]);
		break;
	case ePlayerState::Hit:
		SetFlipbook(_hitFlipbook[DirToInt(_spriteDir)]);
		break;
	case ePlayerState::End:
	default:
		break;
	}
}

void Player::UpdateInput()
{
	_IsAttackFlag = false;
	_direction = Vector2{ 0,0 };
	if (GET_SINGLE(KeyManager)->GetKey('W') && CanChangeDirection())
	{
		_direction = _direction + Vector2{ 0,-1 };
		_spriteDir = ePlayerDirection::UP;
	}
	if (GET_SINGLE(KeyManager)->GetKey('S') && CanChangeDirection())
	{
		_direction = _direction + Vector2{ 0,1 };
		_spriteDir = ePlayerDirection::DOWN;
	}
	if (GET_SINGLE(KeyManager)->GetKey('A') && CanChangeDirection())
	{
		_direction = _direction + Vector2{ -1,0 };
		_spriteDir = ePlayerDirection::LEFT;
	}
	if (GET_SINGLE(KeyManager)->GetKey('D') && CanChangeDirection())
	{
		_direction = _direction + Vector2{ 1,0 };
		_spriteDir = ePlayerDirection::RIGHT;
	}

	if (GET_SINGLE(KeyManager)->GetKeyDown(VK_LBUTTON))
	{
		_IsAttackFlag = true;
	}
}

void Player::UpdateMove()
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
	if (currentOrder <= 5 && _onHit)
	{
		newState = ePlayerState::Hit;
		currentOrder = 5;
	}
	SetState(newState);
}

void Player::UpdateIdle()
{
	ePlayerState newState = ePlayerState::Idle;
	uint32 currentOrder = 0;

	if (currentOrder <= 2 && EPSILON < _direction.Length())
	{
		newState = ePlayerState::Move;
		currentOrder = 2;
	}
	if (currentOrder <= 3 && _IsAttackFlag)
	{
		newState = ePlayerState::Attack;
		currentOrder = 3;
	}
	if (currentOrder <= 5 && _onHit)
	{
		newState = ePlayerState::Hit;
		currentOrder = 5;
	}

	this->SetState(newState);
}

void Player::UpdateAttack()
{
	if (_index==3 && _IsAttack==false)
	{
		for (int i = 0; i < _missileStat; i++)
		{
			Bullet* bullet = new Bullet();
			Vector2 direction;
			switch (_spriteDir)
			{
			case ePlayerDirection::UP:
				direction = Vector2{ 0,-1 };
				break;
			case ePlayerDirection::RIGHT:
				direction = Vector2{ 1,0 };
				break;
			case ePlayerDirection::DOWN:
				direction = Vector2{ 0,1 };
				break;
			case ePlayerDirection::LEFT:
				direction = Vector2{ -1,0 };
				break;
			case ePlayerDirection::END:
				break;
			default:
				break;
			}
			float centerX = _body.x;
			float maxWidth = 70 * (_missileStat - 1);
			float missileX = centerX - maxWidth / 2 + 70 * i;
			bullet->SetBulletInfo(direction, 300, Rect::MakeCenterRect(missileX, _body.y, 10, 10), L"../Resources/Power Ups/Power Up.png");
			{
				BoxCollider* collider = new BoxCollider();
				collider->SetCollision(Rect::MakeCenterRect(0, 0, 20, 20));
				bullet->AddComponent(collider);
			}
			GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(bullet);
		}
		_IsAttack = true;
	}
	if (_index == 0|| _index == 4)
	{
		_IsAttack = false;
	}
	ePlayerState newState = ePlayerState::Attack;
	uint32 currentOrder = 0;

	if (_flipbook->GetInfo().end == _index)
	{
		if (currentOrder <= 1)
		{
			newState = ePlayerState::Idle;
			currentOrder = 1;
		}

		if (currentOrder <= 2 && EPSILON < _direction.Length())
		{
			newState = ePlayerState::Move;
			currentOrder = 2;
		}
	}
	if (currentOrder <= 5 && _onHit)
	{
		newState = ePlayerState::Hit;
		currentOrder = 5;
	}

	this->SetState(newState);
}

void Player::UpdateHit()
{
	ePlayerState newState = ePlayerState::Hit;
	uint32 currentOrder = 0;
	if (_flipbook->GetInfo().end == _index)
	{
		if (currentOrder <= 1)
		{
			newState = ePlayerState::Idle;
			currentOrder = 1;
		}

		if (currentOrder <= 2 && EPSILON < _direction.Length())
		{
			newState = ePlayerState::Move;
			currentOrder = 2;
		}
	}
	this->SetState(newState);
	_onHit = false;
}

bool Player::CanChangeDirection()
{
	ePlayerState state = GetState();
	if (state == ePlayerState::Idle|| state == ePlayerState::Move)
	{
		return true;
	}
	return false;
}

void Player::OnComponentBeginOverlap(class Collider* collider, class Collider* other)
{
	if (other->GetOwner()->GetName() == "ItemBox")
	{

		other->Release();
		GET_SINGLE(SceneManager)->GetCurrentScene()->DeSpawnActor(other->GetOwner());

		_missileStat++;

	}
	if (other->GetOwner()->GetName() == "Monster")
	{
		_onHit = true;
	}

}
void Player::OnComponentEndOverlap(class Collider* collider, class Collider* other)
{

}