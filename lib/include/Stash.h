#include <vector>
#include "Mem.h"
#include <require.h>

#ifndef STASH_H
#define STASH_H
class Stash {
	int size;		// Size of each memory block
	int quantity;	// Number of storage blocks
	int next;		// Next empty block
	Mem *storage;
	void inflate(int increase);
public:
	Stash(int size_, int initQuantity = 0)
		: size(size_), quantity(initQuantity), next(0)
	{
		storage = new Mem(size * initQuantity);
	}
	~Stash() { if (size != 0) delete storage; }

	int add(const void* element);
	void* fetch(int index)
	{
		require(0 <= index, "Stash::fetch (-)index");
		if (index >= next)
			return 0;
		return storage->pointer() + index * size;
	}
	int count() const { return next; }
};
#endif // STASH_H

