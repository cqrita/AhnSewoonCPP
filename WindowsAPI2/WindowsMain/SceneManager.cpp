#include "stdafx.h"
#include "SceneManager.h"
#include "Scene.h"
void SceneManager::Init()
{
	_scene = new Scene();
	_scene->Init();
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
void SceneManager::ChangeScene()
{

}
