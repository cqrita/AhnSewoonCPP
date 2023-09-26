#pragma once
class Scene
{
public:
	vector<class Actor*> _actors;

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
public:
	void SpawnActor(class Actor* Actor);
	void DeSpawnActor(class Actor* Actor);
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