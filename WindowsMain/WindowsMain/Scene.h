#pragma once
class Scene
{
public:
	vector<class Actor*> _actors;
	vector<class UI*> _UIs;

	Vector2Int _cameraPosition{};
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
public:
	void SpawnActor(class Actor* Actor);
	void DeSpawnActor(class Actor* Actor);
public:
	void SetCameraPos(Vector2Int pos) { _cameraPosition = pos; }
	Vector2Int GetCameraPos() { return _cameraPosition; }
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