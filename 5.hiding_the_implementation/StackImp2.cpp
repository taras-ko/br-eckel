#include <iostream>
#include <stdlib.h>
#include "StackImp2.h"

using namespace std;

void StackOfInt::StackImp::push(int val)
{
	storage.insert(storage.begin(), val);
}

int StackOfInt::StackImp::pop()
{
	int val = storage.back();
	storage.pop_back();

	return val;
}
