#include "stdafx.h"
#include "Scene.h"
#include "Enemy.h"
#include "Player.h"
#include "Projectile.h"
void Scene::Init()
{
	_player = new Player();
	_player->Init();
	_generateTime = 0;
}
void Scene::Render(HDC hdc)
{
	_player->Render(hdc);
	for (int i = 0; i < _enemies.size(); i++)
	{
		_enemies[i]->Render(hdc);
	}
	char str[250];
	sprintf_s(str,"HITS : %-3d",_score);
	TextOut(hdc, WIN_SIZE_WIDTH-100, WIN_SIZE_HEIGHT-100, str, strlen(str));
}
void Scene::Update()
{
	this->CheckGameState();
	this->GenerateEnemy();
	this->OnCollisionEnemyProjectile();
	_player->Update();

	for (int i = 0; i < _enemies.size(); i++)
	{
		_enemies[i]->Update();
	}
}
void Scene::Release()
{
	_player->Release();
	SAFE_DELETE(_player);
	for (int i = 0; i < _enemies.size(); i++)
	{
		_enemies[i]->Release();
		SAFE_DELETE(_enemies[i]);
	}

}


void Scene::GenerateEnemy()
{
	//spawn time check
	//monster generate
	_generateTime += DeltaTime;
	if (_generateTime > 0.5)
	{
		Enemy* enemy = new Enemy();
		enemy->Init(Vector2{ Random::GetFloat(0,WIN_SIZE_WIDTH),0 });
		_enemies.push_back(enemy);
		_generateTime -= 0.5f;
	}
}
void Scene::CheckGameState()
{
	if (10 <=_score)
	{
		MessageBox(_hwnd, "LOSE", "GAMESTATE", NULL);
	}
}
void Scene::OnCollisionEnemyProjectile()
{
	RECT temp;
	for (int i = 0; i < _enemies.size(); i++)
	{
		RECT enemyCollision = _enemies[i]->GetCollision().ToRect();
		RECT playerCollision = _player->GetCollision().ToRect();
		if (IntersectRect(&temp,&enemyCollision,&playerCollision))
		{
			_enemies[i]->Release();
			SAFE_DELETE(_enemies[i]);
			_enemies.erase(_enemies.begin() + i);
			_score++;
		}
		if (enemyCollision.bottom == WIN_SIZE_HEIGHT)
		{
			_enemies[i]->Release();
			SAFE_DELETE(_enemies[i]);
			_enemies.erase(_enemies.begin() + i);
		}
	}
}
