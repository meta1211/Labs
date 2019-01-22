//main
#include "Array.h"
#include "TemplateArray.h"
#include <iostream>
#include <ctime>

int main()
{
	Array a(15);
	for (int i = 0; i < 15; i++)
	{
		a[i] = rand() % 100;
	}
	std::cout << "Bitsort test\n Array before sort:\n";
	a.Print();
	a.Sort(sortType::bitSort);
	std::cout << "Array after sort:\n";
	a.Print();
	std::cout << "Temp. array test:\n";
	TemplateArray<double> b;
	std::cout << "Input please number of elemets:";
	int n;
	std::cin >> n;
	std::cout << "Please input " << n << " elements:\n";
	b.Scan(n);
	std::cout << "Array:";
	b.Print();
	std::cout << "Try to find " << b[0] << ":\nIts index is: " << b.Find(b[0]) << std::endl;
	TemplateArray<double> c = TemplateArray<double>(new double[3]{ 1.0, 2.0, 3.0 }, 3);
	std::cout << "Lets check b + c:\nc:\n";
	c.Print();
	(b + c).Print();
	std::cout << "b - " << b[0] << '\n';
	(b - b[0]).Print();
	std::cout << "b -= 0\n";
	b -= 0;
	b.Print();
	system("pause");
	return 0;
}


