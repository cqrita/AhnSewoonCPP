#include "stdafx.h"
#include "Scene.h"
void Scene::Init()
{
	_player = Rect::MakeCenterRect(100, 100, 100, 100);
	_speed = 300;
	_score = 0;
	_spawnRate = 1;
	_spawnTimer = 0;
	_gameState = State::DEFAULT;
}
void Scene::Render(HDC hdc)
{
	if (_gameState == State::WIN)
	{
		string text = "YOU WIN";
		TextOut(hdc, WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2, text.c_str(), text.size());
		return;
	}
	else if (_gameState == State::LOSE)
	{
		string text = "YOU LOSE";
		TextOut(hdc, WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2, text.c_str(), text.size());
		return;
	}
	Draw::Rect(hdc, _player);
	for (int i = 0; i < _missile.size(); i++)
	{
		_missile[i]->Render(hdc);
	}
	for (int i = 0; i < _enemies.size(); i++)
	{
		Draw::Rect(hdc, _enemies[i]);
	}
	string str = "score: " + to_string(_score);
	TextOut(hdc, WIN_SIZE_WIDTH - 100, 0, str.c_str(), str.size());
	
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
	_spawnTimer = _spawnTimer + DeltaTime;
	if (_spawnTimer > _spawnRate&& _gameState == State::DEFAULT)
	{
		_spawnTimer = 0;
		if (_enemies.size() <= 10)
		{
			_enemies.push_back(Rect::MakeRect(rand() % WIN_SIZE_WIDTH, rand() % WIN_SIZE_HEIGHT, 20, 20));
		}
		else
		{
			_gameState = State::LOSE;
		}
	}
	for (int i = 0; i < _missile.size(); i++)
	{
		_missile[i]->Update();
		RECT rc;
		RECT missile = _missile[i]->_body.ToRect();
		for (int j = 0; j < _enemies.size(); j++)
		{
			if (IntersectRect(&rc, &missile, &_enemies[j]))
			{
				_score++;
				SAFE_DELETE(_missile[i]);
				_missile.erase(_missile.begin() + i);
				_enemies.erase(_enemies.begin() + j);
				if (_score >= 10)
				{
					_gameState = State::WIN;
				}
			}
		}
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
	_speed = 500;
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
