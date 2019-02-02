#pragma once
#include <cmath>
#include <iostream>
#include <tuple>
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
		float& operator[] (char index)
		{
			switch (index)
			{
			case 'x':
				return x;
			case 'y':
				return y;
			case 'z':
				return z;
			default:
				return x;
			}
		}
		Vec3f operator*(float a)
		{
			return Vec3f(x * a, y * a, z * a);
		}
		float operator*(const Vec3f &b)
		{
			return x * b.x + y * b.y + z * b.z;
		}
		Vec3f operator-(const Vec3f &b) const
		{
			return Vec3f(x - b.x, y - b.y, z - b.z);
		}
		Vec3f operator +(const Vec3f &b)
		{
			return Vec3f(x + b.x, y + b.y, z + b.z);
		}
		Vec3f static dif(const Vec3f &a, const Vec3f &b)
		{
			return Vec3f(a.x - b.x, a.y - b.y, a.z - b.z);
		}
		float static Multi(const Vec3f &a, const Vec3f &b)
		{
			return a.x * b.x + a.y * b.y + a.z * b.z;
		}
		float Mod()
		{
			return sqrt(*this * *this);
		}
		Vec3f Normalize()
		{
			if (Mod() > 0)
			{
				float m = Mod();
				x /= m;
				y /= m;
				z /= m;
			}
			return *this;
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
		const Geometry::Vec3f black(0, 0, 0);
		const Geometry::Vec3f white(255, 255, 255);
	};
	namespace Figures
	{
		struct RectangleArea
		{
			Vec3f A, B, C, D;
			RectangleArea(const Vec3f &a, const Vec3f &b, const Vec3f &c, const Vec3f &d)
			{
				A = a;
				B = b;
				C = c;
				D = d;
			}
		};

		//All figures must use this class as base class for rendering ones.
		class Figure
		{
		public:
			//Returns area using as figure borders. Slightly increaces render speed. Return zero square rectangle for using pictures size as border. 
			virtual RectangleArea GetBorders() = 0;
			//Sets a rule for drawing figure, usually as math formula.
			virtual bool IsInFigure(const Vec3f &coordinates) = 0;
			virtual std::string GetName() = 0;
		};

		struct Ray
		{
			Vec3f start;
			Vec3f direction;
			Ray(Vec3f Start = (0, 0, 0), Vec3f Direction = (0, 0, 0)) : start(Start), direction(Direction) {};
		};

		class Sphere: public Figure {
		public:
			Vec3f center;
			float radius;
		
			Sphere(Vec3f c, float r) : center(c), radius(r) {};
			
			RectangleArea GetBorders()
			{
				return RectangleArea(
					Vec3f(center['x'] - radius, center['y'] + radius),
					Vec3f(center['x'] + radius, center['y'] + radius),
					Vec3f(center['x'] + radius, center['y'] - radius),
					Vec3f(center['x'] - radius, center['y'] - radius));
			}

			bool IsInFigure(const Vec3f &coordinates)
			{
				return 
					center.Distance(coordinates) <= radius;
			}

			//calculating this as square eq
			std::pair<bool, float> ray_intersect(Ray ray)
			{
				Vec3f newStart = ray.start - center;
				float b = 2 * (newStart * ray.direction);
				float c = newStart * newStart - radius * radius;
				float disc = b * b - 4 * c;
				if (disc < 0)
				{
					return std::pair<bool, float>(false, -1.0);
				}
				else
				{
					disc = sqrt(disc);
					float x1 = (-b + disc) / 2;
					float x2 = (-b - disc) / 2;
					return std::pair<bool, float>(true, x1 > x2 ? x1 : x2);
				}
			}
		};
		class line
		{
		public:
			Vec3f start;
			Vec3f dir;
			//ax + by + c = 0
			line(const Vec3f &Start, const Vec3f &Dir) :start(Start), dir(Dir) {};
		};
	};
}