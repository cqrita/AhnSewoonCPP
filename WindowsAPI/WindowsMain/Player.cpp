#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "Scene.h"
#include "BoxCollider.h"
#include "Sprite.h"
#include "Texture.h"
void Player::Init()
{
	Super::Init();
	this->SetName("Player");
	SetSprite(_moveSprite[int(ePlayerDirection::NORMAL)]);
	_velocity = Vector2{ 0,0 };
}
void Player::Render(HDC hdc)
{
	Super::Render(hdc);
	
}
void Player::Update()
{
	Super::Update();
	UpdateInput();
	UpdateGravity();
	UpdateJumpFall();
	Move(_velocity);
}
void Player::Release()
{
	Super::Release();

}
void Player::Move(Vector2 direction)
{
	_body.y += direction.y * DeltaTime;
}
void Player::SetPlayerInfo(CenterRect body)
{
	_body = body;
	_gravity = -9.8;


	Texture* upTexture = GET_SINGLE(ResourceManager)->LoadTexture("T_playerUp", "image/bird/bird_Up_0.bmp", RGB(255, 0, 255));
	Sprite* upSprite = GET_SINGLE(ResourceManager)->CreateSprite("S_playerUp", upTexture);
	_moveSprite[int(ePlayerDirection::UP)]= upSprite;

	Texture* downTexture = GET_SINGLE(ResourceManager)->LoadTexture("T_playerDown", "image/bird/bird_Down_0.bmp", RGB(255, 0, 255));
	Sprite* downSprite = GET_SINGLE(ResourceManager)->CreateSprite("S_playerDown", downTexture);
	_moveSprite[int(ePlayerDirection::DOWN)]=downSprite;

	Texture* normalTexture = GET_SINGLE(ResourceManager)->LoadTexture("T_playerNormal", "image/bird/bird_Normal_0.bmp", RGB(255, 0, 255));
	Sprite* normalSprite = GET_SINGLE(ResourceManager)->CreateSprite("S_playerNormal", normalTexture);
	_moveSprite[int(ePlayerDirection::NORMAL)]=normalSprite;

	SetSprite(_moveSprite[int(ePlayerDirection::NORMAL)]);
}

void Player::UpdateInput()
{
	if (GET_SINGLE(KeyManager)->GetKeyDown(VK_SPACE))
	{
		_velocity = _velocity + Vector2{ 0,-100 };
	}
}


void Player::UpdateJumpFall()
{
	if (_velocity.y > 10)
	{
		SetSprite(_moveSprite[int(ePlayerDirection::DOWN)]);
	}
	else if (_velocity.y < -10)
	{
		SetSprite(_moveSprite[int(ePlayerDirection::UP)]);
	}
	else
	{
		SetSprite(_moveSprite[int(ePlayerDirection::NORMAL)]);
	}
}


void Player::UpdateGravity()
{
	_velocity.y -= _gravity*0.3;
}


void Player::OnComponentBeginOverlap(class Collider* collider, class Collider* other)
{
	if (other->GetCollisionLayer()==CollisionLayerType::CLT_WALL)
	{
		Alert("GAME END", "GAME END");
	}
}
void Player::OnComponentEndOverlap(class Collider* collider, class Collider* other)
{

}