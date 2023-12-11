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
	_gravity = -9.8;
	_moveFlipbook = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Move_Right");
	_hitFlipbook = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Hit_Right");

	SetFlipbook(_moveFlipbook);

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
	Move(_velocity);
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
}

void Player::UpdateInput()
{
	_velocity = Vector2{ 0,0 };
	if (GET_SINGLE(KeyManager)->GetKey(VK_SPACE))
	{
		_velocity.y=-1200;
		SetFlipbook(_hitFlipbook);
	}
	if (_flipbook->GetInfo().end-1 <= _index&&_flipbook==_hitFlipbook)
	{
		_index = 0;
		SetFlipbook(_moveFlipbook);
	}
	_velocity.x=0.5;
}

void Player::UpdateGravity()
{
	_velocity.y -= _gravity * 50;
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
					pos.y -= static_cast<float>(height+10);
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

void Player::OnComponentBeginOverlap(class Collider* collider, class Collider* other)
{
	if (other->GetCollisionLayer()==CollisionLayerType::CLT_WALL)
	{
		eWallDirection dir= AdjustPosition(collider, other);
		if (dir == eWallDirection::LEFT)
		{
			cout << "hit" << endl;
		}
	}
}
void Player::OnComponentEndOverlap(class Collider* collider, class Collider* other)
{

}