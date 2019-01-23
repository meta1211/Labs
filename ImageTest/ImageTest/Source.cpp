#include <limits>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include "Geometry.h"
#include <algorithm>
using namespace Geometry;
float sq(float a) { return a * a; }
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

void render(Figures::Sphere s, Vec3f color, Vec3f background)
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
			if (s.center.Distance(Vec3f(i, j, 0)) <= s.radius)
			{
				ofs << color;
			}
			else
			{
				ofs << background;
			}
		}
	}
	ofs.close();
}

int main() {
	render(Figures::Sphere(Vec3f(100,100,0), 50), Geometry::colors::white, Geometry::colors::black);
	return 0;
}