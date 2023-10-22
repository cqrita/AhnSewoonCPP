#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"

void Enemy::Init()
{
	Super::Init();
	this->SetName("Enemy");
}
void Enemy::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Enemy::Update()
{
	Super::Update();
	if (_player != nullptr)
	{
		Vector2 direction{ 0,1 };
		Vector2 playerLoc{ _player->GetBody().x,_player->GetBody().y };
		Vector2 enemyLoc{ GetBody().x,GetBody().y };
		float angle = (enemyLoc - Vector2{ GetBody().x,GetBody().y + 1 }).SignedAngle(enemyLoc - playerLoc) * (180 / 3.14);
		if (angle > -30 && angle < 30)
		{
			if (angle<5 && angle>-5)
			{

			}
			else if (angle > 0)
			{
				direction = direction + Vector2{ -0.5,0 };
			}
			else if (angle < 0)
			{
				direction = direction + Vector2{ 0.5,0 };
			}
		}
		Move(direction);
	}
	

}
void Enemy::Release()
{
	Super::Release();

}
void Enemy::Move(Vector2 direction)
{
	_body.x += direction.x * _speed * DeltaTime;
	_body.y += direction.y * _speed * DeltaTime;
}
void Enemy::SetEnemyInfo(int speed, CenterRect body, const WCHAR* spritePath, Player* player)
{
	_speed = speed;
	_body = body;
	_player = player;
	SetSprite(spritePath, _body);
}

void Enemy::OnComponentBeginOverlap(class Collider* collider, class Collider* other)
{
}
void Enemy::OnComponentEndOverlap(class Collider* collider, class Collider* other)
{

}