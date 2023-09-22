#include "stdafx.h"
#include "Enemy.h"
void Enemy::Init(Vector2 position)
{
	_body = Rect::MakeCenterRect(position.x, position.y, 70, 70);
}
void Enemy::Update()
{

}
void Enemy::Render(HDC hdc)
{
	Draw::Rect(hdc, _body);
}
void Enemy::Release()
{

}
