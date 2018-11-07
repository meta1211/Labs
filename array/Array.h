#pragma once
#include <iostream>

const enum sortType
{
	bubbleSort = 0,			//Пузырьковая сортировка
	insertionSort = 1,		//Сортировка прямой вставкой
	shellSort = 2,			//Сортировка Шелла
	pyramidSort = 3,		//Пирамидальная сортировка
	quickSort = 4,			//Быстрая сортировка
	bitSort					//Битовая сортировка
};

class Array
{
private:
	int *arr;
	int capacity;	//max elements count

	void CopyElements(int *, int);
	void CopyElements(int *, int, int);
	void CopyElements(int * a, int * source, int len, int start = 0);
	void Shift(int);
	void Shift(int *, int, int);
	//void Swap(int *, int *);
	bool IsArraysEq(int *, int);

	void BubbleSort(int *, int);
	void BubbleSort(int *, int, int, int);
	void InsertionSort(int *, int);
	void ShellSort(int *, int);
	//void MoveElement(int *, int);
	void PyramidSort(int *, int);
	void QuickSort(int *, int, int, int );
	void BitSort(int *, int, int, int, int);

public:
	void Scan(int);
	void Print();
	int Max();
	int Min();
	int Find(int);
	void Sort(sortType);

	int & operator [](int);
	Array & operator = (Array &x);
	Array operator += (const int);
	Array operator + (int);
	Array operator += (Array);
	Array operator + (Array);
	Array operator -= (int);
	Array operator -(int);
	bool operator ==(Array);
	bool operator !=(Array);
	friend std::ostream& operator << (std::ostream &r, const Array &x)
	{
		for (int i = 0; i < x.capacity; i++)
		{
			r << x.arr[i] << ' ';
		}
		return r;
	}
	friend std::istream & operator >> (std::istream &r, Array &x)
	{
		int tempNum;
		r >> tempNum;
		x += tempNum;
		return r;
	}
	

	Array(int Capacity = 0);
	Array(int *, int);
	Array(const Array &x);
	~Array();
};


