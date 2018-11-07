#pragma once
#include <iostream>
#include <string>
#define SegmentLen 8
#define Segment unsigned char

class BitPointer
{
	Segment	*byte;
	int bitPosition;
private:
	void SetValue(bool value)
	{
		int mask = 1 << (bitPosition % SegmentLen);
		if (value)
		{
			*byte = *byte | mask;
		}
		else
		{
			*byte = *byte & (~mask);
		}
	}

	bool GetValue()
	{
		int mask = 1 << (bitPosition % SegmentLen);
		return *byte & mask;
	}
public:

	BitPointer &operator = (bool a)
	{
		SetValue(a);
		return *this;
	}
	
	BitPointer &operator = (BitPointer a)
	{
		SetValue(a);
		return *this;
	}

	operator bool()
	{
		return GetValue();
	}

	BitPointer(Segment *Byte, int position)
	{
		byte = Byte;
		bitPosition = position;
	}
};

class BitArray
{
private:
	unsigned char *bytes;
	int segmentsCount;
	int bitsCount;
	//bool OR(bool, bool);
	//bool AND(bool, bool);

	void CopyObject(BitArray &source);
	BitArray& ForEach(BitArray &a, BitArray &b, bool(*operation)(bool, bool));
	int CompareEach(BitArray &a, BitArray &b);

public:
	void Scan(int);
	void Print();
	std::string ToString();

#pragma region Logic operators
	bool operator ==(BitArray&);
	bool operator !=(BitArray&);
	bool operator >(BitArray&);
	bool operator <(BitArray&);
#pragma endregion

#pragma region Countructors
	BitArray(int Capacity = SegmentLen);
	BitArray(const char*);
	BitArray(const char*, int);
	BitArray(BitArray&);
	BitArray(BitArray*);
#pragma endregion

#pragma region Transformation operators
	BitArray& operator =(BitArray&);
	BitArray& operator =(BitArray*);
	BitArray& operator &(BitArray&);
	BitArray& operator &=(BitArray&);
	BitArray& operator |(BitArray&);
	BitArray& operator |=(BitArray&);
	BitArray& operator ^(BitArray&);
	BitArray& operator ^=(BitArray&);
	BitArray& operator ~();
	BitArray& operator <<(int);
	BitArray& operator <<=(int);
	BitArray& operator >>(int);
	BitArray& operator >>=(int);
	//bool operator [](int);
	BitPointer operator[](int index);
#pragma endregion

#pragma region Seters and geters
	bool GetValue(int);
	int GetBitsCount();
	int GetWeight();
	void SetValue(int, bool);
	void SetValue(int, bool, int);
	void InvertValue(int);
	void InvertValue(int, int);
#pragma endregion

	friend std::ostream& operator<<(std::ostream& stream, BitArray& x) {
		stream << x.ToString();
		return stream;
	}

	friend std::istream& operator>>(std::istream& stream, BitArray& x) {
		std::string buffer;
		stream >> buffer;
		BitArray a(buffer.c_str());
		x.CopyObject(a);
		return stream;
	}

	~BitArray();
};

