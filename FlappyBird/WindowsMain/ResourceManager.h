#pragma once
class ResourceManager
{
public:
	DECLARE_SINGLE(ResourceManager)
public:
	void Init();
	void Release();
	class Sprite* GetSprite(const string& key);
	class Sprite* CreateSprite(const string& key, class Texture* texture, int x= 0, int y=0, int cx=0, int cy=0);
	class Texture* GetTexture(const string& key);
	class Texture* LoadTexture(const string& key,const string& path, uint32 transparent=RGB(255,0,255));
	class Flipbook* GetFlipbook(const string& key);
	class Flipbook* CreateFlipbook(const string& key,struct FlipbookInfo info);

private:
	string _resourcePath;
	map<string, class ResourceBase*> _resources;
};

