#pragma once
using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;

struct Vector2
{
	float x, y;
	Vector2 operator-(const POINT pt) const
	{
		return Vector2{ static_cast<float>(x - pt.x),static_cast<float>(y - pt.y) };
	}
	Vector2 operator-(const Vector2 other) const
	{
		return Vector2{ x-other.x,y-other.y };
	}
	Vector2 operator-=(const Vector2 other) const
	{
		return Vector2{ x - other.x,y - other.y };
	}

	Vector2 operator+(const Vector2 other) const
	{
		return Vector2{ x + other.x,y + other.y };
	}
	Vector2 operator+=(const Vector2 other) const
	{
		return Vector2{ x + other.x,y + other.y };
	}

	Vector2 operator*(const Vector2 other) const
	{
		return Vector2{ x * other.x,y * other.y };
	}
	Vector2 operator*=(const Vector2 other) const
	{
		return Vector2{ x * other.x,y * other.y };
	}

	Vector2 operator+(const float other) const
	{
		return Vector2{ x + other,y + other };
	}
	Vector2 operator+=(const float other) const
	{
		return Vector2{ x + other,y + other };
	}

	Vector2 operator*(const float other) const
	{
		return Vector2{ x * other,y * other };
	}
	Vector2 operator*=(const float other) const
	{
		return Vector2{ x * other,y * other };
	}



	void Normalize()
	{
		float length = sqrt(x * x + y * y);
		if (length != 0)
		{
			x /= length;
			y /= length;
		}
	}
};
