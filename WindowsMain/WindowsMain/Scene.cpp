#include "stdafx.h"
#include "Scene.h"
#include "Projectile.h"
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
	if (GET_SINGLE(KeyManager)->GetKey('W'))
	{
		_player.y -= _speed*GET_SINGLE(TimeManager)->GetDeltaTime();
	}
	if (GET_SINGLE(KeyManager)->GetKey('S'))
	{
		_player.y += _speed * GET_SINGLE(TimeManager)->GetDeltaTime();
	}
	if (GET_SINGLE(KeyManager)->GetKey('A'))
	{
		_player.x -= _speed * GET_SINGLE(TimeManager)->GetDeltaTime();
	}
	if (GET_SINGLE(KeyManager)->GetKey('D'))
	{
		_player.x += _speed * GET_SINGLE(TimeManager)->GetDeltaTime();
	}
	if (GET_SINGLE(KeyManager)->GetKeyDown(VK_LBUTTON))
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


