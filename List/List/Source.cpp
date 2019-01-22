#include <iostream>
#include "List.h"

int main()
{
	List a;
	a.AddToHead(1);
	a.AddToHead(2);
	a.AddToHead(3);
	//std::cout << "Add and delete 1 to head test:\n";
	//a.AddToHead(1);
	//a.PrintList();
	//a.DelToHead();
	//a.PrintList();
	//std::cout << "Add and delete 1 to tail test:\n";
	//a.AddToTail(1);
	//a.PrintList();
	//a.DelToTail();
	//a.PrintList();
	//std::cout << "Clear test:\n";
	//a.AddToHead(1);
	//a.AddToHead(2);
	//a.AddToHead(3);
	//a.PrintList();
	//a.Clear();
	//a.PrintList();
	//std::cout << "Add 10 after 2nd element:\n";
	//a.PrintList();
	//a.AddToIndex(1, 10);
	//a.PrintList();
	//std::cout << "Delete 10 (index 3):\n";
	//a.DelToIndex(2);
	//a.PrintList();
	//std::cout << "Add 10 after 3:\n";
	//a.PrintList();
	//a.AddToKey(3, 10);
	//a.PrintList();
	//std::cout << "Delete 10:\n";
	//a.DelToKey(10);
	//a.PrintList();
	//std::cout << "b = a:\n";
	List b = a;
	b.PrintList();
	std::cout << "Input please 5 numbers:\n";
	List c(5);
	c.PrintList();
	std::cout << " a + b:\n";
	(a + b).PrintList();
	return 0;
}