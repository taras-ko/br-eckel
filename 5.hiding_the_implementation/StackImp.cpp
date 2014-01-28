#include <iostream>
#include <stdlib.h>
#include "StackImp.h"

using namespace std;

StackOfInt::StackImp::StackImp()
{
	for (int i = 0; i < STORAGE_SIZE; i++)
		storage[i] = 0;

	head = storage;
}

void StackOfInt::StackImp::push(int i)
{
	if ((head - storage) < STORAGE_SIZE)
		*head++ = i;
}

int StackOfInt::StackImp::pop()
{
	if (head > storage)
		return *--head;
	else {
		cout << "Reached to the end of stack!" << endl;
		exit(1);
	}
}
