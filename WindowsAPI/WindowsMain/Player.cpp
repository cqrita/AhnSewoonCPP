#include "stdafx.h"
#include "Player.h"
#include "Projectile.h"
void Player::Init()
{
	_body = Rect::MakeCenterRect(WIN_SIZE_WIDTH/2, WIN_SIZE_HEIGHT-100, 100, 100);
	_speed = 300;
}
void Player::Update()
{
	Vector2 direction = Vector2{ 0,0 };
	if (GET_SINGLE(KeyManager)->GetKey('A'))
	{
		direction = direction + Vector2{ -1,0 };
	}
	if (GET_SINGLE(KeyManager)->GetKey('D'))
	{
		direction = direction + Vector2{ 1,0 };
	}
	if (!(direction.x == 0 && direction.y == 0))
	{
		this->Move(direction);
	}
}
void Player::Render(HDC hdc)
{
	Draw::Rect(hdc, _body);
}
void Player::Release()
{

}
void Player::Move(Vector2 direction)
{
	cout << "move" << endl;
	direction.Normalize();
	_body.x += direction.x * _speed * DeltaTime;
	_body.y += direction.y * _speed * DeltaTime;
}
