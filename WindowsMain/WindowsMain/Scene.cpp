#include "stdafx.h"
#include "Scene.h"
void Scene::Init()
{
	_player = Rect::MakeCenterRect(100, 100, 100, 100);
	_speed = 300;
}
void Scene::Render(HDC hdc)
{
	Draw::Rect(hdc, _player);
	for (int i = 0; i < _missile.size(); i++)
	{
		_missile[i]->Render(hdc);
	}
}
void Scene::Update()
{
	if (GET_SINGLE(KeyManager)->GetKey(VK_UP))
	{
		_player.y -= _speed*GET_SINGLE(TimeManager)->GetDeltaTime();
	}
	if (GET_SINGLE(KeyManager)->GetKey(VK_DOWN))
	{
		_player.y += _speed * GET_SINGLE(TimeManager)->GetDeltaTime();

	}
	if (GET_SINGLE(KeyManager)->GetKey(VK_LEFT))
	{
		_player.x -= _speed * GET_SINGLE(TimeManager)->GetDeltaTime();

	}
	if (GET_SINGLE(KeyManager)->GetKey(VK_RIGHT))
	{
		_player.x += _speed * GET_SINGLE(TimeManager)->GetDeltaTime();
	}
	if (GET_SINGLE(KeyManager)->GetKey(VK_LBUTTON))
	{
		Projectile* projectile = new Projectile();
		Vector2 spawnPos = { _player.x,_player.y };
		Vector2 mousePostion = { _mousePos.x,_mousePos.y };
		Vector2 direction = mousePostion - spawnPos;
		direction.Normalize();

		projectile->Init(spawnPos, direction);
		_missile.push_back(projectile);

	}
	for (int i = 0; i < _missile.size(); i++)
	{
		_missile[i]->Update();
	}
}
void Scene::Release()
{
	for (int i = 0; i < _missile.size(); i++)
	{
		SAFE_DELETE(_missile[i]);
	}
	_missile.clear();
}


void Projectile::Init(Vector2 spawnPos, Vector2 direction)
{
	_body = Rect::MakeCenterRect(spawnPos.x, spawnPos.y, 30, 30);
	_speed = 100;
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
