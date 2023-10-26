#include "stdafx.h"
#include "Vector2.h"
#include "Vector2Int.h"


Vector2 Vector2::operator-(const POINT pt)
{
	return Vector2{ static_cast<float>(x - pt.x),  static_cast<float>(y - pt.y) };
}

Vector2 Vector2::operator-(const Vector2 other)
{
	return Vector2{ x - other.x, y - other.y };
}

Vector2 Vector2::operator-(Vector2Int other)
{
	return Vector2{ x - other.x, y - other.y };
}

void Vector2::operator-=(const Vector2 other)
{
	x -= other.x;
	y -= other.y;
}

Vector2 Vector2::operator+(const Vector2 other)
{
	return Vector2{ x + other.x, y + other.y };
}

void Vector2::operator+=(const Vector2 other)
{
	x += other.x;
	y += other.y;
}

Vector2 Vector2::operator*(const float other)
{
	return Vector2{ x * other, y * other };
}

void Vector2::operator*=(const float other)
{
	x *= other;
	y *= other;
}


Vector2 Vector2::operator/(const float other)
{
	return Vector2{ x / other, y / other };
}

void Vector2::operator/=(const float other)
{
	x /= other;
	y /= other;
}

float Vector2::LengthSquared()
{
	return x * x + y * y;
}

float Vector2::Length()
{
	return ::sqrt(LengthSquared());
}

Vector2 Vector2::Normalize()
{
	float length = Length();
	if (length > 0.00000000001f)
	{
		x /= length;
		y /= length;
	}

	return *this;
}


//�������δ� �ַ� ���� ����ҋ� ���̾��δ�.
//A Dot B = A.x * B.x + A.y * B.y
//A Dot B = |A||B|cos(theta) 
//  -> A B �Ѵ� ���̰� 1�̸� cos(theta)�� ���´�.
//  -> cos(theta)�� �κ��Ͱ� �̷�� ������ ��Ÿ����.
//  -> �� �κ��Ͱ� �̷�� ������ ���Ҷ� ������ ����Ѵ�.
//  Tip1. 
//   -  cos �׷�����
//   -  0�� �϶� 1, 90�� �϶� 0, 180�� �϶� -1 �̴�.
//  Tip2. 
//   - �������� 180�� �Ѵ� ������ ������ �� ����.
//  Tip3.
//   - other ���Ͱ� �� �ڿ� �ִ��� Ȯ���Ϸ���
//   - ������ 0���� ������ �� �ڿ� �ִ�. (90���� �Ѿ��)
float Vector2::Dot(Vector2 other)
{
	return x * other.x + y * other.y;
}

// 2D�� ������ �� �� ����.
// ������ �� Vector �� ���� Vector�� ���Ҷ� ����Ѵ�.


//������ �ݻ�
// 1. �������Ϳ� ������ ���Ѵ�.
// 2. ������ ���Ѱ��� 2�� ���Ѵ�.
// 3. 2���� ���Ѱ��� ���� ���Ϳ��� ����.

/*
Original Vector
	  ^
	  |
	  /
	 /
	/      Normal
   /      /
  +------->
  \
   \
	\
	 \  Reflected Vector
	  \
	   V

*/
Vector2 Vector2::Reflect(Vector2 normal)
{
	normal.Normalize();
	Vector2 original = *this;
	original.Normalize();

	return original - normal * 2 * this->Dot(normal);
}


float Vector2::SignedAngle(Vector2 other)
{
	other.Normalize();
	Vector2 original = *this;
	original.Normalize();

	float dotValue = original.Dot(other);
	if (abs(dotValue - 1.0f) < EPSILON)
	{
		return 0;
	}

	float angle = ::acos(dotValue);
	float sign = original.x * other.y - original.y * other.x;
	if (sign < 0)
	{
		angle = -angle;
	}
	return angle;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}
Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}

Vector2::Vector2(Vector2Int vec)
{
	this->x = vec.x;
	this->y = vec.y;
}