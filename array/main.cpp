//main
#include "Array.h"
#include <iostream>


//using namespace std;

int main()
{
	Array a(new int[5]{ 5,4,3,2,1 }, 5);
	a.Sort(sortType::bitSort);
	a.Print();
	system("pause");
	return 0;
}


