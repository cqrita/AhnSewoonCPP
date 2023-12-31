#include "stdafx.h"
#include "Bullet.h"
void Bullet::Init()
{
	Super::Init();
}
void Bullet::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Bullet::Update()
{
	Super::Update();
	Move(_direction);	
}
void Bullet::Release()
{
	Super::Release();
}

void Bullet::Move(Vector2 direction)
{
	direction.Normalize();
	_body.x += direction.x * _speed * DeltaTime;
	_body.y += direction.y * _speed * DeltaTime;
}
void Bullet::SetBulletInfo(Vector2 direction,int speed, CenterRect body, const WCHAR* spritePath)
{
	_direction = direction;
	_speed = speed;
	_body = body;
	SetSprite(spritePath, _body);
}