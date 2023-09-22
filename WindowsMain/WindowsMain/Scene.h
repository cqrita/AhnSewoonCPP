#pragma once
class Scene
{
private:
	vector<class Enemy*> _enemies;
	class Player* _player;
	int _score;
private:
	float _generateTime=0.0f;
public:
	void GenerateEnemy();
	void CheckGameState();
	void OnCollisionEnemyProjectile();
public:
	void Init();
	void Render(HDC hdc);
	void Update();
	void Release();
};


//Enemy
//
//Projectile
//Player
//move
//shot
// has a projectile
//scene
//generate enemy
// collision
//check game state
//has a player enemy