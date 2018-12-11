#pragma once
#include "BitArray.h"
class BitMatrix
{
private:
	BitArray *subArrays;
	int columns;
	int rows;

	void Recreate(int Cols, int Rows);
	void CopyObject(const BitMatrix&matr);
	static int Max(char** str, int n);
	static BitMatrix ForEach(BitMatrix &a, BitMatrix &b, bool(*operation)(bool, bool));
	static bool Inversion(bool a, bool b)
	{
		return !a;
	}

public:
	void Print();
	void Scan(int cols, int rows);

	BitMatrix operator=(BitMatrix &x);
	BitArray &operator[](int index);
	bool operator == (BitMatrix &x);
	bool operator != (BitMatrix &x);

	BitMatrix operator&(BitMatrix &x);
	BitMatrix operator&=(BitMatrix &x);
	BitMatrix operator|(BitMatrix &x);
	BitMatrix operator|=(BitMatrix &x);
	BitMatrix operator^(BitMatrix &x);
	BitMatrix operator^=(BitMatrix &x);
	BitMatrix operator~();
	BitMatrix ShiftRight(int index, int count);
	BitMatrix ShiftLeft(int index, int count);

	BitArray AndEach();
	BitArray OrEach();
	BitArray XorEach();

	void Set(int x, int y, bool value);
	void Set(int x, int y, int len, bool value);
	void Invert(int x, int y);
	void Invert(int x, int y, int len);

	friend std::ostream & operator << (std::ostream &r, BitMatrix &x)
	{
		for (int i = 0; i < x.rows; i++)
		{
			r << x[i] << '\n';
		}
		return r;
	}

	friend std::istream & operator >> (std::istream &r, BitMatrix &x)
	{
		for (int i = 0; i < x.rows; i++)
		{
			std::string vector;
			r >> vector;
			if (vector.length() != x.columns || !BitArray::IsBoolString(vector.c_str()))
			{
				std::cout << "Wrong input type! Write again, please\n";
				i--;
			}
			else
			{
				BitArray a(vector.c_str());
				x[i] = a;
			}
		}
		return r;
	}

	BitMatrix();
	BitMatrix(int Cols, int Rows);
	BitMatrix(int size);
	BitMatrix(char **data, int dataCount);
	BitMatrix(const BitMatrix&matr);
	~BitMatrix();
};