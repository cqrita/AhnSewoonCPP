#include "stdafx.h"
#include "Player.h"
#include "Projectile.h"
void Player::Init()
{
	_body = Rect::MakeCenterRect(300, 300, 100, 100);
	_speed = 100;
}
void Player::Update()
{
	if (GET_SINGLE(KeyManager)->GetKeyDown(VK_LBUTTON))
	{
		this->Shot();
	}
	Vector2 direction = Vector2{ 0,0 };
	if (GET_SINGLE(KeyManager)->GetKey('W'))
	{
		direction = direction+ Vector2{ 0,-1 };
	}
	if (GET_SINGLE(KeyManager)->GetKey('A'))
	{
		direction = direction + Vector2{ -1,0 };
	}
	if (GET_SINGLE(KeyManager)->GetKey('S'))
	{
		direction = direction + Vector2{ 0,1 };

	}
	if (GET_SINGLE(KeyManager)->GetKey('D'))
	{
		direction = direction + Vector2{ 1,0 };
	}
	if (!(direction.x == 0 && direction.y == 0))
	{
		this->Move(direction);
	}
	for (int i = 0; i < _projectiles.size(); i++)
	{
		_projectiles[i]->Update();
	}
}
void Player::Render(HDC hdc)
{
	Draw::Rect(hdc, _body);
	for (int i = 0; i < _projectiles.size(); i++)
	{
		_projectiles[i]->Render(hdc);
	}
}
void Player::Release()
{
	for (int i = 0; i < _projectiles.size(); i++)
	{
		_projectiles[i]->Release();
		SAFE_DELETE(_projectiles[i]);
	}

}
void Player::Shot()
{
	cout << "shot" << endl;
	Projectile* projectile = new Projectile();
	Vector2 projectileDirection = Vector2{ static_cast<float>(_mousePos.x),static_cast<float>(_mousePos.y) } - Vector2{ _body.x,_body.y };
	projectileDirection.Normalize();
	projectile->Init(Vector2{ _body.x,_body.y }, projectileDirection);
	_projectiles.push_back(projectile);
}
void Player::Move(Vector2 direction)
{
	cout << "move" << endl;
	direction.Normalize();
	_body.x += direction.x * _speed * DeltaTime;
	_body.y += direction.y * _speed * DeltaTime;
}
void Player::RemoveProjectile(int index)
{
	_projectiles[index]->Release();
	SAFE_DELETE(_projectiles[index]);

	_projectiles.erase(_projectiles.begin() + index);
}
