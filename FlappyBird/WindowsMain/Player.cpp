#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "Scene.h"
#include "BoxCollider.h"
#include "CircleCollider.h"
#include "Texture.h"
#include "Flipbook.h"
void Player::Init()
{
	Super::Init();
	SetFlipbook(_moveFlipbook[int(ePlayerDirection::NORMAL)]);
	this->SetName("Player");
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
void Player::SetPlayerInfo(CenterRect body,double gravity, float jump)
{
	_body = body;
	_gravity = gravity;
	_score = 0;
	_jump = jump;
	GET_SINGLE(ResourceManager)->LoadTexture("T_playerUp", "image/bird/bird_up.bmp", RGB(255, 0, 255));
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_playerUp");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 2;
		info.line = 0;
		info.loop = true;
		info.size = { 80, 80 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_playerUp", info);
	}
	_moveFlipbook[int(ePlayerDirection::UP)]= GET_SINGLE(ResourceManager)->GetFlipbook("FB_playerUp");

	GET_SINGLE(ResourceManager)->LoadTexture("T_playerDown", "image/bird/bird_down.bmp", RGB(255, 0, 255));
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_playerDown");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 2;
		info.line = 0;
		info.loop = true;
		info.size = { 80, 80 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_playerDown", info);
	}
	_moveFlipbook[int(ePlayerDirection::DOWN)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_playerDown");


	Texture* normalTexture = GET_SINGLE(ResourceManager)->LoadTexture("T_playerNormal", "image/bird/bird_normal.bmp", RGB(255, 0, 255));
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_playerNormal");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 2;
		info.line = 0;
		info.loop = true;
		info.size = { 80, 80 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_playerNormal", info);
	}
	_moveFlipbook[int(ePlayerDirection::NORMAL)] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_playerNormal");

	SetFlipbook(_moveFlipbook[int(ePlayerDirection::NORMAL)]);

	{
		_collider = new CircleCollider();
		_collider->SetCollision(Circle::MakeCenterCircle(0, 0, 15));
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
		_velocity = _velocity + Vector2{ 0,-_jump };
	}
}


void Player::UpdateJumpFall()
{
	if (_velocity.y > 10)
	{
		SetFlipbook(_moveFlipbook[int(ePlayerDirection::DOWN)]);
	}
	else if (_velocity.y < -10)
	{
		SetFlipbook(_moveFlipbook[int(ePlayerDirection::UP)]);
	}
	else
	{
		SetFlipbook(_moveFlipbook[int(ePlayerDirection::NORMAL)]);
	}
}


void Player::UpdateGravity()
{
	_velocity.y -= _gravity*DeltaTime*50;
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
			PostQuitMessage(0);
		}
	}
}
void Player::OnComponentEndOverlap(class Collider* collider, class Collider* other)
{

}