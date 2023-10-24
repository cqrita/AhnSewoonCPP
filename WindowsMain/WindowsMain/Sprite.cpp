#include "stdafx.h"
#include "Sprite.h"
#include "Texture.h"
Sprite::Sprite(Texture* texture, int x, int y, int cx, int cy)
	:_texture(texture), _x{ x }, _y{ y }, _cx{ cx }, _cy{ cy }
{

}

Sprite::~Sprite()
{

}

HDC Sprite::GetDC()
{
	return _texture->GetDc();
}

int32 Sprite::GetTransparent()
{
	return _texture->GetTransparent();
}
