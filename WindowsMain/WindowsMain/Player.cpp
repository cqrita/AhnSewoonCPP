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
	UpdateGravity();
	switch (_state)
	{
	case ePlayerState::Idle:
		UpdateIdle();
		break;
	case ePlayerState::Move:
		UpdateMove();
		break;
	case ePlayerState::JumpFall:
		UpdateJumpFall();
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
	_body.y += direction.y * DeltaTime;
}
void Player::SetPlayerInfo(float speed,CenterRect body)
{
	_speed = speed;
	_body = body;
	_gravity = -9.8;
	_moveFlipbook[DirToInt(ePlayerDirection::RIGHT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Move_Right");
	_moveFlipbook[DirToInt(ePlayerDirection::LEFT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Move_Left");
	_idleFlipbook[DirToInt(ePlayerDirection::RIGHT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Idle_Right");
	_idleFlipbook[DirToInt(ePlayerDirection::LEFT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Idle_Left");
	_attackFlipbook[DirToInt(ePlayerDirection::RIGHT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Attack_Right");
	_attackFlipbook[DirToInt(ePlayerDirection::LEFT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Attack_Left");
	_hitFlipbook[DirToInt(ePlayerDirection::RIGHT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Hit_Right");
	_hitFlipbook[DirToInt(ePlayerDirection::LEFT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Hit_Left");

	_spriteDir = ePlayerDirection::RIGHT;

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
	case ePlayerState::JumpFall:
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
	_velocity = Vector2{ 0,0 };
	if (GET_SINGLE(KeyManager)->GetKey('A') && CanChangeDirection())
	{
		_velocity = _velocity + Vector2{ -1,0 };
		_spriteDir = ePlayerDirection::LEFT;
	}
	if (GET_SINGLE(KeyManager)->GetKey('D') && CanChangeDirection())
	{
		_velocity = _velocity + Vector2{ 1,0 };
		_spriteDir = ePlayerDirection::RIGHT;
	}
	if (GET_SINGLE(KeyManager)->GetKey('W')&& CanJump())
	{
		_velocity.y=-500;
		SetState(ePlayerState::JumpFall);
	}

	if (GET_SINGLE(KeyManager)->GetKeyDown(VK_LBUTTON))
	{
		_IsAttackFlag = true;
	}
}

void Player::UpdateMove()
{
	if (EPSILON < _velocity.Length())
	{
		SetFlipbook(_moveFlipbook[DirToInt(_spriteDir)]);
		Move(_velocity);
	}
	ePlayerState newState = ePlayerState::Move;
	uint32 currentOrder = 0;
	
	if (currentOrder <= 1 && false == (EPSILON < abs(_velocity.x)))
	{
		newState = ePlayerState::Idle;
		currentOrder = 1;
	}

	SetState(newState);
}

void Player::UpdateIdle()
{
	ePlayerState newState = ePlayerState::Idle;
	uint32 currentOrder = 0;
	if (EPSILON < _velocity.Length())
	{
		Move(_velocity);
	}

	if (currentOrder <= 2 && EPSILON < abs(_velocity.x))
	{
		newState = ePlayerState::Move;
		currentOrder = 2;
	}
	
	this->SetState(newState);
}

void Player::UpdateJumpFall()
{

}


void Player::UpdateGravity()
{
	_velocity.y -= _gravity * 10;
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

bool Player::CanJump()
{
	return false;
}

eWallDirection Player::AdjustPosition(class Collider* collider, class Collider* other)
{
	eWallDirection rv = eWallDirection::END;
	BoxCollider* b1 = dynamic_cast<BoxCollider*>(collider);
	BoxCollider* b2 = dynamic_cast<BoxCollider*>(other);

	CenterRect body = this->GetBody();
	Vector2 pos = body.Position();
	if (b1 != nullptr && b2 != nullptr)
	{
		RECT r1 = b1->GetCollision().ToRect();
		RECT r2 = b2->GetCollision().ToRect();
		RECT intersect = {};
		if (IntersectRect(&intersect, &r1, &r2))
		{
			int width = intersect.right - intersect.left;
			int height = intersect.bottom - intersect.top;

			if (width > height)
			{
				if (intersect.bottom == r1.bottom)
				{
					pos.y -= static_cast<float>(height);
					rv = eWallDirection::UP;
				}
				else
				{
					pos.y += static_cast<float>(height);
					rv = eWallDirection::DOWN;
				}
			}
			else
			{
				if (intersect.right == r1.right)
				{
					pos.x -= static_cast<float>(width);
					rv = eWallDirection::LEFT;
				}
				else
				{
					pos.x += static_cast<float>(width);
					rv = eWallDirection::RIGHT;
				}
			}
		}
	}

	this->_body.x = pos.x;
	this->_body.y = pos.y;

	return rv;
}

void Player::OnComponentBeginOverlap(class Collider* collider, class Collider* other)
{
	if (other->GetCollisionLayer()==CollisionLayerType::CLT_WALL)
	{
		eWallDirection dir= AdjustPosition(collider, other);
		if (dir == eWallDirection::UP)
		{
			_velocity.y = 0;
			SetState(ePlayerState::Idle);
		}
		cout << "hit" << endl;
	}
}
void Player::OnComponentEndOverlap(class Collider* collider, class Collider* other)
{

}