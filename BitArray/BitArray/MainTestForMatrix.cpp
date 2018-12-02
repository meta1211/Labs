#include <iostream>
#include "BitArray.h"
#include "BitMatrix.h"


int main()
{
	char **test = new char*[2]{ new char[5]{'1','1','0','1','\0'}, new char[3]{'1','1','\0'} };
	BitMatrix a(test, 2);
	std::cout << "a (constructor from int**, int):\n";
	a.Print();
	BitMatrix b;
	std::cout << "b (base constructor):\n";
	b.Print();

	int x, y;
	std::cout << "input please strings and columns count:\n";
	std::cin >> x >> y;
	BitMatrix c(x,y);
	std::cout << "input matrix please:\n";
	c.Scan(y, x);
	std::cout << "Your matrix:\n";
	c.Print();

	std::cout << "b = a\n";
	b = a;
	std::cout << "new b:\n";
	b.Print();

	std::cout << "a[1]: \n";
	std::cout << a[1] << '\n';

	std::cout << "a == c?\n";
	std::cout << (a == c ? "Yes" : "No") << '\n';
	std::cout << "a == b?\n";
	std::cout << (a == b ? "Yes" : "No") << '\n';

	std::cout << "a Set(0,1,false), invert(1,0)\n";
	a.Set(0, 1, false);
	a.Invert(1, 0);
	a.Print();

	std::cout << "invert(1, 0, 4) and set(0, 1, 2, true)\n";
	a.Invert(1, 0, 4);
	a.Set(0, 1, 2, true);
	a.Print();

	std::cout << "a:\n";
	a.Print();
	std::cout << "c:\n";
	c.Print();
	std::cout << "c &= a:\n";
	c &= a;
	c.Print();
	std::cout << "OR and XOR works the same way.\n";

	std::cout << "~c:\n";
	(~c).Print();

	std::cout << "c shift left first row by two\n";
	(c.ShiftLeft(0, 2)).Print();

	std::cout << "a:\n";
	a.Print();
	std::cout << "a XorEach:\n";
	(a.XorEach()).Print();
	std::cout << "Test cin for a.\nWrite 2 string witg 4 bits:\n";
	std::cin >> a;
	std::cout << "a: " << a << '\n';
	return 0;
}