#ifndef STACKIMP_H
#define STACKIMP_H
#include "StackOfInt.h"
#define STORAGE_SIZE 20
class StackOfInt::StackImp {
	int *head;
	int storage[STORAGE_SIZE];
public:
	StackImp();
	void push(int);
	int pop();
};

#endif // STACKIMP_H
