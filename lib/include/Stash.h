#include <vector>
#include "Mem.h"

#ifndef STASH_H
#define STASH_H
class Stash {
	int size;		// Size of each memory block
	int quantity;	// Number of storage blocks
	int next;		// Next empty block
	Mem *storage;
	void inflate(int increase);
public:
	Stash(int size, int initQuantity = 0);
	~Stash();
	int add(const void* element);
	void* fetch(int index);
	int count();
};
#endif // STASH_H

