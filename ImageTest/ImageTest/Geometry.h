#pragma once
#include <cmath>
#include <iostream>
namespace Geometry
{
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
		Vec3f operator-(const Vec3f &b)
		{
			return Vec3f(x - b.x, y - b.y, z - b.z);
		}
		Vec3f static dif(const Vec3f &a, const Vec3f &b)
		{
			return Vec3f(a.x - b.x, a.y - b.y, a.z - b.z);
		}
		float mod()
		{
			return sqrt(*this * *this);
		}
		void Normalize()
		{
			if (mod() > 0)
			{
				float m = mod();
				x /= m;
				y /= m;
				z /= m;
			}
		}
		float Distance(const Vec3f &b)
		{
			return sqrt(std::pow(x - b.x, 2) + std::pow(y - b.y, 2) + std::pow(z - b.z, 2));
		}
		friend std::ostream& operator << (std::ostream &r, const Vec3f &v)
		{
			r << v.x << ' ';
			r << v.y << ' ';
			r << v.z << '\n';
			return r;
		}
		~Vec3f() {};
	};
	namespace colors
	{
		const Geometry::Vec3f red(255, 0, 0);
		const Geometry::Vec3f green(0, 255, 0);
		const Geometry::Vec3f blue(0, 0, 255);
		const Geometry::Vec3f black(255, 255, 255);
		const Geometry::Vec3f white(0, 0, 0);
	};
	namespace Figures
	{
		class Figure
		{

		};

		class Sphere {
		public:
			Vec3f center;
			float radius;
		
			Sphere(Vec3f c, float r) : center(c), radius(r) {};

			bool ray_intersect(Vec3f orig, const Vec3f &dir, float &t0) const
			{
				Vec3f L = Vec3f::dif(center, orig);
				float tca = L * dir;
				float d2 = L * L - tca * tca;
				if (d2 > radius*radius) return false;
				float thc = sqrtf(radius*radius - d2);
				t0 = tca - thc;
				float t1 = tca + thc;
				if (t0 < 0) t0 = t1;
				if (t0 < 0) return false;
				return true;
			}
		};
	};
}