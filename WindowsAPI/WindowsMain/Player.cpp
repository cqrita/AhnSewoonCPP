#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "Scene.h"
#include "BoxCollider.h"
#include "Flipbook.h"
#include "Sword.h"
void Player::Init()
{
	Super::Init();
	this->SetName("Player");
	_isAttacking = false;
}
void Player::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Player::Update()
{
	Super::Update();
	Vector2 direction{0,0};
	if (GET_SINGLE(KeyManager)->GetKey('W') && _isAttacking == false)
	{
		direction = direction+ Vector2{0,-1};
		_spriteDir = ePlayerDirection::UP;
	}
	if (GET_SINGLE(KeyManager)->GetKey('S') && _isAttacking == false)
	{
		direction = direction + Vector2{ 0,1 };
		_spriteDir = ePlayerDirection::DOWN;
	}
	if (GET_SINGLE(KeyManager)->GetKey('A') && _isAttacking == false)
	{
		direction = direction + Vector2{ -1,0 };
		_spriteDir = ePlayerDirection::LEFT;
	}
	if (GET_SINGLE(KeyManager)->GetKey('D') && _isAttacking == false)
	{
		direction = direction + Vector2{ 1,0 };
		_spriteDir = ePlayerDirection::RIGHT;
	}
	if (EPSILON<direction.Length()&& _isAttacking==false)
	{
		SetFlipbook(_moveFlipbook[DirToInt(_spriteDir)]);
		direction.Normalize();
		Move(direction);
	}
	else if(_isAttacking)
	{
		if (_index == _flipbook->GetInfo().end)
		{
			_isAttacking = false;
			GET_SINGLE(SceneManager)->GetCurrentScene()->DeSpawnActor(_sword);
		}
		SetFlipbook(_attackFlipbook[DirToInt(_spriteDir)]);
	}
	else
	{
		SetFlipbook(_idleFlipbook[DirToInt(_spriteDir)]);

	}
	if (GET_SINGLE(KeyManager)->GetKeyDown(VK_LBUTTON))
	{
		if (_isAttacking == false)
		{
			_index = 0;
			_isAttacking = true;

			{
				_sword = new Sword();
				_sword->Init();
				Vector2 direction;
				switch (_spriteDir)
				{
				case ePlayerDirection::UP:
					direction= Vector2{ 0,-1 };
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
				direction = direction*50 + Vector2(_body.x, _body.y);
				_sword->SetSwordInfo(direction);
				{
					BoxCollider* collider = new BoxCollider();
					collider->SetCollision(Rect::MakeCenterRect(0, 0, 50, 50));
					collider->Init();
					_sword->AddComponent(collider);
				}
				GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(_sword);
			}
		}
		
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

	_spriteDir = ePlayerDirection::DOWN;

	SetFlipbook(_idleFlipbook[DirToInt(_spriteDir)]);
}

void Player::OnComponentBeginOverlap(class Collider* collider, class Collider* other)
{
	if (other->GetOwner()->GetName() == "ItemBox")
	{

		other->Release();
		GET_SINGLE(SceneManager)->GetCurrentScene()->DeSpawnActor(other->GetOwner());
	}

}
void Player::OnComponentEndOverlap(class Collider* collider, class Collider* other)
{

}
//attack flipbook
//check attack
//check direction
//attack
//spawn sword
//check collision