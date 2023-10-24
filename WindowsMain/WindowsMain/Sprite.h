#pragma once
#include "ResourceBase.h"
class Sprite : public ResourceBase
{
public:
	Sprite(class Texture* texture, int x, int y, int cx, int cy);
	virtual ~Sprite();
public:
	HDC GetDC();
	int32 GetTransparent();
	Vector2Int GetPos() { return Vector2Int{ _x,_y }; }
	Vector2Int GetSize() { return Vector2Int{ _cx,_cy }; }
protected:
	class Texture* _texture = nullptr;
	int _x;
	int _y;
	int _cx;
	int _cy;
};

