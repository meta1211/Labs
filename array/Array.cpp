#include <bitset>  
#include "Array.h"
#define INT16_MAX  2147483647


#pragma region PrivateFunctions

void Array::CopyElements(int *source, int len)
{
	for (int i = 0; i < len; i++)
	{
		arr[i] = source[i];
	}
}

void Array::CopyElements(int *source, int len, int start)
{
	for (int i = 0; i < len; i++)
	{
		arr[i + start] = source[i];
	}
}

void Array::CopyElements(int *a, int *source, int len, int start)
{
	for (int i = 0; i < len; i++)
	{
		a[i + start] = source[i];
	}
}

void Array::Shift(int *a, int start, int end)
{
	for (int i = end - 1; i >= start; i--)
	{
		a[i + 1] = a[i];
	}
}

void Array::Shift(int index)
{
	for (int i = index; i < capacity; i++)
	{
		arr[i] = arr[i + 1];
	}
	capacity--;
}

bool Array::IsArraysEq(int *a, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] != a[i])
			return false;
	}
	return true;
}

void Swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void Array::BubbleSort(int *a, int n)
{
	int i, j;
	bool isSwapped;
	for (i = 0; i < n - 1; i++)
	{
		isSwapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				isSwapped = true;
			}
		}
		if (isSwapped == false)
			break;
	}
}

void Array::InsertionSort(int *a, int n)
{
	int curentValue;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			curentValue = a[i];
			if (a[i] < a[j])
			{
				Shift(a, j, i);
				a[j] = curentValue;
			}
		}
	}
}

void Array::ShellSort(int *a, int n)
{
	int i;
	int value;
	for (int p = n / 2; p >= 0; p--)
	{
		for (int q = 0; q < p; q++)
		{
			for (int j = q + p; j < n; j += p)
			{
				for (i = j - p, value = a[j]; i >= 0 && a[i] > value; i -= p)
				{
					a[i + p] = a[i];
				}
				a[i + p] = value;
			}
		}
	}
}

void MoveElement(int *a, int n, int index)
{
	int j = 2 * index + 1;
	if (j > n)
		return;
	int value = a[index];
	int i = index;
	if (a[j + 1] > a[j] && j + 1 < n)
	{
		j++;
	}
	while (a[j] > value)
	{
		a[i] = a[j];
		i = j;
		j = 2 * i + 1;
		if (j >= n)
		{
			break;
		}
		if (j + 1 < n && a[j + 1] > a[j])
		{
			j++;
		}
	}
	a[i] = value;
}

void BuildPyramid(int *a, int n)
{
	for (int curentIndex = n / 2 - 1; curentIndex >= 0; curentIndex--)
	{
		MoveElement(a, n, curentIndex);
	}
}

void Array::PyramidSort(int *a, int n)
{
	BuildPyramid(a, n);
	for (int N = n; N > 0; )
	{
		Swap(&a[0], &a[N - 1]);
		N--;
		MoveElement(a, N, 0);
	}
	Swap(&a[0], &a[1]);
}

void Array::BubbleSort(int *a, int n, int start, int end)
{
	int i, j;
	bool isSwapped;
	for (i = start; i < end - 1; i++)
	{
		isSwapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				isSwapped = true;
			}
		}
		if (isSwapped == false)
			break;
	}
}

void Array::QuickSort(int *a, int n, int start, int end)
{
	int i = start;
	int j = end;
	int pillar = a[(end + start) / 2];
	
	while(i < j)
	{
		for (; a[i] < pillar && i <= end; i++);
		for (; a[j] > pillar && j >= start; j--);
		if (i <= j)
		{
			Swap(&a[i], &a[j]);
			i++;
			j--;
		}
	}
	if (start < j)
	{
		QuickSort(a, n, start, j);
	}
	if (end > i)
	{
		QuickSort(a, n, i, end);
	}
}

