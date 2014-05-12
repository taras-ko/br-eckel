#include <iostream>
#include <cassert>
#include <cstring>

#include <PStash.h>
#include <require.h>

using namespace std;


int PStash::add(void *element)
{
	const int inflateSize = 10;
	if (next >= quantity)
		inflate(inflateSize);
	storage[next++] = element;
	return next - 1;
}

PStash::~PStash() {
	for (int i = 0; i < next; i++)
		require(storage[i] == 0, "PStash not cleaned up");

	delete []storage;
}

void *PStash::operator[](int index) const
{
	require(index >= 0, "PStash::operator[] index negative");
	if (index >= next)
		return 0;

	return storage[index];
}

void Stash::inflate(int increase)
{
	assert(increase > 0);

	if (increase == 0)
		return;

	int newQuantity = quantity + increase;
	storage->pointer(size * newQuantity);

	quantity = newQuantity;
}
