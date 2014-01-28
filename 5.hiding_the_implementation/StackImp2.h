#ifndef STACKIMP_H
#define STACKIMP_H
#include "StackOfInt.h"
#include <vector>

using namespace std;

class StackOfInt::StackImp {
	int head;
	vector<int> storage;
public:
	void push(int);
	int pop();
};

#endif // STACKIMP_H