void Array::BitSort(int *a, int n, int start, int end, int cmpByte)
{
	int i = start;
	int j = end;
	if (i < j)
	{
		int mask = 1 << cmpByte;
		while (i <= j)
		{
			for (; i <= j && !(a[i] & mask); i++);
			for (; i <= j && (a[j] & mask); j--);
			if (i < j)
			{
				Swap(&a[i], &a[j]);
				i++;
				j--;
			}
		}
		if (start < j)
		{
			BitSort(a, n, start, j, cmpByte - 1);
		}
		if (i < end)
		{
			BitSort(a, n, i, end, cmpByte - 1);
		}
	}
}

#pragma endregion

#pragma region PublicFunctions

void Array::Scan(int m)
{
	int *buffer = new int[m + capacity];
	for (int i = 0; i < m; i++)
	{
		std::cin >> buffer[i + capacity];
	}
	capacity += m;
	delete arr;
	arr = buffer;
}

void Array::Print()
{
	for (int i = 0; i < capacity; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}

int Array::Max()
{
	int maxIndex = 0;
	for (int i = 1; i < capacity; i++)
	{
		if (arr[i] > arr[maxIndex])
		{
			maxIndex = i;
		}
	}
	return maxIndex;
}

int Array::Min()
{
	int minIndex = 0;
	for (int i = 1; i < capacity; i++)
	{
		if (arr[i] < arr[minIndex])
		{
			minIndex = i;
		}
	}
	return minIndex;
}

int Array::Find(int key)
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

void Array::Sort(sortType a = sortType::bubbleSort)
{
	switch (a)
	{
	case bubbleSort:
	{
		BubbleSort(arr, capacity);
		break;
	}
	case insertionSort:
	{
		InsertionSort(arr, capacity);
		break;
	}
	case shellSort:
	{
		ShellSort(arr, capacity);
		break;
	}
	case pyramidSort:
	{
		PyramidSort(arr, capacity);
		break;
	}
	case quickSort:
	{
		QuickSort(arr, capacity, 0, capacity - 1);
		break;
	}
	case bitSort:
	{
		BitSort(arr, capacity, 0, capacity - 1, 16);
		break;
	}
	default:
	{
		std::cout << "Unexpected argument" << std::endl;
		throw std::exception("Couldnt find function for this argument");
		break;
	}
	}
}

#pragma endregion

#pragma region Operators

int &Array::operator [] (int i)
{
	return arr[i];
	//throw std::exception("Index out of array!");
}

Array Array::operator += (const int key)
{
	int *buffer = new int[capacity + 1];
	CopyElements(buffer, arr, capacity);
	buffer[capacity] = key;
	delete []arr;
	arr = buffer;
	capacity++;
	return *this;
}

Array Array::operator + (int key)
{
	Array result(*this);
	result += key;
	return result;
}

Array Array::operator += (Array a)
{
	int *buffer = new int[capacity + a.capacity];
	CopyElements(buffer, arr, capacity);
	delete []arr;
	arr = buffer;
	CopyElements(arr, a.arr, a.capacity, capacity);
	capacity = capacity + a.capacity;
	return *this;
}

Array Array::operator + (Array a)
{
	Array result(capacity + a.capacity);
	CopyElements(result.arr, arr, capacity);
	CopyElements(result.arr, a.arr, a.capacity, capacity);
	return result;
}

Array & Array::operator = (Array &x)
{
	delete []arr;
	arr = new int[x.capacity];
	CopyElements(x.arr, x.capacity);
	capacity = x.capacity;
	return *this;
}

Array Array::operator -= (int index)
{
	Shift(index);
	return *this;
}

Array Array::operator -(int key)
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

bool Array::operator ==(Array a)
{
	if (a.capacity != capacity)
		return false;
	return IsArraysEq(a.arr, a.capacity);
}

bool Array::operator !=(Array a)
{
	if (a.capacity != capacity)
		return true;
	return !IsArraysEq(a.arr, a.capacity);
}

#pragma endregion

#pragma region Contructors

Array::Array(int Capacity)
{
	arr = new int[Capacity];
	capacity = Capacity;
}

Array::Array(int *a, int Capacity)
{
	arr = a;
	capacity = Capacity;
}

Array::Array(const Array & x)
{
	if (!arr)
		delete[] arr;
	arr = new int[x.capacity];
	CopyElements(x.arr, x.capacity);
	capacity = x.capacity;
}

Array::~Array()
{
	delete[] arr;
}

#pragma endregion