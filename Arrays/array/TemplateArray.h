#pragma once
#include <iostream>

template <typename T>
class TemplateArray
{
private:
	T *arr;
	int capacity;

	void CopyElements(T *source, int len)
	{
		for (int i = 0; i < len; i++)
		{
			arr[i] = source[i];
		}
	}
	void CopyElements(T *source, int len, int start)
	{
		for (int i = 0; i < len; i++)
		{
			arr[i + start] = source[i];
		}
	}
	void CopyElements(T *a, T * source, int len, int start = 0)
	{
		for (int i = 0; i < len; i++)
		{
			a[i + start] = source[i];
		}
	}
	void Shift(int index)
	{
		for (int i = index; i < capacity; i++)
		{
			arr[i] = arr[i + 1];
		}
		capacity--;
	}
	//void Shift(int *, int, int);
	void Swap(T *xp, T *yp)
	{
		int temp = *xp;
		*xp = *yp;
		*yp = temp;
	}
	bool IsTemplateArraysEq(T *a, int len)
	{
		for (int i = 0; i < len; i++)
		{
			if (arr[i] != a[i])
				return false;
		}
		return true;
	}


public:
	//void Scan(int);
	void Print()
	{
		for (int i = 0; i < capacity; i++)
		{
			std::cout << arr[i] << ' ';
		}
		std::cout << '\n';
	}
	int Find(T key)
	{
		for (int i = 0; i < capacity; i++)
		{
			if (arr[i] == key)
			{
				return i;
			}
		}
		return -1;
	}

	int & operator [] (int i)
	{
		return arr[i];
		//throw std::exception("Index out of TemplateArray!");
	}
	TemplateArray & operator = (TemplateArray &x)
	{
		delete arr;
		arr = new int[x.capacity];
		CopyElements(x.arr, x.capacity);
		capacity = x.capacity;
		return *this;
	}
	TemplateArray operator += (const T key)
	{
		int *buffer = new int[capacity + 1];
		CopyElements(buffer, arr, capacity);
		buffer[capacity] = key;
		delete arr;
		arr = buffer;
		capacity++;
		return *this;
	}
	TemplateArray operator + (T key)
	{
		TemplateArray result(*this);
		result += key;
		return result;
	}
	TemplateArray operator += (TemplateArray a)
	{
		int *buffer = new int[capacity + a.capacity];
		CopyElements(buffer, arr, capacity);
		delete arr;
		arr = buffer;
		CopyElements(arr, a.arr, a.capacity, capacity);
		capacity = capacity + a.capacity;
		return *this;
	}
	TemplateArray operator + (TemplateArray a)
	{
		TemplateArray result(capacity + a.capacity);
		CopyElements(result.arr, arr, capacity);
		CopyElements(result.arr, a.arr, a.capacity, capacity);
		return result;
	}
	TemplateArray operator -= (int index)
	{
		Shift(index);
		return *this;
	}
	TemplateArray operator -(T key)
	{
		for (int i = 0; i < capacity; i++)
		{
			if (key == arr[i])
			{
				Shift(i);
				break;
			}
		}
		return *this;
	}
	bool operator ==(TemplateArray a)
	{
		if (a.capacity != capacity)
			return false;
		return IsTemplateArraysEq(a.arr, a.capacity);
	}
	bool operator !=(TemplateArray a)
	{
		if (a.capacity != capacity)
			return true;
		return !IsTemplateArraysEq(a.arr, a.capacity);
	}

	//friend std::ostream& operator << (std::ostream &r, const TemplateArray &x)
	//{
	//	for (int i = 0; i < x.capacity; i++)
	//	{
	//		r << x.arr[i] << ' ';
	//	}
	//	return r;
	//}
	//friend std::istream & operator >> (std::istream &r, TemplateArray &x)
	//{
	//	int tempNum;
	//	r >> tempNum;
	//	x += tempNum;
	//	return r;
	//}


	TemplateArray(int Capacity = 0)
	{
		arr = new T[Capacity];
		capacity = Capacity;
	}
	TemplateArray(T *a, int Capacity)
	{
		arr = a;
		capacity = Capacity;
	}
	TemplateArray(const TemplateArray &x)
	{
		if (!arr)
			delete[]arr;
		arr = new T[x.capacity];
		CopyElements(x.arr, x.capacity);
		capacity = x.capacity;
	}
	~TemplateArray()
	{
		delete[]arr;
	}
};


