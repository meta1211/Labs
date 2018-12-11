#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "BitMatrix.h"
#include "BitArray.h"

struct Pair
{
	int a;
	int b;
};

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

std::vector<Pair> SplitStringsByPairs(const std::vector<std::string> &text)
{
	std::vector<Pair> pairs;
	Pair pair;
	for (auto str : text)
	{
		auto words = SplitString(str, ' ');
		pair.a = std::stoi(words[0]);
		pair.b = std::stoi(words[1]);
		pairs.push_back(pair);
	}
	return pairs;
}


int main()
{
	std::string path("C:\\Users\\SoulSold\\source\\repos\\TopologySort\\TopologySort\\input.txt");
	auto edges = SplitStringsByPairs(ReadAllstrings(path));
	int max = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i].a > max)
		{
			max = edges[i].a;
		}
		if (edges[i].b > max)
		{
			max = edges[i].b;
		}
	}
	BitMatrix ways(max, max);
	int *result = new int[max];
	int addedCount = 0;
	for (auto edge : edges)
	{
		ways.Set(edge.b - 1, edge.a - 1, true);
	}
	
	BitArray curentV(max);
	BitArray addedV(max);
	std::cout << "Matrix of ways:\n";
	ways.Print();
	std::cout << '\n';
	while (addedCount < max)
	{
		for (int i = 0; i < max; i++)
		{
			if (ways[i].GetWeight() == 0)
			{
				curentV[i] = true;
			}
		}
		curentV.Print();
		addedV.Print();
		for (int i = 0; i < max; i++)
		{
			if (curentV[i] && !addedV[i])
			{
				result[addedCount] = i + 1;
				addedCount++;
				addedV[i] = true;
				for (int j = 0; j < max; j++)
				{
					ways[j][i] = false;
				}
			}
		}
		curentV.Clear();
	}
	for (int i = 0; i < addedCount; i++)
	{
		std::cout << result[i] << ' ';
	}
	std::cout << '\n';
	return 0;
}
//4 6 2 5 3 7 1