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
	Vector2()
	{
		x = 0;
		y = 0;
	}
	Vector2(int x, int y)
	{
		x = x;
		y = y;
	}
	Vector2 operator-(const POINT pt) const
	{
		return Vector2{ static_cast<float>(x - pt.x),static_cast<float>(y - pt.y) };
	}
	Vector2 operator-(const Vector2 other) const
	{
		return Vector2{ x-other.x,y-other.y };
	}
	void operator-=(const Vector2 other)
	{
		this->x = this->x - other.x;
		this->y = this->y - other.y;

	}
	Vector2 operator+(const Vector2 other) const
	{
		return Vector2{ x + other.x,y + other.y };
	}
	void operator+=(const Vector2 other) 
	{
		this->x = this->x + other.x;
		this->y = this->y + other.y;
	}

	Vector2 operator*(const Vector2 other) const
	{
		return Vector2{ x * other.x,y * other.y };
	}
	void operator*=(const Vector2 other)
	{
		this->x = this->x * other.x;
		this->y = this->y * other.y;
	}

	Vector2 operator+(const float other) const
	{
		return Vector2{ x + other,y + other };
	}

	Vector2 operator*(const float other) const
	{
		return Vector2{ x * other,y * other };
	}

	float LengthSquared()
	{
		return x * x + y * y;
	}
	float Length()
	{
		return sqrt(LengthSquared());
	}
	Vector2 Normalize()
	{
		float length = sqrt(x * x + y * y);
		if (length > 0.00000001f)
		{
			x /= length;
			y /= length;
		}
		return *this;
	}
	float Dot(Vector2 other)
	{
		return this->x* other.x + this->y * other.y;
	}
	Vector2 Reflect(Vector2 normal)
	{
		normal.Normalize();
		Vector2 origin = *this;
		origin.Normalize();
		Vector2 result = origin - normal*(normal.Dot(origin) * 2);
		return result;
	}

	float SignedAngle(Vector2 other) const
	{
		other.Normalize();
		Vector2 origin = *this;
		origin.Normalize();
		float cosTheta = other.Dot(origin);
		float angle = acos(cosTheta);
		float sign = origin.x * other.y - origin.y * other.x;
		if (sign < 0)
		{
			angle = -angle;
		}
		return angle;
	}


	static Vector2 Zero()
	{
		return Vector2{ 0,0 };
	}
	static Vector2 Right()
	{
		return Vector2{ 1,0 };
	}
	static Vector2 Up()
	{
		return Vector2{ 0,-1 };
	}
	static Vector2 Left()
	{
		return Vector2{ 0,1};
	}
	static Vector2 Down()
	{
		return Vector2{ -1,0 };
	}



};
/*
sin 60 r3/2
cos 30 r3/2
cos 60 1/2
tan 30 1/r3
*/

/*


 
*/