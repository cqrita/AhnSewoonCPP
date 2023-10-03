#include "stdafx.h"
#include "Dev1Scene.h"
#include "Actor.h"
#include "Player.h"
#include "SpriteActor.h"
#include "Enemy.h"
#include "Bullet.h"
void Dev1Scene::Init()
{
	_player = new Player();
	_player->Init();
	_player->SetPlayerInfo(300, Rect::MakeCenterRect(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2, 100,100), L"../Resources/Player Ships/Short-Lazer-Ship.png");
	_EnemySpawnRate = 1;
	_EnemySpawnTimer = 0;
	_score = 0;
	_hit = 0;
}
void Dev1Scene::Render(HDC hdc)
{
	for (int i = 0; i < _actors.size(); i++)
	{
		_actors[i]->Render(hdc);
	}
	_player->Render(hdc);
	
	char str[250];
	sprintf_s(str, "DEV1SCENE");
	TextOut(hdc, 0, WIN_SIZE_HEIGHT - 50, str, strlen(str));
	string score = "score: " + to_string(_score);
	string hit = "hit: " + to_string(_hit);
	TextOut(hdc, WIN_SIZE_WIDTH - 100, 0, score.c_str(), score.length());
	TextOut(hdc, WIN_SIZE_WIDTH - 100, 20, hit.c_str(), hit.length());
	//scene objects
}
void Dev1Scene::Update()
{
	for (int i = 0; i < _actors.size(); i++)
	{
		_actors[i]->Update();
	}
	_player->Update();
	SpawnEnemy();
	Collision();
}
void Dev1Scene::Release()
{

	_player->Release();
	SAFE_DELETE(_player);

	for (int i = 0; i < _actors.size(); i++)
	{
		_actors[i]->Release();
		SAFE_DELETE(_actors[i]);
	}
	_actors.clear();
}
void Dev1Scene::SpawnEnemy()
{
	_EnemySpawnTimer += DeltaTime;
	if (_EnemySpawnTimer > _EnemySpawnRate)
	{
		_EnemySpawnTimer = 0;
		Enemy* enemy = new Enemy();
		enemy->Init();
		enemy->SetEnemyInfo(Vector2(0, 1), 300, Rect::MakeCenterRect(Random::GetFloat(0, WIN_SIZE_WIDTH), 0, 80, 80), L"../Resources/Enemies/Enemy_01.png");
		SpawnActor(enemy);
		_enemies.push_back(enemy);
	}
}
void Dev1Scene::Collision()
{
	for (int i = 0; i < _enemies.size(); i++)
	{
		RECT enemyCollision = _enemies[i]->GetCollision().ToRect();
		RECT temp;
		for (int j = 0; j < _player->GetBullets().size(); j++)
		{
			RECT bulletCollision = _player->GetBullets()[j]->GetCollision().ToRect();
			if (IntersectRect(&temp, &enemyCollision, &bulletCollision))
			{
				_score++;
				DeSpawnActor(_enemies[i]);
				_enemies[i]->Release();
				SAFE_DELETE(_enemies[i]);
				_enemies.erase(_enemies.begin()+i);
				DeSpawnActor(_player->GetBullets()[j]);
				_player->GetBullets()[j]->Release();
				SAFE_DELETE(_player->GetBullets()[j]);
				_player->DeleteBullet(j);
			}
		}
		RECT playerCollision = _player->GetCollision().ToRect();
		if (IntersectRect(&temp, &enemyCollision, &playerCollision))
		{
			_hit++;
			DeSpawnActor(_enemies[i]);
			_enemies[i]->Release();
			SAFE_DELETE(_enemies[i]);
			_enemies.erase(_enemies.begin() + i);
		}
	}
}