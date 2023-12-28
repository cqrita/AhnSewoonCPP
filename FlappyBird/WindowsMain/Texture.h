#pragma once
#include "ResourceBase.h"
class Texture : public ResourceBase
{
protected:
	HDC _hdc;
	HBITMAP _bitmap{};
	Vector2Int _size{};
	uint32 _transparent = RGB(255, 0, 255);
public:
	Texture();
	virtual ~Texture();
public:
	Texture* LoadBmp(const string& path);
	void SetSize(Vector2 size) { _size = size; }
	Vector2Int GetSize() { return _size; }
	void SetTransparent(uint32 transparent) { _transparent = transparent; }
	uint32 GetTransparent() { return _transparent; }
	HDC GetDc() { return _hdc; }
};

