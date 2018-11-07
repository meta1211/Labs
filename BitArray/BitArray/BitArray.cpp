#include "BitArray.h"

BitArray test;
#pragma region Seters and geters

bool BitArray::GetValue(int index)
{
	int mask = 1 << (index % SegmentLen);
	return bytes[index / SegmentLen] & mask;
}

int BitArray::GetBitsCount()
{
	return bitsCount;
}

int BitArray::GetWeight()
{
	int sum = 0;
	for (int i = 0; i < bitsCount; i++)
	{
		if (GetValue(i))
		{
			sum++;
		}
	}
	return sum;
}

void BitArray::SetValue(int index, bool value)
{
	int mask = 1 << (index % SegmentLen);
	if (value)
	{
		bytes[index / SegmentLen] = bytes[index / SegmentLen] | mask;
	}
	else
	{
		bytes[index / SegmentLen] = bytes[index / SegmentLen] & (~mask);
	}
}

void BitArray::SetValue(int start, bool value, int len)
{
	for (int i = 0; i < len; i++)
	{
		SetValue(i + start, value);
	}
}

void BitArray::InvertValue(int index)
{
	SetValue(index, !GetValue(index));
}

void BitArray::InvertValue(int start, int len)
{
	for (int i = 0; i < len; i++)
	{
		InvertValue(i + start);
	}
}
#pragma endregion


bool AND(bool x , bool y)
{
	return x && y;
}

bool OR(bool x, bool y)
{
	return x || y;
}

bool XOR(bool x, bool y)
{
	return (!x && y) || (x && !y);
}

void BitArray::CopyObject(BitArray & source)
{
	bytes = new Segment[source.segmentsCount];
	bitsCount = source.bitsCount;
	segmentsCount = source.segmentsCount;
	for (int i = 0; i < bitsCount; i++)
	{
		SetValue(i, source.GetValue(i));
	}
}

BitArray& BitArray::ForEach(BitArray & a, BitArray & b, bool(*operation)(bool, bool))
{
	int FirstLen = a.bitsCount;
	int SecondLen = b.bitsCount;
	int i = 0, j = 0;
	BitArray *result = new BitArray(FirstLen > SecondLen ? FirstLen : SecondLen);
	while (i < FirstLen && j < SecondLen)
	{
		result->SetValue(i, operation(a.GetValue(i), b.GetValue(i)));
		i++;
		j++;
	}
	while (i < FirstLen)
	{
		result->SetValue(i, a.GetValue(i));
		i++;
	}
	while (j < SecondLen)
	{
		result->SetValue(j, b.GetValue(j));
		j++;
	}
	return *result;
}

int BitArray::CompareEach(BitArray & a, BitArray & b)
{
	BitArray &tempA = a;
	BitArray &tempB = b;
	if (a.bitsCount != b.bitsCount)
	{
		if (a.bitsCount > b.bitsCount)
		{
			BitArray g(b.ToString().c_str(), a.bitsCount);
			tempB = g;
		}
		else
		{
			BitArray g(a.ToString().c_str(), b.bitsCount);
			tempA = g;
		}
	}
	int len = tempA.bitsCount;
	for (int i = 0; i < len; i++)
	{
		if (tempA.GetValue(i) > tempB.GetValue(i))
		{
			return -1;
		}
		else if(tempA.GetValue(i) < tempB.GetValue(i))
		{
			return 1;
		}
	}
	return 0;
}

void BitArray::Scan(int count)
{
	std::string buffer;
	std::cin >> buffer;
	if (buffer.length() != count)
	{
		throw std::out_of_range("Wrong length!");
	}
	BitArray a(buffer.c_str(), count);
	CopyObject(a);
}

void BitArray::Print()
{
	std::cout << ToString() << '\n';
}

std::string BitArray::ToString()
{
	std::string *str = new std::string();
	for (int i = 0; i < bitsCount; i++)
	{
		str->push_back(GetValue(i) ? '1' : '0');
	}
	return *str;
}

#pragma region Logic operators
bool BitArray::operator==(BitArray & a)
{
	return  CompareEach(*this, a) == 0;
}

bool BitArray::operator!=(BitArray & a)
{
	return  CompareEach(*this, a) != 0;
}

bool BitArray::operator>(BitArray & a)
{
	return  CompareEach(*this, a) == -1;
}

bool BitArray::operator<(BitArray & a)
{
	return  CompareEach(*this, a) == 1;
}
#pragma endregion

#pragma region Transformation operators

