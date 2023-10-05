#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "Scene.h"
#include "BoxCollider.h"
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
		Bullet* bullet = new Bullet();
		bullet->Init();
		bullet->SetBulletInfo(Vector2(0, -1), 300, Rect::MakeCenterRect(_body.x, _body.y, 10, 10), L"../Resources/Power Ups/Power Up.png");
		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Rect::MakeCenterRect(0, 0, 20, 20));
			collider->Init();
			bullet->AddComponent(collider);
		}
		GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(bullet);
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