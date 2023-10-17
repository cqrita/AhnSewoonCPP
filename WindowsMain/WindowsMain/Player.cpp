#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "Scene.h"
#include "BoxCollider.h"
void Player::Init()
{
	Super::Init();
	this->SetName("Player");

	_missileStat = 1;
}
void Player::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Player::Update()
{
	Super::Update();
	Vector2 direction{0,0};
	if (GET_SINGLE(KeyManager)->GetKey('W'))
	{
		direction = direction+ Vector2{0,-1};
	}
	if (GET_SINGLE(KeyManager)->GetKey('S'))
	{
		direction = direction + Vector2{ 0,1 };
	}
	if (GET_SINGLE(KeyManager)->GetKey('A'))
	{
		direction = direction + Vector2{ -1,0 };
	}
	if (GET_SINGLE(KeyManager)->GetKey('D'))
	{
		direction = direction + Vector2{ 1,0 };
	}
	if (!(direction.x==0&&direction.y==0))
	{
		direction.Normalize();
		Move(direction);
	}
	if (GET_SINGLE(KeyManager)->GetKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < _missileStat; i++)
		{
			Bullet* bullet = new Bullet();
			bullet->Init();
			Vector2 direction;
			direction.x = 0;
			direction.y = -1;
			float centerX = _body.x;
			float maxWidth = (_missileStat-1) * 70;
			float temp2 = centerX-maxWidth/2+i*10;
			bullet->SetBulletInfo(direction, 300, Rect::MakeCenterRect(_body.x+i*70, _body.y, 10, 10), L"../Resources/Power Ups/Power Up.png");
			{
				BoxCollider* collider = new BoxCollider();
				collider->SetCollision(Rect::MakeCenterRect(0, 0, 20, 20));
				collider->Init();
				bullet->AddComponent(collider);
			}
			GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(bullet);
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
void Player::SetPlayerInfo(int speed,CenterRect body,const WCHAR* spritePath)
{
	_speed = speed;
	_body = body;
	SetSprite(spritePath, _body);
}

void Player::OnComponentBeginOverlap(class Collider* collider, class Collider* other)
{

}
void Player::OnComponentEndOverlap(class Collider* collider, class Collider* other)
{

}