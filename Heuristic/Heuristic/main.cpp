#include <iostream>
#include "BitMatrix.h"
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> ReadAllstrings(std::string path)
{
	std::fstream reader(path);
	std::vector<std::string> allStrings;
	if (reader.is_open())
	{
		std::string nextString;
		while (!reader.eof())
		{
			std::getline(reader, nextString);
			allStrings.push_back(nextString);
			nextString.clear();
		}
	}
	else
	{
		allStrings.push_back("WRONG FILE PATH: " + path);
		std::cout << "Wrong path!";
	}
	return allStrings;
}

std::vector<std::string> SplitString(const std::string &str, char separator)
{
	std::vector<std::string> words;
	std::string word;
	for (auto ch : str)
	{
		if (ch == separator)
		{
			words.push_back(word);
			word.clear();
		}
		else
		{
			word.push_back(ch);
		}
	}
	if (word.length() > 0)
	{
		words.push_back(word);
	}
	return words;
}

void Print(int **a, int w, int h)
{
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			std::cout << a[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

int Summ(int *a, int n)
{
	int summ = 0;
	for (int i = 0; i < n; i++)
	{
		summ += a[i];
	}
	return summ;
}

int FindMin(int *a, int n)
{
	int min = INT_MAX;
	int indexOfMin = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min && a[i] > 0)
		{
			min = a[i];
			indexOfMin = i;
		}
	}
	return indexOfMin;
}

int main()
{
	auto data = ReadAllstrings("data.txt");
	int mapSize = std::stoi(SplitString(data[0], ' ')[0]);
	int start = std::stoi(SplitString(data[0], ' ')[1]);
	data.erase(data.begin());
	int **map = new int*[mapSize];
	std::vector<int> way; 
	for (int i = 0; i < mapSize; i++)
	{
		map[i] = new int[mapSize];
		auto dataSlice = SplitString(data[i], ' ');
		for (int j = 0; j < mapSize; j++)
		{
			map[i][j] = std::stoi(dataSlice[j]);
		}
	}
	std::cout << "Start:\n";
	Print(map, mapSize, mapSize);
	int curentCity = start;
	for (int i = 0; i < mapSize - 1; i++)
	{
		int newCity = FindMin(map[curentCity], mapSize);
		way.push_back(newCity);
		for (int j = 0; j < mapSize; j++)
		{
			map[curentCity][j] = -1;
			map[j][curentCity] = -1;
		}
		curentCity = newCity;
	}
	std::cout << "Our way: " << start + 1 << ' ';
	for (int num : way)
	{
		std::cout << num + 1<< ' ';
	}
	std::cout << '\n';
	return 0;
}