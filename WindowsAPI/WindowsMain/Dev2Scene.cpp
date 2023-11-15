#include "stdafx.h"
#include "Dev2Scene.h"
#include "Wall.h"
#include "Mario.h"
#include "BoxCollider.h"
#include "CameraComponent.h"
#include "SpriteActor.h"
#include "Texture.h"
#include "Sprite.h"
void Dev2Scene::Init()
{
	{
		SpriteActor* background = new SpriteActor();
		background->SetLayer(LayerType::Background);
		Texture* texture = GET_SINGLE(ResourceManager)->LoadTexture("T_background", "Background/backround_supermario.bmp", RGB(255, 0, 255));
		Sprite* sprite = GET_SINGLE(ResourceManager)->CreateSprite("S_background", texture);
		background->SetSprite(sprite);
		background->SetBody(Rect::MakeCenterRect(WIN_SIZE_WIDTH * 3.5, 0, WIN_SIZE_WIDTH * 8, WIN_SIZE_HEIGHT));
		SpawnActor(background);
	}

	{
		Mario* mario = new Mario();
		mario->SetPlayerInfo(500, Rect::MakeCenterRect(WIN_SIZE_WIDTH / 2, 200, 200, 200));
		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Rect::MakeCenterRect(0,0,100,100));
			collider->SetCollisionLayer(CollisionLayerType::CLT_OBJECT);
			collider->AddCollisionFlagLayer(CollisionLayerType::CLT_GROUND);
			collider->AddCollisionFlagLayer(CollisionLayerType::CLT_OBJECT);
			collider->AddCollisionFlagLayer(CollisionLayerType::CLT_WALL);
			mario->AddComponent(collider);
		}
		{
			CameraComponent* camera = new CameraComponent();
			mario->AddComponent(camera);
		}
		GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(mario);
	}

	vector<RECT> walls = GET_SINGLE(DataManager)->GetCollisionData();
	for (RECT rc : walls)
	{
		Wall* wall = new Wall();
		rc.left -= WIN_SIZE_WIDTH/2;
		rc.right -= WIN_SIZE_WIDTH/2;
		rc.top -= WIN_SIZE_HEIGHT / 2;
		rc.bottom -= WIN_SIZE_HEIGHT / 2;


		wall->SetWallInfo(rc);
		GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(wall);
	}

	Super::Init();
}
void Dev2Scene::Render(HDC hdc)
{
	Super::Render(hdc);
	char str[250];
	sprintf_s(str, "DEV2SCENE");
	TextOut(hdc, 0, WIN_SIZE_HEIGHT-50, str, strlen(str));
}
void Dev2Scene::Update()
{
	Super::Update();
}
void Dev2Scene::Release()
{
	Super::Release();
}
