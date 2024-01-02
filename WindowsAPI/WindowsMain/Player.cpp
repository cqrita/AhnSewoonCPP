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
	_score = 0;

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

	{
		_collider = new BoxCollider();
		_collider->SetCollision(Rect::MakeCenterRect(0, 0, 50, 50));
		_collider->SetCollisionLayer(CollisionLayerType::CLT_OBJECT);
		_collider->AddCollisionFlagLayer(CollisionLayerType::CLT_OBJECT);
		_collider->AddCollisionFlagLayer(CollisionLayerType::CLT_WALL);
		this->AddComponent(_collider);
	}
	{
		_scoreBox = new BoxCollider();
		_scoreBox->SetCollision(Rect::MakeCenterRect(0, -WIN_SIZE_HEIGHT/2, 2, WIN_SIZE_HEIGHT));
		_scoreBox->SetCollisionLayer(CollisionLayerType::CLT_OBJECT);
		_scoreBox->AddCollisionFlagLayer(CollisionLayerType::CLT_OBJECT);
		_scoreBox->AddCollisionFlagLayer(CollisionLayerType::CLT_WALL);
		this->AddComponent(_scoreBox);
	}
}

void Player::UpdateInput()
{
	if (GET_SINGLE(KeyManager)->GetKeyDown(VK_SPACE))
	{
		_velocity = _velocity + Vector2{ 0,-250 };
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
	_velocity.y -= _gravity*0.35;
}


void Player::OnComponentBeginOverlap(class Collider* collider, class Collider* other)
{
	if (other->GetCollisionLayer()==CollisionLayerType::CLT_WALL)
	{
		if (collider==_scoreBox)
		{
			_score++;
		}
		if (collider==_collider)
		{
			Alert(("SCORE : " + to_string(_score)).c_str(), "GAME END");
		}
	}
}
void Player::OnComponentEndOverlap(class Collider* collider, class Collider* other)
{

}