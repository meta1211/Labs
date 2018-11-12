#include "BitMatrix.h"

void BitMatrix::Recreate(int Cols, int Rows)
{
	if (!subArrays)
	{
		delete[] subArrays;
	}
	subArrays = new BitArray[Rows];
	columns = Cols;
	rows = Rows;
	for (int i = 0; i < Rows; i++)
	{
		BitArray s(Cols);
		subArrays[i] = s;
	}
}

void BitMatrix::CopyObject(BitMatrix &matr)
{
	Recreate(matr.columns, matr.rows);
	for (int i = 0; i < matr.rows; i++)
	{
		subArrays[i] = matr.subArrays[i];
	}
}

int BitMatrix::Max(char ** str, int n)
{
	if (!str)
	{
		return 0;
	}
	int max = strlen(str[0]);
	for (int i = 1; i < n; i++)
	{
		if (max < strlen(str[i]))
		{
			max = strlen(str[i]);
		}
	}
	return max;
}

void BitMatrix::Print()
{
	for (int i = 0; i < rows; i++)
	{
		subArrays[i].Print();
	}
}

BitMatrix::BitMatrix(int Cols, int Rows)
{
	Recreate(Cols, Rows);
}

BitMatrix::BitMatrix(int size = 5)
{
	Recreate(size, size);
}

BitMatrix::BitMatrix(char **data, int dataCount)
{
	int maxLen = Max(data, dataCount);
	Recreate(maxLen, dataCount);
	for (int i = 0; i < dataCount; i++)
	{
		int len = strlen(data[i]);
		for (int j = 0; j < len; j++)
		{
			subArrays[i].SetValue(j, data[i][j] == '1');
		}
		for (int k = len; k < maxLen; k++)
		{
			subArrays[i].SetValue(k, false);
		}
	}
}

BitMatrix::BitMatrix(BitMatrix &matr)
{
	CopyObject(matr);
}

BitMatrix::~BitMatrix()
{
	delete[] subArrays;
}