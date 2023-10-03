#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "Scene.h"
void Player::Init()
{
	Super::Init();
}
void Player::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Player::Update()
{
	Super::Update();
	Vector2 direction{0,0};
	if (GET_SINGLE(KeyManager)->GetKey(VK_UP))
	{
		direction = direction+ Vector2{0,-1};
	}
	if (GET_SINGLE(KeyManager)->GetKey(VK_DOWN))
	{
		direction = direction + Vector2{ 0,1 };
	}
	if (GET_SINGLE(KeyManager)->GetKey(VK_LEFT))
	{
		direction = direction + Vector2{ -1,0 };
	}
	if (GET_SINGLE(KeyManager)->GetKey(VK_RIGHT))
	{
		direction = direction + Vector2{ 1,0 };
	}
	if (!(direction.x==0&&direction.y==0))
	{
		direction.Normalize();
		Move(direction);
	}
	if (GET_SINGLE(KeyManager)->GetKeyDown('Z'))
	{
		for (int i = -1; i <= 1; i++)
		{
			Bullet* bullet = new Bullet();
			bullet->Init();
			bullet->SetBulletInfo(Vector2(i, -1), 300, Rect::MakeCenterRect(_body.x+i, _body.y, 10, 10), L"../Resources/Power Ups/Power Up.png");
			GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(bullet);
			_bullets.push_back(bullet);
		}
	}
	if (GET_SINGLE(KeyManager)->GetKeyDown('X'))
	{

		Bullet* bullet = new Bullet();
		bullet->Init();
		bullet->SetBulletInfo(Vector2(sin(90/DeltaTime), -1), 300, Rect::MakeCenterRect(_body.x, _body.y, 10, 10), L"../Resources/Power Ups/Power Up.png");
		GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(bullet);
		_bullets.push_back(bullet);
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
void Player::SetPlayerInfo(int speed,CenterRect body,const WCHAR* spritePath)
{
	_speed = speed;
	_body = body;
	SetSprite(spritePath, _body);
}