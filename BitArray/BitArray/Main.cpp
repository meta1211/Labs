#include <iostream>
#include "BitArray.h"

int main()
{
	BitArray a("10111000");
	std::cout << "a:\n";
	a.Print();

	BitArray b("111010001");
	std::cout << "b:\n";
	b.Print();

	std::cout << "a & b:\n" << a.ToString() << '\n' << b.ToString() << '\n';
	(a & b).Print();

	std::cout << "a | b:\n" << a.ToString() << '\n' << b.ToString() << '\n';
	(a|b).Print();

	std::cout << "a ^ b:\n" << a.ToString() << '\n' << b.ToString() << '\n';
	(a^b).Print();

	std::cout << "b << 2:\n";
	(b << 2).Print();

	std::cout << "a >> 2:\n";
	(a >> 2).Print();

	std::cout << "Set false from 1 for 3 elements in a:\n";
	a.SetValue(1, false, 3);
	a.Print();

	std::cout << "Set true from 1 for 3 elements in b:\n";
	b.SetValue(1, true, 3);
	b.Print();

	std::cout << "Inversion from 2 for 4 elements in b:\n";
	b.InvertValue(2, 4);
	b.Print();

	std::cout << "Full inversion a:\n";
	BitArray c = ~a;
	c.Print();

	std::cout << "a: length = " << a.GetBitsCount() << " weight = " << a.GetWeight() << " :\n";
	std::cout << "Cin test, input please:\n";
	std::cin >> c;
	c.Print();

	std::cout << "Write index of array please:";
	int index;
	std::cin >> index;
	std::cout << "c[" << index << "] = " << c[index] << '\n';
	c[index] = !c[index];
	std::cout << "After reverse by index c[" << index << "] = " << c[index] << '\n';

	std::cout << "Is a > b?: " << (a > b) <<'\n';
	std::cout << "Is a < b?: " << (a < b) <<'\n';

	return 0;
}
