#include "stdafx.h"
#include "Scene.h"
#include "Actor.h"
#include "UI.h"
void Scene::Init()
{
	for (UI* ui : _UIs)
	{
		ui->Init();
	}

}
void Scene::Render(HDC hdc)
{
	for (const vector<Actor*> actors: _actors)
	{
		for (Actor* actor : actors)
		{
			actor->Render(hdc);
		}
	}
	for (UI* ui : _UIs)
	{
		ui->Render(hdc);
	}

}
void Scene::Update()
{
	for (const vector<Actor*> actors : _actors)
	{
		for (Actor* actor : actors)
		{
			actor->Update();
		}
	}
	for (UI* ui : _UIs)
	{
		ui->Update();
	}

}
void Scene::Release()
{
	for (UI* ui : _UIs)
	{
		ui->Release();
		SAFE_DELETE(ui);
	}
	_UIs.clear();
	for (vector<Actor*>& actors : _actors)
	{
		for (Actor* actor : actors)
		{
			actor->Release();
			SAFE_DELETE(actor);
		}
		actors.clear();
	}

}
void Scene::SpawnActor(class Actor* actor)
{
	if (actor == nullptr)
	{
		return;
	}
	actor->Init();
	_actors[actor->GetLayer()].push_back(actor);
}
void Scene::DeSpawnActor(class Actor* actor)
{
	if (actor == nullptr)
	{
		return;
	}
	actor->Release();
	vector<Actor* >& vec = _actors[actor->GetLayer()];
	auto findIt = find(vec.begin(), vec.end(), actor);
	if (findIt != vec.end())
	{
		vec.erase(findIt);
	}
	SAFE_DELETE(actor);
}
