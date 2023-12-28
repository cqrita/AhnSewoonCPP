#pragma once
struct Vector2Int;
struct Vector2
{
	float x, y;

	Vector2 operator-(const POINT pt);
	Vector2 operator-(const Vector2 other);
	Vector2 operator-(Vector2Int other);
	void operator-=(const Vector2 other);
	Vector2 operator+(const Vector2 other);
	void operator+=(const Vector2 other);
	Vector2 operator*(const float other);
	void operator*=(const float other);
	Vector2 operator/(const float other);
	void operator/=(const float other);
	float LengthSquared();
	float Length();
	Vector2 Normalize();
	float Dot(Vector2 other);
	Vector2 Reflect(Vector2 normal);
	float SignedAngle(Vector2 other);


	Vector2(float x, float y);
	Vector2();
	Vector2(Vector2Int vec);
	static Vector2 Zero()
	{
		return Vector2{ 0, 0 };
	}

	static Vector2 Up()
	{
		return Vector2{ 0, -1 };
	}

	static Vector2 Down()
	{
		return Vector2{ 0, 1 };
	}

	static Vector2 Right()
	{
		return Vector2{ 1, 0 };
	}

	static Vector2 Left()
	{
		return Vector2{ -1, 0 };
	}
	static Vector2 Lerp(Vector2 startValue, Vector2 endValue, float t)
	{
		Vector2 rv = startValue * (1 - t) + endValue * t;
		return rv;
	}

};