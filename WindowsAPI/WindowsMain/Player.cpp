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
	_spriteDir = ePlayerDirection::RIGHT;
	SetState(ePlayerState::JumpFall);
}
void Player::Render(HDC hdc)
{
	Vector2Int CameraPos = CurrentScene->GetCameraPos();
	//Draw::Rect(hdc, test, CameraPos);
	Super::Render(hdc);
}
void Player::Update()
{
	Super::Update();
	UpdateInput();
	if (_state == ePlayerState::JumpFall)
	{
		UpdateGravity();
	}
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
	if (DeltaTime > 0.1f) return;
	_body.x += direction.x * _speed * DeltaTime;
	_body.y += direction.y * DeltaTime;
}
void Player::SetPlayerInfo(float speed,CenterRect body)
{
	_speed = speed;
	_body = body;
	_gravity = 60;
	_moveFlipbook[DirToInt(ePlayerDirection::RIGHT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Move_Right");
	_moveFlipbook[DirToInt(ePlayerDirection::LEFT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Move_Left");
	_idleFlipbook[DirToInt(ePlayerDirection::RIGHT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Idle_Right");
	_idleFlipbook[DirToInt(ePlayerDirection::LEFT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Idle_Left");
	_attackFlipbook[DirToInt(ePlayerDirection::RIGHT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Attack_Right");
	_attackFlipbook[DirToInt(ePlayerDirection::LEFT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Attack_Left");
	_hitFlipbook[DirToInt(ePlayerDirection::RIGHT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Hit_Right");
	_hitFlipbook[DirToInt(ePlayerDirection::LEFT)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Hit_Left");

	test = body.ToRect();
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
		_gravityV = -15;
		SetState(ePlayerState::JumpFall);
	}
}

void Player::UpdateMove()
{
	if (EPSILON < _velocity.Length())
	{
		SetFlipbook(_moveFlipbook[DirToInt(_spriteDir)]);
		Move(_velocity);
	}
	_gravityV = 10;
	ePlayerState newState = ePlayerState::Move;
	uint32 currentOrder = 0;
	
	if (currentOrder <= 1 && false == (EPSILON < abs(_velocity.x)))
	{
		newState = ePlayerState::Idle;
		currentOrder = 1;
	}
	if (currentOrder <= 3 && EPSILON < abs(_velocity.y))
	{
		newState = ePlayerState::JumpFall;
		currentOrder = 3;
	}

	SetState(newState);
}

void Player::UpdateIdle()
{
	ePlayerState newState = ePlayerState::Idle;
	uint32 currentOrder = 0;
	_gravityV = 10;
	if (currentOrder <= 2 && EPSILON < abs(_velocity.x))
	{
		newState = ePlayerState::Move;
		currentOrder = 2;
	}
	if (currentOrder <= 3 && EPSILON < abs(_velocity.y))
	{
		newState = ePlayerState::JumpFall;
		currentOrder = 3;
	}

	this->SetState(newState);
}

void Player::UpdateJumpFall()
{
	if (_gravityV < 10)
	{
		_gravityV += DeltaTime*20;
	}
	else
	{
		_gravityV = 10;
	}
	if (EPSILON < _velocity.Length())
	{
		this->Move(_velocity);
	}
}


void Player::UpdateGravity()
{
	_velocity.y += _gravity * _gravityV;
}

bool Player::CanChangeDirection()
{
	ePlayerState state = GetState();
	if (state == ePlayerState::Idle|| state == ePlayerState::Move|| state == ePlayerState::JumpFall)
	{
		return true;
	}
	return false;
}

bool Player::CanJump()
{
	ePlayerState state = GetState();
	if (state == ePlayerState::Idle || state == ePlayerState::Move)
	{
		return true;
	}
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
					pos.y -= static_cast<float>(height-1);
					rv = eWallDirection::UP;
				}
				else
				{
					pos.y += static_cast<float>(height+10);
					rv = eWallDirection::DOWN;
				}
			}
			else
			{
				if (intersect.right == r1.right)
				{
					pos.x -= static_cast<float>(width+10);
					rv = eWallDirection::LEFT;
				}
				else
				{
					pos.x += static_cast<float>(width+10);
					rv = eWallDirection::RIGHT;
				}
			}
		}
	}

	this->_body.x = pos.x;
	this->_body.y = pos.y;

	return rv;
}

bool Player::CheckWall(Collider* collider, Collider* other)
{
	eWallDirection rv = eWallDirection::END;
	BoxCollider* b1 = dynamic_cast<BoxCollider*>(collider);
	BoxCollider* b2 = dynamic_cast<BoxCollider*>(other);
	if (b1 != nullptr && b2 != nullptr)
	{
		RECT r1 = b1->GetCollision().ToRect();
		RECT r2 = b2->GetCollision().ToRect();
		test = r2;
		r2.left -= 20;
		r2.right += 20;
		r2.top -= 10;
		RECT intersect = {};
		if (IntersectRect(&intersect, &r1, &r2))
		{
			int width = intersect.right - intersect.left;
			int height = intersect.bottom - intersect.top;

			if (width > height)
			{
				if (intersect.bottom == r1.bottom)
				{
					rv = eWallDirection::UP;
					return true;
				}
			}
		}
	}
	return false;
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
	}
	if (other->GetOwner()->GetName() == "ItemBox")
	{
		CenterRect cr = GetBody();
		cr.height *= 1.5;
		cr.width *= 1.5;
		SetBody(cr);
		BoxCollider* bc = dynamic_cast<BoxCollider*>(collider);
		CenterRect boxRect = bc->GetCollision();
		boxRect.height *= 1.5;
		boxRect.width *= 1.5;
		boxRect.x -= cr.x;
		boxRect.y -= cr.y;

		bc->SetCollision(boxRect);
		GET_SINGLE(SceneManager)->GetCurrentScene()->DeSpawnActor(other->GetOwner());
	}
}
void Player::OnComponentEndOverlap(class Collider* collider, class Collider* other)
{
	if (other->GetCollisionLayer() == CollisionLayerType::CLT_WALL)
	{
		if (CheckWall(collider, other))
		{
			SetState(ePlayerState::JumpFall);
		}
	}

}