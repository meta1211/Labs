#pragma once
#include "BitArray.h"
class BitMatrix
{
	BitArray *subArrays;
	int columns;
	int rows;

	void Recreate(int Cols, int Rows);
	void CopyObject(BitMatrix&matr);
	static int Max(char** str, int n);

public:

	void Print();
	void Scan(int cols, int rows);

	BitMatrix operator=(BitMatrix &x);
	BitArray &operator[](int index);
	bool operator == (BitMatrix &x);
	bool operator != (BitMatrix &x);

	void Set(int x, int y, bool value);
	void Set(int x, int y, int len, bool value);
	void Invert(int x, int y);
	void Invert(int x, int y, int len);

	BitMatrix();
	BitMatrix(int Cols, int Rows);
	BitMatrix(int size);
	BitMatrix(char **data, int dataCount);
	BitMatrix(BitMatrix&matr);
	~BitMatrix();
};