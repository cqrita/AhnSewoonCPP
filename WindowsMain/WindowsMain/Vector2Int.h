#pragma once

struct Vector2Int
{
	int x = 0;
	int y = 0;
	Vector2Int();
	Vector2Int(int x, int y);
	Vector2Int(Vector2 vector);
	Vector2Int(POINT point);

	Vector2Int operator+(const Vector2Int& other);
	Vector2Int operator-(const Vector2Int& other);
	Vector2Int operator*(int32 value);
	Vector2Int operator*(float value);
	void operator+=(const Vector2Int& other);
	void operator-=(const Vector2Int& other);
	void operator*=(int32 value);
	int32 LengthSquared();
	float Length();
	int32 Dot(Vector2Int other);

	static Vector2Int Lerp(Vector2Int startValue, Vector2Int endValue, float t)
	{
		Vector2Int rv = startValue * (1-t) + endValue * t;
		return rv;
	}

};