#pragma once
#include "BitArray.h"
class BitMatrix
{
	BitArray *subArrays;
	int columns;
	int rows;

	void Recreate(int, int);
	void CopyObject(BitMatrix&);
	static int Max(char** str, int n);
public:

	void Print();

	BitMatrix(int, int);
	BitMatrix(int);
	BitMatrix(char **, int);
	BitMatrix(BitMatrix&);
	~BitMatrix();
};