#pragma once
#include <math.h>
class Vec3f
{
	float x;
	float y;
	float z;
public:
	Vec3f(float X = 0, float Y = 0, float Z = 0)
	{
		x = X;
		y = Y;
		z = Z;
	}
	float& operator[] (int index)
	{
		switch (index)
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		default:
			return x;
		}
	}
	Vec3f operator*(float a)
	{
		return Vec3f(x * a, y * a, z * a);
	}
	float operator*(Vec3f b)
	{
		return x * b.x + y * b.y + z * b.z;
	}
	Vec3f operator-(Vec3f b)
	{
		return Vec3f(x - b.x, y - b.y, z - b.z);
	}
	float mod()
	{
		return sqrt(*this * *this);
	}
	~Vec3f() {};
};

