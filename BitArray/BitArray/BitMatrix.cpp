#include "BitMatrix.h"
#include <iostream>

void BitMatrix::Recreate(int Cols, int Rows)
{
	if (Cols < 0 || Rows < 0)
	{
		throw std::exception("Arguments cant be negative!");
	}
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

void BitMatrix::Scan(int cols, int rows)
{
	Recreate(cols, rows);
	for (int i = 0; i < rows; i++)
	{
		std::string buffer;
		std::cin >> buffer;
		if (buffer.size() == cols && BitArray::IsBoolString(buffer.c_str()))
		{
			subArrays[i] = buffer;
		}
		else
		{
			std::cout << "Wrong input, try again, please!\n";
			i--;
		}
	}
}

BitMatrix BitMatrix::operator=(BitMatrix & x)
{
	CopyObject(x);
	return *this;
}

BitArray &BitMatrix::operator[](int index)
{
	return subArrays[index];
}

bool BitMatrix::operator==(BitMatrix & x)
{
	if (columns != x.columns || rows != x.rows)
		return false;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (subArrays[i][j] != x.subArrays[i][j])
				return false;
		}
	}
	return true;
}

bool BitMatrix::operator!=(BitMatrix & x)
{
	return !(*this == x);
}

void BitMatrix::Set(int x, int y, bool value)
{
	subArrays[x][y] = value;
}

void BitMatrix::Set(int x, int y, int len, bool value)
{
	if (y + len > subArrays[x].GetBitsCount())
		throw std::out_of_range("Index out of array range!");
	for (int i = 0; i < len; i++)
	{
		subArrays[x][i + y] = value;
	}
}

void BitMatrix::Invert(int x, int y)
{
	subArrays[x][y] = !subArrays[x][y];
}

void BitMatrix::Invert(int x, int y, int len)
{
	if (y + len > subArrays[x].GetBitsCount())
		throw std::out_of_range("Index out of array range!");
	for (int i = 0; i < len; i++)
	{
		subArrays[x][i + y] = !subArrays[x][i + y];
	}
}

BitMatrix::BitMatrix()
{
	int baseLen = 3;
	rows = baseLen;
	columns = baseLen;
	subArrays = new BitArray[baseLen];
	for (int i = 0; i < baseLen; i++)
	{
		BitArray a(baseLen);
		subArrays[i] = a;
		for (int j = 0; j < baseLen; j++)
		{
			subArrays[i][j] = false;
		}
	}
}

BitMatrix::BitMatrix(int Cols, int Rows)
{
	Recreate(Cols, Rows);
}

BitMatrix::BitMatrix(int size)
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
		int deltaLen = maxLen - len;
		for (int j = 0; j < deltaLen; j++)
		{
			subArrays[i][j] = false;
		}
		for (int k = 0; k < len; k++)
		{
			subArrays[i][k + deltaLen] = data[i][k] == '1';
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