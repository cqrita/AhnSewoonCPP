#include "stdafx.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Sprite.h"
void ResourceManager::Init()
{
	_resourcePath = "../Resources/";
}

void ResourceManager::Release()
{
	for (auto& item : _resources)
	{
		SAFE_DELETE(item.second);
	}
	_resources.clear();
}

Sprite* ResourceManager::GetSprite(const string& key)
{
	return static_cast<Sprite*>(_resources[key]);
}

Sprite* ResourceManager::CreateSprite(const string& key, Texture* texture, int x, int y, int cx, int cy)
{
	if (_resources.contains(key))
	{
		return GetSprite(key);
	}
	if (cx == 0)
	{
		cx = texture->GetSize().x;
	}
	if (cy == 0)
	{
		cy = texture->GetSize().y;
	}
	Sprite* sprite = new Sprite(texture, x, y, cx, cy);
	_resources[key] = sprite;
	return sprite;
}

Texture* ResourceManager::GetTexture(const string& key)
{
	return static_cast<Texture*>(_resources[key]);
}

Texture* ResourceManager::LoadTexture(const string& key, const string& path, uint32 transparent)
{
	//_resources
	if (_resources.contains(key))
	{
		return GetTexture(key);
	}
	string fullPath = _resourcePath + path;
	Texture* texture = new Texture();
	texture->SetTransparent(transparent);
	texture->LoadBmp(fullPath);
	_resources[key] = texture;
	return texture;
}
