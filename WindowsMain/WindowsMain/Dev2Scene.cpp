#include "stdafx.h"
#include "Dev2Scene.h"
void Dev2Scene::Init()
{

}
void Dev2Scene::Render(HDC hdc)
{
	char str[250];
	sprintf_s(str, "DEV2SCENE");
	TextOut(hdc, 0, WIN_SIZE_HEIGHT-50, str, strlen(str));
}
void Dev2Scene::Update()
{

}
void Dev2Scene::Release()
{

}
