//: C04:CLib.cpp {O}
// Implementation of example C-like library
// Declare structure and functions:
#include <iostream>
#include <cassert>

#include <Stash.h>

using namespace std;

// Quantity of elements to add
// when increasing storage:
const int increment = 100;

void Stash::initialize(int sz)
{
	size = sz;
	quantity = 0;
	storage = new vector<unsigned char>(0);
	next = 0;
}

int Stash::add(const void* element)
{
	unsigned char *e = (unsigned char *) element;
	for(int i = 0; i < size; i++)
		storage->push_back(e[i]);

	next++;
	return next - 1; // Index number
}

void* Stash::fetch(int index)
{
	// Check index boundaries:
	assert(0 <= index);
	if (index >= next)
		return 0; // To indicate the end

	// Produce pointer to desired element:
	return &(storage->at(index * size));
}

int Stash::count()
{
	return next; // Elements in Stash
}

/*
void Stash::inflate(int increase)
{
	assert(increase > 0);
	int newQuantity = quantity + increase;
	int newBytes = newQuantity * size;
	int oldBytes = quantity * size;
	unsigned char* b = new unsigned char[newBytes];

	for(int i = 0; i < oldBytes; i++)
		b[i] = storage[i]; // Copy old to new

	delete [](storage); // Old storage
	storage = b; // Point to new memory
	quantity = newQuantity;
}
*/

void Stash::cleanup()
{
	if (storage->size() != 0) {
//		cout << "freeing storage" << endl;
		delete storage;
	}
} ///:~

