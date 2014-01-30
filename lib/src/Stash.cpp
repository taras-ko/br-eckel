#include <iostream>
#include <cassert>

#include <Stash.h>
#include <require.h>

using namespace std;

// Quantity of elements to add
// when increasing storage:
const int increment = 100;

Stash::Stash(int sz, int initQuantity)
{
	size = sz;
	quantity = 0;
	next = 0;
	storage = 0;
	inflate(initQuantity);
}

int Stash::add(const void* element)
{
	if (next >= quantity)
		inflate(increment);
	int startBytes = next * size;
	unsigned char *e = (unsigned char *) element;

	for (int i = 0; i < size; i++)
		storage[startBytes + i] = e[i];
	next++;
	return (next - 1);
}

void* Stash::fetch(int index)
{
	require(0 <= index, "Stash::fetch (-)index");
	if (index >= next)
		return 0;
	return &(storage[index * size]);
}

int Stash::count()
{
	return next; // Elements in Stash
}

void Stash::inflate(int increase)
{
	assert(increase > 0);
	if (increase == 0) return;
	int newQuantity = quantity + increase;
	int newBytes = newQuantity * size;
	int oldBytes = quantity * size;
	unsigned char *b = new unsigned char[newBytes];

	for (int i = 0; i < oldBytes; i++)
		b[i] = storage[i]; // Copy old to new

	delete []storage; // Old storage
	storage = b; // Point to new memory
	quantity = newQuantity;
}

Stash::~Stash()
{
	if (size != 0) {
		cout << "freeing storage" << endl;
		delete []storage;
	}
} ///:~

