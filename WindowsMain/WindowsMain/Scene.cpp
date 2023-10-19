#include "stdafx.h"
#include "Scene.h"
#include "Actor.h"
void Scene::Init()
{

}
void Scene::Render(HDC hdc)
{

}
void Scene::Update()
{

}
void Scene::Release()
{

}
void Scene::SpawnActor(class Actor* actor)
{
	_actors.push_back(actor);
}
void Scene::DeSpawnActor(class Actor* actor)
{
	actor->Release();
	_actors.erase(remove(_actors.begin(), _actors.end(), actor), _actors.end());
	SAFE_DELETE(actor);
}
