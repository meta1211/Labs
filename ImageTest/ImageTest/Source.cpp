#include <limits>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include "Geometry.h"
#include <algorithm>
using namespace Geometry;
inline float sq(float a) { return a * a; }

void render() 
{
	const int width = 1024;
	const int height = 768;
	std::vector <std::vector<Vec3f>> framebuffer(width);
	for (auto arr : framebuffer)
	{
		arr = std::vector<Vec3f>(height);
	}
	std::ofstream ofs; // save the framebuffer to file
	ofs.open("./out.ppm");
	ofs << "P3\n" << width << " " << height << "\n255\n";
	for (size_t j = height; j > 0; j--) 
	{
		for (size_t i = 0; i < width; i++) 
		{
			float R = float(j) / height * 255;
			float G = float(i) / (width) * 255;
			ofs << floor(R) << ' ';
			ofs << floor(G) << ' ';
			ofs << 0 << '\n';
		}
	}
	ofs.close();
}

void MakeBackground(std::vector <std::vector<Vec3f>> &pixelArray, const Vec3f &color)
{
	for (auto line : pixelArray)
	{
		for (auto pixel : line)
		{
			pixel = color;
		}
	}
}

void PrintFigure(std::vector <std::vector<Vec3f>> &pixelArray, Figures::Figure &figure, const Vec3f &color)
{
	Figures::RectangleArea borders = figure.GetBorders();
	for (size_t x = borders.A['x']; x < borders.B['x']; x++)
	{
		for (size_t y = borders.C['y']; y < borders.A['y']; y++)
		{
			if (figure.IsInFigure(Vec3f(x, y, 0)))
			{
				pixelArray[x][y] = color;
			}
		}
	}
}

void render(Figures::Sphere s, Vec3f color, Vec3f background)
{
	const int width = 600;
	const int height = 600;
	const Figures::Sphere light(Vec3f(0, 0, 50), 1);

	std::vector <std::vector<Vec3f>> framebuffer(width);
	for (auto &arr : framebuffer)
	{
		arr.resize(height);
	}

	MakeBackground(framebuffer, background);
	//PrintFigure(framebuffer, s, background);

	for (size_t i = 0; i < width; i++)
	{
		for (size_t j = 0; j < height; j++)
		{
			Figures::Ray ray(Vec3f(i, j), Vec3f(0, 0, 1));
			auto intersectionPlace = s.ray_intersect(Figures::Ray(Vec3f(j, i), Vec3f(0, 0, 1)));
			if(intersectionPlace.first)
			{
				Vec3f intersection = ray.start + ray.direction * intersectionPlace.second;
				Vec3f lightSource = light.center - intersection;

				framebuffer[j][i] = color;
			}
		}
	}
	std::ofstream ofs; // save the framebuffer to file
	ofs.open("./out.ppm");
	ofs << "P3\n" << width << " " << height << "\n255\n";
	for (auto line : framebuffer)
	{
		for (auto pixel : line)
		{
			ofs << pixel;
		}
	}
	ofs.close();
}

int main() {
	render(Figures::Sphere(Vec3f(100,100,0), 100), Geometry::colors::white, Geometry::colors::black);
	return 0;
}