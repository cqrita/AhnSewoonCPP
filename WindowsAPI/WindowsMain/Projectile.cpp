#include "stdafx.h"
#include "Projectile.h"
void Projectile::Init(Vector2 spawnPos, Vector2 direction)
{
	_body = Rect::MakeCenterRect(spawnPos.x, spawnPos.y, 30, 30);
	_speed = 500;
	_direction = direction;
}
void Projectile::Update()
{
	float deltaTime = DeltaTime;
	_body.x += _direction.x * deltaTime * _speed;
	_body.y += _direction.y * deltaTime * _speed;
}
void Projectile::Render(HDC hdc)
{
	Draw::Rect(hdc, _body);
}
void Projectile::Release()
{
}
