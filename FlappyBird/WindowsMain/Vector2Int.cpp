#include "stdafx.h"
#include "Vector2Int.h"

Vector2Int::Vector2Int() { x = 0; y = 0; }
Vector2Int::Vector2Int(int x, int y) : x(x), y(y) {}
Vector2Int::Vector2Int(Vector2 vector)
{
	x = static_cast<int>(vector.x);
	y = static_cast<int>(vector.y);
}
Vector2Int::Vector2Int(POINT point)
{
	x = point.x;
	y = point.y;
}

Vector2Int Vector2Int::operator+(const Vector2Int& other)
{
	Vector2Int rv;
	rv.x = this->x + other.x;
	rv.y = this->y + other.y;
	return rv;
}

Vector2Int Vector2Int::operator-(const Vector2Int& other)
{
	Vector2Int rv;
	rv.x = this->x - other.x;
	rv.y = this->y - other.y;
	return rv;
}
Vector2Int Vector2Int::operator*(int32 value)
{
	Vector2Int rv;
	rv.x = this->x * value;
	rv.y = this->y * value;
	return rv;
}
Vector2Int Vector2Int::operator*(float value)
{
	Vector2Int rv;
	rv.x = this->x * value;
	rv.y = this->y * value;
	return rv;
}
void Vector2Int::operator+=(const Vector2Int& other)
{
	this->x += other.x;
	this->y += other.y;
}
void Vector2Int::operator-=(const Vector2Int& other)
{
	this->x -= other.x;
	this->y -= other.y;
}
void Vector2Int::operator*=(int32 value)
{
	this->x *= value;
	this->y *= value;
}

int32 Vector2Int::LengthSquared()
{
	return x * x + y * y;
}

float Vector2Int::Length()
{
	return sqrtf(static_cast<float>(LengthSquared()));
}

int32 Vector2Int::Dot(Vector2Int other)
{
	return x * other.x + y * other.y;
}