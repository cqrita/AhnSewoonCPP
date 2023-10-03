#include "stdafx.h"
#include "Enemy.h"
void Enemy::Init()
{
	Super::Init();
}
void Enemy::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Enemy::Update()
{
	Super::Update();
	Move(_direction);
}
void Enemy::Release()
{
	Super::Release();
}

void Enemy::Move(Vector2 direction)
{
	direction.Normalize();
	_body.x += direction.x * _speed * DeltaTime;
	_body.y += direction.y * _speed * DeltaTime;
}
void Enemy::SetEnemyInfo(Vector2 direction, int speed, CenterRect body, const WCHAR* spritePath)
{
	_direction = direction;
	_speed = speed;
	_body = body;
	SetSprite(spritePath, _body);
}