BitArray& BitArray::operator=(BitArray &source)
{
	CopyObject(source);
	return *this;
}

BitArray& BitArray::operator=(BitArray *source)
{
	CopyObject(*source);
	return *this;
}

BitArray& BitArray::operator&(BitArray &b)
{
	return *(new BitArray(ForEach(*this, b, AND)));
}

BitArray& BitArray::operator&=(BitArray &b)
{
	*this = &(*this & b);
	return *this;
}

BitArray& BitArray::operator|(BitArray &b)
{
	return *(new BitArray(ForEach(*this, b, OR)));
}

BitArray& BitArray::operator|=(BitArray &b)
{
	*this = &(*this | b);
	return *this;
}

BitArray& BitArray::operator^(BitArray &b)
{
	return *(new BitArray(ForEach(*this, b, XOR)));
}

BitArray& BitArray::operator^=(BitArray &b)
{
	*this = &(*this | b);
	return *this;
}

BitArray& BitArray::operator~()
{
	BitArray *result = new BitArray(this);
	for (int i = 0; i < bitsCount; i++)
	{
		result->SetValue(i, !result->GetValue(i));
	}
	return *result;
}

BitArray& BitArray::operator<<(int shiftLen)
{
	BitArray *result = new BitArray(*this);
	for (int k = 0; k < shiftLen; k++)
	{
		for (int i = 0; i < result->GetBitsCount() - k - 1; i++)
		{
			result->SetValue(i, result->GetValue(i + 1));
		}
		result->SetValue(bitsCount - k - 1, false);
	}
	return *result;
}

BitArray& BitArray::operator<<=(int index)
{
	*this = &(*this << index);
	return *this;
}

BitArray& BitArray::operator>>(int shiftLen)
{
	BitArray *result = new BitArray(*this);
	for (int k = 0; k < shiftLen; k++)
	{
		for (int i = result->GetBitsCount() - k - 1; i > 0; i--)
		{
			result->SetValue(i, result->GetValue(i - 1));
		}
		result->SetValue(k, false);
	}
	return *result;
}

BitArray& BitArray::operator>>=(int index)
{
	*this = &(*this >> index);
	return *this;
}

BitPointer BitArray::operator[](int index)
{
	return BitPointer(&bytes[index / SegmentLen], index % SegmentLen);
}

//bool BitArray::operator[](int index)
//{
//	return GetValue(index);
//}


#pragma endregion

#pragma region Countructors
BitArray::BitArray(int Capacity)
{
	bitsCount = Capacity;
	segmentsCount = Capacity % SegmentLen == 0 ? Capacity / SegmentLen : Capacity / SegmentLen + 1;
	bytes = new Segment[segmentsCount];
	for (int i = 0; i < segmentsCount; i++)
	{
		bytes[i] = 0;
	}
}

BitArray::BitArray(const char *vector)
{
	bitsCount = strlen(vector);
	segmentsCount = bitsCount % SegmentLen == 0 ? bitsCount / SegmentLen : bitsCount / SegmentLen + 1;
	bytes = new Segment[segmentsCount];
	for (int i = 0; i < segmentsCount; i++)
	{
		bytes[i] = 0;
	}
	for (int curentBit = 0; curentBit < bitsCount; curentBit++)
	{
		SetValue(curentBit, vector[curentBit] == '1');
	}
}

BitArray::BitArray(const char *vector, int len)
{
	int vectorLen = strlen(vector);
	bitsCount = len;
	segmentsCount = len % SegmentLen == 0 ? len / SegmentLen : len / SegmentLen + 1;
	bytes = new Segment[segmentsCount];
	for (int i = 0; i < segmentsCount; i++)
	{
		bytes[i] = 0;
	}
	for (int curentBit = 0; curentBit < vectorLen; curentBit++)
	{
		SetValue(curentBit, vector[curentBit] == '1');
	}
}

BitArray::BitArray(BitArray & source)
{
	bytes = new Segment[source.segmentsCount];
	bitsCount = source.bitsCount;
	segmentsCount = source.segmentsCount;
	for (int i = 0; i < bitsCount; i++)
	{
		SetValue(i, source.GetValue(i));
	}
}

BitArray::BitArray(BitArray *source)
{
	bytes = new Segment[source->segmentsCount];
	bitsCount = source->bitsCount;
	segmentsCount = source->segmentsCount;
	for (int i = 0; i < bitsCount; i++)
	{
		SetValue(i, source->GetValue(i));
	}
}

BitArray::~BitArray()
{
	delete[]bytes;
}
#pragma endregion


