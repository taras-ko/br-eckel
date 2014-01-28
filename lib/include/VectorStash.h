#include <vector>

#ifndef STASH_H
#define STASH_H
class Stash {
	int size;		// Size of each space
	int quantity;	// Number of storage spaces
	int next;		// Next empty space
	void inflate(int increase);
	std::vector<unsigned char> *storage; // Dynamically allocated array of bytes:
public:
	Stash(int size);
	~Stash();
	int add(const void* element);
	void* fetch(int index);
	int count();
};
#endif // STASH_H

