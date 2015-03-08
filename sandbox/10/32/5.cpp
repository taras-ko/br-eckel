#include "32.h"
#include <iostream>

extern Mirror m1;
Mirror m5(&m1, "m5");

int main()
{
	std::cout << m5.test();
}
