#include "stdafx.h"
#include "Enemy.h"
void Enemy::Init(Vector2 position)
{
	_body = Rect::MakeRect(position.x, position.y, 70, 70);
	_speed = 1000;
}
void Enemy::Update()
{
	Vector2 direction = Vector2{ 0,1 };
	this->Move(direction);
}
void Enemy::Render(HDC hdc)
{
	Draw::Rect(hdc, _body);
}
void Enemy::Release()
{

}
void Enemy::Move(Vector2 direction)
{
	cout << "move" << endl;
	direction.Normalize();
	OffsetRect(&_body, direction.x * _speed * DeltaTime, direction.y * _speed * DeltaTime);
}
