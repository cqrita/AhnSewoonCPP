#include "stdafx.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Dev1Scene.h"
#include "Dev2Scene.h"
#include "MapToolScene.h"
void SceneManager::Init()
{

}
void SceneManager::Render(HDC hdc)
{
	if (_scene)
	{
		_scene->Render(hdc);
	}
}
void SceneManager::Update()
{
	if (_scene)
	{
		_scene->Update();
	}

}
void SceneManager::Release()
{
	if (_scene)
	{
		_scene->Release();
	}
	SAFE_DELETE(_scene)
}
void SceneManager::ChangeScene(SceneType sceneType)
{
	if (_sceneType == sceneType)
	{
		return;
	}
	Scene* newScene = nullptr;
	switch (sceneType)
	{
	case SceneType::Dev1Scene:
		newScene = new Dev1Scene();
		break;
	case SceneType::Dev2Scene:
		newScene = new Dev2Scene();
		break;
	case SceneType::MapToolScene:
		newScene = new MapToolScene();
		break;

	default:
		break;
	}
	if (_scene != nullptr)
	{
		_scene->Release();
		SAFE_DELETE(_scene);
	}
	_scene = newScene;
	_sceneType = sceneType;
	_scene->Init();
}
