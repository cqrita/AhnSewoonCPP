#include "stdafx.h"
#include "Texture.h"

Texture::Texture()
{
}

Texture::~Texture()
{
}

Texture* Texture::LoadBmp(const string& path)
{
	HDC hdc = ::GetDC(_hwnd);
	_hdc = CreateCompatibleDC(hdc);
	std::wstring widestr = std::wstring(path.begin(), path.end());
	Gdiplus::Bitmap* bitmap = Gdiplus::Bitmap::FromFile(widestr.c_str(), false);
	bitmap->GetHBITMAP(_transparent, &_bitmap);
	if (_bitmap == NULL)
	{
		MessageBox(_hwnd, path.c_str(), "Image Load Failed!", NULL);
		return nullptr;
	}
	HBITMAP prev=SelectBitmap(_hdc, _bitmap);
	DeleteBitmap(prev);
	BITMAP bit = {};
	GetBitmapBits(_bitmap, sizeof(BITMAP), &_bitmap);
	_size.x = bit.bmWidth;
	_size.y = bit.bmHeight;
	cout << path << endl;
	SAFE_DELETE(bitmap);
	return this;
}
